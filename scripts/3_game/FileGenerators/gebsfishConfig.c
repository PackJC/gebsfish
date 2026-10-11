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
    // dynamic float array. It became a string after fish.json crashed the JSON
    // reader; that crash was most likely an over-long default string (see the
    // limit noted at FishConfig.SpeciesInfo), not the array -- vanilla loads a
    // ref array<float> inside each element of an array on every boot
    // (cfgeffectarea.json, Data.Pos). The string stays: it is what existing
    // fish.json files hold. GetBiteSpeedArray() parses it back into a
    // TFloatArray for runtime use.
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
// The four config files' folder. Nothing guarantees it exists the first time
// a file is written -- the logger only creates it once it writes a log -- and
// vanilla's JsonSaveFile gives up without a word when it can't open the file.
// Every Save() makes the folder first and uses SaveFile, which says why a
// write failed.
const string GEB_CONFIG_DIR = "$profile:Gebs";

static void GebMakeConfigDir() {
    if (!FileExist(GEB_CONFIG_DIR))
        MakeDirectory(GEB_CONFIG_DIR);
}

// Class names from the JSON files match whatever their case, as the engine's
// own lookups do (ConfigIsExisting, CreateObject) and the validator's duplicate
// check does: an admin's "geb_bluegill" row is the caught geb_BlueGill's, for
// filleting as for bait. Copies, so the callers' strings stay as written.
static bool GebSameClassname(string a, string b) {
    if (a == b)
        return true;
    string aLower = a;
    string bLower = b;
    aLower.ToLower();
    bLower.ToLower();
    return aLower == bLower;
}

// Help text: every string field whose name ends in "Info" is documentation the
// game never reads. Loading fills it from the file like any other field, so an
// old file keeps whatever text it was written with (blank, or an older
// version's). This copies the current text in from `fresh`, a newly made object
// of the same class; settings are never touched. Returns how many texts changed.
static int GebRefreshInfo(Class target, Class fresh) {
    if (!target || !fresh)
        return 0;
    typename t = target.Type();
    int changed = 0;
    int count = t.GetVariableCount();
    for (int i = 0; i < count; i++) {
        if (t.GetVariableType(i) != string)
            continue;
        string name = t.GetVariableName(i);
        int len = name.Length();
        if (len < 5 || name.Substring(len - 4, 4) != "Info")
            continue;
        string now;
        string current;
        t.GetVariableValue(target, i, now);
        t.GetVariableValue(fresh, i, current);
        if (now == current)
            continue;
        EnScript.SetClassVar(target, name, 0, current);
        changed++;
    }
    return changed;
}

// ---------------------------------------------------------------------------
// Was a setting or section actually written in the file on disk?
//
// The loaded object can't tell us. JsonFileLoader reads INTO the object it is
// given. A scalar the file has no value for (a key that is missing, or null)
// is left as it was: on the top-level object, which script made, that is the
// class default. A section or list the file has no value for is made anyway:
// a missing section comes back as an object with every field 0 / false / ""
// (the loader creates it without running its constructor, which is what sets
// the class defaults), and a missing list as an empty one. The same goes for
// the sections and list rows the loader creates, so a field missing from one
// of them reads as 0. A real general.json shows it: a TreasureSettings section
// an older file didn't have came back as Enable 0, Chance 0, Announce 0. So
// once a file is loaded, "this file never had it", "the admin deleted it" and
// "the admin emptied it or set it to 0 on purpose" look the same.
//
// Reading the raw text answers the question directly. Unlike a list of old
// version numbers it never needs maintaining: it keeps working however many
// releases go by.
//
// GebJsonKeys reads a file once and lists the keys it holds by path, so one
// Backfill can ask many questions: "TreasureSettings" is a top-level key,
// "TreasureSettings.Enable" a key inside that section, and
// "Preferences[2].Preferences" the Preferences key in the third row of the
// top-level Preferences list (bait.json uses that name at both levels). Keys
// are listed down to maxDepth objects deep (1 = top level only). A key whose
// value is null is left out, since the loader reads null exactly like a
// missing key. The scan follows the JSON structure and jumps over quoted
// text, so a field name mentioned in an ...Info string never counts as a key.
//
// It reads the file line by line. string.Get walks the whole string to its
// end on every call, so going through a whole file's text character by
// character costs the square of its size (seconds for bait.json); JSON keeps
// every string on one line, and these files are written pretty-printed (by the
// mod and by the config editor), so the lines are short. A file that can't be
// read answers "there" to every question, so a bad read never re-seeds
// defaults over an admin's settings.
class GebJsonKeys {
    protected ref TStringArray m_Paths = new TStringArray();
    protected bool m_Read;
    protected int m_MaxDepth;
    // The open containers, carried from line to line: each one's key path,
    // whether it is a [ list, and for a list the index of the element being
    // read.
    protected ref TStringArray m_ContainerPath = new TStringArray();
    protected ref TBoolArray m_ContainerIsList = new TBoolArray();
    protected ref TIntArray m_ContainerItem = new TIntArray();
    protected int m_Objects;
    protected string m_LastKey;
    // A key that ended its line before its value: its path, settled by the
    // value's first character on a later line.
    protected string m_Pending;

    void GebJsonKeys(string path, int maxDepth) {
        m_MaxDepth = maxDepth;
        if (!FileExist(path)) {
            WarnUnread(path);
            return;
        }
        FileHandle fr = OpenFile(path, FileMode.READ);
        if (!fr) {
            WarnUnread(path);
            return;
        }
        string line;
        while (FGets(fr, line) >= 0)
            ScanLine(line);
        CloseFile(fr);
        if (!m_Read)
            WarnUnread(path);
    }

    // True when the file gives keyPath a value other than null. A file that
    // couldn't be read answers true, so nothing is re-seeded over it.
    bool Has(string keyPath) {
        if (!m_Read)
            return true;
        return m_Paths.Find(keyPath) != -1;
    }

    protected static void WarnUnread(string path) {
        GebsfishLogger.Warn("Couldn't read " + path + " to check which settings it holds; nothing is re-seeded from it this start.", "Config");
    }

    // One line of the file. Every open { and [ is a container (the members
    // above), carried over to the next line; quoted text is jumped over whole.
    protected void ScanLine(string text) {
        string c;
        string here;
        int code;
        int top;
        int close;
        int after;
        int valueAt;
        int len = text.Length();
        int i = 0;
        while (i < len) {
            c = text.Get(i);
            code = c.ToAscii();
            if (code == 32 || code == 9 || code == 10 || code == 13) {
                i++;
                continue;
            }
            // The value of a key that ended an earlier line: null or not.
            if (m_Pending != "") {
                if (c != "n")
                    m_Paths.Insert(m_Pending);
                m_Pending = "";
            }
            if (c == "\"") {
                close = FindClosingQuote(text, i + 1);
                if (close == -1)
                    return;
                after = SkipBlanks(text, close + 1);
                if (after < len && text.Get(after) == ":") {
                    // A key; it sits inside m_Objects objects (1 = top level).
                    m_LastKey = text.Substring(i + 1, close - i - 1);
                    valueAt = SkipBlanks(text, after + 1);
                    if (m_Objects <= m_MaxDepth) {
                        if (valueAt >= len)
                            m_Pending = KeyPath(m_ContainerPath, m_LastKey);
                        else if (text.Get(valueAt) != "n")
                            m_Paths.Insert(KeyPath(m_ContainerPath, m_LastKey));
                    }
                    i = after + 1;
                } else {
                    i = close + 1;
                }
                continue;
            }
            if (c == "{" || c == "[") {
                top = m_ContainerPath.Count() - 1;
                here = "";
                if (top >= 0 && m_ContainerIsList.Get(top))
                    here = m_ContainerPath.Get(top) + "[" + m_ContainerItem.Get(top) + "]";
                else if (top >= 0)
                    here = KeyPath(m_ContainerPath, m_LastKey);
                m_ContainerPath.Insert(here);
                m_ContainerIsList.Insert(c == "[");
                m_ContainerItem.Insert(0);
                if (c == "{") {
                    m_Objects++;
                    m_Read = true;
                }
            } else if (c == "}" || c == "]") {
                top = m_ContainerPath.Count() - 1;
                if (top >= 0) {
                    if (!m_ContainerIsList.Get(top))
                        m_Objects--;
                    m_ContainerPath.Remove(top);
                    m_ContainerIsList.Remove(top);
                    m_ContainerItem.Remove(top);
                }
            } else if (c == ",") {
                top = m_ContainerPath.Count() - 1;
                if (top >= 0 && m_ContainerIsList.Get(top))
                    m_ContainerItem.Set(top, m_ContainerItem.Get(top) + 1);
            }
            i++;
        }
    }

    // The path of `key` read in the innermost open container.
    protected static string KeyPath(TStringArray containerPath, string key) {
        int top = containerPath.Count() - 1;
        if (top < 0 || containerPath.Get(top) == "")
            return key;
        return containerPath.Get(top) + "." + key;
    }

    // Index of the quote that ends the string starting at `start`, or -1.
    // A quote after an odd number of backslashes is part of the text.
    protected static int FindClosingQuote(string text, int start) {
        int len = text.Length();
        int at = start;
        int close;
        int slashes;
        while (at < len) {
            close = text.IndexOfFrom(at, "\"");
            if (close == -1)
                return -1;
            slashes = 0;
            while (close - slashes - 1 >= 0 && text.Get(close - slashes - 1) == "\\")
                slashes++;
            if (slashes % 2 == 0)
                return close;
            at = close + 1;
        }
        return -1;
    }

    // Index of the first character at or after `start` that isn't a space,
    // tab or line break; the text's length if there is none.
    protected static int SkipBlanks(string text, int start) {
        int len = text.Length();
        int at = start;
        string ch;
        int code;
        while (at < len) {
            ch = text.Get(at);
            code = ch.ToAscii();
            if (code != 32 && code != 9 && code != 10 && code != 13)
                return at;
            at++;
        }
        return len;
    }
}

// One question about one file: does it give `key` (a key path, as in
// GebJsonKeys) a value other than null? Reads the file on every call; to ask
// several questions of one file, make one GebJsonKeys and ask that.
static bool GebJsonFileHasKey(string path, string key) {
    int depth = 1;
    for (int at = 0; at < key.Length(); at++) {
        if (key.Get(at) == ".")
            depth++;
    }
    GebJsonKeys file = new GebJsonKeys(path, depth);
    return file.Has(key);
}

