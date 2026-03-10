class CraftHookFromWire extends RecipeBase
{
	override void Init()
	{
		m_Name = "#STR_tool_CraftHookFromWire";
		m_IsInstaRecipe = false;
		m_AnimationLength = 1;
		m_Specialty = 0.0;

		// Ingredient conditions
		m_MinDamageIngredient[0] = -1;
		m_MaxDamageIngredient[0] = 3; // pliers not ruined
		m_MinQuantityIngredient[0] = -1;
		m_MaxQuantityIngredient[0] = -1;

		m_MinDamageIngredient[1] = -1;
		m_MaxDamageIngredient[1] = 3; // wire not ruined
		m_MinQuantityIngredient[1] = 3; // require at least 3 quantity on the wire
		m_MaxQuantityIngredient[1] = -1;

		// Ingredient 1 = Pliers
		InsertIngredient(0, "Pliers");
		m_IngredientAddHealth[0] = -5;   // damage pliers once per craft
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;

		// Ingredient 2 = Metal Wire
		InsertIngredient(1, "MetalWire");
		m_IngredientAddHealth[1] = 0;
		m_IngredientSetHealth[1] = -1;
		m_IngredientAddQuantity[1] = -1; // consume 1 quantity per craft
		m_IngredientDestroy[1] = false;
		m_IngredientUseSoftSkills[1] = false;

		// Result = Hook
		AddResult("Hook");
		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -1;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		ItemBase wire = ingredients[1];
		if (!wire)
			return false;

		return wire.GetQuantity() >= 3;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		ItemBase hook = results[0];

		if (hook)
		{
			hook.SetHealth01("", "", 0.8);
		}
	}
}