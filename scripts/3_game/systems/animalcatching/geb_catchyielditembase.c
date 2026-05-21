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

modded class YieldItemJunk {
	protected int m_GebMinHealthLevel = 3;
	protected int m_GebMaxHealthLevel = 3;

	void GebSetHealthLevelRange(int minHealthLevel, int maxHealthLevel) {
		m_GebMinHealthLevel = Math.Clamp(minHealthLevel, 0, 4);
		m_GebMaxHealthLevel = Math.Clamp(maxHealthLevel, 0, 4);

		if (m_GebMaxHealthLevel < m_GebMinHealthLevel)
			m_GebMaxHealthLevel = m_GebMinHealthLevel;
	}

	override EntityAI SpawnAndSetup(out int yItemIdx, vector v = vector.Zero) {
		EntityAI item = super.SpawnAndSetup(yItemIdx, v);
		if (!item)
			return item;

		int healthLevel = Math.RandomInt(m_GebMinHealthLevel, m_GebMaxHealthLevel + 1);
		item.SetHealth01("", "", GebGetHealth01FromLevel(healthLevel));
		return item;
	}

	protected float GebGetHealth01FromLevel(int healthLevel) {
		switch (healthLevel) {
			case 0:
				return 1.0;
			case 1:
				return 0.85;
			case 2:
				return 0.55;
			case 3:
				return 0.25;
			case 4:
				return 0.0;
		}

		return 0.25;
	}
}
