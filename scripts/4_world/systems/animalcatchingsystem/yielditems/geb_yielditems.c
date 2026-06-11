/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class GebYieldFishBase extends FishYieldItemBase {
	// Per-species weather multipliers cached at registration time, mirroring
	// how m_QualityBase / m_EnviroMask / m_MethodMask are already cached.
	// Default 1.0 = no effect, used as fallback for yields that don't pass
	// multipliers to SetupYield.
	protected float m_RainMultiplier = 1.0;
	protected float m_StormMultiplier = 1.0;
	protected float m_DawnMultiplier = 1.0;
	protected float m_DayMultiplier = 1.0;
	protected float m_DuskMultiplier = 1.0;
	protected float m_NightMultiplier = 1.0;
	// CatchProbability cached so the catching context can weight bite-speed
	// aggregation by per-fish abundance without hitting the config map again.
	protected int m_CatchProbability = 0;
	// 24-hour bite-speed array, 0=12AM ... 23=11PM, range 0.0-1.0. 1.0 means
	// vanilla baseline. Null until SetupYield seeds it; GetBiteSpeedForHour
	// falls back to 1.0 when the array is missing or malformed.
	protected ref TFloatArray m_BiteSpeed;
	// Water-temperature preference fields, all in degrees Celsius. m_TempMin
	// equal to m_TempMax (default 0/0) acts as a sentinel meaning "temperature
	// is disabled for this fish" so the catching context returns 1.0 multiplier
	// for any yield that wasn't initialized via SetTemperature.
	protected float m_TempOptimal = 0.0;
	protected float m_TempMin = 0.0;
	protected float m_TempMax = 0.0;

	void SetupYield(string typeName, int envMask, int methodMask, float rainMul = 1.0, float stormMul = 1.0, float nightMul = 1.0, float dawnMul = 1.0, float dayMul = 1.0, float duskMul = 1.0, int catchProb = 0, TFloatArray biteSpeed = null) {
		super.Init();
		// Defensive: if GeneralSettings isn't populated yet (mod startup race
		// with the JSON load, or an admin who somehow wiped the section out
		// of an existing JSON), fall back to vanilla DayZ's QUALITY_FISH_BASE
		// (0.35). Without the guard, an unpopulated config crashes every fish
		// registration and breaks the entire fishing system.
		if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.GeneralSettings)
			m_QualityBase = m_gebsConfig.General.GeneralSettings.FishQuality;
		else
			m_QualityBase = 0.35;
		m_Type = typeName;
		m_EnviroMask = envMask;
		m_MethodMask = methodMask;
		m_RainMultiplier = rainMul;
		m_StormMultiplier = stormMul;
		m_NightMultiplier = nightMul;
		m_DawnMultiplier = dawnMul;
		m_DayMultiplier = dayMul;
		m_DuskMultiplier = duskMul;
		m_CatchProbability = catchProb;
		m_BiteSpeed = biteSpeed;
	}

	// Separate from SetupYield to avoid pushing the parameter count past
	// Enforce's "Formula too complex" threshold (we already hit that at 11
	// args). Call this in each yield's Init() right after SetupYield to
	// register water-temperature preferences.
	void SetTemperature(float optimal, float minTemp, float maxTemp) {
		m_TempOptimal = optimal;
		m_TempMin = minTemp;
		m_TempMax = maxTemp;
	}

	// Exposes the fish classname (m_Type) so the catching context can read it
	// without depending on m_Type's access modifier on the vanilla parent.
	string GetSpeciesClassname() {
		return m_Type;
	}

	// Per-species weather multipliers. Catching context applies these on top of
	// the global rain/storm/dawn/day/dusk/night multipliers when biasing yield selection.
	float GetRainMultiplier()  { return m_RainMultiplier; }
	float GetStormMultiplier() { return m_StormMultiplier; }
	float GetDawnMultiplier()  { return m_DawnMultiplier; }
	float GetDayMultiplier()   { return m_DayMultiplier; }
	float GetDuskMultiplier()  { return m_DuskMultiplier; }
	float GetNightMultiplier() { return m_NightMultiplier; }

	// Water-temperature preferences in degrees Celsius. Catching context
	// reads these to apply the temperature curve multiplier.
	float GetTempOptimal() { return m_TempOptimal; }
	float GetTempMin()     { return m_TempMin; }
	float GetTempMax()     { return m_TempMax; }

	int GetCatchProbability() { return m_CatchProbability; }

	// Returns the bite-speed multiplier for the given hour (0-23). Falls back to
	// 1.0 (vanilla baseline) when the array is null, the wrong size, or the
	// hour is out of range -- so a missing / malformed JSON entry never freezes
	// the catch cycle.
	float GetBiteSpeedForHour(int hour) {
		if (!m_BiteSpeed || m_BiteSpeed.Count() != 24)
			return 1.0;
		if (hour < 0 || hour > 23)
			return 1.0;
		return m_BiteSpeed[hour];
	}
};
