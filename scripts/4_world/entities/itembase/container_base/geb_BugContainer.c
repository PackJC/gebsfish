/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class geb_BugContainer extends Container_Base
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
		AddAction(ActionDigBugs);
	}
}