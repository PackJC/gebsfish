"""Build the local folder of DayZ's own files that some gebsfish tools need.

Some gebsfish items wear a vanilla model: the ten colour fishing rods, the 50
fishing clothes and the rubber worm. The fish mounts are posed on vanilla's
live fish (tools/build_mount_poses.py). The repo can't carry DayZ's files, so
tools/item_manifest.json names those models by game path (\\dz\\...) and the
tools look them up in a local extraction that this script builds:

    python tools/extract_vanilla.py --game "<DayZ folder>" --debinarizer "<P3DDebinarizer.exe>" <root>

then, for example:

    blender --background --python tools/render_p3d.py -- --src data/clothes
        --out <renders> --manifest tools/item_manifest.json --texroot . --dz <root>
        --only "geb_*FishShirt"

What goes into <root>:
  - every vanilla model in the manifest (tools/item_manifest.json, or each
    --manifest given), every \\dz\\ texture and material it names, and the
    textures and materials the model's first LOD names itself
  - vanilla's live fish and shrimp (dz\\gear\\food\\*_live.p3d, shrimp.p3d) for
    tools/build_mount_poses.py, plus anything given with --add
  - the vanilla relief and shine maps the mod's own materials borrow (the jon
    boat motor's shine map)

Layout: <root>\\<PBO prefix>\\<file>, so a game path resolves by joining it to
<root>, e.g. \\dz\\gear\\food\\bait_worm.p3d is <root>\\DZ\\gear\\food\\bait_worm.p3d
(letter case as the PBO spells it; the tools match without regard to case).
Every .p3d is stored debinarized (MLOD), which is what the Blender importer
reads; the binarized original only passes through a temporary folder.

Options:
  --game DIR         the DayZ install (the folder holding Addons\\), or its Addons folder
  --debinarizer EXE  P3DDebinarizer.exe (default: the one on PATH). It runs as
                     <exe> --engine <engine> <model.p3d> <out folder>
  --engine NAME      the debinarizer's engine (default DeODOL6_2; DeODOL53
                     crashes on DayZ's v54 models)
  --manifest FILE    a manifest to take vanilla paths from; repeatable
                     (default tools/item_manifest.json)
  --add PATH         another game path to extract, * and ? allowed in the file
                     name (e.g. "\\dz\\gear\\food\\*_fillet.p3d"); repeatable
  --force            extract and debinarize again over files already there

Use a short <root> such as C:\\dzx: some DayZ paths are long. The folder holds
DayZ's own content: keep it outside the repo and never commit any of it. The
script refuses a <root> inside the repo. DayZ 1.30 Experimental's models (ODOL
v56) need a patched debinarizer; a failed model is listed at the end.
"""

import argparse
import fnmatch
import glob
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)

# Vanilla's live fish and shrimp, which tools/build_mount_poses.py poses on the
# fish mounts. The pattern also takes any live fish a DayZ update adds.
DEFAULT_EXTRA = (r"\dz\gear\food\shrimp.p3d", r"\dz\gear\food\*_live.p3d")

VERS = 0x56657273      # 'Vers': the PBO header's property block
CPRS = 0x43707273      # 'Cprs': an LZSS-packed entry


def norm(path):
    """A game path as the matching key: lower case, backslashes, no leading one."""
    return path.replace("/", "\\").lstrip("\\").lower()


def is_game_path(path):
    return isinstance(path, str) and norm(path).startswith("dz\\")


class Pbo:
    """A PBO's header, read without loading the whole file: its prefix and its
    entries as name -> (packing, original size, stored size, offset)."""

    def __init__(self, path, props_only=False):
        self.path = path
        self.props, self.entries = {}, None
        with open(path, "rb") as fh:
            self._read(fh, props_only)

    @property
    def prefix(self):
        return self.props.get("prefix", "").strip("\\/")

    def _read(self, fh, props_only):
        buf, pos = bytearray(), 0

        def more():
            chunk = fh.read(1 << 16)
            if not chunk:
                raise ValueError("truncated PBO header")
            buf.extend(chunk)

        def asciiz():
            nonlocal pos
            while True:
                end = buf.find(b"\0", pos)
                if end >= 0:
                    text = bytes(buf[pos:end]).decode("latin-1")
                    pos = end + 1
                    return text
                more()

        def fields():
            nonlocal pos
            while len(buf) - pos < 20:
                more()
            values = struct.unpack_from("<5I", buf, pos)
            pos += 20
            return values

        entries, first = [], True
        while True:
            name = asciiz()
            packing, original, _, _, size = fields()
            if first and not name and packing == VERS:
                while True:
                    key = asciiz()
                    if not key:
                        break
                    self.props[key] = asciiz()
                first = False
                if props_only:
                    return
                continue
            first = False
            if not name:
                break
            entries.append((name, packing, original, size))
        offset, self.entries = pos, {}
        for name, packing, original, size in entries:
            self.entries[name.replace("/", "\\").lower()] = (name, packing, original, size, offset)
            offset += size

    def read(self, key):
        name, packing, original, size, offset = self.entries[key]
        with open(self.path, "rb") as fh:
            fh.seek(offset)
            data = fh.read(size)
        if packing == CPRS or (original and original != size):
            data = lzss(data, original)
        return name, data


