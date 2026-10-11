modded class DayZGame {
    // DeferredInit runs from the GUI call queue, which a dedicated server
    // never ticks (NO_GUI) -- so this covers clients and offline play, and
    // MissionServer.OnInit registers on the dedicated server.
    override void DeferredInit() {
        super.DeferredInit();
        GebRegisterRPCs();
    }

    // Community Framework RPCs. Both current ones are server -> client, but
    // registering on both sides keeps any future client -> server RPC working.
    void GebRegisterRPCs() {
        GetRPCManager().AddRPC("gebsfish", "ConfigSync", this, SingleplayerExecutionType.Client);
        GetRPCManager().AddRPC("gebsfish", "PlayPredatorSound", this, SingleplayerExecutionType.Client);
    }

    void ConfigSync(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target) {
        // Ignore anything but a server -> client sync before doing any work:
        // the server registers this RPC too, so a client could otherwise make
        // the server write log lines on demand.
        if (type != CallType.Client)
            return;

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

        // Debug lines only after the swap: until then a client holds the
        // built-in defaults, whose DebugLogs is always 0.
        SetGebsfishConfig(configParams.param1);
        g_GebConfigReceived = true;
        GebGetConfigReadyInvoker().Invoke();
        if (GebGetDebugLevel() >= 1)
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
        if (GebGetDebugLevel() >= 1)
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
    // Every registration in sync-list order (vanilla keeps its list private).
    protected ref array<ref YieldItemBase> m_GebEntries;
    // Yields other code put in this bank (the map's WorldData, other mods), in
    // the order they came, including any a gebsfish yield of the same type
    // stands in for. Every rebuild puts them back the same way, so a client's
    // rebuild on config sync ends up with the server's list.
    protected ref array<ref YieldItemBase> m_GebForeign;
    protected int m_GebEnd;  // gebsfish's yields are entries 0 .. m_GebEnd - 1
    protected int m_GebTail; // entries from here on came in after the last rebuild
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

    // Still the yield the bank hands out for its type. Vanilla's
    // ClearAllRegisteredItems and UnregisterYieldItem only empty the map, and a
    // later registration of the same type replaces the entry there.
    protected bool GebIsLive(YieldItemBase entry) {
        return entry && m_AllYieldsMap.Get(entry.GetType().Hash()) == entry;
    }

    // False before the first registration, and once something has cleared or
    // replaced gebsfish's yields: a map's WorldData that clears the bank after
    // the yield invoker (as vanilla Livonia and Sakhal do) without a hook in
    // gebsfish.c, or a mod registering a type gebsfish registers.
    bool GebBlockIntact() {
        if (!m_GebHasBlock || m_GebEnd > m_GebEntries.Count())
            return false;
        for (int i = 0; i < m_GebEnd; i++) {
            if (!GebIsLive(m_GebEntries[i]))
                return false;
        }
        return true;
    }

    // Every (re)registration starts from an empty bank so gebsfish's yields
    // come first. The rest is set aside here and goes back in
    // GebEndRegistration.
    void GebBeginRegistration() {
        array<ref YieldItemBase> foreign = new array<ref YieldItemBase>();
        if (m_GebForeign) {
            foreach (YieldItemBase known : m_GebForeign) {
                // Index -1: a gebsfish yield stood in for it last time, so keep
                // it. Registered but no longer live: cleared or replaced since.
                if (known.GetRegistrationIdx() == -1 || GebIsLive(known))
                    foreign.Insert(known);
            }
        }
        int first = 0;
        if (m_GebHasBlock)
            first = m_GebTail;
        for (int i = first; i < m_GebEntries.Count(); i++) {
            YieldItemBase entry = m_GebEntries[i];
            if (GebIsLive(entry) && foreign.Find(entry) == -1)
                foreign.Insert(entry);
        }
        m_GebForeign = foreign;
        Init();
    }

    // Put the other yields back behind gebsfish's. Where both registered a
    // type, gebsfish's stays: fish.json and junk.json decide that catch.
    void GebEndRegistration() {
        m_GebEnd = m_GebEntries.Count();
        m_GebHasBlock = true;
        if (m_GebForeign) {
            foreach (YieldItemBase other : m_GebForeign) {
                other.GebResetRegistrationIndex();
                if (!m_AllYieldsMap.Contains(other.GetType().Hash()))
                    RegisterYieldItem(other);
            }
        }
        m_GebTail = m_GebEntries.Count();
    }
}

modded class YieldItemBase {
    void GebResetRegistrationIndex() {
        m_RegistrationIdx = -1;
    }
}