class GeneralConfig {
    string ConfigVersionInfo = "Mod config version this file was written with. Do NOT edit -- used to migrate the file on mod updates.";
    string ConfigVersion = "";
    string GeneralSettingsInfo = "Global mod settings (each field inside has its own *Info): debug log level, fish quality, knife fillet speed, caviar chance, and the hook-from-fish toggle/chance.";
    ref GenSetConf                    GeneralSettings;
    string RecipeTogglesInfo = "Enable(1)/disable(0) the gebsfish craft/repair recipes (one bool per recipe inside).";
    ref RecipeToggleConf              RecipeToggles;
    string HookFromFishCatchesInfo = "Weighted pool of hooks 'found' stuck in a fish while filleting (gated by GeneralSettings.HookFromFishEnable/Chance). Each entry: Classname (hook/lure to give), Weight (relative odds; 0 disables that entry), MinHealthLevel/MaxHealthLevel (0 pristine .. 4 ruined).";
    ref array<ref HookFromFishEntry>  HookFromFishCatches;
    string TreasureSettingsInfo = "Switches for the ultra-rare treasure catch. The pools it draws from are TreasureContainers and TreasureLoot below.";
    ref TreasureConf                  TreasureSettings;
    string TreasureContainersInfo = "Weighted pool of CONTAINERS an ultra-rare treasure catch can arrive as (gated by TreasureSettings). One is picked per treasure, then filled from TreasureLoot. Give a container a bigger MinItems/MaxItems to make it worth more.";
    ref array<ref TreasureContainerEntry> TreasureContainers;
    string TreasureLootInfo = "Weighted pool of ITEMS that can appear inside a treasure container. Each of the container's item slots rolls this pool independently, so contents differ every time. Add anything you like -- including modded classnames.";
    ref array<ref TreasureLootEntry>  TreasureLoot;
    string PredatorSettingsInfo = "Predator-spawn settings: per-activity chances, enable toggle, and warning sound/message options (each field has its own *Info).";
    ref PredatorConf                  PredatorSettings;
    string PredatorsInfo = "Weighted pool of predators that can spawn. Each entry: Classname (animal), SpawnChance (relative weight), MinCount/MaxCount (how many), MinRadius/MaxRadius (metres from the player to spawn).";
    ref array<ref PredatorEntry>      Predators;
    string BambooFishingNetSettingsInfo = "Bamboo-net action: FindChance (0-1 per cast), PredatorSpawnChance, and a Catches table (each entry: Classname, CatchChance, Environment 1 pond/2 sea/3 both).";
    ref BambooFishingNetConf          BambooFishingNetSettings;
    string SpearFishingSettingsInfo = "Spear fishing: stab at fish in shallow water with an Improvised Spear (bone- or stone-tipped) in hand. Enable, FindChance (0-1 per stab), MaxWaterDepth (metres of water at the aim point), PredatorSpawnChance, and a Catches table (each entry: Classname, CatchChance, Environment 1 pond/2 sea/3 both).";
    ref SpearFishingConf              SpearFishingSettings;
    string DigBugsSettingsInfo = "Dig-for-bugs action: FindChance (0-1) plus a Catches table (each entry: Classname, CatchChance).";
    ref DigBugsConf                   DigBugsSettings;
    string DigWormsSettingsInfo = "Dig-for-worms action: FindChance (0-1) plus a Catches table (each entry: Classname, CatchChance).";
    ref DigWormsConf                  DigWormsSettings;
    string WeatherSettingsInfo = "Global weather/time-of-day/temperature/moon catch modifiers and their thresholds (each field has its own *Info inside).";
    ref WeatherConf                   WeatherSettings;

    private const static string PATH = "$profile:Gebs/general.json";

