# Rig a fish p3d with a spine chain and render a looping swim cycle to a
# transparent PNG sequence (turn it into a GIF with tools/make_gif.py).
#
#   blender --background --python tools/rig_swim.py -- \
#       --p3d <file> --texture <paa> --name geb_X --out <dir>
#
# How it works:
#   1. import the model and normalise its orientation (length -> +X,
#      thickness -> +Y, height -> +Z) since the source models are authored
#      along different axes
#   2. work out which end is the head (the body is bulkier there, so the
#      vertex centroid sits headward of the bounding-box centre)
#   3. build a bone chain head -> tail, bind with automatic weights
#   4. drive each bone with a travelling sine wave whose amplitude grows
#      toward the tail -- that is the swim undulation
#   5. render N frames from a slightly angled view so the S-curve reads

import bpy
import os
import sys
import math
from mathutils import Vector, Matrix

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import render_p3d as rp


def parse_args():
    argv = sys.argv
    argv = argv[argv.index("--") + 1:] if "--" in argv else []
    o = {"p3d": None, "texture": None, "name": None, "out": None, "src": None,
         "view": "AUTO",
         "frames": 24, "res": 512, "samples": 32, "bones": 10,
         "amp": 22.0, "waves": 1.0, "azimuth": 28.0, "elevation": 12.0,
         "margin": 1.30,
         # Jaw: front `mouth_frac` of the body counts as head, and the lower
         # `jaw_frac` of that region's height is the moving lower jaw.
         "mouth_open": 0.0, "mouth_frac": 0.20, "jaw_frac": 0.42,
         "mouth_cycles": 1.0,
         # swim/undulate = spine wave; crawl/drift/pulse = whole-body motion
         # for creatures with no swimming spine.
         "profile": "swim", "flip_head": False}
    i = 0
    while i < len(argv):
        if argv[i] == "--flip-head":
            o["flip_head"] = True
            i += 1
            continue
        k = argv[i][2:] if argv[i].startswith("--") else None
        if k in ("p3d", "texture", "name", "out", "src", "view", "profile"):
            o[k] = argv[i + 1]; i += 2
        elif k in ("frames", "res", "samples", "bones"):
            o[k] = int(argv[i + 1]); i += 2
        elif k in ("amp", "waves", "azimuth", "elevation", "margin",
                   "mouth_open", "mouth_frac", "jaw_frac", "mouth_cycles"):
            o[k] = float(argv[i + 1]); i += 2
        else:
            i += 1
    o["view"] = o["view"].upper()
    o["profile"] = o["profile"].lower()
    if not o["p3d"] or not o["out"]:
        sys.exit("ERROR: --p3d and --out are required")
    o["name"] = o["name"] or os.path.splitext(os.path.basename(o["p3d"]))[0]
    o["src"] = o["src"] or os.path.dirname(o["p3d"])
    return o


def normalise_orientation(objects, view="AUTO"):
    """Rotate so length is +X, the viewing axis is +Y and 'up' is +Z.

    AUTO looks down the thinnest axis. MID looks down the middle axis, which
    is what broad-finned species (sharks, sturgeon) need: their pectoral span
    makes them wider than they are tall, so the thinnest axis is vertical and
    AUTO would render them from above.
    """
    lo, hi = rp.world_bbox(objects)
    size = hi - lo
    extents = [size.x, size.y, size.z]
    order = sorted(range(3), key=lambda i: extents[i], reverse=True)
    axes = [Vector((1, 0, 0)), Vector((0, 1, 0)), Vector((0, 0, 1))]
    e_long, e_mid, e_thin = axes[order[0]], axes[order[1]], axes[order[2]]

    e_view, e_up = (e_mid, e_thin) if view == "MID" else (e_thin, e_mid)

    rot = Matrix((e_long, e_view, e_up))           # rows map model -> world
    if rot.determinant() < 0:
        rot = Matrix((e_long, -e_view, e_up))      # keep it right-handed
    mat = rot.to_4x4()

    for obj in objects:
        obj.matrix_world = mat @ obj.matrix_world
    bpy.context.view_layer.update()

    lo, hi = rp.world_bbox(objects)
    centre = (lo + hi) * 0.5
    for obj in objects:
        obj.matrix_world = Matrix.Translation(-centre) @ obj.matrix_world
    bpy.context.view_layer.update()

    bpy.ops.object.select_all(action='DESELECT')
    for obj in objects:
        obj.select_set(True)
    bpy.context.view_layer.objects.active = objects[0]
    bpy.ops.object.transform_apply(location=True, rotation=True, scale=True)
    bpy.context.view_layer.update()


