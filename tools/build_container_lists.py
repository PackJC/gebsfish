# Write the wiki's "What fits in each container" table from the containers'
# own allow-lists, so the page lists exactly what the game accepts.
#
#   python tools/build_container_lists.py
#
# Reads the s_Allowed / s_Refused / s_Exact lists in
# scripts/4_world/entities/itembase/gear/containers/containers.c (their
# "// group" comments become the groups), expands each entry the way the game
# matches it (a class and every class built on it, by config inheritance;
# s_Exact entries as themselves only), names everything with its English
# in-game name, and replaces the block between the container-lists markers in
# docs/index.html. Vanilla classes in the lists keep the names below, checked
# against vanilla's stringtable; a vanilla class that isn't in the table is
# shown by its classname, with a warning.

import html
import os
import re
import sys

from build_wiki_assets import attribute_keys, config_classes, english_table, read

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
CONTAINERS = os.path.join(REPO, "scripts", "4_world", "entities", "itembase", "gear", "containers", "containers.c")
INDEX = os.path.join(REPO, "docs", "index.html")
START, END = "<!-- container-lists:start -->", "<!-- container-lists:end -->"

# English names of the vanilla classes the lists name (vanilla's stringtable).
VANILLA = {
    "worm": "Earthworm", "jig": "Jig", "hook": "Fishing Hook", "bonehook": "Bone Fishing Hook",
    "woodenhook": "Wooden Fishing Hook", "boneknife": "Bone Knife", "pliers": "Pliers", "cleaver": "Cleaver",
    "combatknife": "Combat Knife", "huntingknife": "Hunting Knife", "ak_bayonet": "KA Bayonet",
    "m9a1_bayonet": "M4-A1 Bayonet", "screwdriver": "Screwdriver", "steakknife": "Steak Knife",
    "stoneknife": "Stone Knife", "shrimp": "Shrimp", "bitterlings": "Bitterlings", "sardines": "Sardines",
}

# What each container row covers: (title, a representative config class, the
# config classes it stands for). The script class each one uses comes from
# containers.c.
ROWS = [
    ("Worm Container", "geb_WormContainer", ["geb_WormContainer"]),
    ("Bug Catcher", "geb_BugContainer", ["geb_BugContainer"]),
    ("Bait Bucket", "geb_MinnowBucket", ["geb_MinnowBucket"]),
    ("Bamboo Fishing Net", "geb_BambooFishingNet", ["geb_BambooFishingNet"]),
    ("Small Tackle Box", "geb_SmallTackle", ["geb_SmallTackle"]),
    ("Tackle Box (large) and Old Tackle Box", "geb_Tackle_Base", ["geb_Tackle_Base", "geb_OldRedTackle"]),
    ("Cooler", "geb_Cooler_base", ["geb_Cooler_base"]),
]

COLOURS = ["Light Blue", "Blue", "Orange", "Green", "Yellow", "Red", "Purple", "Lime", "Camouflage", "Camo",
           "Brown", "Pink", "Black", "White", "Grey", "Gray"]

COOLER_TEXT = ("Any food or drink: every whole fish and shellfish, their fillets and caviar, live bait (worms, "
               "insects, minnows, frogs, salamanders, crayfish, shrimp), and every vanilla food and drink, canteens, "
               "water bottles and pots included. Not the Bait Bucket.")


def parse_lists(text):
    """script class -> {"allowed": [(group, entry)], "refused": [...], "exact": [...]}, plus the config class ->
    script class lines (class geb_X : geb_Y {};)."""
    lists, alias = {}, {}
    for m in re.finditer(r"class\s+(\w+)\s*:\s*(\w+)\s*\{\s*\};", text):
        alias[m.group(1)] = m.group(2)
    for m in re.finditer(r"class\s+(\w+)\s*:\s*\w+\s*\{", text):
        cls = m.group(1)
        depth, j = 0, m.end() - 1
        while j < len(text):
            if text[j] == "{":
                depth += 1
            elif text[j] == "}":
                depth -= 1
                if depth == 0:
                    break
            j += 1
        body = text[m.end():j]
        found = {}
        for lm in re.finditer(r"static\s+ref\s+TStringArray\s+(s_Allowed|s_Refused|s_Exact)\s*=\s*\{(.*?)\};", body, re.S):
            group, items = "", []
            for line in lm.group(2).split("\n"):
                c = re.match(r"\s*//\s*(.+?)\s*$", line)
                if c:
                    group = c.group(1)
                    continue
                for name in re.findall(r'"([^"]+)"', line):
                    items.append((group, name))
            found[{"s_Allowed": "allowed", "s_Refused": "refused", "s_Exact": "exact"}[lm.group(1)]] = items
        if found:
            lists[cls] = found
    return lists, alias


