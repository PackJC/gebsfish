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
		auto salt_chance_map = FileReader.GetSaltChanceMap();
		auto fresh_chance_map = FileReader.GetFreshChanceMap();


		float rndSaltFish;
		float rndFreshFish;
		float rnd;
		float fresh_sum;
		float salt_sum;

		string selected_salt_fish = "";
		string selected_fresh_fish = "";


		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			ItemBase fish;
			rnd = Math.RandomFloatInclusive(0.0, 1.0);

			if (!m_ActionDataFishing.m_Bait){
				m_ActionDataFishing.InitBait(ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Hook")));
			}
			if (!m_ActionDataFishing.IsBaitEmptyHook())
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
				MiscGameplayFunctions.TurnItemIntoItem(m_ActionDataFishing.m_Bait,m_ActionDataFishing.m_Bait.ConfigGetString("hookType"),m_ActionDataFishing.m_Player);
			}
			else
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
			}
			if (rnd > m_ActionDataFishing.FISHING_GARBAGE_CHANCE)
			{
				//Saltwater cast
				if (m_ActionDataFishing.m_IsSurfaceSea)
				{
                   //Sum of all fish catch chances
					foreach (auto skey, auto svalue : salt_chance_map) {
						salt_sum += svalue;
					}
                    //Generate Random number based on sum of all fish catch chances
					rndSaltFish = Math.RandomFloatInclusive(0.0, salt_sum);
					//Generate Random Fish
					foreach (auto s_key, auto s_value: salt_chance_map) {
						if (rndSaltFish <= s_value && s_value > 0 && s_key.Length() > 2) {
							selected_salt_fish = s_key;
							selected_salt_fish.Replace("_CHANCE", "");
							break;
						}
						rndSaltFish -= s_value;
					}
					//Spawn fish
					fish = ItemBase.Cast(GetGame().CreateObject(selected_salt_fish, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				}
				//Freshwater cast
				else
				{
                   //Sum of all fish catch chances
					foreach (auto fkey, auto fvalue: fresh_chance_map) {
						fresh_sum += fvalue;
					}
                    //Generate Random number based on sum of all fish catch chances
					rndFreshFish = Math.RandomFloatInclusive(0.0, fresh_sum);
					//Generate Random Fish
					foreach (auto f_key, auto f_value: fresh_chance_map) {
						if (rndFreshFish <= f_value && f_value > 0 && f_key.Length() > 2) {
							selected_fresh_fish = f_key;
							selected_fresh_fish.Replace("_CHANCE", "");
							break;
						}
						rndFreshFish -= f_value;
					}
					//Spawn fish
					fish = ItemBase.Cast(GetGame().CreateObject(selected_fresh_fish, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				}
			}
			//Junk catch
			else
			{
				string junk_type = m_JunkTypes.Get(Math.RandomInt(0,m_JunkTypes.Count()));
				fish = ItemBase.Cast(GetGame().CreateObjectEx(junk_type,m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
				fish.SetHealth("","Health",fish.GetMaxHealth("","Health") * 0.1);
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
			m_ActionDataFishing.m_MainItem.AddHealth(0);
		}
	}
};
