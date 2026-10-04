"""Render CHANGELOG.md into the wiki's Changelog tab.

The site used to carry a hand-written summary of the current release only, which
drifted from CHANGELOG.md and dropped the version history entirely. This turns
the markdown into the tab's markup so there is one source of truth: edit
CHANGELOG.md, re-run this, done.

    python tools/build_changelog_html.py

Rewrites only the region between the CHANGELOG:START / CHANGELOG:END markers in
docs/index.html; everything else in the page is left byte-for-byte alone,
including its line endings and any byte-order mark.

Markdown handled (all that CHANGELOG.md actually uses):
    ## v3.3.3 - Unreleased    release heading
    ### New Systems           section heading
    - item  /  * item         bullet (either marker)
        * sub-item            nested bullet (indented, either marker)
    plain text                paragraph (under a release or inside a section)
    **bold**  `code`  [text](url)   inline
"""

import codecs
import io
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "CHANGELOG.md")
DST = os.path.join(ROOT, "docs", "index.html")

START = "<!-- CHANGELOG:START -->"
END = "<!-- CHANGELOG:END -->"

TOP_ITEM = re.compile(r"^[-*]\s+(.*)$")
SUB_ITEM = re.compile(r"^\s{2,}[-*]\s+(.*)$")


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
    """-> [(release_title, intro_blocks, [(section_title, blocks)])]

    A block is ("p", text) or ("ul", [(text, [subitems])]). Text between a
    release heading and its first section is the release's intro."""
    releases = []
    blocks = None          # where the current lines go: an intro or a section
    para = []              # prose lines of the paragraph being collected

    def flush():
        if para and blocks is not None:
            blocks.append(("p", " ".join(para)))
        del para[:]

    for raw in md.splitlines():
        line = raw.rstrip()
        if line.startswith("## "):
            flush()
            intro = []
            releases.append((line[3:].strip(), intro, []))
            blocks = intro
            continue
        if not releases:
            continue                       # the file's own "# Changelog" and anything before
        if line.startswith("### "):
            flush()
            blocks = []
            releases[-1][2].append((line[4:].strip(), blocks))
            continue
        if not line.strip():
            flush()
            continue

        sub = SUB_ITEM.match(line)
        if sub and blocks and blocks[-1][0] == "ul" and blocks[-1][1]:
            flush()
            blocks[-1][1][-1][1].append(sub.group(1).strip())
            continue
        top = TOP_ITEM.match(line) or sub  # a sub-item with no parent stands alone
        if top:
            flush()
            if not blocks or blocks[-1][0] != "ul":
                blocks.append(("ul", []))
            blocks[-1][1].append((top.group(1).strip(), []))
            continue
        para.append(line.strip())
    flush()
    return releases


def render_blocks(blocks, out):
    for kind, data in blocks:
        if kind == "p":
            out.append("    <p>" + inline(data) + "</p>")
            continue
        out.append("    <ul>")
        for text, subs in data:
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


def render(releases):
    out = []
    first = True
    for title, intro, sections in releases:
        sections = [(t, b) for t, b in sections if b]      # an empty heading says nothing
        if not intro and not sections:
            continue
        # Every release is a collapsible block; the newest starts open so the page
        # still lands on current content instead of a wall of closed summaries.
        openattr = " open" if first else ""
        first = False
        out.append('  <details class="faq-item"%s><summary>%s</summary><div class="chg">'
                   % (openattr, esc(title)))
        render_blocks(intro, out)
        for sec_title, blocks in sections:
            out.append("    <h3>" + esc(sec_title) + "</h3>")
            render_blocks(blocks, out)
        out.append("  </div></details>")
    return "\n".join(out)


def main():
    md = io.open(SRC, encoding="utf-8-sig").read()
    releases = parse(md)
    if not releases:
        print("no releases parsed - aborting")
        return 1

    # Keep the page's own line endings (and BOM, if any): with git's autocrlf
    # the working copy is CRLF, and rewriting it as LF would touch every line.
    raw = io.open(DST, "rb").read()
    bom = raw.startswith(codecs.BOM_UTF8)
    page = raw.decode("utf-8-sig")
    newline = "\r\n" if "\r\n" in page else "\n"
    page = page.replace("\r\n", "\n")
    if START not in page or END not in page:
        print("markers not found in %s - add %s and %s" % (DST, START, END))
        return 1

    head, rest = page.split(START, 1)
    _, tail = rest.split(END, 1)
    text = head + START + "\n" + render(releases) + "\n  " + END + tail
    data = text.replace("\n", newline).encode("utf-8")
    io.open(DST, "wb").write((codecs.BOM_UTF8 if bom else b"") + data)

    def count(blocks, kind):
        return sum(len(d) if kind == "ul" else 1 for k, d in blocks if k == kind)
    bullets = paragraphs = 0
    print("releases : %d" % len(releases))
    for title, intro, sections in releases:
        print("   %-28s %d sections" % (title, sum(1 for _, b in sections if b)))
        for blocks in [intro] + [b for _, b in sections]:
            bullets += count(blocks, "ul")
            paragraphs += count(blocks, "p")
    print("bullets  : %d" % bullets)
    print("paragraphs: %d" % paragraphs)
    print("written  : %s" % DST)
    return 0


if __name__ == "__main__":
    sys.exit(main())
