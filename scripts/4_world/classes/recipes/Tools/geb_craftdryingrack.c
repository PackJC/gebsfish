/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Craft the Fish Drying Rack: 7 Long Wooden Sticks + 1 Rope, the way vanilla's
// Shelter Kit takes a rope and 4 sticks. Long sticks stack to 10, so the seven
// come off one stack and the rest stays; the rope is used up. The rack is a
// heavy item (two hands, never in cargo), so it is made on the ground at the
// player's feet. Vanilla's crafting animation, like every recipe.
class CraftDryingRack extends RecipeBase {

	static const int GEB_STICKS = 7;

	override void Init() {
		m_Name = "#STR_craft_fishdryingrack";
		m_IsInstaRecipe = false;
		m_AnimationLength = 2;
		m_Specialty = 0.02;// roughness

		m_AnywhereInInventory = false;
		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;// anything short of ruined

		m_MinQuantityIngredient[0] = GEB_STICKS;
		m_MaxQuantityIngredient[0] = -1;

		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;

		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1 -- the poles: four legs, the ridge and two rails
		InsertIngredient(0,"LongWoodenStick");

		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -GEB_STICKS;
		m_IngredientDestroy[0] = false; // take seven, keep the rest of the stack
		m_IngredientUseSoftSkills[0] = false;

		//ingredient 2 -- the lashings and the fillet loops
		InsertIngredient(1,"Rope");

		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = true;
		m_IngredientUseSoftSkills[1] = false;
		//----------------------------------------------------------------------------------------------------------------------

		//result1
		AddResult("geb_FishDryingRack");

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;// on the ground: a heavy item fits nowhere else
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;

		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.RecipeToggles && !m_gebsConfig.General.RecipeToggles.CraftDryingRack)
			return false;

		// Long sticks and rope also sit in shelter, fireplace and trap slots.
		// Never use up one that is part of something, as vanilla's kit recipes
		// refuse to (the fish mounts' rule). Gear the player wears is fine.
		for (int i = 0; i < 2; i++) {
			ItemBase ingredient = ingredients[i];
			if (!ingredient || !ingredient.GetInventory() || !ingredient.GetInventory().IsAttachment())
				continue;
			EntityAI holder = ingredient.GetHierarchyParent();
			if (holder && !holder.IsMan())
				return false;
		}
		return true;
	}
};
