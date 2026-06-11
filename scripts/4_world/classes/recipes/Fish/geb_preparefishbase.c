class GebPrepareFishBase extends PrepareFish {
	void SetupFishRecipe(string ingredientType) {
		InsertIngredient(0, ingredientType);
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
		for (int i = 0; i < count; ++i) {
			AddDefaultResultAtIndex(resultType, startIndex + i);
		}
	}

	int GetInclusiveRandom(int min, int max) {
		if (max < min)
			max = min;

		return Math.RandomInt(min, max + 1);
	}

	void SetupStandardRecipe(string ingredientType, string resultType, int minCount, int maxCount) {
		SetupFishRecipe(ingredientType);
		AddRepeatedResults(resultType, GetInclusiveRandom(minCount, maxCount));
	}

	// One tail is always produced at index 0; MeatMin/MeatMax then controls the
	// CLAW count (mirrors SetupCaviarRecipe, where the caviar is the bonus and
	// Meat* drives the meat). A lobster yields its tail PLUS [MeatMin..MeatMax] claws.
	void SetupLobsterRecipe(string ingredientType, string tailType, string clawType, int minCount, int maxCount) {
		SetupFishRecipe(ingredientType);
		AddDefaultResultAtIndex(tailType, 0);

		int clawCount = GetInclusiveRandom(minCount, maxCount);
		AddRepeatedResults(clawType, clawCount, 1);
	}

	void SetupCaviarRecipe(string ingredientType, string caviarType, string meatType, int minCount, int maxCount) {
		SetupFishRecipe(ingredientType);
		AddDefaultResultAtIndex(caviarType, 0);

		int ran = GetInclusiveRandom(minCount, maxCount);
		AddRepeatedResults(meatType, ran, 1);
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

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
	}
};

// ===== VANILLA FISH (facade reads via m_gebsConfig.Fish.Get(...)) =====

modded class PrepareCarp extends PrepareFish {
    override void Init() {
		super.Init();
		InsertIngredient(0, "Carp");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Fish && m_gebsConfig.Fish.Get("Carp")) {
			FishConf c = m_gebsConfig.Fish.Get("Carp");
			minMeat = c.MeatMin;
			maxMeat = c.MeatMax;
		}
		// Defend against admin inversion (MeatMin > MeatMax). Without this
		// the RandomInt rolls into a degenerate range and the for-loop never
		// runs -> zero fillets, silently. Matches the GetInclusiveRandom
		// guard used by every fish that extends GebPrepareFishBase.
		if (maxMeat < minMeat) maxMeat = minMeat;
		int ran = Math.RandomInt(minMeat, maxMeat + 1);
		for (int i = 0; i < ran; ++i) {
			AddResult("CarpFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
	}
};

modded class PrepareSteelheadTrout extends PrepareFish {
	override void Init() {
		super.Init();
		InsertIngredient(0, "SteelheadTrout");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		AddResult("RedCaviar");
		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = 0;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = 0;

		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Fish && m_gebsConfig.Fish.Get("SteelheadTrout")) {
			FishConf c = m_gebsConfig.Fish.Get("SteelheadTrout");
			minMeat = c.MeatMin;
			maxMeat = c.MeatMax;
		}
		// Defend against admin inversion (MeatMin > MeatMax). Without this
		// the RandomInt rolls into a degenerate range and the for-loop never
		// runs -> zero fillets, silently. Matches the GetInclusiveRandom
		// guard used by every fish that extends GebPrepareFishBase.
		if (maxMeat < minMeat) maxMeat = minMeat;
		int ran = Math.RandomInt(minMeat, maxMeat + 1);
		for (int i = 1; i <= ran; ++i) {
			AddResult("SteelheadTroutFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);

		float chance = 0.3;
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.GeneralSettings) {
			chance = m_gebsConfig.General.GeneralSettings.CaviarChance;
		}

		if (chance <= 0.0 || (chance < 1.0 && Math.RandomFloat(0, 1) > chance)) {
			if (results && results.Count() > 0 && results[0])
				results[0].Delete();
		}
	}
};

modded class PrepareMackerel extends PrepareFish {
	override void Init() {
		super.Init();
		InsertIngredient(0, "Mackerel");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Fish && m_gebsConfig.Fish.Get("Mackerel")) {
			FishConf c = m_gebsConfig.Fish.Get("Mackerel");
			minMeat = c.MeatMin;
			maxMeat = c.MeatMax;
		}
		// Defend against admin inversion (MeatMin > MeatMax). Without this
		// the RandomInt rolls into a degenerate range and the for-loop never
		// runs -> zero fillets, silently. Matches the GetInclusiveRandom
		// guard used by every fish that extends GebPrepareFishBase.
		if (maxMeat < minMeat) maxMeat = minMeat;
		int ran = Math.RandomInt(minMeat, maxMeat + 1);
		for (int i = 0; i < ran; ++i) {
			AddResult("MackerelFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
	}
};

modded class PrepareWalleyePollock extends PrepareFish {
	override void Init() {
		super.Init();
		InsertIngredient(0, "WalleyePollock");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Fish && m_gebsConfig.Fish.Get("WalleyePollock")) {
			FishConf c = m_gebsConfig.Fish.Get("WalleyePollock");
			minMeat = c.MeatMin;
			maxMeat = c.MeatMax;
		}
		// Defend against admin inversion (MeatMin > MeatMax). Without this
		// the RandomInt rolls into a degenerate range and the for-loop never
		// runs -> zero fillets, silently. Matches the GetInclusiveRandom
		// guard used by every fish that extends GebPrepareFishBase.
		if (maxMeat < minMeat) maxMeat = minMeat;
		int ran = Math.RandomInt(minMeat, maxMeat + 1);
		for (int i = 0; i < ran; ++i) {
			AddResult("WalleyePollockFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
	}
};
