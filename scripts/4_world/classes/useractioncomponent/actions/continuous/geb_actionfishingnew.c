modded class ActionFishingNew: ActionContinuousBase {
    override void OnEnd(ActionData action_data){
        super.OnEnd(action_data);

        FishingActionData fad;
        if (!Class.CastTo(fad, action_data))
            return;

        // Animate the rod as a fallback.
        fad.AnimateRod(false, true);

        if (!fad.m_Player || !g_Game.IsServer())
            return;

        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.PredatorSettings)
            return;

        // Predator spawn chance is split by outcome:
        //   - Catch succeeded -> PredatorSpawnChanceFishing
        //   - Cast caught nothing -> PredatorSpawnChanceFailCatch
        // GebsPredatorSpawner.TrySpawn handles the chance roll, predator
        // selection, position search, multi-instance spawning, warning sound
        // RPC, and player chat warning. Caller just picks the right chance.
        float chance;
        if (fad.m_FishingResult == 1) {
            chance = m_gebsConfig.General.PredatorSettings.PredatorSpawnChanceFishing;
        } else {
            chance = m_gebsConfig.General.PredatorSettings.PredatorSpawnChanceFailCatch;

            if (GebGetDebugLevel() >= 1) {
                GebsfishLogger.Debug("Cast failed; rolling fail-catch predator chance (" + chance + ").", "PredatorSpawnFishing");
            }
        }

        GebsPredatorSpawner.TrySpawn(fad.m_Player, chance, "PredatorSpawnFishing");

        // Ultra-rare treasure, rolled only on a successful catch -- a failed cast
        // shouldn't hand out loot. Deliberately independent of the fish pool: it
        // has its own probability rather than being a yield competing with the 79
        // species, so tuning it never quietly starves anything else, and it can be
        // set far finer than the catch pool's 0-25 integer weights allow.
        if (fad.m_FishingResult == 1)
            GebsTreasureSpawner.TryPull(fad.m_Player, fad.m_MainItem, "Treasure");
    }
}
