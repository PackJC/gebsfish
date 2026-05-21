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
	protected float m_NightMultiplier = 1.0;

	void SetupYield(string typeName, int envMask, int methodMask, float rainMul = 1.0, float stormMul = 1.0, float nightMul = 1.0) {
		super.Init();
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = typeName;
		m_EnviroMask = envMask;
		m_MethodMask = methodMask;
		m_RainMultiplier = rainMul;
		m_StormMultiplier = stormMul;
		m_NightMultiplier = nightMul;
	}

	// Exposes the fish classname (m_Type) so the catching context can read it
	// without depending on m_Type's access modifier on the vanilla parent.
	string GetSpeciesClassname() {
		return m_Type;
	}

	// Per-species weather multipliers. Catching context applies these on top of
	// the global rain/storm/night multipliers when biasing yield selection.
	float GetRainMultiplier()  { return m_RainMultiplier; }
	float GetStormMultiplier() { return m_StormMultiplier; }
	float GetNightMultiplier() { return m_NightMultiplier; }
};

// ===== FRESHWATER FISH =====
class geb_YieldCarp : GebYieldFishBase {
	override void Init() {
		SetupYield("Carp", m_gebsConfig.Carp.Environment, m_gebsConfig.Carp.CatchMethod, m_gebsConfig.Carp.RainMultiplier, m_gebsConfig.Carp.StormMultiplier, m_gebsConfig.Carp.NightMultiplier);
	}
}

class geb_YieldBitterlings : GebYieldFishBase {
	override void Init() {
		SetupYield("Bitterlings", m_gebsConfig.Bitterlings.Environment, m_gebsConfig.Bitterlings.CatchMethod, m_gebsConfig.Bitterlings.RainMultiplier, m_gebsConfig.Bitterlings.StormMultiplier, m_gebsConfig.Bitterlings.NightMultiplier);
	}
}

class geb_YieldSteelheadTrout : GebYieldFishBase {
	override void Init() {
		SetupYield("SteelheadTrout", m_gebsConfig.SteelheadTrout.Environment, m_gebsConfig.SteelheadTrout.CatchMethod, m_gebsConfig.SteelheadTrout.RainMultiplier, m_gebsConfig.SteelheadTrout.StormMultiplier, m_gebsConfig.SteelheadTrout.NightMultiplier);
	}
}

class geb_YieldCherrySalmon : GebYieldFishBase {
	override void Init() {
		SetupYield("geb_CherrySalmon", m_gebsConfig.CherrySalmon.Environment, m_gebsConfig.CherrySalmon.CatchMethod, m_gebsConfig.CherrySalmon.RainMultiplier, m_gebsConfig.CherrySalmon.StormMultiplier, m_gebsConfig.CherrySalmon.NightMultiplier);
	}
}

class geb_YieldChinookSalmon : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_ChinookSalmon", m_gebsConfig.ChinookSalmon.Environment, m_gebsConfig.ChinookSalmon.CatchMethod, m_gebsConfig.ChinookSalmon.RainMultiplier, m_gebsConfig.ChinookSalmon.StormMultiplier, m_gebsConfig.ChinookSalmon.NightMultiplier);
	}
}

class geb_YieldSockEyeSalmon : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SockEyeSalmon", m_gebsConfig.SockEyeSalmon.Environment, m_gebsConfig.SockEyeSalmon.CatchMethod, m_gebsConfig.SockEyeSalmon.RainMultiplier, m_gebsConfig.SockEyeSalmon.StormMultiplier, m_gebsConfig.SockEyeSalmon.NightMultiplier);
	}
}

class geb_YieldLakeSturgeon : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_LakeSturgeon", m_gebsConfig.LakeSturgeon.Environment, m_gebsConfig.LakeSturgeon.CatchMethod, m_gebsConfig.LakeSturgeon.RainMultiplier, m_gebsConfig.LakeSturgeon.StormMultiplier, m_gebsConfig.LakeSturgeon.NightMultiplier);
	}
}

