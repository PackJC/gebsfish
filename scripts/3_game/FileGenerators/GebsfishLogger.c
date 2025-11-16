// File: scripts/3_Game/GebsfishLogger.c

enum GebsfishLogLevel
{
	DEBUG = 0,
	INFO  = 1,
	WARN  = 2,
	ERROR = 3
};

class GebsfishLogger
{
	private static string          m_LogDir          = "$profile:Gebs/Fish/Logs";
	private static string          m_AsciiFile       = "gebsfish/scripts/3_Game/FileGenerators/GebsBanner.txt";
	private static string          m_SessionFilePath = "";
	private static GebsfishLogLevel m_MinLevel        = GebsfishLogLevel.DEBUG;
	private static bool            m_Initialized     = false;

	static void Init(string tag = "gebsfish")
	{
		if (m_Initialized) return;

		EnsureDirectory(m_LogDir);

		string ts = BuildDateTimeCompact();
		m_SessionFilePath = m_LogDir + "/" + ts + "_" + tag + ".log";

		FileHandle fh = OpenFile(m_SessionFilePath, FileMode.WRITE);
		if (fh != 0)
		{
			GebsAsciiArt.Write(fh); //header art

			string side = "UNKNOWN";
            if (g_Game)
            {
                if (g_Game.IsServer())
                    side = "SERVER";
                else
                    side = "CLIENT";
            }

			string worldName = "empty";
			if (g_Game)
			{
				g_Game.GetWorldName(worldName);
				worldName.ToLower();
			}

			// string serverName = "Unknown";
			// if (g_Game)
			// {
			// 	serverName = g_Game.GetHostName();
			// 	GebsfishLogger.Debug("Server Name is: " + serverName + "!!!", "Header");
			// }

			//header info
			FPrintln(fh, "==================== LOGGING SESSION START ====================");
			//FPrintln(fh, "Server: " + serverName); 
			FPrintln(fh, "World: " + worldName);
			FPrintln(fh, "Log Type: " + side);
			FPrintln(fh, "Time: " + BuildDateTimeReadable());
			FPrintln(fh, "File: " + m_SessionFilePath);
            FPrintln(fh, "Gebsfish Version: " + VERSION_GEBSFISH);
			FPrintln(fh, "=======================================================");
			CloseFile(fh);
		}

		m_Initialized = true;
	}

	static void SetMinLevel(GebsfishLogLevel level) { m_MinLevel = level; }
	static void Debug(string msg, string category = "") { Log(GebsfishLogLevel.DEBUG, msg, category); }
	static void Info(string msg, string category = "")  { Log(GebsfishLogLevel.INFO,  msg, category); }
	static void Warn(string msg, string category = "")  { Log(GebsfishLogLevel.WARN,  msg, category); }
	static void Error(string msg, string category = "") { Log(GebsfishLogLevel.ERROR, msg, category); }

	static void Log(GebsfishLogLevel level, string message, string category = "")
	{
		if (!m_Initialized) Init();
		if (level < m_MinLevel) return;

		FileHandle fh = OpenFile(m_SessionFilePath, FileMode.APPEND);
		if (fh == 0) return;

		string ts   = BuildDateTimeReadable();

		string side = "UNKNOWN";
        if (g_Game)
        {
            if (g_Game.IsServer())
                side = "SERVER";
            else
                side = "CLIENT";
        }

		string lvl  = LevelToString(level);

		string cat = "";
        if (category != "")
        {
            cat = "[" + category + "] ";
        }

		FPrintln(fh, "[" + ts + "][" + side + "][" + lvl + "] " + cat + message);
		CloseFile(fh);
	}

	// --- helpers ---
	private static string LevelToString(GebsfishLogLevel level)
	{
		switch (level) {
			case GebsfishLogLevel.DEBUG: return "DEBUG";
			case GebsfishLogLevel.INFO:  return "INFO";
			case GebsfishLogLevel.WARN:  return "WARN";
			case GebsfishLogLevel.ERROR: return "ERROR";
		}
		return "UNKNOWN";
	}

	private static string BuildDateTimeReadable()
    {
        int y, m, d, hh, mm, ss;
        GetYearMonthDayUTC(y, m, d);
        GetHourMinuteSecondUTC(hh, mm, ss);

        string ts = Pad4(y) + "-" + Pad2(m) + "-" + Pad2(d) + " " + Pad2(hh) + ":" + Pad2(mm) + ":" + Pad2(ss);
        return ts;
    }

    private static string BuildDateTimeCompact()
    {
        int y, m, d, hh, mm, ss;
        GetYearMonthDayUTC(y, m, d);
        GetHourMinuteSecondUTC(hh, mm, ss);

        string ts = Pad4(y) + Pad2(m) + Pad2(d) + "-" + Pad2(hh) + Pad2(mm) + Pad2(ss);
        return ts;
    }

	private static void EnsureDirectory(string fullPath)
	{
		if (fullPath == "") return;

		// Normalize backslashes to forward slashes
		fullPath.Replace("\\", "/");

		// Trim trailing slashes
		while (fullPath.Length() > 0)
		{
			int last = fullPath.Length() - 1;
			string lastChar = fullPath.Substring(last, 1);
			if (lastChar == "/")
				fullPath = fullPath.Substring(0, last);
			else
				break;
		}
		if (fullPath == "") return;

		// Separate engine prefix like "$profile:"
		int colon = fullPath.IndexOf(":");
		string root = "";
		string rest = fullPath;
		if (colon != -1)
		{
			root = fullPath.Substring(0, colon + 1); // keep the ':'
			int after = colon + 1;
			if (after < fullPath.Length())
				rest = fullPath.Substring(after, fullPath.Length() - after);
			else
				rest = "";
			if (rest == "") return;

			// Drop leading slash after prefix, if any
			if (rest.Length() > 0 && rest.Substring(0, 1) == "/")
				rest = rest.Substring(1, rest.Length() - 1);
		}

		// Split remaining path and build it one segment at a time
		TStringArray parts = new TStringArray;
		rest.Split("/", parts);

		string current = root; // e.g., "$profile:"
		for (int i = 0; i < parts.Count(); i++)
		{
			string seg = parts.Get(i);
			if (seg == "" || seg == ".") continue;

			if (current != "" && current.Substring(current.Length() - 1, 1) != "/")
				current += "/";

			current += seg;

			// Idempotent: safe if it already exists
			MakeDirectory(current);
		}
	}

    static string Pad2(int n)
    {
        if (n < 10) return "0" + n.ToString();
        return n.ToString();
    }

    static string Pad4(int n)
    {
        string s = n.ToString();
        if (n < 10)   return "000" + s;
        if (n < 100)  return "00"  + s;
        if (n < 1000) return "0"   + s;
        return s;
    }

}