def main():
    classes = config_classes()
    lower = {c.lower(): c for c in classes}
    names = attribute_keys("displayName", classes)
    table = english_table()
    lists, alias = parse_lists(read(CONTAINERS))
    scope_rx = re.compile(r"\bscope\s*=\s*(\d+)\s*;")

    def top_level(body):
        out, depth = [], 0
        for ch in body:
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
            elif depth == 0:
                out.append(ch)
        return "".join(out)

    def scope(cls):
        seen, cur = set(), cls
        while cur and cur in classes and cur not in seen:
            seen.add(cur)
            parent, body = classes[cur]
            hit = scope_rx.search(top_level(body))
            if hit:
                return int(hit.group(1))
            cur = parent
        return None

    def is_kind(cls, base):
        seen, cur = set(), cls
        while cur and cur not in seen:
            if cur.lower() == base.lower():
                return True
            seen.add(cur)
            cur = classes[cur][0] if cur in classes else None
        return False

    def name_of(cls):
        if cls in classes:
            return table.get(names.get(cls, ""), "") or cls
        n = VANILLA.get(cls.lower())
        if not n:
            print("warning: no English name for vanilla class %s" % cls)
        return n or cls

    def expand(entry, exact):
        """Items the entry admits: the class itself (a vanilla class, or a mod class with scope 2) and, unless
        exact, every scope-2 mod class built on it."""
        out = []
        real = lower.get(entry.lower(), entry)
        if real in classes:
            if scope(real) in (None, 2):
                out.append(real)
        else:
            out.append(entry)
        if not exact:
            for c in classes:
                if c != real and scope(c) in (None, 2) and is_kind(c, entry):
                    out.append(c)
        return out

    def script_lists(config_cls):
        cur, seen = config_cls, set()
        while cur and cur not in seen:
            seen.add(cur)
            if cur in lists:
                return lists[cur]
            if cur in alias:
                cur = alias[cur]
                continue
            cur = classes[cur][0] if cur in classes else None
        return None

    def collapse(items):
        """Colour variants of one parent -> 'Fish Knife (10 colours: ...)'; numbered ones -> 'Spoon Lure #1-#4'."""
        groups, order = {}, []
        for cls in items:
            n = name_of(cls)
            parent = classes[cls][0] if cls in classes else None
            key, label = ("one", n), None
            num = re.match(r"(.+?) #(\d+)$", n)
            if num:
                key, label = ("num", num.group(1), parent), num.group(2)
            else:
                for col in COLOURS:
                    if n.startswith(col + " ") and parent:
                        key, label = ("col", n[len(col) + 1:], parent), col
                        break
            if key not in groups:
                groups[key] = []
                order.append(key)
            groups[key].append(label)
        out = []
        for key in order:
            labels = groups[key]
            if key[0] == "num" and len(labels) > 1:
                out.append("%s #%s–#%s" % (key[1], min(labels, key=int), max(labels, key=int)))
            elif key[0] == "col" and len(labels) > 1:
                out.append("%s (%d colours: %s)" % (key[1], len(labels), ", ".join(labels)))
            elif key[0] == "num":
                out.append("%s #%s" % (key[1], labels[0]))
            elif key[0] == "col":
                out.append("%s %s" % (labels[0], key[1]))
            else:
                out.append(key[1])
        return out

    rows_html = []
    for title, rep, members in ROWS:
        found = script_lists(rep)
        if not found:
            print("warning: no allow-list found for %s" % rep)
            continue
        cargo_text = []
        for mcls in members:
            cur, hit = mcls, None
            while cur in classes and not hit:
                hit = re.search(r"itemsCargoSize\[\]\s*=\s*\{\s*(\d+)\s*,\s*(\d+)\s*\}", classes[cur][1])
                cur = classes[cur][0]
            if hit:
                cargo_text.append("%s×%s" % hit.groups())
        if [e for g, e in found.get("allowed", [])] == ["Edible_Base"]:
            rows_html.append("        <tr><td><b>%s</b></td><td>%s</td><td>%s</td></tr>" % (
                html.escape(title), " / ".join(dict.fromkeys(cargo_text)), html.escape(COOLER_TEXT)))
            continue
        refused = [e for g, e in found.get("refused", [])]
        groups, seen = [], set()

        def add(group, cls_list):
            for c in cls_list:
                if c in seen or any(is_kind(c, r) for r in refused):
                    continue
                seen.add(c)
                if not groups or groups[-1][0] != group:
                    match = [g for g in groups if g[0] == group]
                    if match:
                        match[0][1].append(c)
                        continue
                    groups.append((group, [c]))
                else:
                    groups[-1][1].append(c)

        for group, entry in found.get("allowed", []):
            add(group, expand(entry, False))
        live = next((g for g, e in found.get("allowed", []) if "bait" in g.lower()), "")
        for group, entry in found.get("exact", []):
            add(live, expand(entry, True))
        parts = []
        for group, cls_list in groups:
            text = ", ".join(html.escape(n) for n in collapse(cls_list))
            label = group.replace(" / ", " and ") if group else ""
            parts.append(("<b>%s:</b> %s" % (html.escape(label[:1].upper() + label[1:]), text)) if label else text)
        rows_html.append("        <tr><td><b>%s</b></td><td>%s</td><td>%s</td></tr>" % (
            html.escape(title), " / ".join(dict.fromkeys(cargo_text)), "<br>".join(parts)))

    block = "\n".join([
        START,
        '  <h4 id="guide-what-fits">What fits in each container</h4>',
        "  <p>Everything each container takes, read from the mod's own allow-lists (an item also has to fit the free "
        "cargo space). Colour and numbered variants are grouped. Generated by <code>tools/build_container_lists.py</code>.</p>",
        '  <div class="tblwrap">',
        "    <table>",
        "      <thead><tr><th>Container</th><th>Cargo</th><th>Takes</th></tr></thead>",
        "      <tbody>",
    ] + rows_html + [
        "      </tbody>",
        "    </table>",
        "  </div>",
        "  " + END,
    ])
    page = open(INDEX, "rb").read().decode("utf-8")
    nl = "\r\n" if "\r\n" in page else "\n"
    page = page.replace("\r\n", "\n")
    if START in page:
        s = page.index(START)
        e = page.index(END, s) + len(END)
        page = page[:s] + block.lstrip() + page[e:]
    else:
        anchor = '<div class="banner warn"><b>The Bait Bucket will not accept worms or insects.</b>'
        i = page.index(anchor)
        j = page.index("\n", i) + 1
        page = page[:j] + "  " + block + "\n" + page[j:]
    open(INDEX, "wb").write(page.replace("\n", nl).encode("utf-8"))
    print("containers listed : %d" % len(rows_html))
    return 0


if __name__ == "__main__":
    sys.exit(main())
