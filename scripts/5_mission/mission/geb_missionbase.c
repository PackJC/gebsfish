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

		RegisterFreshwaterFish(bank);
		RegisterFreshwaterCrustaceans(bank);
		RegisterSaltwaterFish(bank);
		RegisterSaltwaterCrustaceans(bank);

		GebsfishLogger.Info("Registering fish complete.", "MissionBase");
	}

	protected void RegisterFreshwaterFish(CatchYieldBank bank) {
		if (m_gebsConfig.Carp) {
			bank.RegisterYieldItem(new geb_YieldCarp(m_gebsConfig.Carp.CatchProbability));
		}
		if (m_gebsConfig.Bitterlings) {
			bank.RegisterYieldItem(new geb_YieldBitterlings(m_gebsConfig.Bitterlings.CatchProbability));
		}
		if (m_gebsConfig.NorthernPike) {
			bank.RegisterYieldItem(new geb_YieldNorthernPike(m_gebsConfig.NorthernPike.CatchProbability));
		}
		if (m_gebsConfig.NorthernSnakeHead) {
			bank.RegisterYieldItem(new geb_YieldNorthernSnakeHead(m_gebsConfig.NorthernSnakeHead.CatchProbability));
		}
		if (m_gebsConfig.Muskellunge) {
			bank.RegisterYieldItem(new geb_YieldMuskellunge(m_gebsConfig.Muskellunge.CatchProbability));
		}
		if (m_gebsConfig.TigerMuskellunge) {
			bank.RegisterYieldItem(new geb_YieldTigerMuskellunge(m_gebsConfig.TigerMuskellunge.CatchProbability));
		}
		if (m_gebsConfig.SpottedMuskellunge) {
			bank.RegisterYieldItem(new geb_YieldSpottedMuskellunge(m_gebsConfig.SpottedMuskellunge.CatchProbability));
		}
		if (m_gebsConfig.BarredMuskellunge) {
			bank.RegisterYieldItem(new geb_YieldBarredMuskellunge(m_gebsConfig.BarredMuskellunge.CatchProbability));
		}
		if (m_gebsConfig.AlligatorGar) {
			bank.RegisterYieldItem(new geb_YieldAlligatorGar(m_gebsConfig.AlligatorGar.CatchProbability));
		}
		if (m_gebsConfig.LargeMouthBass) {
			bank.RegisterYieldItem(new geb_YieldLargeMouthBass(m_gebsConfig.LargeMouthBass.CatchProbability));
		}
		if (m_gebsConfig.SmallMouthBass) {
			bank.RegisterYieldItem(new geb_YieldSmallMouthBass(m_gebsConfig.SmallMouthBass.CatchProbability));
		}
		if (m_gebsConfig.WallEye) {
			bank.RegisterYieldItem(new geb_YieldWallEye(m_gebsConfig.WallEye.CatchProbability));
		}
		if (m_gebsConfig.SunFish) {
			bank.RegisterYieldItem(new geb_YieldSunFish(m_gebsConfig.SunFish.CatchProbability));
		}
		if (m_gebsConfig.WhiteBass) {
			bank.RegisterYieldItem(new geb_YieldWhiteBass(m_gebsConfig.WhiteBass.CatchProbability));
		}
		if (m_gebsConfig.BlackBass) {
			bank.RegisterYieldItem(new geb_YieldBlackBass(m_gebsConfig.BlackBass.CatchProbability));
		}
		if (m_gebsConfig.NeoshoBass) {
			bank.RegisterYieldItem(new geb_YieldNeoshoBass(m_gebsConfig.NeoshoBass.CatchProbability));
		}
		if (m_gebsConfig.StripedBass) {
			bank.RegisterYieldItem(new geb_YieldStripedBass(m_gebsConfig.StripedBass.CatchProbability));
		}
		if (m_gebsConfig.RainbowTrout) {
			bank.RegisterYieldItem(new geb_YieldRainbowTrout(m_gebsConfig.RainbowTrout.CatchProbability));
		}
		if (m_gebsConfig.BrownTrout) {
			bank.RegisterYieldItem(new geb_YieldBrownTrout(m_gebsConfig.BrownTrout.CatchProbability));
		}
		if (m_gebsConfig.BrookTrout) {
			bank.RegisterYieldItem(new geb_YieldBrookTrout(m_gebsConfig.BrookTrout.CatchProbability));
		}
		if (m_gebsConfig.LakeTrout) {
			bank.RegisterYieldItem(new geb_YieldLakeTrout(m_gebsConfig.LakeTrout.CatchProbability));
		}
		if (m_gebsConfig.CutThroatTrout) {
			bank.RegisterYieldItem(new geb_YieldCutThroatTrout(m_gebsConfig.CutThroatTrout.CatchProbability));
		}
		if (m_gebsConfig.LakeSturgeon) {
			bank.RegisterYieldItem(new geb_YieldLakeSturgeon(m_gebsConfig.LakeSturgeon.CatchProbability));
		}
		if (m_gebsConfig.YellowPerch) {
			bank.RegisterYieldItem(new geb_YieldYellowPerch(m_gebsConfig.YellowPerch.CatchProbability));
		}
		if (m_gebsConfig.FlatHeadCatFish) {
			bank.RegisterYieldItem(new geb_YieldFlatHeadCatFish(m_gebsConfig.FlatHeadCatFish.CatchProbability));
		}
		if (m_gebsConfig.FatHeadMinnow) {
			bank.RegisterYieldItem(new geb_YieldFatHeadMinnow(m_gebsConfig.FatHeadMinnow.CatchProbability));
		}
		if (m_gebsConfig.AmericanBullFrog) {
			bank.RegisterYieldItem(new geb_YieldAmericanBullFrog(m_gebsConfig.AmericanBullFrog.CatchProbability));
		}
		if (m_gebsConfig.RedSalamander) {
			bank.RegisterYieldItem(new geb_YieldRedSalamander(m_gebsConfig.RedSalamander.CatchProbability));
		}
		if (m_gebsConfig.BlueGill) {
			bank.RegisterYieldItem(new geb_YieldBlueGill(m_gebsConfig.BlueGill.CatchProbability));
		}
		if (m_gebsConfig.Sauger) {
			bank.RegisterYieldItem(new geb_YieldSauger(m_gebsConfig.Sauger.CatchProbability));
		}
		if (m_gebsConfig.BowFin) {
			bank.RegisterYieldItem(new geb_YieldBowFin(m_gebsConfig.BowFin.CatchProbability));
		}
		if (m_gebsConfig.SlimySculpin) {
			bank.RegisterYieldItem(new geb_YieldSlimySculpin(m_gebsConfig.SlimySculpin.CatchProbability));
		}
		if (m_gebsConfig.Severum) {
			bank.RegisterYieldItem(new geb_YieldSeverum(m_gebsConfig.Severum.CatchProbability));
		}
	}

	protected void RegisterFreshwaterCrustaceans(CatchYieldBank bank) {
		if (m_gebsConfig.SignalCrayFish) {
			bank.RegisterYieldItem(new geb_YieldSignalCrayFish(m_gebsConfig.SignalCrayFish.CatchProbability));
		}
		if (m_gebsConfig.EuropeanCrayFish) {
			bank.RegisterYieldItem(new geb_YieldEuropeanCrayFish(m_gebsConfig.EuropeanCrayFish.CatchProbability));
		}
		if (m_gebsConfig.CaveCrayFish) {
			bank.RegisterYieldItem(new geb_YieldCaveCrayFish(m_gebsConfig.CaveCrayFish.CatchProbability));
		}
		if (m_gebsConfig.FloridaCrayFish) {
			bank.RegisterYieldItem(new geb_YieldFloridaCrayFish(m_gebsConfig.FloridaCrayFish.CatchProbability));
		}
		if (m_gebsConfig.MonongahelaCrayFish) {
			bank.RegisterYieldItem(new geb_YieldMonongahelaCrayFish(m_gebsConfig.MonongahelaCrayFish.CatchProbability));
		}
		if (m_gebsConfig.RedSwampCrayFish) {
			bank.RegisterYieldItem(new geb_YieldRedSwampCrayFish(m_gebsConfig.RedSwampCrayFish.CatchProbability));
		}
		if (m_gebsConfig.RustyCrayFish) {
			bank.RegisterYieldItem(new geb_YieldRustyCrayFish(m_gebsConfig.RustyCrayFish.CatchProbability));
		}
	}

	protected void RegisterSaltwaterFish(CatchYieldBank bank) {
		if (m_gebsConfig.Mackerel) {
			bank.RegisterYieldItem(new geb_YieldMackerel(m_gebsConfig.Mackerel.CatchProbability));
		}
		if (m_gebsConfig.Sardines) {
			bank.RegisterYieldItem(new geb_YieldSardines(m_gebsConfig.Sardines.CatchProbability));
		}
		if (m_gebsConfig.WalleyePollock) {
			bank.RegisterYieldItem(new geb_YieldWalleyePollock(m_gebsConfig.WalleyePollock.CatchProbability));
		}
		if (m_gebsConfig.SteelheadTrout) {
			bank.RegisterYieldItem(new geb_YieldSteelheadTrout(m_gebsConfig.SteelheadTrout.CatchProbability));
		}
		if (m_gebsConfig.MahiMahi) {
			bank.RegisterYieldItem(new geb_YieldMahiMahi(m_gebsConfig.MahiMahi.CatchProbability));
		}
		if (m_gebsConfig.AtlanticSailFish) {
			bank.RegisterYieldItem(new geb_YieldAtlanticSailFish(m_gebsConfig.AtlanticSailFish.CatchProbability));
		}
		if (m_gebsConfig.AngelFish) {
			bank.RegisterYieldItem(new geb_YieldAngelFish(m_gebsConfig.AngelFish.CatchProbability));
		}
		if (m_gebsConfig.AsianSeaBass) {
			bank.RegisterYieldItem(new geb_YieldAsianSeaBass(m_gebsConfig.AsianSeaBass.CatchProbability));
		}
		if (m_gebsConfig.AtlanticBlueMarlin) {
			bank.RegisterYieldItem(new geb_YieldAtlanticBlueMarlin(m_gebsConfig.AtlanticBlueMarlin.CatchProbability));
		}
		if (m_gebsConfig.Bonita) {
			bank.RegisterYieldItem(new geb_YieldBonita(m_gebsConfig.Bonita.CatchProbability));
		}
		if (m_gebsConfig.CherrySalmon) {
			bank.RegisterYieldItem(new geb_YieldCherrySalmon(m_gebsConfig.CherrySalmon.CatchProbability));
		}
		if (m_gebsConfig.ChinookSalmon) {
			bank.RegisterYieldItem(new geb_YieldChinookSalmon(m_gebsConfig.ChinookSalmon.CatchProbability));
		}
		if (m_gebsConfig.SockEyeSalmon) {
			bank.RegisterYieldItem(new geb_YieldSockEyeSalmon(m_gebsConfig.SockEyeSalmon.CatchProbability));
		}
		if (m_gebsConfig.FlatHeadMullet) {
			bank.RegisterYieldItem(new geb_YieldFlatHeadMullet(m_gebsConfig.FlatHeadMullet.CatchProbability));
		}
		if (m_gebsConfig.LeopardShark) {
			bank.RegisterYieldItem(new geb_YieldLeopardShark(m_gebsConfig.LeopardShark.CatchProbability));
		}
		if (m_gebsConfig.HammerHeadShark) {
			bank.RegisterYieldItem(new geb_YieldHammerHeadShark(m_gebsConfig.HammerHeadShark.CatchProbability));
		}
		if (m_gebsConfig.PacificCod) {
			bank.RegisterYieldItem(new geb_YieldPacificCod(m_gebsConfig.PacificCod.CatchProbability));
		}
		if (m_gebsConfig.RedHeadCichlid) {
			bank.RegisterYieldItem(new geb_YieldRedHeadCichlid(m_gebsConfig.RedHeadCichlid.CatchProbability));
		}
		if (m_gebsConfig.RoughNeckRock) {
			bank.RegisterYieldItem(new geb_YieldRoughNeckRock(m_gebsConfig.RoughNeckRock.CatchProbability));
		}
		if (m_gebsConfig.BlueTang) {
			bank.RegisterYieldItem(new geb_YieldBlueTang(m_gebsConfig.BlueTang.CatchProbability));
		}
		if (m_gebsConfig.LargeHeadHairTailFish) {
			bank.RegisterYieldItem(new geb_YieldLargeHeadHairTailFish(m_gebsConfig.LargeHeadHairTailFish.CatchProbability));
		}
		if (m_gebsConfig.HumpHeadWrasse) {
			bank.RegisterYieldItem(new geb_YieldHumpHeadWrasse(m_gebsConfig.HumpHeadWrasse.CatchProbability));
		}
		if (m_gebsConfig.SiameseTigerFish) {
			bank.RegisterYieldItem(new geb_YieldSiameseTigerFish(m_gebsConfig.SiameseTigerFish.CatchProbability));
		}
		if (m_gebsConfig.GreatWhiteShark) {
			bank.RegisterYieldItem(new geb_YieldGreatWhiteShark(m_gebsConfig.GreatWhiteShark.CatchProbability));
		}
		if (m_gebsConfig.AngelShark) {
			bank.RegisterYieldItem(new geb_YieldAngelShark(m_gebsConfig.AngelShark.CatchProbability));
		}
		if (m_gebsConfig.YellowFinTuna) {
			bank.RegisterYieldItem(new geb_YieldYellowFinTuna(m_gebsConfig.YellowFinTuna.CatchProbability));
		}
		if (m_gebsConfig.WhiteGrunt) {
			bank.RegisterYieldItem(new geb_YieldWhiteGrunt(m_gebsConfig.WhiteGrunt.CatchProbability));
		}
		if (m_gebsConfig.YellowSnapper) {
			bank.RegisterYieldItem(new geb_YieldYellowSnapper(m_gebsConfig.YellowSnapper.CatchProbability));
		}
		if (m_gebsConfig.SouthernFlounder) {
			bank.RegisterYieldItem(new geb_YieldSouthernFlounder(m_gebsConfig.SouthernFlounder.CatchProbability));
		}
	}

	protected void RegisterSaltwaterCrustaceans(CatchYieldBank bank) {
		if (m_gebsConfig.Shrimp) {
			bank.RegisterYieldItem(new geb_YieldShrimp(m_gebsConfig.Shrimp.CatchProbability));
		}
		if (m_gebsConfig.BloodClam) {
			bank.RegisterYieldItem(new geb_YieldBloodClam(m_gebsConfig.BloodClam.CatchProbability));
		}
		if (m_gebsConfig.Mussel) {
			bank.RegisterYieldItem(new geb_YieldMussel(m_gebsConfig.Mussel.CatchProbability));
		}
		if (m_gebsConfig.BlackDevilSnail) {
			bank.RegisterYieldItem(new geb_YieldBlackDevilSnail(m_gebsConfig.BlackDevilSnail.CatchProbability));
		}
		if (m_gebsConfig.StarFish) {
			bank.RegisterYieldItem(new geb_YieldStarFish(m_gebsConfig.StarFish.CatchProbability));
		}
		if (m_gebsConfig.KingCrab) {
			bank.RegisterYieldItem(new geb_YieldKingCrab(m_gebsConfig.KingCrab.CatchProbability));
		}
		if (m_gebsConfig.SnowCrab) {
			bank.RegisterYieldItem(new geb_YieldSnowCrab(m_gebsConfig.SnowCrab.CatchProbability));
		}
		if (m_gebsConfig.BlueJellyFish) {
			bank.RegisterYieldItem(new geb_YieldBlueJellyFish(m_gebsConfig.BlueJellyFish.CatchProbability));
		}
		if (m_gebsConfig.AmericanLobster) {
			bank.RegisterYieldItem(new geb_YieldAmericanLobster(m_gebsConfig.AmericanLobster.CatchProbability));
		}
		if (m_gebsConfig.EuropeanLobster) {
			bank.RegisterYieldItem(new geb_YieldEuropeanLobster(m_gebsConfig.EuropeanLobster.CatchProbability));
		}
	}

	protected void RegisterJunkYieldData(CatchYieldBank bank) {
		GebsfishLogger.Info("Adding junk to the yield data.", "MissionBase");

		int i;
		if (m_gebsConfig.Junk)
		{
			JunkEntry junkItem;
			for (i = 0; i < m_gebsConfig.Junk.Count(); i++)
			{
				junkItem = m_gebsConfig.Junk[i];
				if (!junkItem || junkItem.Classname == "")
					continue;

				YieldItemJunk junkYield = new YieldItemJunk(junkItem.CatchProbability, junkItem.Classname);
				junkYield.GebSetHealthLevelRange(junkItem.MinHealthLevel, junkItem.MaxHealthLevel);
				bank.RegisterYieldItem(junkYield);
			}
		}

		if (m_gebsConfig.ContainerJunk)
		{
			ContainerJunkEntry containerJunkItem;
			for (i = 0; i < m_gebsConfig.ContainerJunk.Count(); i++)
			{
				containerJunkItem = m_gebsConfig.ContainerJunk[i];
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
