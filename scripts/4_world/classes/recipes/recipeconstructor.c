/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class PluginRecipesManager {
	override void RegisterRecipies() {
		super.RegisterRecipies();

		// Fish fillet/caviar/lobster recipes -- data-driven from the live Species table.
		// One generic recipe per row that has a ResultMain; the 4 vanilla fish
		// (Carp/SteelheadTrout/Mackerel/WalleyePollock) stay as their own modded classes.
		gebsfishConfig cfg = GetGebSettingsConfig();
		if (cfg && cfg.Fish && cfg.Fish.Species) {
			GebPrepareFishData recipe;
			foreach (FishConf f : cfg.Fish.Species) {
				if (!f || f.ResultMain == "") continue;                       // catch-only: no recipe
				if (f.Classname == "Carp" || f.Classname == "SteelheadTrout" || f.Classname == "Mackerel" || f.Classname == "WalleyePollock") continue; // vanilla: modded classes
				recipe = new GebPrepareFishData();
				recipe.SetConf(f);
				RegisterRecipe(recipe);
			}
		}

		//Tools
		RegisterRecipe(new CraftBambooFishingNet);
		RegisterRecipe(new RepairFishingPole);
		RegisterRecipe(new RepairBambooFishingNet);
		RegisterRecipe(new CraftHookFromWire);
	}
};