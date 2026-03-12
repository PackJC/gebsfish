modded class ActionSkinningCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent = UATimeSpent.SKIN;

		ItemBase tool = m_ActionData.m_MainItem;

		if (tool && tool.IsKindOf("geb_FishKnife_Base"))
		{
			
			time_spent = time_spent * 0.5; // 50% faster
			//time_spent = time_spent * 0.85; // 15% faster
		}

		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
}