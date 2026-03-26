/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class geb_EdibleBase extends Edible_Base
{
	override bool CanBeCookedOnStick()
	{
		return false;
	}

	override bool CanBeCooked()
	{
		return false;
	}

	override bool IsCorpse()
	{
		return true;
	}

	override bool CanDecay()
	{
		return true;
	}

	override bool CanSaveItemInHands(EntityAI item_in_hands)
	{
		return false;
	}

	override bool IsHeavyBehaviour()
	{
		return true;
	}

	override bool IsTwoHandedBehaviour()
	{
		return true;
	}
}

class geb_AngelShark extends geb_EdibleBase {}
class geb_AtlanticBlueMarlin extends geb_EdibleBase {}
class geb_AtlanticSailFish extends geb_EdibleBase {}
class geb_GreatWhiteShark extends geb_EdibleBase {}
class geb_HammerHeadShark extends geb_EdibleBase {}
class geb_LeopardShark extends geb_EdibleBase {}
class geb_MahiMahi extends geb_EdibleBase {}
class geb_Sturgeon extends geb_EdibleBase {}

class geb_FatHeadMinnow extends Edible_Base {
    override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (InventorySlots.GetSlotName(slot_id) == "Bait")
		{
			SetAnimationPhase("bait_unhooked",1);
			SetAnimationPhase("bait_hooked",0);
		}
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		if (InventorySlots.GetSlotName(slot_id) == "Bait")
		{
			SetAnimationPhase("bait_unhooked",0);
			SetAnimationPhase("bait_hooked",1);
		}
	}
}