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
		float MACKEREL_CHANCE = 25;
		float ANGELFISH_CHANCE = 25;
		float BLUEMARLIN_CHANCE = 25;
		float BONITA_CHANCE = 25;
		float CHERRYSALMON_CHANCE = 25;
		float FLATHEADMULLET_CHANCE = 25;
		float LEOPARDSHARK_CHANCE = 25;
		float PACIFICCOD_CHANCE = 25;
		float REDHEADCICHLID_CHANCE = 25;
		float ROUGHNECKROCK_CHANCE = 25;
		float SEVERUM_CHANCE = 25;
		float SHRIMP_CHANCE = 25;
		float BLUETANG_CHANCE = 25;
		float HAIRTAILFISH_CHANCE = 25;
		float HUMPHEADWRASSE_CHANCE = 25;
		float SIAMESETIGERFISH_CHANCE = 25;
		float ASIANSEABASS_CHANCE = 25;
		float JELLYFISH_CHANCE = 25;
		float STARFISH_CHANCE = 25;
		float BLOODCLAM_CHANCE = 25;
		float KINGCRAB_CHANCE = 25;

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

