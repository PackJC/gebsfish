/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class Trap_FishNet extends TrapSpawnBase
{

	override void SpawnCatch()
	{
		super.SpawnCatch();
		m_CatchesPond.Clear();
		m_CatchesPond.Insert("geb_Crayfish", 1);
		m_CatchesPond.Insert("geb_Mussel", 2);
		m_CatchesPond.Insert("geb_Catfish", 3);
		m_CatchesPond.Insert("geb_Minnow", 4);
		m_CatchesPond.Insert("geb_Slimysculpin", 5);
		m_CatchesPond.Insert("Carp", 6);
		m_CatchesPond.Insert("geb_Blackdevilsnail", 7);
		m_CatchesSea.Clear();
		m_CatchesSea.Insert("Mackerel", 1);
		m_CatchesSea.Insert("geb_Bloodclam", 2);
		m_CatchesSea.Insert("geb_Shrimp", 3);
		m_CatchesSea.Insert("geb_Starfish", 4);
		m_CatchesSea.Insert("geb_Kingcrab", 5);
		m_CatchesSea.Insert("geb_Jellyfish", 6);
		m_CatchesSea.Insert("geb_Lobster", 7);
		m_CatchesSea.Insert("geb_BlueLobster", 7);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!attachment.IsInherited(Worm))
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}
}

modded class Trap_FishNet extends TrapSpawnBase
{

}
