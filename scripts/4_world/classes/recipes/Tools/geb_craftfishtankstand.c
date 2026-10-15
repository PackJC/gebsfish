/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Craft the Fish Tank Stand: 8 planks + 16 nails, with a hammer or a hatchet on
// you. The Fishing Locker's recipe (geb_craftfishinglocker.c) with the amounts
// of vanilla's wooden crate, as the stand is a crate-sized cabinet; it comes
// out on the ground the same way. Until 2026-10-14 the stand was a trader and
// admin item only.
class CraftFishTankStand extends CraftFishingLocker {
	override protected int GebPlanks() {
		return 8;
	}

	override protected int GebNails() {
		return 16;
	}

	override protected string GebResult() {
		return "geb_FishTankStand";
	}

	override protected string GebName() {
		return "#STR_craft_fishtankstand";
	}

	override protected bool GebEnabled() {
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.RecipeToggles)
			return m_gebsConfig.General.RecipeToggles.CraftFishTankStand;
		return true;
	}
};
