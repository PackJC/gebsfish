# Batch-render MLOD .p3d models to clean side-on PNGs with a transparent
# background, using Blender + the Arma 3 Object Builder addon.
#
#   blender --background --python tools/render_p3d.py -- --src <dir> --out <dir>
#
# Options (all after the `--`):
#   --src DIR        folder of .p3d files                     (required)
#   --out DIR        folder to write PNGs into                (required)
#   --limit N        only process the first N models          (default: all)
#   --only a,b,c     only these model names (no .p3d suffix)
#   --res N          square output resolution in px           (default 1024)
#   --samples N      EEVEE render samples                     (default 64)
#   --margin F       framing padding, 1.0 = tight             (default 1.08)
#   --view AUTO|X|Y|Z  axis to look down; AUTO = thinnest     (default AUTO)
#   --flip-h         mirror horizontally (fish faces the other way)
#   --flip-v         flip vertically (if models come out belly-up)
#   --no-textures    render untextured clay instead
#
# Notes:
#   - Only the first LOD of each file is imported (the visual LOD).
#   - Textures come from the .paa path embedded in the p3d; the file is
#     located by basename inside --src, so variant-named textures resolve.
#   - Colour management is forced to Standard so texture colours render
#     accurately instead of being desaturated by Blender's default AgX.

import bpy
import math
import os
import re
import sys
import glob
from mathutils import Vector, Matrix


def parse_args():
    argv = sys.argv
    argv = argv[argv.index("--") + 1:] if "--" in argv else []
    opts = {
        "src": None, "out": None, "limit": 0, "only": "",
        "res": 1024, "samples": 64, "margin": 1.08,
        "view": "AUTO", "textures": True,
        "flip_h": False, "flip_v": False, "manifest": None, "texroot": None,
    }
    i = 0
    while i < len(argv):
        a = argv[i]
        if a == "--no-textures":
            opts["textures"] = False
            i += 1
            continue
        if a in ("--flip-h", "--flip-v"):
            opts["flip_h" if a == "--flip-h" else "flip_v"] = True
            i += 1
            continue
        key = a[2:] if a.startswith("--") else None
        if key in ("src", "out", "only", "view", "manifest", "texroot"):
            opts[key] = argv[i + 1]
            i += 2
        elif key in ("limit", "res", "samples"):
            opts[key] = int(argv[i + 1])
            i += 2
        elif key == "margin":
            opts[key] = float(argv[i + 1])
            i += 2
        else:
            i += 1
    if not opts["src"] or not opts["out"]:
        sys.exit("ERROR: --src and --out are required")
    opts["view"] = opts["view"].upper()
    return opts


def reset_scene():
    """Empty the scene between models.

    Deliberately NOT wm.read_factory_settings(): that resets preferences too,
    which unregisters the Object Builder extension and makes every import
    after the first one fail with "operator could not be found".
    """
    for obj in list(bpy.data.objects):
        bpy.data.objects.remove(obj, do_unlink=True)
    for coll in list(bpy.data.collections):
        try:
            bpy.data.collections.remove(coll)
        except Exception:
            pass
    for block in (bpy.data.meshes, bpy.data.materials, bpy.data.images,
                  bpy.data.lights, bpy.data.cameras, bpy.data.armatures,
                  bpy.data.worlds, bpy.data.actions, bpy.data.node_groups):
        for item in list(block):
            try:
                block.remove(item)      # render result / viewer images resist
            except Exception:
                pass


def import_model(path):
    bpy.ops.a3ob.import_p3d(
        filepath=path,
        first_lod_only=True,      # visual LOD only
        enclose=False,
        groupby='NONE',
        proxy_action='CLEAR',     # drop proxy geometry
        additional_data_allowed=True,
        additional_data={'UV', 'MATERIALS'},
        validate_meshes=True,
        absolute_paths=False,
    )
    return [o for o in bpy.context.scene.objects if o.type == 'MESH']


