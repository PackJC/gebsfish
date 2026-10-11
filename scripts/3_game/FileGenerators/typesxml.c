class gebsfishTypes {
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-types.xml";

    void GenerateTypesXML() {
        // Only generate on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the existing file already matches the current version.
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
        WriteVehicleSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-types.xml successfully generated in $profile:Gebs/mpmissions/.", "Types");
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
            foreach (FishConf f : cfg.Fish.Species) {
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
        ref array<ref XmlTypeEntry> gearItems = new array<ref XmlTypeEntry>;
        gearItems.Reserve(100);

        // Fishing rods: the ten colours share the spawns the four rods had (4 x 5 = 20, now 10 x 2 = 20),
        // so a new colour makes each rod rarer, not rods commoner.
        TStringArray rods = {"geb_RedFishingRod", "geb_BlueFishingRod", "geb_GreenFishingRod", "geb_PurpleFishingRod", "geb_OrangeFishingRod", "geb_YellowFishingRod", "geb_BrownFishingRod", "geb_LightBlueFishingRod", "geb_LimeFishingRod", "geb_PinkFishingRod"};
        InsertGearBatch(gearItems, rods, 2, 1);

        // Fishing clothes: 50 pieces (hats, shirts, raincoats, wellies and gloves, ten colours each), one of
        // each in the world, the fewest the economy allows. The four hats, four shirts and two gloves were 30
        // at 3 apiece; one each of every new colour and piece keeps each piece rarer than it was. Typed as
        // clothes, like vanilla's raincoats, caps, T-shirts and gloves, so they spawn where clothing does
        // instead of on tool spots.
        TStringArray clothes = {
            "geb_BlueFishHat", "geb_RedFishHat", "geb_GreenFishHat", "geb_PurpleFishHat", "geb_OrangeFishHat", "geb_YellowFishHat", "geb_BrownFishHat", "geb_LightBlueFishHat", "geb_LimeFishHat", "geb_PinkFishHat",
            "geb_RedFishShirt", "geb_GreenFishShirt", "geb_BlueFishShirt", "geb_PurpleFishShirt", "geb_OrangeFishShirt", "geb_YellowFishShirt", "geb_BrownFishShirt", "geb_LightBlueFishShirt", "geb_LimeFishShirt", "geb_PinkFishShirt",
            "geb_RedFishRaincoat", "geb_GreenFishRaincoat", "geb_BlueFishRaincoat", "geb_PurpleFishRaincoat", "geb_OrangeFishRaincoat", "geb_YellowFishRaincoat", "geb_BrownFishRaincoat", "geb_LightBlueFishRaincoat", "geb_LimeFishRaincoat", "geb_PinkFishRaincoat",
            "geb_RedFishWellies", "geb_GreenFishWellies", "geb_BlueFishWellies", "geb_PurpleFishWellies", "geb_OrangeFishWellies", "geb_YellowFishWellies", "geb_BrownFishWellies", "geb_LightBlueFishWellies", "geb_LimeFishWellies", "geb_PinkFishWellies",
            "geb_BlueFishGloves", "geb_OrangeFishGloves", "geb_YellowFishGloves", "geb_RedFishGloves", "geb_GreenFishGloves", "geb_PurpleFishGloves", "geb_BrownFishGloves", "geb_LightBlueFishGloves", "geb_LimeFishGloves", "geb_PinkFishGloves"
        };
        InsertGearBatch(gearItems, clothes, 1, 1, "clothes");

        // Everything else (knives, tackle boxes, containers, baits/lures,
        // the repair kit, coolers) shares the same 3/1 loot profile.
        TStringArray gear = {
            "geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife",
            "geb_RedFishKnife", "geb_PurpleFishKnife", "geb_LimeFishKnife", "geb_LightBlueFishKnife", "geb_CamoFishKnife", "geb_BrownFishKnife", "geb_PinkFishKnife",
            "geb_OldRedTackle", "geb_OldPurpleTackle", "geb_OldGreenTackle", "geb_OldBlueTackle",
            "geb_YellowTackle", "geb_RedTackle", "geb_PurpleTackle", "geb_PinkTackle",
            "geb_OrangeTackle", "geb_LimeTackle", "geb_LightBlueTackle", "geb_GreenTackle",
            "geb_BrownTackle", "geb_CamoTackle", "geb_BlueTackle", "geb_SmallTackle",
            "geb_MinnowBucket", "geb_BambooFishingNet", "geb_BugContainer", "geb_WormContainer",
            "geb_RubberWorm",
            "geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
            "geb_Lure1", "geb_Lure2", "geb_Lure3", "geb_Lure4",
            "geb_SpoonLure1", "geb_SpoonLure2", "geb_SpoonLure3", "geb_SpoonLure4",
            "geb_CurlyTailJig1", "geb_CurlyTailJig2", "geb_CurlyTailJig3", "geb_CurlyTailJig4",
            "geb_FishingRodRepairKit",
            "geb_RedCooler", "geb_YellowCooler", "geb_BlueCooler", "geb_OrangeCooler",
            "geb_BrownCooler", "geb_PurpleCooler", "geb_PinkCooler", "geb_LimeCooler",
            "geb_LightBlueCooler", "geb_GreenCooler", "geb_CamoCooler"
        };
        InsertGearBatch(gearItems, gear, 3, 1);

        // Quantities stay -1 (the item's config default), as vanilla does
        // for gear: any other range makes the CE re-roll quantity on every
        // spawn, so repair kits would come with random uses left. Lifetime
        // is 4 hours untouched, vanilla's for fishing rods, knives and most
        // tools; at 2 hours a stocked cooler or tackle box left outside a
        // base vanished with everything in it.
        FPrintln(file, "    <!-- Gear Items -->");
        foreach (XmlTypeEntry gearEntry : gearItems) {
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

        // The fish mounts are placed structures, not pocket loot: crafted with
        // nominal 0 like vanilla's WoodenCrate, and the tent/barrel lifetime
        // (45 days untouched) instead of the 4-hour gear lifetime, so wall
        // trophies persist like any base fixture and abandoned ones decay
        // away on the same schedule as tents.
        FPrintln(file, "    <!-- Placed structures -->");
        TStringArray mounts = {"geb_WoodenFishMount", "geb_MediumFishMount", "geb_LargeFishMount"};
        foreach (string mount : mounts) {
            WriteType(file, mount, 0, 3888000, 0, 0, -1, -1, 200, "tools", false, true);
        }
    }

    protected void InsertGearBatch(array<ref XmlTypeEntry> gearItems, TStringArray names, int nominal, int min, string category = "tools") {
        foreach (string name : names) {
            gearItems.Insert(new XmlTypeEntry(name, nominal, min, category));
        }
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

class XmlTypeEntry {
    string Name;
    int Nominal;
    int Min;
    string Category;

    void XmlTypeEntry(string name, int nominal, int min, string category = "tools") {
        Name = name;
        Nominal = nominal;
        Min = min;
        Category = category;
    }
}
