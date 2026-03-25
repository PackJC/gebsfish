class gebsfishConfig
{
    // Current config version used to decide whether an existing JSON file is still compatible.
    static const string CONFIG_VERSION = VERSION_GEBSFISH;

    // Config folder / file naming.
    private const static string ModFolder = "$profile:\\Gebs\\";
    private const static string FileName = "fishingsettings";
    private const static string FileType = ".json";

    // Main config sections saved to JSON.
    string ConfigVersion = "";
    ref GenSetConf GeneralSettings;
    ref PredatorConf PredatorSettings;
    ref LogConf CFToolsLogging;
    ref array<ref PredatorEntry> Predators;
    ref array<ref BugEntry> Bugs;
    ref array<ref FishEntry> Fish;
    ref array<ref JunkEntry> Junk;
    ref array<ref ContainerJunkEntry> ContainerJunk;

    void gebsfishConfig()
    {
        // Intentionally empty.
        // Initialization is done explicitly so load / reset flow stays predictable.
    }

    protected string GetConfigPath()
    {
        return ModFolder + FileName + FileType;
    }

    protected string GetBackupPath()
    {
        return ModFolder + FileName + "_old" + FileType;
    }

    void Load()
    {
        if (!g_Game.IsDedicatedServer())
            return;

        string path = GetConfigPath();

        if (FileExist(path))
        {
            JsonFileLoader<gebsfishConfig>.JsonLoadFile(path, this);
            GebsfishLogger.Info("Found settings file; loading gebsfish settings from file.", "JSON");

            if (ConfigVersion == CONFIG_VERSION)
                return;

            JsonFileLoader<gebsfishConfig>.JsonSaveFile(GetBackupPath(), this);
            GebsfishLogger.Info("New config version found for mod; backing up old file and generating new config file.", "JSON");
        }

        GebsfishLogger.Info("Generating settings file.", "JSON");
        InitializeDefaults();
        Save();
    }

    protected void InitializeBaseObjects()
    {
        GeneralSettings = new GenSetConf;
        CFToolsLogging = new LogConf;
        PredatorSettings = new PredatorConf;

        Predators = new array<ref PredatorEntry>();
        Bugs = new array<ref BugEntry>();
        Fish = new array<ref FishEntry>();
        Junk = new array<ref JunkEntry>();
        ContainerJunk = new array<ref ContainerJunkEntry>();
    }

    protected void InitializeDefaults()
    {
        ConfigVersion = CONFIG_VERSION;
        InitializeBaseObjects();
        InitializeFishConfigs();
        InitializeDefaultBugs();
        InitializeDefaultPredators();
        InitializeDefaultJunk();
    }

    protected void InitializeDefaultBugs()
    {
        AddBug("geb_FieldCricket", 0.25);
        AddBug("geb_GrassHopper", 0.25);
        AddBug("geb_GrubWorm", 0.75);
        AddBug("Worm", 0.25);
    }

    protected void InitializeDefaultPredators()
    {
        AddPredator("Animal_CanisLupus_Grey", 0.6, 1, 3, 50, 200);
        AddPredator("Animal_UrsusArctos", 0.3, 1, 1, 100, 300);
    }

    protected void InitializeDefaultJunk()
    {
        AddJunk("Wellies_Brown", 5);
        AddJunk("Wellies_Grey", 5);
        AddJunk("Wellies_Green", 5);
        AddJunk("Wellies_Black", 5);
        AddContainerJunk("Pot", 5);
    }

    protected void InitializeFishConfigs()
    {
        // AddFish(classname, environment, catchMethod, meatMin, meatMax, catchProbability)
        // FRESHWATER - FISH
        AddFish("Carp", 1, 3, 1, 2, 15);
        AddFish("Bitterlings", 1, 6, 0, 0, 15);
        AddFish("NorthernPike", 1, 1, 2, 4, 15);
        AddFish("LargeMouthBass", 1, 3, 1, 2, 15);
        AddFish("SmallMouthBass", 1, 3, 1, 2, 15);
        AddFish("WallEye", 1, 3, 1, 2, 15);
        AddFish("SunFish", 1, 3, 1, 2, 15);
        AddFish("WhiteBass", 1, 3, 1, 2, 15);
        AddFish("BlackBass", 1, 3, 1, 2, 15);
        AddFish("RainbowTrout", 1, 3, 1, 2, 15);
        AddFish("BrownTrout", 1, 3, 1, 2, 15);
        AddFish("BrookTrout", 1, 3, 1, 2, 15);
        AddFish("LakeTrout", 1, 3, 1, 2, 15);
        AddFish("CutThroatTrout", 1, 3, 1, 2, 15);
        AddFish("Sturgeon", 1, 3, 1, 2, 15);
        AddFish("YellowPerch", 1, 3, 1, 2, 15);
        AddFish("FlatHeadCatFish", 1, 3, 1, 4, 15);
        AddFish("FatHeadMinnow", 1, 5, 1, 2, 15);
        AddFish("BlueGill", 1, 3, 1, 2, 15);
        AddFish("Sauger", 1, 3, 1, 2, 15);
        AddFish("BowFin", 1, 3, 1, 2, 15);
        AddFish("SlimySculpin", 1, 3, 1, 2, 15);
        AddFish("Severum", 1, 3, 1, 2, 15);

        // FRESHWATER - CRUSTACEANS / INVERTEBRATES
        AddFish("SignalCrayFish", 1, 4, 1, 2, 15);
        AddFish("EuropeanCrayFish", 1, 4, 1, 2, 15);

        // SALTWATER - FISH
        AddFish("Mackerel", 2, 3, 1, 2, 15);
        AddFish("Sardines", 2, 6, 0, 0, 15);
        AddFish("WalleyePollock", 2, 3, 1, 2, 24);
        AddFish("SteelheadTrout", 2, 3, 1, 2, 12);
        AddFish("MahiMahi", 2, 1, 3, 7, 15);
        AddFish("AtlanticSailFish", 2, 1, 4, 7, 15);
        AddFish("AngelFish", 2, 1, 1, 2, 15);
        AddFish("AsianSeaBass", 2, 3, 2, 4, 15);
        AddFish("AtlanticBlueMarlin", 2, 1, 3, 6, 15);
        AddFish("Bonita", 2, 3, 1, 2, 15);
        AddFish("CherrySalmon", 2, 3, 1, 2, 15);
        AddFish("ChinookSalmon", 2, 3, 1, 2, 15);
        AddFish("SockEyeSalmon", 2, 3, 1, 2, 15);
        AddFish("FlatHeadMullet", 2, 3, 1, 2, 15);
        AddFish("LeopardShark", 2, 1, 2, 4, 15);
        AddFish("HammerHeadShark", 2, 1, 2, 4, 15);
        AddFish("PacificCod", 2, 3, 1, 2, 15);
        AddFish("RedHeadCichlid", 2, 3, 1, 2, 15);
        AddFish("RoughNeckRock", 2, 3, 1, 2, 15);
        AddFish("BlueTang", 2, 3, 1, 2, 15);
        AddFish("LargeHeadHairTailFish", 2, 3, 3, 5, 15);
        AddFish("HumpHeadWrasse", 2, 3, 3, 5, 15);
        AddFish("SiameseTigerFish", 2, 3, 3, 6, 15);
        AddFish("GreatWhiteShark", 2, 1, 5, 10, 15);
        AddFish("AngelShark", 2, 1, 3, 8, 15);
        AddFish("YellowFinTuna", 2, 1, 2, 6, 15);

        // SALTWATER - CRUSTACEANS / INVERTEBRATES
        AddFish("Shrimp", 2, 6, 0, 0, 1);
        AddFish("BloodClam", 2, 4, 0, 0, 15);
        AddFish("Mussel", 2, 6, 0, 0, 15);
        AddFish("BlackDevilSnail", 2, 6, 0, 0, 15);
        AddFish("StarFish", 2, 6, 0, 0, 15);
        AddFish("KingCrab", 2, 6, 1, 2, 15);
        AddFish("SnowCrab", 2, 6, 1, 2, 15);
        AddFish("BlueJellyFish", 2, 6, 1, 2, 15);
        AddFish("AmericanLobster", 2, 6, 1, 2, 15);
        AddFish("EuropeanLobster", 2, 6, 1, 2, 15);
    }

    protected void AddBug(string classname, float catchChance)
    {
        BugEntry bug = new BugEntry();
        bug.Classname = classname;
        bug.CatchChance = catchChance;
        Bugs.Insert(bug);
    }

    protected void AddPredator(string classname, float spawnChance, int minCount, int maxCount, float minRadius, float maxRadius)
    {
        PredatorEntry predator = new PredatorEntry();
        predator.Classname = classname;
        predator.SpawnChance = spawnChance;
        predator.MinCount = minCount;
        predator.MaxCount = maxCount;
        predator.MinRadius = minRadius;
        predator.MaxRadius = maxRadius;
        Predators.Insert(predator);
    }

    protected void AddJunk(string classname, int catchProbability)
    {
        JunkEntry junkEntry = new JunkEntry();
        junkEntry.Classname = classname;
        junkEntry.CatchProbability = catchProbability;
        Junk.Insert(junkEntry);
    }

    protected void AddContainerJunk(string classname, int catchProbability)
    {
        ContainerJunkEntry junkEntry = new ContainerJunkEntry();
        junkEntry.Classname = classname;
        junkEntry.CatchProbability = catchProbability;
        ContainerJunk.Insert(junkEntry);
    }

    protected void AddFish(string classname, int environment, int catchMethod, int meatMin, int meatMax, int catchProbability)
    {
        if (classname == string.Empty)
        {
            GebsfishLogger.Error("AddFish called with empty classname.", "JSON");
            return;
        }

        if (environment < 1 || environment > 3)
        {
            GebsfishLogger.Error("Invalid environment for fish classname: " + classname, "JSON");
            return;
        }

        if (catchMethod < 1 || catchMethod > 7)
        {
            GebsfishLogger.Error("Invalid catch method for fish classname: " + classname, "JSON");
            return;
        }

        if (meatMin < 0 || meatMax < 0 || meatMin > meatMax || meatMax > 10)
        {
            GebsfishLogger.Error("Invalid meat settings for fish classname: " + classname, "JSON");
            return;
        }

        if (catchProbability < 0 || catchProbability > 25)
        {
            GebsfishLogger.Error("Invalid catch probability for fish classname: " + classname, "JSON");
            return;
        }

        FishEntry fishEntry = new FishEntry();
        fishEntry.Classname = classname;
        fishEntry.Environment = environment;
        fishEntry.CatchMethod = catchMethod;
        fishEntry.MeatMin = meatMin;
        fishEntry.MeatMax = meatMax;
        fishEntry.CatchProbability = catchProbability;
        Fish.Insert(fishEntry);
    }

    FishEntry GetFishByClassname(string classname)
    {
        foreach (FishEntry fishEntry : Fish)
        {
            if (fishEntry.Classname == classname)
                return fishEntry;
        }

        return null;
    }

    void Save()
    {
        if (!FileExist(ModFolder))
        {
            MakeDirectory(ModFolder);
        }

        JsonFileLoader<gebsfishConfig>.JsonSaveFile(GetConfigPath(), this);
        GebsfishLogger.Info("Settings file generation complete.", "JSON");
    }
}

