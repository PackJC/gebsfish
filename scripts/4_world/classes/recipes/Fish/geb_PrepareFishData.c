/* ============================================================================
   One data-driven fillet recipe, seeded from a FishConf row. Registered once
   per Species entry that has a ResultMain (see recipeconstructor). RecipeShape: 0 fillet, 1 caviar, 2 lobster.

   NOTE: the 4 vanilla fish (Carp/SteelheadTrout/Mackerel/WalleyePollock) remain
   their own `modded class Prepare*` overrides -- do NOT register them here too
   (skip rows whose Classname is a vanilla name, or just let those modded classes
   read their values from m_gebsConfig.Fish.Get(...)).
   ============================================================================ */
class GebPrepareFishData : GebPrepareFishBase {
    protected ref FishConf m_Conf;

    // NOTE: can't take the FishConf as a constructor arg -- the vanilla recipe
    // base (PrepareFish -> RecipeBase) declares a no-arg constructor prototype,
    // and Enforce requires a derived class's constructor to match it. Set the
    // row via this setter BEFORE RegisterRecipe(), which triggers Init().
    void SetConf(FishConf conf) { m_Conf = conf; }

    override void Init() {
        super.Init();
        if (!m_Conf || m_Conf.ResultMain == "") return; // catch-only species: no fillet recipe
        int mn = m_Conf.MeatMin;
        int mx = m_Conf.MeatMax;
        if (m_Conf.RecipeShape == 1)
            SetupCaviarRecipe(m_Conf.Classname, m_Conf.ResultBonus, m_Conf.ResultMain, mn, mx);
        else if (m_Conf.RecipeShape == 2)
            SetupLobsterRecipe(m_Conf.Classname, m_Conf.ResultBonus, m_Conf.ResultMain, mn, mx); // bonus=tail, main=claw
        else
            SetupStandardRecipe(m_Conf.Classname, m_Conf.ResultMain, mn, mx);
    }

    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
        super.Do(ingredients, player, results, specialty_weight);
        if (m_Conf && m_Conf.RecipeShape == 1) // caviar keep-chance only; lobster tail always kept
            ApplyConfiguredCaviarChance(results);
    }
}
