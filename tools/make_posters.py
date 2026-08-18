# Build 1920x1080 category poster sheets from the species renders.
#
#   python tools/make_posters.py <renders_dir> <out_dir>
#
# Groups every rendered species by habitat and body plan, lays each group out
# over a procedurally generated underwater or seabed backdrop, and captions
# each with its in-game display name. Habitat comes from the Environment
# field in the config seeds (1 pond, 2 sea, 3 both) and names come from the
# stringtable, so the sheets stay truthful to what the mod ships.

import csv
import glob
import json
import math
import os
import re
import sys

import numpy as np
from PIL import Image, ImageDraw, ImageFilter, ImageFont

TOOLS = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(TOOLS)
SEEDS = os.path.join(REPO, "scripts", "3_game", "FileGenerators", "gebsfishConfig.c")
FISH_CFG = os.path.join(REPO, "data", "fish", "config.cpp")
STRINGS = os.path.join(REPO, "languagecore", "stringtable.csv")

FONT_BOLD = r"C:\Windows\Fonts\arialbd.ttf"
FONT_REG = r"C:\Windows\Fonts\arial.ttf"

W, H = 1920, 1080
HEAD, FOOT, PAD = 132, 46, 26

SHELLFISH = ("crayfish", "lobster", "crab", "shrimp", "clam", "mussel",
             "snail", "starfish", "jellyfish")
AMPHIBIAN = ("frog", "salamander")

THEMES = {
    "freshwater": {
        "title": "FRESHWATER SPECIES", "subtitle": "Ponds, lakes and rivers",
        "backdrop": "planted", "deep": (10, 34, 30), "shallow": (44, 104, 88),
        "accent": (170, 240, 200), "seed": 11,
    },
    "saltwater": {
        "title": "SALTWATER SPECIES", "subtitle": "Open sea and coastal waters",
        "backdrop": "water", "deep": (3, 14, 40), "shallow": (26, 84, 150),
        "accent": (140, 202, 255), "seed": 23,
    },
    "brackish": {
        "title": "FRESHWATER & SALTWATER", "subtitle": "Species found in both environments",
        "backdrop": "water", "deep": (6, 22, 38), "shallow": (30, 96, 122),
        "accent": (138, 220, 232), "seed": 37,
    },
    "shellfish": {
        "title": "CRUSTACEANS & SHELLFISH", "subtitle": "Trapped, netted and gathered",
        "backdrop": "sand", "deep": (96, 74, 46), "shallow": (198, 172, 126),
        "accent": (255, 226, 170), "seed": 53,
    },
    "bait": {
        "title": "LIVE BAIT", "subtitle": "Caught, dug and gathered for the hook",
        "backdrop": "planted", "deep": (12, 26, 12), "shallow": (60, 100, 46),
        "accent": (196, 232, 140), "seed": 71, "noun": "baits",
    },
}

# Bait that isn't a catchable species lives in the tackle folder, so it comes
# from the gear renders rather than the species renders.
BAIT_EXTRAS = ("geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm")

THEMES["gear"] = {
    "title": "GEAR & TACKLE", "subtitle": "Lures, tools, containers and kit",
    "backdrop": "slate", "deep": (16, 22, 28), "shallow": (58, 70, 82),
    "accent": (168, 200, 228), "seed": 97, "noun": "items",
}
THEMES["boats"] = {
    "title": "JON BOATS", "subtitle": "Every hull and camo pattern",
    "backdrop": "water", "deep": (5, 18, 44), "shallow": (34, 96, 156),
    "accent": (150, 208, 255), "seed": 113, "noun": "hull variants",
}
THEMES["lures"] = {
    "title": "HOOKS, LURES & TACKLE", "subtitle": "Jigs, spinners, spoons and crankbaits",
    "backdrop": "slate", "deep": (14, 20, 26), "shallow": (62, 66, 76),
    "accent": (198, 214, 236), "seed": 131, "noun": "items",
}

