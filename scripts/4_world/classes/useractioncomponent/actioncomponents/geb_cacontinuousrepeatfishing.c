// At elevated debug logging each fishing cycle's bite window is logged, as the
// old timing override did. (Until 2026-10-14 this class also raised bubbles
// at the cast point just before a bite.)
modded class CAContinuousRepeatFishing {
	override void SetNewSignalData(float startTime, float durationTime) {
		super.SetNewSignalData(startTime, durationTime);

		if (GebGetDebugLevel() == ELEVATED_DEBUG) {
			if (m_SignalStartTime == NO_SIGNAL || m_SignalDuration == NO_SIGNAL)
				GebsfishLogger.Debug("Cycle of " + m_TimeToComplete + " s has no bite signal (requested start " + startTime + " s, duration " + durationTime + " s).", "FishingCA");
			else
				GebsfishLogger.Debug("Bite signal at " + m_SignalStartTime + " s for " + m_SignalDuration + " s in a " + m_TimeToComplete + " s cycle (requested start " + startTime + " s, duration " + durationTime + " s).", "FishingCA");
		}
	}
}
