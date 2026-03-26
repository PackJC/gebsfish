modded class ActionDigWorms
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		PlayerBase player = action_data.m_Player;
		if (!player || !action_data.m_MainItem || !action_data.m_Target)
			return;

		int amount = action_data.m_MainItem.GetOnDigWormsAmount();
		float grubChance = 0.25;

		for (int i = 0; i < amount; i++)
		{
			string spawnType = "Worm";

			if (Math.RandomFloat01() < grubChance)
				spawnType = "geb_GrubWorm"; // replace with your real classname if different

			GetGame().CreateObjectEx(spawnType, action_data.m_Target.GetCursorHitPos(), ECE_PLACE_ON_SURFACE);
		}

		MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 4);
	}
}