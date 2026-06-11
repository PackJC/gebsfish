/* ============================================================================
   Gebsfish config -- four JSON files + a keyed fish table.
   - general.json  -> GeneralConfig (mechanics / actions / predators / weather)
   - bait.json     -> BaitSettingsConf (per-bait fish-preference table)
   - junk.json     -> JunkConfig (world-junk + container-junk tables)
   - fish.json     -> FishConfig (the keyed Species table + catch tuning)
   The gebsfishConfig facade owns all four; GetGebSettingsConfig() returns it.
   Each class seeds its own defaults on a cold start via SeedDefaults() and
   backfills any missing section on load via Backfill().
   ============================================================================ */

// ---- one fish row ----------------------------------------------------------
class FishConf {
    string Classname;          // catch/spawn classname + recipe ingredient
    int    RecipeShape;        // 0 fillet | 1 caviar | 2 lobster  (NOT 'Shape' -- collides with an engine type)
    string ResultMain;         // repeated result (fillet meat / lobster claws); "" = no recipe
    string ResultBonus;        // single index-0 result (caviar / lobster tail); "" for RecipeShape 0
    int    MeatMin;
    int    MeatMax;
    int    Environment;        // 1 pond | 2 sea | 3 both
    int    CatchMethod;        // rod/trap bitmask
    int    CatchProbability;   // 0-25
    float  RainMultiplier;
    float  StormMultiplier;
    float  DawnMultiplier;
    float  DayMultiplier;
    float  DuskMultiplier;
    float  NightMultiplier;
    float  TempOptimal;
    float  TempMin;
    float  TempMax;
    // BiteSpeed is 24 hourly values stored as a space-separated STRING, not a
    // dynamic float array. DayZ's JsonFileLoader access-violates deserializing a
    // ref array<float> member that lives inside an array<ref FishConf> element
    // -- numeric arrays in array-element classes must be static (vanilla's
    // "float pos[3]") or, as here, a string. Every other array-element config
    // (PredatorEntry/NetEntry/BaitConfig) avoids a dynamic primitive array,
    // which is why only fish.json crashed on read. GetBiteSpeedArray() parses
    // it back into a TFloatArray for runtime use.
    string BiteSpeed;

    void FishConf() { }

    TFloatArray GetBiteSpeedArray() {
        TFloatArray arr = new TFloatArray();
        TStringArray parts = new TStringArray();
        BiteSpeed.Split(" ", parts);
        foreach (string s : parts) {
            if (s != "") arr.Insert(s.ToFloat());
        }
        return arr;
    }
}

// ===========================================================================
// FILE 1: general.json
// ===========================================================================
class GeneralConfig {
    string ConfigVersionInfo = "Mod config version this file was written with. Do NOT edit -- used to migrate the file on mod updates.";
    string ConfigVersion = "";
    string GeneralSettingsInfo = "Global mod settings (each field inside has its own *Info): debug log level, fish quality, knife fillet speed, caviar chance, and the hook-from-fish toggle/chance.";
    ref GenSetConf                    GeneralSettings;
    string RecipeTogglesInfo = "Enable(1)/disable(0) the gebsfish craft/repair recipes (one bool per recipe inside).";
    ref RecipeToggleConf              RecipeToggles;
    string HookFromFishCatchesInfo = "Weighted pool of hooks 'found' stuck in a fish while filleting (gated by GeneralSettings.HookFromFishEnable/Chance). Each entry: Classname (hook/lure to give), Weight (relative odds; 0 disables that entry), MinHealthLevel/MaxHealthLevel (0 pristine .. 4 ruined).";
    ref array<ref HookFromFishEntry>  HookFromFishCatches;
    string PredatorSettingsInfo = "Predator-spawn settings: per-activity chances, enable toggle, and warning sound/message options (each field has its own *Info).";
    ref PredatorConf                  PredatorSettings;
    string PredatorsInfo = "Weighted pool of predators that can spawn. Each entry: Classname (animal), SpawnChance (relative weight), MinCount/MaxCount (how many), MinRadius/MaxRadius (metres from the player to spawn).";
    ref array<ref PredatorEntry>      Predators;
    string BambooFishingNetSettingsInfo = "Bamboo-net action: FindChance (0-1 per cast), PredatorSpawnChance, and a Catches table (each entry: Classname, CatchChance, Environment 1 pond/2 sea/3 both).";
    ref BambooFishingNetConf          BambooFishingNetSettings;
    string DigBugsSettingsInfo = "Dig-for-bugs action: FindChance (0-1) plus a Catches table (each entry: Classname, CatchChance).";
    ref DigBugsConf                   DigBugsSettings;
    string DigWormsSettingsInfo = "Dig-for-worms action: FindChance (0-1) plus a Catches table (each entry: Classname, CatchChance).";
    ref DigWormsConf                  DigWormsSettings;
    string WeatherSettingsInfo = "Global weather/time-of-day/temperature/moon catch modifiers and their thresholds (each field has its own *Info inside).";
    ref WeatherConf                   WeatherSettings;

    private const static string PATH = "$profile:Gebs/general.json";

