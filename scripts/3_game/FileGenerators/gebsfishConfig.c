class gebsfishConfig {
    
    //Define Config Version
    static const string CONFIG_VERSION = VERSION_GEBSFISH;

    //config location
    private const static string ModFolder = "$profile:\\Gebs\\";
    private const static string SettingsConfigFile = "fishingsettings.json";
    private const static string FileName = "fishingsettings";
    private const static string FileType = ".json";

    //Config Reference 
    string ConfigVersion = "";
    ref GenSetConf GeneralSettings;
    ref RecipeToggleConf RecipeToggles;
    ref PredatorConf PredatorSettings;
    ref WeatherConf WeatherSettings;
    ref ForageConf ForageSettings;
    ref LogConf CFToolsLogging;
    ref array<ref PredatorEntry> Predators;
    // Used by ActionDigBugs, the bug catcher / catch-bugs action.
    ref array<ref BugEntry> Bugs;
    // Used by ActionDigWorms, the normal dig-worms action.
    ref array<ref BugEntry> DigWorms;
    // Used by ActionBambooFishingNet, the in-water minnow / frog / salamander net.
    ref array<ref BugEntry> NetItems;
    ref MackerelConf Mackerel;
    ref CarpConf Carp;
    ref SardinesConf Sardines;
    ref BitterlingsConf Bitterlings;
    ref WalleyePollockConf WalleyePollock;
    ref SteelheadTroutConf SteelheadTrout;
    ref ShrimpConf Shrimp;
    ref NorthernSnakeHeadConf NorthernSnakeHead;
    ref NorthernPikeConf NorthernPike;
    ref BarredMuskellungeConf BarredMuskellunge;
    ref SpottedMuskellungeConf SpottedMuskellunge;
    ref TigerMuskellungeConf TigerMuskellunge;
    ref MuskellungeConf Muskellunge;
    ref AlligatorGarConf AlligatorGar;
    ref LargeMouthBassConf LargeMouthBass;
    ref SmallMouthBassConf SmallMouthBass;
    ref WallEyeConf WallEye;
    ref SunFishConf SunFish;
    ref WhiteBassConf WhiteBass;
    ref StripedBassConf StripedBass;
    ref NeoshoBassConf NeoshoBass;
    ref BlackBassConf BlackBass;
    ref RainbowTroutConf RainbowTrout;
    ref BrownTroutConf BrownTrout;
    ref BrookTroutConf BrookTrout;
    ref LakeTroutConf LakeTrout;
    ref CutThroatTroutConf CutThroatTrout;
    ref LakeSturgeonConf LakeSturgeon;
    ref YellowPerchConf YellowPerch;
    ref FlatHeadCatFishConf FlatHeadCatFish;
    ref FatHeadMinnowConf FatHeadMinnow;
    ref AmericanBullFrogConf AmericanBullFrog;
    ref RedSalamanderConf RedSalamander;
    ref BlueGillConf BlueGill;
    ref SaugerConf Sauger;
    ref BowFinConf BowFin;
    ref SlimySculpinConf SlimySculpin;
    ref SeverumConf Severum;
    ref SignalCrayFishConf SignalCrayFish;
    ref EuropeanCrayFishConf EuropeanCrayFish;
    ref FloridaCrayFishConf FloridaCrayFish;
    ref CaveCrayFishConf CaveCrayFish;
    ref MonongahelaCrayFishConf MonongahelaCrayFish;
    ref RedSwampCrayFishConf RedSwampCrayFish;
    ref RustyCrayFishConf RustyCrayFish;
    ref MahiMahiConf MahiMahi;
    ref AtlanticSailFishConf AtlanticSailFish;
    ref AngelFishConf AngelFish;
    ref AsianSeaBassConf AsianSeaBass;
    ref AtlanticBlueMarlinConf AtlanticBlueMarlin;
    ref BonitaConf Bonita;
    ref CherrySalmonConf CherrySalmon;
    ref ChinookSalmonConf ChinookSalmon;
    ref SockEyeSalmonConf SockEyeSalmon;
    ref FlatHeadMulletConf FlatHeadMullet;
    ref LeopardSharkConf LeopardShark;
    ref HammerHeadSharkConf HammerHeadShark;
    ref PacificCodConf PacificCod;
    ref RedHeadCichlidConf RedHeadCichlid;
    ref RoughNeckRockConf RoughNeckRock;
    ref BlueTangConf BlueTang;
    ref LargeHeadHairTailFishConf LargeHeadHairTailFish;
    ref HumpHeadWrasseConf HumpHeadWrasse;
    ref SiameseTigerFishConf SiameseTigerFish;
    ref GreatWhiteSharkConf GreatWhiteShark;
    ref AngelSharkConf AngelShark;
    ref YellowFinTunaConf YellowFinTuna;
    ref WhiteGruntConf WhiteGrunt;
    ref SouthernFlounderConf SouthernFlounder;
    ref YellowSnapperConf YellowSnapper;
    ref BloodClamConf BloodClam;
    ref MusselConf Mussel;
    ref BlackDevilSnailConf BlackDevilSnail;
    ref StarFishConf StarFish;
    ref KingCrabConf KingCrab;
    ref SnowCrabConf SnowCrab;
    ref BlueJellyFishConf BlueJellyFish;
    ref AmericanLobsterConf AmericanLobster;
    ref EuropeanLobsterConf EuropeanLobster;

    ref array<ref JunkEntry> Junk;
    ref array<ref ContainerJunkEntry> ContainerJunk;

    void Load() {
        if (g_Game.IsDedicatedServer()) {
            if (FileExist(ModFolder + SettingsConfigFile)) {
                //If config exists, load file
                JsonFileLoader<gebsfishConfig>.JsonLoadFile(ModFolder + SettingsConfigFile, this);
                GebsfishLogger.Info("Found settings file; Loading gebsfish settings from file.", "JSON");
                
                // If version mismatch, backup old version of json before replacing it
                if (ConfigVersion != CONFIG_VERSION){
                    JsonFileLoader<gebsfishConfig>.JsonSaveFile(ModFolder + FileName + "_old" + FileType, this);
                    
                    GebsfishLogger.Info("New config version found for mod; Backing up old file and saving as " + ModFolder + FileName + "_old" + FileType + " and generating new config file.", "JSON");
                }
                else {
                    // Config exists and version matches, but older manually edited files can
                    // still be missing shared settings sections. Fill those missing refs and
                    // save so new options such as CaviarChance appear in the JSON.
                    EnsureMissingConfigSections();
                    Save();
                    return;
                }
            }
        GebsfishLogger.Info("Generating settings file.", "JSON");

        //Save config file version to file
        ConfigVersion = CONFIG_VERSION;
        //Save general settings to file
        GeneralSettings = new GenSetConf;
        RecipeToggles = new RecipeToggleConf;
        //Save CF Tools logging settings to file
        CFToolsLogging = new LogConf;
        //Save predator config data to the file
        PredatorSettings = new PredatorConf;
        // Weather catch buff settings. Per-species multipliers live inline
        // on each FishConf class (Rain/Storm/NightMultiplier).
        WeatherSettings = new WeatherConf;
        // Forage settings (find chance per dig/net attempt).
        ForageSettings = new ForageConf;
        Predators = new array<ref PredatorEntry>();
        // Bug catcher / catch-bugs action spawn table.
        Bugs = new array<ref BugEntry>();
        // Normal dig-worms action spawn table.
        DigWorms = new array<ref BugEntry>();
        // Bamboo fishing net spawn table.
        NetItems = new array<ref BugEntry>();
        //Save fish config data to file

        Mackerel = new MackerelConf;
        Carp = new CarpConf;
        Sardines = new SardinesConf;
        Bitterlings = new BitterlingsConf;
        WalleyePollock = new WalleyePollockConf;
        SteelheadTrout = new SteelheadTroutConf;
        Shrimp = new ShrimpConf;
        NorthernSnakeHead = new NorthernSnakeHeadConf;
        NorthernPike = new NorthernPikeConf;
        BarredMuskellunge = new BarredMuskellungeConf;
        SpottedMuskellunge = new SpottedMuskellungeConf;
        TigerMuskellunge = new TigerMuskellungeConf;
        Muskellunge = new MuskellungeConf;
        AlligatorGar = new AlligatorGarConf;
        LargeMouthBass = new LargeMouthBassConf;
        SmallMouthBass = new SmallMouthBassConf;
        WallEye = new WallEyeConf;
        SunFish = new SunFishConf;
        WhiteBass = new WhiteBassConf;
        StripedBass = new StripedBassConf;
        NeoshoBass = new NeoshoBassConf;
        BlackBass = new BlackBassConf;
        RainbowTrout = new RainbowTroutConf;
        BrownTrout = new BrownTroutConf;
        BrookTrout = new BrookTroutConf;
        LakeTrout = new LakeTroutConf;
        CutThroatTrout = new CutThroatTroutConf;
        LakeSturgeon = new LakeSturgeonConf;
        YellowPerch = new YellowPerchConf;
        FlatHeadCatFish = new FlatHeadCatFishConf;
        FatHeadMinnow = new FatHeadMinnowConf;
        AmericanBullFrog = new AmericanBullFrogConf;
        RedSalamander = new RedSalamanderConf;
        BlueGill = new BlueGillConf;
        Sauger = new SaugerConf;
        BowFin = new BowFinConf;
        SlimySculpin = new SlimySculpinConf;
        Severum = new SeverumConf;
        SignalCrayFish = new SignalCrayFishConf;
        EuropeanCrayFish = new EuropeanCrayFishConf;
        CaveCrayFish = new CaveCrayFishConf;
        FloridaCrayFish = new FloridaCrayFishConf;
        MonongahelaCrayFish = new MonongahelaCrayFishConf;
        RedSwampCrayFish = new RedSwampCrayFishConf;
        RustyCrayFish = new RustyCrayFishConf;
        MahiMahi = new MahiMahiConf;
        AtlanticSailFish = new AtlanticSailFishConf;
        AngelFish = new AngelFishConf;
        AsianSeaBass = new AsianSeaBassConf;
        AtlanticBlueMarlin = new AtlanticBlueMarlinConf;
        Bonita = new BonitaConf;
        CherrySalmon = new CherrySalmonConf;
        ChinookSalmon = new ChinookSalmonConf;
        SockEyeSalmon = new SockEyeSalmonConf;
        FlatHeadMullet = new FlatHeadMulletConf;
        LeopardShark = new LeopardSharkConf;
        HammerHeadShark = new HammerHeadSharkConf;
        PacificCod = new PacificCodConf;
        RedHeadCichlid = new RedHeadCichlidConf;
        RoughNeckRock = new RoughNeckRockConf;
        BlueTang = new BlueTangConf;
        LargeHeadHairTailFish = new LargeHeadHairTailFishConf;
        HumpHeadWrasse = new HumpHeadWrasseConf;
        SiameseTigerFish = new SiameseTigerFishConf;
        GreatWhiteShark = new GreatWhiteSharkConf;
        AngelShark = new AngelSharkConf;
        YellowFinTuna = new YellowFinTunaConf;
        WhiteGrunt = new WhiteGruntConf;
        SouthernFlounder = new SouthernFlounderConf;
        YellowSnapper = new YellowSnapperConf;
        BloodClam = new BloodClamConf;
        Mussel = new MusselConf;
        BlackDevilSnail = new BlackDevilSnailConf;
        StarFish = new StarFishConf;
        KingCrab = new KingCrabConf;
        SnowCrab = new SnowCrabConf;
        BlueJellyFish = new BlueJellyFishConf;
        AmericanLobster = new AmericanLobsterConf;
        EuropeanLobster = new EuropeanLobsterConf;

        Junk = new array<ref JunkEntry>();
        ContainerJunk = new array<ref ContainerJunkEntry>();

        // Add default bug catcher / catch-bugs data to file.

        BugEntry FieldCricket = new BugEntry();
        FieldCricket.Classname = "geb_FieldCricket";
        FieldCricket.CatchChance = 0.25;

        BugEntry GrassHopper = new BugEntry();
        GrassHopper.Classname = "geb_GrassHopper";
        GrassHopper.CatchChance = 0.25;

        BugEntry GrubWorm = new BugEntry();
        GrubWorm.Classname = "geb_GrubWorm";
        GrubWorm.CatchChance = 0.75;

        BugEntry Worm = new BugEntry();
        Worm.Classname = "Worm";
        Worm.CatchChance = 0.25;

        Bugs.Insert(FieldCricket);
        Bugs.Insert(GrassHopper);
        Bugs.Insert(GrubWorm);
        Bugs.Insert(Worm);

        // Add default normal dig-worms data to file.
        BugEntry DigWorm = new BugEntry();
        DigWorm.Classname = "Worm";
        DigWorm.CatchChance = 0.75;

        BugEntry DigGrubWorm = new BugEntry();
        DigGrubWorm.Classname = "geb_GrubWorm";
        DigGrubWorm.CatchChance = 0.25;

        DigWorms.Insert(DigWorm);
        DigWorms.Insert(DigGrubWorm);

        // Add default bamboo-fishing-net spawn table. Matches the previously
        // hardcoded behaviour (equal chance minnow / frog / salamander) but is
        // now editable by server admins.
        BugEntry NetMinnow = new BugEntry();
        NetMinnow.Classname = "geb_FatHeadMinnow";
        NetMinnow.CatchChance = 1.0;

        BugEntry NetBullFrog = new BugEntry();
        NetBullFrog.Classname = "geb_AmericanBullFrog";
        NetBullFrog.CatchChance = 1.0;

        BugEntry NetSalamander = new BugEntry();
        NetSalamander.Classname = "geb_RedSalamander";
        NetSalamander.CatchChance = 1.0;

        NetItems.Insert(NetMinnow);
        NetItems.Insert(NetBullFrog);
        NetItems.Insert(NetSalamander);

        //Add default predator data to file

        PredatorEntry Wolf = new PredatorEntry();
        Wolf.Classname = "Animal_CanisLupus_Grey";
        Wolf.SpawnChance = 0.6;
        Wolf.MinCount = 1;
        Wolf.MaxCount = 3;
        Wolf.MinRadius = 50;
        Wolf.MaxRadius = 200;

        PredatorEntry Bear = new PredatorEntry();
        Bear.Classname = "Animal_UrsusArctos";
        Bear.SpawnChance = 0.3;
        Bear.MinCount = 1;
        Bear.MaxCount = 1;
        Bear.MinRadius = 100;
        Bear.MaxRadius = 300;

        Predators.Insert(Wolf);
        Predators.Insert(Bear);

        JunkEntry Wellies_Brown = new JunkEntry();
        Wellies_Brown.Classname = "Wellies_Brown";
        Wellies_Brown.CatchProbability = 5;
        Wellies_Brown.MinHealthLevel = 3;
        Wellies_Brown.MaxHealthLevel = 3;

        JunkEntry Wellies_Grey = new JunkEntry();
        Wellies_Grey.Classname = "Wellies_Grey";
        Wellies_Grey.CatchProbability = 5;
        Wellies_Grey.MinHealthLevel = 3;
        Wellies_Grey.MaxHealthLevel = 3;

        JunkEntry Wellies_Green = new JunkEntry();
        Wellies_Green.Classname = "Wellies_Green";
        Wellies_Green.CatchProbability = 5;
        Wellies_Green.MinHealthLevel = 3;
        Wellies_Green.MaxHealthLevel = 3;

        JunkEntry Wellies_Black = new JunkEntry();
        Wellies_Black.Classname = "Wellies_Black";
        Wellies_Black.CatchProbability = 5;
        Wellies_Black.MinHealthLevel = 3;
        Wellies_Black.MaxHealthLevel = 3;

        Junk.Insert(Wellies_Brown);
        Junk.Insert(Wellies_Grey);
        Junk.Insert(Wellies_Green);
        Junk.Insert(Wellies_Black);

        ContainerJunkEntry Pot = new ContainerJunkEntry();
        Pot.Classname = "Pot";
        Pot.CatchProbability = 5;
        Pot.MinHealthLevel = 3;
        Pot.MaxHealthLevel = 3;

        ContainerJunk.Insert(Pot);

        //Save it
        Save();
        }
    }
    void Save() {
        if (!FileExist(ModFolder)) {
            //if config folder doesn't exist, create it.
            MakeDirectory(ModFolder);
        }
        //Save JSON Config
        JsonFileLoader<gebsfishConfig>.JsonSaveFile(ModFolder + SettingsConfigFile, this);
        GebsfishLogger.Info("Settings file generation complete", "JSON");

    }

    void EnsureMissingConfigSections() {
        // These guards keep old or hand-edited JSON files from crashing shared
        // settings, predator logic, bug digging, and junk registration.
        // Existing values are preserved; only missing object/array refs are created.
        if (!GeneralSettings) GeneralSettings = new GenSetConf;
        if (!RecipeToggles) RecipeToggles = new RecipeToggleConf;
        if (!CFToolsLogging) CFToolsLogging = new LogConf;
        if (!PredatorSettings) PredatorSettings = new PredatorConf;
        if (!WeatherSettings) WeatherSettings = new WeatherConf;
        // Per-species multipliers now live on each FishConf class (Rain/Storm/
        // NightMultiplier), so nothing extra to seed here.
        if (!ForageSettings) ForageSettings = new ForageConf;
        // NetItems is for ActionBambooFishingNet, the bamboo fishing net.
        if (!NetItems) {
            NetItems = new array<ref BugEntry>();

            BugEntry NetMinnow = new BugEntry();
            NetMinnow.Classname = "geb_FatHeadMinnow";
            NetMinnow.CatchChance = 1.0;

            BugEntry NetBullFrog = new BugEntry();
            NetBullFrog.Classname = "geb_AmericanBullFrog";
            NetBullFrog.CatchChance = 1.0;

            BugEntry NetSalamander = new BugEntry();
            NetSalamander.Classname = "geb_RedSalamander";
            NetSalamander.CatchChance = 1.0;

            NetItems.Insert(NetMinnow);
            NetItems.Insert(NetBullFrog);
            NetItems.Insert(NetSalamander);
        }
        if (!Predators) Predators = new array<ref PredatorEntry>();
        // Bugs is only for ActionDigBugs, the bug catcher / catch-bugs action.
        if (!Bugs) Bugs = new array<ref BugEntry>();
        // DigWorms is only for ActionDigWorms, the normal dig-worms action.
        if (!DigWorms) {
            DigWorms = new array<ref BugEntry>();

            BugEntry DigWorm = new BugEntry();
            DigWorm.Classname = "Worm";
            DigWorm.CatchChance = 0.75;

            BugEntry DigGrubWorm = new BugEntry();
            DigGrubWorm.Classname = "geb_GrubWorm";
            DigGrubWorm.CatchChance = 0.25;

            DigWorms.Insert(DigWorm);
            DigWorms.Insert(DigGrubWorm);
        }
        if (!Junk) Junk = new array<ref JunkEntry>();
        if (!ContainerJunk) ContainerJunk = new array<ref ContainerJunkEntry>();

        // Do not auto-create individual fish config sections here. Prepare recipes
        // intentionally fall back to 1 meat when their section is missing, and
        // mission registration skips missing fish instead of crashing.
    }

    // Per-species weather multipliers live inline on each FishConf class
    // (RainMultiplier / StormMultiplier / NightMultiplier). They are read at
    // yield-registration time by GebYieldFishBase.SetupYield in geb_yielditems.c
    // and cached on the yield itself, mirroring how m_QualityBase /
    // m_EnviroMask / m_MethodMask are already cached. The catching context
    // then reads them off the GebYieldFishBase via GetRainMultiplier() etc.
    //
    // Adding a new fish: add the FishConf class with multiplier fields, then
    // pass those fields to SetupYield in the matching geb_YieldXxx.Init().
    // No code changes needed in this file beyond the FishConf class.
}

