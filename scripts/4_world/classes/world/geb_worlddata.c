/*

CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class WorldData
{
	override void InitYieldBank()
	{
		super.InitYieldBank();

		if (!m_YieldBank)
		{
			Print("Error: m_YieldBank is not initialized!");
			return;
		}
		//19 freshwater fish
		m_YieldBank.RegisterYieldItem(new gebNorthernpike(18));   // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebLargemouthbass(20)); // Very high chance of catching
		m_YieldBank.RegisterYieldItem(new gebSmallmouthbass(18)); // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebWalleye(16));        // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebSunfish(14));        // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebWhitebass(17));      // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebBlackbass(20));      // Very high chance of catching
		m_YieldBank.RegisterYieldItem(new gebRainbowTrout(18));   // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebBrownTrout(18));     // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebBrookTrout(16));     // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebLakeTrout(17));      // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebCutthroatTrout(16)); // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebPerch(15));          // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebCatfish(22));        // Very high chance of catching (nocturnal feeder)
		m_YieldBank.RegisterYieldItem(new gebMinnow(25));         // Very high chance of catching (common)
		m_YieldBank.RegisterYieldItem(new gebBluegill(23));       // Very high chance of catching (common)
		m_YieldBank.RegisterYieldItem(new gebSauger(16));         // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebBowfin(14));         // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebSlimysculpin(13));   // Moderate to lower chance of catching

		//1 freshwater crustacean
		m_YieldBank.RegisterYieldItem(new gebCrayfish(20));  // High chance of catching (common species in traps)

		//20 saltwater fish
		m_YieldBank.RegisterYieldItem(new gebMahimahi(20));       // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebSailfish(18));       // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebAngelfish(15));      // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebAsianseabass(19));   // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebBluemarlin(17));     // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebBonita(21));         // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebCherrysalmon(17));   // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebFlatheadmullet(16)); // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebLeopardshark(18));   // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebPacificcod(19));     // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebRedheadcichlid(16)); // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebRoughneckrock(14));  // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebSeverum(15));        // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebBluetang(16));       // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebHairtailfish(17));   // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebHumpheadwrasse(15)); // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebSiamesetigerfish(16)); // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebGreatwhiteshark(12)); // Lower chance of catching (rare)
		m_YieldBank.RegisterYieldItem(new gebAngelshark(14));     // Moderate chance of catching (night feeder)
		m_YieldBank.RegisterYieldItem(new gebYellowfintuna(18));  // Moderate to high chance of catching

		//8 saltwater crustacean
		m_YieldBank.RegisterYieldItem(new gebBloodclam(22));      // High chance of catching (common)
		m_YieldBank.RegisterYieldItem(new gebMussel(23));         // Very high chance of catching (common)
		m_YieldBank.RegisterYieldItem(new gebBlackdevilsnail(18)); // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebStarfish(16));       // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebKingcrab(15));       // Moderate chance of catching
		m_YieldBank.RegisterYieldItem(new gebJellyfish(17));      // Moderate to high chance of catching
		m_YieldBank.RegisterYieldItem(new gebLobster(19));        // High chance of catching
		m_YieldBank.RegisterYieldItem(new gebBlueLobster(14));    // Lower chance of catching (rare)
	}
};
