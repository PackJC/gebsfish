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
    ref LogConf CFToolsLogging;
    ref array<ref PredatorEntry> Predators;
    // Per-action sections -- each owns its own find-chance, spawn table,
    // and any action-specific extras (the net also has PredatorSpawnChance).
    ref BambooFishingNetConf BambooFishingNetSettings;
    ref DigBugsConf DigBugsSettings;
    ref DigWormsConf DigWormsSettings;
    string BaitPreferenceEnableInfo = "Master toggle for the bait / lure preference system. Each entry in BaitPreferences pairs a bait classname (Worm, geb_GrubWorm, geb_SpinnerBaitRed, etc.) with a list of per-fish multipliers that bias the weighted catch pick toward that fish when this bait is on the hook (e.g. a Worm makes BlueGill 2.0x more likely while making large saltwater fish 0.3x). Set to 0 to disable the bias entirely -- every bait becomes neutral 1.0x for every fish and only the underlying CatchProbability values drive the pick. Bait still functions mechanically (gets eaten/destroyed, hook still loses bait on a miss) -- this only disables the per-fish bias. The BaitPreferences array still loads from JSON when disabled so a server can flip this on/off without losing tuned values. Useful when admins want bait to function but not influence catch outcomes, or for diagnosing whether unexpected fish are coming from bait bias vs weather/temperature/time-of-day multipliers.";
    bool BaitPreferenceEnable = 1;
    // Per-bait fish-preference table. Multiplies into the weighted pick at
    // catch time so the bait/lure on the hook biases WHICH fish gets
    // selected. See SeedDefaultBaitPreferences() for the default ecology.
    ref array<ref BaitConfig> BaitPreferences;
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
                    // Config exists and version matches. Older manually edited
                    // files can still be missing shared settings sections, so
                    // backfill any null refs. Only Save() if something was
                    // actually filled in -- otherwise we'd needlessly rewrite
                    // the JSON on every server start (and risk corrupting
                    // hand-edited files via reformatting).
                    if (EnsureMissingConfigSections()) {
                        GebsfishLogger.Info("Backfilled missing config sections; saving updated JSON.", "JSON");
                        Save();
                    }
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
        // on each FishConf class (Rain/Storm/Dawn/Day/Dusk/NightMultiplier).
        WeatherSettings = new WeatherConf;
        Predators = new array<ref PredatorEntry>();
        // Per-action settings (find chance + spawn table + any action-specific
        // extras). Default Catches entries are seeded further down in Build().
        BambooFishingNetSettings = new BambooFishingNetConf;
        DigBugsSettings = new DigBugsConf;
        DigWormsSettings = new DigWormsConf;
        // Per-bait fish-preference table. Seeded with biologically defensible
        // multipliers so the system is "alive" out of the box; admins can
        // tune by editing the JSON.
        BaitPreferences = new array<ref BaitConfig>();
        SeedDefaultBaitPreferences();
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

        DigBugsSettings.Catches.Insert(FieldCricket);
        DigBugsSettings.Catches.Insert(GrassHopper);
        DigBugsSettings.Catches.Insert(GrubWorm);
        DigBugsSettings.Catches.Insert(Worm);

        // Add default normal dig-worms data to file.
        BugEntry DigWorm = new BugEntry();
        DigWorm.Classname = "Worm";
        DigWorm.CatchChance = 0.75;

        BugEntry DigGrubWorm = new BugEntry();
        DigGrubWorm.Classname = "geb_GrubWorm";
        DigGrubWorm.CatchChance = 0.25;

        DigWormsSettings.Catches.Insert(DigWorm);
        DigWormsSettings.Catches.Insert(DigGrubWorm);

        // Add default bamboo-fishing-net spawn table. Matches the previously
        // hardcoded behaviour (equal chance minnow / frog / salamander) but is
        // now editable by server admins. All three are freshwater so
        // Environment = 1 (pond). Admins can add Environment=2 / 3 entries
        // (e.g. Shrimp) for saltwater catches.
        NetEntry NetMinnow = new NetEntry();
        NetMinnow.Classname = "geb_FatHeadMinnow";
        NetMinnow.CatchChance = 1.0;
        NetMinnow.Environment = 1;

        NetEntry NetBullFrog = new NetEntry();
        NetBullFrog.Classname = "geb_AmericanBullFrog";
        NetBullFrog.CatchChance = 1.0;
        NetBullFrog.Environment = 1;

        NetEntry NetSalamander = new NetEntry();
        NetSalamander.Classname = "geb_RedSalamander";
        NetSalamander.CatchChance = 1.0;
        NetSalamander.Environment = 1;

        BambooFishingNetSettings.Catches.Insert(NetMinnow);
        BambooFishingNetSettings.Catches.Insert(NetBullFrog);
        BambooFishingNetSettings.Catches.Insert(NetSalamander);

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

    // Returns true if any missing section was created, false if the loaded
    // config already had everything. Callers use the return value to decide
    // whether to Save() -- a no-op pass should not rewrite the JSON on every
    // server start. Existing values are always preserved; only missing
    // object/array refs are created.
    bool EnsureMissingConfigSections() {
        bool changed = false;
        if (!GeneralSettings)    { GeneralSettings = new GenSetConf;       changed = true; }
        if (!RecipeToggles)      { RecipeToggles = new RecipeToggleConf;   changed = true; }
        if (!CFToolsLogging)     { CFToolsLogging = new LogConf;           changed = true; }
        if (!PredatorSettings)   { PredatorSettings = new PredatorConf;    changed = true; }
        if (!WeatherSettings)    { WeatherSettings = new WeatherConf;      changed = true; }
        // Per-species multipliers now live on each FishConf class (Rain/Storm/
        // Dawn/Day/Dusk/NightMultiplier), so nothing extra to seed here.
        if (!Predators)          { Predators = new array<ref PredatorEntry>();           changed = true; }

        // Per-action sections. If a section is missing (fresh install, or an
        // admin removed it by hand-editing the JSON), allocate with the same
        // defaults Build() uses so the action keeps working.
        if (!BambooFishingNetSettings) {
            BambooFishingNetSettings = new BambooFishingNetConf;

            NetEntry netMinnow = new NetEntry();
            netMinnow.Classname = "geb_FatHeadMinnow";
            netMinnow.CatchChance = 1.0;
            netMinnow.Environment = 1;

            NetEntry netBullFrog = new NetEntry();
            netBullFrog.Classname = "geb_AmericanBullFrog";
            netBullFrog.CatchChance = 1.0;
            netBullFrog.Environment = 1;

            NetEntry netSalamander = new NetEntry();
            netSalamander.Classname = "geb_RedSalamander";
            netSalamander.CatchChance = 1.0;
            netSalamander.Environment = 1;

            BambooFishingNetSettings.Catches.Insert(netMinnow);
            BambooFishingNetSettings.Catches.Insert(netBullFrog);
            BambooFishingNetSettings.Catches.Insert(netSalamander);
            changed = true;
        }

        if (!DigBugsSettings) {
            DigBugsSettings = new DigBugsConf;

            BugEntry fieldCricket = new BugEntry();
            fieldCricket.Classname = "geb_FieldCricket";
            fieldCricket.CatchChance = 0.25;

            BugEntry grassHopper = new BugEntry();
            grassHopper.Classname = "geb_GrassHopper";
            grassHopper.CatchChance = 0.25;

            BugEntry grubWorm = new BugEntry();
            grubWorm.Classname = "geb_GrubWorm";
            grubWorm.CatchChance = 0.75;

            BugEntry vanillaWorm = new BugEntry();
            vanillaWorm.Classname = "Worm";
            vanillaWorm.CatchChance = 0.25;

            DigBugsSettings.Catches.Insert(fieldCricket);
            DigBugsSettings.Catches.Insert(grassHopper);
            DigBugsSettings.Catches.Insert(grubWorm);
            DigBugsSettings.Catches.Insert(vanillaWorm);
            changed = true;
        }

        if (!DigWormsSettings) {
            DigWormsSettings = new DigWormsConf;

            BugEntry digWorm = new BugEntry();
            digWorm.Classname = "Worm";
            digWorm.CatchChance = 0.75;

            BugEntry digGrubWorm = new BugEntry();
            digGrubWorm.Classname = "geb_GrubWorm";
            digGrubWorm.CatchChance = 0.25;

            DigWormsSettings.Catches.Insert(digWorm);
            DigWormsSettings.Catches.Insert(digGrubWorm);
            changed = true;
        }

        if (!Junk)               { Junk = new array<ref JunkEntry>();                    changed = true; }
        if (!ContainerJunk)      { ContainerJunk = new array<ref ContainerJunkEntry>();  changed = true; }

        if (!BaitPreferences) {
            BaitPreferences = new array<ref BaitConfig>();
            SeedDefaultBaitPreferences();
            changed = true;
        }

        // Do not auto-create individual fish config sections here. Prepare recipes
        // intentionally fall back to 1 meat when their section is missing, and
        // mission registration skips missing fish instead of crashing.
        return changed;
    }

    // Default per-bait fish-preference table. Every bait lists every
    // rod-eligible fish. Multiplier > 1.0 makes that fish more likely
    // to be the selected catch; < 1.0 makes it less likely; 1.0 is
    // neutral. Fish are bucketed into 15 ecological categories so the
    // seed stays compact; the JSON output still shows every fish-bait
    // pair explicitly so admins can tune individual entries.
    protected void SeedDefaultBaitPreferences() {
        ref array<string> catPanfish = new array<string>;
        catPanfish.Insert("geb_BlueGill");
        catPanfish.Insert("geb_SunFish");
        catPanfish.Insert("geb_YellowPerch");
        catPanfish.Insert("Bitterlings");

        ref array<string> catBass = new array<string>;
        catBass.Insert("geb_LargeMouthBass");
        catBass.Insert("geb_SmallMouthBass");
        catBass.Insert("geb_BlackBass");
        catBass.Insert("geb_NeoshoBass");
        catBass.Insert("geb_StripedBass");
        catBass.Insert("geb_WhiteBass");

        ref array<string> catPikeMusky = new array<string>;
        catPikeMusky.Insert("geb_NorthernPike");
        catPikeMusky.Insert("geb_Muskellunge");
        catPikeMusky.Insert("geb_BarredMuskellunge");
        catPikeMusky.Insert("geb_SpottedMuskellunge");
        catPikeMusky.Insert("geb_TigerMuskellunge");
        catPikeMusky.Insert("geb_NorthernSnakeHead");
        catPikeMusky.Insert("geb_BowFin");

        ref array<string> catWalleye = new array<string>;
        catWalleye.Insert("geb_WallEye");
        catWalleye.Insert("geb_Sauger");

        ref array<string> catTroutSalmon = new array<string>;
        catTroutSalmon.Insert("SteelheadTrout");
        catTroutSalmon.Insert("geb_BrookTrout");
        catTroutSalmon.Insert("geb_BrownTrout");
        catTroutSalmon.Insert("geb_RainbowTrout");
        catTroutSalmon.Insert("geb_CutThroatTrout");
        catTroutSalmon.Insert("geb_LakeTrout");
        catTroutSalmon.Insert("geb_ChinookSalmon");
        catTroutSalmon.Insert("geb_CherrySalmon");
        catTroutSalmon.Insert("geb_SockEyeSalmon");

        ref array<string> catCatfishBottom = new array<string>;
        catCatfishBottom.Insert("geb_FlatHeadCatFish");
        catCatfishBottom.Insert("geb_AlligatorGar");
        catCatfishBottom.Insert("geb_LakeSturgeon");

        ref array<string> catCarp = new array<string>;
        catCarp.Insert("Carp");

        ref array<string> catAmphibian = new array<string>;
        catAmphibian.Insert("geb_AmericanBullFrog");
        catAmphibian.Insert("geb_RedSalamander");

        ref array<string> catBaitFish = new array<string>;
        catBaitFish.Insert("geb_FatHeadMinnow");
        catBaitFish.Insert("geb_FlatHeadMullet");
        catBaitFish.Insert("geb_SlimySculpin");

        ref array<string> catCrustacean = new array<string>;
        catCrustacean.Insert("Shrimp");
        catCrustacean.Insert("geb_SignalCrayFish");
        catCrustacean.Insert("geb_EuropeanCrayFish");
        catCrustacean.Insert("geb_FloridaCrayFish");
        catCrustacean.Insert("geb_CaveCrayFish");
        catCrustacean.Insert("geb_MonongahelaCrayFish");
        catCrustacean.Insert("geb_RedSwampCrayFish");
        catCrustacean.Insert("geb_RustyCrayFish");
        catCrustacean.Insert("geb_AmericanLobster");
        catCrustacean.Insert("geb_EuropeanLobster");
        catCrustacean.Insert("geb_KingCrab");
        catCrustacean.Insert("geb_SnowCrab");

        ref array<string> catSaltwaterLarge = new array<string>;
        catSaltwaterLarge.Insert("geb_GreatWhiteShark");
        catSaltwaterLarge.Insert("geb_HammerHeadShark");
        catSaltwaterLarge.Insert("geb_AngelShark");
        catSaltwaterLarge.Insert("geb_LeopardShark");
        catSaltwaterLarge.Insert("geb_AtlanticBlueMarlin");
        catSaltwaterLarge.Insert("geb_AtlanticSailFish");
        catSaltwaterLarge.Insert("geb_YellowFinTuna");

        ref array<string> catSaltwaterMed = new array<string>;
        catSaltwaterMed.Insert("geb_AsianSeaBass");
        catSaltwaterMed.Insert("geb_Bonita");
        catSaltwaterMed.Insert("geb_MahiMahi");
        catSaltwaterMed.Insert("geb_RoughNeckRock");
        catSaltwaterMed.Insert("geb_SiameseTigerFish");
        catSaltwaterMed.Insert("WalleyePollock");
        catSaltwaterMed.Insert("geb_PacificCod");
        catSaltwaterMed.Insert("geb_LargeHeadHairTailFish");
        catSaltwaterMed.Insert("geb_SouthernFlounder");

        ref array<string> catSaltwaterSmall = new array<string>;
        catSaltwaterSmall.Insert("Mackerel");
        catSaltwaterSmall.Insert("Sardines");
        catSaltwaterSmall.Insert("geb_YellowSnapper");
        catSaltwaterSmall.Insert("geb_WhiteGrunt");

        ref array<string> catReefTropical = new array<string>;
        catReefTropical.Insert("geb_AngelFish");
        catReefTropical.Insert("geb_BlueTang");
        catReefTropical.Insert("geb_HumpHeadWrasse");
        catReefTropical.Insert("geb_Severum");
        catReefTropical.Insert("geb_RedHeadCichlid");

        ref array<string> catShellfishInvert = new array<string>;
        catShellfishInvert.Insert("geb_BloodClam");
        catShellfishInvert.Insert("geb_Mussel");
        catShellfishInvert.Insert("geb_BlackDevilSnail");
        catShellfishInvert.Insert("geb_BlueJellyFish");
        catShellfishInvert.Insert("geb_StarFish");

        BaitConfig bait;

        bait = new BaitConfig();
        bait.BaitClassname = "Worm";
        AppendBaitPrefsByCategory(bait, catPanfish, 2.0);
        AppendBaitPrefsByCategory(bait, catBass, 1.4);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 0.6);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.2);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.6);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.5);
        AppendBaitPrefsByCategory(bait, catCarp, 2.0);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.2);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.7);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.4);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_GrassHopper";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 1.4);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 0.4);
        AppendBaitPrefsByCategory(bait, catWalleye, 0.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.7);
        AppendBaitPrefsByCategory(bait, catCarp, 1.0);
        AppendBaitPrefsByCategory(bait, catAmphibian, 1.8);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.9);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.4);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_FieldCricket";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 1.4);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 0.4);
        AppendBaitPrefsByCategory(bait, catWalleye, 0.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.7);
        AppendBaitPrefsByCategory(bait, catCarp, 1.0);
        AppendBaitPrefsByCategory(bait, catAmphibian, 1.8);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.9);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.4);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_GrubWorm";
        AppendBaitPrefsByCategory(bait, catPanfish, 2.0);
        AppendBaitPrefsByCategory(bait, catBass, 1.4);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 0.5);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.3);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.8);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.3);
        AppendBaitPrefsByCategory(bait, catCarp, 1.4);
        AppendBaitPrefsByCategory(bait, catAmphibian, 1.0);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.1);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.4);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.7);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.7);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_RubberWorm";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 2.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.5);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 0.7);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.7);
        AppendBaitPrefsByCategory(bait, catCarp, 0.4);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.6);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.4);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.4);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "Shrimp";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 0.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 0.5);
        AppendBaitPrefsByCategory(bait, catWalleye, 0.5);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 0.7);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.6);
        AppendBaitPrefsByCategory(bait, catCarp, 0.4);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.7);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 2.0);
        AppendBaitPrefsByCategory(bait, catReefTropical, 1.5);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.5);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_FatHeadMinnow";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.7);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.5);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.5);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.4);
        AppendBaitPrefsByCategory(bait, catAmphibian, 1.0);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.8);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.4);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.0);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.8);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.5);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_RedSalamander";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.4);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.0);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.5);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 2.5);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 0.6);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.4);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.3);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpinnerBait1";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.8);
        AppendBaitPrefsByCategory(bait, catBass, 2.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.6);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.5);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpinnerBait2";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.8);
        AppendBaitPrefsByCategory(bait, catBass, 2.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.6);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.5);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpinnerBait3";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.8);
        AppendBaitPrefsByCategory(bait, catBass, 2.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.6);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.5);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpinnerBait4";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.8);
        AppendBaitPrefsByCategory(bait, catBass, 2.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.6);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.5);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.4);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpoonLure1";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 1.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.0);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.8);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.9);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.5);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpoonLure2";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 1.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.0);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.8);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.9);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.5);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpoonLure3";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 1.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.0);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.8);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.9);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.5);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_SpoonLure4";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.6);
        AppendBaitPrefsByCategory(bait, catBass, 1.5);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 2.0);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 2.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.4);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.8);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 0.9);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.6);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.5);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_Lure1";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.7);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.8);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 1.0);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.7);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_Lure2";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.7);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.8);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 1.0);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.7);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_Lure3";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.7);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.8);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 1.0);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.7);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_Lure4";
        AppendBaitPrefsByCategory(bait, catPanfish, 0.7);
        AppendBaitPrefsByCategory(bait, catBass, 2.0);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.8);
        AppendBaitPrefsByCategory(bait, catWalleye, 1.8);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.5);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 1.0);
        AppendBaitPrefsByCategory(bait, catCarp, 0.3);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 1.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.5);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 1.0);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.7);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_CurlyTailJig1";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 2.2);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.5);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.0);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.8);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_CurlyTailJig2";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 2.2);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.5);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.0);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.8);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_CurlyTailJig3";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 2.2);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.5);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.0);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.8);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);

        bait = new BaitConfig();
        bait.BaitClassname = "geb_CurlyTailJig4";
        AppendBaitPrefsByCategory(bait, catPanfish, 1.5);
        AppendBaitPrefsByCategory(bait, catBass, 2.2);
        AppendBaitPrefsByCategory(bait, catPikeMusky, 1.3);
        AppendBaitPrefsByCategory(bait, catWalleye, 2.0);
        AppendBaitPrefsByCategory(bait, catTroutSalmon, 1.0);
        AppendBaitPrefsByCategory(bait, catCatfishBottom, 0.8);
        AppendBaitPrefsByCategory(bait, catCarp, 0.5);
        AppendBaitPrefsByCategory(bait, catAmphibian, 0.5);
        AppendBaitPrefsByCategory(bait, catBaitFish, 1.0);
        AppendBaitPrefsByCategory(bait, catCrustacean, 0.3);
        AppendBaitPrefsByCategory(bait, catSaltwaterLarge, 0.7);
        AppendBaitPrefsByCategory(bait, catSaltwaterMed, 1.0);
        AppendBaitPrefsByCategory(bait, catSaltwaterSmall, 0.8);
        AppendBaitPrefsByCategory(bait, catReefTropical, 0.6);
        AppendBaitPrefsByCategory(bait, catShellfishInvert, 0.3);
        BaitPreferences.Insert(bait);
    }

    // Helper: append a BaitPreferenceEntry to `conf.Preferences` for
    // every fish classname in `fishList`, all with the same multiplier.
    // Lets SeedDefaultBaitPreferences emit per-category preferences in
    // one line per (bait, category) pair instead of per fish.
    protected void AppendBaitPrefsByCategory(BaitConfig conf, array<string> fishList, float mul) {
        foreach (string fish : fishList) {
            BaitPreferenceEntry pref = new BaitPreferenceEntry();
            pref.FishClassname = fish;
            pref.Multiplier = mul;
            conf.Preferences.Insert(pref);
        }
    }

    // Per-species weather multipliers live inline on each FishConf class
    // (RainMultiplier / StormMultiplier / DawnMultiplier / DayMultiplier /
    // DuskMultiplier / NightMultiplier). They are read at yield-registration
    // time by GebYieldFishBase.SetupYield in geb_yielditems.c and cached on
    // the yield itself, mirroring how m_QualityBase / m_EnviroMask /
    // m_MethodMask are already cached. The catching context then reads them
    // off the GebYieldFishBase via GetRainMultiplier() etc.
    //
    // Adding a new fish: add the FishConf class with multiplier fields, then
    // pass those fields to SetupYield in the matching geb_YieldXxx.Init().
    // No code changes needed in this file beyond the FishConf class.
}