def head_is_positive_x(objects):
    """A fish carries most of its bulk forward, so the vertex centroid sits
    on the head side of the bounding-box centre."""
    total, count = Vector((0.0, 0.0, 0.0)), 0
    for obj in objects:
        mw = obj.matrix_world
        for v in obj.data.vertices:
            total += mw @ v.co
            count += 1
    if not count:
        return True
    lo, hi = rp.world_bbox(objects)
    return (total / count).x > (lo.x + hi.x) * 0.5


def build_rig(objects, nbones, head_pos_x):
    lo, hi = rp.world_bbox(objects)
    x_head, x_tail = (hi.x, lo.x) if head_pos_x else (lo.x, hi.x)
    z_mid = (lo.z + hi.z) * 0.5

    arm_data = bpy.data.armatures.new("Rig")
    arm = bpy.data.objects.new("Rig", arm_data)
    bpy.context.scene.collection.objects.link(arm)
    bpy.context.view_layer.objects.active = arm
    bpy.ops.object.mode_set(mode='EDIT')

    names, prev = [], None
    for i in range(nbones):
        t0, t1 = i / nbones, (i + 1) / nbones
        b = arm_data.edit_bones.new("b%02d" % i)
        b.head = Vector((x_head + (x_tail - x_head) * t0, 0.0, z_mid))
        b.tail = Vector((x_head + (x_tail - x_head) * t1, 0.0, z_mid))
        if prev:
            b.parent = prev
            b.use_connect = True
        prev = b
        names.append(b.name)
    bpy.ops.object.mode_set(mode='OBJECT')

    bpy.ops.object.select_all(action='DESELECT')
    for obj in objects:
        obj.select_set(True)
    arm.select_set(True)
    bpy.context.view_layer.objects.active = arm
    try:
        bpy.ops.object.parent_set(type='ARMATURE_AUTO')
    except RuntimeError as exc:
        # Bone-heat weighting fails on non-manifold or overlapping geometry.
        print("  ! automatic weights failed (%s), using envelopes" % exc)
        bpy.ops.object.parent_set(type='ARMATURE_ENVELOPE')

    ensure_weights(objects, arm, names)
    return arm, names


def ensure_weights(objects, arm, names):
    """Guarantee the mesh is actually weighted to the chain.

    Bone heat can fail *silently* on some meshes: it creates the vertex
    groups and the armature modifier but assigns no weights, leaving the
    model rigged yet completely frozen (smallmouthbass did exactly this, and
    produced a 24-frame render of 24 identical images). When that happens,
    weight each vertex along the chain by its position instead, blending
    between the two nearest bones so the bend stays smooth.
    """
    weighted = sum(1 for o in objects for v in o.data.vertices if len(v.groups) > 0)
    if weighted:
        return False

    print("  ! bone-heat produced no weights, falling back to positional weighting")
    bones = [arm.data.bones[n] for n in names]
    x_start, x_end = bones[0].head_local.x, bones[-1].tail_local.x
    span = (x_end - x_start) or 1e-6
    last = len(names) - 1

    for obj in objects:
        groups = {n: (obj.vertex_groups.get(n) or obj.vertex_groups.new(name=n))
                  for n in names}
        matrix = obj.matrix_world
        for v in obj.data.vertices:
            t = min(1.0, max(0.0, ((matrix @ v.co).x - x_start) / span))
            pos = t * last
            i0 = int(math.floor(pos))
            i1 = min(i0 + 1, last)
            frac = pos - i0
            groups[names[i0]].add([v.index], 1.0 - frac, 'REPLACE')
            if i1 != i0:
                groups[names[i1]].add([v.index], frac, 'REPLACE')
    return True


