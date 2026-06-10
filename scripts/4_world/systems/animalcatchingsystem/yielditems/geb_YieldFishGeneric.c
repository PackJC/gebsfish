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
    // the base's int prototype), so it comes through this setter, which MUST be
    // called BEFORE RegisterYieldItem() -- that's what triggers Init().
    void SetConf(FishConf conf) { m_Conf = conf; }

    override void Init() {
        if (!m_Conf) return;
        // Careful with SetupYield's param order: night is the 3rd multiplier
        // (rain, storm, night, then dawn/day/dusk).
        SetupYield(m_Conf.Classname, m_Conf.Environment, m_Conf.CatchMethod,
                   m_Conf.RainMultiplier, m_Conf.StormMultiplier, m_Conf.NightMultiplier,
                   m_Conf.DawnMultiplier, m_Conf.DayMultiplier, m_Conf.DuskMultiplier,
                   m_Conf.CatchProbability, m_Conf.BiteSpeed);
        SetTemperature(m_Conf.TempOptimal, m_Conf.TempMin, m_Conf.TempMax);
    }
}