class geb_YieldNorthernSnakeHead : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_NorthernSnakeHead", m_gebsConfig.NorthernSnakeHead.Environment, m_gebsConfig.NorthernSnakeHead.CatchMethod, m_gebsConfig.NorthernSnakeHead.RainMultiplier, m_gebsConfig.NorthernSnakeHead.StormMultiplier, m_gebsConfig.NorthernSnakeHead.NightMultiplier);
	}
}

class geb_YieldNorthernPike : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_NorthernPike", m_gebsConfig.NorthernPike.Environment, m_gebsConfig.NorthernPike.CatchMethod, m_gebsConfig.NorthernPike.RainMultiplier, m_gebsConfig.NorthernPike.StormMultiplier, m_gebsConfig.NorthernPike.NightMultiplier);
	}
}

class geb_YieldMuskellunge : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_Muskellunge", m_gebsConfig.Muskellunge.Environment, m_gebsConfig.Muskellunge.CatchMethod, m_gebsConfig.Muskellunge.RainMultiplier, m_gebsConfig.Muskellunge.StormMultiplier, m_gebsConfig.Muskellunge.NightMultiplier);
	}
}

class geb_YieldTigerMuskellunge : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_TigerMuskellunge", m_gebsConfig.TigerMuskellunge.Environment, m_gebsConfig.TigerMuskellunge.CatchMethod, m_gebsConfig.TigerMuskellunge.RainMultiplier, m_gebsConfig.TigerMuskellunge.StormMultiplier, m_gebsConfig.TigerMuskellunge.NightMultiplier);
	}
}

class geb_YieldSpottedMuskellunge : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SpottedMuskellunge", m_gebsConfig.SpottedMuskellunge.Environment, m_gebsConfig.SpottedMuskellunge.CatchMethod, m_gebsConfig.SpottedMuskellunge.RainMultiplier, m_gebsConfig.SpottedMuskellunge.StormMultiplier, m_gebsConfig.SpottedMuskellunge.NightMultiplier);
	}
}

class geb_YieldBarredMuskellunge : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BarredMuskellunge", m_gebsConfig.BarredMuskellunge.Environment, m_gebsConfig.BarredMuskellunge.CatchMethod, m_gebsConfig.BarredMuskellunge.RainMultiplier, m_gebsConfig.BarredMuskellunge.StormMultiplier, m_gebsConfig.BarredMuskellunge.NightMultiplier);
	}
}

class geb_YieldAlligatorGar : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AlligatorGar", m_gebsConfig.AlligatorGar.Environment, m_gebsConfig.AlligatorGar.CatchMethod, m_gebsConfig.AlligatorGar.RainMultiplier, m_gebsConfig.AlligatorGar.StormMultiplier, m_gebsConfig.AlligatorGar.NightMultiplier);
	}
}

class geb_YieldLargeMouthBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_LargeMouthBass", m_gebsConfig.LargeMouthBass.Environment, m_gebsConfig.LargeMouthBass.CatchMethod, m_gebsConfig.LargeMouthBass.RainMultiplier, m_gebsConfig.LargeMouthBass.StormMultiplier, m_gebsConfig.LargeMouthBass.NightMultiplier);
	}
}

class geb_YieldSmallMouthBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SmallMouthBass", m_gebsConfig.SmallMouthBass.Environment, m_gebsConfig.SmallMouthBass.CatchMethod, m_gebsConfig.SmallMouthBass.RainMultiplier, m_gebsConfig.SmallMouthBass.StormMultiplier, m_gebsConfig.SmallMouthBass.NightMultiplier);
	}
}

class geb_YieldWallEye : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_WallEye", m_gebsConfig.WallEye.Environment, m_gebsConfig.WallEye.CatchMethod, m_gebsConfig.WallEye.RainMultiplier, m_gebsConfig.WallEye.StormMultiplier, m_gebsConfig.WallEye.NightMultiplier);
	}
}

