modded class PlayerBase extends ManBase
{
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        if (rpc_type == GebsfishRPC.PLAYPREDATORSOUND)
        {
            Param1<string> data;
            if (ctx.Read(data))
            {
                string soundSetName = data.param1;
                EffectSound soundEffect;
                GebsfishLogger.Debug("Received RPC to play sound: " + soundSetName + ".", "PredatorSpawnFishingRPC");
                PlaySoundSet(soundEffect, soundSetName, 0, 0); // Play the sound on the client
            }
        }

    }
}