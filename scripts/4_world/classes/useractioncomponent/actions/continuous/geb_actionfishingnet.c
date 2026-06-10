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
	// Constructor values intentionally match master. The bamboo net's
	// itemInfo[] in data/tools/config.cpp is "CatchWithNet", so
	// SetDiggingAnimation routes through the CatchWithNet branch and sets
	// STANCEMASK_ERECT | STANCEMASK_CROUCH -- the CROUCH from the
	// constructor stays compatible. Any tag that flips SetDiggingAnimation
	// to the ERECT-only fallback branch will hang the action because the
	// constructor's CROUCH is then incompatible. See commit history for the
	// regression that taught us this.
	void ActionBambooFishingNet() {
		m_CallbackClass = ActionBambooFishingNetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_POKE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		// Match ActionDigBugs so netting grants the same toughness progression
		// as the other manual gathering actions. Without this the AddSpecialty
		// call in OnFinishProgressServer adds the unset base-class default (0).
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#STR_action_gatherminnows";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}

	// Client-only water-surface validation. Pulled into a helper so callers
	// stay readable, but the actual ActionCondition still trusts the
	// dedicated server (returns true) -- server-side SurfaceIsPond/Sea
	// against target.GetCursorHitPos() is unreliable here and rejecting
	// valid casts leaves the client waiting forever for action confirmation.
	bool IsValidFishingNetSurface(ActionTarget target) {
		if (!target)
			return false;

		vector position = target.GetCursorHitPos();
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

		// Dedicated server trusts the client's surface validation. See helper
		// comment for why server-side validation breaks here.
		if (g_Game.IsDedicatedServer())
			return true;

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

	// Returns the find chance from the consolidated BambooFishingNetSettings
	// section, clamped to [0, 1]. Defaults to 1.0 (always finds) when the
	// config is unavailable.
	float GetFishingNetFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.BambooFishingNetSettings)
			return 1.0;

		float chance = m_gebsConfig.General.BambooFishingNetSettings.FindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	// Weighted-random spawn classname from BambooFishingNetSettings.Catches.
	// Mirrors the pattern used by ActionDigWorms / ActionDigBugs so server
	// admins can edit what comes out of the net the same way they edit
	// worm/bug spawn tables. Returns empty string if no valid entries are
	// configured for the current environment.
	//
	// `environment` is 1=pond, 2=sea, 3=both. Only entries whose own
	// Environment matches (or is 3=both) participate in the weighted roll.
	// This is how saltwater casts get different catches than freshwater
	// casts without needing two separate config arrays.
	string GetConfiguredNetSpawnType(int environment) {
		int debugLevel = GebGetDebugLevel();

		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.BambooFishingNetSettings) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Net spawn lookup: config missing -- returning empty", "NetSpawn");
			return "";
		}
		ref array<ref NetEntry> catches = m_gebsConfig.General.BambooFishingNetSettings.Catches;
		if (!catches || catches.Count() == 0) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Net spawn lookup: Catches table empty -- returning empty (env=" + environment + ")", "NetSpawn");
			return "";
		}

		// Build the eligible pool once (env filter lives only here, so the
		// sum/walk can't disagree), then defer the roll to the shared picker.
		TStringArray names = new TStringArray;
		TFloatArray weights = new TFloatArray;
		foreach (NetEntry netEntry : catches) {
			if (!netEntry || netEntry.Classname == "" || netEntry.CatchChance <= 0)
				continue;
			if (netEntry.Environment != 3 && netEntry.Environment != environment)
				continue;
			names.Insert(netEntry.Classname);
			weights.Insert(netEntry.CatchChance);
		}

		int pick = GebWeightedPick.Pick(names, weights, debugLevel, "NetSpawn");
		if (pick < 0)
			return "";
		return names[pick];
	}

	override void OnFinishProgressServer(ActionData action_data) {
		int debugLevel = GebGetDebugLevel();

		// Guard action_data and its fields up front. The downstream code calls
		// player.GetPosition / player.GetSoftSkillsManager and dereferences
		// net via net.GetInventory -- a null on any would crash. Vanilla
		// usually has these populated when OnFinishProgressServer fires, but
		// disconnect / inventory-wipe edge cases can leave them null.
		if (!action_data || !action_data.m_Player) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Bamboo net: action_data or player is null -- skipping", "NetSpawn");
			return;
		}

		PlayerBase player = action_data.m_Player;
		ItemBase net = action_data.m_MainItem;

		// Per-attempt find chance gate. Net still takes damage on a miss so
		// nets wear down even when the catch fails.
		float findChance = GetFishingNetFindChance();
		float findRoll = -1;
		bool foundSomething;
		if (findChance >= 1.0) {
			foundSomething = true;
		} else {
			findRoll = Math.RandomFloat01();
			foundSomething = (findRoll <= findChance);
		}

		if (debugLevel >= 1) {
			GebsfishLogger.Debug("Net find-chance gate: findChance=" + findChance + " roll=" + findRoll + " result=" + foundSomething, "NetSpawn");
		}

		if (foundSomething) {
			// Determine which water type the cast is over so the Catches
			// table can be filtered by Environment (1=pond, 2=sea, 3=both).
			// Falls back to pond if the target's surface query comes back
			// empty.
			int environment = 1;
			if (action_data.m_Target) {
				vector targetPos = action_data.m_Target.GetCursorHitPos();
				if (g_Game.SurfaceIsSea(targetPos[0], targetPos[2]))
					environment = 2;
				else if (g_Game.SurfaceIsPond(targetPos[0], targetPos[2]))
					environment = 1;
			}

			string spawnType = GetConfiguredNetSpawnType(environment);
			if (spawnType != "") {
				// Try to spawn the catch into the net's cargo first. Falls
				// back to the player's feet when the net is full or the
				// filtered-cargo check rejects the item (see s_Allowed in
				// containers.c). CreateInInventory returns null on either
				// failure mode, so a single check covers both. Use
				// CreateInInventory rather than CreateInCargo* because the
				// former handles slot lookup automatically and matches the
				// pattern used elsewhere in the mod (geb_jonboat.c spark
				// plug spawn).
				EntityAI catchEntity;
				if (net && net.GetInventory())
					catchEntity = net.GetInventory().CreateInInventory(spawnType);
				if (!catchEntity)
					g_Game.CreateObjectEx(spawnType, player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
		}

		// Predator spawn chance for net use. Independent of the find-chance
		// roll so predators can show up even if no minnow was caught (and
		// vice versa). Default in config is much lower than fishing
		// (0.01 vs 0.05) since the net is a slower / quieter activity.
		if (player && g_Game.IsServer() && m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.BambooFishingNetSettings) {
			GebsPredatorSpawner.TrySpawn(player, m_gebsConfig.General.BambooFishingNetSettings.PredatorSpawnChance, "PredatorSpawnFishingNet");
		}

		player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

		if (net)
			net.DecreaseHealth("", "", 5);
	}

	void SetDiggingAnimation( ItemBase item ) {
		// The bamboo net carries itemInfo[] = {"CatchWithNet"}, which routes
		// through the DEPLOY_1HD animation here. STANCEMASK must include
		// CROUCH so the constructor's CROUCH stance stays compatible after
		// SetupAction overwrites these values. The else clause exists as a
		// safety net for any non-CatchWithNet item routed through this
		// action class in the future.
		if (item.KindOf("CatchWithNet")) {
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		}
		else {
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		}
	}
};
