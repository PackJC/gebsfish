// gebsfish's own particles: the fish tank's, vanilla ones resized
// (data/particles, still on vanilla's materials). Fishing itself uses
// vanilla's bite splash only: the splashes by fish weight and the bubbles
// before a bite and on treasure were taken out on 2026-10-14 (Cole: they
// made fishing more confusing).
modded class ParticleList {
    // The fish tank's air stone (geb_FishTank): a looping stream of small bubbles
    // (vanilla breath_bubbles slowed down) with geyser_bubbles' bubbling at 4 % on top.
    static const int GEB_BUBBLES_TANK     = RegisterParticle("gebsfish/data/particles/", "geb_bubbles_tank");
    // The tank's volcano ornament: the same stream three times as dense, from its crater.
    static const int GEB_BUBBLES_VOLCANO  = RegisterParticle("gebsfish/data/particles/", "geb_bubbles_volcano");
    // The tank's hang-on-back filter: a thin falling sheet of water (vanilla water_jet_weak,
    // slowed and narrowed) and the small looping splash where it lands (the fishing splash at 8 %).
    static const int GEB_FILTER_STREAM    = RegisterParticle("gebsfish/data/particles/", "geb_filter_stream");
    static const int GEB_FILTER_SPLASH    = RegisterParticle("gebsfish/data/particles/", "geb_filter_splash");
    // The tank's treasure chest: one gush of bubbles each time its lid is fully open.
    static const int GEB_BUBBLES_CHEST    = RegisterParticle("gebsfish/data/particles/", "geb_bubbles_chest");
}

class GebFishingFx {
    // A one-shot effect every nearby player sees: made on the server, removed
    // after lifespan seconds. Does nothing on a multiplayer client.
    static void Play(vector pos, int particleId, float lifespan = 5) {
        if (!g_Game.IsServer() || particleId == ParticleList.INVALID)
            return;
        SEffectManager.CreateParticleServer(pos, new ParticleEffecterParameters("ParticleEffecter", lifespan, particleId));
    }
}
