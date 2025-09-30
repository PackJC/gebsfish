modded class MissionServer
{
	override void OnInit()
	{		
		super.OnInit();
		if(m_gebsConfig){
			GebsfishLogger.Info("Version " + VERSION_GEBSFISH + " loaded successfully!", "MissionServer Init");
		}

		gebsfishTypes fishTypesGenerator = new gebsfishTypes();
    	fishTypesGenerator.GenerateTypesXML();
		gebsfishSpawnableTypes fishSpawnableTypesGenerator = new gebsfishSpawnableTypes();
    	fishSpawnableTypesGenerator.GenerateSpawnableTypesXML();
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);

		if(identity){
			//if identity is valid, send config to player. 
			auto configParams = new Param1<gebsfishConfig>(GetGebSettingsConfig());
			GebsfishLogger.Info("Sending Geb's Fishing config " + VERSION_GEBSFISH + " to Player: " + identity.GetName() + " RPC: " + GebsfishRPC.CONFIGSYNC, "RPC");
			PlayerBase player = PlayerBase.Cast(identity.GetPlayer());
			GetGame().RPCSingleParam(player, GebsfishRPC.CONFIGSYNC, configParams, true, identity);
		}
		
	}

	override void OnGameplayDataHandlerLoad() {
		super.OnGameplayDataHandlerLoad();

		YieldsMap mGeb_YieldsMapAll;
		mGeb_YieldsMapAll = GetGame().GetMission().GetWorldData().GetCatchYieldBank().GetYieldsMap();
		if(m_gebsConfig.GeneralSettings.DebugLogs == ELEVATED_DEBUG){
			GebsfishLogger.Debug("Start Dump:","YieldMap");
			YieldItemBase yItem;
			int count = mGeb_YieldsMapAll.Count();
			for (int i = 0; i < count; i++){
				yItem = mGeb_YieldsMapAll.GetElement(i);
				string gebDebugCatchMethod;
				string gebDebugCatchEnviro;
				switch(yItem.GetEnviroMask()) {
					case 1:
						gebDebugCatchEnviro = "Pond";
						break;
					case 2: 
						gebDebugCatchEnviro = "Sea";
						break;
					case 3: 
						gebDebugCatchEnviro = "Pond and Sea";
						break;
					case 4: 
						gebDebugCatchEnviro = "Forest";
						break;
					case 8:
						gebDebugCatchEnviro = "Field";
						break;
					default: 
						gebDebugCatchEnviro = "Environment Unknown or Out of Range";
						break;
				}
				switch(yItem.GetMethodMask()) {
					case 1:
						gebDebugCatchMethod = "Rod";
						break;
					case 2: 
						gebDebugCatchMethod = "Large Trap";
						break;
					case 3: 
						gebDebugCatchMethod = "Rod and Large Trap";
						break;
					case 4:
						gebDebugCatchMethod = "Small Trap";
						break;
					case 5: 
						gebDebugCatchMethod = "Rod and Small Trap";
						break;
					case 6: 
						gebDebugCatchMethod = "Large Trap and Small Trap";
						break;
					case 7: 
						gebDebugCatchMethod = "Rod, Large Trap, and Small Trap";
						break;
					case 8:
						gebDebugCatchMethod = "Land Trap: Snare";
						break;
					default: 
						gebDebugCatchMethod = "Catch Method Unknown or Out of Range";
						break;
				}

				// GebsfishLogger.Debug("Yield Item " + i + " : " + yItem,"YieldMap");
				// GebsfishLogger.Debug("Yield Item " + i + " Type: " + yItem.GetType(),"YieldMap");
				// GebsfishLogger.Debug("Yield Item " + i + " Name: " + GetDisplayNameFromTypeName(yItem.GetType()),"YieldMap");
				// GebsfishLogger.Debug("Yield Item " + i + " Catch Probability Weight: " + yItem.GebGetCatchProbability().ToString(),"YieldMap");
				// GebsfishLogger.Debug("Yield Item " + i + " Catch Method: " + gebDebugCatchMethod,"YieldMap");
				// GebsfishLogger.Debug("Yield Item " + i + " Catch Environment: " + gebDebugCatchEnviro,"YieldMap");

				GebsfishLogger.Debug( "Item " + i + " " + yItem + ", Type: " + yItem.GetType() + ", Name: " + GetDisplayNameFromTypeName(yItem.GetType()) + ", Catch Probability Weight: " + yItem.GebGetCatchProbability().ToString() + ", Catch Method: " + gebDebugCatchMethod + ", Catch Environment: " + gebDebugCatchEnviro, "YieldMapItem");

			}
			GebsfishLogger.Debug("End Dump","YieldMap");
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
}