    void Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<GeneralConfig>.LoadFile(PATH, this, err))
                GebsfishLogger.Error("general.json failed to load: " + err, "Config");
            changed = Backfill();
            if (ConfigVersion != VERSION_GEBSFISH) { ConfigVersion = VERSION_GEBSFISH; changed = true; }
        } else {
            SeedDefaults();
            changed = true;
        }
        // Only write the file back when something actually changed (fresh
        // generation, a backfilled section, or a version bump). A valid,
        // up-to-date file is left untouched -- no rewrite, no mtime change.
        if (changed) Save();
    }
    void Save() { JsonFileLoader<GeneralConfig>.JsonSaveFile(PATH, this); }

    // Returns true if any missing section had to be allocated/seeded, so Load
    // can decide whether to persist. Existing values are never overwritten.
    bool Backfill() {
        bool changed = false;
        if (!GeneralSettings)          { GeneralSettings = new GenSetConf;       changed = true; }
        if (!RecipeToggles)            { RecipeToggles = new RecipeToggleConf;   changed = true; }
        if (!PredatorSettings)         { PredatorSettings = new PredatorConf;    changed = true; }
        if (!WeatherSettings)          { WeatherSettings = new WeatherConf;      changed = true; }
        // A per-action section that is entirely missing (fresh key never
        // written, or hand-deleted) is re-seeded with working defaults. A
        // section that exists but was emptied on purpose is left alone.
        if (!BambooFishingNetSettings) { SeedDefaultNetCatches();       changed = true; }
        if (!DigBugsSettings)          { SeedDefaultDigBugsCatches();   changed = true; }
        if (!DigWormsSettings)         { SeedDefaultDigWormsCatches();  changed = true; }
        if (!Predators)                { SeedDefaultPredators();        changed = true; }
        if (!HookFromFishCatches || HookFromFishCatches.Count() == 0) { SeedHookFromFish(); changed = true; }
        return changed;
    }

    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        GeneralSettings = new GenSetConf;
        RecipeToggles = new RecipeToggleConf;
        PredatorSettings = new PredatorConf;
        WeatherSettings = new WeatherConf;
        BambooFishingNetSettings = new BambooFishingNetConf;
        DigBugsSettings = new DigBugsConf;
        DigWormsSettings = new DigWormsConf;
        SeedHookFromFish();
        SeedDefaultPredators();
        SeedDefaultNetCatches();
        SeedDefaultDigBugsCatches();
        SeedDefaultDigWormsCatches();
    }

    void SeedHookFromFish() {
        if (!HookFromFishCatches) HookFromFishCatches = new array<ref HookFromFishEntry>();
        HookFromFishEntry h = new HookFromFishEntry();
        h.Classname = "FishingHook"; h.Weight = 1.0; h.MinHealthLevel = 3; h.MaxHealthLevel = 3;
        HookFromFishCatches.Insert(h);
    }

    // ---- default seed tables ----
    void SeedDefaultPredators() {
        if (!Predators) Predators = new array<ref PredatorEntry>();
        PredatorEntry wolf = new PredatorEntry();
        wolf.Classname = "Animal_CanisLupus_Grey"; wolf.SpawnChance = 0.6; wolf.MinCount = 1; wolf.MaxCount = 1; wolf.MinRadius = 50; wolf.MaxRadius = 200;
        Predators.Insert(wolf);
        PredatorEntry bear = new PredatorEntry();
        bear.Classname = "Animal_UrsusArctos"; bear.SpawnChance = 0.3; bear.MinCount = 1; bear.MaxCount = 1; bear.MinRadius = 100; bear.MaxRadius = 300;
        Predators.Insert(bear);
    }

    void SeedDefaultNetCatches() {
        if (!BambooFishingNetSettings) BambooFishingNetSettings = new BambooFishingNetConf;
        if (!BambooFishingNetSettings.Catches) BambooFishingNetSettings.Catches = new array<ref NetEntry>();
        NetEntry minnow = new NetEntry();     minnow.Classname = "geb_FatHeadMinnow";    minnow.CatchChance = 1.0;     minnow.Environment = 1;     BambooFishingNetSettings.Catches.Insert(minnow);
        NetEntry frog = new NetEntry();       frog.Classname = "geb_AmericanBullFrog";   frog.CatchChance = 1.0;       frog.Environment = 1;       BambooFishingNetSettings.Catches.Insert(frog);
        NetEntry salamander = new NetEntry(); salamander.Classname = "geb_RedSalamander"; salamander.CatchChance = 1.0; salamander.Environment = 1; BambooFishingNetSettings.Catches.Insert(salamander);
    }

    void SeedDefaultDigBugsCatches() {
        if (!DigBugsSettings) DigBugsSettings = new DigBugsConf;
        if (!DigBugsSettings.Catches) DigBugsSettings.Catches = new array<ref BugEntry>();
        BugEntry cricket = new BugEntry(); cricket.Classname = "geb_FieldCricket"; cricket.CatchChance = 0.25; DigBugsSettings.Catches.Insert(cricket);
        BugEntry hopper = new BugEntry();  hopper.Classname = "geb_GrassHopper";   hopper.CatchChance = 0.25;  DigBugsSettings.Catches.Insert(hopper);
        BugEntry grub = new BugEntry();    grub.Classname = "geb_GrubWorm";        grub.CatchChance = 0.75;    DigBugsSettings.Catches.Insert(grub);
        BugEntry worm = new BugEntry();    worm.Classname = "Worm";                worm.CatchChance = 0.25;    DigBugsSettings.Catches.Insert(worm);
    }

    void SeedDefaultDigWormsCatches() {
        if (!DigWormsSettings) DigWormsSettings = new DigWormsConf;
        if (!DigWormsSettings.Catches) DigWormsSettings.Catches = new array<ref BugEntry>();
        BugEntry worm = new BugEntry(); worm.Classname = "Worm";         worm.CatchChance = 0.75; DigWormsSettings.Catches.Insert(worm);
        BugEntry grub = new BugEntry(); grub.Classname = "geb_GrubWorm"; grub.CatchChance = 0.25; DigWormsSettings.Catches.Insert(grub);
    }

}

// Bait-preference block: the master toggle + its info live WITH the table they
// control (parallel to BambooFishingNetSettings = FindChance + Catches).
class BaitSettingsConf {
    string ConfigVersionInfo = "Mod config version this file was written with. Do NOT edit -- used to migrate the file on mod updates.";
    string ConfigVersion = "";
    string EnableInfo = "Master toggle for the bait / lure preference system. Each entry in Preferences pairs a bait classname (Worm, geb_GrubWorm, geb_SpinnerBait1, etc.) with a list of per-fish multipliers that bias the weighted catch pick toward that fish when this bait is on the hook (e.g. a Worm makes BlueGill 2.0x more likely while making large saltwater fish 0.3x). Set to 0 to disable the bias entirely -- every bait becomes neutral 1.0x for every fish and only the underlying CatchProbability values drive the pick. Bait still functions mechanically (gets eaten/destroyed, hook still loses bait on a miss) -- this only disables the per-fish bias. Preferences still loads from JSON when disabled so a server can flip this on/off without losing tuned values. Useful when admins want bait to function but not influence catch outcomes, or for diagnosing whether unexpected fish are coming from bait bias vs weather/temperature/time-of-day multipliers.";
    bool Enable = 1;
    string PreferencesInfo = "Per-bait fish-preference table. Each entry pairs a bait/lure Classname with its own list of per-fish multipliers (the entry's Preferences array, each: a fish classname + a multiplier). Multiplier >1 = that fish is more likely on this bait, <1 = less, 1.0 = neutral. Only applied when Enable = 1.";
    ref array<ref BaitConfig> Preferences;

