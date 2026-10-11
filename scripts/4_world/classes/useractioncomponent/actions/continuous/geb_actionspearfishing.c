/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Spear fishing: stand in or beside shallow water with a vanilla Spear, Bone
// Spear or Stone Spear and stab at the bottom. No bait, a short action, and
// the catch comes from SpearFishingSettings. It is resolved on the server
// alone in OnFinishProgressServer -- nothing here feeds the synced catch maths
// the rod uses, so client and server can't disagree about it.

class ActionGebSpearFishingCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_WORMS * 0.6);
	}
};

class ActionGebSpearFishing : ActionGebWaterBase {
	// How far away the water may be, and what a stab costs the spear: at 1 a
	// 100-health spear lasts about four fish at the default FindChance (0.04).
	protected const float SPEAR_REACH = 3.0;
	protected const float SPEAR_HEALTH_PER_STAB = 1.0;

	// DIGMANIPULATE is the standing two-handed work loop vanilla plays for
	// shovels, hoes and pickaxes. Standing, because the player is usually
	// wading. The stance mask must stay ERECT
	// to match it: a stance the command doesn't support hangs the action
	// (see ActionBambooFishingNet).
	void ActionGebSpearFishing() {
		m_CallbackClass = ActionGebSpearFishingCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#STR_action_spearfishing";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTWaterSurfaceEx(SPEAR_REACH, LIQUID_SALTWATER | LIQUID_FRESHWATER);
	}

	override bool HasTarget() {
		return true;
	}

	protected SpearFishingConf GetSpearSettings() {
		if (!m_gebsConfig || !m_gebsConfig.General)
			return null;
		return m_gebsConfig.General.SpearFishingSettings;
	}

	// Metres of water at the spot aimed at. GetWaterDepth measures how far a
	// point sits below the water surface, so it is taken at the bottom (the
	// terrain under the aim point).
	protected float GetWaterDepthAt(vector position) {
		float bottom = g_Game.SurfaceY(position[0], position[2]);
		return g_Game.GetWaterDepth(Vector(position[0], bottom, position[2]));
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (!target || player.IsPlacingLocal() || player.IsSwimming())
			return false;

		SpearFishingConf settings = GetSpearSettings();
		if (!settings || !settings.Enable)
			return false;

		// The dedicated server takes the water type from the action payload,
		// as it does for the net; the water-surface condition still runs there.
		if (g_Game.IsDedicatedServer())
			return true;

		if (GebGetWaterType(target) == 0)
			return false;
		float depth = GetWaterDepthAt(target.GetCursorHitPos());
		return depth > 0 && depth <= settings.MaxWaterDepth;
	}

	override bool ActionConditionContinue(ActionData action_data) {
		return !action_data.m_Player.IsSwimming();
	}

	// Weighted pick from SpearFishingSettings.Catches among the entries for
	// this water (Environment 1 pond, 2 sea, 3 both); empty when none apply.
	string GetSpearCatchType(SpearFishingConf settings, int environment) {
		int debugLevel = GebGetDebugLevel();
		if (!settings || !settings.Catches || settings.Catches.Count() == 0)
			return "";

		TStringArray names = new TStringArray;
		TFloatArray weights = new TFloatArray;
		foreach (SpearEntry entry : settings.Catches) {
			if (!entry || entry.Classname == "" || entry.CatchChance <= 0)
				continue;
			if (entry.Environment != 3 && entry.Environment != environment)
				continue;
			names.Insert(entry.Classname);
			weights.Insert(entry.CatchChance);
		}

		int pick = GebWeightedPick.Pick(names, weights, debugLevel, "SpearFishing");
		if (pick < 0)
			return "";
		return names[pick];
	}

	// Caught fish come out as full as a rod's would (FishQuality).
	protected float GetCatchQuality() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings)
			return 1.0;
		return Math.Clamp(m_gebsConfig.General.GeneralSettings.FishQuality, 0.0, 1.0);
	}

	override void OnFinishProgressServer(ActionData action_data) {
		int debugLevel = GebGetDebugLevel();
		if (!action_data || !action_data.m_Player)
			return;

		GebWaterActionData data = GebWaterActionData.Cast(action_data);
		if (!data || !GebIsWaterType(data.m_GebEnvironment)) {
			GebsfishLogger.Error("Missing valid water type for a spear stab; skipping the catch.", "SpearFishing");
			return;
		}

		PlayerBase player = action_data.m_Player;
		ItemBase spear = action_data.m_MainItem;
		SpearFishingConf settings = GetSpearSettings();

		if (settings) {
			float findChance = Math.Clamp(settings.FindChance, 0.0, 1.0);
			float roll;
			bool caught = GebRollChance(findChance, roll);
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Spear stab: findChance=" + findChance + " roll=" + roll + " caught=" + caught + " water=" + data.m_GebEnvironment, "SpearFishing");

			bool landed = false;
			if (caught) {
				string catchType = GetSpearCatchType(settings, data.m_GebEnvironment);
				if (catchType != "") {
					// At the player's feet, as the net's overflow lands: the
					// spear is in the player's hands, and placing a new item
					// into inventory by type would skip the filtered
					// containers' allow-lists.
					Object spawned = g_Game.CreateObjectEx(catchType, player.GetPosition(), ECE_PLACE_ON_SURFACE);
					landed = spawned != null;
					ItemBase catchItem = ItemBase.Cast(spawned);
					if (catchItem && catchItem.HasQuantity())
						catchItem.SetQuantityNormalized(GetCatchQuality());
					if (debugLevel >= 1)
						GebsfishLogger.Debug("Spear caught " + catchType + ".", "SpearFishing");
				}
			}

			// A predator chance only for a fish landed, the way a rod rolls once
			// per cast. Rolled on every 6 s stab, with about 25 stabs to a fish,
			// it drew a wolf or bear every ten minutes or so: some twenty times a
			// rod's rate.
			if (landed)
				GebsPredatorSpawner.TrySpawn(player, settings.PredatorSpawnChance, "PredatorSpawnSpear");
		}

		player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

		if (spear)
			spear.DecreaseHealth("", "", SPEAR_HEALTH_PER_STAB);
	}
};
