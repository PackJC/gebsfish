modded class CAContinuousRepeatFishing : CAContinuousRepeat {
    override void SetNewSignalData(float startTime, float durationTime) {
		if (startTime == NO_SIGNAL && durationTime == NO_SIGNAL) {
			m_SignalStartTime = startTime;
			m_SignalDuration = durationTime;
		}
		else {
			// Intentionally unclamped (vanilla clamps to SIGNAL_DURATION_MIN/MAX);
			// the too-short case is handled explicitly in the branch just below.
			float maximalUsableDuration = m_TimeToComplete - UAFishingConstants.SIGNAL_DEADZONE_END_DURATION - UAFishingConstants.SIGNAL_DEADZONE_START_DURATION;
			if (maximalUsableDuration < UAFishingConstants.SIGNAL_DURATION_MIN_BASE) {
				if (maximalUsableDuration <= 0) {
					float deadzonesTime = UAFishingConstants.SIGNAL_DEADZONE_END_DURATION + UAFishingConstants.SIGNAL_DEADZONE_START_DURATION;

                    if (GebGetDebugLevel() >= 1) {
					    GebsfishLogger.Debug("Cycle m_TimeToComplete: " + m_TimeToComplete + " shorter than combined deadzone times: " + deadzonesTime + "! No time left for any signal, skipping!","FishingCA");
                    }
				}
				else {
                    if (GebGetDebugLevel() >= 1) {
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
			
			if (durationTime != m_SignalDuration) {
                if (GebGetDebugLevel() >= 1) {
				    GebsfishLogger.Debug("Signal durationTime adjusted from " + durationTime + " to " + m_SignalDuration + ". maximalUsableDuration: " + maximalUsableDuration + ", m_TimeToComplete: " + m_TimeToComplete,"FishingCA");
                }
			}
			if (startTime != m_SignalStartTime) {
                if (GebGetDebugLevel() >= 1) {
				    GebsfishLogger.Debug("Signal startTime adjusted from " + startTime + " to " + m_SignalStartTime + ". m_SignalDuration: " + m_SignalDuration + ", m_TimeToComplete: " + m_TimeToComplete,"FishingCA");
                }
			}
		}
	}
}