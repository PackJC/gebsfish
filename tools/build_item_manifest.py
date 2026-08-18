# Manifest for every NON-fish item in the mod (tackle, tools, vehicles...).
#
# Same story as the fish: one .p3d serves many item variants via
# hiddenSelectionsTextures (one cooler model -> 11 colours, one spinner ->
# 4 patterns), so rendering per-.p3d would produce untextured placeholders
# and miss every variant.
#
#   python tools/build_item_manifest.py > tools/item_manifest.json

import json
import glob
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_fish_manifest as B

REPO = B.REPO

# Per-model presentation fixes, keyed by .p3d basename so every colour
# variant inherits them.
#   ISO  - containers and gear: an axis-aligned view of a bucket or tackle
#          box just shows a flat lid or side, and ISO keeps the upright axis
#          up so handles stay on top
#   MID  - spinner: the blade sits edge-on and pointing down in the default
#          view; looking down the middle axis turns it face-on to camera
#   texture - the p3d's embedded reference is wrong or missing
MODEL_OVERRIDES = {
    # Boxy items need their upright axis forced: all three extents differ, so
    # the automatic "odd extent out" guess lays them on their side. The
    # cooler/tackle models are authored with Y up; the worm container is a
    # squat cylinder whose lid faces Z.
    "baitbucket.p3d":          {"view": "ISO", "texture": "data/tackle/baitbucket_co.paa"},
    "wormcontainer.p3d":       {"view": "ISO:Z"},
    "bugcontainer.p3d":        {"view": "ISO"},
    "bamboofishingnet.p3d":    {"view": "ISO"},
    "cooler.p3d":              {"view": "ISO:X"},
    "largetackle.p3d":         {"view": "ISO:X"},
    "mediumtackle.p3d":        {"view": "ISO:X"},
    "smalltackle.p3d":         {"view": "ISO"},
    # The boat is 5.9m long on Y, so the automatic upright guess stands it on
    # its stern. Its materials are also ordered motor-then-hull, the reverse
    # of the config's hull-then-motor texture list.
    "geb_jonboat.p3d":         {"view": "ISO:Z", "reverse_textures": True},
    "fishingline_biggame.p3d": {"view": "ISO", "texture": "data/tools/fishingline_biggame_co.paa"},
    "spinner.p3d":             {"view": "MID"},
    # Live bait shares the bait sheet, so face them all the same way.
    "grasshopper.p3d":         {"flip_h": True},
    "grub.p3d":                {"flip_h": True},
}


def main():
    classes = {}
    for cfg in glob.glob(os.path.join(REPO, "data", "*", "config.cpp")):
        for name, info in B.find_classes(B.read(cfg)).items():
            info["model"], info["textures"] = B.own_fields(info["body"])
            classes.setdefault(name, info)

    seen, manifest = set(), []
    for name in sorted(classes):
        # Abstract bases duplicate a concrete variant's model+texture pair.
        if "base" in name.lower():
            continue
        model = B.inherited(name, classes, "model")
        if not model:
            continue
        model_path = B.to_local(model)
        if not model_path or not os.path.isfile(model_path):
            continue
        # Fish are covered by build_fish_manifest.py.
        if os.sep + "fish" + os.sep in model_path.lower():
            continue

        textures = B.inherited(name, classes, "textures") or []
        # Keep the whole list: hiddenSelections map 1:1 onto material slots,
        # so a multi-part model (jon boat hull + outboard motor) needs each.
        tex_paths = []
        for t in textures:
            p = B.to_local(t)
            tex_paths.append(p if p and os.path.isfile(p) else None)
        while tex_paths and tex_paths[-1] is None:
            tex_paths.pop()
        tex_path = tex_paths[0] if tex_paths else None

        key = (model_path.lower(), "|".join(str(t).lower() for t in tex_paths))
        if key in seen:
            continue
        seen.add(key)
        entry = {"name": name, "p3d": model_path, "texture": tex_path}
        if len(tex_paths) > 1:
            entry["textures"] = tex_paths

        ov = MODEL_OVERRIDES.get(os.path.basename(model_path).lower())
        if ov:
            if ov.get("view"):
                entry["view"] = ov["view"]
            if ov.get("texture"):
                forced = os.path.join(REPO, ov["texture"].replace("/", os.sep))
                if os.path.isfile(forced):
                    entry["texture"] = forced
            if ov.get("reverse_textures") and len(tex_paths) > 1:
                entry["textures"] = list(reversed(tex_paths))
            for flag in ("flip_h", "flip_v", "roll"):
                if ov.get(flag):
                    entry[flag] = True
        manifest.append(entry)

    models = {}
    for e in manifest:
        models.setdefault(os.path.basename(e["p3d"]), []).append(e["name"])
    sys.stderr.write("item variants: %d across %d models\n" % (len(manifest), len(models)))
    for m, names in sorted(models.items(), key=lambda kv: -len(kv[1])):
        sys.stderr.write("   %-24s %d\n" % (m, len(names)))
    no_tex = [e["name"] for e in manifest if not e["texture"]]
    sys.stderr.write("without texture: %d %s\n" % (len(no_tex), ", ".join(no_tex[:8])))

    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
