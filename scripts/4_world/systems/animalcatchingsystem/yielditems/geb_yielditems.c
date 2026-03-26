/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class GebYieldFishBase extends FishYieldItemBase
{
	void SetupYield(string typeName, int envMask, int methodMask)
	{
		super.Init();
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = typeName;
		m_EnviroMask = envMask;
		m_MethodMask = methodMask;
	}
};

// ===== FRESHWATER FISH =====
class geb_YieldCarp : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("Carp", m_gebsConfig.Carp.Environment, m_gebsConfig.Carp.CatchMethod);
	}
}

class geb_YieldBitterlings : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("Bitterlings", m_gebsConfig.Bitterlings.Environment, m_gebsConfig.Bitterlings.CatchMethod);
	}
}

class geb_YieldSteelheadTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("SteelheadTrout", m_gebsConfig.SteelheadTrout.Environment, m_gebsConfig.SteelheadTrout.CatchMethod);
	}
}

class geb_YieldCherrySalmon : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_CherrySalmon", m_gebsConfig.CherrySalmon.Environment, m_gebsConfig.CherrySalmon.CatchMethod);
	}
}

class geb_YieldChinookSalmon : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_ChinookSalmon", m_gebsConfig.ChinookSalmon.Environment, m_gebsConfig.ChinookSalmon.CatchMethod);
	}
}

class geb_YieldSockEyeSalmon : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SockEyeSalmon", m_gebsConfig.SockEyeSalmon.Environment, m_gebsConfig.SockEyeSalmon.CatchMethod);
	}
}

class geb_YieldSturgeon : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_Sturgeon", m_gebsConfig.Sturgeon.Environment, m_gebsConfig.Sturgeon.CatchMethod);
	}
}

class geb_YieldNorthernPike : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_NorthernPike", m_gebsConfig.NorthernPike.Environment, m_gebsConfig.NorthernPike.CatchMethod);
	}
}

class geb_YieldLargeMouthBass : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_LargeMouthBass", m_gebsConfig.LargeMouthBass.Environment, m_gebsConfig.LargeMouthBass.CatchMethod);
	}
}

class geb_YieldSmallMouthBass : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SmallMouthBass", m_gebsConfig.SmallMouthBass.Environment, m_gebsConfig.SmallMouthBass.CatchMethod);
	}
}

class geb_YieldWallEye : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_WallEye", m_gebsConfig.WallEye.Environment, m_gebsConfig.WallEye.CatchMethod);
	}
}

class geb_YieldSunFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SunFish", m_gebsConfig.SunFish.Environment, m_gebsConfig.SunFish.CatchMethod);
	}
}

class geb_YieldWhiteBass : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_WhiteBass", m_gebsConfig.WhiteBass.Environment, m_gebsConfig.WhiteBass.CatchMethod);
	}
}

class geb_YieldBlackBass : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BlackBass", m_gebsConfig.BlackBass.Environment, m_gebsConfig.BlackBass.CatchMethod);
	}
}

class geb_YieldRainbowTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_RainbowTrout", m_gebsConfig.RainbowTrout.Environment, m_gebsConfig.RainbowTrout.CatchMethod);
	}
}

class geb_YieldBrownTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BrownTrout", m_gebsConfig.BrownTrout.Environment, m_gebsConfig.BrownTrout.CatchMethod);
	}
}

class geb_YieldBrookTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BrookTrout", m_gebsConfig.BrookTrout.Environment, m_gebsConfig.BrookTrout.CatchMethod);
	}
}

class geb_YieldLakeTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_LakeTrout", m_gebsConfig.LakeTrout.Environment, m_gebsConfig.LakeTrout.CatchMethod);
	}
}

class geb_YieldCutThroatTrout : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_CutThroatTrout", m_gebsConfig.CutThroatTrout.Environment, m_gebsConfig.CutThroatTrout.CatchMethod);
	}
}

class geb_YieldYellowPerch : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_YellowPerch", m_gebsConfig.YellowPerch.Environment, m_gebsConfig.YellowPerch.CatchMethod);
	}
}

