class gebsfishSpawnableTypes {
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-spawnabletypes.xml";

    void GenerateSpawnableTypesXML() {
        // Only generate this on the server.
        if (!g_Game || !g_Game.IsServer())
            return;

        string version = VERSION_GEBSFISH;

        // Skip regeneration if the current file already matches the mod version.
        if (GebXmlFiles.IsCurrentVersion(FILE_PATH, version)) {
            GebsfishLogger.Info("Spawnable types XML already at version " + version + ". Skipping regeneration.", "SpawnableTypes");
            return;
        }

        GebXmlFiles.EnsureDirectoryExists();

        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file) {
            GebsfishLogger.Error("Could not create gebsfish-spawnabletypes.xml in $profile:Gebs/mpmissions/.", "SpawnableTypes");
            return;
        }

        WriteHeader(file, version);
        WriteTackleSection(file);
        WriteClothingSection(file);
        WriteContainerSection(file);
        WriteVehicleSection(file);
        WriteFooter(file);

        CloseFile(file);
        GebsfishLogger.Info("gebsfish-spawnabletypes.xml successfully generated in $profile:Gebs/mpmissions/.", "SpawnableTypes");
    }

    protected void WriteHeader(FileHandle file, string version) {
        FPrintln(file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        GebXmlFiles.WriteVersionLine(file, version);
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
            "geb_CamoTackle", "geb_BlueTackle", "geb_YellowTackle", "geb_SmallTackle"
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
        // Shirts may carry a fish knife, a fishing hat and fishing gloves; raincoats and wellies spawn empty.
        ref TStringArray clothingItems = {"geb_GreenFishShirt", "geb_BlueFishShirt", "geb_PurpleFishShirt", "geb_RedFishShirt", "geb_OrangeFishShirt", "geb_YellowFishShirt", "geb_BrownFishShirt", "geb_LightBlueFishShirt", "geb_LimeFishShirt", "geb_PinkFishShirt"};

        TStringArray knives = {"geb_BlueFishKnife", "geb_OrangeFishKnife", "geb_GreenFishKnife", "geb_YellowFishKnife", "geb_RedFishKnife", "geb_PurpleFishKnife", "geb_LimeFishKnife", "geb_LightBlueFishKnife", "geb_CamoFishKnife", "geb_BrownFishKnife", "geb_PinkFishKnife"};
        ref array<ref XmlCargoItem> knifeCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(knifeCargo, knives, 0.09);

        TStringArray hats = {"geb_BlueFishHat", "geb_GreenFishHat", "geb_PurpleFishHat", "geb_RedFishHat", "geb_OrangeFishHat", "geb_YellowFishHat", "geb_BrownFishHat", "geb_LightBlueFishHat", "geb_LimeFishHat", "geb_PinkFishHat"};
        ref array<ref XmlCargoItem> hatCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(hatCargo, hats, 0.10);

        TStringArray gloves = {"geb_BlueFishGloves", "geb_OrangeFishGloves", "geb_YellowFishGloves", "geb_RedFishGloves", "geb_GreenFishGloves", "geb_PurpleFishGloves", "geb_BrownFishGloves", "geb_LightBlueFishGloves", "geb_LimeFishGloves", "geb_PinkFishGloves"};
        ref array<ref XmlCargoItem> gloveCargo = new array<ref XmlCargoItem>;
        InsertCargoBatch(gloveCargo, gloves, 0.10);

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

    // The jon boats come with a spark plug one time in ten, as vanilla's
    // Boat_01 boats do.
    protected void WriteVehicleSection(FileHandle file) {
        TStringArray boats = GebXmlFiles.s_JonBoats;
        FPrintln(file, "    <!-- Vehicles -->");
        foreach (string boat : boats) {
            FPrintln(file, "    <type name=\"" + boat + "\">");
            FPrintln(file, "        <attachments chance=\"0.10\">");
            FPrintln(file, "            <item name=\"SparkPlug\" chance=\"1.0\" />");
            FPrintln(file, "        </attachments>");
            FPrintln(file, "    </type>");
        }
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

    // Enforce's string.Format has no printf-style %.2f (only %1..%9
    // positional args -- "%.2f" emits the literal text ".2f"), so build the
    // 2-decimal string by hand in integer space. Chance is a 0..1
    // probability; clamp so a bad table value can't emit an out-of-range
    // attribute.
    protected string FormatChance(float chance) {
        int hundredths = Math.Round(chance * 100);
        if (hundredths < 0)
            hundredths = 0;
        if (hundredths > 100)
            hundredths = 100;
        int whole = hundredths / 100;
        int frac = hundredths % 100;
        string fracText = frac.ToString();
        if (frac < 10)
            fracText = "0" + fracText;
        return whole.ToString() + "." + fracText;
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
