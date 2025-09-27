/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/


modded class MissionBase{ //Original

    override void InitWorldYieldDataDefaults(CatchYieldBank bank){
        super.InitWorldYieldDataDefaults(bank);
		
		if (bank)
		{	

				GetGebSettingsConfig();

				bank.ClearAllRegisteredItems();
				//Initialize yield data
				GebsfishLogger.Info("Initializing yield data.", "MissionBase");

				//start loading fish data
				GebsfishLogger.Info("Adding fish to the yield data.", "MissionBase");

				//fishies
				bank.RegisterYieldItem(new geb_YieldCarp(m_gebsConfig.Carp.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldMackerel(m_gebsConfig.Mackerel.CatchProbability));


				bank.RegisterYieldItem(new geb_YieldSardines(m_gebsConfig.Sardines.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBitterlings(m_gebsConfig.Bitterlings.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldWalleyePollock(m_gebsConfig.WalleyePollock.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSteelheadTrout(m_gebsConfig.SteelheadTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldShrimp(m_gebsConfig.Shrimp.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldNorthernPike(m_gebsConfig.NorthernPike.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldLargeMouthBass(m_gebsConfig.LargeMouthBass.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSmallMouthBass(m_gebsConfig.SmallMouthBass.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldWallEye(m_gebsConfig.WallEye.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSunFish(m_gebsConfig.SunFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldWhiteBass(m_gebsConfig.WhiteBass.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBlackBass(m_gebsConfig.BlackBass.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldRainbowTrout(m_gebsConfig.RainbowTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBrownTrout(m_gebsConfig.BrownTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBrookTrout(m_gebsConfig.BrookTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldLakeTrout(m_gebsConfig.LakeTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldCutThroatTrout(m_gebsConfig.CutThroatTrout.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldYellowPerch(m_gebsConfig.YellowPerch.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldFlatHeadCatFish(m_gebsConfig.FlatHeadCatFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldFatHeadMinnow(m_gebsConfig.FatHeadMinnow.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBlueGill(m_gebsConfig.BlueGill.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSauger(m_gebsConfig.Sauger.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBowFin(m_gebsConfig.BowFin.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSlimySculpin(m_gebsConfig.SlimySculpin.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSeverum(m_gebsConfig.Severum.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSignalCrayFish(m_gebsConfig.SignalCrayFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldEuropeanCrayFish(m_gebsConfig.EuropeanCrayFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldMahiMahi(m_gebsConfig.MahiMahi.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAtlanticSailFish(m_gebsConfig.AtlanticSailFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAngelFish(m_gebsConfig.AngelFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAsianSeaBass(m_gebsConfig.AsianSeaBass.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAtlanticBlueMarlin(m_gebsConfig.AtlanticBlueMarlin.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBonita(m_gebsConfig.Bonita.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldCherrySalmon(m_gebsConfig.CherrySalmon.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldChinookSalmon(m_gebsConfig.ChinookSalmon.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSockEyeSalmon(m_gebsConfig.SockEyeSalmon.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldFlatHeadMullet(m_gebsConfig.FlatHeadMullet.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldLeopardShark(m_gebsConfig.LeopardShark.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldPacificCod(m_gebsConfig.PacificCod.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldRedHeadCichlid(m_gebsConfig.RedHeadCichlid.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldRoughNeckRock(m_gebsConfig.RoughNeckRock.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBlueTang(m_gebsConfig.BlueTang.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldLargeHeadHairTailFish(m_gebsConfig.LargeHeadHairTailFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldHumpHeadWrasse(m_gebsConfig.HumpHeadWrasse.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSiameseTigerFish(m_gebsConfig.SiameseTigerFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldGreatWhiteShark(m_gebsConfig.GreatWhiteShark.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAngelShark(m_gebsConfig.AngelShark.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldYellowFinTuna(m_gebsConfig.YellowFinTuna.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBloodClam(m_gebsConfig.BloodClam.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldMussel(m_gebsConfig.Mussel.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBlackDevilSnail(m_gebsConfig.BlackDevilSnail.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldStarFish(m_gebsConfig.StarFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldKingCrab(m_gebsConfig.KingCrab.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldSnowCrab(m_gebsConfig.SnowCrab.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldBlueJellyFish(m_gebsConfig.BlueJellyFish.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldAmericanLobster(m_gebsConfig.AmericanLobster.CatchProbability));

				bank.RegisterYieldItem(new geb_YieldEuropeanLobster(m_gebsConfig.EuropeanLobster.CatchProbability));
				
				//finished loading fish data
				GebsfishLogger.Info("Registering fish complete.", "MissionBase");

				//start loading junk data
				GebsfishLogger.Info("Adding junk to the yield data.", "MissionBase");

				for (int i = 0; i < m_gebsConfig.Junk.Count(); i++){
					JunkEntry junkItem = m_gebsConfig.Junk[i];
					bank.RegisterYieldItem(new YieldItemJunk(junkItem.CatchProbability, junkItem.Classname));
				}
				
				for (int i1 = 0; i1 < m_gebsConfig.ContainerJunk.Count(); i1++){
					ContainerJunkEntry containerjunkItem = m_gebsConfig.ContainerJunk[i1];
					bank.RegisterYieldItem(new YieldItemJunkEmpty(containerjunkItem.CatchProbability, containerjunkItem.Classname));
				}


				//finished loading junk data
				GebsfishLogger.Info("Registering junk items complete.", "MissionBase");
			
				//load animal yeilds for traps (snare)
				bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
				bank.RegisterYieldItem(new YieldItemDeadRooster(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
				bank.RegisterYieldItem(new YieldItemDeadFox(2));

				GebsfishLogger.Info("Initialization of yield data complete.", "MissionBase");
			
		}
	}

}; 


// modded class MissionBase{

//     override void InitWorldYieldDataDefaults(CatchYieldBank bank){
//         super.InitWorldYieldDataDefaults(bank);
		
// 		if (bank)
// 		{	
// 			GetGebSettingsConfig();

// 			bank.ClearAllRegisteredItems();
// 			//Initialize yield data
// 			GebsfishLogger.Info("Initializing yield data.", "MissionBase");

// 			//start loading fish data
// 			GebsfishLogger.Info("Adding fish to the yield data.", "MissionBase");

// 			//fishies

// 				bank.RegisterYieldItem(new geb_YieldCarp(15));

// 				bank.RegisterYieldItem(new geb_YieldMackerel(15));

// 				bank.RegisterYieldItem(new geb_YieldSardines(15));

// 				bank.RegisterYieldItem(new geb_YieldBitterlings(15));

// 				bank.RegisterYieldItem(new geb_YieldWalleyePollock(15));

// 				bank.RegisterYieldItem(new geb_YieldSteelheadTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldShrimp(15));

// 				bank.RegisterYieldItem(new geb_YieldNorthernPike(15));

// 				bank.RegisterYieldItem(new geb_YieldLargeMouthBass(15));

// 				bank.RegisterYieldItem(new geb_YieldSmallMouthBass(15));

// 				bank.RegisterYieldItem(new geb_YieldWallEye(15));

// 				bank.RegisterYieldItem(new geb_YieldSunFish(15));

// 				bank.RegisterYieldItem(new geb_YieldWhiteBass(15));

// 				bank.RegisterYieldItem(new geb_YieldBlackBass(15));

// 				bank.RegisterYieldItem(new geb_YieldRainbowTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldBrownTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldBrookTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldLakeTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldCutThroatTrout(15));

// 				bank.RegisterYieldItem(new geb_YieldYellowPerch(15));

// 				bank.RegisterYieldItem(new geb_YieldFlatHeadCatFish(15));

// 				bank.RegisterYieldItem(new geb_YieldFatHeadMinnow(15));

// 				bank.RegisterYieldItem(new geb_YieldBlueGill(15));

// 				bank.RegisterYieldItem(new geb_YieldSauger(15));

// 				bank.RegisterYieldItem(new geb_YieldBowFin(15));

// 				bank.RegisterYieldItem(new geb_YieldSlimySculpin(15));

// 				bank.RegisterYieldItem(new geb_YieldSeverum(15));

// 				bank.RegisterYieldItem(new geb_YieldSignalCrayFish(15));

// 				bank.RegisterYieldItem(new geb_YieldEuropeanCrayFish(15));

// 				bank.RegisterYieldItem(new geb_YieldMahiMahi(15));

// 				bank.RegisterYieldItem(new geb_YieldAtlanticSailFish(15));

// 				bank.RegisterYieldItem(new geb_YieldAngelFish(15));

// 				bank.RegisterYieldItem(new geb_YieldAsianSeaBass(15));

// 				bank.RegisterYieldItem(new geb_YieldAtlanticBlueMarlin(15));

// 				bank.RegisterYieldItem(new geb_YieldBonita(15));

// 				bank.RegisterYieldItem(new geb_YieldCherrySalmon(15));

// 				bank.RegisterYieldItem(new geb_YieldChinookSalmon(15));

// 				bank.RegisterYieldItem(new geb_YieldSockEyeSalmon(15));

// 				bank.RegisterYieldItem(new geb_YieldFlatHeadMullet(15));

// 				bank.RegisterYieldItem(new geb_YieldLeopardShark(15));

// 				bank.RegisterYieldItem(new geb_YieldPacificCod(15));

// 				bank.RegisterYieldItem(new geb_YieldRedHeadCichlid(15));

// 				bank.RegisterYieldItem(new geb_YieldRoughNeckRock(15));

// 				bank.RegisterYieldItem(new geb_YieldBlueTang(15));

// 				bank.RegisterYieldItem(new geb_YieldLargeHeadHairTailFish(15));

// 				bank.RegisterYieldItem(new geb_YieldHumpHeadWrasse(15));

// 				bank.RegisterYieldItem(new geb_YieldSiameseTigerFish(15));

// 				bank.RegisterYieldItem(new geb_YieldGreatWhiteShark(15));

// 				bank.RegisterYieldItem(new geb_YieldAngelShark(15));

// 				bank.RegisterYieldItem(new geb_YieldYellowFinTuna(15));

// 				bank.RegisterYieldItem(new geb_YieldBloodClam(15));

// 				bank.RegisterYieldItem(new geb_YieldMussel(15));

// 				bank.RegisterYieldItem(new geb_YieldBlackDevilSnail(15));

// 				bank.RegisterYieldItem(new geb_YieldStarFish(15));

// 				bank.RegisterYieldItem(new geb_YieldKingCrab(15));

// 				bank.RegisterYieldItem(new geb_YieldSnowCrab(15));

// 				bank.RegisterYieldItem(new geb_YieldBlueJellyFish(15));

// 				bank.RegisterYieldItem(new geb_YieldAmericanLobster(15));

// 				bank.RegisterYieldItem(new geb_YieldEuropeanLobster(15));

			
// 			//finished loading fish data
// 			GebsfishLogger.Info("Registering fish coimplete.", "MissionBase");

// 			//start loading junk data
// 			GebsfishLogger.Info("Adding junk to the yield data.", "MissionBase");

// 			// for (int i = 0; i < m_gebsConfig.Junk.Count(); i++){
// 			// 	JunkEntry junkItem = m_gebsConfig.Junk[i];
// 			// 	bank.RegisterYieldItem(new YieldItemJunk(junkItem.CatchProbability, junkItem.Classname));
// 			// }
			
// 			// for (int i1 = 0; i1 < m_gebsConfig.ContainerJunk.Count(); i1++){
// 			// 	ContainerJunkEntry containerjunkItem = m_gebsConfig.ContainerJunk[i1];
// 			// 	bank.RegisterYieldItem(new YieldItemJunkEmpty(containerjunkItem.CatchProbability, containerjunkItem.Classname));
// 			// }


// 			//finished loading junk data
// 			GebsfishLogger.Info("Registering junk items complete.", "MissionBase");
		
// 			//load animal yeilds for traps (snare)
// 			bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
// 			bank.RegisterYieldItem(new YieldItemDeadRooster(1));
// 			bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
// 			bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
// 			bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
// 			bank.RegisterYieldItem(new YieldItemDeadFox(2));

// 			GebsfishLogger.Info("Initialization of yield data complete.", "MissionBase");
// 		}
// 	}

// };