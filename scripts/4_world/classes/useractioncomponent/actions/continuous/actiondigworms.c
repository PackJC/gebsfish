modded class ActionDigWormsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent;
		time_spent = UATimeSpent.DIG_WORMS;
		time_spent = time_spent * 1.2;
		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

modded class ActionDigWorms: ActionContinuousBase
{

	static ref map<string, float> worm_map = new map<string, float>();
	static float WORM_CHANCE = 50;
	static float GRUBWORM_CHANCE = 50;
	static float worm_chance_sum;
	static string selected_worm = "";
	static float rndWorm;


	void ActionDigWorms()
	{
		worm_map["Worm"] = WORM_CHANCE;
		worm_map["GrubWorm"] = GRUBWORM_CHANCE;

		m_CallbackClass = ActionDigBugsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "Look for worms!";
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
			if ( !player.IsPlacingLocal() )
			{
				if ( target )
				{
					string surface_type;
					vector position;
					position = target.GetCursorHitPos();
					GetGame().SurfaceGetType( position[0], position[2], surface_type );					
					if ( GetGame().IsSurfaceFertile(surface_type) )
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
		foreach(auto worm_name, auto worm_chance : worm_map) {
			worm_chance_sum += worm_chance;
		}

		rndWorm = Math.RandomFloatInclusive(0.0, worm_chance_sum);

		foreach(auto _worm_name, auto _worm_chance: worm_map) {
			if (rndWorm <= _worm_chance && _worm_chance > 0) {
				selected_worm = _worm_name;
				break;
			}
			rndWorm -= _worm_chance;
		}



		ItemBase bugs;
		bugs = ItemBase.Cast(GetGame().CreateObject(selected_worm, action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		bugs.SetQuantity(10, false);
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
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