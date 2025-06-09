modded class ActionSkinningCB
{
    override void CreateActionComponent()
    {
        // vanilla default
        float time_spent = UATimeSpent.SKIN;

        // shorten if our knife + fish
        ItemBase tool   = m_ActionData.m_MainItem;
        Object   target = m_ActionData.m_Target.GetObject();

        if (tool && tool.IsKindOf("geb_FishKnife_Base") && target && target.IsKindOf("Fish_Base"))
        {
            time_spent *= 0.85;                // 15 % faster
        }

        m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
    }
}

modded class ActionSkinning
{
    // better fillets & gentler knife wear  (only our knife on fish)
    override void OnFinishProgressServer(ActionData action_data)
    {
        super.OnFinishProgressServer(action_data);

        ItemBase tool    = action_data.m_MainItem;
        Object   target  = action_data.m_Target.GetObject();

        if (!tool || !tool.IsKindOf("geb_FishKnife_Base") || !target || !target.IsKindOf("Fish_Base"))
            return;

        /* Cut knife wear by half */
        float lost = tool.GetMaxHealth() - tool.GetHealth();
        tool.AddHealth(lost * 0.50);                 // restore 50 % of what was lost

        /* +20 % health to just-spawned fillets */
        array<Object> vicinity = {};
        g_Game.GetObjectsAtPosition(target.GetPosition(), 3.0, vicinity, null);

        foreach (Object obj : vicinity)
        {
            Edible_Base fillet;
            if ( Class.CastTo(fillet, obj) && fillet.IsKindOf("Edible_Base") )
            {
                if (fillet.GetLifetime() < 1)        // brand-new item
                {
                    float h = fillet.GetHealth01();
                    fillet.SetHealth01("", "", Math.Clamp(h + 0.20, 0, 1));
                }
            }
        }
    }
}
