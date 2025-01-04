// Define RPC constant for predator sound
const int RPC_PLAY_PREDATOR_SOUND = 2757509117; // Unique ID for the predator sound RPC

class gebsfishConfig{

    //Define Config Version
    static const string CONFIG_VERSION = "0.1";

    // Define RPC constant for predator sound
    const int RPC_PLAY_PREDATOR_SOUND = 2757509117; // Unique ID for the predator sound RPC

    //config location
    private const static string ModFolder = "$profile:\\gebsfish\\";
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
    ref LargemouthBassConf LargemouthBass;
    ref SmallmouthBassConf SmallmouthBass;
    ref WalleyeConf Walleye;
    ref SunfishConf Sunfish;
    ref WhiteBassConf WhiteBass;
    ref BlackBassConf BlackBass;
    ref RainbowTroutConf RainbowTrout;
    ref BrownTroutConf BrownTrout;
    ref BrookTroutConf BrookTrout;
    ref LakeTroutConf LakeTrout;
    ref CutthroatTroutConf CutthroatTrout;
    ref PerchConf Perch;
    ref CatfishConf Catfish;
    ref MinnowConf Minnow;
    ref BluegillConf Bluegill;
    ref SaugerConf Sauger;
    ref BowfinConf Bowfin;
    ref SlimySculpinConf SlimySculpin;
    ref SeverumConf Severum;
    ref CrayfishConf Crayfish;
    ref MahimahiConf Mahimahi;
    ref SailfishConf Sailfish;
    ref AngelfishConf Angelfish;
    ref AsianSeaBassConf AsianSeaBass;
    ref BlueMarlinConf BlueMarlin;
    ref BonitaConf Bonita;
    ref CherrySalmonConf CherrySalmon;
    ref ChinookSalmonConf ChinookSalmon;
    ref SockeyeSalmonConf SockeyeSalmon;
    ref FlatheadMulletConf FlatheadMullet;
    ref LeopardSharkConf LeopardShark;
    ref PacificCodConf PacificCod;
    ref RedheadCichlidConf RedheadCichlid;
    ref RoughneckRockConf RoughneckRock;
    ref BlueTangConf BlueTang;
    ref HairtailFishConf HairtailFish;
    ref HumpheadWrasseConf HumpheadWrasse;
    ref SiameseTigerfishConf SiameseTigerfish;
    ref GreatWhiteSharkConf GreatWhiteShark;
    ref AngelSharkConf AngelShark;
    ref YellowfinTunaConf YellowfinTuna;
    ref BloodClamConf BloodClam;
    ref MusselConf Mussel;
    ref BlackDevilSnailConf BlackDevilSnail;
    ref StarfishConf Starfish;
    ref KingCrabConf KingCrab;
    ref JellyfishConf Jellyfish;
    ref LobsterConf Lobster;
    ref BlueLobsterConf BlueLobster;

    ref JunkConf Junk;
    ref ContainerJunkConf ContainerJunk;

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
        LargemouthBass = new LargemouthBassConf;
        SmallmouthBass = new SmallmouthBassConf;
        Walleye = new WalleyeConf;
        Sunfish = new SunfishConf;
        WhiteBass = new WhiteBassConf;
        BlackBass = new BlackBassConf;
        RainbowTrout = new RainbowTroutConf;
        BrownTrout = new BrownTroutConf;
        BrookTrout = new BrookTroutConf;
        LakeTrout = new LakeTroutConf;
        CutthroatTrout = new CutthroatTroutConf;
        Perch = new PerchConf;
        Catfish = new CatfishConf;
        Minnow = new MinnowConf;
        Bluegill = new BluegillConf;
        Sauger = new SaugerConf;
        Bowfin = new BowfinConf;
        SlimySculpin = new SlimySculpinConf;
        Severum = new SeverumConf;
        Crayfish = new CrayfishConf;
        Mahimahi = new MahimahiConf;
        Sailfish = new SailfishConf;
        Angelfish = new AngelfishConf;
        AsianSeaBass = new AsianSeaBassConf;
        BlueMarlin = new BlueMarlinConf;
        Bonita = new BonitaConf;
        CherrySalmon = new CherrySalmonConf;
        ChinookSalmon = new ChinookSalmonConf;
        SockeyeSalmon = new SockeyeSalmonConf;
        FlatheadMullet = new FlatheadMulletConf;
        LeopardShark = new LeopardSharkConf;
        PacificCod = new PacificCodConf;
        RedheadCichlid = new RedheadCichlidConf;
        RoughneckRock = new RoughneckRockConf;
        BlueTang = new BlueTangConf;
        HairtailFish = new HairtailFishConf;
        HumpheadWrasse = new HumpheadWrasseConf;
        SiameseTigerfish = new SiameseTigerfishConf;
        GreatWhiteShark = new GreatWhiteSharkConf;
        AngelShark = new AngelSharkConf;
        YellowfinTuna = new YellowfinTunaConf;
        BloodClam = new BloodClamConf;
        Mussel = new MusselConf;
        BlackDevilSnail = new BlackDevilSnailConf;
        Starfish = new StarfishConf;
        KingCrab = new KingCrabConf;
        Jellyfish = new JellyfishConf;
        Lobster = new LobsterConf;
        BlueLobster = new BlueLobsterConf;


