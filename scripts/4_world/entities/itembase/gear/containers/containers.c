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
	ref TStringArray ItemArray = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_Minnow", "geb_Crayfish"};

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
	ref TStringArray ItemArray = { "Worm", "geb_Minnow", "geb_Crayfish", "geb_GrubWorm", "geb_GrassHopper", "geb_FieldCricket", "geb_RubberWorm" };

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
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_OldRedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_OldGreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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



class geb_OldBlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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


class geb_OldPurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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


class geb_YellowTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_RedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_PurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_PinkTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_OrangeTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_LimeTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_LightBlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_GreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_FunYellowTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_FunRedTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_FunPurpleTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_FunGreenTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_CamoTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_BrownTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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

class geb_BlueTackleBox : Container_Base
{
	ref TStringArray ItemArray = { "geb_Lure1", "geb_Lure2","geb_Lure3","geb_Lure4","geb_OrangeFishGloves", "geb_BlueFishGloves", "geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet", "Hook", 
		"geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
		"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_PurpleFishKnife", "geb_RedFishKnife" 
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