    bool Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<GeneralConfig>.LoadFile(PATH, this, err)) {
                GebsfishLogger.Error("general.json failed to load; file preserved, using defaults for this session: " + err, "Config");
                return false;
            }
            changed = Backfill();
            if (ConfigVersion != VERSION_GEBSFISH) {
                int added = MergeNewDefaults();
                if (added > 0)
                    GebsfishLogger.Info("general.json: added " + added.ToString() + " new default entries (update '" + ConfigVersion + "' -> '" + VERSION_GEBSFISH + "'). Existing entries untouched.", "Migrate");
                ConfigVersion = VERSION_GEBSFISH;
                changed = true;
            }
            int helpTexts = RefreshInfoStrings();
            if (helpTexts > 0) {
                GebsfishLogger.Info("general.json: brought " + helpTexts.ToString() + " help texts up to date. Settings untouched.", "Migrate");
                changed = true;
            }
        } else {
            SeedDefaults();
            changed = true;
        }
        // Only write the file back when something actually changed (fresh
        // generation, a backfilled section, or a version bump). A valid,
        // up-to-date file is left untouched -- no rewrite, no mtime change.
        if (changed) Save();
        return true;
    }
    // The current help text in every ...Info field (GebRefreshInfo): the file's
    // own, each section's, and every table row's (each row carries its own
    // copy). A new section or table must be added here. Returns how many changed.
    protected int RefreshInfoStrings() {
        int n = GebRefreshInfo(this, new GeneralConfig());
        n += GebRefreshInfo(GeneralSettings, new GenSetConf());
        n += GebRefreshInfo(RecipeToggles, new RecipeToggleConf());
        n += GebRefreshInfo(TreasureSettings, new TreasureConf());
        n += GebRefreshInfo(PredatorSettings, new PredatorConf());
        n += GebRefreshInfo(BambooFishingNetSettings, new BambooFishingNetConf());
        n += GebRefreshInfo(SpearFishingSettings, new SpearFishingConf());
        n += GebRefreshInfo(DigBugsSettings, new DigBugsConf());
        n += GebRefreshInfo(DigWormsSettings, new DigWormsConf());
        n += GebRefreshInfo(WeatherSettings, new WeatherConf());
        if (HookFromFishCatches) {
            HookFromFishEntry freshHook = new HookFromFishEntry();
            foreach (HookFromFishEntry hook : HookFromFishCatches)
                n += GebRefreshInfo(hook, freshHook);
        }
        if (TreasureContainers) {
            TreasureContainerEntry freshBox = new TreasureContainerEntry();
            foreach (TreasureContainerEntry box : TreasureContainers)
                n += GebRefreshInfo(box, freshBox);
        }
        if (TreasureLoot) {
            TreasureLootEntry freshLoot = new TreasureLootEntry();
            foreach (TreasureLootEntry loot : TreasureLoot)
                n += GebRefreshInfo(loot, freshLoot);
        }
        if (Predators) {
            PredatorEntry freshPredator = new PredatorEntry();
            foreach (PredatorEntry predator : Predators)
                n += GebRefreshInfo(predator, freshPredator);
        }
        if (BambooFishingNetSettings && BambooFishingNetSettings.Catches) {
            NetEntry freshNet = new NetEntry();
            foreach (NetEntry net : BambooFishingNetSettings.Catches)
                n += GebRefreshInfo(net, freshNet);
        }
        if (SpearFishingSettings && SpearFishingSettings.Catches) {
            SpearEntry freshSpear = new SpearEntry();
            foreach (SpearEntry spear : SpearFishingSettings.Catches)
                n += GebRefreshInfo(spear, freshSpear);
        }
        BugEntry freshBug = new BugEntry();
        if (DigBugsSettings && DigBugsSettings.Catches) {
            foreach (BugEntry bug : DigBugsSettings.Catches)
                n += GebRefreshInfo(bug, freshBug);
        }
        if (DigWormsSettings && DigWormsSettings.Catches) {
            foreach (BugEntry worm : DigWormsSettings.Catches)
                n += GebRefreshInfo(worm, freshBug);
        }
        return n;
    }

    void Save() {
        GebMakeConfigDir();
        string error;
        if (!JsonFileLoader<GeneralConfig>.SaveFile(PATH, this, error))
            GebsfishLogger.Error("general.json could not be written: " + error, "Config");
    }

    // Re-seeds whatever the file is missing and returns true if anything had
    // to be added, so Load can decide whether to persist. Values the file
    // holds are never overwritten. "Missing" is read from the file text
    // (GebJsonKeys): the loader turns a missing section into an all-zero
    // object, never null, and reads a missing list as an empty one, so the
    // loaded object can't say what the file lacked. A section or list written
    // as null counts as missing, the way the loader treats it.
    bool Backfill() {
        bool changed = false;
        GebJsonKeys file = new GebJsonKeys(PATH, 2);
        if (!GeneralSettings || !file.Has("GeneralSettings"))   { GeneralSettings = new GenSetConf;       changed = true; }
        if (!RecipeToggles || !file.Has("RecipeToggles"))       { RecipeToggles = new RecipeToggleConf;   changed = true; }
        if (!PredatorSettings || !file.Has("PredatorSettings")) { PredatorSettings = new PredatorConf;    changed = true; }
        if (!WeatherSettings || !file.Has("WeatherSettings"))   { WeatherSettings = new WeatherConf;      changed = true; }
        if (!TreasureSettings || !file.Has("TreasureSettings")) { TreasureSettings = new TreasureConf;    changed = true; }
        // Settings added to an EXISTING section need their own check: the
        // section is there, the field just isn't, and the loader leaves a
        // field missing from a section at 0 / false (it builds sections
        // without their class defaults). Ask the file directly, so a server
        // that never had the toggle gets the intended default while one that
        // has it keeps the admin's choice, including a deliberate 0.
        if (RecipeToggles && !file.Has("RecipeToggles.CraftFishMount")) {
            RecipeToggles.CraftFishMount = true;
            changed = true;
        }
        if (TreasureSettings && !file.Has("TreasureSettings.RequireRealRod")) {
            TreasureSettings.RequireRealRod = true;
            changed = true;
        }
        if (TreasureSettings && !file.Has("TreasureSettings.RodCatchesToRuin")) {
            TreasureSettings.RodCatchesToRuin = 3;
            changed = true;
        }
        // A per-action section that is entirely missing (fresh key never
        // written, or hand-deleted) is re-seeded with working defaults, and so
        // is a Catches table missing from a section that is there. A table the
        // file holds but empty was emptied on purpose and is left alone.
        if (!BambooFishingNetSettings || !file.Has("BambooFishingNetSettings")) {
            BambooFishingNetSettings = null;
            SeedDefaultNetCatches();
            changed = true;
        } else if (!file.Has("BambooFishingNetSettings.Catches")) {
            BambooFishingNetSettings.Catches = null;
            SeedDefaultNetCatches();
            changed = true;
        }
        if (!SpearFishingSettings || !file.Has("SpearFishingSettings")) {
            SpearFishingSettings = null;
            SeedDefaultSpearCatches();
            changed = true;
        } else if (!file.Has("SpearFishingSettings.Catches")) {
            SpearFishingSettings.Catches = null;
            SeedDefaultSpearCatches();
            changed = true;
        }
        if (!DigBugsSettings || !file.Has("DigBugsSettings")) {
            DigBugsSettings = null;
            SeedDefaultDigBugsCatches();
            changed = true;
        } else if (!file.Has("DigBugsSettings.Catches")) {
            DigBugsSettings.Catches = null;
            SeedDefaultDigBugsCatches();
            changed = true;
        }
        if (!DigWormsSettings || !file.Has("DigWormsSettings")) {
            DigWormsSettings = null;
            SeedDefaultDigWormsCatches();
            changed = true;
        } else if (!file.Has("DigWormsSettings.Catches")) {
            DigWormsSettings.Catches = null;
            SeedDefaultDigWormsCatches();
            changed = true;
        }
        if (!Predators || !file.Has("Predators")) { Predators = null; SeedDefaultPredators(); changed = true; }
        // These three pools are refilled when they are empty, too.
        if (!HookFromFishCatches || HookFromFishCatches.Count() == 0 || !file.Has("HookFromFishCatches")) { HookFromFishCatches = null; SeedHookFromFish(); changed = true; }
        if (!TreasureContainers || TreasureContainers.Count() == 0 || !file.Has("TreasureContainers")) { TreasureContainers = null; SeedTreasureContainers(); changed = true; }
        if (!TreasureLoot || TreasureLoot.Count() == 0 || !file.Has("TreasureLoot")) { TreasureLoot = null; SeedTreasureLoot(); changed = true; }
        if (CorrectLegacyHookClassnames()) changed = true;
        return changed;
    }

    // Earlier defaults used FishingHook, but the vanilla item is Hook.
    // Keep that name if another loaded mod actually defines it.
    protected bool CorrectLegacyHookClassnames() {
        if (g_Game.ConfigIsExisting("CfgVehicles FishingHook"))
            return false;
        bool changed = false;
        foreach (HookFromFishEntry hook : HookFromFishCatches) {
            if (hook && GebSameClassname(hook.Classname, "FishingHook")) {
                hook.Classname = "Hook";
                changed = true;
            }
        }
        foreach (TreasureLootEntry loot : TreasureLoot) {
            if (loot && GebSameClassname(loot.Classname, "FishingHook")) {
                loot.Classname = "Hook";
                changed = true;
            }
        }
        return changed;
    }

    // Additive update merge (version-change only, see Load): insert default
    // entries missing from the loaded arrays; never modify existing ones.
    // Runs after Backfill, which has already re-seeded every section and list
    // the file didn't have -- so a list that is empty here was written empty.
    // It is skipped: an admin emptied it on purpose, and the docs promise it
    // stays that way. The exceptions are HookFromFishCatches,
    // TreasureContainers and TreasureLoot, which Backfill refills when empty.
    // A row deleted from a list that still has entries is re-added; to
    // disable an entry permanently use weight/chance 0 instead of deleting it.
    int MergeNewDefaults() {
        GeneralConfig defaults = new GeneralConfig();
        defaults.SeedDefaults();
        int added = 0;
        if (Predators && Predators.Count() > 0 && defaults.Predators) {
            foreach (PredatorEntry dp : defaults.Predators) {
                if (dp && !HasPredator(dp.Classname)) { Predators.Insert(dp); added++; }
            }
        }
        if (BambooFishingNetSettings && BambooFishingNetSettings.Catches && BambooFishingNetSettings.Catches.Count() > 0 && defaults.BambooFishingNetSettings && defaults.BambooFishingNetSettings.Catches) {
            foreach (NetEntry dn : defaults.BambooFishingNetSettings.Catches) {
                if (dn && !HasNetCatch(dn.Classname)) { BambooFishingNetSettings.Catches.Insert(dn); added++; }
            }
        }
        if (SpearFishingSettings && SpearFishingSettings.Catches && SpearFishingSettings.Catches.Count() > 0 && defaults.SpearFishingSettings && defaults.SpearFishingSettings.Catches) {
            foreach (SpearEntry ds : defaults.SpearFishingSettings.Catches) {
                if (ds && !HasSpearCatch(ds.Classname)) { SpearFishingSettings.Catches.Insert(ds); added++; }
            }
        }
        if (DigBugsSettings && defaults.DigBugsSettings)
            added += MergeBugCatches(DigBugsSettings.Catches, defaults.DigBugsSettings.Catches);
        if (DigWormsSettings && defaults.DigWormsSettings)
            added += MergeBugCatches(DigWormsSettings.Catches, defaults.DigWormsSettings.Catches);
        if (HookFromFishCatches && defaults.HookFromFishCatches) {
            foreach (HookFromFishEntry dh : defaults.HookFromFishCatches) {
                if (dh && !HasHookCatch(dh.Classname)) { HookFromFishCatches.Insert(dh); added++; }
            }
        }
        if (TreasureContainers && defaults.TreasureContainers) {
            foreach (TreasureContainerEntry dc : defaults.TreasureContainers) {
                if (dc && !HasTreasureContainer(dc.Classname)) { TreasureContainers.Insert(dc); added++; }
            }
        }
        if (TreasureLoot && defaults.TreasureLoot) {
            foreach (TreasureLootEntry dl : defaults.TreasureLoot) {
                if (dl && !HasTreasureLoot(dl.Classname)) { TreasureLoot.Insert(dl); added++; }
            }
        }

        // Recipe toggles are NOT handled here. A toggle added to an existing
        // section can't be spotted on the loaded object: the loader builds the
        // RecipeToggles section without its class defaults, so a toggle added
        // in a later version loads as 0 on every server whose config predates
        // it -- indistinguishable from an admin deliberately switching it off.
        // Backfill() settles that by asking the file text whether the key is
        // there (GebJsonKeys), never by version number. A new RecipeToggleConf
        // bool needs its own key check in Backfill(); copy the CraftFishMount
        // block there.
        return added;
    }
    protected bool HasPredator(string classname) {
        foreach (PredatorEntry e : Predators) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
    }
    protected bool HasNetCatch(string classname) {
        foreach (NetEntry e : BambooFishingNetSettings.Catches) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
    }
    protected bool HasSpearCatch(string classname) {
        foreach (SpearEntry e : SpearFishingSettings.Catches) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
    }
    protected bool HasHookCatch(string classname) {
        foreach (HookFromFishEntry e : HookFromFishCatches) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
    }

    bool HasTreasureContainer(string classname) {
        if (!TreasureContainers) return false;
        foreach (TreasureContainerEntry c : TreasureContainers) if (c && GebSameClassname(c.Classname, classname)) return true;
        return false;
    }

    bool HasTreasureLoot(string classname) {
        if (!TreasureLoot) return false;
        foreach (TreasureLootEntry l : TreasureLoot) if (l && GebSameClassname(l.Classname, classname)) return true;
        return false;
    }
    protected static int MergeBugCatches(array<ref BugEntry> into, array<ref BugEntry> defs) {
        if (!into || into.Count() == 0 || !defs)      // emptied on purpose: left alone
            return 0;
        int added = 0;
        foreach (BugEntry d : defs) {
            if (!d) continue;
            bool found = false;
            foreach (BugEntry e : into) {
                if (e && GebSameClassname(e.Classname, d.Classname)) { found = true; break; }
            }
            if (!found) { into.Insert(d); added++; }
        }
        return added;
    }

    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        GeneralSettings = new GenSetConf;
        RecipeToggles = new RecipeToggleConf;
        PredatorSettings = new PredatorConf;
        WeatherSettings = new WeatherConf;
        BambooFishingNetSettings = new BambooFishingNetConf;
        SpearFishingSettings = new SpearFishingConf;
        DigBugsSettings = new DigBugsConf;
        DigWormsSettings = new DigWormsConf;
        SeedHookFromFish();
        TreasureSettings = new TreasureConf;
        SeedTreasureContainers();
        SeedTreasureLoot();
        SeedDefaultPredators();
        SeedDefaultNetCatches();
        SeedDefaultSpearCatches();
        SeedDefaultDigBugsCatches();
        SeedDefaultDigWormsCatches();
    }

    void SeedHookFromFish() {
        if (!HookFromFishCatches) HookFromFishCatches = new array<ref HookFromFishEntry>();
        HookFromFishEntry h = new HookFromFishEntry();
        h.Classname = "Hook"; h.Weight = 1.0; h.MinHealthLevel = 3; h.MaxHealthLevel = 3;
        HookFromFishCatches.Insert(h);
    }

    // Deliberately small starting pools of plain vanilla classnames -- every
    // server has them, so treasure works out of the box without depending on
    // another mod. They are meant to be replaced: this is the one feature where
    // the whole point is that the admin decides what is worth finding.
    void SeedTreasureContainers() {
        if (!TreasureContainers) TreasureContainers = new array<ref TreasureContainerEntry>();
        TreasureContainerEntry c;
        c = new TreasureContainerEntry();
        c.Classname = "SeaChest";    c.Weight = 1.0;  c.MinHealthLevel = 1; c.MaxHealthLevel = 3; c.MinItems = 3; c.MaxItems = 6;
        TreasureContainers.Insert(c);
        c = new TreasureContainerEntry();
        c.Classname = "WoodenCrate"; c.Weight = 2.0;  c.MinHealthLevel = 2; c.MaxHealthLevel = 3; c.MinItems = 2; c.MaxItems = 4;
        TreasureContainers.Insert(c);
        c = new TreasureContainerEntry();
        c.Classname = "DryBag_Black"; c.Weight = 3.0; c.MinHealthLevel = 1; c.MaxHealthLevel = 3; c.MinItems = 1; c.MaxItems = 3;
        TreasureContainers.Insert(c);
    }

    void SeedTreasureLoot() {
        if (!TreasureLoot) TreasureLoot = new array<ref TreasureLootEntry>();
        TreasureLootEntry l;
        l = new TreasureLootEntry(); l.Classname = "Rag";              l.Weight = 6.0; l.MinHealthLevel = 2; l.MaxHealthLevel = 4; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Nail";             l.Weight = 5.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; l.MinQuantity = 5; l.MaxQuantity = 30; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Rope";             l.Weight = 4.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "DuctTape";         l.Weight = 3.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Hook";      l.Weight = 3.0; l.MinHealthLevel = 0; l.MaxHealthLevel = 2; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Canteen";          l.Weight = 2.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Screwdriver";      l.Weight = 2.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Matchbox";         l.Weight = 2.0; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Compass";          l.Weight = 1.0; l.MinHealthLevel = 0; l.MaxHealthLevel = 2; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "Binoculars";       l.Weight = 0.5; l.MinHealthLevel = 1; l.MaxHealthLevel = 3; TreasureLoot.Insert(l);
        l = new TreasureLootEntry(); l.Classname = "geb_BlackCaviar";  l.Weight = 0.5; l.MinHealthLevel = 0; l.MaxHealthLevel = 1; TreasureLoot.Insert(l);
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

    // Fish that come into the shallows: panfish, carp, bass, bowfin and
    // bullfrogs in fresh water; flounder (gigged in real life), grunts and
    // reef tang at sea; mullet and gar in both.
    void SeedDefaultSpearCatches() {
        if (!SpearFishingSettings) SpearFishingSettings = new SpearFishingConf;
        if (!SpearFishingSettings.Catches) SpearFishingSettings.Catches = new array<ref SpearEntry>();
        AddSpearCatch("Carp", 20, 1);
        AddSpearCatch("geb_BlueGill", 18, 1);
        AddSpearCatch("geb_YellowPerch", 15, 1);
        AddSpearCatch("geb_SunFish", 15, 1);
        AddSpearCatch("geb_AmericanBullFrog", 12, 1);
        AddSpearCatch("geb_LargeMouthBass", 10, 1);
        AddSpearCatch("geb_BowFin", 8, 1);
        AddSpearCatch("geb_FlatHeadMullet", 15, 3);
        AddSpearCatch("geb_AlligatorGar", 4, 3);
        AddSpearCatch("geb_SouthernFlounder", 20, 2);
        AddSpearCatch("geb_WhiteGrunt", 10, 2);
        AddSpearCatch("geb_BlueTang", 6, 2);
    }
    protected void AddSpearCatch(string classname, float weight, int environment) {
        SpearEntry entry = new SpearEntry();
        entry.Classname = classname;
        entry.CatchChance = weight;
        entry.Environment = environment;
        SpearFishingSettings.Catches.Insert(entry);
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
    string EnableInfo = "Master toggle for the bait / lure preference system. Each entry in Preferences pairs a bait classname with per-fish multipliers that bias the weighted catch pick while that bait is on the hook (e.g. a Worm makes BlueGill 2.0x more likely but large saltwater fish 0.3x). Set to 0 to disable the bias -- every bait becomes neutral 1.0x and only CatchProbability drives the pick. Bait still functions mechanically (a bite eats it, whether you land the fish or let it go; reeling in with no bite keeps it), and Preferences still loads from JSON so a server can flip this on/off without losing tuned values. Useful when bait should work but not influence outcomes, or to check whether unexpected fish come from bait bias vs weather/temperature/time-of-day multipliers.";
    bool Enable = 1;
    string PreferencesInfo = "Per-bait fish-preference table. Each entry pairs a bait/lure Classname with its own list of per-fish multipliers (the entry's Preferences array, each: a fish classname + a multiplier). Multiplier >1 = that fish is more likely on this bait, <1 = less, 1.0 = neutral. A Classname without a trailing number also covers its numbered variants (geb_SpinnerBait matches geb_SpinnerBait1 through geb_SpinnerBait4) -- add an entry with the exact numbered classname to tune one variant separately; the exact entry wins. Multipliers are rounded to the nearest 0.01 when this file is written. Only applied when Enable = 1.";
    // Multiplier semantics documented once here, not on every bait or fish entry.
    string MultiplierInfo = "How strongly this bait favours this fish in the weighted catch pick. 1.0 = neutral (same as having no entry), above 1.0 makes the fish more likely (2.0 = twice as likely), below 1.0 makes it less likely (0.3 = much rarer), 0 effectively removes it. Only used while the Enable toggle at the top of this file is on.";
    ref array<ref BaitConfig> Preferences;

    private const static string PATH = "$profile:Gebs/bait.json";
    bool Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<BaitSettingsConf>.LoadFile(PATH, this, err)) {
                GebsfishLogger.Error("bait.json failed to load; file preserved, using defaults for this session: " + err, "Config");
                return false;
            }
            // The top-level Preferences table, asked for by path: every bait
            // row has a Preferences list too. The loader reads a missing table
            // as an empty one, so only the file text tells "not there"
            // (re-seeded) from "emptied on purpose" (kept); a table with rows
            // came from the file, so only an empty one needs the file asked.
            if (!Preferences || (Preferences.Count() == 0 && !GebJsonFileHasKey(PATH, "Preferences"))) { SeedDefaultPreferences(); changed = true; }
            if (RenameLegacyFish()) changed = true;
            if (ConfigVersion != VERSION_GEBSFISH) {
                int added = MergeNewDefaults();
                if (added > 0)
                    GebsfishLogger.Info("bait.json: added " + added.ToString() + " new default bait rows / fish preferences (update '" + ConfigVersion + "' -> '" + VERSION_GEBSFISH + "'). Existing multipliers untouched.", "Migrate");
                ConfigVersion = VERSION_GEBSFISH;
                changed = true;
            }
            // the current help text (the rows carry none)
            if (GebRefreshInfo(this, new BaitSettingsConf()) > 0)
                changed = true;
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
        return true;
    }

    // 3.3.3 renamed geb_Bonita to geb_PacificBonito. A preference written
    // before that takes the new name, keeping its multiplier; where the bait
    // already has a geb_PacificBonito preference the old one is dropped.
    // Runs before the merge, so the merge doesn't add a second, default row.
    protected bool RenameLegacyFish() {
        if (!Preferences)
            return false;
        bool changed = false;
        foreach (BaitConfig bait : Preferences) {
            if (!bait || !bait.Preferences)
                continue;
            bool hasNew = false;
            foreach (BaitPreferenceEntry seen : bait.Preferences) {
                if (seen && GebSameClassname(seen.FishClassname, "geb_PacificBonito"))
                    hasNew = true;
            }
            for (int i = bait.Preferences.Count() - 1; i >= 0; i--) {
                BaitPreferenceEntry pref = bait.Preferences[i];
                if (!pref || !GebSameClassname(pref.FishClassname, "geb_Bonita"))
                    continue;
                if (hasNew) {
                    bait.Preferences.RemoveOrdered(i);
                } else {
                    pref.FishClassname = "geb_PacificBonito";
                    hasNew = true;
                }
                changed = true;
            }
        }
        if (changed)
            GebsfishLogger.Info("bait.json: preferences for geb_Bonita now name geb_PacificBonito (renamed in 3.3.3; multipliers kept).", "Migrate");
        return changed;
    }
    void Save() {
        GebMakeConfigDir();
        string error;
        if (!JsonFileLoader<BaitSettingsConf>.SaveFile(PATH, this, error)) {
            GebsfishLogger.Error("bait.json could not be written: " + error, "Config");
            return;
        }
        RoundMultiplierLines();
    }
    // The JSON writer serializes floats at full double precision, so a seeded
    // 1.4 lands in the file as "1.399999976158142". Rewrite every
    // "Multiplier": line with the value rounded to the nearest 0.01 to keep
    // the generated file hand-editable. Line-based on purpose: the writer
    // emits one field per line and Multiplier is the only float in this file.
    protected void RoundMultiplierLines() {
        string key = "\"Multiplier\":";
        FileHandle fr = OpenFile(PATH, FileMode.READ);
        if (!fr)
            return;
        array<string> lines = new array<string>();
        string line;
        while (FGets(fr, line) != -1) {
            int idx = line.IndexOf(key);
            if (idx != -1) {
                int valueStart = idx + key.Length();
                string value = line.Substring(valueStart, line.Length() - valueStart);
                bool hadComma = value.IndexOf(",") != -1;
                value.Replace(",", "");
                value.TrimInPlace();
                // Round in integer hundredths so the rebuilt text can't
                // reintroduce float noise. Negative values clamp to 0.0,
                // matching the floor in GetBaitMultiplier.
                int hundredths = Math.Round(value.ToFloat() * 100.0);
                if (hundredths < 0)
                    hundredths = 0;
                int whole = hundredths / 100;
                int frac = hundredths % 100;
                string fracText;
                if (frac % 10 == 0) {
                    int fracTenth = frac / 10;
                    fracText = fracTenth.ToString();         // 1.4, 2.0
                } else if (frac < 10)
                    fracText = "0" + frac.ToString();        // 0.05
                else
                    fracText = frac.ToString();              // 0.25
                line = line.Substring(0, valueStart) + " " + whole.ToString() + "." + fracText;
                if (hadComma)
                    line += ",";
            }
            lines.Insert(line);
        }
        CloseFile(fr);

        FileHandle fw = OpenFile(PATH, FileMode.WRITE);
        if (!fw)
            return;
        foreach (string outLine : lines)
            FPrintln(fw, outLine);
        CloseFile(fw);
    }
    void SeedDefaults() {
        ConfigVersion = VERSION_GEBSFISH;
        Enable = true;
        SeedDefaultPreferences();
    }

    // Additive update merge (version-change only, see Load). Two levels:
    //   1. a default bait/lure row missing entirely -> whole row inserted
    //   2. a default per-fish preference missing from an existing row (e.g.
    //      a fish added this update) -> just that preference inserted
    // Existing multipliers are never modified; a Preferences list the file
    // holds but empty (the whole file's, or one bait's) was emptied on
    // purpose and is skipped. A bait row whose Preferences list is missing
    // from the file gets the defaults: the loader reads it as an empty list,
    // so the file text decides (GebJsonKeys). Numbered lure variants stay covered
    // by their family row (GetBaitMultiplier's trailing-digit fallback), and
    // an exact numbered entry still wins.
    int MergeNewDefaults() {
        if (!Preferences || Preferences.Count() == 0)
            return 0;
        GebJsonKeys file;
        BaitSettingsConf defaults = new BaitSettingsConf();
        defaults.SeedDefaultPreferences();
        int added = 0;
        foreach (BaitConfig db : defaults.Preferences) {
            if (!db)
                continue;
            BaitConfig mine = FindBait(db.BaitClassname);
            if (!mine) {
                Preferences.Insert(db);
                added++;
                continue;
            }
            if (!db.Preferences)
                continue;
            // An empty list is one the file holds empty (emptied on purpose,
            // kept) or one it doesn't have (filled in). Rows keep their order
            // from the file through the load and RenameLegacyFish, so a row's
            // index is its place in the file. The file is only read when some
            // row needs the answer.
            if (!mine.Preferences || mine.Preferences.Count() == 0) {
                if (!file)
                    file = new GebJsonKeys(PATH, 2);
                if (file.Has("Preferences[" + Preferences.Find(mine) + "].Preferences"))
                    continue;
            }
            if (!mine.Preferences)
                mine.Preferences = new array<ref BaitPreferenceEntry>();
            foreach (BaitPreferenceEntry dp : db.Preferences) {
                if (!dp)
                    continue;
                bool found = false;
                foreach (BaitPreferenceEntry mp : mine.Preferences) {
                    if (mp && GebSameClassname(mp.FishClassname, dp.FishClassname)) { found = true; break; }
                }
                if (!found) { mine.Preferences.Insert(dp); added++; }
            }
        }
        return added;
    }
    protected BaitConfig FindBait(string baitClassname) {
        foreach (BaitConfig b : Preferences) {
            if (b && GebSameClassname(b.BaitClassname, baitClassname)) return b;
        }
        return null;
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
        // Shrimp is the signature reef/tropical bait -- the one bucket no
        // other bait favors -- and a strong general saltwater live bait.
        SeedBait("Shrimp",            1.0, 1.2, 0.5, 0.8, 0.8, 1.4, 0.8, 0.4, 0.9, 0.7, 1.5, 1.8, 2.5);
        // Vanilla's trap baitfish. Bitterlings, from traps in fresh water, take
        // the predators a minnow does; sardines, from traps at sea, are the big
        // saltwater bait (tuna, marlin, sharks).
        SeedBait("Bitterlings",       0.6, 2.0, 2.5, 2.2, 1.2, 1.8, 0.3, 0.8, 0.8, 0.6, 0.6, 0.4, 0.3);
        SeedBait("Sardines",          0.4, 0.8, 1.0, 0.8, 0.6, 1.5, 0.3, 0.3, 0.5, 2.5, 2.0, 1.2, 1.0);

        // One row per lure family: GetBaitMultiplier's trailing-digit
        // fallback resolves geb_SpinnerBait1..4 etc. to these rows, and an
        // exact numbered entry (e.g. geb_SpinnerBait2) still overrides.
        SeedBait("geb_SpinnerBait",  0.8, 2.5, 2.3, 2.0, 1.5, 1.0, 0.3, 0.5, 1.0, 0.8, 1.0, 1.2, 0.6);
        SeedBait("geb_SpoonLure",    0.6, 1.5, 2.0, 1.8, 2.5, 0.8, 0.3, 0.4, 1.0, 1.8, 2.0, 1.5, 1.0);
        SeedBait("geb_Lure",         0.7, 2.0, 1.8, 1.8, 1.5, 1.0, 0.3, 0.5, 1.0, 1.3, 1.5, 1.0, 0.7);
        SeedBait("geb_CurlyTailJig", 1.5, 2.2, 1.3, 2.0, 1.0, 0.8, 0.5, 0.5, 1.0, 0.7, 1.0, 0.8, 0.6);
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
        s_CatSaltwaterMed = {"geb_AsianSeaBass", "geb_PacificBonito", "geb_GreatBarracuda", "geb_MahiMahi", "geb_RoughNeckRock", "geb_SiameseTigerFish", "WalleyePollock", "geb_PacificCod", "geb_LargeHeadHairTailFish", "geb_SouthernFlounder"};
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
    // Lets SeedBait emit per-category preferences in one line per
    // (bait, category) pair instead of per fish.
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
    string JunkShareInfo = "Share of rod catches that come up as junk instead of a fish, from 0 to 0.9 (0.1 = about 1 catch in 10, close to vanilla DayZ's rate; 0 = no junk). It holds on every map, in every season and at every hour: each cast, junk's weight is set from the fish that can bite there. In water where no fish can bite, a rod pulls only junk, as in vanilla.";
    float JunkShare = 0.1;
    string JunkInfo = "Table of 'junk' items a rod can pull instead of a fish (nets and traps never catch junk). JunkShare sets how often junk comes up; each entry's CatchProbability (0-25) only sets how often that item turns up compared with the other junk (0 = never). MinHealthLevel/MaxHealthLevel = health range, 0 pristine .. 4 ruined (the spawned item's health is rolled in this range).";
    ref array<ref JunkEntry>          Junk;
    string ContainerJunkInfo = "Like Junk, but for liquid containers (e.g. the Pot), which come up empty. They share JunkShare with the Junk items. Same fields: Classname, CatchProbability (0-25), MinHealthLevel/MaxHealthLevel (0-4).";
    ref array<ref ContainerJunkEntry> ContainerJunk;

    private const static string PATH = "$profile:Gebs/junk.json";
    bool Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<JunkConfig>.LoadFile(PATH, this, err)) {
                GebsfishLogger.Error("junk.json failed to load; file preserved, using defaults for this session: " + err, "Config");
                return false;
            }
            changed = Backfill();
            if (ConfigVersion != VERSION_GEBSFISH) {
                int added = MergeNewDefaults();
                if (added > 0)
                    GebsfishLogger.Info("junk.json: added " + added.ToString() + " new default entries (update '" + ConfigVersion + "' -> '" + VERSION_GEBSFISH + "'). Existing entries untouched.", "Migrate");
                ConfigVersion = VERSION_GEBSFISH;
                changed = true;
            }
            if (RefreshInfoStrings() > 0)
                changed = true;
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
        return true;
    }
    void Save() {
        GebMakeConfigDir();
        string error;
        if (!JsonFileLoader<JunkConfig>.SaveFile(PATH, this, error))
            GebsfishLogger.Error("junk.json could not be written: " + error, "Config");
    }
    // Re-seeds a table the file doesn't have (or has as null). Whether it is
    // there comes from the file text (GebJsonKeys): the loader reads a missing
    // table as an empty one, the same as one emptied on purpose, which is kept.
    bool Backfill() {
        bool changed = false;
        GebJsonKeys file = new GebJsonKeys(PATH, 1);
        if (!Junk || !file.Has("Junk"))                   { Junk = null;          SeedDefaultJunk();          changed = true; }
        if (!ContainerJunk || !file.Has("ContainerJunk")) { ContainerJunk = null; SeedDefaultContainerJunk(); changed = true; }
        // A file written before JunkShare existed doesn't have it. JunkShare
        // sits at the top of the file, where the loader leaves a missing value
        // at the class default -- but ask the file anyway: a file without it
        // gets it written in, and a deliberate 0 is kept.
        if (!file.Has("JunkShare")) {
            JunkConfig defaults = new JunkConfig();
            JunkShare = defaults.JunkShare;
            changed = true;
        }
        return changed;
    }

    // The current help text in every ...Info field (GebRefreshInfo), the
    // file's own and every row's (each row carries its own copy). Returns how
    // many changed.
    protected int RefreshInfoStrings() {
        int n = GebRefreshInfo(this, new JunkConfig());
        if (Junk) {
            JunkEntry freshJunk = new JunkEntry();
            foreach (JunkEntry j : Junk)
                n += GebRefreshInfo(j, freshJunk);
        }
        if (ContainerJunk) {
            ContainerJunkEntry freshContainer = new ContainerJunkEntry();
            foreach (ContainerJunkEntry c : ContainerJunk)
                n += GebRefreshInfo(c, freshContainer);
        }
        return n;
    }

    // Additive update merge (version-change only, see Load): insert default
    // entries missing from the loaded tables; never modify existing ones. A
    // table that is empty here was written empty (Backfill re-seeds one the
    // file doesn't have) and is left alone (emptied on purpose). Permanently
    // remove one entry by setting CatchProbability 0, not deletion.
    int MergeNewDefaults() {
        JunkConfig defaults = new JunkConfig();
        defaults.SeedDefaultJunk();
        defaults.SeedDefaultContainerJunk();
        int added = 0;
        if (Junk && Junk.Count() > 0 && defaults.Junk) {
            foreach (JunkEntry dj : defaults.Junk) {
                if (dj && !HasJunk(dj.Classname)) { Junk.Insert(dj); added++; }
            }
        }
        if (ContainerJunk && ContainerJunk.Count() > 0 && defaults.ContainerJunk) {
            foreach (ContainerJunkEntry dc : defaults.ContainerJunk) {
                if (dc && !HasContainerJunk(dc.Classname)) { ContainerJunk.Insert(dc); added++; }
            }
        }
        return added;
    }
    protected bool HasJunk(string classname) {
        foreach (JunkEntry e : Junk) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
    }
    protected bool HasContainerJunk(string classname) {
        foreach (ContainerJunkEntry e : ContainerJunk) if (e && GebSameClassname(e.Classname, classname)) return true;
        return false;
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
    // with the string's tail) when a string member's value IN MEMORY is 1024
    // bytes or more -- for a config class that is the compiled default literal,
    // which the reader copies into a 1024-byte buffer before it reads the file.
    // Bracketed empirically: 955 loads, 1458 crashed the server on every restart.
    // A long value in the FILE doesn't crash (it is cut to 1023 bytes), and no
    // edit to the file can fix the crash. Keep every string literal in this
    // file under ~900 bytes.
    string SpeciesInfo = "One object per fish/catchable. Classname = catchable item classname (also the fillet-recipe ingredient). RecipeShape: 0 = fillet only, 1 = caviar (ResultBonus caviar at index 0, gated by GeneralSettings.CaviarChance), 2 = lobster (ResultBonus tail at index 0). ResultMain = repeated fillet/claw result classname ('' = catch-only, no recipe). MeatMin/MeatMax = fillets per prepare. Environment: 1 pond, 2 sea, 3 both. CatchMethod bitmask: 1 rod + 2 largetrap + 4 smalltrap, added together (7 = all). CatchProbability = 0-25 abundance weight (0 = uncatchable). Rain/Storm/Dawn/Day/Dusk/NightMultiplier = per-species catch-bias multipliers (1.0 = no effect). TempOptimal/TempMin/TempMax = water-temperature preference in degrees Celsius. BiteSpeed = 24 space-separated hourly bite-speed values (index 0 = 12AM), each 0.0-1.0 where 1.0 = vanilla speed.";
    ref array<ref FishConf>           Species;

    private const static string PATH = "$profile:Gebs/fish.json";

    // Case-blind (GebSameClassname): the caught fish's type is the config's
    // spelling, the row is the admin's.
    FishConf Get(string classname) {
        if (!Species) return null;
        foreach (FishConf f : Species) if (f && GebSameClassname(f.Classname, classname)) return f;
        return null;
    }

    bool Load() {
        bool changed = false;
        if (FileExist(PATH)) {
            string err;
            if (!JsonFileLoader<FishConfig>.LoadFile(PATH, this, err)) {
                GebsfishLogger.Error("fish.json failed to load; file preserved, using defaults for this session: " + err, "Config");
                return false;
            }
            changed = Backfill();
            if (RenameLegacyFish()) changed = true;
            if (ConfigVersion != VERSION_GEBSFISH) {
                int added = MergeNewDefaults();
                if (added > 0)
                    GebsfishLogger.Info("fish.json: added " + added.ToString() + " new default species (update '" + ConfigVersion + "' -> '" + VERSION_GEBSFISH + "'). Existing entries untouched.", "Migrate");
                ConfigVersion = VERSION_GEBSFISH;
                changed = true;
            }
            // the current help text (the species rows carry none)
            if (GebRefreshInfo(this, new FishConfig()) > 0)
                changed = true;
        } else {
            SeedDefaults();
            changed = true;
        }
        if (changed) Save();
        return true;
    }
    // 3.3.3 renamed geb_Bonita to geb_PacificBonito (and its fillet). A row
    // written before that takes the new names, keeping the admin's tuning;
    // if geb_PacificBonito already has a row the old one is dropped. Runs
    // before the merge, so the merge doesn't add a second, default row.
    protected bool RenameLegacyFish() {
        if (!Species)
            return false;
        bool hasNew = false;
        foreach (FishConf seen : Species) {
            if (seen && GebSameClassname(seen.Classname, "geb_PacificBonito"))
                hasNew = true;
        }
        bool changed = false;
        for (int i = Species.Count() - 1; i >= 0; i--) {
            FishConf f = Species[i];
            if (!f || !GebSameClassname(f.Classname, "geb_Bonita"))
                continue;
            if (hasNew) {
                Species.RemoveOrdered(i);
                GebsfishLogger.Info("fish.json: dropped the old geb_Bonita row; geb_PacificBonito already has one.", "Migrate");
            } else {
                f.Classname = "geb_PacificBonito";
                hasNew = true;
                GebsfishLogger.Info("fish.json: renamed geb_Bonita to geb_PacificBonito (renamed in 3.3.3; its settings kept).", "Migrate");
            }
            changed = true;
        }
        // The fillet's old name, on the bonito's row or any other an admin
        // gave it to: the class is gone, so a row still naming it would
        // fillet into nothing.
        foreach (FishConf row : Species) {
            if (!row)
                continue;
            if (GebSameClassname(row.ResultMain, "geb_BonitaFilletMeat")) {
                row.ResultMain = "geb_PacificBonitoFilletMeat";
                changed = true;
            }
            if (GebSameClassname(row.ResultBonus, "geb_BonitaFilletMeat")) {
                row.ResultBonus = "geb_PacificBonitoFilletMeat";
                changed = true;
            }
        }
        return changed;
    }

    void Save() {
        GebMakeConfigDir();
        string error;
        if (!JsonFileLoader<FishConfig>.SaveFile(PATH, this, error))
            GebsfishLogger.Error("fish.json could not be written: " + error, "Config");
    }

    // Re-seeds the Species table when the file doesn't have it (or has it as
    // null). The loader reads a missing table as an empty one, so the file
    // text decides; "Species": [] written on purpose is kept.
    bool Backfill() {
        if (!Species || (Species.Count() == 0 && !GebJsonFileHasKey(PATH, "Species"))) { SeedSpecies(); return true; }
        return false;
    }

    // Additive update merge: any species the compiled defaults have but the
    // loaded file lacks is inserted. Runs only on a version change (see
    // Load), so in-version admin deletions are respected until the next mod
    // update; existing rows are never modified, and a Species list written
    // empty is left empty (Backfill re-seeds one the file doesn't have). To
    // remove a species permanently, set its CatchProbability to 0 instead of
    // deleting it.
    int MergeNewDefaults() {
        if (!Species || Species.Count() == 0)
            return 0;
        FishConfig defaults = new FishConfig();
        defaults.SeedSpecies();
        int added = 0;
        foreach (FishConf def : defaults.Species) {
            if (def && !Get(def.Classname)) { Species.Insert(def); added++; }
        }
        return added;
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
    // Each helper returns the 24 values as one space-separated string
    // (FishConf.BiteSpeed is a string; GetBiteSpeedArray parses it per fish).
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
        f = new FishConf(); f.Classname="geb_LakeTrout"; f.RecipeShape=1; f.ResultMain="geb_LakeTroutFilletMeat"; f.ResultBonus="RedCaviar"; f.MeatMin=1; f.MeatMax=2; f.Environment=1; f.CatchMethod=3; f.CatchProbability=8; f.RainMultiplier=1.3; f.StormMultiplier=1.2; f.DawnMultiplier=1.3; f.DayMultiplier=0.9; f.DuskMultiplier=1.3; f.NightMultiplier=1.1; f.TempOptimal=10.0; f.TempMin=2.0; f.TempMax=16.0; f.BiteSpeed=BiteCrepuscular(); Species.Insert(f);
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
        f = new FishConf(); f.Classname="geb_PacificBonito"; f.RecipeShape=0; f.ResultMain="geb_PacificBonitoFilletMeat"; f.ResultBonus=""; f.MeatMin=1; f.MeatMax=2; f.Environment=2; f.CatchMethod=3; f.CatchProbability=10; f.RainMultiplier=1.1; f.StormMultiplier=1.3; f.DawnMultiplier=1.2; f.DayMultiplier=1.0; f.DuskMultiplier=1.2; f.NightMultiplier=1.0; f.TempOptimal=22.0; f.TempMin=14.0; f.TempMax=28.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
        f = new FishConf(); f.Classname="geb_GreatBarracuda"; f.RecipeShape=0; f.ResultMain="geb_GreatBarracudaFilletMeat"; f.ResultBonus=""; f.MeatMin=2; f.MeatMax=4; f.Environment=2; f.CatchMethod=1; f.CatchProbability=6; f.RainMultiplier=1.0; f.StormMultiplier=1.1; f.DawnMultiplier=1.3; f.DayMultiplier=1.0; f.DuskMultiplier=1.3; f.NightMultiplier=0.7; f.TempOptimal=26.0; f.TempMin=18.0; f.TempMax=32.0; f.BiteSpeed=BitePelagic(); Species.Insert(f);
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
// True while the main menu is loading or running. DayZ runs the menu as an
// offline session, so IsServer() is true there. This is the same test vanilla
// uses to decide to build MissionMainMenu (CreateMission in
// 5_mission/somemission.c). The engine sets the mission path before it builds
// the mission, so this is already right while the menu's world and recipes
// are being set up.
static bool GebIsMainMenu() {
    if (g_Game.IsMultiplayer())
        return false;
    string path = GetDayZGame().GetMissionPath();
    return path.Contains("NoCutscene") || path.Contains("intro");
}

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
        if (!g_Game.IsServer() || GebIsMainMenu()) {
            // Server owns disk config; clients receive it by RPC. The main
            // menu counts as a server (it's an offline session) but must not
            // read or write the player's files either.
            // Defaults provide provisional catch data during mission loading.
            // Recipe IDs no longer depend on Species membership or order.
            Fish.SeedDefaults();
            return;
        }

        // Sweep pre-3.3 layout files into Gebs/gebs_oldfiles before loading,
        // so an upgraded server never mixes old and new config files.
        GebsfishMigration.ArchiveOldFiles();

        if (!General.Load()) {
            // Discard any partially deserialized state; never save over a failed load.
            General = new GeneralConfig();
            General.SeedDefaults();
        }
        if (!Bait.Load()) {
            // Discard any partially deserialized state; never save over a failed load.
            Bait = new BaitSettingsConf();
            Bait.SeedDefaults();
        }
        if (!Junk.Load()) {
            // Discard any partially deserialized state; never save over a failed load.
            Junk = new JunkConfig();
            Junk.SeedDefaults();
        }
        if (!Fish.Load()) {
            // Discard any partially deserialized state; never save over a failed load.
            Fish = new FishConfig();
            Fish.SeedDefaults();
        }
        GebValidateFishConfig(Fish);
        GebValidateRows(this);
    }
}

