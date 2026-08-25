/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Both guts items can chum the water two ways: the explicit action below, or
// simply being thrown/dropped into deep enough water -- every move to GROUND
// is forwarded to GebsChumSystem, which schedules the delayed in-water check
// (the item is still mid-air when the location change fires on a throw).
// Health gating (half or better) lives in the chum system / action condition.

modded class Guts {
	override void SetActions() {
		super.SetActions();
		AddAction(ActionChumWater);
	}

	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc) {
		super.EEItemLocationChanged(oldLoc, newLoc);
		GebsChumSystem.OnGutsLocationChanged(this, newLoc);
	}
};

modded class SmallGuts {
	override void SetActions() {
		super.SetActions();
		AddAction(ActionChumWater);
	}

	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc) {
		super.EEItemLocationChanged(oldLoc, newLoc);
		GebsChumSystem.OnGutsLocationChanged(this, newLoc);
	}
};
