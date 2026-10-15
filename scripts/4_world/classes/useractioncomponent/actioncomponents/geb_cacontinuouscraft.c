// Fish knives fillet faster (GeneralSettings.FishKnifeSpeedMultiplier). The
// speed-up is applied to each fillet when it starts, from the knife used for
// it. Setup runs on both the client and the server with the same items, so
// both end the fillet at the same moment -- changing the shared recipe instead
// left the server on the last player's knife, and the player sat in the
// animation after the fillets had dropped.
modded class CAContinuousCraft {
	override void Setup(ActionData action_data) {
		super.Setup(action_data);
		if (m_AdjustedTimeToComplete <= 0)
			return; // instant or debug craft
		if (GebIsFishFillet(action_data) && GebUsesFishKnife(action_data))
			m_AdjustedTimeToComplete = m_AdjustedTimeToComplete * GebFishKnifeMultiplier();
	}

	protected bool GebIsFishFillet(ActionData action_data) {
		WorldCraftActionData craft = WorldCraftActionData.Cast(action_data);
		PluginRecipesManager recipes = PluginRecipesManager.Cast(GetPlugin(PluginRecipesManager));
		if (!craft || !recipes || craft.m_RecipeID < 0 || craft.m_RecipeID >= recipes.m_RecipeList.Count())
			return false;
		return PrepareFish.Cast(recipes.m_RecipeList[craft.m_RecipeID]) != null;
	}

	// The knife is either the item in hands or the one being targeted.
	protected bool GebUsesFishKnife(ActionData action_data) {
		if (action_data.m_MainItem && action_data.m_MainItem.IsKindOf("geb_FishKnife_Base"))
			return true;
		if (!action_data.m_Target)
			return false;
		ItemBase target = ItemBase.Cast(action_data.m_Target.GetObject());
		return target && target.IsKindOf("geb_FishKnife_Base");
	}

	protected float GebFishKnifeMultiplier() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings)
			return 1.0;
		float multiplier = m_gebsConfig.General.GeneralSettings.FishKnifeSpeedMultiplier;
		if (multiplier <= 0)
			return 1.0;
		return multiplier;
	}
}
