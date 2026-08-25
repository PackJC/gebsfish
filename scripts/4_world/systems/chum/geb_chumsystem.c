/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// One active chum school: a handful of fish item entities swimming lazy
// circles around the chum point until they are speared or the school expires.
// The "fish" are ordinary geb fish items (real models, real weight/quality on
// catch) that the server moves by hand -- DayZ 1.29 has no ambient fish AI to
// borrow, the old Animal_CyprinusCarpio/ScomberScombrus swimmers are gone from
// the game data entirely. SetTakeable(false) keeps the vanilla Take action off
// them while they swim, so the spear is the only way to collect one.
class GebChumSchool {
	vector m_Center;             // chum point (x/z) at water-surface height
	float m_SurfaceY;            // water surface height at the chum point
	int m_ExpireAtMs;            // g_Game.GetTime() after which leftovers despawn
	ref array<ItemBase> m_Fish;  // members still swimming (speared ones are removed)
	ref TFloatArray m_Angle;     // per-fish orbit angle, radians
	ref TFloatArray m_Radius;    // per-fish orbit radius, metres
	ref TFloatArray m_Speed;     // per-fish angular speed, radians/second (sign = direction)
	ref TFloatArray m_Depth;     // per-fish depth below the surface, metres

	void GebChumSchool(vector center, float surfaceY, int durationSeconds) {
		m_Center = center;
		m_SurfaceY = surfaceY;
		m_ExpireAtMs = g_Game.GetTime() + (durationSeconds * 1000);
		m_Fish = new array<ItemBase>();
		m_Angle = new TFloatArray;
		m_Radius = new TFloatArray;
		m_Speed = new TFloatArray;
		m_Depth = new TFloatArray;
	}
}

// Server-side manager for the chum-the-water feature (FB-style flow: guts in
// deep water -> temporary school of medium/small fish -> spear one).
// Entry points:
//   TryChumAt            -- the ActionChumWater finish handler
//   OnGutsLocationChanged -- thrown/dropped guts detection (modded Guts/SmallGuts)
//   ClaimFish            -- ActionSpearFish converts a swimmer into a catch
class GebsChumSystem {

	protected static ref array<ref GebChumSchool> s_Schools = new array<ref GebChumSchool>();
	protected static bool s_TickScheduled = false;

	// How often the swimmers advance. Item transforms replicate on change, so
	// smaller steps look smoother but cost more sync traffic; 300ms at the
	// slow orbit speeds below moves each fish a few centimetres per step.
	protected const int TICK_MS = 300;

	static ChumConf GetConf() {
		gebsfishConfig cfg = GetGebSettingsConfig();
		if (!cfg || !cfg.General)
			return null;
		return cfg.General.ChumSettings;
	}

	// Water-column depth (surface to seabed) at a world x/z, and the surface
	// height that goes with it. SurfaceY returns the seabed under water, and
	// GetWaterDepth of a point at seabed height is exactly the column above it.
	static float GetWaterColumn(float x, float z, out float surfaceY) {
		float seabedY = g_Game.SurfaceY(x, z);
		float column = g_Game.GetWaterDepth(Vector(x, seabedY, z));
		surfaceY = seabedY + column;
		return column;
	}

	// Full server-side validation + school spawn around a point in the water.
	// Returns true when a school was created. `player` may be null (thrown
	// guts with the thrower out of range); it is only used for the status
	// message.
	static bool TryChumAt(vector aroundPos, PlayerBase player, string logTag) {
		if (!g_Game.IsServer())
			return false;

		ChumConf conf = GetConf();
		int debugLevel = GebGetDebugLevel();
		if (!conf || !conf.Enable) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Chum skipped: feature disabled or config missing.", logTag);
			return false;
		}

		float surfaceY;
		float column = GetWaterColumn(aroundPos[0], aroundPos[2], surfaceY);
		if (column < conf.MinWaterDepth) {
			if (debugLevel >= 1)
				GebsfishLogger.Debug("Chum skipped: water column " + column + "m is under the " + conf.MinWaterDepth + "m minimum.", logTag);
			return false;
		}

		// 1=pond, 2=sea -- matches the Environment convention used by the net
		// and fish tables. A point that reads as neither but still has a water
		// column (some custom-map rivers) is treated as pond.
		int environment = 1;
		if (g_Game.SurfaceIsSea(aroundPos[0], aroundPos[2]))
			environment = 2;

		int countMin = conf.FishCountMin;
		int countMax = conf.FishCountMax;
		if (countMin < 1) countMin = 1;
		if (countMax < countMin) countMax = countMin;
		int count = Math.RandomInt(countMin, countMax + 1);

