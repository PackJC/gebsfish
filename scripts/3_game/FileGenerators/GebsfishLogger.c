enum GebsfishLogLevel {
    DEBUG = 0,
    INFO  = 1,
    WARN  = 2,
    ERROR = 3
};

class GebsfishLogger {
    // The last argument for every FindFile call in the mod. 1.30's script
    // binding hands it to the engine as the file system to search rather than
    // as flags (Bohemia's DZEXP-134): FindFileFlags.ALL is 2, which picks the
    // server's own folder, while -1 searches the normal way, so $profile:
    // paths resolve again. Once Bohemia fixes the binding, -1 is no valid
    // flag and listings may come back empty again; the log pruner still has
    // sessions.txt then.
    static const int FIND_FILE_FLAGS = -1;

    private static const string LOG_DIR = "$profile:Gebs/logs";
    // Names of the session logs still on disk, one per line (see PruneOldLogs).
    private static const string LOG_INDEX = "$profile:Gebs/logs/sessions.txt";
    // Session logs older than this are deleted on startup (see PruneOldLogs).
    private static const int LOG_RETENTION_DAYS = 3;
    private static string m_SessionFilePath = "";
    private static bool m_Initialized = false;
    private static bool m_InitFailed = false;
    // No session-lifetime handle on purpose. Enforce exposes no flush, so
    // CloseFile is the only thing that commits bytes to disk: opening and
    // closing around each write means a hard crash can never take the tail
    // of the log with it, and it leaves the file unlocked so it can be read
    // or moved while the server is running.

    static void Init(string tag = "gebsfish") {
        if (m_Initialized || m_InitFailed)
            return;

        EnsureDirectory(LOG_DIR);

        string safeTag = SanitizeFileNamePart(tag);
        if (safeTag == string.Empty)
            safeTag = "gebsfish";

        string sessionName = BuildDateTimeCompact() + "_" + safeTag + ".log";
        m_SessionFilePath = LOG_DIR + "/" + sessionName;

        // A log that can't be opened is said once, not tried again every line.
        FileHandle file = OpenFile(m_SessionFilePath, FileMode.WRITE);
        if (file == 0) {
            ToRPT(GebsfishLogLevel.WARN, "Can't write " + m_SessionFilePath + "; no Gebs log this session.", "Logs");
            m_SessionFilePath = "";
            m_InitFailed = true;
            return;
        }

        string side = GetExecutionSide();
        string worldName = GetWorldNameSafe();

        // The banner opens the log, ahead of the header (a log only exists
        // with DebugLogs on).
        GebsAsciiArt.Write(file);
        FPrintln(file, "==================== LOGGING SESSION START ====================");
        FPrintln(file, "World: " + worldName);
        FPrintln(file, "Log Type: " + side);
        FPrintln(file, "Time: " + BuildDateTimeReadable());
        FPrintln(file, "File: " + m_SessionFilePath);
        FPrintln(file, "Gebsfish Version: " + VERSION_GEBSFISH);
        FPrintln(file, "===============================================================");

        CloseFile(file);
        m_Initialized = true;

        // Safe to log from here: m_Initialized is set, so the Info() below
        // re-enters Init() and returns immediately instead of recursing.
        PruneOldLogs(sessionName);
    }

    // Whether this side writes its Gebs log: DebugLogs 1 or 2. The loaded
    // config answers once general.json is in (a client's once the server's
    // config arrives); before that, general.json's own text does.
    private static bool LoggingOn() {
        if (m_gebsConfig && m_gebsConfig.General && m_gebsConfig.General.GeneralSettings)
            return GebGetDebugLevel() >= 1;
        return DebugLogsOn();
    }

    // DebugLogs read from general.json's text: the logger starts on its first
    // line, while general.json is still loading, so the loaded config can't
    // answer yet. No file (a first boot, or a client) counts as off. Read once
    // (-1 = not yet): the main menu and a client before the server's config
    // arrives ask on every line.
    private static int m_FileDebugLogs = -1;

