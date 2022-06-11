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
		m_CatchesPond.Insert("geb_Largemouthbass", 3);
		m_CatchesPond.Insert("geb_Whitebass", 4);
		m_CatchesPond.Insert("geb_Blackbass", 5);
		m_CatchesPond.Insert("geb_Trout", 6);
		m_CatchesPond.Insert("geb_Minnow", 7);
		m_CatchesPond.Insert("geb_Bluegill", 8);
		m_CatchesPond.Insert("geb_Slimysculpin", 9);
		m_CatchesPond.Insert("Carp", 10);
		m_CatchesPond.Insert("geb_Blackdevilsnail", 11);
		m_CatchesSea.Clear();
		m_CatchesSea.Insert("geb_Asianseabass", 1);
		m_CatchesSea.Insert("geb_Bloodclam", 2);
		m_CatchesSea.Insert("geb_Bonita", 3);
		m_CatchesSea.Insert("geb_Cherrysalmon", 4);
		m_CatchesSea.Insert("geb_Pacificcod", 5);
		m_CatchesSea.Insert("geb_Shrimp", 6);
		m_CatchesSea.Insert("geb_Asianseabass", 7);
		m_CatchesSea.Insert("geb_Starfish", 8);
		m_CatchesSea.Insert("geb_Kingcrab", 9);
		m_CatchesSea.Insert("geb_Jellyfish", 10);
		m_CatchesSea.Insert("geb_Lobster", 11);
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
