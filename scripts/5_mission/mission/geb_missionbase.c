/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class MissionBase
{
	void RegisterFishYield<T>(CatchYieldBank bank, int catchProbability)
	{
		if (!bank || catchProbability <= 0)
			return;

		bank.RegisterYieldItem(new T(catchProbability));
	}

	void RegisterJunkYields(CatchYieldBank bank)
	{
		if (!bank || !m_gebsConfig)
			return;

		if (m_gebsConfig.Junk)
		{
			for (int i = 0; i < m_gebsConfig.Junk.Count(); i++)
			{
				JunkEntry junkItem = m_gebsConfig.Junk[i];
				if (!junkItem || junkItem.Classname == string.Empty || junkItem.CatchProbability <= 0)
					continue;

				bank.RegisterYieldItem(new YieldItemJunk(junkItem.CatchProbability, junkItem.Classname));
			}
		}

		if (m_gebsConfig.ContainerJunk)
		{
			for (int i1 = 0; i1 < m_gebsConfig.ContainerJunk.Count(); i1++)
			{
				ContainerJunkEntry containerJunkItem = m_gebsConfig.ContainerJunk[i1];
				if (!containerJunkItem || containerJunkItem.Classname == string.Empty || containerJunkItem.CatchProbability <= 0)
					continue;

				bank.RegisterYieldItem(new YieldItemJunkEmpty(containerJunkItem.CatchProbability, containerJunkItem.Classname));
			}
		}
	}

	void RegisterTrapYields(CatchYieldBank bank)
	{
		if (!bank)
			return;

		bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
		bank.RegisterYieldItem(new YieldItemDeadRooster(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
		bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
		bank.RegisterYieldItem(new YieldItemDeadFox(2));
	}

	override void InitWorldYieldDataDefaults(CatchYieldBank bank)
	{
		super.InitWorldYieldDataDefaults(bank);

		if (!bank)
			return;

		GetGebSettingsConfig();
		if (!m_gebsConfig)
		{
			GebsfishLogger.Error("m_gebsConfig is null. Yield data was not initialized.", "MissionBase");
			return;
		}

		bank.ClearAllRegisteredItems();

		GebsfishLogger.Info("Initializing yield data.", "MissionBase");
		GebsfishLogger.Info("Adding fish to the yield data.", "MissionBase");

		// ===== FRESHWATER FISH =====
		RegisterFishYield<geb_YieldCarp>(bank, m_gebsConfig.Carp.CatchProbability);
		RegisterFishYield<geb_YieldBitterlings>(bank, m_gebsConfig.Bitterlings.CatchProbability);
		RegisterFishYield<geb_YieldSteelheadTrout>(bank, m_gebsConfig.SteelheadTrout.CatchProbability);
		RegisterFishYield<geb_YieldNorthernPike>(bank, m_gebsConfig.NorthernPike.CatchProbability);
		RegisterFishYield<geb_YieldLargeMouthBass>(bank, m_gebsConfig.LargeMouthBass.CatchProbability);
		RegisterFishYield<geb_YieldSmallMouthBass>(bank, m_gebsConfig.SmallMouthBass.CatchProbability);
		RegisterFishYield<geb_YieldWallEye>(bank, m_gebsConfig.WallEye.CatchProbability);
		RegisterFishYield<geb_YieldSunFish>(bank, m_gebsConfig.SunFish.CatchProbability);
		RegisterFishYield<geb_YieldWhiteBass>(bank, m_gebsConfig.WhiteBass.CatchProbability);
		RegisterFishYield<geb_YieldBlackBass>(bank, m_gebsConfig.BlackBass.CatchProbability);
		RegisterFishYield<geb_YieldRainbowTrout>(bank, m_gebsConfig.RainbowTrout.CatchProbability);
		RegisterFishYield<geb_YieldBrownTrout>(bank, m_gebsConfig.BrownTrout.CatchProbability);
		RegisterFishYield<geb_YieldBrookTrout>(bank, m_gebsConfig.BrookTrout.CatchProbability);
		RegisterFishYield<geb_YieldLakeTrout>(bank, m_gebsConfig.LakeTrout.CatchProbability);
		RegisterFishYield<geb_YieldCutThroatTrout>(bank, m_gebsConfig.CutThroatTrout.CatchProbability);
		RegisterFishYield<geb_YieldYellowPerch>(bank, m_gebsConfig.YellowPerch.CatchProbability);
		RegisterFishYield<geb_YieldFlatHeadCatFish>(bank, m_gebsConfig.FlatHeadCatFish.CatchProbability);
		RegisterFishYield<geb_YieldFatHeadMinnow>(bank, m_gebsConfig.FatHeadMinnow.CatchProbability);
		RegisterFishYield<geb_YieldBlueGill>(bank, m_gebsConfig.BlueGill.CatchProbability);
		RegisterFishYield<geb_YieldSauger>(bank, m_gebsConfig.Sauger.CatchProbability);
		RegisterFishYield<geb_YieldBowFin>(bank, m_gebsConfig.BowFin.CatchProbability);
		RegisterFishYield<geb_YieldSlimySculpin>(bank, m_gebsConfig.SlimySculpin.CatchProbability);
		RegisterFishYield<geb_YieldCherrySalmon>(bank, m_gebsConfig.CherrySalmon.CatchProbability);
		RegisterFishYield<geb_YieldChinookSalmon>(bank, m_gebsConfig.ChinookSalmon.CatchProbability);
		RegisterFishYield<geb_YieldSockEyeSalmon>(bank, m_gebsConfig.SockEyeSalmon.CatchProbability);
		RegisterFishYield<geb_YieldSeverum>(bank, m_gebsConfig.Severum.CatchProbability);

		// ===== FRESHWATER CRUSTACEAN =====
		RegisterFishYield<geb_YieldSignalCrayFish>(bank, m_gebsConfig.SignalCrayFish.CatchProbability);
		RegisterFishYield<geb_YieldEuropeanCrayFish>(bank, m_gebsConfig.EuropeanCrayFish.CatchProbability);

		// ===== SALTWATER FISH =====
		RegisterFishYield<geb_YieldMackerel>(bank, m_gebsConfig.Mackerel.CatchProbability);
		RegisterFishYield<geb_YieldSardines>(bank, m_gebsConfig.Sardines.CatchProbability);
		RegisterFishYield<geb_YieldWalleyePollock>(bank, m_gebsConfig.WalleyePollock.CatchProbability);
		RegisterFishYield<geb_YieldMahiMahi>(bank, m_gebsConfig.MahiMahi.CatchProbability);
		RegisterFishYield<geb_YieldAtlanticSailFish>(bank, m_gebsConfig.AtlanticSailFish.CatchProbability);
		RegisterFishYield<geb_YieldAngelFish>(bank, m_gebsConfig.AngelFish.CatchProbability);
		RegisterFishYield<geb_YieldAsianSeaBass>(bank, m_gebsConfig.AsianSeaBass.CatchProbability);
		RegisterFishYield<geb_YieldAtlanticBlueMarlin>(bank, m_gebsConfig.AtlanticBlueMarlin.CatchProbability);
		RegisterFishYield<geb_YieldBonita>(bank, m_gebsConfig.Bonita.CatchProbability);
		RegisterFishYield<geb_YieldFlatHeadMullet>(bank, m_gebsConfig.FlatHeadMullet.CatchProbability);
		RegisterFishYield<geb_YieldLeopardShark>(bank, m_gebsConfig.LeopardShark.CatchProbability);
		RegisterFishYield<geb_YieldPacificCod>(bank, m_gebsConfig.PacificCod.CatchProbability);
		RegisterFishYield<geb_YieldRedHeadCichlid>(bank, m_gebsConfig.RedHeadCichlid.CatchProbability);
		RegisterFishYield<geb_YieldRoughNeckRock>(bank, m_gebsConfig.RoughNeckRock.CatchProbability);
		RegisterFishYield<geb_YieldBlueTang>(bank, m_gebsConfig.BlueTang.CatchProbability);
		RegisterFishYield<geb_YieldLargeHeadHairTailFish>(bank, m_gebsConfig.LargeHeadHairTailFish.CatchProbability);
		RegisterFishYield<geb_YieldHumpHeadWrasse>(bank, m_gebsConfig.HumpHeadWrasse.CatchProbability);
		RegisterFishYield<geb_YieldSiameseTigerFish>(bank, m_gebsConfig.SiameseTigerFish.CatchProbability);
		RegisterFishYield<geb_YieldGreatWhiteShark>(bank, m_gebsConfig.GreatWhiteShark.CatchProbability);
		RegisterFishYield<geb_YieldAngelShark>(bank, m_gebsConfig.AngelShark.CatchProbability);
		RegisterFishYield<geb_YieldYellowFinTuna>(bank, m_gebsConfig.YellowFinTuna.CatchProbability);

		// ===== SALTWATER CRUSTACEAN / MARINE INVERTEBRATES =====
		RegisterFishYield<geb_YieldShrimp>(bank, m_gebsConfig.Shrimp.CatchProbability);
		RegisterFishYield<geb_YieldBloodClam>(bank, m_gebsConfig.BloodClam.CatchProbability);
		RegisterFishYield<geb_YieldMussel>(bank, m_gebsConfig.Mussel.CatchProbability);
		RegisterFishYield<geb_YieldBlackDevilSnail>(bank, m_gebsConfig.BlackDevilSnail.CatchProbability);
		RegisterFishYield<geb_YieldStarFish>(bank, m_gebsConfig.StarFish.CatchProbability);
		RegisterFishYield<geb_YieldKingCrab>(bank, m_gebsConfig.KingCrab.CatchProbability);
		RegisterFishYield<geb_YieldSnowCrab>(bank, m_gebsConfig.SnowCrab.CatchProbability);
		RegisterFishYield<geb_YieldBlueJellyFish>(bank, m_gebsConfig.BlueJellyFish.CatchProbability);
		RegisterFishYield<geb_YieldAmericanLobster>(bank, m_gebsConfig.AmericanLobster.CatchProbability);
		RegisterFishYield<geb_YieldEuropeanLobster>(bank, m_gebsConfig.EuropeanLobster.CatchProbability);

		GebsfishLogger.Info("Registering fish complete.", "MissionBase");
		GebsfishLogger.Info("Adding junk to the yield data.", "MissionBase");

		RegisterJunkYields(bank);

		GebsfishLogger.Info("Registering junk items complete.", "MissionBase");

		RegisterTrapYields(bank);

		GebsfishLogger.Info("Initialization of yield data complete.", "MissionBase");
	}
};
