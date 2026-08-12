class GebPrepareFishBase extends PrepareFish {
	// The generic setup/result helpers (SetupFishRecipe, AddRepeatedResults,
	// GetInclusiveRandom, the caviar-chance pair, SetupVanillaFilletRecipe)
	// live on modded PrepareFish (preparefish.c) so the vanilla-fish recipes
	// below -- which extend PrepareFish directly, not this class -- share
	// them. This base keeps only the three recipe shapes the data-driven
	// pipeline (GebPrepareFishData) dispatches on.

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
};

// ===== VANILLA FISH (facade reads via m_gebsConfig.Fish.Get(...)) =====
//
// Each recipe collapses to SetupVanillaFilletRecipe (modded PrepareFish),
// which reads MeatMin/MeatMax from the live Species row, falls back to one
// meat piece when the row is missing, guards MeatMin > MeatMax inversion,
// and clamps total results to the engine's MAXIMUM_RESULTS cap. These were
// previously four near-identical ~40-line Init() bodies that had already
// drifted from the shared helpers (and missed the MAXIMUM_RESULTS clamp).

modded class PrepareCarp extends PrepareFish {
	override void Init() {
		super.Init();
		SetupVanillaFilletRecipe("Carp", "CarpFilletMeat");
	}
};

modded class PrepareSteelheadTrout extends PrepareFish {
	override void Init() {
		super.Init();
		SetupVanillaFilletRecipe("SteelheadTrout", "SteelheadTroutFilletMeat", "RedCaviar");
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		super.Do(ingredients, player, results, specialty_weight);
		ApplyConfiguredCaviarChance(results);
	}
};

modded class PrepareMackerel extends PrepareFish {
	override void Init() {
		super.Init();
		SetupVanillaFilletRecipe("Mackerel", "MackerelFilletMeat");
	}
};

modded class PrepareWalleyePollock extends PrepareFish {
	override void Init() {
		super.Init();
		SetupVanillaFilletRecipe("WalleyePollock", "WalleyePollockFilletMeat");
	}
};
