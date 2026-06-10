class gebsfishSpawnableTypes {
    private const string DIRECTORY_PATH = "$profile:Gebs/mpmissions/";
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-spawnabletypes.xml";
    private const string VERSION_PREFIX = "<!-- Version: ";

    void GenerateSpawnableTypesXML() {
        // Only generate this on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the current file already matches the mod version.
        if (IsCurrentVersion(FILE_PATH, version)) {
            GebsfishLogger.Info("Spawnable types XML already at version " + version + ". Skipping regeneration.", "SpawnableTypes");
            return;
        }

        EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file) {
            GebsfishLogger.Error("Could not create gebsfish-spawnabletypes.xml in $profile:Gebs/mpmissions/.", "SpawnableTypes");
            return;
        }

        WriteHeader(file, version);
        WriteTackleSection(file);
        WriteClothingSection(file);
        WriteContainerSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-spawnabletypes.xml successfully generated in $profile:Gebs/mpmissions/.", "SpawnableTypes");
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
        FPrintln(file, "<spawnabletypes>");
    }

    protected void WriteFooter(FileHandle file) {
        FPrintln(file, "</spawnabletypes>");
    }

    protected void WriteTackleSection(FileHandle file) {
        ref TStringArray tackleItems = {
            "geb_OldBlueTackle", "geb_OldGreenTackle", "geb_OldPurpleTackle", "geb_OldRedTackle",
            "geb_RedTackle", "geb_PurpleTackle", "geb_PinkTackle", "geb_OrangeTackle",
            "geb_LimeTackle", "geb_LightBlueTackle", "geb_GreenTackle", "geb_BrownTackle",
            "geb_CamoTackle", "geb_BlueTackle", "geb_FunPurpleTackle", "geb_FunYellowTackle",
            "geb_FunGreenTackle", "geb_FunRedTackle", "geb_SmallTackle"
        };

        TStringArray lures = {
            "geb_Lure1", "geb_Lure2", "geb_Lure3", "geb_Lure4",
            "geb_SpinnerBait1", "geb_SpinnerBait2", "geb_SpinnerBait3", "geb_SpinnerBait4",
            "geb_CurlyTailJig1", "geb_CurlyTailJig2", "geb_CurlyTailJig3", "geb_CurlyTailJig4",
            "geb_SpoonLure1", "geb_SpoonLure2", "geb_SpoonLure3", "geb_SpoonLure4"
        };
        ref array<ref XmlCargoItem> tackleCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(tackleCargo, lures, 0.33);

        FPrintln(file, "    <!-- Tackle -->");
        foreach (string tackle : tackleItems) {
            WriteTypeWithSingleCargo(file, tackle, 0.20, tackleCargo);
        }
    }

    protected void WriteClothingSection(FileHandle file) {
        ref TStringArray clothingItems = {"geb_GreenFishShirt", "geb_BlueFishShirt", "geb_PurpleFishShirt", "geb_RedFishShirt"};

        TStringArray knives = {"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_RedFishKnife", "geb_PurpleFishKnife"};
        ref array<ref XmlCargoItem> knifeCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(knifeCargo, knives, 0.16);

        TStringArray hats = {"geb_BlueFishHat", "geb_GreenFishHat", "geb_PurpleFishHat", "geb_RedFishHat"};
        ref array<ref XmlCargoItem> hatCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(hatCargo, hats, 0.25);

        TStringArray gloves = {"geb_BlueFishGloves", "geb_OrangeFishGloves"};
        ref array<ref XmlCargoItem> gloveCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(gloveCargo, gloves, 0.50);

        FPrintln(file, "    <!-- Clothes -->");
        foreach (string clothing : clothingItems)
        {
            FPrintln(file, "    <type name=\"" + clothing + "\">");
            WriteCargoBlock(file, 0.15, knifeCargo);
            WriteCargoBlock(file, 0.15, hatCargo);
            WriteCargoBlock(file, 0.20, gloveCargo);
            FPrintln(file, "    </type>");
        }
    }

    protected void WriteContainerSection(FileHandle file) {
        FPrintln(file, "    <!-- Containers -->");

        ref array<ref XmlCargoItem> wormCargo = new array<ref XmlCargoItem>;
        wormCargo.Insert(new XmlCargoItem("Worm", 1.00));
        WriteTypeWithRepeatedCargo(file, "geb_WormContainer", 6, 0.20, wormCargo);

        ref array<ref XmlCargoItem> bugCargo = new array<ref XmlCargoItem>;
        bugCargo.Insert(new XmlCargoItem("Worm", 0.27));
        bugCargo.Insert(new XmlCargoItem("geb_GrassHopper", 0.26));
        bugCargo.Insert(new XmlCargoItem("geb_FieldCricket", 0.20));
        bugCargo.Insert(new XmlCargoItem("geb_GrubWorm", 0.27));
        WriteTypeWithRepeatedCargo(file, "geb_BugContainer", 12, 0.20, bugCargo);

        ref array<ref XmlCargoItem> minnowCargo = new array<ref XmlCargoItem>;
        minnowCargo.Insert(new XmlCargoItem("geb_FatHeadMinnow", 1.00));
        minnowCargo.Insert(new XmlCargoItem("geb_AmericanBullFrog", 1.00));
        minnowCargo.Insert(new XmlCargoItem("geb_RedSalamander", 1.00));
        WriteTypeWithRepeatedCargo(file, "geb_MinnowBucket", 12, 0.20, minnowCargo);
    }

    protected void WriteTypeWithSingleCargo(FileHandle file, string typeName, float cargoChance, array<ref XmlCargoItem> items) {
        FPrintln(file, "    <type name=\"" + typeName + "\">");
        WriteCargoBlock(file, cargoChance, items);
        FPrintln(file, "    </type>");
    }

    protected void WriteTypeWithRepeatedCargo(FileHandle file, string typeName, int repeatCount, float cargoChance, array<ref XmlCargoItem> items) {
        FPrintln(file, "    <type name=\"" + typeName + "\">");

        for (int i = 0; i < repeatCount; i++) {
            WriteCargoBlock(file, cargoChance, items);
        }

        FPrintln(file, "    </type>");
    }

    protected void InsertCargoBatch(array<ref XmlCargoItem> items, TStringArray names, float chance) {
        foreach (string name : names) {
            items.Insert(new XmlCargoItem(name, chance));
        }
    }

    protected void WriteCargoBlock(FileHandle file, float cargoChance, array<ref XmlCargoItem> items) {
        FPrintln(file, "        <cargo chance=\"" + FormatChance(cargoChance) + "\">");

        foreach (XmlCargoItem item : items) {
            FPrintln(file, "            <item name=\"" + item.Name + "\" chance=\"" + FormatChance(item.Chance) + "\" />");
        }

        FPrintln(file, "        </cargo>");
    }

    protected string FormatChance(float chance) {
        return string.Format("%.2f", chance);
    }
}

class XmlCargoItem {
    string Name;
    float Chance;

    void XmlCargoItem(string name, float chance) {
        Name = name;
        Chance = chance;
    }
}
