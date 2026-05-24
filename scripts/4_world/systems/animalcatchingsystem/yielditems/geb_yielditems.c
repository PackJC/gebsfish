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
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
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

// ===== FRESHWATER FISH =====
class geb_YieldCarp : GebYieldFishBase {
	override void Init() {
		CarpConf c = m_gebsConfig.Carp;
		SetupYield("Carp", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBitterlings : GebYieldFishBase {
	override void Init() {
		BitterlingsConf c = m_gebsConfig.Bitterlings;
		SetupYield("Bitterlings", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSteelheadTrout : GebYieldFishBase {
	override void Init() {
		SteelheadTroutConf c = m_gebsConfig.SteelheadTrout;
		SetupYield("SteelheadTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldCherrySalmon : GebYieldFishBase {
	override void Init() {
		CherrySalmonConf c = m_gebsConfig.CherrySalmon;
		SetupYield("geb_CherrySalmon", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldChinookSalmon : GebYieldFishBase {
    override void Init() {
		ChinookSalmonConf c = m_gebsConfig.ChinookSalmon;
		SetupYield("geb_ChinookSalmon", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSockEyeSalmon : GebYieldFishBase {
    override void Init() {
		SockEyeSalmonConf c = m_gebsConfig.SockEyeSalmon;
		SetupYield("geb_SockEyeSalmon", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldLakeSturgeon : GebYieldFishBase {
    override void Init() {
		LakeSturgeonConf c = m_gebsConfig.LakeSturgeon;
		SetupYield("geb_LakeSturgeon", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldNorthernSnakeHead : GebYieldFishBase {
    override void Init() {
		NorthernSnakeHeadConf c = m_gebsConfig.NorthernSnakeHead;
		SetupYield("geb_NorthernSnakeHead", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldNorthernPike : GebYieldFishBase {
    override void Init() {
		NorthernPikeConf c = m_gebsConfig.NorthernPike;
		SetupYield("geb_NorthernPike", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldMuskellunge : GebYieldFishBase {
    override void Init() {
		MuskellungeConf c = m_gebsConfig.Muskellunge;
		SetupYield("geb_Muskellunge", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldTigerMuskellunge : GebYieldFishBase {
    override void Init() {
		TigerMuskellungeConf c = m_gebsConfig.TigerMuskellunge;
		SetupYield("geb_TigerMuskellunge", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSpottedMuskellunge : GebYieldFishBase {
    override void Init() {
		SpottedMuskellungeConf c = m_gebsConfig.SpottedMuskellunge;
		SetupYield("geb_SpottedMuskellunge", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBarredMuskellunge : GebYieldFishBase {
    override void Init() {
		BarredMuskellungeConf c = m_gebsConfig.BarredMuskellunge;
		SetupYield("geb_BarredMuskellunge", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAlligatorGar : GebYieldFishBase {
    override void Init() {
		AlligatorGarConf c = m_gebsConfig.AlligatorGar;
		SetupYield("geb_AlligatorGar", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldLargeMouthBass : GebYieldFishBase {
    override void Init() {
		LargeMouthBassConf c = m_gebsConfig.LargeMouthBass;
		SetupYield("geb_LargeMouthBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSmallMouthBass : GebYieldFishBase {
    override void Init() {
		SmallMouthBassConf c = m_gebsConfig.SmallMouthBass;
		SetupYield("geb_SmallMouthBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldWallEye : GebYieldFishBase {
    override void Init() {
		WallEyeConf c = m_gebsConfig.WallEye;
		SetupYield("geb_WallEye", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSunFish : GebYieldFishBase {
    override void Init() {
		SunFishConf c = m_gebsConfig.SunFish;
		SetupYield("geb_SunFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldWhiteBass : GebYieldFishBase {
    override void Init() {
		WhiteBassConf c = m_gebsConfig.WhiteBass;
		SetupYield("geb_WhiteBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBlackBass : GebYieldFishBase {
    override void Init() {
		BlackBassConf c = m_gebsConfig.BlackBass;
		SetupYield("geb_BlackBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldNeoshoBass : GebYieldFishBase {
    override void Init() {
		NeoshoBassConf c = m_gebsConfig.NeoshoBass;
		SetupYield("geb_NeoshoBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldStripedBass : GebYieldFishBase {
    override void Init() {
		StripedBassConf c = m_gebsConfig.StripedBass;
		SetupYield("geb_StripedBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldRainbowTrout : GebYieldFishBase {
    override void Init() {
		RainbowTroutConf c = m_gebsConfig.RainbowTrout;
		SetupYield("geb_RainbowTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBrownTrout : GebYieldFishBase {
    override void Init() {
		BrownTroutConf c = m_gebsConfig.BrownTrout;
		SetupYield("geb_BrownTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBrookTrout : GebYieldFishBase {
    override void Init() {
		BrookTroutConf c = m_gebsConfig.BrookTrout;
		SetupYield("geb_BrookTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldLakeTrout : GebYieldFishBase {
    override void Init() {
		LakeTroutConf c = m_gebsConfig.LakeTrout;
		SetupYield("geb_LakeTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldCutThroatTrout : GebYieldFishBase {
    override void Init() {
		CutThroatTroutConf c = m_gebsConfig.CutThroatTrout;
		SetupYield("geb_CutThroatTrout", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldYellowPerch : GebYieldFishBase {
    override void Init() {
		YellowPerchConf c = m_gebsConfig.YellowPerch;
		SetupYield("geb_YellowPerch", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldFlatHeadCatFish : GebYieldFishBase {
    override void Init() {
		FlatHeadCatFishConf c = m_gebsConfig.FlatHeadCatFish;
		SetupYield("geb_FlatHeadCatFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldFatHeadMinnow : GebYieldFishBase {
    override void Init() {
		FatHeadMinnowConf c = m_gebsConfig.FatHeadMinnow;
		SetupYield("geb_FatHeadMinnow", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAmericanBullFrog : GebYieldFishBase {
    override void Init() {
		AmericanBullFrogConf c = m_gebsConfig.AmericanBullFrog;
		SetupYield("geb_AmericanBullFrog", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldRedSalamander : GebYieldFishBase {
    override void Init() {
		RedSalamanderConf c = m_gebsConfig.RedSalamander;
		SetupYield("geb_RedSalamander", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBlueGill : GebYieldFishBase {
    override void Init() {
		BlueGillConf c = m_gebsConfig.BlueGill;
		SetupYield("geb_BlueGill", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSauger : GebYieldFishBase {
    override void Init() {
		SaugerConf c = m_gebsConfig.Sauger;
		SetupYield("geb_Sauger", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBowFin : GebYieldFishBase {
    override void Init() {
		BowFinConf c = m_gebsConfig.BowFin;
		SetupYield("geb_BowFin", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSlimySculpin : GebYieldFishBase {
    override void Init() {
		SlimySculpinConf c = m_gebsConfig.SlimySculpin;
		SetupYield("geb_SlimySculpin", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}


// ===== FRESHWATER CRUSTACEAN =====
class geb_YieldSignalCrayFish : GebYieldFishBase {
    override void Init() {
		SignalCrayFishConf c = m_gebsConfig.SignalCrayFish;
		SetupYield("geb_SignalCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldEuropeanCrayFish : GebYieldFishBase {
    override void Init() {
		EuropeanCrayFishConf c = m_gebsConfig.EuropeanCrayFish;
		SetupYield("geb_EuropeanCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}
class geb_YieldFloridaCrayFish : GebYieldFishBase {
    override void Init() {
		FloridaCrayFishConf c = m_gebsConfig.FloridaCrayFish;
		SetupYield("geb_FloridaCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}
class geb_YieldCaveCrayFish : GebYieldFishBase {
    override void Init() {
		CaveCrayFishConf c = m_gebsConfig.CaveCrayFish;
		SetupYield("geb_CaveCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}
class geb_YieldMonongahelaCrayFish : GebYieldFishBase {
    override void Init() {
		MonongahelaCrayFishConf c = m_gebsConfig.MonongahelaCrayFish;
		SetupYield("geb_MonongahelaCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}
class geb_YieldRustyCrayFish : GebYieldFishBase {
    override void Init() {
		RustyCrayFishConf c = m_gebsConfig.RustyCrayFish;
		SetupYield("geb_RustyCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}
class geb_YieldRedSwampCrayFish : GebYieldFishBase {
    override void Init() {
		RedSwampCrayFishConf c = m_gebsConfig.RedSwampCrayFish;
		SetupYield("geb_RedSwampCrayFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}


// ===== SALTWATER FISH =====
class geb_YieldMackerel : GebYieldFishBase {
    override void Init() {
		MackerelConf c = m_gebsConfig.Mackerel;
		SetupYield("Mackerel", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSardines : GebYieldFishBase {
    override void Init() {
		SardinesConf c = m_gebsConfig.Sardines;
		SetupYield("Sardines", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldWalleyePollock : GebYieldFishBase {
    override void Init() {
		WalleyePollockConf c = m_gebsConfig.WalleyePollock;
		SetupYield("WalleyePollock", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldMahiMahi : GebYieldFishBase {
    override void Init() {
		MahiMahiConf c = m_gebsConfig.MahiMahi;
		SetupYield("geb_MahiMahi", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAtlanticSailFish : GebYieldFishBase {
    override void Init() {
		AtlanticSailFishConf c = m_gebsConfig.AtlanticSailFish;
		SetupYield("geb_AtlanticSailFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAngelFish : GebYieldFishBase {
    override void Init() {
		AngelFishConf c = m_gebsConfig.AngelFish;
		SetupYield("geb_AngelFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAsianSeaBass : GebYieldFishBase {
    override void Init() {
		AsianSeaBassConf c = m_gebsConfig.AsianSeaBass;
		SetupYield("geb_AsianSeaBass", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAtlanticBlueMarlin : GebYieldFishBase {
    override void Init() {
		AtlanticBlueMarlinConf c = m_gebsConfig.AtlanticBlueMarlin;
		SetupYield("geb_AtlanticBlueMarlin", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBonita : GebYieldFishBase {
    override void Init() {
		BonitaConf c = m_gebsConfig.Bonita;
		SetupYield("geb_Bonita", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldFlatHeadMullet : GebYieldFishBase {
    override void Init() {
		FlatHeadMulletConf c = m_gebsConfig.FlatHeadMullet;
		SetupYield("geb_FlatHeadMullet", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldRedHeadCichlid : GebYieldFishBase {
    override void Init() {
		RedHeadCichlidConf c = m_gebsConfig.RedHeadCichlid;
		SetupYield("geb_RedHeadCichlid", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldRoughNeckRock : GebYieldFishBase {
    override void Init() {
		RoughNeckRockConf c = m_gebsConfig.RoughNeckRock;
		SetupYield("geb_RoughNeckRock", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBlueTang : GebYieldFishBase {
    override void Init() {
		BlueTangConf c = m_gebsConfig.BlueTang;
		SetupYield("geb_BlueTang", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldLargeHeadHairTailFish : GebYieldFishBase {
    override void Init() {
		LargeHeadHairTailFishConf c = m_gebsConfig.LargeHeadHairTailFish;
		SetupYield("geb_LargeHeadHairTailFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldHumpHeadWrasse : GebYieldFishBase {
    override void Init() {
		HumpHeadWrasseConf c = m_gebsConfig.HumpHeadWrasse;
		SetupYield("geb_HumpHeadWrasse", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSiameseTigerFish : GebYieldFishBase {
    override void Init() {
		SiameseTigerFishConf c = m_gebsConfig.SiameseTigerFish;
		SetupYield("geb_SiameseTigerFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldLeopardShark : GebYieldFishBase {
    override void Init() {
		LeopardSharkConf c = m_gebsConfig.LeopardShark;
		SetupYield("geb_LeopardShark", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldHammerHeadShark : GebYieldFishBase {
    override void Init() {
		HammerHeadSharkConf c = m_gebsConfig.HammerHeadShark;
		SetupYield("geb_HammerHeadShark", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldPacificCod : GebYieldFishBase {
    override void Init() {
		PacificCodConf c = m_gebsConfig.PacificCod;
		SetupYield("geb_PacificCod", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldGreatWhiteShark : GebYieldFishBase {
    override void Init() {
		GreatWhiteSharkConf c = m_gebsConfig.GreatWhiteShark;
		SetupYield("geb_GreatWhiteShark", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAngelShark : GebYieldFishBase {
    override void Init() {
		AngelSharkConf c = m_gebsConfig.AngelShark;
		SetupYield("geb_AngelShark", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldYellowFinTuna : GebYieldFishBase {
    override void Init() {
		YellowFinTunaConf c = m_gebsConfig.YellowFinTuna;
		SetupYield("geb_YellowFinTuna", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldYellowSnapper : GebYieldFishBase {
    override void Init() {
		YellowSnapperConf c = m_gebsConfig.YellowSnapper;
		SetupYield("geb_YellowSnapper", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldWhiteGrunt : GebYieldFishBase {
    override void Init() {
		WhiteGruntConf c = m_gebsConfig.WhiteGrunt;
		SetupYield("geb_WhiteGrunt", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSouthernFlounder : GebYieldFishBase {
    override void Init() {
		SouthernFlounderConf c = m_gebsConfig.SouthernFlounder;
		SetupYield("geb_SouthernFlounder", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSeverum : GebYieldFishBase {
    override void Init() {
		SeverumConf c = m_gebsConfig.Severum;
		SetupYield("geb_Severum", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

// ===== SALTWATER CRUSTACEAN / MARINE INVERTEBRATES =====
class geb_YieldShrimp : GebYieldFishBase {
    override void Init() {
		ShrimpConf c = m_gebsConfig.Shrimp;
		SetupYield("Shrimp", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBloodClam : GebYieldFishBase {
    override void Init() {
		BloodClamConf c = m_gebsConfig.BloodClam;
		SetupYield("geb_BloodClam", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldMussel : GebYieldFishBase {
    override void Init() {
		MusselConf c = m_gebsConfig.Mussel;
		SetupYield("geb_Mussel", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBlackDevilSnail : GebYieldFishBase {
    override void Init() {
		BlackDevilSnailConf c = m_gebsConfig.BlackDevilSnail;
		SetupYield("geb_BlackDevilSnail", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldStarFish : GebYieldFishBase {
    override void Init() {
		StarFishConf c = m_gebsConfig.StarFish;
		SetupYield("geb_StarFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldKingCrab : GebYieldFishBase {
    override void Init() {
		KingCrabConf c = m_gebsConfig.KingCrab;
		SetupYield("geb_KingCrab", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldSnowCrab : GebYieldFishBase {
    override void Init() {
		SnowCrabConf c = m_gebsConfig.SnowCrab;
		SetupYield("geb_SnowCrab", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldBlueJellyFish : GebYieldFishBase {
    override void Init() {
		BlueJellyFishConf c = m_gebsConfig.BlueJellyFish;
		SetupYield("geb_BlueJellyFish", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldAmericanLobster : GebYieldFishBase {
    override void Init() {
		AmericanLobsterConf c = m_gebsConfig.AmericanLobster;
		SetupYield("geb_AmericanLobster", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}

class geb_YieldEuropeanLobster : GebYieldFishBase {
    override void Init() {
		EuropeanLobsterConf c = m_gebsConfig.EuropeanLobster;
		SetupYield("geb_EuropeanLobster", c.Environment, c.CatchMethod, c.RainMultiplier, c.StormMultiplier, c.NightMultiplier, c.DawnMultiplier, c.DayMultiplier, c.DuskMultiplier, c.CatchProbability, c.BiteSpeed);
		SetTemperature(c.TempOptimal, c.TempMin, c.TempMax);
	}
}