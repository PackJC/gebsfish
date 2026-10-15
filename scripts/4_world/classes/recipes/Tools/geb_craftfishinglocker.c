/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Craft the Fishing Locker: 10 planks + 20 nails, with a hammer or a hatchet on
// you (the tools vanilla nails with when building). Vanilla's wooden crate is
// 8 planks + 16 nails; the locker is a bigger piece of joinery. 10 is a full
// stack: planks stack to 10 in DayZ 1.30 (varStackMax), so 12 from one stack
// could never be crafted. Like the crate
// it comes out on the ground, as it is far too big for any inventory.
//
// The tool isn't an ingredient for the same reason as on the fish mounts
// (CraftFishMount): vanilla recipes take two ingredients, so the planks and
// nails are the pair dragged together and CanDo looks for the tool on the
// player, which Do then wears as an ingredient-slot tool would be.
class CraftFishingLocker extends RecipeBase {

	private const float TOOL_WEAR = 5.0;

	// What the recipe takes and makes. The Fish Tank Stand's recipe
	// (CraftFishTankStand, geb_craftfishtankstand.c) is this one with its own.
	protected int GebPlanks() {
		return 10;
	}

	protected int GebNails() {
		return 20;
	}

	protected string GebResult() {
		return "geb_FishingLocker";
	}

	protected string GebName() {
		return "#STR_craft_fishinglocker";
	}

	protected bool GebEnabled() {
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.RecipeToggles)
			return m_gebsConfig.General.RecipeToggles.CraftFishingLocker;
		return true;
	}

	override void Init() {
		m_Name = GebName();
		m_IsInstaRecipe = false;
		m_AnimationLength = 3;
		m_Specialty = 0.02;// roughness

		m_AnywhereInInventory = false;
		//conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3;// anything short of ruined

		m_MinQuantityIngredient[0] = GebPlanks();
		m_MaxQuantityIngredient[0] = -1;

		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3;

		m_MinQuantityIngredient[1] = GebNails();
		m_MaxQuantityIngredient[1] = -1;
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1 -- the planks
		InsertIngredient(0,"WoodenPlank");

		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = -GebPlanks();
		m_IngredientDestroy[0] = false; // consume the planks, keep the rest of the stack
		m_IngredientUseSoftSkills[0] = false;

		//ingredient 2 -- the nails
		InsertIngredient(1,"Nail");

		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = -GebNails();
		m_IngredientDestroy[1] = false;
		m_IngredientUseSoftSkills[1] = false;
		//----------------------------------------------------------------------------------------------------------------------

		//result1
		AddResult(GebResult());

		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = 0;// the planks' condition, as vanilla's crate
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;// the ground
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
		//----------------------------------------------------------------------------------------------------------------------
	}

	// First non-ruined hammer or hatchet anywhere on the player, or null.
	protected ItemBase FindTool(PlayerBase player) {
		if (!player || !player.GetHumanInventory())
			return null;

		array<EntityAI> items = new array<EntityAI>();
		player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.INORDER, items);

		foreach (EntityAI entity : items) {
			ItemBase item = ItemBase.Cast(entity);
			if (!item || item.IsRuined())
				continue;
			if (item.IsKindOf("Hammer") || item.IsKindOf("Hatchet"))
				return item;
		}

		return null;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		if (!GebEnabled())
			return false;

		// Planks and nails also sit in fence, gate and watchtower slots (some
		// locked once built). Never use up ones that are part of something, as
		// vanilla CraftFenceKit refuses to. Gear the player wears is fine.
		for (int i = 0; i < 2; i++) {
			ItemBase ingredient = ingredients[i];
			if (!ingredient || !ingredient.GetInventory() || !ingredient.GetInventory().IsAttachment())
				continue;
			EntityAI holder = ingredient.GetHierarchyParent();
			if (holder && !holder.IsMan())
				return false;
		}

		// The third "ingredient" the engine has no slot for.
		return FindTool(player) != null;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);

		// Wear the tool by hand: it never sat in an ingredient slot.
		ItemBase tool = FindTool(player);
		if (tool)
			tool.DecreaseHealth("", "", TOOL_WEAR);
	}
};
