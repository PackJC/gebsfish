// Bubbles rise at the cast point just before a bite, a cue to get ready. The
// bite's start time is set for each cycle on client and server alike; the
// server shows the bubbles, so everyone nearby sees them. At elevated debug
// logging each cycle's bite window is logged, as the old timing override did.
modded class CAContinuousRepeatFishing {
	protected const float GEB_BUBBLES_LEAD_SECS = 1.5;
	protected bool m_GebBubblesShown;

	override void SetNewSignalData(float startTime, float durationTime) {
		super.SetNewSignalData(startTime, durationTime);
		m_GebBubblesShown = false;

		if (GebGetDebugLevel() == ELEVATED_DEBUG) {
			if (m_SignalStartTime == NO_SIGNAL || m_SignalDuration == NO_SIGNAL)
				GebsfishLogger.Debug("Cycle of " + m_TimeToComplete + " s has no bite signal (requested start " + startTime + " s, duration " + durationTime + " s).", "FishingCA");
			else
				GebsfishLogger.Debug("Bite signal at " + m_SignalStartTime + " s for " + m_SignalDuration + " s in a " + m_TimeToComplete + " s cycle (requested start " + startTime + " s, duration " + durationTime + " s).", "FishingCA");
		}
	}

	override int Execute(ActionData action_data) {
		int result = super.Execute(action_data);
		if (m_GebBubblesShown || !g_Game.IsServer() || !action_data || !action_data.m_Target)
			return result;
		if (m_SignalStartTime == NO_SIGNAL || m_SignalDuration == NO_SIGNAL)
			return result;
		if (m_TimeElpased >= m_SignalStartTime - GEB_BUBBLES_LEAD_SECS && m_TimeElpased < m_SignalStartTime) {
			m_GebBubblesShown = true;
			GebFishingFx.Play(action_data.m_Target.GetCursorHitPos(), ParticleList.GEB_BUBBLES_BITE, 3);
		}
		return result;
	}
}
