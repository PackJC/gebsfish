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

		//Tools
		// Registered BEFORE the data-driven fish loop on purpose. RegisterRecipe
		// hands out sequential IDs and actions send that ID over the network, so
		// client and server must agree. Anything registered after a variable-length
		// loop shifts by however many species that side happened to register --
		// keep the fixed recipes first so their IDs never move.
		RegisterRecipe(new CraftBambooFishingNet);
		RegisterRecipe(new RepairFishingPole);
		RegisterRecipe(new RepairBambooFishingNet);
		RegisterRecipe(new CraftHookFromWire);
		RegisterRecipe(new CraftFishMount);

		// Fish fillet/caviar/lobster recipes -- data-driven from the live Species table.
		// One generic recipe per row that has a ResultMain; the 4 vanilla fish
		// (Carp/SteelheadTrout/Mackerel/WalleyePollock) stay as their own modded classes.
		// Clients seed the compiled defaults in gebsfishConfig.LoadAll so this loop
		// registers the same set here as it does on the server.
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
		} else {
			GebsfishLogger.Error("Species table unavailable at recipe registration -- no fish fillet recipes were registered (fish will have no Gut action).", "Recipes");
		}
	}
};