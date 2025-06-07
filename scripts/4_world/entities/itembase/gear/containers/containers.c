/*

  CREATED BY PACKJC
  https://smokymountainsoftware.com
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  https://www.smokymountainsoftware.com/Contributions welcome via github

*/


//To restrict items in containers
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
	ref TStringArray ItemArray = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_Minnow", "geb_SignalCrayfish", "geb_EuropeanCrayfish"};

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
	ref TStringArray ItemArray = { "geb_FatheadMinnow", "geb_SignalCrayFish", "geb_EuropeanCrayFish", "Shrimp" };

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
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};


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

class geb_OldRedTackle : Container_Base
{
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};


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

class geb_OldGreenTackle : Container_Base
{
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};


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



class geb_OldBlueTackle : Container_Base
{
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};


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


class geb_OldPurpleTackle : Container_Base
{
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};


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


class geb_Tackle_Base : Container_Base
{
	ref TStringArray ItemArray = { "Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook",
		"geb_FishKnife_Base" 
	};

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

