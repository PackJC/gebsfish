class gebsfishSpawnableTypes {
    void GenerateSpawnableTypesXML()
    {
        // Define current XML version
        string version = "1.0";

        // Define the custom directory inside profiles
        string directoryPath = "$profile:Gebs/extras/mpmissions/";
        string filePath = directoryPath + "gebsfish-spawnabletypes.xml";

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
                            Print("[gebsfish] [SPAWNABLETYPES] spawnable types XML already at version " + version + ", skipping generation.");
                            CloseFile(readFile);
                            return;
                        }
                    }
                }
                CloseFile(readFile);
            }
            // Delete outdated file if version mismatched or not found
            DeleteFile(filePath);
            Print("[gebsfish] [SPAWNABLETYPES] Deleted existing spawnabletypes XML for regeneration.");
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
            Print("[gebsfish] [SPAWNABLETYPES] Error: Could not create gebsfish-spawnabletypes.xml in profiles/Gebs/extras/mpmissions!");
            return;
        }

        // Write XML header with version
        FPrint(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
        FPrint(file, "<!-- Version: " + version + " -->\n");
        FPrint(file, "<spawnabletypes>\n");

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

        FPrint(file, "    <!-- Tackle -->\n");
        foreach (string tackle : tackleItems)
        {
            FPrint(file, "    <type name=\"" + tackle + "\">\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Lure1\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_Lure2\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_Lure3\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_Lure4\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_SpinnerBait1\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_SpinnerBait2\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_SpinnerBait3\" chance=\"0.33\" />\n");
            FPrint(file, "            <item name=\"geb_SpinnerBait4\" chance=\"0.33\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "    </type>\n");
        }

        ref array<string> clothingItems = new array<string>;
        clothingItems.Insert("geb_GreenFishShirt");
        clothingItems.Insert("geb_BlueFishShirt");
        clothingItems.Insert("geb_PurpleFishShirt");
        clothingItems.Insert("geb_RedFishShirt");

        FPrint(file, "    <!-- Clothes -->\n");
        foreach (string clothing : clothingItems )
        {
            FPrint(file, "    <type name=\"" + clothing + "\">\n");
            FPrint(file, "        <cargo chance=\"0.15\">\n");
            FPrint(file, "            <item name=\"geb_BlueFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "            <item name=\"geb_OrangeFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "            <item name=\"geb_GreenFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "            <item name=\"geb_YellowFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "            <item name=\"geb_RedFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "            <item name=\"geb_PurpleFishKnife\" chance=\"0.16\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.15\">\n");
            FPrint(file, "            <item name=\"geb_BlueFishHat\" chance=\"0.25\" />\n");
            FPrint(file, "            <item name=\"geb_GreenFishHat\" chance=\"0.25\" />\n");
            FPrint(file, "            <item name=\"geb_PurpleFishHat\" chance=\"0.25\" />\n");
            FPrint(file, "            <item name=\"geb_RedFishHat\" chance=\"0.25\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_BlueFishGloves\" chance=\"0.50\" />\n");
            FPrint(file, "            <item name=\"geb_OrangeFishGloves\" chance=\"0.50\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "    </type>\n"); 
        }


        FPrint(file, "    <!-- Containers -->\n");

            FPrint(file, "    <type name=\"geb_WormContainer\">\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "    </type>\n");
            FPrint(file, "    <type name=\"geb_BugContainer\">\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_Worm\" chance=\"0.27\" />\n");
            FPrint(file, "            <item name=\"geb_GrassHopper\" chance=\"0.26\" />\n");
            FPrint(file, "            <item name=\"geb_FieldCricket\" chance=\"0.20\" />\n");
            FPrint(file, "            <item name=\"geb_GrubWorm\" chance=\"0.27\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "    </type>\n");

            FPrint(file, "    <type name=\"geb_MinnowBucket\">\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "        <cargo chance=\"0.20\">\n");
            FPrint(file, "            <item name=\"geb_FatHeadMinnow\" chance=\"1.00\" />\n");
            FPrint(file, "        </cargo>\n");
            FPrint(file, "    </type>\n");            

        // Close XML structure
        FPrint(file, "</spawnabletypes>");

        CloseFile(file);
        Print("[gebsfish] [TYPES] gebsfish-spawnabletypes.xml successfully generated in profiles/Gebs/extras/mpmissions/.");
    }
}