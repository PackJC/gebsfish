//added file only for debugging. Remove code in future.
//Can we remove this for 1.29? Cole - 3/25/26

modded class CatchingContextFishingRodAction : CatchingContextFishingBase {
    override void InitCatchingItemData() {
		super.InitCatchingItemData();
		
		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
			GebsfishLogger.Debug("---InitCatchingItemData---","InitCatchingItemData");
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
    // multipliers cached on each GebYieldFishBase at registration time (read
    // off the matching FishConf's RainMultiplier / StormMultiplier /
    // NightMultiplier fields in SetupYield).
    // Returns -1 on any error condition (zero total weight, cast failures, etc.)
    // so the caller falls back to the existing uniform pick. Stays sync-safe by
    // using GetRandomInRange against an integer-scaled cumulative weight.
    protected int PickWeightedYieldIndex() {
        int n = m_ProbabilityArray.Count();
        if (n <= 0)
            return -1;

        // Scale floats to ints (×1000) so weighted-random can use the integer
        // sync RNG, keeping client and server in lockstep.
        const int SCALE = 1000;
        ref array<int> scaled = new array<int>;
        scaled.Reserve(n);
        int total = 0;

        for (int i = 0; i < n; i++) {
            YieldItemBase y;
            int weight = SCALE;  // baseline weight when no buff applies

            if (Class.CastTo(y, m_YieldsMapAll.Get(m_ProbabilityArray[i])) && y) {
                GebYieldFishBase gy;
                if (Class.CastTo(gy, y) && gy) {
                    float mul = GetSpeciesWeatherMultiplier(gy);
                    weight = Math.Round(SCALE * mul);
                    if (weight < 0)
                        weight = 0;
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
                if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) {
                    GebsfishLogger.Debug("Weighted yield pick: idx=" + j + " roll=" + roll + " total=" + total, "GenerateResult");
                }
                return j;
            }
        }
        return n - 1;  // floating-point edge case; clamp to last
    }

    // Per-species multiplier overlay. Reads the per-species Rain/Storm/Night
    // multipliers straight off the GebYieldFishBase (cached there at
    // registration time from the matching FishConf), then applies the same
    // rain/storm/night conditions as the global multiplier. Yields that
    // weren't passed multipliers in SetupYield default to 1.0 (no effect).
    protected float GetSpeciesWeatherMultiplier(GebYieldFishBase gy) {
        if (!gy)
            return 1.0;
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;

        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.WeatherCatchBoostEnable)
            return 1.0;

        float speciesRain  = gy.GetRainMultiplier();
        float speciesStorm = gy.GetStormMultiplier();
        float speciesNight = gy.GetNightMultiplier();

        float multiplier = 1.0;

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

        // Night component (stacks with rain/storm).
        if (w.NightStartHour != w.NightEndHour && speciesNight != 1.0) {
            int year, month, day, hour, minute;
            g_Game.GetWorld().GetDate(year, month, day, hour, minute);
            bool isNight = false;
            if (w.NightStartHour < w.NightEndHour) {
                isNight = (hour >= w.NightStartHour && hour < w.NightEndHour);
            } else {
                isNight = (hour >= w.NightStartHour || hour < w.NightEndHour);
            }
            if (isNight)
                multiplier = multiplier * speciesNight;
        }

        return multiplier;
    }

    // Computes the combined rain / storm / night multiplier from the current
    // world state. Returns 1.0 (no effect) when the buff is disabled in config,
    // when no condition is currently active, or when weather/world state isn't
    // available yet (mission startup race).
    //
    // Rain and storm are mutually exclusive (storm replaces rain rather than
    // stacking with it). Rain/storm CAN stack with night. Combined result is
    // clamped to WeatherSettings.MaxStackedMultiplier so a stormy night never
    // becomes a runaway printer.
    protected float GetWeatherCatchMultiplier() {
        if (!m_gebsConfig || !m_gebsConfig.WeatherSettings)
            return 1.0;

        WeatherConf w = m_gebsConfig.WeatherSettings;
        if (!w.WeatherCatchBoostEnable)
            return 1.0;

        float multiplier = 1.0;

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

        // ---- night component ----
        // Skip when the configured window is zero-length (start == end), which
        // is the convention for "disable the night buff."
        if (w.NightStartHour != w.NightEndHour && w.NightCatchMultiplier != 1.0) {
            int year, month, day, hour, minute;
            g_Game.GetWorld().GetDate(year, month, day, hour, minute);

            bool isNight = false;
            if (w.NightStartHour < w.NightEndHour) {
                // Same-day window, e.g. 14..18.
                isNight = (hour >= w.NightStartHour && hour < w.NightEndHour);
            } else {
                // Wraps midnight, e.g. 20..6.
                isNight = (hour >= w.NightStartHour || hour < w.NightEndHour);
            }

            if (isNight)
                multiplier = multiplier * w.NightCatchMultiplier;
        }

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