//general settings config data
class GenSetConf {
    string DebugInfo = "Turns debug mode on(1) or off(0) to print extra logs to the script.log file";
    int DebugLogs = 0;
    string FishQualityInfo = "Sets the base value on(1) or off(0) for the fish quantity bar";
    float FishQuality = 1;
    string FishKnifeSpeedMultiplierInfo = "Animation length multiplier applied when filleting a fish with a geb fish knife. 1.0 = vanilla speed, 0.7 = 30% faster. Set to 1.0 to disable the bonus.";
    float FishKnifeSpeedMultiplier = 0.7;
    string CaviarChanceInfo = "Chance that preparing roe/caviar fish keeps the caviar result. 0 disables caviar, 1 always gives caviar.";
    float CaviarChance = 0.3;
};

class RecipeToggleConf {
    string RecipeToggleInfo = "Enables(1) or disables(0) Gebsfish non-fish-prep recipes. Fish prepare/fillet recipes are not controlled here.";
    bool CraftBambooFishingNet = 1;
    bool CraftHookFromWire = 1;
    bool RepairFishingPole = 1;
};

//cftools logging config data
class LogConf {
    string LoggingInfo = "Requires the ExtraLogs mod by TRG to use this section.";
    bool CatchLogs = 0;
    bool PredatorSpawn = 0;
    bool PredatorSounds = 0;
};