		vector center = Vector(aroundPos[0], surfaceY, aroundPos[2]);
		GebChumSchool school = new GebChumSchool(center, surfaceY, conf.DurationSeconds);

		float swimRadius = conf.SwimRadius;
		if (swimRadius < 1) swimRadius = 1;

		// Fish swim between just under the surface and just above the seabed;
		// the clamp keeps a 6ft-deep chum from putting fish in the mud.
		float maxDepthBelowSurface = column - 0.5;
		if (maxDepthBelowSurface < 0.5) maxDepthBelowSurface = 0.5;
		if (maxDepthBelowSurface > 1.5) maxDepthBelowSurface = 1.5;

		int spawned = 0;
		for (int i = 0; i < count; i++) {
			string classname = PickCatchClass(conf, environment, debugLevel, logTag);
			if (classname == "")
				break; // no eligible entries for this environment

			float angle = Math.RandomFloat(0, Math.PI2);
			float radius = Math.RandomFloat(swimRadius * 0.35, swimRadius);
			float depth = Math.RandomFloat(0.4, maxDepthBelowSurface);

			vector pos = Vector(center[0] + Math.Cos(angle) * radius, surfaceY - depth, center[2] + Math.Sin(angle) * radius);
			// ECE_KEEPHEIGHT: keep the underwater Y instead of snapping the
			// item to the seabed/surface.
			ItemBase fish = ItemBase.Cast(g_Game.CreateObjectEx(classname, pos, ECE_KEEPHEIGHT));
			if (!fish) {
				GebsfishLogger.Error("Chum failed to spawn '" + classname + "' -- check the ChumSettings.Catches classnames.", logTag);
				continue;
			}
			fish.SetTakeable(false); // spear-only: hides the vanilla Take action while it swims

			school.m_Fish.Insert(fish);
			school.m_Angle.Insert(angle);
			school.m_Radius.Insert(radius);
			// Slow lazy orbit; random direction per fish so the school doesn't
			// look like a carousel.
			float speed = Math.RandomFloat(0.15, 0.35);
			if (Math.RandomFloat01() < 0.5)
				speed = -speed;
			school.m_Speed.Insert(speed);
			school.m_Depth.Insert(depth);
			spawned++;
		}

		if (spawned == 0)
			return false;

		s_Schools.Insert(school);
		EnsureTick();

