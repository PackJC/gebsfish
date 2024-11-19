/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/
class YieldItemMackerel : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		//m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "Mackerel";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
	}
}

class YieldItemCarp : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		//m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "Carp";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
	}
}

class YieldItemSardines : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		//m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "Sardines";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
	}
}

class YieldItemBitterlings : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		//m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "Bitterlings";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
	}
}

//---------//
//cool new fish//
//---------//
class YieldItemWalleyePollock : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "WalleyePollock";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
	}
}

class YieldItemSteelheadTrout : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
		m_QualityBase = 1;
		m_Type = "SteelheadTrout";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
	}
}

class YieldItemShrimp : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_QualityBase = 1;
		m_Type = "Shrimp";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
	}
}


//Saltwater
class gebMahimahi : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Mahimahi";
        m_QualityBase = 1;
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};   
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSailfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sailfish";
        m_QualityBase = 1;
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebAngelfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Angelfish";
        m_QualityBase = 1;
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebAsianseabass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Asianseabass";
        m_QualityBase = 1;
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBluemarlin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluemarlin";
        m_QualityBase = 1;
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBonita : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bonita";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebCherrysalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Cherrysalmon";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebChinooksalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Chinooksalmon";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSockeyesalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sockeyesalmon";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};
                                           
class gebFlatheadmullet : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Flatheadmullet";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebRedheadcichlid : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Redheadcichlid";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebRoughneckrock : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Roughneckrock";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBluetang : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluetang";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebHairtailfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Hairtailfish";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebHumpheadwrasse : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Humpheadwrasse";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSiamesetigerfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Siamesetigerfish";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebLeopardshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Leopardshark";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebPacificcod : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Pacificcod";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebGreatwhiteshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Greatwhiteshark";
        m_QualityBase = 1;
        // Feeds early morning and late evening (3 AM - 10 AM, 9 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 0/*6PM*/, 0/*7PM*/, 0/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebAngelshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Angelshark";
        m_QualityBase = 1;
        // Feeds during night and early morning (1 AM - 10 AM, 9 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 0/*6PM*/, 0/*7PM*/, 0/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebYellowfintuna : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Yellowfintuna";
        m_QualityBase = 1;
        // Feeds early morning and evening (3 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

//Freshwater
class gebNorthernpike : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Northernpike";
        m_QualityBase = 1;
        // Feeds throughout the day, mostly active during daylight hours (6 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebLargemouthbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Largemouthbass";
        m_QualityBase = 1;
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSmallmouthbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Smallmouthbass";
        m_QualityBase = 1;
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebWalleye : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Walleye";
        m_QualityBase = 1;
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSunfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sunfish";
        m_QualityBase = 1;
        // Feeds mostly during daylight hours (6 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebWhitebass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Whitebass";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSeverum : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Severum";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBlackbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Blackbass";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebRainbowTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Trout";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBrownTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BrownTrout";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBrookTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BrookTrout";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebLakeTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_LakeTrout";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebCutthroatTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_CutthroatTrout";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebPerch : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Perch";
        m_QualityBase = 1;
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebCatfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Catfish";
        m_QualityBase = 1;
        // Nocturnal feeder, active mostly at night (3 AM - 10 AM, 9 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 0/*6PM*/, 0/*7PM*/, 0/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebMinnow : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Minnow";
        m_QualityBase = 1;
        // Feeds all day (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebBluegill : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluegill";
        m_QualityBase = 1;
        // Feeds all day (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSauger : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sauger";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebBowfin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bowfin";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

class gebSlimysculpin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Slimysculpin";
        m_QualityBase = 1;
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD|AnimalCatchingConstants.MASK_METHOD_FISHTRAP_LARGE;
    }
};

//Fishtraps
class gebCrayfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Crayfish";
        m_QualityBase = 1;
        // Feeds throughout the night and early morning (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebBloodclam : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bloodclam";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebMussel : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Mussel";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebBlackdevilsnail : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Blackdevilsnail";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebStarfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Starfish";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebKingcrab : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Kingcrab";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebJellyfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Jellyfish";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Lobster";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};

class gebBlueLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BlueLobster";
        m_QualityBase = 1;
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};