//predator animals config data
class PredatorConf {
    string PredatorSpawnEnabledInfo = "Turns on(1) and off(0) the predators feature of the mod. When on, it will enable the random spawning of predators when catching/cutting up the fish.";
    bool PredatorSpawnEnabled = 1;
    string PredatorSpawnChanceInfo = "Controls the chance for a predator to spawn from each action. Fishing is when a fish is caught, preparing is when filleting, failcatch is when fishing rolls nothing, fishingnet is when the bamboo fishing net action completes. Set any to 0 to disable that path.";
    float PredatorSpawnChanceFishing = 0.05;
    float PredatorSpawnChancePreparing = 0.05;
    float PredatorSpawnChanceFailCatch = 0.01;
    float PredatorSpawnChanceFishingNet = 0.01;
    string PredatorSpawnSoundInfo = "PredatorWarningSoundEnable controls the audible notification and PredatorWarningSoundRadius controls how far players hear the sound from the triggering player.";
    bool PredatorWarningSoundEnable = 1;
    int PredatorWarningSoundRadius = 50;
    string PredatorWarningMessageInfo = "PredatorWarningMessageEnable turns the chat message on and off, PredatorWarningMessage'Color' controls the color of the text. Only set one of the colors to on at a time.";
    bool PredatorWarningMessageEnable = 1;
    bool PredatorWarningMessageGreen = 0;
    bool PredatorWarningMessageRed = 0;
    bool PredatorWarningMessageYellow = 1;
    bool PredatorWarningMessageGrey = 0;
}

