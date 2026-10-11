# Prepare the wiki's per-item assets: a trimmed thumbnail for every piece of
# gear, bait and lure, plus its English description, written into docs/ for
# GitHub Pages.
#
#   python tools/build_wiki_items.py [renders_dir]     (default: gear_renders on your Desktop)
#
# The gear counterpart to build_wiki_assets.py, and it reuses that script's
# stringtable lookup so item text comes from exactly the same place as fish
# text -- each class's descriptionShort resolved through stringtable.csv, so
# the site always shows what the game shows.
#
# Renders are cropped to the subject and saved as WebP: the source PNGs are
# ~48 MB, which has no business in a git repo for a web page.

import glob
import html
import json
import os
import re
import sys

from PIL import Image

# Same folder, so the fish builder's helpers are importable rather than copied.
from build_wiki_assets import attribute_keys, config_classes, desktop_dir, english_table

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
DOCS_IMG = os.path.join(REPO, "docs", "items")
OUT_JS = os.path.join(REPO, "docs", "item-details.js")

MAX_W, MAX_H = 420, 300

# Which tab each render belongs under. Checked in order, first match wins, so
# the specific patterns have to come before the loose ones. The containers are
# named after what they hold (geb_WormContainer, geb_MinnowBucket = the Bait
# Bucket), so they're matched as gear before the bait words can claim them.
# Anything unmatched lands in "gear", which is the safe default -- it shows up
# rather than silently disappearing.
CATEGORIES = [
    # The rubber worm is a soft plastic lure, though its name says bait (as
    # make_posters.py files it); it's matched here before "Worm" can claim it.
    ("lure",  ("Lure", "SpinnerBait", "SpoonLure", "CurlyTailJig", "RubberWorm")),
    ("gear",  ("Container", "Bucket")),
    ("bait",  ("Worm", "Cricket", "GrassHopper", "Grub", "Minnow")),
    ("boat",  ("jonboat",)),
    ("gear",  ()),
]


def categorise(cls):
    for name, needles in CATEGORIES:
        for n in needles:
            if n.lower() in cls.lower():
                return name
    return "gear"


def prettify(cls):
    """Readable fallback when a class has no displayName: geb_BlueFishKnife -> Blue Fish Knife."""
    name = cls[4:] if cls.lower().startswith("geb_") else cls
    name = name.replace("_", " ")
    name = re.sub(r"(?<=[a-z])(?=[A-Z])", " ", name)
    name = re.sub(r"(?<=[A-Za-z])(?=\d)", " ", name)
    return name.strip().title()


SCOPE = re.compile(r"\bscope\s*=\s*(\d+)\s*;")
PREFIX = "const ITEMDETAIL = "


def top_level(body):
    """A class body without anything inside nested braces (nested classes,
    arrays), so a nested class's scope can't be read as this class's."""
    out, depth = [], 0
    for ch in body:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
        elif depth == 0:
            out.append(ch)
    return "".join(out)


def item_scope(cls, classes):
    """The class's scope, its own or inherited; None when no class in the mod's
    configs sets one (the chain runs on into vanilla)."""
    seen, cur = set(), cls
    while cur and cur in classes and cur not in seen:
        seen.add(cur)
        parent, body = classes[cur]
        found = SCOPE.search(top_level(body))
        if found:
            return int(found.group(1))
        cur = parent
    return None


def listed(cls, classes):
    """Belongs in the wiki: the configs still define it, and it isn't a hidden
    base class or alias (scope 0 or 1)."""
    return cls in classes and item_scope(cls, classes) in (None, 2)


def load_existing():
    """item-details.js's entries as they are now; None if it can't be read."""
    if not os.path.exists(OUT_JS):
        return {}
    with open(OUT_JS, "r", encoding="utf-8") as fh:
        text = fh.read()
    start = text.find(PREFIX)
    if start < 0:
        return None
    try:
        return json.loads(text[start + len(PREFIX):].strip().rstrip(";"))
    except ValueError:
        return None


def main():
    renders = sys.argv[1] if len(sys.argv) > 1 else desktop_dir("gear_renders")
    if not os.path.isdir(renders):
        print("renders dir not found: %s" % renders)
        return 1
    pngs = sorted(glob.glob(os.path.join(renders, "*.png")))
    # Without renders this would still rewrite item-details.js, with nothing in
    # it, so stop before touching docs/ (as build_wiki_assets.py does).
    if not pngs:
        print("no PNG renders in %s -- nothing written" % renders)
        return 1
    existing = load_existing()
    if existing is None:
        print("%s can't be read -- fix or delete it first; nothing written" % OUT_JS)
        return 1
    os.makedirs(DOCS_IMG, exist_ok=True)

    classes = config_classes()
    keys = attribute_keys("descriptionShort", classes)
    names = attribute_keys("displayName", classes)
    table = english_table()

    def entry(cls):
        # Escaped because the page injects it with innerHTML.
        label = table.get(names.get(cls, ""), "") or prettify(cls)
        return {
            "name": html.escape(label),
            "img": "items/%s.webp" % cls,
            "desc": html.escape(table.get(keys.get(cls, ""), "")),
            "cat": categorise(cls),
        }

    # Start from what the page lists now, so rendering a few items replaces
    # only those. Every entry's text is refreshed from the configs, and an
    # entry whose class is gone or hidden is dropped: a removed item can't
    # linger, and an old render left in the folder can't bring one back.
    details, dropped, skipped = {}, [], []
    for cls in existing:
        if listed(cls, classes):
            details[cls] = entry(cls)
        else:
            dropped.append(cls)

    rendered = 0
    for path in pngs:
        cls = os.path.splitext(os.path.basename(path))[0]
        if not listed(cls, classes):
            skipped.append(cls)
            continue
        img = Image.open(path).convert("RGBA")
        bbox = img.getbbox()
        if bbox:
            img = img.crop(bbox)
        img.thumbnail((MAX_W, MAX_H), Image.LANCZOS)
        img.save(os.path.join(DOCS_IMG, cls + ".webp"), "WEBP", quality=86, method=6)
        details[cls] = entry(cls)
        rendered += 1

    with open(OUT_JS, "w", encoding="utf-8") as fh:
        fh.write("// Generated by tools/build_wiki_items.py -- do not edit by hand.\n")
        fh.write(PREFIX)
        json.dump(details, fh, ensure_ascii=False, indent=0, sort_keys=True)
        fh.write(";\n")

    total = sum(os.path.getsize(os.path.join(DOCS_IMG, f)) for f in os.listdir(DOCS_IMG))
    counts = {}
    for v in details.values():
        counts[v["cat"]] = counts.get(v["cat"], 0) + 1
    no_desc = sorted(c for c, v in details.items() if not v["desc"])

    print("images written : %d of %d renders  (%.1f MB total in docs/items/)" % (rendered, len(pngs), total / 1048576.0))
    print("entries        : %d  (%s)" % (len(details), ", ".join("%s %d" % (k, counts[k]) for k in sorted(counts))))
    print("descriptions   : %d of %d have text" % (len(details) - len(no_desc), len(details)))
    if no_desc:
        print("no description : %s" % ", ".join(no_desc))
    if skipped:
        print("not rendered   : %s (gone from the configs, or not scope 2)" % ", ".join(sorted(skipped)))
    if dropped:
        print("dropped        : %s (gone from the configs, or not scope 2)" % ", ".join(sorted(dropped)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
