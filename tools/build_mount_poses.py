# Writes scripts/4_world/entities/itembase/gear/geb_fishmountposes.c: how every
# mountable species hangs on the fish mounts. Rerun it after adding a mountable
# fish or changing one's model:
#
#   python tools/build_mount_poses.py
#
# The mountable vanilla classes (Shrimp, Carp, Mackerel, WalleyePollock,
# SteelheadTrout) have their poses in tools/vanilla_mount_poses.json, because
# their models can't live in this repo. After a game update, recompute them
# from the game's own models:
#
#   python tools/build_mount_poses.py --dz <extraction root>
#
# where <extraction root> holds the debinarized (MLOD) vanilla models under
# their game paths, e.g. <root>/dz/gear/food/carp_live.p3d (tools/extract_vanilla.py
# makes one). That rewrites the JSON file, reports every row that changed and
# flags any *_live.p3d catch model next to them that has no row yet (a new
# vanilla fish: give its class the GebFishMount slot in data/fish/config.cpp and
# a row in the JSON file).
#
# Each species hangs upright and side-on, its good side out and its head to the
# viewer's right: the side and facing of its wiki picture (tools/fish_manifest.json
# view and flips, read the way render_p3d.py reads them). Its box is centred on
# the board and its back sits just clear of the board's face.
#
# Frames (Arma model coordinates). Mount: +Y up, +Z out of the wall towards the
# viewer, so the viewer's right is -X. The fish rides the gebfishmount proxy at the
# board's display point; the proxy's long leg is the fish's +Y and its short leg
# the fish's +Z, laid along -X and +Z, so before any pose the fish's +X points up,
# its +Y to the viewer's right and its +Z out. The mount's Model.cfg turns it with
# nested bones: roll (about +Z) inside pitch (about +X) inside yaw (about +Y)
# inside three translations, all through the display point. The engine turns by
# the right-hand rule about the axis from its first memory point to its second
# (checked on vanilla's CivilianSedan: trunk lid, driver door and wheels), so the
# pose is translate * yaw * pitch * roll with ordinary rotation matrices.
#
# Each species' size is the smallest mount that holds it, by model length:
# small up to SMALL_MAX, medium up to MEDIUM_MAX, large beyond.

import argparse
import datetime
import glob
import json
import math
import os
import struct
import sys

import numpy as np

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(REPO, "scripts", "4_world", "entities", "itembase", "gear", "geb_fishmountposes.c")
SMALL_MAX, MEDIUM_MAX = 0.65, 2.0     # metres of model length
GAP = 0.004                           # fish's back to the board's face (m)

# Mountable vanilla classes, which aren't in the fish manifest: their game model
# path, the view their side shows in (AUTO, or MID for the steelhead, whose fins
# are wider than it is tall) and their stored pose. The Shrimp is a cluster of four.
VANILLA = os.path.join(REPO, "tools", "vanilla_mount_poses.json")


def first_visual_points(path):
    """The points the first visual LOD's faces use (MLOD)."""
    b = open(path, "rb").read()
    if b[:4] != b"MLOD":
        raise ValueError("%s is not an MLOD p3d" % path)
    nlods = struct.unpack_from("<I", b, 8)[0]
    pos = 12
    for _ in range(nlods):
        npts, nnrm, nfaces = struct.unpack_from("<3I", b, pos + 12)
        pos += 28
        pts = np.frombuffer(b, "<f4", npts * 4, pos).reshape(-1, 4)[:, :3].astype(float)
        pos += npts * 16 + nnrm * 12
        used = set()
        for _ in range(nfaces):
            nv = struct.unpack_from("<I", b, pos)[0]
            for k in range(nv):
                used.add(struct.unpack_from("<I", b, pos + 4 + k * 16)[0])
            pos += 72
            pos = b.index(b"\0", pos) + 1
            pos = b.index(b"\0", pos) + 1
        pos += 4                                   # TAGG
        while True:
            pos += 1
            end = b.index(b"\0", pos)
            name = b[pos:end]
            pos = end + 1
            size = struct.unpack_from("<I", b, pos)[0]
            pos += 4 + size
            if name == b"#EndOfFile#":
                break
        resolution = struct.unpack_from("<f", b, pos)[0]
        pos += 4
        if resolution < 1000:
            return pts[sorted(used)]
    raise ValueError("%s has no visual LOD" % path)