    private const static string PATH = "$profile:Gebs/bait.json";
    void Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<BaitSettingsConf>.LoadFile(PATH, this, err))
                GebsfishLogger.Error("bait.json failed to load: " + err, "Config");
            if (!Preferences) { SeedDefaultPreferences(); changed = true; }
            if (ConfigVersion != VERSION_GEBSFISH) { ConfigVersion = VERSION_GEBSFISH; changed = true; }
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
    }
    void Save() { JsonFileLoader<BaitSettingsConf>.JsonSaveFile(PATH, this); }
    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        Enable = true;
        SeedDefaultPreferences();
    }
    // Seed the default bait ecology. Each SeedBait row pairs a bait classname
    // with its 13 category multipliers; the JSON output still lists every
    // fish-bait pair so admins can tune individual entries.
    void SeedDefaultPreferences() {
        Preferences = new array<ref BaitConfig>();
        EnsureCategories();

        // Column order: panfish, bass, pike/musky, walleye, trout/salmon,
        // catfish/bottom, carp, amphibian, baitfish, saltwater-large,
        // saltwater-med, saltwater-small, reef/tropical.
        SeedBait("Worm",              2.0, 1.4, 0.6, 1.2, 1.6, 1.5, 2.0, 0.5, 1.2, 0.3, 0.5, 0.7, 0.6);
        SeedBait("geb_GrassHopper",   1.5, 1.4, 0.4, 0.8, 2.0, 0.7, 1.0, 1.8, 0.9, 0.3, 0.4, 0.6, 0.6);
        SeedBait("geb_FieldCricket",  1.5, 1.4, 0.4, 0.8, 2.0, 0.7, 1.0, 1.8, 0.9, 0.3, 0.4, 0.6, 0.6);
        SeedBait("geb_GrubWorm",      2.0, 1.4, 0.5, 1.3, 1.8, 1.3, 1.4, 1.0, 1.1, 0.3, 0.5, 0.7, 0.7);
        SeedBait("geb_RubberWorm",    0.6, 2.5, 1.3, 1.5, 0.7, 0.7, 0.4, 0.4, 0.6, 0.3, 0.4, 0.4, 0.4);
        SeedBait("geb_FatHeadMinnow", 0.7, 2.0, 2.5, 2.5, 1.5, 1.8, 0.4, 1.0, 0.8, 1.0, 0.8, 0.5, 0.4);
        SeedBait("geb_RedSalamander", 0.4, 2.0, 2.0, 1.5, 1.0, 2.5, 0.3, 0.4, 0.6, 0.5, 0.5, 0.4, 0.3);

        // The numbered variants within a lure family share one tuning.
        int i;
        for (i = 1; i <= 4; i++) SeedBait("geb_SpinnerBait" + i,  0.8, 2.5, 2.3, 2.0, 1.5, 1.0, 0.3, 0.5, 1.0, 0.8, 1.0, 1.2, 0.6);
        for (i = 1; i <= 4; i++) SeedBait("geb_SpoonLure" + i,    0.6, 1.5, 2.0, 1.8, 2.5, 0.8, 0.3, 0.4, 1.0, 1.8, 2.0, 1.5, 1.0);
        for (i = 1; i <= 4; i++) SeedBait("geb_Lure" + i,         0.7, 2.0, 1.8, 1.8, 1.5, 1.0, 0.3, 0.5, 1.0, 1.3, 1.5, 1.0, 0.7);
        for (i = 1; i <= 4; i++) SeedBait("geb_CurlyTailJig" + i, 1.5, 2.2, 1.3, 2.0, 1.0, 0.8, 0.5, 0.5, 1.0, 0.7, 1.0, 0.8, 0.6);
    }

    // Fish-category buckets shared by every SeedBait row. Static so they are
    // built once and never serialized into bait.json.
    protected static ref array<string> s_CatPanfish;
    protected static ref array<string> s_CatBass;
    protected static ref array<string> s_CatPikeMusky;
    protected static ref array<string> s_CatWalleye;
    protected static ref array<string> s_CatTroutSalmon;
    protected static ref array<string> s_CatCatfishBottom;
    protected static ref array<string> s_CatCarp;
    protected static ref array<string> s_CatAmphibian;
    protected static ref array<string> s_CatBaitFish;
    protected static ref array<string> s_CatSaltwaterLarge;
    protected static ref array<string> s_CatSaltwaterMed;
    protected static ref array<string> s_CatSaltwaterSmall;
    protected static ref array<string> s_CatReefTropical;

    protected static void EnsureCategories() {
        if (s_CatPanfish)
            return;
        s_CatPanfish = {"geb_BlueGill", "geb_SunFish", "geb_YellowPerch", "Bitterlings"};
        s_CatBass = {"geb_LargeMouthBass", "geb_SmallMouthBass", "geb_BlackBass", "geb_NeoshoBass", "geb_StripedBass", "geb_WhiteBass"};
        s_CatPikeMusky = {"geb_NorthernPike", "geb_Muskellunge", "geb_BarredMuskellunge", "geb_SpottedMuskellunge", "geb_TigerMuskellunge", "geb_NorthernSnakeHead", "geb_BowFin"};
        s_CatWalleye = {"geb_WallEye", "geb_Sauger"};
        s_CatTroutSalmon = {"SteelheadTrout", "geb_BrookTrout", "geb_BrownTrout", "geb_RainbowTrout", "geb_CutThroatTrout", "geb_LakeTrout", "geb_ChinookSalmon", "geb_CherrySalmon", "geb_SockEyeSalmon"};
        s_CatCatfishBottom = {"geb_FlatHeadCatFish", "geb_AlligatorGar", "geb_LakeSturgeon"};
        s_CatCarp = {"Carp"};
        s_CatAmphibian = {"geb_AmericanBullFrog", "geb_RedSalamander"};
        s_CatBaitFish = {"geb_FatHeadMinnow", "geb_FlatHeadMullet", "geb_SlimySculpin"};
        s_CatSaltwaterLarge = {"geb_GreatWhiteShark", "geb_HammerHeadShark", "geb_AngelShark", "geb_LeopardShark", "geb_AtlanticBlueMarlin", "geb_AtlanticSailFish", "geb_YellowFinTuna"};
        s_CatSaltwaterMed = {"geb_AsianSeaBass", "geb_Bonita", "geb_MahiMahi", "geb_RoughNeckRock", "geb_SiameseTigerFish", "WalleyePollock", "geb_PacificCod", "geb_LargeHeadHairTailFish", "geb_SouthernFlounder"};
        s_CatSaltwaterSmall = {"Mackerel", "Sardines", "geb_YellowSnapper", "geb_WhiteGrunt"};
        s_CatReefTropical = {"geb_AngelFish", "geb_BlueTang", "geb_HumpHeadWrasse", "geb_Severum", "geb_RedHeadCichlid"};
    }

    // Builds one bait entry from its 13 category multipliers and inserts it.
    protected void SeedBait(string baitName, float panfish, float bass, float pikeMusky, float walleye, float troutSalmon, float catfishBottom, float carp, float amphibian, float baitFish, float saltLarge, float saltMed, float saltSmall, float reefTropical) {
        BaitConfig bait = new BaitConfig();
        bait.BaitClassname = baitName;
        AppendBaitPrefsByCategory(bait, s_CatPanfish, panfish);
        AppendBaitPrefsByCategory(bait, s_CatBass, bass);
        AppendBaitPrefsByCategory(bait, s_CatPikeMusky, pikeMusky);
        AppendBaitPrefsByCategory(bait, s_CatWalleye, walleye);
        AppendBaitPrefsByCategory(bait, s_CatTroutSalmon, troutSalmon);
        AppendBaitPrefsByCategory(bait, s_CatCatfishBottom, catfishBottom);
        AppendBaitPrefsByCategory(bait, s_CatCarp, carp);
        AppendBaitPrefsByCategory(bait, s_CatAmphibian, amphibian);
        AppendBaitPrefsByCategory(bait, s_CatBaitFish, baitFish);
        AppendBaitPrefsByCategory(bait, s_CatSaltwaterLarge, saltLarge);
        AppendBaitPrefsByCategory(bait, s_CatSaltwaterMed, saltMed);
        AppendBaitPrefsByCategory(bait, s_CatSaltwaterSmall, saltSmall);
        AppendBaitPrefsByCategory(bait, s_CatReefTropical, reefTropical);
        Preferences.Insert(bait);
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
}

// junk.json: world-junk + container-junk catch tables.
class JunkConfig {
    string ConfigVersionInfo = "Mod config version this file was written with. Do NOT edit.";
    string ConfigVersion = "";
    string JunkInfo = "Weighted table of 'junk' items a rod/trap can pull instead of a fish. Each entry: Classname = item to spawn; CatchProbability = 0-25 weight in the catch pool; MinHealthLevel/MaxHealthLevel = health range, 0 pristine .. 4 ruined (the spawned item's health is rolled in this range).";
    ref array<ref JunkEntry>          Junk;
    string ContainerJunkInfo = "Like Junk, but for 'container' junk -- items spawned holding cargo (e.g. a tin can). Same fields: Classname, CatchProbability (0-25), MinHealthLevel/MaxHealthLevel (0-4).";
    ref array<ref ContainerJunkEntry> ContainerJunk;

    private const static string PATH = "$profile:Gebs/junk.json";
    void Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<JunkConfig>.LoadFile(PATH, this, err))
                GebsfishLogger.Error("junk.json failed to load: " + err, "Config");
            changed = Backfill();
            if (ConfigVersion != VERSION_GEBSFISH) { ConfigVersion = VERSION_GEBSFISH; changed = true; }
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
    }
    void Save() { JsonFileLoader<JunkConfig>.JsonSaveFile(PATH, this); }
    bool Backfill() {
        bool changed = false;
        if (!Junk)          { SeedDefaultJunk();          changed = true; }
        if (!ContainerJunk) { SeedDefaultContainerJunk(); changed = true; }
        return changed;
    }
    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        SeedDefaultJunk();
        SeedDefaultContainerJunk();
    }
    void SeedDefaultJunk() {
        if (!Junk) Junk = new array<ref JunkEntry>();
        JunkEntry brown = new JunkEntry(); brown.Classname = "Wellies_Brown"; brown.CatchProbability = 5; brown.MinHealthLevel = 3; brown.MaxHealthLevel = 3; Junk.Insert(brown);
        JunkEntry grey = new JunkEntry();  grey.Classname = "Wellies_Grey";   grey.CatchProbability = 5;  grey.MinHealthLevel = 3;  grey.MaxHealthLevel = 3;  Junk.Insert(grey);
        JunkEntry green = new JunkEntry(); green.Classname = "Wellies_Green"; green.CatchProbability = 5; green.MinHealthLevel = 3; green.MaxHealthLevel = 3; Junk.Insert(green);
        JunkEntry black = new JunkEntry(); black.Classname = "Wellies_Black"; black.CatchProbability = 5; black.MinHealthLevel = 3; black.MaxHealthLevel = 3; Junk.Insert(black);
    }
    void SeedDefaultContainerJunk() {
        if (!ContainerJunk) ContainerJunk = new array<ref ContainerJunkEntry>();
        ContainerJunkEntry pot = new ContainerJunkEntry(); pot.Classname = "Pot"; pot.CatchProbability = 5; pot.MinHealthLevel = 3; pot.MaxHealthLevel = 3; ContainerJunk.Insert(pot);
    }
}

