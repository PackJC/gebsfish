# Turn a transparent PNG sequence into a looping GIF with a shared palette.
#
#   python tools/make_gif.py <frames_dir> <out.gif> [frame_ms]
#
# GIF only supports 1-bit alpha, so semi-transparent edge pixels have to be
# forced fully on or fully off; the threshold below trades a little edge
# quality for a background that is genuinely clear. A single palette is built
# across every frame so colours don't shimmer between them.

import glob
import os
import sys

from PIL import Image

ALPHA_CUTOFF = 128      # below this a pixel becomes transparent
TRANSPARENT_INDEX = 255


def build(frames_dir, out_path, frame_ms=60):
    files = sorted(glob.glob(os.path.join(frames_dir, "*.png")))
    if not files:
        sys.exit("no PNG frames in %s" % frames_dir)

    frames = [Image.open(f).convert("RGBA") for f in files]
    w, h = frames[0].size

    # One palette for the whole sequence, leaving index 255 for transparency.
    sheet = Image.new("RGB", (w, h * len(frames)), (0, 0, 0))
    for i, fr in enumerate(frames):
        sheet.paste(fr.convert("RGB"), (0, i * h))
    palette = sheet.quantize(colors=TRANSPARENT_INDEX, method=Image.MEDIANCUT)

    out_frames = []
    for fr in frames:
        p = fr.convert("RGB").quantize(palette=palette, dither=Image.Dither.NONE)
        mask = fr.getchannel("A").point(lambda a: 255 if a < ALPHA_CUTOFF else 0)
        p.paste(TRANSPARENT_INDEX, mask)
        out_frames.append(p)

    out_frames[0].save(
        out_path, save_all=True, append_images=out_frames[1:],
        duration=frame_ms, loop=0, transparency=TRANSPARENT_INDEX,
        disposal=2, optimize=False,
    )
    size_kb = os.path.getsize(out_path) / 1024.0

    # PIL drops any frame whose delta from the previous one is empty, so if
    # the motion is too subtle to survive quantisation the GIF silently
    # collapses to a single still. Check rather than trust.
    written = getattr(Image.open(out_path), "n_frames", 1)
    warn = ""
    if written < len(frames):
        warn = "  *** WARNING: only %d of %d frames survived -- motion is too " \
               "subtle to quantise; increase --amp ***" % (written, len(frames))
    print("%s  (%d frames, %dx%d, %.0f KB)%s"
          % (out_path, written, w, h, size_kb, warn))


if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.exit("usage: make_gif.py <frames_dir> <out.gif> [frame_ms]")
    build(sys.argv[1], sys.argv[2],
          int(sys.argv[3]) if len(sys.argv) > 3 else 60)
