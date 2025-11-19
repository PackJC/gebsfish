modded class PrepareFish {
    override void Init() {
		super.Init();
		m_RecipeUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
        GetGebSettingsConfig();
		//----------------------------------------------------------------------------------------------------------------------
		//Ingredient 2
		InsertIngredient(1,"geb_BlueFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
		InsertIngredient(1,"geb_OrangeFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
		InsertIngredient(1,"geb_GreenFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
		InsertIngredient(1,"geb_YellowFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
		InsertIngredient(1,"geb_RedFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
		InsertIngredient(1,"geb_PurpleFishKnife",DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING);
    }

    //Called upon recipe's completion
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight){
		// Adjusts quantity of results to the quantity of the 1st ingredient
		super.Do(ingredients, player, results, specialty_weight);
        // Trigger predator spawning
		TrySpawnPredator(player);
	}

    void TrySpawnPredator(PlayerBase player){
		if (!g_Game.IsServer() || !m_gebsConfig) return;

		// Check if predator spawning is enabled
		if (!m_gebsConfig.PredatorSettings.PredatorSpawnEnabled)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
				GebsfishLogger.Debug("Predator spawning is disabled in the config file.", "PredatorSpawnPrepare");
            }
			return;
		}

		// Global spawn chance check
		if (Math.RandomFloat(0, 1) > m_gebsConfig.PredatorSettings.PredatorSpawnChancePreparing)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
				GebsfishLogger.Debug("Global spawn chance for predator failed.", "PredatorSpawnPrepare");
            }
			return;
		}

		vector playerPosition = player.GetPosition();
		if(m_gebsConfig.GeneralSettings.DebugLogs){
			GebsfishLogger.Debug("Global Spawn chance for predator succeeded. Selecting predator from config to spawn.", "PredatorSpawnPrepare");
        }

		PredatorEntry selectedPredator = GetRandomPredatorEntry();
		if (selectedPredator)
		{
			int count = Math.RandomInt(selectedPredator.MinCount, selectedPredator.MaxCount + 1);
			if(m_gebsConfig.GeneralSettings.DebugLogs){
				GebsfishLogger.Debug("Spawning " + count + " " + selectedPredator.Classname + " around player.", "PredatorSpawnPrepare");
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
					player.MessageFriendly(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in grey
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageGrey){
					player.MessageStatus(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in red
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageRed){
					player.MessageImportant(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in yellow
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageYellow){
					player.MessageAction(Widget.TranslateString("#STR_action_predatorspawn"));
				}
			}
		}
		else
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
				GebsfishLogger.Debug("No predator was selected to spawn.", "PredatorSpawnPrepare");
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
				GebsfishLogger.Debug("No predators have a valid spawn chance.", "PredatorSpawnPrepare");
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
		Object predator = g_Game.CreateObject(classname, position, false, true);
		if (predator)
		{
			if(m_gebsConfig.GeneralSettings.DebugLogs){
				GebsfishLogger.Debug("Spawned " + classname + " at " + position.ToString() + ".", "PredatorSpawnPrepare");;
            }

			#ifdef ExtraLogs
				if(m_gebsConfig.CFToolsLogging.PredatorSpawn) {
					string gebpredatorspawnmessage = "Predator " + classname + " spawned at " + position.ToString();
					SendToCFTools(triggeringPlayer, "" , "" , gebpredatorspawnmessage);
				}
			#endif
            
			// Send RPC to all players within 50 meters
			if (!soundPlayed && g_Game.IsServer())
			{
				array<Man> players = new array<Man>();
				g_Game.GetPlayers(players);

				foreach (Man player : players)
				{
					PlayerBase nearbyPlayer = PlayerBase.Cast(player);
					if (nearbyPlayer)
					{
						float distance = vector.Distance(triggeringPlayer.GetPosition(), nearbyPlayer.GetPosition());
						if (distance <= m_gebsConfig.PredatorSettings.PredatorWarningSoundRadius) {    // Distance from triggering player
							Param1<string> rpcData = new Param1<string>("PredatorWarning_SoundSet");
							nearbyPlayer.RPCSingleParam(GebsfishRPC.PLAYPREDATORSOUND, rpcData, true, nearbyPlayer.GetIdentity());
							if(m_gebsConfig.GeneralSettings.DebugLogs){
								GebsfishLogger.Debug("Sent RPC to play sound for players within " + m_gebsConfig.PredatorSettings.PredatorWarningSoundRadius + " meters of " + triggeringPlayer.GetIdentity().GetName() + ": " + nearbyPlayer.GetIdentity().GetName() + ".", "PredatorSpawnPrepareRPC");
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
				GebsfishLogger.Debug("Failed to spawn " + classname + ".", "PredatorSpawnPrepare");
            }
		}
	}
}
