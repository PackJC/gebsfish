# Render a looping animated GIF for every species in the fish manifest.
#
#   python tools/batch_gifs.py [out_dir] [--only name1,name2] [--res 512] [--blender path]
#
# out_dir defaults to fish_gifs on your Desktop. Blender is found from
# --blender, the BLENDER environment variable, the PATH, or the newest
# install under Program Files\Blender Foundation.
#
# Each species gets a motion profile suited to its anatomy -- a spine
# undulation is right for a trout and ridiculous on a clam:
#
#   swim        fish and the salamander: travelling spine wave
#   crustacean  crayfish, lobsters, crabs: the tail tucks and releases, walking bob
#   crawl       the frog and the shrimp: walking bob with a slight sway
#   drift       clams, mussels, snails: nearly static, very slow turn
#   curl        starfish: the arms lift and settle, very slow turn
#   pulse       jellyfish: contracting bell
#
# No jaw animation -- these are swim cycles only.

import argparse
import glob
import json
import os
import re
import shutil
import subprocess
import sys

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
MANIFEST = os.path.join(TOOLS, "fish_manifest.json")
FISH_DIR = os.path.join(REPO, "data", "fish")

CRUSTACEAN = ("crayfish", "lobster", "crab")
CRAWL = ("bullfrog", "shrimp")
DRIFT = ("clam", "mussel", "snail")
CURL = ("starfish",)
PULSE = ("jellyfish",)

# The batch default was too timid: on long thin fish the motion was small
# enough that GIF quantisation collapsed every frame into one still image.
SWIM_AMP = "34"


def profile_for(name):
    n = name.lower()
    if any(k in n for k in PULSE):
        return "pulse"
    if any(k in n for k in CURL):
        return "curl"
    if any(k in n for k in DRIFT):
        return "drift"
    if any(k in n for k in CRUSTACEAN):
        return "crustacean"
    if any(k in n for k in CRAWL):
        return "crawl"
    return "swim"


def find_blender(explicit):
    """--blender, then $BLENDER, then the PATH, then the newest Program Files install."""
    for candidate in (explicit, os.environ.get("BLENDER")):
        if candidate and os.path.isfile(candidate):
            return candidate
    on_path = shutil.which("blender")
    if on_path:
        return on_path
    installs = glob.glob(os.path.join(os.environ.get("ProgramFiles", r"C:\Program Files"),
                                      "Blender Foundation", "Blender *", "blender.exe"))

    def version(path):
        m = re.search(r"Blender (\d+)\.(\d+)", path)
        return (int(m.group(1)), int(m.group(2))) if m else (0, 0)
    return max(installs, key=version) if installs else None


def local(path):
    """A manifest path (relative to the repo root) as a usable file path."""
    if path and not os.path.isabs(path):
        return os.path.join(REPO, path.replace("/", os.sep))
    return path


def main():
    ap = argparse.ArgumentParser(description="Render a looping GIF per species in tools/fish_manifest.json.")
    ap.add_argument("out_dir", nargs="?", default=os.path.join(os.path.expanduser("~"), "Desktop", "fish_gifs"))
    ap.add_argument("--only", help="comma-separated species classnames")
    ap.add_argument("--res", default="512")
    ap.add_argument("--blender", help="path to blender.exe")
    args = ap.parse_args()

    blender = find_blender(args.blender)
    if not blender:
        sys.exit("Blender not found: pass --blender <path to blender.exe> or set BLENDER.")
    out_root, res = args.out_dir, args.res
    only = {x.strip().lower() for x in args.only.split(",") if x.strip()} if args.only else None

    os.makedirs(out_root, exist_ok=True)
    with open(MANIFEST, encoding="utf-8") as fh:
        entries = json.load(fh)
    if only:
        entries = [e for e in entries if e["name"].lower() in only]

    done, failed = [], []
    for i, e in enumerate(entries, 1):
        name = e["name"]
        profile = profile_for(name)
        print("\n[%d/%d] %s  (%s)" % (i, len(entries), name, profile), flush=True)

        cmd = [blender, "--background", "--python",
               os.path.join(TOOLS, "rig_swim.py"), "--",
               "--p3d", local(e["p3d"]), "--name", name, "--out", out_root,
               "--src", FISH_DIR, "--profile", profile, "--res", res]
        if e.get("texture"):
            cmd += ["--texture", local(e["texture"])]
        # The species' own material: several species share one model, and
        # without it they all render with the base species' material.
        if e.get("material"):
            cmd += ["--material", local(e["material"])]
        if e.get("view"):
            cmd += ["--view", e["view"]]
        # Orientation fixes, as the still renderer applies them. flip_h is
        # left out: rig_swim turns every head the same way itself.
        for key, flag in (("flip_head", "--flip-head"), ("flip_v", "--flip-v"), ("roll", "--roll")):
            if e.get(key):
                cmd += [flag]
        if profile == "swim":
            # Eel-like bodies read better with a stronger, longer wave.
            if "salamander" in name.lower():
                cmd += ["--amp", "42", "--waves", "1.4"]
            else:
                cmd += ["--amp", SWIM_AMP]
        elif profile == "curl":
            # Oblique view so the arms lifting is actually visible.
            cmd += ["--azimuth", "42", "--elevation", "38"]

        r = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
        frames = os.path.join(out_root, "frames_" + name)
        if r.returncode != 0 or not os.path.isdir(frames):
            failed.append((name, "render rc=%s" % r.returncode))
            print("   FAILED: %s" % (r.stderr or "")[-300:], flush=True)
            continue

        gif = os.path.join(out_root, name + "_swim.gif")
        g = subprocess.run([sys.executable, os.path.join(TOOLS, "make_gif.py"),
                            frames, gif, "60"], capture_output=True, text=True, errors="replace")
        if g.returncode != 0:
            failed.append((name, "gif"))
            print("   GIF FAILED: %s" % (g.stderr or "")[-200:], flush=True)
        elif "WARNING" in (g.stdout or ""):
            # Don't let a silently-collapsed GIF pass as a success.
            failed.append((name, "frames collapsed"))
            print("   %s" % g.stdout.strip().split("***")[1], flush=True)
        else:
            done.append(name)
            print("   ok -> %s" % os.path.basename(gif), flush=True)

    print("\n================ SUMMARY ================")
    print("gifs written : %d" % len(done))
    print("failed       : %d" % len(failed))
    for n, why in failed:
        print("   - %s (%s)" % (n, why))
    print("output       : %s" % out_root)


if __name__ == "__main__":
    main()