        //Save junk config data to file
        Junk = new JunkConf;
        ContainerJunk = new ContainerJunkConf;

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
        Worm.Classname = "geb_Worm";
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
    string FishQualityInfo = "Sets the base value for the fish quanity bar";
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

class BugConf {
    string NotImplemented = "This section is not implemented yet. Please use the old bugs.cfg file to configure the bugs.";
    string BugInfo = "Controls catch chance for each bug when using the bug catcher. 0-25.";
    int Worm = 10;
    int GrassHopper = 10;
    int GrubWorm = 10;
    int FieldCricket = 10;
}

//fish config data
class MackerelConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};

class LargemouthBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class SmallmouthBassConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class WalleyeConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class SunfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class CutthroatTroutConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class PerchConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class CatfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1};  
};

class MinnowConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};

class BluegillConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class BowfinConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class CrayfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class MahimahiConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};

class SailfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};

class AngelfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  
};

class BlueMarlinConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class SockeyeSalmonConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class FlatheadMulletConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class RedheadCichlidConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class RoughneckRockConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class HairtailFishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class HumpheadWrasseConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class SiameseTigerfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};  
};

class YellowfinTunaConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float MeatMin = 1;
    float MeatMax = 2;
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
    float BoneMin = 1;
    float BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class StarfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    float BoneMin = 1;
    float BoneMax = 1;
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
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class JellyfishConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class LobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};
class BlueLobsterConf {
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    float MeatMin = 1;
    float MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 15;
    // autoptr TStringArray BiteSpeedInfo = {"How fast the fish bite at each time. Uses values 0.0-1.0 to slow or speed up the catch cycle times during the animation per in-game hour. 24 values as shown below.","12AM", "1AM", "2AM", "3AM", "4AM", "5AM", "6AM", "7AM", "8AM", "9AM", "10AM", "11AM", "12PM", "1PM", "2PM", "3PM", "4PM", "5PM", "6PM", "7PM", "8PM", "9PM", "10PM", "11PM"};
    // autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  
};


//Junk config data
class JunkConf {
    string JunkInfo = "Any item can be added here except for liquid containers.";
    autoptr TStringArray Classnames = {"Wellies_Brown", "Wellies_Grey", "Wellies_Green", "Wellies_Black"};
};

class ContainerJunkConf {
    string JunkInfo = "Add liquid containers here so they are empty when caught.";
    autoptr TStringArray Classnames = {"Pot"};
};

//Save config data
ref gebsfishConfig m_gebsConfig;
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
//Prevent double printing in log file since it loads the yield data twice
bool gebsMissionLoaded = false;




// class GebConversion{
//     static int FishingMethod(int gebMethod){
//         static int geb_method;
//         switch(gebMethod){
//             case 1:
//                 geb_method = 1;
//                 break;
//             case 2:
//                 geb_method = 2;
//                 break;
//             case 3:
//                 geb_method = 3;
//                 break;
//             case 4:
//                 geb_method = 4;
//                 break;
//             case 5:
//                 geb_method = 5;
//                 break;
//             case 6:
//                 geb_method = 6;
//                 break;
//             case 7:
//                 geb_method = 7;
//                 break;
//             default:
//                 Print("[gebsfish] Config setting for fish environment not in range. Defaulting to Rod");
//                 geb_method = 1;
//                 break;
//         }
//         return geb_method;
//     }

//     static int Environment(int gebEnviro){
//         int geb_enviro;
//         switch(gebEnviro){
//             case 2:
//                 geb_enviro = 2;
//                 break;
//             case 1:
//                 geb_enviro = 1;
//                 break;
//             case 3: 
//                 geb_enviro = 3;
//                 break;
//             default:
//                 Print("[gebsfish] Config setting for fish environment not in range. Defaulting to Pond");
//                 geb_enviro = 1;
//                 break;
//         }
//         return geb_enviro;
//     }

//     static void FishingCoefs(TFloatArray coefs, out float[] input) {
//         if(coefs.Count() != 24) return;
//         input;
//         // Print(coefs);
//         float fishing_coefs[24];

//         for(int i = 0; i < 24; i++) {
//             fishing_coefs[i] = coefs[i];
//             // Print("Fishing Coef:");
//             // Print(fishing_coefs[i]);
//             // Print("Coef:");
//             // Print(coefs[i]);
//         }
//         // Print(fishing_coefs);
//         input = fishing_coefs;
//         // Print(input);
//     }

// }