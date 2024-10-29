/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

//Saltwater
class gebMahimahi : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Mahimahi";
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
        // Feeds during warm daylight hours (9 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 0/*6AM*/, 0/*7AM*/, 0/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebChinooksalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Chinooksalmon";
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSockeyesalmon : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Sockeyesalmon";
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active during early morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds mostly during daylight hours (6 AM - 6 PM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 0/*3AM*/, 0/*4AM*/, 0/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 0/*7PM*/, 0/*8PM*/, 0/*9PM*/, 0/*10PM*/, 0/*11PM*/, 0/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebSeverum : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Severum";
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_POND;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_ROD;
    }
};

class gebBlackbass : FishYieldItemBase
{
    override void Init()
    {
        super.Init();
        m_Type = "geb_Blackbass";
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day, most active in the morning and evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Nocturnal feeder, active mostly at night (3 AM - 10 AM, 9 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {0/*1AM*/, 0/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 0/*6PM*/, 0/*7PM*/, 0/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds all day (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds all day (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds early morning and late evening (1 AM - 10 AM, 6 PM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 0/*11AM*/, 0/*12PM*/, 0/*1PM*/, 0/*2PM*/, 0/*3PM*/, 0/*4PM*/, 0/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
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
        // Feeds throughout the day and night (1 AM - 12 AM)
        m_HourlyCycleLengthCoefs = {1/*1AM*/, 1/*2AM*/, 1/*3AM*/, 1/*4AM*/, 1/*5AM*/, 1/*6AM*/, 1/*7AM*/, 1/*8AM*/, 1/*9AM*/, 1/*10AM*/, 1/*11AM*/, 1/*12PM*/, 1/*1PM*/, 1/*2PM*/, 1/*3PM*/, 1/*4PM*/, 1/*5PM*/, 1/*6PM*/, 1/*7PM*/, 1/*8PM*/, 1/*9PM*/, 1/*10PM*/, 1/*11PM*/, 1/*12AM*/};
        m_EnviroMask = AnimalCatchingConstants.MASK_ENVIRO_SEA;
        m_MethodMask = AnimalCatchingConstants.MASK_METHOD_FISHTRAP_SMALL;
    }
};