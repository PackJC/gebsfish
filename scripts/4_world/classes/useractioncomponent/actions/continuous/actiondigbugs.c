class ActionDigBugsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent;
		time_spent = UATimeSpent.DIG_WORMS;
		time_spent = time_spent * 1.2;
		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class ActionDigBugs: ActionContinuousBase
{

	auto insect_map = new map<string, float>();
	insect_map["FieldCricket"] = FIELDCRICKET_CHANCE;
	insect_map["GrassHopper"] = GRASSHOPPER_CHANCE;
	float GRASSHOPPER_CHANCE = 50;
	float FIELDCRICKET_CHANCE = 50;
	float insect_chance_sum;
	string selected_insect = "";
	float rndInsect;


	void ActionDigBugs()
	{
		m_CallbackClass = ActionDigBugsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "Look for bugs!";
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
		foreach(auto insect_name, auto insect_chance : insect_map) {
			insect_chance_sum += insect_chance;
		}

		rndInsect = Math.RandomFloatInclusive(0.0, insect_chance_sum);

		foreach(auto _insect_name, auto _insect_chance: insect_map) {
			if (rndInsect <= _insect_chance && _insect_chance > 0) {
				selected_insect = _insect_name;
				break;
			}
			rndInsect -= _insect_chance;
		}



		ItemBase bugs;
		bugs = ItemBase.Cast(GetGame().CreateObject(selected_insect, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
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