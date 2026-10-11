// Jon boats at the map's boat spawn points, next to the vanilla boats rather
// than in place of them.
//
// The Central Economy reads every events file registered in
// cfgeconomycore.xml after the mission's db/events.xml, and an event it
// already knows is updated, not replaced: the fields a later file gives
// overwrite, the children it lists are added, and the rest (vanilla's Boat_01
// children, positions, lifetime, limit) stays. The exception is the flags:
// a later file that leaves out <flags> resets the event's flags to none,
// which would switch off remove_damaged and leave every wrecked boat in place,
// counting toward the caps. So gebsfish-events.xml names the five jon boats,
// the event's nominal and max (each raised by five from the mission's own
// db/events.xml) and the mission's own flags line, and the vanilla boats keep
// every spawn they had.
//
// Each spawn, the economy picks one child at random and skips the spawn when
// that child is at its max, so jon boats capped at one per colour can't crowd
// the vanilla boats out.
class gebsfishEvents {
    private const string FILE_PATH = "$profile:Gebs/mpmissions/gebsfish-events.xml";
    private const string MISSION_EVENTS_PATH = "$mission:db/events.xml";
    private const string BOAT_EVENT = "VehicleBoat";

    // Written at every start, not only on a version change like the types
    // files: the counts and flags come from the mission's db/events.xml, which
    // an admin can edit, and a server can change maps.
    void GenerateEventsXML() {
        if (!g_Game || !g_Game.IsServer())
            return;

        TStringArray boats = GebXmlFiles.s_JonBoats;
        int nominal;
        int max;
        bool active;
        string flags;
        bool found = ReadMissionBoatEvent(nominal, max, active, flags);

        GebXmlFiles.EnsureDirectoryExists();
        FileHandle file = OpenFile(FILE_PATH, FileMode.WRITE);
        if (!file) {
            GebsfishLogger.Error("Could not create gebsfish-events.xml in $profile:Gebs/mpmissions/.", "Events");
            return;
        }

        FPrintln(file, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>");
        GebXmlFiles.WriteVersionLine(file, VERSION_GEBSFISH);

        // No boat event to add to: an empty file, so registering it does no
        // harm. Writing the event anyway would create one with no positions,
        // or switch a disabled one back on.
        if (!found || !active) {
            string why = "has no " + BOAT_EVENT + " event";
            if (found)
                why = "has its " + BOAT_EVENT + " event switched off (active 0)";
            FPrintln(file, "<!-- This mission's db/events.xml " + why + ", so there are no boat spawn points to add the jon boats to. -->");
            FPrintln(file, "<events>");
            FPrintln(file, "</events>");
            CloseFile(file);
            GebsfishLogger.Info("gebsfish-events.xml written without an event: the mission's db/events.xml " + why + ".", "Events");
            return;
        }

        bool counts = nominal >= 0 && max >= 0;
        int newNominal = nominal + boats.Count();
        int newMax = max + boats.Count();

        FPrintln(file, "<!-- Jon boats at this map's boat spawn points, next to the vanilla boats.");
        FPrintln(file, "     Copy this file into a folder named gebsfish in your mission folder and register it in cfgeconomycore.xml:");
        FPrintln(file, "         <ce folder=\"gebsfish\">");
        FPrintln(file, "             <file name=\"gebsfish-events.xml\" type=\"events\"/>");
        FPrintln(file, "         </ce>");
        FPrintln(file, "     gebsfish-types.xml must be in your economy too, or the economy leaves the jon boats out.");
        FPrintln(file, "     The economy reads this file after db/events.xml and adds to its VehicleBoat event: the five jon boats");
        FPrintln(file, "     join the vanilla boats, one of each colour at most, and everything else about the event stays as");
        if (counts) {
            FPrintln(file, "     db/events.xml has it, except the nominal and max, which go up by five (from " + nominal.ToString() + " and " + max.ToString() + " in this");
            FPrintln(file, "     mission's db/events.xml) so the vanilla boats keep all their spawns.");
        } else {
            FPrintln(file, "     db/events.xml has it. Its VehicleBoat event has no nominal or max this file could read, so the");
            FPrintln(file, "     jon boats share the event's count with the vanilla boats.");
        }
        FPrintln(file, "     The flags line is db/events.xml's own: the economy clears an event's flags when a later file leaves");
        FPrintln(file, "     them out, which would stop wrecked boats being cleaned up. If you change the VehicleBoat event in");
        FPrintln(file, "     db/events.xml (its nominal, max or flags), copy this file again after the next start, which rewrites it.");
        FPrintln(file, "     Or skip this file: paste the five child lines into the VehicleBoat event in db/events.xml and add");
        FPrintln(file, "     five to its nominal and max. -->");
        FPrintln(file, "<events>");
        FPrintln(file, "    <event name=\"" + BOAT_EVENT + "\">");
        if (counts) {
            FPrintln(file, "        <nominal>" + newNominal.ToString() + "</nominal>");
            FPrintln(file, "        <max>" + newMax.ToString() + "</max>");
        }
        // An event with no flags line has none set, which is also what leaving
        // it out here gives.
        if (flags != "")
            FPrintln(file, "        " + flags);
        FPrintln(file, "        <children>");
        foreach (string boat : boats) {
            FPrintln(file, "            <child lootmax=\"0\" lootmin=\"0\" max=\"1\" min=\"0\" type=\"" + boat + "\"/>");
        }
        FPrintln(file, "        </children>");
        FPrintln(file, "    </event>");
        FPrintln(file, "</events>");
        CloseFile(file);

        if (counts)
            GebsfishLogger.Info("gebsfish-events.xml written: the five jon boats join the VehicleBoat event, nominal " + nominal.ToString() + " to " + newNominal.ToString() + ", max " + max.ToString() + " to " + newMax.ToString() + ".", "Events");
        else
            GebsfishLogger.Info("gebsfish-events.xml written: the five jon boats join the VehicleBoat event; its nominal and max couldn't be read, so they share its count.", "Events");
    }

    // The VehicleBoat event's nominal, max, active and flags in the mission's
    // db/events.xml, one element per line as vanilla writes them. -1 for a
    // count the event doesn't give; flags is the whole <flags .../> element,
    // joined onto one line if it spans several, or "" if the event has none.
    protected bool ReadMissionBoatEvent(out int nominal, out int max, out bool active, out string flags) {
        nominal = -1;
        max = -1;
        active = true;
        flags = "";

        FileHandle fr = OpenFile(MISSION_EVENTS_PATH, FileMode.READ);
        if (!fr)
            return false;

        string needle = "\"" + BOAT_EVENT + "\"";
        string line;
        bool inside = false;
        bool found = false;
        bool inFlags = false;
        int value;
        while (FGets(fr, line) != -1) {
            if (!inside) {
                if (line.IndexOf("<event") != -1 && line.IndexOf(needle) != -1) {
                    inside = true;
                    found = true;
                }
                continue;
            }
            if (line.IndexOf("</event>") != -1)
                break;
            if (!inFlags && flags == "" && line.IndexOf("<flags") != -1) {
                int at = line.IndexOf("<flags");
                line = line.Substring(at, line.Length() - at);
                inFlags = true;
            }
            if (inFlags) {
                if (flags != "")
                    flags += " ";
                flags += line.Trim();
                int close = flags.IndexOf(">");
                if (close != -1) {
                    // Always written self-closing: <flags> has no content.
                    if (close > 0 && flags.Substring(close - 1, 1) == "/")
                        flags = flags.Substring(0, close + 1);
                    else
                        flags = flags.Substring(0, close) + "/>";
                    inFlags = false;
                }
                continue;
            }
            if (ReadElement(line, "nominal", value))
                nominal = value;
            else if (ReadElement(line, "max", value))
                max = value;
            else if (ReadElement(line, "active", value))
                active = value == 1;
        }
        CloseFile(fr);
        // A flags element that never closed isn't copied: half an element
        // would break the file.
        if (inFlags)
            flags = "";
        return found;
    }

    // <name>number</name> on one line gives the number.
    protected bool ReadElement(string line, string name, out int value) {
        string open = "<" + name + ">";
        int start = line.IndexOf(open);
        if (start == -1)
            return false;
        start += open.Length();
        int end = line.IndexOf("</" + name + ">");
        if (end <= start)
            return false;
        value = line.Substring(start, end - start).Trim().ToInt();
        return true;
    }
}