class geb_YieldSunFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SunFish", m_gebsConfig.SunFish.Environment, m_gebsConfig.SunFish.CatchMethod, m_gebsConfig.SunFish.RainMultiplier, m_gebsConfig.SunFish.StormMultiplier, m_gebsConfig.SunFish.NightMultiplier);
	}
}

class geb_YieldWhiteBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_WhiteBass", m_gebsConfig.WhiteBass.Environment, m_gebsConfig.WhiteBass.CatchMethod, m_gebsConfig.WhiteBass.RainMultiplier, m_gebsConfig.WhiteBass.StormMultiplier, m_gebsConfig.WhiteBass.NightMultiplier);
	}
}

class geb_YieldBlackBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BlackBass", m_gebsConfig.BlackBass.Environment, m_gebsConfig.BlackBass.CatchMethod, m_gebsConfig.BlackBass.RainMultiplier, m_gebsConfig.BlackBass.StormMultiplier, m_gebsConfig.BlackBass.NightMultiplier);
	}
}

class geb_YieldNeoshoBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_NeoshoBass", m_gebsConfig.NeoshoBass.Environment, m_gebsConfig.NeoshoBass.CatchMethod, m_gebsConfig.NeoshoBass.RainMultiplier, m_gebsConfig.NeoshoBass.StormMultiplier, m_gebsConfig.NeoshoBass.NightMultiplier);
	}
}

class geb_YieldStripedBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_StripedBass", m_gebsConfig.StripedBass.Environment, m_gebsConfig.StripedBass.CatchMethod, m_gebsConfig.StripedBass.RainMultiplier, m_gebsConfig.StripedBass.StormMultiplier, m_gebsConfig.StripedBass.NightMultiplier);
	}
}

class geb_YieldRainbowTrout : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RainbowTrout", m_gebsConfig.RainbowTrout.Environment, m_gebsConfig.RainbowTrout.CatchMethod, m_gebsConfig.RainbowTrout.RainMultiplier, m_gebsConfig.RainbowTrout.StormMultiplier, m_gebsConfig.RainbowTrout.NightMultiplier);
	}
}

class geb_YieldBrownTrout : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BrownTrout", m_gebsConfig.BrownTrout.Environment, m_gebsConfig.BrownTrout.CatchMethod, m_gebsConfig.BrownTrout.RainMultiplier, m_gebsConfig.BrownTrout.StormMultiplier, m_gebsConfig.BrownTrout.NightMultiplier);
	}
}

class geb_YieldBrookTrout : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BrookTrout", m_gebsConfig.BrookTrout.Environment, m_gebsConfig.BrookTrout.CatchMethod, m_gebsConfig.BrookTrout.RainMultiplier, m_gebsConfig.BrookTrout.StormMultiplier, m_gebsConfig.BrookTrout.NightMultiplier);
	}
}

class geb_YieldLakeTrout : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_LakeTrout", m_gebsConfig.LakeTrout.Environment, m_gebsConfig.LakeTrout.CatchMethod, m_gebsConfig.LakeTrout.RainMultiplier, m_gebsConfig.LakeTrout.StormMultiplier, m_gebsConfig.LakeTrout.NightMultiplier);
	}
}

class geb_YieldCutThroatTrout : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_CutThroatTrout", m_gebsConfig.CutThroatTrout.Environment, m_gebsConfig.CutThroatTrout.CatchMethod, m_gebsConfig.CutThroatTrout.RainMultiplier, m_gebsConfig.CutThroatTrout.StormMultiplier, m_gebsConfig.CutThroatTrout.NightMultiplier);
	}
}

class geb_YieldYellowPerch : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_YellowPerch", m_gebsConfig.YellowPerch.Environment, m_gebsConfig.YellowPerch.CatchMethod, m_gebsConfig.YellowPerch.RainMultiplier, m_gebsConfig.YellowPerch.StormMultiplier, m_gebsConfig.YellowPerch.NightMultiplier);
	}
}

