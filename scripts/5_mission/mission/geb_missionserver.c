modded class MissionServer
{
	override void OnInit()
	{		
		super.OnInit();
		if(m_gebsConfig){
			Print("[gebsfish] Gebsfish V3.1 Loaded Successfully!");
		}
		
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);

		if(identity){
			//if identity is valid, send config to player. 
			auto configParams = new Param1<gebsfishConfig>(GetGebSettingsConfig());
			Print("[gebsfish] Sending Geb's Fishing config to Player: " + identity.GetName() + " RPC: " + RPC_GEBSCONFIG_SYNC);
			PlayerBase player = PlayerBase.Cast(identity.GetPlayer())
			GetGame().RPCSingleParam(player, RPC_GEBSCONFIG_SYNC, configParams, true, identity);
		}
		
	}

	override void OnGameplayDataHandlerLoad() {
		super.OnGameplayDataHandlerLoad();

		YieldsMap mGeb_YieldsMapAll;
		mGeb_YieldsMapAll = GetGame().GetMission().GetWorldData().GetCatchYieldBank().GetYieldsMap();
		if(m_gebsConfig.GeneralSettings.DebugLogs){
			Print("[gebsfish] [DEBUG] [YieldMapOutput] Start YieldMapAll Dump");
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
				Print("[gebsfish] [DEBUG] [YieldMapOutput] Yield Item " + i + " : " + yItem);
				Print("[gebsfish] [DEBUG] [YieldMapOutput] Yield Item " + i + " Type: " + yItem.GetType());
				Print("[gebsfish] [DEBUG] [YieldMapOutput] Yield Item " + i + " Name: " + GetDisplayNameFromTypeName(yItem.GetType()));
				Print("[gebsfish] [DEBUG] [YieldMapOutput] Yield Item " + i + " Catch Method: " + gebDebugCatchMethod);
				Print("[gebsfish] [DEBUG] [YieldMapOutput] Yield Item " + i + " Catch Environment: " + gebDebugCatchEnviro);
			}

			Print("[gebsfish] [DEBUG] [YieldMapOutput] End YieldMapAll Dump");
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