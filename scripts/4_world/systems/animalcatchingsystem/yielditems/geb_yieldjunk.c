/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// YieldItemJunk and YieldItemJunkEmpty are defined in vanilla DayZ at
// 4_World/DayZ/Systems/AnimalCatchingSystem/YieldItems/YieldsFishingJunk.c,
// so the modded class declarations have to live in 4_World too. Trying to
// mod them from 3_Game fails with "Unknown type 'YieldItemJunk'" because
// 3_Game cannot see 4_World types.

modded class YieldItemJunk {
	protected int m_GebMinHealthLevel = 3;
	protected int m_GebMaxHealthLevel = 3;

	void GebSetHealthLevelRange(int minHealthLevel, int maxHealthLevel) {
		m_GebMinHealthLevel = Math.Clamp(minHealthLevel, 0, 4);
		m_GebMaxHealthLevel = Math.Clamp(maxHealthLevel, 0, 4);

		if (m_GebMaxHealthLevel < m_GebMinHealthLevel)
			m_GebMaxHealthLevel = m_GebMinHealthLevel;
	}

	// Vanilla calls SetHealthLevel(STATE_BADLY_DAMAGED) here. We override to
	// roll a configurable [min..max] health level so server admins can decide
	// how broken the junk catches are. Skip super so vanilla's hard-coded
	// BADLY_DAMAGED set doesn't fight ours.
	override void OnEntityYieldSpawned(EntityAI spawn) {
		if (!spawn)
			return;

		int healthLevel = Math.RandomInt(m_GebMinHealthLevel, m_GebMaxHealthLevel + 1);
		spawn.SetHealthLevel(healthLevel, "");
	}
}