//general settings config data
class GenSetConf {
    string DebugInfo = "Debug log level for script.log. 0 = off, 1 = standard (per-cast summaries: BiteSpeed aggregate, cycle scaling, weighted pick results), 2 = elevated (per-tick probability, per-fish BiteSpeed breakdown table). Set to 1 when tuning fishing config; 2 only when reproducing a specific bug since it is very chatty.";
    int DebugLogs = 0;
    string FishQualityInfo = "Base quality value applied to every fish spawned from a successful catch. Read by trader mods (DayZ-Expansion-Market, TraderPlus, Dr. Jones, etc.) to determine sell price, and by the engine to drive food quality / nutrition values. Vanilla DayZ uses QUALITY_FISH_BASE = 0.35, but several popular trader mods only accept items at FULL quality (1.0) and will silently reject or refuse to buy fish that come in below that threshold. Default is 1.0 to stay compatible with those traders out of the box. Lower it (e.g. 0.35) only if your trader setup accepts fractional quality and you want to match vanilla payouts. Higher values (1.5+) work as a payout boost on traders that scale price by quality.";
    float FishQuality = 1.0;
    string FishKnifeSpeedMultiplierInfo = "Animation length multiplier applied when filleting a fish with a geb fish knife. 1.0 = vanilla speed (no bonus), 0.9 = 10% faster (default), 0.7 = 30% faster but causes visible animation desync. DayZ does not expose a way to scale the actual character animation playback, only the recipe duration -- so values too far below 1.0 produce a noticeable gap where the recipe ends before the skinning finish-animation completes (player can freeze briefly, or move away before the fillet visually appears). 0.9 keeps the gap inside the finish-transition window so it isn't perceptible.";
    float FishKnifeSpeedMultiplier = 0.9;
    string CaviarChanceInfo = "Chance that preparing roe/caviar fish keeps the caviar result. 0 disables caviar, 1 always gives caviar.";
    float CaviarChance = 0.3;
};

