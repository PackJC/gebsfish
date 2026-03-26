class GebPrepareFishBase extends PrepareFish
{
	void SetupFishRecipe(string ingredientType)
	{
		InsertIngredient(0, ingredientType);
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;
	}

	void AddDefaultResultAtIndex(string resultType, int index)
	{
		AddResult(resultType);
		m_ResultSetFullQuantity[index] = false;
		m_ResultSetQuantity[index] = -1;
		m_ResultSetHealth[index] = -1;
		m_ResultInheritsHealth[index] = 0;
		m_ResultInheritsColor[index] = -1;
		m_ResultToInventory[index] = -2;
		m_ResultUseSoftSkills[index] = false;
		m_ResultReplacesIngredient[index] = 0;
	}

	void AddRepeatedResults(string resultType, int count, int startIndex = 0)
	{
		for (int i = 0; i < count; ++i)
		{
			AddDefaultResultAtIndex(resultType, startIndex + i);
		}
	}

	int GetInclusiveRandom(int min, int max)
	{
		if (max < min)
			max = min;

		return Math.RandomInt(min, max + 1);
	}

	void SetupStandardRecipe(string ingredientType, string resultType, int minCount, int maxCount)
	{
		SetupFishRecipe(ingredientType);
		AddRepeatedResults(resultType, GetInclusiveRandom(minCount, maxCount));
	}

	void SetupLobsterRecipe(string ingredientType, string tailType, string clawType, int minCount, int maxCount)
	{
		SetupFishRecipe(ingredientType);
		AddDefaultResultAtIndex(tailType, 0);

		int total = GetInclusiveRandom(minCount, maxCount);
		int clawCount = total - 1;
		if (clawCount < 0)
			clawCount = 0;

		AddRepeatedResults(clawType, clawCount, 1);
	}

	void ApplyThirtyPercentCaviarChance(array<ItemBase> results)
	{
		if (Math.RandomFloat(0, 1) > 0.3)
		{
			if (results && results.Count() > 0 && results[0])
				results[0].Delete();
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
	}
};

// ===== FRESHWATER FISH =====

class PrepareYellowPerch extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_YellowPerch", "geb_YellowPerchFilletMeat", m_gebsConfig.YellowPerch.MeatMin, m_gebsConfig.YellowPerch.MeatMax);
	}
};

class PrepareBlackBass extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_BlackBass", "geb_BlackBassFilletMeat", m_gebsConfig.BlackBass.MeatMin, m_gebsConfig.BlackBass.MeatMax);
	}
};

class PrepareBlueGill extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_BlueGill", "geb_BlueGillFilletMeat", m_gebsConfig.BlueGill.MeatMin, m_gebsConfig.BlueGill.MeatMax);
	}
};

class PrepareBowFin extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_BowFin", "geb_BowFinFilletMeat", m_gebsConfig.BowFin.MeatMin, m_gebsConfig.BowFin.MeatMax);
	}
};

