/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Craft the Wooden Fish Mount: 1 plank + 1 metal wire, with a hacksaw on you.
//
// WHY THE HACKSAW ISN'T AN INGREDIENT: vanilla caps recipes at two ingredients
// (MAX_NUMBER_OF_INGREDIENTS = 2 in RecipeBase.c) -- there is no third slot to
// put it in. So the two consumed materials are the combined pair, and the saw is
// enforced as a tool: CanDo refuses the craft unless one is on the player, and
// Do takes durability off it the way an ingredient-slot tool would. The player
// still needs all three items; only the plank and wire are dragged together.
class CraftFishMount extends RecipeBase {

	// Roughly matches what a tool loses in an ingredient slot on a comparable craft.
	private const float HACKSAW_WEAR = 5.0;

	override void Init() {
		m_Name = "#STR_craft_fishmount";
		m_IsInstaRecipe = false;
		m_AnimationLength = 2;
		m_Specialty = 0.02;// roughness

		m_AnywhereInInventory = false;
		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;// anything short of ruined

		m_MinQuantityIngredient[0] = -1;
		m_MaxQuantityIngredient[0] = -1;

		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;

		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1 -- the board
		InsertIngredient(0,"WoodenPlank");

		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientUseSoftSkills[0] = false;

		//ingredient 2 -- the hanging wire
		InsertIngredient(1,"MetalWire");

		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = 0;
		m_IngredientDestroy[1] = true;
		m_IngredientUseSoftSkills[1] = false;
		//----------------------------------------------------------------------------------------------------------------------

		//result1
		AddResult("geb_WoodenFishMount");

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -1;// place anywhere in the player's inventory
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;

		//----------------------------------------------------------------------------------------------------------------------
	}

	// First non-ruined hacksaw anywhere on the player, or null.
	protected ItemBase FindHacksaw(PlayerBase player) {
		if (!player || !player.GetHumanInventory())
			return null;

		array<EntityAI> items = new array<EntityAI>();
		player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.INORDER, items);

		foreach (EntityAI entity : items) {
			ItemBase item = ItemBase.Cast(entity);
			if (!item || !item.IsKindOf("Hacksaw"))
				continue;
			if (item.IsRuined())
				continue;
			return item;
		}

		return null;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.RecipeToggles && !m_gebsConfig.General.RecipeToggles.CraftFishMount)
			return false;

		// The third "ingredient" the engine has no slot for.
		return FindHacksaw(player) != null;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);

		// Wear the saw by hand, since it never occupied an ingredient slot and so
		// never went through m_IngredientAddHealth.
		ItemBase saw = FindHacksaw(player);
		if (saw)
			saw.DecreaseHealth("", "", HACKSAW_WEAR);
	}
};
