# Compare where two models' bones actually sit.
#
#   blender --background --python tools/compare_rig.py -- \
#       --a citizena_skinny_m.p3d --b geb_GreenAlien.p3d
#
# MLOD p3d files don't store bone transforms -- the skeleton lives in the
# anim data. But a bone's location can be recovered from a correctly rigged
# model: it is roughly the weight-averaged centroid of the vertices in that
# bone's selection. Doing that for both models shows whether they were built
# around the SAME skeleton.
#
# This matters more than weighting quality. Arma rotates a vertex around its
# bone's pivot, so if a model's elbow isn't where the skeleton's elbow is,
# the limb swings wrong no matter how good the weights are.

import bpy
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import render_p3d as rp

# Bones worth comparing: the ones that drive visible limb motion.
KEY = ["pelvis", "spine", "spine1", "spine2", "spine3", "neck", "head",
       "leftshoulder", "leftarm", "leftforearm", "lefthand",
       "rightshoulder", "rightarm", "rightforearm", "righthand",
       "leftupleg", "leftleg", "leftfoot",
       "rightupleg", "rightleg", "rightfoot"]


def parse_args():
    argv = sys.argv
    argv = argv[argv.index("--") + 1:] if "--" in argv else []
    o = {"a": None, "b": None}
    for i, tok in enumerate(argv):
        if tok in ("--a", "--b") and i + 1 < len(argv):
            o[tok[2:]] = argv[i + 1]
    if not o["a"] or not o["b"]:
        sys.exit("ERROR: --a and --b are required")
    return o


def load(path):
    rp.reset_scene()
    bpy.ops.a3ob.import_p3d(
        filepath=path, first_lod_only=True, enclose=False, groupby='NONE',
        proxy_action='CLEAR', additional_data_allowed=True,
        additional_data={'SELECTIONS'}, validate_meshes=False,
        absolute_paths=False)
    meshes = [o for o in bpy.context.scene.objects if o.type == 'MESH']
    meshes.sort(key=lambda o: len(o.data.vertices), reverse=True)
    obj = meshes[0]

    centroids, lo, hi = {}, None, None
    acc = {}
    for v in obj.data.vertices:
        p = obj.matrix_world @ v.co
        lo = p.copy() if lo is None else [min(lo[i], p[i]) for i in range(3)]
        hi = p.copy() if hi is None else [max(hi[i], p[i]) for i in range(3)]
        for ge in v.groups:
            if ge.weight <= 0:
                continue
            name = obj.vertex_groups[ge.group].name.lower()
            slot = acc.setdefault(name, [0.0, 0.0, 0.0, 0.0])
            for i in range(3):
                slot[i] += p[i] * ge.weight
            slot[3] += ge.weight
    for name, (x, y, z, w) in acc.items():
        if w > 0:
            centroids[name] = (x / w, y / w, z / w)
    return centroids, lo, hi


def main():
    o = parse_args()
    a, alo, ahi = load(o["a"])
    b, blo, bhi = load(o["b"])

    print("\nA %-28s height %.3f  width %.3f"
          % (os.path.basename(o["a"]), ahi[2] - alo[2], ahi[0] - alo[0]))
    print("B %-28s height %.3f  width %.3f"
          % (os.path.basename(o["b"]), bhi[2] - blo[2], bhi[0] - blo[0]))

    print("\n%-16s %-22s %-22s %8s" % ("bone", "A (x,y,z)", "B (x,y,z)", "offset"))
    print("-" * 74)
    shared, offsets = 0, []
    for name in KEY:
        pa, pb = a.get(name), b.get(name)
        if not pa or not pb:
            print("%-16s %-22s %-22s %8s"
                  % (name, "%.2f,%.2f,%.2f" % pa if pa else "--",
                     "%.2f,%.2f,%.2f" % pb if pb else "--", "n/a"))
            continue
        d = sum((pa[i] - pb[i]) ** 2 for i in range(3)) ** 0.5
        shared += 1
        offsets.append((d, name))
        print("%-16s %-22s %-22s %8.3f"
              % (name, "%.2f,%.2f,%.2f" % pa, "%.2f,%.2f,%.2f" % pb, d))

    if offsets:
        offsets.sort(reverse=True)
        avg = sum(d for d, _ in offsets) / len(offsets)
        print("\nshared bones: %d   mean offset: %.3f m   worst: %s"
              % (shared, avg, ", ".join("%s %.2f" % (n, d) for d, n in offsets[:4])))
        print("\nA mean offset under ~0.05 m means both models were built for "
              "the same skeleton and re-weighting will work.\nOver ~0.15 m "
              "means the geometry itself sits away from the bones, and no "
              "weighting can make the animation look right.")


if __name__ == "__main__":
    main()
