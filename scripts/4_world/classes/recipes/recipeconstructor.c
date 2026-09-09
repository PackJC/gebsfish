modded class PluginRecipesManager {
    override void RegisterRecipies() {
        super.RegisterRecipies();
        // Fixed membership/order on both peers, independent of fish.json.
        RegisterRecipe(new CraftBambooFishingNet);
        RegisterRecipe(new RepairFishingPole);
        RegisterRecipe(new RepairBambooFishingNet);
        RegisterRecipe(new CraftHookFromWire);
        RegisterRecipe(new CraftFishMount);
        RegisterRecipe(new GebPrepareFishData);
    }
};
