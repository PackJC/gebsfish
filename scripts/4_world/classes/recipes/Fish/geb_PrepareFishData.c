// One stable recipe ID for all configured non-vanilla fish.
// Ingredient eligibility reads the live config, including after ConfigSync.
// Inventory_Base keeps custom catch items eligible without registration changes.
class GebPrepareFishData : GebPrepareFishBase {
    override void Init() {
        super.Init();
        m_GebConfiguredRecipe = true;
        SetupFishRecipe("Inventory_Base");
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player) {
        if (!ingredients[0]) return false;
        string species = ingredients[0].GetType();
        if (species == "Carp" || species == "SteelheadTrout" || species == "Mackerel" || species == "WalleyePollock")
            return false;
        return super.CanDo(ingredients, player);
    }
}
