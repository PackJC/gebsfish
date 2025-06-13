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
    ref PredatorConf PredatorSettings;
    ref LogConf CFToolsLogging;
    ref array<ref PredatorEntry> Predators;
    ref array<ref BugEntry> Bugs;
    ref MackerelConf Mackerel;
    ref CarpConf Carp;
    ref SardinesConf Sardines;
    ref BitterlingsConf Bitterlings;
    ref WalleyePollockConf WalleyePollock;
    ref SteelheadTroutConf SteelheadTrout;
    ref ShrimpConf Shrimp;
    ref NorthernPikeConf NorthernPike;
    ref LargeMouthBassConf LargeMouthBass;
    ref SmallMouthBassConf SmallMouthBass;
    ref WallEyeConf WallEye;
    ref SunFishConf SunFish;
    ref WhiteBassConf WhiteBass;
    ref BlackBassConf BlackBass;
    ref RainbowTroutConf RainbowTrout;
    ref BrownTroutConf BrownTrout;
    ref BrookTroutConf BrookTrout;
    ref LakeTroutConf LakeTrout;
    ref CutThroatTroutConf CutThroatTrout;
    ref YellowPerchConf YellowPerch;
    ref FlatHeadCatFishConf FlatHeadCatFish;
    ref FatHeadMinnowConf FatHeadMinnow;
    ref BlueGillConf BlueGill;
    ref SaugerConf Sauger;
    ref BowFinConf BowFin;
    ref SlimySculpinConf SlimySculpin;
    ref SeverumConf Severum;
    ref SignalCrayFishConf SignalCrayFish;
    ref EuropeanCrayFishConf EuropeanCrayFish;
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

    void Load(){
        if (GetGame().IsDedicatedServer()){
            if (FileExist(ModFolder + SettingsConfigFile)){
                //If config exists, load file
                JsonFileLoader<gebsfishConfig>.JsonLoadFile(ModFolder + SettingsConfigFile, this);
                Print("[gebsfish] [JSON] Found settings file; Loading gebsfish settings.");
                // If version mismatch, backup old version of json before replacing it
                if (ConfigVersion != CONFIG_VERSION){
                    JsonFileLoader<gebsfishConfig>.JsonSaveFile(ModFolder + FileName + "_old" + FileType, this);
                    Print("[gebsfish] [JSON] New config version found for mod; Backing up old file and saving as " + ModFolder + FileName + "_old" + FileType + " and generating new config file.");
                }
                else {
                    // Config exists and version matches, stop here.
                    return;
                }
            }
        
        Print("[gebsfish] [JSON] Generating settings file.");
        //Save config file version to file
        ConfigVersion = CONFIG_VERSION;
        //Save general settings to file
        GeneralSettings = new GenSetConf;
        //Save CF Tools logging settings to file
        CFToolsLogging = new LogConf;
        //Save predator config data to the file 
        PredatorSettings = new PredatorConf;
        Predators = new array<ref PredatorEntry>();
        //Save bugs config data to file
        Bugs = new array<ref BugEntry>();
        //Save fish config data to file
        Mackerel = new MackerelConf;
        Carp = new CarpConf;
        Sardines = new SardinesConf;
        Bitterlings = new BitterlingsConf;
        WalleyePollock = new WalleyePollockConf;
        SteelheadTrout = new SteelheadTroutConf;
        Shrimp = new ShrimpConf;
        NorthernPike = new NorthernPikeConf;
        LargeMouthBass = new LargeMouthBassConf;
        SmallMouthBass = new SmallMouthBassConf;
        WallEye = new WallEyeConf;
        SunFish = new SunFishConf;
        WhiteBass = new WhiteBassConf;
        BlackBass = new BlackBassConf;
        RainbowTrout = new RainbowTroutConf;
        BrownTrout = new BrownTroutConf;
        BrookTrout = new BrookTroutConf;
        LakeTrout = new LakeTroutConf;
        CutThroatTrout = new CutThroatTroutConf;
        YellowPerch = new YellowPerchConf;
        FlatHeadCatFish = new FlatHeadCatFishConf;
        FatHeadMinnow = new FatHeadMinnowConf;
        BlueGill = new BlueGillConf;
        Sauger = new SaugerConf;
        BowFin = new BowFinConf;
        SlimySculpin = new SlimySculpinConf;
        Severum = new SeverumConf;
        SignalCrayFish = new SignalCrayFishConf;
        EuropeanCrayFish = new EuropeanCrayFishConf;
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

        //Add default bug data to file

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

        JunkEntry Wellies_Grey = new JunkEntry();
        Wellies_Grey.Classname = "Wellies_Grey";
        Wellies_Grey.CatchProbability = 5;

        JunkEntry Wellies_Green = new JunkEntry();
        Wellies_Green.Classname = "Wellies_Green";
        Wellies_Green.CatchProbability = 5;

        JunkEntry Wellies_Black = new JunkEntry();
        Wellies_Black.Classname = "Wellies_Black";
        Wellies_Black.CatchProbability = 5;

        Junk.Insert(Wellies_Brown);
        Junk.Insert(Wellies_Grey);
        Junk.Insert(Wellies_Green);
        Junk.Insert(Wellies_Black);

        ContainerJunkEntry Pot = new ContainerJunkEntry();
        Pot.Classname = "Pot";
        Pot.CatchProbability = 5;

        ContainerJunk.Insert(Pot);

        //Save it
        Save();
        }
    }
    void Save(){
        if (!FileExist(ModFolder)){
            //if config folder doesn't exist, create it.
            MakeDirectory(ModFolder);
        }
        //Save JSON Config
        JsonFileLoader<gebsfishConfig>.JsonSaveFile(ModFolder + SettingsConfigFile, this);
        Print("[gebsfish] [JSON] Settigns file generation complete!");
    }
}

