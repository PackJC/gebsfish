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

	// Returns the find chance from the consolidated DigBugsSettings section,
	// clamped to [0, 1]. Defaults to 1.0 (always finds) when the config is
	// unavailable so missing config never blocks the action.
	float GetDigBugsFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.DigBugsSettings)
			return 1.0;

		float chance = m_gebsConfig.DigBugsSettings.FindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		float bugSum = 0.0;
		float rndBug = 0.0;
		string selectedBug = "";

		int debugLevel = 0;
		if (m_gebsConfig && m_gebsConfig.GeneralSettings)
			debugLevel = m_gebsConfig.GeneralSettings.DebugLogs;

		// Guard action_data fields up front. Vanilla normally guarantees these
		// are populated when OnFinishProgressServer fires, but edge cases
		// (player disconnect mid-action, inventory wipe by another mod, item
		// destroyed by environment) can leave them null. Without these guards
		// the DealAbsoluteDmg / GetSoftSkillsManager calls below would crash.
		if (!action_data || !action_data.m_Player || !action_data.m_MainItem) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: action_data missing player or main item -- skipping", "DigBugs");
			return;
		}

		if (!m_gebsConfig || !m_gebsConfig.DigBugsSettings) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: config missing -- skipping", "DigBugs");
			return;
		}
		ref array<ref BugEntry> catches = m_gebsConfig.DigBugsSettings.Catches;
		if (!catches || catches.Count() == 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: Catches table empty -- skipping", "DigBugs");
			return;
		}

		// Per-attempt find chance gate. Tool damage still applies on a miss
		// so the action has a cost even when nothing is found.
		float findChance = GetDigBugsFindChance();
		float findRoll = -1;
		bool foundSomething = true;
		if (findChance < 1.0) {
			findRoll = Math.RandomFloat01();
			foundSomething = (findRoll <= findChance);
		}
		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Dig-bugs find-chance gate: findChance=" + findChance + " roll=" + findRoll + " result=" + foundSomething, "DigBugs");
		}
		if (!foundSomething) {
			MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
			return;
		}

		if (debugLevel == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---Dig-bugs weighted pick---", "DigBugs");
			GebsfishLogger.Debug("entry | classname | chance | included", "DigBugs");
		}

		// Calculate the total spawn chance for valid bug entries only.
		// Blank classnames and zero/negative chances are ignored so they cannot
		// steal roll range from real bugs or try to spawn an empty classname.
		int idx = 0;
		foreach (BugEntry bug1 : catches) {
			bool included = true;
			string reason = "";
			if (!bug1 || bug1.Classname == "" || bug1.CatchChance <= 0) {
				included = false;
				reason = "blank/zero";
			}
			if (debugLevel == ELEVATED_DEBUG) {
				string entryCls = "<null>";
				float entryChance = 0;
				if (bug1) {
					entryCls = bug1.Classname;
					entryChance = bug1.CatchChance;
				}
				string flag = "yes";
				if (!included)
					flag = "no (" + reason + ")";
				GebsfishLogger.Debug("" + idx + " | " + entryCls + " | " + entryChance + " | " + flag, "DigBugs");
			}
			if (included)
				bugSum += bug1.CatchChance;
			idx++;
		}

		if (bugSum <= 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: totalChance=0 after filter -- skipping", "DigBugs");
			return;
		}

		// Generate a random value within the total spawn chance
		rndBug = Math.RandomFloatInclusive(0.0, bugSum);
		float rndStart = rndBug;

		// Select a bug from the same filtered set used for the total above.
		foreach (BugEntry bug : catches) {
			if (!bug || bug.Classname == "" || bug.CatchChance <= 0)
				continue;

			if (rndBug <= bug.CatchChance) {
				selectedBug = bug.Classname;
				break;
			}
			rndBug -= bug.CatchChance;
		}

		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Dig-bugs picked: " + selectedBug + " roll=" + rndStart + " totalChance=" + bugSum, "DigBugs");
		}

		// Spawn the selected bug if one was found. Quantity 1 -- one bug per
		// successful dig. Previously SetQuantity(10) was hardcoded and got
		// silently clamped to the item's max stack (5 for most bugs).
		if (selectedBug != "") {
			ItemBase bugs = ItemBase.Cast(g_Game.CreateObject(selectedBug, action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
			if (bugs) {
				bugs.SetQuantity(1, false);
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
