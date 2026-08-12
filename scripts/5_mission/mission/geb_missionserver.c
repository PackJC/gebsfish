modded class MissionServer {
	override void OnInit() {		
		super.OnInit();
		if(m_gebsConfig) {
			GebsfishLogger.Info("Version " + VERSION_GEBSFISH + " loaded successfully!", "MissionServer Init");
		}

		// RPCs are registered in DayZGame.DeferredInit() so they exist on both client and server.

		gebsfishTypes fishTypesGenerator = new gebsfishTypes();
    	fishTypesGenerator.GenerateTypesXML();
		gebsfishSpawnableTypes fishSpawnableTypesGenerator = new gebsfishSpawnableTypes();
    	fishSpawnableTypesGenerator.GenerateSpawnableTypesXML();
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);

		if(identity) {
			//if identity is valid, send config to player. 
			auto configParams = new Param1<gebsfishConfig>(GetGebSettingsConfig());
			GebsfishLogger.Info("Sending Geb's Fishing config " + VERSION_GEBSFISH + " to Player: " + identity.GetName() + " RPC: ConfigSync", "RPC");
			PlayerBase player = PlayerBase.Cast(identity.GetPlayer());
			GetRPCManager().SendRPC("gebsfish", "ConfigSync", configParams, true, identity, player);
		}
	}

	override void OnGameplayDataHandlerLoad() {
		super.OnGameplayDataHandlerLoad();
		if(GebGetDebugLevel() == ELEVATED_DEBUG){
			// Resolve the yield map only when the dump will actually run,
			// and null-guard each link -- the old unconditional 3-deep chain
			// ran on every load and crashed if any link was null.
			WorldData wd = g_Game.GetMission().GetWorldData();
			if (!wd || !wd.GetCatchYieldBank())
				return;
			YieldsMap mGeb_YieldsMapAll = wd.GetCatchYieldBank().GetYieldsMap();
			if (!mGeb_YieldsMapAll)
				return;
			GebsfishLogger.Debug("Start Dump:","YieldMap");
			YieldItemBase yItem;
			int count = mGeb_YieldsMapAll.Count();
			for (int i = 0; i < count; i++) {
				yItem = mGeb_YieldsMapAll.GetElement(i);
				GebsfishLogger.Debug("Item " + i + " " + yItem + ", Type: " + yItem.GetType() + ", Name: " + GetDisplayNameFromTypeName(yItem.GetType()) + ", Catch Probability Weight: " + yItem.GebGetCatchProbability().ToString() + ", Catch Method: " + GetMethodMaskName(yItem.GetMethodMask()) + ", Catch Environment: " + GetEnviroMaskName(yItem.GetEnviroMask()), "YieldMapItem");
			}
			GebsfishLogger.Debug("End Dump","YieldMap");
		}
	}

	string GetEnviroMaskName(int mask) {
		switch (mask) {
			case 1: return "Pond";
			case 2: return "Sea";
			case 3: return "Pond and Sea";
			case 4: return "Forest";
			case 8: return "Field";
		}
		return "Environment Unknown or Out of Range";
	}

	string GetMethodMaskName(int mask) {
		switch (mask) {
			case 1: return "Rod";
			case 2: return "Large Trap";
			case 3: return "Rod and Large Trap";
			case 4: return "Small Trap";
			case 5: return "Rod and Small Trap";
			case 6: return "Large Trap and Small Trap";
			case 7: return "Rod, Large Trap, and Small Trap";
			case 8: return "Land Trap: Snare";
		}
		return "Catch Method Unknown or Out of Range";
	}

	string GetDisplayNameFromTypeName(string typeName) {

        // Find the display name in the config
        string displayName = "";
        if (g_Game.ConfigIsExisting("CfgVehicles " + typeName)) {
            displayName = g_Game.ConfigGetTextOut("CfgVehicles " + typeName + " displayName");
        }
        
        // Return display name or fallback to type name if not found
        if (displayName == "") {
            return typeName; // Fallback to type name if no display name is found
        }
        return displayName;
    }
}