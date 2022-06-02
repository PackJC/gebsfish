//Needed to register the action

modded class BambooFishingNet extends Container_Base
{
	override bool IsContainer()
	{
		return true;         
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( parent && (parent.IsKindOf("BugCatcher")) )
		{
			return false;
		}
		
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBambooFishingNet);

	}
}