modded class YieldItemBase {

    void YieldItemBase(int baseWeight){
		m_BaseWeight = baseWeight;
		Init();
	}

    override void Init(){
        super.Init(); 
        GetGebSettingsConfig();
    }

    int GebGetCatchProbability() {
        return m_BaseWeight;
    }
}