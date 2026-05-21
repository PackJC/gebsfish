/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class ActionDigBugsCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		float time_spent;
		time_spent = UATimeSpent.DIG_WORMS;
		time_spent = time_spent * 1.2;
		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class ActionDigBugs : ActionContinuousBase {
	void ActionDigBugs() {
		m_CallbackClass = ActionDigBugsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#STR_action_digbugs";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}

	bool IsValidBugDigSurface(ActionTarget target) {
		if (!target)
			return false;

		string surface_type;
		vector position = target.GetCursorHitPos();
		g_Game.SurfaceGetType(position[0], position[2], surface_type);

		// Keep the client prompt and the server completion rule identical.
		// This prevents the server from accepting bug digging on non-fertile
		// terrain just because the client was allowed to start the action.
		return g_Game.IsSurfaceFertile(surface_type);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsPlacingLocal())
			return false;

		vector plr_pos = player.GetPosition();
		float height = g_Game.SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;

		if (height > 0.4)
			return false;

		return IsValidBugDigSurface(target);
	}

	override bool ActionConditionContinue(ActionData action_data) {
		return true;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL) {
		if (super.SetupAction(player, target, item, action_data, extra_data)) {
			if (item) {
				SetDiggingAnimation(item);
			}
			return true;
		}
		return false;
	}

	override bool HasTarget() {
		return true;
	}

	// Returns the find chance from the config, clamped to [0, 1]. Defaults to
	// 1.0 (always finds) when the config is unavailable so missing config
	// never blocks the action.
	float GetDigBugsFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.ForageSettings)
			return 1.0;

		float chance = m_gebsConfig.ForageSettings.DigBugsFindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		float bugSum = 0.0;
		float rndBug = 0.0;
		string selectedBug = "";

		if (!m_gebsConfig || !m_gebsConfig.Bugs || m_gebsConfig.Bugs.Count() == 0) {
			return;
		}

		// Per-attempt find chance gate. Tool damage still applies on a miss
		// so the action has a cost even when nothing is found.
		float findChance = GetDigBugsFindChance();
		if (findChance < 1.0 && Math.RandomFloat01() > findChance) {
			MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
			return;
		}

		// Calculate the total spawn chance for valid bug entries only.
		// Blank classnames and zero/negative chances are ignored so they cannot
		// steal roll range from real bugs or try to spawn an empty classname.
		foreach (BugEntry bug1 : m_gebsConfig.Bugs) {
			if (!bug1 || bug1.Classname == "" || bug1.CatchChance <= 0)
				continue;

			bugSum += bug1.CatchChance;
		}

		if (bugSum <= 0) {
			return;
		}

		// Generate a random value within the total spawn chance
		rndBug = Math.RandomFloatInclusive(0.0, bugSum);

		// Select a bug from the same filtered set used for the total above.
		foreach (BugEntry bug : m_gebsConfig.Bugs) {
			if (!bug || bug.Classname == "" || bug.CatchChance <= 0)
				continue;

			if (rndBug <= bug.CatchChance) {
				selectedBug = bug.Classname;
				break;
			}
			rndBug -= bug.CatchChance;
		}

		// Spawn the selected bug if one was found
		if (selectedBug != "") {
			ItemBase bugs = ItemBase.Cast(g_Game.CreateObject(selectedBug, action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
			if (bugs) {
				bugs.SetQuantity(10, false);
			}
		}

		// Apply damage to the main item and update player's specialty weight
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}

	void SetDiggingAnimation(ItemBase item) {
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