# Terminal tackle that goes on the line, split out from the containers and
# tools so each sheet reads as one kind of thing.
LURE_KEYS = ("jig", "spinner", "spoon", "crank", "popper", "squarebill", "lure")

# Each lure family gets its own column on the tackle sheet.
LURE_FAMILIES = ("jig", "spinner", "spoon", "crank", "popper", "squarebill")


def lure_family(label):
    low = label.lower()
    for i, key in enumerate(LURE_FAMILIES):
        if key in low:
            return i
    return len(LURE_FAMILIES)

def gear_rank(label):
    """Keep like with like on the gear sheet instead of alphabetising coolers,
    knives and boxes into one another. The old tackle boxes are their own
    band rather than being mixed in with the modern ones."""
    low = label.lower()
    if "cooler" in low:
        return 0
    if "tackle" in low:
        if low.startswith("old"):
            return 2
        if "small" in low:
            return 3
        return 1
    if "knife" in low:
        return 4
    if any(k in low for k in ("bucket", "container", "catcher")):
        return 5
    if any(k in low for k in ("net", "repair", "line")):
        return 6
    return 9

# The jon boat classnames carry no stringtable name, so caption them by the
# pattern rather than falling back to a raw "jonboat camo desert".
BOAT_NAMES = {
    "geb_jonboat_camo_desert": "Desert Camo",
    "geb_jonboat_camo_forest": "Forest Camo",
    "geb_jonboat_camo_snow": "Snow Camo",
    "geb_jonboat_grayaluminum": "Gray Aluminium",
    "geb_jonboat_greenaluminum": "Green Aluminium",
}


# --------------------------------------------------------------------------
# data
# --------------------------------------------------------------------------

def read(path):
    with open(path, "r", encoding="utf-8", errors="ignore") as fh:
        return fh.read()


def species_environments():
    out = {}
    for m in re.finditer(r'f\.Classname="([^"]+)".*?f\.Environment=(\d+)',
                         read(SEEDS), re.S):
        out.setdefault(m.group(1), int(m.group(2)))
    return out


def display_names():
    """classname -> English display name, from every config's displayName key."""
    keys = {}
    for cfg in glob.glob(os.path.join(REPO, "data", "*", "config.cpp")):
        for m in re.finditer(r'class\s+(\w+)\s*:[^{]*\{(.*?)\n\t*\}', read(cfg), re.S):
            d = re.search(r'displayName\s*=\s*"\$?([^"]+)"', m.group(2))
            if d:
                keys.setdefault(m.group(1), d.group(1).lower())

    table = {}
    with open(STRINGS, "r", encoding="utf-8-sig", errors="ignore") as fh:
        for row in csv.reader(fh):
            if len(row) > 2 and row[0]:
                table[row[0].strip().lower()] = row[2].strip()

    return {cls: table[key] for cls, key in keys.items() if table.get(key)}


def prettify(classname):
    n = classname[4:] if classname.startswith("geb_") else classname
    return re.sub(r"(?<!^)(?=[A-Z])", " ", n).replace("_", " ").strip()


# Within the shellfish sheet, keep relatives together rather than letting
# the alphabet scatter them (lobster, snail, clam, crayfish, ...).
SHELL_ORDER = (
    ("crayfish", 0), ("lobster", 1), ("crab", 2),
    ("clam", 3), ("mussel", 3), ("snail", 3),
    ("shrimp", 4), ("starfish", 5), ("jellyfish", 6),
)


def shell_rank(classname):
    low = classname.lower()
    for key, rank in SHELL_ORDER:
        if key in low:
            return rank
    return 9


def categorise(classname, env):
    low = classname.lower()
    if any(k in low for k in SHELLFISH):
        return "shellfish"
    if any(k in low for k in AMPHIBIAN):
        return "bait"          # frogs and salamanders are hook bait here
    return {1: "freshwater", 2: "saltwater", 3: "brackish"}.get(env, "freshwater")


# --------------------------------------------------------------------------
# procedural backdrops
# --------------------------------------------------------------------------