class PrepareBrookTrout extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_BrookTrout");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.BrookTrout.MeatMin, m_gebsConfig.BrookTrout.MeatMax);
		AddRepeatedResults("geb_BrookTroutFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

class PrepareBrownTrout extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_BrownTrout");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.BrownTrout.MeatMin, m_gebsConfig.BrownTrout.MeatMax);
		AddRepeatedResults("geb_BrownTroutFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

modded class PrepareCarp extends PrepareFish
{
	override void Init()
	{
		super.Init();
		InsertIngredient(0, "Carp");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int ran = Math.RandomInt(m_gebsConfig.Carp.MeatMin, m_gebsConfig.Carp.MeatMax + 1);
		for (int i = 0; i < ran; ++i)
		{
			AddResult("CarpFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
	}
};

class PrepareCherrySalmon extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_CherrySalmon");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.CherrySalmon.MeatMin, m_gebsConfig.CherrySalmon.MeatMax);
		AddRepeatedResults("geb_CherrySalmonFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

class PrepareChinookSalmon extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_ChinookSalmon");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.ChinookSalmon.MeatMin, m_gebsConfig.ChinookSalmon.MeatMax);
		AddRepeatedResults("geb_ChinookSalmonFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

class PrepareCutThroatTrout extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_CutThroatTrout");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.CutThroatTrout.MeatMin, m_gebsConfig.CutThroatTrout.MeatMax);
		AddRepeatedResults("geb_CutThroatTroutFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

class PrepareFlatHeadCatFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_FlatHeadCatFish", "geb_FlatHeadCatFishFilletMeat", m_gebsConfig.FlatHeadCatFish.MeatMin, m_gebsConfig.FlatHeadCatFish.MeatMax);
	}
};

class PrepareLakeTrout extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_LakeTrout", "geb_LakeTroutFilletMeat", m_gebsConfig.LakeTrout.MeatMin, m_gebsConfig.LakeTrout.MeatMax);
	}
};

class PrepareLargeMouthBass extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_LargeMouthBass", "geb_LargeMouthBassFilletMeat", m_gebsConfig.LargeMouthBass.MeatMin, m_gebsConfig.LargeMouthBass.MeatMax);
	}
};

class PrepareNorthernPike extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_NorthernPike", "geb_NorthernPikeFilletMeat", m_gebsConfig.NorthernPike.MeatMin, m_gebsConfig.NorthernPike.MeatMax);
	}
};

class PrepareRainbowTrout extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_RainbowTrout");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.RainbowTrout.MeatMin, m_gebsConfig.RainbowTrout.MeatMax);
		AddRepeatedResults("geb_RainbowTroutFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

class PrepareSauger extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_Sauger", "geb_SaugerFilletMeat", m_gebsConfig.Sauger.MeatMin, m_gebsConfig.Sauger.MeatMax);
	}
};

class PrepareSlimySculpin extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_SlimySculpin", "geb_SlimySculpinFilletMeat", m_gebsConfig.SlimySculpin.MeatMin, m_gebsConfig.SlimySculpin.MeatMax);
	}
};

class PrepareSmallMouthBass extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_SmallMouthBass", "geb_SmallMouthBassFilletMeat", m_gebsConfig.SmallMouthBass.MeatMin, m_gebsConfig.SmallMouthBass.MeatMax);
	}
};

class PrepareSockEyeSalmon extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupFishRecipe("geb_SockEyeSalmon");
		AddDefaultResultAtIndex("RedCaviar", 0);

		int ran = GetInclusiveRandom(m_gebsConfig.SockEyeSalmon.MeatMin, m_gebsConfig.SockEyeSalmon.MeatMax);
		AddRepeatedResults("geb_SockEyeSalmonFilletMeat", ran, 1);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
		ApplyThirtyPercentCaviarChance(results);
	}
};

modded class PrepareSteelheadTrout extends PrepareFish
{
	override void Init()
	{
		super.Init();
		InsertIngredient(0, "SteelheadTrout");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		AddResult("RedCaviar");
		m_ResultSetFullQuantity[0] = false;
		m_ResultSetQuantity[0] = -1;
		m_ResultSetHealth[0] = -1;
		m_ResultInheritsHealth[0] = 0;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = 0;

		int ran = Math.RandomInt(m_gebsConfig.SteelheadTrout.MeatMin, m_gebsConfig.SteelheadTrout.MeatMax + 1);
		for (int i = 1; i <= ran; ++i)
		{
			AddResult("SteelheadTroutFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);

		if (Math.RandomFloat(0, 1) > 0.3)
		{
			if (results && results.Count() > 0 && results[0])
				results[0].Delete();
		}
	}
};

class PrepareSturgeon extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_Sturgeon", "geb_SturgeonFilletMeat", m_gebsConfig.Sturgeon.MeatMin, m_gebsConfig.Sturgeon.MeatMax);
	}
};

class PrepareSunFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_SunFish", "geb_SunFishFilletMeat", m_gebsConfig.SunFish.MeatMin, m_gebsConfig.SunFish.MeatMax);
	}
};

