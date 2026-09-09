modded class DayZGame {
    override void DeferredInit() {
        super.DeferredInit();

        // Register RPCs with Community Framework - must be done on both client and server
        GetRPCManager().AddRPC("gebsfish", "ConfigSync", this, SingleplayerExecutionType.Client);
        GetRPCManager().AddRPC("gebsfish", "PlayPredatorSound", this, SingleplayerExecutionType.Client);
    }

    void ConfigSync(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
        GebsfishLogger.Info("ConfigSync RPC callback called. Type: " + type + ", IsClient: " + g_Game.IsClient(), "RPC");

        if (type != CallType.Client) {
            GebsfishLogger.Info("ConfigSync: Not client type, returning.", "RPC");
            return;
        }

        Param1<gebsfishConfig> configParams;
        if (!ctx.Read(configParams)) {
            GebsfishLogger.Error("ConfigSync: Failed to read configParams from context!", "RPC");
            return;
        }

        // Don't overwrite with an empty/garbled payload -- keep whatever the
        // client already has (defaults) rather than nulling the config and
        // crashing the catch math.
        if (!configParams || !configParams.param1 || !configParams.param1.General || !configParams.param1.Fish || !configParams.param1.Bait || !configParams.param1.Junk) {
            GebsfishLogger.Error("ConfigSync: received an incomplete config payload -- ignoring it (client keeps current values).", "RPC");
            return;
        }

        GebsfishLogger.Info("ConfigSync: Successfully read configParams, setting config.", "RPC");
        SetGebsfishConfig(configParams.param1);
        g_GebConfigReceived = true;
        GebGetConfigReadyInvoker().Invoke();
        GebsfishLogger.Info("Client received config data " + VERSION_GEBSFISH + " from the server.", "RPC");
    }

    void PlayPredatorSound(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
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
// Shared across script layers; refresh only this mod's bank listener on config sync.
ref ScriptInvoker g_GebConfigReadyInvoker;

static ScriptInvoker GebGetConfigReadyInvoker() {
    if (!g_GebConfigReadyInvoker)
        g_GebConfigReadyInvoker = new ScriptInvoker();
    return g_GebConfigReadyInvoker;
}

bool g_GebConfigReceived;
ref CatchYieldBank g_GebYieldBank;

static bool GebCatchConfigReady() {
    return g_Game.IsServer() || !g_Game.IsMultiplayer() || g_GebConfigReceived;
}

modded class CatchYieldBank {
    protected ref array<ref YieldItemBase> m_GebEntries;
    protected ref array<ref YieldItemBase> m_GebSuffix;
    protected int m_GebStart;
    protected int m_GebEnd;
    protected bool m_GebHasBlock;

    override protected void Init() {
        super.Init(); // Resets BOTH the map and vanilla's private ordered hashes.
        m_GebEntries = new array<ref YieldItemBase>();
    }

    override void RegisterYieldItem(YieldItemBase data) {
        if (!data)
            return;
        super.RegisterYieldItem(data);
        m_GebEntries.Insert(data);
    }

    override YieldItemBase GetYieldItemByIdx(int idx) {
        if (!m_GebEntries || idx < 0 || idx >= m_GebEntries.Count())
            return null;
        return super.GetYieldItemByIdx(idx);
    }

    void GebBeginRegistration() {
        if (!m_GebHasBlock) {
            m_GebStart = m_GebEntries.Count();
            return;
        }
        array<ref YieldItemBase> prefix = new array<ref YieldItemBase>();
        m_GebSuffix = new array<ref YieldItemBase>();
        int i;
        for (i = 0; i < m_GebStart; i++)
            prefix.Insert(m_GebEntries[i]);
        for (i = m_GebEnd; i < m_GebEntries.Count(); i++)
            m_GebSuffix.Insert(m_GebEntries[i]);
        Init();
        foreach (YieldItemBase before : prefix) {
            before.GebResetRegistrationIndex();
            RegisterYieldItem(before);
        }
        m_GebStart = m_GebEntries.Count();
    }

    void GebEndRegistration() {
        m_GebEnd = m_GebEntries.Count();
        m_GebHasBlock = true;
        if (m_GebSuffix) {
            foreach (YieldItemBase after : m_GebSuffix) {
                after.GebResetRegistrationIndex();
                RegisterYieldItem(after);
            }
            m_GebSuffix = null;
        }
    }
}

modded class YieldItemBase {
    void GebResetRegistrationIndex() {
        m_RegistrationIdx = -1;
    }
}
