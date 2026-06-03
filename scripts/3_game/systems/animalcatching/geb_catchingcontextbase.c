modded class CatchingContextBase {
    override EntityAI SpawnAndSetupCatch(out int yItemIdx, vector v = vector.Zero) {
		if (!m_IsValid) {
			// Bug reports against "I caught nothing" used to land with a single
			// "Could not spawn catch for item: <ref>" line that didn't say which
			// rod was used or what fish was about to spawn. Surface enough
			// context here that the report is actionable on its own.
			//
			// Walks the rod -> hook -> bait attachment chain via the public
			// FindAttachmentBySlotName API rather than touching the rod
			// subclass's protected m_Hook / m_Bait. Slot names match vanilla's
			// itemInfo[] for fishing rods. For non-rod actions (net, dig) the
			// FindAttachmentBySlotName calls return null and those entries
			// just log as "<none>", which is exactly right for those paths.
			//
			// Player position is not logged here because CatchingContextBase
			// doesn't expose a player ref. The triggering action's own logs
			// already record the player at action start, so cross-referencing
			// by timestamp covers that.
			string mainType = "<null>";
			string hookType = "<none>";
			string baitType = "<none>";
			string yieldName = "<none>";

			if (m_MainItem) {
				mainType = m_MainItem.GetType();
				EntityAI attachedHook = m_MainItem.FindAttachmentBySlotName("Hook");
				if (attachedHook) {
					hookType = attachedHook.GetType();
					EntityAI attachedBait = attachedHook.FindAttachmentBySlotName("Bait");
					if (attachedBait)
						baitType = attachedBait.GetType();
				}
			}

			if (m_Result && m_Result.GebGetFishingResultName() != "")
				yieldName = m_Result.GebGetFishingResultName();

			GebsfishLogger.Error("Could not spawn catch: mainItem=" + mainType + " hook=" + hookType + " bait=" + baitType + " yield=" + yieldName,"SpawnAndSetupCatch");
			return null;
		}
		m_Result.UpdateCatchQuality(this);

		return m_Result.SpawnAndSetup(yItemIdx,v);
	}
}