// General settings config data.
class GenSetConf
{
    string DebugInfo = "Turns debug mode on to print extra logs to the script.log file.";
    int DebugLogs = 0;

    string FishQualityInfo = "Sets the base value for the fish quantity bar.";
    float FishQuality = 1;
};

// CFTools logging config data.
class LogConf
{
    string LoggingInfo = "Requires the ExtraLogs mod by TRG to use this section.";
    bool CatchLogs = false;
    bool PredatorSpawn = false;
    bool PredatorSounds = false;
};

// Predator feature config data.
class PredatorConf
{
    string PredatorSpawnEnabledInfo = "Turns on(true) and off(false) the predators feature of the mod. When on, it enables random predator spawning when catching or cutting up fish.";
    bool PredatorSpawnEnabled = true;

    string PredatorSpawnChanceInfo = "Chance for a predator to spawn when a fish is caught or cut up. Fishing is while fishing, preparing is while filleting, failcatch is when nothing is caught.";
    float PredatorSpawnChanceFishing = 0.25;
    float PredatorSpawnChancePreparing = 0.25;
    float PredatorSpawnChanceFailCatch = 0.01;

    string PredatorSpawnSoundInfo = "PredatorWarningSoundEnable controls the audible notification and PredatorWarningSoundRadius controls how far players hear the sound from the triggering player.";
    bool PredatorWarningSoundEnable = true;
    int PredatorWarningSoundRadius = 50;

