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
	// Meat* drives the meat). Previously Meat* meant total pieces INCLUDING the
	// tail, so a roll of MeatMin=1 yielded a clawless tail. Net effect of this
	// change: a lobster now yields its tail PLUS [MeatMin..MeatMax] claws.
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
		if (m_gebsConfig && m_gebsConfig.GeneralSettings) {
			return m_gebsConfig.GeneralSettings.CaviarChance;
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

// Intermediate base for caviar fish: adds the post-fillet caviar roll so each
// caviar recipe only needs its Init(). super.Do() chains to PrepareFish.Do
// (predator + hook-from-fish), then we apply the configured caviar chance.
class GebPrepareCaviarFishBase extends GebPrepareFishBase {
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
		ApplyConfiguredCaviarChance(results);
	}
};

// ===== FRESHWATER FISH =====

class PrepareYellowPerch extends GebPrepareFishBase {
	override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.YellowPerch) {
			minMeat = m_gebsConfig.YellowPerch.MeatMin;
			maxMeat = m_gebsConfig.YellowPerch.MeatMax;
		}
		SetupStandardRecipe("geb_YellowPerch", "geb_YellowPerchFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBlackBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BlackBass) {
			minMeat = m_gebsConfig.BlackBass.MeatMin;
			maxMeat = m_gebsConfig.BlackBass.MeatMax;
		}
		SetupStandardRecipe("geb_BlackBass", "geb_BlackBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBlueGill extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BlueGill) {
			minMeat = m_gebsConfig.BlueGill.MeatMin;
			maxMeat = m_gebsConfig.BlueGill.MeatMax;
		}
		SetupStandardRecipe("geb_BlueGill", "geb_BlueGillFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBowFin extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BowFin) {
			minMeat = m_gebsConfig.BowFin.MeatMin;
			maxMeat = m_gebsConfig.BowFin.MeatMax;
		}
		SetupStandardRecipe("geb_BowFin", "geb_BowFinFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBrookTrout extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BrookTrout) {
			minMeat = m_gebsConfig.BrookTrout.MeatMin;
			maxMeat = m_gebsConfig.BrookTrout.MeatMax;
		}
		SetupCaviarRecipe("geb_BrookTrout", "RedCaviar", "geb_BrookTroutFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBrownTrout extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BrownTrout) {
			minMeat = m_gebsConfig.BrownTrout.MeatMin;
			maxMeat = m_gebsConfig.BrownTrout.MeatMax;
		}
		SetupCaviarRecipe("geb_BrownTrout", "RedCaviar", "geb_BrownTroutFilletMeat", minMeat, maxMeat);
	}
};

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
		if (m_gebsConfig && m_gebsConfig.Carp) {
			minMeat = m_gebsConfig.Carp.MeatMin;
			maxMeat = m_gebsConfig.Carp.MeatMax;
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

class PrepareCherrySalmon extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.CherrySalmon) {
			minMeat = m_gebsConfig.CherrySalmon.MeatMin;
			maxMeat = m_gebsConfig.CherrySalmon.MeatMax;
		}
		SetupCaviarRecipe("geb_CherrySalmon", "RedCaviar", "geb_CherrySalmonFilletMeat", minMeat, maxMeat);
	}
};

class PrepareChinookSalmon extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.ChinookSalmon) {
			minMeat = m_gebsConfig.ChinookSalmon.MeatMin;
			maxMeat = m_gebsConfig.ChinookSalmon.MeatMax;
		}
		SetupCaviarRecipe("geb_ChinookSalmon", "RedCaviar", "geb_ChinookSalmonFilletMeat", minMeat, maxMeat);
	}
};

class PrepareCutThroatTrout extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.CutThroatTrout) {
			minMeat = m_gebsConfig.CutThroatTrout.MeatMin;
			maxMeat = m_gebsConfig.CutThroatTrout.MeatMax;
		}
		SetupCaviarRecipe("geb_CutThroatTrout", "RedCaviar", "geb_CutThroatTroutFilletMeat", minMeat, maxMeat);
	}
};

class PrepareFlatHeadCatFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.FlatHeadCatFish) {
			minMeat = m_gebsConfig.FlatHeadCatFish.MeatMin;
			maxMeat = m_gebsConfig.FlatHeadCatFish.MeatMax;
		}
		SetupStandardRecipe("geb_FlatHeadCatFish", "geb_FlatHeadCatFishFilletMeat", minMeat, maxMeat);
	}
};

