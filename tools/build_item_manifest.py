# Manifest for every NON-fish item in the mod (tackle, tools, vehicles,
# clothes...).
#
# Same story as the fish: one .p3d serves many item variants via
# hiddenSelectionsTextures (one cooler model -> 11 colours, one spinner ->
# 4 patterns), so rendering per-.p3d would produce untextured placeholders
# and miss every variant.
#
#   python tools/build_item_manifest.py [out.json]     (default tools/item_manifest.json)
#
# Writes the file itself as UTF-8 with repo-relative paths, like
# build_fish_manifest.py (a PowerShell `>` redirect would write UTF-16).
#
# Every class in the CfgVehicles of data/*/config.cpp either gets an entry or
# is listed under "skipped" with the reason (base classes, vanilla classes the
# mod only modifies, missing models); the fish config is build_fish_manifest.py's.
#
# Items on a vanilla model (the colour rods, the clothes, the rubber worm) keep
# its game path (\dz\...). The repo holds none of DayZ's own files, so
# render_p3d.py --dz <folder> finds those models in a local extraction that
# tools/extract_vanilla.py builds.

import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import build_fish_manifest as B

REPO = B.REPO

# The model each vanilla parent class gives the mod's items. DayZ's own config
# names it (CfgVehicles model=...), and the repo doesn't have that config.
VANILLA_MODELS = {
    "TShirt_ColorBase":      r"\dz\characters\tops\tshirt_ground.p3d",
    "Raincoat_ColorBase":    r"\dz\characters\tops\raincoat_g.p3d",
    "Wellies_ColorBase":     r"\dz\characters\shoes\wellies_ground.p3d",
    "NBCGloves_ColorBase":   r"\dz\characters\gloves\nbc_gloves_g.p3d",
    "BaseballCap_ColorBase": r"\dz\characters\headgear\baseballcap_ground.p3d",
    "FishingRod":            r"\dz\gear\tools\fishing_rod.p3d",
}

# Per-model presentation fixes, keyed by .p3d basename so every colour
# variant inherits them.
#   ISO  - containers and gear: an axis-aligned view of a bucket or tackle
#          box just shows a flat lid or side, and ISO keeps the upright axis
#          up so handles stay on top
#   MID  - spinner: the blade sits edge-on and pointing down in the default
#          view; looking down the middle axis turns it face-on to camera
#   texture - the p3d's embedded reference is wrong or missing
#   tilt - degrees the picture turns counter-clockwise: long items and lures
#          rise to the right like a product shot instead of lying flat
#   reverse_slots - the model's material slots run the other way round from
#          the config's hiddenSelections, so textures and materials go back to front
#   model - picture this model instead (a worn one, where the ground model
#          lies badly)
#   entry - which item of hiddenSelectionsTextures/Materials the pictured
#          model wears, where the config lists them per model rather than per
#          material slot (vanilla clothing: ground, male, female)
#   hide - named selections left out of the picture
MODEL_OVERRIDES = {
    # Boxy items need their upright axis forced: all three extents differ, so
    # the automatic "odd extent out" guess lays them on their side. The
    # cooler/tackle models are authored with Y up; the worm container is a
    # squat cylinder whose lid faces Z.
    "baitbucket.p3d":          {"view": "ISO", "texture": "data/tackle/baitbucket_co.paa"},
    "wormcontainer.p3d":       {"view": "ISO:Z"},
    "bugcatcher.p3d":          {"view": "ISO"},
    "bamboofishingnet.p3d":    {"view": "ISO"},
    "cooler.p3d":              {"view": "ISO:X"},
    "largetackle.p3d":         {"view": "ISO:X"},
    "mediumtackle.p3d":        {"view": "ISO:X:218"},   # latch side (the front) to camera
    "smalltackle.p3d":         {"view": "ISO"},
    # The boat is 5.9m long on Y, so the automatic upright guess stands it on
    # its stern. Its materials are also ordered motor-then-hull, the reverse
    # of the config's hull-then-motor texture and material lists.
    "geb_jonboat.p3d":         {"view": "ISO:Z", "reverse_slots": True},
    "fishingline_biggame.p3d": {"view": "ISO", "texture": "data/tools/fishingline_biggame_co.paa"},
    "spinner.p3d":             {"view": "MID", "tilt": 35},
    # Long items and lures rise to the right (Cole, 2026-10-05: "rendered sideways");
    # the jig turns over so its hook point rides up, as a jig is fished.
    "fishknife.p3d":           {"tilt": 35},
    "spoonlure.p3d":           {"tilt": 35},
    "curlytailjig.p3d":        {"flip_v": True, "tilt": 35},
    # The fish mounts hang on walls: face-on, from the front (+Z in the model).
    "smallfishmount.p3d":      {"view": "Y", "flip_h": True},
    "mediumfishmount.p3d":     {"view": "Y", "flip_h": True},
    "largefishmount.p3d":      {"view": "Y", "flip_h": True},
    # Live bait side-on with the head to the right (Cole, 2026-10-05: the
    # cricket and grasshopper showed top-down). Their spread legs make the side
    # the widest view, so MID; the grasshopper is modelled belly-up to the
    # others, so it turns over as well.
    "fieldcricket.p3d":        {"view": "MID"},
    "grasshopper.p3d":         {"view": "MID", "flip_h": True, "flip_v": True},
    "grub.p3d":                {"flip_h": True, "flip_v": True},
    # Hard lures nose to the right, the line tie leading (Cole, 2026-10-05).
    "popper.p3d":              {"flip_h": True},
    "purplecrank.p3d":         {"flip_h": True},
    "yellowcrank.p3d":         {"flip_h": True},
    "squarebill.p3d":          {"flip_h": True},
    # Vanilla models (render_p3d.py --dz). The tee and the raincoat lie folded,
    # seen from above; the gloves as a pair.
    "tshirt_ground.p3d":       {"view": "Z", "entry": 0},
    "raincoat_g.p3d":          {"view": "Z", "entry": 0},
    "nbc_gloves_g.p3d":        {"view": "ISO:Z", "entry": 0},
    # Vanilla's ground cap lies on its side, so a print on its front reads
    # sideways, and the ground wellies lie flat. Both show the worn model, with
    # the worn texture: the cap turned to its front print, the pair standing
    # with the logo and strap to camera.
    "baseballcap_ground.p3d":  {"model": r"\dz\characters\headgear\baseballcap_m.p3d", "entry": 1, "view": "ISO:Z:290"},
    "wellies_ground.p3d":      {"model": r"\dz\characters\shoes\wellies_m.p3d", "entry": 1, "view": "ISO:Z:340"},
    # Rods rise to the right like the other long items, the reel under the rod.
    "fishing_rod.p3d":         {"flip_v": True, "tilt": 35},
    # Vanilla's worm model holds a hooked worm and a loose one; the rubber worm
    # is pictured loose.
    "bait_worm.p3d":           {"hide": ["bait_hooked"]},
}

