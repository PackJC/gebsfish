/*

  CREATED BY PACKJC
  https://smokymountainsoftware.com
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  https://www.smokymountainsoftware.com/ Contributions welcome via github

*/


class geb_FilteredContainerBase : Container_Base {
	protected TStringArray GetAllowedItemKinds() {
		return null;
	}

	// Kinds refused even when the allow list would take them.
	protected TStringArray GetRefusedItemKinds() {
		return null;
	}

	// Kinds taken as their own class only, not the classes built on them:
	// vanilla Shrimp in a tackle box, where "Shrimp" by inheritance would
	// also take every crayfish, clam, snail, starfish and jellyfish.
	protected TStringArray GetExactItemKinds() {
		return null;
	}

	override int GetDamageSystemVersionChange() {
		return 110;
	}

	// Shared check so the drag-drop path (CanReceiveItemIntoCargo) and the
	// script/persistence path (CanLoadItemIntoCargo) stay in lockstep.
	// Vanilla DayZ does not always route every cargo move through the same
	// check, so overriding both keeps disallowed items out of moves such as
	// quickbar swaps, and out of save-load. A new item created straight into
	// the cargo by classname (CreateInInventory, a craft result) is checked
	// by neither: see GebAcceptsType below.
	protected bool IsAllowedCargoItem(EntityAI item) {
		if (!item)
			return false;

		TStringArray refused = GetRefusedItemKinds();
		if (refused) {
			foreach (string kind : refused) {
				if (item.IsKindOf(kind))
					return false;
			}
		}

		if (GebTypeIsExact(item.GetType(), GetExactItemKinds()))
			return true;

		TStringArray allowed = GetAllowedItemKinds();
		if (!allowed || allowed.Count() == 0)
			return false;

		for (int i = 0; i < allowed.Count(); i++) {
			if (item.IsKindOf(allowed.Get(i)))
				return true;
		}

		return false;
	}

	// The same rule by classname, for an item that doesn't exist yet. The
	// engine only asks the cargo checks here about an existing item, while
	// CreateInInventory places a new one by classname without asking, so
	// anything spawning straight into one of these containers must check
	// this first.
	bool GebAcceptsType(string type) {
		if (GebTypeMatches(type, GetRefusedItemKinds()))
			return false;
		if (GebTypeIsExact(type, GetExactItemKinds()))
			return true;
		return GebTypeMatches(type, GetAllowedItemKinds());
	}

	// A new `type` in owner's inventory (a player's, or a container's) at the
	// spot CreateInInventory would pick: the first free cargo or attachment
	// spot, which the engine may find inside another container there. Null
	// when there is none, or when that spot is inside one of these containers
	// that refuses the type, since the engine picks it by classname without
	// asking their cargo checks and the next restart would throw the item out.
	static EntityAI GebCreateInInventory(EntityAI owner, string type) {
		if (!owner || !owner.GetInventory() || type == "")
			return null;
		InventoryLocation loc = new InventoryLocation();
		if (!owner.GetInventory().FindFirstFreeLocationForNewEntity(type, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT, loc))
			return null;
		EntityAI parent = loc.GetParent();
		if (!parent || !parent.GetInventory())
			return null;
		// The spot's container and every one it sits in, up to the owner.
		EntityAI holder = parent;
		while (holder) {
			geb_FilteredContainerBase filtered = geb_FilteredContainerBase.Cast(holder);
			if (filtered && !filtered.GebAcceptsType(type))
				return null;
			if (holder == owner)
				break;
			holder = holder.GetHierarchyParent();
		}
		if (loc.GetType() == InventoryLocationType.ATTACHMENT)
			return parent.GetInventory().CreateAttachmentEx(type, loc.GetSlot());
		if (loc.GetType() == InventoryLocationType.CARGO)
			return parent.GetInventory().CreateEntityInCargoEx(type, loc.GetIdx(), loc.GetRow(), loc.GetCol(), loc.GetFlip());
		return null;
	}

	// The type is one of the listed classes itself (any case), not a
	// subclass of one.
	static bool GebTypeIsExact(string type, TStringArray kinds) {
		if (type == "" || !kinds)
			return false;
		foreach (string kind : kinds) {
			if (GebSameClassname(type, kind))
				return true;
		}
		return false;
	}

