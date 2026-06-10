modded class ActionDigWorms {
	string GetConfiguredDigWormSpawnType() {
		int debugLevel = GebGetDebugLevel();

		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.DigWormsSettings) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-worms: config missing -- using fallback", "DigWorms");
			return GetFallbackDigWormSpawnType();
		}
		ref array<ref BugEntry> catches = m_gebsConfig.General.DigWormsSettings.Catches;
		if (!catches || catches.Count() == 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-worms: Catches table empty -- using fallback", "DigWorms");
			return GetFallbackDigWormSpawnType();
		}

		TStringArray names = new TStringArray;
		TFloatArray weights = new TFloatArray;
		foreach (BugEntry wormEntry : catches) {
			if (!wormEntry || wormEntry.Classname == "" || wormEntry.CatchChance <= 0)
				continue;
			names.Insert(wormEntry.Classname);
			weights.Insert(wormEntry.CatchChance);
		}

		int pick = GebWeightedPick.Pick(names, weights, debugLevel, "DigWorms");
		if (pick < 0)
			return GetFallbackDigWormSpawnType();
		return names[pick];
	}

	// Fallback used when the config is missing, empty, or has zero total weight.
	// Always returns vanilla "Worm" so server owners who explicitly remove grubs
	// from their config never get them spawned anyway. Grubs only appear when
	// they're actively configured in DigWormsSettings.Catches.
	string GetFallbackDigWormSpawnType() {
		return "Worm";
	}

	// Returns the per-attempt find chance from the consolidated DigWormsSettings
	// section, clamped to [0, 1]. Defaults to 1.0 (always finds, matching
	// vanilla-style behaviour) when the config is unavailable so missing
	// config never blocks the action.
	float GetDigWormsFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.DigWormsSettings)
			return 1.0;

		float chance = m_gebsConfig.General.DigWormsSettings.FindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		if (!action_data || !action_data.m_Player || !action_data.m_MainItem || !action_data.m_Target)
			return;
		PlayerBase player = action_data.m_Player;

		int debugLevel = GebGetDebugLevel();

		int amount = action_data.m_MainItem.GetOnDigWormsAmount();
		float findChance = GetDigWormsFindChance();

		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Dig-worms attempt start: amount=" + amount + " findChance=" + findChance, "DigWorms");
		}

		int hits = 0;
		int misses = 0;
		// Each of the N attempts rolls its own find chance. On a miss, that
		// slot produces nothing. So expected yield is roughly amount * findChance.
		for (int i = 0; i < amount; i++) {
			float perRoll = -1;
			if (findChance < 1.0) {
				perRoll = Math.RandomFloat01();
				if (perRoll > findChance) {
					misses++;
					if (debugLevel == ELEVATED_DEBUG)
						GebsfishLogger.Debug("Dig-worms slot " + i + ": miss (roll=" + perRoll + ")", "DigWorms");
					continue;
				}
			}
			hits++;

			string spawnType = GetConfiguredDigWormSpawnType();
			if (debugLevel == ELEVATED_DEBUG)
				GebsfishLogger.Debug("Dig-worms slot " + i + ": hit (roll=" + perRoll + ") spawning " + spawnType, "DigWorms");
			GetGame().CreateObjectEx(spawnType, action_data.m_Target.GetCursorHitPos(), ECE_PLACE_ON_SURFACE);
		}

		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Dig-worms attempt complete: hits=" + hits + " misses=" + misses + " (amount=" + amount + ")", "DigWorms");
		}

		MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 4);
	}
}