ref gebsfishConfig m_gebsConfig;
// Set when the main menu, or a client's game that held the config, ends: the
// next menu or offline game loads its own (MissionBase.InitWorldYieldDataDefaults).
bool g_GebConfigStale;

static gebsfishConfig GetGebSettingsConfig() {
    if (!m_gebsConfig) {
        GebsfishLogger.Info("Initializing gebsfish config.", "JSON");
        g_GebConfigStale = false;
        m_gebsConfig = new gebsfishConfig;
        m_gebsConfig.LoadAll();
    }
    return m_gebsConfig;
}

static void SetGebsfishConfig(gebsfishConfig config) {
    g_GebConfigStale = false;
    m_gebsConfig = config;
}

// Null-safe debug level: 0 off, 1 normal, 2 (ELEVATED_DEBUG) verbose.
static int GebGetDebugLevel() {
    if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.GeneralSettings)
        return 0;
    int lvl = m_gebsConfig.General.GeneralSettings.DebugLogs;
    // Admins reasonably assume higher = more logging, but the verbose sites
    // gate with `== ELEVATED_DEBUG` -- clamp 3+ down to 2 so cranking the
    // value up can never silently turn elevated logging OFF.
    if (lvl > ELEVATED_DEBUG)
        lvl = ELEVATED_DEBUG;
    return lvl;
}