	// The type is one of the listed classes or inherits from one (config
	// inheritance). The explicit name match covers the class itself, the
	// way vanilla's recipe matching pairs it with IsKindOf.
	static bool GebTypeMatches(string type, TStringArray allowed) {
		if (type == "" || !allowed)
			return false;
		foreach (string kind : allowed) {
			if (GebSameClassname(type, kind) || g_Game.IsKindOf(type, kind))
				return true;
		}
		return false;
	}

	// Vanilla's checks first: Container_Base refuses new items while the
	// container itself sits in another container's cargo (a tackle box in a
	// backpack), and the engine checks the item actually fits.
	override bool CanReceiveItemIntoCargo(EntityAI item) {
		if (!super.CanReceiveItemIntoCargo(item))
			return false;
		return IsAllowedCargoItem(item);
	}

	// Loading from storage deliberately has no "inside other cargo" check (in
	// vanilla either): a stored box's contents must reload where they were.
	override bool CanLoadItemIntoCargo(EntityAI item) {
		if (!super.CanLoadItemIntoCargo(item))
			return false;
		return IsAllowedCargoItem(item);
	}
};

class geb_WormContainer : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Worm", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;
		// Self-nesting guard, matching the other geb containers. The allow
		// list already blocks this on the receiving side, but vanilla does
		// not route every inventory move through the same check.
		if (parent && parent.IsKindOf("geb_WormContainer"))
			return false;
		return true;
	}
};

class geb_BugContainer : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	// No IsContainer() override: vanilla Container_Base already returns true.

	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;

		// Prevent bug containers from being placed inside other bug containers.
		// This blocks self-nesting while still allowing normal cargo rules elsewhere.
		if (parent && parent.IsKindOf("geb_BugContainer"))
			return false;

		return true;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionDigBugs);
	}
};

class geb_BambooFishingNet : geb_FilteredContainerBase {
	// geb_Crayfish_Base covers all seven crayfish, so any of them an admin
	// adds to the net's catch table fits in the net.
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_FatHeadMinnow", "geb_Crayfish_Base", "geb_AmericanBullFrog", "geb_RedSalamander" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;

		// Prevent bamboo fishing nets from being placed inside other bamboo fishing nets.
		// This blocks self-nesting while still allowing normal cargo rules elsewhere.
		if (parent && parent.IsKindOf("geb_BambooFishingNet"))
			return false;

		return true;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionBambooFishingNet);
	}
};

class geb_MinnowBucket : geb_FilteredContainerBase {
	// The filter matches by config inheritance, so "Shrimp" admits every
	// small aquatic catch built on it: the minnow, frog and salamander, all
	// seven crayfish, the blood clam, mussel, snail, starfish and jellyfish.
	// That's intended -- they're all small water creatures kept fresh in a
	// bucket. The explicit entries keep the list readable and still work if
	// one of them stops inheriting Shrimp. Bitterlings and Sardines aren't
	// Shrimp: vanilla's trap baitfish, hook bait like the minnow.
	static ref TStringArray s_Allowed = { "geb_FatHeadMinnow", "geb_Crayfish_Base", "Shrimp", "geb_AmericanBullFrog", "geb_RedSalamander", "Bitterlings", "Sardines" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;
		// Self-nesting guard, matching the other geb containers.
		if (parent && parent.IsKindOf("geb_MinnowBucket"))
			return false;
		return true;
	}
};

// Tackle-box allow lists. Three groups of entries:
//
//   1. ARTIFICIAL LURES -- "geb_Lure" catches all 16 lure variants via the
//      config inheritance walk (geb_SpinnerBait1-4 / geb_SpoonLure1-4 /
//      geb_Lure1-4 / geb_CurlyTailJig1-4 all extend geb_Lure). "Jig" stays
//      for vanilla jigs.
//   2. LIVE BAIT -- worms (vanilla + grub + rubber), insects (grasshopper +
//      cricket), minnows, salamander, bullfrog, bitterlings, sardines, and
//      vanilla shrimp as its own class only (s_Exact). Players can stash bait
//      directly in the tackle box instead of always needing the dedicated
//      worm/bug/minnow containers, while the dedicated containers still
//      remain the most efficient way to organize bait at scale.
//   3. TOOLS -- hooks, knives, pliers, gloves, dedicated bait containers,
//      the bamboo fishing net, and the geb_FishingRodRepairKit. The cargo
//      grids were bumped (small 6x1 -> 6x2, large 9x1 -> 9x3 in
//      data/tackle/config.cpp) so the 2x2 repair kit fits.

