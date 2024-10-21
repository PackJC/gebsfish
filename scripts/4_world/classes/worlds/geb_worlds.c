modded class EnochData
{
	override void InitYieldBank()
	{
		super.InitYieldBank();

		FileReader.GetInstance();		
			auto salt_chance_map = FileReader.GetSaltChanceMap();
			auto fresh_chance_map = FileReader.GetFreshChanceMap();

			//19 freshwater fish
			m_YieldBank.RegisterYieldItem(new gebNorthernpike(Math.Ceil(fresh_chance_map.Get("geb_NORTHERNPIKE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLargemouthbass(Math.Ceil(fresh_chance_map.Get("geb_LARGEMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSmallmouthbass(Math.Ceil(fresh_chance_map.Get("geb_SMALLMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWalleye(Math.Ceil(fresh_chance_map.Get("geb_WALLEYE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSunfish(Math.Ceil(fresh_chance_map.Get("geb_SUNFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWhitebass(Math.Ceil(fresh_chance_map.Get("geb_WHITEBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackbass(Math.Ceil(fresh_chance_map.Get("geb_BLACKBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRainbowTrout(Math.Ceil(fresh_chance_map.Get("geb_RAINBOWTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrownTrout(Math.Ceil(fresh_chance_map.Get("geb_BROWNTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrookTrout(Math.Ceil(fresh_chance_map.Get("geb_BROOKTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLakeTrout(Math.Ceil(fresh_chance_map.Get("geb_LAKETROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCutthroatTrout(Math.Ceil(fresh_chance_map.Get("geb_CUTTHROATTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPerch(Math.Ceil(fresh_chance_map.Get("geb_PERCH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCatfish(Math.Ceil(fresh_chance_map.Get("geb_CATFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMinnow(Math.Ceil(fresh_chance_map.Get("geb_MINNOW_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluegill(Math.Ceil(fresh_chance_map.Get("geb_BLUEGILL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSauger(Math.Ceil(fresh_chance_map.Get("geb_SAUGER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBowfin(Math.Ceil(fresh_chance_map.Get("geb_BOWFIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSlimysculpin(Math.Ceil(fresh_chance_map.Get("geb_SLIMYSCULPIN_CHANCE"))));

			//1 freshwater crustacean
			m_YieldBank.RegisterYieldItem(new gebCrayfish(Math.Ceil(fresh_chance_map.Get("geb_CRAYFISH_CHANCE"))));

			//20 saltwater fish
			m_YieldBank.RegisterYieldItem(new gebMahimahi(Math.Ceil(salt_chance_map.Get("geb_MAHIMAHI_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSailfish(Math.Ceil(salt_chance_map.Get("geb_SAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelfish(Math.Ceil(salt_chance_map.Get("geb_ANGELFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAsianseabass(Math.Ceil(salt_chance_map.Get("geb_ASIANSEABASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluemarlin(Math.Ceil(salt_chance_map.Get("geb_BLUEMARLIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBonita(Math.Ceil(salt_chance_map.Get("geb_BONITA_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCherrysalmon(Math.Ceil(salt_chance_map.Get("geb_CHERRYSALMON_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebFlatheadmullet(Math.Ceil(salt_chance_map.Get("geb_FLATHEADMULLET_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLeopardshark(Math.Ceil(salt_chance_map.Get("geb_LEOPARDSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPacificcod(Math.Ceil(salt_chance_map.Get("geb_PACIFICCOD_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRedheadcichlid(Math.Ceil(salt_chance_map.Get("geb_REDHEADCICHLID_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRoughneckrock(Math.Ceil(salt_chance_map.Get("geb_ROUGHNECKROCK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSeverum(Math.Ceil(salt_chance_map.Get("geb_SEVERUM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluetang(Math.Ceil(salt_chance_map.Get("geb_BLUETANG_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHairtailfish(Math.Ceil(salt_chance_map.Get("geb_HAIRTAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHumpheadwrasse(Math.Ceil(salt_chance_map.Get("geb_HUMPHEADWRASSE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSiamesetigerfish(Math.Ceil(salt_chance_map.Get("geb_SIAMESETIGERFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebGreatwhiteshark(Math.Ceil(salt_chance_map.Get("geb_GREATWHITESHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelshark(Math.Ceil(salt_chance_map.Get("geb_ANGELSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebYellowfintuna(Math.Ceil(salt_chance_map.Get("geb_YELLOWFINTUNA_CHANCE"))));

			
			//8 saltwater crustacean
			m_YieldBank.RegisterYieldItem(new gebBloodclam(Math.Ceil(salt_chance_map.Get("geb_BLOODCLAM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMussel(Math.Ceil(salt_chance_map.Get("geb_MUSSEL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackdevilsnail(Math.Ceil(salt_chance_map.Get("geb_BLACKDEVILSNAIL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebStarfish(Math.Ceil(salt_chance_map.Get("geb_STARFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebKingcrab(Math.Ceil(salt_chance_map.Get("geb_KINGCRAB_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebJellyfish(Math.Ceil(salt_chance_map.Get("geb_JELLYFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLobster(Math.Ceil(salt_chance_map.Get("geb_LOBSTER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlueLobster(Math.Ceil(salt_chance_map.Get("geb_BLUELOBSTER_CHANCE"))));	}
};

modded class SakhalData
{
	override void InitYieldBank()
	{
		super.InitYieldBank();

		FileReader.GetInstance();		
			auto salt_chance_map = FileReader.GetSaltChanceMap();
			auto fresh_chance_map = FileReader.GetFreshChanceMap();

			//19 freshwater fish
			m_YieldBank.RegisterYieldItem(new gebNorthernpike(Math.Ceil(fresh_chance_map.Get("geb_NORTHERNPIKE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLargemouthbass(Math.Ceil(fresh_chance_map.Get("geb_LARGEMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSmallmouthbass(Math.Ceil(fresh_chance_map.Get("geb_SMALLMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWalleye(Math.Ceil(fresh_chance_map.Get("geb_WALLEYE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSunfish(Math.Ceil(fresh_chance_map.Get("geb_SUNFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWhitebass(Math.Ceil(fresh_chance_map.Get("geb_WHITEBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackbass(Math.Ceil(fresh_chance_map.Get("geb_BLACKBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRainbowTrout(Math.Ceil(fresh_chance_map.Get("geb_RAINBOWTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrownTrout(Math.Ceil(fresh_chance_map.Get("geb_BROWNTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrookTrout(Math.Ceil(fresh_chance_map.Get("geb_BROOKTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLakeTrout(Math.Ceil(fresh_chance_map.Get("geb_LAKETROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCutthroatTrout(Math.Ceil(fresh_chance_map.Get("geb_CUTTHROATTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPerch(Math.Ceil(fresh_chance_map.Get("geb_PERCH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCatfish(Math.Ceil(fresh_chance_map.Get("geb_CATFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMinnow(Math.Ceil(fresh_chance_map.Get("geb_MINNOW_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluegill(Math.Ceil(fresh_chance_map.Get("geb_BLUEGILL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSauger(Math.Ceil(fresh_chance_map.Get("geb_SAUGER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBowfin(Math.Ceil(fresh_chance_map.Get("geb_BOWFIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSlimysculpin(Math.Ceil(fresh_chance_map.Get("geb_SLIMYSCULPIN_CHANCE"))));

			//1 freshwater crustacean
			m_YieldBank.RegisterYieldItem(new gebCrayfish(Math.Ceil(fresh_chance_map.Get("geb_CRAYFISH_CHANCE"))));

			//20 saltwater fish
			m_YieldBank.RegisterYieldItem(new gebMahimahi(Math.Ceil(salt_chance_map.Get("geb_MAHIMAHI_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSailfish(Math.Ceil(salt_chance_map.Get("geb_SAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelfish(Math.Ceil(salt_chance_map.Get("geb_ANGELFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAsianseabass(Math.Ceil(salt_chance_map.Get("geb_ASIANSEABASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluemarlin(Math.Ceil(salt_chance_map.Get("geb_BLUEMARLIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBonita(Math.Ceil(salt_chance_map.Get("geb_BONITA_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCherrysalmon(Math.Ceil(salt_chance_map.Get("geb_CHERRYSALMON_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebFlatheadmullet(Math.Ceil(salt_chance_map.Get("geb_FLATHEADMULLET_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLeopardshark(Math.Ceil(salt_chance_map.Get("geb_LEOPARDSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPacificcod(Math.Ceil(salt_chance_map.Get("geb_PACIFICCOD_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRedheadcichlid(Math.Ceil(salt_chance_map.Get("geb_REDHEADCICHLID_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRoughneckrock(Math.Ceil(salt_chance_map.Get("geb_ROUGHNECKROCK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSeverum(Math.Ceil(salt_chance_map.Get("geb_SEVERUM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluetang(Math.Ceil(salt_chance_map.Get("geb_BLUETANG_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHairtailfish(Math.Ceil(salt_chance_map.Get("geb_HAIRTAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHumpheadwrasse(Math.Ceil(salt_chance_map.Get("geb_HUMPHEADWRASSE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSiamesetigerfish(Math.Ceil(salt_chance_map.Get("geb_SIAMESETIGERFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebGreatwhiteshark(Math.Ceil(salt_chance_map.Get("geb_GREATWHITESHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelshark(Math.Ceil(salt_chance_map.Get("geb_ANGELSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebYellowfintuna(Math.Ceil(salt_chance_map.Get("geb_YELLOWFINTUNA_CHANCE"))));

			
			//8 saltwater crustacean
			m_YieldBank.RegisterYieldItem(new gebBloodclam(Math.Ceil(salt_chance_map.Get("geb_BLOODCLAM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMussel(Math.Ceil(salt_chance_map.Get("geb_MUSSEL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackdevilsnail(Math.Ceil(salt_chance_map.Get("geb_BLACKDEVILSNAIL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebStarfish(Math.Ceil(salt_chance_map.Get("geb_STARFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebKingcrab(Math.Ceil(salt_chance_map.Get("geb_KINGCRAB_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebJellyfish(Math.Ceil(salt_chance_map.Get("geb_JELLYFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLobster(Math.Ceil(salt_chance_map.Get("geb_LOBSTER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlueLobster(Math.Ceil(salt_chance_map.Get("geb_BLUELOBSTER_CHANCE"))));	}
};

modded class ChernarusPlusData
{
	override void InitYieldBank()
	{
		super.InitYieldBank();

		FileReader.GetInstance();		
			auto salt_chance_map = FileReader.GetSaltChanceMap();
			auto fresh_chance_map = FileReader.GetFreshChanceMap();

			//19 freshwater fish
			m_YieldBank.RegisterYieldItem(new gebNorthernpike(Math.Ceil(fresh_chance_map.Get("geb_NORTHERNPIKE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLargemouthbass(Math.Ceil(fresh_chance_map.Get("geb_LARGEMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSmallmouthbass(Math.Ceil(fresh_chance_map.Get("geb_SMALLMOUTHBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWalleye(Math.Ceil(fresh_chance_map.Get("geb_WALLEYE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSunfish(Math.Ceil(fresh_chance_map.Get("geb_SUNFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebWhitebass(Math.Ceil(fresh_chance_map.Get("geb_WHITEBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackbass(Math.Ceil(fresh_chance_map.Get("geb_BLACKBASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRainbowTrout(Math.Ceil(fresh_chance_map.Get("geb_RAINBOWTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrownTrout(Math.Ceil(fresh_chance_map.Get("geb_BROWNTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBrookTrout(Math.Ceil(fresh_chance_map.Get("geb_BROOKTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLakeTrout(Math.Ceil(fresh_chance_map.Get("geb_LAKETROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCutthroatTrout(Math.Ceil(fresh_chance_map.Get("geb_CUTTHROATTROUT_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPerch(Math.Ceil(fresh_chance_map.Get("geb_PERCH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCatfish(Math.Ceil(fresh_chance_map.Get("geb_CATFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMinnow(Math.Ceil(fresh_chance_map.Get("geb_MINNOW_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluegill(Math.Ceil(fresh_chance_map.Get("geb_BLUEGILL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSauger(Math.Ceil(fresh_chance_map.Get("geb_SAUGER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBowfin(Math.Ceil(fresh_chance_map.Get("geb_BOWFIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSlimysculpin(Math.Ceil(fresh_chance_map.Get("geb_SLIMYSCULPIN_CHANCE"))));

			//1 freshwater crustacean
			m_YieldBank.RegisterYieldItem(new gebCrayfish(Math.Ceil(fresh_chance_map.Get("geb_CRAYFISH_CHANCE"))));

			//20 saltwater fish
			m_YieldBank.RegisterYieldItem(new gebMahimahi(Math.Ceil(salt_chance_map.Get("geb_MAHIMAHI_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSailfish(Math.Ceil(salt_chance_map.Get("geb_SAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelfish(Math.Ceil(salt_chance_map.Get("geb_ANGELFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAsianseabass(Math.Ceil(salt_chance_map.Get("geb_ASIANSEABASS_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluemarlin(Math.Ceil(salt_chance_map.Get("geb_BLUEMARLIN_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBonita(Math.Ceil(salt_chance_map.Get("geb_BONITA_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebCherrysalmon(Math.Ceil(salt_chance_map.Get("geb_CHERRYSALMON_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebFlatheadmullet(Math.Ceil(salt_chance_map.Get("geb_FLATHEADMULLET_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLeopardshark(Math.Ceil(salt_chance_map.Get("geb_LEOPARDSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebPacificcod(Math.Ceil(salt_chance_map.Get("geb_PACIFICCOD_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRedheadcichlid(Math.Ceil(salt_chance_map.Get("geb_REDHEADCICHLID_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebRoughneckrock(Math.Ceil(salt_chance_map.Get("geb_ROUGHNECKROCK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSeverum(Math.Ceil(salt_chance_map.Get("geb_SEVERUM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBluetang(Math.Ceil(salt_chance_map.Get("geb_BLUETANG_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHairtailfish(Math.Ceil(salt_chance_map.Get("geb_HAIRTAILFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebHumpheadwrasse(Math.Ceil(salt_chance_map.Get("geb_HUMPHEADWRASSE_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebSiamesetigerfish(Math.Ceil(salt_chance_map.Get("geb_SIAMESETIGERFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebGreatwhiteshark(Math.Ceil(salt_chance_map.Get("geb_GREATWHITESHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebAngelshark(Math.Ceil(salt_chance_map.Get("geb_ANGELSHARK_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebYellowfintuna(Math.Ceil(salt_chance_map.Get("geb_YELLOWFINTUNA_CHANCE"))));

			
			//8 saltwater crustacean
			m_YieldBank.RegisterYieldItem(new gebBloodclam(Math.Ceil(salt_chance_map.Get("geb_BLOODCLAM_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebMussel(Math.Ceil(salt_chance_map.Get("geb_MUSSEL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlackdevilsnail(Math.Ceil(salt_chance_map.Get("geb_BLACKDEVILSNAIL_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebStarfish(Math.Ceil(salt_chance_map.Get("geb_STARFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebKingcrab(Math.Ceil(salt_chance_map.Get("geb_KINGCRAB_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebJellyfish(Math.Ceil(salt_chance_map.Get("geb_JELLYFISH_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebLobster(Math.Ceil(salt_chance_map.Get("geb_LOBSTER_CHANCE"))));
			m_YieldBank.RegisterYieldItem(new gebBlueLobster(Math.Ceil(salt_chance_map.Get("geb_BLUELOBSTER_CHANCE"))));	}
};
