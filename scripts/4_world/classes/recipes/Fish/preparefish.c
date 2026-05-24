modded class PrepareFish {
    // Vanilla baseline so the knife-speed multiplier never compounds across CanDo calls.
    protected float m_BaseAnimationLength;

    override void Init() {
		super.Init();
		m_RecipeUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
        GetGebSettingsConfig();
		//----------------------------------------------------------------------------------------------------------------------
		// Ingredient 2 (the knife). The 4th arg `showItem = true` keeps the
		// knife visible in the player's hands during the skinning animation.
		// RecipeBase.InsertIngredient defaults showItem to FALSE, which calls
		// TryHideItemInHands(true) at action start -- that's the bug that was
		// making the geb fish knife model disappear mid-fillet.
		InsertIngredient(1,"geb_BlueFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);
		InsertIngredient(1,"geb_OrangeFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);
		InsertIngredient(1,"geb_GreenFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);
		InsertIngredient(1,"geb_YellowFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);
		InsertIngredient(1,"geb_RedFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);
		InsertIngredient(1,"geb_PurpleFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, true);

		m_BaseAnimationLength = m_AnimationLength;
    }

    // Recalculated every CanDo so swapping knives mid-session always reflects the
    // current tool, and so the multiplier scales from the vanilla baseline (never compounds).
    override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		ApplyFishKnifeSpeedBonus(ingredients);
		return super.CanDo(ingredients, player);
	}

    void ApplyFishKnifeSpeedBonus(ItemBase ingredients[]) {
		float multiplier = 1.0;
		if (m_gebsConfig && m_gebsConfig.GeneralSettings)
			multiplier = m_gebsConfig.GeneralSettings.FishKnifeSpeedMultiplier;

		if (multiplier <= 0)
			multiplier = 1.0;

		if (ingredients[1] && ingredients[1].IsKindOf("geb_FishKnife_Base"))
			m_AnimationLength = m_BaseAnimationLength * multiplier;
		else
			m_AnimationLength = m_BaseAnimationLength;
	}

    //Called upon recipe's completion
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		// Adjusts quantity of results to the quantity of the 1st ingredient
		super.Do(ingredients, player, results, specialty_weight);
        // Trigger predator spawning
		TrySpawnPredator(player);
	}

    // Predator spawn after filleting succeeds. Delegates to GebsPredatorSpawner,
    // which owns the chance roll, predator selection, position search, multi-spawn
    // loop, warning sound RPC, and chat broadcast. Caller just provides the
    // player + chance value from config.
    void TrySpawnPredator(PlayerBase player) {
        if (!m_gebsConfig || !m_gebsConfig.PredatorSettings) return;
        GebsPredatorSpawner.TrySpawn(player, m_gebsConfig.PredatorSettings.PredatorSpawnChancePreparing, "PredatorSpawnPrepare");
    }
}
