/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class geb_YieldMackerel : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		// autoptr TFloatArray gebCycle = m_gebsConfig.Mackerel.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "Mackerel";
		m_EnviroMask = m_gebsConfig.Mackerel.Environment;
		m_MethodMask = m_gebsConfig.Mackerel.CatchMethod;
	}
}

class geb_YieldCarp : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
        
        // autoptr TFloatArray gebCycle = m_gebsConfig.Carp.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "Carp";
		m_EnviroMask = m_gebsConfig.Carp.Environment;
		m_MethodMask = m_gebsConfig.Carp.CatchMethod;
	}
}

class geb_YieldSardines : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sardines.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "Sardines";
		m_EnviroMask = m_gebsConfig.Sardines.Environment;
		m_MethodMask = m_gebsConfig.Sardines.CatchMethod;
	}
}

class geb_YieldBitterlings : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bitterlings.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "Bitterlings";
		m_EnviroMask = m_gebsConfig.Bitterlings.Environment;
		m_MethodMask = m_gebsConfig.Bitterlings.CatchMethod;
	}
}

//---------//
//cool new fish//
//---------//
class geb_YieldWalleyePollock : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.WalleyePollock.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "WalleyePollock";
		m_EnviroMask = m_gebsConfig.WalleyePollock.Environment;
		m_MethodMask = m_gebsConfig.WalleyePollock.CatchMethod;
	}
}

class geb_YieldSteelheadTrout : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SteelheadTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "SteelheadTrout";
		m_EnviroMask = m_gebsConfig.SteelheadTrout.Environment;
		m_MethodMask = m_gebsConfig.SteelheadTrout.CatchMethod;
	}
}

class geb_YieldShrimp : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Shrimp.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "Shrimp";
		m_EnviroMask = m_gebsConfig.Shrimp.Environment;
		m_MethodMask = m_gebsConfig.Shrimp.CatchMethod;
	}
}


//Saltwater
class geb_YieldMahiMahi : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Mahimahi.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_MahiMahi";
		m_EnviroMask = m_gebsConfig.MahiMahi.Environment;
		m_MethodMask = m_gebsConfig.MahiMahi.CatchMethod;
    }
};

class geb_YieldAtlanticSailFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sailfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AtlanticSailFish";
		m_EnviroMask = m_gebsConfig.AtlanticSailFish.Environment;
		m_MethodMask = m_gebsConfig.AtlanticSailFish.CatchMethod;
    }
};

class geb_YieldAngelFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Angelfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AngelFish";
		m_EnviroMask = m_gebsConfig.AngelFish.Environment;
		m_MethodMask = m_gebsConfig.AngelFish.CatchMethod;
    }
};

class geb_YieldAsianSeaBass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.AsianSeaBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AsianSeaBass";
		m_EnviroMask = m_gebsConfig.AsianSeaBass.Environment;
		m_MethodMask = m_gebsConfig.AsianSeaBass.CatchMethod;
    }
};

class geb_YieldAtlanticBlueMarlin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueMarlin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AtlanticBlueMarlin";
		m_EnviroMask = m_gebsConfig.AtlanticBlueMarlin.Environment;
		m_MethodMask = m_gebsConfig.AtlanticBlueMarlin.CatchMethod;
    }
};

class geb_YieldBonita : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bonita.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bonita";
		m_EnviroMask = m_gebsConfig.Bonita.Environment;
		m_MethodMask = m_gebsConfig.Bonita.CatchMethod;
    }
};

class geb_YieldCherrySalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.CherrySalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_CherrySalmon";
		m_EnviroMask = m_gebsConfig.CherrySalmon.Environment;
		m_MethodMask = m_gebsConfig.CherrySalmon.CatchMethod;
    }
};

class geb_YieldChinookSalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.ChinookSalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_ChinookSalmon";
		m_EnviroMask = m_gebsConfig.ChinookSalmon.Environment;
		m_MethodMask = m_gebsConfig.ChinookSalmon.CatchMethod;
    }
};

