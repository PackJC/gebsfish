/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Craft the fish mounts: planks + 1 metal wire, with a hacksaw on you. The
// small plaque takes 1 plank, the medium board 3 and the large board 6
// (CraftMediumFishMount and CraftLargeFishMount at the bottom change only the
// plank count, the board and the name).
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

	// Planks used, the board made and the recipe's name.
	protected int GebPlanks() {
		return 1;
	}

	protected string GebBoard() {
		return "geb_WoodenFishMount";
	}

	protected string GebRecipeName() {
		return "#STR_craft_smallfishmount";
	}

	override void Init() {
		m_Name = GebRecipeName();
		m_IsInstaRecipe = false;
		m_AnimationLength = 2;
		m_Specialty = 0.02;// roughness

		m_AnywhereInInventory = false;
		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;// anything short of ruined

		m_MinQuantityIngredient[0] = GebPlanks();
		m_MaxQuantityIngredient[0] = -1;

		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;

		m_MinQuantityIngredient[1] = -1;
		m_MaxQuantityIngredient[1] = -1;
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1 -- the board's planks
		InsertIngredient(0,"WoodenPlank");

		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -GebPlanks();
		m_IngredientDestroy[0] = false; // consume the planks, preserve the rest of the stack
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
		AddResult(GebBoard());

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;// the ground, unless SpawnItems below finds the board a safe spot in the player's inventory
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;

		//----------------------------------------------------------------------------------------------------------------------
	}

	// The board goes where vanilla's "anywhere in the player's inventory"
	// result (-1) would put it: the first free cargo or attachment spot the
	// player's inventory has for its classname. When there is none, or that
	// spot is inside a gebsfish filtered container (cooler, Bait Bucket,
	// tackle box...) that refuses boards, vanilla's SpawnItems drops it on the
	// ground (-2 in Init), even if another spot is free: the engine picks the
	// spot by classname without asking the container's cargo checks, so the
	// board would go in and be thrown out when storage loads after a restart
	// (geb_FilteredContainerBase.GebCreateInInventory). The hands are never
	// free here: one of the ingredients is in them.
	override void SpawnItems(ItemBase ingredients[], PlayerBase player, array<ItemBase> spawned_objects) {
		EntityAI board = geb_FilteredContainerBase.GebCreateInInventory(player, GebBoard());
		if (!board) {
			super.SpawnItems(ingredients, player, spawned_objects);
			return;
		}
		spawned_objects.Clear();
		spawned_objects.Insert(ItemBase.Cast(board));
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

		// Planks and wire also sit in fence, gate, watchtower and flag-pole
		// slots (some locked once built), and wire on car batteries. Never use up one
		// that is part of something, as vanilla CraftFenceKit and
		// CraftMetalWire refuse to. Gear the player wears is fine.
		for (int i = 0; i < 2; i++) {
			ItemBase ingredient = ingredients[i];
			if (!ingredient || !ingredient.GetInventory() || !ingredient.GetInventory().IsAttachment())
				continue;
			EntityAI holder = ingredient.GetHierarchyParent();
			if (holder && !holder.IsMan())
				return false;
		}

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

// Three planks make the medium board (pike, catfish, cod, crabs).
class CraftMediumFishMount extends CraftFishMount {
	override protected int GebPlanks() {
		return 3;
	}

	override protected string GebBoard() {
		return "geb_MediumFishMount";
	}

	override protected string GebRecipeName() {
		return "#STR_craft_mediumfishmount";
	}
};

// Six planks make the large board (sturgeon, billfish, sharks).
class CraftLargeFishMount extends CraftFishMount {
	override protected int GebPlanks() {
		return 6;
	}

	override protected string GebBoard() {
		return "geb_LargeFishMount";
	}

	override protected string GebRecipeName() {
		return "#STR_craft_largefishmount";
	}
};
