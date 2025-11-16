//added file only for debugging. Remove code in future. 

modded class CatchingContextFishingRodAction : CatchingContextFishingBase
{
    
    override void InitCatchingItemData()
	{
		super.InitCatchingItemData();
		
		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG)
		{
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

    override bool ModifySignalProbability(inout float probability)
	{
		float easingTime;
		if ((float)m_SignalCurrent < m_SignalCycleTarget)
		{
			easingTime = Math.InverseLerp(0,m_SignalCycleTarget,(float)m_SignalCurrent);
			probability = Easing.EaseInExpo(easingTime) * m_SignalTargetProbability * GetChanceCoef();
		}
		else
		{
			easingTime = Math.InverseLerp(m_SignalCycleTarget,m_SignalCycleEndTarget,(float)m_SignalCurrent);
			probability = (m_SignalTargetProbability + (Easing.EaseInExpo(easingTime) * (m_SignalTargetEndProbability - m_SignalTargetProbability))) * GetChanceCoef();
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG)
		{
			GebsfishLogger.Debug("---ModifySignalProbability---","ModifySignalProbability");
			GebsfishLogger.Debug("m_SignalCurrent: " + m_SignalCurrent,"ModifySignalProbability");
			GebsfishLogger.Debug("easingTime: " + easingTime,"ModifySignalProbability");
			GebsfishLogger.Debug("probability: " + probability,"ModifySignalProbability");
		}
		
		return true;
    }

    override void GenerateResult()
	{
		YieldItemBase yItem;
		int idx = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,0,m_ProbabilityArray.Count() - 1);
		Class.CastTo(yItem,m_YieldsMapAll.Get(m_ProbabilityArray[idx]));
		m_Result.SetYieldItem(yItem);

        if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("---------------------Starting New Fishing Session---------------------","GenerateResult")
			GebsfishLogger.Debug("---Generating Fishing Result---","GenerateResult");
            GebsfishLogger.Debug("Random number rolled: " + idx, "GenerateResult");
            GebsfishLogger.Debug("Yield Item Selected: " + yItem, "GenerateResult");
			GebsfishLogger.Debug("Possible Catch: " + m_Result.GebGetFishingResultName(),"GenerateResult");

			if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG) 
			{
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
				for (int i = 0; i < n; i++)
				{
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

    override float RandomizeSignalDuration()
	{
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalDurationMin,m_SignalDurationMax);
		
		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG )
		{
			GebsfishLogger.Debug("---RandomizeSignalDuration---","RandomizeSignalDuration");
			GebsfishLogger.Debug("next signal duration: " + res,"RandomizeSignalDuration");
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("Catch signal duration chosen: " + res,"RandomizeSignalDuration");
		}
		
		return res;
	}

    override float RandomizeSignalStartTime()
	{
		float res = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSAnimalCatching,m_SignalStartTimeMin,m_SignalStartTimeMax);

		if (m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG)
		{
			GebsfishLogger.Debug("---RandomizeSignalStartTime---","RandomizeSignalStartTime");
			GebsfishLogger.Debug("next signal start time: " + res,"RandomizeSignalStartTime");
		}

		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("Catch signal starts at: " + res,"RandomizeSignalStartTime");
		}
		
		return res;
	}

	override protected void TryHookLoss()
	{
		if (m_Hook && !m_Hook.IsSetForDeletion())
		{
			float lossChance = GetHookLossChanceModifierClamped();
			if (lossChance <= 0)
				return;
			
			float roll = m_Player.GetRandomGeneratorSyncManager().GetRandom01(RandomGeneratorSyncUsage.RGSAnimalCatching);
			
			if (lossChance >= 1 || roll < lossChance)
			{
				RemoveItemSafe(m_Hook);
				if (m_gebsConfig.GeneralSettings.DebugLogs)
				{
					GebsfishLogger.Debug("Hook was lost.","TryHookLoss");
				}
			} else 
			{
				if (m_gebsConfig.GeneralSettings.DebugLogs)
				{
					GebsfishLogger.Debug("Hook was not lost.","TryHookLoss");
				}
			}	
		}
	}

	override protected void RemoveItemSafe(EntityAI item)
	{
		if (item && !m_Player.IsQuickFishing())
		{
			item.SetPrepareToDelete(); //should probably flag the bait too, but the action terminates anyway
			item.DeleteSafe();

			if (m_gebsConfig.GeneralSettings.DebugLogs)
				{
					GebsfishLogger.Debug("Item Lost: " + item.GetType() + "; Removing item from player inventory.","RemoveItemSafe");
				}
		}
	}

	override protected void TryDamageItems()
	{
		if (!g_Game.IsMultiplayer() || g_Game.IsDedicatedServer())
		{
			if (m_Hook && !m_Hook.IsSetForDeletion())
				if (m_gebsConfig.GeneralSettings.DebugLogs)
				{
					GebsfishLogger.Debug("Applying damage to item: " + m_Hook.GetType() ,"TryDamageItems");
				}
				m_Hook.AddHealth("","Health",-UAFishingConstants.DAMAGE_HOOK);

		}
	}

	override void OnBeforeSpawnSignalHit()
	{
		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("Trying hook loss before catch signal is generated.","OnBeforeSpawnSignalHit");
		}
		TryHookLoss();
	}
	
	override void OnAfterSpawnSignalHit()
	{
		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("Catch signal success. Removing bait and damaging hook.","OnAfterSpawnSignalHit");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
	}
	
	//! release without signal
	override void OnSignalMiss()
	{
		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("Catch signal missed. Trying hook and bait loss.","OnSignalMiss");
		}
		TryHookLoss();
		TryBaitLoss();
	}
	
	override void OnSignalPass()
	{
		if (m_gebsConfig.GeneralSettings.DebugLogs)
		{
			GebsfishLogger.Debug("catch signal ignored. Removing bait, applying damage to hook, and updating catching item data.","OnSignalPass");
		}
		RemoveItemSafe(m_Bait);
		TryDamageItems();
		UpdateCatchingItemData();
	}
}
