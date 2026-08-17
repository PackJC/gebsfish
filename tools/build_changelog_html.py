"""Render CHANGELOG.md into the wiki's Changelog tab.

The site used to carry a hand-written summary of the current release only, which
drifted from CHANGELOG.md and dropped the version history entirely. This turns
the markdown into the tab's markup so there is one source of truth: edit
CHANGELOG.md, re-run this, done.

    python tools/build_changelog_html.py

Rewrites only the region between the CHANGELOG:START / CHANGELOG:END markers in
docs/index.html; everything else in the page is left byte-for-byte alone.

Markdown handled (all that CHANGELOG.md actually uses):
    ## v4.0.0 - Unreleased    release heading
    ### New Systems           section heading
    - item                    bullet
        * sub-item            nested bullet
    **bold**  `code`  [text](url)   inline
"""

import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "CHANGELOG.md")
DST = os.path.join(ROOT, "docs", "index.html")

START = "<!-- CHANGELOG:START -->"
END = "<!-- CHANGELOG:END -->"


def esc(s):
    return s.replace("&", "&amp;").replace("<", "&lt;").replace(">", "&gt;")


def inline(s):
    """Markdown inline -> HTML. Escape first, then re-introduce our own tags."""
    s = esc(s)
    s = re.sub(r"`([^`]+)`", r"<code>\1</code>", s)
    s = re.sub(r"\*\*([^*]+)\*\*", r"<b>\1</b>", s)
    s = re.sub(r"\[([^\]]+)\]\(([^)]+)\)", r'<a href="\2">\1</a>', s)
    return s


def parse(md):
    """-> [(release_title, [(section_title, [(text, [subitems])])])]"""
    releases = []
    section = None
    items = None

    for raw in md.splitlines():
        line = raw.rstrip()
        if line.startswith("## "):
            releases.append((line[3:].strip(), []))
            section = None
            items = None
            continue
        if not releases:
            continue                       # skip the file's own "# Changelog"
        if line.startswith("### "):
            items = []
            section = (line[4:].strip(), items)
            releases[-1][1].append(section)
            continue
        if items is None:
            continue                       # prose between headings: not used by the tab

        sub = re.match(r"^\s{2,}\*\s+(.*)$", line)
        if sub and items:
            items[-1][1].append(sub.group(1).strip())
            continue
        top = re.match(r"^-\s+(.*)$", line)
        if top:
            items.append((top.group(1).strip(), []))
    return releases


def render(releases):
    out = []
    for ri, (title, sections) in enumerate(releases):
        if not sections:
            continue
        # Every release is a collapsible block; the newest starts open so the page
        # still lands on current content instead of a wall of closed summaries.
        openattr = " open" if ri == 0 else ""
        out.append('  <details class="faq-item"%s><summary>%s</summary><div class="chg">'
                   % (openattr, esc(title)))
        for sec_title, items in sections:
            out.append("    <h3>" + esc(sec_title) + "</h3>")
            out.append("    <ul>")
            for text, subs in items:
                if subs:
                    out.append("      <li>" + inline(text))
                    out.append("        <ul>")
                    for s in subs:
                        out.append("          <li>" + inline(s) + "</li>")
                    out.append("        </ul>")
                    out.append("      </li>")
                else:
                    out.append("      <li>" + inline(text) + "</li>")
            out.append("    </ul>")
        out.append("  </div></details>")
    return "\n".join(out)


def main():
    md = io.open(SRC, encoding="utf-8").read()
    releases = parse(md)
    if not releases:
        print("no releases parsed - aborting")
        return 1

    html = render(releases)
    page = io.open(DST, encoding="utf-8").read()
    if START not in page or END not in page:
        print("markers not found in %s - add %s and %s" % (DST, START, END))
        return 1

    head, rest = page.split(START, 1)
    _, tail = rest.split(END, 1)
    io.open(DST, "w", encoding="utf-8", newline="").write(
        head + START + "\n" + html + "\n  " + END + tail)

    total_items = sum(len(i) for _, secs in releases for _, i in secs)
    print("releases : %d" % len(releases))
    for t, secs in releases:
        print("   %-28s %d sections" % (t, len(secs)))
    print("bullets  : %d" % total_items)
    print("written  : %s" % DST)
    return 0


if __name__ == "__main__":
    sys.exit(main())
