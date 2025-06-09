/*

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

*/