STRINGS_AND_COMMENTS = re.compile(r'"[^"\n]*"|//[^\n]*|/\*.*?\*/', re.S)
SCOPE = re.compile(r"\bscope\s*=\s*(\d+)\s*;")


def strip_comments(text):
    """The config without its // and /* */ comments; string literals are kept
    whole, so a // inside one survives."""
    return STRINGS_AND_COMMENTS.sub(lambda m: m.group(0) if m.group(0).startswith('"') else "", text)


def item_classes(text):
    """Names of the classes defined directly in class CfgVehicles: the items
    and their bases, not the DamageSystem and other classes nested in them."""
    found, stack = [], []
    for m in re.finditer(r'class\s+(\w+)\s*(?::\s*\w+)?\s*\{|[{}]', text):
        tok = m.group(0)
        if tok == "{":
            stack.append("")
        elif tok == "}":
            if stack:
                stack.pop()
        else:
            if len(stack) == 1 and stack[0].lower() == "cfgvehicles":
                found.append(m.group(1))
            stack.append(m.group(1))
    return found


def top_level(body):
    """A class body without anything inside nested braces, so a nested class's
    scope can't be read as this class's."""
    out, depth = [], 0
    for ch in body:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        elif depth == 0:
            out.append(ch)
    return "".join(out)


def item_scope(name, classes):
    """The class's scope, its own or inherited; None when no class of the mod's
    sets one (the chain runs on into vanilla)."""
    seen, cur = set(), name
    while cur and cur in classes and cur not in seen:
        seen.add(cur)
        m = SCOPE.search(top_level(classes[cur]["body"]))
        if m:
            return int(m.group(1))
        cur = classes[cur]["parent"]
    return None


def item_model(name, classes):
    """The model a class shows: its own or an inherited `model`, else the one a
    vanilla parent gives it (VANILLA_MODELS). Returns (model, None), or
    (None, <the vanilla class the chain ends in>) when there is none."""
    seen, cur = set(), name
    while cur and cur not in seen:
        seen.add(cur)
        info = classes.get(cur)
        if info and info["model"]:
            return info["model"], None
        if cur in VANILLA_MODELS:
            return VANILLA_MODELS[cur], None
        if info is None:
            return None, cur
        cur = info["parent"]
    return None, None


def ref(path, missing):
    """A config path as the manifest keeps it: repo-relative for the mod's own
    files, the game path for DayZ's (render_p3d.py --dz resolves those). A mod
    file that isn't in the repo gives None and goes on the `missing` list."""
    if not path:
        return None
    p = path.replace("/", "\\").lstrip("\\")
    if p.lower().startswith("dz\\"):
        return "\\" + p.lower()
    local = B.to_local(path)
    if local and os.path.isfile(local):
        return B.rel(local)
    missing.add(path)
    return None