def load_paa(paa_path):
    """Import a .paa via the addon and return the new image datablock."""
    before = set(bpy.data.images.keys())
    try:
        bpy.ops.a3ob.import_paa(filepath=paa_path, color_space='SRGB')
    except Exception as exc:
        print("    ! PAA import failed for %s: %s" % (paa_path, exc))
        return None
    fresh = [img for name, img in bpy.data.images.items() if name not in before]
    return fresh[0] if fresh else None


_TEX_INDEX = {}


def build_texture_index(root):
    """Index every .paa under the mod so models can reference textures that
    live outside their own folder (tackle models do this)."""
    if not root or _TEX_INDEX:
        return
    for dirpath, _, files in os.walk(root):
        for f in files:
            if f.lower().endswith(".paa"):
                _TEX_INDEX.setdefault(f.lower(), os.path.join(dirpath, f))


def resolve_texture(base, src_dir, texroot=None):
    """Locate a .paa on disk from the name embedded in the p3d.

    Some models point at a `_ca.paa` (colour+alpha) that was never shipped --
    the lobster trio does this -- so fall back to the `_co.paa` colour map of
    the same stem rather than rendering the model untextured. Falls back to a
    mod-wide index when the file isn't beside the model.
    """
    stem = re.sub(r"_(ca|co)\.paa$", "", base, flags=re.IGNORECASE)
    names = (base, stem + "_co.paa", stem + "_ca.paa")
    for candidate in names:
        path = os.path.join(src_dir, candidate)
        if os.path.isfile(path):
            return path
    if texroot:
        build_texture_index(texroot)
        for candidate in names:
            hit = _TEX_INDEX.get(candidate.lower())
            if hit:
                return hit
    return None


def apply_textures(objects, src_dir, cache, override=None, texroot=None):
    """Wire textures into each material as a Principled BSDF.

    `override` is the manifest's hiddenSelectionsTextures list: entry N
    replaces material slot N, mirroring how DayZ maps hiddenSelections to
    materials. That is how one shared model becomes several species
    (crayfish.p3d) and how multi-part models get the right skin on each part
    (the jon boat's hull and outboard motor are separate selections).
    Slots past the end of the list keep the texture embedded in the p3d.
    """
    applied, missing = 0, []
    seen = set()
    index = 0
    for obj in objects:
        for slot in obj.material_slots:
            mat = slot.material
            if not mat or mat.name in seen:
                continue
            seen.add(mat.name)
            slot_index = index
            index += 1

            path = None
            if override and slot_index < len(override):
                candidate = override[slot_index]
                if candidate and os.path.isfile(candidate):
                    path = candidate
            if path is None:
                props = getattr(mat, "a3ob_properties_material", None)
                raw = getattr(props, "texture_path", "") if props else ""
                base = os.path.basename(raw.replace("\\", "/")) if raw else ""
                if not base.lower().endswith(".paa"):
                    continue
                path = resolve_texture(base, src_dir, texroot)
                if not path:
                    missing.append(base)
                    continue

            if path in cache:
                img = cache[path]
            else:
                img = load_paa(path)
                cache[path] = img
            if img is None:
                missing.append(os.path.basename(path))
                continue

            mat.use_nodes = True
            nt = mat.node_tree
            nt.nodes.clear()
            out = nt.nodes.new('ShaderNodeOutputMaterial')
            bsdf = nt.nodes.new('ShaderNodeBsdfPrincipled')
            tex = nt.nodes.new('ShaderNodeTexImage')
            tex.image = img
            tex.location = (-400, 0)
            bsdf.location = (-100, 0)
            out.location = (200, 0)
            if "Roughness" in bsdf.inputs:
                bsdf.inputs["Roughness"].default_value = 0.45
            nt.links.new(tex.outputs["Color"], bsdf.inputs["Base Color"])
            # Fins and similar cutouts rely on the texture alpha.
            if "Alpha" in tex.outputs and "Alpha" in bsdf.inputs:
                nt.links.new(tex.outputs["Alpha"], bsdf.inputs["Alpha"])
                try:
                    mat.surface_render_method = 'DITHERED'   # EEVEE Next
                except (AttributeError, TypeError):
                    try:
                        mat.blend_method = 'HASHED'          # legacy EEVEE
                    except (AttributeError, TypeError):
                        pass
            nt.links.new(bsdf.outputs["BSDF"], out.inputs["Surface"])
            applied += 1
    return applied, missing