class geb_YieldFlatHeadCatFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_FlatHeadCatFish", m_gebsConfig.FlatHeadCatFish.Environment, m_gebsConfig.FlatHeadCatFish.CatchMethod, m_gebsConfig.FlatHeadCatFish.RainMultiplier, m_gebsConfig.FlatHeadCatFish.StormMultiplier, m_gebsConfig.FlatHeadCatFish.NightMultiplier);
	}
}

class geb_YieldFatHeadMinnow : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_FatHeadMinnow", m_gebsConfig.FatHeadMinnow.Environment, m_gebsConfig.FatHeadMinnow.CatchMethod, m_gebsConfig.FatHeadMinnow.RainMultiplier, m_gebsConfig.FatHeadMinnow.StormMultiplier, m_gebsConfig.FatHeadMinnow.NightMultiplier);
	}
}

class geb_YieldAmericanBullFrog : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AmericanBullFrog", m_gebsConfig.AmericanBullFrog.Environment, m_gebsConfig.AmericanBullFrog.CatchMethod, m_gebsConfig.AmericanBullFrog.RainMultiplier, m_gebsConfig.AmericanBullFrog.StormMultiplier, m_gebsConfig.AmericanBullFrog.NightMultiplier);
	}
}

class geb_YieldRedSalamander : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RedSalamander", m_gebsConfig.RedSalamander.Environment, m_gebsConfig.RedSalamander.CatchMethod, m_gebsConfig.RedSalamander.RainMultiplier, m_gebsConfig.RedSalamander.StormMultiplier, m_gebsConfig.RedSalamander.NightMultiplier);
	}
}

class geb_YieldBlueGill : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BlueGill", m_gebsConfig.BlueGill.Environment, m_gebsConfig.BlueGill.CatchMethod, m_gebsConfig.BlueGill.RainMultiplier, m_gebsConfig.BlueGill.StormMultiplier, m_gebsConfig.BlueGill.NightMultiplier);
	}
}

class geb_YieldSauger : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_Sauger", m_gebsConfig.Sauger.Environment, m_gebsConfig.Sauger.CatchMethod, m_gebsConfig.Sauger.RainMultiplier, m_gebsConfig.Sauger.StormMultiplier, m_gebsConfig.Sauger.NightMultiplier);
	}
}

class geb_YieldBowFin : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BowFin", m_gebsConfig.BowFin.Environment, m_gebsConfig.BowFin.CatchMethod, m_gebsConfig.BowFin.RainMultiplier, m_gebsConfig.BowFin.StormMultiplier, m_gebsConfig.BowFin.NightMultiplier);
	}
}

class geb_YieldSlimySculpin : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SlimySculpin", m_gebsConfig.SlimySculpin.Environment, m_gebsConfig.SlimySculpin.CatchMethod, m_gebsConfig.SlimySculpin.RainMultiplier, m_gebsConfig.SlimySculpin.StormMultiplier, m_gebsConfig.SlimySculpin.NightMultiplier);
	}
}


// ===== FRESHWATER CRUSTACEAN =====
class geb_YieldSignalCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SignalCrayFish", m_gebsConfig.SignalCrayFish.Environment, m_gebsConfig.SignalCrayFish.CatchMethod, m_gebsConfig.SignalCrayFish.RainMultiplier, m_gebsConfig.SignalCrayFish.StormMultiplier, m_gebsConfig.SignalCrayFish.NightMultiplier);
	}
}

