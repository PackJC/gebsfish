/*

  CREATED BY PACKJC
  https://smokymountainsoftware.com
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  https://www.smokymountainsoftware.com/Contributions welcome via github

*/


class geb_FilteredContainerBase : Container_Base {
	protected TStringArray GetAllowedItemKinds() {
		return null;
	}

	override int GetDamageSystemVersionChange() {
		return 110;
	}

	// Shared check so the drag-drop path (CanReceiveItemIntoCargo) and the
	// script/persistence path (CanLoadItemIntoCargo) stay in lockstep.
	// Vanilla DayZ does not always route every cargo move through the same
	// check, so overriding both prevents disallowed items sneaking in via
	// quickbar swaps, world-craft results, or save-load.
	protected bool IsAllowedCargoItem(EntityAI item) {
		if (!item)
			return false;

		TStringArray allowed = GetAllowedItemKinds();
		if (!allowed || allowed.Count() == 0)
			return false;

		for (int i = 0; i < allowed.Count(); i++) {
			if (item.IsKindOf(allowed.Get(i)))
				return true;
		}

		return false;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item) {
		return IsAllowedCargoItem(item);
	}

	override bool CanLoadItemIntoCargo(EntityAI item) {
		return IsAllowedCargoItem(item);
	}
};

class geb_WormContainer : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Worm", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}
};

class geb_BugContainer : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override bool IsContainer() {
		return true;
	}

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
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_FatHeadMinnow", "geb_SignalCrayFish", "geb_EuropeanCrayFish", "geb_AmericanBullFrog", "geb_RedSalamander" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}

	override bool IsContainer() {
		return true;
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
	static ref TStringArray s_Allowed = { "geb_FatHeadMinnow", "geb_SignalCrayFish", "geb_EuropeanCrayFish", "Shrimp", "geb_AmericanBullFrog", "geb_RedSalamander" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}
};

// Tackle-box allow lists. Three groups of entries:
//
//   1. ARTIFICIAL LURES -- "geb_Lure" catches all 16 lure variants via the
//      config inheritance walk (geb_SpinnerBait1-4 / geb_SpoonLure1-4 /
//      geb_Lure1-4 / geb_CurlyTailJig1-4 all extend geb_Lure). "Jig" stays
//      for vanilla jigs.
//   2. LIVE BAIT -- worms (vanilla + grub + rubber), insects (grasshopper +
//      cricket), minnows, salamander, bullfrog. Players can stash bait
//      directly in the tackle box instead of always needing the dedicated
//      worm/bug/minnow containers, while the dedicated containers still
//      remain the most efficient way to organize bait at scale.
//   3. TOOLS -- hooks, knives, pliers, gloves, dedicated bait containers,
//      the bamboo fishing net, and the geb_FishingRodRepairKit. The cargo
//      grids were bumped (small 6x1 -> 6x2, large 9x1 -> 9x3 in
//      data/tackle/config.cpp) so the 2x2 repair kit fits.

class geb_SmallTackleBase : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = {
		// Lures / jigs
		"Jig", "geb_Lure",
		// Live bait
		"Worm", "geb_GrubWorm", "geb_RubberWorm",
		"geb_GrassHopper", "geb_FieldCricket",
		"geb_FatHeadMinnow", "geb_RedSalamander", "geb_AmericanBullFrog",
		// Tools / containers
		"geb_OrangeFishGloves", "geb_BlueFishGloves",
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"geb_FishingRodRepairKit",
		"Hook", "geb_FishKnife_Base", "BoneKnife", "BoneHook", "Pliers"
	};

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
	}
};

class geb_LargeTackleBase : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = {
		// Lures / jigs
		"Jig", "geb_Lure",
		// Live bait
		"Worm", "geb_GrubWorm", "geb_RubberWorm",
		"geb_GrassHopper", "geb_FieldCricket",
		"geb_FatHeadMinnow", "geb_RedSalamander", "geb_AmericanBullFrog",
		// Tools / containers
		"geb_OrangeFishGloves", "geb_BlueFishGloves",
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"geb_FishingRodRepairKit",
		"Hook", "geb_FishKnife_Base", "BoneKnife", "BoneHook",
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
// pots, which extend Bottle_Base -> Edible_Base. Non-food gear stays out.
class geb_Cooler_base : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "Edible_Base" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
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
	//   COOLING_TICK_SECS = seconds between ticks
	protected const float COOLING_TARGET_C  = -5.0;
	protected const float COOLING_STEP_C    = 1.5;
	protected const float COOLING_TICK_SECS = 60.0;

	protected ref Timer m_CoolingTimer;

	// Vanilla skips ambient temperature processing for any item whose
	// hierarchy ROOT self-adjusts (EntityAI.ProcessVariables and
	// ItemBase.ProcessItemTemperature both gate on it). Claiming it here
	// hands the cooler full control of its cargo's temperature while it
	// sits in the world. Inside a vehicle/tent the root is no longer the
	// cooler so vanilla ambient drift competes, but the tick re-chills
	// every minute and stays ahead.
	override bool IsSelfAdjustingTemperature() {
		return true;
	}

	override void EEInit() {
		super.EEInit();
		if (g_Game.IsServer()) {
			m_CoolingTimer = new Timer(CALL_CATEGORY_SYSTEM);
			m_CoolingTimer.Run(COOLING_TICK_SECS, this, "OnCoolingTick", null, true);
		}
	}

	override void EEDelete(EntityAI parent) {
		super.EEDelete(parent);
		if (m_CoolingTimer)
			m_CoolingTimer.Stop();
	}

	// Steps every cargo item toward the cooling target. While an unfrozen
	// item's requested temperature is below its freeze threshold, vanilla
	// holds the shown value AT the threshold and accumulates freeze progress
	// instead -- so the repeated calls during that phase are what drive the
	// item from cold to frozen.
	void OnCoolingTick() {
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

	override bool IsContainer() {
		return true;
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
