/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class ActionChumWaterCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
};

// "Chum the Water" on Guts / SmallGuts: dump the guts into deep water to draw
// a short-lived school of spearable fish (GebsChumSystem). The other route to
// the same effect is simply throwing the guts into deep water -- see
// GebsChumSystem.OnGutsLocationChanged.
class ActionChumWater : ActionContinuousBase {
	void ActionChumWater() {
		m_CallbackClass = ActionChumWaterCB;
		// Pouring-out animation -- the closest vanilla full-body action to
		// emptying a pile of guts over the water.
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "#str_geb_action_chumwater";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		// LARGE (8m) so the cursor can reach water that is actually deep
		// enough -- the 6ft column rarely exists within arm's reach of the
		// shoreline. The throw route covers anything past that.
		m_ConditionTarget = new CCTSurface(UAMaxDistances.LARGE);
	}

	// Client-side gate; the dedicated server trusts the client here exactly
	// like ActionBambooFishingNet does (server-side surface queries against
	// the cursor position are unreliable), and the REAL validation runs again
	// inside GebsChumSystem.TryChumAt on finish.
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsPlacingLocal())
			return false;

		ChumConf conf = GebsChumSystem.GetConf();
		if (conf) {
			if (!conf.Enable)
				return false;
			// "Half or better health" gate -- rotten guts don't chum.
			if (item && item.GetHealth01("", "") * 100 < conf.GutsMinHealthPercent)
				return false;
		}

		if (g_Game.IsDedicatedServer())
			return true;

		if (!target)
			return false;
		vector cursor = target.GetCursorHitPos();
		if (!g_Game.SurfaceIsPond(cursor[0], cursor[2]) && !g_Game.SurfaceIsSea(cursor[0], cursor[2]))
			return false;

		// Only offer the action over water that is deep enough to matter, so
		// the player isn't sold a chum that TryChumAt will reject.
		if (conf) {
			float surfaceY;
			if (GebsChumSystem.GetWaterColumn(cursor[0], cursor[2], surfaceY) < conf.MinWaterDepth)
				return false;
		}
		return true;
	}

	override bool ActionConditionContinue(ActionData action_data) {
		return true;
	}

	override bool HasTarget() {
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		if (!action_data || !action_data.m_Player)
			return;

		PlayerBase player = action_data.m_Player;
		ItemBase guts = action_data.m_MainItem;

		vector chumPoint = player.GetPosition();
		if (action_data.m_Target)
			chumPoint = action_data.m_Target.GetCursorHitPos();

		// TryChumAt re-validates depth/enable server-side; only a school that
		// actually spawned consumes the guts.
		if (GebsChumSystem.TryChumAt(chumPoint, player, "ChumAction")) {
			player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
			if (guts)
				g_Game.ObjectDelete(guts);
		} else {
			player.MessageStatus(Widget.TranslateString("#str_geb_chum_tooshallow"));
		}
	}
};
