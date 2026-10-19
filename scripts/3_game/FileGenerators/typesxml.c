class gebsfishTypes {
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-types.xml";

    void GenerateTypesXML() {
        // Only generate on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Written only when the mod's version changes (or the file is missing),
        // like the spawnable types. The canned fish rows are copied from the
        // mission's db/types.xml at that moment: after editing those rows or
        // changing maps, delete this file to have it written again.
        if (GebXmlFiles.IsCurrentVersion(FILE_PATH, version)) {
            GebsfishLogger.Info("Types XML already at version " + version + ". Skipping regeneration.", "Types");
            return;
        }

        GebXmlFiles.EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file) {
            GebsfishLogger.Error("Could not create gebsfish-types.xml in $profile:Gebs/mpmissions/.", "Types");
            return;
        }

        WriteHeader(file, version);
        WriteFishSection(file);
        WriteGearSection(file);
        WriteVanillaReskinSection(file);
        WriteVehicleSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Notice("gebsfish-types.xml successfully generated in $profile:Gebs/mpmissions/.", "Types");
    }

    protected void WriteHeader(FileHandle file, string version) {
        FPrintln(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        GebXmlFiles.WriteVersionLine(file, version);
        FPrintln(file, "<types>");
    }

    protected void WriteFooter(FileHandle file) {
        FPrintln(file, "</types>");
    }

    protected void WriteFishSection(FileHandle file) {
        FPrintln(file, "    <!-- Fish Items -->");

        gebsfishConfig cfg = GetGebSettingsConfig();
        if (cfg && cfg.Fish && cfg.Fish.Species) {
            // Result classnames are shared across species (five pike and muskies
            // give geb_YellowCaviar), but types.xml needs each declared once.
            map<string, bool> written = new map<string, bool>();
            foreach (GebFishConf f : cfg.Fish.Species) {
                if (!f || f.Classname == "") continue;
                WriteTypeOnce(file, written, f.Classname);
                if (f.ResultMain != "")  WriteTypeOnce(file, written, f.ResultMain);
                if (f.ResultBonus != "") WriteTypeOnce(file, written, f.ResultBonus);
            }
        }
    }

    protected void WriteTypeOnce(FileHandle file, map<string, bool> written, string name) {
        // Only emit classnames this mod owns (geb_ prefix). Vanilla species
        // in the table (Carp, Mackerel, RedCaviar, the fillet meats, ...)
        // are already defined by the mission's own types.xml -- re-declaring
        // them creates colliding definitions when admins merge this file.
        if (name.IndexOf("geb_") != 0)
            return;
        if (written.Contains(name))
            return;
        written.Insert(name, true);
        // -1 quantities like vanilla's fish: these only spawn as cargo (bait
        // buckets), and any other range would make the CE re-roll how full
        // each one comes.
        WriteType(file, name, 0, 14400, 0, 0, -1, -1, 100, "food", false, true);
    }

    protected void WriteGearSection(FileHandle file) {
        ref array<ref GebXmlTypeEntry> gearItems = new array<ref GebXmlTypeEntry>;
        gearItems.Reserve(100);

        // Fishing rods: the eighteen rods (ten colours, four camos, and the fly, spincast, baitcast and heavy surf rods)
        // all spawn alike, one each (Cole, 2026-10-13: "should all be equal"). That is 18 in the world, two fewer than the
        // four rods' old 20 (4 x 5), since 20 doesn't split evenly 18 ways and a new rod mustn't make rods commoner.
        TStringArray rods = {"geb_RedFishingRod", "geb_BlueFishingRod", "geb_GreenFishingRod", "geb_PurpleFishingRod", "geb_OrangeFishingRod", "geb_YellowFishingRod", "geb_BrownFishingRod", "geb_LightBlueFishingRod", "geb_LimeFishingRod", "geb_PinkFishingRod", "geb_CamoFishingRod", "geb_DesertCamoFishingRod", "geb_SnowCamoFishingRod", "geb_PinkCamoFishingRod", "geb_FlyFishingRod", "geb_SpincastFishingRod", "geb_BaitcastFishingRod", "geb_HeavySurfRod"};
        InsertGearBatch(gearItems, rods, 1, 1);

        // Fishing clothes: 84 pieces (hats, shirts, raincoats, vests, wellies and gloves, ten colours and four
        // camos each), one of each in the world, the fewest the economy allows. The four hats, four shirts and two gloves were 30
        // at 3 apiece; one each of every new colour and piece keeps each piece rarer than it was. Typed as
        // clothes, like vanilla's raincoats, caps, T-shirts and gloves, so they spawn where clothing does
        // instead of on tool spots.
        TStringArray clothes = {
            "geb_BlueFishHat", "geb_RedFishHat", "geb_GreenFishHat", "geb_PurpleFishHat", "geb_OrangeFishHat", "geb_YellowFishHat", "geb_BrownFishHat", "geb_LightBlueFishHat", "geb_LimeFishHat", "geb_PinkFishHat", "geb_CamoFishHat", "geb_DesertCamoFishHat", "geb_SnowCamoFishHat", "geb_PinkCamoFishHat",
            "geb_RedFishShirt", "geb_GreenFishShirt", "geb_BlueFishShirt", "geb_PurpleFishShirt", "geb_OrangeFishShirt", "geb_YellowFishShirt", "geb_BrownFishShirt", "geb_LightBlueFishShirt", "geb_LimeFishShirt", "geb_PinkFishShirt", "geb_CamoFishShirt", "geb_DesertCamoFishShirt", "geb_SnowCamoFishShirt", "geb_PinkCamoFishShirt",
            "geb_RedFishRaincoat", "geb_GreenFishRaincoat", "geb_BlueFishRaincoat", "geb_PurpleFishRaincoat", "geb_OrangeFishRaincoat", "geb_YellowFishRaincoat", "geb_BrownFishRaincoat", "geb_LightBlueFishRaincoat", "geb_LimeFishRaincoat", "geb_PinkFishRaincoat", "geb_CamoFishRaincoat", "geb_DesertCamoFishRaincoat", "geb_SnowCamoFishRaincoat", "geb_PinkCamoFishRaincoat",
            "geb_RedFishVest", "geb_GreenFishVest", "geb_BlueFishVest", "geb_PurpleFishVest", "geb_OrangeFishVest", "geb_YellowFishVest", "geb_BrownFishVest", "geb_LightBlueFishVest", "geb_LimeFishVest", "geb_PinkFishVest", "geb_CamoFishVest", "geb_DesertCamoFishVest", "geb_SnowCamoFishVest", "geb_PinkCamoFishVest",
            "geb_RedFishWellies", "geb_GreenFishWellies", "geb_BlueFishWellies", "geb_PurpleFishWellies", "geb_OrangeFishWellies", "geb_YellowFishWellies", "geb_BrownFishWellies", "geb_LightBlueFishWellies", "geb_LimeFishWellies", "geb_PinkFishWellies", "geb_CamoFishWellies", "geb_DesertCamoFishWellies", "geb_SnowCamoFishWellies", "geb_PinkCamoFishWellies",
            "geb_BlueFishGloves", "geb_OrangeFishGloves", "geb_YellowFishGloves", "geb_RedFishGloves", "geb_GreenFishGloves", "geb_PurpleFishGloves", "geb_BrownFishGloves", "geb_LightBlueFishGloves", "geb_LimeFishGloves", "geb_PinkFishGloves", "geb_CamoFishGloves", "geb_DesertCamoFishGloves", "geb_SnowCamoFishGloves", "geb_PinkCamoFishGloves"
        };
        InsertGearBatch(gearItems, clothes, 1, 1, "clothes");

        // Fish knives, large tackle boxes and coolers: fourteen of each (ten colours, four camos) share the spawns
        // the eleven had at 3 apiece (33): five at 3 and nine at 2 is still 33, so a new colour makes each rarer.
        TStringArray knives = {"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_RedFishKnife"};
        InsertGearBatch(gearItems, knives, 3, 1);
        TStringArray rarerKnives = {"geb_PurpleFishKnife", "geb_LimeFishKnife", "geb_LightBlueFishKnife", "geb_CamoFishKnife", "geb_BrownFishKnife", "geb_PinkFishKnife", "geb_DesertCamoFishKnife", "geb_SnowCamoFishKnife", "geb_PinkCamoFishKnife"};
        InsertGearBatch(gearItems, rarerKnives, 2, 1);
        TStringArray tackle = {"geb_RedTackle", "geb_YellowTackle", "geb_BlueTackle", "geb_OrangeTackle", "geb_GreenTackle"};
        InsertGearBatch(gearItems, tackle, 3, 1);
        TStringArray rarerTackle = {"geb_PurpleTackle", "geb_PinkTackle", "geb_LimeTackle", "geb_LightBlueTackle", "geb_BrownTackle", "geb_CamoTackle", "geb_DesertCamoTackle", "geb_SnowCamoTackle", "geb_PinkCamoTackle"};
        InsertGearBatch(gearItems, rarerTackle, 2, 1);
        TStringArray coolers = {"geb_RedCooler", "geb_YellowCooler", "geb_BlueCooler", "geb_OrangeCooler", "geb_GreenCooler"};
        InsertGearBatch(gearItems, coolers, 3, 1);
        TStringArray rarerCoolers = {"geb_BrownCooler", "geb_PurpleCooler", "geb_PinkCooler", "geb_LimeCooler", "geb_LightBlueCooler", "geb_CamoCooler", "geb_DesertCamoCooler", "geb_SnowCamoCooler", "geb_PinkCamoCooler"};
        InsertGearBatch(gearItems, rarerCoolers, 2, 1);

        // Old Tackle Boxes: fourteen colours (ten colours, four camos) at 1 each. The four had 4 x 3 = 12; nominal 1
        // is the floor, so fourteen can't share twelve: two more than before, each box rarer than it was.
        TStringArray oldTackle = {"geb_OldRedTackle", "geb_OldPurpleTackle", "geb_OldGreenTackle", "geb_OldBlueTackle", "geb_OldOrangeTackle", "geb_OldYellowTackle", "geb_OldBrownTackle", "geb_OldPinkTackle", "geb_OldLimeTackle", "geb_OldLightBlueTackle", "geb_OldCamoTackle", "geb_OldDesertCamoTackle", "geb_OldSnowCamoTackle", "geb_OldPinkCamoTackle"};
        InsertGearBatch(gearItems, oldTackle, 1, 1);

        // Everything else (the small tackle box, containers, baits/lures, the repair kit) shares the same 3/1
        // loot profile.
        TStringArray gear = {
            "geb_SmallTackle",
            "geb_MinnowBucket", "geb_BambooFishingNet", "geb_BugContainer", "geb_WormContainer",
            "geb_RubberWorm",
            "geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
            "geb_Lure1", "geb_Lure2", "geb_Lure3", "geb_Lure4",
            "geb_SpoonLure1", "geb_SpoonLure2", "geb_SpoonLure3", "geb_SpoonLure4",
            "geb_CurlyTailJig1", "geb_CurlyTailJig2", "geb_CurlyTailJig3", "geb_CurlyTailJig4",
            "geb_FeatherJig",
            "geb_FishingRodRepairKit"
        };
        InsertGearBatch(gearItems, gear, 3, 1);

        // Quantities stay -1 (the item's config default), as vanilla does
        // for gear: any other range makes the CE re-roll quantity on every
        // spawn, so repair kits would come with random uses left. Lifetime
        // is 4 hours untouched, vanilla's for fishing rods, knives and most
        // tools; at 2 hours a stocked cooler or tackle box left outside a
        // base vanished with everything in it.
        FPrintln(file, "    <!-- Gear Items -->");
        foreach (GebXmlTypeEntry gearEntry : gearItems) {
            WriteType(file, gearEntry.Name, gearEntry.Nominal, 14400, 0, gearEntry.Min, -1, -1, 200, gearEntry.Category, true, false);
        }

        // Live insect bait comes from digging (and inside bug containers via
        // spawnabletypes), never loose: it starts dying the moment it exists,
        // so a world spawn would mostly be found dead. Same profile as
        // vanilla Worm -- crafted, nominal 0. Cargo spawns ignore the flag.
        TStringArray liveBait = {"geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm"};
        FPrintln(file, "    <!-- Live bait (dug, not looted) -->");
        foreach (string bait : liveBait) {
            WriteType(file, bait, 0, 7200, 0, 0, -1, -1, 200, "tools", false, true);
        }

        // The fish mounts, the Fish Drying Rack, the Fishing Locker and the Fish Tank Stand are placed structures, not pocket loot: crafted with
        // nominal 0 like vanilla's WoodenCrate, and the tent/barrel lifetime
        // (45 days untouched) instead of the 4-hour gear lifetime, so wall
        // trophies persist like any base fixture and abandoned ones decay
        // away on the same schedule as tents. The drying rack's kit too: it
        // lies on the ground while its long sticks go in.
        FPrintln(file, "    <!-- Placed structures -->");
        TStringArray mounts = {"geb_WoodenFishMount", "geb_MediumFishMount", "geb_LargeFishMount", "geb_FishDryingRack", "geb_FishDryingRackKit", "geb_FishingLocker", "geb_FishTankStand"};
        foreach (string mount : mounts) {
            WriteType(file, mount, 0, 3888000, 0, 0, -1, -1, 200, "tools", false, true);
        }
        // The Fish Tank is placed the same way but comes from traders and admins
        // (or, rarely, a treasure catch), never a recipe: nominal 0 / min 0 so the
        // CE knows the class and never spawns it (as with the jon boats),
        // crafted=0, and the structures' lifetime. Its stand is crafted (above).
        TStringArray traderOnly = {"geb_FishTank"};
        foreach (string traderItem : traderOnly) {
            WriteType(file, traderItem, 0, 3888000, 0, 0, -1, -1, 200, "tools", false, false);
        }
    }

    protected void InsertGearBatch(array<ref GebXmlTypeEntry> gearItems, TStringArray names, int nominal, int min, string category = "tools") {
        foreach (string name : names) {
            gearItems.Insert(new GebXmlTypeEntry(name, nominal, min, category));
        }
    }

    // Reskins of vanilla loot (data/food): the canned fish, built on vanilla's
    // two fish cans, the Fish Oil Pills, built on vanilla's vitamins, and the
    // fish foods on vanilla's pate tins, 250 g cans, honey jar, snack bags,
    // stick pack, cereal box and powdered milk. They
    // share vanilla's spawns instead of adding to them: each vanilla item and
    // the items built on it split the mission's own nominal and min, and this
    // file lowers vanilla's row to its share with a row that gives only the
    // nominal and min. The economy reads a later row of a type it already
    // knows as an update of just the fields that row gives, so the rest of
    // vanilla's row stays; pasted after vanilla's rows in db/types.xml it works
    // the same. Each new item copies its vanilla item's row from the mission
    // (places, tiers, lifetime, flags), and each opened can the vanilla opened
    // can's. Nominal 1 is the floor while the vanilla item spawns at all, so a
    // map with fewer of it than there are kinds gets a few more.
    static ref TStringArray s_FlatTins = {"geb_SpratsCan", "geb_AnchoviesCan", "geb_KipperSnacksCan", "geb_MackerelTomatoCan", "geb_SmokedTroutCan", "geb_SmokedMusselsCan", "geb_SmokedOystersCan", "geb_SquidInkCan"};
    static ref TStringArray s_RoundCans = {"geb_SalmonCan", "geb_CodLiverCan", "geb_SauryCan", "geb_CrabMeatCan", "geb_BonitoCan", "geb_CaviarCan", "geb_MincedClamsCan"};
    static ref TStringArray s_VitaminReskins = {"geb_FishOilPills"};
    static ref TStringArray s_PajkaReskins = {"geb_CodRoeSpread"};
    static ref TStringArray s_PateReskins = {"geb_SalmonPate"};
    static ref TStringArray s_BrisketReskins = {"geb_SmokedFishSpread"};
    static ref TStringArray s_PorkCanReskins = {"geb_FishSoupCan", "geb_ClamChowderCan"};
    static ref TStringArray s_LunchmeatReskins = {"geb_FishBallsCan", "geb_HerringMustardCan"};
    static ref TStringArray s_HoneyReskins = {"geb_PickledHerring", "geb_RedCaviarJar", "geb_PickledMussels"};
    static ref TStringArray s_CrackersReskins = {"geb_PrawnCrackers"};
    static ref TStringArray s_ChipsReskins = {"geb_DriedSquidSnack"};
    static ref TStringArray s_SaltySticksReskins = {"geb_FishJerky"};
    static ref TStringArray s_CerealReskins = {"geb_BonitoFlakes"};
    private const string MISSION_TYPES_PATH = "$mission:db/types.xml";

    protected void WriteVanillaReskinSection(FileHandle file) {
        TStringArray wanted = {"TunaCan", "TunaCan_Opened", "SardinesCan", "SardinesCan_Opened", "VitaminBottle", "Pajka", "Pajka_Opened", "Pate", "Pate_Opened", "BrisketSpread", "BrisketSpread_Opened", "PorkCan", "PorkCan_Opened", "Lunchmeat", "Lunchmeat_Opened", "Honey", "Crackers", "Chips", "SaltySticks", "BoxCerealCrunchin"};
        map<string, ref TStringArray> rows = ReadMissionTypes(wanted);
        FPrintln(file, "    <!-- Canned fish: the flat tins share vanilla TunaCan's spawns, the round cans SardinesCan's. The short");
        FPrintln(file, "         TunaCan and SardinesCan rows lower vanilla's nominal and min to vanilla's share; the economy reads");
        FPrintln(file, "         them as an update of just those two fields, so if you paste this file into db/types.xml, keep them");
        FPrintln(file, "         after vanilla's own rows. A merge tool that replaces whole rows would lose the rest of vanilla's row:");
        FPrintln(file, "         set vanilla's nominal and min to these numbers by hand instead (later copies of this file would then");
        FPrintln(file, "         split the lowered numbers). Each new can copies its vanilla can's row from this mission's db/types.xml,");
        FPrintln(file, "         as it was when this file was written (it's written again when the mod's version changes, or if you delete it). -->");
        WriteSharedFamily(file, "TunaCan", s_FlatTins, rows, true);
        WriteSharedFamily(file, "SardinesCan", s_RoundCans, rows, true);
        FPrintln(file, "    <!-- Fish Oil Pills share vanilla VitaminBottle's spawns the same way. -->");
        WriteSharedFamily(file, "VitaminBottle", s_VitaminReskins, rows, false);
        FPrintln(file, "    <!-- The fish foods on vanilla's pate tins, 250 g cans, honey jar, snacks and cereal box share those items' spawns the same way. -->");
        WriteSharedFamily(file, "Pajka", s_PajkaReskins, rows, true);
        WriteSharedFamily(file, "Pate", s_PateReskins, rows, true);
        WriteSharedFamily(file, "BrisketSpread", s_BrisketReskins, rows, true);
        WriteSharedFamily(file, "PorkCan", s_PorkCanReskins, rows, true);
        WriteSharedFamily(file, "Lunchmeat", s_LunchmeatReskins, rows, true);
        WriteSharedFamily(file, "Honey", s_HoneyReskins, rows, false);
        WriteSharedFamily(file, "Crackers", s_CrackersReskins, rows, false);
        WriteSharedFamily(file, "Chips", s_ChipsReskins, rows, false);
        WriteSharedFamily(file, "SaltySticks", s_SaltySticksReskins, rows, false);
        WriteSharedFamily(file, "BoxCerealCrunchin", s_CerealReskins, rows, false);
    }

    // withOpened: each item also has an _Opened class (the cans), typed from
    // the vanilla opened item's row.
    protected void WriteSharedFamily(FileHandle file, string parent, TStringArray items, map<string, ref TStringArray> rows, bool withOpened) {
        TStringArray row = rows.Get(parent);
        TStringArray opened = rows.Get(parent + "_Opened");
        int nominal = -1;
        int min = -1;
        int value;
        if (row) {
            foreach (string line : row) {
                if (GebXmlFiles.ReadElement(line, "nominal", value))
                    nominal = value;
                else if (GebXmlFiles.ReadElement(line, "min", value))
                    min = value;
            }
        }

        if (nominal < 0 || min < 0) {
            // Nothing to share: typed so the economy knows them, never spawned as loot.
            FPrintln(file, "    <!-- This mission's db/types.xml has no " + parent + " row this file could read, so the items built on it don't spawn as loot. -->");
            foreach (string lone : items) {
                WriteType(file, lone, 0, 14400, 0, 0, -1, -1, 100, "food", false, false);
                if (withOpened)
                    WriteType(file, lone + "_Opened", 0, 9000, 0, 0, -1, -1, 100, "food", false, true);
            }
            GebsfishLogger.Warn("gebsfish-types.xml: the mission's db/types.xml has no readable " + parent + " row, so the items built on it get no loot spawns.", "Types");
            return;
        }

        int slots = items.Count() + 1;
        int least = 0;
        if (nominal > 0)
            least = 1;
        int total = Share(nominal, slots, 0, least);
        FPrintln(file, "    <type name=\"" + parent + "\">");
        FPrintln(file, "        <nominal>" + total.ToString() + "</nominal>");
        FPrintln(file, "        <min>" + Share(min, slots, 0, 0).ToString() + "</min>");
        FPrintln(file, "    </type>");
        for (int i = 0; i < items.Count(); i++) {
            int share = Share(nominal, slots, i + 1, least);
            total += share;
            WriteRowCopy(file, row, items[i], share, Share(min, slots, i + 1, 0));
            if (!withOpened)
                continue;
            if (opened)
                WriteRowCopy(file, opened, items[i] + "_Opened", -1, -1);
            else
                WriteType(file, items[i] + "_Opened", 0, 9000, 0, 0, -1, -1, 100, "food", false, true);
        }
        GebsfishLogger.Info("gebsfish-types.xml: " + parent + " and " + items.Count().ToString() + " items built on it share its nominal " + nominal.ToString() + " (" + total.ToString() + " in all).", "Types");
    }

    // The index-th of count shares of total, the larger shares first, never below least.
    protected int Share(int total, int count, int index, int least) {
        int share = total / count;
        if (index < total % count)
            share++;
        if (share < least)
            share = least;
        return share;
    }

    // A mission row written under another name, its nominal and min replaced unless -1.
    protected void WriteRowCopy(FileHandle file, TStringArray row, string name, int nominal, int min) {
        foreach (string line : row) {
            string t = line.Trim();
            if (t.IndexOf("<type") == 0)
                FPrintln(file, "    <type name=\"" + name + "\">");
            else if (t.IndexOf("</type>") == 0)
                FPrintln(file, "    </type>");
            else if (nominal >= 0 && t.IndexOf("<nominal>") == 0)
                FPrintln(file, "        <nominal>" + nominal.ToString() + "</nominal>");
            else if (min >= 0 && t.IndexOf("<min>") == 0)
                FPrintln(file, "        <min>" + min.ToString() + "</min>");
            else if (t != "")
                FPrintln(file, "        " + t);
        }
    }

    // The first row of each wanted type in the mission's db/types.xml, one
    // element per line as vanilla writes it (a row on a single line isn't
    // read). A later row of the same type (this file pasted in) is skipped,
    // so the shares always come from the mission's own row.
    protected map<string, ref TStringArray> ReadMissionTypes(TStringArray wanted) {
        map<string, ref TStringArray> rows = new map<string, ref TStringArray>();
        FileHandle fr = OpenFile(MISSION_TYPES_PATH, FileMode.READ);
        if (!fr)
            return rows;

        string line;
        TStringArray current = null;
        while (FGets(fr, line) != -1) {
            if (current) {
                current.Insert(line);
                if (line.IndexOf("</type>") != -1)
                    current = null;
                continue;
            }
            if (line.IndexOf("<type") == -1 || line.IndexOf("</type>") != -1)
                continue;
            foreach (string name : wanted) {
                if (!rows.Contains(name) && line.IndexOf("\"" + name + "\"") != -1) {
                    current = new TStringArray();
                    current.Insert(line);
                    rows.Insert(name, current);
                    break;
                }
            }
        }
        CloseFile(fr);
        return rows;
    }

    // The jon boats, typed the way vanilla types its Boat_01 boats: nominal 0
    // (they come from the VehicleBoat event, an admin or a trader, not loot),
    // lifetime 3, cost 100, counted on the map only, no category or usage.
    // Without a type the CE doesn't know them at all.
    protected void WriteVehicleSection(FileHandle file) {
        TStringArray boats = GebXmlFiles.s_JonBoats;
        FPrintln(file, "    <!-- Vehicles -->");
        foreach (string boat : boats) {
            FPrintln(file, "    <type name=\"" + boat + "\">");
            FPrintln(file, "        <nominal>0</nominal>");
            FPrintln(file, "        <lifetime>3</lifetime>");
            FPrintln(file, "        <restock>0</restock>");
            FPrintln(file, "        <min>0</min>");
            FPrintln(file, "        <quantmin>-1</quantmin>");
            FPrintln(file, "        <quantmax>-1</quantmax>");
            FPrintln(file, "        <cost>100</cost>");
            FPrintln(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"0\" deloot=\"0\"/>");
            FPrintln(file, "    </type>");
        }

        // The boat trailer (a vehicle since 2026-10-13, an item before) keeps
        // a placed item's lifetime (45 days untouched, as a tent) rather than
        // the boats' 3 seconds. Nominal 0: not loot (admins and traders place
        // it; it comes with its wheels).
        FPrintln(file, "    <type name=\"geb_BoatTrailer\">");
        FPrintln(file, "        <nominal>0</nominal>");
        FPrintln(file, "        <lifetime>3888000</lifetime>");
        FPrintln(file, "        <restock>0</restock>");
        FPrintln(file, "        <min>0</min>");
        FPrintln(file, "        <quantmin>-1</quantmin>");
        FPrintln(file, "        <quantmax>-1</quantmax>");
        FPrintln(file, "        <cost>100</cost>");
        FPrintln(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"0\" deloot=\"0\"/>");
        FPrintln(file, "    </type>");
    }

    // crafted=1 means "only made by players": the CE loot spawner skips the
    // type whatever its nominal (vanilla sets it only on nominal-0 types).
    // Anything meant to spawn as world loot must be written crafted=0.
    protected void WriteType(FileHandle file, string typeName, int nominal, int lifetime, int restock, int min, int quantMin, int quantMax, int cost, string category, bool addUsageTags, bool crafted) {
        string craftedFlag = "0";
        if (crafted)
            craftedFlag = "1";

        FPrintln(file, "    <type name=\"" + typeName + "\">");
        FPrintln(file, "        <nominal>" + nominal.ToString() + "</nominal>");
        FPrintln(file, "        <lifetime>" + lifetime.ToString() + "</lifetime>");
        FPrintln(file, "        <restock>" + restock.ToString() + "</restock>");
        FPrintln(file, "        <min>" + min.ToString() + "</min>");
        FPrintln(file, "        <quantmin>" + quantMin.ToString() + "</quantmin>");
        FPrintln(file, "        <quantmax>" + quantMax.ToString() + "</quantmax>");
        FPrintln(file, "        <cost>" + cost.ToString() + "</cost>");
        FPrintln(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"" + craftedFlag + "\" deloot=\"0\"/>");
        FPrintln(file, "        <category name=\"" + category + "\"/>");

        if (addUsageTags) {
            FPrintln(file, "        <usage name=\"Coast\"/>");
            FPrintln(file, "        <usage name=\"Farm\"/>");
            FPrintln(file, "        <usage name=\"Hunting\"/>");
            FPrintln(file, "        <usage name=\"Village\"/>");
        }

        FPrintln(file, "    </type>");
    }
}

class GebXmlTypeEntry {
    string Name;
    int Nominal;
    int Min;
    string Category;

    void GebXmlTypeEntry(string name, int nominal, int min, string category = "tools") {
        Name = name;
        Nominal = nominal;
        Min = min;
        Category = category;
    }
}
