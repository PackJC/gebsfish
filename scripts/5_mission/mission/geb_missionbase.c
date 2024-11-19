/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/


modded class MissionBase
{    
    override void InitWorldYieldDataDefaults(CatchYieldBank bank)
	{
        super.InitWorldYieldDataDefaults(bank);
		if (bank)
		{	
			auto salt_chance_map = FileReader.GetSaltChanceMap();
			auto fresh_chance_map = FileReader.GetFreshChanceMap();

			bank.ClearAllRegisteredItems();
			
			//fishies
			bank.RegisterYieldItem(new YieldItemCarp(15));
			bank.RegisterYieldItem(new YieldItemMackerel(15));
			bank.RegisterYieldItem(new YieldItemSardines(15));
			bank.RegisterYieldItem(new YieldItemBitterlings(15));
			bank.RegisterYieldItem(new YieldItemWalleyePollock(24));
			bank.RegisterYieldItem(new YieldItemSteelheadTrout(12));
			bank.RegisterYieldItem(new YieldItemShrimp(1));
		
			//fishy junk
			bank.RegisterYieldItem(new YieldItemJunk(1,"Wellies_Brown"));
			bank.RegisterYieldItem(new YieldItemJunk(1,"Wellies_Grey"));
			bank.RegisterYieldItem(new YieldItemJunk(1,"Wellies_Green"));
			bank.RegisterYieldItem(new YieldItemJunk(1,"Wellies_Black"));
			bank.RegisterYieldItem(new YieldItemJunkEmpty(1,"Pot"));
		
			//non-fishies
			bank.RegisterYieldItem(new YieldItemDeadRabbit(4));
			bank.RegisterYieldItem(new YieldItemDeadRooster(1));
			bank.RegisterYieldItem(new YieldItemDeadChicken_White(1));
			bank.RegisterYieldItem(new YieldItemDeadChicken_Spotted(1));
			bank.RegisterYieldItem(new YieldItemDeadChicken_Brown(1));
			bank.RegisterYieldItem(new YieldItemDeadFox(2));

			//20 freshwater fish
			bank.RegisterYieldItem(new gebNorthernpike(15));
			bank.RegisterYieldItem(new gebLargemouthbass(15));
			bank.RegisterYieldItem(new gebSmallmouthbass(15));
			bank.RegisterYieldItem(new gebWalleye(15));
			bank.RegisterYieldItem(new gebSunfish(15));
			bank.RegisterYieldItem(new gebWhitebass(15));
			bank.RegisterYieldItem(new gebBlackbass(15));
			bank.RegisterYieldItem(new gebRainbowTrout(15));
			bank.RegisterYieldItem(new gebBrownTrout(15));
			bank.RegisterYieldItem(new gebBrookTrout(15));
			bank.RegisterYieldItem(new gebLakeTrout(15));
			bank.RegisterYieldItem(new gebCutthroatTrout(15));
			bank.RegisterYieldItem(new gebPerch(15));
			bank.RegisterYieldItem(new gebCatfish(15));
			bank.RegisterYieldItem(new gebMinnow(15));
			bank.RegisterYieldItem(new gebBluegill(15));
			bank.RegisterYieldItem(new gebSauger(15));
			bank.RegisterYieldItem(new gebBowfin(15));
			bank.RegisterYieldItem(new gebSlimysculpin(15));
			bank.RegisterYieldItem(new gebSeverum(15));

			//1 freshwater crustacean
			bank.RegisterYieldItem(new gebCrayfish(15));

			//21 saltwater fish
			bank.RegisterYieldItem(new gebMahimahi(15));
			bank.RegisterYieldItem(new gebSailfish(15));
			bank.RegisterYieldItem(new gebAngelfish(15));
			bank.RegisterYieldItem(new gebAsianseabass(15));
			bank.RegisterYieldItem(new gebBluemarlin(15));
			bank.RegisterYieldItem(new gebBonita(15));
			bank.RegisterYieldItem(new gebCherrysalmon(15));
			bank.RegisterYieldItem(new gebChinooksalmon(15));
			bank.RegisterYieldItem(new gebSockeyesalmon(15));
			bank.RegisterYieldItem(new gebFlatheadmullet(15));
			bank.RegisterYieldItem(new gebLeopardshark(15));
			bank.RegisterYieldItem(new gebPacificcod(15));
			bank.RegisterYieldItem(new gebRedheadcichlid(15));
			bank.RegisterYieldItem(new gebRoughneckrock(15));
			bank.RegisterYieldItem(new gebBluetang(15));
			bank.RegisterYieldItem(new gebHairtailfish(15));
			bank.RegisterYieldItem(new gebHumpheadwrasse(15));
			bank.RegisterYieldItem(new gebSiamesetigerfish(15));
			bank.RegisterYieldItem(new gebGreatwhiteshark(15));
			bank.RegisterYieldItem(new gebAngelshark(15));
			bank.RegisterYieldItem(new gebYellowfintuna(15));

			
			//8 saltwater crustacean
			bank.RegisterYieldItem(new gebBloodclam(15));
			bank.RegisterYieldItem(new gebMussel(15));
			bank.RegisterYieldItem(new gebBlackdevilsnail(15));
			bank.RegisterYieldItem(new gebStarfish(15));
			bank.RegisterYieldItem(new gebKingcrab(15));
			bank.RegisterYieldItem(new gebJellyfish(15));
			bank.RegisterYieldItem(new gebLobster(15));
			bank.RegisterYieldItem(new gebBlueLobster(15));
		}
	}
};