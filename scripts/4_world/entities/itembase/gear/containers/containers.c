/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

/*
	To restrict items in containers
*/

class geb_WormContainer : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "geb_GrubWorm", "geb_RubberWorm" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_BugContainer : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm"};

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}
		return false;
	}
};


class geb_BambooFishingNet : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_Minnow", "geb_Shrimp", "geb_Crayfish"};

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}
		return false;
	}
};

class geb_MinnowBucket : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "geb_Minnow", "geb_Crayfish", "geb_Shrimp", "geb_GrubWorm", "geb_GrassHopper", "geb_FieldCricket", "geb_RubberWorm" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}
		return false;
	}
};

class geb_SmallTackle : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_OldRedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_OldGreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};



class geb_OldBlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};


class geb_OldPurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};


class geb_YellowTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_RedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_PurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_PinkTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_OrangeTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_LimeTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_LightBlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_GreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_FunYellowTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_FunRedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_FunPurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_FunGreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_CamoTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_BrownTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};

class geb_BlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", "geb_MetalHookBobber1", "geb_MetalHookBobber2", "geb_MetalHookBobber3", "geb_MetalHookBobber4", "geb_BoneHookBobber1", "geb_BoneHookBobber2", "geb_BoneHookBobber3", "geb_BoneHookBobber4", "geb_MetalHook", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm",
"geb_MetalHookBobber1WormBait", "geb_MetalHookBobber1RubberWormBait", "geb_MetalHookBobber1GrubWormBait", "geb_MetalHookBobber1GrassHopperBait", "geb_MetalHookBobber1FieldCricketBait", "geb_MetalHookBobber1MinnowBait",
"geb_MetalHookBobber2WormBait", "geb_MetalHookBobber2RubberWormBait", "geb_MetalHookBobber2GrubWormBait", "geb_MetalHookBobber2GrassHopperBait", "geb_MetalHookBobber2FieldCricketBait", "geb_MetalHookBobber2MinnowBait",
"geb_MetalHookBobber3WormBait", "geb_MetalHookBobber3RubberWormBait", "geb_MetalHookBobber3GrubWormBait", "geb_MetalHookBobber3GrassHopperBait", "geb_MetalHookBobber3FieldCricketBait", "geb_MetalHookBobber3MinnowBait",
"geb_MetalHookBobber4WormBait", "geb_MetalHookBobber4RubberWormBait", "geb_MetalHookBobber4GrubWormBait", "geb_MetalHookBobber4GrassHopperBait", "geb_MetalHookBobber4FieldCricketBait", "geb_MetalHookBobber4MinnowBait",
"geb_MetalWormBait", "geb_MetalRubberWormBait", "geb_MetalGrubWormBait", "geb_MetalGrassHopperBait", "geb_MetalFieldCricketBait", "geb_MetalMinnowBait",
"geb_BoneRubberWormBait", "geb_BoneGrubWormBait", "geb_BoneGrassHopperBait", "geb_BoneFieldCricketBait", "geb_BoneMinnowBait",
"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
"geb_Bobber1", "geb_Bobber2", "geb_Bobber3", "geb_Bobber4",
"geb_BigGameFishingline", "geb_FlyFishingLine", "geb_SaltwaterFishingLine",
"geb_BoneHookBobber1WormBait", "geb_BoneHookBobber1RubberWormBait", "geb_BoneHookBobber1GrubWormBait", "geb_BoneHookBobber1GrassHopperBait", "geb_BoneHookBobber1FieldCricketBait", "geb_BoneHookBobber1MinnowBait","geb_BoneHookBobber2WormBait", "geb_BoneHookBobber2RubberWormBait", "geb_BoneHookBobber2GrubWormBait", "geb_BoneHookBobber2GrassHopperBait", "geb_BoneHookBobber2FieldCricketBait", "geb_BoneHookBobber2MinnowBait",
"geb_BoneHookBobber3WormBait", "geb_BoneHookBobber3RubberWormBait", "geb_BoneHookBobber3GrubWormBait", "geb_BoneHookBobber3GrassHopperBait", "geb_BoneHookBobber3FieldCricketBait", "geb_BoneHookBobber3MinnowBait",
"geb_BoneHookBobber4WormBait", "geb_BoneHookBobber4RubberWormBait", "geb_BoneHookBobber4GrubWormBait", "geb_BoneHookBobber4GrassHopperBait", "geb_BoneHookBobber4FieldCricketBait", "geb_BoneHookBobber4MinnowBait",
"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" };

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		for (int i = 0; i < ItemArray.Count(); i++)
		{
			if (item.IsKindOf(ItemArray.Get(i)))
			{
				return true;
			};
		}

		return false;
	}
};