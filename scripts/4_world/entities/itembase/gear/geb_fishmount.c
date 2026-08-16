/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Wooden trophy mount. One item covers every catchable: the plaque carries a
// single GebFishMount attachment slot (CfgSlots in data/tools/config.cpp) and
// the player attaches the ACTUAL caught fish -- its model renders on the
// plaque via the gebfishmount proxy and its weight/quality persist through
// normal attachment save/load. Rot for the mounted fish is paused in
// Edible_Base.ProcessDecay (see geb_ediblebase.c) so trophies are taxidermy,
// not a countdown to a rotten wall.
class geb_WoodenFishMount : ItemBase {

	// No rotten or ruined trophies. Everything else the slot accepts
	// (config-side inventorySlot[] on the fish bases) is fair game.
	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		ItemBase item = ItemBase.Cast(attachment);
		if (item && item.IsRuined())
			return false;

		Edible_Base food = Edible_Base.Cast(attachment);
		if (food && food.HasFoodStage() && food.GetFoodStageType() == FoodStageType.ROTTEN)
			return false;

		return true;
	}

	// Mounting is permanent: once a fish is on the plaque it can't be
	// detached, dragged out, or taken to hands -- taxidermy, not storage.
	// This also stops the mount doubling as a free never-rots fish locker.
	// The only way to get the fish back is destroying the mount (vanilla
	// drops attachments when the parent is ruined).
	override bool CanReleaseAttachment(EntityAI attachment) {
		return false;
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

	override bool CanBePlaced(Man player, vector position) {
		return true;
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0") {
		super.OnPlacementComplete(player, position, orientation);
		// Keep the wall angle the hologram previewed -- the base call would
		// otherwise leave the plaque lying flat.
		if (g_Game.IsServer())
			SetOrientation(orientation);
	}
}

// Wall-snapping placement for the fish mount. Vanilla's advanced placement
// (hold-to-place from hands) aligns holograms to the GROUND; this modded
// Hologram intercepts the update for geb_WoodenFishMount, raycasts along the
// player's facing, and when the hit surface is near-vertical it pins the
// projection flat against the wall. No wall in reach -> falls through to the
// vanilla ground placement, so the plaque can still be set down flat.
modded class Hologram {

	// A surface counts as a wall while its normal is mostly horizontal.
	// |normal.y| of 0 = perfectly vertical wall, 1 = flat floor/ceiling.
	private const float GEB_MOUNT_WALL_MAX_NY = 0.45;

	override void UpdateHologram(float timeslice) {
		if (!m_Parent || !m_Parent.IsInherited(geb_WoodenFishMount)) {
			super.UpdateHologram(timeslice);
			return;
		}
		if (!m_Projection || !GetUpdatePosition())
			return;

		// Reuse vanilla's own placement raycast rather than casting again:
		// it goes from the camera along the view direction with the correct
		// intersect type, and leaves the hit surface normal in m_ContactDir.
		SetProjectionPosition(GetProjectionEntityPosition(m_Player));

		vector normal = m_ContactDir;
		if (normal.Length() > 0 && Math.AbsFloat(normal[1]) < GEB_MOUNT_WALL_MAX_NY) {
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

	// The plaque deliberately sits flush against the wall -- the vanilla
	// bounding-box collision test would read that as a collision and paint
	// the hologram permanently red, so skip it for the mount only.
	override bool IsCollidingBBox(ItemBase action_item = null) {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return false;
		return super.IsCollidingBBox(action_item);
	}

	// The box test's twin, and the reason the plaque wouldn't go on buildings.
	// IsCollidingBBox only covers the simple bounding box; player-built and map
	// structures are geometry proxies, which get this separate sweep. Sitting
	// flush against a wall is a collision to it by definition, so a mount that
	// placed fine on a lone surface was refused on anything proxy-based.
	override bool IsCollidingGeometryProxy(ItemBase action_item = null) {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return false;
		return super.IsCollidingGeometryProxy(action_item);
	}

	// ---- the rest of EvaluateCollision's ground-placement assumptions ----
	// EvaluateCollision runs a long chain of tests, and nearly all of them are
	// written for something being set down on the ground. A plaque hanging on a
	// wall fails them by definition, so each one below has to opt out for the
	// mount or the hologram stays red and placement is refused. Everything NOT
	// listed here still applies -- player collision, permitted-area, underwater
	// and in-terrain all remain in force, so this doesn't become a free pass.

	// Nothing underneath a wall mount: that IS the point, not an error.
	override bool IsFloating() {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return false;
		return super.IsFloating();
	}

	// Same reason -- there is no ground surface below the plaque to qualify.
	override bool IsBaseViable() {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return true;
		return super.IsBaseViable();
	}

	// Mounting on an interior wall means there is a ceiling overhead; the roof
	// clipping guard exists to stop things being stuck to the underside of a
	// floor, which is not what is happening here.
	override bool IsClippingRoof() {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return false;
		return super.IsClippingRoof();
	}

	// Vanilla limits how far above or below the player an object can be placed.
	// A trophy belongs at eye level or higher on the wall, which trips it.
	override bool HeightPlacementCheck() {
		if (m_Parent && m_Parent.IsInherited(geb_WoodenFishMount))
			return true;
		return super.HeightPlacementCheck();
	}

}

