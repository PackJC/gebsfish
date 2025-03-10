modded class MissionServer
{
	override void OnInit()
	{		
		super.OnInit();
		if(m_gebsConfig){
			Print("[gebsfish] Gebsfish V3.0 Loaded Successfully!");
		}
		
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);
		auto configParams = new Param1<gebsfishConfig>(GetGebSettingsConfig());
		Print("Sending Geb's Fishing config to Player: " + identity.GetName() + " RPC: " + RPC_GEBSCONFIG_SYNC);
		GetGame().RPCSingleParam(player, RPC_GEBSCONFIG_SYNC, configParams, true, identity);
	}
}