class PrepareWallEye extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_WallEye", "geb_WallEyeFilletMeat", m_gebsConfig.WallEye.MeatMin, m_gebsConfig.WallEye.MeatMax);
	}
};

class PrepareWhiteBass extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_WhiteBass", "geb_WhiteBassFilletMeat", m_gebsConfig.WhiteBass.MeatMin, m_gebsConfig.WhiteBass.MeatMax);
	}
};

// ===== FRESHWATER CRUSTACEAN =====
// None currently

// ===== SALTWATER FISH =====

class PrepareAngelFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_AngelFish", "geb_AngelFishFilletMeat", m_gebsConfig.AngelFish.MeatMin, m_gebsConfig.AngelFish.MeatMax);
	}
};

class PrepareAngelShark extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_AngelShark", "geb_AngelSharkFilletMeat", m_gebsConfig.AngelShark.MeatMin, m_gebsConfig.AngelShark.MeatMax);
	}
};

class PrepareAsianSeaBass extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_AsianSeaBass", "geb_AsianSeaBassFilletMeat", m_gebsConfig.AsianSeaBass.MeatMin, m_gebsConfig.AsianSeaBass.MeatMax);
	}
};

class PrepareAtlanticBlueMarlin extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_AtlanticBlueMarlin", "geb_AtlanticBlueMarlinFilletMeat", m_gebsConfig.AtlanticBlueMarlin.MeatMin, m_gebsConfig.AtlanticBlueMarlin.MeatMax);
	}
};

class PrepareAtlanticSailFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_AtlanticSailFish", "geb_AtlanticSailFishFilletMeat", m_gebsConfig.AtlanticSailFish.MeatMin, m_gebsConfig.AtlanticSailFish.MeatMax);
	}
};

class PrepareBlueTang extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_BlueTang", "geb_BlueTangFilletMeat", m_gebsConfig.BlueTang.MeatMin, m_gebsConfig.BlueTang.MeatMax);
	}
};

class PrepareBonita extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_Bonita", "geb_BonitaFilletMeat", m_gebsConfig.Bonita.MeatMin, m_gebsConfig.Bonita.MeatMax);
	}
};

class PrepareFlatHeadMullet extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_FlatHeadMullet", "geb_FlatHeadMulletFilletMeat", m_gebsConfig.FlatHeadMullet.MeatMin, m_gebsConfig.FlatHeadMullet.MeatMax);
	}
};

class PrepareGreatWhiteShark extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_GreatWhiteShark", "geb_GreatWhiteSharkFilletMeat", m_gebsConfig.GreatWhiteShark.MeatMin, m_gebsConfig.GreatWhiteShark.MeatMax);
	}
};

class PrepareHammerHeadShark extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_HammerHeadShark", "geb_HammerHeadSharkFilletMeat", m_gebsConfig.HammerHeadShark.MeatMin, m_gebsConfig.HammerHeadShark.MeatMax);
	}
};

class PrepareHumpHeadWrasse extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_HumpHeadWrasse", "geb_HumpHeadWrasseFilletMeat", m_gebsConfig.HumpHeadWrasse.MeatMin, m_gebsConfig.HumpHeadWrasse.MeatMax);
	}
};

class PrepareLargeHeadHairTailFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_LargeHeadHairTailFish", "geb_LargeHeadHairTailFishFilletMeat", m_gebsConfig.LargeHeadHairTailFish.MeatMin, m_gebsConfig.LargeHeadHairTailFish.MeatMax);
	}
};

class PrepareLeopardShark extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_LeopardShark", "geb_LeopardSharkFilletMeat", m_gebsConfig.LeopardShark.MeatMin, m_gebsConfig.LeopardShark.MeatMax);
	}
};

modded class PrepareMackerel extends PrepareFish
{
	override void Init()
	{
		super.Init();
		InsertIngredient(0, "Mackerel");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int ran = Math.RandomInt(m_gebsConfig.Mackerel.MeatMin, m_gebsConfig.Mackerel.MeatMax + 1);
		for (int i = 0; i < ran; ++i)
		{
			AddResult("MackerelFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
	}
};

class PrepareMahiMahi extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_MahiMahi", "geb_MahiMahiFilletMeat", m_gebsConfig.MahiMahi.MeatMin, m_gebsConfig.MahiMahi.MeatMax);
	}
};