class geb_YieldSockEyeSalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SockeyeSalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SockEyeSalmon";
		m_EnviroMask = m_gebsConfig.SockEyeSalmon.Environment;
		m_MethodMask = m_gebsConfig.SockEyeSalmon.CatchMethod;
    }
};
                                           
class geb_YieldFlatHeadMullet : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.FlatheadMullet.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_FlatHeadMullet";
		m_EnviroMask = m_gebsConfig.FlatHeadMullet.Environment;
		m_MethodMask = m_gebsConfig.FlatHeadMullet.CatchMethod;
    }
};

class geb_YieldRedHeadCichlid : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RedheadCichlid.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_RedHeadCichlid";
		m_EnviroMask = m_gebsConfig.RedHeadCichlid.Environment;
		m_MethodMask = m_gebsConfig.RedHeadCichlid.CatchMethod;
    }
};

class geb_YieldRoughNeckRock : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RoughneckRock.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_RoughNeckRock";
		m_EnviroMask = m_gebsConfig.RoughNeckRock.Environment;
		m_MethodMask = m_gebsConfig.RoughNeckRock.CatchMethod;
    }
};

class geb_YieldBlueTang : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueTang.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlueTang";
		m_EnviroMask = m_gebsConfig.BlueTang.Environment;
		m_MethodMask = m_gebsConfig.BlueTang.CatchMethod;
    }
};

class geb_YieldLargeHeadHairTailFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.HairtailFish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_LargeHeadHairTailFish";
		m_EnviroMask = m_gebsConfig.LargeHeadHairTailFish.Environment;
		m_MethodMask = m_gebsConfig.LargeHeadHairTailFish.CatchMethod;
    }
};

class geb_YieldHumpHeadWrasse : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.HumpheadWrasse.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_HumpHeadWrasse";
		m_EnviroMask = m_gebsConfig.HumpHeadWrasse.Environment;
		m_MethodMask = m_gebsConfig.HumpHeadWrasse.CatchMethod;
    }
};

class geb_YieldSiameseTigerFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SiameseTigerfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SiameseTigerFish";
		m_EnviroMask = m_gebsConfig.SiameseTigerFish.Environment;
		m_MethodMask = m_gebsConfig.SiameseTigerFish.CatchMethod;
    }
};

class geb_YieldLeopardShark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.LeopardShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_LeopardShark";
		m_EnviroMask = m_gebsConfig.LeopardShark.Environment;
		m_MethodMask = m_gebsConfig.LeopardShark.CatchMethod;
    }
};

class geb_YieldPacificCod : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.PacificCod.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_PacificCod";
		m_EnviroMask = m_gebsConfig.PacificCod.Environment;
		m_MethodMask = m_gebsConfig.PacificCod.CatchMethod;
    }
};

class geb_YieldGreatWhiteShark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.GreatWhiteShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_GreatWhiteShark";
		m_EnviroMask = m_gebsConfig.GreatWhiteShark.Environment;
		m_MethodMask = m_gebsConfig.GreatWhiteShark.CatchMethod;
    }
};

class geb_YieldAngelShark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.AngelShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AngelShark";
		m_EnviroMask = m_gebsConfig.AngelShark.Environment;
		m_MethodMask = m_gebsConfig.AngelShark.CatchMethod;
    }
};

class geb_YieldYellowFinTuna : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.YellowfinTuna.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_YellowFinTuna";
		m_EnviroMask = m_gebsConfig.YellowFinTuna.Environment;
		m_MethodMask = m_gebsConfig.YellowFinTuna.CatchMethod;
    }
};

//Freshwater
class geb_YieldNorthernPike : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.NorthernPike.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_NorthernPike";
		m_EnviroMask = m_gebsConfig.NorthernPike.Environment;
		m_MethodMask = m_gebsConfig.NorthernPike.CatchMethod;
    }
};

class geb_YieldLargeMouthBass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.LargemouthBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_LargeMouthBass";
		m_EnviroMask = m_gebsConfig.LargeMouthBass.Environment;
		m_MethodMask = m_gebsConfig.LargeMouthBass.CatchMethod;
    }
};

