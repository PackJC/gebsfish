/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class ActionBambooFishingNetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent;
		time_spent = UATimeSpent.DIG_WORMS;
		time_spent = time_spent * 1.2;
		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class ActionBambooFishingNet : ActionContinuousBase
{
	void ActionBambooFishingNet()
	{
		m_CallbackClass = ActionBambooFishingNetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_POKE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_Text = "#STR_gatherminnows";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player.IsPlacingLocal() )
			return false;
		
		// Check if player is standing on terrain
		vector plr_pos = player.GetPosition();
		float height = GetGame().SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;
		
		if ( height > 0.4 )
			return false; // Player is not standing on ground
		
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( !player.IsPlacingLocal() /*&& player.IsCurrentCameraAimedAtGround()*/ )
			{
				if ( target )
				{
					string surface_type;
					vector position;
					position = target.GetCursorHitPos();
					GetGame().SurfaceGetType( position[0], position[2], surface_type );
					if (GetGame().SurfaceIsPond(position[0], position[2]) || GetGame().SurfaceIsSea(position[0], position[2]))
					{
						return true;
					}
				}
			}
		
			return false;
		}
		else
		{
			return true;
		}
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( item )
			{
				SetDiggingAnimation( item );
			}
			
			return true;
		}
		
		return false;
	}

	override bool HasTarget()
	{
		return true;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		ItemBase bugs;
		Class.CastTo(bugs, GetGame().CreateObjectEx("geb_Minnow", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));

		//bugs.SetQuantity(100, false);
		//MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);









	}
	
	void SetDiggingAnimation( ItemBase item )
	{
		if (item.KindOf("CatchBugs"))
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		}
		else
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		}
	}
};