    string PredatorWarningMessageInfo = "PredatorWarningMessageEnable turns the chat message on and off. Only set one message color to true at a time.";
    bool PredatorWarningMessageEnable = true;
    bool PredatorWarningMessageGreen = false;
    bool PredatorWarningMessageRed = false;
    bool PredatorWarningMessageYellow = true;
    bool PredatorWarningMessageGrey = false;
};

class PredatorEntry
{
    string Classname;   // Predator classname.
    float SpawnChance;  // Spawn percentage chance.
    int MinCount;       // Minimum predator count to spawn.
    int MaxCount;       // Maximum predator count to spawn.
    float MinRadius;    // Minimum spawn radius from player.
    float MaxRadius;    // Maximum spawn radius from player.
};

// Bug config data.
class BugEntry
{
    string Classname;   // Bug classname used as bait / catch source.
    float CatchChance;  // Chance to catch this bug.
};

// Fish config data.
class FishEntry
{
    // Actual DayZ classname for this fish.
    // This is also the identifier you use when looking fish up in code.
    string Classname;

    // 1 = pond, 2 = sea, 3 = both.
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;

    // 1 = rod
    // 2 = largetrap
    // 3 = rod and largetrap
    // 4 = smalltrap
    // 5 = rod and smalltrap
    // 6 = largetrap and smalltrap
    // 7 = rod, largetrap and smalltrap
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;