//general settings config data
class GenSetConf {
    string DebugInfo = "Turns debug mode on to print extra logs to the script.log file";
    bool DebugLogs = 0;
    string FishQualityInfo = "Sets the base value for the fish quantity bar";
    float FishQuality = 1;
    
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
    string PredatorSpawnChanceInfo = "Controls the chance for a predator to spawn when a fish is caught or cut up. Fishing is when fishing, preparing is when getting fillets, failcatch is when nothing is caught.";
    float PredatorSpawnChanceFishing = 0.25;
    float PredatorSpawnChancePreparing = 0.25;
    float PredatorSpawnChanceFailCatch = 0.01;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};

class SardinesConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};

class BitterlingsConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
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
    int CatchProbability = 24;
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
    int CatchProbability = 12;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};  
};

class ShrimpConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 1;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};  
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
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
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};

class MusselConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int BoneMin = 1;
    int BoneMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};

class BlackDevilSnailConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class StarFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class KingCrabConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class SnowCrabConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class BlueJellyFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class AmericanLobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class EuropeanLobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};

//Junk config data

class JunkEntry {
    string ClassnameInfo = "Any classname for a junk item that's not a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
};

class ContainerJunkEntry {
    string ClassnameInfo = "Any classname for a junk item that's a liquid container.";
    string Classname;
    string CatchProbInfo = "Catch probability for this junk item. Typically a scale of 0-25, with 0 being no chance.";
    int CatchProbability;
};

//Save config data
protected ref gebsfishConfig m_gebsConfig;
// Helper function to return config data storage object
static gebsfishConfig GetGebSettingsConfig(){
    if (!m_gebsConfig){
        Print("[gebsfish] Initializing gebsfish.");
        Print("[gebsfish] Loading JSON config file. ");
        m_gebsConfig = new gebsfishConfig;

        //Only load JSON config on the server
        if (GetGame().IsServer()){
            m_gebsConfig.Load();
        }
    }
    return m_gebsConfig;
}

static void SetGebsfishConfig(gebsfishConfig config)
{
    Print("[gebsfish] Set config settings from server.");
    m_gebsConfig = config;
}
//Prevent double printing in log file since it loads the yield data twice
bool gebsMissionLoaded = false;