class RecipeToggleConf {
    string RecipeToggleInfo = "Enables(1) or disables(0) Gebsfish non-fish-prep recipes. Fish prepare/fillet recipes are not controlled here.";
    bool CraftBambooFishingNet = 1;
    bool CraftHookFromWire = 1;
    bool RepairFishingPole = 1;
    bool RepairBambooFishingNet = 1;
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
    string PredatorSpawnChanceInfo = "Controls the chance for a predator to spawn from each action. Fishing is when a fish is caught, preparing is when filleting, failcatch is when fishing rolls nothing. Bamboo fishing net has its own predator chance under BambooFishingNetSettings.PredatorSpawnChance. Set any to 0 to disable that path.";
    float PredatorSpawnChanceFishing = 0.05;
    float PredatorSpawnChancePreparing = 0.05;
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

    string TimeWindowInfo = "Hour-of-day windows. Start is inclusive, end is exclusive (e.g. Dawn 5-7 covers hours 5 and 6 only). With the defaults the four windows tile the full 24-hour day without overlap, so exactly one applies at any given moment. If you reconfigure the boundaries so windows do overlap, the resolver picks them in priority order Dawn -> Day -> Dusk -> Night. Per-fish Dawn/Day/Dusk/NightMultiplier fields apply alongside these globals.";
    int DawnStartHour = 5;
    int DawnEndHour = 7;
    int DayStartHour = 7;
    int DayEndHour = 17;
    int DuskStartHour = 17;
    int DuskEndHour = 20;
    int NightStartHour = 20;
    int NightEndHour = 5;
    float DawnCatchMultiplier = 1.10;
    float DayCatchMultiplier = 1.0;
    float DuskCatchMultiplier = 1.10;
    float NightCatchMultiplier = 1.15;

