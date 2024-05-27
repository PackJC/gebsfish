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
	static const string FILLETS_CONFIG_PATH = "$profile:gebsfis/Fillets.cfg";

	static const string DIRECTORY = "$profile:gebsfish";
	
	static ref map<string, string> fillets_chance_map = new map<string, string>();
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
		
		//create gebfish directory
		if (!FileExist(DIRECTORY))
		{
			//If user doesn't have salt config, they probably need to make a directory; ie new install
			MakeDirectory(DIRECTORY);
		}

		//If the folders don't exist, create them
		if (!FileExist(SALT_CONFIG_PATH))
		{
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
		if (!FileExist(FILLETS_CONFIG_PATH))
		{
			CreateConfig(FILLETS_CONFIG_PATH);
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
			//This is to force adding new fish, so when server owner updates it should include new fish
			if (salt_chance_map.Contains("geb_MAHIMAHI_CHANCE")) {
				newSaltFishDetected = true;
			}
			if (!newSaltFishDetected) {
				FPrintln(salt_file, "geb_MAHIMAHI_CHANCE=66");
				FPrintln(salt_file, "geb_SAILFISH_CHANCE=66");

			}
			CloseFile(salt_file);
		}

		//Open fresh fish config if exist
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
			//This is to force adding new fish, so when server owner updates it should include new fish
			if (fresh_chance_map.Contains("geb_SMALLMOUTHBASS_CHANCE")) {
				newFreshFishDetected = true;
			}
			if (!newFreshFishDetected) {
				FPrintln(fresh_file, "geb_SMALLMOUTHBASS_CHANCE=66");
				FPrintln(fresh_file, "geb_SUNFISH_CHANCE=66");
				FPrintln(fresh_file, "geb_WALLEYE_CHANCE=66");
			}
			CloseFile(fresh_file);
		}

		//Open bug config if exist
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

		//If file exists, open it and read files
		if (FileExist(FILLETS_CONFIG_PATH))
		{
			FileHandle fillets_file = OpenFile(FILLETS_CONFIG_PATH, FileMode.READ);
			string fillets_line;
			while (FGets(fillets_file, fillets_line) != -1)
			{
				//geb_Bluegill=30 = map["bluegill"] = 30
				fillets_line.Trim();
				int tokenIndexFillet = fillets_line.IndexOf("=");
				int lengthIndexFillet = fillets_line.Length() - tokenIndexFillet;
				fillets_chance_map[fillets_line.Substring(0, tokenIndexFillet)] = (fillets_line.Substring(tokenIndexFillet + 1, lengthIndexFillet - 1));
			}

			CloseFile(fillets_file);
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
			FPrintln(f, "geb_SEVERUM_CHANCE=41");
			break;
		case "$profile:gebsfish/Bugs.cfg":
			FPrintln(f, "geb_FieldCricket=50");
			FPrintln(f, "geb_GrassHopper=50");
			FPrintln(f, "geb_GrubWorm=50");
			FPrintln(f, "Worm=50");
			break;
		case "$profile:gebsfish/Fillets.cfg":
			FPrintln(f, "CARP_FILLETS=1,4");
			FPrintln(f, "geb_CRAYFISH_FILLETS=1,4");
			FPrintln(f, "geb_BLUEGILL_FILLETS=1,4");
			FPrintln(f, "geb_BLACKBASS_FILLETS=1,4");
			FPrintln(f, "geb_CATFISH_FILLETS=1,4");
			FPrintln(f, "geb_LARGEMOUTHBASS_FILLETS=1,4");
			FPrintln(f, "geb_SMALLMOUTHBASS_FILLETS=1,4");
			FPrintln(f, "geb_SUNFISH_FILLETS=1,4");
			FPrintln(f, "geb_WALLEYE_FILLETS=1,4");
			FPrintln(f, "geb_MINNOW_FILLETS=1,4");
			FPrintln(f, "geb_NORTHERNPIKE_FILLETS=1,4");
			FPrintln(f, "geb_PERCH_FILLETS=1,4");
			FPrintln(f, "geb_SAUGER_FILLETS=1,4");
			FPrintln(f, "geb_TROUT_FILLETS=1,4");
			FPrintln(f, "geb_LAKETROUT_FILLETS=1,4");
			FPrintln(f, "geb_BROOKTROUT_FILLETS=1,4");
			FPrintln(f, "geb_BROWNTROUT_FILLETS=1,4");
			FPrintln(f, "geb_CUTHROATTROUT_FILLETS=1,4");
			FPrintln(f, "geb_WHITEBASS_FILLETS=1,4");
			FPrintln(f, "geb_BOWFIN_FILLETS=1,4");
			FPrintln(f, "geb_SLIMYSCULPIN_FILLETS=1,4");
			FPrintln(f, "geb_CHINOOKSALMON_FILLETS=1,4");
			FPrintln(f, "geb_SOCKEYESALMON_FILLETS=1,4");
			FPrintln(f, "geb_SEVERUM_FILLETS=1,4");
			FPrintln(f, "MACKEREL_FILLETS=1,4");
			FPrintln(f, "geb_ANGELFISH_FILLETS=1,4");
			FPrintln(f, "geb_BLUEMARLIN_FILLETS=1,4");
			FPrintln(f, "geb_BONITA_FILLETS=1,4");
			FPrintln(f, "geb_CHERRYSALMON_FILLETS=1,4");
			FPrintln(f, "geb_FLATHEADMULLET_FILLETS=1,4");
			FPrintln(f, "geb_LEOPARDSHARK_FILLETS=1,4");
			FPrintln(f, "geb_PACIFICCOD_FILLETS=1,4");
			FPrintln(f, "geb_REDHEADCICHLID_FILLETS=1,4");
			FPrintln(f, "geb_ROUGHNECKROCK_FILLETS=1,4");
			FPrintln(f, "geb_SHRIMP_FILLETS=1,4");
			FPrintln(f, "geb_BLUETANG_FILLETS=1,4");
			FPrintln(f, "geb_HAIRTAILFISH_FILLETS=1,4");
			FPrintln(f, "geb_HUMPHEADWRASSE_FILLETS=1,4");
			FPrintln(f, "geb_SIAMESETIGERFISH_FILLETS=1,4");
			FPrintln(f, "geb_ASIANSEABASS_FILLETS=1,4");
			FPrintln(f, "geb_JELLYFISH_FILLETS=1,4");
			FPrintln(f, "geb_STARFISH_FILLETS=1,4");
			FPrintln(f, "geb_KINGCRAB_FILLETS=1,4");
			FPrintln(f, "geb_ANGELSHARK_FILLETS=1,4");
			FPrintln(f, "geb_GREATWHITESHARK_FILLETS=1,4");
			FPrintln(f, "geb_YELLOWFINTUNA_FILLETS=1,4");
			FPrintln(f, "geb_MAHIMAHI_FILLETS=1,4");
			FPrintln(f, "geb_SAILFISH_FILLETS=1,4");
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

	static map<string, string> GetFilletsChanceMap()
	{
		return fillets_chance_map;
	}
};