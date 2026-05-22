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

        if (!m_gebsConfig || !m_gebsConfig.PredatorSettings)
            return;

        // Predator spawn chance is split by outcome:
        //   - Catch succeeded -> PredatorSpawnChanceFishing
        //   - Cast caught nothing -> PredatorSpawnChanceFailCatch
        // GebsPredatorSpawner.TrySpawn handles the chance roll, predator
        // selection, position search, multi-instance spawning, warning sound
        // RPC, and chat broadcast. Caller just picks the right chance.
        float chance;
        if (fad.m_FishingResult == 1) {
            chance = m_gebsConfig.PredatorSettings.PredatorSpawnChanceFishing;
        } else {
            chance = m_gebsConfig.PredatorSettings.PredatorSpawnChanceFailCatch;

            if (m_gebsConfig.GeneralSettings && m_gebsConfig.GeneralSettings.DebugLogs) {
                GebsfishLogger.Debug("Cast failed; rolling fail-catch predator chance (" + chance + ").", "PredatorSpawnFishing");
            }
        }

        GebsPredatorSpawner.TrySpawn(fad.m_Player, chance, "PredatorSpawnFishing");
    }

    string GetDisplayNameFromTypeName(string typeName) {
        // Find the display name in the config
        string displayName = "";
        if (g_Game.ConfigIsExisting("CfgVehicles " + typeName)) {
            displayName = g_Game.ConfigGetTextOut("CfgVehicles " + typeName + " displayName");
        }

        // Return display name or fallback to type name if not found
        if (displayName == "") {
            return typeName;
        }

        return displayName;
    }
}
