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

// Cooler container -- preserves fillets parented in its cargo. The
// actual decay slowdown lives in the modded Edible_Base.ProcessDecay
// override (see edible_base/geb_ediblebase.c). This class only handles
// cargo filtering + nesting prevention.
//
// Named geb_Cooler_base to match the config-side base class. The
// colored variants (geb_RedCooler / geb_BlueCooler / etc.) don't need
// their own script classes -- DayZ falls back to the config parent's
// script class at instantiation, so every variant gets the same cargo
// filter and decay-preservation behavior automatically.
//
// Allow list keys on the two vanilla fillet base classes (CarpFilletMeat
// and MackerelFilletMeat). All gebsfish fillet variants extend one of
// those (see data/fish/config.cpp -- geb_FreshWater_Fillet_* extend
// CarpFilletMeat, geb_SaltWater_Fillet_* + lobster parts extend
// MackerelFilletMeat) so IsKindOf catches every current and future
// fillet without listing every species individually.
class geb_Cooler_base : geb_FilteredContainerBase {
	static ref TStringArray s_Allowed = { "CarpFilletMeat", "MackerelFilletMeat" };

	override protected TStringArray GetAllowedItemKinds() {
		return s_Allowed;
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
