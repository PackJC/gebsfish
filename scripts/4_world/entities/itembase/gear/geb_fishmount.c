/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Trophy mounts in three sizes. Each plaque carries a single GebFishMount
// attachment slot (CfgSlots in data/tools/config.cpp) and the player attaches
// the ACTUAL caught fish -- its model renders on the board via the
// gebfishmount proxy and its weight/quality persist through normal attachment
// save/load. Rot for the mounted fish is paused in Edible_Base.ProcessDecay
// (see geb_ediblebase.c) so trophies are taxidermy, not a countdown to a
// rotten wall.
//
// geb_WoodenFishMount is the small plaque; geb_MediumFishMount and
// geb_LargeFishMount below only change the size and the board's measurements.
// A fish goes on its own size of board or a bigger one (GebMountPoses gives
// each species' size), and the board turns and shifts it so it hangs side-on,
// head to the right, centred in the clear field above the nameplate.
class geb_WoodenFishMount : ItemBase {

	// The largest catch the board takes: 0 small, 1 medium, 2 large.
	int GebMountSize() {
		return 0;
	}

	// The clear field a fish is centred in, in metres above (+) and below (-)
	// the display point at the middle of the board's face: from just over the
	// nameplate (its top plus 3.5 % of the board's height) to the inside of the
	// routed edge, measured on each board's model.
	float GebFieldBottom() {
		return -0.108;
	}

	float GebFieldTop() {
		return 0.170;
	}

	// Half the board's height: standing on the floor (no wall in reach) the
	// hologram lifts it by this much, so it stands on its bottom edge instead
	// of half in the ground.
	float GebHalfHeight() {
		return 0.19;
	}

	// No rotten or ruined trophies, nothing too big for the board, and nothing
	// on a ruined board (it would stay there for good: the trophy only dies with
	// the plaque when the plaque turns ruined). Everything else the slot accepts
	// (config-side inventorySlot[] on the fish bases) is fair game.
	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		// Only a board standing in the world (hung or set down) takes a fish:
		// one in hands, a backpack or a container doesn't. Vanilla's take
		// action looks for a free spot through everything the player carries,
		// slots included, so picking a fish up could otherwise mount it on a
		// carried board, and mounting can't be undone.
		if (GetHierarchyParent())
			return false;

		if (IsRuined())
			return false;

		ItemBase item = ItemBase.Cast(attachment);
		if (item && item.IsRuined())
			return false;

		Edible_Base food = Edible_Base.Cast(attachment);
		if (food && food.HasFoodStage() && food.GetFoodStageType() == FoodStageType.ROTTEN)
			return false;

		GebMountPose pose = GebMountPoses.Get(attachment.GetType());
		if (pose && pose.Size > GebMountSize())
			return false;

