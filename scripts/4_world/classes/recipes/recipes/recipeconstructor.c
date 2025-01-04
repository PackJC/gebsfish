/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

		//Freshwater crustacean
		RegisterRecipe(new PrepareCrayfish);

		//Freshwater fish 	
		RegisterRecipe(new PrepareBluegill);
		RegisterRecipe(new PrepareBlackbass);
		RegisterRecipe(new PrepareCatfish);
		RegisterRecipe(new PrepareLargemouthbass);
		RegisterRecipe(new PrepareSmallmouthbass);
		RegisterRecipe(new PrepareSunfish);
		RegisterRecipe(new PrepareWalleye);
		RegisterRecipe(new PrepareMinnow);
		RegisterRecipe(new PrepareNorthernpike);
		RegisterRecipe(new PreparePerch);
		RegisterRecipe(new PrepareSauger);
		RegisterRecipe(new PrepareRainbowTrout);
		RegisterRecipe(new PrepareBrownTrout);
		RegisterRecipe(new PrepareBrookTrout);
		RegisterRecipe(new PrepareLakeTrout);
		RegisterRecipe(new PrepareCutthroatTrout);
		RegisterRecipe(new PrepareWhitebass);
		RegisterRecipe(new PrepareBowfin);
		RegisterRecipe(new PrepareSlimysculpin);
		RegisterRecipe(new PrepareSockeyesalmon);
		RegisterRecipe(new PrepareChinooksalmon);

		//Saltwater crustacean
		RegisterRecipe(new PrepareMussel);
		RegisterRecipe(new PrepareBlackdevilsnail);
		RegisterRecipe(new PrepareStarfish);
		RegisterRecipe(new PrepareKingcrab);
		RegisterRecipe(new PrepareJellyfish);
		RegisterRecipe(new PrepareBloodclam);
		RegisterRecipe(new PrepareLobster);
		RegisterRecipe(new PrepareBlueLobster);

		//Saltwater Fish
		RegisterRecipe(new PrepareAngelfish);
		RegisterRecipe(new PrepareSailfish);
		RegisterRecipe(new PrepareMahimahi);
		RegisterRecipe(new PrepareAsianseabass);
		RegisterRecipe(new PrepareBluemarlin);
		RegisterRecipe(new PrepareBonita);
		RegisterRecipe(new PrepareCherrysalmon);
		RegisterRecipe(new PrepareFlatheadmullet);
		RegisterRecipe(new PrepareLeopardshark);
		RegisterRecipe(new PreparePacificcod);
		RegisterRecipe(new PrepareRedheadcichlid);
		RegisterRecipe(new PrepareRoughneckrock);
		RegisterRecipe(new PrepareSeverum);
		RegisterRecipe(new PrepareBluetang);
		RegisterRecipe(new PrepareHairtailfish);
		RegisterRecipe(new PrepareHumpheadwrasse);
		RegisterRecipe(new PrepareSiamesetigerfish);
		RegisterRecipe(new PrepareAngelshark);
		RegisterRecipe(new PrepareGreatwhiteshark);
		RegisterRecipe(new PrepareYellowfintuna);
		
		//Tools
		RegisterRecipe(new CraftWoodenNet);

	}
};