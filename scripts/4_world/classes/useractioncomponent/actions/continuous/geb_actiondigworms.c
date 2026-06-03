modded class ActionDigWorms {
	string GetConfiguredDigWormSpawnType() {
		int debugLevel = 0;
		if (m_gebsConfig && m_gebsConfig.GeneralSettings)
			debugLevel = m_gebsConfig.GeneralSettings.DebugLogs;

		if (!m_gebsConfig || !m_gebsConfig.DigWormsSettings) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-worms: config missing -- using fallback", "DigWorms");
			return GetFallbackDigWormSpawnType();
		}
		ref array<ref BugEntry> catches = m_gebsConfig.DigWormsSettings.Catches;
		if (!catches || catches.Count() == 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-worms: Catches table empty -- using fallback", "DigWorms");
			return GetFallbackDigWormSpawnType();
		}

		if (debugLevel == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---Dig-worms weighted pick---", "DigWorms");
			GebsfishLogger.Debug("entry | classname | chance | included", "DigWorms");
		}

		float totalChance = 0.0;
		int idx = 0;
		foreach (BugEntry wormEntry1 : catches) {
			bool included = true;
			string reason = "";
			if (!wormEntry1 || wormEntry1.Classname == "" || wormEntry1.CatchChance <= 0) {
				included = false;
				reason = "blank/zero";
			}
			if (debugLevel == ELEVATED_DEBUG) {
				string entryCls = "<null>";
				float entryChance = 0;
				if (wormEntry1) {
					entryCls = wormEntry1.Classname;
					entryChance = wormEntry1.CatchChance;
				}
				string flag = "yes";
				if (!included)
					flag = "no (" + reason + ")";
				GebsfishLogger.Debug("" + idx + " | " + entryCls + " | " + entryChance + " | " + flag, "DigWorms");
			}
			if (included)
				totalChance += wormEntry1.CatchChance;
			idx++;
		}

		if (totalChance <= 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-worms: totalChance=0 after filter -- using fallback", "DigWorms");
			return GetFallbackDigWormSpawnType();
		}

		float roll = Math.RandomFloatInclusive(0.0, totalChance);
		float rollStart = roll;
		foreach (BugEntry wormEntry : catches) {
			if (!wormEntry || wormEntry.Classname == "" || wormEntry.CatchChance <= 0)
				continue;

			if (roll <= wormEntry.CatchChance) {
				if (debugLevel >= 1)
					GebsfishLogger.Debug("Dig-worms picked: " + wormEntry.Classname + " roll=" + rollStart + " totalChance=" + totalChance, "DigWorms");
				return wormEntry.Classname;
			}

			roll -= wormEntry.CatchChance;
		}

		if (debugLevel >= 1)
			GebsfishLogger.Debug("Dig-worms: weighted walk exhausted -- using fallback", "DigWorms");
		return GetFallbackDigWormSpawnType();
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
		if (!m_gebsConfig || !m_gebsConfig.DigWormsSettings)
			return 1.0;

		float chance = m_gebsConfig.DigWormsSettings.FindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		PlayerBase player = action_data.m_Player;
		if (!player || !action_data.m_MainItem || !action_data.m_Target)
			return;

		int debugLevel = 0;
		if (m_gebsConfig && m_gebsConfig.GeneralSettings)
			debugLevel = m_gebsConfig.GeneralSettings.DebugLogs;

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