class geb_YieldEuropeanCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_EuropeanCrayFish", m_gebsConfig.EuropeanCrayFish.Environment, m_gebsConfig.EuropeanCrayFish.CatchMethod, m_gebsConfig.EuropeanCrayFish.RainMultiplier, m_gebsConfig.EuropeanCrayFish.StormMultiplier, m_gebsConfig.EuropeanCrayFish.NightMultiplier);
	}
}
class geb_YieldFloridaCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_FloridaCrayFish", m_gebsConfig.FloridaCrayFish.Environment, m_gebsConfig.FloridaCrayFish.CatchMethod, m_gebsConfig.FloridaCrayFish.RainMultiplier, m_gebsConfig.FloridaCrayFish.StormMultiplier, m_gebsConfig.FloridaCrayFish.NightMultiplier);
	}
}
class geb_YieldCaveCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_CaveCrayFish", m_gebsConfig.CaveCrayFish.Environment, m_gebsConfig.CaveCrayFish.CatchMethod, m_gebsConfig.CaveCrayFish.RainMultiplier, m_gebsConfig.CaveCrayFish.StormMultiplier, m_gebsConfig.CaveCrayFish.NightMultiplier);
	}
}
class geb_YieldMonongahelaCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_MonongahelaCrayFish", m_gebsConfig.MonongahelaCrayFish.Environment, m_gebsConfig.MonongahelaCrayFish.CatchMethod, m_gebsConfig.MonongahelaCrayFish.RainMultiplier, m_gebsConfig.MonongahelaCrayFish.StormMultiplier, m_gebsConfig.MonongahelaCrayFish.NightMultiplier);
	}
}
class geb_YieldRustyCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RustyCrayFish", m_gebsConfig.RustyCrayFish.Environment, m_gebsConfig.RustyCrayFish.CatchMethod, m_gebsConfig.RustyCrayFish.RainMultiplier, m_gebsConfig.RustyCrayFish.StormMultiplier, m_gebsConfig.RustyCrayFish.NightMultiplier);
	}
}
class geb_YieldRedSwampCrayFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RedSwampCrayFish", m_gebsConfig.RedSwampCrayFish.Environment, m_gebsConfig.RedSwampCrayFish.CatchMethod, m_gebsConfig.RedSwampCrayFish.RainMultiplier, m_gebsConfig.RedSwampCrayFish.StormMultiplier, m_gebsConfig.RedSwampCrayFish.NightMultiplier);
	}
}


// ===== SALTWATER FISH =====
class geb_YieldMackerel : GebYieldFishBase {
    override void Init() {
		SetupYield("Mackerel", m_gebsConfig.Mackerel.Environment, m_gebsConfig.Mackerel.CatchMethod, m_gebsConfig.Mackerel.RainMultiplier, m_gebsConfig.Mackerel.StormMultiplier, m_gebsConfig.Mackerel.NightMultiplier);
	}
}

class geb_YieldSardines : GebYieldFishBase {
    override void Init() {
		SetupYield("Sardines", m_gebsConfig.Sardines.Environment, m_gebsConfig.Sardines.CatchMethod, m_gebsConfig.Sardines.RainMultiplier, m_gebsConfig.Sardines.StormMultiplier, m_gebsConfig.Sardines.NightMultiplier);
	}
}

class geb_YieldWalleyePollock : GebYieldFishBase {
    override void Init() {
		SetupYield("WalleyePollock", m_gebsConfig.WalleyePollock.Environment, m_gebsConfig.WalleyePollock.CatchMethod, m_gebsConfig.WalleyePollock.RainMultiplier, m_gebsConfig.WalleyePollock.StormMultiplier, m_gebsConfig.WalleyePollock.NightMultiplier);
	}
}

class geb_YieldMahiMahi : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_MahiMahi", m_gebsConfig.MahiMahi.Environment, m_gebsConfig.MahiMahi.CatchMethod, m_gebsConfig.MahiMahi.RainMultiplier, m_gebsConfig.MahiMahi.StormMultiplier, m_gebsConfig.MahiMahi.NightMultiplier);
	}
}

class geb_YieldAtlanticSailFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AtlanticSailFish", m_gebsConfig.AtlanticSailFish.Environment, m_gebsConfig.AtlanticSailFish.CatchMethod, m_gebsConfig.AtlanticSailFish.RainMultiplier, m_gebsConfig.AtlanticSailFish.StormMultiplier, m_gebsConfig.AtlanticSailFish.NightMultiplier);
	}
}

