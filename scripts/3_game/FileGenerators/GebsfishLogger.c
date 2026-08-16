enum GebsfishLogLevel {
    DEBUG = 0,
    INFO  = 1,
    WARN  = 2,
    ERROR = 3
};

class GebsfishLogger {
    private static const string LOG_DIR = "$profile:Gebs/logs";
    // Session logs older than this are deleted on startup (see PruneOldLogs).
    // A constant rather than a config field for now -- say the word and it moves
    // into GeneralSettings alongside DebugLogs.
    private static const int LOG_RETENTION_DAYS = 3;
    private static string m_SessionFilePath = "";
    private static GebsfishLogLevel m_MinLevel = GebsfishLogLevel.DEBUG;
    private static bool m_Initialized = false;
    // No session-lifetime handle on purpose. Enforce exposes no flush, so
    // CloseFile is the only thing that commits bytes to disk: opening and
    // closing around each write means a hard crash can never take the tail
    // of the log with it, and it leaves the file unlocked so it can be read
    // or moved while the server is running.

    static void Init(string tag = "gebsfish") {
        if (m_Initialized)
            return;

        EnsureDirectory(LOG_DIR);

        string safeTag = SanitizeFileNamePart(tag);
        if (safeTag == string.Empty)
            safeTag = "gebsfish";

        m_SessionFilePath = LOG_DIR + "/" + BuildDateTimeCompact() + "_" + safeTag + ".log";

        FileHandle file = OpenFile(m_SessionFilePath, FileMode.WRITE);
        if (file == 0) {
            m_SessionFilePath = "";
            return;
        }

        string side = GetExecutionSide();
        string worldName = GetWorldNameSafe();

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
        PruneOldLogs();
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
    private static void PruneOldLogs() {
        int year, month, day;
        GetYearMonthDayUTC(year, month, day);   // filenames are UTC, so compare in UTC
        int today = DayNumber(year, month, day);

        string fileName;
        FileAttr attr;
        FindFileHandle handle = FindFile(LOG_DIR + "/*.log", fileName, attr, FindFileFlags.ALL);
        if (!handle)
            return;

        // Collect first, delete after: mutating a live directory listing risks
        // skipping entries (same reason GebsfishMigration.MoveDirFiles does this).
        array<string> doomed = new array<string>();
        bool more = true;
        while (more) {
            if (fileName != "" && (attr & FileAttr.DIRECTORY) == 0) {
                int fileDay = ParseLogDayNumber(fileName);
                if (fileDay > 0 && (today - fileDay) >= LOG_RETENTION_DAYS)
                    doomed.Insert(fileName);
            }
            more = FindNextFile(handle, fileName, attr);
        }
        CloseFindFile(handle);

        int deleted = 0;
        foreach (string name : doomed) {
            string full = LOG_DIR + "/" + name;
            if (full == m_SessionFilePath)      // never the live session file
                continue;
            if (DeleteFile(full))
                deleted++;
        }

        if (deleted > 0)
            Info("Removed " + deleted + " log file(s) older than " + LOG_RETENTION_DAYS + " days.", "Logs");
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

    // Banner for the top of the log. Deliberately NOT written from Init():
    // the logger initialises lazily on its first write, which happens while
    // the config is still loading, so DebugLogs isn't known yet. The caller
    // (MissionServer.OnInit) fires this once the config is up and only when
    // debug logging is enabled.
    static void WriteBanner() {
        if (!m_Initialized)
            Init();
        if (!m_Initialized || m_SessionFilePath == string.Empty)
            return;

        FileHandle file = OpenFile(m_SessionFilePath, FileMode.APPEND);
        if (file == 0)
            return;
        GebsAsciiArt.Write(file);
        CloseFile(file);
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

    static void Log(GebsfishLogLevel level, string message, string category = "") {
        if (level < m_MinLevel)
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

    // Optional helper in case you ever want to force a new log file per session / reload.
    static void Reset() {
        m_SessionFilePath = "";
        m_Initialized = false;
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
