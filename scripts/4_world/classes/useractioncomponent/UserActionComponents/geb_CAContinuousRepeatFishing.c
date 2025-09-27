modded class CAContinuousRepeatFishing : CAContinuousRepeat
{
    override void SetNewSignalData(float startTime, float durationTime)
	{
		if (startTime == NO_SIGNAL && durationTime == NO_SIGNAL)
		{
			m_SignalStartTime = startTime;
			m_SignalDuration = durationTime;
		}
		else
		{
			//float maximalUsableDuration = Math.Clamp(m_TimeToComplete - UAFishingConstants.SIGNAL_DEADZONE_END_DURATION - UAFishingConstants.SIGNAL_DEADZONE_START_DURATION,UAFishingConstants.SIGNAL_DURATION_MIN_BASE,UAFishingConstants.SIGNAL_DURATION_MAX_BASE);
			float maximalUsableDuration = m_TimeToComplete - UAFishingConstants.SIGNAL_DEADZONE_END_DURATION - UAFishingConstants.SIGNAL_DEADZONE_START_DURATION;
			if (maximalUsableDuration < UAFishingConstants.SIGNAL_DURATION_MIN_BASE)
			{
				if (maximalUsableDuration <= 0)
				{
					float deadzonesTime = UAFishingConstants.SIGNAL_DEADZONE_END_DURATION + UAFishingConstants.SIGNAL_DEADZONE_START_DURATION;

                    if (m_gebsConfig.GeneralSettings.DebugLogs)
	            	{
					    GebsfishLogger.Debug("Cycle m_TimeToComplete: " + m_TimeToComplete + " shorter than combined deadzone times: " + deadzonesTime + "! No time left for any signal, skipping!","FishingCA");
                    }
				}
				else
				{
                    if (m_gebsConfig.GeneralSettings.DebugLogs)
                	{
					    GebsfishLogger.Debug("maximalUsableDuration " + maximalUsableDuration + " is shorter than UAFishingConstants.SIGNAL_DURATION_MIN_BASE, skipping signal!","FishingCA");
                    }
				}
				
				m_SignalStartTime = NO_SIGNAL;
				m_SignalDuration = NO_SIGNAL;
				return;
			}
			
			m_SignalDuration = Math.Clamp(durationTime,UAFishingConstants.SIGNAL_DURATION_MIN_BASE,Math.Min(maximalUsableDuration,UAFishingConstants.SIGNAL_DURATION_MAX_BASE)); //scaled down if needed, guaranteed at least SIGNAL_DURATION_MIN_BASE
			m_SignalStartTime = Math.Clamp(startTime,UAFishingConstants.SIGNAL_DEADZONE_START_DURATION,(m_TimeToComplete - m_SignalDuration - UAFishingConstants.SIGNAL_DEADZONE_END_DURATION));
			m_SignalEndTime = m_SignalStartTime + m_SignalDuration;
			
			if (durationTime != m_SignalDuration)
			{
                if (m_gebsConfig.GeneralSettings.DebugLogs)
		        {
				    GebsfishLogger.Debug("Signal durationTime adjusted from " + durationTime + " to " + m_SignalDuration + ". maximalUsableDuration: " + maximalUsableDuration + ", m_TimeToComplete: " + m_TimeToComplete,"FishingCA");
                }
			}
			if (startTime != m_SignalStartTime)
			{
                if (m_gebsConfig.GeneralSettings.DebugLogs)
		        {
				    GebsfishLogger.Debug("Signal startTime adjusted from " + startTime + " to " + m_SignalStartTime + ". m_SignalDuration: " + m_SignalDuration + ", m_TimeToComplete: " + m_TimeToComplete,"FishingCA");
                }
			}
		}
	}
}