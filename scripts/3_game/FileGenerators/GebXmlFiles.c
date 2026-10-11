/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// What the files written to $profile:Gebs/mpmissions share (gebsfish-types,
// gebsfish-spawnabletypes and gebsfish-events): the folder, the version line
// at the top of each, and the jon boats all three list.
class GebXmlFiles {
    static const string DIRECTORY_PATH = "$profile:Gebs/mpmissions/";
    static const string VERSION_PREFIX = "<!-- Version: ";

    // The five jon boat colours.
    static ref TStringArray s_JonBoats = {"geb_jonboat_greenaluminum", "geb_jonboat_grayaluminum", "geb_jonboat_camo_desert", "geb_jonboat_camo_snow", "geb_jonboat_camo_forest"};

    static void EnsureDirectoryExists() {
        GebMakeConfigDir();
        MakeDirectory(DIRECTORY_PATH);
    }

    // The line IsCurrentVersion reads back.
    static void WriteVersionLine(FileHandle file, string version) {
        FPrintln(file, VERSION_PREFIX + version + " -->");
    }

    static bool IsCurrentVersion(string filePath, string expectedVersion) {
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

    protected static string ExtractVersionFromLine(string line) {
        int start = line.IndexOf(VERSION_PREFIX);
        if (start == -1)
            return string.Empty;

        string tail = line.Substring(start, line.Length() - start);
        int end = tail.IndexOf("-->");
        if (end == -1)
            return string.Empty;

        return tail.Substring(VERSION_PREFIX.Length(), end - VERSION_PREFIX.Length()).Trim();
    }
}