class geb_SmallTackleBase : geb_FilteredContainerBase {
	// Vanilla Shrimp (hook bait) by its own class only: the crayfish, clams,
	// mussels, snails, starfish and jellyfish are built on it too.
	static ref TStringArray s_Exact = { "Shrimp" };

	override protected TStringArray GetExactItemKinds() {
		return s_Exact;
	}

	static ref TStringArray s_Allowed = {
		// Lures / jigs
		"Jig", "geb_Lure",
		// Live bait
		"Worm", "geb_GrubWorm", "geb_RubberWorm",
		"geb_GrassHopper", "geb_FieldCricket",
		"geb_FatHeadMinnow", "geb_RedSalamander", "geb_AmericanBullFrog",
		"Bitterlings", "Sardines",
		// Tools / containers
		"geb_FishGloves_Base",  // every colour of fishing gloves, and any added later
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"geb_FishingRodRepairKit",
		"Hook", "BoneHook", "WoodenHook", "geb_FishKnife_Base", "BoneKnife", "Pliers"
	};

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}
};

class geb_LargeTackleBase : geb_FilteredContainerBase {
	// Vanilla Shrimp (hook bait) by its own class only: the crayfish, clams,
	// mussels, snails, starfish and jellyfish are built on it too.
	static ref TStringArray s_Exact = { "Shrimp" };

	override protected TStringArray GetExactItemKinds() {
		return s_Exact;
	}

	static ref TStringArray s_Allowed = {
		// Lures / jigs
		"Jig", "geb_Lure",
		// Live bait
		"Worm", "geb_GrubWorm", "geb_RubberWorm",
		"geb_GrassHopper", "geb_FieldCricket",
		"geb_FatHeadMinnow", "geb_RedSalamander", "geb_AmericanBullFrog",
		"Bitterlings", "Sardines",
		// Tools / containers
		"geb_FishGloves_Base",  // every colour of fishing gloves, and any added later
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"geb_FishingRodRepairKit",
		"Hook", "BoneHook", "WoodenHook", "geb_FishKnife_Base", "BoneKnife",
		"Cleaver", "CombatKnife", "HuntingKnife", "ak_bayonet", "m9a1_bayonet",
		"Pliers", "Screwdriver", "Steakknife", "stoneknife"
	};

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}
};

