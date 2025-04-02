/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/


modded class MissionBase{

    override void InitWorldYieldDataDefaults(CatchYieldBank bank){
        super.InitWorldYieldDataDefaults(bank);
		
		if (bank)
		{	
			
			if(gebsMissionLoaded == true) {
				//Print("[gebsfish] missionbase load");
				GetGebSettingsConfig();

				bank.ClearAllRegisteredItems();
				//Initialize yield data
				Print("[gebsfish] [INIT] Initializing yield data.");
				//start loading fish data
				Print("[gebsfish] [FISH] Adding fish to yield data");
				//fishies
				if (m_gebsConfig.Carp.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemCarp(m_gebsConfig.Carp.CatchProbability));
					Print("[gebsfish] Carp are catchable.");
				}
				if (m_gebsConfig.Mackerel.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemMackerel(m_gebsConfig.Mackerel.CatchProbability));
					Print("[gebsfish] Mackerel are catchable.");
				}
				if (m_gebsConfig.Sardines.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemSardines(m_gebsConfig.Sardines.CatchProbability));
					Print("[gebsfish] Sardines are catchable.");
				}
				if (m_gebsConfig.Bitterlings.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemBitterlings(m_gebsConfig.Bitterlings.CatchProbability));
					Print("[gebsfish] Bitterlings are catchable.");
				}
				if (m_gebsConfig.WalleyePollock.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemWalleyePollock(m_gebsConfig.WalleyePollock.CatchProbability));
					Print("[gebsfish] Pollock are catchable.");
				}
				if (m_gebsConfig.SteelheadTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemSteelheadTrout(m_gebsConfig.SteelheadTrout.CatchProbability));
					Print("[gebsfish] Steelhead Trout are catchable.");
				}
				if (m_gebsConfig.Shrimp.CatchProbability != 0){
					bank.RegisterYieldItem(new YieldItemShrimp(m_gebsConfig.Shrimp.CatchProbability));
					Print("[gebsfish] Shrimp are catchable.");
				}
				if (m_gebsConfig.NorthernPike.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldNorthernPike(m_gebsConfig.NorthernPike.CatchProbability));
					Print("[gebsfish] Northern Pike are catchable.");
				}
				if (m_gebsConfig.LargeMouthBass.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldLargeMouthBass(m_gebsConfig.LargeMouthBass.CatchProbability));
					Print("[gebsfish] Largemouth Bass are catchable.");
				}
				if (m_gebsConfig.SmallMouthBass.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldSmallMouthBass(m_gebsConfig.SmallMouthBass.CatchProbability));
					Print("[gebsfish] Smallmouth Bass are catchable.");
				}
				if (m_gebsConfig.WallEye.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldWallEye(m_gebsConfig.WallEye.CatchProbability));
					Print("[gebsfish] Walleye are catchable.");
				}
				if (m_gebsConfig.SunFish.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldSunFish(m_gebsConfig.SunFish.CatchProbability));
					Print("[gebsfish] Sunfish are catchable.");
				}
				if (m_gebsConfig.WhiteBass.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldWhiteBass(m_gebsConfig.WhiteBass.CatchProbability));
					Print("[gebsfish] White Bass are catchable.");
				}
				if (m_gebsConfig.BlackBass.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldBlackBass(m_gebsConfig.BlackBass.CatchProbability));
					Print("[gebsfish] Black Bass are catchable.");
				}
				if (m_gebsConfig.RainbowTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldRainbowTrout(m_gebsConfig.RainbowTrout.CatchProbability));
					Print("[gebsfish] Rainbow Trout are catchable.");
				}
				if (m_gebsConfig.BrownTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldBrownTrout(m_gebsConfig.BrownTrout.CatchProbability));
					Print("[gebsfish] Brown Trout are catchable.");
				}
				if (m_gebsConfig.BrookTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldBrookTrout(m_gebsConfig.BrookTrout.CatchProbability));
					Print("[gebsfish] Brook Trout are catchable.");
				}
				if (m_gebsConfig.LakeTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldLakeTrout(m_gebsConfig.LakeTrout.CatchProbability));
					Print("[gebsfish] Lake Trout are catchable.");
				}
				if (m_gebsConfig.CutThroatTrout.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldCutThroatTrout(m_gebsConfig.CutThroatTrout.CatchProbability));
					Print("[gebsfish] Cutthroat Trout are catchable.");
				}
				if (m_gebsConfig.YellowPerch.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldYellowPerch(m_gebsConfig.YellowPerch.CatchProbability));
					Print("[gebsfish] Perch are catchable.");
				}
				if (m_gebsConfig.FlatHeadCatFish.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldFlatHeadCatFish(m_gebsConfig.FlatHeadCatFish.CatchProbability));
					Print("[gebsfish] Catfish are catchable.");
				}
				if (m_gebsConfig.FatHeadMinnow.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldMinnow(m_gebsConfig.FatHeadMinnow.CatchProbability));
					Print("[gebsfish] Minnow are catchable.");
				}
				if (m_gebsConfig.BlueGill.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldBlueGill(m_gebsConfig.BlueGill.CatchProbability));
					Print("[gebsfish] Bluegill are catchable.");
				}
				if (m_gebsConfig.Sauger.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldSauger(m_gebsConfig.Sauger.CatchProbability));
					Print("[gebsfish] Sauger are catchable.");
				}
				if (m_gebsConfig.BowFin.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldBowFin(m_gebsConfig.BowFin.CatchProbability));
					Print("[gebsfish] Bowfin are catchable.");
				}
				if (m_gebsConfig.SlimySculpin.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldSlimySculpin(m_gebsConfig.SlimySculpin.CatchProbability));
					Print("[gebsfish] Slimy Sculpin are catchable.");
				}
				if (m_gebsConfig.Severum.CatchProbability != 0){
					bank.RegisterYieldItem(new geb_YieldSeverum(m_gebsConfig.Severum.CatchProbability));
					Print("[gebsfish] Severum are catchable.");
				}
				if (m_gebsConfig.CrayFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldCrayFish(m_gebsConfig.CrayFish.CatchProbability));
					Print("[gebsfish] Crayfish are catchable.");
				}
				if (m_gebsConfig.MahiMahi.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldMahiMahi(m_gebsConfig.MahiMahi.CatchProbability));
					Print("[gebsfish] Mahimahi are catchable.");
				}
				if (m_gebsConfig.SailFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldSailFish(m_gebsConfig.SailFish.CatchProbability));
					Print("[gebsfish] Sailfish are catchable.");
				}
				if (m_gebsConfig.AngelFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldAngelFish(m_gebsConfig.AngelFish.CatchProbability));
					Print("[gebsfish] Angelfish are catchable.");
				}
				if (m_gebsConfig.AsianSeaBass.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldAsianSeaBass(m_gebsConfig.AsianSeaBass.CatchProbability));
					Print("[gebsfish] Asian Sea Bass are catchable.");
				}
				if (m_gebsConfig.AtlanticBlueMarlin.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldAtlanticBlueMarlin(m_gebsConfig.AtlanticBlueMarlin.CatchProbability));
					Print("[gebsfish] Blue Marlin are catchable.");
				}
				if (m_gebsConfig.Bonita.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldBonita(m_gebsConfig.Bonita.CatchProbability));
					Print("[gebsfish] Bonita are catchable.");
				}
				if (m_gebsConfig.CherrySalmon.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldCherrySalmon(m_gebsConfig.CherrySalmon.CatchProbability));
					Print("[gebsfish] Cherry Salmon are catchable.");
				}
				if (m_gebsConfig.ChinookSalmon.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldChinookSalmon(m_gebsConfig.ChinookSalmon.CatchProbability));
					Print("[gebsfish] Chinook Salmon are catchable.");
				}
				if (m_gebsConfig.SockEyeSalmon.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldSockEyeSalmon(m_gebsConfig.SockEyeSalmon.CatchProbability));
					Print("[gebsfish] Sockeye Salmon are catchable.");
				}
				if (m_gebsConfig.FlatHeadMullet.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldFlatHeadMullet(m_gebsConfig.FlatHeadMullet.CatchProbability));
					Print("[gebsfish] Flathead Mullet are catchable.");
				}
				if (m_gebsConfig.LeopardShark.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldLeopardShark(m_gebsConfig.LeopardShark.CatchProbability));
					Print("[gebsfish] Leopard Shark are catchable.");
				}
				if (m_gebsConfig.PacificCod.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldPacificCod(m_gebsConfig.PacificCod.CatchProbability));
					Print("[gebsfish] Pacific Cod are catchable.");
				}
				if (m_gebsConfig.RedHeadCichlid.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldRedHeadCichlid(m_gebsConfig.RedHeadCichlid.CatchProbability));
					Print("[gebsfish] Redhead Cichlid are catchable.");
				}
				if (m_gebsConfig.RoughNeckRock.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldRoughNeckRock(m_gebsConfig.RoughNeckRock.CatchProbability));
					Print("[gebsfish] Roughneck Rock are catchable.");
				}
				if (m_gebsConfig.BlueTang.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldBluetang(m_gebsConfig.BlueTang.CatchProbability));
					Print("[gebsfish] Blue Tang are catchable.");
				}
				if (m_gebsConfig.LargeHeadHairTailFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldLargeHeadHairTailFish(m_gebsConfig.LargeHeadHairTailFish.CatchProbability));
					Print("[gebsfish] Hairtail Fish are catchable.");
				}
				if (m_gebsConfig.HumpHeadWrasse.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldHumpHeadWrasse(m_gebsConfig.HumpHeadWrasse.CatchProbability));
					Print("[gebsfish] Humphead Wrasse are catchable.");
				}
				if (m_gebsConfig.SiameseTigerFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldSiameseTigerFish(m_gebsConfig.SiameseTigerFish.CatchProbability));
					Print("[gebsfish] Siamese Tiger fish are catchable.");
				}
				if (m_gebsConfig.GreatWhiteShark.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldGreatWhiteShark(m_gebsConfig.GreatWhiteShark.CatchProbability));
					Print("[gebsfish] Great White Shark are catchable.");
				}
				if (m_gebsConfig.AngelShark.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldAngelShark(m_gebsConfig.AngelShark.CatchProbability));
					Print("[gebsfish] Angel Shark are catchable.");
				}
				if (m_gebsConfig.YellowFinTuna.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldYellowFinTuna(m_gebsConfig.YellowFinTuna.CatchProbability));
					Print("[gebsfish] Yellowfin Tuna are catchable.");
				}
				if (m_gebsConfig.BloodClam.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldBloodClam(m_gebsConfig.BloodClam.CatchProbability));
					Print("[gebsfish] Blood Clam are catchable.");
				}
				if (m_gebsConfig.Mussel.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldMussel(m_gebsConfig.Mussel.CatchProbability));
					Print("[gebsfish] Mussel are catchable.");
				}
				if (m_gebsConfig.BlackDevilSnail.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldBlackDevilSnail(m_gebsConfig.BlackDevilSnail.CatchProbability));
					Print("[gebsfish] Black Devil Snail are catchable.");
				}
				if (m_gebsConfig.StarFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldStarFish(m_gebsConfig.StarFish.CatchProbability));
					Print("[gebsfish] Starfish are catchable.");
				}
				if (m_gebsConfig.KingCrab.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldKingCrab(m_gebsConfig.KingCrab.CatchProbability));
					Print("[gebsfish] King Crab are catchable.");
				}
				if (m_gebsConfig.BlueJellyFish.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldJellyFish(m_gebsConfig.BlueJellyFish.CatchProbability));
					Print("[gebsfish] Blue Jellyfish are catchable.");
				}
				if (m_gebsConfig.Lobster.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldLobster(m_gebsConfig.Lobster.CatchProbability));
					Print("[gebsfish] Lobster are catchable.");
				}
				if (m_gebsConfig.BlueLobster.CatchProbability != 0) {
					bank.RegisterYieldItem(new geb_YieldBlueLobster(m_gebsConfig.BlueLobster.CatchProbability));
					Print("[gebsfish] Blue Lobster are catchable.");
				}
				
				//finished loading fish data
				Print("[gebsfish] [FISH] Loading fish complete.");

				//start loading junk data
				Print("[gebsfish] [JUNK] Adding junk to yield data.");

				foreach(string junk: m_gebsConfig.Junk.Classnames){
					Print("[gebsfish] " + junk + " is catchable as junk.");
					bank.RegisterYieldItem(new YieldItemJunk(1,junk));
				}

				foreach(string containerjunk: m_gebsConfig.ContainerJunk.Classnames){
					Print("[gebsfish] " + containerjunk + " is catchable as junk.");
					bank.RegisterYieldItem(new YieldItemJunkEmpty(1,junk));
				}
				
				//finished loading junk data
				Print("[gebsfish] [JUNK] Loading junk complete.");
			
				//load animal yeilds for traps (snare)
				bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
				bank.RegisterYieldItem(new YieldItemDeadRooster(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
				bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
				bank.RegisterYieldItem(new YieldItemDeadFox(2));

				Print("[gebsfish] [INIT] Initialization of yield data complete.");

			}
			gebsMissionLoaded = true;
		}
	}

};