class geb_YieldSmallMouthBass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SmallmouthBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SmallMouthBass";
		m_EnviroMask = m_gebsConfig.SmallMouthBass.Environment;
		m_MethodMask = m_gebsConfig.SmallMouthBass.CatchMethod;
    }
};

class geb_YieldWallEye : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Walleye.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_WallEye";
		m_EnviroMask = m_gebsConfig.WallEye.Environment;
		m_MethodMask = m_gebsConfig.WallEye.CatchMethod;
    }
};

class geb_YieldSunFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sunfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SunFish";
		m_EnviroMask = m_gebsConfig.SunFish.Environment;
		m_MethodMask = m_gebsConfig.SunFish.CatchMethod;
    }
};

class geb_YieldWhiteBass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.WhiteBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_WhiteBass";
		m_EnviroMask = m_gebsConfig.WhiteBass.Environment;
		m_MethodMask = m_gebsConfig.WhiteBass.CatchMethod;
    }
};

class geb_YieldSeverum : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Severum.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Severum";
		m_EnviroMask = m_gebsConfig.Severum.Environment;
		m_MethodMask = m_gebsConfig.Severum.CatchMethod;
    }
};

class geb_YieldBlackBass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlackBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlackBass";
		m_EnviroMask = m_gebsConfig.BlackBass.Environment;
		m_MethodMask = m_gebsConfig.BlackBass.CatchMethod;
    }
};

class geb_YieldRainbowTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RainbowTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_RainbowTrout";
		m_EnviroMask = m_gebsConfig.RainbowTrout.Environment;
		m_MethodMask = m_gebsConfig.RainbowTrout.CatchMethod;
    }
};

class geb_YieldBrownTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BrownTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BrownTrout";
		m_EnviroMask = m_gebsConfig.BrownTrout.Environment;
		m_MethodMask = m_gebsConfig.BrownTrout.CatchMethod;
    }
};

class geb_YieldBrookTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BrookTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BrookTrout";
		m_EnviroMask = m_gebsConfig.BrookTrout.Environment;
		m_MethodMask = m_gebsConfig.BrookTrout.CatchMethod;
    }
};

class geb_YieldLakeTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.LakeTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_LakeTrout";
		m_EnviroMask = m_gebsConfig.LakeTrout.Environment;
		m_MethodMask = m_gebsConfig.LakeTrout.CatchMethod;
    }
};

class geb_YieldCutThroatTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.CutthroatTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_CutThroatTrout";
		m_EnviroMask = m_gebsConfig.CutThroatTrout.Environment;
		m_MethodMask = m_gebsConfig.CutThroatTrout.CatchMethod;
    }
};

class geb_YieldYellowPerch : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Perch.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_YellowPerch";
		m_EnviroMask = m_gebsConfig.YellowPerch.Environment;
		m_MethodMask = m_gebsConfig.YellowPerch.CatchMethod;
    }
};

class geb_YieldFlatHeadCatFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Catfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_FlatHeadCatFish";
		m_EnviroMask = m_gebsConfig.FlatHeadCatFish.Environment;
		m_MethodMask = m_gebsConfig.FlatHeadCatFish.CatchMethod;
    }
};

class geb_YieldFatHeadMinnow : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Minnow.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_FatHeadMinnow";
		m_EnviroMask = m_gebsConfig.FatHeadMinnow.Environment;
		m_MethodMask = m_gebsConfig.FatHeadMinnow.CatchMethod;
    }
};

class geb_YieldBlueGill : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bluegill.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlueGill";
		m_EnviroMask = m_gebsConfig.BlueGill.Environment;
		m_MethodMask = m_gebsConfig.BlueGill.CatchMethod;
    }
};

class geb_YieldSauger : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sauger.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Sauger";
		m_EnviroMask = m_gebsConfig.Sauger.Environment;
		m_MethodMask = m_gebsConfig.Sauger.CatchMethod;
    }
};

class geb_YieldBowFin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bowfin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BowFin";
		m_EnviroMask = m_gebsConfig.BowFin.Environment;
		m_MethodMask = m_gebsConfig.BowFin.CatchMethod;
    }
};

