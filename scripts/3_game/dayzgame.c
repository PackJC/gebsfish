modded class DayZGame {
    
    override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
        super.OnRPC(sender, target, rpc_type, ctx);

        if (rpc_type == GebsfishRPC.CONFIGSYNC)
        {
            Param1<gebsfishConfig> configParams;
            if(!ctx.Read(configParams))
            return;
            SetGebsfishConfig(configParams.param1);
            GebsfishLogger.Info("Client received config data " + VERSION_GEBSFISH + " from the server.", "RPC");
        }
    }
}
