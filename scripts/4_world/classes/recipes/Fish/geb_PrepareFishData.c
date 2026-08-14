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
    // and Enforce requires a derived class's constructor to match it. So the
    // row comes through this setter.
    //
    // CRITICAL ORDERING: vanilla RecipeBase's constructor calls Init() itself
    // (4_World/DayZ/Classes/Recipes/RecipeBase.c), so Init() has ALREADY run --
    // with m_Conf still null -- before this setter can be called, and
    // PluginRecipesManager.RegisterRecipe never calls it again (it only inserts
    // into m_RecipeList and assigns an ID). So the conf-dependent setup has to
    // be applied from here, or the recipe registers with no ingredients and no
    // results and the fish gets no Gut action at all.
    //
    // Only the conf-dependent HALF is re-applied, not Init() as a whole:
    // super.Init() inserts the six knife ingredients, and InsertIngredient
    // appends (it also pushes into m_AnimationInfos), so re-running it would
    // duplicate every knife entry.
    void SetConf(FishConf conf) {
        m_Conf = conf;
        ApplyConf();
    }

    override void Init() {
        super.Init();  // knives + vanilla PrepareFish setup; must run exactly once
        ApplyConf();   // no-op during construction: m_Conf isn't set yet
    }

    protected void ApplyConf() {
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