    string CapInfo = "Hard cap on combined multipliers. Stops storm + night from compounding into something silly.";
    float MaxStackedMultiplier = 2.0;

    string MoonPhaseInfo = "Moon-phase catch buff. Calculates the actual lunar phase from the in-game date and interpolates between FullMoonMultiplier (at full moon) and NewMoonMultiplier (at new moon), smooth across quarter moons. Only applies at night since the moon isn't a visible/active factor during the day. Independent of WeatherCatchBoostEnable so admins can run moon-only or weather-only. Defaults stay within +-20% to avoid feeling gimmicky.";
    bool MoonPhaseEnable = 1;
    float FullMoonMultiplier = 1.20;
    float NewMoonMultiplier = 0.90;

    string TemperatureInfo = "Per-species water-temperature catch buff. Reads ambient air temperature as a proxy for water temperature and applies a per-fish bell curve: 1.0x at the fish's TempOptimal, falling linearly to MinTempMultiplier as water drops to TempMin and to MaxTempMultiplier as it rises to TempMax. Outside [TempMin, TempMax] the multiplier stays clamped at those floors so cold-water fish never fully shut down in summer (and vice versa). All temps in degrees Celsius. Set TemperatureEffectEnable to 0 to disable entirely; set a fish's TempMin equal to its TempMax to disable just that fish. Independent of WeatherCatchBoostEnable.";
    bool TemperatureEffectEnable = 1;
    float MinTempMultiplier = 0.1;
    float MaxTempMultiplier = 0.1;
    string WaterTempOffsetInfo = "Admin offset (degrees Celsius) added to ambient air temperature before the per-fish curve is applied. Use NEGATIVE values for winter/cold-themed servers (e.g. Sakhal) so cold-water fish actually feed and warm-water fish back off; use POSITIVE values for tropical/summer servers. Default 0 = use ambient air temp unchanged. This shifts the curve globally without editing every fish's TempOptimal/TempMin/TempMax. Examples: 0 = vanilla Chernarus (bass active in summer, trout in spring/fall); -5 = cold map like Sakhal (lake trout/salmon/cod active year-round, bass struggles); -10 = frozen lake roleplay (only cold-water species feed); +5 = tropical mod (reef fish/marlin/mahi dominate, trout shut down).";
    float WaterTempOffset = 0.0;

