class FishingRodRepairKit : ItemBase
{
    override bool CanBeUsedToRepair(ItemBase item)
    {
        return item.IsKindOf("FishingRod_Base");
    }

    override void OnApply(ItemBase target)
    {
        super.OnApply(target);

        if (!target) return;

        float currentHealth = target.GetHealth("", "");
        float maxHealth = target.GetMaxHealth("", "");
        float newHealth = currentHealth + (maxHealth * 0.10); // repair 10%

        // Don't exceed max health
        if (newHealth > maxHealth) newHealth = maxHealth;

        target.SetHealth("", "", newHealth);

        // Reduce quantity
        AddQuantity(-1);
    }

    override bool CanRepair(ItemBase item)
    {
        return CanBeUsedToRepair(item);
    }

    override bool HasQuantity()
    {
        return true;
    }

    override float GetQuantityMax()
    {
        return 4;
    }

    override string GetQuantityFormat()
    {
        return "0";
    }

    override bool CanBeSplit()
    {
        return false;
    }
}
