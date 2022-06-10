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
		m_CatchesPond.Insert("Crayfish", 1);
		m_CatchesPond.Insert("Mussel", 2);
		m_CatchesPond.Insert("Largemouthbass", 3);
		m_CatchesPond.Insert("Whitebass", 4);
		m_CatchesPond.Insert("Blackbass", 5);
		m_CatchesPond.Insert("Trout", 6);
		m_CatchesPond.Insert("Minnow", 7);
		m_CatchesPond.Insert("Bluegill", 8);
		m_CatchesPond.Insert("Slimysculpin", 9);
		m_CatchesPond.Insert("Carp", 10);
		m_CatchesPond.Insert("Blackdevilsnail", 11);
		m_CatchesSea.Clear();
		m_CatchesSea.Insert("Asianseabass", 1);
		m_CatchesSea.Insert("Bloodclam", 2);
		m_CatchesSea.Insert("Bonita", 3);
		m_CatchesSea.Insert("Cherrysalmon", 4);
		m_CatchesSea.Insert("Pacificcod", 5);
		m_CatchesSea.Insert("Shrimp", 6);
		m_CatchesSea.Insert("Asianseabass", 7);
		m_CatchesSea.Insert("Starfish", 8);
		m_CatchesSea.Insert("Kingcrab", 9);
		m_CatchesSea.Insert("Jellyfish", 10);
		m_CatchesSea.Insert("Lobster", 11);
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