def add_jaw(objects, arm, root_bone, mouth_frac, jaw_frac):
    """Add a hinged lower-jaw bone and hand-weight the jaw vertices to it.

    These models carry no jaw bone, so the jaw is located geometrically: the
    front `mouth_frac` of the body is the head, and within that region every
    vertex below `jaw_frac` of its height is treated as lower jaw. Weights
    ramp in from the hinge so the corner of the mouth doesn't tear open.
    """
    lo, hi = rp.world_bbox(objects)
    length = max(hi.x - lo.x, 1e-6)
    hinge_x = hi.x - length * mouth_frac          # head sits at +X

    zs = []
    for obj in objects:
        mw = obj.matrix_world
        for v in obj.data.vertices:
            p = mw @ v.co
            if p.x >= hinge_x:
                zs.append(p.z)
    if not zs:
        return 0
    z_lo, z_hi = min(zs), max(zs)
    jaw_z = z_lo + (z_hi - z_lo) * jaw_frac

    bpy.context.view_layer.objects.active = arm
    bpy.ops.object.mode_set(mode='EDIT')
    eb = arm.data.edit_bones.new("jaw")
    eb.head = Vector((hinge_x, 0.0, jaw_z))
    eb.tail = Vector((hi.x, 0.0, jaw_z))
    eb.roll = 0.0
    eb.parent = arm.data.edit_bones[root_bone]    # follows the swim motion
    eb.use_connect = False
    bpy.ops.object.mode_set(mode='OBJECT')

    moved, span = 0, length * mouth_frac
    for obj in objects:
        grp = obj.vertex_groups.get("jaw") or obj.vertex_groups.new(name="jaw")
        mw = obj.matrix_world
        for v in obj.data.vertices:
            p = mw @ v.co
            if p.x < hinge_x or p.z > jaw_z:
                continue
            t = min(1.0, max(0.0, (p.x - hinge_x) / span))
            w = t * t * (3.0 - 2.0 * t)           # smoothstep from the hinge
            if w < 0.01:
                continue
            # Scale the spine weights down by the jaw's share before adding
            # the jaw weight, so the two blend rather than fight.
            for gi, gw in [(ge.group, ge.weight) for ge in v.groups]:
                g = obj.vertex_groups[gi]
                if g.name != "jaw":
                    g.add([v.index], gw * (1.0 - w), 'REPLACE')
            grp.add([v.index], w, 'REPLACE')
            moved += 1
    return moved


def animate_jaw(arm, frames, open_deg, cycles):
    pb = arm.pose.bones.get("jaw")
    if not pb:
        return
    bpy.context.view_layer.objects.active = arm
    bpy.ops.object.mode_set(mode='POSE')
    pb.rotation_mode = 'XYZ'
    amp = math.radians(open_deg)
    for f in range(frames):
        openness = 0.5 - 0.5 * math.cos(2.0 * math.pi * cycles * (f / frames))
        # The bone runs along +X with zero roll, so its local X axis is world
        # -Y; a negative rotation there swings the jaw tip downward (open).
        pb.rotation_euler = (-amp * openness, 0.0, 0.0)
        pb.keyframe_insert("rotation_euler", frame=f + 1)
    bpy.ops.object.mode_set(mode='OBJECT')


def animate(arm, names, frames, amp_deg, waves):
    bpy.context.view_layer.objects.active = arm
    bpy.ops.object.mode_set(mode='POSE')
    amp = math.radians(amp_deg)
    n = len(names)
    for f in range(frames):
        phase = 2.0 * math.pi * (f / frames)
        for i, bn in enumerate(names):
            t = (i + 1) / n                      # 0 at head, 1 at tail
            # Amplitude ramps quadratically toward the tail, and the wave is
            # delayed along the body so the curve travels backwards.
            angle = amp * (t ** 2) * math.sin(phase - waves * 2.0 * math.pi * t)
            pb = arm.pose.bones[bn]
            pb.rotation_mode = 'XYZ'
            pb.rotation_euler = (0.0, 0.0, angle)
            pb.keyframe_insert("rotation_euler", frame=f + 1)
    bpy.ops.object.mode_set(mode='OBJECT')
    if arm.animation_data and arm.animation_data.action:
        for fc in arm.animation_data.action.fcurves:
            for kp in fc.keyframe_points:
                kp.interpolation = 'LINEAR'


