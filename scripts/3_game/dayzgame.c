modded class DayZGame
{
    override void DeferredInit()
    {
        super.DeferredInit();

        // Register RPCs with Community Framework - must be done on both client and server
        GetRPCManager().AddRPC("gebsfish", "ConfigSync", this, SingleplayerExecutionType.Client);
        GetRPCManager().AddRPC("gebsfish", "PlayPredatorSound", this, SingleplayerExecutionType.Client);
    }

    void ConfigSync(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        GebsfishLogger.Info("ConfigSync RPC callback called. Type: " + type + ", IsClient: " + g_Game.IsClient(), "RPC");

        if (type != CallType.Client)
        {
            GebsfishLogger.Info("ConfigSync: Not client type, returning.", "RPC");
            return;
        }

        Param1<gebsfishConfig> configParams;
        if (!ctx.Read(configParams))
        {
            GebsfishLogger.Error("ConfigSync: Failed to read configParams from context!", "RPC");
            return;
        }

        GebsfishLogger.Info("ConfigSync: Successfully read configParams, setting config.", "RPC");
        SetGebsfishConfig(configParams.param1);
        GebsfishLogger.Info("Client received config data " + VERSION_GEBSFISH + " from the server.", "RPC");
    }

    void PlayPredatorSound(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type != CallType.Client)
            return;

        Param1<string> data;
        if (!ctx.Read(data))
            return;

        // Use Man instead of PlayerBase since Man is accessible from 3_Game module
        // PlaySoundSet is available on Man/ManBase which PlayerBase extends
        Man player = Man.Cast(target);
        if (!player)
            return;

        string soundSetName = data.param1;
        EffectSound soundEffect;
        GebsfishLogger.Debug("Received RPC to play sound: " + soundSetName + ".", "PredatorSpawnFishingRPC");
        player.PlaySoundSet(soundEffect, soundSetName, 0, 0); // Play the sound on the client
    }
}