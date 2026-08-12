/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class MissionBase {
	// Bank instance the guard below has already registered into. A fresh
	// mission load builds a new bank (new instance), so re-registration
	// happens naturally; only repeat calls for the same bank are skipped.
	protected static CatchYieldBank s_GebInitializedBank;

	override void InitWorldYieldDataDefaults(CatchYieldBank bank) {
		// Deliberately NOT calling super, and NOT calling
		// ClearAllRegisteredItems(): vanilla's only job in this method is
		// registering its 15 default yields, which we previously registered
		// and then immediately cleared. Vanilla's clear only empties the
		// yields MAP -- not the private m_OrderedHashes sync list -- so that
		// register-then-clear dance stranded 15 dead registration indices
		// (0-14) at the front of the bank. Never registering the defaults
		// leaves both structures empty and in sync, with our yields starting
		// at index 0. Vanilla species stay catchable via our own Species
		// table (Carp, Mackerel, ... are registered by RegisterFishYieldData).
		if (!bank)
			return;

		// Re-entry guard: some world-init paths invoke this method twice per
		// boot for the SAME bank (see the double "Initializing yield data"
		// in server logs). With the old register-then-clear flow a second
		// pass self-corrected; now that nothing clears the bank, it would
		// append ~90 duplicate hashes to the sync list. Guard on the bank
		// INSTANCE -- not on "bank is non-empty" -- so a custom map's
		// WorldData that registers its own animals before this chain still
		// gets our yields added alongside them instead of being skipped.
		if (bank == s_GebInitializedBank) {
			GebsfishLogger.Info("Yield data already initialized for this bank -- skipping duplicate init.", "MissionBase");
			return;
		}
		s_GebInitializedBank = bank;

		GetGebSettingsConfig();

		GebsfishLogger.Info("Initializing yield data.", "MissionBase");

		RegisterFishYieldData(bank);
		RegisterJunkYieldData(bank);
		RegisterTrapAnimalYieldData(bank);

		GebsfishLogger.Info("Initialization of yield data complete.", "MissionBase");
	}

	protected void RegisterFishYieldData(CatchYieldBank bank) {
		if (!m_gebsConfig) {
			GebsfishLogger.Error("Gebsfish config was missing. Skipping fish yield registration.", "MissionBase");
			return;
		}

		GebsfishLogger.Info("Adding fish to the yield data.", "MissionBase");

		if (m_gebsConfig && m_gebsConfig.Fish && m_gebsConfig.Fish.Species) {
			geb_YieldFishGeneric fishYield;
			foreach (FishConf f : m_gebsConfig.Fish.Species) {
				if (f && f.Classname != "") {
					// The int (catch probability) is REQUIRED by the vanilla base
					// constructor (FishYieldItemBase) -- it's the weight the bank
					// uses for selection. The rest of the row rides in via SetConf.
					fishYield = new geb_YieldFishGeneric(f.CatchProbability);
					fishYield.SetConf(f);
					bank.RegisterYieldItem(fishYield);
				}
			}
		}

		GebsfishLogger.Info("Registering fish complete.", "MissionBase");
	}

	protected void RegisterJunkYieldData(CatchYieldBank bank) {
		// Same graceful exit RegisterFishYieldData uses -- without it, a
		// config that failed to load crashes the server here at mission init
		// instead of logging and disabling junk catches.
		if (!m_gebsConfig) {
			GebsfishLogger.Error("Gebsfish config was missing. Skipping junk yield registration.", "MissionBase");
			return;
		}

		GebsfishLogger.Info("Adding junk to the yield data.", "MissionBase");

		int i;
		if (m_gebsConfig.Junk && m_gebsConfig.Junk.Junk)
		{
			JunkEntry junkItem;
			for (i = 0; i < m_gebsConfig.Junk.Junk.Count(); i++)
			{
				junkItem = m_gebsConfig.Junk.Junk[i];
				if (!junkItem || junkItem.Classname == "")
					continue;

				YieldItemJunk junkYield = new YieldItemJunk(junkItem.CatchProbability, junkItem.Classname);
				junkYield.GebSetHealthLevelRange(junkItem.MinHealthLevel, junkItem.MaxHealthLevel);
				bank.RegisterYieldItem(junkYield);
			}
		}

		if (m_gebsConfig.Junk && m_gebsConfig.Junk.ContainerJunk)
		{
			ContainerJunkEntry containerJunkItem;
			for (i = 0; i < m_gebsConfig.Junk.ContainerJunk.Count(); i++)
			{
				containerJunkItem = m_gebsConfig.Junk.ContainerJunk[i];
				if (!containerJunkItem || containerJunkItem.Classname == "")
					continue;

				YieldItemJunkEmpty containerJunkYield = new YieldItemJunkEmpty(containerJunkItem.CatchProbability, containerJunkItem.Classname);
				containerJunkYield.GebSetHealthLevelRange(containerJunkItem.MinHealthLevel, containerJunkItem.MaxHealthLevel);
				bank.RegisterYieldItem(containerJunkYield);
			}
		}

		GebsfishLogger.Info("Registering junk items complete.", "MissionBase");
	}

	protected void RegisterTrapAnimalYieldData(CatchYieldBank bank) {
		bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
		bank.RegisterYieldItem(new YieldItemDeadRooster(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
		bank.RegisterYieldItem(new YieldItemDeadFox(2));
	}
};