    string BiteSpeedEnableInfo = "Master toggle for the per-fish BiteSpeed cycle scaling. Each fish has a 24-hour BiteSpeed array (e.g. CarpConf.BiteSpeed = {0.85, 0.85, ..., 1.0, ...}) where 1.0 means the fish bites at its natural speed for that hour and 0.5 means the cycle takes twice as long. The catching context aggregates these across the active fish pool, weighted by per-fish CatchProbability and the current time-of-day multiplier, then stretches the catch cycle inversely so lower aggregates mean longer waits between bites. Set to 0 to bypass entirely and use vanilla DayZ cycle length regardless of which fish are in the pool -- the per-fish BiteSpeed arrays still appear in JSON for tuning but have no in-game effect. Independent of WeatherCatchBoostEnable, MoonPhaseEnable, and TemperatureEffectEnable. Useful for servers wanting a flat fishing experience without per-hour variance, or for isolating whether a tuning issue is coming from BiteSpeed math vs other multipliers.";
    bool BiteSpeedEnable = 1;

    string SpeciesBuffsInfo = "Per-species multipliers are configured inline on each fish section below (RainMultiplier, StormMultiplier, DawnMultiplier, DayMultiplier, DuskMultiplier, NightMultiplier, TempOptimal, TempMin, TempMax). 1.0 = no effect, higher = bites more, lower = bites less.";
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

// Bamboo fishing net spawn-table entry. Mirrors BugEntry's Classname /
// CatchChance contract so existing JSON migrates without edits (a server's
// fishingsettings.json from before this split will deserialize cleanly), but
// adds an Environment field so the same Catches array can hold both
// freshwater and saltwater entries. 1=pond, 2=sea, 3=both. Entries whose
// Environment doesn't match the current water surface are skipped before
// the weighted roll.
class NetEntry {
    string Classname;
    float CatchChance;
    int Environment = 1;
}

// One per fish that a given bait/lure favours. Multiplier > 1.0 makes the
// fish more likely to be the selected catch when this bait is on the hook;
// < 1.0 makes it less likely. 1.0 = neutral, same as omitting the entry.
class BaitPreferenceEntry {
    string FishClassname;
    float Multiplier = 1.0;
}

// Bait-side container: each bait/lure classname owns a list of fish it
// favours. Lookups default to 1.0 (no bias) when the current bait is not
// in BaitPreferences at all, or when the bait is configured but the
// specific fish isn't listed. So admins can opt in incrementally without
// listing every fish-bait pair.
class BaitConfig {
    string BaitClassname;
    ref array<ref BaitPreferenceEntry> Preferences;