class geb_YieldFlatHeadCatFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_FlatHeadCatFish", m_gebsConfig.FlatHeadCatFish.Environment, m_gebsConfig.FlatHeadCatFish.CatchMethod);
	}
}

class geb_YieldFatHeadMinnow : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_FatHeadMinnow", m_gebsConfig.FatHeadMinnow.Environment, m_gebsConfig.FatHeadMinnow.CatchMethod);
	}
}

class geb_YieldBlueGill : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BlueGill", m_gebsConfig.BlueGill.Environment, m_gebsConfig.BlueGill.CatchMethod);
	}
}

class geb_YieldSauger : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_Sauger", m_gebsConfig.Sauger.Environment, m_gebsConfig.Sauger.CatchMethod);
	}
}

class geb_YieldBowFin : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BowFin", m_gebsConfig.BowFin.Environment, m_gebsConfig.BowFin.CatchMethod);
	}
}

class geb_YieldSlimySculpin : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SlimySculpin", m_gebsConfig.SlimySculpin.Environment, m_gebsConfig.SlimySculpin.CatchMethod);
	}
}


// ===== FRESHWATER CRUSTACEAN =====
class geb_YieldSignalCrayFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SignalCrayFish", m_gebsConfig.SignalCrayFish.Environment, m_gebsConfig.SignalCrayFish.CatchMethod);
	}
}

class geb_YieldEuropeanCrayFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_EuropeanCrayFish", m_gebsConfig.EuropeanCrayFish.Environment, m_gebsConfig.EuropeanCrayFish.CatchMethod);
	}
}


// ===== SALTWATER FISH =====
class geb_YieldMackerel : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("Mackerel", m_gebsConfig.Mackerel.Environment, m_gebsConfig.Mackerel.CatchMethod);
	}
}

class geb_YieldSardines : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("Sardines", m_gebsConfig.Sardines.Environment, m_gebsConfig.Sardines.CatchMethod);
	}
}

class geb_YieldWalleyePollock : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("WalleyePollock", m_gebsConfig.WalleyePollock.Environment, m_gebsConfig.WalleyePollock.CatchMethod);
	}
}

class geb_YieldMahiMahi : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_MahiMahi", m_gebsConfig.MahiMahi.Environment, m_gebsConfig.MahiMahi.CatchMethod);
	}
}

class geb_YieldAtlanticSailFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AtlanticSailFish", m_gebsConfig.AtlanticSailFish.Environment, m_gebsConfig.AtlanticSailFish.CatchMethod);
	}
}

class geb_YieldAngelFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AngelFish", m_gebsConfig.AngelFish.Environment, m_gebsConfig.AngelFish.CatchMethod);
	}
}

class geb_YieldAsianSeaBass : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AsianSeaBass", m_gebsConfig.AsianSeaBass.Environment, m_gebsConfig.AsianSeaBass.CatchMethod);
	}
}

class geb_YieldAtlanticBlueMarlin : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AtlanticBlueMarlin", m_gebsConfig.AtlanticBlueMarlin.Environment, m_gebsConfig.AtlanticBlueMarlin.CatchMethod);
	}
}

class geb_YieldBonita : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_Bonita", m_gebsConfig.Bonita.Environment, m_gebsConfig.Bonita.CatchMethod);
	}
}

class geb_YieldFlatHeadMullet : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_FlatHeadMullet", m_gebsConfig.FlatHeadMullet.Environment, m_gebsConfig.FlatHeadMullet.CatchMethod);
	}
}

class geb_YieldRedHeadCichlid : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_RedHeadCichlid", m_gebsConfig.RedHeadCichlid.Environment, m_gebsConfig.RedHeadCichlid.CatchMethod);
	}
}

class geb_YieldRoughNeckRock : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_RoughNeckRock", m_gebsConfig.RoughNeckRock.Environment, m_gebsConfig.RoughNeckRock.CatchMethod);
	}
}