class geb_YieldAngelFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AngelFish", m_gebsConfig.AngelFish.Environment, m_gebsConfig.AngelFish.CatchMethod, m_gebsConfig.AngelFish.RainMultiplier, m_gebsConfig.AngelFish.StormMultiplier, m_gebsConfig.AngelFish.NightMultiplier);
	}
}

class geb_YieldAsianSeaBass : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AsianSeaBass", m_gebsConfig.AsianSeaBass.Environment, m_gebsConfig.AsianSeaBass.CatchMethod, m_gebsConfig.AsianSeaBass.RainMultiplier, m_gebsConfig.AsianSeaBass.StormMultiplier, m_gebsConfig.AsianSeaBass.NightMultiplier);
	}
}

class geb_YieldAtlanticBlueMarlin : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AtlanticBlueMarlin", m_gebsConfig.AtlanticBlueMarlin.Environment, m_gebsConfig.AtlanticBlueMarlin.CatchMethod, m_gebsConfig.AtlanticBlueMarlin.RainMultiplier, m_gebsConfig.AtlanticBlueMarlin.StormMultiplier, m_gebsConfig.AtlanticBlueMarlin.NightMultiplier);
	}
}

class geb_YieldBonita : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_Bonita", m_gebsConfig.Bonita.Environment, m_gebsConfig.Bonita.CatchMethod, m_gebsConfig.Bonita.RainMultiplier, m_gebsConfig.Bonita.StormMultiplier, m_gebsConfig.Bonita.NightMultiplier);
	}
}

class geb_YieldFlatHeadMullet : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_FlatHeadMullet", m_gebsConfig.FlatHeadMullet.Environment, m_gebsConfig.FlatHeadMullet.CatchMethod, m_gebsConfig.FlatHeadMullet.RainMultiplier, m_gebsConfig.FlatHeadMullet.StormMultiplier, m_gebsConfig.FlatHeadMullet.NightMultiplier);
	}
}

class geb_YieldRedHeadCichlid : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RedHeadCichlid", m_gebsConfig.RedHeadCichlid.Environment, m_gebsConfig.RedHeadCichlid.CatchMethod, m_gebsConfig.RedHeadCichlid.RainMultiplier, m_gebsConfig.RedHeadCichlid.StormMultiplier, m_gebsConfig.RedHeadCichlid.NightMultiplier);
	}
}

class geb_YieldRoughNeckRock : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_RoughNeckRock", m_gebsConfig.RoughNeckRock.Environment, m_gebsConfig.RoughNeckRock.CatchMethod, m_gebsConfig.RoughNeckRock.RainMultiplier, m_gebsConfig.RoughNeckRock.StormMultiplier, m_gebsConfig.RoughNeckRock.NightMultiplier);
	}
}

class geb_YieldBlueTang : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BlueTang", m_gebsConfig.BlueTang.Environment, m_gebsConfig.BlueTang.CatchMethod, m_gebsConfig.BlueTang.RainMultiplier, m_gebsConfig.BlueTang.StormMultiplier, m_gebsConfig.BlueTang.NightMultiplier);
	}
}

class geb_YieldLargeHeadHairTailFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_LargeHeadHairTailFish", m_gebsConfig.LargeHeadHairTailFish.Environment, m_gebsConfig.LargeHeadHairTailFish.CatchMethod, m_gebsConfig.LargeHeadHairTailFish.RainMultiplier, m_gebsConfig.LargeHeadHairTailFish.StormMultiplier, m_gebsConfig.LargeHeadHairTailFish.NightMultiplier);
	}
}

class geb_YieldHumpHeadWrasse : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_HumpHeadWrasse", m_gebsConfig.HumpHeadWrasse.Environment, m_gebsConfig.HumpHeadWrasse.CatchMethod, m_gebsConfig.HumpHeadWrasse.RainMultiplier, m_gebsConfig.HumpHeadWrasse.StormMultiplier, m_gebsConfig.HumpHeadWrasse.NightMultiplier);
	}
}