def fractal_noise(w, h, octaves, seed):
    """Sum progressively finer random layers -- cheap fractal/Perlin-ish noise."""
    rng = np.random.default_rng(seed)
    total = np.zeros((h, w), dtype=np.float32)
    amp, norm = 1.0, 0.0
    for o in range(octaves):
        res = 2 ** (o + 2)
        cell = rng.random((res, res)).astype(np.float32)
        layer = Image.fromarray((cell * 255).astype(np.uint8)).resize((w, h), Image.BICUBIC)
        total += amp * (np.asarray(layer, dtype=np.float32) / 255.0)
        norm += amp
        amp *= 0.5
    return total / norm


def vertical_gradient(w, h, top, bottom):
    t = np.linspace(0.0, 1.0, h, dtype=np.float32)[:, None]
    out = np.zeros((h, w, 3), dtype=np.float32)
    for c in range(3):
        out[:, :, c] = top[c] + (bottom[c] - top[c]) * t
    return out


def water_backdrop(theme):
    """Lit water: caustic veins, god rays from the surface, drifting motes."""
    seed = theme["seed"]
    img = vertical_gradient(W, H, theme["shallow"], theme["deep"])

    # Caustics: ridged noise sharpened into thin bright filaments, strongest
    # near the surface where the light enters.
    n = fractal_noise(W, H, 5, seed)
    veins = (1.0 - np.abs(2.0 * n - 1.0)) ** 4
    # Blur the filaments: unblurred they read as harsh lightning rather than
    # light rippling across water.
    veins = np.asarray(Image.fromarray((veins * 255).astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(5)), dtype=np.float32) / 255.0
    depth_falloff = np.clip(1.0 - np.linspace(0.0, 1.0, H, dtype=np.float32) * 1.15, 0, 1)[:, None]
    caustic = veins * depth_falloff * 78.0
    for c in range(3):
        img[:, :, c] += caustic * (0.55 + 0.15 * c)

    # God rays: wide soft wedges leaning in from the surface.
    rng = np.random.default_rng(seed + 1)
    xs = np.arange(W, dtype=np.float32)[None, :]
    ys = np.linspace(0.0, 1.0, H, dtype=np.float32)[:, None]
    rays = np.zeros((H, W), dtype=np.float32)
    for _ in range(7):
        x0 = rng.uniform(0, W)
        lean = rng.uniform(-0.35, 0.35) * W
        width = rng.uniform(70, 190)
        centre = x0 + lean * ys
        rays += np.exp(-((xs - centre) ** 2) / (2 * width ** 2)) * rng.uniform(0.5, 1.0)
    rays *= np.clip(1.0 - ys * 1.25, 0, 1) * 46.0
    for c in range(3):
        img[:, :, c] += rays * (0.7 + 0.12 * c)

    # Suspended particles.
    motes = np.zeros((H, W), dtype=np.float32)
    for _ in range(340):
        x, y = rng.integers(0, W), rng.integers(0, H)
        motes[max(0, y - 1):y + 2, max(0, x - 1):x + 2] = rng.uniform(40, 120)
    motes = np.asarray(Image.fromarray(motes.astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(1.6)), dtype=np.float32)
    img += motes[:, :, None] * 0.5

    return np.clip(img, 0, 255)


def sand_backdrop(theme):
    """Seabed: rippled sand with grain, grit and settled shadow."""
    seed = theme["seed"]
    img = vertical_gradient(W, H, theme["shallow"], theme["deep"])

    # Ripples: parallel bands warped by noise so they wander like real sand.
    warp = fractal_noise(W, H, 4, seed) - 0.5
    ys = np.linspace(0.0, 1.0, H, dtype=np.float32)[:, None]
    ripple = np.sin((ys * 34.0) + warp * 7.0)
    ripple = np.repeat(ripple, W, axis=1) if ripple.shape[1] == 1 else ripple
    shade = ripple * 15.0 * (0.45 + 0.55 * ys)
    for c in range(3):
        img[:, :, c] += shade

    # Grain and scattered grit.
    rng = np.random.default_rng(seed + 5)
    grain = (rng.random((H, W)).astype(np.float32) - 0.5) * 17.0
    for c in range(3):
        img[:, :, c] += grain

    grit = fractal_noise(W, H, 6, seed + 9)
    speck = np.clip((grit - 0.62) * 5.0, 0, 1) * 34.0
    for c in range(3):
        img[:, :, c] -= speck * (1.0 - 0.18 * c)

    # Light pooling from above.
    glow = np.exp(-((np.linspace(-1.4, 1.4, H, dtype=np.float32) + 0.7) ** 2) * 2.0)
    img += glow[:, None, None] * 26.0

    return np.clip(img, 0, 255)


