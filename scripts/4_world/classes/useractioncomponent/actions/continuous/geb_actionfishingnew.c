modded class ActionFishingNew: ActionContinuousBase {

    override void OnEnd(ActionData action_data){
        super.OnEnd(action_data);

        FishingActionData fad;
        if (Class.CastTo(fad, action_data))
        {
            // Animate the rod as a fallback
            fad.AnimateRod(false, true);
            PlayerBase player = fad.m_Player;
            // Check if the fishing result is successful
            if (fad.m_FishingResult == 1) // Assuming 1 indicates success
            {
                TrySpawnPredator(fad);
                string gebcatchtype = fad.m_ContextData.GebGetCatchingResult();
                string gebcatchname = GetDisplayNameFromTypeName(gebcatchtype);
				string gebcatchitem = fad.m_MainItem.GetType();
				string gebcatchitemname = GetDisplayNameFromTypeName(gebcatchitem);
				string gebcatchmessage = "Caught a " + gebcatchname + " with a " + gebcatchitemname;
                Print(gebcatchtype);
                Print(gebcatchname);
				Print(gebcatchitem);
				Print(gebcatchitemname);

                #ifdef ExtraLogs
				if(m_gebsConfig.CFToolsLogging.CatchLogs) {
					SendToCFTools(player, "", "", gebcatchmessage);
				}
                #endif
            }
            else if (Math.RandomFloat(0, 1) <= m_gebsConfig.PredatorSettings.PredatorSpawnChanceFailCatch) // 1% chance to spawn even on failure
            {   
                if(m_gebsConfig.GeneralSettings.DebugLogs){
                    Print("[gebsfish] [Predator] " + m_gebsConfig.PredatorSettings.PredatorSpawnChanceFailCatch +"% random chance triggered. Spawning predator despite no catch.");   
                }
                TrySpawnPredator(fad);
            }
        }
    }

    string GetDisplayNameFromTypeName(string typeName) {

        // Find the display name in the config
        string displayName = "";
        if (GetGame().ConfigIsExisting("CfgVehicles " + typeName))
        {
            displayName = GetGame().ConfigGetTextOut("CfgVehicles " + typeName + " displayName");
        }
        
        // Return display name or fallback to type name if not found
        if (displayName == "")
        {
            return typeName; // Fallback to type name if no display name is found
        }

        return displayName;
    }

    void TrySpawnPredator(FishingActionData action_data){
		if (!GetGame().IsServer() || !m_gebsConfig) return;

		// Check if predator spawning is enabled
		if (!m_gebsConfig.PredatorSettings.PredatorSpawnEnabled)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] Predator spawning is disabled.");
            }
			return;
		}

		// Global spawn chance check
		if (Math.RandomFloat(0, 1) > m_gebsConfig.PredatorSettings.PredatorSpawnChancePreparing)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] Global spawn chance failed.");
            }
			return;
		}

        PlayerBase player = action_data.m_Player;
		vector playerPosition = player.GetPosition();
		if(m_gebsConfig.GeneralSettings.DebugLogs){
            Print("[gebsfish] [Predator] Global spawn chance passed. Selecting predator to spawn.");
        }

		PredatorEntry selectedPredator = GetRandomPredatorEntry();
		if (selectedPredator)
		{
			int count = Math.RandomInt(selectedPredator.MinCount, selectedPredator.MaxCount + 1);
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] Spawning " + count + " " + selectedPredator.Classname + " around player.");
            }

            bool soundPlayed = false; // Initialize sound flag
			for (int i = 0; i < count; i++)
			{
				vector spawnPos = GenerateSpawnPosition(playerPosition, selectedPredator.MinRadius, selectedPredator.MaxRadius);
				SpawnPredator(selectedPredator.Classname, spawnPos, player, soundPlayed);
			}

            //Send message to the player
			if(m_gebsConfig.PredatorSettings.PredatorWarningMessageEnable){
				//Send message to the player in green
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageGreen){
					player.MessageFriendly("Your activities have attracted some company...");
				}
				//Send message to the player in grey
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageGrey){
					player.MessageStatus("Your activities have attracted some company...");
				}
				//Send message to the player in red
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageRed){
					player.MessageImportant("Your activities have attracted some company...");
				}
				//Send message to the player in yellow
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageYellow){
					player.MessageAction("Your activities have attracted some company...");
				}
			}
		}
		else
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] No predator was selected to spawn.");
            }
		}
	}

    PredatorEntry GetRandomPredatorEntry(){
		float totalWeight = 0;
		foreach (PredatorEntry predator1 : m_gebsConfig.Predators)
		{
			totalWeight += predator1.SpawnChance;
		}

		if (totalWeight == 0)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] No predators have valid spawn chances.");
            }
			return null;
		}

		float randomValue = Math.RandomFloat(0, totalWeight);
		float cumulativeWeight = 0;

		foreach (PredatorEntry predator : m_gebsConfig.Predators)
		{
			cumulativeWeight += predator.SpawnChance;
			if (randomValue <= cumulativeWeight)
			{
				return predator;
			}
		}

		return null;
	}

    vector GenerateSpawnPosition(vector center, float minRadius, float maxRadius){
        float angle = Math.RandomFloat(0, 360);
        float distance = Math.RandomFloat(minRadius, maxRadius);
        float xOffset = Math.Cos(angle) * distance;
        float zOffset = Math.Sin(angle) * distance;

        return Vector(center[0] + xOffset, center[1], center[2] + zOffset);
    }

    void SpawnPredator(string classname, vector position, PlayerBase triggeringPlayer, out bool soundPlayed){
		Object predator = GetGame().CreateObject(classname, position, false, true);
		if (predator)
		{

			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] Spawned " + classname + " at " + position.ToString());
            }

            #ifdef ExtraLogs
				if(m_gebsConfig.CFToolsLogging.PredatorSpawn) {
					string gebpredatorspawnmessage = "Predator " + classname + " spawned at " + position.ToString();
					SendToCFTools(triggeringPlayer, "" , "" , gebpredatorspawnmessage);
				}
			#endif
            
			// Send RPC to all players within 50 meters
			if (!soundPlayed && GetGame().IsServer())
			{
				array<Man> players = new array<Man>();
				GetGame().GetPlayers(players);

				foreach (Man player : players)
				{
					PlayerBase nearbyPlayer = PlayerBase.Cast(player);
					if (nearbyPlayer)
					{
						float distance = vector.Distance(triggeringPlayer.GetPosition(), nearbyPlayer.GetPosition());
						if (distance <= m_gebsConfig.PredatorSettings.PredatorWarningSoundRadius) {    // Distance from triggering player
							Param1<string> rpcData = new Param1<string>("PredatorWarning_SoundSet");
							nearbyPlayer.RPCSingleParam(RPC_PLAY_PREDATOR_SOUND, rpcData, true, nearbyPlayer.GetIdentity());
							if(m_gebsConfig.GeneralSettings.DebugLogs){
								Print("[gebsfish] [Predator] Sent RPC to play sound for player within 50 meters of " + triggeringPlayer.GetIdentity().GetName() + ": " + nearbyPlayer.GetIdentity().GetName());
							}
							#ifdef ExtraLogs
                                if(m_gebsConfig.CFToolsLogging.PredatorSounds) {
									string gebpredatorsoundmessage = "Predator sound played for player within 50 meters of " + triggeringPlayer.GetIdentity().GetName();
                                    SendToCFTools(nearbyPlayer , "" , "" , gebpredatorsoundmessage);
                                }
                            #endif
						}
					}
				}

				soundPlayed = true; // Mark the sound as played
			}
		}
		else
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
                Print("[gebsfish] [Predator] Failed to spawn " + classname);
            }
		}
	}

}