//weather catch buff config data
//Fish bite more during rain/storms and at night. Multipliers stack but
//are clamped to MaxStackedMultiplier so a stormy night does not become a printer.
//Set WeatherCatchBoostEnable = 0 to fully disable. Any individual multiplier
//of 1.0 means "no effect" for that condition.
class WeatherConf {
    string WeatherCatchBoostInfo = "Controls the rain / storm / night catch-rate buff. Set WeatherCatchBoostEnable to 0 to disable entirely. Multipliers below 1.0 act as penalties.";
    bool WeatherCatchBoostEnable = 1;

    string RainInfo = "RainThreshold is the rain intensity (0-1) above which the rain buff kicks in. Rain above StormThreshold uses StormCatchMultiplier instead.";
    float RainThreshold = 0.3;
    float StormThreshold = 0.7;
    float RainCatchMultiplier = 1.25;
    float StormCatchMultiplier = 1.5;

    string NightInfo = "Hours during which NightCatchMultiplier applies. NightStartHour is inclusive, NightEndHour is exclusive. Set both to 0 to disable the night buff.";
    int NightStartHour = 20;
    int NightEndHour = 6;
    float NightCatchMultiplier = 1.15;

    string CapInfo = "Hard cap on combined multipliers. Stops storm + night from compounding into something silly.";
    float MaxStackedMultiplier = 2.0;

