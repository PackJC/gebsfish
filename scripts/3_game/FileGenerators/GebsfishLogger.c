enum GebsfishLogLevel {
    DEBUG = 0,
    INFO  = 1,
    WARN  = 2,
    ERROR = 3
};

class GebsfishLogger {
    private static const string LOG_DIR = "$profile:Gebs/logs";
    private static string m_SessionFilePath = "";
    private static GebsfishLogLevel m_MinLevel = GebsfishLogLevel.DEBUG;
    private static bool m_Initialized = false;
    // Session-lifetime handle. Kept open on purpose: at elevated debug a
    // single cast can emit hundreds of lines, and an open/append/close
    // round-trip per line stalls the server main thread. The OS closes the
    // handle at process exit; Reset() closes it for an explicit new session.
    private static FileHandle m_File = 0;

    static void Init(string tag = "gebsfish") {
        if (m_Initialized)
            return;

        EnsureDirectory(LOG_DIR);

        string safeTag = SanitizeFileNamePart(tag);
        if (safeTag == string.Empty)
            safeTag = "gebsfish";

        m_SessionFilePath = LOG_DIR + "/" + BuildDateTimeCompact() + "_" + safeTag + ".log";

        m_File = OpenFile(m_SessionFilePath, FileMode.WRITE);
        if (m_File == 0) {
            m_SessionFilePath = "";
            return;
        }

        string side = GetExecutionSide();
        string worldName = GetWorldNameSafe();

        FPrintln(m_File, "==================== LOGGING SESSION START ====================");
        FPrintln(m_File, "World: " + worldName);
        FPrintln(m_File, "Log Type: " + side);
        FPrintln(m_File, "Time: " + BuildDateTimeReadable());
        FPrintln(m_File, "File: " + m_SessionFilePath);
        FPrintln(m_File, "Gebsfish Version: " + VERSION_GEBSFISH);
        FPrintln(m_File, "===============================================================");

        m_Initialized = true;
    }

    static void SetMinLevel(GebsfishLogLevel level) {
        m_MinLevel = level;
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

        if (!m_Initialized || m_File == 0)
            return;

        string line = "[" + BuildDateTimeReadable() + "][" + GetExecutionSide() + "][" + LevelToString(level) + "] ";
        if (category != string.Empty)
            line += "[" + category + "] ";

        line += message;

        FPrintln(m_File, line);
    }

    // Optional helper in case you ever want to force a new log file per session / reload.
    static void Reset() {
        if (m_File != 0)
            CloseFile(m_File);
        m_File = 0;
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