def multi_gradient(w, h, stops):
    """Vertical gradient through several colour stops: (position, rgb)."""
    ys = np.linspace(0.0, 1.0, h, dtype=np.float32)
    pos = [s[0] for s in stops]
    out = np.zeros((h, w, 3), dtype=np.float32)
    for c in range(3):
        out[:, :, c] = np.interp(ys, pos, [s[1][c] for s in stops])[:, None]
    return out


def draw_reeds(rng, count, y_top, y_bottom, palette, width, sway, blur):
    """Aquatic stalks rising from the bed, each with a gentle S-curve.
    Far stalks are drawn thinner and blurred to fake depth of field."""
    layer = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    draw = ImageDraw.Draw(layer)
    for _ in range(count):
        x0 = rng.uniform(-60, W + 60)
        top = rng.uniform(y_top - 60, y_top + 150)
        bottom = rng.uniform(y_bottom - 40, y_bottom + 60)
        amp = rng.uniform(*sway)
        phase = rng.uniform(0.0, 6.28)
        colour = palette[int(rng.integers(0, len(palette)))]
        base_w = rng.uniform(*width)
        # Draw as a tapered ribbon rather than a constant-width line: a reed
        # is thick at the root and narrows to a tip, and equal-width strokes
        # read as flat green bars.
        left, right = [], []
        for i in range(25):
            t = i / 24.0
            y = top + (bottom - top) * t
            x = x0 + math.sin(phase + t * 3.1) * amp * (1.0 - t * 0.35)
            half = base_w * (0.18 + 0.82 * t) * 0.5
            left.append((x - half, y))
            right.append((x + half, y))
        draw.polygon(left + right[::-1], fill=colour)
    return layer.filter(ImageFilter.GaussianBlur(blur)) if blur else layer


