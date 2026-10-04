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
	protected CatchYieldBank s_GebInitializedBank;
	protected gebsfishConfig m_GebRegisteredConfig;

	void MissionBase() {
		GebGetConfigReadyInvoker().Insert(GebOnConfigReceived);
		// Vanilla's constructor has built the world data, yield bank and all, by
		// now. A map whose WorldData clears the bank after the yield invoker has
		// run, and that gebsfish.c doesn't hook, has just wiped our yields; put
		// them back.
		GebRepairYieldBank();
	}

	protected void GebRepairYieldBank() {
		if (!m_WorldData)
			return;
		CatchYieldBank bank = m_WorldData.GetCatchYieldBank();
		if (!bank || bank.GebBlockIntact())
			return;
		GebsfishLogger.Info(m_WorldData.ClassName() + " left the mod's yields out of its catch list -- registering them again, ahead of the map's own.", "MissionBase");
		InitWorldYieldDataDefaults(bank);
	}

	// Second check once the mission is up (MissionServer and MissionGameplay
	// both call super here): another mod's mission constructor, running after
	// ours, can still have changed the bank.
	override void OnInit() {
		super.OnInit();
		GebRepairYieldBank();
	}

	void GebOnConfigReceived() {
		if (s_GebInitializedBank)
			InitWorldYieldDataDefaults(s_GebInitializedBank);
	}

	void ~MissionBase() {
		GebGetConfigReadyInvoker().Remove(GebOnConfigReceived);
		if (g_GebYieldBank == s_GebInitializedBank) {
			g_GebYieldBank = null;
			// The menu only holds the built-in defaults; drop them so the next
			// mission loads its own (the profile's files offline, the server's
			// copy online).
			if (!g_Game.IsServer() || IsInherited(MissionMainMenu)) {
				g_GebConfigReceived = false;
				m_gebsConfig = null;
			}
		}
	}

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
		// in server logs). Each registration rebuilds the bank, ours first
		// and everything already in it after (CatchYieldBank
		// GebBeginRegistration), so a repeat only redoes the same work. It
		// runs again when the config changed (a client receiving the
		// server's) or when our yields are no longer in the bank: a map that
		// clears it after this chain and fires the invoker again, as
		// third-party map fixes do.
		if (bank == s_GebInitializedBank && m_GebRegisteredConfig == m_gebsConfig && bank.GebBlockIntact()) {
			GebsfishLogger.Info("Yield data already initialized for this bank -- skipping duplicate init.", "MissionBase");
			return;
		}
		s_GebInitializedBank = bank;

		GetGebSettingsConfig();
		g_GebYieldBank = bank;
		m_GebRegisteredConfig = m_gebsConfig;
		bank.GebBeginRegistration();

		GebsfishLogger.Info("Initializing yield data.", "MissionBase");

		RegisterFishYieldData(bank);
		RegisterJunkYieldData(bank);
		RegisterTrapAnimalYieldData(bank);
		bank.GebEndRegistration();

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
				if (f && f.Classname != "" && !bank.GetYieldsMap().Contains(f.Classname.Hash())) {
					// The int (catch probability) is REQUIRED by the vanilla base
					// constructor (FishYieldItemBase) -- it's the weight the bank
					// uses for selection. The rest of the row rides in via SetConf.
					fishYield = new geb_YieldFishGeneric(f.CatchProbability);
					fishYield.SetConf(f);
					GebRegisterUniqueYield(bank, fishYield);
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
				if (!junkItem || junkItem.Classname == "" || !g_Game.ConfigIsExisting("CfgVehicles " + junkItem.Classname) || bank.GetYieldsMap().Contains(junkItem.Classname.Hash()))
					continue;

				YieldItemJunk junkYield = new YieldItemJunk(Math.Clamp(junkItem.CatchProbability, 0, 25), junkItem.Classname);
				junkYield.GebSetHealthLevelRange(junkItem.MinHealthLevel, junkItem.MaxHealthLevel);
				GebRegisterUniqueYield(bank, junkYield);
			}
		}

		if (m_gebsConfig.Junk && m_gebsConfig.Junk.ContainerJunk)
		{
			ContainerJunkEntry containerJunkItem;
			for (i = 0; i < m_gebsConfig.Junk.ContainerJunk.Count(); i++)
			{
				containerJunkItem = m_gebsConfig.Junk.ContainerJunk[i];
				if (!containerJunkItem || containerJunkItem.Classname == "" || !g_Game.ConfigIsExisting("CfgVehicles " + containerJunkItem.Classname) || bank.GetYieldsMap().Contains(containerJunkItem.Classname.Hash()))
					continue;

				YieldItemJunkEmpty containerJunkYield = new YieldItemJunkEmpty(Math.Clamp(containerJunkItem.CatchProbability, 0, 25), containerJunkItem.Classname);
				containerJunkYield.GebSetHealthLevelRange(containerJunkItem.MinHealthLevel, containerJunkItem.MaxHealthLevel);
				GebRegisterUniqueYield(bank, containerJunkYield);
			}
		}

		GebsfishLogger.Info("Registering junk items complete.", "MissionBase");
	}

    protected void GebRegisterUniqueYield(CatchYieldBank bank, YieldItemBase data) {
        if (!data || bank.GetYieldsMap().Contains(data.GetType().Hash()))
            return;
        bank.RegisterYieldItem(data);
    }

	// Vanilla's snare catches per map. Sakhal has no poultry and an even
	// rabbit/fox split (sakhal.c InitYieldBank), and so does Namalsk's own
	// list; Chernarus, Livonia and maps without their own list use the one
	// below. Keyed on the world name, not the WorldData class: the first
	// registration runs while the mission's WorldData is still being built,
	// and client and server must end up with the same list.
	protected void RegisterTrapAnimalYieldData(CatchYieldBank bank) {
		string worldName;
		g_Game.GetWorldName(worldName);
		worldName.ToLower();
		if (worldName == "sakhal" || worldName == "namalsk") {
			GebRegisterUniqueYield(bank, new YieldItemDeadRabbit(1));
			GebRegisterUniqueYield(bank, new YieldItemDeadFox(1));
			return;
		}

		GebRegisterUniqueYield(bank, new YieldItemDeadRabbit(4));
		GebRegisterUniqueYield(bank, new YieldItemDeadRooster(1));
		GebRegisterUniqueYield(bank, new YieldItemDeadChicken_White(1));
		GebRegisterUniqueYield(bank, new YieldItemDeadChicken_Spotted(1));
		GebRegisterUniqueYield(bank, new YieldItemDeadChicken_Brown(1));
		GebRegisterUniqueYield(bank, new YieldItemDeadFox(2));
	}
};
