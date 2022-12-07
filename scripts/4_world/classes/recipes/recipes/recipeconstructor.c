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

		/*
			FOOD RECIPES
		*/

		//Freshwater Life 	
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
		RegisterRecipe(new PrepareCrayfish);
		RegisterRecipe(new PrepareTrout);
		RegisterRecipe(new PrepareBrownTrout);
		RegisterRecipe(new PrepareBrookTrout);
		RegisterRecipe(new PrepareLakeTrout);
		RegisterRecipe(new PrepareCutthroatTrout);
		RegisterRecipe(new PrepareWhitebass);
		RegisterRecipe(new PrepareBowfin);
		RegisterRecipe(new PrepareSlimysculpin);
		RegisterRecipe(new PrepareSlimysculpin);
		RegisterRecipe(new PrepareMussel);
		RegisterRecipe(new PrepareBlackdevilsnail);
		RegisterRecipe(new PrepareSockeyesalmon);
		RegisterRecipe(new PrepareChinooksalmon);

		//Saltwater Life
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
		RegisterRecipe(new PrepareShrimp);
		RegisterRecipe(new PrepareBluetang);
		RegisterRecipe(new PrepareHairtailfish);
		RegisterRecipe(new PrepareHumpheadwrasse);
		RegisterRecipe(new PrepareSiamesetigerfish);
		RegisterRecipe(new PrepareStarfish);
		RegisterRecipe(new PrepareKingcrab);
		RegisterRecipe(new PrepareJellyfish);
		RegisterRecipe(new PrepareBloodclam);
		RegisterRecipe(new PrepareLobster);
		RegisterRecipe(new PrepareBlueLobster);
		RegisterRecipe(new PrepareAngelshark);
		RegisterRecipe(new PrepareGreatwhiteshark);
		RegisterRecipe(new PrepareYellowfintuna);
		/*
			BAIT RECIPES
		*/

		//Bone Bobbers
		RegisterRecipe(new CraftBoneHookBobber1);
		RegisterRecipe(new CraftBoneHookBobber1WormBait);
		RegisterRecipe(new CraftBoneHookBobber1RubberWormBait);
		RegisterRecipe(new CraftBoneHookBobber1GrubWormBait);
		RegisterRecipe(new CraftBoneHookBobber1GrassHopperBait);
		RegisterRecipe(new CraftBoneHookBobber1FieldCricketBait);
		RegisterRecipe(new CraftBoneHookBobber1MinnowBait);
		RegisterRecipe(new CraftBoneHookBobber2);
		RegisterRecipe(new CraftBoneHookBobber2WormBait);
		RegisterRecipe(new CraftBoneHookBobber2RubberWormBait);
		RegisterRecipe(new CraftBoneHookBobber2GrubWormBait);
		RegisterRecipe(new CraftBoneHookBobber2GrassHopperBait);
		RegisterRecipe(new CraftBoneHookBobber2FieldCricketBait);
		RegisterRecipe(new CraftBoneHookBobber2MinnowBait);
		RegisterRecipe(new CraftBoneHookBobber3);
		RegisterRecipe(new CraftBoneHookBobber3WormBait);
		RegisterRecipe(new CraftBoneHookBobber3RubberWormBait);
		RegisterRecipe(new CraftBoneHookBobber3GrubWormBait);
		RegisterRecipe(new CraftBoneHookBobber3GrassHopperBait);
		RegisterRecipe(new CraftBoneHookBobber3FieldCricketBait);
		RegisterRecipe(new CraftBoneHookBobber3MinnowBait);
		RegisterRecipe(new CraftBoneHookBobber4);
		RegisterRecipe(new CraftBoneHookBobber4WormBait);
		RegisterRecipe(new CraftBoneHookBobber4RubberWormBait);
		RegisterRecipe(new CraftBoneHookBobber4GrubWormBait);
		RegisterRecipe(new CraftBoneHookBobber4GrassHopperBait);
		RegisterRecipe(new CraftBoneHookBobber4FieldCricketBait);
		RegisterRecipe(new CraftBoneHookBobber4MinnowBait);

		//Metal Bobbers
		RegisterRecipe(new CraftMetalHookBobber1);
		RegisterRecipe(new CraftMetalHookBobber1WormBait);
		RegisterRecipe(new CraftMetalHookBobber1RubberWormBait);
		RegisterRecipe(new CraftMetalHookBobber1GrubWormBait);
		RegisterRecipe(new CraftMetalHookBobber1GrassHopperBait);
		RegisterRecipe(new CraftMetalHookBobber1FieldCricketBait);
		RegisterRecipe(new CraftMetalHookBobber1MinnowBait);
		RegisterRecipe(new CraftMetalHookBobber2);
		RegisterRecipe(new CraftMetalHookBobber2WormBait);
		RegisterRecipe(new CraftMetalHookBobber2RubberWormBait);
		RegisterRecipe(new CraftMetalHookBobber2GrubWormBait);
		RegisterRecipe(new CraftMetalHookBobber2GrassHopperBait);
		RegisterRecipe(new CraftMetalHookBobber2FieldCricketBait);
		RegisterRecipe(new CraftMetalHookBobber2MinnowBait);
		RegisterRecipe(new CraftMetalHookBobber3);
		RegisterRecipe(new CraftMetalHookBobber3WormBait);
		RegisterRecipe(new CraftMetalHookBobber3RubberWormBait);
		RegisterRecipe(new CraftMetalHookBobber3GrubWormBait);
		RegisterRecipe(new CraftMetalHookBobber3GrassHopperBait);
		RegisterRecipe(new CraftMetalHookBobber3FieldCricketBait);
		RegisterRecipe(new CraftMetalHookBobber3MinnowBait);
		RegisterRecipe(new CraftMetalHookBobber4);
		RegisterRecipe(new CraftMetalHookBobber4WormBait);
		RegisterRecipe(new CraftMetalHookBobber4RubberWormBait);
		RegisterRecipe(new CraftMetalHookBobber4GrubWormBait);
		RegisterRecipe(new CraftMetalHookBobber4GrassHopperBait);
		RegisterRecipe(new CraftMetalHookBobber4FieldCricketBait);
		RegisterRecipe(new CraftMetalHookBobber4MinnowBait);

		//Bobbers
		RegisterRecipe(new CraftVanillaHookBobber1);
		RegisterRecipe(new CraftVanillaHookBobber2);
		RegisterRecipe(new CraftVanillaHookBobber3);
		RegisterRecipe(new CraftVanillaHookBobber4);

		//Metal Hook Baits
		RegisterRecipe(new CraftMetalHook);
		RegisterRecipe(new CraftMetalRubberWormBait);
		RegisterRecipe(new CraftMetalGrubWormBait);
		RegisterRecipe(new CraftMetalGrassHopperBait);
		RegisterRecipe(new CraftMetalFieldCricketBait);
		RegisterRecipe(new CraftMetalWormBait);
		RegisterRecipe(new CraftMetalMinnowBait);

		//Vanilla Hook Baits
		RegisterRecipe(new CraftVanillaHookRubberWormBait);
		RegisterRecipe(new CraftVanillaHookGrubWormBait);
		RegisterRecipe(new CraftVanillaHookGrassHopperBait);
		RegisterRecipe(new CraftVanillaHookFieldCricketBait);
		RegisterRecipe(new CraftVanillaHookMinnowBait);

		//Bone Hook Baits
		RegisterRecipe(new CraftBoneRubberWormBait);
		RegisterRecipe(new CraftBoneGrubWormBait);
		RegisterRecipe(new CraftBoneGrassHopperBait);
		RegisterRecipe(new CraftBoneFieldCricketBait);
		RegisterRecipe(new CraftBoneMinnowBait);

		//Tools
		RegisterRecipe(new CraftWoodenNet);

	}

};