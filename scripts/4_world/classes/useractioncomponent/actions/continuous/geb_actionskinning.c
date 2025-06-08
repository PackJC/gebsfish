
modded class ActionSkinning
{
    /* Faster only with our knife -- 0.85 × vanilla time
    ---------------------------------------------------------- */
    override void CreateActionComponent()
    {
        float time_spent = UATimeSpent.SKINNING;          // vanilla default

        ItemBase tool    = m_ActionData.m_MainItem;
        Object   target  = m_ActionData.m_Target.GetObject();

        if (  tool   && tool.IsKindOf("geb_FishKnife_Base")
           && target && target.IsKindOf("Fish_Base") )
        {
            time_spent *= 0.85;        // 15 % faster
        }

        m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
    }

    /*  Better fillets & gentler durability loss
    ------------------------------------------------
       Fires once the cut finishes on the SERVER. */
    override void OnFinishProgressServer( ActionData action_data )
    {
        super.OnFinishProgressServer(action_data);   // <-- let vanilla spawn fillets

        ItemBase tool    = action_data.m_MainItem;
        Object   target  = action_data.m_Target.GetObject();

        if (  !tool   || !tool.IsKindOf("geb_FishKnife_Base")
           || !target || !target.IsKindOf("Fish_Base") )
            return;   // not our knife or not a fish → leave vanilla values

        /* 2-A  Reduce knife wear (½ vanilla loss) */
        float old_hp_tool = tool.GetHealth();                  // absolute health points
        float loss        = (tool.GetMaxHealth() - old_hp_tool) * 0.50;
        tool.SetHealth(old_hp_tool + loss);                    // restore 50 % of lost HP

        /* 2-B  Boost quality of every fillet spawned ( +20 % health ) */
        array<Object> vicinity = new array<Object>;
        g_Game.GetObjectsAtPosition(action_data.m_Player.GetPosition(), 3.0, vicinity, null);

        foreach (Object obj : vicinity)
        {
            Edible_Base fillet;
            if ( Class.CastTo(fillet, obj) && fillet.IsKindOf("Edible_Base") )
            {
                // only very fresh fillets (spawned this frame)
                if ( fillet.GetLifetime() < 1 )
                {
                    float h = fillet.GetHealth01();
                    fillet.SetHealth01( "", "", Math.Clamp( h + 0.20, 0, 1 ) );
                }
            }
        }
    }
}