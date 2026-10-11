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
		// Crouch-only, set once here (the bug catcher is the only item with
		// this action). Like vanilla crafting, a standing player is moved into
		// a crouch before the dig starts, and standing up cancels it.
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
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

	override bool HasTarget() {
		return true;
	}

	// Returns the find chance from the consolidated DigBugsSettings section,
	// clamped to [0, 1]. Defaults to 1.0 (always finds) when the config is
	// unavailable so missing config never blocks the action.
	float GetDigBugsFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.DigBugsSettings)
			return 1.0;

		return Math.Clamp(m_gebsConfig.General.DigBugsSettings.FindChance, 0.0, 1.0);
	}

	override void OnFinishProgressServer(ActionData action_data) {
		int debugLevel = GebGetDebugLevel();

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

		// A completed dig always wears the tool and trains the skill, whether
		// or not anything is found below (matches dig-worms).
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.DigBugsSettings) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: config missing -- skipping", "DigBugs");
			return;
		}
		ref array<ref BugEntry> catches = m_gebsConfig.General.DigBugsSettings.Catches;
		if (!catches || catches.Count() == 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Dig-bugs: Catches table empty -- skipping", "DigBugs");
			return;
		}

		// Per-attempt find chance gate.
		float findChance = GetDigBugsFindChance();
		float findRoll;
		bool foundSomething = GebRollChance(findChance, findRoll);
		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Dig-bugs find-chance gate: findChance=" + findChance + " roll=" + findRoll + " result=" + foundSomething, "DigBugs");
		}
		if (!foundSomething)
			return;

		// Build the eligible pool once, then defer the roll to the shared
		// picker (single filter pass -> sum and walk can't disagree).
		TStringArray names = new TStringArray;
		TFloatArray weights = new TFloatArray;
		foreach (BugEntry bug : catches) {
			if (!bug || bug.Classname == "" || bug.CatchChance <= 0)
				continue;
			names.Insert(bug.Classname);
			weights.Insert(bug.CatchChance);
		}

		int pick = GebWeightedPick.Pick(names, weights, debugLevel, "DigBugs");
		if (pick < 0)
			return;
		string selectedBug = names[pick];

		// The bug goes into the Bug Catcher doing the digging, as the bamboo
		// net keeps its catch, and onto the spot the player dug when it doesn't
		// fit or isn't on the catcher's allow-list. The allow-list is checked by
		// classname first: CreateInInventory places a new item by type without
		// asking the cargo filter, so a refused type would go in now and be
		// thrown out at the next restart. Quantity 1 -- one bug per successful
		// dig. CreateObjectEx, NOT CreateObject: CreateObject's third param is
		// `bool create_local` (a flag there silently coerces to true and the
		// object never networks to clients); only CreateObjectEx takes ECE_ flags.
		if (selectedBug != "") {
			EntityAI catcher = action_data.m_MainItem;
			EntityAI bugEntity;
			geb_FilteredContainerBase filtered = geb_FilteredContainerBase.Cast(catcher);
			if (catcher && catcher.GetInventory() && (!filtered || filtered.GebAcceptsType(selectedBug)))
				bugEntity = catcher.GetInventory().CreateInInventory(selectedBug);
			if (!bugEntity)
				bugEntity = EntityAI.Cast(g_Game.CreateObjectEx(selectedBug, action_data.m_Target.GetCursorHitPos(), ECE_PLACE_ON_SURFACE));
			ItemBase bugs = ItemBase.Cast(bugEntity);
			if (bugs) {
				bugs.SetQuantity(1, false);
			}
		}
	}
};