def picture_frame(P, e):
    """The wiki picture's right (head), up (dorsal) and towards-the-camera axes, in Arma coordinates."""
    B = P[:, [0, 2, 1]]                            # Blender = Arma with Y and Z swapped
    ext = B.max(0) - B.min(0)
    order = sorted(range(3), key=lambda i: ext[i], reverse=True)
    view = (e.get("view") or "AUTO").upper()
    if view == "AUTO":
        ih, iv = order[0], order[1]
    elif view == "MID":
        ih, iv = order[0], order[2]
    else:
        iview = "XYZ".index(view)
        rest = [i for i in order if i != iview]
        ih, iv = rest[0], rest[1]
    flip_h, flip_v = bool(e.get("flip_h")), bool(e.get("flip_v"))
    if e.get("roll"):
        ih, iv, flip_v = iv, ih, not flip_v
    ax = np.eye(3)
    right = -ax[ih] if flip_h else ax[ih]
    up = -ax[iv] if flip_v else ax[iv]
    side = np.cross(right, up)
    sw = lambda v: np.array([v[0], v[2], v[1]])
    return sw(right), sw(up), sw(side)


def rot(axis, deg):
    c, s = math.cos(math.radians(deg)), math.sin(math.radians(deg))
    if axis == "x":
        return np.array([[1, 0, 0], [0, c, -s], [0, s, c]])
    if axis == "y":
        return np.array([[c, 0, s], [0, 1, 0], [-s, 0, c]])
    return np.array([[c, -s, 0], [s, c, 0], [0, 0, 1]])


BASE = np.array([[0, -1, 0], [1, 0, 0], [0, 0, 1]], float)     # the proxy before any pose
WANT = np.array([[-1, 0, 0], [0, 1, 0], [0, 0, 1]], float)     # head -> -X, dorsal -> +Y, good side -> +Z


def pose(P, e):
    right, up, side = picture_frame(P, e)
    Rw = WANT.T @ np.stack([right, up, side], 1).T                  # fish model -> mount
    target = Rw @ BASE.T                                            # what the bones have to add
    best = None
    for pitch in (0, 90, 180, 270):
        for yaw in (0, 90, 180, 270):
            for roll in (0, 90, 180, 270):
                if np.allclose(rot("y", yaw) @ rot("x", pitch) @ rot("z", roll), target, atol=1e-6):
                    key = (pitch != 0, (yaw % 180 != 0) + (roll % 180 != 0), yaw, pitch, roll)
                    best = key if best is None or key < best else best
    if best is None:
        raise ValueError("no right-angle pose for %s" % e["name"])
    yaw, pitch, roll = best[2:]
    Q = P @ Rw.T
    lo, hi = Q.min(0), Q.max(0)
    c = (lo + hi) / 2
    length = float((P.max(0) - P.min(0)).max())
    size = 0 if length <= SMALL_MAX else (1 if length <= MEDIUM_MAX else 2)
    return size, yaw, pitch, roll, -c[0], -c[1], GAP - lo[2], hi[1] - lo[1], length


def find_ci(root, game_path):
    """The file at game_path (\\dz\\... or dz/...) under root, matching case-insensitively."""
    here = root
    for part in [p for p in game_path.replace("\\", "/").split("/") if p]:
        if not os.path.isdir(here):
            return None
        hit = [n for n in os.listdir(here) if n.lower() == part.lower()]
        if not hit:
            return None
        here = os.path.join(here, hit[0])
    return here if os.path.isfile(here) else None


def recompute_vanilla(doc, root):
    """Pose every vanilla row from its model under root; report changes; rewrite doc in place."""
    changed = 0
    for name, row in doc["classes"].items():
        path = find_ci(root, row["model"])
        if not path:
            sys.exit("%s: %s not found under %s" % (name, row["model"], root))
        with open(path, "rb") as fh:
            if fh.read(4) != b"MLOD":
                sys.exit("%s: %s is binarized (ODOL); debinarize it first (tools/extract_vanilla.py does)" % (name, path))
        e = {"name": name, "view": row.get("view", "AUTO"), "flip_h": row.get("flip_h"), "flip_v": row.get("flip_v")}
        size, yaw, pitch, roll, dx, dy, dz, h, length = pose(first_visual_points(path), e)
        new = [size, yaw, pitch, roll, round(dx, 4), round(dy, 4), round(dz, 4), round(h, 3)]
        old = row["pose"]
        if [round(v, 4) for v in old] != [round(v, 4) for v in new]:
            changed += 1
            print("%-16s changed: %s -> %s" % (name, old, new))
        row["pose"], row["length"] = new, round(length, 2)
    # a catch model next to the known ones that has no row: a new vanilla fish?
    known = {os.path.basename(r["model"].replace("\\", "/")).lower() for r in doc["classes"].values()}
    folders = {os.path.dirname(find_ci(root, r["model"])) for r in doc["classes"].values()}
    for folder in sorted(folders):
        for p in sorted(glob.glob(os.path.join(folder, "*_live.p3d"))):
            if os.path.basename(p).lower() not in known:
                print("NEW? %s has no row: if it is a catch, give its class the GebFishMount slot "
                      "(data/fish/config.cpp) and add it to %s, then rerun" % (p, os.path.relpath(VANILLA, REPO)))
    doc["computed"] = "%s, by build_mount_poses.py --dz" % datetime.date.today().isoformat()
    with open(VANILLA, "w", encoding="utf-8", newline="\n") as fh:
        json.dump(doc, fh, indent=1)
        fh.write("\n")
    print("vanilla rows: %d recomputed, %d changed; wrote %s" % (len(doc["classes"]), changed, os.path.relpath(VANILLA, REPO)))


