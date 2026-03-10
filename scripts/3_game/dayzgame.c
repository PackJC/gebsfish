modded class DayZGame {
    
    void ConfigSync(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
            return;
        
        Param1<gebsfishConfig> configParams;
        if(!ctx.Read(configParams))
            return;
        
        SetGebsfishConfig(configParams.param1);
        GebsfishLogger.Info("Client received config data " + VERSION_GEBSFISH + " from the server.", "RPC");
    }
    
    void PlayPredatorSound(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
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
