// Gebsfish override of the vanilla fishing-rod catching context. Owns the
// per-fish weighted pick, bait-preference bias, weather/time-of-day/moon/
// temperature multipliers, BiteSpeed cycle scaling, and all the diagnostic
// logging gated by GeneralSettings.DebugLogs.
modded class CatchingContextFishingRodAction : CatchingContextFishingBase {
    override void Init(Param par) {
		super.Init(par);
		// Vanilla Init() runs InitCatchingItemData BEFORE SetupProbabilityArray,
		// so the bite-speed aggregate (which reads m_ProbabilityArray) is a no-op
		// during construction. Re-apply it here, now that the pool exists, so the
		// FIRST signal cycle of the cast is scaled too -- not just cycles 2+ via
		// UpdateCatchingItemData. No compounding: the next InitCatchingItemData
		// resets the cycle targets to base (ClearCatchingItemData) before this
		// rescales them.
		ApplyBiteSpeedScaling();
	}

	override void InitCatchingItemData() {
		super.InitCatchingItemData();
		ApplyBiteSpeedScaling();
	}

	// Stretches the signal-cycle targets inversely to the aggregated BiteSpeed of
	// the current pool (lower aggregate -> longer wait). No-op (biteSpeed=1.0)
	// when the buff is disabled, the pool is empty, or all weights resolve to
	// zero. Safe to call repeatedly: super.InitCatchingItemData resets the cycle
	// targets to base each cycle, so this never compounds.
	protected void ApplyBiteSpeedScaling() {
		float cycleTargetBefore = m_SignalCycleTarget;
		float cycleEndBefore = m_SignalCycleEndTarget;
		float biteSpeed = ComputeAggregateBiteSpeed();
		if (biteSpeed != 1.0) {
			m_SignalCycleTarget = m_SignalCycleTarget / biteSpeed;
			m_SignalCycleEndTarget = m_SignalCycleEndTarget / biteSpeed;
		}

		if (GetDebugLogLevel() >= 1) {
			GebsfishLogger.Debug("Cycle scaled by BiteSpeed=" + biteSpeed + ": cycleTarget " + cycleTargetBefore + "->" + m_SignalCycleTarget + ", cycleEnd " + cycleEndBefore + "->" + m_SignalCycleEndTarget, "InitCatchingItemData");
		}

		if (GetDebugLogLevel() == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---InitCatchingItemData---","InitCatchingItemData");
			GebsfishLogger.Debug("aggregate bite speed: " + biteSpeed,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalCycleTarget (adjusted): " + m_SignalCycleTarget,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalCycleTargetAdjustment: " + m_SignalCycleTargetAdjustment,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalTargetProbability: " + m_SignalTargetProbability,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalCycleEndTarget (adjusted): " + m_SignalCycleEndTarget,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalCycleTargetEndAdjustment: " + m_SignalCycleTargetEndAdjustment,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalTargetEndProbability: " + m_SignalTargetEndProbability,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalDurationMin: " + m_SignalDurationMin,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalDurationMax: " + m_SignalDurationMax,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalStartTimeMin: " + m_SignalStartTimeMin,"InitCatchingItemData");
			GebsfishLogger.Debug("m_SignalStartTimeMax: " + m_SignalStartTimeMax,"InitCatchingItemData");
		}
	}

	// Weighted average of per-fish BiteSpeed[currentHour] across every yield in
	// the active probability pool. Each fish's contribution is weighted by its
	// CatchProbability times its current time-of-day weather multiplier, so the
	// aggregate reflects the fish actually likely to bite right now. Returns
	// 1.0 (no effect) when the buff is disabled, the pool is empty, or all
	// weights resolve to zero. Floor of 0.05 prevents an all-zero hour from
	// freezing the cycle.
	//
	// Logging: DebugLogs=1 prints a one-line summary per cast (hour, pool size,
	// final aggregate, top contributors). DebugLogs=2 (ELEVATED_DEBUG) adds a
	// per-fish breakdown row showing BiteSpeed, CatchProbability, weather
	// multiplier, weight, and contribution to the numerator.
	protected float ComputeAggregateBiteSpeed() {
		if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
			return 1.0;
		// Gate on BiteSpeedEnable (not WeatherCatchBoostEnable) so the three
		// catch-modifying systems -- weather/time-of-day, moon, and BiteSpeed --
		// are independently toggleable. The aggregate still uses
		// GetSpeciesWeatherMultiplier internally for per-fish weighting, and
		// that helper handles its own enable gating.
		if (!m_gebsConfig.WeatherSettings.BiteSpeedEnable)
			return 1.0;
		if (!m_ProbabilityArray || m_ProbabilityArray.Count() == 0)
			return 1.0;

		int hour = GetCurrentHour();
		float numerator = 0.0;
		float denominator = 0.0;
		// Enforce's parser dislikes `bool x = (intExpr >= literal);` here, so
		// cache the level as an int and compare inline at each log site -- same
		// pattern that already compiles cleanly inside the `if`s above.
		int debugLevel = GetDebugLogLevel();

		// Tracks the highest-weighted contributor so the regular debug summary
		// can name the fish that's dominating the aggregate this cast.
		string topName = "";
		float topWeight = 0;
		float topBiteSpeed = 0;

		if (debugLevel == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---BiteSpeed aggregate breakdown (hour=" + hour + ")---", "ComputeAggregateBiteSpeed");
			GebsfishLogger.Debug("species | BiteSpeed[h] | CatchProb | weatherMul | weight | contribution", "ComputeAggregateBiteSpeed");
		}

		int n = m_ProbabilityArray.Count();
		int contributors = 0;
		for (int i = 0; i < n; i++) {
			YieldItemBase y;
			if (!Class.CastTo(y, m_YieldsMapAll.Get(m_ProbabilityArray[i])) || !y)
				continue;
			GebYieldFishBase gy;
			if (!Class.CastTo(gy, y) || !gy)
				continue;

			float _aggRainStorm, _aggTimeMul, _aggTempMul;
			int _aggWindow;
			float weatherMul = GetSpeciesWeatherMultiplier(gy, _aggRainStorm, _aggWindow, _aggTimeMul, _aggTempMul);
			float weight = gy.GetCatchProbability() * weatherMul;
			float biteSpeed = gy.GetBiteSpeedForHour(hour);

			if (weight <= 0) {
				if (debugLevel == ELEVATED_DEBUG) {
					GebsfishLogger.Debug(gy.GetSpeciesClassname() + " | " + biteSpeed + " | " + gy.GetCatchProbability() + " | " + weatherMul + " | 0 (SKIPPED) | 0", "ComputeAggregateBiteSpeed");
				}
				continue;
			}

			float contribution = biteSpeed * weight;
			numerator += contribution;
			denominator += weight;
			contributors++;

			if (weight > topWeight) {
				topWeight = weight;
				topName = gy.GetSpeciesClassname();
				topBiteSpeed = biteSpeed;
			}

			if (debugLevel == ELEVATED_DEBUG) {
				GebsfishLogger.Debug(gy.GetSpeciesClassname() + " | " + biteSpeed + " | " + gy.GetCatchProbability() + " | " + weatherMul + " | " + weight + " | " + contribution, "ComputeAggregateBiteSpeed");
			}
		}

		if (denominator <= 0) {
			if (debugLevel >= 1) {
				GebsfishLogger.Debug("BiteSpeed aggregate: 1.0 baseline (all weights zero, pool=" + n + " hour=" + hour + ")", "ComputeAggregateBiteSpeed");
			}
			return 1.0;
		}

		float aggregated = numerator / denominator;
		bool floored = false;
		if (aggregated < 0.05) {
			aggregated = 0.05;
			floored = true;
		}

		if (debugLevel >= 1) {
			string flooredTag = "";
			if (floored)
				flooredTag = " (FLOORED to 0.05)";
			GebsfishLogger.Debug("BiteSpeed aggregate: " + aggregated + " | hour=" + hour + " | pool=" + n + " | contributors=" + contributors + " | top=" + topName + "(BiteSpeed=" + topBiteSpeed + ", weight=" + topWeight + ")" + flooredTag, "ComputeAggregateBiteSpeed");
		}
		if (debugLevel == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("totals: numerator=" + numerator + " denominator=" + denominator + " aggregated=" + aggregated, "ComputeAggregateBiteSpeed");
			GebsfishLogger.Debug("---End BiteSpeed breakdown---", "ComputeAggregateBiteSpeed");
		}

		return aggregated;
	}

    override bool ModifySignalProbability(inout float probability) {
		float easingTime;
		if ((float)m_SignalCurrent < m_SignalCycleTarget) {
			easingTime = Math.InverseLerp(0,m_SignalCycleTarget,(float)m_SignalCurrent);
			probability = Easing.EaseInExpo(easingTime) * m_SignalTargetProbability * GetChanceCoef();
		}
		else {
			easingTime = Math.InverseLerp(m_SignalCycleTarget,m_SignalCycleEndTarget,(float)m_SignalCurrent);
			probability = (m_SignalTargetProbability + (Easing.EaseInExpo(easingTime) * (m_SignalTargetEndProbability - m_SignalTargetProbability))) * GetChanceCoef();
		}

		// Weather catch buff: rain / storm / night make fish bite more often.
		// Applied as a probability multiplier so it stacks naturally with
		// GetChanceCoef() above. Returns 1.0 when disabled or no condition matches,
		// so this is a no-op for servers that leave WeatherCatchBoostEnable off.
		float weatherMul = GetWeatherCatchMultiplier();
		if (weatherMul != 1.0)
			probability = probability * weatherMul;

		if (GetDebugLogLevel() == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---ModifySignalProbability---","ModifySignalProbability");
			GebsfishLogger.Debug("m_SignalCurrent: " + m_SignalCurrent,"ModifySignalProbability");
			GebsfishLogger.Debug("easingTime: " + easingTime,"ModifySignalProbability");
			GebsfishLogger.Debug("weather multiplier: " + weatherMul,"ModifySignalProbability");
			GebsfishLogger.Debug("probability: " + probability,"ModifySignalProbability");
		}

		return true;
    }

    // True when the weather catch buff feature is enabled in config. Per-species
    // multipliers live inline on each FishConf now, so any fish with non-1.0
    // multipliers automatically participates in the weighted pick. When the
    // feature is disabled, GenerateResult falls back to the uniform pick path.
    protected bool HasActiveSpeciesBuffs() {
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return false;
        return m_gebsConfig.WeatherSettings.WeatherCatchBoostEnable;
    }

    // Weighted random selection over m_ProbabilityArray, biased by per-species
    // weather/time-of-day multipliers and the per-bait fish-preference table.
    // Each yield's final weight is SCALE * speciesWeatherMul * baitMul.
    // Returns -1 on any error condition (zero total weight, cast failures, etc.)
    // so the caller falls back to the existing uniform pick. Stays sync-safe by
    // using GetRandomInRange against an integer-scaled cumulative weight.
    protected int PickWeightedYieldIndex() {
        int n = m_ProbabilityArray.Count();
        if (n <= 0)
            return -1;

        // Scale floats to ints (x1000) so weighted-random can use the integer
        // sync RNG, keeping client and server in lockstep.
        const int SCALE = 1000;
        ref array<int> scaled = new array<int>;
        scaled.Reserve(n);
        int total = 0;
        int debugLevel = GetDebugLogLevel();
        string baitSource = "";
        string baitClassname = GetCurrentBaitClassname(baitSource);

        if (debugLevel == ELEVATED_DEBUG) {
            GebsfishLogger.Debug("---PickWeightedYieldIndex (bait=" + baitClassname + " source=" + baitSource + ")---", "GenerateResult");
            GebsfishLogger.Debug("species | rain/storm | window | timeMul | tempMul | weatherMul | baitMul | scaled", "GenerateResult");
        }

        for (int i = 0; i < n; i++) {
            YieldItemBase y;
            int weight = SCALE;  // baseline weight when no buff applies

            if (Class.CastTo(y, m_YieldsMapAll.Get(m_ProbabilityArray[i])) && y) {
                GebYieldFishBase gy;
                if (Class.CastTo(gy, y) && gy) {
                    float dbgRainStorm, dbgTimeMul, dbgTempMul;
                    int dbgWindow;
                    float weatherMul = GetSpeciesWeatherMultiplier(gy, dbgRainStorm, dbgWindow, dbgTimeMul, dbgTempMul);
                    float baitMul = GetBaitMultiplier(gy.GetSpeciesClassname(), baitClassname);
                    weight = Math.Round(SCALE * weatherMul * baitMul);
                    if (weight < 0)
                        weight = 0;

                    if (debugLevel == ELEVATED_DEBUG) {
                        GebsfishLogger.Debug(gy.GetSpeciesClassname() + " | " + dbgRainStorm + " | " + WindowToString(dbgWindow) + " | " + dbgTimeMul + " | " + dbgTempMul + " | " + weatherMul + " | " + baitMul + " | " + weight, "GenerateResult");
                    }
                }
            }

            scaled.Insert(weight);
            total += weight;
        }

        if (total <= 0)
            return -1;

        int roll = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching, 0, total - 1);
        int cumul = 0;
        for (int j = 0; j < n; j++) {
            cumul += scaled[j];
            if (roll < cumul) {
                if (debugLevel == ELEVATED_DEBUG) {
                    GebsfishLogger.Debug("Weighted yield pick: idx=" + j + " roll=" + roll + " total=" + total, "GenerateResult");
                }
                return j;
            }
        }
        return n - 1;  // floating-point edge case; clamp to last
    }

    // Returns the classname currently on the rod's hook. Prefers m_Bait (a
    // worm / minnow / salamander attached to the hook) since that's the
    // active bait when bait-style items are in use. Falls back to m_Hook,
    // which for gebsfish lures IS the hook itself (geb_SpinnerBait*,
    // geb_SpoonLure*, geb_CurlyTailJig*, geb_Lure*). Returns empty string
    // when neither is available -- callers default to a neutral 1.0
    // multiplier in that case.
    //
    // outSource exposes which slot supplied the classname so debug logging
    // can distinguish "bait biased the pick" from "the lure-as-hook did" --
    // when bait preferences look wrong, that distinction is the answer to
    // "why am I catching X with this lure".
    protected string GetCurrentBaitClassname(out string outSource) {
        if (m_Bait) {
            outSource = "bait";
            return m_Bait.GetType();
        }
        if (m_Hook) {
            outSource = "hook";
            return m_Hook.GetType();
        }
        outSource = "none";
        return "";
    }

    // Null-safe debug-log level; delegates to the shared global accessor so
    // the null-guard logic lives in exactly one place.
    protected int GetDebugLogLevel() {
        return GebGetDebugLevel();
    }

    // Case-insensitive classname comparison. DayZ engine classnames are
    // case-sensitive (CreateObject("Worm") works, CreateObject("worm") does
    // not), so engine-supplied GetType() results always come back canonical.
    // But admins hand-editing the JSON aren't always careful with case --
    // silently failing those lookups makes whole subsystems (bait preferences
    // etc.) look broken on what's really a typo. Defensive copies before
    // ToLower so we never mutate the caller's strings.
    protected bool ClassnamesMatch(string a, string b) {
        string aCopy = a;
        string bCopy = b;
        aCopy.ToLower();
        bCopy.ToLower();
        return aCopy == bCopy;
    }

    // Small label helper for the weather sub-component log table. Keeps the
    // breakdown row scannable -- "Dawn" reads faster than "0" when you're
    // diagnosing "wrong time of day is being applied".
    protected string WindowToString(int window) {
        if (window == 0) return "Dawn";
        if (window == 1) return "Day";
        if (window == 2) return "Dusk";
        if (window == 3) return "Night";
        return "none";
    }

    // Per-bait fish-preference multiplier. Walks BaitPreferences for an
    // entry matching the current bait classname, then walks that entry's
    // Preferences for a row matching the fish classname. Returns 1.0 (no
    // bias) when the bait isn't configured at all, when the fish isn't in
    // the bait's preference list, or when the config is missing -- so the
    // system is fully opt-in and a partial config can never block catches.
    protected float GetBaitMultiplier(string fishClassname, string baitClassname) {
        if (baitClassname == "" || fishClassname == "")
            return 1.0;
        if (!m_gebsConfig || !m_gebsConfig.BaitPreferences)
            return 1.0;
        // Master toggle: when disabled, every bait is neutral 1.0x for every
        // fish so only CatchProbability and the other multipliers (weather,
        // time-of-day, temperature, moon) drive the weighted pick.
        if (!m_gebsConfig.BaitPreferenceEnable)
            return 1.0;

        foreach (BaitConfig bait : m_gebsConfig.BaitPreferences) {
            // Case-insensitive on the classname match: m_Bait.GetType() comes
            // back in DayZ's canonical PascalCase, but admins hand-editing
            // the JSON sometimes type "worm" or "WORM" -- silently failing
            // those lookups would make the entire bait-preference system
            // look broken on what's really a typo.
            if (!bait || !ClassnamesMatch(bait.BaitClassname, baitClassname))
                continue;
            if (!bait.Preferences)
                return 1.0;
            foreach (BaitPreferenceEntry pref : bait.Preferences) {
                if (pref && ClassnamesMatch(pref.FishClassname, fishClassname)) {
                    // Floor at 0 so an admin typo (-2.0) can't drag the
                    // weighted-pick weight negative. Downstream rounds
                    // negative weights to 0 anyway, but defending at the
                    // source means future refactors of the pick math can
                    // trust the multipliers are non-negative.
                    if (pref.Multiplier < 0.0)
                        return 0.0;
                    return pref.Multiplier;
                }
            }
            return 1.0;  // matched bait but fish not listed -- neutral
        }

        return 1.0;  // bait not in config at all -- neutral
    }

    // Returns the current water temperature in degrees Celsius. Uses ambient
    // air temperature as a proxy -- water temperature isn't exposed cleanly
    // by the engine, but ambient already tracks weather/time-of-day/season,
    // so it's a defensible stand-in for game purposes. Adds the admin-
    // configured WaterTempOffset so winter/tropical servers can shift the
    // whole curve without editing every fish. Defaults to 18 C (plus offset)
    // if world state isn't available yet (mission startup race) so the curve
    // returns a sensible mid-range neutral value.
    protected float GetCurrentWaterTemp() {
        float offset = 0.0;
        if (m_gebsConfig && m_gebsConfig.WeatherSettings)
            offset = m_gebsConfig.WeatherSettings.WaterTempOffset;

        if (!g_Game || !g_Game.GetMission())
            return 18.0 + offset;
        WorldData worldData = g_Game.GetMission().GetWorldData();
        if (!worldData)
            return 18.0 + offset;
        return worldData.GetBaseEnvTemperature() + offset;
    }

    // Per-species water-temperature multiplier. Piecewise linear bell curve:
    //   - 1.0 at TempOptimal
    //   - lerps to MinTempMultiplier as water drops to TempMin
    //   - lerps to MaxTempMultiplier as water rises to TempMax
    //   - clamps to those floors outside [TempMin, TempMax]
    // Returns 1.0 (neutral) when disabled in config, when the fish wasn't
    // initialized via SetTemperature (sentinel TempMin == TempMax), or when
    // TempMin >= TempOptimal >= TempMax (degenerate range).
    protected float GetSpeciesTempMultiplier(GebYieldFishBase gy) {
        if (!gy)
            return 1.0;
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;
        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.TemperatureEffectEnable)
            return 1.0;

        float tempOpt = gy.GetTempOptimal();
        float tempMin = gy.GetTempMin();
        float tempMax = gy.GetTempMax();

        // Uninitialized sentinel: same value means SetTemperature was never
        // called for this fish. Stay neutral so partial wiring never breaks
        // catches.
        if (tempMin == tempMax)
            return 1.0;
        // Degenerate range guard -- treat as disabled to avoid divide-by-zero.
        if (tempOpt <= tempMin || tempOpt >= tempMax)
            return 1.0;

        float waterTemp = GetCurrentWaterTemp();
        float floorMin = w.MinTempMultiplier;
        float floorMax = w.MaxTempMultiplier;

        if (waterTemp <= tempMin)
            return floorMin;
        if (waterTemp >= tempMax)
            return floorMax;
        if (waterTemp == tempOpt)
            return 1.0;

        if (waterTemp < tempOpt) {
            // Cold side: lerp from floorMin (at TempMin) to 1.0 (at TempOptimal).
            float t = (waterTemp - tempMin) / (tempOpt - tempMin);
            return Math.Lerp(floorMin, 1.0, t);
        }
        // Warm side: lerp from 1.0 (at TempOptimal) to floorMax (at TempMax).
        float t2 = (waterTemp - tempOpt) / (tempMax - tempOpt);
        return Math.Lerp(1.0, floorMax, t2);
    }

    // Per-species multiplier overlay. Reads the per-species Rain/Storm/Dawn/
    // Day/Dusk/Night multipliers straight off the GebYieldFishBase (cached
    // there at registration time from the matching FishConf), then applies
    // the same rain/storm + time-of-day conditions as the global multiplier.
    // Stacks the per-species temperature curve on top. Yields that weren't
    // passed multipliers in SetupYield default to 1.0 (no effect). Bails
    // early only when BOTH WeatherCatchBoostEnable and TemperatureEffectEnable
    // are off -- temperature is independent of the rain/time toggle.
    //
    // Out params expose the sub-components so callers (PickWeightedYieldIndex)
    // can log a per-species breakdown at ELEVATED_DEBUG without re-deriving
    // them. dbgRainStormMul is whichever of rain/storm actually applied (1.0
    // if neither), dbgWindow is the resolved Dawn=0/Day=1/Dusk=2/Night=3/-1
    // sentinel, dbgTimeMul is the picked time-of-day multiplier, dbgTempMul
    // is the temperature-curve multiplier.
    protected float GetSpeciesWeatherMultiplier(GebYieldFishBase gy, out float dbgRainStormMul, out int dbgWindow, out float dbgTimeMul, out float dbgTempMul) {
        dbgRainStormMul = 1.0;
        dbgWindow = -1;
        dbgTimeMul = 1.0;
        dbgTempMul = 1.0;

        if (!gy)
            return 1.0;
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;

        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.WeatherCatchBoostEnable && !w.TemperatureEffectEnable)
            return 1.0;

        float multiplier = 1.0;

        if (w.WeatherCatchBoostEnable) {
            // Floor at 0 -- admin typo could set a negative multiplier on
            // a FishConf and drag the running total negative. Downstream
            // weight rounds negatives to 0, but defending at source keeps
            // the multiplier semantically a non-negative scale factor and
            // makes future refactors safe.
            float speciesRain  = gy.GetRainMultiplier();
            float speciesStorm = gy.GetStormMultiplier();
            if (speciesRain < 0.0)  speciesRain  = 0.0;
            if (speciesStorm < 0.0) speciesStorm = 0.0;

            // Rain / storm component (mutually exclusive, matches global rule).
            Weather weather = g_Game.GetWeather();
            if (weather && weather.GetRain()) {
                float rain = weather.GetRain().GetActual();
                // Band selection (storm vs rain) is decided purely by the
                // thresholds; the != 1.0 no-op check must stay INSIDE the chosen
                // band, otherwise a storm-neutral fish (StormMultiplier == 1.0)
                // would fall through and wrongly get the rain multiplier applied
                // during a storm.
                if (rain >= w.StormThreshold) {
                    dbgRainStormMul = speciesStorm;
                    if (speciesStorm != 1.0)
                        multiplier = multiplier * speciesStorm;
                } else if (rain >= w.RainThreshold) {
                    dbgRainStormMul = speciesRain;
                    if (speciesRain != 1.0)
                        multiplier = multiplier * speciesRain;
                }
            }

            // Time-of-day component. Exactly one of Dawn / Day / Dusk / Night
            // applies based on the current hour; pick the matching species
            // multiplier and stack it onto the running total.
            int hour = GetCurrentHour();
            float speciesTimeOfDay = 1.0;
            int window = ResolveTimeWindow(w, hour);
            dbgWindow = window;
            if (window == 0)      speciesTimeOfDay = gy.GetDawnMultiplier();
            else if (window == 1) speciesTimeOfDay = gy.GetDayMultiplier();
            else if (window == 2) speciesTimeOfDay = gy.GetDuskMultiplier();
            else if (window == 3) speciesTimeOfDay = gy.GetNightMultiplier();
            if (speciesTimeOfDay < 0.0)
                speciesTimeOfDay = 0.0;
            dbgTimeMul = speciesTimeOfDay;

            if (speciesTimeOfDay != 1.0)
                multiplier = multiplier * speciesTimeOfDay;
        }

        // ---- temperature component ----
        // Independent of WeatherCatchBoostEnable. Helper returns 1.0 when
        // disabled or when the fish wasn't wired through SetTemperature yet.
        float tempMul = GetSpeciesTempMultiplier(gy);
        if (tempMul < 0.0)
            tempMul = 0.0;
        dbgTempMul = tempMul;
        if (tempMul != 1.0)
            multiplier = multiplier * tempMul;

        // Apply the same global stacking cap GetWeatherCatchMultiplier uses, so
        // a species' rain/storm x time-of-day x temperature weighting can't
        // compound past MaxStackedMultiplier and dominate the weighted pick.
        if (w.MaxStackedMultiplier > 0 && multiplier > w.MaxStackedMultiplier) {
            if (GetDebugLogLevel() >= 1)
                GebsfishLogger.Debug("Species weather mul clamped: " + multiplier + " -> " + w.MaxStackedMultiplier + " (cap)", "GetSpeciesWeatherMultiplier");
            multiplier = w.MaxStackedMultiplier;
        }

        return multiplier;
    }

    // Returns the current in-game hour (0-23). Defaults to 12 (noon) if the
    // world state isn't available yet (mission startup race).
    protected int GetCurrentHour() {
        int year, month, day, hour, minute;
        if (g_Game && g_Game.GetWorld()) {
            g_Game.GetWorld().GetDate(year, month, day, hour, minute);
            return hour;
        }
        return 12;
    }

    // Resolves the current time-of-day window based on hour and the configured
    // Dawn/Day/Dusk/Night boundaries. Returns:
    //   0 = Dawn
    //   1 = Day
    //   2 = Dusk
    //   3 = Night
    //  -1 = no window matched (shouldn't happen if config covers 24h)
    // Each window is checked via HourInWindow, which handles the wrap case
    // (start > end means the window crosses midnight, e.g. Night 20-5). All
    // four windows accept wrap configurations -- by default only Night uses
    // it, but admins running unusual schedules (post-apoc / arctic / fantasy
    // servers) may want a 23-2 Dawn or similar.
    protected int ResolveTimeWindow(WeatherConf w, int hour) {
        if (HourInWindow(hour, w.DawnStartHour, w.DawnEndHour))
            return 0;
        if (HourInWindow(hour, w.DayStartHour, w.DayEndHour))
            return 1;
        if (HourInWindow(hour, w.DuskStartHour, w.DuskEndHour))
            return 2;
        if (HourInWindow(hour, w.NightStartHour, w.NightEndHour))
            return 3;
        return -1;
    }

    // Returns true if `hour` falls inside the [startHour, endHour) window.
    // Treats start == end as "window disabled" (returns false) so an admin
    // can zero out a window without it accidentally matching every hour.
    // When start < end, behaves as a standard half-open range. When start
    // > end, the window wraps around midnight (e.g. 20-5 covers 20, 21,
    // 22, 23, 0, 1, 2, 3, 4).
    protected bool HourInWindow(int hour, int startHour, int endHour) {
        if (startHour == endHour)
            return false;
        if (startHour < endHour)
            return (hour >= startHour && hour < endHour);
        return (hour >= startHour || hour < endHour);
    }

    // Computes the synodic moon phase as a 0..1 fraction where 0 = new moon,
    // 0.5 = full moon, 1.0 = back to new. Uses the Meeus Julian Date formula
    // against a known reference new moon (2000-01-06 18:14 UTC, JD 2451550.26)
    // and the long-term-average synodic period (29.530588853 days). Accuracy
    // stays within ~6 hours over many years -- well inside game tolerances.
    // The in-game date drives this so any HUD mod showing the calendar will
    // line up with the phase reported here.
    protected float ComputeMoonPhase(int year, int month, int day, int hour) {
        int y = year;
        int m = month;
        if (m <= 2) {
            y = y - 1;
            m = m + 12;
        }
        int a = y / 100;
        int b = 2 - a + (a / 4);

        // Broken into intermediates because Enforce's parser doesn't accept
        // multi-line expressions with leading + operators -- collapsing the
        // single jd expression below was the original syntax error.
        float jdYearTerm = Math.Floor(365.25 * (y + 4716));
        float jdMonthTerm = Math.Floor(30.6001 * (m + 1));
        float jdDayTerm = day + b - 1524.5;
        float jdHourTerm = hour / 24.0;
        float jd = jdYearTerm + jdMonthTerm + jdDayTerm + jdHourTerm;

        float daysSince = jd - 2451550.26;   // ref new moon JD
        float synodic = 29.530588853;        // average synodic month
        float phase = daysSince / synodic;
        phase = phase - Math.Floor(phase);
        if (phase < 0)
            phase = phase + 1.0;
        return phase;
    }

    // Per-cast moon-phase multiplier. Returns 1.0 (neutral) when disabled,
    // during daytime (moon not a visible/active factor), when both extremes
    // are 1.0, or when the world date isn't available yet. Otherwise lerps
    // linearly between FullMoonMultiplier at full moon and NewMoonMultiplier
    // at new moon, smooth across quarter moons. Independent of
    // WeatherCatchBoostEnable so admins can run moon-only or weather-only.
    protected float GetMoonMultiplier() {
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;
        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.MoonPhaseEnable)
            return 1.0;
        if (w.FullMoonMultiplier == 1.0 && w.NewMoonMultiplier == 1.0)
            return 1.0;

        // Moon only applies at night -- reuse the configured Night window.
        int hour = GetCurrentHour();
        if (ResolveTimeWindow(w, hour) != 3)
            return 1.0;

        int year, month, day, h, minute;
        if (!g_Game || !g_Game.GetWorld())
            return 1.0;
        g_Game.GetWorld().GetDate(year, month, day, h, minute);

        float phase = ComputeMoonPhase(year, month, day, h);

        // phase=0.5 -> distFromFull=0 (full). phase=0 or 1 -> distFromFull=1 (new).
        float distFromFull = Math.AbsFloat(phase - 0.5) * 2.0;

        return Math.Lerp(w.FullMoonMultiplier, w.NewMoonMultiplier, distFromFull);
    }

    // Computes the combined rain / storm / dawn / day / dusk / night / moon
    // multiplier from the current world state. Returns 1.0 (no effect) when
    // every feature is disabled, when no condition is currently active, or
    // when weather/world state isn't available yet (mission startup race).
    //
    // Rain and storm are mutually exclusive (storm replaces rain rather than
    // stacking with it). Dawn/Day/Dusk/Night are also mutually exclusive --
    // the current hour falls in exactly one. Rain/storm CAN stack with the
    // time-of-day window AND with the moon-phase multiplier (moon is night-
    // only, so it never stacks with Dawn/Day/Dusk). MoonPhaseEnable is
    // independent of WeatherCatchBoostEnable so admins can run moon-only or
    // weather-only. Combined result is clamped to MaxStackedMultiplier so a
    // stormy full-moon night never becomes a runaway printer.
    protected float GetWeatherCatchMultiplier() {
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;

        WeatherConf w = m_gebsConfig.WeatherSettings;
        // Bail out only if BOTH feature toggles are off -- moon is independent
        // of WeatherCatchBoostEnable.
        if (!w.WeatherCatchBoostEnable && !w.MoonPhaseEnable)
            return 1.0;

        int debugLevel = 0;
        if (m_gebsConfig.GeneralSettings)
            debugLevel = GetDebugLogLevel();

        float multiplier = 1.0;
        float dbgRainStorm = 1.0;
        int dbgWindow = -1;
        float dbgTimeMul = 1.0;

        if (w.WeatherCatchBoostEnable) {
            // ---- rain / storm component ----
            Weather weather = g_Game.GetWeather();
            if (weather && weather.GetRain()) {
                float rain = weather.GetRain().GetActual();
                // Band selection (storm vs rain) is decided purely by the
                // thresholds; the != 1.0 no-op check stays INSIDE the chosen
                // band so a storm-neutral config (StormCatchMultiplier == 1.0)
                // can't fall through and wrongly apply the rain multiplier
                // during a storm.
                if (rain >= w.StormThreshold) {
                    dbgRainStorm = w.StormCatchMultiplier;
                    if (w.StormCatchMultiplier != 1.0)
                        multiplier = multiplier * w.StormCatchMultiplier;
                } else if (rain >= w.RainThreshold) {
                    dbgRainStorm = w.RainCatchMultiplier;
                    if (w.RainCatchMultiplier != 1.0)
                        multiplier = multiplier * w.RainCatchMultiplier;
                }
            }

            // ---- time-of-day component ----
            // Exactly one of Dawn / Day / Dusk / Night applies based on hour.
            // Each window has its own global multiplier in WeatherSettings;
            // pick the matching one and stack it.
            int hour = GetCurrentHour();
            int window = ResolveTimeWindow(w, hour);
            dbgWindow = window;
            float timeOfDayMul = 1.0;
            if (window == 0)      timeOfDayMul = w.DawnCatchMultiplier;
            else if (window == 1) timeOfDayMul = w.DayCatchMultiplier;
            else if (window == 2) timeOfDayMul = w.DuskCatchMultiplier;
            else if (window == 3) timeOfDayMul = w.NightCatchMultiplier;
            dbgTimeMul = timeOfDayMul;

            if (timeOfDayMul != 1.0)
                multiplier = multiplier * timeOfDayMul;
        }

        // ---- moon-phase component ----
        // Independent of WeatherCatchBoostEnable. Helper handles disable /
        // daytime / no-op cases and returns 1.0 in any of them.
        float moonMul = GetMoonMultiplier();
        if (moonMul != 1.0)
            multiplier = multiplier * moonMul;

        // ---- cap ----
        // Cap-clamp is logged at DebugLogs >= 1 (not gated to ELEVATED_DEBUG)
        // because a silent clamp is one of the easier "why aren't multipliers
        // doing what I configured" traps -- admins need to see it the first
        // time they turn diagnostics on.
        if (w.MaxStackedMultiplier > 0 && multiplier > w.MaxStackedMultiplier) {
            if (debugLevel >= 1) {
                GebsfishLogger.Debug("Global weather mul clamped: " + multiplier + " -> " + w.MaxStackedMultiplier + " (cap)", "GetWeatherCatchMultiplier");
            }
            multiplier = w.MaxStackedMultiplier;
        }

        if (debugLevel == ELEVATED_DEBUG) {
            GebsfishLogger.Debug("Global weather mul breakdown: rain/storm=" + dbgRainStorm + " window=" + WindowToString(dbgWindow) + " timeMul=" + dbgTimeMul + " moonMul=" + moonMul + " final=" + multiplier, "GetWeatherCatchMultiplier");
        }

        return multiplier;
    }

    override void GenerateResult() {
		// A fully disabled or malformed yield config can leave this empty.
		// Guard before random selection so the range never becomes 0..-1.
		if (!m_ProbabilityArray || m_ProbabilityArray.Count() == 0) {
			if (GetDebugLogLevel()) {
				GebsfishLogger.Debug("No valid fishing yields available. Skipping result generation.", "GenerateResult");
			}
			return;
		}

		YieldItemBase yItem;
		int idx = -1;

		// If per-species weather buffs are configured, pick weighted instead of
		// uniformly so the buff actually biases WHICH fish is selected. The
		// helper returns -1 when buffs are absent / zero / disabled, in which
		// case we fall through to the existing uniform-random path.
		if (HasActiveSpeciesBuffs())
			idx = PickWeightedYieldIndex();

		if (idx < 0)
			idx = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,0,m_ProbabilityArray.Count() - 1);

		// The probability array stores keys into the yield map, so resolve the
		// selected entry before setting it as the active fishing result.
		if (!Class.CastTo(yItem,m_YieldsMapAll.Get(m_ProbabilityArray[idx])) || !yItem) {
			if (GetDebugLogLevel()) {
				GebsfishLogger.Debug("Failed to resolve fishing yield item at probability index: " + idx, "GenerateResult");
			}
			return;
		}

		m_Result.SetYieldItem(yItem);

        if (GetDebugLogLevel()) {
			// Resolve the yield's species classname for the log instead of
			// stringifying the YieldItemBase reference directly. Enforce's
			// default object-to-string for YieldItemBase walks the first
			// internal member, so concatenating yItem directly to a string
			// rendered as something like "[0,..]" rather than a usable name.
			// Casting to GebYieldFishBase gives us the configured species
			// classname (e.g. "geb_BlueGill").
			string yieldClassname = "<unresolved>";
			GebYieldFishBase gyResult;
			if (Class.CastTo(gyResult, yItem) && gyResult)
				yieldClassname = gyResult.GetSpeciesClassname();

			GebsfishLogger.Debug("---------------------Starting New Fishing Session---------------------","GenerateResult");
			GebsfishLogger.Debug("---Generating Fishing Result---","GenerateResult");
            GebsfishLogger.Debug("Random number rolled: " + idx, "GenerateResult");
            GebsfishLogger.Debug("Yield Item Selected: " + yieldClassname, "GenerateResult");
			// Wording note: this fish is locked in at GenerateResult time --
			// the catching context picks once at fishing start, before any
			// signal fires, and that same yield is what spawns on a successful
			// reel-in. The label spells that out so the log isn't mistaken
			// for "one of several possible catches" or for an array index
			// readout. m_Result.GebGetFishingResultName resolves to the same
			// species classname via m_YItem.GetType() -- kept as a second
			// readout because it confirms the result struct actually received
			// the yield (i.e. SetYieldItem succeeded).
			GebsfishLogger.Debug("Pre-determined yield (will spawn on success): " + m_Result.GebGetFishingResultName(),"GenerateResult");

			// Pool composition snapshot. At basic debug level we just log the
			// count + a compact species list so admins can answer "is fish X
			// even eligible right now". At ELEVATED_DEBUG we expand to a per-
			// entry table with env/method/catchProb so anyone asking "why
			// isn't fish X spawning" can read the answer straight from the
			// log (e.g. wrong Environment, CatchProbability=0, masked off).
			LogProbabilityArrayAssembly();
		}
	}

	// Dumps the assembled m_ProbabilityArray with resolved species classnames
	// plus enough surrounding metadata to diagnose pool composition. Split out
	// from GenerateResult to keep that override scannable. Tolerates a null /
	// empty array and a null m_YieldsMapAll without throwing so a misconfigured
	// server still gets a useful log line instead of a silent return.
	protected void LogProbabilityArrayAssembly() {
		int debugLevel = GetDebugLogLevel();
		if (debugLevel < 1)
			return;

		array<int> arr = m_ProbabilityArray;
		if (!arr) {
			GebsfishLogger.Debug("Probability pool: <null>", "PoolAssembly");
			return;
		}

		int n = arr.Count();
		if (n == 0) {
			GebsfishLogger.Debug("Probability pool: [] (empty)", "PoolAssembly");
			return;
		}

		if (debugLevel == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("Probability pool [count=" + n + "]:", "PoolAssembly");
			GebsfishLogger.Debug("idx | key | classname | envMask | methodMask | catchProb", "PoolAssembly");
		}

		string compact = "";
		for (int i = 0; i < n; i++) {
			int key = arr.Get(i);
			string clsName = "<unresolved>";
			int envMask = -1;
			int methodMask = -1;
			int catchProb = -1;
			YieldItemBase y;
			if (m_YieldsMapAll && Class.CastTo(y, m_YieldsMapAll.Get(key)) && y) {
				GebYieldFishBase gy;
				if (Class.CastTo(gy, y) && gy) {
					clsName = gy.GetSpeciesClassname();
					catchProb = gy.GetCatchProbability();
				}
				envMask = y.GetEnviroMask();
				methodMask = y.GetMethodMask();
			}

			if (debugLevel == ELEVATED_DEBUG) {
				GebsfishLogger.Debug("" + i + " | " + key + " | " + clsName + " | " + envMask + " | " + methodMask + " | " + catchProb, "PoolAssembly");
			}

			if (compact != "")
				compact += ", ";
			compact += clsName;
		}

		// Always-on (DebugLogs >= 1) one-liner: comma-separated species list so
		// "is fish X in the pool" is answerable at the lower debug level too.
		GebsfishLogger.Debug("Pool species (" + n + "): " + compact, "PoolAssembly");
	}

    override float RandomizeSignalDuration() {
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalDurationMin,m_SignalDurationMax);
		
		if (GetDebugLogLevel() == ELEVATED_DEBUG ) {
			GebsfishLogger.Debug("---RandomizeSignalDuration---","RandomizeSignalDuration");
			GebsfishLogger.Debug("next signal duration: " + res,"RandomizeSignalDuration");
		}

		if (GetDebugLogLevel()) {
			GebsfishLogger.Debug("Catch signal duration chosen: " + res,"RandomizeSignalDuration");
		}
		
		return res;
	}

    override float RandomizeSignalStartTime() {
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalStartTimeMin,m_SignalStartTimeMax);

		if (GetDebugLogLevel() == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---RandomizeSignalStartTime---","RandomizeSignalStartTime");
			GebsfishLogger.Debug("next signal start time: " + res,"RandomizeSignalStartTime");
		}

		if (GetDebugLogLevel()) {
			GebsfishLogger.Debug("Catch signal starts at: " + res,"RandomizeSignalStartTime");
		}
		
		return res;
	}

	override protected void TryHookLoss() {
		if (m_Hook && !m_Hook.IsSetForDeletion()) {
			float lossChance = GetHookLossChanceModifierClamped();
			if (lossChance <= 0)
				return;

			float roll = m_Player.GetRandomGeneratorSyncManager().GetRandom01(RandomGeneratorSyncUsage.RGSAnimalCatching);
			string hookType = m_Hook.GetType();

			if (lossChance >= 1 || roll < lossChance) {
				RemoveItemSafe(m_Hook);
				if (GetDebugLogLevel()) {
					GebsfishLogger.Debug("Hook was lost. type=" + hookType + " roll=" + roll + " lossChance=" + lossChance,"TryHookLoss");
				}
			}
            else {
				if (GetDebugLogLevel()) {
					GebsfishLogger.Debug("Hook was not lost. type=" + hookType + " roll=" + roll + " lossChance=" + lossChance,"TryHookLoss");
				}
			}
		}
	}

	override protected void RemoveItemSafe(EntityAI item) {
		if (item && !m_Player.IsQuickFishing()) {
			string parentType = item.GetType();
			float parentHpBefore = -1;
			ItemBase parentAsItem = ItemBase.Cast(item);
			if (parentAsItem)
				parentHpBefore = parentAsItem.GetHealth("","Health");

			// Hooks can carry an attached bait item (worm, minnow, salamander,
			// etc.) in their "Bait" slot -- same slot name vanilla uses in
			// CatchingContextFishingRodAction.AddCatchingItem. Deleting the hook
			// without first flagging that attachment for deletion would leave
			// the bait orphaned (or trip an attachment-detach error inside the
			// engine's parent cleanup). The original vanilla comment punted on
			// this with "the action terminates anyway" -- handle it properly so
			// the inventory stays consistent if any other system reads it
			// mid-cleanup.
			EntityAI attachedBait = item.FindAttachmentBySlotName("Bait");
			if (attachedBait) {
				string attachedType = attachedBait.GetType();
				attachedBait.SetPrepareToDelete();
				attachedBait.DeleteSafe();
				if (GetDebugLogLevel()) {
					GebsfishLogger.Debug("Cleaned up attached bait before parent removal: type=" + attachedType + " (parent=" + parentType + ")","RemoveItemSafe");
				}
			}

			item.SetPrepareToDelete();
			item.DeleteSafe();

			if (GetDebugLogLevel()) {
				GebsfishLogger.Debug("Item Lost: type=" + parentType + " hpAtRemoval=" + parentHpBefore + "; Removing item from player inventory.","RemoveItemSafe");
			}
		}
	}

	override protected void TryDamageItems() {
		if (!g_Game.IsMultiplayer() || g_Game.IsDedicatedServer()) {
			if (m_Hook && !m_Hook.IsSetForDeletion()) {
				float hookHpBefore = m_Hook.GetHealth("","Health");
				string hookType = m_Hook.GetType();
				if (GetDebugLogLevel()) {
					GebsfishLogger.Debug("Applying damage to hook: type=" + hookType + " hpBefore=" + hookHpBefore + " dmg=" + UAFishingConstants.DAMAGE_HOOK,"TryDamageItems");
				}
				m_Hook.AddHealth("","Health",-UAFishingConstants.DAMAGE_HOOK);
				// First AddHealth on the rod (the 3-arg form lands on hooks
				// just fine but silently no-ops on rods, so we still call the
				// single-arg form below). Guard m_MainItem here -- the player
				// could have dropped the rod mid-action and the later
				// `if (m_MainItem)` block guards only its own usage, not this
				// line.
				if (m_MainItem)
                    m_MainItem.AddHealth(-UAFishingConstants.DAMAGE_HOOK);
				if (GetDebugLogLevel()) {
					GebsfishLogger.Debug("Hook HP after: type=" + hookType + " hpAfter=" + m_Hook.GetHealth("","Health"),"TryDamageItems");
				}
				// Vanilla's old ActionFishingNew used the single-arg form
				// (AddHealth(-1.5)) on the rod, not the 3-arg form. The rod's
				// damage system seems to require it -- the 3-arg form lands on
				// hooks just fine but silently no-ops on rods. Matching vanilla's
				// exact signature here.
				if (m_MainItem) {
					float rodHpBefore = m_MainItem.GetHealth("","Health");
					string rodType = m_MainItem.GetType();
					if (GetDebugLogLevel()) {
						GebsfishLogger.Debug("Applying damage to rod: type=" + rodType + " hpBefore=" + rodHpBefore + " dmg=" + UAFishingConstants.DAMAGE_HOOK,"TryDamageItems");
					}
					m_MainItem.AddHealth(-UAFishingConstants.DAMAGE_HOOK);
					if (GetDebugLogLevel()) {
						GebsfishLogger.Debug("Rod HP after: type=" + rodType + " hpAfter=" + m_MainItem.GetHealth("","Health"),"TryDamageItems");
					}
				}
			}
		}
	}

	override void OnBeforeSpawnSignalHit() {
		if (GetDebugLogLevel()) {
			GebsfishLogger.Debug("Trying hook loss before catch signal is generated.","OnBeforeSpawnSignalHit");
		}
		TryHookLoss();
	}

	override void OnAfterSpawnSignalHit() {
		if (GetDebugLogLevel()) {
			string baitType = "<none>";
			if (m_Bait)
				baitType = m_Bait.GetType();
			GebsfishLogger.Debug("Catch signal success. Removing bait (" + baitType + ") and damaging hook.","OnAfterSpawnSignalHit");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
	}

	//! release without signal
	override void OnSignalMiss() {
		if (GetDebugLogLevel()) {
			string hookTypeM = "<none>";
			string baitTypeM = "<none>";
			if (m_Hook) hookTypeM = m_Hook.GetType();
			if (m_Bait) baitTypeM = m_Bait.GetType();
			GebsfishLogger.Debug("Catch signal missed. Trying hook (" + hookTypeM + ") and bait (" + baitTypeM + ") loss.","OnSignalMiss");
		}
		TryHookLoss();
		TryBaitLoss();
	}

	override void OnSignalPass() {
		if (GetDebugLogLevel()) {
			string baitTypeP = "<none>";
			if (m_Bait)
				baitTypeP = m_Bait.GetType();
			GebsfishLogger.Debug("Catch signal ignored. Removing bait (" + baitTypeP + "), applying damage to hook, and updating catching item data.","OnSignalPass");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
		UpdateCatchingItemData();
	}
}
