/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class YieldItemMackerel : FishYieldItemBase
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

modded class YieldItemCarp : FishYieldItemBase
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

modded class YieldItemSardines : FishYieldItemBase
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

modded class YieldItemBitterlings : FishYieldItemBase
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
modded class YieldItemWalleyePollock : FishYieldItemBase
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

modded class YieldItemSteelheadTrout : FishYieldItemBase
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

modded class YieldItemShrimp : FishYieldItemBase
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
class gebMahimahi : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Mahimahi.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Mahimahi";
		m_EnviroMask = m_gebsConfig.Mahimahi.Environment;
		m_MethodMask = m_gebsConfig.Mahimahi.CatchMethod;
    }
};

class gebSailfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sailfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Sailfish";
		m_EnviroMask = m_gebsConfig.Sailfish.Environment;
		m_MethodMask = m_gebsConfig.Sailfish.CatchMethod;
    }
};

class gebAngelfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Angelfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Angelfish";
		m_EnviroMask = m_gebsConfig.Angelfish.Environment;
		m_MethodMask = m_gebsConfig.Angelfish.CatchMethod;
    }
};

class gebAsianseabass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.AsianSeaBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Asianseabass";
		m_EnviroMask = m_gebsConfig.AsianSeaBass.Environment;
		m_MethodMask = m_gebsConfig.AsianSeaBass.CatchMethod;
    }
};

class gebBluemarlin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueMarlin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bluemarlin";
		m_EnviroMask = m_gebsConfig.BlueMarlin.Environment;
		m_MethodMask = m_gebsConfig.BlueMarlin.CatchMethod;
    }
};

class gebBonita : FishYieldItemBase
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

class gebCherrysalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.CherrySalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Cherrysalmon";
		m_EnviroMask = m_gebsConfig.CherrySalmon.Environment;
		m_MethodMask = m_gebsConfig.CherrySalmon.CatchMethod;
    }
};

class gebChinooksalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.ChinookSalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Chinooksalmon";
		m_EnviroMask = m_gebsConfig.ChinookSalmon.Environment;
		m_MethodMask = m_gebsConfig.ChinookSalmon.CatchMethod;
    }
};

class gebSockeyesalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SockeyeSalmon.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Sockeyesalmon";
		m_EnviroMask = m_gebsConfig.SockeyeSalmon.Environment;
		m_MethodMask = m_gebsConfig.SockeyeSalmon.CatchMethod;
    }
};
                                           
class gebFlatheadmullet : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.FlatheadMullet.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Flatheadmullet";
		m_EnviroMask = m_gebsConfig.FlatheadMullet.Environment;
		m_MethodMask = m_gebsConfig.FlatheadMullet.CatchMethod;
    }
};

class gebRedheadcichlid : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RedheadCichlid.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Redheadcichlid";
		m_EnviroMask = m_gebsConfig.RedheadCichlid.Environment;
		m_MethodMask = m_gebsConfig.RedheadCichlid.CatchMethod;
    }
};

class gebRoughneckrock : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RoughneckRock.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Roughneckrock";
		m_EnviroMask = m_gebsConfig.RoughneckRock.Environment;
		m_MethodMask = m_gebsConfig.RoughneckRock.CatchMethod;
    }
};

class gebBluetang : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueTang.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bluetang";
		m_EnviroMask = m_gebsConfig.BlueTang.Environment;
		m_MethodMask = m_gebsConfig.BlueTang.CatchMethod;
    }
};

class gebHairtailfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.HairtailFish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Hairtailfish";
		m_EnviroMask = m_gebsConfig.HairtailFish.Environment;
		m_MethodMask = m_gebsConfig.HairtailFish.CatchMethod;
    }
};

class gebHumpheadwrasse : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.HumpheadWrasse.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Humpheadwrasse";
		m_EnviroMask = m_gebsConfig.HumpheadWrasse.Environment;
		m_MethodMask = m_gebsConfig.HumpheadWrasse.CatchMethod;
    }
};

class gebSiamesetigerfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SiameseTigerfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Siamesetigerfish";
		m_EnviroMask = m_gebsConfig.SiameseTigerfish.Environment;
		m_MethodMask = m_gebsConfig.SiameseTigerfish.CatchMethod;
    }
};

class gebLeopardshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.LeopardShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Leopardshark";
		m_EnviroMask = m_gebsConfig.LeopardShark.Environment;
		m_MethodMask = m_gebsConfig.LeopardShark.CatchMethod;
    }
};

class gebPacificcod : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.PacificCod.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Pacificcod";
		m_EnviroMask = m_gebsConfig.PacificCod.Environment;
		m_MethodMask = m_gebsConfig.PacificCod.CatchMethod;
    }
};

class gebGreatwhiteshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.GreatWhiteShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Greatwhiteshark";
		m_EnviroMask = m_gebsConfig.GreatWhiteShark.Environment;
		m_MethodMask = m_gebsConfig.GreatWhiteShark.CatchMethod;
    }
};

class gebAngelshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.AngelShark.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Angelshark";
		m_EnviroMask = m_gebsConfig.AngelShark.Environment;
		m_MethodMask = m_gebsConfig.AngelShark.CatchMethod;
    }
};

class gebYellowfintuna : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.YellowfinTuna.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Yellowfintuna";
		m_EnviroMask = m_gebsConfig.YellowfinTuna.Environment;
		m_MethodMask = m_gebsConfig.YellowfinTuna.CatchMethod;
    }
};

//Freshwater
class gebNorthernpike : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.NorthernPike.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Northernpike";
		m_EnviroMask = m_gebsConfig.NorthernPike.Environment;
		m_MethodMask = m_gebsConfig.NorthernPike.CatchMethod;
    }
};

class gebLargemouthbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.LargemouthBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Largemouthbass";
		m_EnviroMask = m_gebsConfig.LargemouthBass.Environment;
		m_MethodMask = m_gebsConfig.LargemouthBass.CatchMethod;
    }
};

class gebSmallmouthbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SmallmouthBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Smallmouthbass";
		m_EnviroMask = m_gebsConfig.SmallmouthBass.Environment;
		m_MethodMask = m_gebsConfig.SmallmouthBass.CatchMethod;
    }
};

class gebWalleye : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Walleye.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Walleye";
		m_EnviroMask = m_gebsConfig.Walleye.Environment;
		m_MethodMask = m_gebsConfig.Walleye.CatchMethod;
    }
};

class gebSunfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Sunfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Sunfish";
		m_EnviroMask = m_gebsConfig.Sunfish.Environment;
		m_MethodMask = m_gebsConfig.Sunfish.CatchMethod;
    }
};

class gebWhitebass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.WhiteBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Whitebass";
		m_EnviroMask = m_gebsConfig.WhiteBass.Environment;
		m_MethodMask = m_gebsConfig.WhiteBass.CatchMethod;
    }
};

class gebSeverum : FishYieldItemBase
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

class gebBlackbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlackBass.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Blackbass";
		m_EnviroMask = m_gebsConfig.BlackBass.Environment;
		m_MethodMask = m_gebsConfig.BlackBass.CatchMethod;
    }
};

class gebRainbowTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.RainbowTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Trout";
		m_EnviroMask = m_gebsConfig.RainbowTrout.Environment;
		m_MethodMask = m_gebsConfig.RainbowTrout.CatchMethod;
    }
};

class gebBrownTrout : FishYieldItemBase
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

class gebBrookTrout : FishYieldItemBase
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

class gebLakeTrout : FishYieldItemBase
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

class gebCutthroatTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.CutthroatTrout.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_CutthroatTrout";
		m_EnviroMask = m_gebsConfig.CutthroatTrout.Environment;
		m_MethodMask = m_gebsConfig.CutthroatTrout.CatchMethod;
    }
};