def main():
    B.check_args("item_manifest.json")
    classes, candidates, fish_classes = {}, [], 0
    for cfg in sorted(glob.glob(os.path.join(REPO, "data", "*", "config.cpp"))):
        text = strip_comments(B.read(cfg))
        for name, info in B.find_classes(text).items():
            info["model"], info["textures"], info["materials"] = B.own_fields(info["body"])
            classes.setdefault(name, info)
        # Fish are covered by build_fish_manifest.py, and their fillets (on
        # vanilla fillet models) aren't wiki items.
        if os.path.basename(os.path.dirname(cfg)).lower() == "fish":
            fish_classes = len(item_classes(text))
        else:
            candidates += item_classes(text)

    seen, manifest, skipped, missing = {}, [], [], set()
    for name in sorted(set(candidates)):
        scope = item_scope(name, classes)
        if scope is None:
            skipped.append((name, "no scope in the mod's configs: a vanilla class the mod modifies"))
            continue
        if scope != 2:
            skipped.append((name, "scope %d: a base class, not an item" % scope))
            continue
        model, vanilla = item_model(name, classes)
        if not model:
            skipped.append((name, "no model: it comes from vanilla %s, which VANILLA_MODELS doesn't list" % vanilla
                            if vanilla else "no model"))
            continue
        model_ref = ref(model, missing)
        if not model_ref:
            skipped.append((name, "model not in the repo: %s" % model))
            continue
        ov = MODEL_OVERRIDES.get(os.path.basename(model.replace("\\", "/")).lower(), {})
        if ov.get("model"):
            model_ref = ref(ov["model"], missing)
            if not model_ref:
                skipped.append((name, "MODEL_OVERRIDES model not in the repo: %s" % ov["model"]))
                continue

        # Keep the whole lists: hiddenSelections map 1:1 onto material slots,
        # so a multi-part model (jon boat hull + outboard motor) needs each.
        textures = [ref(t, missing) for t in (B.inherited(name, classes, "textures") or [])]
        materials = [ref(m, missing) for m in (B.inherited(name, classes, "materials") or [])]
        if "entry" in ov:
            textures = textures[ov["entry"]:ov["entry"] + 1]
            materials = materials[ov["entry"]:ov["entry"] + 1]
        texture = textures[0] if textures else None
        if ov.get("texture"):
            forced = os.path.join(REPO, ov["texture"].replace("/", os.sep))
            if os.path.isfile(forced):
                texture = B.rel(forced)
        if ov.get("reverse_slots"):
            textures.reverse()
            materials.reverse()
        while textures and textures[-1] is None:
            textures.pop()
        while materials and materials[-1] is None:
            materials.pop()

        key = (model_ref.lower(), "|".join(str(t).lower() for t in textures),
               "|".join(str(m).lower() for m in materials))
        if key in seen:
            skipped.append((name, "same model, textures and materials as %s" % seen[key]))
            continue
        seen[key] = name
        entry = {"name": name, "p3d": model_ref, "texture": texture}
        if len(textures) > 1:
            entry["textures"] = textures
        if materials:
            entry["materials"] = materials
        if ov.get("view"):
            entry["view"] = ov["view"]
        for flag in ("flip_h", "flip_v", "roll"):
            if ov.get(flag):
                entry[flag] = True
        if ov.get("tilt"):
            entry["tilt"] = ov["tilt"]
        if ov.get("hide"):
            entry["hide"] = ov["hide"]
        manifest.append(entry)

    models = {}
    for e in manifest:
        models.setdefault(os.path.basename(e["p3d"].replace("\\", "/")), []).append(e["name"])
    sys.stderr.write("item variants: %d across %d models\n" % (len(manifest), len(models)))
    for m, names in sorted(models.items(), key=lambda kv: -len(kv[1])):
        sys.stderr.write("   %-24s %d\n" % (m, len(names)))
    no_tex = [e["name"] for e in manifest if not e["texture"]]
    sys.stderr.write("without texture: %d %s\n" % (len(no_tex), ", ".join(no_tex[:8])))
    vanilla = [e["name"] for e in manifest if e["p3d"].startswith("\\")]
    if vanilla:
        sys.stderr.write("on vanilla models: %d (render_p3d.py --dz <tools/extract_vanilla.py folder>)\n" % len(vanilla))
    sys.stderr.write("skipped: %d\n" % len(skipped))
    for name, why in skipped:
        sys.stderr.write("   %-28s %s\n" % (name, why))
    if fish_classes:
        sys.stderr.write("   (data/fish/config.cpp's %d classes are build_fish_manifest.py's)\n" % fish_classes)
    if missing:
        sys.stderr.write("config files missing from the repo: %s\n" % ", ".join(sorted(missing)))

    B.write_manifest(manifest, "item_manifest.json")


if __name__ == "__main__":
    main()