class geb_YieldSiameseTigerFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SiameseTigerFish", m_gebsConfig.SiameseTigerFish.Environment, m_gebsConfig.SiameseTigerFish.CatchMethod, m_gebsConfig.SiameseTigerFish.RainMultiplier, m_gebsConfig.SiameseTigerFish.StormMultiplier, m_gebsConfig.SiameseTigerFish.NightMultiplier);
	}
}

class geb_YieldLeopardShark : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_LeopardShark", m_gebsConfig.LeopardShark.Environment, m_gebsConfig.LeopardShark.CatchMethod, m_gebsConfig.LeopardShark.RainMultiplier, m_gebsConfig.LeopardShark.StormMultiplier, m_gebsConfig.LeopardShark.NightMultiplier);
	}
}

class geb_YieldHammerHeadShark : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_HammerHeadShark", m_gebsConfig.HammerHeadShark.Environment, m_gebsConfig.HammerHeadShark.CatchMethod, m_gebsConfig.HammerHeadShark.RainMultiplier, m_gebsConfig.HammerHeadShark.StormMultiplier, m_gebsConfig.HammerHeadShark.NightMultiplier);
	}
}

class geb_YieldPacificCod : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_PacificCod", m_gebsConfig.PacificCod.Environment, m_gebsConfig.PacificCod.CatchMethod, m_gebsConfig.PacificCod.RainMultiplier, m_gebsConfig.PacificCod.StormMultiplier, m_gebsConfig.PacificCod.NightMultiplier);
	}
}

class geb_YieldGreatWhiteShark : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_GreatWhiteShark", m_gebsConfig.GreatWhiteShark.Environment, m_gebsConfig.GreatWhiteShark.CatchMethod, m_gebsConfig.GreatWhiteShark.RainMultiplier, m_gebsConfig.GreatWhiteShark.StormMultiplier, m_gebsConfig.GreatWhiteShark.NightMultiplier);
	}
}

class geb_YieldAngelShark : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AngelShark", m_gebsConfig.AngelShark.Environment, m_gebsConfig.AngelShark.CatchMethod, m_gebsConfig.AngelShark.RainMultiplier, m_gebsConfig.AngelShark.StormMultiplier, m_gebsConfig.AngelShark.NightMultiplier);
	}
}

class geb_YieldYellowFinTuna : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_YellowFinTuna", m_gebsConfig.YellowFinTuna.Environment, m_gebsConfig.YellowFinTuna.CatchMethod, m_gebsConfig.YellowFinTuna.RainMultiplier, m_gebsConfig.YellowFinTuna.StormMultiplier, m_gebsConfig.YellowFinTuna.NightMultiplier);
	}
}

class geb_YieldYellowSnapper : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_YellowSnapper", m_gebsConfig.YellowSnapper.Environment, m_gebsConfig.YellowSnapper.CatchMethod, m_gebsConfig.YellowSnapper.RainMultiplier, m_gebsConfig.YellowSnapper.StormMultiplier, m_gebsConfig.YellowSnapper.NightMultiplier);
	}
}

class geb_YieldWhiteGrunt : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_WhiteGrunt", m_gebsConfig.WhiteGrunt.Environment, m_gebsConfig.WhiteGrunt.CatchMethod, m_gebsConfig.WhiteGrunt.RainMultiplier, m_gebsConfig.WhiteGrunt.StormMultiplier, m_gebsConfig.WhiteGrunt.NightMultiplier);
	}
}

class geb_YieldSouthernFlounder : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SouthernFlounder", m_gebsConfig.SouthernFlounder.Environment, m_gebsConfig.SouthernFlounder.CatchMethod, m_gebsConfig.SouthernFlounder.RainMultiplier, m_gebsConfig.SouthernFlounder.StormMultiplier, m_gebsConfig.SouthernFlounder.NightMultiplier);
	}
}

class geb_YieldSeverum : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_Severum", m_gebsConfig.Severum.Environment, m_gebsConfig.Severum.CatchMethod, m_gebsConfig.Severum.RainMultiplier, m_gebsConfig.Severum.StormMultiplier, m_gebsConfig.Severum.NightMultiplier);
	}
}

