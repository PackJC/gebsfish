modded class PlayerBase extends ManBase
{
    // const int RPC_PLAY_PREDATOR_SOUND = 2757509117; // Unique ID for the predator sound RPC
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        if (rpc_type == RPC_PLAY_PREDATOR_SOUND)
        {
            Param1<string> data;
            if (ctx.Read(data))
            {
                string soundSetName = data.param1;
                EffectSound soundEffect;
                Print("[gebsfish] [PredatorSpawn] Received RPC to play sound: " + soundSetName);
                PlaySoundSet(soundEffect, soundSetName, 0, 0); // Play the sound on the client
            }
        }

        switch(rpc_type)
        {
            case RPC_GEBSCONFIG_SYNC: // this case is for grabbing fishing config from the server
            {
                Param1<gebsfishConfig> configParams;
                if(!ctx.Read(configParams))
                    return;
                SetGebsfishConfig(configParams.param1);
                break;
            }
            Print("[gebsfish] Received config data from server");
        }
    }
}