// Cooler container -- preserves the fish products parented in its cargo.
// The actual decay stop lives in the modded Edible_Base.ProcessDecay
// override (see edible_base/geb_ediblebase.c). This class only handles
// cargo filtering + nesting prevention.
//
// Named geb_Cooler_base to match the config-side base class. The
// colored variants (geb_RedCooler / geb_BlueCooler / etc.) don't need
// their own script classes -- DayZ falls back to the config parent's
// script class at instantiation, so every variant gets the same cargo
// filter and decay-preservation behavior automatically.
//
// The allow list is a single key: every food and drink item in the game
// (whole fish, fillets, caviar, fruit, vegetables, meat, cans, drinks)
// descends from the vanilla Edible_Base config class, so IsKindOf on it
// admits all of them -- including liquid containers like canteens and
// pots, which extend Bottle_Base -> Edible_Base. Non-food gear stays out,
// and so does the Bait Bucket: its config is a WaterBottle, for the water
// its bait lives in, which makes it an Edible_Base too.
class geb_Cooler_base : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Edible_Base" };
	static ref TStringArray s_Refused = { "geb_MinnowBucket" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override protected TStringArray GetRefusedItemKinds() {
		return s_Refused;
	}

	// Active chilling: every tick, cargo items step toward COOLING_TARGET_C,
	// so contents visibly go chilly, then cold (the inventory temperature
	// tint follows the value down), and -- because the target sits below the
	// per-item freeze threshold -- eventually FROZEN. Freezing is gradual
	// and vanilla-driven: SetTemperature parks the item at its freeze
	// threshold (0C for food) while vanilla's freeze progression runs, then
	// flips it frozen and lets it sink to the target. Frozen food must thaw
	// (campfire, or just outside the cooler) before it can be eaten or
	// filleted -- that's the gameplay trade-off of long-term storage.
	//   COOLING_TARGET_C  = temperature contents settle at (below 0 = freezer)
	//   COOLING_STEP_C    = degrees moved per tick
	//   COOLING_TICK_SECS = seconds of the CE update's elapsed time per tick
	protected const float COOLING_TARGET_C  = -5.0;
	protected const float COOLING_STEP_C    = 1.5;
	protected const float COOLING_TICK_SECS = 60.0;

	// Seconds of cooling not yet spent on a tick (see OnCEUpdate).
	protected float m_CoolingElapsed;

	// Vanilla skips ambient temperature processing for any item whose
	// hierarchy ROOT self-adjusts (EntityAI.ProcessVariables and
	// ItemBase.ProcessItemTemperature both gate on it). Claiming it here
	// hands the cooler full control of its cargo's temperature while it
	// sits in the world. Inside a vehicle/tent the root is no longer the
	// cooler so vanilla ambient drift competes, but the tick re-chills
	// every minute and stays ahead. A ruined cooler gives that up: vanilla's
	// ambient pass then reaches its contents again, so a frozen fish thaws and
	// then rots (frozen food never decays, so claiming it kept it frozen and
	// fresh for good).
	override bool IsSelfAdjustingTemperature() {
		return !IsRuined();
	}

	// The cooling runs on the Central Economy's periodic item update, the
	// clock vanilla uses for food rot and item temperature (and the mod's
	// worms), not a Timer per cooler checked every frame. The update hands
	// over the seconds since the cooler's last one; they add up to whole
	// cooling ticks, so contents cool at the same rate however often the
	// update comes. A long gap catches up at most ten ticks at once.
	override void OnCEUpdate() {
		super.OnCEUpdate();
		// A ruined cooler no longer chills; its contents warm up as anywhere.
		if (!g_Game.IsServer() || m_ElapsedSinceLastUpdate <= 0 || IsRuined())
			return;
		m_CoolingElapsed += m_ElapsedSinceLastUpdate;
		int ticks = Math.Floor(m_CoolingElapsed / COOLING_TICK_SECS);
		if (ticks <= 0)
			return;
		m_CoolingElapsed -= ticks * COOLING_TICK_SECS;
		if (ticks > 10)
			ticks = 10;
		for (int t = 0; t < ticks; t++)
			OnCoolingTick();
	}

	// Steps every cargo item toward the cooling target. While an unfrozen
	// item's requested temperature is below its freeze threshold, vanilla
	// holds the shown value AT the threshold and accumulates freeze progress
	// instead -- so the repeated calls during that phase are what drive the
	// item from cold to frozen.
	void OnCoolingTick() {
		// The update can come while the entity is mid-delete / not yet
		// initialized, where GetInventory() itself is null.
		if (!GetInventory())
			return;
		CargoBase cargo = GetInventory().GetCargo();
		if (!cargo)
			return;

		for (int i = 0; i < cargo.GetItemCount(); i++) {
			ItemBase item = ItemBase.Cast(cargo.GetItem(i));
			if (!item || !item.CanHaveTemperature())
				continue;

			float current = item.GetTemperature();
			if (!item.GetIsFrozen() && current <= item.GetTemperatureFreezeThreshold()) {
				// Parked at the threshold while freeze progress accumulates:
				// keep requesting the target so the progression keeps running.
				item.SetTemperature(COOLING_TARGET_C);
				continue;
			}
			if (Math.AbsFloat(current - COOLING_TARGET_C) < 0.01)
				continue;

			float next;
			if (current > COOLING_TARGET_C)
				next = Math.Max(COOLING_TARGET_C, current - COOLING_STEP_C);
			else
				next = Math.Min(COOLING_TARGET_C, current + COOLING_STEP_C);
			item.SetTemperature(next);
		}
	}

	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;

		// Prevent coolers-inside-coolers. IsKindOf walks the config
		// inheritance chain, so all colored variants are caught by the
		// base check.
		if (parent && parent.IsKindOf("geb_Cooler_base"))
			return false;

		return true;
	}
};

class geb_SmallTackle : geb_SmallTackleBase {};
class geb_OldRedTackle : geb_LargeTackleBase {};
class geb_OldGreenTackle : geb_LargeTackleBase {};
class geb_OldBlueTackle : geb_LargeTackleBase {};
class geb_OldPurpleTackle : geb_LargeTackleBase {};
class geb_Tackle_Base : geb_LargeTackleBase {};