// ===== SALTWATER CRUSTACEAN / MARINE INVERTEBRATES =====
class geb_YieldShrimp : GebYieldFishBase {
    override void Init() {
		SetupYield("Shrimp", m_gebsConfig.Shrimp.Environment, m_gebsConfig.Shrimp.CatchMethod, m_gebsConfig.Shrimp.RainMultiplier, m_gebsConfig.Shrimp.StormMultiplier, m_gebsConfig.Shrimp.NightMultiplier);
	}
}

class geb_YieldBloodClam : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BloodClam", m_gebsConfig.BloodClam.Environment, m_gebsConfig.BloodClam.CatchMethod, m_gebsConfig.BloodClam.RainMultiplier, m_gebsConfig.BloodClam.StormMultiplier, m_gebsConfig.BloodClam.NightMultiplier);
	}
}

class geb_YieldMussel : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_Mussel", m_gebsConfig.Mussel.Environment, m_gebsConfig.Mussel.CatchMethod, m_gebsConfig.Mussel.RainMultiplier, m_gebsConfig.Mussel.StormMultiplier, m_gebsConfig.Mussel.NightMultiplier);
	}
}

class geb_YieldBlackDevilSnail : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BlackDevilSnail", m_gebsConfig.BlackDevilSnail.Environment, m_gebsConfig.BlackDevilSnail.CatchMethod, m_gebsConfig.BlackDevilSnail.RainMultiplier, m_gebsConfig.BlackDevilSnail.StormMultiplier, m_gebsConfig.BlackDevilSnail.NightMultiplier);
	}
}

class geb_YieldStarFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_StarFish", m_gebsConfig.StarFish.Environment, m_gebsConfig.StarFish.CatchMethod, m_gebsConfig.StarFish.RainMultiplier, m_gebsConfig.StarFish.StormMultiplier, m_gebsConfig.StarFish.NightMultiplier);
	}
}

class geb_YieldKingCrab : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_KingCrab", m_gebsConfig.KingCrab.Environment, m_gebsConfig.KingCrab.CatchMethod, m_gebsConfig.KingCrab.RainMultiplier, m_gebsConfig.KingCrab.StormMultiplier, m_gebsConfig.KingCrab.NightMultiplier);
	}
}

class geb_YieldSnowCrab : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_SnowCrab", m_gebsConfig.SnowCrab.Environment, m_gebsConfig.SnowCrab.CatchMethod, m_gebsConfig.SnowCrab.RainMultiplier, m_gebsConfig.SnowCrab.StormMultiplier, m_gebsConfig.SnowCrab.NightMultiplier);
	}
}

class geb_YieldBlueJellyFish : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_BlueJellyFish", m_gebsConfig.BlueJellyFish.Environment, m_gebsConfig.BlueJellyFish.CatchMethod, m_gebsConfig.BlueJellyFish.RainMultiplier, m_gebsConfig.BlueJellyFish.StormMultiplier, m_gebsConfig.BlueJellyFish.NightMultiplier);
	}
}

class geb_YieldAmericanLobster : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_AmericanLobster", m_gebsConfig.AmericanLobster.Environment, m_gebsConfig.AmericanLobster.CatchMethod, m_gebsConfig.AmericanLobster.RainMultiplier, m_gebsConfig.AmericanLobster.StormMultiplier, m_gebsConfig.AmericanLobster.NightMultiplier);
	}
}

class geb_YieldEuropeanLobster : GebYieldFishBase {
    override void Init() {
		SetupYield("geb_EuropeanLobster", m_gebsConfig.EuropeanLobster.Environment, m_gebsConfig.EuropeanLobster.CatchMethod, m_gebsConfig.EuropeanLobster.RainMultiplier, m_gebsConfig.EuropeanLobster.StormMultiplier, m_gebsConfig.EuropeanLobster.NightMultiplier);
	}
}