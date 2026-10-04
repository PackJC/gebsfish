/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Centralised predator-spawn logic. Callers (fishing action, prepare-fish
// recipe, fishing-net action) pass the triggering player, the chance from
// config (e.g. PredatorSpawnChanceFishing / Preparing / FailCatch / FishingNet),
// and a log tag so call sites stay identifiable in script.log.
//
// Handles:
//   - Server-only guard
//   - Config null guards
//   - PredatorSpawnEnabled toggle
//   - Random chance roll
//   - Weighted selection from m_gebsConfig.General.Predators
//   - Land-only spawn-position search (avoids spawning predators in water)
//   - Spawning N instances per the predator's MinCount/MaxCount
//   - Warning sound RPC to nearby players (PredatorWarningSoundEnable)
//   - Chat warning to the triggering player (PredatorWarningMessageEnable + color flags)
//   - Cleanup: these are plain AI animals that nothing else ever removes, so
//     the spawner caps how many it has out and despawns old ones (see below)
//
// Returns true if at least one predator was spawned, false otherwise.
class GebsPredatorSpawner {
    // Most predators one spawn event can bring, whatever MaxCount says -- a
    // config typo of 100 shouldn't drop a hundred wolves on a player.
    protected static const int MAX_PER_SPAWN = 10;
    // Living predators from this spawner allowed at once, server-wide. At the
    // cap, new spawns are skipped until some are killed or despawned.
    protected static const int MAX_ACTIVE = 30;
    // A predator still alive this long after spawning is removed, once no
    // player is within DESPAWN_PLAYER_RADIUS to see it vanish. Killed ones
    // are left alone: the corpse is the game's to clean up.
    protected static const float DESPAWN_AFTER_SECS = 900.0;
    protected static const float DESPAWN_PLAYER_RADIUS = 150.0;
    protected static const int SWEEP_INTERVAL_MS = 60000;

    // Predators this spawner created and their spawn times (GetTickTime),
    // kept in step. Entity references null themselves when the entity is
    // deleted, so a dead or removed entry is simply dropped on the next pass.
    protected static ref array<Object> s_GebActive;
    protected static ref array<float> s_GebSpawnedAt;
    protected static bool s_GebSweeping;

    static bool TrySpawn(PlayerBase player, float chance, string logTag) {
        if (!g_Game.IsServer() || !player)
            return false;

        gebsfishConfig cfg = GetGebSettingsConfig();
        if (!cfg || !cfg.General || !cfg.General.PredatorSettings) {
            // No safe config to read. Bail rather than crash the action.
            return false;
        }

        int debugLogs = GebGetDebugLevel();

        if (!cfg.General.PredatorSettings.PredatorSpawnEnabled) {
            if (debugLogs)
                GebsfishLogger.Debug("Predator spawning disabled in config.", logTag);
            return false;
        }

        if (chance <= 0)
            return false;

        if (Math.RandomFloat(0, 1) > chance) {
            if (debugLogs)
                GebsfishLogger.Debug("Predator spawn chance roll failed.", logTag);
            return false;
        }

        PredatorEntry selected = PickWeightedPredator(cfg, debugLogs, logTag);
        if (!selected) {
            if (debugLogs)
                GebsfishLogger.Debug("No predator was selected to spawn from the config.", logTag);
            return false;
        }

        int minCount = selected.MinCount;
        int maxCount = selected.MaxCount;
        if (minCount < 0) minCount = 0;
        if (maxCount < 0) maxCount = 0;
        if (maxCount < minCount) maxCount = minCount;
        if (maxCount > MAX_PER_SPAWN) maxCount = MAX_PER_SPAWN;
        if (minCount > maxCount) minCount = maxCount;

        int count = Math.RandomInt(minCount, maxCount + 1);
        int room = MAX_ACTIVE - GebActiveCount();
        if (room <= 0) {
            if (debugLogs)
                GebsfishLogger.Debug("Predator cap reached (" + MAX_ACTIVE + " alive). Skipping this spawn.", logTag);
            return false;
        }
        if (count > room)
            count = room;
        if (debugLogs)
            GebsfishLogger.Debug("Spawning " + count + " " + selected.Classname + " around player.", logTag);

        vector playerPos = player.GetPosition();
        bool soundPlayed = false;
        bool anySpawned = false;
        for (int i = 0; i < count; i++) {
            bool foundLand;
            vector spawnPos = FindLandSpawnPosition(playerPos, selected.MinRadius, selected.MaxRadius, debugLogs, logTag, foundLand);
            // Skip rather than spawn over water. Happens when the triggering
            // player is fishing far from shore (boat in deep sea) and no
            // random offset within [MinRadius, MaxRadius] hit terrain after
            // the retry cap.
            if (!foundLand) {
                if (debugLogs)
                    GebsfishLogger.Debug("Skipping predator spawn -- no land found within [" + selected.MinRadius + "m, " + selected.MaxRadius + "m] of player. Likely too far from shore.", logTag);
                continue;
            }
            if (SpawnOneAt(selected.Classname, spawnPos, player, cfg, debugLogs, logTag, soundPlayed))
                anySpawned = true;
        }

        if (anySpawned)
            SendPredatorMessageToPlayer(cfg, player);
        return anySpawned;
    }

    // Weighted random over m_gebsConfig.General.Predators using SpawnChance as the weight.
    protected static PredatorEntry PickWeightedPredator(gebsfishConfig cfg, int debugLogs, string logTag) {
        if (!cfg.General || !cfg.General.Predators || cfg.General.Predators.Count() == 0) {
            if (debugLogs)
                GebsfishLogger.Debug("No predators are configured.", logTag);
            return null;
        }

        // Filter to eligible entries once, keeping a parallel ref list so the
        // shared picker's returned index maps back to the PredatorEntry.
        array<ref PredatorEntry> eligible = new array<ref PredatorEntry>();
        TStringArray names = new TStringArray;
        TFloatArray weights = new TFloatArray;
        foreach (PredatorEntry predator : cfg.General.Predators) {
            if (!predator || predator.Classname == "" || predator.SpawnChance <= 0)
                continue;
            eligible.Insert(predator);
            names.Insert(predator.Classname);
            weights.Insert(predator.SpawnChance);
        }

        int pick = GebWeightedPick.Pick(names, weights, debugLogs, logTag);
        if (pick < 0)
            return null;
        return eligible[pick];
    }

    // Picks a random offset in [minRadius..maxRadius] around center and
    // retries up to 20 times to find a position that isn't over sea or pond.
    // Sets foundLand=true on success. On failure (all 20 attempts landed
    // over water, typically when fishing far from shore in a boat) returns
    // center as a safe fallback with foundLand=false so the caller can skip
    // the spawn instead of dropping a wolf underwater.
    //
    // Pins the result's Y to the walkable surface via SurfaceRoadY (a bridge
    // deck, a rock or another object's roadway, else the terrain), the way
    // vanilla snaps traps and stashes, rather than reusing center's Y. The
    // triggering player may be on a boat, on a cliff, or wading in shallow
    // water -- their Y is not the ground the predator needs to spawn on.
    protected static vector FindLandSpawnPosition(vector center, float minRadius, float maxRadius, int debugLogs, string logTag, out bool foundLand) {
        foundLand = false;
        if (minRadius < 0) minRadius = 0;
        if (maxRadius < 0) maxRadius = 0;
        if (maxRadius < minRadius) maxRadius = minRadius;

        vector spawnPos = center;

        const int maxAttempts = 20;
        for (int attempts = 0; attempts < maxAttempts; attempts++) {
            // Math.Cos/Sin take radians, so the angle must span [0, 2pi) --
            // feeding degrees here produced an angularly clumped spawn ring.
            float angle = Math.RandomFloat(0, Math.PI2);
            float distance = Math.RandomFloat(minRadius, maxRadius);
            float xOffset = Math.Cos(angle) * distance;
            float zOffset = Math.Sin(angle) * distance;

            float candidateX = center[0] + xOffset;
            float candidateZ = center[2] + zOffset;

            if (g_Game.SurfaceIsSea(candidateX, candidateZ) || g_Game.SurfaceIsPond(candidateX, candidateZ)) {
                if (debugLogs == ELEVATED_DEBUG)
                    GebsfishLogger.Debug("Surface selected for spawning predator was over water. Retrying.", logTag);
                continue;
            }

            // The surface Y at the candidate, not the player's Y. SurfaceY
            // alone is the bare terrain, under any bridge or inside any rock.
            float candidateY = g_Game.SurfaceRoadY(candidateX, candidateZ);
            spawnPos = Vector(candidateX, candidateY, candidateZ);
            foundLand = true;
            return spawnPos;
        }

        if (debugLogs)
            GebsfishLogger.Debug("Warning: Max attempts reached while trying to find a land spawn position.", logTag);

        return spawnPos;
    }

    // Spawns one predator entity at the given position. On the first successful
    // spawn within a single TrySpawn call, also fires the warning-sound RPC to
    // nearby players if PredatorWarningSoundEnable is on.
    protected static bool SpawnOneAt(string classname, vector position, PlayerBase triggeringPlayer, gebsfishConfig cfg, int debugLogs, string logTag, out bool soundPlayed) {
        // Vanilla's own spawn path: AI (DZ_LightAI) goes through SpawnAI with
        // ECE_PLACE_ON_SURFACE | ECE_INITAI | ECE_EQUIP_ATTACHMENTS, so it is
        // traced onto the surface at `position` and set up the way the game
        // sets up its own animals; anything else is placed on the surface too.
        Object predator = triggeringPlayer.SpawnEntityOnGroundPos(classname, position);
        if (!predator) {
            if (debugLogs)
                GebsfishLogger.Debug("Failed to spawn " + classname + ".", logTag);
            return false;
        }

        if (debugLogs)
            GebsfishLogger.Debug("Spawned " + classname + " at " + position.ToString(), logTag);
        GebTrack(predator);

        // Warning sound RPC, fired once per TrySpawn call (the `out bool` flag).
        if (!cfg.General.PredatorSettings.PredatorWarningSoundEnable || soundPlayed)
            return true;

        PlayerIdentity triggeringIdentity = triggeringPlayer.GetIdentity();
        string triggeringPlayerName = "unknown player";
        if (triggeringIdentity)
            triggeringPlayerName = triggeringIdentity.GetName();

        array<Man> players = new array<Man>();
        g_Game.GetPlayers(players);

        foreach (Man player : players) {
            PlayerBase nearbyPlayer = PlayerBase.Cast(player);
            if (!nearbyPlayer)
                continue;

            PlayerIdentity nearbyIdentity = nearbyPlayer.GetIdentity();
            if (!nearbyIdentity)
                continue;

            float distance = vector.Distance(triggeringPlayer.GetPosition(), nearbyPlayer.GetPosition());
            if (distance > cfg.General.PredatorSettings.PredatorWarningSoundRadius)
                continue;

            Param1<string> rpcData = new Param1<string>("PredatorWarning_SoundSet");
            GetRPCManager().SendRPC("gebsfish", "PlayPredatorSound", rpcData, true, nearbyIdentity, nearbyPlayer);

            if (debugLogs)
                GebsfishLogger.Debug("Sent warning sound RPC to " + nearbyIdentity.GetName() + " (within " + cfg.General.PredatorSettings.PredatorWarningSoundRadius + "m of " + triggeringPlayerName + ").", logTag + "RPC");
        }

        soundPlayed = true;
        return true;
    }

    protected static void GebTrack(Object predator) {
        if (!s_GebActive) {
            s_GebActive = new array<Object>();
            s_GebSpawnedAt = new array<float>();
        }
        s_GebActive.Insert(predator);
        s_GebSpawnedAt.Insert(g_Game.GetTickTime());
        // One shared sweep for every predator, not a timer each.
        if (!s_GebSweeping) {
            s_GebSweeping = true;
            g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebsPredatorSpawner.GebSweep, SWEEP_INTERVAL_MS, true);
        }
    }

    // Living predators this spawner has out; drops entries that were killed
    // or deleted since the last look.
    protected static int GebActiveCount() {
        if (!s_GebActive)
            return 0;
        for (int i = s_GebActive.Count() - 1; i >= 0; i--) {
            Object animal = s_GebActive[i];
            if (!animal || !animal.IsAlive()) {
                s_GebActive.RemoveOrdered(i);
                s_GebSpawnedAt.RemoveOrdered(i);
            }
        }
        return s_GebActive.Count();
    }

    // Every SWEEP_INTERVAL_MS while any are out: removes living predators
    // older than DESPAWN_AFTER_SECS that no player is close to, then stops
    // itself once the list is empty.
    static void GebSweep() {
        if (GebActiveCount() > 0) {
            float now = g_Game.GetTickTime();
            array<Man> players = new array<Man>();
            g_Game.GetPlayers(players);
            for (int i = s_GebActive.Count() - 1; i >= 0; i--) {
                if (now - s_GebSpawnedAt[i] < DESPAWN_AFTER_SECS)
                    continue;
                Object animal = s_GebActive[i];
                if (GebPlayerNear(animal.GetPosition(), players))
                    continue;
                s_GebActive.RemoveOrdered(i);
                s_GebSpawnedAt.RemoveOrdered(i);
                animal.Delete();
            }
        }
        if (!s_GebActive || s_GebActive.Count() == 0) {
            g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebsPredatorSpawner.GebSweep);
            s_GebSweeping = false;
        }
    }

    protected static bool GebPlayerNear(vector position, array<Man> players) {
        float radiusSq = DESPAWN_PLAYER_RADIUS * DESPAWN_PLAYER_RADIUS;
        foreach (Man man : players) {
            if (man && vector.DistanceSq(man.GetPosition(), position) <= radiusSq)
                return true;
        }
        return false;
    }

    // Sends the configured chat warning to the triggering player only (not
    // a server-wide broadcast). Only fires if PredatorWarningMessageEnable
    // is on, then routes via the first color flag that's set.
    protected static void SendPredatorMessageToPlayer(gebsfishConfig cfg, PlayerBase player) {
        if (!cfg.General.PredatorSettings.PredatorWarningMessageEnable)
            return;

        // Send the stringtable key, not translated text: this runs on the
        // server, and the player's chat widget translates a "#" key into the
        // player's own language when it shows the line.
        string pred_message = "#STR_action_predatorspawn";

        if (cfg.General.PredatorSettings.PredatorWarningMessageGreen)
            player.MessageFriendly(pred_message);
        else if (cfg.General.PredatorSettings.PredatorWarningMessageGrey)
            player.MessageStatus(pred_message);
        else if (cfg.General.PredatorSettings.PredatorWarningMessageRed)
            player.MessageImportant(pred_message);
        else if (cfg.General.PredatorSettings.PredatorWarningMessageYellow)
            player.MessageAction(pred_message);
    }
}
