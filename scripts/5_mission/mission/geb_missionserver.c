modded class MissionServer {
	override void OnInit() {
		super.OnInit();
		// Banner only when the admin has debug logging on -- a production
		// server's log stays clean. Safe to call here: the config is loaded
		// by now, so GebGetDebugLevel() reports the real setting.
		if (GebGetDebugLevel() > 0) {
			GebsfishLogger.WriteBanner();
		}
		if(m_gebsConfig) {
			GebsfishLogger.Info("Version " + VERSION_GEBSFISH + " loaded successfully!", "MissionServer Init");
		}

		// Clients register the RPCs in DayZGame.DeferredInit, which a
		// dedicated server never runs (it sits on the GUI call queue).
		if (g_Game.IsDedicatedServer())
			GetDayZGame().GebRegisterRPCs();

		GebWarnUnplaceableNetCatches();

		gebsfishTypes fishTypesGenerator = new gebsfishTypes();
		fishTypesGenerator.GenerateTypesXML();
		gebsfishSpawnableTypes fishSpawnableTypesGenerator = new gebsfishSpawnableTypes();
		fishSpawnableTypesGenerator.GenerateSpawnableTypesXML();
		gebsfishEvents fishEventsGenerator = new gebsfishEvents();
		fishEventsGenerator.GenerateEventsXML();
	}

	// Net catches spawn into the net's cargo, which only takes the classes on
	// geb_BambooFishingNet.s_Allowed (containers.c); anything else always
	// lands at the player's feet. Say so once at startup, not silently.
	protected void GebWarnUnplaceableNetCatches() {
		if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.BambooFishingNetSettings || !m_gebsConfig.General.BambooFishingNetSettings.Catches)
			return;

		foreach (NetEntry entry : m_gebsConfig.General.BambooFishingNetSettings.Catches) {
			if (!entry || entry.Classname == "" || entry.CatchChance <= 0)
				continue;
			// The same check the net action makes before spawning a catch.
			if (!geb_FilteredContainerBase.GebTypeMatches(entry.Classname, geb_BambooFishingNet.s_Allowed))
				GebsfishLogger.Warn("Net catch '" + entry.Classname + "' isn't on the net's allow-list (geb_BambooFishingNet in containers.c), so it will always drop at the player's feet instead of going into the net.", "NetConfig");
		}
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);

		if(identity) {
			//if identity is valid, send config to player.
			auto configParams = new Param1<gebsfishConfig>(GetGebSettingsConfig());
			if (GebGetDebugLevel() >= 1)
				GebsfishLogger.Info("Sending Geb's Fishing config " + VERSION_GEBSFISH + " to Player: " + identity.GetName() + " RPC: ConfigSync", "RPC");
			// No target object, as in vanilla's own prepare-time syncs
			// (CfgGameplayHandler.SyncDataSendEx): the client's handler never
			// reads one, and CGame.RPC silently drops an RPC whose target has no
			// network id.
			GetRPCManager().SendRPC("gebsfish", "ConfigSync", configParams, true, identity);
		}
	}

	override void OnGameplayDataHandlerLoad() {
		super.OnGameplayDataHandlerLoad();
		// Vanilla builds the server's world data a second time here, with a
		// new catch list, after MissionBase's two checks ran on the first one:
		// check the list the server keeps (nothing to do while ours is in it).
		GebRepairYieldBank();
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
