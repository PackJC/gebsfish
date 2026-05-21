modded class YieldItemBase {

    void YieldItemBase(int baseWeight) {
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

// YieldItemJunk and YieldItemJunkEmpty live in vanilla's 4_World scope
// (4_World/DayZ/Systems/AnimalCatchingSystem/YieldItems/YieldsFishingJunk.c),
// so any modded class for them has to live in 4_World too. See
// scripts/4_world/systems/animalcatchingsystem/yielditems/geb_yieldjunk.c.