    // MeatMin / MeatMax determine fillet yield when the fish is prepared.
    // DayZ hard limit is 10 fillets max.
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 0;
    int MeatMax = 0;

    // 0-25 scale where 0 = no chance and 25 = very common.
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
};

// Junk config data.
class JunkEntry
{
    string ClassnameInfo = "Any classname for a junk item that is not a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
};

class ContainerJunkEntry
{
    string ClassnameInfo = "Any classname for a junk item that is a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
};

// Saved config instance.
ref gebsfishConfig m_gebsConfig;

// Helper function to return config data storage object.
static gebsfishConfig GetGebSettingsConfig()
{
    if (!m_gebsConfig)
    {
        GebsfishLogger.Info("Initializing gebsfish.", "JSON");
        GebsfishLogger.Info("Loading JSON config file.", "JSON");

        m_gebsConfig = new gebsfishConfig;

        // Only load JSON config on the server.
        if (g_Game.IsServer())
        {
            m_gebsConfig.Load();
        }
        else
        {
            m_gebsConfig.InitializeBaseObjects();
        }
    }

    return m_gebsConfig;
}

static void SetGebsfishConfig(gebsfishConfig config)
{
    GebsfishLogger.Info("Setting config settings from server config file.", "JSON");
    m_gebsConfig = config;
}

// Prevent double printing in log file since it loads the yield data twice.
bool gebsMissionLoaded = false;
