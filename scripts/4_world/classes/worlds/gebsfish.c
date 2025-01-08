class GebsFishData : WorldData {

    override void Init(){
        super.Init();
        Print("[gebsfish] [Init] Start load of data in World Data");
        GetGebSettingsConfig();
        Print("[gebsfish] [Init] End load of data in World Data");
    }

    override void InitYieldBank()
	{
		super.InitYieldBank();
		
		m_YieldBank.ClearAllRegisteredItems();
		Print("[gebsfish] [InitYieldBank] Initializing yield data.");
		Print("[gebsfish] [InitYieldBank] Initializing yield data.");
        //start loading fish data
        Print("[gebsfish] [InitYieldBank] Adding fish to yield data");
        //fishies
        if (m_gebsConfig.Carp.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemCarp(m_gebsConfig.Carp.CatchProbability));
            Print("[gebsfish] Carp are catchable.");
        }
        if (m_gebsConfig.Mackerel.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemMackerel(m_gebsConfig.Mackerel.CatchProbability));
            Print("[gebsfish] Mackerel are catchable.");
        }
        if (m_gebsConfig.Sardines.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemSardines(m_gebsConfig.Sardines.CatchProbability));
            Print("[gebsfish] Sardines are catchable.");
        }
        if (m_gebsConfig.Bitterlings.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemBitterlings(m_gebsConfig.Bitterlings.CatchProbability));
            Print("[gebsfish] Bitterlings are catchable.");
        }
        if (m_gebsConfig.WalleyePollock.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemWalleyePollock(m_gebsConfig.WalleyePollock.CatchProbability));
            Print("[gebsfish] Pollock are catchable.");
        }
        if (m_gebsConfig.SteelheadTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemSteelheadTrout(m_gebsConfig.SteelheadTrout.CatchProbability));
            Print("[gebsfish] Steelhead Trout are catchable.");
        }
        if (m_gebsConfig.Shrimp.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new YieldItemShrimp(m_gebsConfig.Shrimp.CatchProbability));
            Print("[gebsfish] Shrimp are catchable.");
        }
        if (m_gebsConfig.NorthernPike.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebNorthernpike(m_gebsConfig.NorthernPike.CatchProbability));
            Print("[gebsfish] Northern Pike are catchable.");
        }
        if (m_gebsConfig.LargemouthBass.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebLargemouthbass(m_gebsConfig.LargemouthBass.CatchProbability));
            Print("[gebsfish] Largemouth Bass are catchable.");
        }
        if (m_gebsConfig.SmallmouthBass.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebSmallmouthbass(m_gebsConfig.SmallmouthBass.CatchProbability));
            Print("[gebsfish] Smallmouth Bass are catchable.");
        }
        if (m_gebsConfig.Walleye.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebWalleye(m_gebsConfig.Walleye.CatchProbability));
            Print("[gebsfish] Walleye are catchable.");
        }
        if (m_gebsConfig.Sunfish.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebSunfish(m_gebsConfig.Sunfish.CatchProbability));
            Print("[gebsfish] Sunfish are catchable.");
        }
        if (m_gebsConfig.WhiteBass.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebWhitebass(m_gebsConfig.WhiteBass.CatchProbability));
            Print("[gebsfish] White Bass are catchable.");
        }
        if (m_gebsConfig.BlackBass.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebBlackbass(m_gebsConfig.BlackBass.CatchProbability));
            Print("[gebsfish] Black Bass are catchable.");
        }
        if (m_gebsConfig.RainbowTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebRainbowTrout(m_gebsConfig.RainbowTrout.CatchProbability));
            Print("[gebsfish] Rainbow Trout are catchable.");
        }
        if (m_gebsConfig.BrownTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebBrownTrout(m_gebsConfig.BrownTrout.CatchProbability));
            Print("[gebsfish] Brown Trout are catchable.");
        }
        if (m_gebsConfig.BrookTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebBrookTrout(m_gebsConfig.BrookTrout.CatchProbability));
            Print("[gebsfish] Brook Trout are catchable.");
        }
        if (m_gebsConfig.LakeTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebLakeTrout(m_gebsConfig.LakeTrout.CatchProbability));
            Print("[gebsfish] Lake Trout are catchable.");
        }
        if (m_gebsConfig.CutthroatTrout.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebCutthroatTrout(m_gebsConfig.CutthroatTrout.CatchProbability));
            Print("[gebsfish] Cutthroat Trout are catchable.");
        }
        if (m_gebsConfig.Perch.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebPerch(m_gebsConfig.Perch.CatchProbability));
            Print("[gebsfish] Perch are catchable.");
        }
        if (m_gebsConfig.Catfish.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebCatfish(m_gebsConfig.Catfish.CatchProbability));
            Print("[gebsfish] Catfish are catchable.");
        }
        if (m_gebsConfig.Minnow.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebMinnow(m_gebsConfig.Minnow.CatchProbability));
            Print("[gebsfish] Minnow are catchable.");
        }
        if (m_gebsConfig.Bluegill.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebBluegill(m_gebsConfig.Bluegill.CatchProbability));
            Print("[gebsfish] Bluegill are catchable.");
        }
        if (m_gebsConfig.Sauger.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebSauger(m_gebsConfig.Sauger.CatchProbability));
            Print("[gebsfish] Sauger are catchable.");
        }
        if (m_gebsConfig.Bowfin.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebBowfin(m_gebsConfig.Bowfin.CatchProbability));
            Print("[gebsfish] Bowfin are catchable.");
        }
        if (m_gebsConfig.SlimySculpin.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebSlimysculpin(m_gebsConfig.SlimySculpin.CatchProbability));
            Print("[gebsfish] Slimy Sculpin are catchable.");
        }
        if (m_gebsConfig.Severum.CatchProbability != 0){
            m_YieldBank.RegisterYieldItem(new gebSeverum(m_gebsConfig.Severum.CatchProbability));
            Print("[gebsfish] Severum are catchable.");
        }
        //chatgpt
        if (m_gebsConfig.Crayfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebCrayfish(m_gebsConfig.Crayfish.CatchProbability));
            Print("[gebsfish] Crayfish are catchable.");
        }
        if (m_gebsConfig.Mahimahi.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebMahimahi(m_gebsConfig.Mahimahi.CatchProbability));
            Print("[gebsfish] Mahimahi are catchable.");
        }
        if (m_gebsConfig.Sailfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebSailfish(m_gebsConfig.Sailfish.CatchProbability));
            Print("[gebsfish] Sailfish are catchable.");
        }
        if (m_gebsConfig.Angelfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebAngelfish(m_gebsConfig.Angelfish.CatchProbability));
            Print("[gebsfish] Angelfish are catchable.");
        }
        if (m_gebsConfig.AsianSeaBass.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebAsianseabass(m_gebsConfig.AsianSeaBass.CatchProbability));
            Print("[gebsfish] Asian Sea Bass are catchable.");
        }
        if (m_gebsConfig.BlueMarlin.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBluemarlin(m_gebsConfig.BlueMarlin.CatchProbability));
            Print("[gebsfish] Blue Marlin are catchable.");
        }
        if (m_gebsConfig.Bonita.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBonita(m_gebsConfig.Bonita.CatchProbability));
            Print("[gebsfish] Bonita are catchable.");
        }
        if (m_gebsConfig.CherrySalmon.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebCherrysalmon(m_gebsConfig.CherrySalmon.CatchProbability));
            Print("[gebsfish] Cherry Salmon are catchable.");
        }
        if (m_gebsConfig.ChinookSalmon.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebChinooksalmon(m_gebsConfig.ChinookSalmon.CatchProbability));
            Print("[gebsfish] Chinook Salmon are catchable.");
        }
        if (m_gebsConfig.SockeyeSalmon.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebSockeyesalmon(m_gebsConfig.SockeyeSalmon.CatchProbability));
            Print("[gebsfish] Sockeye Salmon are catchable.");
        }
        if (m_gebsConfig.FlatheadMullet.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebFlatheadmullet(m_gebsConfig.FlatheadMullet.CatchProbability));
            Print("[gebsfish] Flathead Mullet are catchable.");
        }
        if (m_gebsConfig.LeopardShark.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebLeopardshark(m_gebsConfig.LeopardShark.CatchProbability));
            Print("[gebsfish] Leopard Shark are catchable.");
        }
        if (m_gebsConfig.PacificCod.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebPacificcod(m_gebsConfig.PacificCod.CatchProbability));
            Print("[gebsfish] Pacific Cod are catchable.");
        }
        if (m_gebsConfig.RedheadCichlid.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebRedheadcichlid(m_gebsConfig.RedheadCichlid.CatchProbability));
            Print("[gebsfish] Redhead Cichlid are catchable.");
        }
        if (m_gebsConfig.RoughneckRock.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebRoughneckrock(m_gebsConfig.RoughneckRock.CatchProbability));
            Print("[gebsfish] Roughneck Rock are catchable.");
        }
        if (m_gebsConfig.BlueTang.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBluetang(m_gebsConfig.BlueTang.CatchProbability));
            Print("[gebsfish] Blue Tang are catchable.");
        }
        if (m_gebsConfig.HairtailFish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebHairtailfish(m_gebsConfig.HairtailFish.CatchProbability));
            Print("[gebsfish] Hairtail Fish are catchable.");
        }
        if (m_gebsConfig.HumpheadWrasse.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebHumpheadwrasse(m_gebsConfig.HumpheadWrasse.CatchProbability));
            Print("[gebsfish] Humphead Wrasse are catchable.");
        }
        if (m_gebsConfig.SiameseTigerfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebSiamesetigerfish(m_gebsConfig.SiameseTigerfish.CatchProbability));
            Print("[gebsfish] Siamese Tiger fish are catchable.");
        }
        if (m_gebsConfig.GreatWhiteShark.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebGreatwhiteshark(m_gebsConfig.GreatWhiteShark.CatchProbability));
            Print("[gebsfish] Great White Shark are catchable.");
        }
        if (m_gebsConfig.AngelShark.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebAngelshark(m_gebsConfig.AngelShark.CatchProbability));
            Print("[gebsfish] Angel Shark are catchable.");
        }
        if (m_gebsConfig.YellowfinTuna.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebYellowfintuna(m_gebsConfig.YellowfinTuna.CatchProbability));
            Print("[gebsfish] Yellowfin Tuna are catchable.");
        }
        if (m_gebsConfig.BloodClam.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBloodclam(m_gebsConfig.BloodClam.CatchProbability));
            Print("[gebsfish] Blood Clam are catchable.");
        }
        if (m_gebsConfig.Mussel.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebMussel(m_gebsConfig.Mussel.CatchProbability));
            Print("[gebsfish] Mussel are catchable.");
        }
        if (m_gebsConfig.BlackDevilSnail.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBlackdevilsnail(m_gebsConfig.BlackDevilSnail.CatchProbability));
            Print("[gebsfish] Black Devil Snail are catchable.");
        }
        if (m_gebsConfig.Starfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebStarfish(m_gebsConfig.Starfish.CatchProbability));
            Print("[gebsfish] Starfish are catchable.");
        }
        if (m_gebsConfig.KingCrab.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebKingcrab(m_gebsConfig.KingCrab.CatchProbability));
            Print("[gebsfish] King Crab are catchable.");
        }
        if (m_gebsConfig.Jellyfish.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebJellyfish(m_gebsConfig.Jellyfish.CatchProbability));
            Print("[gebsfish] Jellyfish are catchable.");
        }
        if (m_gebsConfig.Lobster.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebLobster(m_gebsConfig.Lobster.CatchProbability));
            Print("[gebsfish] Lobster are catchable.");
        }
        if (m_gebsConfig.BlueLobster.CatchProbability != 0) {
            m_YieldBank.RegisterYieldItem(new gebBlueLobster(m_gebsConfig.BlueLobster.CatchProbability));
            Print("[gebsfish] Blue Lobster are catchable.");
        }

        
        //finished loading fish data
        Print("[gebsfish] [InitYieldBank] Loading fish complete.");

        //start loading junk data
        Print("[gebsfish] [InitYieldBank] Adding junk to yield data.");

        foreach(string junk: m_gebsConfig.Junk.Classnames){
            Print("[gebsfish] " + junk + " is catchable as junk.");
            m_YieldBank.RegisterYieldItem(new YieldItemJunk(1,junk));
        }

        foreach(string containerjunk: m_gebsConfig.ContainerJunk.Classnames){
            Print("[gebsfish] " + containerjunk + " is catchable as junk.");
            m_YieldBank.RegisterYieldItem(new YieldItemJunkEmpty(1,junk));
        }

        
        //finished loading junk data
        Print("[gebsfish] [InitYieldBank] Loading junk complete.");
    
        //load animal yeilds for traps (snare)
        m_YieldBank.RegisterYieldItem(new YieldItemDeadRabbit(4));
        m_YieldBank.RegisterYieldItem(new YieldItemDeadRooster(1));
        m_YieldBank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
        m_YieldBank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
        m_YieldBank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
        m_YieldBank.RegisterYieldItem(new YieldItemDeadFox(2));

        Print("[gebsfish] [InitYieldBank] Initialization of yield data complete.");
	}
}