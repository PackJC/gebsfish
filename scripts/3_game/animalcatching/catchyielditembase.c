modded class YieldItemBase {

    void YieldItemBase(int baseWeight){
		m_BaseWeight = baseWeight;
		Init();
	}

    override void Init(){
        GetGebSettingsConfig();
        // Print("[gebsfish] [DEBUG]");
        // Print(m_gebsConfig.Carp.CatchTimes);
        // Print("[gebsfish] [DEBUG]");
    }
}