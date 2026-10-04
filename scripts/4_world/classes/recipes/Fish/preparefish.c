modded class PrepareFish {
    protected bool m_GebConfiguredRecipe;
    protected string m_GebFallbackSpecies;
    protected string m_GebFallbackMain;
    protected string m_GebFallbackBonus;
    protected bool m_GebCaviarResult;

    protected FishConf GebResolveRecipe(ItemBase fish) {
        if (!fish) return null;
        if (m_gebsConfig && m_gebsConfig.Fish) {
            FishConf configured = m_gebsConfig.Fish.Get(fish.GetType());
            if (configured) return configured;
        }
        if (m_GebFallbackSpecies == "" || fish.GetType() != m_GebFallbackSpecies)
            return null;
        FishConf fallback = new FishConf();
        fallback.Classname = m_GebFallbackSpecies;
        fallback.ResultMain = m_GebFallbackMain;
        fallback.ResultBonus = m_GebFallbackBonus;
        fallback.MeatMin = 1;
        fallback.MeatMax = 1;
        if (m_GebFallbackBonus != "") fallback.RecipeShape = 1;
        return fallback;
    }

    protected bool GebHasValidResults(FishConf conf) {
        if (!conf || conf.ResultMain == "") return false;
        if (!g_Game.ConfigIsExisting("CfgVehicles " + conf.ResultMain)) return false;
        if (conf.RecipeShape == 1 || conf.RecipeShape == 2) {
            if (conf.ResultBonus == "" || !g_Game.ConfigIsExisting("CfgVehicles " + conf.ResultBonus))
                return false;
        }
        return true;
    }

    // RecipeBase spawns results before modifying them or calling Do().
    // Rebuild here once per execution, never during CanDo/registration.
    override void SpawnItems(ItemBase ingredients[], PlayerBase player, array<ItemBase> spawned_objects) {
        if (m_GebConfiguredRecipe) {
            FishConf conf = GebResolveRecipe(ingredients[0]);
            m_NumberOfResults = 0;
            m_GebCaviarResult = false;
            if (GebHasValidResults(conf)) {
                int bonusCount = 0;
                if (conf.RecipeShape == 1 || conf.RecipeShape == 2) {
                    AddDefaultResultAtIndex(conf.ResultBonus, 0);
                    bonusCount = 1;
                    m_GebCaviarResult = conf.RecipeShape == 1;
                }
                int capacity = MAXIMUM_RESULTS - bonusCount;
                int minCount = conf.MeatMin;
                int maxCount = conf.MeatMax;
                if (minCount < 0) minCount = 0;
                if (minCount > capacity) minCount = capacity;
                if (maxCount < minCount) maxCount = minCount;
                if (maxCount > capacity) maxCount = capacity;
                int count = Math.RandomInt(minCount, maxCount + 1);
                AddRepeatedResults(conf.ResultMain, count, bonusCount);
            }
        }
        super.SpawnItems(ingredients, player, spawned_objects);
    }

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
    }

    // The fish-knife speed-up is applied per fillet in CAContinuousCraft.Setup
    // (geb_cacontinuouscraft.c), not here: the recipe is shared by every player.
    override bool CanDo(ItemBase ingredients[], PlayerBase player) {
        if (!ingredients[0] || !ingredients[1]) return false;
        if (m_GebConfiguredRecipe && !GebHasValidResults(GebResolveRecipe(ingredients[0])))
            return false;
		// A frozen fish can't be filleted -- thaw it first. Mirrors vanilla's
		// PrepareAnimal, which blocks skinning frozen carcasses the same way.
		if (ingredients[0] && ingredients[0].GetIsFrozen())
			return false;
		// Mounting is permanent: the mount refuses to release the fish, but a
		// recipe never asks, so block filleting it here. (Decay is paused on
		// the mount, so an old trophy would also come off as fresh fillets.)
		if (geb_WoodenFishMount.Cast(ingredients[0].GetHierarchyParent()))
			return false;

		return super.CanDo(ingredients, player);
	}

	// ---- Shared recipe-construction helpers ----
	// Used by GebPrepareFishBase (the data-driven pipeline) AND the modded
	// vanilla-fish recipes in geb_preparefishbase.c. They live here on
	// PrepareFish because the vanilla recipes (modded PrepareCarp etc.)
	// extend PrepareFish directly and can't reach helpers declared on
	// GebPrepareFishBase.

	void SetupFishRecipe(string ingredientType) {
		// As vanilla PrepareCarp: with the fish in hands the skinning animation
		// plays and the fish is hidden (showItem false), instead of the generic
		// crafting animation.
		InsertIngredient(0, ingredientType, DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, false);
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;
	}

	void AddDefaultResultAtIndex(string resultType, int index) {
		AddResult(resultType);
		m_ResultSetFullQuantity[index] = false;
		m_ResultSetQuantity[index] = -1;
		m_ResultSetHealth[index] = -1;
		m_ResultInheritsHealth[index] = 0;
		m_ResultInheritsColor[index] = -1;
		m_ResultToInventory[index] = -2;
		m_ResultUseSoftSkills[index] = false;
		m_ResultReplacesIngredient[index] = 0;
	}

	void AddRepeatedResults(string resultType, int count, int startIndex = 0) {
		// Vanilla RecipeBase stores results in fixed [MAXIMUM_RESULTS] arrays
		// and AddResult has no bounds check -- an over-large MeatMax in a
		// hand-edited fish.json would write out of bounds. Clamp so the
		// total result count (bonus at index 0 included via startIndex)
		// never exceeds the engine cap.
		if (startIndex + count > MAXIMUM_RESULTS)
			count = MAXIMUM_RESULTS - startIndex;
		for (int i = 0; i < count; ++i) {
			AddDefaultResultAtIndex(resultType, startIndex + i);
		}
	}

	int GetInclusiveRandom(int min, int max) {
		if (max < min)
			max = min;

		return Math.RandomInt(min, max + 1);
	}

    // Vanilla recipes keep their own stable IDs, but resolve live tuning
    // when executed. Clear vanilla's pre-added results to avoid duplication.
    void SetupVanillaFilletRecipe(string fishClassname, string filletClassname, string bonusClassname = "") {
        m_GebConfiguredRecipe = true;
        m_GebFallbackSpecies = fishClassname;
        m_GebFallbackMain = filletClassname;
        m_GebFallbackBonus = bonusClassname;
        m_NumberOfResults = 0;
        SetupFishRecipe(fishClassname);
    }

	float GetConfiguredCaviarChance() {
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.GeneralSettings) {
			return m_gebsConfig.General.GeneralSettings.CaviarChance;
		}

		return 0.3;
	}

	void ApplyConfiguredCaviarChance(array<ItemBase> results) {
		float chance = GetConfiguredCaviarChance();

		if (chance >= 1.0)
			return;

		if (chance <= 0.0 || Math.RandomFloat(0, 1) > chance) {
			if (results && results.Count() > 0 && results[0])
				results[0].Delete();
		}
	}

    //Called upon recipe's completion
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		// Adjusts quantity of results to the quantity of the 1st ingredient
        // Failed spawns must not reach PrepareAnimal.Do's unchecked dereferences.
        ItemBase caviar;
        if (m_GebCaviarResult && results && results.Count() > 0)
            caviar = results[0];
        for (int resultIndex = results.Count() - 1; resultIndex >= 0; --resultIndex) {
            if (!results[resultIndex]) results.Remove(resultIndex);
        }
        // Vanilla PrepareAnimal.Do copies the fish's fill level onto every
        // result. A custom catch with no quantity reads as 0% full, which
        // would delete every fillet (varQuantityDestroyOnMin), so do vanilla's
        // transfer here with full fillets instead.
        if (ingredients[0] && !ingredients[0].HasQuantity()) {
            foreach (ItemBase filletResult : results) {
                MiscGameplayFunctions.TransferItemProperties(ingredients[0], filletResult);
                filletResult.SetQuantityMax();
            }
            SetBloodyHands(ingredients, player);
        } else {
            super.Do(ingredients, player, results, specialty_weight);
        }
        if (caviar)
            ApplyConfiguredCaviarChance(results);
        // Trigger predator spawning
		TrySpawnPredator(player);
		// Roll for a damaged hook 'stuck in the fish'
		TrySpawnHookFromFish(player);
	}

    // Predator spawn after filleting succeeds. Delegates to GebsPredatorSpawner,
    // which owns the chance roll, predator selection, position search, multi-spawn
    // loop, warning sound RPC, and player chat warning. Caller just provides the
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
    // range. Server-only so the spawn doesn't double up between client and
    // server. The hook drops on the ground beside the player, with the
    // fillets. Logs at DebugLogs >= 1 so admins can see when the system fires.
    void TrySpawnHookFromFish(PlayerBase player) {
        if (!player) return;
        if (!g_Game.IsServer()) return;
        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings) return;

        GenSetConf gs = m_gebsConfig.General.GeneralSettings;
        if (!gs.HookFromFishEnable) return;
        if (gs.HookFromFishChance <= 0) return;

        int debugLevel = GebGetDebugLevel(); // shared accessor, clamps 3+ to ELEVATED_DEBUG
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

        // On the ground with the fillets: vanilla's RecipeBase.SpawnItems drops
        // them with this same call and spread. Never into the inventory, where
        // a worm container, bug catcher or bait bucket could take a hook it
        // doesn't allow and drop it on the next restart.
        EntityAI spawned = player.SpawnEntityOnGroundRaycastDispersed(picked.Classname, DEFAULT_SPAWN_DISTANCE);
        if (!spawned) {
            if (debugLevel >= 1)
                GebsfishLogger.Debug("HookFromFish picked=" + picked.Classname + " but it could not be spawned on the ground", "HookFromFish");
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
