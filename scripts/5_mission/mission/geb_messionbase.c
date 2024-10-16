modded class MissionBase
{    
    override void InitWorldYieldDataDefaults(CatchYieldBank bank)
	{
        super.InitWorldYieldDataDefaults(bank);
		if (bank)
		{			
			//freshwater fish
			bank.RegisterYieldItem(new gebNorthernpike());
			bank.RegisterYieldItem(new gebLargemouthbass());
			bank.RegisterYieldItem(new gebSmallmouthbass());
			bank.RegisterYieldItem(new gebWalleye());
			bank.RegisterYieldItem(new gebSunfish());
			bank.RegisterYieldItem(new gebWhitebass());
			bank.RegisterYieldItem(new gebBlackbass());
			bank.RegisterYieldItem(new gebTrout());
			bank.RegisterYieldItem(new gebBrownTrout());
			bank.RegisterYieldItem(new gebBrookTrout());
			bank.RegisterYieldItem(new gebLakeTrout());
			bank.RegisterYieldItem(new gebCutthroatTrout());
			bank.RegisterYieldItem(new gebPerch());
			bank.RegisterYieldItem(new gebCatfish());
			bank.RegisterYieldItem(new gebMinnow());
			bank.RegisterYieldItem(new gebBluegill());
			bank.RegisterYieldItem(new gebSauger());
			bank.RegisterYieldItem(new gebBowfin());
			bank.RegisterYieldItem(new gebSlimysculpin());

			//freshwater crustacean
			bank.RegisterYieldItem(new gebCrayfish());

			//saltwater fish
			bank.RegisterYieldItem(new gebMahimahi());
			bank.RegisterYieldItem(new gebSailfish());
			bank.RegisterYieldItem(new gebAngelfish());
			bank.RegisterYieldItem(new gebAsianseabass());
			bank.RegisterYieldItem(new gebBluemarlin());
			bank.RegisterYieldItem(new gebBonita());
			bank.RegisterYieldItem(new gebCherrysalmon());
			bank.RegisterYieldItem(new gebFlatheadmullet());
			bank.RegisterYieldItem(new gebLeopardshark());
			bank.RegisterYieldItem(new gebPacificcod());
			bank.RegisterYieldItem(new gebRedheadcichlid());
			bank.RegisterYieldItem(new gebRoughneckrock());
			bank.RegisterYieldItem(new gebSeverum());
			bank.RegisterYieldItem(new gebBluetang());
			bank.RegisterYieldItem(new gebHairtailfish());
			bank.RegisterYieldItem(new gebHumpheadwrasse());
			bank.RegisterYieldItem(new gebSiamesetigerfish());
			bank.RegisterYieldItem(new gebGreatwhiteshark());
			bank.RegisterYieldItem(new gebAngelshark());
			bank.RegisterYieldItem(new gebYellowfintuna());

			//saltwater crustacean
			bank.RegisterYieldItem(new gebBloodclam());
			bank.RegisterYieldItem(new gebMussel());
			bank.RegisterYieldItem(new gebBlackdevilsnail());
			bank.RegisterYieldItem(new gebStarfish());
			bank.RegisterYieldItem(new gebKingcrab());
			bank.RegisterYieldItem(new gebJellyfish());
			bank.RegisterYieldItem(new gebLobster());
			bank.RegisterYieldItem(new gebBlueLobster());
		}
	}
};