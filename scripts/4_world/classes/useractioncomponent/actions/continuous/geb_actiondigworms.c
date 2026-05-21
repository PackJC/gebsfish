modded class ActionDigWorms {
	string GetConfiguredDigWormSpawnType() {
		if (!m_gebsConfig || !m_gebsConfig.DigWorms || m_gebsConfig.DigWorms.Count() == 0)
			return GetFallbackDigWormSpawnType();

		float totalChance = 0.0;
		foreach (BugEntry wormEntry1 : m_gebsConfig.DigWorms) {
			if (!wormEntry1 || wormEntry1.Classname == "" || wormEntry1.CatchChance <= 0)
				continue;

			totalChance += wormEntry1.CatchChance;
		}

		if (totalChance <= 0)
			return GetFallbackDigWormSpawnType();

		float roll = Math.RandomFloatInclusive(0.0, totalChance);
		foreach (BugEntry wormEntry : m_gebsConfig.DigWorms) {
			if (!wormEntry || wormEntry.Classname == "" || wormEntry.CatchChance <= 0)
				continue;

			if (roll <= wormEntry.CatchChance)
				return wormEntry.Classname;

			roll -= wormEntry.CatchChance;
		}

		return GetFallbackDigWormSpawnType();
	}

	string GetFallbackDigWormSpawnType() {
		if (Math.RandomFloat01() < 0.25)
			return "geb_GrubWorm";

		return "Worm";
	}

	override void OnFinishProgressServer(ActionData action_data) {
		PlayerBase player = action_data.m_Player;
		if (!player || !action_data.m_MainItem || !action_data.m_Target)
			return;

		int amount = action_data.m_MainItem.GetOnDigWormsAmount();

		for (int i = 0; i < amount; i++) {
			string spawnType = GetConfiguredDigWormSpawnType();
			GetGame().CreateObjectEx(spawnType, action_data.m_Target.GetCursorHitPos(), ECE_PLACE_ON_SURFACE);
		}

		MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 4);
	}
}
