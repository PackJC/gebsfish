/* ============================================================================
   One generic yield, seeded from a FishConf row. Registered once per
   Species entry (see geb_missionbase).
   ============================================================================ */
class geb_YieldFishGeneric : GebYieldFishBase {
    protected ref FishConf m_Conf;

    // NOTE: we deliberately declare NO constructor here. The vanilla base
    // (FishYieldItemBase) requires an int (catch probability) in its
    // constructor, so callers do `new geb_YieldFishGeneric(catchProb)` and the
    // arg forwards straight to the base.
    // The FishConf row can't ride in the constructor (its type wouldn't match
    // the base's int prototype), so it comes through this setter.
    //
    // CRITICAL ORDERING: vanilla YieldItemBase's constructor calls Init()
    // itself (3_Game/DayZ/Systems/AnimalCatching/CatchYieldItemBase.c), so
    // Init() has ALREADY run -- with m_Conf still null -- before this setter
    // can be called, and CatchYieldBank.RegisterYieldItem never calls it
    // again (it only assigns a registration index and does a map insert).
    // So the setup has to be applied from here. Without this, SetupYield never
    // runs, m_Type stays "" and the enviro/method masks stay 0: the bank keys
    // on GetType().Hash(), so all 79 species collapse onto one empty entry
    // that matches no environment or catch method -- you catch only junk.
    void SetConf(FishConf conf) {
        m_Conf = conf;
        ApplyConf();
    }

    override void Init() {
        ApplyConf();   // no-op during construction: m_Conf isn't set yet
    }

    protected void ApplyConf() {
        if (!m_Conf) return;
        // Careful with SetupYield's param order: night is the 3rd multiplier
        // (rain, storm, night, then dawn/day/dusk).
        SetupYield(m_Conf.Classname, m_Conf.Environment, m_Conf.CatchMethod,
                   m_Conf.RainMultiplier, m_Conf.StormMultiplier, m_Conf.NightMultiplier,
                   m_Conf.DawnMultiplier, m_Conf.DayMultiplier, m_Conf.DuskMultiplier,
                   m_Conf.CatchProbability, m_Conf.GetBiteSpeedArray());
        SetTemperature(m_Conf.TempOptimal, m_Conf.TempMin, m_Conf.TempMax);
    }
}
