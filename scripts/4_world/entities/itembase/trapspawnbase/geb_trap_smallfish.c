modded class Trap_SmallFish extends TrapSpawnBase
{
	override void SpawnCatch()
	{
		super.SpawnCatch();

		m_CatchesPond.Clear();
		m_CatchesPond.Insert("Bitterlings", 1);
		m_CatchesPond.Insert("Crayfish", 2);
		m_CatchesPond.Insert("Minnow", 3);
		m_CatchesPond.Insert("Slimysculpin", 4);
		m_CatchesPond.Insert("Mussel", 5);
		m_CatchesPond.Insert("Blackdevilsnail", 6);

		m_CatchesSea.Clear();
		m_CatchesSea.Insert("Sardines", 1);
		m_CatchesSea.Insert("Shrimp", 2);
		m_CatchesSea.Insert("Bloodclam", 3);
		m_CatchesSea.Insert("Starfish", 4);
		m_CatchesSea.Insert("Jellyfish", 5);

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
