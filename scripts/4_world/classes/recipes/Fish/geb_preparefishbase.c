// Shared marker base for the single data-driven recipe.
class GebPrepareFishBase extends PrepareFish {}

// Vanilla fish retain vanilla recipe IDs. Outputs are built by
// PrepareFish.SpawnItems from current configuration for every preparation.
// Each fillets only its own fish: vanilla's ingredient match would also take
// another mod's fish built on it, which GebResolveRecipe refuses here.
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