class gebPerch : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Perch.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Perch";
		m_EnviroMask = m_gebsConfig.Perch.Environment;
		m_MethodMask = m_gebsConfig.Perch.CatchMethod;
    }
};

class gebCatfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Catfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Catfish";
		m_EnviroMask = m_gebsConfig.Catfish.Environment;
		m_MethodMask = m_gebsConfig.Catfish.CatchMethod;
    }
};

class gebMinnow : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Minnow.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Minnow";
		m_EnviroMask = m_gebsConfig.Minnow.Environment;
		m_MethodMask = m_gebsConfig.Minnow.CatchMethod;
    }
};

class gebBluegill : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bluegill.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bluegill";
		m_EnviroMask = m_gebsConfig.Bluegill.Environment;
		m_MethodMask = m_gebsConfig.Bluegill.CatchMethod;
    }
};

class gebSauger : FishYieldItemBase
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

class gebBowfin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Bowfin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bowfin";
		m_EnviroMask = m_gebsConfig.Bowfin.Environment;
		m_MethodMask = m_gebsConfig.Bowfin.CatchMethod;
    }
};

class gebSlimysculpin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.SlimySculpin.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Slimysculpin";
		m_EnviroMask = m_gebsConfig.SlimySculpin.Environment;
		m_MethodMask = m_gebsConfig.SlimySculpin.CatchMethod;
    }
};

//Fishtraps
class gebCrayfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Crayfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Crayfish";
		m_EnviroMask = m_gebsConfig.Crayfish.Environment;
		m_MethodMask = m_gebsConfig.Crayfish.CatchMethod;
    }
};

class gebBloodclam : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BloodClam.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Bloodclam";
		m_EnviroMask = m_gebsConfig.BloodClam.Environment;
		m_MethodMask = m_gebsConfig.BloodClam.CatchMethod;
    }
};

class gebMussel : FishYieldItemBase
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

class gebBlackdevilsnail : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlackDevilSnail.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Blackdevilsnail";
		m_EnviroMask = m_gebsConfig.BlackDevilSnail.Environment;
		m_MethodMask = m_gebsConfig.BlackDevilSnail.CatchMethod;
    }
};

class gebStarfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Starfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Starfish";
		m_EnviroMask = m_gebsConfig.Starfish.Environment;
		m_MethodMask = m_gebsConfig.Starfish.CatchMethod;
    }
};

class gebKingcrab : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.KingCrab.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Kingcrab";
		m_EnviroMask = m_gebsConfig.KingCrab.Environment;
		m_MethodMask = m_gebsConfig.KingCrab.CatchMethod;
    }
};

class gebJellyfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Jellyfish.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Jellyfish";
		m_EnviroMask = m_gebsConfig.Jellyfish.Environment;
		m_MethodMask = m_gebsConfig.Jellyfish.CatchMethod;
    }
};

class gebLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.Lobster.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_Lobster";
		m_EnviroMask = m_gebsConfig.Lobster.Environment;
		m_MethodMask = m_gebsConfig.Lobster.CatchMethod;
    }
};

class gebBlueLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
		
        // autoptr TFloatArray gebCycle = m_gebsConfig.BlueLobster.BiteSpeed;
        // m_HourlyCycleLengthCoefs = {gebCycle[0],gebCycle[1],gebCycle[2],gebCycle[3],gebCycle[4],gebCycle[5],gebCycle[6],gebCycle[7],gebCycle[8],gebCycle[9],gebCycle[10],gebCycle[11],gebCycle[12],gebCycle[13],gebCycle[14],gebCycle[15],gebCycle[16],gebCycle[17],gebCycle[18],gebCycle[19],gebCycle[20],gebCycle[21],gebCycle[22],gebCycle[23]};
		m_QualityBase = m_gebsConfig.GeneralSettings.FishQuality;
		m_Type = "geb_BlueLobster";
		m_EnviroMask = m_gebsConfig.BlueLobster.Environment;
		m_MethodMask = m_gebsConfig.BlueLobster.CatchMethod;
    }
};