
class WormContainer : Container_Base 
{
	ref TStringArray ItemArray = { "Worm", "GrubWorm", "RubberWorm" };

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

class BugContainer : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm"};

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


class BambooFishingNet : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm", "Minnow", "Shrimp", "Crayfish"};

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

class MinnowBucket : Container_Base
{
	ref TStringArray ItemArray = { "Worm", "Minnow", "Crayfish", "Shrimp", "GrubWorm", "GrassHopper", "FieldCricket", "RubberWorm" };

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

class SmallTackle : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4", "OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class OldRedTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class OldGreenTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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



class OldBlueTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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


class OldPurpleTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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


class YellowTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class RedTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class PurpleTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class PinkTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class OrangeTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class LimeTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class LightBlueTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class GreenTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class FunYellowTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class FunRedTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class FunPurpleTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class FunGreenTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4", "OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class CamoTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4", "OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class BrownTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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

class BlueTackleBox : Container_Base 
{
	ref TStringArray ItemArray = { "Lure1", "Lure2","Lure3","Lure4","OrangeFishGloves", "BlueFishGloves", "WormContainer", "BugContainer", "Geb_FishingNet", "Hook", "MetalHookBobber1", "MetalHookBobber2", "MetalHookBobber3", "MetalHookBobber4", "BoneHookBobber1", "BoneHookBobber2", "BoneHookBobber3", "BoneHookBobber4", "MetalHook", "GrassHopper", "FieldCricket", "GrubWorm", "RubberWorm",
"MetalHookBobber1WormBait", "MetalHookBobber1RubberWormBait", "MetalHookBobber1GrubWormBait", "MetalHookBobber1GrassHopperBait", "MetalHookBobber1FieldCricketBait", "MetalHookBobber1MinnowBait",
"MetalHookBobber2WormBait", "MetalHookBobber2RubberWormBait", "MetalHookBobber2GrubWormBait", "MetalHookBobber2GrassHopperBait", "MetalHookBobber2FieldCricketBait", "MetalHookBobber2MinnowBait",
"MetalHookBobber3WormBait", "MetalHookBobber3RubberWormBait", "MetalHookBobber3GrubWormBait", "MetalHookBobber3GrassHopperBait", "MetalHookBobber3FieldCricketBait", "MetalHookBobber3MinnowBait",
"MetalHookBobber4WormBait", "MetalHookBobber4RubberWormBait", "MetalHookBobber4GrubWormBait", "MetalHookBobber4GrassHopperBait", "MetalHookBobber4FieldCricketBait", "MetalHookBobber4MinnowBait",
"MetalWormBait", "MetalRubberWormBait", "MetalGrubWormBait", "MetalGrassHopperBait", "MetalFieldCricketBait", "MetalMinnowBait",
"BoneRubberWormBait", "BoneGrubWormBait", "BoneGrassHopperBait", "BoneFieldCricketBait", "BoneMinnowBait",
"SpinnerBait1", "SpinnerBait2", "SpinnerBait3", "SpinnerBait4",
"Bobber1", "Bobber2", "Bobber3", "Bobber4",
"BigGameFishingline", "FlyFishingLine", "SaltwaterFishingLine",
"BoneHookBobber1WormBait", "BoneHookBobber1RubberWormBait", "BoneHookBobber1GrubWormBait", "BoneHookBobber1GrassHopperBait", "BoneHookBobber1FieldCricketBait", "BoneHookBobber1MinnowBait","BoneHookBobber2WormBait", "BoneHookBobber2RubberWormBait", "BoneHookBobber2GrubWormBait", "BoneHookBobber2GrassHopperBait", "BoneHookBobber2FieldCricketBait", "BoneHookBobber2MinnowBait",
"BoneHookBobber3WormBait", "BoneHookBobber3RubberWormBait", "BoneHookBobber3GrubWormBait", "BoneHookBobber3GrassHopperBait", "BoneHookBobber3FieldCricketBait", "BoneHookBobber3MinnowBait",
"BoneHookBobber4WormBait", "BoneHookBobber4RubberWormBait", "BoneHookBobber4GrubWormBait", "BoneHookBobber4GrassHopperBait", "BoneHookBobber4FieldCricketBait", "BoneHookBobber4MinnowBait",
"BlueFishKnife", "OrangeFishKnife", "GreenFishKnife", "YellowFishKnife", "PurpleFishKnife", "RedFishKnife" };

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