    private static bool DebugLogsOn() {
        if (m_FileDebugLogs >= 0)
            return m_FileDebugLogs > 0;
        m_FileDebugLogs = 0;
        FileHandle file = OpenFile(GEB_CONFIG_DIR + "/general.json", FileMode.READ);
        if (!file)
            return false;
        string line;
        while (FGets(file, line) >= 0) {
            int at = line.IndexOf("\"DebugLogs\"");
            if (at < 0)
                continue;
            string value = line.Substring(at + 11, line.Length() - at - 11);   // after "DebugLogs"
            value.Replace(":", "");
            value.Replace(",", "");
            m_FileDebugLogs = value.Trim().ToInt();
            if (m_FileDebugLogs < 0)
                m_FileDebugLogs = 0;
            break;
        }
        CloseFile(file);
        return m_FileDebugLogs > 0;
    }

    // Delete session logs older than LOG_RETENTION_DAYS so an unattended server
    // doesn't accumulate one file per restart forever.
    //
    // Age comes from the filename, not the filesystem: Enforce's FindFile hands
    // back FileAttr flags only, with no modification time anywhere in the API, and
    // we control the name format (BuildDateTimeCompact -> YYYYMMDD-HHMMSS_tag.log)
    // so the date is right there. Anything that doesn't parse as that format is
    // left alone -- this only ever deletes files it positively recognises as its
    // own, never "everything in the folder".
    // A directory listing can't tell a folder from a file by its attribute:
    // the script enum makes FileAttr.DIRECTORY its first member (0), so
    // "attr & FileAttr.DIRECTORY" is always 0. A folder is what can't be opened
    // for reading as a file.
    static bool IsRegularFile(string path) {
        FileHandle file = OpenFile(path, FileMode.READ);
        if (!file)
            return false;
        CloseFile(file);
        return true;
    }

    // Finding the files: a folder listing (see FIND_FILE_FLAGS for why it
    // passes -1), plus the names in sessions.txt, which the logger keeps so
    // pruning doesn't depend on FindFile alone while Bohemia's DZEXP-134 is
    // open. A name a broken listing takes from another folder doesn't open
    // under Gebs/logs and is skipped, so it can't reach other files.
    private static void PruneOldLogs(string sessionName) {
        int year, month, day;
        GetYearMonthDayUTC(year, month, day);   // filenames are UTC, so compare in UTC
        int today = DayNumber(year, month, day);

        array<string> names = ReadLogIndex();
        if (names.Find(sessionName) == -1)
            names.Insert(sessionName);

        // Collect first, delete after: mutating a live directory listing risks
        // skipping entries (same reason GebsfishMigration.MoveDirFiles does this).
        string fileName;
        FileAttr attr;
        FindFileHandle handle = FindFile(LOG_DIR + "/*.log", fileName, attr, FIND_FILE_FLAGS);
        if (handle) {
            bool more = true;
            while (more) {
                if (fileName != "" && names.Find(fileName) == -1)
                    names.Insert(fileName);
                more = FindNextFile(handle, fileName, attr);
            }
            CloseFindFile(handle);
        }

        array<string> kept = new array<string>();
        int deleted = 0;
        foreach (string name : names) {
            int fileDay = ParseLogDayNumber(name);
            if (fileDay <= 0 || !IsPlainLogName(name))
                continue;
            string full = LOG_DIR + "/" + name;
            if (!IsRegularFile(full))
                continue;                       // already gone, or not in Gebs/logs
            // Never the live session file; a log that won't delete stays
            // listed and is tried again next start.
            if (full != m_SessionFilePath && (today - fileDay) >= LOG_RETENTION_DAYS && DeleteFile(full)) {
                deleted++;
                continue;
            }
            kept.Insert(name);
        }
        WriteLogIndex(kept);

        if (deleted > 0)
            Info("Removed " + deleted + " log file(s) older than " + LOG_RETENTION_DAYS + " days.", "Logs");
    }

    // A bare file name ending in .log. sessions.txt is a text file anyone with
    // access to the profile can edit, so nothing from it reaches DeleteFile
    // with a folder in it.
    private static bool IsPlainLogName(string name) {
        if (name.Contains("/") || name.Contains("\\") || name.Contains(".."))
            return false;
        int len = name.Length();
        return len > 4 && name.Substring(len - 4, 4) == ".log";
    }