		return true;
	}

	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		GebPoseTrophy(item);
	}

	// Attachments come back after a restart through EEItemAttached as well;
	// this covers a load order where the board's own state arrives last.
	override void AfterStoreLoad() {
		super.AfterStoreLoad();
		if (GetInventory() && GetInventory().AttachmentCount() > 0)
			GebPoseTrophy(GetInventory().GetAttachmentFromIndex(0));
	}

	// Sets the six fish_* animations (Model.cfg) for this fish: turns as
	// phases of a full turn, shifts as 0.5 + metres / 4. Runs on the server and
	// on every client that sees the attachment, so each side poses it from the
	// same table. A species with no pose keeps the proxy's own orientation and
	// sits in the middle of the field.
	void GebPoseTrophy(EntityAI fish) {
		if (!fish)
			return;

		GebMountPose pose = GebMountPoses.Get(fish.GetType());
		vector shift = vector.Zero;
		float height = 0;
		float yaw = 0;
		float pitch = 0;
		float roll = 0;
		if (pose) {
			shift = pose.Offset;
			height = pose.Height;
			yaw = pose.Yaw;
			pitch = pose.Pitch;
			roll = pose.Roll;
		}
		shift[1] = shift[1] + GebDisplayHeight(height);

		SetAnimationPhase("fish_x", 0.5 + shift[0] / 4.0);
		SetAnimationPhase("fish_y", 0.5 + shift[1] / 4.0);
		SetAnimationPhase("fish_z", 0.5 + shift[2] / 4.0);
		SetAnimationPhase("fish_yaw", yaw / 360.0);
		SetAnimationPhase("fish_pitch", pitch / 360.0);
		SetAnimationPhase("fish_roll", roll / 360.0);
	}

	// Where the middle of a fish this tall goes: the middle of the clear field,
	// or, for a fish taller than the field, lowered by half the excess (never
	// below the board's centre) so it overhangs top and bottom alike.
	float GebDisplayHeight(float height) {
		float bottom = GebFieldBottom();
		float top = GebFieldTop();
		float middle = (bottom + top) / 2.0;
		float fieldHeight = top - bottom;
		if (height <= fieldHeight)
			return middle;
		return Math.Max(0.0, middle - (height - fieldHeight) / 2.0);
	}

	// Mounting is permanent: once a fish is on the plaque it can't be
	// detached, dragged out, or taken to hands -- taxidermy, not storage.
	// This also stops the mount doubling as a free never-rots fish locker.
	// Ruining the mount doesn't give the fish back either: it is destroyed
	// with the plaque (EEHealthLevelChanged below).
	//
	// One way out: a trophy too big for its board. The 3.3.2 Wooden Fish Mount
	// took any catch and is now the small plaque (same class), so a pike or a
	// shark mounted on it before 3.3.3 can be taken off and hung on a medium or
	// large board, where it is permanent again.
	override bool CanReleaseAttachment(EntityAI attachment) {
		if (!attachment)
			return false;
		GebMountPose pose = GebMountPoses.Get(attachment.GetType());
		return pose && pose.Size > GebMountSize();
	}

	// The trophy dies with the plaque. Vanilla hands a ruined container's
	// attachments back, which would make "smash the mount" the recovery route
	// CanReleaseAttachment exists to prevent -- and would turn the plaque into a
	// never-rots fish locker with one extra step. Destroying the fish outright
	// keeps mounting genuinely permanent: the decision to mount a catch is final.
	//
	// Same hook and the same STATE_RUINED check vanilla's ImprovisedExplosive
	// uses to ruin its attachments; this deletes rather than ruins so a smashed
	// plaque doesn't leave a worthless fish lying on the ground.
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);

		if (g_Game.IsServer() && newLevel == GameConstants.STATE_RUINED)
			DestroyMountedFish();
	}

	// Counting down: deleting shrinks the attachment list, so walking up would
	// skip entries. The mount only has the one slot today, but this stays
	// correct if it ever gains another.
	protected void DestroyMountedFish() {
		if (!g_Game.IsServer() || !GetInventory())
			return;

		for (int i = GetInventory().AttachmentCount() - 1; i >= 0; --i) {
			EntityAI attachment = GetInventory().GetAttachmentFromIndex(i);
			if (attachment)
				attachment.Delete();
		}
	}

	// Placement. ItemBase.IsDeployable() is false by default, so without
	// this the hold-to-place hologram never appears at all and the modded
	// Hologram below never gets a chance to run its wall snapping.
	override bool IsDeployable() {
		return true;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}

	// How far from the player's feet the plaque can go. The hologram clamps
	// the aim point to this (Hologram.SetHologramPosition below).
	static const float PLACEMENT_REACH = 2.5;

	// Also the server's check: the server never runs the hologram's aim test,
	// so without this a modified client could send any position. The extra
	// 0.5 m covers the player shifting between placing and the server's check.
	override bool CanBePlaced(Man player, vector position) {
		if (!super.CanBePlaced(player, position))
			return false;
		if (!player)
			return true;
		float maxDistance = PLACEMENT_REACH + 0.5;
		return vector.DistanceSq(player.GetPosition(), position) <= maxDistance * maxDistance;
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0") {
		super.OnPlacementComplete(player, position, orientation);
		// Keep the wall angle the hologram previewed -- the base call would
		// otherwise leave the plaque lying flat.
		if (g_Game.IsServer())
			SetOrientation(orientation);
	}
}

// For pike, muskies, catfish, cod and the crabs, and anything smaller.
class geb_MediumFishMount : geb_WoodenFishMount {
	override int GebMountSize() {
		return 1;
	}

	override float GebFieldBottom() {
		return -0.192;
	}

	override float GebFieldTop() {
		return 0.283;
	}

	override float GebHalfHeight() {
		return 0.31;
	}
}

// For the sturgeon, billfish, mahi-mahi and sharks, and anything smaller. The
// big fish are taller than the field and simply overhang the board.
class geb_LargeFishMount : geb_WoodenFishMount {
	override int GebMountSize() {
		return 2;
	}

