/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// "Assemble drying rack": empty-handed, at a Fish Drying Rack Kit lying on the
// ground with all six long sticks in its slot (geb_fishdryingrack.c), lash the
// frame together, for vanilla's empty-handed building time. The animation is
// vanilla's empty-handed full-body work loop (ActionMineBushByHand's
// CMD_ACTIONFB_INTERACT): the building one (CMD_ACTIONFB_ASSEMBLE) needs a tool
// in the hands, and without one it never reached its loop, so the action never
// finished and the player stood frozen (Cole, 2026-10-14).
class GebActionAssembleDryingRackCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BASEBUILDING_CONSTRUCT_SLOW);
	}
};

class GebActionAssembleDryingRack : ActionContinuousBase {
	void GebActionAssembleDryingRack() {
		m_CallbackClass = GebActionAssembleDryingRackCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#STR_action_assembledryingrack";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}

	override typename GetInputType() {
		return ContinuousInteractActionInput;
	}

	override bool HasTarget() {
		return true;
	}

	override bool UseMainItem() {
		return false;
	}

	override bool HasProgress() {
		return true;
	}

	override bool CanBeUsedLeaning() {
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsPlacingLocal() || player.IsPlacingServer())
			return false;
		geb_FishDryingRackKit kit = geb_FishDryingRackKit.Cast(target.GetObject());
		return kit && kit.GebCanAssemble();
	}

	override void OnFinishProgressServer(ActionData action_data) {
		geb_FishDryingRackKit kit = geb_FishDryingRackKit.Cast(action_data.m_Target.GetObject());
		if (!kit)
			return;
		kit.GebAssemble();
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}
};
