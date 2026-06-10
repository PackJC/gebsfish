class gebsfishTypes {
    private const string DIRECTORY_PATH = "$profile:Gebs/mpmissions/";
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-types.xml";
    private const string VERSION_PREFIX = "<!-- Version: ";

    void GenerateTypesXML() {
        // Only generate on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the existing file already matches the current version.
        if (IsCurrentVersion(FILE_PATH, version)) {
            GebsfishLogger.Info("Types XML already at version " + version + ". Skipping regeneration.", "Types");
            return;
        }

        EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file) {
            GebsfishLogger.Error("Could not create gebsfish-types.xml in $profile:Gebs/mpmissions/.", "Types");
            return;
        }

        WriteHeader(file, version);
        WriteFishSection(file);
        WriteGearSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-types.xml successfully generated in $profile:Gebs/mpmissions/.", "Types");
    }

    protected bool IsCurrentVersion(string filePath, string expectedVersion) {
        if (!FileExist(filePath))
            return false;

        FileHandle readFile = OpenFile(filePath, FileMode.READ);
        if (!readFile)
            return false;

        string line;
        string existingVersion = "";
        int lineCount = 0;

        // Read the first few lines so the version comment can be found even if the XML declaration is first.
        while (lineCount < 5 && FGets(readFile, line) > 0) {
            existingVersion = ExtractVersionFromLine(line);
            if (existingVersion != string.Empty)
                break;

            lineCount++;
        }

        CloseFile(readFile);
        return existingVersion == expectedVersion;
    }

    protected string ExtractVersionFromLine(string line) {
        int start = line.IndexOf(VERSION_PREFIX);
        if (start == -1)
            return string.Empty;

        string tail = line.Substring(start, line.Length() - start);
        int end = tail.IndexOf("-->");
        if (end == -1)
            return string.Empty;

        return tail.Substring(VERSION_PREFIX.Length(), end - VERSION_PREFIX.Length()).Trim();
    }

    protected void EnsureDirectoryExists() {
        MakeDirectory("$profile:Gebs");
        MakeDirectory(DIRECTORY_PATH);
    }

    protected void WriteHeader(FileHandle file, string version) {
        FPrintln(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        FPrintln(file, "<!-- Version: " + version + " -->");
        FPrintln(file, "<types>");
    }

    protected void WriteFooter(FileHandle file) {
        FPrintln(file, "</types>");
    }

    protected void WriteFishSection(FileHandle file) {
        FPrintln(file, "    <!-- Fish Items -->");

        gebsfishConfig cfg = GetGebSettingsConfig();
        if (cfg && cfg.Fish && cfg.Fish.Species) {
            foreach (FishConf f : cfg.Fish.Species) {
                if (!f || f.Classname == "") continue;
                WriteType(file, f.Classname, 0, 14400, 0, 0, 10, 100, 100, "food", false);
                if (f.ResultMain != "")  WriteType(file, f.ResultMain, 0, 14400, 0, 0, 10, 100, 100, "food", false);
                if (f.ResultBonus != "") WriteType(file, f.ResultBonus, 0, 14400, 0, 0, 10, 100, 100, "food", false);
            }
        }
    }

    protected void WriteGearSection(FileHandle file) {
        ref array<ref XmlTypeEntry> gearItems = new array<ref XmlTypeEntry>;
        gearItems.Reserve(80);

        // Fishing rods spawn slightly more often than the rest of the gear.
        TStringArray rods = {"geb_RedFishingRod", "geb_BlueFishingRod", "geb_GreenFishingRod", "geb_PurpleFishingRod"};
        InsertGearBatch(gearItems, rods, 5, 1);

        // Everything else (knives, tackle boxes, containers, baits/lures,
        // clothing, coolers) shares the same 3/1 loot profile.
        TStringArray gear = {
            "geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife",
            "geb_RedFishKnife", "geb_PurpleFishKnife",
            "geb_OldRedTackle", "geb_OldPurpleTackle", "geb_OldGreenTackle", "geb_OldBlueTackle",
            "geb_YellowTackle", "geb_RedTackle", "geb_PurpleTackle", "geb_PinkTackle",
            "geb_OrangeTackle", "geb_LimeTackle", "geb_LightBlueTackle", "geb_GreenTackle",
            "geb_BrownTackle", "geb_CamoTackle", "geb_BlueTackle", "geb_SmallTackle",
            "geb_MinnowBucket", "geb_BambooFishingNet", "geb_BugContainer", "geb_WormContainer",
            "geb_RubberWorm", "geb_GrassHopper", "geb_FieldCricket", "geb_GrubWorm",
            "geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
            "geb_Lure1", "geb_Lure2", "geb_Lure3", "geb_Lure4",
            "geb_SpoonLure1", "geb_SpoonLure2", "geb_SpoonLure3", "geb_SpoonLure4",
            "geb_CurlyTailJig1", "geb_CurlyTailJig2", "geb_CurlyTailJig3", "geb_CurlyTailJig4",
            "geb_FunPurpleTackle", "geb_FunYellowTackle", "geb_FunGreenTackle", "geb_FunRedTackle",
            "geb_BlueFishHat", "geb_RedFishHat", "geb_GreenFishHat", "geb_PurpleFishHat",
            "geb_RedFishShirt", "geb_GreenFishShirt", "geb_BlueFishShirt", "geb_PurpleFishShirt",
            "geb_FishingRodRepairKit", "geb_BlueFishGloves", "geb_OrangeFishGloves",
            "geb_RedCooler", "geb_YellowCooler", "geb_BlueCooler", "geb_OrangeCooler",
            "geb_BrownCooler", "geb_PurpleCooler", "geb_PinkCooler", "geb_LimeCooler",
            "geb_LightBlueCooler", "geb_GreenCooler", "geb_CamoCooler"
        };
        InsertGearBatch(gearItems, gear, 3, 1);

        FPrintln(file, "    <!-- Gear Items -->");
        foreach (XmlTypeEntry gearEntry : gearItems) {
            WriteType(file, gearEntry.Name, gearEntry.Nominal, 7200, 0, gearEntry.Min, 0, 100, 200, "tools", true);
        }
    }

    protected void InsertGearBatch(array<ref XmlTypeEntry> gearItems, TStringArray names, int nominal, int min) {
        foreach (string name : names) {
            gearItems.Insert(new XmlTypeEntry(name, nominal, min));
        }
    }

    protected void WriteType(FileHandle file, string typeName, int nominal, int lifetime, int restock, int min, int quantMin, int quantMax, int cost, string category, bool addUsageTags) {
        FPrintln(file, "    <type name=\"" + typeName + "\">");
        FPrintln(file, "        <nominal>" + nominal.ToString() + "</nominal>");
        FPrintln(file, "        <lifetime>" + lifetime.ToString() + "</lifetime>");
        FPrintln(file, "        <restock>" + restock.ToString() + "</restock>");
        FPrintln(file, "        <min>" + min.ToString() + "</min>");
        FPrintln(file, "        <quantmin>" + quantMin.ToString() + "</quantmin>");
        FPrintln(file, "        <quantmax>" + quantMax.ToString() + "</quantmax>");
        FPrintln(file, "        <cost>" + cost.ToString() + "</cost>");
        FPrintln(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"1\" deloot=\"0\"/>");
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

    void XmlTypeEntry(string name, int nominal, int min) {
        Name = name;
        Nominal = nominal;
        Min = min;
    }
}
