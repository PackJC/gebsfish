modded class PrepareFish {
    // Vanilla baseline so the knife-speed multiplier never compounds across CanDo calls.
    protected float m_BaseAnimationLength;

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

		m_BaseAnimationLength = m_AnimationLength;
    }

    // Recalculated every CanDo so swapping knives mid-session always reflects the
    // current tool, and so the multiplier scales from the vanilla baseline (never compounds).
    override bool CanDo(ItemBase ingredients[], PlayerBase player) {
		ApplyFishKnifeSpeedBonus(ingredients);
		return super.CanDo(ingredients, player);
	}

    void ApplyFishKnifeSpeedBonus(ItemBase ingredients[]) {
		float multiplier = 1.0;
		if (m_gebsConfig && m_gebsConfig.GeneralSettings)
			multiplier = m_gebsConfig.GeneralSettings.FishKnifeSpeedMultiplier;

		if (multiplier <= 0)
			multiplier = 1.0;

		if (ingredients[1] && ingredients[1].IsKindOf("geb_FishKnife_Base"))
			m_AnimationLength = m_BaseAnimationLength * multiplier;
		else
			m_AnimationLength = m_BaseAnimationLength;
	}

    //Called upon recipe's completion
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) {
		// Adjusts quantity of results to the quantity of the 1st ingredient
		super.Do(ingredients, player, results, specialty_weight);
        // Trigger predator spawning
		TrySpawnPredator(player);
	}

    void TrySpawnPredator(PlayerBase player) {
		if (!g_Game.IsServer() || !m_gebsConfig || !player) return;

		int debugLogs = 0;
		if (m_gebsConfig.GeneralSettings)
			debugLogs = m_gebsConfig.GeneralSettings.DebugLogs;

		if (!m_gebsConfig.PredatorSettings) {
			if(debugLogs) {
				GebsfishLogger.Debug("PredatorSettings config is missing. Skipping predator spawn.", "PredatorSpawnPrepare");
            }
			return;
		}

		// Check if predator spawning is enabled
		if (!m_gebsConfig.PredatorSettings.PredatorSpawnEnabled) {
			if(debugLogs) {
				GebsfishLogger.Debug("Predator spawning is disabled in the config file.", "PredatorSpawnPrepare");
            }
			return;
		}

		// Global spawn chance check
		if (Math.RandomFloat(0, 1) > m_gebsConfig.PredatorSettings.PredatorSpawnChancePreparing) {
			if(debugLogs) {
				GebsfishLogger.Debug("Global spawn chance for predator failed.", "PredatorSpawnPrepare");
            }
			return;
		}

		vector playerPosition = player.GetPosition();
		if(debugLogs) {
			GebsfishLogger.Debug("Global Spawn chance for predator succeeded. Selecting predator from config to spawn.", "PredatorSpawnPrepare");
        }

		PredatorEntry selectedPredator = GetRandomPredatorEntry();
		if (selectedPredator) {
			int minCount = selectedPredator.MinCount;
			int maxCount = selectedPredator.MaxCount;
			if (minCount < 0)
				minCount = 0;
			if (maxCount < 0)
				maxCount = 0;
			if (maxCount < minCount)
				maxCount = minCount;

			int count = Math.RandomInt(minCount, maxCount + 1);
			if(debugLogs) {
				GebsfishLogger.Debug("Spawning " + count + " " + selectedPredator.Classname + " around player.", "PredatorSpawnPrepare");
            }

            bool soundPlayed = false; // Initialize sound flag
			for (int i = 0; i < count; i++) {
				vector spawnPos = GenerateSpawnPosition(playerPosition, selectedPredator.MinRadius, selectedPredator.MaxRadius);
				SpawnPredator(selectedPredator.Classname, spawnPos, player, soundPlayed);
			}

            //Send message to the player
			if(m_gebsConfig.PredatorSettings.PredatorWarningMessageEnable) {
				//Send message to the player in green
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageGreen) {
					player.MessageFriendly(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in grey
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageGrey) {
					player.MessageStatus(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in red
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageRed) {
					player.MessageImportant(Widget.TranslateString("#STR_action_predatorspawn"));
				}
				//Send message to the player in yellow
				if(m_gebsConfig.PredatorSettings.PredatorWarningMessageYellow) {
					player.MessageAction(Widget.TranslateString("#STR_action_predatorspawn"));
				}
			}
		}
		else {
			if(debugLogs) {
				GebsfishLogger.Debug("No predator was selected to spawn.", "PredatorSpawnPrepare");
            }
		}
	}

	PredatorEntry GetRandomPredatorEntry() {
		if (!m_gebsConfig)
			return null;

		int debugLogs = 0;
		if (m_gebsConfig.GeneralSettings)
			debugLogs = m_gebsConfig.GeneralSettings.DebugLogs;

		if (!m_gebsConfig.Predators || m_gebsConfig.Predators.Count() == 0) {
			if(debugLogs) {
				GebsfishLogger.Debug("No predators are configured.", "PredatorSpawnPrepare");
            }
			return null;
		}

		float totalWeight = 0;
		foreach (PredatorEntry predator1 : m_gebsConfig.Predators) {
			if (!predator1 || predator1.Classname == "" || predator1.SpawnChance <= 0)
				continue;

			totalWeight += predator1.SpawnChance;
		}

		if (totalWeight <= 0) {
			if(debugLogs) {
				GebsfishLogger.Debug("No predators have a valid spawn chance.", "PredatorSpawnPrepare");
            }
			return null;
		}

		float randomValue = Math.RandomFloat(0, totalWeight);
		float cumulativeWeight = 0;

		foreach (PredatorEntry predator : m_gebsConfig.Predators) {
			if (!predator || predator.Classname == "" || predator.SpawnChance <= 0)
				continue;

			cumulativeWeight += predator.SpawnChance;
			if (randomValue <= cumulativeWeight) {
				return predator;
			}
		}

		return null;
	}

	vector GenerateSpawnPosition(vector center, float minRadius, float maxRadius) {
		vector spawnPos;
		if (minRadius < 0)
			minRadius = 0;
		if (maxRadius < 0)
			maxRadius = 0;
		if (maxRadius < minRadius)
			maxRadius = minRadius;

		float angle = Math.RandomFloat(0, 360);
		float distance = Math.RandomFloat(minRadius, maxRadius);
		float xOffset = Math.Cos(angle) * distance;
		float zOffset = Math.Sin(angle) * distance;

		spawnPos = Vector(center[0] + xOffset, center[1], center[2] + zOffset);

		int attempts = 0;
		const int maxAttempts = 20;

		// Preparing fish can happen right next to water.
		// The old code accepted the first random position, so predators could spawn
		// out in the sea or a pond. This retry loop keeps sampling nearby positions
		// until it finds land, matching the fishing predator behavior.
		while ((g_Game.SurfaceIsSea(spawnPos[0], spawnPos[2]) || g_Game.SurfaceIsPond(spawnPos[0], spawnPos[2])) && attempts < maxAttempts) {
			if( m_gebsConfig && m_gebsConfig.GeneralSettings && ELEVATED_DEBUG == m_gebsConfig.GeneralSettings.DebugLogs ) {
				GebsfishLogger.Debug("Surface selected for spawning predator was over water. Selecting new location for spawning predator.", "PredatorSpawnPrepare");
            }

			angle = Math.RandomFloat(0, 360);
			distance = Math.RandomFloat(minRadius, maxRadius);
			xOffset = Math.Cos(angle) * distance;
			zOffset = Math.Sin(angle) * distance;

			spawnPos = Vector(center[0] + xOffset, center[1], center[2] + zOffset);
			attempts++;
		}

		// If all attempts hit water, return the last point so the action never hangs.
		// The debug log makes that fallback visible during testing.
		if (m_gebsConfig && m_gebsConfig.GeneralSettings && m_gebsConfig.GeneralSettings.DebugLogs && attempts >= maxAttempts) {
			GebsfishLogger.Debug("Warning: Max attempts reached while trying to find a land spawn position.", "PredatorSpawnPrepare");
		}

		return spawnPos;
	}

	void SpawnPredator(string classname, vector position, PlayerBase triggeringPlayer, out bool soundPlayed) {
		if (!m_gebsConfig || !triggeringPlayer || classname == "")
			return;

		Object predator = g_Game.CreateObject(classname, position, false, true);
		if (predator) {
			if(m_gebsConfig.GeneralSettings && m_gebsConfig.GeneralSettings.DebugLogs) {
				GebsfishLogger.Debug("Spawned " + classname + " at " + position.ToString() + ".", "PredatorSpawnPrepare");;
            }

			#ifdef ExtraLogs
				if(m_gebsConfig.CFToolsLogging && m_gebsConfig.CFToolsLogging.PredatorSpawn) {
					string gebpredatorspawnmessage = "Predator " + classname + " spawned at " + position.ToString();
					SendToCFTools(triggeringPlayer, "" , "" , gebpredatorspawnmessage);
				}
			#endif
            
			// Send RPC to nearby players when warning sounds are enabled.
			if (m_gebsConfig.PredatorSettings && m_gebsConfig.PredatorSettings.PredatorWarningSoundEnable && !soundPlayed && g_Game.IsServer()) {
				PlayerIdentity triggeringIdentity = triggeringPlayer.GetIdentity();
				string triggeringPlayerName = "unknown player";

				// Logs and CFTools messages only need a readable name. If the player who
				// triggered the predator disconnects at the wrong moment, keep the sound
				// loop working and use a safe fallback name instead of calling GetName()
				// on a null identity.
				if (triggeringIdentity) {
					triggeringPlayerName = triggeringIdentity.GetName();
				}

				array<Man> players = new array<Man>();
				g_Game.GetPlayers(players);

				foreach (Man player : players) {
					PlayerBase nearbyPlayer = PlayerBase.Cast(player);
					if (nearbyPlayer) {
						PlayerIdentity nearbyIdentity = nearbyPlayer.GetIdentity();

						// The warning sound RPC is sent to a player identity.
						// If someone disconnects during this loop, PlayerBase can still cast
						// successfully while its identity is already gone, so skip that player
						// instead of sending the RPC or debug log through a null identity.
						if (!nearbyIdentity) {
							continue;
						}

						float distance = vector.Distance(triggeringPlayer.GetPosition(), nearbyPlayer.GetPosition());
						if (distance <= m_gebsConfig.PredatorSettings.PredatorWarningSoundRadius) {    // Distance from triggering player
							Param1<string> rpcData = new Param1<string>("PredatorWarning_SoundSet");
							GetRPCManager().SendRPC("gebsfish", "PlayPredatorSound", rpcData, true, nearbyIdentity, nearbyPlayer);
							if(m_gebsConfig.GeneralSettings && m_gebsConfig.GeneralSettings.DebugLogs) {
								GebsfishLogger.Debug("Sent RPC to play sound for players within " + m_gebsConfig.PredatorSettings.PredatorWarningSoundRadius + " meters of " + triggeringPlayerName + ": " + nearbyIdentity.GetName() + ".", "PredatorSpawnPrepareRPC");
							}
							#ifdef ExtraLogs
                                if(m_gebsConfig.CFToolsLogging && m_gebsConfig.CFToolsLogging.PredatorSounds) {
									string gebpredatorsoundmessage = "Predator sound played for player within 50 meters of " + triggeringPlayerName;
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
			if(m_gebsConfig.GeneralSettings && m_gebsConfig.GeneralSettings.DebugLogs) {
				GebsfishLogger.Debug("Failed to spawn " + classname + ".", "PredatorSpawnPrepare");
            }
		}
	}
}