    string SpeciesBuffsInfo = "Per-species multipliers are configured inline on each fish section below (RainMultiplier, StormMultiplier, NightMultiplier). 1.0 = no effect, higher = bites more, lower = bites less.";
}

//foraging config data
//FindChance is a per-attempt 0-1 probability that ANY item spawns from the
//action. 1.0 = always finds something (vanilla-style), 0.0 = never finds
//anything. The SPAWN TABLE itself (which item appears when the roll succeeds)
//is the top-level array on gebsfishConfig: DigWorms / Bugs / NetItems.
class ForageConf {
    string ForageInfo = "Per-attempt find-chance for the dig and net actions. 1.0 = always finds something, 0.0 = never finds anything. The spawn tables (DigWorms / Bugs / NetItems) decide WHAT spawns when the roll succeeds.";
    float DigWormsFindChance = 0.85;
    float DigBugsFindChance = 0.65;
    float FishingNetFindChance = 0.5;
}

class PredatorEntry {
    string Classname;   //Classname of predator
    float SpawnChance;  //Spawn percentage chance
    int MinCount;       //Minimum count of predators spawned
    int MaxCount;       //Maximum count of predators spawned
    float MinRadius;    //Minimum radius from player
    float MaxRadius;    //Maximum radius from player
}

//bug config data