class geb_YieldSlimySculpin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SlimySculpin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SlimySculpin";
		m_EnviroMask = m_gebsConfig.SlimySculpin.Environment;
		m_MethodMask = m_gebsConfig.SlimySculpin.CatchMethod;
    }
};

//Fishtraps
class geb_YieldSignalCrayFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Crayfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SignalCrayFish";
		m_EnviroMask = m_gebsConfig.SignalCrayFish.Environment;
		m_MethodMask = m_gebsConfig.SignalCrayFish.CatchMethod;
    }
};

class geb_YieldEuropeanCrayFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Crayfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_EuropeanCrayFish";
		m_EnviroMask = m_gebsConfig.EuropeanCrayFish.Environment;
		m_MethodMask = m_gebsConfig.EuropeanCrayFish.CatchMethod;
    }
};

class geb_YieldBloodClam : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BloodClam.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BloodClam";
		m_EnviroMask = m_gebsConfig.BloodClam.Environment;
		m_MethodMask = m_gebsConfig.BloodClam.CatchMethod;
    }
};

class geb_YieldMussel : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Mussel.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Mussel";
		m_EnviroMask = m_gebsConfig.Mussel.Environment;
		m_MethodMask = m_gebsConfig.Mussel.CatchMethod;
    }
};

class geb_YieldBlackDevilSnail : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlackDevilSnail.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlackDevilSnail";
		m_EnviroMask = m_gebsConfig.BlackDevilSnail.Environment;
		m_MethodMask = m_gebsConfig.BlackDevilSnail.CatchMethod;
    }
};

class geb_YieldStarFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Starfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_StarFish";
		m_EnviroMask = m_gebsConfig.StarFish.Environment;
		m_MethodMask = m_gebsConfig.StarFish.CatchMethod;
    }
};

class geb_YieldKingCrab : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.KingCrab.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_KingCrab";
		m_EnviroMask = m_gebsConfig.KingCrab.Environment;
		m_MethodMask = m_gebsConfig.KingCrab.CatchMethod;
    }
};

class geb_YieldSnowCrab : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.KingCrab.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_SnowCrab";
		m_EnviroMask = m_gebsConfig.SnowCrab.Environment;
		m_MethodMask = m_gebsConfig.SnowCrab.CatchMethod;
    }
};

class geb_YieldBlueJellyFish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Jellyfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlueJellyFish";
		m_EnviroMask = m_gebsConfig.BlueJellyFish.Environment;
		m_MethodMask = m_gebsConfig.BlueJellyFish.CatchMethod;
    }
};

class geb_YieldAmericanLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Lobster.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_AmericanLobster";
		m_EnviroMask = m_gebsConfig.AmericanLobster.Environment;
		m_MethodMask = m_gebsConfig.AmericanLobster.CatchMethod;
    }
};

class geb_YieldEuropeanLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueLobster.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_EuropeanLobster";
		m_EnviroMask = m_gebsConfig.EuropeanLobster.Environment;
		m_MethodMask = m_gebsConfig.EuropeanLobster.CatchMethod;
    }
};



//Testing

// class geb_YieldMackerel : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();

// 		// autoptr TFloatArray gebCycle = m_gebsConfig.Mackerel.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "Mackerel";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
// 	}
// }

// class geb_YieldCarp : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
        
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Carp.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "Carp";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
// 	}
// }

// class geb_YieldSardines : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Sardines.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "Sardines";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
// 	}
// }

// class geb_YieldBitterlings : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Bitterlings.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "Bitterlings";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
// 	}
// }

// //---------//
// //cool new fish//
// //---------//
// class geb_YieldWalleyePollock : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.WalleyePollock.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "WalleyePollock";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
// 	}
// }

// class geb_YieldSteelheadTrout : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.SteelheadTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "SteelheadTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
// 	}
// }

// class geb_YieldShrimp : FishYieldItemBase
// {
// 	override void Init()
// 	{
// 		super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Shrimp.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "Shrimp";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
// 	}
// }


