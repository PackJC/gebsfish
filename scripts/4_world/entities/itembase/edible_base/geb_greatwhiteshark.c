/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

//Added so fish cannot be put into cargo, it is simply too large


class geb_Greatwhiteshark extends Edible_Base
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

	override bool CanReceiveItemIntoHands(EntityAI item_to_hands)
	{
		return false;
	}

	override bool CanSaveItemInHands(EntityAI item_in_hands)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}


	override bool CanPutInCargo(EntityAI item)
    {
        if (!super.CanPutInCargo(item))
            return false;

        // only handle licenses with special logic
        if (item.IsKindOf("Transport"))
        {
                return true;
        }

        return false;
    }

	override bool CanLoadItemIntoCargo(EntityAI item)
    {
        if (!super.CanLoadItemIntoCargo(item))
            return false;

        // only handle licenses with special logic
        if (item.IsKindOf("Transport"))
        {
                return true;
        }

        return false;
    }
	override bool IsTakeable()
	{
		return false;
	}

}