    private static array<string> ReadLogIndex() {
        array<string> names = new array<string>();
        FileHandle file = OpenFile(LOG_INDEX, FileMode.READ);
        if (!file)
            return names;
        string line;
        while (FGets(file, line) >= 0) {
            line = line.Trim();
            if (line != "" && names.Find(line) == -1)
                names.Insert(line);
        }
        CloseFile(file);
        return names;
    }

    private static void WriteLogIndex(array<string> names) {
        FileHandle file = OpenFile(LOG_INDEX, FileMode.WRITE);
        if (!file)
            return;
        foreach (string entry : names)
            FPrintln(file, entry);
        CloseFile(file);
    }

    // Day number for the YYYYMMDD prefix of a log filename, or -1 if the name
    // isn't ours. Re-padding the parsed values and comparing back to the original
    // text rejects non-numeric junk without a character-by-character scan --
    // ToInt() returns 0 for garbage, which won't round-trip.
    private static int ParseLogDayNumber(string name) {
        if (name.Length() < 8)
            return -1;

        string ys = name.Substring(0, 4);
        string ms = name.Substring(4, 2);
        string ds = name.Substring(6, 2);

        int y = ys.ToInt();
        int m = ms.ToInt();
        int d = ds.ToInt();

        if (Pad4(y) != ys || Pad2(m) != ms || Pad2(d) != ds)
            return -1;
        if (y < 2000 || m < 1 || m > 12 || d < 1 || d > 31)
            return -1;

        return DayNumber(y, m, d);
    }

    // Days since 2000-01-01. Built by summing whole years and months rather than
    // with the usual divide-heavy civil-date formula: plain YYYYMMDD subtraction
    // would be wrong across month and year boundaries (1 Sep minus 3 days is 29
    // Aug, not 20260898), and this stays obviously correct without depending on
    // Enforce's integer-division rounding. It runs once per log file at startup.
    // NOTE: written with plain if/else rather than the ternary operator --
    // Enforce rejects a ternary on the right-hand side of a compound assignment
    // ("days += cond ? a : b;" is a broken expression to its parser).
    private static int DayNumber(int y, int m, int d) {
        int days = 0;
        for (int yy = 2000; yy < y; yy++) {
            if (IsLeapYear(yy))
                days += 366;
            else
                days += 365;
        }

        bool leap = IsLeapYear(y);
        if (m > 1)  days += 31;
        if (m > 2) {
            if (leap)
                days += 29;
            else
                days += 28;
        }
        if (m > 3)  days += 31;
        if (m > 4)  days += 30;
        if (m > 5)  days += 31;
        if (m > 6)  days += 30;
        if (m > 7)  days += 31;
        if (m > 8)  days += 31;
        if (m > 9)  days += 30;
        if (m > 10) days += 31;
        if (m > 11) days += 30;

        return days + d;
    }

    private static bool IsLeapYear(int y) {
        if (y % 400 == 0)
            return true;
        if (y % 100 == 0)
            return false;
        return (y % 4 == 0);
    }

    static void Debug(string msg, string category = "") {
        Log(GebsfishLogLevel.DEBUG, msg, category);
    }

    static void Info(string msg, string category = "") {
        Log(GebsfishLogLevel.INFO, msg, category);
    }

    static void Warn(string msg, string category = "") {
        Log(GebsfishLogLevel.WARN, msg, category);
    }

    static void Error(string msg, string category = "") {
        Log(GebsfishLogLevel.ERROR, msg, category);
    }

    // An admin hears of this whatever DebugLogs says: the mod changed their
    // files (merged rows, renames, a new XML to copy) or left them something to
    // do. The RPT always, the Gebs log too when there is one.
    static void Notice(string msg, string category = "") {
        ToRPT(GebsfishLogLevel.INFO, msg, category);
        Log(GebsfishLogLevel.INFO, msg, category);
    }

    private static void ToRPT(GebsfishLogLevel level, string message, string category) {
        string rptLine = "[Gebsfish][" + LevelToString(level) + "] ";
        if (category != string.Empty)
            rptLine += "[" + category + "] ";
        PrintToRPT(rptLine + message);
    }

