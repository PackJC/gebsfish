/*

  CREATED BY PACKJC
  https://smokymountainsoftware.com
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  https://www.smokymountainsoftware.com/Contributions welcome via github

*/


class geb_FilteredContainerBase : Container_Base
{
	protected TStringArray GetAllowedItemKinds()
	{
		return null;
	}

	override int GetDamageSystemVersionChange()
	{
		return 110;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		TStringArray allowed = GetAllowedItemKinds();
		if (!allowed || allowed.Count() == 0)
			return false;

		for (int i = 0; i < allowed.Count(); i++)
		{
			if (item && item.IsKindOf(allowed.Get(i)))
				return true;
		}

		return false;
	}
};

class geb_WormContainer : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = { "Worm", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_BugContainer : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm" };

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_BambooFishingNet : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = { "Worm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm", "geb_RubberWorm", "geb_Minnow", "geb_SignalCrayFish", "geb_EuropeanCrayFish" };

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_MinnowBucket : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = { "geb_FatheadMinnow", "geb_SignalCrayFish", "geb_EuropeanCrayFish", "Shrimp" };

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_SmallTackleBase : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = {
		"Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves",
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"Hook", "geb_FishKnife_Base", "BoneKnife", "BoneHook", "Pliers"
	};

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_LargeTackleBase : geb_FilteredContainerBase
{
	static ref TStringArray s_Allowed = {
		"Jig", "geb_OrangeFishGloves", "geb_BlueFishGloves",
		"geb_WormContainer", "geb_BugContainer", "geb_BambooFishingNet",
		"Hook", "geb_FishKnife_Base", "BoneKnife", "BoneHook",
		"Cleaver", "CombatKnife", "HuntingKnife", "ak_bayonet", "m9a1_bayonet",
		"Pliers", "Screwdriver", "Steakknife", "stoneknife"
	};

	override protected TStringArray GetAllowedItemKinds()
	{
		return s_Allowed;
	}
};

class geb_SmallTackle : geb_SmallTackleBase {};
class geb_OldRedTackle : geb_LargeTackleBase {};
class geb_OldGreenTackle : geb_LargeTackleBase {};
class geb_OldBlueTackle : geb_LargeTackleBase {};
class geb_OldPurpleTackle : geb_LargeTackleBase {};
class geb_Tackle_Base : geb_LargeTackleBase {};