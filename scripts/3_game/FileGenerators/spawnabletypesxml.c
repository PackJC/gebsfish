class gebsfishSpawnableTypes
{
    private const string DIRECTORY_PATH = "$profile:Gebs/extras/mpmissions/";
    private const string FILE_PATH = "$profile:Gebs/extras/mpmissions/gebsfish-spawnabletypes.xml";
    private const string VERSION_PREFIX = "<!-- Version: ";

    void GenerateSpawnableTypesXML()
    {
        // Only generate this on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the current file already matches the mod version.
        if (IsCurrentVersion(FILE_PATH, version))
        {
            GebsfishLogger.Info("Spawnable types XML already at version " + version + ". Skipping regeneration.", "SpawnableTypes");
            return;
        }

        EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file)
        {
            GebsfishLogger.Error("Could not create gebsfish-spawnabletypes.xml in $profile:Gebs/extras/mpmissions/.", "SpawnableTypes");
            return;
        }

        WriteHeader(file, version);
        WriteTackleSection(file);
        WriteClothingSection(file);
        WriteContainerSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-spawnabletypes.xml successfully generated in $profile:Gebs/extras/mpmissions/.", "SpawnableTypes");
    }

    protected bool IsCurrentVersion(string filePath, string expectedVersion)
    {
        if (!FileExist(filePath))
            return false;

        FileHandle readFile = OpenFile(filePath, FileMode.READ);
        if (!readFile)
            return false;

        string line;
        string existingVersion = "";
        int lineCount = 0;

        // Read the first few lines so the version comment can be found even if the XML declaration is first.
        while (lineCount < 5 && FGets(readFile, line) > 0)
        {
            existingVersion = ExtractVersionFromLine(line);
            if (existingVersion != string.Empty)
                break;

            lineCount++;
        }

        CloseFile(readFile);
        return existingVersion == expectedVersion;
    }

    protected string ExtractVersionFromLine(string line)
    {
        int start = line.IndexOf(VERSION_PREFIX);
        if (start == -1)
            return string.Empty;

        string tail = line.Substring(start, line.Length() - start);
        int end = tail.IndexOf("-->");
        if (end == -1)
            return string.Empty;

        return tail.Substring(VERSION_PREFIX.Length(), end - VERSION_PREFIX.Length()).Trim();
    }

    protected void EnsureDirectoryExists()
    {
        MakeDirectory("$profile:Gebs");
        MakeDirectory("$profile:Gebs/extras");
        MakeDirectory(DIRECTORY_PATH);
    }

    protected void WriteHeader(FileHandle file, string version)
    {
        FPrint(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        FPrint(file, "<!-- Version: " + version + " -->");
        FPrint(file, "<spawnabletypes>");
    }

    protected void WriteFooter(FileHandle file)
    {
        FPrint(file, "</spawnabletypes>");
    }

    protected void WriteTackleSection(FileHandle file)
    {
        ref array<string> tackleItems = new array<string>;
        tackleItems.Insert("geb_OldBlueTackle");
        tackleItems.Insert("geb_OldGreenTackle");
        tackleItems.Insert("geb_OldPurpleTackle");
        tackleItems.Insert("geb_OldRedTackle");
        tackleItems.Insert("geb_RedTackle");
        tackleItems.Insert("geb_PurpleTackle");
        tackleItems.Insert("geb_PinkTackle");
        tackleItems.Insert("geb_OrangeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LightBlueTackle");
        tackleItems.Insert("geb_GreenTackle");
        tackleItems.Insert("geb_BrownTackle");
        tackleItems.Insert("geb_CamoTackle");
        tackleItems.Insert("geb_BlueTackle");
        tackleItems.Insert("geb_FunPurpleTackle");
        tackleItems.Insert("geb_FunYellowTackle");
        tackleItems.Insert("geb_FunGreenTackle");
        tackleItems.Insert("geb_FunRedTackle");
        tackleItems.Insert("geb_SmallTackle");

        // Repeated entries change before release.
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");
        tackleItems.Insert("geb_LimeTackle");

        ref array<ref XmlCargoItem> tackleCargo = new array<ref XmlCargoItem>;
        tackleCargo.Insert(new XmlCargoItem("geb_Lure1", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_Lure2", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_Lure3", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_Lure4", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_SpinnerBait1", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_SpinnerBait2", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_SpinnerBait3", 0.33));
        tackleCargo.Insert(new XmlCargoItem("geb_SpinnerBait4", 0.33));

        FPrint(file, "    <!-- Tackle -->");
        foreach (string tackle : tackleItems)
        {
            WriteTypeWithSingleCargo(file, tackle, 0.20, tackleCargo);
        }
    }

    protected void WriteClothingSection(FileHandle file)
    {
        ref array<string> clothingItems = new array<string>;
        clothingItems.Insert("geb_GreenFishShirt");
        clothingItems.Insert("geb_BlueFishShirt");
        clothingItems.Insert("geb_PurpleFishShirt");
        clothingItems.Insert("geb_RedFishShirt");

        ref array<ref XmlCargoItem> knifeCargo = new array<ref XmlCargoItem>;
        knifeCargo.Insert(new XmlCargoItem("geb_BlueFishKnife", 0.16));
        knifeCargo.Insert(new XmlCargoItem("geb_OrangeFishKnife", 0.16));
        knifeCargo.Insert(new XmlCargoItem("geb_GreenFishKnife", 0.16));
        knifeCargo.Insert(new XmlCargoItem("geb_YellowFishKnife", 0.16));
        knifeCargo.Insert(new XmlCargoItem("geb_RedFishKnife", 0.16));
        knifeCargo.Insert(new XmlCargoItem("geb_PurpleFishKnife", 0.16));

        ref array<ref XmlCargoItem> hatCargo = new array<ref XmlCargoItem>;
        hatCargo.Insert(new XmlCargoItem("geb_BlueFishHat", 0.25));
        hatCargo.Insert(new XmlCargoItem("geb_GreenFishHat", 0.25));
        hatCargo.Insert(new XmlCargoItem("geb_PurpleFishHat", 0.25));
        hatCargo.Insert(new XmlCargoItem("geb_RedFishHat", 0.25));

        ref array<ref XmlCargoItem> gloveCargo = new array<ref XmlCargoItem>;
        gloveCargo.Insert(new XmlCargoItem("geb_BlueFishGloves", 0.50));
        gloveCargo.Insert(new XmlCargoItem("geb_OrangeFishGloves", 0.50));

        FPrint(file, "    <!-- Clothes -->");
        foreach (string clothing : clothingItems)
        {
            FPrint(file, "    <type name=\"" + clothing + "\">");
            WriteCargoBlock(file, 0.15, knifeCargo);
            WriteCargoBlock(file, 0.15, hatCargo);
            WriteCargoBlock(file, 0.20, gloveCargo);
            FPrint(file, "    </type>");
        }
    }

    protected void WriteContainerSection(FileHandle file)
    {
        FPrint(file, "    <!-- Containers -->");

        ref array<ref XmlCargoItem> wormCargo = new array<ref XmlCargoItem>;
        wormCargo.Insert(new XmlCargoItem("geb_Worm", 1.00));
        WriteTypeWithRepeatedCargo(file, "geb_WormContainer", 6, 0.20, wormCargo);

        ref array<ref XmlCargoItem> bugCargo = new array<ref XmlCargoItem>;
        bugCargo.Insert(new XmlCargoItem("geb_Worm", 0.27));
        bugCargo.Insert(new XmlCargoItem("geb_GrassHopper", 0.26));
        bugCargo.Insert(new XmlCargoItem("geb_FieldCricket", 0.20));
        bugCargo.Insert(new XmlCargoItem("geb_GrubWorm", 0.27));
        WriteTypeWithRepeatedCargo(file, "geb_BugContainer", 12, 0.20, bugCargo);

        ref array<ref XmlCargoItem> minnowCargo = new array<ref XmlCargoItem>;
        minnowCargo.Insert(new XmlCargoItem("geb_FatHeadMinnow", 1.00));
        WriteTypeWithRepeatedCargo(file, "geb_MinnowBucket", 12, 0.20, minnowCargo);
    }

    protected void WriteTypeWithSingleCargo(FileHandle file, string typeName, float cargoChance, array<ref XmlCargoItem> items)
    {
        FPrint(file, "    <type name=\"" + typeName + "\">");
        WriteCargoBlock(file, cargoChance, items);
        FPrint(file, "    </type>");
    }

    protected void WriteTypeWithRepeatedCargo(FileHandle file, string typeName, int repeatCount, float cargoChance, array<ref XmlCargoItem> items)
    {
        FPrint(file, "    <type name=\"" + typeName + "\">");

        for (int i = 0; i < repeatCount; i++)
        {
            WriteCargoBlock(file, cargoChance, items);
        }

        FPrint(file, "    </type>");
    }

    protected void WriteCargoBlock(FileHandle file, float cargoChance, array<ref XmlCargoItem> items)
    {
        FPrint(file, "        <cargo chance=\"" + FormatChance(cargoChance) + "\">");

        foreach (XmlCargoItem item : items)
        {
            FPrint(file, "            <item name=\"" + item.Name + "\" chance=\"" + FormatChance(item.Chance) + "\" />");
        }

        FPrint(file, "        </cargo>");
    }

    protected string FormatChance(float chance)
    {
        return string.Format("%.2f", chance);
    }
}

class XmlCargoItem
{
    string Name;
    float Chance;

    void XmlCargoItem(string name, float chance)
    {
        Name = name;
        Chance = chance;
    }
}
