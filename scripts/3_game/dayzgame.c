modded class DayZGame {
    
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
        super.OnRPC(sender, target, rpc_type, ctx);
		Event_OnRPC.Invoke(sender, target, rpc_type, ctx);

        if (rpc_type == RPC_GEBSCONFIG_SYNC)
        {
            Param1<gebsfishConfig> configParams;
            if(!ctx.Read(configParams))
            return;
            SetGebsfishConfig(configParams.param1);
            Print("[gebsfish] Client received config data from the server.");
        }
    }
}
