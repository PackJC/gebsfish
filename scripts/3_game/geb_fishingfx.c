// Particle effects for fishing. gebsfish's own particles are vanilla ones
// resized (data/particles: fishing_signal_splash.ptc and geyser_bubbles.ptc,
// still on vanilla's materials).
modded class ParticleList {
    static const int GEB_SPLASH_MEDIUM    = RegisterParticle("gebsfish/data/particles/", "geb_splash_medium");
    static const int GEB_SPLASH_LARGE     = RegisterParticle("gebsfish/data/particles/", "geb_splash_large");
    static const int GEB_BUBBLES_BITE     = RegisterParticle("gebsfish/data/particles/", "geb_bubbles_bite");
    static const int GEB_BUBBLES_TREASURE = RegisterParticle("gebsfish/data/particles/", "geb_bubbles_treasure");
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
    // A fish's splash goes by its full weight (config weight + varQuantityMax
    // x weightPerQuantityUnit): up to a vanilla carp keeps vanilla's bite
    // splash, heavier fish get the medium one, fish over 15 kg the large one.
    static const float SPLASH_VANILLA_MAX_GRAMS = 2300;   // a vanilla carp, full
    static const float SPLASH_MEDIUM_MAX_GRAMS = 15000;

    static int SplashFor(string type) {
        string cfg = "CfgVehicles " + type + " ";
        float grams = g_Game.ConfigGetFloat(cfg + "weight") + g_Game.ConfigGetFloat(cfg + "varQuantityMax") * g_Game.ConfigGetFloat(cfg + "weightPerQuantityUnit");
        if (grams > SPLASH_MEDIUM_MAX_GRAMS)
            return ParticleList.GEB_SPLASH_LARGE;
        if (grams > SPLASH_VANILLA_MAX_GRAMS)
            return ParticleList.GEB_SPLASH_MEDIUM;
        return ParticleList.FISHING_SIGNAL_SPLASH;
    }

    // A one-shot effect every nearby player sees: made on the server, removed
    // after lifespan seconds. Does nothing on a multiplayer client.
    static void Play(vector pos, int particleId, float lifespan = 5) {
        if (!g_Game.IsServer() || particleId == ParticleList.INVALID)
            return;
        SEffectManager.CreateParticleServer(pos, new ParticleEffecterParameters("ParticleEffecter", lifespan, particleId));
    }
}
