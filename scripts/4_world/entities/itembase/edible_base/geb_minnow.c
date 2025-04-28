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