// //Saltwater
// class geb_YieldMahiMahi : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Mahimahi.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_MahiMahi";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldAtlanticSailFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Sailfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AtlanticSailFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldAngelFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Angelfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AngelFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldAsianSeaBass : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.AsianSeaBass.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AsianSeaBass";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldAtlanticBlueMarlin : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BlueMarlin.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AtlanticBlueMarlin";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBonita : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Bonita.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_Bonita";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldCherrySalmon : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.CherrySalmon.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_CherrySalmon";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldChinookSalmon : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.ChinookSalmon.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_ChinookSalmon";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSockEyeSalmon : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.SockeyeSalmon.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SockEyeSalmon";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };
                                           
// class geb_YieldFlatHeadMullet : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.FlatheadMullet.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_FlatHeadMullet";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldRedHeadCichlid : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.RedheadCichlid.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_RedHeadCichlid";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldRoughNeckRock : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.RoughneckRock.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_RoughNeckRock";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBlueTang : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BlueTang.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BlueTang";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldLargeHeadHairTailFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.HairtailFish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_LargeHeadHairTailFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldHumpHeadWrasse : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.HumpheadWrasse.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_HumpHeadWrasse";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSiameseTigerFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.SiameseTigerfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SiameseTigerFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldLeopardShark : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.LeopardShark.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_LeopardShark";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldPacificCod : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.PacificCod.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_PacificCod";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldGreatWhiteShark : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.GreatWhiteShark.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_GreatWhiteShark";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldAngelShark : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.AngelShark.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AngelShark";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldYellowFinTuna : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.YellowfinTuna.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_YellowFinTuna";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// //Freshwater
// class geb_YieldNorthernPike : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.NorthernPike.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_NorthernPike";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldLargeMouthBass : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.LargemouthBass.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_LargeMouthBass";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSmallMouthBass : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.SmallmouthBass.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SmallMouthBass";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldWallEye : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Walleye.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_WallEye";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSunFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Sunfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SunFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldWhiteBass : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.WhiteBass.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_WhiteBass";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSeverum : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Severum.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_Severum";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBlackBass : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BlackBass.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BlackBass";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldRainbowTrout : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.RainbowTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_RainbowTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBrownTrout : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BrownTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BrownTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBrookTrout : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BrookTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BrookTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldLakeTrout : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.LakeTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_LakeTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldCutThroatTrout : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.CutthroatTrout.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_CutThroatTrout";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldYellowPerch : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Perch.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_YellowPerch";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldFlatHeadCatFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Catfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_FlatHeadCatFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldFatHeadMinnow : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Minnow.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_FatHeadMinnow";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBlueGill : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Bluegill.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BlueGill";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSauger : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Sauger.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_Sauger";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldBowFin : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Bowfin.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BowFin";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// class geb_YieldSlimySculpin : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.SlimySculpin.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SlimySculpin";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
//     }
// };

// //Fishtraps
// class geb_YieldSignalCrayFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Crayfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SignalCrayFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
//     }
// };

// class geb_YieldEuropeanCrayFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Crayfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_EuropeanCrayFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };

// class geb_YieldBloodClam : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BloodClam.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BloodClam";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
//     }
// };

// class geb_YieldMussel : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Mussel.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_Mussel";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
//     }
// };

// class geb_YieldBlackDevilSnail : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BlackDevilSnail.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BlackDevilSnail";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
//     }
// };

// class geb_YieldStarFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Starfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_StarFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
//     }
// };

// class geb_YieldKingCrab : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.KingCrab.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_KingCrab";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };

// class geb_YieldSnowCrab : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.KingCrab.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_SnowCrab";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };

// class geb_YieldBlueJellyFish : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Jellyfish.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_BlueJellyFish";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };

// class geb_YieldAmericanLobster : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.Lobster.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_AmericanLobster";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };

// class geb_YieldEuropeanLobster : FishYieldItemBase
// {
//     override void Init()
//     {
//         super.Init();
		
//         // autoptr TFloatArray gebCycle = m_gebsConfig.BlueLobster.BiteSpeed;
//         // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
// 		m_QualityBase = 1;
// 		m_Type = "geb_EuropeanLobster";
// 		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
// 		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
//     }
// };