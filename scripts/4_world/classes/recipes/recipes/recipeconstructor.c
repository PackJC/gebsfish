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
		RegisterRecipe(new PrepareCrayFish);

		//Freshwater fish 	
		RegisterRecipe(new PrepareBlueGill);
		RegisterRecipe(new PrepareBlackBass);
		RegisterRecipe(new PrepareFlatHeadCatFish);
		RegisterRecipe(new PrepareLargeMouthBass);
		RegisterRecipe(new PrepareSmallMouthBass);
		RegisterRecipe(new PrepareSunFish);
		RegisterRecipe(new PrepareWallEye);
		RegisterRecipe(new PrepareFatHeadMinnow);
		RegisterRecipe(new PrepareNorthernPike);
		RegisterRecipe(new PrepareYellowPerch);
		RegisterRecipe(new PrepareSauger);
		RegisterRecipe(new PrepareRainbowTrout);
		RegisterRecipe(new PrepareBrownTrout);
		RegisterRecipe(new PrepareBrookTrout);
		RegisterRecipe(new PrepareLakeTrout);
		RegisterRecipe(new PrepareCutThroatTrout);
		RegisterRecipe(new PrepareWhiteBass);
		RegisterRecipe(new PrepareBowFin);
		RegisterRecipe(new PrepareSlimySculpin);
		RegisterRecipe(new PrepareSockEyeSalmon);
		RegisterRecipe(new PrepareChinookSalmon);

		//Saltwater crustacean
		RegisterRecipe(new PrepareMussel);
		RegisterRecipe(new PrepareBlackDevilSnail);
		RegisterRecipe(new PrepareStarFish);
		RegisterRecipe(new PrepareKingCrab);
		RegisterRecipe(new PrepareBlueJellyFish);
		RegisterRecipe(new PrepareBloodClam);
		RegisterRecipe(new PrepareLobster);
		RegisterRecipe(new PrepareBlueLobster);

		//Saltwater Fish
		RegisterRecipe(new PrepareAngelFish);
		RegisterRecipe(new PrepareAtlanticSailFish);
		RegisterRecipe(new PrepareMahiMahi);
		RegisterRecipe(new PrepareAsianSeaBass);
		RegisterRecipe(new PrepareAtlanticBlueMarlin);
		RegisterRecipe(new PrepareBonita);
		RegisterRecipe(new PrepareCherrySalmon);
		RegisterRecipe(new PrepareFlatHeadMullet);
		RegisterRecipe(new PrepareLeopardShark);
		RegisterRecipe(new PreparePacificCod);
		RegisterRecipe(new PrepareRedHeadCichlid);
		RegisterRecipe(new PrepareRoughNeckRock);
		RegisterRecipe(new PrepareSeverum);
		RegisterRecipe(new PrepareBlueTang);
		RegisterRecipe(new PrepareLargeHeadHairTailFish);
		RegisterRecipe(new PrepareHumpHeadWrasse);
		RegisterRecipe(new PrepareSiameseTigerFish);
		RegisterRecipe(new PrepareAngelShark);
		RegisterRecipe(new PrepareGreatWhiteShark);
		RegisterRecipe(new PrepareYellowFinTuna);
		
		//Tools
		RegisterRecipe(new CraftWoodenNet);

	}
};