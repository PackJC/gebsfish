/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class Trap_SmallFish extends TrapSpawnBase
{
	override void SpawnCatch()
	{
		super.SpawnCatch();

		m_CatchesPond.Clear();
		m_CatchesPond.Insert("Bitterlings", 1);
		m_CatchesPond.Insert("geb_Crayfish", 2);
		m_CatchesPond.Insert("geb_Minnow", 3);
		m_CatchesPond.Insert("geb_Slimysculpin", 4);
		m_CatchesPond.Insert("geb_Mussel", 5);
		m_CatchesPond.Insert("geb_Blackdevilsnail", 6);

		m_CatchesSea.Clear();
		m_CatchesSea.Insert("Sardines", 1);
		m_CatchesSea.Insert("geb_Shrimp", 2);
		m_CatchesSea.Insert("geb_Bloodclam", 3);
		m_CatchesSea.Insert("geb_Starfish", 4);
		m_CatchesSea.Insert("geb_Jellyfish", 5);
	}


	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!attachment.IsInherited(Worm))
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}
}

modded class Trap_SmallFish extends TrapSpawnBase
{

}
