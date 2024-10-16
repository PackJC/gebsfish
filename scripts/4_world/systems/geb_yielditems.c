//Saltwater
class gebMahimahi : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Mahimahi";
        //caught during warm hours of the day - example
        m_HourlyCycleLengthCoefs = {0/*1AM*/,0/*2AM*/,0/*3AM*/,0/*4AM*/,0/*5AM*/,0/*6AM*/,0/*7AM*/,0/*8AM*/,1/*9AM*/,1/*10AM*/,1/*11AM*/,1/*12PM*/,1/*1PM*/,1/*2PM*/,1/*3PM*/,1/*4PM*/,1/*5PM*/,1/*6PM*/,1/*7PM*/,1/*8PM*/,0/*9PM*/,0/*10PM*/,0/*11PM*/,0/*12AM*/};
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
        m_HourlyCycleLengthCoefs = {0/*1AM*/,0/*2AM*/,0/*3AM*/,0/*4AM*/,0/*5AM*/,0/*6AM*/,0/*7AM*/,0/*8AM*/,1/*9AM*/,1/*10AM*/,1/*11AM*/,1/*12PM*/,1/*1PM*/,1/*2PM*/,1/*3PM*/,1/*4PM*/,1/*5PM*/,1/*6PM*/,1/*7PM*/,1/*8PM*/,0/*9PM*/,0/*10PM*/,0/*11PM*/,0/*12AM*/};
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
        m_HourlyCycleLengthCoefs = {0/*1AM*/,0/*2AM*/,0/*3AM*/,0/*4AM*/,0/*5AM*/,0/*6AM*/,0/*7AM*/,0/*8AM*/,1/*9AM*/,1/*10AM*/,1/*11AM*/,1/*12PM*/,1/*1PM*/,1/*2PM*/,1/*3PM*/,1/*4PM*/,1/*5PM*/,1/*6PM*/,1/*7PM*/,1/*8PM*/,0/*9PM*/,0/*10PM*/,0/*11PM*/,0/*12AM*/};
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
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBluemarlin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluemarlin";
        m_HourlyCycleLengthCoefs = {0/*1AM*/,0/*2AM*/,0/*3AM*/,0/*4AM*/,0/*5AM*/,0/*6AM*/,0/*7AM*/,0/*8AM*/,1/*9AM*/,1/*10AM*/,1/*11AM*/,1/*12PM*/,1/*1PM*/,1/*2PM*/,1/*3PM*/,1/*4PM*/,1/*5PM*/,1/*6PM*/,1/*7PM*/,1/*8PM*/,0/*9PM*/,0/*10PM*/,0/*11PM*/,0/*12AM*/};
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
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebCherrysalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Cherrysalmon";
        m_HourlyCycleLengthCoefs = {1/*1AM*/,1/*2AM*/,1/*3AM*/,1/*4AM*/,1/*5AM*/,1/*6AM*/,1/*7AM*/,1/*8AM*/,1/*9AM*/,1/*10AM*/,0/*11AM*/,0/*12PM*/,0/*1PM*/,0/*2PM*/,0/*3PM*/,0/*4PM*/,0/*5PM*/,1/*6PM*/,1/*7PM*/,1/*8PM*/,1/*9PM*/,1/*10PM*/,1/*11PM*/,1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebFlatheadmullet : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Flatheadmullet";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebLeopardshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Leopardshark";
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
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebRedheadcichlid : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Redheadcichlid";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebRoughneckrock : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Roughneckrock";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSeverum : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Severum";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebShrimp : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Shrimp";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBluetang : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluetang";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebHairtailfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Hairtailfish";
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
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSiamesetigerfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Siamesetigerfish";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBloodclam : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bloodclam";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebMussel : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Mussel";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBlackdevilsnail : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Blackdevilsnail";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebStarfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Starfish";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebKingcrab : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Kingcrab";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebJellyfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Jellyfish";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Lobster";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBlueLobster : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BlueLobster";
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebGreatwhiteshark : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Greatwhiteshark";
    	m_HourlyCycleLengthCoefs = {0,0,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,0,0,0,1,1,1,1};
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
        		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};

		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};
class gebSmallmouthbass : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		m_Type = "geb_Smallmouthbass";
        		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};

		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};
class gebWalleye : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		m_Type = "geb_Walleye";
        		m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};

		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};
class gebSunfish : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		m_Type = "geb_Sunfish";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};
class gebWhitebass : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		m_Type = "geb_Whitebass";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};
class gebRainbowTrout : FishYieldItemBase
{
	override void Init()
	{
		super.Init();

		m_Type = "geb_Trout";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
	}
};

class gebBrownTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BrownTrout";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBrookTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_BrookTrout";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebLakeTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_LakeTrout";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebCutthroatTrout : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_CutthroatTrout";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebPerch : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Perch";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebCatfish : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Catfish";
        m_HourlyCycleLengthCoefs = {0,0,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,0,0,0,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebMinnow : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Minnow";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBluegill : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bluegill";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,1,1,1/*12h*/,1,1,1,1,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSauger : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sauger";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBowfin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Bowfin";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSlimysculpin : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Slimysculpin";
        m_HourlyCycleLengthCoefs = {1,1,1,1,1,1,1,1,1,1,0,0,0/*12h*/,0,0,0,0,1,1,1,1,1,1,1};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};


//Fishtraps
class gebCrayfish : FishYieldItemBase
{
	override void Init()
	{
		super.Init();
		
		m_Type = "geb_Crayfish";
		m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
		m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
	}
};