class PrepareLakeTrout extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.LakeTrout) {
			minMeat = m_gebsConfig.LakeTrout.MeatMin;
			maxMeat = m_gebsConfig.LakeTrout.MeatMax;
		}
		SetupStandardRecipe("geb_LakeTrout", "geb_LakeTroutFilletMeat", minMeat, maxMeat);
	}
};

class PrepareLargeMouthBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.LargeMouthBass) {
			minMeat = m_gebsConfig.LargeMouthBass.MeatMin;
			maxMeat = m_gebsConfig.LargeMouthBass.MeatMax;
		}
		SetupStandardRecipe("geb_LargeMouthBass", "geb_LargeMouthBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareAlligatorGar extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AlligatorGar) {
			minMeat = m_gebsConfig.AlligatorGar.MeatMin;
			maxMeat = m_gebsConfig.AlligatorGar.MeatMax;
		}
		SetupStandardRecipe("geb_AlligatorGar", "geb_AlligatorGarFilletMeat", minMeat, maxMeat);
	}
};

class PrepareNorthernSnakeHead extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.NorthernSnakeHead) {
			minMeat = m_gebsConfig.NorthernSnakeHead.MeatMin;
			maxMeat = m_gebsConfig.NorthernSnakeHead.MeatMax;
		}
		SetupStandardRecipe("geb_NorthernSnakeHead", "geb_NorthernSnakeHeadFilletMeat", minMeat, maxMeat);
	}
};

class PrepareNorthernPike extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.NorthernPike) {
			minMeat = m_gebsConfig.NorthernPike.MeatMin;
			maxMeat = m_gebsConfig.NorthernPike.MeatMax;
		}
		SetupCaviarRecipe("geb_NorthernPike", "geb_YellowCaviar", "geb_NorthernPikeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareMuskellunge extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Muskellunge) {
			minMeat = m_gebsConfig.Muskellunge.MeatMin;
			maxMeat = m_gebsConfig.Muskellunge.MeatMax;
		}
		SetupCaviarRecipe("geb_Muskellunge", "geb_YellowCaviar", "geb_MuskellungeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareTigerMuskellunge extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.TigerMuskellunge) {
			minMeat = m_gebsConfig.TigerMuskellunge.MeatMin;
			maxMeat = m_gebsConfig.TigerMuskellunge.MeatMax;
		}
		SetupCaviarRecipe("geb_TigerMuskellunge", "geb_YellowCaviar", "geb_TigerMuskellungeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBarredMuskellunge extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BarredMuskellunge) {
			minMeat = m_gebsConfig.BarredMuskellunge.MeatMin;
			maxMeat = m_gebsConfig.BarredMuskellunge.MeatMax;
		}
		SetupCaviarRecipe("geb_BarredMuskellunge", "geb_YellowCaviar", "geb_BarredMuskellungeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSpottedMuskellunge extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SpottedMuskellunge) {
			minMeat = m_gebsConfig.SpottedMuskellunge.MeatMin;
			maxMeat = m_gebsConfig.SpottedMuskellunge.MeatMax;
		}
		SetupCaviarRecipe("geb_SpottedMuskellunge", "geb_YellowCaviar", "geb_SpottedMuskellungeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareRainbowTrout extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.RainbowTrout) {
			minMeat = m_gebsConfig.RainbowTrout.MeatMin;
			maxMeat = m_gebsConfig.RainbowTrout.MeatMax;
		}
		SetupCaviarRecipe("geb_RainbowTrout", "RedCaviar", "geb_RainbowTroutFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSauger extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Sauger) {
			minMeat = m_gebsConfig.Sauger.MeatMin;
			maxMeat = m_gebsConfig.Sauger.MeatMax;
		}
		SetupStandardRecipe("geb_Sauger", "geb_SaugerFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSlimySculpin extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SlimySculpin) {
			minMeat = m_gebsConfig.SlimySculpin.MeatMin;
			maxMeat = m_gebsConfig.SlimySculpin.MeatMax;
		}
		SetupStandardRecipe("geb_SlimySculpin", "geb_SlimySculpinFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSmallMouthBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SmallMouthBass) {
			minMeat = m_gebsConfig.SmallMouthBass.MeatMin;
			maxMeat = m_gebsConfig.SmallMouthBass.MeatMax;
		}
		SetupStandardRecipe("geb_SmallMouthBass", "geb_SmallMouthBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSockEyeSalmon extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SockEyeSalmon) {
			minMeat = m_gebsConfig.SockEyeSalmon.MeatMin;
			maxMeat = m_gebsConfig.SockEyeSalmon.MeatMax;
		}
		SetupCaviarRecipe("geb_SockEyeSalmon", "RedCaviar", "geb_SockEyeSalmonFilletMeat", minMeat, maxMeat);
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
		if (m_gebsConfig && m_gebsConfig.SteelheadTrout) {
			minMeat = m_gebsConfig.SteelheadTrout.MeatMin;
			maxMeat = m_gebsConfig.SteelheadTrout.MeatMax;
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
		if (m_gebsConfig && m_gebsConfig.GeneralSettings) {
			chance = m_gebsConfig.GeneralSettings.CaviarChance;
		}

		if (chance <= 0.0 || (chance < 1.0 && Math.RandomFloat(0, 1) > chance)) {
			if (results && results.Count() > 0 && results[0])
				results[0].Delete();
		}
	}
};

