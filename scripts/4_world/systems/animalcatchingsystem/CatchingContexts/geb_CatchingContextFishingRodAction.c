//added file only for debugging. Remove code in future.
//Can we remove this for 1.29? Cole - 3/25/26

modded class CatchingContextFishingRodAction : CatchingContextFishingBase {
    override void InitCatchingItemData() {
		super.InitCatchingItemData();

		// Per-fish bite-speed scaling. Aggregates the 24-hour BiteSpeed arrays
		// off every yield in the current pool (weighted by CatchProbability x
		// time-of-day multiplier), then stretches the cycle inversely. Lower
		// aggregate -> longer wait. Skipped entirely when the buff is disabled
		// in config so vanilla servers see no change.
		float cycleTargetBefore = m_SignalCycleTarget;
		float cycleEndBefore = m_SignalCycleEndTarget;
		float biteSpeed = ComputeAggregateBiteSpeed();
		if (biteSpeed != 1.0) {
			m_SignalCycleTarget = m_SignalCycleTarget / biteSpeed;
			m_SignalCycleEndTarget = m_SignalCycleEndTarget / biteSpeed;
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs >= 1) {
			GebsfishLogger.Debug("Cycle scaled by BiteSpeed=" + biteSpeed + ": cycleTarget " + cycleTargetBefore + "->" + m_SignalCycleTarget + ", cycleEnd " + cycleEndBefore + "->" + m_SignalCycleEndTarget, "InitCatchingItemData");
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
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
		int debugLevel = m_gebsConfig.GeneralSettings.DebugLogs;

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

			float weatherMul = GetSpeciesWeatherMultiplier(gy);
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

		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
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
        int debugLevel = m_gebsConfig.GeneralSettings.DebugLogs;
        string baitClassname = GetCurrentBaitClassname();

        if (debugLevel == ELEVATED_DEBUG) {
            GebsfishLogger.Debug("---PickWeightedYieldIndex (bait=" + baitClassname + ")---", "GenerateResult");
            GebsfishLogger.Debug("species | weatherMul | baitMul | scaled", "GenerateResult");
        }

        for (int i = 0; i < n; i++) {
            YieldItemBase y;
            int weight = SCALE;  // baseline weight when no buff applies

            if (Class.CastTo(y, m_YieldsMapAll.Get(m_ProbabilityArray[i])) && y) {
                GebYieldFishBase gy;
                if (Class.CastTo(gy, y) && gy) {
                    float weatherMul = GetSpeciesWeatherMultiplier(gy);
                    float baitMul = GetBaitMultiplier(gy.GetSpeciesClassname(), baitClassname);
                    weight = Math.Round(SCALE * weatherMul * baitMul);
                    if (weight < 0)
                        weight = 0;

                    if (debugLevel == ELEVATED_DEBUG) {
                        GebsfishLogger.Debug(gy.GetSpeciesClassname() + " | " + weatherMul + " | " + baitMul + " | " + weight, "GenerateResult");
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
    protected string GetCurrentBaitClassname() {
        if (m_Bait)
            return m_Bait.GetType();
        if (m_Hook)
            return m_Hook.GetType();
        return "";
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
            if (!bait || bait.BaitClassname != baitClassname)
                continue;
            if (!bait.Preferences)
                return 1.0;
            foreach (BaitPreferenceEntry pref : bait.Preferences) {
                if (pref && pref.FishClassname == fishClassname)
                    return pref.Multiplier;
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
    protected float GetSpeciesWeatherMultiplier(GebYieldFishBase gy) {
        if (!gy)
            return 1.0;
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;

        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.WeatherCatchBoostEnable && !w.TemperatureEffectEnable)
            return 1.0;

        float multiplier = 1.0;

        if (w.WeatherCatchBoostEnable) {
            float speciesRain  = gy.GetRainMultiplier();
            float speciesStorm = gy.GetStormMultiplier();

            // Rain / storm component (mutually exclusive, matches global rule).
            Weather weather = g_Game.GetWeather();
            if (weather && weather.GetRain()) {
                float rain = weather.GetRain().GetActual();
                if (rain >= w.StormThreshold && speciesStorm != 1.0) {
                    multiplier = multiplier * speciesStorm;
                } else if (rain >= w.RainThreshold && speciesRain != 1.0) {
                    multiplier = multiplier * speciesRain;
                }
            }

            // Time-of-day component. Exactly one of Dawn / Day / Dusk / Night
            // applies based on the current hour; pick the matching species
            // multiplier and stack it onto the running total.
            int hour = GetCurrentHour();
            float speciesTimeOfDay = 1.0;
            int window = ResolveTimeWindow(w, hour);
            if (window == 0)      speciesTimeOfDay = gy.GetDawnMultiplier();
            else if (window == 1) speciesTimeOfDay = gy.GetDayMultiplier();
            else if (window == 2) speciesTimeOfDay = gy.GetDuskMultiplier();
            else if (window == 3) speciesTimeOfDay = gy.GetNightMultiplier();

            if (speciesTimeOfDay != 1.0)
                multiplier = multiplier * speciesTimeOfDay;
        }

        // ---- temperature component ----
        // Independent of WeatherCatchBoostEnable. Helper returns 1.0 when
        // disabled or when the fish wasn't wired through SetTemperature yet.
        float tempMul = GetSpeciesTempMultiplier(gy);
        if (tempMul != 1.0)
            multiplier = multiplier * tempMul;

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
    // Checks dawn/day/dusk first since night may wrap midnight and is the
    // catch-all fallback.
    protected int ResolveTimeWindow(WeatherConf w, int hour) {
        if (w.DawnStartHour != w.DawnEndHour && hour >= w.DawnStartHour && hour < w.DawnEndHour)
            return 0;
        if (w.DayStartHour != w.DayEndHour && hour >= w.DayStartHour && hour < w.DayEndHour)
            return 1;
        if (w.DuskStartHour != w.DuskEndHour && hour >= w.DuskStartHour && hour < w.DuskEndHour)
            return 2;
        if (w.NightStartHour != w.NightEndHour) {
            bool isNight;
            if (w.NightStartHour < w.NightEndHour)
                isNight = (hour >= w.NightStartHour && hour < w.NightEndHour);
            else
                isNight = (hour >= w.NightStartHour || hour < w.NightEndHour);
            if (isNight)
                return 3;
        }
        return -1;
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

        float multiplier = 1.0;

        if (w.WeatherCatchBoostEnable) {
            // ---- rain / storm component ----
            Weather weather = g_Game.GetWeather();
            if (weather && weather.GetRain()) {
                float rain = weather.GetRain().GetActual();
                if (rain >= w.StormThreshold && w.StormCatchMultiplier != 1.0) {
                    multiplier = multiplier * w.StormCatchMultiplier;
                } else if (rain >= w.RainThreshold && w.RainCatchMultiplier != 1.0) {
                    multiplier = multiplier * w.RainCatchMultiplier;
                }
            }

            // ---- time-of-day component ----
            // Exactly one of Dawn / Day / Dusk / Night applies based on hour.
            // Each window has its own global multiplier in WeatherSettings;
            // pick the matching one and stack it.
            int hour = GetCurrentHour();
            int window = ResolveTimeWindow(w, hour);
            float timeOfDayMul = 1.0;
            if (window == 0)      timeOfDayMul = w.DawnCatchMultiplier;
            else if (window == 1) timeOfDayMul = w.DayCatchMultiplier;
            else if (window == 2) timeOfDayMul = w.DuskCatchMultiplier;
            else if (window == 3) timeOfDayMul = w.NightCatchMultiplier;

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
        if (w.MaxStackedMultiplier > 0 && multiplier > w.MaxStackedMultiplier)
            multiplier = w.MaxStackedMultiplier;

        return multiplier;
    }

    override void GenerateResult() {
		// A fully disabled or malformed yield config can leave this empty.
		// Guard before random selection so the range never becomes 0..-1.
		if (!m_ProbabilityArray || m_ProbabilityArray.Count() == 0) {
			if (m_gebsConfig && m_gebsConfig.GeneralSettings.DebugLogs) {
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
			if (m_gebsConfig && m_gebsConfig.GeneralSettings.DebugLogs) {
				GebsfishLogger.Debug("Failed to resolve fishing yield item at probability index: " + idx, "GenerateResult");
			}
			return;
		}

		m_Result.SetYieldItem(yItem);

        if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("---------------------Starting New Fishing Session---------------------","GenerateResult");
			GebsfishLogger.Debug("---Generating Fishing Result---","GenerateResult");
            GebsfishLogger.Debug("Random number rolled: " + idx, "GenerateResult");
            GebsfishLogger.Debug("Yield Item Selected: " + yItem, "GenerateResult");
			GebsfishLogger.Debug("Possible Catch: " + m_Result.GebGetFishingResultName(),"GenerateResult");

			if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
				array<int> arr = m_ProbabilityArray;
				string name = "m_ProbabilityArray";
				if (!arr) {
					GebsfishLogger.Debug(name + ": <null>", "Probabilities");
					return;
				}

				int n = arr.Count();
				if (n == 0) {
					GebsfishLogger.Debug(name + ": [] (empty)", "Probabilities");
					return;
				}

				string line = name + " [count=" + n.ToString() + "]: ";
				for (int i = 0; i < n; i++) {
					float v = arr.Get(i);
					// optional: round to 3 decimals to keep lines short
					float rv = Math.Round(v * 1000.0) / 1000.0;

					line += "#" + i.ToString() + "=" + v.ToString();
					if (i < n - 1) line += ", ";

					// flush every 30 entries to avoid mega-lines
					if ((i % 30) == 29) {
						GebsfishLogger.Debug(line, "Probabilities");
						line = "";
					}
				}
			}
		}
	}

    override float RandomizeSignalDuration() {
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalDurationMin,m_SignalDurationMax);
		
		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG ) {
			GebsfishLogger.Debug("---RandomizeSignalDuration---","RandomizeSignalDuration");
			GebsfishLogger.Debug("next signal duration: " + res,"RandomizeSignalDuration");
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("Catch signal duration chosen: " + res,"RandomizeSignalDuration");
		}
		
		return res;
	}

    override float RandomizeSignalStartTime() {
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalStartTimeMin,m_SignalStartTimeMax);

		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---RandomizeSignalStartTime---","RandomizeSignalStartTime");
			GebsfishLogger.Debug("next signal start time: " + res,"RandomizeSignalStartTime");
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs) {
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
			
			if (lossChance >= 1 || roll < lossChance) {
				RemoveItemSafe(m_Hook);
				if (m_gebsConfig.GeneralSettings.DebugLogs) {
					GebsfishLogger.Debug("Hook was lost.","TryHookLoss");
				}
			} 
            else {
				if (m_gebsConfig.GeneralSettings.DebugLogs) {
					GebsfishLogger.Debug("Hook was not lost.","TryHookLoss");
				}
			}	
		}
	}

	override protected void RemoveItemSafe(EntityAI item) {
		if (item && !m_Player.IsQuickFishing()) {
			item.SetPrepareToDelete(); //should probably flag the bait too, but the action terminates anyway
			item.DeleteSafe();

			if (m_gebsConfig.GeneralSettings.DebugLogs) {
				GebsfishLogger.Debug("Item Lost: " + item.GetType() + "; Removing item from player inventory.","RemoveItemSafe");
			}
		}
	}

	override protected void TryDamageItems() {
		if (!g_Game.IsMultiplayer() || g_Game.IsDedicatedServer()) {
			if (m_Hook && !m_Hook.IsSetForDeletion()) {
				if (m_gebsConfig.GeneralSettings.DebugLogs) {
					GebsfishLogger.Debug("Applying damage to item: " + m_Hook.GetType() ,"TryDamageItems");
				}
				m_Hook.AddHealth("","Health",-UAFishingConstants.DAMAGE_HOOK);
			}
		}
	}

	override void OnBeforeSpawnSignalHit() {
		if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("Trying hook loss before catch signal is generated.","OnBeforeSpawnSignalHit");
		}
		TryHookLoss();
	}
	
	override void OnAfterSpawnSignalHit() {
		if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("Catch signal success. Removing bait and damaging hook.","OnAfterSpawnSignalHit");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
	}
	
	//! release without signal
	override void OnSignalMiss() {
		if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("Catch signal missed. Trying hook and bait loss.","OnSignalMiss");
		}
		TryHookLoss();
		TryBaitLoss();
	}
	
	override void OnSignalPass() {
		if (m_gebsConfig.GeneralSettings.DebugLogs) {
			GebsfishLogger.Debug("catch signal ignored. Removing bait, applying damage to hook, and updating catching item data.","OnSignalPass");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
		UpdateCatchingItemData();
	}
}
