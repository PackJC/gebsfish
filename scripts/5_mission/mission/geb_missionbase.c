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
			bank.RegisterYieldItem(new gebNorthernpike(Math.Ceil(fresh_chance_map.Get("geb_NORTHERNPIKE_CHANCE"))));
			bank.RegisterYieldItem(new gebLargemouthbass(Math.Ceil(fresh_chance_map.Get("geb_LARGEMOUTHBASS_CHANCE"))));
			bank.RegisterYieldItem(new gebSmallmouthbass(Math.Ceil(fresh_chance_map.Get("geb_SMALLMOUTHBASS_CHANCE"))));
			bank.RegisterYieldItem(new gebWalleye(Math.Ceil(fresh_chance_map.Get("geb_WALLEYE_CHANCE"))));
			bank.RegisterYieldItem(new gebSunfish(Math.Ceil(fresh_chance_map.Get("geb_SUNFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebWhitebass(Math.Ceil(fresh_chance_map.Get("geb_WHITEBASS_CHANCE"))));
			bank.RegisterYieldItem(new gebBlackbass(Math.Ceil(fresh_chance_map.Get("geb_BLACKBASS_CHANCE"))));
			bank.RegisterYieldItem(new gebRainbowTrout(Math.Ceil(fresh_chance_map.Get("geb_TROUT_CHANCE"))));
			bank.RegisterYieldItem(new gebBrownTrout(Math.Ceil(fresh_chance_map.Get("geb_BROWNTROUT_CHANCE"))));
			bank.RegisterYieldItem(new gebBrookTrout(Math.Ceil(fresh_chance_map.Get("geb_BROOKTROUT_CHANCE"))));
			bank.RegisterYieldItem(new gebLakeTrout(Math.Ceil(fresh_chance_map.Get("geb_LAKETROUT_CHANCE"))));
			bank.RegisterYieldItem(new gebCutthroatTrout(Math.Ceil(fresh_chance_map.Get("geb_CUTTHROATTROUT_CHANCE"))));
			bank.RegisterYieldItem(new gebPerch(Math.Ceil(fresh_chance_map.Get("geb_PERCH_CHANCE"))));
			bank.RegisterYieldItem(new gebCatfish(Math.Ceil(fresh_chance_map.Get("geb_CATFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebMinnow(Math.Ceil(fresh_chance_map.Get("geb_MINNOW_CHANCE"))));
			bank.RegisterYieldItem(new gebBluegill(Math.Ceil(fresh_chance_map.Get("geb_BLUEGILL_CHANCE"))));
			bank.RegisterYieldItem(new gebSauger(Math.Ceil(fresh_chance_map.Get("geb_SAUGER_CHANCE"))));
			bank.RegisterYieldItem(new gebBowfin(Math.Ceil(fresh_chance_map.Get("geb_BOWFIN_CHANCE"))));
			bank.RegisterYieldItem(new gebSlimysculpin(Math.Ceil(fresh_chance_map.Get("geb_SLIMYSCULPIN_CHANCE"))));
			bank.RegisterYieldItem(new gebSeverum(Math.Ceil(fresh_chance_map.Get("geb_SEVERUM_CHANCE"))));

			//1 freshwater crustacean
			bank.RegisterYieldItem(new gebCrayfish(Math.Ceil(fresh_chance_map.Get("geb_CRAYFISH_CHANCE"))));

			//21 saltwater fish
			bank.RegisterYieldItem(new gebMahimahi(Math.Ceil(salt_chance_map.Get("geb_MAHIMAHI_CHANCE"))));
			bank.RegisterYieldItem(new gebSailfish(Math.Ceil(salt_chance_map.Get("geb_SAILFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebAngelfish(Math.Ceil(salt_chance_map.Get("geb_ANGELFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebAsianseabass(Math.Ceil(salt_chance_map.Get("geb_ASIANSEABASS_CHANCE"))));
			bank.RegisterYieldItem(new gebBluemarlin(Math.Ceil(salt_chance_map.Get("geb_BLUEMARLIN_CHANCE"))));
			bank.RegisterYieldItem(new gebBonita(Math.Ceil(salt_chance_map.Get("geb_BONITA_CHANCE"))));
			bank.RegisterYieldItem(new gebCherrysalmon(Math.Ceil(salt_chance_map.Get("geb_CHERRYSALMON_CHANCE"))));
			bank.RegisterYieldItem(new gebChinooksalmon(Math.Ceil(fresh_chance_map.Get("geb_CHINOOKSALMON_CHANCE"))));
			bank.RegisterYieldItem(new gebSockeyesalmon(Math.Ceil(fresh_chance_map.Get("geb_SOCKEYESALMON_CHANCE"))));
			bank.RegisterYieldItem(new gebFlatheadmullet(Math.Ceil(salt_chance_map.Get("geb_FLATHEADMULLET_CHANCE"))));
			bank.RegisterYieldItem(new gebLeopardshark(Math.Ceil(salt_chance_map.Get("geb_LEOPARDSHARK_CHANCE"))));
			bank.RegisterYieldItem(new gebPacificcod(Math.Ceil(salt_chance_map.Get("geb_PACIFICCOD_CHANCE"))));
			bank.RegisterYieldItem(new gebRedheadcichlid(Math.Ceil(salt_chance_map.Get("geb_REDHEADCICHLID_CHANCE"))));
			bank.RegisterYieldItem(new gebRoughneckrock(Math.Ceil(salt_chance_map.Get("geb_ROUGHNECKROCK_CHANCE"))));
			bank.RegisterYieldItem(new gebBluetang(Math.Ceil(salt_chance_map.Get("geb_BLUETANG_CHANCE"))));
			bank.RegisterYieldItem(new gebHairtailfish(Math.Ceil(salt_chance_map.Get("geb_HAIRTAILFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebHumpheadwrasse(Math.Ceil(salt_chance_map.Get("geb_HUMPHEADWRASSE_CHANCE"))));
			bank.RegisterYieldItem(new gebSiamesetigerfish(Math.Ceil(salt_chance_map.Get("geb_SIAMESETIGERFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebGreatwhiteshark(Math.Ceil(salt_chance_map.Get("geb_GREATWHITESHARK_CHANCE"))));
			bank.RegisterYieldItem(new gebAngelshark(Math.Ceil(salt_chance_map.Get("geb_ANGELSHARK_CHANCE"))));
			bank.RegisterYieldItem(new gebYellowfintuna(Math.Ceil(salt_chance_map.Get("geb_YELLOWFINTUNA_CHANCE"))));

			
			//8 saltwater crustacean
			bank.RegisterYieldItem(new gebBloodclam(Math.Ceil(salt_chance_map.Get("geb_BLOODCLAM_CHANCE"))));
			bank.RegisterYieldItem(new gebMussel(Math.Ceil(salt_chance_map.Get("geb_MUSSEL_CHANCE"))));
			bank.RegisterYieldItem(new gebBlackdevilsnail(Math.Ceil(salt_chance_map.Get("geb_BLACKDEVILSNAIL_CHANCE"))));
			bank.RegisterYieldItem(new gebStarfish(Math.Ceil(salt_chance_map.Get("geb_STARFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebKingcrab(Math.Ceil(salt_chance_map.Get("geb_KINGCRAB_CHANCE"))));
			bank.RegisterYieldItem(new gebJellyfish(Math.Ceil(salt_chance_map.Get("geb_JELLYFISH_CHANCE"))));
			bank.RegisterYieldItem(new gebLobster(Math.Ceil(salt_chance_map.Get("geb_LOBSTER_CHANCE"))));
			bank.RegisterYieldItem(new gebBlueLobster(Math.Ceil(salt_chance_map.Get("geb_BLUELOBSTER_CHANCE"))));
		}
	}
};