def planted_backdrop(theme):
    """A weedy freshwater shallow: rippled surface, reed beds, mossy bottom."""
    seed = theme["seed"]
    rng = np.random.default_rng(seed)

    img = multi_gradient(W, H, [
        (0.00, (128, 196, 186)),   # bright water just under the surface
        (0.30, (58, 140, 128)),
        (0.62, (52, 118, 88)),
        (1.00, (104, 122, 54)),    # olive bed
    ])

    # Surface: wavy mirror bands across the top, fading down fast.
    ys = np.linspace(0.0, 1.0, H, dtype=np.float32)[:, None]
    xs = np.arange(W, dtype=np.float32)[None, :]
    warp = (fractal_noise(W, H, 4, seed + 1) - 0.5) * 26.0
    bands = np.sin((xs + warp) * 0.045) * np.sin((xs + warp) * 0.017 + 1.3)
    surface = np.clip(bands, 0, 1) * np.clip(1.0 - ys * 5.2, 0, 1) * 90.0
    for c in range(3):
        img[:, :, c] += surface * (0.85 + 0.08 * c)

    # Mossy bed with an uneven top edge.
    edge_noise = fractal_noise(W, 16, 4, seed + 2)[0]
    edge = H * 0.70 + (edge_noise - 0.5) * 120.0
    yy = np.repeat(np.arange(H, dtype=np.float32)[:, None], W, axis=1)
    bed = np.clip((yy - edge[None, :]) / 60.0, 0, 1)
    moss = fractal_noise(W, H, 6, seed + 3)
    bed_colour = np.stack([
        112 + moss * 58, 128 + moss * 62, 44 + moss * 46], axis=-1).astype(np.float32)
    img = img * (1 - bed[:, :, None]) + bed_colour * bed[:, :, None]
    # Grain and dark detritus so the bed doesn't read as flat paint.
    grit = np.clip((fractal_noise(W, H, 7, seed + 4) - 0.55) * 4.0, 0, 1)
    img -= (grit * bed * 46.0)[:, :, None]

    base = Image.fromarray(np.clip(img, 0, 255).astype(np.uint8), "RGB").convert("RGBA")

    # Reeds in three depth layers, far ones hazy and desaturated.
    far = draw_reeds(rng, 110, H * 0.10, H * 0.78,
                     [(70, 128, 100, 90), (84, 144, 108, 90), (62, 118, 96, 90)],
                     (4, 10), (6, 26), 8.0)
    mid = draw_reeds(rng, 60, H * 0.06, H * 0.80,
                     [(50, 112, 66, 135), (66, 132, 74, 135), (42, 100, 62, 135)],
                     (6, 14), (10, 34), 3.0)
    # Few and semi-transparent up front, so they frame the fish instead of
    # cutting across them.
    near = draw_reeds(rng, 14, H * 0.02, H * 0.86,
                      [(32, 86, 46, 165), (46, 102, 52, 165)],
                      (10, 20), (14, 44), 0.8)
    for layer in (far, mid, near):
        base.alpha_composite(layer)

    arr = np.asarray(base.convert("RGB"), dtype=np.float32)

    # Sunlight from the surface, and suspended motes.
    shafts = np.zeros((H, W), dtype=np.float32)
    for _ in range(6):
        x0 = rng.uniform(0, W)
        lean = rng.uniform(-0.3, 0.3) * W
        width = rng.uniform(90, 220)
        shafts += np.exp(-((xs - (x0 + lean * ys)) ** 2) / (2 * width ** 2))
    arr += (shafts * np.clip(1.0 - ys * 1.4, 0, 1) * 30.0)[:, :, None]

    motes = np.zeros((H, W), dtype=np.float32)
    for _ in range(260):
        x, y = rng.integers(0, W), rng.integers(0, int(H * 0.85))
        motes[y:y + 2, x:x + 2] = rng.uniform(50, 110)
    motes = np.asarray(Image.fromarray(motes.astype(np.uint8)).filter(
        ImageFilter.GaussianBlur(1.4)), dtype=np.float32)
    arr += motes[:, :, None] * 0.55

    return np.clip(arr, 0, 255)


def slate_backdrop(theme):
    """Neutral dark surface for hard goods -- gear shouldn't float in water."""
    seed = theme["seed"]
    img = multi_gradient(W, H, [
        (0.00, theme["shallow"]), (0.55, theme["deep"]),
        (1.00, tuple(max(0, c - 10) for c in theme["deep"])),
    ])
    grain = (fractal_noise(W, H, 6, seed) - 0.5) * 26.0
    img += grain[:, :, None]
    fine = np.random.default_rng(seed + 3).random((H, W)).astype(np.float32) - 0.5
    img += fine[:, :, None] * 9.0
    glow = np.exp(-((np.linspace(-1.5, 1.5, H, dtype=np.float32) + 0.85) ** 2) * 1.7)
    img += glow[:, None, None] * 30.0
    return np.clip(img, 0, 255)


def backdrop(theme):
    kind = theme["backdrop"]
    if kind == "planted":
        arr = planted_backdrop(theme)
    elif kind == "slate":
        arr = slate_backdrop(theme)
    else:
        arr = water_backdrop(theme) if kind == "water" else sand_backdrop(theme)
    bg = Image.fromarray(arr.astype(np.uint8), "RGB")

    # Vignette, and a dark band behind the header so the title stays legible.
    vig = Image.new("L", (W, H), 0)
    ImageDraw.Draw(vig).rectangle([int(W * 0.04), int(H * 0.03),
                                   int(W * 0.96), int(H * 0.97)], fill=255)
    vig = vig.filter(ImageFilter.GaussianBlur(120))
    bg = Image.composite(bg, Image.new("RGB", (W, H), (0, 0, 0)), vig)

    shade = Image.new("L", (W, H), 0)
    ImageDraw.Draw(shade).rectangle([0, 0, W, HEAD - 6], fill=110)
    shade = shade.filter(ImageFilter.GaussianBlur(38))
    return Image.composite(Image.new("RGB", (W, H), (0, 0, 0)), bg, shade)