		if (debugLevel >= 1)
			GebsfishLogger.Debug("Chum school of " + spawned + " spawned at " + center.ToString() + " (env=" + environment + ", column=" + column + "m).", logTag);
		if (player)
			player.MessageStatus(Widget.TranslateString("#str_geb_chum_success"));
		return true;
	}

	// Weighted pick from ChumSettings.Catches filtered to the chummed water
	// type -- same eligibility contract as the bamboo net's Catches table.
	protected static string PickCatchClass(ChumConf conf, int environment, int debugLevel, string logTag) {
		if (!conf.Catches || conf.Catches.Count() == 0)
			return "";

		TStringArray names = new TStringArray;
		TFloatArray weights = new TFloatArray;
		foreach (NetEntry entry : conf.Catches) {
			if (!entry || entry.Classname == "" || entry.CatchChance <= 0)
				continue;
			if (entry.Environment != 3 && entry.Environment != environment)
				continue;
			names.Insert(entry.Classname);
			weights.Insert(entry.CatchChance);
		}

		int pick = GebWeightedPick.Pick(names, weights, debugLevel, logTag);
		if (pick < 0)
			return "";
		return names[pick];
	}

	// Modded Guts/SmallGuts forward every location change here; a change to
	// GROUND is a drop OR a throw, so schedule delayed checks and let the
	// water/health validation decide. Two staggered checks because a thrown
	// item is still mid-air at the first one; the check consumes the guts on
	// success, so the second pass sees null and exits.
	static void OnGutsLocationChanged(ItemBase guts, InventoryLocation newLoc) {
		if (!g_Game.IsServer() || !guts || !newLoc)
			return;
		if (newLoc.GetType() != InventoryLocationType.GROUND)
			return;

		ChumConf conf = GetConf();
		if (!conf || !conf.Enable)
			return;

		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckThrownGuts, 1500, false, guts);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckThrownGuts, 4000, false, guts);
	}

	static void CheckThrownGuts(ItemBase guts) {
		if (!guts)
			return; // consumed by the earlier check, or otherwise deleted
		// Back in someone's hands/inventory between the throw and this check.
		if (guts.GetHierarchyRoot() != guts)
			return;

		ChumConf conf = GetConf();
		if (!conf || !conf.Enable)
			return;

		if (guts.GetHealth01("", "") * 100 < conf.GutsMinHealthPercent)
			return; // too rotten to chum with -- they just sink

		vector pos = guts.GetPosition();
		float surfaceY;
		float column = GetWaterColumn(pos[0], pos[2], surfaceY);
		if (column < conf.MinWaterDepth)
			return;
		// Must actually be in the water, not on a dock/boat above it. A small
		// tolerance above the surface covers items floating on the waves.
		if (pos[1] > surfaceY + 0.3)
			return;

		vector chumPoint = Vector(pos[0], surfaceY, pos[2]);
		if (TryChumAt(chumPoint, null, "ChumThrow"))
			g_Game.ObjectDelete(guts);
	}

	// The spear action asks for the fish it hit. A registered swimmer is
	// removed from its school (so the mover stops touching it), made takeable
	// again, and handed back for attachment. Anything not in a school returns
	// null -- either the school expired mid-action or the object was never a
	// chum fish.
	static ItemBase ClaimFish(Object obj) {
		if (!g_Game.IsServer())
			return null;
		// The cast must be null-checked BEFORE Find: a school slot whose fish
		// was deleted holds null until the next tick compacts it, and
		// Find(null) would happily "claim" that empty slot.
		ItemBase target = ItemBase.Cast(obj);
		if (!target)
			return null;

		for (int s = 0; s < s_Schools.Count(); s++) {
			GebChumSchool school = s_Schools[s];
			int idx = school.m_Fish.Find(target);
			if (idx < 0)
				continue;

			ItemBase fish = school.m_Fish[idx];
			school.m_Fish.Remove(idx);
			school.m_Angle.Remove(idx);
			school.m_Radius.Remove(idx);
			school.m_Speed.Remove(idx);
			school.m_Depth.Remove(idx);
			if (school.m_Fish.Count() == 0)
				s_Schools.Remove(s);

			fish.SetTakeable(true);
			return fish;
		}
		return null;
	}

	protected static void EnsureTick() {
		if (s_TickScheduled)
			return;
		s_TickScheduled = true;
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Tick, TICK_MS, false);
	}

	// Advances every school: move the swimmers, expire finished schools.
	// Reschedules itself only while schools exist, so an idle server pays
	// nothing for the feature.
	protected static void Tick() {
		s_TickScheduled = false;

		float dt = TICK_MS / 1000.0;
		int now = g_Game.GetTime();

		for (int s = s_Schools.Count() - 1; s >= 0; s--) {
			GebChumSchool school = s_Schools[s];

			if (now >= school.m_ExpireAtMs) {
				// School dispersed -- despawn whatever wasn't speared.
				foreach (ItemBase leftover : school.m_Fish) {
					if (leftover)
						g_Game.ObjectDelete(leftover);
				}
				s_Schools.Remove(s);
				continue;
			}

			for (int i = school.m_Fish.Count() - 1; i >= 0; i--) {
				ItemBase fish = school.m_Fish[i];
				if (!fish) {
					// Deleted from outside (admin tool, cleanup) -- drop the slot.
					school.m_Fish.Remove(i);
					school.m_Angle.Remove(i);
					school.m_Radius.Remove(i);
					school.m_Speed.Remove(i);
					school.m_Depth.Remove(i);
					continue;
				}

				float angle = school.m_Angle[i] + school.m_Speed[i] * dt;
				school.m_Angle[i] = angle;

				// Lazy circle plus a slight vertical bob so they read as
				// swimming rather than rotating on a stick.
				float bob = Math.Sin(angle * 2) * 0.1;
				vector pos = Vector(
					school.m_Center[0] + Math.Cos(angle) * school.m_Radius[i],
					school.m_SurfaceY - school.m_Depth[i] + bob,
					school.m_Center[2] + Math.Sin(angle) * school.m_Radius[i]);
				fish.SetPosition(pos);

				// Face the direction of travel (the orbit tangent). For a
				// counter-clockwise orbit the velocity is (-sin, 0, cos).
				float dirSign = 1;
				if (school.m_Speed[i] < 0)
					dirSign = -1;
				float yaw = Math.Atan2(-Math.Sin(angle) * dirSign, Math.Cos(angle) * dirSign) * Math.RAD2DEG;
				fish.SetOrientation(Vector(yaw, 0, 0));
			}

			if (school.m_Fish.Count() == 0)
				s_Schools.Remove(s);
		}

		if (s_Schools.Count() > 0)
			EnsureTick();
	}
}
