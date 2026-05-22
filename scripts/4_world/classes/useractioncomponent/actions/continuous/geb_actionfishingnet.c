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

	// Returns the find chance from the config, clamped to [0, 1]. Defaults to
	// 1.0 (always finds) when the config is unavailable.
	float GetFishingNetFindChance() {
		if (!m_gebsConfig || !m_gebsConfig.ForageSettings)
			return 1.0;

		float chance = m_gebsConfig.ForageSettings.FishingNetFindChance;
		if (chance < 0.0) chance = 0.0;
		if (chance > 1.0) chance = 1.0;
		return chance;
	}

	// Weighted-random spawn classname from m_gebsConfig.NetItems. Mirrors the
	// pattern used by ActionDigWorms / ActionDigBugs so server admins can edit
	// what comes out of the net the same way they edit worm/bug spawn tables.
	// Returns empty string if no valid entries are configured.
	string GetConfiguredNetSpawnType() {
		if (!m_gebsConfig || !m_gebsConfig.NetItems || m_gebsConfig.NetItems.Count() == 0)
			return "";

		float totalChance = 0.0;
		foreach (BugEntry netEntry1 : m_gebsConfig.NetItems) {
			if (!netEntry1 || netEntry1.Classname == "" || netEntry1.CatchChance <= 0)
				continue;

			totalChance += netEntry1.CatchChance;
		}

		if (totalChance <= 0)
			return "";

		float roll = Math.RandomFloatInclusive(0.0, totalChance);
		foreach (BugEntry netEntry : m_gebsConfig.NetItems) {
			if (!netEntry || netEntry.Classname == "" || netEntry.CatchChance <= 0)
				continue;

			if (roll <= netEntry.CatchChance)
				return netEntry.Classname;

			roll -= netEntry.CatchChance;
		}

		return "";
	}

	override void OnFinishProgressServer(ActionData action_data) {
		PlayerBase player = action_data.m_Player;
		ItemBase net = action_data.m_MainItem;

		// Per-attempt find chance gate. Net still takes damage on a miss so
		// nets wear down even when the catch fails.
		float findChance = GetFishingNetFindChance();
		bool foundSomething = (findChance >= 1.0 || Math.RandomFloat01() <= findChance);

		if (foundSomething) {
			string spawnType = GetConfiguredNetSpawnType();
			if (spawnType != "")
				g_Game.CreateObjectEx(spawnType, player.GetPosition(), ECE_PLACE_ON_SURFACE);
		}

		// Predator spawn chance for net use. Independent of the find-chance roll
		// so predators can show up even if no minnow was caught (and vice versa).
		// Default in config is much lower than fishing (0.01 vs 0.05) since the
		// net is a slower / quieter activity than rod fishing.
		if (player && g_Game.IsServer() && m_gebsConfig && m_gebsConfig.PredatorSettings) {
			GebsPredatorSpawner.TrySpawn(player, m_gebsConfig.PredatorSettings.PredatorSpawnChanceFishingNet, "PredatorSpawnFishingNet");
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
