class ModdedActionSkinningCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        float time_spent = UATimeSpent.SKIN;

        ItemBase tool = m_ActionData.m_MainItem;
        Object target = m_ActionData.m_Target.GetObject();

        if (tool && tool.IsKindOf("geb_FishKnife_Base") && target && (target.IsKindOf("geb_FreshFish_Base") || target.IsKindOf("geb_SaltFish_Base")))
        {
            time_spent *= 0.25;
            Print(">> Fast fish knife skinning applied");
        }
        else
        {
            Print(">> Default skinning time used");
        }

        m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
    }
}

modded class ActionSkinning : ActionContinuousBase
{
    void ActionSkinning()
    {
        Print(">> Modded ActionSkinning constructor called!");
        m_CallbackClass = ModdedActionSkinningCB; // ← KEY CHANGE
        m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;

        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
        m_FullBody = true;
        m_Text = "#skin";
    }

    override void CreateConditionComponents()  
    {   
        Print(">> Using Modded ActionSkinning ConditionComponents!");
        m_ConditionItem   = new CCINonRuined();
        m_ConditionTarget = new CCTCursorNoRuinCheck();
    }
}