def animate_arm_curl(objects, frames, span, amount=0.13):
    """Starfish: the arms slowly lift and settle back down.

    A starfish doesn't swim or wander -- it flexes. After normalisation the
    disc lies in the X/Z plane with its normal on Y, so a shape key displaces
    each vertex along Y in proportion to how far it sits from the centre:
    the arm tips travel furthest, the central disc barely moves.
    """
    for obj in objects:
        mesh = obj.data
        if not mesh.shape_keys:
            obj.shape_key_add(name="Basis", from_mix=False)
        key = obj.shape_key_add(name="Curl", from_mix=False)

        count = len(mesh.vertices)
        if not count:
            continue
        cx = sum(v.co.x for v in mesh.vertices) / count
        cz = sum(v.co.z for v in mesh.vertices) / count
        max_r = max(math.hypot(v.co.x - cx, v.co.z - cz)
                    for v in mesh.vertices) or 1e-6
        lift = span * amount

        for i, v in enumerate(mesh.vertices):
            r = math.hypot(v.co.x - cx, v.co.z - cz) / max_r
            key.data[i].co = v.co + Vector((0.0, (r ** 2) * lift, 0.0))

        block = mesh.shape_keys.key_blocks["Curl"]
        for f in range(frames):
            phase = 2.0 * math.pi * (f / frames)
            block.value = 0.5 - 0.5 * math.cos(phase)     # loops seamlessly
            block.keyframe_insert("value", frame=f + 1)


def animate_tail_curl(arm, names, frames, amp_deg=26.0):
    """Crustaceans: the abdomen tucks and releases.

    Crayfish and lobsters hold the thorax still and flex the tail, so only
    the rear bones rotate, and they pitch (tuck under) rather than yaw like
    a swimming fish.
    """
    bpy.context.view_layer.objects.active = arm
    bpy.ops.object.mode_set(mode='POSE')
    amp = math.radians(amp_deg)
    n = len(names)
    for f in range(frames):
        phase = 2.0 * math.pi * (f / frames)
        wave = 0.5 - 0.5 * math.cos(phase)
        for i, bn in enumerate(names):
            t = (i + 1) / n
            rear = max(0.0, (t - 0.45) / 0.55)     # front half stays rigid
            pb = arm.pose.bones[bn]
            pb.rotation_mode = 'XYZ'
            pb.rotation_euler = (amp * (rear ** 2) * wave, 0.0, 0.0)
            pb.keyframe_insert("rotation_euler", frame=f + 1)
    bpy.ops.object.mode_set(mode='OBJECT')


def animate_object(objects, profile, frames, span):
    """Whole-body motion for creatures that don't swim with a spine.

    A bone chain undulating like a fish looks absurd on a lobster or a clam,
    so these get subtle transform animation instead:
      crawl - crustaceans and the frog: a walking bob with a slight sway
      drift - shells, snails and starfish: near-static, a very slow turn
      pulse - jellyfish: the bell contracts and the body rises with it
    """
    for obj in objects:
        obj.rotation_mode = 'XYZ'
        base_loc = obj.location.copy()
        base_rot = obj.rotation_euler.copy()
        base_scale = obj.scale.copy()

        for f in range(frames):
            phase = 2.0 * math.pi * (f / frames)
            loc, rot, scale = base_loc.copy(), base_rot.copy(), base_scale.copy()

            if profile == "crawl":
                loc.z += math.sin(phase * 2.0) * span * 0.014
                rot.z += math.radians(3.5) * math.sin(phase)
                rot.y += math.radians(2.5) * math.sin(phase * 2.0)
            elif profile == "drift":
                rot.z += math.radians(7.0) * math.sin(phase)
                loc.z += math.sin(phase) * span * 0.010
            elif profile == "pulse":
                contract = 0.5 - 0.5 * math.cos(phase * 2.0)
                scale.x = base_scale.x * (1.0 + 0.11 * contract)
                scale.y = base_scale.y * (1.0 + 0.11 * contract)
                scale.z = base_scale.z * (1.0 - 0.17 * contract)
                loc.z += span * 0.05 * contract

            obj.location, obj.rotation_euler, obj.scale = loc, rot, scale
            obj.keyframe_insert("location", frame=f + 1)
            obj.keyframe_insert("rotation_euler", frame=f + 1)
            obj.keyframe_insert("scale", frame=f + 1)

        obj.location, obj.rotation_euler, obj.scale = base_loc, base_rot, base_scale
        if obj.animation_data and obj.animation_data.action:
            for fc in obj.animation_data.action.fcurves:
                for kp in fc.keyframe_points:
                    kp.interpolation = 'LINEAR'


