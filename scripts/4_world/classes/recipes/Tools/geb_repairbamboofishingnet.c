/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class RepairBambooFishingNet : RecipeBase {
	override void Init() {
		m_Name = "#repair";
		m_IsInstaRecipe = false;
		m_AnimationLength = 2.5;
		m_Specialty = -0.02;

		// ---- ingredient 0: the Netting (one piece, destroyed on use) ----
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;     // can use up to badly-damaged netting
		m_MinQuantityIngredient[0] = -1;
		m_MaxQuantityIngredient[0] = -1;

		// ---- ingredient 1: the bamboo fishing net being repaired ----
		// Min 1 (must be at least Worn -- can't "repair" a Pristine net).
		// Max 3 (Badly Damaged) -- Ruined nets are beyond saving and have
		// to be crafted from scratch.
		m_MinDamageIngredient[1] = 1;
		m_MaxDamageIngredient[1] = 3;
		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;

		InsertIngredient(0, "Netting");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -1;
		m_IngredientDestroy[0] = true;    // one netting consumed per repair
		m_IngredientUseSoftSkills[0] = false;

		InsertIngredient(1, "geb_BambooFishingNet", DayZPlayerConstants.CMD_ACTIONFB_CLEANING_WEAPON, true);
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;    // we set this manually in Do() so we
		                                  // can target STATE_WORN exactly regardless
		                                  // of starting damage state
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = false;
		m_IngredientUseSoftSkills[1] = false;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		if (m_gebsConfig && m_gebsConfig.RecipeToggles && !m_gebsConfig.RecipeToggles.RepairBambooFishingNet)
			return false;
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		// Repair the bamboo net to STATE_WORN (1) regardless of starting
		// damage. One netting always restores it to the same "fresh-but-not-
		// pristine" level so admins get a predictable repair outcome and
		// the Netting cost stays balanced across damage tiers.
		if (ingredients[1])
			ingredients[1].SetHealthLevel(1, "");
	}

	override bool IsRepeatable() {
		return true;
	}
}
