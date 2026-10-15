/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The Fishing Locker (data/locker/config.cpp; model, maps and Model.cfg built by
// tools/locker). A placed container like vanilla's sea chest and wooden crate,
// with twenty spots that show what is in them: six rods, the fishing clothes, a
// backpack, two tackle boxes, a cooler, the bait bucket, a worm or bug
// container and two fish traps, plus the cabinet's cargo.
//
// Each spot is a proxy in its own Model.cfg bone. Items differ a lot in size and
// in where their model's origin is, so when one is attached the bone is moved to
// stand it where its spot says (GebLockerSpots, generated from the build's
// layout): its loot box turned the way the proxy turns it, then set on the shelf,
// hung from the peg or laid against the panel. A medium tackle box sits on the
// shelf as a large one does, and any backpack hangs flat against the side.
class geb_FishingLocker : DeployableContainer_Base {

	void geb_FishingLocker() {
		// Where vanilla spreads the contents when the locker is ruined
		// (DeployableContainer_Base.EEHealthLevelChanged): half the footprint,
		// and in y a height offset rather than a half extent.
		m_HalfExtents = Vector(0.9, 0.1, 0.27);
	}

	// Back into hands only once it is empty, cargo and spots alike: a full
	// two-metre locker carried about would be a stash on legs.
	override bool CanPutIntoHands(EntityAI parent) {
		if (!super.CanPutIntoHands(parent))
			return false;
		return GetInventory().CountInventory() <= 1;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		// Only a locker standing in the world takes gear. Vanilla's take action
		// looks for a free spot through everything the player carries, slots
		// included, so a locker in hands could otherwise swallow a picked-up rod.
		if (GetHierarchyParent())
			return false;

		// A set trap stays where it was set.
		TrapSpawnBase trap = TrapSpawnBase.Cast(attachment);
		if (trap && (trap.IsDeployed() || trap.IsActive()))
			return false;

		return true;
	}

	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		GebPlaceItem(item, slot_name);
	}

	// Attachments come back after a restart through EEItemAttached as well;
	// this covers a load order where the locker's own state arrives last.
	override void AfterStoreLoad() {
		super.AfterStoreLoad();
		GebPlaceAll();
	}

	void GebPlaceAll() {
		if (!GetInventory())
			return;

		for (int i = 0; i < GetInventory().AttachmentCount(); i++) {
			EntityAI item = GetInventory().GetAttachmentFromIndex(i);
			InventoryLocation loc = new InventoryLocation();
			if (item && item.GetInventory().GetCurrentInventoryLocation(loc))
				GebPlaceItem(item, InventorySlots.GetSlotName(loc.GetSlot()));
		}
	}

	// Moves the spot's bone (animations <spot>_x/_y/_z: 0.5 + metres / 4) so the
	// item's loot box lands as its spot's rules say, per locker axis: l its low
	// side on the spot's point, h its high side, c centred, o the item's own
	// origin left there. Nothing is ever pushed into the ground. Runs on the
	// server and on every client that sees the attachment, so both sides place it
	// from the same item.
	void GebPlaceItem(EntityAI item, string slotName) {
		GebLockerSpot spot = GebLockerSpots.Get(slotName);
		if (!item || !spot)
			return;

		vector lo;
		vector hi;
		if (!GebLootBox(item, lo, hi))
			return;

		// The loot box's corners turned into the locker's axes.
		vector boxLo = Vector(1000000, 1000000, 1000000);
		vector boxHi = Vector(-1000000, -1000000, -1000000);
		for (int i = 0; i < 8; i++) {
			float cx = lo[0];
			if (i & 1)
				cx = hi[0];
			float cy = lo[1];
			if (i & 2)
				cy = hi[1];
			float cz = lo[2];
			if (i & 4)
				cz = hi[2];
			vector p = spot.AxisX * cx + spot.AxisY * cy + spot.AxisZ * cz;
			for (int a = 0; a < 3; a++) {
				boxLo[a] = Math.Min(boxLo[a], p[a]);
				boxHi[a] = Math.Max(boxHi[a], p[a]);
			}
		}

		vector move = vector.Zero;
		for (int k = 0; k < 3; k++) {
			string rule = spot.Rules.Get(k);
			if (rule == "l")
				move[k] = -boxLo[k];
			else if (rule == "h")
				move[k] = -boxHi[k];
			else if (rule == "c")
				move[k] = -(boxLo[k] + boxHi[k]) / 2.0;
		}
		if (spot.Anchor[1] + move[1] + boxLo[1] < 0)
			move[1] = -spot.Anchor[1] - boxLo[1];

		string axes = "xyz";
		for (int n = 0; n < 3; n++) {
			if (spot.Rules.Get(n) != "o")
				SetAnimationPhase(spot.Spot + "_" + axes.Get(n), 0.5 + move[n] / 4.0);
		}
	}

	// The item's loot box: the memory points every item model carries for the
	// engine's own ground placement (so "on the shelf" means just what "dropped
	// on the shelf" would), else the model's clipping box.
	bool GebLootBox(EntityAI item, out vector lo, out vector hi) {
		if (item.MemoryPointExists("boundingbox_min") && item.MemoryPointExists("boundingbox_max")) {
			vector a = item.GetMemoryPointPos("boundingbox_min");
			vector b = item.GetMemoryPointPos("boundingbox_max");
			lo = Vector(Math.Min(a[0], b[0]), Math.Min(a[1], b[1]), Math.Min(a[2], b[2]));
			hi = Vector(Math.Max(a[0], b[0]), Math.Max(a[1], b[1]), Math.Max(a[2], b[2]));
			return true;
		}

		vector minMax[2];
		item.ClippingInfo(minMax);
		lo = minMax[0];
		hi = minMax[1];
		return lo != hi;
	}
}
