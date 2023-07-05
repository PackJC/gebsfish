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

	override int Execute( ActionData action_data )
	{
		vector fishingLineLocation = action_data.m_Target.GetCursorHitPos();
		geb_AmbientFish = EntityAI.Cast(GetGame().CreateObject("geb_Ambientfish1", action_data.m_Target.GetCursorHitPos() , false));
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater(GetGame().ObjectDelete, 15000, false, geb_AmbientFish);
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
			if(fad.m_FishingResult == 1){
				if ( !GetGame().IsDedicatedServer() ){
					//Play particle when user reels in fish
					Particle fishingCatchParticle = Particle.PlayInWorld(ParticleList.IMPACT_WATER_MEDIUM_ENTER, fishingLineLocation);
				}
			}
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
