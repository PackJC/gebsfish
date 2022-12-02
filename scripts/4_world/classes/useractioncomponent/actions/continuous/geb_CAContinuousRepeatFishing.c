/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class CAContinuousRepeatFishing : CAContinuousRepeat
{
	EntityAI geb_AmbientFish;
	void CAContinuousRepeatFishing( float time_to_complete_action )
	{
		m_DefaultTimeToComplete = time_to_complete_action;
	}
  
	override int Execute( ActionData action_data )
	{
		geb_AmbientFish = EntityAI.Cast(GetGame().CreateObject("geb_Ambientfish1", action_data.m_Target.GetCursorHitPos() , false));
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetGame().ObjectDelete, 20000, false, geb_AmbientFish);

		if ( !action_data.m_Player )
		{
			return UA_ERROR;
		}
  
		if ( m_TimeElpased < m_TimeToComplete )
		{
			m_TimeElpased += action_data.m_Player.GetDeltaT();
			m_TotalTimeElpased += action_data.m_Player.GetDeltaT();
		
			return UA_PROCESSING;
		}

		else
		{
			m_SpentUnits.param1 = m_TimeElpased;
			SetACData(m_SpentUnits);
			m_TimeElpased = m_TimeToComplete - m_TimeElpased;
			OnCompletePogress(action_data);
			FishingActionData fad = FishingActionData.Cast(action_data);
			if (fad && fad.m_FishingResult != -1)
			{
				return UA_FINISHED;
			}
			else
			{
				return UA_PROCESSING;
			}
		}
	}
 };

 /*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/