    void BaitConfig() {
        Preferences = new array<ref BaitPreferenceEntry>();
    }
}

// Settings for ActionBambooFishingNet. Owns the per-attempt find-chance
// roll, the predator-spawn chance after the action completes, and the
// weighted Catches table.
class BambooFishingNetConf {
    string FindChanceInfo = "Per-attempt probability the net produces any catch. 0-1; 1.0 = always finds, 0.0 = never finds.";
    float FindChance = 0.5;

    string PredatorChanceInfo = "Per-attempt probability of a predator spawning after the net action completes, independent of the catch roll.";
    float PredatorSpawnChance = 0.01;

    string CatchesInfo = "Weighted spawn table. Environment: 1=pond, 2=sea, 3=both. Entries whose Environment doesn't match the cast surface are skipped before the weighted roll.";
    ref array<ref NetEntry> Catches;

    void BambooFishingNetConf() {
        // Allocate so consumers can iterate without an extra null guard.
        Catches = new array<ref NetEntry>();
    }
}

// Settings for ActionDigBugs. Owns the per-attempt find-chance roll and
// the weighted Catches table.
class DigBugsConf {
    string FindChanceInfo = "Per-attempt probability the bug catcher action produces any catch. 0-1; 1.0 = always finds, 0.0 = never finds.";
    float FindChance = 0.65;

    string CatchesInfo = "Weighted spawn table for the bug catcher action. Empty by default -- admins fill in classnames + chances.";
    ref array<ref BugEntry> Catches;

    void DigBugsConf() {
        Catches = new array<ref BugEntry>();
    }
}

// Settings for ActionDigWorms. Owns the per-slot find-chance roll and
// the weighted Catches table.
class DigWormsConf {
    string FindChanceInfo = "Per-slot probability the dig-worms action produces a worm in each dirt slot. 0-1.";
    float FindChance = 0.85;

    string CatchesInfo = "Weighted spawn table for the worm digging action.";
    ref array<ref BugEntry> Catches;

