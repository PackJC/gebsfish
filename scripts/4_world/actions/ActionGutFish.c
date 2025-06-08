modded class ActionGutFish
{
    override void CreateActionComponent()
    {
        float baseTime = UATimeSpent.GUTTING;
        ItemBase tool = ItemBase.Cast(m_Data.m_MainItem);

        if (tool && tool.IsKindOf("geb_FishKnife_Base"))
        {
            baseTime *= 0.85; // 15% faster
        }

        m_ActionData.m_ActionComponent = new CAContinuousTime(baseTime);
    }
}