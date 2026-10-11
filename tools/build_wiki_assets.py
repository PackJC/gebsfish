# Prepare the wiki's per-species assets: a trimmed thumbnail for each fish
# and its English description, both written into docs/ for GitHub Pages.
#
#   python tools/build_wiki_assets.py [renders_dir]     (default: fish_renders_species on your Desktop)
#
# Images are cropped to the subject, scaled down and saved as WebP so 72
# species cost a few MB in the repo rather than ~40MB of full-size PNGs.
# Descriptions come from each class's descriptionShort key resolved through
# the stringtable, so the site shows the same text as the game.

import csv
import glob
import html
import json
import os
import re
import sys

from PIL import Image

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
STRINGS = os.path.join(REPO, "languagecore", "stringtable.csv")
DOCS_IMG = os.path.join(REPO, "docs", "fish")
OUT_JS = os.path.join(REPO, "docs", "fish-details.js")

MAX_W, MAX_H = 460, 330


def read(path):
    with open(path, "r", encoding="utf-8", errors="ignore") as fh:
        return fh.read()


def config_classes():
    """classname -> (parent, body) across every data config.

    Brace-matched rather than regex-delimited. The obvious pattern for a class
    body ends it at a closing brace preceded by tabs, which silently skips every
    class in a space-indented file -- data/vehicles/config.cpp is space-indented,
    which is why the jon boat never appeared to have any text. Counting braces
    handles both styles and nested classes without caring about whitespace.
    """
    classes = {}
    opener = re.compile(r'class\s+(\w+)\s*(?::\s*(\w+))?\s*\{')
    for cfg in glob.glob(os.path.join(REPO, "data", "*", "config.cpp")):
        text = read(cfg)
        for m in opener.finditer(text):
            depth = 0
            for j in range(m.end() - 1, len(text)):
                if text[j] == "{":
                    depth += 1
                elif text[j] == "}":
                    depth -= 1
                    if depth == 0:
                        classes.setdefault(m.group(1), (m.group(2), text[m.end():j]))
                        break
    return classes


def attribute_keys(attr, classes=None):
    """classname -> stringtable key for `attr`, following config inheritance.

    Walking the parent chain matters. Variant classes routinely declare only a
    scope and their textures and inherit everything else, so reading each class
    body in isolation reports them as having no text at all. The jon boat colours
    are the obvious case: geb_jonboat_base carries the description and all five
    variants inherit it.
    """
    if classes is None:
        classes = config_classes()
    pattern = re.compile(attr + r'\s*=\s*"\$?([^"]+)"')
    keys = {}
    for cls in classes:
        seen, cur = set(), cls
        while cur and cur in classes and cur not in seen:
            seen.add(cur)          # cycle guard -- a typo'd config shouldn't hang the build
            parent, body = classes[cur]
            found = pattern.search(body)
            if found:
                keys[cls] = found.group(1).lower()
                break
            cur = parent
    return keys


def description_keys():
    """classname -> descriptionShort stringtable key, from every config."""
    return attribute_keys("descriptionShort")


def english_table():
    table = {}
    with open(STRINGS, "r", encoding="utf-8-sig", errors="ignore") as fh:
        for row in csv.reader(fh):
            if len(row) > 2 and row[0]:
                table[row[0].strip().lower()] = row[2].strip()
    return table


def desktop_dir(name):
    """Default render folders live on the user's Desktop."""
    return os.path.join(os.path.expanduser("~"), "Desktop", name)


def main():
    renders = sys.argv[1] if len(sys.argv) > 1 else desktop_dir("fish_renders_species")
    pngs = sorted(glob.glob(os.path.join(renders, "*.png")))
    # Without renders this would still rewrite fish-details.js, with every
    # rendered species' image gone, so stop before touching docs/.
    if not pngs:
        print("no PNG renders in %s -- nothing written" % renders)
        return 1
    os.makedirs(DOCS_IMG, exist_ok=True)

    keys, table = description_keys(), english_table()
    # The catchable species, from the seeds. A render of anything else (a
    # removed species, a fillet) is skipped before its picture is written,
    # so an old render left in the folder can't put a deleted picture back.
    seeds = os.path.join(REPO, "scripts", "3_game", "FileGenerators", "gebsfishConfig.c")
    species = set(re.findall(r'f\.Classname="([^"]+)"', read(seeds)))

    details, written, no_desc, skipped = {}, 0, [], []
    for path in pngs:
        cls = os.path.splitext(os.path.basename(path))[0]
        if cls not in species:
            skipped.append(cls)
            continue

        img = Image.open(path).convert("RGBA")
        bbox = img.getbbox()
        if bbox:
            img = img.crop(bbox)
        img.thumbnail((MAX_W, MAX_H), Image.LANCZOS)
        img.save(os.path.join(DOCS_IMG, cls + ".webp"), "WEBP", quality=86, method=6)
        written += 1

        desc = table.get(keys.get(cls, ""), "")
        if not desc:
            no_desc.append(cls)
        # Escaped here because the page injects it with innerHTML.
        details[cls] = {"img": "fish/%s.webp" % cls, "desc": html.escape(desc)}

    # Species not rendered this run keep the picture they already have in
    # docs/fish/ (rendering one species mustn't blank the others), and the
    # ones with no picture at all (the vanilla DayZ fish) still get their
    # text so the panel isn't empty. Restrict to the catchable species so the
    # payload stays small -- every tool and lure in the mod also has a
    # description, and none of them appear in the fish table.
    for cls in sorted(species):
        if cls in details:
            continue
        has_img = os.path.exists(os.path.join(DOCS_IMG, cls + ".webp"))
        desc = table.get(keys.get(cls, ""), "")
        if has_img or desc:
            details[cls] = {"img": ("fish/%s.webp" % cls) if has_img else "", "desc": html.escape(desc)}
    details = {k: v for k, v in details.items() if k in species}

    with open(OUT_JS, "w", encoding="utf-8") as fh:
        fh.write("// Generated by tools/build_wiki_assets.py -- do not edit by hand.\n")
        fh.write("const FISHDETAIL = ")
        json.dump(details, fh, ensure_ascii=False, indent=0, sort_keys=True)
        fh.write(";\n")

    total_kb = sum(os.path.getsize(os.path.join(DOCS_IMG, f))
                   for f in os.listdir(DOCS_IMG)) / 1024.0
    print("images written : %d  (%.1f MB total in docs/fish/)" % (written, total_kb / 1024))
    print("descriptions   : %d of %d entries have text"
          % (sum(1 for v in details.values() if v["desc"]), len(details)))
    if no_desc:
        print("no description : %s" % ", ".join(sorted(no_desc)[:12]))
    if skipped:
        print("not a species  : %s (no picture written)" % ", ".join(sorted(skipped)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