def lzss(src, length):
    """Unpack a PBO entry stored with Bohemia's LZSS."""
    out, i = bytearray(), 0
    while len(out) < length and i < len(src):
        flags = src[i]
        i += 1
        for bit in range(8):
            if len(out) >= length or i >= len(src):
                break
            if flags & (1 << bit):
                out.append(src[i])
                i += 1
            else:
                b1, b2 = src[i], src[i + 1]
                i += 2
                start = len(out) - (b1 | ((b2 & 0xF0) << 4))
                for k in range((b2 & 0x0F) + 3):
                    out.append(out[start + k] if start + k >= 0 else 0x20)
    return bytes(out[:length])


def first_lod_files(data):
    """The textures and materials the faces of an MLOD p3d's first LOD name."""
    if data[:4] != b"MLOD" or data[12:16] != b"P3DM":
        return set()
    points, normals, faces = struct.unpack_from("<3I", data, 24)
    p = 40 + points * 16 + normals * 12
    found = set()
    for _ in range(faces):
        p += 4 + 4 * 16 + 4
        for _ in range(2):
            end = data.index(b"\0", p)
            found.add(data[p:end].decode("latin-1"))
            p = end + 1
    return {f for f in found if f and not f.startswith("#")}


def borrowed_maps():
    """\\dz\\ files the mod's own materials use as relief (Stage1) or shine (Stage5)
    maps, the stages render_p3d.py reads."""
    found = set()
    for dirpath, dirnames, files in os.walk(os.path.join(REPO, "data")):
        dirnames[:] = [d for d in dirnames if not d.startswith(".")]
        for f in files:
            if not f.lower().endswith(".rvmat"):
                continue
            with open(os.path.join(dirpath, f), "rb") as fh:
                raw = fh.read()
            if raw[:4] == b"\0raP":
                continue
            for stage in re.finditer(r"class\s+Stage[15]\s*\{(.*?)\};", raw.decode("latin-1"), re.S):
                for tex in re.findall(r'texture\s*=\s*"([^"]*)"', stage.group(1)):
                    if is_game_path(tex):
                        found.add(tex)
    return found


def manifest_paths(path):
    """The game paths (\\dz\\...) a manifest names: models, textures, materials."""
    with open(path, "r", encoding="utf-8") as fh:
        entries = json.load(fh)
    found = set()
    for e in entries:
        for key in ("p3d", "texture", "material"):
            if is_game_path(e.get(key)):
                found.add(e[key])
        for key in ("textures", "materials"):
            found.update(p for p in (e.get(key) or []) if is_game_path(p))
    return found


def pbo_files(game):
    """The game's PBOs: Addons and dta first, then the Addons of its other
    folders (terrains, DLC), never the mods (@...) or the workshop (!...)."""
    found = []
    for sub in ("Addons", "dta"):
        found += sorted(glob.glob(os.path.join(game, sub, "*.pbo")))
    for d in sorted(os.listdir(game)):
        if d[:1] in "@!." or d.lower() in ("addons", "dta"):
            continue
        found += sorted(glob.glob(os.path.join(game, d, "Addons", "*.pbo")))
    return found


