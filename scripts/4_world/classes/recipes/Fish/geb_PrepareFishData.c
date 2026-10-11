// One stable recipe ID for all configured non-vanilla fish.
// Ingredient eligibility reads the live config, including after ConfigSync.
// Inventory_Base keeps custom catch items eligible without registration changes.
class GebPrepareFishData : GebPrepareFishBase {
    override void Init() {
        super.Init();
        m_GebConfiguredRecipe = true;
        SetupFishRecipe("Inventory_Base");
        // Hidden (scope 1) aliases of renamed fish, kept so stored ones load
        // (data/fish/config.cpp). The crafting cache only takes scope 2 classes
        // by inheritance (PluginRecipesManager.GenerateRecipeCache), so an
        // alias is offered this recipe only when named here. It fillets by the
        // Pacific Bonito's row (GebResolveRecipe).
        InsertIngredient(0, "geb_Bonita", DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING, false);
    }

    // Vanilla's four fish are filleted by their own recipes (PrepareCarp etc.,
    // geb_preparefishbase.c), which take only those exact fish; offering them
    // here as well listed the fillet twice. Another mod's fish built on one of
    // them is filleted here, and only when it has a fish.json row of its own.
    override bool CanDo(ItemBase ingredients[], PlayerBase player) {
        if (!ingredients[0]) return false;
        string species = ingredients[0].GetType();
        if (GebSameClassname(species, "Carp") || GebSameClassname(species, "SteelheadTrout") || GebSameClassname(species, "Mackerel") || GebSameClassname(species, "WalleyePollock"))
            return false;
        return super.CanDo(ingredients, player);
    }
}
