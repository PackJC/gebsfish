/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class ActionBambooFishingNetCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		float time_spent;
		time_spent = UATimeSpent.DIG_WORMS;
		time_spent = time_spent * 1.2;
		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class ActionBambooFishingNet : ActionContinuousBase {
	void ActionBambooFishingNet() {
		m_CallbackClass = ActionBambooFishingNetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_POKE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_Text = "#STR_action_gatherminnows";
	}
	
	override void CreateConditionComponents() {	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}

	bool IsValidFishingNetSurface(ActionTarget target) {
		if (!target)
			return false;

		vector position = target.GetCursorHitPos();

		// Bamboo nets are meant for pond/sea water. Run the same check on the
		// server as the client prompt so the action cannot complete from dry land.
		return g_Game.SurfaceIsPond(position[0], position[2]) || g_Game.SurfaceIsSea(position[0], position[2]);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) {
		if ( player.IsPlacingLocal() )
			return false;
		
		// Check if player is standing on terrain
		vector plr_pos = player.GetPosition();
		float height = g_Game.SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;
		
		if ( height > 0.4 )
			return false; // Player is not standing on ground
		
		return IsValidFishingNetSurface(target);
	}
	
	override bool ActionConditionContinue( ActionData action_data ) {
		return true;
	}
	
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL ) {	
		if( super.SetupAction( player, target, item, action_data, extra_data ) ) {
			if ( item ) {
				SetDiggingAnimation( item );
			}
			return true;
		}
		return false;
	}

	override bool HasTarget() {
		return true;
	}

override void OnFinishProgressServer(ActionData action_data)
{
    PlayerBase player = action_data.m_Player;
    ItemBase net = action_data.m_MainItem;

    int roll = Math.RandomInt(0, 3); // 0, 1, or 2 — equal chance

    switch (roll)
    {
        case 0:
            g_Game.CreateObjectEx("geb_FatHeadMinnow", player.GetPosition(), ECE_PLACE_ON_SURFACE);
            break;

        case 1:
            g_Game.CreateObjectEx("geb_AmericanBullFrog", player.GetPosition(), ECE_PLACE_ON_SURFACE);
            break;

        case 2:
            g_Game.CreateObjectEx("geb_RedSalamander", player.GetPosition(), ECE_PLACE_ON_SURFACE);
            break;
    }

    player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

    if (net)
        net.DecreaseHealth("", "", 5);
}
	
	void SetDiggingAnimation( ItemBase item ) {
		if (item.KindOf("CatchBugs")) {
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		}
		else {
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		}
	}
};