class Extractor:
    def __init__(self, game, root, exe, engine, force):
        self.root, self.exe, self.engine, self.force = root, exe, engine, force
        self.prefixes = []                  # (prefix key, pbo path), longest first
        for path in pbo_files(game):
            try:
                prefix = Pbo(path, props_only=True).prefix
            except (OSError, ValueError, struct.error):
                continue
            if prefix:
                self.prefixes.append((norm(prefix), path))
        self.prefixes.sort(key=lambda kv: -len(kv[0]))
        self.pbos = {}
        self.done, self.written, self.debinned, self.kept, self.failed = set(), [], [], [], []

    def pbo_for(self, key):
        for prefix, path in self.prefixes:
            if key.startswith(prefix + "\\"):
                if path not in self.pbos:
                    self.pbos[path] = Pbo(path)
                return self.pbos[path]
        return None

    def matches(self, wanted):
        """(pbo, entry key) for a game path, or each file a wildcard name matches."""
        key = norm(wanted)
        pbo = self.pbo_for(key)
        if pbo is None:
            return None, []
        rest = key[len(norm(pbo.prefix)) + 1:]
        if any(c in rest for c in "*?["):
            return pbo, sorted(k for k in pbo.entries if fnmatch.fnmatchcase(k, rest))
        return pbo, [rest] if rest in pbo.entries else []

    def target(self, pbo, name):
        parts = pbo.prefix.replace("/", "\\").split("\\") + name.replace("/", "\\").split("\\")
        return os.path.join(self.root, *parts)

    def extract(self, wanted):
        """Extract a game path (or pattern); returns the game paths its model names."""
        pbo, keys = self.matches(wanted)
        if pbo is None:
            self.failed.append((wanted, "no PBO in the game has that prefix"))
            return []
        if not keys:
            self.failed.append((wanted, "not in %s" % os.path.basename(pbo.path)))
            return []
        follow = []
        for key in keys:
            full = norm(pbo.prefix) + "\\" + key
            if full in self.done:
                continue
            self.done.add(full)
            name = pbo.entries[key][0]
            dst = self.target(pbo, name)
            is_model = key.endswith(".p3d")
            data = None
            if os.path.isfile(dst) and not self.force:
                with open(dst, "rb") as fh:
                    data = fh.read()
                if is_model and data[:4] != b"MLOD":
                    data = None                     # an earlier run left it binarized
                else:
                    self.kept.append(full)
            if data is None:
                name, data = pbo.read(key)
                if is_model and data[:4] == b"ODOL":
                    data, why = self.debinarize(data, os.path.basename(dst))
                    if data is None:
                        self.failed.append((full, why))
                        continue
                    self.debinned.append(full)
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                with open(dst, "wb") as fh:
                    fh.write(data)
                self.written.append(full)
            if is_model:
                follow += [f for f in first_lod_files(data) if is_game_path(f)]
        return follow

    def debinarize(self, odol, name):
        with tempfile.TemporaryDirectory(prefix="gebsfish_odol_") as tmp:
            src = os.path.join(tmp, name)
            out = os.path.join(tmp, "mlod")
            os.makedirs(out)
            with open(src, "wb") as fh:
                fh.write(odol)
            try:
                run = subprocess.run([self.exe, "--engine", self.engine, src, out],
                                     capture_output=True, text=True, errors="replace", timeout=600)
            except (OSError, subprocess.TimeoutExpired) as exc:
                return None, "debinarizer: %s" % exc
            result = os.path.join(out, name)
            if run.returncode != 0 or not os.path.isfile(result):
                tail = " ".join((run.stdout + run.stderr).split())[-300:]
                return None, "debinarizer failed (exit %d): %s" % (run.returncode, tail)
            with open(result, "rb") as fh:
                data = fh.read()
            if data[:4] != b"MLOD":
                return None, "debinarizer wrote something other than MLOD"
            return data, None


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("root", help="folder to build the extraction in (outside the repo)")
    ap.add_argument("--game", required=True, help="the DayZ install folder, or its Addons folder")
    ap.add_argument("--debinarizer", default=shutil.which("P3DDebinarizer.exe") or shutil.which("P3DDebinarizer"),
                    help="P3DDebinarizer.exe (default: the one on PATH)")
    ap.add_argument("--engine", default="DeODOL6_2")
    ap.add_argument("--manifest", action="append", help="default tools/item_manifest.json")
    ap.add_argument("--add", action="append", default=[], help="another game path or pattern")
    ap.add_argument("--force", action="store_true")
    args = ap.parse_args()

    root = os.path.abspath(args.root)
    repo = os.path.realpath(REPO)
    if os.path.normcase(os.path.realpath(root)).startswith(os.path.normcase(repo + os.sep)) \
            or os.path.normcase(os.path.realpath(root)) == os.path.normcase(repo):
        sys.exit("refused: %s is inside the repo; DayZ's files must stay out of it" % root)
    game = os.path.abspath(args.game)
    if os.path.basename(game).lower() == "addons":
        game = os.path.dirname(game)
    if not os.path.isdir(os.path.join(game, "Addons")):
        sys.exit("no Addons folder in %s: give --game the DayZ install folder" % game)
    if not args.debinarizer or not os.path.isfile(args.debinarizer):
        sys.exit("P3DDebinarizer.exe not found: pass --debinarizer <path>")

    wanted = set(DEFAULT_EXTRA) | set(args.add) | borrowed_maps()
    for m in args.manifest or [os.path.join(TOOLS, "item_manifest.json")]:
        wanted |= manifest_paths(m)

    ex = Extractor(game, root, args.debinarizer, args.engine, args.force)
    print("%d PBOs indexed; %d paths asked for" % (len(ex.prefixes), len(wanted)))
    queue = sorted(wanted, key=norm)
    while queue:
        queue = sorted(set(f for w in queue for f in ex.extract(w)), key=norm)

    print("written      : %d (%d of them models debinarized)" % (len(ex.written), len(ex.debinned)))
    print("already there: %d (--force to redo)" % len(ex.kept))
    if ex.failed:
        print("failed       : %d" % len(ex.failed))
        for path, why in ex.failed:
            print("   - %s: %s" % (path, why))
    print("extraction   : %s" % root)
    print("render with  : blender --background --python tools/render_p3d.py -- ... --dz \"%s\"" % root)
    return 1 if ex.failed else 0


if __name__ == "__main__":
    sys.exit(main())