//general settings config data
class GenSetConf {
    string DebugInfo = "Debug log level for the logs in $profile:Gebs/logs (warnings and errors also go to the server RPT). 0 = off, 1 = standard (per cast: date, hour, rain, water temperature, the species in the pool, the fish picked, the BiteSpeed aggregate and any multiplier clamp), 2 = elevated (adds the pool table, the per-fish BiteSpeed table and the bite chance on every tick). Set to 1 when tuning fishing config; 2 only when reproducing a specific bug since it is very chatty.";
    int DebugLogs = 0;
    string FishQualityInfo = "How full every caught fish comes out, from 0 to 1 (1 = a whole, full fish), and with it how much the fish weighs. Vanilla DayZ calls this catch quality and uses 0.35, then the rod, hook and bait add a small random bonus on top. The result is capped at 1, so values above 1.0 behave exactly like 1.0. Trader mods (DayZ-Expansion-Market, TraderPlus, Dr. Jones, etc.) look at how full an item is, and several refuse anything that is not full, so the default of 1.0 keeps every fish sellable. Lower it (e.g. 0.35) only if your trader buys partly-full items and you want vanilla-style size variation.";
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
    bool CraftFishMount = 1;
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
    string PredatorSpawnEnabledInfo = "Turns on(1) and off(0) the predators feature of the mod. When on, it will enable the random spawning of predators when fishing, filleting, using the bamboo net or spear fishing; off turns all of them off.";
    bool PredatorSpawnEnabled = 1;
    string PredatorSpawnChanceInfo = "Gate 1 of 3 for predator spawning -- the per-action chance that ANY predator is selected. Fishing is when a fish is caught, preparing is when filleting, failcatch is when fishing rolls nothing. Bamboo fishing net and spear fishing have their own predator chances under BambooFishingNetSettings.PredatorSpawnChance and SpearFishingSettings.PredatorSpawnChance. Set any to 0 to disable that path entirely. Final per-catch odds = thisChance * (predator weight / sum of weights), so 0.01 here with default wolf/bear weights gives wolves 1/150 and bear 1/300. See the comment above PredatorConf for the full three-gate breakdown.";
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

