class gebsfishTypes {
    void GenerateTypesXML()
    {
        // Define current XML version
        string version = "1.0";

        // Define the custom directory inside profiles
        string directoryPath = "$profile:Gebs/extras/mpmissions/";
        string filePath = directoryPath + "gebsfish-types.xml";

        // Version check: if file exists, read its version
        if (FileExist(filePath))
        {
            FileHandle readFile = OpenFile(filePath, FileMode.READ);
            if (readFile)
            {
                string firstLine;
                FGets(readFile, firstLine);
                int start = firstLine.IndexOf("<!-- Version: ");
                if (start != -1)
                {
                    string tail = firstLine.Substring(start, firstLine.Length() - start);
                    int end = tail.IndexOf("-->");
                    if (end != -1)
                    {
                        // Skip "<!-- Version: " which is 14 characters
                        string existingVersion = tail.Substring(14, end - 14).Trim();
                        if (existingVersion == version)
                        {
                            Print("[gebsfish] [TYPES] types XML already at version " + version + ", skipping generation.");
                            CloseFile(readFile);
                            return;
                        }
                    }
                }
                CloseFile(readFile);
            }
            DeleteFile(filePath);
            Print("[gebsfish] [TYPES] Deleted existing types XML for regeneration.");
        }

        // Ensure the directory exists
        if (!FileExist(directoryPath))
        {
            MakeDirectory("$profile:Gebs");
            MakeDirectory("$profile:Gebs/extras/");
            MakeDirectory(directoryPath);
        }

        // Open file for writing
        FileHandle file = OpenFile(filePath, FileMode.WRITE);
        if (!file)
        {
            Print("[gebsfish] [TYPES] Error: Could not create gebsfish-types.xml in profiles/Gebs/extras/mpmissions!");
            return;
        }

        // Write XML header with version
        FPrint(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        FPrint(file, "<!-- Version: " + version + " -->");
        FPrint(file, "<types>");


        // Fish Items
        ref array<string> fishItems = new array<string>;
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
        fishItems.Insert("geb_CrayFish");
        fishItems.Insert("geb_CrayFishTailMeat");
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
        fishItems.Insert("geb_FatHeadMinnowFilletMeat");
        fishItems.Insert("geb_BlueGill");
        fishItems.Insert("geb_BlueGillFilletMeat");
        fishItems.Insert("geb_Sauger");
        fishItems.Insert("geb_SaugerFilletMeat");
        fishItems.Insert("geb_BowFin");
        fishItems.Insert("geb_BowFinFilletMeat");
        fishItems.Insert("geb_Mussel");
        fishItems.Insert("geb_MusselFilletMeat");
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
        fishItems.Insert("geb_FlatHeadmullet");
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
        fishItems.Insert("geb_KingCrabFilletMeat");
        fishItems.Insert("geb_BlueJellyFish");
        fishItems.Insert("geb_BlueJellyFishFilletMeat");
        fishItems.Insert("geb_Lobster");
        fishItems.Insert("geb_LobsterTail");
        fishItems.Insert("geb_LobsterFilletMeat");
        fishItems.Insert("geb_BlueLobster");
        fishItems.Insert("geb_BlueLobsterTail");
        fishItems.Insert("geb_BlueLobsterFilletMeat");
        fishItems.Insert("geb_GreatWhiteShark");
        fishItems.Insert("geb_GreatWhiteSharkFilletMeat");
        fishItems.Insert("geb_AngelShark");
        fishItems.Insert("geb_AngelSharkFilletMeat");
        fishItems.Insert("geb_YellowFinTuna");
        fishItems.Insert("geb_YellowFinTunaFilletMeat");

        FPrint(file, "    <!-- Fish Items -->\n");
        foreach (string fish : fishItems)
        {
            FPrint(file, "    <type name=\"" + fish + "\">\n");
            FPrint(file, "        <nominal>0</nominal>\n");
            FPrint(file, "        <lifetime>14400</lifetime>\n");
            FPrint(file, "        <restock>0</restock>\n");
            FPrint(file, "        <min>0</min>\n");
            FPrint(file, "        <quantmin>10</quantmin>\n");
            FPrint(file, "        <quantmax>100</quantmax>\n");
            FPrint(file, "        <cost>100</cost>\n");
            FPrint(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"1\" deloot=\"0\"/>\n");
            FPrint(file, "        <category name=\"food\"/>\n");
            FPrint(file, "    </type>\n");
        }

        // Gear Items
        ref array<ref Param3<string, int, int>> gearItems = new array<ref Param3<string, int, int>>;
        gearItems.Insert(new Param3<string, int, int>("geb_RedFishingRod", 5, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BlueFishingRod", 5, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GreenFishingRod", 5, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PurpleFishingRod", 5, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BlueFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OrangeFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GreenFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_YellowFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_RedFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PurpleFishKnife", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OldRedTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OldPurpleTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OldGreenTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OldBlueTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_YellowTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_RedTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PurpleTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PinkTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_OrangeTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_LimeTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_LightBlueTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GreenTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BrownTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_CamoTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BlueTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_SmallTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_MinnowBucket", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BambooFishingNet", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BugContainer", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_WormContainer", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_RubberWorm", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GrassHopper", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_FieldCricket", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GrubWorm", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_SpinnerBait1", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_SpinnerBait2", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_SpinnerBait3", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_SpinnerBait4", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_Lure1", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_Lure2", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_Lure3", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_Lure4", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_FunPurpleTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_FunYellowTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_FunGreenTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_FunRedTackle", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BlueFishHat", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_RedFishHat", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GreenFishHat", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PurpleFishHat", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_RedFishShirt", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_GreenFishShirt", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_BlueFishShirt", 3, 1));
        gearItems.Insert(new Param3<string, int, int>("geb_PurpleFishShirt", 3, 1));

        FPrint(file, "    <!-- Gear Items -->\n");
        foreach (Param3<string, int, int> gear : gearItems)
        {
            FPrint(file, "    <type name=\"" + gear.param1 + "\">\n");
            FPrint(file, "        <nominal>" + gear.param2.ToString() + "</nominal>\n");
            FPrint(file, "        <lifetime>7200</lifetime>\n");
            FPrint(file, "        <restock>0</restock>\n");
            FPrint(file, "        <min>" + gear.param3.ToString() + "</min>\n");
            FPrint(file, "        <quantmin>0</quantmin>\n");
            FPrint(file, "        <quantmax>100</quantmax>\n");
            FPrint(file, "        <cost>200</cost>\n");
            FPrint(file, "        <flags count_in_cargo=\"0\" count_in_hoarder=\"0\" count_in_map=\"1\" count_in_player=\"0\" crafted=\"1\" deloot=\"0\"/>\n");
            FPrint(file, "        <category name=\"tools\"/>\n");
            FPrint(file, "        <usage name=\"Coast\"/>\n");
            FPrint(file, "        <usage name=\"Farm\"/>\n");
            FPrint(file, "        <usage name=\"Hunting\"/>\n");
            FPrint(file, "        <usage name=\"Village\"/>\n");
            FPrint(file, "    </type>\n");
        }

        // Close XML structure
        FPrint(file, "</types>");

        CloseFile(file);
        Print("[gebsfish] [TYPES] gebsfish-types.xml successfully generated in profiles/Gebs/extras/mpmissions/.");
    }
}