# --------------------------------------------------------------------------
# layout
# --------------------------------------------------------------------------

def choose_grid(count):
    """Pick the column count that gives each species the most room on 1080p."""
    best = None
    for cols in range(3, 13):     # gear sheets need more columns than fish
        rows = math.ceil(count / cols)
        cw = (W - 2 * PAD) // cols
        ch = (H - HEAD - FOOT) // rows
        label = max(34, min(52, ch // 4))     # room for a wrapped second line
        area = (cw - 12) * (ch - label - 8)
        if ch - label - 8 < 48:
            continue
        if best is None or area > best[0]:
            best = (area, cols, rows, cw, ch, label)
    if best is None:
        cols = 8
        rows = math.ceil(count / cols)
        return cols, rows, (W - 2 * PAD) // cols, (H - HEAD - FOOT) // rows, 24
    return best[1], best[2], best[3], best[4], best[5]


def fit_label(draw, text, max_w, cache, base_size):
    """Fit a species name in the cell: shrink it, then wrap it onto two lines,
    and only truncate as a last resort. Chopping mid-word ('Largemouth Ba')
    makes the sheet look broken."""
    def font(size):
        if size not in cache:
            try:
                cache[size] = ImageFont.truetype(FONT_BOLD, size)
            except OSError:
                cache[size] = ImageFont.load_default()
        return cache[size]

    floor = max(11, base_size - 5)
    for size in range(base_size, floor - 1, -1):
        if draw.textlength(text, font=font(size)) <= max_w:
            return [(text, font(size))]

    words = text.split()
    if len(words) > 1:
        for size in range(base_size, floor - 1, -1):
            f = font(size)
            for cut in range(1, len(words)):
                a, b = " ".join(words[:cut]), " ".join(words[cut:])
                if max(draw.textlength(a, font=f), draw.textlength(b, font=f)) <= max_w:
                    return [(a, f), (b, f)]

    f = font(floor)
    trimmed = text
    while trimmed and draw.textlength(trimmed + "...", font=f) > max_w:
        trimmed = trimmed[:-1]
    return [(trimmed + "...", f)]


def count_split_groups(groups, cols):
    """How many groups get broken across a row boundary at this width."""
    index, splits = 0, 0
    for group in groups:
        if group and index // cols != (index + len(group) - 1) // cols:
            splits += 1
        index += len(group)
    return splits


def choose_grid_grouped(groups):
    """Pick the column count that keeps whole groups on their own rows.

    Padding each group out to a full row wastes most of the sheet when the
    groups are small, so instead search for a width where the groups happen
    to land on row boundaries, and only then maximise cell size.
    """
    flat = [item for group in groups for item in group]
    best = None
    for cols in range(3, 13):
        rows = max(1, math.ceil(len(flat) / cols))
        cw = (W - 2 * PAD) // cols
        ch = (H - HEAD - FOOT) // rows
        label = max(34, min(52, ch // 4))
        if ch - label - 8 < 48:
            continue
        score = (-count_split_groups(groups, cols), (cw - 12) * (ch - label - 8))
        if best is None or score > best[0]:
            best = (score, cols, rows, cw, ch, label, flat)
    return best


def build_sheet(entries, theme, out_path, groups=None, columns=False):
    if groups and columns:
        # One family per column: variants of the same lure read as a set
        # stacked vertically rather than strung along a row.
        groups = [g for g in groups if g]
        cols = len(groups)
        rows = max(len(g) for g in groups)
        cell_w = (W - 2 * PAD) // cols
        cell_h = (H - HEAD - FOOT) // rows
        label_h = max(34, min(52, cell_h // 4))
        entries = [groups[c][r] if r < len(groups[c]) else None
                   for r in range(rows) for c in range(cols)]
    elif groups:
        picked = choose_grid_grouped([g for g in groups if g])
        if picked:
            _, cols, rows, cell_w, cell_h, label_h, entries = picked
        else:
            groups = None
    if not groups:

        cols, rows, cell_w, cell_h, label_h = choose_grid(len(entries))

    count = len(entries)
    real_count = sum(1 for e in entries if e)   # padding must not be counted

    sheet = backdrop(theme).convert("RGBA")
    draw = ImageDraw.Draw(sheet)

    try:
        f_title = ImageFont.truetype(FONT_BOLD, 58)
        f_sub = ImageFont.truetype(FONT_REG, 25)
        f_name = ImageFont.truetype(FONT_BOLD, max(13, min(21, label_h - 8)))
        f_foot = ImageFont.truetype(FONT_REG, 18)
    except OSError:
        f_title = f_sub = f_name = f_foot = ImageFont.load_default()

    draw.text((W // 2 + 2, 50 + 2), theme["title"], font=f_title,
              fill=(0, 0, 0, 190), anchor="mm")
    draw.text((W // 2, 50), theme["title"], font=f_title, fill=(255, 255, 255), anchor="mm")
    draw.text((W // 2, 96), theme["subtitle"], font=f_sub, fill=theme["accent"], anchor="mm")
    draw.line([(W // 2 - 200, 118), (W // 2 + 200, 118)], fill=theme["accent"], width=2)

    font_cache = {}
    grid_w = cols * cell_w
    x_off = (W - grid_w) // 2

    for i, entry in enumerate(entries):
        if entry is None:            # padding that keeps groups on their own row
            continue
        name, path = entry
        col, row = i % cols, i // cols
        # Centre a short final row (only when the layout isn't group-padded,
        # since padded rows are deliberately ragged).
        in_row = min(cols, count - row * cols)
        row_off = (cols - in_row) * cell_w // 2 if (row == rows - 1 and not groups) else 0
        x0 = x_off + row_off + col * cell_w
        y0 = HEAD + row * cell_h

        try:
            img = Image.open(path).convert("RGBA")
        except OSError:
            continue
        bbox = img.getbbox()
        if bbox:
            img = img.crop(bbox)

        avail_w, avail_h = cell_w - 14, cell_h - label_h - 10
        scale = min(avail_w / img.width, avail_h / img.height)
        img = img.resize((max(1, int(img.width * scale)),
                          max(1, int(img.height * scale))), Image.LANCZOS)

        # Soft contact shadow so subjects sit on the backdrop instead of
        # floating flatly over it.
        shadow = Image.new("RGBA", (img.width + 26, img.height + 26), (0, 0, 0, 0))
        shadow.paste((0, 0, 0, 120), (13, 13), img.getchannel("A"))
        shadow = shadow.filter(ImageFilter.GaussianBlur(9))
        ix = x0 + (cell_w - img.width) // 2
        iy = y0 + (avail_h - img.height) // 2 + 6
        sheet.alpha_composite(shadow, (ix - 13, iy - 9))
        sheet.alpha_composite(img, (ix, iy))

        lines = fit_label(draw, name, cell_w - 10, font_cache, f_name.size)
        line_h = lines[0][1].size + 3
        ly = y0 + cell_h - label_h // 2 - (len(lines) - 1) * line_h // 2 - 2
        for text, font in lines:
            draw.text((x0 + cell_w // 2 + 1, ly + 1), text, font=font,
                      fill=(0, 0, 0, 200), anchor="mm")
            draw.text((x0 + cell_w // 2, ly), text, font=font,
                      fill=(255, 255, 255), anchor="mm")
            ly += line_h

    draw.text((W // 2, H - 26),
              "Gebsfish  -  %d %s" % (real_count, theme.get("noun", "species")),
              font=f_foot, fill=theme["accent"], anchor="mm")

    sheet.convert("RGB").save(out_path, quality=94)
    print("%-24s %2d %-14s %dx%d  ->  %s"
          % (theme["title"], real_count, theme.get("noun", "species"),
             W, H, os.path.basename(out_path)))


def main():
    renders = sys.argv[1] if len(sys.argv) > 1 else r"C:\Users\ECHO\Desktop\fish_renders_species"
    out_dir = sys.argv[2] if len(sys.argv) > 2 else r"C:\Users\ECHO\Desktop\fish_posters"
    gear_dir = sys.argv[3] if len(sys.argv) > 3 else r"C:\Users\ECHO\Desktop\gear_renders"
    os.makedirs(out_dir, exist_ok=True)

    envs, names = species_environments(), display_names()
    groups, missing = {}, []
    for cls, env in sorted(envs.items()):
        path = os.path.join(renders, cls + ".png")
        if not os.path.isfile(path):
            missing.append(cls)
            continue
        cat = categorise(cls, env)
        label = names.get(cls) or prettify(cls)
        rank = shell_rank(cls) if cat == "shellfish" else 0
        groups.setdefault(cat, []).append((rank, label, path))

    # Bugs used as bait aren't catchable species, so they come from the gear
    # renders and join the frogs and salamander on the bait sheet.
    for extra in BAIT_EXTRAS:
        path = os.path.join(gear_dir, extra + ".png")
        if os.path.isfile(path):
            groups.setdefault("bait", []).append(
                (0, names.get(extra) or prettify(extra), path))

    for key in ("freshwater", "saltwater", "brackish", "shellfish", "bait"):
        rows = sorted(groups.get(key, []))
        entries = [(label, path) for _, label, path in rows]
        if not entries:
            continue
        # Crustaceans read better with each family on its own row.
        banded = None
        if key == "shellfish":
            banded = []
            for rank in sorted({r for r, _, _ in rows}):
                banded.append([(l, p) for r, l, p in rows if r == rank])
        build_sheet(entries, THEMES[key], os.path.join(out_dir, "%s.jpg" % key),
                    groups=banded)

    # Gear and boats come from the item manifest rather than the species list.
    item_manifest = os.path.join(TOOLS, "item_manifest.json")
    if os.path.isfile(item_manifest):
        with open(item_manifest, encoding="utf-8") as fh:
            items = json.load(fh)
        gear, boats, lures = [], [], []
        for e in items:
            name = e["name"]
            path = os.path.join(gear_dir, name + ".png")
            if not os.path.isfile(path):
                continue
            low = name.lower()
            if "jonboat" in low:
                boats.append((BOAT_NAMES.get(low, prettify(name)), path))
                continue
            if name in BAIT_EXTRAS:
                continue          # bugs belong on the bait sheet, not in gear
            label = names.get(name) or prettify(name)
            target = lures if any(k in low or k in label.lower() for k in LURE_KEYS) else gear
            target.append((label, path))

        gear_banded = None
        if gear:
            ranked = sorted((gear_rank(l), l, p) for l, p in gear)
            gear_banded = [[(l, p) for r, l, p in ranked if r == rank]
                           for rank in sorted({r for r, _, _ in ranked})]

        lure_cols = None
        if lures:
            ranked = sorted((lure_family(l), l, p) for l, p in lures)
            lure_cols = [[(l, p) for f, l, p in ranked if f == fam]
                         for fam in sorted({f for f, _, _ in ranked})]

        for entries, theme, fname, banded, as_cols in (
                (lures, "lures", "lures.jpg", lure_cols, True),
                (gear, "gear", "gear.jpg", gear_banded, False),
                (boats, "boats", "boats.jpg", None, False)):
            if entries:
                build_sheet(sorted(entries), THEMES[theme],
                            os.path.join(out_dir, fname),
                            groups=banded, columns=as_cols)

    stale = os.path.join(out_dir, "amphibian.jpg")   # superseded by bait.jpg
    if os.path.isfile(stale):
        os.remove(stale)

    if missing:
        print("\nno render (vanilla DayZ species): %s" % ", ".join(missing))


if __name__ == "__main__":
    main()