    string RainInfo = "RainThreshold is the rain intensity (0-1) above which the rain buff kicks in. Rain above StormThreshold uses StormCatchMultiplier instead. Snowfall counts as rain (Sakhal snows instead of raining): the heavier of the two decides.";
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

    string TemperatureInfo = "Per-species water-temperature catch buff. Each cast's water temperature is the map's own water temperature from the game's world data (Chernarus 15 C fresh / 23 C sea, Livonia 20 / 25, Sakhal 2 / -0.5; other maps use Chernarus's unless they define their own), swung by season (up to +/-6 C in fresh water and +/-3 C at sea, warmest in early August), plus WaterTempOffset. Each fish gets a bell curve: 1.0x at its TempOptimal, falling linearly to MinTempMultiplier as water drops to TempMin and to MaxTempMultiplier as it rises to TempMax, and clamped at those floors outside that range so no fish fully shuts down. All temps in degrees Celsius. Set TemperatureEffectEnable to 0 to disable entirely; set a fish's TempMin equal to its TempMax to disable just that fish. Independent of WeatherCatchBoostEnable.";
    bool TemperatureEffectEnable = 1;
    float MinTempMultiplier = 0.1;
    float MaxTempMultiplier = 0.1;
    string WaterTempOffsetInfo = "Admin offset (degrees Celsius) added to the water temperature before the per-fish curve is applied. Default 0 uses the map's own water temperature unchanged, which already makes cold maps cold (on Sakhal the cold-water species dominate) and warm seas warm. Use it for maps whose water doesn't fit: NEGATIVE for winter/cold-themed servers or custom maps that inherit Chernarus's values, POSITIVE for tropical servers. This shifts the curve globally without editing every fish's TempOptimal/TempMin/TempMax. Examples: -5 = a cooler year (trout/salmon/cod favoured, bass struggles); -10 = frozen-lake roleplay (only cold-water species feed); +5 = tropical (reef fish/marlin/mahi dominate, trout shut down). Water never goes below freezing.";
    float WaterTempOffset = 0.0;