// ===========================================================================
// FILE 4: fish.json  (just the Species table now)
// ===========================================================================
class FishConfig {
    string ConfigVersionInfo = "Mod config version this file was written with. Do NOT edit -- used to migrate the file on mod updates.";
    string ConfigVersion = "";
    // ENGINE LIMIT: ReadFromString access-violates (illegal read, stack smeared
    // with the string's tail) when any single string member exceeds ~1024 chars.
    // Bracketed empirically: 955 loads, 1458 crashed the server on every restart.
    // The limit applies to the DEFAULT literal too, not just the file value --
    // a long default crashes the load even when the on-disk value is short.
    // Keep every string literal in this file under ~900 chars.
    string SpeciesInfo = "One object per fish/catchable. Classname = catchable item classname (also the fillet-recipe ingredient). RecipeShape: 0 = fillet only, 1 = caviar (ResultBonus caviar at index 0, gated by GeneralSettings.CaviarChance), 2 = lobster (ResultBonus tail at index 0). ResultMain = repeated fillet/claw result classname ('' = catch-only, no recipe). MeatMin/MeatMax = fillets per prepare. Environment: 1 pond, 2 sea, 3 both. CatchMethod bitmask: 1 rod + 2 largetrap + 4 smalltrap, added together (7 = all). CatchProbability = 0-25 abundance weight (0 = uncatchable). Rain/Storm/Dawn/Day/Dusk/NightMultiplier = per-species catch-bias multipliers (1.0 = no effect). TempOptimal/TempMin/TempMax = water-temperature preference in degrees Celsius. BiteSpeed = 24 space-separated hourly bite-speed values (index 0 = 12AM), each 0.0-1.0 where 1.0 = vanilla speed.";
    ref array<ref FishConf>           Species;

    private const static string PATH = "$profile:Gebs/fish.json";

    FishConf Get(string classname) {
        if (!Species) return null;
        foreach (FishConf f : Species) if (f && f.Classname == classname) return f;
        return null;
    }