def main():
    ap = argparse.ArgumentParser(description="Write geb_fishmountposes.c from the fish manifest and the vanilla rows.")
    ap.add_argument("--dz", metavar="ROOT", help="recompute the vanilla rows from debinarized game models under ROOT")
    args = ap.parse_args()
    doc = json.load(open(VANILLA, encoding="utf-8"))
    if args.dz:
        recompute_vanilla(doc, args.dz)
    man = json.load(open(os.path.join(REPO, "tools", "fish_manifest.json"), encoding="utf-8"))
    rows, cache = {}, {}
    for e in man:
        p3d = e["p3d"]
        if p3d not in cache:
            cache[p3d] = first_visual_points(os.path.join(REPO, p3d.replace("/", os.sep)))
        rows[e["name"]] = pose(cache[p3d], e)
    for name, row in doc["classes"].items():
        size, yaw, pitch, roll, dx, dy, dz, h = row["pose"]
        rows[name] = (size, yaw, pitch, roll, dx, dy, dz, h, None)
    lines = []
    for name in sorted(rows, key=str.lower):
        size, yaw, pitch, roll, dx, dy, dz, h, _ = rows[name]
        lines.append('\t\tAdd("%s", %d, %d, %d, %d, %.4f, %.4f, %.4f, %.3f);' % (name, size, yaw, pitch, roll, dx, dy, dz, h))
    src = HEADER + "\n".join(lines) + FOOTER
    with open(OUT, "w", encoding="utf-8", newline="\r\n") as fh:      # CRLF, like the other scripts
        fh.write(src)
    names = ("small", "medium", "large")
    for s in range(3):
        group = sorted((r[8], n) for n, r in rows.items() if r[0] == s and r[8] is not None)
        if group:
            print("%-6s %2d species, %.2f to %.2f m" % (names[s], len(group), group[0][0], group[-1][0]))
    print("wrote %s (%d species)" % (os.path.relpath(OUT, REPO), len(rows)))


HEADER = '''/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// GENERATED by tools/build_mount_poses.py from the fish models and
// tools/fish_manifest.json. Don't edit by hand: rerun it after adding a
// mountable fish or changing one's model.
//
// How each species hangs on the fish mounts (geb_fishmount.c): the smallest
// mount that holds it (0 small, 1 medium, 2 large), the turn that shows it
// side-on with its head to the viewer's right (yaw about the board's vertical,
// pitch about its long axis, roll about the wall normal, in degrees), the shift
// that centres it on the display point and keeps its back just clear of the
// board (metres: right-to-left, up, out), and its height for placing it in the
// board's clear field.
class GebMountPose {
	int Size;
	float Yaw;
	float Pitch;
	float Roll;
	vector Offset;
	float Height;

	void GebMountPose(int size, float yaw, float pitch, float roll, vector offset, float height) {
		Size = size;
		Yaw = yaw;
		Pitch = pitch;
		Roll = roll;
		Offset = offset;
		Height = height;
	}
}

class GebMountPoses {
	protected static ref map<string, ref GebMountPose> s_Poses;

	// The species' pose. A class that isn't listed (another mod's subclass of a
	// listed fish) takes its nearest listed config parent's pose and size; null
	// for anything else (it hangs as the proxy leaves it, centred on the board's
	// field). Each answer is remembered, misses too.
	static GebMountPose Get(string type) {
		if (!s_Poses) {
			s_Poses = new map<string, ref GebMountPose>();
			Fill();
		}
		GebMountPose pose;
		if (s_Poses.Find(type, pose))
			return pose;
		string cls = type;
		string parent;
		for (int depth = 0; depth < 10; depth++) {
			if (!g_Game.ConfigGetBaseName("CfgVehicles " + cls, parent) || parent == "" || parent == cls)
				break;
			if (s_Poses.Find(parent, pose))
				break;
			cls = parent;
		}
		s_Poses.Set(type, pose);
		return pose;
	}

	protected static void Add(string type, int size, float yaw, float pitch, float roll, float dx, float dy, float dz, float height) {
		s_Poses.Set(type, new GebMountPose(size, yaw, pitch, roll, Vector(dx, dy, dz), height));
	}

	protected static void Fill() {
'''

FOOTER = '''
	}
}
'''


if __name__ == "__main__":
    main()