    void DigWormsConf() {
        Catches = new array<ref BugEntry>();
    }
}

//fish config data
class MackerelConf {
    float TempOptimal = 18.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.95, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.95, 1, 1, 0.95, 0.95, 0.9, 0.9, 0.85};
};
class CarpConf {
    float TempOptimal = 24.0;
    float TempMin = 14.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.95, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.95, 1, 1, 0.95, 0.95, 0.9, 0.9, 0.85};
};
class SardinesConf {
    float TempOptimal = 18.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 24;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class BitterlingsConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 24;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class WalleyePollockConf {
    float TempOptimal = 8.0;
    float TempMin = 1.0;
    float TempMax = 14.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.1;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class SteelheadTroutConf {
    float TempOptimal = 13.0;
    float TempMin = 4.0;
    float TempMax = 20.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float DawnMultiplier = 1.5;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class ShrimpConf {
    float TempOptimal = 20.0;
    float TempMin = 12.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float DawnMultiplier = 0.9;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class NorthernSnakeHeadConf {
    float TempOptimal = 21.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class NorthernPikeConf {
    float TempOptimal = 18.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class MuskellungeConf {
    float TempOptimal = 19.0;
    float TempMin = 10.0;
    float TempMax = 25.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class SpottedMuskellungeConf {
    float TempOptimal = 19.0;
    float TempMin = 10.0;
    float TempMax = 25.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class BarredMuskellungeConf {
    float TempOptimal = 19.0;
    float TempMin = 10.0;
    float TempMax = 25.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class TigerMuskellungeConf {
    float TempOptimal = 19.0;
    float TempMin = 10.0;
    float TempMax = 25.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class AlligatorGarConf {
    float TempOptimal = 26.0;
    float TempMin = 16.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class LargeMouthBassConf {
    float TempOptimal = 24.0;
    float TempMin = 14.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.1;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class SmallMouthBassConf {
    float TempOptimal = 21.0;
    float TempMin = 12.0;
    float TempMax = 27.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.1;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class WallEyeConf {
    float TempOptimal = 18.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.7;
    float DuskMultiplier = 1.5;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class SunFishConf {
    float TempOptimal = 25.0;
    float TempMin = 15.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 0.9;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class WhiteBassConf {
    float TempOptimal = 21.0;
    float TempMin = 12.0;
    float TempMax = 27.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.95, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.95, 1, 1, 0.95, 0.95, 0.9, 0.9, 0.85};
};
class BlackBassConf {
    float TempOptimal = 23.0;
    float TempMin = 13.0;
    float TempMax = 29.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class StripedBassConf {
    float TempOptimal = 20.0;
    float TempMin = 10.0;
    float TempMax = 26.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class NeoshoBassConf {
    float TempOptimal = 22.0;
    float TempMin = 13.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class RainbowTroutConf {
    float TempOptimal = 14.0;
    float TempMin = 4.0;
    float TempMax = 21.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float DawnMultiplier = 1.5;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class BrownTroutConf {
    float TempOptimal = 14.0;
    float TempMin = 4.0;
    float TempMax = 21.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float DawnMultiplier = 1.5;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class BrookTroutConf {
    float TempOptimal = 13.0;
    float TempMin = 4.0;
    float TempMax = 20.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float DawnMultiplier = 1.5;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class LakeTroutConf {
    float TempOptimal = 10.0;
    float TempMin = 2.0;
    float TempMax = 16.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.1;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class CutThroatTroutConf {
    float TempOptimal = 13.0;
    float TempMin = 4.0;
    float TempMax = 20.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.4;
    float DawnMultiplier = 1.5;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class LakeSturgeonConf {
    float TempOptimal = 15.0;
    float TempMin = 5.0;
    float TempMax = 22.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.95, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.95, 1, 1, 0.95, 0.95, 0.9, 0.9, 0.85};
};
class YellowPerchConf {
    float TempOptimal = 19.0;
    float TempMin = 10.0;
    float TempMax = 25.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 21;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class FlatHeadCatFishConf {
    float TempOptimal = 26.0;
    float TempMin = 16.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.7;
    float DuskMultiplier = 1.4;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.6;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class FatHeadMinnowConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 25;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class AmericanBullFrogConf {
    float TempOptimal = 25.0;
    float TempMin = 15.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.5;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.5;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class RedSalamanderConf {
    float TempOptimal = 15.0;
    float TempMin = 6.0;
    float TempMax = 22.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 5;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.6;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class BlueGillConf {
    float TempOptimal = 25.0;
    float TempMin = 15.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 22;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 0.9;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class SaugerConf {
    float TempOptimal = 18.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 0.7;
    float DuskMultiplier = 1.5;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.8, 0.75, 0.7, 0.7, 0.9, 1, 1, 0.85, 0.7, 0.6, 0.5, 0.5, 0.5, 0.5, 0.6, 0.75, 0.9, 1, 1, 1, 0.95, 0.9, 0.85};
};
class BowFinConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class SlimySculpinConf {
    float TempOptimal = 10.0;
    float TempMin = 2.0;
    float TempMax = 16.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.95, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.95, 1, 1, 0.95, 0.95, 0.9, 0.9, 0.85};
};
class SeverumConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class SignalCrayFishConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class EuropeanCrayFishConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class CaveCrayFishConf {
    float TempOptimal = 12.0;
    float TempMin = 4.0;
    float TempMax = 18.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 2;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class FloridaCrayFishConf {
    float TempOptimal = 25.0;
    float TempMin = 15.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class MonongahelaCrayFishConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class RedSwampCrayFishConf {
    float TempOptimal = 24.0;
    float TempMin = 14.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class RustyCrayFishConf {
    float TempOptimal = 22.0;
    float TempMin = 12.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class MahiMahiConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 7;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.5;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class AtlanticSailFishConf {
    float TempOptimal = 27.0;
    float TempMin = 21.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 4;
    int MeatMax = 7;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class AngelFishConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.8;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class AsianSeaBassConf {
    float TempOptimal = 28.0;
    float TempMin = 20.0;
    float TempMax = 33.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class AtlanticBlueMarlinConf {
    float TempOptimal = 26.0;
    float TempMin = 20.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 3;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.2;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.4;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class BonitaConf {
    float TempOptimal = 22.0;
    float TempMin = 14.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class CherrySalmonConf {
    float TempOptimal = 12.0;
    float TempMin = 4.0;
    float TempMax = 18.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 6;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class ChinookSalmonConf {
    float TempOptimal = 12.0;
    float TempMin = 4.0;
    float TempMax = 18.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class SockEyeSalmonConf {
    float TempOptimal = 13.0;
    float TempMin = 4.0;
    float TempMax = 18.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float DawnMultiplier = 1.4;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.6, 0.55, 0.5, 0.5, 0.55, 0.85, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55, 0.55, 0.55, 0.6, 0.7, 0.9, 1, 1, 0.95, 0.85, 0.75, 0.65};
};
class FlatHeadMulletConf {
    float TempOptimal = 25.0;
    float TempMin = 15.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 18;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.3;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class LeopardSharkConf {
    float TempOptimal = 18.0;
    float TempMin = 10.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class HammerHeadSharkConf {
    float TempOptimal = 26.0;
    float TempMin = 18.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 4;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class PacificCodConf {
    float TempOptimal = 8.0;
    float TempMin = 2.0;
    float TempMax = 14.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class RedHeadCichlidConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.1;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class RoughNeckRockConf {
    float TempOptimal = 17.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class BlueTangConf {
    float TempOptimal = 26.0;
    float TempMin = 20.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class LargeHeadHairTailFishConf {
    float TempOptimal = 17.0;
    float TempMin = 8.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 5;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class HumpHeadWrasseConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 5;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 4;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 0.9;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.2;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 0.8;
    float NightMultiplier = 0.8;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.4, 0.4, 0.4, 0.4, 0.45, 0.6, 0.75, 0.9, 1, 1, 1, 1, 1, 1, 1, 0.95, 0.85, 0.75, 0.6, 0.5, 0.45, 0.4, 0.4, 0.4};
};
class SiameseTigerFishConf {
    float TempOptimal = 27.0;
    float TempMin = 20.0;
    float TempMax = 32.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 3;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 6;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.1;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class GreatWhiteSharkConf {
    float TempOptimal = 17.0;
    float TempMin = 10.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 5;
    int MeatMax = 10;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 2;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.2;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class AngelSharkConf {
    float TempOptimal = 18.0;
    float TempMin = 10.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 3;
    int MeatMax = 8;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.5;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class YellowFinTunaConf {
    float TempOptimal = 25.0;
    float TempMin = 18.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 8;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class YellowSnapperConf {
    float TempOptimal = 25.0;
    float TempMin = 18.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 13;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.3;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class SouthernFlounderConf {
    float TempOptimal = 18.0;
    float TempMin = 10.0;
    float TempMax = 24.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 11;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.1;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.3;
    float StormMultiplier = 1.3;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class WhiteGruntConf {
    float TempOptimal = 25.0;
    float TempMin = 18.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 1;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 2;
    int MeatMax = 6;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.2;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.2;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.5, 0.5, 0.5, 0.55, 0.6, 0.75, 0.9, 1, 1, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.9, 0.95, 1, 1, 0.9, 0.8, 0.7, 0.6, 0.55};
};
class BloodClamConf {
    float TempOptimal = 18.0;
    float TempMin = 4.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 4;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int BoneMin = 1;
    int BoneMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 14;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.95, 0.95, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.9, 0.9, 0.9, 0.95, 0.95, 0.95};
};
class MusselConf {
    float TempOptimal = 16.0;
    float TempMin = 4.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 3;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int BoneMin = 1;
    int BoneMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 20;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.1;
    float NightMultiplier = 0.9;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {0.95, 0.95, 0.95, 0.9, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.85, 0.9, 0.9, 0.9, 0.95, 0.95, 0.95};
};
class BlackDevilSnailConf {
    float TempOptimal = 22.0;
    float TempMin = 10.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 1;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 10;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.2;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class StarFishConf {
    float TempOptimal = 16.0;
    float TempMin = 4.0;
    float TempMax = 28.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string BoneInfo = "BoneMin and BoneMax determine the minimum and maximum Bone pieces for the prepare action. DayZ has a hard limit of 10 bones max.";
    int BoneMin = 1;
    int BoneMax = 1;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 16;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 1.0;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.0;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};
class KingCrabConf {
    float TempOptimal = 5.0;
    float TempMin = 0.0;
    float TempMax = 12.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 5;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class SnowCrabConf {
    float TempOptimal = 4.0;
    float TempMin = 0.0;
    float TempMax = 10.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 7;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.1;
    float NightMultiplier = 1.3;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class BlueJellyFishConf {
    float TempOptimal = 20.0;
    float TempMin = 8.0;
    float TempMax = 30.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 12;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.9;
    float DuskMultiplier = 1.0;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class AmericanLobsterConf {
    float TempOptimal = 12.0;
    float TempMin = 4.0;
    float TempMax = 18.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
};
class EuropeanLobsterConf {
    float TempOptimal = 14.0;
    float TempMin = 5.0;
    float TempMax = 20.0;
    string EnvironmentInfo = "1 - pond, 2 - sea, 3 - both";
    int Environment = 2;
    string CatchMethodInfo = "1 - rod, 2 - largetrap, 3 - rod and largetrap, 4 - smalltrap, 5 - rod and smalltrap, 6 - largetrap and smalltrap, 7 - rod, largetrap and smalltrap";
    int CatchMethod = 6;
    string MeatInfo = "MeatMin and MeatMax determine the minimum and maximum meat pieces for the fillet action. DayZ has a hard limit of 10 fillets max.";
    int MeatMin = 1;
    int MeatMax = 2;
    string CatchProbInfo = "0-25; 0 means no chance to catch fish, 25 means high chance";
    int CatchProbability = 9;
    string WeatherMultiplierInfo = "Per-species rain/storm/dawn/day/dusk/night multipliers, applied on top of WeatherSettings global multipliers. 1.0 = no effect, higher = bites more in that condition, lower = bites less.";
    float RainMultiplier = 1.0;
    float DawnMultiplier = 1.0;
    float DayMultiplier = 0.8;
    float DuskMultiplier = 1.1;
    float StormMultiplier = 1.0;
    float NightMultiplier = 1.4;
    string BiteSpeedInfo = "Hour-of-day bite speed for the catch cycle, 24 values indexed 0=12AM ... 23=11PM. Range 0.0-1.0 where 1.0 = vanilla baseline (no slowdown) and lower = longer wait for that hour. Aggregated across all yields in the active pool, weighted by CatchProbability and time-of-day multiplier.";
    autoptr TFloatArray BiteSpeed = {1, 1, 1, 0.95, 0.85, 0.75, 0.65, 0.55, 0.5, 0.45, 0.45, 0.45, 0.45, 0.45, 0.5, 0.55, 0.65, 0.75, 0.85, 0.9, 1, 1, 1, 1};
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