class PreparePacificCod extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_PacificCod", "geb_PacificCodFilletMeat", m_gebsConfig.PacificCod.MeatMin, m_gebsConfig.PacificCod.MeatMax);
	}
};

class PrepareRedHeadCichlid extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_RedHeadCichlid", "geb_RedHeadCichlidFilletMeat", m_gebsConfig.RedHeadCichlid.MeatMin, m_gebsConfig.RedHeadCichlid.MeatMax);
	}
};

class PrepareRoughNeckRock extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_RoughNeckRock", "geb_RoughNeckRockFilletMeat", m_gebsConfig.RoughNeckRock.MeatMin, m_gebsConfig.RoughNeckRock.MeatMax);
	}
};

class PrepareSeverum extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_Severum", "geb_SeverumFilletMeat", m_gebsConfig.Severum.MeatMin, m_gebsConfig.Severum.MeatMax);
	}
};

class PrepareSiameseTigerFish extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_SiameseTigerFish", "geb_SiameseTigerFishFilletMeat", m_gebsConfig.SiameseTigerFish.MeatMin, m_gebsConfig.SiameseTigerFish.MeatMax);
	}
};

modded class PrepareWalleyePollock extends PrepareFish
{
	override void Init()
	{
		super.Init();
		InsertIngredient(0, "WalleyePollock");
		m_IngredientAddHealth[0] = 0;
		m_IngredientSetHealth[0] = -1;
		m_IngredientAddQuantity[0] = 0;
		m_IngredientDestroy[0] = true;
		m_IngredientAddHealth[1] = -4;

		int ran = Math.RandomInt(m_gebsConfig.WalleyePollock.MeatMin, m_gebsConfig.WalleyePollock.MeatMax + 1);
		for (int i = 0; i < ran; ++i)
		{
			AddResult("WalleyePollockFilletMeat");
			m_ResultSetFullQuantity[i] = false;
			m_ResultSetQuantity[i] = -1;
			m_ResultSetHealth[i] = -1;
			m_ResultInheritsHealth[i] = 0;
			m_ResultInheritsColor[i] = -1;
			m_ResultToInventory[i] = -2;
			m_ResultUseSoftSkills[i] = false;
			m_ResultReplacesIngredient[i] = 0;
		}
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		super.Do(ingredients, player, results, specialty_weight);
	}
};

class PrepareYellowFinTuna extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_YellowFinTuna", "geb_YellowFinTunaFilletMeat", m_gebsConfig.YellowFinTuna.MeatMin, m_gebsConfig.YellowFinTuna.MeatMax);
	}
};

// ===== SALTWATER CRUSTACEAN =====

class PrepareAmericanLobster extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupLobsterRecipe("geb_AmericanLobster", "geb_AmericanLobsterTail", "geb_AmericanLobsterClaw", m_gebsConfig.AmericanLobster.MeatMin, m_gebsConfig.AmericanLobster.MeatMax);
	}
};

class PrepareEuropeanLobster extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupLobsterRecipe("geb_EuropeanLobster", "geb_EuropeanLobsterTail", "geb_EuropeanLobsterClaw", m_gebsConfig.EuropeanLobster.MeatMin, m_gebsConfig.EuropeanLobster.MeatMax);
	}
};

class PrepareKingCrab extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_KingCrab", "geb_KingCrabLegs", m_gebsConfig.KingCrab.MeatMin, m_gebsConfig.KingCrab.MeatMax);
	}
};

class PrepareSnowCrab extends GebPrepareFishBase
{
	override void Init()
	{
		super.Init();
		SetupStandardRecipe("geb_SnowCrab", "geb_SnowCrabLegs", m_gebsConfig.SnowCrab.MeatMin, m_gebsConfig.SnowCrab.MeatMax);
	}
};