class PrepareLakeSturgeon extends GebPrepareCaviarFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.LakeSturgeon) {
			minMeat = m_gebsConfig.LakeSturgeon.MeatMin;
			maxMeat = m_gebsConfig.LakeSturgeon.MeatMax;
		}
		SetupCaviarRecipe("geb_LakeSturgeon", "geb_BlackCaviar", "geb_LakeSturgeonFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSunFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SunFish) {
			minMeat = m_gebsConfig.SunFish.MeatMin;
			maxMeat = m_gebsConfig.SunFish.MeatMax;
		}
		SetupStandardRecipe("geb_SunFish", "geb_SunFishFilletMeat", minMeat, maxMeat);
	}
};

class PrepareWallEye extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.WallEye) {
			minMeat = m_gebsConfig.WallEye.MeatMin;
			maxMeat = m_gebsConfig.WallEye.MeatMax;
		}
		SetupStandardRecipe("geb_WallEye", "geb_WallEyeFilletMeat", minMeat, maxMeat);
	}
};

class PrepareWhiteBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.WhiteBass) {
			minMeat = m_gebsConfig.WhiteBass.MeatMin;
			maxMeat = m_gebsConfig.WhiteBass.MeatMax;
		}
		SetupStandardRecipe("geb_WhiteBass", "geb_WhiteBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareStripedBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.StripedBass) {
			minMeat = m_gebsConfig.StripedBass.MeatMin;
			maxMeat = m_gebsConfig.StripedBass.MeatMax;
		}
		SetupStandardRecipe("geb_StripedBass", "geb_StripedBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareNeoshoBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.NeoshoBass) {
			minMeat = m_gebsConfig.NeoshoBass.MeatMin;
			maxMeat = m_gebsConfig.NeoshoBass.MeatMax;
		}
		SetupStandardRecipe("geb_NeoshoBass", "geb_NeoshoBassFilletMeat", minMeat, maxMeat);
	}
};

// ===== FRESHWATER CRUSTACEAN =====
// None currently

// ===== SALTWATER FISH =====

class PrepareAngelFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AngelFish) {
			minMeat = m_gebsConfig.AngelFish.MeatMin;
			maxMeat = m_gebsConfig.AngelFish.MeatMax;
		}
		SetupStandardRecipe("geb_AngelFish", "geb_AngelFishFilletMeat", minMeat, maxMeat);
	}
};

class PrepareAngelShark extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AngelShark) {
			minMeat = m_gebsConfig.AngelShark.MeatMin;
			maxMeat = m_gebsConfig.AngelShark.MeatMax;
		}
		SetupStandardRecipe("geb_AngelShark", "geb_AngelSharkFilletMeat", minMeat, maxMeat);
	}
};

class PrepareAsianSeaBass extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AsianSeaBass) {
			minMeat = m_gebsConfig.AsianSeaBass.MeatMin;
			maxMeat = m_gebsConfig.AsianSeaBass.MeatMax;
		}
		SetupStandardRecipe("geb_AsianSeaBass", "geb_AsianSeaBassFilletMeat", minMeat, maxMeat);
	}
};

class PrepareAtlanticBlueMarlin extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AtlanticBlueMarlin) {
			minMeat = m_gebsConfig.AtlanticBlueMarlin.MeatMin;
			maxMeat = m_gebsConfig.AtlanticBlueMarlin.MeatMax;
		}
		SetupStandardRecipe("geb_AtlanticBlueMarlin", "geb_AtlanticBlueMarlinFilletMeat", minMeat, maxMeat);
	}
};

class PrepareAtlanticSailFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AtlanticSailFish) {
			minMeat = m_gebsConfig.AtlanticSailFish.MeatMin;
			maxMeat = m_gebsConfig.AtlanticSailFish.MeatMax;
		}
		SetupStandardRecipe("geb_AtlanticSailFish", "geb_AtlanticSailFishFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBlueTang extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.BlueTang) {
			minMeat = m_gebsConfig.BlueTang.MeatMin;
			maxMeat = m_gebsConfig.BlueTang.MeatMax;
		}
		SetupStandardRecipe("geb_BlueTang", "geb_BlueTangFilletMeat", minMeat, maxMeat);
	}
};

class PrepareBonita extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Bonita) {
			minMeat = m_gebsConfig.Bonita.MeatMin;
			maxMeat = m_gebsConfig.Bonita.MeatMax;
		}
		SetupStandardRecipe("geb_Bonita", "geb_BonitaFilletMeat", minMeat, maxMeat);
	}
};

class PrepareFlatHeadMullet extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.FlatHeadMullet) {
			minMeat = m_gebsConfig.FlatHeadMullet.MeatMin;
			maxMeat = m_gebsConfig.FlatHeadMullet.MeatMax;
		}
		SetupStandardRecipe("geb_FlatHeadMullet", "geb_FlatHeadMulletFilletMeat", minMeat, maxMeat);
	}
};

class PrepareGreatWhiteShark extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.GreatWhiteShark) {
			minMeat = m_gebsConfig.GreatWhiteShark.MeatMin;
			maxMeat = m_gebsConfig.GreatWhiteShark.MeatMax;
		}
		SetupStandardRecipe("geb_GreatWhiteShark", "geb_GreatWhiteSharkFilletMeat", minMeat, maxMeat);
	}
};

class PrepareHammerHeadShark extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.HammerHeadShark) {
			minMeat = m_gebsConfig.HammerHeadShark.MeatMin;
			maxMeat = m_gebsConfig.HammerHeadShark.MeatMax;
		}
		SetupStandardRecipe("geb_HammerHeadShark", "geb_HammerHeadSharkFilletMeat", minMeat, maxMeat);
	}
};

class PrepareHumpHeadWrasse extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.HumpHeadWrasse) {
			minMeat = m_gebsConfig.HumpHeadWrasse.MeatMin;
			maxMeat = m_gebsConfig.HumpHeadWrasse.MeatMax;
		}
		SetupStandardRecipe("geb_HumpHeadWrasse", "geb_HumpHeadWrasseFilletMeat", minMeat, maxMeat);
	}
};

class PrepareLargeHeadHairTailFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.LargeHeadHairTailFish) {
			minMeat = m_gebsConfig.LargeHeadHairTailFish.MeatMin;
			maxMeat = m_gebsConfig.LargeHeadHairTailFish.MeatMax;
		}
		SetupStandardRecipe("geb_LargeHeadHairTailFish", "geb_LargeHeadHairTailFishFilletMeat", minMeat, maxMeat);
	}
};

class PrepareLeopardShark extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.LeopardShark) {
			minMeat = m_gebsConfig.LeopardShark.MeatMin;
			maxMeat = m_gebsConfig.LeopardShark.MeatMax;
		}
		SetupStandardRecipe("geb_LeopardShark", "geb_LeopardSharkFilletMeat", minMeat, maxMeat);
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
		if (m_gebsConfig && m_gebsConfig.Mackerel) {
			minMeat = m_gebsConfig.Mackerel.MeatMin;
			maxMeat = m_gebsConfig.Mackerel.MeatMax;
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

class PrepareMahiMahi extends GebPrepareFishBase {
	override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.MahiMahi) {
			minMeat = m_gebsConfig.MahiMahi.MeatMin;
			maxMeat = m_gebsConfig.MahiMahi.MeatMax;
		}
		SetupStandardRecipe("geb_MahiMahi", "geb_MahiMahiFilletMeat", minMeat, maxMeat);
	}
};

class PreparePacificCod extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.PacificCod) {
			minMeat = m_gebsConfig.PacificCod.MeatMin;
			maxMeat = m_gebsConfig.PacificCod.MeatMax;
		}
		SetupStandardRecipe("geb_PacificCod", "geb_PacificCodFilletMeat", minMeat, maxMeat);
	}
};

class PrepareRedHeadCichlid extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.RedHeadCichlid) {
			minMeat = m_gebsConfig.RedHeadCichlid.MeatMin;
			maxMeat = m_gebsConfig.RedHeadCichlid.MeatMax;
		}
		SetupStandardRecipe("geb_RedHeadCichlid", "geb_RedHeadCichlidFilletMeat", minMeat, maxMeat);
	}
};

