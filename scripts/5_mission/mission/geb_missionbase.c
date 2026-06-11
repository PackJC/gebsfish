/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class MissionBase {
	override void InitWorldYieldDataDefaults(CatchYieldBank bank) {
		super.InitWorldYieldDataDefaults(bank);

		if (!bank)
			return;

		GetGebSettingsConfig();

		bank.ClearAllRegisteredItems();

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
