// Per-cast state the mod adds to vanilla's fishing action data.
modded class FishingActionData {
    // World inputs for this cast's catch math, identical on client and server
    // (see GebFishingSnapshot).
    ref GebFishingSnapshot m_GebSnapshot;
    // Set on the server when the reel-in actually spawned a catch.
    bool m_GebCatchSpawned;
}

modded class FishingActionReceiveData {
    ref GebFishingSnapshot m_GebSnapshot;
}

modded class ActionFishingNew: ActionContinuousBase {
    override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = null) {
        if (!GebCatchConfigReady())
            return false;
        if (!super.SetupAction(player, target, item, action_data, extra_data))
            return false;
        FishingActionData data = FishingActionData.Cast(action_data);
        return data && data.m_ContextData && data.m_ContextData.IsValid();
    }

    // Builds the cast's catching context, on client and server alike. The
    // client (and offline play) reads the world here; on a server,
    // HandleReciveData has already filled in the client's reading -- or the
    // server's own, if the client's didn't match.
    override protected void ComposeLocalContextData(FishingActionData data) {
        if (!data.m_GebSnapshot)
            data.m_GebSnapshot = GebFishingSnapshot.CaptureLocal();
        CatchingContextFishingRodAction.GebSetPendingSnapshot(data.m_GebSnapshot);
        super.ComposeLocalContextData(data);
        CatchingContextFishingRodAction.GebSetPendingSnapshot(null);
    }

    // The snapshot travels with the action start, after vanilla's sea flag.
    override void WriteToContext(ParamsWriteContext ctx, ActionData action_data) {
        super.WriteToContext(ctx, action_data);
        FishingActionData data;
        if (!Class.CastTo(data, action_data))
            return;
        if (!data.m_GebSnapshot)
            data.m_GebSnapshot = GebFishingSnapshot.CaptureLocal();
        data.m_GebSnapshot.Write(ctx);
    }

    override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data) {
        if (!super.ReadFromContext(ctx, action_recive_data))
            return false;
        FishingActionReceiveData received;
        if (!Class.CastTo(received, action_recive_data))
            return false;
        GebFishingSnapshot snapshot = new GebFishingSnapshot();
        if (!snapshot.Read(ctx))
            return false;
        received.m_GebSnapshot = snapshot;
        return true;
    }

    // Server: adopt the client's reading only when it matches the server's own
    // within tolerance, so a modified client can't claim a storm or a better
    // hour. A mismatch can desync that one cast, never cheat it.
    override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data) {
        super.HandleReciveData(action_recive_data, action_data);
        FishingActionData data = FishingActionData.Cast(action_data);
        if (!data)
            return;

        GebFishingSnapshot own = GebFishingSnapshot.CaptureLocal();
        FishingActionReceiveData received = FishingActionReceiveData.Cast(action_recive_data);
        if (received && received.m_GebSnapshot && received.m_GebSnapshot.IsCloseTo(own)) {
            data.m_GebSnapshot = received.m_GebSnapshot;
            return;
        }

        data.m_GebSnapshot = own;
        if (GebGetDebugLevel() >= 1) {
            string clientReading = "none";
            if (received && received.m_GebSnapshot)
                clientReading = received.m_GebSnapshot.Describe();
            GebsfishLogger.Debug("Client cast conditions (" + clientReading + ") don't match the server's (" + own.Describe() + "); using the server's.", "CastSnapshot");
        }
    }

    // Records whether the reel-in actually produced a catch. Vanilla's result
    // flag can't tell: it reports success while the hook is still on the rod,
    // and a hook lost on that same reel-in is only scheduled for deletion (so
    // it still looks attached) while SpawnAndSetupCatch has already refused to
    // spawn anything. Runs where vanilla calls it: the server, or offline.
    override protected EntityAI TrySpawnCatch(FishingActionData action_data) {
        EntityAI caught = super.TrySpawnCatch(action_data);
        if (caught)
            action_data.m_GebCatchSpawned = true;
        return caught;
    }

    override void OnEnd(ActionData action_data){
        super.OnEnd(action_data);

        FishingActionData fad;
        if (!Class.CastTo(fad, action_data))
            return;

        // Vanilla OnEnd already resets the rod animation.

        if (!fad.m_Player || !g_Game.IsServer())
            return;

        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.PredatorSettings)
            return;

        // -1 means no evaluated reel-in (for example, an interrupted cast).
        // Only completed outcomes qualify for predator or treasure rolls.
        if (fad.m_FishingResult != 0 && fad.m_FishingResult != 1)
            return;

        // "Caught" means a catch actually spawned (TrySpawnCatch above), not
        // vanilla's m_FishingResult == 1 -- that is also 1 when the hook was
        // lost on the same reel-in and nothing came up.
        bool caught = fad.m_GebCatchSpawned;

        // Predator spawn chance is split by outcome:
        //   - Caught something -> PredatorSpawnChanceFishing
        //   - Caught nothing   -> PredatorSpawnChanceFailCatch
        // GebsPredatorSpawner.TrySpawn handles the chance roll, predator
        // selection, position search, multi-instance spawning, warning sound
        // RPC, and player chat warning. Caller just picks the right chance.
        float chance;
        if (caught) {
            chance = m_gebsConfig.General.PredatorSettings.PredatorSpawnChanceFishing;
        } else {
            chance = m_gebsConfig.General.PredatorSettings.PredatorSpawnChanceFailCatch;

            if (GebGetDebugLevel() >= 1) {
                GebsfishLogger.Debug("Cast caught nothing; rolling fail-catch predator chance (" + chance + ").", "PredatorSpawnFishing");
            }
        }

        GebsPredatorSpawner.TrySpawn(fad.m_Player, chance, "PredatorSpawnFishing");

        // Ultra-rare treasure, rolled only when something was actually caught --
        // a failed cast shouldn't hand out loot. Deliberately independent of the
        // fish pool: it has its own probability rather than being a yield
        // competing with the 79 species, so tuning it never quietly starves
        // anything else, and it can be set far finer than the catch pool's 0-25
        // integer weights allow.
        if (caught)
            GebsTreasureSpawner.TryPull(fad.m_Player, fad.m_MainItem, "Treasure");
    }
}

// A trap can synchronize before configuration or carry an invalid index.
// Skip cosmetic effects until its yield can be resolved.
modded class TrapSpawnBase {
    override protected void PlayCatchSound(YieldItemBase yItem) {
        if (GebCatchConfigReady() && yItem)
            super.PlayCatchSound(yItem);
    }
    override protected void PlayCatchNoise(YieldItemBase yItem) {
        if (yItem)
            super.PlayCatchNoise(yItem);
    }
    override protected void PlayCatchParticleSynced(YieldItemBase yItem) {
        if (yItem)
            super.PlayCatchParticleSynced(yItem);
    }
}
