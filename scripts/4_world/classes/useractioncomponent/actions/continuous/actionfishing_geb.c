class FileReader
{
	static const string SALT_CONFIG_PATH = "$profile:gebsfish/SaltwaterCfg.cfg";
	static const string TRAP_CONFIG_PATH = "$profile:gebsfish/TrapCfg.cfg";
	static const string BUG_CONFIG_PATH = "$profile:gebsfish/BugCfg.cfg";
	static const string WORM_CONFIG_PATH = "$profile:gebsfish/WormCfg.cfg";
	static const string FRESH_CONFIG_PATH = "$profile:gebsfish/FreshwaterCfg.cfg";
	static const string DIRECTORY = "$profile:gebsfish";

	static auto fresh_chance_map = new map<string, float>();	//15 fish
	static auto salt_chance_map = new map<string, float>();	//21 fish
	static auto trap_chance_map = new map<string, float>();	//? fish
	static auto bug_chance_map = new map<string, float>();	//2 bug
	static auto worm_chance_map = new map<string, float>();	//2 worm

	private const float MACKEREL_CHANCE = 0.5;
	private const float MACKEREL_CHANCE = 0;
	private const float ANGELFISH_CHANCE = 0;
	private const float BLUEMARLIN_CHANCE = 0;
	private const float BONITA_CHANCE = 0;
	private const float CHERRYSALMON_CHANCE = 0;
	private const float FLATHEADMULLET_CHANCE = 0;
	private const float LEOPARDSHARK_CHANCE = 0;
	private const float PACIFICCOD_CHANCE = 0;
	private const float REDHEADCICHLID_CHANCE = 0;
	private const float ROUGHNECKROCK_CHANCE = 0;
	private const float SEVERUM_CHANCE = 0;
	private const float SHRIMP_CHANCE = 0;
	private const float BLUETANG_CHANCE = 0;
	private const float HAIRTAILFISH_CHANCE = 0;
	private const float HUMPHEADWRASSE_CHANCE = 0;
	private const float SIAMESETIGERFISH_CHANCE = 0;
	private const float ASIANSEABASS_CHANCE = 0;
	private const float JELLYFISH_CHANCE = 0;
	private const float STARFISH_CHANCE = 0;
	private const float BLOODCLAM_CHANCE = 0;
	private const float KINGCRAB_CHANCE = 0;



	void FileReader()
	{

		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			LoadFromConfigFile();
		}
	}

	static FileReader GetInstance()
	{
		if (!instance) instance = new FileReader;
		return instance;
	}

	void LoadFromConfigFile()
	{
		if (FileExist(SALT_CONFIG_PATH))
		{
			FileHandle file = OpenFile(SALT_CONFIG_PATH, FileMode.READ);
			string line;
			while (FGets(file, line) != -1)
			{
				line.BetterTrim(); //Removes remaining whitespaces
				//BLUEGILL=30
				//create map here maybe or up above
				line.Split("=", tokens);

				//add to map here

			}
			CloseFile(file);
		}
		
		if (!FileExist(SALT_CONFIG_PATH))
		{
			Print("[gebsfish] NOT FOUND: SaltwaterCfg.cfg ");
			Print("[gebsfish] CREATING FILE: SaltwaterCfg.cfg");
			CreateConfig();
		}
	}

	// Creates the config file and sets default values.
	void CreateConfig()
	{
		bool success = MakeDirectory(DIRECTORY);
		if (success)
		{
			FileHandle f = OpenFile(CONFIG_PATH, FileMode.WRITE);
			array<string> sortedKeys = m_LessFishing_Vals.GetKeyArray();
			sortedKeys.Sort();

			foreach(string key : sortedKeys)
			{
				FPrintln(f, key + "=" + m_LessFishing_Vals.Get(key));
			}

			CloseFile(f);
		}
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
	map<string, float> GetFreshFishMap()
	{
		return FreshFishMap;
	}

	//Set fish weighted chance
	void SetFreshFishMap(string key, float val)
	{
		FreshFishMap.Set(key, val);
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