    string BiteSpeedEnableInfo = "Master toggle for the per-fish BiteSpeed cycle scaling. Each fish has a 24-hour BiteSpeed array where 1.0 = bites at natural speed that hour and 0.5 = the cycle takes twice as long. The catching context aggregates these across the active fish pool (weighted by CatchProbability and the time-of-day multiplier) and stretches the catch cycle inversely -- lower aggregates mean longer waits between bites. Set to 0 to use vanilla cycle length regardless of the pool; the arrays still appear in JSON but have no in-game effect. Independent of WeatherCatchBoostEnable, MoonPhaseEnable, and TemperatureEffectEnable. Useful for a flat fishing experience without per-hour variance, or for isolating whether a tuning issue comes from BiteSpeed math vs other multipliers.";
    bool BiteSpeedEnable = 1;

    string SpeciesBuffsInfo = "Per-species multipliers live on each fish in fish.json (RainMultiplier, StormMultiplier, DawnMultiplier, DayMultiplier, DuskMultiplier, NightMultiplier, TempOptimal, TempMin, TempMax). They decide WHICH fish bites; the global multipliers above decide how OFTEN anything bites, and the two never multiply together. 1.0 = no effect, higher = more likely, lower = less likely.";
}

class PredatorEntry {
    string ClassnameInfo = "Classname of the predator to spawn (e.g. Animal_CanisLupus_Grey for a grey wolf, Animal_UrsusArctos for a bear).";
    string Classname;   //Classname of predator
    string SpawnChanceInfo = "Relative weight for this predator in the weighted pick (NOT a 0-1 percentage). The chance of this predator being chosen is its weight divided by the sum of all predator weights. Defaults: wolf 0.6 and bear 0.3 give the wolf 2/3 and the bear 1/3 of all spawns. This is Gate 2 of 3 -- see the comment above PredatorConf.";
    float SpawnChance;  //Spawn percentage chance
    string MinCountInfo = "Minimum number of this predator to spawn at once (uniform random between MinCount and MaxCount). 1/1 means always exactly one.";
    int MinCount;       //Minimum count of predators spawned
    string MaxCountInfo = "Maximum number of this predator to spawn at once (uniform random between MinCount and MaxCount, capped at 10). Raise above MinCount for a pack (e.g. 1/3 wolves).";
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
    string EnvironmentInfo = "Where this entry is allowed: 1 = pond/freshwater only, 2 = sea/saltwater only, 3 = both. Entries whose Environment doesn't match the water the net was cast in are skipped before the weighted pick. Always set it: a row without a valid Environment never catches anything, and the server log names it at startup.";
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
// in the Preferences list at all, or when the bait is configured but the
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

// One entry in SpearFishingSettings.Catches: the same shape as NetEntry.
class SpearEntry {
    string ClassnameInfo = "Classname of the catch this entry can produce (a fish, a frog or any other item).";
    string Classname;
    string CatchChanceInfo = "Relative weight within the spear's Catches table (not a 0-1 chance, and separate from FindChance). Among the entries valid for the water stabbed into, an entry's odds are its weight divided by the sum of those weights. 0 disables it without deleting it.";
    float CatchChance;
    string EnvironmentInfo = "Where this entry can be caught: 1 = pond/freshwater only, 2 = sea only, 3 = both. Always set it: a row without a valid Environment never catches anything, and the server log names it at startup.";
    int Environment = 1;
}

// Settings for ActionGebSpearFishing: the master switch, the per-stab find
// chance, how deep the water may be, the predator chance and the weighted
// Catches table.
class SpearFishingConf {
    string EnableInfo = "Turns spear fishing on (1) or off (0). Off, spears get no fishing action.";
    bool Enable = true;

    string FindChanceInfo = "Per-stab probability of catching anything. 0-1; 1.0 = every stab catches, 0.0 = none do. The default 0.04 with a 6 s stab gives a fish about every 2.5 minutes, a little slower than a rod.";
    float FindChance = 0.04;

    string MaxWaterDepthInfo = "Deepest water, in metres at the spot aimed at, that a spear can fish. Spear fishing is for the shallows: knee-deep water near the bank or shore.";
    float MaxWaterDepth = 1.0;

    string PredatorChanceInfo = "Chance (0-1) that a predator is drawn when a stab lands a fish, the way a rod rolls once per cast. 0.01 = about one predator per 100 fish.";
    float PredatorSpawnChance = 0.01;

    string CatchesInfo = "Weighted catch table. Environment: 1=pond, 2=sea, 3=both. Entries whose Environment doesn't match the water stabbed into are skipped before the weighted roll.";
    ref array<ref SpearEntry> Catches;

    void SpearFishingConf() {
        Catches = new array<ref SpearEntry>();
    }
}

// Settings for ActionDigBugs. Owns the per-attempt find-chance roll and
// the weighted Catches table.
class DigBugsConf {
    string FindChanceInfo = "Per-attempt probability the bug catcher action produces any catch. 0-1; 1.0 = always finds, 0.0 = never finds.";
    float FindChance = 0.65;

