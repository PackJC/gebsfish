modded class YieldItemBase {
    //Added so we can be compatible with other mods -Tree helped with this
    super.Init(); 
    void YieldItemBase(int baseWeight){
		m_BaseWeight = baseWeight;
		Init();
	}

    override void Init(){
        GetGebSettingsConfig();
    }

    int GebGetCatchProbability() {
        return m_BaseWeight;
    }
}