def setup_camera(lo, hi, azimuth, elevation, margin):
    """Slightly off-axis view: a pure side-on camera would hide the lateral
    undulation almost completely, since a fish swims by bending sideways."""
    centre = (lo + hi) * 0.5
    span = max(hi.x - lo.x, hi.y - lo.y, hi.z - lo.z, 1e-6)
    az, el = math.radians(azimuth), math.radians(elevation)
    direction = Vector((math.sin(az) * math.cos(el),
                        -math.cos(az) * math.cos(el),
                        math.sin(el)))

    cam_data = bpy.data.cameras.new("Cam")
    cam_data.type = 'ORTHO'
    cam = bpy.data.objects.new("Cam", cam_data)
    bpy.context.scene.collection.objects.link(cam)
    cam.location = centre + direction * span * 4.0
    cam.rotation_euler = (centre - cam.location).to_track_quat('-Z', 'Y').to_euler()
    bpy.context.scene.camera = cam
    bpy.context.view_layer.update()

    inv = cam.matrix_world.inverted()
    xs, ys = [], []
    for cx in (lo.x, hi.x):
        for cy in (lo.y, hi.y):
            for cz in (lo.z, hi.z):
                p = inv @ Vector((cx, cy, cz))
                xs.append(abs(p.x)); ys.append(abs(p.y))
    # Extra headroom: the body swings outside its rest bounds while animating.
    cam_data.ortho_scale = max(max(xs), max(ys)) * 2.0 * margin
    return centre, span, (Vector((1, 0, 0)), Vector((0, 0, 1)), -direction)


def main():
    o = parse_args()
    frame_dir = os.path.join(o["out"], "frames_" + o["name"])
    os.makedirs(frame_dir, exist_ok=True)

    print("=== rigging %s ===" % o["name"])
    rp.reset_scene()
    meshes = rp.import_model(o["p3d"])
    if not meshes:
        sys.exit("no mesh imported from %s" % o["p3d"])

    applied, missing = rp.apply_textures(
        meshes, o["src"], {}, [o["texture"]] if o["texture"] else None)
    print("  textures applied: %d%s" % (applied, "  MISSING: " + ",".join(missing) if missing else ""))

    normalise_orientation(meshes, o["view"])
    head_pos = head_is_positive_x(meshes)
    if o["flip_head"]:
        head_pos = not head_pos          # centroid test guessed backwards
    print("  head faces %s%s" % ("+X" if head_pos else "-X",
                                 " (flipped)" if o["flip_head"] else ""))
    if not head_pos:
        # Everything downstream (bone chain, jaw) assumes the head is at +X.
        flip = Matrix.Rotation(math.pi, 4, 'Z')
        for obj in meshes:
            obj.matrix_world = flip @ obj.matrix_world
        bpy.context.view_layer.update()
        bpy.ops.object.select_all(action='DESELECT')
        for obj in meshes:
            obj.select_set(True)
        bpy.context.view_layer.objects.active = meshes[0]
        bpy.ops.object.transform_apply(location=True, rotation=True, scale=True)

    box_lo, box_hi = rp.world_bbox(meshes)
    body_span = max(box_hi.x - box_lo.x, box_hi.y - box_lo.y,
                    box_hi.z - box_lo.z, 1e-6)

    if o["profile"] in ("swim", "undulate"):
        arm, names = build_rig(meshes, o["bones"], True)
        if o["mouth_open"] > 0:
            print("  jaw vertices: %d" %
                  add_jaw(meshes, arm, names[0], o["mouth_frac"], o["jaw_frac"]))
            animate_jaw(arm, o["frames"], o["mouth_open"], o["mouth_cycles"])
        animate(arm, names, o["frames"], o["amp"], o["waves"])
    elif o["profile"] == "crustacean":
        arm, names = build_rig(meshes, o["bones"], True)
        animate_tail_curl(arm, names, o["frames"], o["amp"])
        animate_object([arm], "crawl", o["frames"], body_span)
    elif o["profile"] == "curl":
        animate_arm_curl(meshes, o["frames"], body_span)
        animate_object(meshes, "drift", o["frames"], body_span)
    else:
        animate_object(meshes, o["profile"], o["frames"], body_span)

    lo, hi = rp.world_bbox(meshes)
    centre, span, basis = setup_camera(
        lo, hi, o["azimuth"], o["elevation"], o["margin"])
    rp.setup_lights(centre, span, basis)
    rp.setup_render({"res": o["res"], "samples": o["samples"]})

    scene = bpy.context.scene
    scene.frame_start, scene.frame_end = 1, o["frames"]
    scene.render.filepath = os.path.join(frame_dir, o["name"] + "_")
    bpy.ops.render.render(animation=True)
    print("  -> %d frames in %s" % (o["frames"], frame_dir))


if __name__ == "__main__":
    main()