    string CatchesInfo = "Weighted spawn table for the bug catcher action. Seeded with a cricket, grasshopper, grub and worm; add entries or change their weights.";
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
    string CatchProbInfo = "How often this item turns up compared with the other junk, 0-25 (0 = never). How often junk comes up at all is JunkShare, at the top of the file.";
    int CatchProbability;
    string HealthLevelInfo = "Health level range for spawned junk: 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined. Use 3/3 for fixed badly damaged, 3/4 for random badly damaged or ruined.";
    int MinHealthLevel = 3;
    int MaxHealthLevel = 3;
};

class ContainerJunkEntry {
    string ClassnameInfo = "Any classname for a junk item that's a liquid container.";
    string Classname;
    string CatchProbInfo = "How often this container turns up compared with the other junk, 0-25 (0 = never). It shares JunkShare with the Junk items.";
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
    string ClassnameInfo = "Hook classname to spawn (e.g. Hook for vanilla, or any gebsfish lure/hook).";
    string Classname;
    string WeightInfo = "Relative weight in the weighted pick. Set to 0 to disable an entry without deleting it. Pure ratios -- 2.0 is twice as likely as 1.0.";
    float Weight = 1.0;
    string HealthLevelInfo = "Health level range. 0 pristine, 1 worn, 2 damaged, 3 badly damaged, 4 ruined. Defaults to 3/3 (fixed Badly Damaged).";
    int MinHealthLevel = 3;
    int MaxHealthLevel = 3;
};

// ---------------------------------------------------------------------------
// TREASURE
// A very rare "you pulled up something worth keeping" catch. One weighted pick
// chooses the CONTAINER, then that container is filled with a random number of
// items rolled independently from the loot pool -- so no two hauls match.
// Both pools are entirely admin-defined; nothing here is hardcoded in script.
// ---------------------------------------------------------------------------
// Treasure feature switches. Its own section on purpose: Backfill gives a
// section the file doesn't have its class defaults (it asks the file text,
// since the loader turns a missing section into an all-zero object rather
// than null), so one check makes a whole new feature default correctly on
// servers whose config predates it, with no version checks anywhere. A loose
// bool/float added to an existing section would load as 0 instead and need a
// key check of its own (see CraftFishMount) -- that is why every switchable
// system here is a section rather than scalars on GeneralSettings.
class TreasureConf {
    string TreasureInfo = "Ultra-rare treasure catch. On a SUCCESSFUL catch (not a failed cast) this rolls once: on a hit, one container is picked from the top-level TreasureContainers pool and filled with a random number of items rolled independently from TreasureLoot, so no two hauls are the same. Enable set to 0 turns the feature off entirely; Chance is the per-catch probability and 0 also disables it. Default 0.0002 is about 1 in 5000 CATCHES -- that is catches, not casts, so a session landing 60 fish has roughly a 1.2 percent chance of seeing one. For reference: 0.0005 is ~1 in 2000, 0.002 is ~1 in 500, 0.00005 is ~1 in 20000. Keep it low -- this is meant to be a story someone tells, not a farm. The container spawns at the player's feet (they are usually too big for a pocket). Edit the TreasureContainers / TreasureLoot pools rather than this line to change what actually appears.";
    bool Enable = 1;
    float Chance = 0.0002;
    string AnnounceInfo = "Send the lucky player a chat message when a treasure is pulled up. Purely cosmetic -- set to 0 for a silent find.";
    bool Announce = 1;
    string RequireRealRodInfo = "Restrict treasure to a proper fishing rod. The crafted ImprovisedFishingRod is a stick and a piece of rope, so it is excluded, as is any rod that does not inherit from FishingRod. The vanilla rod and the ten gebsfish colour rods all qualify. Set to 0 to let any rod find treasure.";
    bool RequireRealRod = 1;
    string RodCatchesToRuinInfo = "How many treasure pulls it takes to ruin a PRISTINE rod -- winching a loaded container up is brutal on tackle. Each pull removes this fraction of the rod maximum health, so the default 3 costs 50 of a stock rod 150 HP. A rod already worn from ordinary fishing gives out sooner, and the damage rescales on its own if the hitpoints are retuned or another mod rod is used. Set to 0 to leave the rod undamaged.";
    int RodCatchesToRuin = 3;
};

class TreasureContainerEntry {
    string ClassnameInfo = "Container classname the treasure spawns as. Anything with cargo works -- SeaChest, WoodenCrate, Fur_Backpack, a barrel, an ammo box. Items are placed into its cargo, so a container with no cargo space will arrive empty.";
    string Classname;
    string WeightInfo = "Relative weight among containers. 0 disables this entry without deleting it (deleting gets it re-added on the next version bump).";
    float Weight = 1.0;
    string HealthLevelInfo = "Health level the container spawns at: 0 pristine .. 4 ruined. A range rolls per spawn -- 1/3 gives anything from worn to badly damaged.";
    int MinHealthLevel = 1;
    int MaxHealthLevel = 3;
    string ItemCountInfo = "How many loot rolls this container gets. Each roll picks independently from TreasureLoot, so a bigger container can be made to hold more. Set both: MaxItems 0 means the container always arrives empty.";
    int MinItems = 2;
    int MaxItems = 5;
};

class TreasureLootEntry {
    string ClassnameInfo = "Item classname that can appear inside a treasure container. Any classname on the server is valid, including items from other mods.";
    string Classname;
    string WeightInfo = "Relative weight in the loot pick. 0 disables this entry without deleting it. Pure ratios -- a 0.1 entry is a tenth as likely as a 1.0 entry.";
    float Weight = 1.0;
    string HealthLevelInfo = "Health level range for this item: 0 pristine .. 4 ruined. Rolled per item.";
    int MinHealthLevel = 1;
    int MaxHealthLevel = 3;
    string QuantityInfo = "Quantity range for stackable items (ammo, nails). Rolled per item and clamped to what the item actually allows. Leave 0/0 to let the item spawn at its own default.";
    int MinQuantity = 0;
    int MaxQuantity = 0;
};
// Runtime validation deliberately leaves the administrator's JSON unchanged.
static float GebValidateNumber(float value, float minimum, float maximum, string field) {
    float fixedValue;
    if (!(value >= minimum))
        fixedValue = minimum;
    else
        fixedValue = Math.Min(value, maximum);
    if (fixedValue != value)
        GebsfishLogger.Error("Runtime correction: " + field + " -> " + fixedValue, "ConfigValidation");
    return fixedValue;
}

static void GebValidateFishConfig(FishConfig config) {
    if (!config || !config.Species)
        return;
    map<int, string> seen = new map<int, string>();
    int removed = 0;
    for (int i = 0; i < config.Species.Count(); i++) {
        FishConf f = config.Species[i];
        // Every removal shifts the later rows down, so i + removed is the row's
        // place in the file (counting from 0), the one an admin can look up.
        int row = i + removed;
        string problem = "";
        if (!f)
            problem = "the row is empty";
        else if (f.Classname == "")
            problem = "it has no Classname";
        else if (!g_Game.ConfigIsExisting("CfgVehicles " + f.Classname))
            problem = f.Classname + " is not an item in this game (a typo, or its mod isn't loaded)";
        if (problem != "") {
            GebsfishLogger.Error("Skipping fish.json Species row " + row + ": " + problem, "ConfigValidation");
            config.Species.RemoveOrdered(i);
            i--;
            removed++;
            continue;
        }
        // Case-insensitive, like the CE and config lookups: "geb_bluegill" and
        // "geb_BlueGill" are the same item and must not register twice.
        string lowerName = f.Classname;
        lowerName.ToLower();
        int key = lowerName.Hash();
        if (seen.Contains(key)) {
            GebsfishLogger.Error("Skipping fish.json Species row " + row + ": " + f.Classname + " conflicts with an earlier row (" + seen.Get(key) + ")", "ConfigValidation");
            config.Species.RemoveOrdered(i);
            i--;
            removed++;
            continue;
        }
        seen.Insert(key, f.Classname);
        string field = "fish.json/" + f.Classname + "/";
        f.CatchProbability = GebValidateNumber(f.CatchProbability, 0, 25, field + "CatchProbability");
        if (f.Environment < 0 || f.Environment > 3) {
            GebsfishLogger.Error(field + "Environment invalid; disabling habitat eligibility.", "ConfigValidation");
            f.Environment = 0;
        }
        if (f.CatchMethod < 0 || f.CatchMethod > 7) {
            GebsfishLogger.Error(field + "CatchMethod invalid; disabling method eligibility.", "ConfigValidation");
            f.CatchMethod = 0;
        }
        f.RecipeShape = GebValidateNumber(f.RecipeShape, 0, 2, field + "RecipeShape");
        f.MeatMin = GebValidateNumber(f.MeatMin, 0, 10, field + "MeatMin");
        f.MeatMax = GebValidateNumber(f.MeatMax, f.MeatMin, 10, field + "MeatMax");
        f.RainMultiplier = GebValidateNumber(f.RainMultiplier, 0, 1000, field + "RainMultiplier");
        f.StormMultiplier = GebValidateNumber(f.StormMultiplier, 0, 1000, field + "StormMultiplier");
        f.DawnMultiplier = GebValidateNumber(f.DawnMultiplier, 0, 1000, field + "DawnMultiplier");
        f.DayMultiplier = GebValidateNumber(f.DayMultiplier, 0, 1000, field + "DayMultiplier");
        f.DuskMultiplier = GebValidateNumber(f.DuskMultiplier, 0, 1000, field + "DuskMultiplier");
        f.NightMultiplier = GebValidateNumber(f.NightMultiplier, 0, 1000, field + "NightMultiplier");
        f.TempMin = GebValidateNumber(f.TempMin, -100, 100, field + "TempMin");
        f.TempMax = GebValidateNumber(f.TempMax, f.TempMin, 100, field + "TempMax");
        f.TempOptimal = GebValidateNumber(f.TempOptimal, f.TempMin, f.TempMax, field + "TempOptimal");
        TFloatArray speeds = f.GetBiteSpeedArray();
        if (speeds.Count() != 24) {
            GebsfishLogger.Error(field + "BiteSpeed must contain 24 values; using 1 for every hour.", "ConfigValidation");
            speeds.Clear();
            for (int h = 0; h < 24; h++)
                speeds.Insert(1);
        }
        f.BiteSpeed = "";
        for (int hour = 0; hour < 24; hour++) {
            float speed = GebValidateNumber(speeds[hour], 0, 1, field + "BiteSpeed/" + hour);
            if (hour > 0)
                f.BiteSpeed += " ";
            f.BiteSpeed += speed.ToString();
        }
        if (f.ResultMain != "" && !g_Game.ConfigIsExisting("CfgVehicles " + f.ResultMain)) {
            GebsfishLogger.Error(field + "ResultMain does not exist; disabling its recipe.", "ConfigValidation");
            f.ResultMain = "";
        }
        // Empty needs its own test: ConfigIsExisting("CfgVehicles ") stops at
        // the trailing space and finds CfgVehicles itself, so "" passed.
        if (f.RecipeShape != 0 && (f.ResultBonus == "" || !g_Game.ConfigIsExisting("CfgVehicles " + f.ResultBonus))) {
            GebsfishLogger.Error(field + "ResultBonus is empty or does not exist; disabling its recipe.", "ConfigValidation");
            f.ResultMain = "";
        }
    }
    GebsfishLogger.Info("Validated " + config.Species.Count() + " species; skipped " + removed + " invalid/duplicate rows. JSON preserved.", "ConfigValidation");
}

// Rows added to the JSON files by hand can carry values the server can't use:
// a key left out of a row loads as 0 / empty, not as the class default (the
// loader builds rows without their class defaults; see GebJsonKeys). Each
// such row is named at startup with what it will do; nothing is changed, so
// the admin's file stays as written.
static int GebWarnRow(string where, int row, string classname, string problem) {
    string name = classname;
    if (name == "")
        name = "no Classname";
    GebsfishLogger.Error(where + " row " + row + " (" + name + "): " + problem, "ConfigValidation");
    return 1;
}

static int GebCheckCatchRow(string where, int row, string classname, int environment) {
    if (classname == "")
        return GebWarnRow(where, row, classname, "it has no Classname, so it never catches anything");
    if (environment < 1 || environment > 3)
        return GebWarnRow(where, row, classname, "Environment is " + environment + "; it must be 1 (pond), 2 (sea) or 3 (both), so this row never catches anything");
    return 0;
}

static int GebCheckLevels(string where, int row, string classname, int minLevel, int maxLevel) {
    if (minLevel < 0 || maxLevel > 4 || minLevel > maxLevel)
        return GebWarnRow(where, row, classname, "MinHealthLevel " + minLevel + " / MaxHealthLevel " + maxLevel + " must run from low to high within 0 (pristine) to 4 (ruined)");
    return 0;
}

static void GebValidateRows(gebsfishConfig cfg) {
    if (!cfg)
        return;
    int warnings = 0;
    GeneralConfig g = cfg.General;
    if (g && g.BambooFishingNetSettings && g.BambooFishingNetSettings.Catches) {
        foreach (int ni, NetEntry net : g.BambooFishingNetSettings.Catches) {
            if (net)
                warnings += GebCheckCatchRow("general.json BambooFishingNetSettings.Catches", ni, net.Classname, net.Environment);
        }
    }
    if (g && g.SpearFishingSettings && g.SpearFishingSettings.Catches) {
        foreach (int si, SpearEntry spear : g.SpearFishingSettings.Catches) {
            if (spear)
                warnings += GebCheckCatchRow("general.json SpearFishingSettings.Catches", si, spear.Classname, spear.Environment);
        }
    }
    if (g && g.TreasureContainers) {
        foreach (int ci, TreasureContainerEntry box : g.TreasureContainers) {
            if (!box)
                continue;
            if (box.MaxItems < 1)
                warnings += GebWarnRow("general.json TreasureContainers", ci, box.Classname, "MaxItems is " + box.MaxItems + ", so it always arrives empty");
            else if (box.MinItems > box.MaxItems)
                warnings += GebWarnRow("general.json TreasureContainers", ci, box.Classname, "MinItems " + box.MinItems + " is above MaxItems " + box.MaxItems);
            warnings += GebCheckLevels("general.json TreasureContainers", ci, box.Classname, box.MinHealthLevel, box.MaxHealthLevel);
        }
    }
    if (g && g.TreasureLoot) {
        foreach (int li, TreasureLootEntry loot : g.TreasureLoot) {
            if (!loot)
                continue;
            warnings += GebCheckLevels("general.json TreasureLoot", li, loot.Classname, loot.MinHealthLevel, loot.MaxHealthLevel);
            if (loot.MinQuantity > loot.MaxQuantity)
                warnings += GebWarnRow("general.json TreasureLoot", li, loot.Classname, "MinQuantity " + loot.MinQuantity + " is above MaxQuantity " + loot.MaxQuantity);
        }
    }
    if (g && g.Predators) {
        foreach (int pi, PredatorEntry predator : g.Predators) {
            if (!predator)
                continue;
            if (predator.MaxCount < 1)
                warnings += GebWarnRow("general.json Predators", pi, predator.Classname, "MaxCount is " + predator.MaxCount + ", so it never spawns");
            else if (predator.MinCount > predator.MaxCount)
                warnings += GebWarnRow("general.json Predators", pi, predator.Classname, "MinCount " + predator.MinCount + " is above MaxCount " + predator.MaxCount);
            if (predator.MinRadius > predator.MaxRadius)
                warnings += GebWarnRow("general.json Predators", pi, predator.Classname, "MinRadius " + predator.MinRadius + " is above MaxRadius " + predator.MaxRadius);
        }
    }
    if (cfg.Junk && cfg.Junk.Junk) {
        foreach (int ji, JunkEntry junk : cfg.Junk.Junk) {
            if (junk)
                warnings += GebCheckLevels("junk.json Junk", ji, junk.Classname, junk.MinHealthLevel, junk.MaxHealthLevel);
        }
    }
    if (cfg.Junk && cfg.Junk.ContainerJunk) {
        foreach (int ki, ContainerJunkEntry cjunk : cfg.Junk.ContainerJunk) {
            if (cjunk)
                warnings += GebCheckLevels("junk.json ContainerJunk", ki, cjunk.Classname, cjunk.MinHealthLevel, cjunk.MaxHealthLevel);
        }
    }
    if (cfg.Bait && cfg.Bait.Preferences) {
        foreach (int bi, BaitConfig bait : cfg.Bait.Preferences) {
            if (!bait)
                continue;
            if (bait.BaitClassname == "")
                warnings += GebWarnRow("bait.json Preferences", bi, "", "it has no BaitClassname, so its preferences never apply");
            if (!bait.Preferences)
                continue;
            string baitWhere = "bait.json " + bait.BaitClassname + " Preferences";
            foreach (int fi, BaitPreferenceEntry pref : bait.Preferences) {
                if (!pref)
                    continue;
                if (pref.FishClassname == "")
                    warnings += GebWarnRow(baitWhere, fi, "", "it has no FishClassname, so it never applies");
                else if (pref.Multiplier < 0)
                    warnings += GebWarnRow(baitWhere, fi, pref.FishClassname, "Multiplier is " + pref.Multiplier + "; below 0 counts as 0, which takes this fish out of the bait's pool");
            }
        }
    }
    if (warnings > 0)
        GebsfishLogger.Info("Config rows: " + warnings + " warning(s) above. Nothing was changed; fix the rows in the JSON files.", "ConfigValidation");
}
