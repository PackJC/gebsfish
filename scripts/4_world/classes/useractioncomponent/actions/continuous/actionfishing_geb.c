class FileReader
{
	static const string SALT_CONFIG_PATH = "$profile:gebsfish/SaltwaterCfg.cfg";
	static const string TRAP_CONFIG_PATH = "$profile:TrapCfg.cfg";
	static const string BUG_CONFIG_PATH = "$profile:BugCfg.cfg";
	static const string WORM_CONFIG_PATH = "$profile:WormCfg.cfg";
	static const string FRESH_CONFIG_PATH = "$profile:FreshwaterCfg.cfg";
	static const string DIRECTORY = "$profile:gebsfish.txt";

	static ref map<string, float> fresh_chance_map = new map<string, float>();	//15 fish
	static ref map<string, float> salt_chance_map = new map<string, float>();	//21 fish
	static ref map<string, float> trap_chance_map = new map<string, float>();	//? fish
	static ref map<string, float> bug_chance_map = new map<string, float>();	//2 bug
	static ref map<string, float> worm_chance_map = new map<string, float>();	//2 worm

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


		if (!FileExist(DIRECTORY))
		{
			Print("[gebsfish] NOT FOUND: SaltwaterCfg.cfg ");
			Print("[gebsfish] CREATING FILE: SaltwaterCfg.cfg");
			CreateConfig(DIRECTORY);
		}

		if (!FileExist(SALT_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: SaltwaterCfg.cfg ");
			Print("[gebsfish] CREATING FILE: SaltwaterCfg.cfg");
			CreateConfig(SALT_CONFIG_PATH);
		}
		if (!FileExist(FRESH_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: FreshwaterCfg.cfg ");
			Print("[gebsfish] CREATING FILE: FreshwaterCfg.cfg");
			CreateConfig(FRESH_CONFIG_PATH);
		}
		if (!FileExist(TRAP_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: TrapCfg.cfg ");
			Print("[gebsfish] CREATING FILE: TrapCfg.cfg");
			CreateConfig(TRAP_CONFIG_PATH);
		}
		if (!FileExist(BUG_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: BugCfg.cfg ");
			Print("[gebsfish] CREATING FILE: BugCfg.cfg");
			CreateConfig(BUG_CONFIG_PATH);
		}
		if (!FileExist(WORM_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: WormCfg.cfg ");
			Print("[gebsfish] CREATING FILE: WormCfg.cfg");
			CreateConfig(WORM_CONFIG_PATH);
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
				//string name = salt_line.Substring(0, tokenIndex);
				int lengthIndex = salt_line.Length() - tokenIndex;
				//string value = salt_line.Substring(tokenIndex + 1, lengthIndex - 1);

				//string to float here

				salt_chance_map[salt_line.Substring(0, tokenIndex)] = (salt_line.Substring(tokenIndex + 1, lengthIndex - 1)).ToFloat();

			}
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

		if (FileExist(TRAP_CONFIG_PATH))
		{
			FileHandle trap_file = OpenFile(TRAP_CONFIG_PATH, FileMode.READ);
			string trap_line;
			while (FGets(trap_file, trap_line) != -1)
			{
				trap_line.Trim(); //Removes remaining whitespaces
				int tokenIndex3 = trap_line.IndexOf("=");
				int lengthIndex3 = trap_line.Length() - tokenIndex3;
				trap_chance_map[trap_line.Substring(0, tokenIndex3)] = (trap_line.Substring(tokenIndex3 + 1, lengthIndex3 - 1)).ToFloat();
			}
			CloseFile(trap_file);
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

		if (FileExist(WORM_CONFIG_PATH))
		{
			FileHandle worm_file = OpenFile(WORM_CONFIG_PATH, FileMode.READ);
			string worm_line;
			while (FGets(worm_file, worm_line) != -1)
			{
				worm_line.Trim(); //Removes remaining whitespaces
				int tokenIndex5 = worm_line.IndexOf("=");
				int lengthIndex5 = worm_line.Length() - tokenIndex5;
				worm_chance_map[worm_line.Substring(0, tokenIndex5)] = (worm_line.Substring(tokenIndex5 + 1, lengthIndex5 - 1)).ToFloat();
			}
			CloseFile(worm_file);
		}

		
	}

	// Creates the config file and sets default values.
	void CreateConfig(string CONFIG_PATH)
	{
			FileHandle f = OpenFile(CONFIG_PATH, FileMode.WRITE);
			CloseFile(f);
	}
	static string BetterTrim(string line)
	{
		line.Replace("	", ""); // Replace Tabs("\t" or "	") with nothing.
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

	//Get fish weighted chance
	static map<string, float> GetSaltChanceMap()
	{
		return salt_chance_map;
	}

	//Set fish weighted chance
	void SetFreshFishMap(string key, float val)
	{
		salt_chance_map.Set(key, val);
	}

};





















modded class ActionFishingNewCB : ActionContinuousBaseCB
{
	
	override void HandleFishingResultSuccess()
	{
		float rndSaltFish;
		float rndFreshFish;
		float rnd;
		float fresh_sum;
		float salt_sum;
		string selected_salt_fish = "";
		string selected_fresh_fish = "";

		//Saltwater Fish Chances
		float MACKEREL_CHANCE = 0;
		float ANGELFISH_CHANCE = 0;
		float BLUEMARLIN_CHANCE = 0;
		float BONITA_CHANCE = 0;
		float CHERRYSALMON_CHANCE = 0;
		float FLATHEADMULLET_CHANCE = 0;
		float LEOPARDSHARK_CHANCE = 0;
		float PACIFICCOD_CHANCE = 0;
		float REDHEADCICHLID_CHANCE = 0;
		float ROUGHNECKROCK_CHANCE = 0;
		float SEVERUM_CHANCE = 0;
		float SHRIMP_CHANCE = 0;
		float BLUETANG_CHANCE = 0;
		float HAIRTAILFISH_CHANCE = 0;
		float HUMPHEADWRASSE_CHANCE = 0;
		float SIAMESETIGERFISH_CHANCE = 0;
		float ASIANSEABASS_CHANCE = 0;
		float JELLYFISH_CHANCE = 0;
		float STARFISH_CHANCE = 0;
		float BLOODCLAM_CHANCE = 0;
		float KINGCRAB_CHANCE = 0;

		//Freshwater Fish Chances
		float CARP_CHANCE = 25;
		float CRAYFISH_CHANCE = 25;
		float BLUEGILL_CHANCE = 25;
		float BLACKBASS_CHANCE = 25;
		float CATFISH_CHANCE = 25;
		float LARGEMOUTHBASS_CHANCE = 25;
		float MINNOW_CHANCE = 25;
		float NORTHERNPIKE_CHANCE = 25;
		float PERCH_CHANCE = 25;
		float SAUGER_CHANCE = 25;
		float TROUT_CHANCE = 25;
		float WHITEBASS_CHANCE = 25;
		float BOWFIN_CHANCE = 25;
		float SLIMYSCULPIN_CHANCE = 25;
		float MUSSEL_CHANCE = 25;

		auto salt_chance_map = FileReader.GetSaltChanceMap();



		auto fresh_fish_map = new map<string, float>();	//15 fish
		auto salt_fish_map = new map<string, float>();	//21 fish

		//Freshwater Fish Chance
		fresh_fish_map["Carp"]= CARP_CHANCE;
		fresh_fish_map["Crayfish"] = CRAYFISH_CHANCE;
		fresh_fish_map["Bluegill"] = BLUEGILL_CHANCE;
		fresh_fish_map["Blackbass"] = BLACKBASS_CHANCE;
		fresh_fish_map["Catfish"] = CATFISH_CHANCE;
		fresh_fish_map["Largemouthbass"] = LARGEMOUTHBASS_CHANCE;
		fresh_fish_map["Minnow"] = MINNOW_CHANCE;
		fresh_fish_map["Northernpike"] = NORTHERNPIKE_CHANCE;
		fresh_fish_map["Perch"] = PERCH_CHANCE;
		fresh_fish_map["Sauger"] = SAUGER_CHANCE;
		fresh_fish_map["Trout"] = TROUT_CHANCE;
		fresh_fish_map["Whitebass"] = WHITEBASS_CHANCE;
		fresh_fish_map["Bowfin"] = BOWFIN_CHANCE;
		fresh_fish_map["Slimysculpin"] = SLIMYSCULPIN_CHANCE;
		fresh_fish_map["Mussel"] = MUSSEL_CHANCE;

		//Saltwater Fish Chance
		salt_fish_map["Mackerel"] = MACKEREL_CHANCE;
		salt_fish_map["Angelfish"] = ANGELFISH_CHANCE;
		salt_fish_map["Bluemarlin"] = BLUEMARLIN_CHANCE;
		salt_fish_map["Bonita"] = BONITA_CHANCE;
		salt_fish_map["Cherrysalmon"] = CHERRYSALMON_CHANCE;
		salt_fish_map["Flatheadmullet"] = FLATHEADMULLET_CHANCE;
		salt_fish_map["Leopardshark"] = LEOPARDSHARK_CHANCE;
		salt_fish_map["Pacificcod"] = PACIFICCOD_CHANCE;
		salt_fish_map["Redheadcichlid"] = REDHEADCICHLID_CHANCE;
		salt_fish_map["Roughneckrock"] = ROUGHNECKROCK_CHANCE;
		salt_fish_map["Severum"] = SEVERUM_CHANCE;
		salt_fish_map["Shrimp"] = SHRIMP_CHANCE;
		salt_fish_map["Bluetang"] = BLUETANG_CHANCE;
		salt_fish_map["Hairtailfish"] = HAIRTAILFISH_CHANCE;
		salt_fish_map["Humpheadwrasse"] = HUMPHEADWRASSE_CHANCE;
		salt_fish_map["Siamesetigerfish"] = SIAMESETIGERFISH_CHANCE;
		salt_fish_map["Asianseabass"] = ASIANSEABASS_CHANCE;
		salt_fish_map["Jellyfish"] = JELLYFISH_CHANCE;
		salt_fish_map["Starfish"] = STARFISH_CHANCE;
		salt_fish_map["Bloodclam"] = BLOODCLAM_CHANCE;
		salt_fish_map["Kingcrab"] = KINGCRAB_CHANCE;

		if (salt_chance_map.Count() > 0) {
			salt_fish_map = salt_chance_map;

		}

		Print("[gebsfish] salt_fish_map " + salt_fish_map);
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			ItemBase fish;
			
			rnd = Math.RandomFloatInclusive(0.0, 1.0);

			if (!m_ActionDataFishing.m_Bait)
				m_ActionDataFishing.InitBait(ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Hook")));
			
			if (!m_ActionDataFishing.IsBaitEmptyHook())
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
				MiscGameplayFunctions.TurnItemIntoItem(m_ActionDataFishing.m_Bait,m_ActionDataFishing.m_Bait.ConfigGetString("hookType"),m_ActionDataFishing.m_Player);
			}
			else
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
			}

			//Saltwater Calculate Total Weight
			foreach (auto skey, auto svalue : salt_fish_map) {
				salt_sum += svalue;
			}
			//Freshwater Calculate Total Weight
			foreach (auto fkey, auto fvalue: fresh_fish_map) {
				fresh_sum += fvalue;
			}

			rndSaltFish = Math.RandomFloatInclusive(0.0, salt_sum);
			rndFreshFish = Math.RandomFloatInclusive(0.0, fresh_sum);

			foreach (auto s_key, auto s_value: salt_fish_map) {
				if (rndSaltFish <= s_value && s_value > 0) {
					selected_salt_fish = s_key;
					break;
				}
				rndSaltFish -= s_value;
			}

			foreach (auto f_key, auto f_value: fresh_fish_map) {
				if (rndFreshFish <= f_value && f_value > 0) {
					selected_fresh_fish = f_key;
					break;
				}
				rndFreshFish -= f_value;
			}


			if (rnd > m_ActionDataFishing.FISHING_GARBAGE_CHANCE)
			{
				//If Saltwater
				if (m_ActionDataFishing.m_IsSurfaceSea)
				{
					fish = ItemBase.Cast(GetGame().CreateObject(selected_salt_fish, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				}
				//If Freshwater
				else
				{
					fish = ItemBase.Cast(GetGame().CreateObject(selected_fresh_fish, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				}
			}
			else
			{
				if ( !m_ActionDataFishing.m_IsSurfaceSea )
				{
					string junk_type = m_JunkTypes.Get(Math.RandomInt(0,m_JunkTypes.Count()));
					fish = ItemBase.Cast(GetGame().CreateObjectEx(junk_type,m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
					fish.SetHealth("","Health",fish.GetMaxHealth("","Health") * 0.1);
				}
			}
			
			if (fish)
			{
				fish.SetWet(0.3);
				if (fish.HasQuantity())
				{
					float coef = Math.RandomFloatInclusive(1.0, 1.0);
					float item_quantity = fish.GetQuantityMax() * coef;
					item_quantity = Math.Round(item_quantity);
					fish.SetQuantity( item_quantity );
				}
			}
			
			//Set to zero for compatability with traders
			m_ActionDataFishing.m_MainItem.AddHealth(-0);
		}
	}
};

