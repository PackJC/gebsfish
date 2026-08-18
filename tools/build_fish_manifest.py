# Build a species -> (model, texture) manifest for the render tool.
#
# Several species share one .p3d and differ only by texture (every crayfish
# uses crayfish.p3d; both lobsters use lobster.p3d), so rendering one image
# per .p3d file misses them. This walks data/fish/config.cpp, resolves each
# species class through its inheritance chain to find the model it uses and
# the first entry of its hiddenSelectionsTextures (the raw/uncooked skin),
# and writes a manifest the renderer can iterate.
#
#   python tools/build_fish_manifest.py > tools/fish_manifest.json

import json
import os
import re
import sys

# Species whose pectoral span makes the model wider than it is tall. The
# renderer's default rule (look down the thinnest axis) then produces a
# top-down view, so these are pinned to "MID" -- look down the middle axis --
# to get a proper lateral profile.
VIEW_OVERRIDES = {
    "geb_GreatWhiteShark": "MID",
    "geb_HammerHeadShark": "MID",
    "geb_LeopardShark": "MID",
    "geb_LakeSturgeon": "MID",
    "geb_SlimySculpin": "MID",
    "geb_NorthernSnakeHead": "MID",
    "geb_FlatHeadCatFish": "MID",
}

# Species where the "bulk sits forward" head test guesses backwards, so the
# swim wave travels from tail to head and the animation looks reversed.
FLIP_HEAD = {
    "geb_SiameseTigerFish",
}

# Viewed from the wrong side: the camera moves to the far side of the model,
# which shows a crayfish's carapace instead of its belly and turns a fish
# that faced left to face right like every other species.
FLIP_H = {
    "geb_SignalCrayFish", "geb_EuropeanCrayFish", "geb_FloridaCrayFish",
    "geb_CaveCrayFish", "geb_MonongahelaCrayFish", "geb_RedSwampCrayFish",
    "geb_RustyCrayFish",
    "geb_FatHeadMinnow",
}

# Turn 90 degrees in frame. The frog's widest axis is its splayed legs, not
# its body, so by default it lands head-up instead of facing sideways like
# the rest of the live bait.
ROLL = {
    "geb_AmericanBullFrog",
}

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONFIG = os.path.join(REPO, "data", "fish", "config.cpp")
SEEDS = os.path.join(REPO, "scripts", "3_game", "FileGenerators", "gebsfishConfig.c")


def read(path):
    with open(path, "r", encoding="utf-8", errors="ignore") as fh:
        return fh.read()


def find_classes(text):
    """Map every class name to its parent and its raw body text."""
    classes = {}
    for m in re.finditer(r'class\s+(\w+)\s*(?::\s*(\w+))?\s*\{', text):
        name, parent = m.group(1), m.group(2)
        start = m.end() - 1
        depth, j = 0, start
        while j < len(text):
            if text[j] == '{':
                depth += 1
            elif text[j] == '}':
                depth -= 1
                if depth == 0:
                    break
            j += 1
        classes[name] = {"parent": parent, "body": text[start + 1:j]}
    return classes


def own_fields(body):
    """Pull `model` and `hiddenSelectionsTextures` declared by this class
    itself, ignoring anything inside nested subclasses."""
    model, textures = None, None
    depth, i = 0, 0
    while i < len(body):
        c = body[i]
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
        elif depth == 0:
            if model is None and body.startswith("model", i):
                m = re.match(r'model\s*=\s*"([^"]*)"', body[i:])
                if m:
                    model = m.group(1)
            elif textures is None and body.startswith("hiddenSelectionsTextures", i):
                m = re.match(r'hiddenSelectionsTextures\s*\[\s*\]\s*=\s*\{(.*?)\}', body[i:], re.S)
                if m:
                    found = [t for t in re.findall(r'"([^"]+)"', m.group(1)) if t.strip()]
                    if found:
                        textures = found
        i += 1
    return model, textures


def inherited(name, classes, field):
    """Walk up the inheritance chain for the first class that defines field."""
    seen = set()
    while name and name in classes and name not in seen:
        seen.add(name)
        value = classes[name][field]
        if value:
            return value
        name = classes[name]["parent"]
    return None


def to_local(arma_path):
    """\\gebsfish\\data\\fish\\x.paa -> <repo>/data/fish/x.paa"""
    if not arma_path:
        return None
    p = arma_path.replace("\\", "/").lstrip("/")
    if p.lower().startswith("gebsfish/"):
        p = p[len("gebsfish/"):]
    return os.path.join(REPO, p.replace("/", os.sep))


def main():
    classes = find_classes(read(CONFIG))
    for info in classes.values():
        info["model"], info["textures"] = own_fields(info["body"])

    species = re.findall(r'f\.Classname="([^"]+)"', read(SEEDS))

    manifest, skipped = [], []
    for name in species:
        if name not in classes:
            skipped.append((name, "vanilla / not defined in data/fish/config.cpp"))
            continue
        model = inherited(name, classes, "model")
        textures = inherited(name, classes, "textures")
        model_path = to_local(model)
        if not model_path or not os.path.isfile(model_path):
            skipped.append((name, "model missing: %s" % model))
            continue
        # First entry is the raw skin; the rest are cooking states.
        tex_path = to_local(textures[0]) if textures else None
        if tex_path and not os.path.isfile(tex_path):
            tex_path = None
        entry = {
            "name": name,
            "p3d": model_path,
            "texture": tex_path,
        }
        if name in VIEW_OVERRIDES:
            entry["view"] = VIEW_OVERRIDES[name]
        if name in FLIP_HEAD:
            entry["flip_head"] = True
        if name in FLIP_H:
            entry["flip_h"] = True
        if name in ROLL:
            entry["roll"] = True
        manifest.append(entry)

    sys.stderr.write("species in config : %d\n" % len(species))
    sys.stderr.write("renderable        : %d\n" % len(manifest))
    sys.stderr.write("skipped           : %d\n" % len(skipped))
    for name, why in skipped:
        sys.stderr.write("   - %-28s %s\n" % (name, why))

    models = {}
    for e in manifest:
        models.setdefault(os.path.basename(e["p3d"]), []).append(e["name"])
    shared = {k: v for k, v in models.items() if len(v) > 1}
    sys.stderr.write("\nshared models (%d):\n" % len(shared))
    for model, names in sorted(shared.items()):
        sys.stderr.write("   %-24s %d: %s\n" % (model, len(names), ", ".join(names)))

    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