def clay_material(objects):
    mat = bpy.data.materials.new("Clay")
    mat.use_nodes = True
    bsdf = mat.node_tree.nodes.get("Principled BSDF")
    if bsdf:
        bsdf.inputs["Base Color"].default_value = (0.75, 0.76, 0.78, 1.0)
        bsdf.inputs["Roughness"].default_value = 0.55
    for obj in objects:
        obj.data.materials.clear()
        obj.data.materials.append(mat)


def world_bbox(objects):
    corners = []
    for obj in objects:
        for c in obj.bound_box:
            corners.append(obj.matrix_world @ Vector(c))
    if not corners:
        return None, None
    lo = Vector((min(c.x for c in corners), min(c.y for c in corners), min(c.z for c in corners)))
    hi = Vector((max(c.x for c in corners), max(c.y for c in corners), max(c.z for c in corners)))
    return lo, hi


def setup_camera_iso(lo, hi, center, extents, axes, margin, up_axis=None,
                     azimuth=38.0, elevation=26.0):
    """Three-quarter view for gear and containers.

    An axis-aligned view of a bucket or tackle box just shows its flat lid or
    side. This finds the object's upright axis -- for a cylinder or box the
    two 'ground plane' extents are the most alike, so the odd one out is up --
    keeps it pointing up in frame (handles stay on top), and orbits the camera
    round to a 3/4 angle so all three faces read.
    """
    if up_axis in ("X", "Y", "Z"):
        up = axes[{"X": 0, "Y": 1, "Z": 2}[up_axis]]
    else:
        scores = []
        for i in range(3):
            a, b = [extents[j] for j in range(3) if j != i]
            scores.append((abs(a - b) / max(a, b, 1e-6), i))
        up = axes[min(scores)[1]]
    h1, h2 = [axes[j] for j in range(3) if axes[j] != up]

    az, el = math.radians(azimuth), math.radians(elevation)
    direction = (h1 * (math.cos(az) * math.cos(el))
                 + h2 * (math.sin(az) * math.cos(el))
                 + up * math.sin(el)).normalized()

    span = max(max(extents), 1e-6)
    forward = -direction                       # camera -> subject
    right = forward.cross(up).normalized()
    frame_up = right.cross(forward).normalized()

    cam_data = bpy.data.cameras.new("Cam")
    cam_data.type = 'ORTHO'
    cam = bpy.data.objects.new("Cam", cam_data)
    bpy.context.scene.collection.objects.link(cam)
    rot = Matrix((
        (right.x, frame_up.x, -forward.x),
        (right.y, frame_up.y, -forward.y),
        (right.z, frame_up.z, -forward.z),
    )).to_4x4()
    cam.matrix_world = Matrix.Translation(center + direction * span * 4.0) @ rot
    bpy.context.scene.camera = cam
    bpy.context.view_layer.update()

    inv = cam.matrix_world.inverted()
    xs, ys = [], []
    for cx in (lo.x, hi.x):
        for cy in (lo.y, hi.y):
            for cz in (lo.z, hi.z):
                p = inv @ Vector((cx, cy, cz))
                xs.append(abs(p.x)); ys.append(abs(p.y))
    cam_data.ortho_scale = max(max(xs), max(ys)) * 2.0 * margin
    return cam, center, span, (right, frame_up, -forward)