class geb_YieldBlueTang : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BlueTang", m_gebsConfig.BlueTang.Environment, m_gebsConfig.BlueTang.CatchMethod);
	}
}

class geb_YieldLargeHeadHairTailFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_LargeHeadHairTailFish", m_gebsConfig.LargeHeadHairTailFish.Environment, m_gebsConfig.LargeHeadHairTailFish.CatchMethod);
	}
}

class geb_YieldHumpHeadWrasse : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_HumpHeadWrasse", m_gebsConfig.HumpHeadWrasse.Environment, m_gebsConfig.HumpHeadWrasse.CatchMethod);
	}
}

class geb_YieldSiameseTigerFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SiameseTigerFish", m_gebsConfig.SiameseTigerFish.Environment, m_gebsConfig.SiameseTigerFish.CatchMethod);
	}
}

class geb_YieldLeopardShark : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_LeopardShark", m_gebsConfig.LeopardShark.Environment, m_gebsConfig.LeopardShark.CatchMethod);
	}
}

class geb_YieldHammerHeadShark : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_HammerHeadShark", m_gebsConfig.HammerHeadShark.Environment, m_gebsConfig.HammerHeadShark.CatchMethod);
	}
}

class geb_YieldPacificCod : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_PacificCod", m_gebsConfig.PacificCod.Environment, m_gebsConfig.PacificCod.CatchMethod);
	}
}

class geb_YieldGreatWhiteShark : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_GreatWhiteShark", m_gebsConfig.GreatWhiteShark.Environment, m_gebsConfig.GreatWhiteShark.CatchMethod);
	}
}

class geb_YieldAngelShark : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AngelShark", m_gebsConfig.AngelShark.Environment, m_gebsConfig.AngelShark.CatchMethod);
	}
}

class geb_YieldYellowFinTuna : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_YellowFinTuna", m_gebsConfig.YellowFinTuna.Environment, m_gebsConfig.YellowFinTuna.CatchMethod);
	}
}

class geb_YieldSeverum : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_Severum", m_gebsConfig.Severum.Environment, m_gebsConfig.Severum.CatchMethod);
	}
}


// ===== SALTWATER CRUSTACEAN / MARINE INVERTEBRATES =====
class geb_YieldShrimp : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("Shrimp", m_gebsConfig.Shrimp.Environment, m_gebsConfig.Shrimp.CatchMethod);
	}
}

class geb_YieldBloodClam : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BloodClam", m_gebsConfig.BloodClam.Environment, m_gebsConfig.BloodClam.CatchMethod);
	}
}

class geb_YieldMussel : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_Mussel", m_gebsConfig.Mussel.Environment, m_gebsConfig.Mussel.CatchMethod);
	}
}

class geb_YieldBlackDevilSnail : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BlackDevilSnail", m_gebsConfig.BlackDevilSnail.Environment, m_gebsConfig.BlackDevilSnail.CatchMethod);
	}
}

class geb_YieldStarFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_StarFish", m_gebsConfig.StarFish.Environment, m_gebsConfig.StarFish.CatchMethod);
	}
}

class geb_YieldKingCrab : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_KingCrab", m_gebsConfig.KingCrab.Environment, m_gebsConfig.KingCrab.CatchMethod);
	}
}

class geb_YieldSnowCrab : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_SnowCrab", m_gebsConfig.SnowCrab.Environment, m_gebsConfig.SnowCrab.CatchMethod);
	}
}

class geb_YieldBlueJellyFish : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_BlueJellyFish", m_gebsConfig.BlueJellyFish.Environment, m_gebsConfig.BlueJellyFish.CatchMethod);
	}
}

class geb_YieldAmericanLobster : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_AmericanLobster", m_gebsConfig.AmericanLobster.Environment, m_gebsConfig.AmericanLobster.CatchMethod);
	}
}

class geb_YieldEuropeanLobster : GebYieldFishBase
{
	override void Init()
	{
		SetupYield("geb_EuropeanLobster", m_gebsConfig.EuropeanLobster.Environment, m_gebsConfig.EuropeanLobster.CatchMethod);
	}
}