    void Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<FishConfig>.LoadFile(PATH, this, err))
                GebsfishLogger.Error("fish.json failed to load: " + err, "Config");
            changed = Backfill();
            if (ConfigVersion != VERSION_GEBSFISH) { ConfigVersion = VERSION_GEBSFISH; changed = true; }
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
    }
    void Save() { JsonFileLoader<FishConfig>.JsonSaveFile(PATH, this); }

    bool Backfill() {
        if (!Species || Species.Count() == 0) { SeedSpecies(); return true; }
        return false;
    }

    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        SeedSpecies();
    }

    void SeedSpecies() {
        Species = new array<ref FishConf>();
        SeedSpeciesA(); SeedSpeciesB(); SeedSpeciesC(); SeedSpeciesD(); SeedSpeciesE();
    }
    // ---- shared 24-hour BiteSpeed curves (index 0 = 12AM .. 23 = 11PM) ----
    // Each helper returns a FRESH array so no two fish share one instance.
    // Fastest 8PM-2AM, slowest midday -- catfish, crayfish, frogs, sharks, lobsters.
    protected string BiteNocturnal() { return "1 1 1 0.95 0.85 0.75 0.65 0.55 0.5 0.45 0.45 0.45 0.45 0.45 0.5 0.55 0.65 0.75 0.85 0.9 1 1 1 1"; }
    // Sharp dawn + dusk peaks, slow night and midday -- bass, trout, salmon.
    protected string BiteCrepuscular() { return "0.6 0.55 0.5 0.5 0.55 0.85 1 1 0.9 0.8 0.7 0.6 0.55 0.55 0.55 0.6 0.7 0.9 1 1 0.95 0.85 0.75 0.65"; }
    // Daytime cruiser: morning/evening peaks, holds ~0.85 midday -- tuna, marlin, mahi, cod.
    protected string BitePelagic() { return "0.5 0.5 0.5 0.55 0.6 0.75 0.9 1 1 0.95 0.9 0.85 0.85 0.85 0.85 0.9 0.95 1 1 0.9 0.8 0.7 0.6 0.55"; }
    // Full daytime plateau, very slow nights -- bluegill, perch, sunfish, minnows.
    protected string BiteDiurnal() { return "0.4 0.4 0.4 0.4 0.45 0.6 0.75 0.9 1 1 1 1 1 1 1 0.95 0.85 0.75 0.6 0.5 0.45 0.4 0.4 0.4"; }
    // Dawn/dusk peaks that stay strong into the night -- pike, muskies, walleye, sauger.
    protected string BiteTwilightNight() { return "0.85 0.8 0.75 0.7 0.7 0.9 1 1 0.85 0.7 0.6 0.5 0.5 0.5 0.5 0.6 0.75 0.9 1 1 1 0.95 0.9 0.85"; }
    // Gentle all-day rhythm, 0.85-1.0 -- carp, mackerel, sturgeon, sculpin.
    protected string BiteSteady() { return "0.85 0.85 0.85 0.85 0.9 0.95 1 1 0.95 0.9 0.9 0.9 0.9 0.9 0.9 0.9 0.95 1 1 0.95 0.95 0.9 0.9 0.85"; }
    // Near-flat ~0.85-0.95 -- filter feeders (blood clam, mussel).
    protected string BiteFilterFeeder() { return "0.95 0.95 0.95 0.9 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.85 0.9 0.9 0.9 0.95 0.95 0.95"; }
    // Flat 1.0 around the clock -- starfish.
    protected string BiteConstant() { return "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"; }
    void SeedSpeciesA() {
        FishConf f;
        // freshwater + vanilla
        f = new FishConf(); f.Classname="Mackerel"; f.RecipeShape=0; f.ResultMain="MackerelFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=22; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.1; f.DayMultiplier=1.0; f.DuskMultiplier=1.1; f.NightMultiplier=1.0; f.TempOptimal=18.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteSteady(); Species.Insert(f);
        f = new FishConf(); f.Classname="Carp"; f.RecipeShape=0; f.ResultMain="CarpFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=22; f.RainMultiplier=0.9; f.StormMultiplier=0.8; f.DawnMultiplier=1.2; f.DayMultiplier=0.9; f.DuskMultiplier=1.2; f.NightMultiplier=0.9; f.TempOptimal=24.0; f.TempMin=14.0; f.TempMax=30.0; f.BiteSpeed=BiteSteady(); Species.Insert(f);
        f = new FishConf(); f.Classname="Sardines"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=2; f.CatchMethod=6; f.CatchProbability=24; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=1.1; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=18.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="Bitterlings"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=1; f.CatchMethod=6; f.CatchProbability=24; f.RainMultiplier=1.1; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.1; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="WalleyePollock"; f.RecipeShape=0; f.ResultMain="WalleyePollockFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=20; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.1; f.NightMultiplier=1.1; f.TempOptimal=8.0; f.TempMin=1.0; f.TempMax=14.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="SteelheadTrout"; f.RecipeShape=1; f.ResultMain="SteelheadTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=9; f.RainMultiplier=1.4; f.StormMultiplier=1.3; f.DawnMultiplier=1.5; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=13.0; f.TempMin=4.0; f.TempMax=20.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="Shrimp"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=2; f.CatchMethod=6; f.CatchProbability=22; f.RainMultiplier=0.9; f.StormMultiplier=1.0; f.DawnMultiplier=0.9; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.3; f.TempOptimal=20.0; f.TempMin=12.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_NorthernSnakeHead"; f.RecipeShape=0; f.ResultMain="geb_NorthernSnakeHeadFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=5; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.2; f.DayMultiplier=0.8; f.DuskMultiplier=1.3; f.NightMultiplier=1.5; f.TempOptimal=21.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_NorthernPike"; f.RecipeShape=1; f.ResultMain="geb_NorthernPikeFilletMeat"; f.ResultBonus="geb_YellowCaviar"; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=8; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.4; f.TempOptimal=18.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BarredMuskellunge"; f.RecipeShape=1; f.ResultMain="geb_BarredMuskellungeFilletMeat"; f.ResultBonus="geb_YellowCaviar"; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=3; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.4; f.TempOptimal=19.0; f.TempMin=10.0; f.TempMax=25.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SpottedMuskellunge"; f.RecipeShape=1; f.ResultMain="geb_SpottedMuskellungeFilletMeat"; f.ResultBonus="geb_YellowCaviar"; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=3; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.4; f.TempOptimal=19.0; f.TempMin=10.0; f.TempMax=25.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_TigerMuskellunge"; f.RecipeShape=1; f.ResultMain="geb_TigerMuskellungeFilletMeat"; f.ResultBonus="geb_YellowCaviar"; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=3; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.4; f.TempOptimal=19.0; f.TempMin=10.0; f.TempMax=25.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_Muskellunge"; f.RecipeShape=1; f.ResultMain="geb_MuskellungeFilletMeat"; f.ResultBonus="geb_YellowCaviar"; f.MeatMin=2; f.MeatMax=4; f.Environment=1; f.CatchMethod=1; f.CatchProbability=4; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.4; f.TempOptimal=19.0; f.TempMin=10.0; f.TempMax=25.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AlligatorGar"; f.RecipeShape=0; f.ResultMain="geb_AlligatorGarFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=3; f.CatchMethod=1; f.CatchProbability=4; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.2; f.DayMultiplier=0.8; f.DuskMultiplier=1.3; f.NightMultiplier=1.4; f.TempOptimal=26.0; f.TempMin=16.0; f.TempMax=32.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_LargeMouthBass"; f.RecipeShape=0; f.ResultMain="geb_LargeMouthBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=14; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.4; f.NightMultiplier=1.1; f.TempOptimal=24.0; f.TempMin=14.0; f.TempMax=30.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SmallMouthBass"; f.RecipeShape=0; f.ResultMain="geb_SmallMouthBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=13; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.4; f.NightMultiplier=1.1; f.TempOptimal=21.0; f.TempMin=12.0; f.TempMax=27.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
    }
    void SeedSpeciesB() {
        FishConf f;
        f = new FishConf(); f.Classname="geb_WallEye"; f.RecipeShape=0; f.ResultMain="geb_WallEyeFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=12; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.3; f.DayMultiplier=0.7; f.DuskMultiplier=1.5; f.NightMultiplier=1.5; f.TempOptimal=18.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SunFish"; f.RecipeShape=0; f.ResultMain="geb_SunFishFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=20; f.RainMultiplier=1.1; f.StormMultiplier=0.9; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=25.0; f.TempMin=15.0; f.TempMax=30.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_WhiteBass"; f.RecipeShape=0; f.ResultMain="geb_WhiteBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=11; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.3; f.NightMultiplier=1.3; f.TempOptimal=21.0; f.TempMin=12.0; f.TempMax=27.0; f.BiteSpeed=BiteSteady(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_StripedBass"; f.RecipeShape=0; f.ResultMain="geb_StripedBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=10; f.RainMultiplier=1.0; f.StormMultiplier=1.4; f.DawnMultiplier=1.2; f.DayMultiplier=0.9; f.DuskMultiplier=1.4; f.NightMultiplier=1.3; f.TempOptimal=20.0; f.TempMin=10.0; f.TempMax=26.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_NeoshoBass"; f.RecipeShape=0; f.ResultMain="geb_NeoshoBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=7; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=22.0; f.TempMin=13.0; f.TempMax=28.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BlackBass"; f.RecipeShape=0; f.ResultMain="geb_BlackBassFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=13; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=23.0; f.TempMin=13.0; f.TempMax=29.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_RainbowTrout"; f.RecipeShape=1; f.ResultMain="geb_RainbowTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=14; f.RainMultiplier=1.4; f.StormMultiplier=1.3; f.DawnMultiplier=1.5; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=14.0; f.TempMin=4.0; f.TempMax=21.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BrownTrout"; f.RecipeShape=1; f.ResultMain="geb_BrownTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=12; f.RainMultiplier=1.4; f.StormMultiplier=1.3; f.DawnMultiplier=1.5; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=14.0; f.TempMin=4.0; f.TempMax=21.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BrookTrout"; f.RecipeShape=1; f.ResultMain="geb_BrookTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=12; f.RainMultiplier=1.4; f.StormMultiplier=1.3; f.DawnMultiplier=1.5; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=13.0; f.TempMin=4.0; f.TempMax=20.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_LakeTrout"; f.RecipeShape=0; f.ResultMain="geb_LakeTroutFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=8; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.3; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.1; f.TempOptimal=10.0; f.TempMin=2.0; f.TempMax=16.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_CutThroatTrout"; f.RecipeShape=1; f.ResultMain="geb_CutThroatTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=9; f.RainMultiplier=1.4; f.StormMultiplier=1.3; f.DawnMultiplier=1.5; f.DayMultiplier=0.8; f.DuskMultiplier=1.4; f.NightMultiplier=1.0; f.TempOptimal=13.0; f.TempMin=4.0; f.TempMax=20.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_LakeSturgeon"; f.RecipeShape=1; f.ResultMain="geb_LakeSturgeonFilletMeat"; f.ResultBonus="geb_BlackCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=3; f.RainMultiplier=1.1; f.StormMultiplier=1.4; f.DawnMultiplier=1.1; f.DayMultiplier=0.9; f.DuskMultiplier=1.1; f.NightMultiplier=1.0; f.TempOptimal=15.0; f.TempMin=5.0; f.TempMax=22.0; f.BiteSpeed=BiteSteady(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_YellowPerch"; f.RecipeShape=0; f.ResultMain="geb_YellowPerchFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=21; f.RainMultiplier=1.1; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=19.0; f.TempMin=10.0; f.TempMax=25.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_FlatHeadCatFish"; f.RecipeShape=0; f.ResultMain="geb_FlatHeadCatFishFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=4; f.Environment=1; f.CatchMethod=3; f.CatchProbability=5; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.2; f.DayMultiplier=0.7; f.DuskMultiplier=1.4; f.NightMultiplier=1.6; f.TempOptimal=26.0; f.TempMin=16.0; f.TempMax=32.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_FatHeadMinnow"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=5; f.CatchProbability=25; f.RainMultiplier=1.2; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.1; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AmericanBullFrog"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=5; f.CatchProbability=12; f.RainMultiplier=1.5; f.StormMultiplier=1.2; f.DawnMultiplier=1.4; f.DayMultiplier=1.0; f.DuskMultiplier=1.5; f.NightMultiplier=1.3; f.TempOptimal=25.0; f.TempMin=15.0; f.TempMax=32.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
    }
    void SeedSpeciesC() {
        FishConf f;
        f = new FishConf(); f.Classname="geb_RedSalamander"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=5; f.CatchProbability=7; f.RainMultiplier=1.6; f.StormMultiplier=1.3; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.3; f.NightMultiplier=1.2; f.TempOptimal=15.0; f.TempMin=6.0; f.TempMax=22.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BlueGill"; f.RecipeShape=0; f.ResultMain="geb_BlueGillFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=22; f.RainMultiplier=1.1; f.StormMultiplier=0.9; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=25.0; f.TempMin=15.0; f.TempMax=30.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_Sauger"; f.RecipeShape=0; f.ResultMain="geb_SaugerFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=10; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.3; f.DayMultiplier=0.7; f.DuskMultiplier=1.5; f.NightMultiplier=1.5; f.TempOptimal=18.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteTwilightNight(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BowFin"; f.RecipeShape=0; f.ResultMain="geb_BowFinFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=8; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.2; f.DayMultiplier=0.8; f.DuskMultiplier=1.3; f.NightMultiplier=1.4; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SlimySculpin"; f.RecipeShape=0; f.ResultMain="geb_SlimySculpinFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=16; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.0; f.NightMultiplier=1.2; f.TempOptimal=10.0; f.TempMin=2.0; f.TempMax=16.0; f.BiteSpeed=BiteSteady(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_Severum"; f.RecipeShape=0; f.ResultMain="geb_SeverumFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=3; f.RainMultiplier=1.1; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=1.0; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SignalCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=18; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_EuropeanCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=11; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_FloridaCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=8; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=25.0; f.TempMin=15.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_CaveCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=2; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.0; f.NightMultiplier=1.5; f.TempOptimal=12.0; f.TempMin=4.0; f.TempMax=18.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_MonongahelaCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=7; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_RedSwampCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=18; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=24.0; f.TempMin=14.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_RustyCrayFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=4; f.CatchProbability=14; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=22.0; f.TempMin=12.0; f.TempMax=28.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        // saltwater
        f = new FishConf(); f.Classname="geb_MahiMahi"; f.RecipeShape=0; f.ResultMain="geb_MahiMahiFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=7; f.Environment=2; f.CatchMethod=1; f.CatchProbability=10; f.RainMultiplier=1.2; f.StormMultiplier=1.5; f.DawnMultiplier=1.1; f.DayMultiplier=1.1; f.DuskMultiplier=1.0; f.NightMultiplier=1.0; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AtlanticSailFish"; f.RecipeShape=0; f.ResultMain="geb_AtlanticSailFishFilletMeat"; f.ResultBonus=""; f.MeatMin=4; f.MeatMax=7; f.Environment=2; f.CatchMethod=1; f.CatchProbability=4; f.RainMultiplier=1.2; f.StormMultiplier=1.4; f.DawnMultiplier=1.2; f.DayMultiplier=1.1; f.DuskMultiplier=1.2; f.NightMultiplier=1.0; f.TempOptimal=27.0; f.TempMin=21.0; f.TempMax=32.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AngelFish"; f.RecipeShape=0; f.ResultMain="geb_AngelFishFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=1; f.CatchProbability=10; f.RainMultiplier=0.9; f.StormMultiplier=0.8; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.8; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
    }
    void SeedSpeciesD() {
        FishConf f;
        f = new FishConf(); f.Classname="geb_AsianSeaBass"; f.RecipeShape=0; f.ResultMain="geb_AsianSeaBassFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=3; f.CatchMethod=3; f.CatchProbability=10; f.RainMultiplier=1.2; f.StormMultiplier=1.3; f.DawnMultiplier=1.2; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.2; f.TempOptimal=28.0; f.TempMin=20.0; f.TempMax=33.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AtlanticBlueMarlin"; f.RecipeShape=0; f.ResultMain="geb_AtlanticBlueMarlinFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=6; f.Environment=2; f.CatchMethod=1; f.CatchProbability=3; f.RainMultiplier=1.2; f.StormMultiplier=1.4; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.0; f.TempOptimal=26.0; f.TempMin=20.0; f.TempMax=30.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_Bonita"; f.RecipeShape=0; f.ResultMain="geb_BonitaFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=10; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.0; f.TempOptimal=22.0; f.TempMin=14.0; f.TempMax=28.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_CherrySalmon"; f.RecipeShape=1; f.ResultMain="geb_CherrySalmonFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=6; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.0; f.TempOptimal=12.0; f.TempMin=4.0; f.TempMax=18.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_ChinookSalmon"; f.RecipeShape=1; f.ResultMain="geb_ChinookSalmonFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=8; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.0; f.TempOptimal=12.0; f.TempMin=4.0; f.TempMax=18.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SockEyeSalmon"; f.RecipeShape=1; f.ResultMain="geb_SockEyeSalmonFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=8; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.4; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.0; f.TempOptimal=13.0; f.TempMin=4.0; f.TempMax=18.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_FlatHeadMullet"; f.RecipeShape=0; f.ResultMain="geb_FlatHeadMulletFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=3; f.CatchMethod=3; f.CatchProbability=18; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.3; f.DayMultiplier=1.1; f.DuskMultiplier=1.2; f.NightMultiplier=1.0; f.TempOptimal=25.0; f.TempMin=15.0; f.TempMax=30.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_LeopardShark"; f.RecipeShape=0; f.ResultMain="geb_LeopardSharkFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=2; f.CatchMethod=1; f.CatchProbability=9; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.2; f.NightMultiplier=1.4; f.TempOptimal=18.0; f.TempMin=10.0; f.TempMax=24.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_HammerHeadShark"; f.RecipeShape=0; f.ResultMain="geb_HammerHeadSharkFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=2; f.CatchMethod=1; f.CatchProbability=5; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.1; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.5; f.TempOptimal=26.0; f.TempMin=18.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_PacificCod"; f.RecipeShape=0; f.ResultMain="geb_PacificCodFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=16; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.1; f.DayMultiplier=1.0; f.DuskMultiplier=1.1; f.NightMultiplier=1.2; f.TempOptimal=8.0; f.TempMin=2.0; f.TempMax=14.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_RedHeadCichlid"; f.RecipeShape=0; f.ResultMain="geb_RedHeadCichlidFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=4; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.1; f.DuskMultiplier=1.0; f.NightMultiplier=1.0; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_RoughNeckRock"; f.RecipeShape=0; f.ResultMain="geb_RoughNeckRockFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=14; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.1; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.2; f.TempOptimal=17.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BlueTang"; f.RecipeShape=0; f.ResultMain="geb_BlueTangFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=12; f.RainMultiplier=0.9; f.StormMultiplier=0.8; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=26.0; f.TempMin=20.0; f.TempMax=30.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_LargeHeadHairTailFish"; f.RecipeShape=0; f.ResultMain="geb_LargeHeadHairTailFishFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=5; f.Environment=2; f.CatchMethod=3; f.CatchProbability=9; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.2; f.NightMultiplier=1.4; f.TempOptimal=17.0; f.TempMin=8.0; f.TempMax=24.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_HumpHeadWrasse"; f.RecipeShape=0; f.ResultMain="geb_HumpHeadWrasseFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=5; f.Environment=2; f.CatchMethod=3; f.CatchProbability=4; f.RainMultiplier=0.9; f.StormMultiplier=0.8; f.DawnMultiplier=1.0; f.DayMultiplier=1.2; f.DuskMultiplier=1.0; f.NightMultiplier=0.8; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BiteDiurnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SiameseTigerFish"; f.RecipeShape=0; f.ResultMain="geb_SiameseTigerFishFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=6; f.Environment=1; f.CatchMethod=3; f.CatchProbability=6; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.1; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.2; f.TempOptimal=27.0; f.TempMin=20.0; f.TempMax=32.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
    }
    void SeedSpeciesE() {
        FishConf f;
        f = new FishConf(); f.Classname="geb_GreatWhiteShark"; f.RecipeShape=0; f.ResultMain="geb_GreatWhiteSharkFilletMeat"; f.ResultBonus=""; f.MeatMin=5; f.MeatMax=10; f.Environment=2; f.CatchMethod=1; f.CatchProbability=2; f.RainMultiplier=1.0; f.StormMultiplier=1.2; f.DawnMultiplier=1.2; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.4; f.TempOptimal=17.0; f.TempMin=10.0; f.TempMax=24.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AngelShark"; f.RecipeShape=0; f.ResultMain="geb_AngelSharkFilletMeat"; f.ResultBonus=""; f.MeatMin=3; f.MeatMax=8; f.Environment=2; f.CatchMethod=1; f.CatchProbability=7; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.2; f.NightMultiplier=1.5; f.TempOptimal=18.0; f.TempMin=10.0; f.TempMax=24.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_YellowFinTuna"; f.RecipeShape=0; f.ResultMain="geb_YellowFinTunaFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=6; f.Environment=2; f.CatchMethod=1; f.CatchProbability=8; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.3; f.DayMultiplier=1.0; f.DuskMultiplier=1.3; f.NightMultiplier=1.0; f.TempOptimal=25.0; f.TempMin=18.0; f.TempMax=30.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_WhiteGrunt"; f.RecipeShape=0; f.ResultMain="geb_WhiteGruntFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=6; f.Environment=2; f.CatchMethod=1; f.CatchProbability=14; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.2; f.TempOptimal=25.0; f.TempMin=18.0; f.TempMax=30.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SouthernFlounder"; f.RecipeShape=0; f.ResultMain="geb_SouthernFlounderFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=6; f.Environment=2; f.CatchMethod=1; f.CatchProbability=11; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.2; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.4; f.TempOptimal=18.0; f.TempMin=10.0; f.TempMax=24.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_YellowSnapper"; f.RecipeShape=0; f.ResultMain="geb_YellowSnapperFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=6; f.Environment=2; f.CatchMethod=1; f.CatchProbability=13; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=1.0; f.DuskMultiplier=1.3; f.NightMultiplier=1.3; f.TempOptimal=25.0; f.TempMin=18.0; f.TempMax=30.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        // shellfish / crustaceans
        f = new FishConf(); f.Classname="geb_BloodClam"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=2; f.CatchMethod=4; f.CatchProbability=14; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=18.0; f.TempMin=4.0; f.TempMax=30.0; f.BiteSpeed=BiteFilterFeeder(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_Mussel"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=3; f.CatchMethod=6; f.CatchProbability=20; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.0; f.NightMultiplier=0.9; f.TempOptimal=16.0; f.TempMin=4.0; f.TempMax=28.0; f.BiteSpeed=BiteFilterFeeder(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BlackDevilSnail"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=1; f.CatchMethod=6; f.CatchProbability=10; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.0; f.NightMultiplier=1.2; f.TempOptimal=22.0; f.TempMin=10.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_StarFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=1; f.Environment=2; f.CatchMethod=6; f.CatchProbability=16; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=1.0; f.DuskMultiplier=1.0; f.NightMultiplier=1.0; f.TempOptimal=16.0; f.TempMin=4.0; f.TempMax=28.0; f.BiteSpeed=BiteConstant(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_KingCrab"; f.RecipeShape=0; f.ResultMain="geb_KingCrabLegs"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=6; f.CatchProbability=5; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.1; f.NightMultiplier=1.3; f.TempOptimal=5.0; f.TempMin=0.0; f.TempMax=12.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_SnowCrab"; f.RecipeShape=0; f.ResultMain="geb_SnowCrabLegs"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=6; f.CatchProbability=7; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.1; f.NightMultiplier=1.3; f.TempOptimal=4.0; f.TempMin=0.0; f.TempMax=10.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_BlueJellyFish"; f.RecipeShape=0; f.ResultMain=""; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=6; f.CatchProbability=12; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.9; f.DuskMultiplier=1.0; f.NightMultiplier=1.4; f.TempOptimal=20.0; f.TempMin=8.0; f.TempMax=30.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_AmericanLobster"; f.RecipeShape=2; f.ResultMain="geb_AmericanLobsterClaw"; f.ResultBonus="geb_AmericanLobsterTail"; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=6; f.CatchProbability=9; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=12.0; f.TempMin=4.0; f.TempMax=18.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_EuropeanLobster"; f.RecipeShape=2; f.ResultMain="geb_EuropeanLobsterClaw"; f.ResultBonus="geb_EuropeanLobsterTail"; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=6; f.CatchProbability=9; f.RainMultiplier=1.0; f.StormMultiplier=1.0; f.DawnMultiplier=1.0; f.DayMultiplier=0.8; f.DuskMultiplier=1.1; f.NightMultiplier=1.4; f.TempOptimal=14.0; f.TempMin=5.0; f.TempMax=20.0; f.BiteSpeed=BiteNocturnal(); Species.Insert(f);
    }
}

// ===========================================================================
// FACADE + GLOBAL ACCESSORS
// ===========================================================================
class gebsfishConfig {
    ref GeneralConfig     General;   // general.json
    ref BaitSettingsConf  Bait;      // bait.json
    ref JunkConfig        Junk;      // junk.json
    ref FishConfig        Fish;      // fish.json

    void LoadAll() {
        General = new GeneralConfig();
        Bait    = new BaitSettingsConf();
        Junk    = new JunkConfig();
        Fish    = new FishConfig();
        if (!g_Game.IsServer())
            return;   // server owns the files; clients receive values via RPC

        General.Load();
        Bait.Load();
        Junk.Load();
        Fish.Load();
    }
}

ref gebsfishConfig m_gebsConfig;

static gebsfishConfig GetGebSettingsConfig() {
    if (!m_gebsConfig) {
        GebsfishLogger.Info("Initializing gebsfish config.", "JSON");
        m_gebsConfig = new gebsfishConfig;
        m_gebsConfig.LoadAll();
    }
    return m_gebsConfig;
}

static void SetGebsfishConfig(gebsfishConfig config) {
    GebsfishLogger.Info("Setting config from server (RPC).", "JSON");
    m_gebsConfig = config;
}

// Null-safe debug level: 0 off, 1 normal, 2 (ELEVATED_DEBUG) verbose.
static int GebGetDebugLevel() {
    if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings)
        return 0;
    return m_gebsConfig.General.GeneralSettings.DebugLogs;
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
    string HookFromFishInfo = "When filleting a fish, there is a chance to recover a damaged hook 'stuck in the fish'. The roll happens once per fillet action (each time you fillet a fish), not once per fillet meat produced -- a fish that yields several fillets still only rolls once. HookFromFishEnable toggles the feature, HookFromFishChance is the probability per fillet action (default 0.004 = ~1/250). The pool of possible hooks (and the health-level range each spawns at) lives in the top-level HookFromFishCatches array so admins can add lures or other hook variants and weight them. Set Weight to 0 to disable an entry without deleting it; set MinHealthLevel/MaxHealthLevel both to 3 for a fixed Badly Damaged hook, or 3/4 for a random Badly Damaged or Ruined.";
    bool HookFromFishEnable = 1;
    float HookFromFishChance = 0.004;
};

class RecipeToggleConf {
    string RecipeToggleInfo = "Enables(1) or disables(0) Gebsfish non-fish-prep recipes. Fish prepare/fillet recipes are not controlled here.";
    bool CraftBambooFishingNet = 1;
    bool CraftHookFromWire = 1;
    bool RepairFishingPole = 1;
    bool RepairBambooFishingNet = 1;
};

//predator animals config data
//
// Predator spawning runs through three independent gates -- the final per-
// action odds are the product of all three. Tune each gate separately so
// admins can think about "how often" and "what / how many" without those
// two questions interacting.
//
//   Gate 1: per-action chance (these fields). Rolls once per fishing /
//           filleting / failed-cast / net-use event. With the defaults of
//           0.01, anything-at-all happens roughly 1/100 actions.
//
//   Gate 2: weighted predator pick over the Predators[] array, using each
//           entry's SpawnChance as a relative weight. The defaults give
//           wolves 0.6 / (0.6 + 0.3) = 2/3 of all predator spawns and
//           bears the remaining 1/3.
//
//   Gate 3: per-predator MinCount/MaxCount (uniform random). Defaults are
//           wolf 1/1 and bear 1/1, so exactly one animal spawns when the
//           predator is picked. Widen the range (e.g. wolf 1/3) for a
//           higher-stakes server.
//
//   Combined per-catch with the defaults:
//     wolf: 1/100 * 2/3 = 1/150 (~0.67%), always one wolf
//     bear: 1/100 * 1/3 = 1/300 (~0.33%), always one bear
//
// GebsPredatorSpawner.TrySpawn applies all three gates in order. A fourth
// silent filter (no land within [MinRadius, MaxRadius]) can drop the
// effective rate below these nominal fractions when the player is far
// from shore -- not configurable here, see geb_predatorspawner.c.
class PredatorConf {
    string PredatorSpawnEnabledInfo = "Turns on(1) and off(0) the predators feature of the mod. When on, it will enable the random spawning of predators when catching/cutting up the fish.";
    bool PredatorSpawnEnabled = 1;
    string PredatorSpawnChanceInfo = "Gate 1 of 3 for predator spawning -- the per-action chance that ANY predator is selected. Fishing is when a fish is caught, preparing is when filleting, failcatch is when fishing rolls nothing. Bamboo fishing net has its own predator chance under BambooFishingNetSettings.PredatorSpawnChance. Set any to 0 to disable that path entirely. Final per-catch odds = thisChance * (predator weight / sum of weights), so 0.01 here with default wolf/bear weights gives wolves 1/150 and bear 1/300. See the comment above PredatorConf for the full three-gate breakdown.";
    float PredatorSpawnChanceFishing = 0.01;
    float PredatorSpawnChancePreparing = 0.01;
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
    string ClassnameInfo = "Classname of the predator to spawn (e.g. Animal_CanisLupus_Grey for a grey wolf, Animal_UrsusArctos for a bear).";
    string Classname;   //Classname of predator
    string SpawnChanceInfo = "Relative weight for this predator in the weighted pick (NOT a 0-1 percentage). The chance of this predator being chosen is its weight divided by the sum of all predator weights. Defaults: wolf 0.6 and bear 0.3 give the wolf 2/3 and the bear 1/3 of all spawns. This is Gate 2 of 3 -- see the comment above PredatorConf.";
    float SpawnChance;  //Spawn percentage chance
    string MinCountInfo = "Minimum number of this predator to spawn at once (uniform random between MinCount and MaxCount). 1/1 means always exactly one.";
    int MinCount;       //Minimum count of predators spawned
    string MaxCountInfo = "Maximum number of this predator to spawn at once (uniform random between MinCount and MaxCount). Raise above MinCount for a pack (e.g. 1/3 wolves).";
    int MaxCount;       //Maximum count of predators spawned
    string MinRadiusInfo = "Closest distance, in metres, from the player that this predator may spawn. The spawner only uses points with land between MinRadius and MaxRadius, so a fully off-shore player may get no spawn.";
    float MinRadius;    //Minimum radius from player
    string MaxRadiusInfo = "Farthest distance, in metres, from the player that this predator may spawn. Must be greater than MinRadius.";
    float MaxRadius;    //Maximum radius from player
}

//bug config data

class BugEntry {
    string ClassnameInfo = "Classname of the bug / worm this entry can produce (e.g. Worm, geb_GrubWorm, geb_FieldCricket, geb_GrassHopper).";
    string Classname;
    string CatchChanceInfo = "Relative weight for this entry within the action's Catches table (NOT a 0-1 chance, and separate from the action's FindChance). Once the action decides it found something, the result is picked from all entries by weight: an entry's odds are its weight divided by the sum of all weights. Set to 0 (or below) to disable this entry without deleting it.";
    float CatchChance;
}

// Bamboo fishing net spawn-table entry. Mirrors BugEntry's Classname /
// CatchChance contract, but adds an Environment field so the same Catches
// array can hold both freshwater and saltwater entries. 1=pond, 2=sea,
// 3=both. Entries whose Environment doesn't match the current water surface
// are skipped before the weighted roll.
class NetEntry {
    string ClassnameInfo = "Classname of the creature this net entry can produce (e.g. geb_FatHeadMinnow, geb_AmericanBullFrog, geb_RedSalamander).";
    string Classname;
    string CatchChanceInfo = "Relative weight for this entry within the net's Catches table (NOT a 0-1 chance, and separate from the net's FindChance). Among the entries valid for the current water surface, an entry's odds are its weight divided by the sum of those weights. Set to 0 (or below) to disable this entry without deleting it.";
    float CatchChance;
    string EnvironmentInfo = "Where this entry is allowed: 1 = pond/freshwater only, 2 = sea/saltwater only, 3 = both. Entries whose Environment doesn't match the water the net was cast in are skipped before the weighted pick.";
    int Environment = 1;
}

// One per fish that a given bait/lure favours. Multiplier > 1.0 makes the
// fish more likely to be the selected catch when this bait is on the hook;
// < 1.0 makes it less likely. 1.0 = neutral, same as omitting the entry.
class BaitPreferenceEntry {
    string FishClassnameInfo = "Classname of the fish this bias applies to when the parent bait/lure is on the hook (e.g. geb_BlueGill, geb_LargeMouthBass, Carp).";
    string FishClassname;
    string MultiplierInfo = "How strongly this bait favours this fish in the weighted catch pick. 1.0 = neutral (same as having no entry), above 1.0 makes the fish more likely (2.0 = twice as likely), below 1.0 makes it less likely (0.3 = much rarer), 0 effectively removes it. Only used while GeneralSettings.BaitPreferenceEnable is on.";
    float Multiplier = 1.0;
}

// Bait-side container: each bait/lure classname owns a list of fish it
// favours. Lookups default to 1.0 (no bias) when the current bait is not
// in BaitPreferences at all, or when the bait is configured but the
// specific fish isn't listed. So admins can opt in incrementally without
// listing every fish-bait pair.
class BaitConfig {
    string BaitClassnameInfo = "Classname of the bait or lure this preference table applies to (e.g. Worm, geb_GrubWorm, geb_SpinnerBait1). When this bait is on the hook, the fish multipliers below bias which fish gets caught.";
    string BaitClassname;
    string PreferencesInfo = "List of per-fish biases for this bait: each entry pairs a fish classname with a multiplier. Fish not listed here default to 1.0 (no bias). Only used while GeneralSettings.BaitPreferenceEnable is on.";
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

// HookFromFish config entry. Weighted pool used by the 'damaged hook stuck in
// a fish' fillet feature (gated by GeneralSettings.HookFromFishEnable /
// HookFromFishChance). MinHealthLevel/MaxHealthLevel work the same way as the
// junk entries: 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined.
class HookFromFishEntry {
    string ClassnameInfo = "Hook classname to spawn (e.g. FishingHook for vanilla, or any gebsfish lure/hook).";
    string Classname;
    string WeightInfo = "Relative weight in the weighted pick. Set to 0 to disable an entry without deleting it. Pure ratios -- 2.0 is twice as likely as 1.0.";
    float Weight = 1.0;
    string HealthLevelInfo = "Health level range. 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined. Defaults to 3/3 (fixed Badly Damaged).";
    int MinHealthLevel = 3;
    int MaxHealthLevel = 3;
};