def setup_camera(lo, hi, view, margin, flip_h=False, flip_v=False, roll=False):
    """Orthographic camera giving a true lateral (side) view.

    A fish is longest nose-to-tail, second-tallest dorsal-to-ventral, and
    thinnest across the body. So the side profile is the view down the
    SHORTEST axis, with the longest axis horizontal in frame and the middle
    axis vertical. Choosing the axis by extent rather than a fixed world axis
    keeps this correct whatever orientation the model was authored in.
    """
    center = (lo + hi) * 0.5
    size = hi - lo
    axes = [Vector((1, 0, 0)), Vector((0, 1, 0)), Vector((0, 0, 1))]
    extents = [size.x, size.y, size.z]
    order = sorted(range(3), key=lambda i: extents[i], reverse=True)

    if view.startswith("ISO"):
        # "ISO" picks the upright axis automatically; "ISO:Z" forces it, which
        # is needed for boxy items whose three extents all differ.
        forced = view.split(":")[1] if ":" in view else None
        return setup_camera_iso(lo, hi, center, extents, axes, margin, forced)

    if view == "AUTO":
        i_h, i_v = order[0], order[1]      # view down the thinnest axis
    elif view == "MID":
        # Broad-finned species (sharks, sturgeon) have a pectoral span wider
        # than the body is tall, so their THINNEST axis is the vertical one
        # and AUTO yields a top-down view. Looking down the middle axis
        # instead gives the true lateral profile.
        i_h, i_v = order[0], order[2]
    else:
        i_view = {"X": 0, "Y": 1, "Z": 2}[view]
        rest = [i for i in order if i != i_view]
        i_h, i_v = rest[0], rest[1]

    if roll:
        # Turn the subject 90 degrees in frame without moving to the other
        # side of it: a splay-legged frog is widest across its legs, so the
        # default choice lays its body vertically with the head pointing up.
        i_h, i_v, flip_v = i_v, i_h, not flip_v

    right = -axes[i_h] if flip_h else axes[i_h].copy()
    up = -axes[i_v] if flip_v else axes[i_v].copy()
    local_z = right.cross(up)          # camera looks along -local_z

    span = max(max(extents), 1e-6)
    dist = span * 4.0

    cam_data = bpy.data.cameras.new("Cam")
    cam_data.type = 'ORTHO'
    cam = bpy.data.objects.new("Cam", cam_data)
    bpy.context.scene.collection.objects.link(cam)
    # Build the orientation explicitly: columns are the camera's local X
    # (frame right), Y (frame up) and Z (backwards along the view).
    rot = Matrix((
        (right.x, up.x, local_z.x),
        (right.y, up.y, local_z.y),
        (right.z, up.z, local_z.z),
    )).to_4x4()
    cam.matrix_world = Matrix.Translation(center + local_z * dist) @ rot
    bpy.context.scene.camera = cam
    basis = (right, up, local_z)

    # Fit by projecting the bounding box into camera space.
    bpy.context.view_layer.update()
    inv = cam.matrix_world.inverted()
    xs, ys = [], []
    for cx in (lo.x, hi.x):
        for cy in (lo.y, hi.y):
            for cz in (lo.z, hi.z):
                p = inv @ Vector((cx, cy, cz))
                xs.append(abs(p.x))
                ys.append(abs(p.y))
    cam_data.ortho_scale = max(max(xs), max(ys)) * 2.0 * margin
    return cam, center, span, basis


def setup_lights(center, span, basis):
    """Distance-independent sun lamps placed relative to the camera basis, so
    the lighting reads the same no matter which axis we ended up viewing down."""
    right, up, local_z = basis
    setups = [
        ("Key",  (local_z * 1.0) + (up * 0.7) - (right * 0.6), 3.2),
        ("Fill", (local_z * 0.9) + (right * 0.9) - (up * 0.1), 1.4),
        ("Rim",  (local_z * -0.8) + (up * 0.5), 2.2),
    ]
    for name, direction, energy in setups:
        data = bpy.data.lights.new(name, type='SUN')
        data.energy = energy
        data.angle = 0.5
        lamp = bpy.data.objects.new(name, data)
        bpy.context.scene.collection.objects.link(lamp)
        lamp.location = center + direction.normalized() * span * 3.0
        lamp.rotation_euler = (center - lamp.location).to_track_quat('-Z', 'Y').to_euler()

    world = bpy.data.worlds.new("W")
    world.use_nodes = True
    bg = world.node_tree.nodes.get("Background")
    if bg:
        bg.inputs[0].default_value = (0.32, 0.34, 0.38, 1.0)
        bg.inputs[1].default_value = 0.9
    bpy.context.scene.world = world


