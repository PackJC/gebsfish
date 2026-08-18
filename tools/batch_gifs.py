# Render a looping animated GIF for every species in the fish manifest.
#
#   python tools/batch_gifs.py <out_dir> [--only name1,name2] [--res 512]
#
# Each species gets a motion profile suited to its anatomy -- a spine
# undulation is right for a trout and ridiculous on a clam:
#
#   swim   fish and the salamander: travelling spine wave
#   crawl  crustaceans and the frog: walking bob with a slight sway
#   drift  shells, snails, starfish: nearly static, very slow turn
#   pulse  jellyfish: contracting bell
#
# No jaw animation -- these are swim cycles only.

import json
import os
import subprocess
import sys

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
BLENDER = r"C:\Program Files\Blender Foundation\Blender 4.4\blender.exe"
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


def main():
    out_root = sys.argv[1] if len(sys.argv) > 1 else r"C:\Users\ECHO\Desktop\fish_gifs"
    only, res = None, "512"
    for i, a in enumerate(sys.argv):
        if a == "--only":
            only = {x.strip().lower() for x in sys.argv[i + 1].split(",")}
        elif a == "--res":
            res = sys.argv[i + 1]

    os.makedirs(out_root, exist_ok=True)
    entries = json.load(open(MANIFEST, encoding="utf-8"))
    if only:
        entries = [e for e in entries if e["name"].lower() in only]

    done, failed = [], []
    for i, e in enumerate(entries, 1):
        name = e["name"]
        profile = profile_for(name)
        print("\n[%d/%d] %s  (%s)" % (i, len(entries), name, profile), flush=True)

        cmd = [BLENDER, "--background", "--python",
               os.path.join(TOOLS, "rig_swim.py"), "--",
               "--p3d", e["p3d"], "--name", name, "--out", out_root,
               "--src", FISH_DIR, "--profile", profile, "--res", res]
        if e.get("texture"):
            cmd += ["--texture", e["texture"]]
        if e.get("view"):
            cmd += ["--view", e["view"]]
        if e.get("flip_head"):
            cmd += ["--flip-head"]
        if profile == "swim":
            # Eel-like bodies read better with a stronger, longer wave.
            if "salamander" in name.lower():
                cmd += ["--amp", "42", "--waves", "1.4"]
            else:
                cmd += ["--amp", SWIM_AMP]
        elif profile == "curl":
            # Oblique view so the arms lifting is actually visible.
            cmd += ["--azimuth", "42", "--elevation", "38"]

        r = subprocess.run(cmd, capture_output=True, text=True)
        frames = os.path.join(out_root, "frames_" + name)
        if r.returncode != 0 or not os.path.isdir(frames):
            failed.append((name, "render rc=%s" % r.returncode))
            print("   FAILED: %s" % (r.stderr or "")[-300:], flush=True)
            continue

        gif = os.path.join(out_root, name + "_swim.gif")
        g = subprocess.run([sys.executable, os.path.join(TOOLS, "make_gif.py"),
                            frames, gif, "60"], capture_output=True, text=True)
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
