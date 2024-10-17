modded class MissionBase
{    
    override void InitWorldYieldDataDefaults(CatchYieldBank bank)
	{
        super.InitWorldYieldDataDefaults(bank);
		if (bank)
		{			
			//19 freshwater fish
			bank.RegisterYieldItem(new gebNorthernpike(18));   // High chance of catching
			bank.RegisterYieldItem(new gebLargemouthbass(20)); // Very high chance of catching
			bank.RegisterYieldItem(new gebSmallmouthbass(18)); // High chance of catching
			bank.RegisterYieldItem(new gebWalleye(16));        // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebSunfish(14));        // Moderate chance of catching
			bank.RegisterYieldItem(new gebWhitebass(17));      // High chance of catching
			bank.RegisterYieldItem(new gebBlackbass(20));      // Very high chance of catching
			bank.RegisterYieldItem(new gebRainbowTrout(18));   // High chance of catching
			bank.RegisterYieldItem(new gebBrownTrout(18));     // High chance of catching
			bank.RegisterYieldItem(new gebBrookTrout(16));     // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebLakeTrout(17));      // High chance of catching
			bank.RegisterYieldItem(new gebCutthroatTrout(16)); // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebPerch(15));          // Moderate chance of catching
			bank.RegisterYieldItem(new gebCatfish(22));        // Very high chance of catching (nocturnal feeder)
			bank.RegisterYieldItem(new gebMinnow(25));         // Very high chance of catching (common)
			bank.RegisterYieldItem(new gebBluegill(23));       // Very high chance of catching (common)
			bank.RegisterYieldItem(new gebSauger(16));         // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebBowfin(14));         // Moderate chance of catching
			bank.RegisterYieldItem(new gebSlimysculpin(13));   // Moderate to lower chance of catching

			//1 freshwater crustacean
			bank.RegisterYieldItem(new gebCrayfish(20));  // High chance of catching (common species in traps)

			//20 saltwater fish
			bank.RegisterYieldItem(new gebMahimahi(20));       // High chance of catching
			bank.RegisterYieldItem(new gebSailfish(18));       // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebAngelfish(15));      // Moderate chance of catching
			bank.RegisterYieldItem(new gebAsianseabass(19));   // High chance of catching
			bank.RegisterYieldItem(new gebBluemarlin(17));     // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebBonita(21));         // High chance of catching
			bank.RegisterYieldItem(new gebCherrysalmon(17));   // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebFlatheadmullet(16)); // Moderate chance of catching
			bank.RegisterYieldItem(new gebLeopardshark(18));   // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebPacificcod(19));     // High chance of catching
			bank.RegisterYieldItem(new gebRedheadcichlid(16)); // Moderate chance of catching
			bank.RegisterYieldItem(new gebRoughneckrock(14));  // Moderate chance of catching
			bank.RegisterYieldItem(new gebSeverum(15));        // Moderate chance of catching
			bank.RegisterYieldItem(new gebBluetang(16));       // Moderate chance of catching
			bank.RegisterYieldItem(new gebHairtailfish(17));   // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebHumpheadwrasse(15)); // Moderate chance of catching
			bank.RegisterYieldItem(new gebSiamesetigerfish(16)); // Moderate chance of catching
			bank.RegisterYieldItem(new gebGreatwhiteshark(12)); // Lower chance of catching (rare)
			bank.RegisterYieldItem(new gebAngelshark(14));     // Moderate chance of catching (night feeder)
			bank.RegisterYieldItem(new gebYellowfintuna(18));  // Moderate to high chance of catching

			//8 saltwater crustacean
			bank.RegisterYieldItem(new gebBloodclam(22));      // High chance of catching (common)
			bank.RegisterYieldItem(new gebMussel(23));         // Very high chance of catching (common)
			bank.RegisterYieldItem(new gebBlackdevilsnail(18)); // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebStarfish(16));       // Moderate chance of catching
			bank.RegisterYieldItem(new gebKingcrab(15));       // Moderate chance of catching
			bank.RegisterYieldItem(new gebJellyfish(17));      // Moderate to high chance of catching
			bank.RegisterYieldItem(new gebLobster(19));        // High chance of catching
			bank.RegisterYieldItem(new gebBlueLobster(14));    // Lower chance of catching (rare)
		}
	}
};