def setup_render(opts):
    scene = bpy.context.scene
    for engine in ('BLENDER_EEVEE_NEXT', 'BLENDER_EEVEE'):
        try:
            scene.render.engine = engine
            break
        except TypeError:
            continue
    try:
        scene.eevee.taa_render_samples = opts["samples"]
    except AttributeError:
        pass
    scene.render.resolution_x = opts["res"]
    scene.render.resolution_y = opts["res"]
    scene.render.resolution_percentage = 100
    scene.render.film_transparent = True
    scene.render.image_settings.file_format = 'PNG'
    scene.render.image_settings.color_mode = 'RGBA'
    # Default AgX washes out saturated texture colour; Standard keeps it true.
    try:
        scene.view_settings.view_transform = 'Standard'
        scene.view_settings.look = 'None'
    except TypeError:
        pass


def render_one(path, opts, name=None, override=None, view_override=None,
               flips=None):
    name = name or os.path.splitext(os.path.basename(path))[0]
    print("\n=== %s ===" % name)
    reset_scene()

    try:
        meshes = import_model(path)
    except Exception as exc:
        print("  ! import failed: %s" % exc)
        return False, name, "import failed"
    if not meshes:
        print("  ! no mesh in first LOD")
        return False, name, "no mesh"

    tris = sum(len(o.data.polygons) for o in meshes)
    print("  objects=%d faces=%d" % (len(meshes), tris))

    if opts["textures"]:
        applied, missing = apply_textures(
            meshes, opts["src"], {}, override, opts["texroot"])
        print("  textures applied: %d%s" % (applied, ("  MISSING: " + ", ".join(sorted(set(missing)))) if missing else ""))
    else:
        clay_material(meshes)

    lo, hi = world_bbox(meshes)
    if lo is None:
        return False, name, "empty bounds"
    print("  size: %.3f x %.3f x %.3f" % (hi.x - lo.x, hi.y - lo.y, hi.z - lo.z))

    flip_h, flip_v, roll = flips if flips else (opts["flip_h"], opts["flip_v"], False)
    _, center, span, basis = setup_camera(
        lo, hi, (view_override or opts["view"]).upper(),
        opts["margin"], flip_h or opts["flip_h"], flip_v or opts["flip_v"], roll)
    setup_lights(center, span, basis)
    setup_render(opts)

    bpy.context.scene.render.filepath = os.path.join(opts["out"], name + ".png")
    bpy.ops.render.render(write_still=True)
    print("  -> %s.png" % name)
    return True, name, None


def main():
    opts = parse_args()
    os.makedirs(opts["out"], exist_ok=True)

    # A manifest renders one image per SPECIES (several species can share one
    # model with different textures); without one, it is one image per .p3d.
    if opts["manifest"]:
        import json
        with open(opts["manifest"], "r", encoding="utf-8") as fh:
            jobs = [(e["name"], e["p3d"],
                     e.get("textures") or ([e["texture"]] if e.get("texture") else None),
                     e.get("view"),
                     (bool(e.get("flip_h")), bool(e.get("flip_v")), bool(e.get("roll"))))
                    for e in json.load(fh)]
    else:
        jobs = [(os.path.splitext(os.path.basename(f))[0], f, None, None, None)
                for f in sorted(glob.glob(os.path.join(opts["src"], "*.p3d")))]

    if opts["only"]:
        wanted = {n.strip().lower() for n in opts["only"].split(",") if n.strip()}
        jobs = [j for j in jobs if j[0].lower() in wanted]
    if opts["limit"] > 0:
        jobs = jobs[:opts["limit"]]

    print("Rendering %d item(s) from %s" % (len(jobs), opts["src"]))
    ok, failed = [], []
    for job_name, path, override, view, flips in jobs:
        success, name, why = render_one(path, opts, job_name, override, view, flips)
        (ok if success else failed).append(name if success else "%s (%s)" % (name, why))

    print("\n================ SUMMARY ================")
    print("rendered : %d" % len(ok))
    print("failed   : %d" % len(failed))
    for f in failed:
        print("   - %s" % f)
    print("output   : %s" % opts["out"])


if __name__ == "__main__":
    main()
