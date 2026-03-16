modded class ActionSkinningCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		ItemBase tool = m_ActionData.m_MainItem;

		if (tool && tool.IsKindOf("geb_FishKnife_Base"))
		{
			m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.TEST_BLOOD);
			return;
		}

		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SKIN);
	}
}