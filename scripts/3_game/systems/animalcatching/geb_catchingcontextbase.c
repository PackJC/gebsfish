modded class CatchingContextBase {
    override EntityAI SpawnAndSetupCatch(out int yItemIdx, vector v = vector.Zero) {
		if (!m_IsValid) {
			GebsfishLogger.Error("Could not spawn catch for item: " + m_MainItem,"SpawnAndSetupCatch");
			return null;
		}
		m_Result.UpdateCatchQuality(this);
		
		return m_Result.SpawnAndSetup(yItemIdx,v);
	}
}