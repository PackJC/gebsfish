/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

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
		float KINGCRAB_CHANCE = 0;
		float ANGELSHARK_CHANCE = 0;
		float GREATWHITESHARK_CHANCE = 0;
		float YELLOWFINTUNA_CHANCE = 0;

		//Freshwater Fish Chances
		float CARP_CHANCE = 0;
		float CRAYFISH_CHANCE = 0;
		float BLUEGILL_CHANCE = 0;
		float BLACKBASS_CHANCE = 0;
		float CATFISH_CHANCE = 0;
		float LARGEMOUTHBASS_CHANCE = 0;
		float MINNOW_CHANCE = 0;
		float NORTHERNPIKE_CHANCE = 0;
		float PERCH_CHANCE = 0;
		float SAUGER_CHANCE = 0;
		float TROUT_CHANCE = 0;

		float BROWNTROUT_CHANCE = 0;
		float BROOKTROUT_CHANCE = 0;
		float LAKETROUT_CHANCE = 0;
		float CUTTHROATTROUT_CHANCE = 0;




		float WHITEBASS_CHANCE = 0;
		float BOWFIN_CHANCE = 0;
		float SLIMYSCULPIN_CHANCE = 0;

		auto salt_chance_map = FileReader.GetSaltChanceMap();
		auto fresh_chance_map = FileReader.GetFreshChanceMap();



		auto fresh_fish_map = new map<string, float>();	//15 fish
		auto salt_fish_map = new map<string, float>();	//21 fish

		//Freshwater Fish Chance
		fresh_fish_map["Carp"]= CARP_CHANCE;
		fresh_fish_map["geb_Crayfish"] = CRAYFISH_CHANCE;
		fresh_fish_map["geb_Bluegill"] = BLUEGILL_CHANCE;
		fresh_fish_map["geb_Blackbass"] = BLACKBASS_CHANCE;
		fresh_fish_map["geb_Catfish"] = CATFISH_CHANCE;
		fresh_fish_map["geb_Largemouthbass"] = LARGEMOUTHBASS_CHANCE;
		fresh_fish_map["geb_Minnow"] = MINNOW_CHANCE;
		fresh_fish_map["geb_Northernpike"] = NORTHERNPIKE_CHANCE;
		fresh_fish_map["geb_Perch"] = PERCH_CHANCE;
		fresh_fish_map["geb_Sauger"] = SAUGER_CHANCE;
		fresh_fish_map["geb_Trout"] = TROUT_CHANCE;

		fresh_fish_map["geb_BrownTrout"] = BROWNTROUT_CHANCE;
		fresh_fish_map["geb_BrookTrout"] = BROOKTROUT_CHANCE;
		fresh_fish_map["geb_LakeTrout"] = LAKETROUT_CHANCE;
		fresh_fish_map["geb_CutthroatTrout"] = CUTTHROATTROUT_CHANCE;


		fresh_fish_map["geb_Whitebass"] = WHITEBASS_CHANCE;
		fresh_fish_map["geb_Bowfin"] = BOWFIN_CHANCE;
		fresh_fish_map["geb_Slimysculpin"] = SLIMYSCULPIN_CHANCE;

		//Saltwater Fish Chance
		salt_fish_map["Mackerel"] = MACKEREL_CHANCE;
		salt_fish_map["geb_Angelfish"] = ANGELFISH_CHANCE;
		salt_fish_map["geb_Bluemarlin"] = BLUEMARLIN_CHANCE;
		salt_fish_map["geb_Bonita"] = BONITA_CHANCE;
		salt_fish_map["geb_Cherrysalmon"] = CHERRYSALMON_CHANCE;
		salt_fish_map["geb_Flatheadmullet"] = FLATHEADMULLET_CHANCE;
		salt_fish_map["geb_Leopardshark"] = LEOPARDSHARK_CHANCE;
		salt_fish_map["geb_Pacificcod"] = PACIFICCOD_CHANCE;
		salt_fish_map["geb_Redheadcichlid"] = REDHEADCICHLID_CHANCE;
		salt_fish_map["geb_Roughneckrock"] = ROUGHNECKROCK_CHANCE;
		salt_fish_map["geb_Severum"] = SEVERUM_CHANCE;
		salt_fish_map["geb_Shrimp"] = SHRIMP_CHANCE;
		salt_fish_map["geb_Bluetang"] = BLUETANG_CHANCE;
		salt_fish_map["geb_Hairtailfish"] = HAIRTAILFISH_CHANCE;
		salt_fish_map["geb_Humpheadwrasse"] = HUMPHEADWRASSE_CHANCE;
		salt_fish_map["geb_Siamesetigerfish"] = SIAMESETIGERFISH_CHANCE;
		salt_fish_map["geb_Asianseabass"] = ASIANSEABASS_CHANCE;
		salt_fish_map["geb_Jellyfish"] = JELLYFISH_CHANCE;
		salt_fish_map["geb_Starfish"] = STARFISH_CHANCE;
		salt_fish_map["geb_Kingcrab"] = KINGCRAB_CHANCE;
		salt_fish_map["geb_Angelshark"] = ANGELSHARK_CHANCE;
		salt_fish_map["geb_Greatwhiteshark"] = GREATWHITESHARK_CHANCE;
		salt_fish_map["geb_Yellowfintuna"] = YELLOWFINTUNA_CHANCE;

		if (salt_chance_map.Count() > 0) {
			salt_fish_map = salt_chance_map;

		}
		if (fresh_chance_map.Count() > 0) {
			fresh_fish_map = fresh_chance_map;

		}

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

			//Added equal past s_value in last arg
			foreach (auto s_key, auto s_value: salt_fish_map) {
				if (rndSaltFish <= s_value && s_value > 0) {
					selected_salt_fish = s_key;
					selected_salt_fish.Replace("_CHANCE", "");
					break;
				}
				rndSaltFish -= s_value;
			}

			foreach (auto f_key, auto f_value: fresh_fish_map) {
				if (rndFreshFish <= f_value && f_value > 0) {
					selected_fresh_fish = f_key;
					selected_fresh_fish.Replace("_CHANCE", "");

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