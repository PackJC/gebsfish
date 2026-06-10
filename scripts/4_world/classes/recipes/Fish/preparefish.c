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
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.GeneralSettings)
			multiplier = m_gebsConfig.General.GeneralSettings.FishKnifeSpeedMultiplier;

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
		// Roll for a damaged hook 'stuck in the fish'
		TrySpawnHookFromFish(player);
	}

    // Predator spawn after filleting succeeds. Delegates to GebsPredatorSpawner,
    // which owns the chance roll, predator selection, position search, multi-spawn
    // loop, warning sound RPC, and chat broadcast. Caller just provides the
    // player + chance value from config.
    void TrySpawnPredator(PlayerBase player) {
        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.PredatorSettings) return;
        GebsPredatorSpawner.TrySpawn(player, m_gebsConfig.General.PredatorSettings.PredatorSpawnChancePreparing, "PredatorSpawnPrepare");
    }

    // Damaged-hook-from-fish feature. Fires once per fillet action (one Do()
    // call = one fish prepared, regardless of how many fillet meats it yields):
    // rolls HookFromFishChance (default 0.004 = ~1/250) and on a hit, picks a
    // hook classname from the weighted HookFromFishCatches pool and spawns it
    // at a random health level in that entry's [MinHealthLevel, MaxHealthLevel]
    // range. Server-only so
    // the spawn doesn't double up between client + server. Tries the player's
    // inventory first (cleanest UX -- hook lands where the fillets do), falls
    // back to player position if inventory placement fails. Logs at DebugLogs
    // >= 1 so admins can see when the system fires.
    void TrySpawnHookFromFish(PlayerBase player) {
        if (!player) return;
        if (!g_Game.IsServer()) return;
        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings) return;

        GenSetConf gs = m_gebsConfig.General.GeneralSettings;
        if (!gs.HookFromFishEnable) return;
        if (gs.HookFromFishChance <= 0) return;

        int debugLevel = gs.DebugLogs;
        float roll = Math.RandomFloat01();
        if (roll > gs.HookFromFishChance) {
            if (debugLevel == ELEVATED_DEBUG)
                GebsfishLogger.Debug("HookFromFish miss: roll=" + roll + " chance=" + gs.HookFromFishChance, "HookFromFish");
            return;
        }

        ref array<ref HookFromFishEntry> entries = m_gebsConfig.General.HookFromFishCatches;
        if (!entries || entries.Count() == 0) {
            if (debugLevel >= 1)
                GebsfishLogger.Debug("HookFromFish hit but Catches pool empty -- skipping", "HookFromFish");
            return;
        }

        // Filter to eligible hooks once, keeping a parallel ref list so the
        // shared picker's index maps back to the entry (for its health range).
        array<ref HookFromFishEntry> eligible = new array<ref HookFromFishEntry>();
        TStringArray names = new TStringArray;
        TFloatArray weights = new TFloatArray;
        foreach (HookFromFishEntry e : entries) {
            if (!e || e.Classname == "" || e.Weight <= 0)
                continue;
            eligible.Insert(e);
            names.Insert(e.Classname);
            weights.Insert(e.Weight);
        }

        int pick = GebWeightedPick.Pick(names, weights, debugLevel, "HookFromFish");
        if (pick < 0)
            return;
        HookFromFishEntry picked = eligible[pick];

        // Random health level inside the configured range. Clamp to 0..4 in
        // case an admin typo'd a value -- SetHealthLevel above 4 silently no-ops
        // in some engine builds, which would leave the hook at pristine and
        // mislead bug reports.
        int minLvl = picked.MinHealthLevel;
        int maxLvl = picked.MaxHealthLevel;
        if (minLvl < 0) minLvl = 0;
        if (minLvl > 4) minLvl = 4;
        if (maxLvl < minLvl) maxLvl = minLvl;
        if (maxLvl > 4) maxLvl = 4;
        int healthLevel = Math.RandomInt(minLvl, maxLvl + 1);

        // Prefer player inventory (lands in cargo / on belt slot if it fits).
        // CreateInInventory returns null on failure, in which case fall back
        // to dropping it at the player's feet so the hook isn't lost on a
        // full inventory.
        EntityAI spawned = null;
        if (player.GetInventory())
            spawned = player.GetInventory().CreateInInventory(picked.Classname);

        if (!spawned) {
            spawned = EntityAI.Cast(g_Game.CreateObjectEx(picked.Classname, player.GetPosition(), ECE_PLACE_ON_SURFACE));
        }

        if (!spawned) {
            if (debugLevel >= 1)
                GebsfishLogger.Debug("HookFromFish picked=" + picked.Classname + " but CreateInInventory/CreateObjectEx both returned null -- spawn failed", "HookFromFish");
            return;
        }

        ItemBase spawnedItem = ItemBase.Cast(spawned);
        if (spawnedItem)
            spawnedItem.SetHealthLevel(healthLevel, "");

        if (debugLevel >= 1) {
            GebsfishLogger.Debug("HookFromFish hit: spawned=" + picked.Classname + " healthLevel=" + healthLevel + " roll=" + roll + " chance=" + gs.HookFromFishChance, "HookFromFish");
        }
    }
}
