class gebsfishTypes
{
    private const string DIRECTORY_PATH = "$profile:Gebs/extras/mpmissions/";
    private const string FILE_PATH = "$profile:Gebs/extras/mpmissions/gebsfish-types.xml";
    private const string VERSION_PREFIX = "<!-- Version: ";

    void GenerateTypesXML()
    {
        // Only generate on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the existing file already matches the current version.
        if (IsCurrentVersion(FILE_PATH, version))
        {
            GebsfishLogger.Info("Types XML already at version " + version + ". Skipping regeneration.", "Types");
            return;
        }

        EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file)
        {
            GebsfishLogger.Error("Could not create gebsfish-types.xml in $profile:Gebs/extras/mpmissions/.", "Types");
            return;
        }

        WriteHeader(file, version);
        WriteFishSection(file);
        WriteGearSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-types.xml successfully generated in $profile:Gebs/extras/mpmissions/.", "Types");
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
        MakeDirectory("$profile:Gebs/Extras");
        MakeDirectory(DIRECTORY_PATH);
    }

    protected void WriteHeader(FileHandle file, string version)
    {
        FPrint(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        FPrint(file, "<!-- Version: " + version + " -->");
        FPrint(file, "<types>");
    }

    protected void WriteFooter(FileHandle file)
    {
        FPrint(file, "</types>");
    }

    protected void WriteFishSection(FileHandle file)
    {
        ref array<string> fishItems = new array<string>;
        fishItems.Reserve(128);

        fishItems.Insert("geb_SockEyeSalmon");
        fishItems.Insert("geb_SockEyeSalmonFilletMeat");
        fishItems.Insert("geb_ChinookSalmon");
        fishItems.Insert("geb_ChinookSalmonFilletMeat");
        fishItems.Insert("geb_SmallMouthBass");
        fishItems.Insert("geb_SmallMouthBassFilletMeat");
        fishItems.Insert("geb_SunFish");
        fishItems.Insert("geb_SunFishFilletMeat");
        fishItems.Insert("geb_WallEye");
        fishItems.Insert("geb_WallEyeFilletMeat");
        fishItems.Insert("geb_BrownTrout");
        fishItems.Insert("geb_BrownTroutFilletMeat");
        fishItems.Insert("geb_BrookTrout");
        fishItems.Insert("geb_BrookTroutFilletMeat");
        fishItems.Insert("geb_LakeTrout");
        fishItems.Insert("geb_LakeTroutFilletMeat");
        fishItems.Insert("geb_CutThroatTrout");
        fishItems.Insert("geb_CutThroatTroutFilletMeat");
        fishItems.Insert("geb_HammerHeadShark");
        fishItems.Insert("geb_HammerHeadSharkFilletMeat");
        fishItems.Insert("geb_Sturgeon");
        fishItems.Insert("geb_SturgeonFilletMeat");
        fishItems.Insert("geb_EuropeanCrayFish");
        fishItems.Insert("geb_SignalCrayFish");
        fishItems.Insert("geb_NorthernPike");
        fishItems.Insert("geb_NorthernPikeFilletMeat");
        fishItems.Insert("geb_LargeMouthBass");
        fishItems.Insert("geb_LargeMouthBassFilletMeat");
        fishItems.Insert("geb_WhiteBass");
        fishItems.Insert("geb_WhiteBassFilletMeat");
        fishItems.Insert("geb_BlackBass");
        fishItems.Insert("geb_BlackBassFilletMeat");
        fishItems.Insert("geb_RainbowTrout");
        fishItems.Insert("geb_RainbowTroutFilletMeat");
        fishItems.Insert("geb_YellowPerch");
        fishItems.Insert("geb_YellowPerchFilletMeat");
        fishItems.Insert("geb_FlatHeadCatFish");
        fishItems.Insert("geb_FlatHeadCatFishFilletMeat");
        fishItems.Insert("geb_FatHeadMinnow");
        fishItems.Insert("geb_BlueGill");
        fishItems.Insert("geb_BlueGillFilletMeat");
        fishItems.Insert("geb_Sauger");
        fishItems.Insert("geb_SaugerFilletMeat");
        fishItems.Insert("geb_BowFin");
        fishItems.Insert("geb_BowFinFilletMeat");
        fishItems.Insert("geb_Mussel");
        fishItems.Insert("geb_BlackDevilSnail");
        fishItems.Insert("geb_SlimySculpin");
        fishItems.Insert("geb_SlimySculpinFilletMeat");
        fishItems.Insert("geb_AngelFish");
        fishItems.Insert("geb_AngelFishFilletMeat");
        fishItems.Insert("geb_AsianSeaBass");
        fishItems.Insert("geb_AsianSeaBassFilletMeat");
        fishItems.Insert("geb_AtlanticBlueMarlin");
        fishItems.Insert("geb_AtlanticBlueMarlinFilletMeat");
        fishItems.Insert("geb_Bonita");
        fishItems.Insert("geb_BonitaFilletMeat");
        fishItems.Insert("geb_CherrySalmon");
        fishItems.Insert("geb_CherrySalmonFilletMeat");
        fishItems.Insert("geb_FlatHeadMullet");
        fishItems.Insert("geb_FlatHeadMulletFilletMeat");
        fishItems.Insert("geb_LeopardShark");
        fishItems.Insert("geb_LeopardSharkFilletMeat");
        fishItems.Insert("geb_PacificCod");
        fishItems.Insert("geb_PacificCodFilletMeat");
        fishItems.Insert("geb_RedHeadCichlid");
        fishItems.Insert("geb_RedHeadCichlidFilletMeat");
        fishItems.Insert("geb_RoughNeckRock");
        fishItems.Insert("geb_RoughNeckRockFilletMeat");
        fishItems.Insert("geb_Severum");
        fishItems.Insert("geb_SeverumFilletMeat");
        fishItems.Insert("geb_BlueTang");
        fishItems.Insert("geb_BlueTangFilletMeat");
        fishItems.Insert("geb_LargeHeadHairTailFish");
        fishItems.Insert("geb_LargeHeadHairTailFishFilletMeat");
        fishItems.Insert("geb_HumpHeadWrasse");
        fishItems.Insert("geb_HumpHeadWrasseFilletMeat");
        fishItems.Insert("geb_SiameseTigerFish");
        fishItems.Insert("geb_SiameseTigerFishFilletMeat");
        fishItems.Insert("geb_MahiMahi");
        fishItems.Insert("geb_MahiMahiFilletMeat");
        fishItems.Insert("geb_AtlanticSailFish");
        fishItems.Insert("geb_AtlanticSailFishFilletMeat");
        fishItems.Insert("geb_StarFish");
        fishItems.Insert("geb_KingCrab");
        fishItems.Insert("geb_KingCrabLegs");
        fishItems.Insert("geb_SnowCrab");
        fishItems.Insert("geb_SnowCrabLegs");
        fishItems.Insert("geb_BlueJellyFish");
        fishItems.Insert("geb_AmericanLobster");
        fishItems.Insert("geb_AmericanLobsterTail");
        fishItems.Insert("geb_AmericanLobsterClaw");
        fishItems.Insert("geb_EuropeanLobster");
        fishItems.Insert("geb_EuropeanLobsterTail");
        fishItems.Insert("geb_EuropeanLobsterClaw");
        fishItems.Insert("geb_GreatWhiteShark");
        fishItems.Insert("geb_GreatWhiteSharkFilletMeat");
        fishItems.Insert("geb_AngelShark");
        fishItems.Insert("geb_AngelSharkFilletMeat");
        fishItems.Insert("geb_YellowFinTuna");
        fishItems.Insert("geb_YellowFinTunaFilletMeat");

        FPrint(file, "    <!-- Fish Items -->");
        foreach (string fish : fishItems)
        {
            WriteType(file, fish, 0, 14400, 0, 0, 10, 100, 100, "food", false);
        }
    }

    protected void WriteGearSection(FileHandle file)
    {
        ref array<ref XmlTypeEntry> gearItems = new array<ref XmlTypeEntry>;
        gearItems.Reserve(64);

        gearItems.Insert(new XmlTypeEntry("geb_RedFishingRod", 5, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BlueFishingRod", 5, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GreenFishingRod", 5, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PurpleFishingRod", 5, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BlueFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OrangeFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GreenFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_YellowFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_RedFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PurpleFishKnife", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OldRedTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OldPurpleTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OldGreenTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OldBlueTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_YellowTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_RedTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PurpleTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PinkTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_OrangeTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_LimeTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_LightBlueTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GreenTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BrownTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_CamoTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BlueTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_SmallTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_MinnowBucket", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BambooFishingNet", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BugContainer", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_WormContainer", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_RubberWorm", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GrassHopper", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FieldCricket", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GrubWorm", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_SpinnerBait1", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_SpinnerBait2", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_SpinnerBait3", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_SpinnerBait4", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_Lure1", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_Lure2", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_Lure3", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_Lure4", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FunPurpleTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FunYellowTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FunGreenTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FunRedTackle", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BlueFishHat", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_RedFishHat", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GreenFishHat", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PurpleFishHat", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_RedFishShirt", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_GreenFishShirt", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_BlueFishShirt", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_PurpleFishShirt", 3, 1));
        gearItems.Insert(new XmlTypeEntry("geb_FishingRodRepairKit", 3, 1));

        FPrint(file, "    <!-- Gear Items -->");
        foreach (XmlTypeEntry gear : gearItems)
        {
            WriteType(file, gear.Name, gear.Nominal, 7200, 0, gear.Min, 0, 100, 200, "tools", true);
        }
    }

    protected void WriteType(FileHandle file, string typeName, int nominal, int lifetime, int restock, int min, int quantMin, int quantMax, int cost, string category, bool addUsageTags)
    {
        FPrint(file, "    <type name=\"" + typeName + "\">");
        FPrint(file, "        <nominal>" + nominal.ToString() + "</nominal>");
        FPrint(file, "        <lifetime>" + lifetime.ToString() + "</lifetime>");
        FPrint(file, "        <restock>" + restock.ToString() + "</restock>");
        FPrint(file, "        <min>" + min.ToString() + "</min>");
        FPrint(file, "        <quantmin>" + quantMin.ToString() + "</quantmin>");
        FPrint(file, "        <quantmax>" + quantMax.ToString() + "</quantmax>");
        FPrint(file, "        <cost>" + cost.ToString() + "</cost>");
        FPrint(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"1\" deloot=\"0\"/>");
        FPrint(file, "        <category name=\"" + category + "\"/>");

        if (addUsageTags)
        {
            FPrint(file, "        <usage name=\"Coast\"/>");
            FPrint(file, "        <usage name=\"Farm\"/>");
            FPrint(file, "        <usage name=\"Hunting\"/>");
            FPrint(file, "        <usage name=\"Village\"/>");
        }

        FPrint(file, "    </type>");
    }
}

class XmlTypeEntry
{
    string Name;
    int Nominal;
    int Min;

    void XmlTypeEntry(string name, int nominal, int min)
    {
        Name = name;
        Nominal = nominal;
        Min = min;
    }
}