	override float GebFieldBottom() {
		return -0.396;
	}

	override float GebFieldTop() {
		return 0.563;
	}

	override float GebHalfHeight() {
		return 0.60;
	}
}

// Wall-snapping placement for the fish mounts. Vanilla's advanced placement
// (hold-to-place from hands) aligns holograms to the GROUND; this modded
// Hologram intercepts the update for geb_WoodenFishMount and its subclasses,
// raycasts along the player's facing, and when the hit surface is
// near-vertical it pins the projection flat against the wall. No wall in
// reach -> vanilla's ground placement turned to the camera, the board
// standing upright on its bottom edge.
modded class Hologram {

	// A surface counts as a wall while its normal is mostly horizontal.
	// |normal.y| of 0 = perfectly vertical wall, 1 = flat floor/ceiling.
	private const float GEB_MOUNT_WALL_MAX_NY = 0.45;

	// How far behind the board's back a wall may be (m). The client hangs the
	// board flush on the surface it aims at; the margin covers uneven walls.
	private const float GEB_MOUNT_WALL_GAP = 0.06;

	// Whether the board being placed hangs on a wall, set at the start of each
	// EvaluateCollision (GebMountBackedByWall). The ground tests below are
	// skipped only then: standing on the floor the board gets them like
	// anything else, or it could be stood in a doorway or through a door, a car
	// or a tent.
	protected bool m_GebMountOnWall;

	override void UpdateHologram(float timeslice) {
		if (!m_Parent || !m_Parent.IsInherited(geb_WoodenFishMount)) {
			super.UpdateHologram(timeslice);
			return;
		}
		// Vanilla's update drops the hologram while the player can't place
		// things; this replacement has to as well.
		if (GebPlacementRestricted()) {
			m_Player.TogglePlacingLocal();
			return;
		}
		if (!m_Projection || !GetUpdatePosition())
			return;

		// Reuse vanilla's own placement raycast rather than casting again:
		// it goes from the camera along the view direction with the correct
		// intersect type, and leaves the hit surface normal in m_ContactDir.
		vector position = GetProjectionEntityPosition(m_Player);
		vector normal = m_ContactDir;
		bool onWall = normal.Length() > 0 && Math.AbsFloat(normal[1]) < GEB_MOUNT_WALL_MAX_NY;
		// On the floor the board stands upright on its bottom edge; its origin
		// is the middle of its back, so lift it by half its height.
		geb_WoodenFishMount mount = geb_WoodenFishMount.Cast(m_Parent);
		if (!onWall && mount)
			position[1] = position[1] + mount.GebHalfHeight();
		SetProjectionPosition(position);

		if (onWall) {
			normal.Normalize();
			// Hang it like a picture: the plaque's face points straight out along
			// the wall normal, and its top stays world-up so it never lands
			// rotated or upside down on a sloped wall.
			//
			// Argument order matters and is easy to get backwards.
			// DirectionAndUpMatrix(dir, up, mat) puts `dir` on the Z axis and
			// `up` on the Y axis (see the worked example on the proto, and
			// vanilla's own PluginCharPlacement call which passes the facing
			// direction first and "0 1 0" second). Passing the wall normal as
			// `up` instead of as `dir` rolls the plaque 90 degrees onto its side.
			vector mat[4];
			Math3D.DirectionAndUpMatrix(normal, "0 1 0", mat);
			vector rot[3];
			rot[0] = mat[0];
			rot[1] = mat[1];
			rot[2] = mat[2];
			SetProjectionOrientation(Math3D.MatrixToAngles(rot));
		} else {
			SetProjectionOrientation(AlignProjectionOnTerrain(timeslice));
		}

		EvaluateCollision();
		RefreshTrigger();
		CheckPowerSource();
		RefreshVisual();
		m_Projection.OnHologramBeingPlaced(m_Player);
	}

	// Client (every frame while placing) and server (each check of the place
	// action) both come through here, so both decide wall or floor the same way
	// before the tests run.
	override void EvaluateCollision(ItemBase action_item = null) {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			m_GebMountOnWall = GebMountBackedByWall();
		super.EvaluateCollision(action_item);
	}

	// True when the board, where it is now, has a wall right behind it: the
	// middle of its back and at least three of four points out towards its
	// corners each meet one within GEB_MOUNT_WALL_GAP. Decided from the board's
	// own position and angle rather than from the aim, because the server never
	// sees the client's aim, only the position and orientation it sends. A
	// board standing on the floor backed against a wall counts as hung on it,
	// which is harmless.
	protected bool GebMountBackedByWall() {
		if (!m_Projection)
			return false;
		vector minMax[2];
		GetProjectionCollisionBox(minMax);
		float midX = (minMax[0][0] + minMax[1][0]) * 0.5;
		float midY = (minMax[0][1] + minMax[1][1]) * 0.5;
		float dx = (minMax[1][0] - minMax[0][0]) * 0.3;
		float dy = (minMax[1][1] - minMax[0][1]) * 0.3;
		float back = minMax[0][2];
		if (!GebWallBehind(midX, midY, back))
			return false;
		int corners = 0;
		if (GebWallBehind(midX - dx, midY - dy, back))
			corners++;
		if (GebWallBehind(midX + dx, midY - dy, back))
			corners++;
		if (GebWallBehind(midX - dx, midY + dy, back))
			corners++;
		if (GebWallBehind(midX + dx, midY + dy, back))
			corners++;
		return corners >= 3;
	}

	// One ray straight back out of the board at (x, y) on its back, from just
	// inside it to GEB_MOUNT_WALL_GAP behind. What it meets counts as a wall
	// when it stays put: the ground, rocks, trees, map buildings and
	// player-built walls do. A building's door does not (a board hung on one
	// would be left standing in the doorway once it opened), nor anything else
	// that moves or can be packed away: vehicles, tents, crates, another board.
	protected bool GebWallBehind(float x, float y, float back) {
		vector from = m_Projection.ModelToWorld(Vector(x, y, back + 0.03));
		vector to = m_Projection.ModelToWorld(Vector(x, y, back - GEB_MOUNT_WALL_GAP));
		RaycastRVParams ray = new RaycastRVParams(from, to, m_Projection);
		ray.with = m_Player;
		array<ref RaycastRVResult> hits = new array<ref RaycastRVResult>();
		if (!DayZPhysics.RaycastRVProxy(ray, hits) || hits.Count() == 0)
			return false;
		RaycastRVResult hit = hits[0];
		if (!hit.obj)
			return true;
		Building building = Building.Cast(hit.obj);
		if (building)
			return building.GetDoorIndex(hit.component) < 0;
		if (hit.obj.IsInherited(BaseBuildingBase))
			return true;
		return !hit.obj.IsInherited(EntityAI);
	}

	// Vanilla's two box tests put the box's middle half its height above the
	// object's origin, taking the origin to be its bottom. The board's origin
	// is the middle of its back, so on the floor they would test a box half a
	// board too high and miss its lower half. This tests the board where it
	// stands, the box lifted the 5 cm vanilla lifts it clear of the floor.
	// proxies: the geometry-proxy sweep (player-built and map structures)
	// instead of the plain box test.
	protected bool GebMountBoxColliding(ItemBase action_item, bool proxies) {
		if (CfgGameplayHandler.GetDisableIsCollidingBBoxCheck())
			return false;
		vector minMax[2];
		GetProjectionCollisionBox(minMax);
		vector lift = "0 0.05 0";
		vector centre = m_Projection.ModelToWorld((minMax[0] + minMax[1]) * 0.5) + lift;
		vector orientation = GetProjectionOrientation();
		vector edgeLength = GetCollisionBoxSize(minMax);
		array<Object> excluded = new array<Object>();
		excluded.Insert(m_Projection);
		excluded.Insert(m_Player);
		if (action_item)
			excluded.Insert(action_item);
		if (proxies) {
			BoxCollidingParams params = new BoxCollidingParams();
			params.SetParams(centre, orientation, edgeLength, ObjIntersect.View, ObjIntersect.Geom, false);
			array<ref BoxCollidingResult> proxyHits = new array<ref BoxCollidingResult>();
			return g_Game.IsBoxCollidingGeometryProxy(params, excluded, proxyHits);
		}
		array<Object> collided = new array<Object>();
		return g_Game.IsBoxCollidingGeometry(centre, orientation, edgeLength, ObjIntersectFire, ObjIntersectGeom, excluded, collided);
	}

	// The same list as vanilla's IsRestrictedFromAdvancedPlacing, which is
	// private to Hologram and so can't be called from here.
	protected bool GebPlacementRestricted() {
		if (m_Player.IsJumpInProgress())
			return true;
		if (m_Player.IsSwimming())
			return true;
		if (m_Player.IsClimbingLadder())
			return true;
		if (m_Player.IsRaised())
			return true;
		if (m_Player.IsClimbing())
			return true;
		if (m_Player.IsRestrained())
			return true;
		if (m_Player.IsUnconscious())
			return true;
		return false;
	}

	// Vanilla clamps the aim point to 1-2 m from the player's feet and marks a
	// clamped point as floating (red). 2 m from the feet only reaches about
	// head height on a wall, so the mount gets PLACEMENT_REACH instead: high
	// enough for a trophy above eye level, and still red past that.
	override protected bool SetHologramPosition(vector startPosition, float minProjectionDistance, float maxProjectionDistance, inout vector contactPosition) {
		if (!m_Parent || !m_Parent.IsInherited(geb_WoodenFishMount))
			return super.SetHologramPosition(startPosition, minProjectionDistance, maxProjectionDistance, contactPosition);

		maxProjectionDistance = Math.Max(maxProjectionDistance, geb_WoodenFishMount.PLACEMENT_REACH);
		bool clamped = super.SetHologramPosition(startPosition, minProjectionDistance, maxProjectionDistance, contactPosition);
		// The aim ray hit nothing (GetProjectionEntityPosition zeroes
		// m_ContactDir and only a hit fills it in): there is no wall or floor
		// to put the plaque on, wherever the ray happened to end. In third
		// person that end point can fall inside the longer reach.
		return clamped || m_ContactDir.Length() == 0;
	}

	// On a wall the plaque deliberately sits flush against it -- the vanilla
	// bounding-box collision test would read that as a collision and paint
	// the hologram permanently red, so it is skipped there. On the floor the
	// board gets the test, measured where it stands.
	override bool IsCollidingBBox(ItemBase action_item = null) {
		if (!m_Parent || !m_Parent.IsInherited(geb_WoodenFishMount))
			return super.IsCollidingBBox(action_item);
		if (m_GebMountOnWall)
			return false;
		return GebMountBoxColliding(action_item, false);
	}

	// The box test's twin, and the reason the plaque wouldn't go on buildings.
	// IsCollidingBBox only covers the simple bounding box; player-built and map
	// structures are geometry proxies, which get this separate sweep. Sitting
	// flush against a wall is a collision to it by definition, so on a wall it
	// is skipped; on the floor it runs, measured where the board stands.
	override bool IsCollidingGeometryProxy(ItemBase action_item = null) {
		if (!m_Parent || !m_Parent.IsInherited(geb_WoodenFishMount))
			return super.IsCollidingGeometryProxy(action_item);
		if (m_GebMountOnWall)
			return false;
		return GebMountBoxColliding(action_item, true);
	}

	// ---- the rest of EvaluateCollision's ground-placement assumptions ----
	// EvaluateCollision runs a long chain of tests, and nearly all of them are
	// written for something being set down on the ground. A plaque hanging on a
	// wall fails them by definition, so each one below opts out while the board
	// hangs on a wall (m_GebMountOnWall) or the hologram stays red and placement
	// is refused. Standing on the floor the board gets them all, as anything
	// set down does. Everything NOT listed here always applies -- player
	// collision, permitted-area, underwater and in-terrain all remain in force,
	// so this doesn't become a free pass.

	// IsFloating is deliberately NOT overridden. Vanilla's "floating" doesn't
	// mean "nothing underneath": it means the aim point was out of reach and
	// got clamped, and switching it off let the plaque be hung in mid-air.

	// There is no ground surface below a wall plaque to qualify.
	override bool IsBaseViable() {
		if (m_GebMountOnWall && m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return true;
		return super.IsBaseViable();
	}

	// Mounting on an interior wall means there is a ceiling overhead; the roof
	// clipping guard exists to stop things being stuck to the underside of a
	// floor, which is not what is happening here.
	override bool IsClippingRoof() {
		if (m_GebMountOnWall && m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return false;
		return super.IsClippingRoof();
	}

	// Vanilla limits how far above or below the player an object can be placed.
	// A trophy belongs at eye level or higher on the wall, which trips it.
	override bool HeightPlacementCheck() {
		if (m_GebMountOnWall && m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return true;
		return super.HeightPlacementCheck();
	}

}
