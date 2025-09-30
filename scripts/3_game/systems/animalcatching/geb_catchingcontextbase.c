modded class CatchingContextBase {
    //helper function for cftools logging; outputs the display name of the catch.
    string GebGetCatchingResult() { 
        string geboutput = m_Result.GebGetFishingResultName();
        return geboutput;
    }

    override EntityAI SpawnAndSetupCatch(out int yItemIdx, vector v = vector.Zero)
	{
		if (!m_IsValid)
		{
			GebsfishLogger.Error("Could not spawn catch for item: " + m_MainItem,"SpawnAndSetupCatch");
			return null;
		}
		m_Result.UpdateCatchQuality(this);
		
		return m_Result.SpawnAndSetup(yItemIdx,v);
	}
}