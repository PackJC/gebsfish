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

	static const string FISHINGTIME_CONFIG_PATH = "$profile:gebsfish/FishingTime.cfg";
	static float fishingtime_float = 3.0;

	static ref map<string, float> fresh_chance_map = new map<string, float>();
	static ref map<string, float> salt_chance_map = new map<string, float>();
	static ref map<string, float> bug_chance_map = new map<string, float>();

	static ref FileReader instance;

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
		bool newFreshFishDetected = false;
		bool newSaltFishDetected = false;

		//Checking if files don't exist first
		if (!FileExist(SALT_CONFIG_PATH))
		{
			//If user doesn't have salt config, they probably need to make a directory; ie new install
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
		if (!FileExist(FISHINGTIME_CONFIG_PATH))
		{
			CreateConfig(FISHINGTIME_CONFIG_PATH);
		}

		//If file exists, open it and read files
		if (FileExist(SALT_CONFIG_PATH))
		{
			FileHandle salt_file = OpenFile(SALT_CONFIG_PATH, FileMode.READ);
			string salt_line;
			while (FGets(salt_file, salt_line) != -1)
			{
				//geb_Bluegill=30 = map["bluegill"] = 30
				salt_line.Trim();
				int tokenIndex = salt_line.IndexOf("=");
				int lengthIndex = salt_line.Length() - tokenIndex;
				salt_chance_map[salt_line.Substring(0, tokenIndex)] = (salt_line.Substring(tokenIndex + 1, lengthIndex - 1)).ToFloat();

			}
			CloseFile(salt_file);

			//This is to force adding new fish, so when server owner updates it should include new fish
			if (salt_chance_map.Contains("geb_MAHIMAHI_CHANCE")) {
				newSaltFishDetected = true;
			}
			if (!newSaltFishDetected) {
				FileHandle salt_file_updater = OpenFile(SALT_CONFIG_PATH, FileMode.APPEND);
				FPrintln(salt_file_updater, "geb_MAHIMAHI_CHANCE=66");
				FPrintln(salt_file_updater, "geb_SAILFISH_CHANCE=66");

			}
			CloseFile(salt_file_updater);
		}
		if (FileExist(FRESH_CONFIG_PATH))
		{
			FileHandle fresh_file = OpenFile(FRESH_CONFIG_PATH, FileMode.READ);
			string fresh_line;
			while (FGets(fresh_file, fresh_line) != -1)
			{
				//geb_Bluegill=30 = map["bluegill"] = 30
				fresh_line.Trim();
				int tokenIndex2 = fresh_line.IndexOf("=");
				int lengthIndex2 = fresh_line.Length() - tokenIndex2;
				string name = salt_line.Substring(0, tokenIndex);

				fresh_chance_map[fresh_line.Substring(0, tokenIndex2)] = (fresh_line.Substring(tokenIndex2 + 1, lengthIndex2 - 1)).ToFloat();
			}
			CloseFile(fresh_file);


			//This is to force adding new fish, so when server owner updates it should include new fish
			if (fresh_chance_map.Contains("geb_SMALLMOUTHBASS_CHANCE")) {
				newFreshFishDetected = true;
			}
			if (!newFreshFishDetected) {
				FileHandle fresh_file_updater = OpenFile(FRESH_CONFIG_PATH, FileMode.APPEND);
				FPrintln(fresh_file_updater, "geb_SMALLMOUTHBASS_CHANCE=66");
				FPrintln(fresh_file_updater, "geb_SUNFISH_CHANCE=66");
				FPrintln(fresh_file_updater, "geb_WALLEYE_CHANCE=66");

			}
			CloseFile(fresh_file_updater);
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
				bug_chance_map[bug_line.Substring(0, tokenIndex4)] = (bug_line.Substring(tokenIndex4 + 1, lengthIndex4 - 1)).ToFloat();
			}
			CloseFile(bug_file);
		}
		if (FileExist(FISHINGTIME_CONFIG_PATH))
		{
			FileHandle fishingtime_file = OpenFile(FISHINGTIME_CONFIG_PATH, FileMode.READ);
			string fishingtime_line;
			while (FGets(fishingtime_file, fishingtime_line) != -1)
			{
				fishingtime_float = fishingtime_line.ToFloat();
			}
			CloseFile(fishingtime_file);
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
			FPrintln(f, "geb_KINGCRAB_CHANCE=41");
			FPrintln(f, "geb_ANGELSHARK_CHANCE=41");
			FPrintln(f, "geb_GREATWHITESHARK_CHANCE=41");
			FPrintln(f, "geb_YELLOWFINTUNA_CHANCE=41");
			FPrintln(f, "geb_MAHIMAHI_CHANCE=41");
			FPrintln(f, "geb_SAILFISH_CHANCE=41");
			break;
		case "$profile:gebsfish/Freshwater.cfg":
			FPrintln(f, "CARP_CHANCE=66");
			FPrintln(f, "geb_CRAYFISH_CHANCE=66");
			FPrintln(f, "geb_BLUEGILL_CHANCE=66");
			FPrintln(f, "geb_BLACKBASS_CHANCE=66");
			FPrintln(f, "geb_CATFISH_CHANCE=66");
			FPrintln(f, "geb_LARGEMOUTHBASS_CHANCE=66");
			FPrintln(f, "geb_SMALLMOUTHBASS_CHANCE=66");
			FPrintln(f, "geb_SUNFISH_CHANCE=66");
			FPrintln(f, "geb_WALLEYE_CHANCE=66");
			FPrintln(f, "geb_MINNOW_CHANCE=66");
			FPrintln(f, "geb_NORTHERNPIKE_CHANCE=66");
			FPrintln(f, "geb_PERCH_CHANCE=66");
			FPrintln(f, "geb_SAUGER_CHANCE=66");
			FPrintln(f, "geb_TROUT_CHANCE=66");
			FPrintln(f, "geb_LAKETROUT_CHANCE=66");
			FPrintln(f, "geb_BROOKTROUT_CHANCE=66");
			FPrintln(f, "geb_BROWNTROUT_CHANCE=66");
			FPrintln(f, "geb_CUTHROATTROUT_CHANCE=66");
			FPrintln(f, "geb_WHITEBASS_CHANCE=66");
			FPrintln(f, "geb_BOWFIN_CHANCE=66");
			FPrintln(f, "geb_SLIMYSCULPIN_CHANCE=66");
			FPrintln(f, "geb_CHINOOKSALMON_CHANCE=66");
			FPrintln(f, "geb_SOCKEYESALMON_CHANCE=66");
			break;
		case "$profile:gebsfish/Bugs.cfg":
			FPrintln(f, "geb_FieldCricket=50");
			FPrintln(f, "geb_GrassHopper=50");
			FPrintln(f, "geb_GrubWorm=50");
			FPrintln(f, "Worm=50");
			break;
		case "$profile:gebsfish/FishingTime.cfg":
			FPrintln(f, "10.0");
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

	static float GetFishingTimeFloat()
	{
		return fishingtime_float;
	}
};