class PrepareRoughNeckRock extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.RoughNeckRock) {
			minMeat = m_gebsConfig.RoughNeckRock.MeatMin;
			maxMeat = m_gebsConfig.RoughNeckRock.MeatMax;
		}
		SetupStandardRecipe("geb_RoughNeckRock", "geb_RoughNeckRockFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSeverum extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.Severum) {
			minMeat = m_gebsConfig.Severum.MeatMin;
			maxMeat = m_gebsConfig.Severum.MeatMax;
		}
		SetupStandardRecipe("geb_Severum", "geb_SeverumFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSiameseTigerFish extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SiameseTigerFish) {
			minMeat = m_gebsConfig.SiameseTigerFish.MeatMin;
			maxMeat = m_gebsConfig.SiameseTigerFish.MeatMax;
		}
		SetupStandardRecipe("geb_SiameseTigerFish", "geb_SiameseTigerFishFilletMeat", minMeat, maxMeat);
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
		if (m_gebsConfig && m_gebsConfig.WalleyePollock) {
			minMeat = m_gebsConfig.WalleyePollock.MeatMin;
			maxMeat = m_gebsConfig.WalleyePollock.MeatMax;
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

class PrepareYellowFinTuna extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.YellowFinTuna) {
			minMeat = m_gebsConfig.YellowFinTuna.MeatMin;
			maxMeat = m_gebsConfig.YellowFinTuna.MeatMax;
		}
		SetupStandardRecipe("geb_YellowFinTuna", "geb_YellowFinTunaFilletMeat", minMeat, maxMeat);
	}
};

class PrepareYellowSnapper extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.YellowSnapper) {
			minMeat = m_gebsConfig.YellowSnapper.MeatMin;
			maxMeat = m_gebsConfig.YellowSnapper.MeatMax;
		}
		SetupStandardRecipe("geb_YellowSnapper", "geb_YellowSnapperFilletMeat", minMeat, maxMeat);
	}
};

class PrepareSouthernFlounder extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SouthernFlounder) {
			minMeat = m_gebsConfig.SouthernFlounder.MeatMin;
			maxMeat = m_gebsConfig.SouthernFlounder.MeatMax;
		}
		SetupStandardRecipe("geb_SouthernFlounder", "geb_SouthernFlounderFilletMeat", minMeat, maxMeat);
	}
};

class PrepareWhiteGrunt extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.WhiteGrunt) {
			minMeat = m_gebsConfig.WhiteGrunt.MeatMin;
			maxMeat = m_gebsConfig.WhiteGrunt.MeatMax;
		}
		SetupStandardRecipe("geb_WhiteGrunt", "geb_WhiteGruntFilletMeat", minMeat, maxMeat);
	}
};

// ===== SALTWATER CRUSTACEAN =====

class PrepareAmericanLobster extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.AmericanLobster) {
			minMeat = m_gebsConfig.AmericanLobster.MeatMin;
			maxMeat = m_gebsConfig.AmericanLobster.MeatMax;
		}
		SetupLobsterRecipe("geb_AmericanLobster", "geb_AmericanLobsterTail", "geb_AmericanLobsterClaw", minMeat, maxMeat);
	}
};

class PrepareEuropeanLobster extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.EuropeanLobster) {
			minMeat = m_gebsConfig.EuropeanLobster.MeatMin;
			maxMeat = m_gebsConfig.EuropeanLobster.MeatMax;
		}
		SetupLobsterRecipe("geb_EuropeanLobster", "geb_EuropeanLobsterTail", "geb_EuropeanLobsterClaw", minMeat, maxMeat);
	}
};

class PrepareKingCrab extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.KingCrab) {
			minMeat = m_gebsConfig.KingCrab.MeatMin;
			maxMeat = m_gebsConfig.KingCrab.MeatMax;
		}
		SetupStandardRecipe("geb_KingCrab", "geb_KingCrabLegs", minMeat, maxMeat);
	}
};

class PrepareSnowCrab extends GebPrepareFishBase {
    override void Init() {
		super.Init();
		int minMeat = 1;
		int maxMeat = 1;
		// Keep the recipe registered even if this fish config section is missing.
		// Missing config falls back to one meat piece instead of crashing Init().
		if (m_gebsConfig && m_gebsConfig.SnowCrab) {
			minMeat = m_gebsConfig.SnowCrab.MeatMin;
			maxMeat = m_gebsConfig.SnowCrab.MeatMax;
		}
		SetupStandardRecipe("geb_SnowCrab", "geb_SnowCrabLegs", minMeat, maxMeat);
	}
};