    static void Log(GebsfishLogLevel level, string message, string category = "") {
        // Warnings and errors also go to the RPT, where admins look first --
        // and where they still land if the Gebs log file can't be written.
        if (level >= GebsfishLogLevel.WARN)
            ToRPT(level, message, category);

        // DebugLogs 0 writes no Gebs log at all, not even the file.
        if (!LoggingOn())
            return;

        if (!m_Initialized)
            Init();

        if (!m_Initialized || m_SessionFilePath == string.Empty)
            return;

        FileHandle file = OpenFile(m_SessionFilePath, FileMode.APPEND);
        if (file == 0)
            return;

        string line = "[" + BuildDateTimeReadable() + "][" + GetExecutionSide() + "][" + LevelToString(level) + "] ";
        if (category != string.Empty)
            line += "[" + category + "] ";

        line += message;

        FPrintln(file, line);
        CloseFile(file);
    }

    private static string GetExecutionSide() {
        if (!g_Game)
            return "UNKNOWN";

        if (g_Game.IsServer())
            return "SERVER";

        return "CLIENT";
    }

    private static string GetWorldNameSafe() {
        string worldName = "empty";

        if (g_Game)
        {
            g_Game.GetWorldName(worldName);
            worldName.ToLower();
        }

        return worldName;
    }

    private static string LevelToString(GebsfishLogLevel level) {
        switch (level)
        {
            case GebsfishLogLevel.DEBUG: return "DEBUG";
            case GebsfishLogLevel.INFO:  return "INFO";
            case GebsfishLogLevel.WARN:  return "WARN";
            case GebsfishLogLevel.ERROR: return "ERROR";
        }

        return "UNKNOWN";
    }

    private static string BuildDateTimeReadable() {
        int year, month, day, hour, minute, second;
        GetYearMonthDayUTC(year, month, day);
        GetHourMinuteSecondUTC(hour, minute, second);

        return Pad4(year) + "-" + Pad2(month) + "-" + Pad2(day) + " " + Pad2(hour) + ":" + Pad2(minute) + ":" + Pad2(second);
    }

    private static string BuildDateTimeCompact() {
        int year, month, day, hour, minute, second;
        GetYearMonthDayUTC(year, month, day);
        GetHourMinuteSecondUTC(hour, minute, second);

        return Pad4(year) + Pad2(month) + Pad2(day) + "-" + Pad2(hour) + Pad2(minute) + Pad2(second);
    }

    private static void EnsureDirectory(string fullPath) {
        if (fullPath == string.Empty)
            return;

        fullPath.Replace("\\", "/");

        while (fullPath.Length() > 0) {
            int lastIndex = fullPath.Length() - 1;
            if (fullPath.Substring(lastIndex, 1) == "/")
                fullPath = fullPath.Substring(0, lastIndex);
            else
                break;
        }

        if (fullPath == string.Empty)
            return;

        int colonIndex = fullPath.IndexOf(":");
        string root = "";
        string rest = fullPath;

        if (colonIndex != -1) {
            root = fullPath.Substring(0, colonIndex + 1);

            int afterColon = colonIndex + 1;
            if (afterColon < fullPath.Length())
                rest = fullPath.Substring(afterColon, fullPath.Length() - afterColon);
            else
                rest = "";

            if (rest.Length() > 0 && rest.Substring(0, 1) == "/")
                rest = rest.Substring(1, rest.Length() - 1);
        }

        TStringArray parts = new TStringArray;
        rest.Split("/", parts);

        string current = root;
        for (int i = 0; i < parts.Count(); i++) {
            string segment = parts.Get(i);
            if (segment == string.Empty || segment == ".")
                continue;

            if (current != string.Empty && current.Substring(current.Length() - 1, 1) != "/")
                current += "/";

            current += segment;
            MakeDirectory(current);
        }
    }

    private static string SanitizeFileNamePart(string value) {
        string result = value;

        result.Replace("\\", "_");
        result.Replace("/", "_");
        result.Replace(":", "_");
        result.Replace("*", "_");
        result.Replace("?", "_");
        result.Replace("\"", "_");
        result.Replace("<", "_");
        result.Replace(">", "_");
        result.Replace("|", "_");
        result.Replace(" ", "_");

        return result;
    }

    static string Pad2(int n) {
        if (n < 10)
            return "0" + n.ToString();

        return n.ToString();
    }

    static string Pad4(int n) {
        string s = n.ToString();

        if (n < 10)
            return "000" + s;

        if (n < 100)
            return "00" + s;

        if (n < 1000)
            return "0" + s;

        return s;
    }
}