class BugEntry {
    string Classname;
    float CatchChance;
}

//fish config data
class MackerelConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class CarpConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};
class SardinesConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 24;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};
class BitterlingsConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 24;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};
class WalleyePollockConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.1;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};  
};
class SteelheadTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};  
};
class ShrimpConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};  
};
class NorthernSnakeHeadConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class NorthernPikeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class MuskellungeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class SpottedMuskellungeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class BarredMuskellungeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class TigerMuskellungeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class AlligatorGarConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class LargeMouthBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.1;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SmallMouthBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.1;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class WallEyeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SunFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 0.9;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class WhiteBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BlackBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class StripedBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class NeoshoBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class RainbowTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BrownTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BrookTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class LakeTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.1;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class CutThroatTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class LakeSturgeonConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class YellowPerchConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 21;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class FlatHeadCatFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.6;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1};  
};
class FatHeadMinnowConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 25;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class AmericanBullFrogConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.5;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class RedSalamanderConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.6;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class BlueGillConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 0.9;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class SaugerConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BowFinConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SlimySculpinConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SeverumConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SignalCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class EuropeanCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class CaveCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 2;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class FloridaCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class MonongahelaCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class RedSwampCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class RustyCrayFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class MahiMahiConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 7;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float StormMultiplier = 1.5;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class AtlanticSailFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 4;
    int MeatMax = 7;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class AngelFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.8;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class AsianSeaBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class AtlanticBlueMarlinConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};
class BonitaConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class CherrySalmonConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 6;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class ChinookSalmonConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SockEyeSalmonConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class FlatHeadMulletConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class LeopardSharkConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class HammerHeadSharkConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class PacificCodConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class RedHeadCichlidConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class RoughNeckRockConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BlueTangConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class LargeHeadHairTailFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 5;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class HumpHeadWrasseConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 5;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.8;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SiameseTigerFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 6;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class GreatWhiteSharkConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 5;
    int MeatMax = 10;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 2;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class AngelSharkConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 8;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class YellowFinTunaConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class YellowSnapperConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class SouthernFlounderConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class WhiteGruntConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};
class BloodClamConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int BoneMin = 1;
    int BoneMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class MusselConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int BoneMin = 1;
    int BoneMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class BlackDevilSnailConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.2;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class StarFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class KingCrabConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class SnowCrabConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class BlueJellyFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class AmericanLobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class EuropeanLobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};

//Junk config data

class JunkEntry {
    string ClassnameInfo = "Any classname for a junk item that's not a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
    string HealthLevelInfo = "Health level range for spawned junk: 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined. Use 3/3 for fixed badly damaged, 3/4 for random badly damaged or ruined.";
    int MinHealthLevel = 3;
    int MaxHealthLevel = 3;
};

class ContainerJunkEntry {
    string ClassnameInfo = "Any classname for a junk item that's a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
    string HealthLevelInfo = "Health level range for spawned container junk: 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined. Use 3/3 for fixed badly damaged, 3/4 for random badly damaged or ruined.";
    int MinHealthLevel = 3;
    int MaxHealthLevel = 3;
};

//Save config data
protected ref gebsfishConfig m_gebsConfig;
// Helper function to return config data storage object
static gebsfishConfig GetGebSettingsConfig() {
    if (!m_gebsConfig) {
        GebsfishLogger.Info("Initializing gebsfish.", "JSON");
        GebsfishLogger.Info("Loading JSON config file.", "JSON");
        m_gebsConfig = new gebsfishConfig;

        //Only load JSON config on the server
        if (g_Game.IsServer()){
            m_gebsConfig.Load();
        }
    }
    return m_gebsConfig;
}

static void SetGebsfishConfig(gebsfishConfig config) {
    GebsfishLogger.Info("Setting config settings from server config file.", "JSON");
    m_gebsConfig = config;
}
//Prevent double printing in log file since it loads the yield data twice
bool gebsMissionLoaded = false;
