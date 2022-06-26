/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class FileReader
{
	static const string FRESH_CONFIG_PATH = "$profile:gebsfish/Freshwater.cfg";
	static const string SALT_CONFIG_PATH = "$profile:gebsfish/Saltwater.cfg";
	static const string BUG_CONFIG_PATH = "$profile:gebsfish/Bugs.cfg";

	static const string DIRECTORY = "$profile:gebsfish";

	static ref map<string, float> fresh_chance_map = new map<string, float>();
	static ref map<string, float> salt_chance_map = new map<string, float>();
	static ref map<string, float> bug_chance_map = new map<string, float>();

	private static ref FileReader instance;

	void FileReader()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			LoadFiles();
		}
	}

	static FileReader GetInstance()
	{
		if (!instance) instance = new FileReader;
		return instance;
	}

	void LoadFiles()
	{

		if (!FileExist(SALT_CONFIG_PATH))
		{
			MakeDirectory(DIRECTORY);
			CreateConfig(SALT_CONFIG_PATH);
		}
		if (!FileExist(FRESH_CONFIG_PATH))
		{
			CreateConfig(FRESH_CONFIG_PATH);
		}
		if (!FileExist(BUG_CONFIG_PATH))
		{
			CreateConfig(BUG_CONFIG_PATH);
		}




		if (FileExist(SALT_CONFIG_PATH))
		{
			FileHandle salt_file = OpenFile(SALT_CONFIG_PATH, FileMode.READ);
			string salt_line;
			while (FGets(salt_file, salt_line) != -1)
			{
				/// <summary>
				/// Bluegill=30 turns to name=bluegill and value=30
				/// </summary>
				salt_line.Trim(); //Removes remaining whitespaces
				int tokenIndex = salt_line.IndexOf("=");
				int lengthIndex = salt_line.Length() - tokenIndex;
				salt_chance_map[salt_line.Substring(0, tokenIndex)] = (salt_line.Substring(tokenIndex + 1, lengthIndex - 1)).ToFloat();

			}

			//if saltchancemap doesnt have fish then add line to map

			CloseFile(salt_file);
		}

		if (FileExist(FRESH_CONFIG_PATH))
		{
			FileHandle fresh_file = OpenFile(FRESH_CONFIG_PATH, FileMode.READ);
			string fresh_line;
			while (FGets(fresh_file, fresh_line) != -1)
			{
				fresh_line.Trim(); //Removes remaining whitespaces
				int tokenIndex2 = fresh_line.IndexOf("=");
				int lengthIndex2 = fresh_line.Length() - tokenIndex2;
				fresh_chance_map[fresh_line.Substring(0, tokenIndex2)] = (fresh_line.Substring(tokenIndex2 + 1, lengthIndex2 - 1)).ToFloat();
			}
			CloseFile(fresh_file);
		}

		if (FileExist(BUG_CONFIG_PATH))
		{
			FileHandle bug_file = OpenFile(BUG_CONFIG_PATH, FileMode.READ);
			string bug_line;
			while (FGets(bug_file, bug_line) != -1)
			{
				bug_line.Trim(); //Removes remaining whitespaces
				int tokenIndex4 = bug_line.IndexOf("=");
				int lengthIndex4 = bug_line.Length() - tokenIndex4;
				bug_chance_map[fresh_line.Substring(0, tokenIndex4)] = (bug_line.Substring(tokenIndex4 + 1, lengthIndex4 - 1)).ToFloat();
			}
			CloseFile(fresh_file);
		}
	}

	// Creates the config file and sets default values.
	void CreateConfig(string CONFIG_PATH)
	{
		FileHandle f = OpenFile(CONFIG_PATH, FileMode.WRITE);
		switch (CONFIG_PATH) {
		case "$profile:gebsfish/Saltwater.cfg":
			FPrintln(f, "MACKEREL_CHANCE=41");
			FPrintln(f, "geb_ANGELFISH_CHANCE=41");
			FPrintln(f, "geb_BLUEMARLIN_CHANCE=41");
			FPrintln(f, "geb_BONITA_CHANCE=41");
			FPrintln(f, "geb_CHERRYSALMON_CHANCE=41");
			FPrintln(f, "geb_FLATHEADMULLET_CHANCE=41");
			FPrintln(f, "geb_LEOPARDSHARK_CHANCE=41");
			FPrintln(f, "geb_PACIFICCOD_CHANCE=41");
			FPrintln(f, "geb_REDHEADCICHLID_CHANCE=41");
			FPrintln(f, "geb_ROUGHNECKROCK_CHANCE=41");
			FPrintln(f, "geb_SEVERUM_CHANCE=41");
			FPrintln(f, "geb_SHRIMP_CHANCE=41");
			FPrintln(f, "geb_BLUETANG_CHANCE=41");
			FPrintln(f, "geb_HAIRTAILFISH_CHANCE=41");
			FPrintln(f, "geb_HUMPHEADWRASSE_CHANCE=41");
			FPrintln(f, "geb_SIAMESETIGERFISH_CHANCE=41");
			FPrintln(f, "geb_ASIANSEABASS_CHANCE=41");
			FPrintln(f, "geb_JELLYFISH_CHANCE=41");
			FPrintln(f, "geb_STARFISH_CHANCE=41");
			FPrintln(f, "geb_BLOODCLAM_CHANCE=41");
			FPrintln(f, "geb_KINGCRAB_CHANCE=41");
			FPrintln(f, "geb_ANGELSHARK_CHANCE=41");
			FPrintln(f, "geb_GREATWHITESHARK_CHANCE=41");
			FPrintln(f, "geb_YELLOWFINTUNA_CHANCE=41");
			break;
		case "$profile:gebsfish/Freshwater.cfg":
			FPrintln(f, "CARP_CHANCE=25");
			FPrintln(f, "geb_CRAYFISH_CHANCE=66");
			FPrintln(f, "geb_BLUEGILL_CHANCE=66");
			FPrintln(f, "geb_BLACKBASS_CHANCE=66");
			FPrintln(f, "geb_CATFISH_CHANCE=66");
			FPrintln(f, "geb_LARGEMOUTHBASS_CHANCE=66");
			FPrintln(f, "geb_MINNOW_CHANCE=66");
			FPrintln(f, "geb_NORTHERNPIKE_CHANCE=66");
			FPrintln(f, "geb_PERCH_CHANCE=66");
			FPrintln(f, "geb_SAUGER_CHANCE=66");
			FPrintln(f, "geb_TROUT_CHANCE=66");

			FPrintln(f, "geb_TROUT_CHANCE=66");
			FPrintln(f, "geb_LAKETROUT_CHANCE=66");
			FPrintln(f, "geb_BROOKTROUT_CHANCE=66");
			FPrintln(f, "geb_BROWNTROUT_CHANCE=66");
			FPrintln(f, "geb_CUTHROATTROUT_CHANCE=66");

			FPrintln(f, "geb_WHITEBASS_CHANCE=66");
			FPrintln(f, "geb_BOWFIN_CHANCE=66");
			FPrintln(f, "geb_SLIMYSCULPIN_CHANCE=66");
			FPrintln(f, "geb_MUSSEL_CHANCE=66");
			break;
		case "$profile:gebsfish/Bugs.cfg":
			FPrintln(f, "geb_FieldCricket=333");
			FPrintln(f, "geb_GrassHopper=333");
			FPrintln(f, "geb_GrubWorm=333");
			break;
		}
		CloseFile(f);
	}

	static string BetterTrim(string line)
	{
		line.Replace("	", ""); // Replace Tabs("/t" or "	") with nothing.
		line.Replace(";", "");
		line.Trim(); //Removes remaining whitespaces

		bool hasSpaces = true;
		while (hasSpaces)
		{
			line = line.Trim();

			if (line.Length() > 0)
				hasSpaces = line.Get(0) == " " || line.Get(line.Length() - 1) == " ";
			else
				hasSpaces = false;
		}

		return line;
	}

	static map<string, float> GetSaltChanceMap()
	{
		return salt_chance_map;
	}

	static map<string, float> GetFreshChanceMap()
	{
		return fresh_chance_map;
	}

	static map<string, float> GetBugChanceMap()
	{
		return bug_chance_map;
	}
};