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
//   - Weighted selection from m_gebsConfig.Predators
//   - Land-only spawn-position search (avoids spawning predators in water)
//   - Spawning N instances per the predator's MinCount/MaxCount
//   - Warning sound RPC to nearby players (PredatorWarningSoundEnable)
//   - Chat-message broadcast (PredatorWarningMessageEnable + color flags)
//
// Returns true if at least one predator was spawned, false otherwise.
class GebsPredatorSpawner {

    static bool TrySpawn(PlayerBase player, float chance, string logTag) {
        if (!g_Game.IsServer() || !player)
            return false;

        gebsfishConfig cfg = GetGebSettingsConfig();
        if (!cfg || !cfg.PredatorSettings) {
            // No safe config to read. Bail rather than crash the action.
            return false;
        }

        int debugLogs = 0;
        if (cfg.GeneralSettings)
            debugLogs = cfg.GeneralSettings.DebugLogs;

        if (!cfg.PredatorSettings.PredatorSpawnEnabled) {
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

        int count = Math.RandomInt(minCount, maxCount + 1);
        if (debugLogs)
            GebsfishLogger.Debug("Spawning " + count + " " + selected.Classname + " around player.", logTag);

        vector playerPos = player.GetPosition();
        bool soundPlayed = false;
        for (int i = 0; i < count; i++) {
            vector spawnPos = FindLandSpawnPosition(playerPos, selected.MinRadius, selected.MaxRadius, debugLogs, logTag);
            SpawnOneAt(selected.Classname, spawnPos, player, cfg, debugLogs, logTag, soundPlayed);
        }

        BroadcastPredatorMessage(cfg, player);
        return true;
    }

    // Weighted random over m_gebsConfig.Predators using SpawnChance as the weight.
    protected static PredatorEntry PickWeightedPredator(gebsfishConfig cfg, int debugLogs, string logTag) {
        if (!cfg.Predators || cfg.Predators.Count() == 0) {
            if (debugLogs)
                GebsfishLogger.Debug("No predators are configured.", logTag);
            return null;
        }

        float totalWeight = 0;
        foreach (PredatorEntry predator1 : cfg.Predators) {
            if (!predator1 || predator1.Classname == "" || predator1.SpawnChance <= 0)
                continue;
            totalWeight += predator1.SpawnChance;
        }

        if (totalWeight <= 0) {
            if (debugLogs)
                GebsfishLogger.Debug("No predators have a valid spawn chance in the config.", logTag);
            return null;
        }

        float randomValue = Math.RandomFloat(0, totalWeight);
        float cumulative = 0;
        foreach (PredatorEntry predator : cfg.Predators) {
            if (!predator || predator.Classname == "" || predator.SpawnChance <= 0)
                continue;

            cumulative += predator.SpawnChance;
            if (randomValue <= cumulative)
                return predator;
        }

        return null;
    }

    // Picks a random offset in [minRadius..maxRadius] around center and retries
    // up to 20 times if it lands on sea or pond. Falls back to whatever the
    // last roll was so the spawn never hangs indefinitely.
    protected static vector FindLandSpawnPosition(vector center, float minRadius, float maxRadius, int debugLogs, string logTag) {
        if (minRadius < 0) minRadius = 0;
        if (maxRadius < 0) maxRadius = 0;
        if (maxRadius < minRadius) maxRadius = minRadius;

        float angle = Math.RandomFloat(0, 360);
        float distance = Math.RandomFloat(minRadius, maxRadius);
        float xOffset = Math.Cos(angle) * distance;
        float zOffset = Math.Sin(angle) * distance;

        vector spawnPos = Vector(center[0] + xOffset, center[1], center[2] + zOffset);

        const int maxAttempts = 20;
        int attempts = 0;
        while ((g_Game.SurfaceIsSea(spawnPos[0], spawnPos[2]) || g_Game.SurfaceIsPond(spawnPos[0], spawnPos[2])) && attempts < maxAttempts) {
            if (debugLogs == ELEVATED_DEBUG)
                GebsfishLogger.Debug("Surface selected for spawning predator was over water. Retrying.", logTag);

            angle = Math.RandomFloat(0, 360);
            distance = Math.RandomFloat(minRadius, maxRadius);
            xOffset = Math.Cos(angle) * distance;
            zOffset = Math.Sin(angle) * distance;
            spawnPos = Vector(center[0] + xOffset, center[1], center[2] + zOffset);
            attempts++;
        }

        if (debugLogs && attempts >= maxAttempts)
            GebsfishLogger.Debug("Warning: Max attempts reached while trying to find a land spawn position.", logTag);

        return spawnPos;
    }

    // Spawns one predator entity at the given position. On the first successful
    // spawn within a single TrySpawn call, also fires the warning-sound RPC to
    // nearby players if PredatorWarningSoundEnable is on.
    protected static void SpawnOneAt(string classname, vector position, PlayerBase triggeringPlayer, gebsfishConfig cfg, int debugLogs, string logTag, out bool soundPlayed) {
        Object predator = g_Game.CreateObject(classname, position, false, true);
        if (!predator) {
            if (debugLogs)
                GebsfishLogger.Debug("Failed to spawn " + classname + ".", logTag);
            return;
        }

        if (debugLogs)
            GebsfishLogger.Debug("Spawned " + classname + " at " + position.ToString(), logTag);

        #ifdef ExtraLogs
            if (cfg.CFToolsLogging && cfg.CFToolsLogging.PredatorSpawn) {
                string gebpredatorspawnmessage = "Predator " + classname + " spawned at " + position.ToString();
                SendToCFTools(triggeringPlayer, "", "", gebpredatorspawnmessage);
            }
        #endif

        // Warning sound RPC, fired once per TrySpawn call (the `out bool` flag).
        if (!cfg.PredatorSettings.PredatorWarningSoundEnable || soundPlayed)
            return;

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
            if (distance > cfg.PredatorSettings.PredatorWarningSoundRadius)
                continue;

            Param1<string> rpcData = new Param1<string>("PredatorWarning_SoundSet");
            GetRPCManager().SendRPC("gebsfish", "PlayPredatorSound", rpcData, true, nearbyIdentity, nearbyPlayer);

            if (debugLogs)
                GebsfishLogger.Debug("Sent warning sound RPC to " + nearbyIdentity.GetName() + " (within " + cfg.PredatorSettings.PredatorWarningSoundRadius + "m of " + triggeringPlayerName + ").", logTag + "RPC");

            #ifdef ExtraLogs
                if (cfg.CFToolsLogging && cfg.CFToolsLogging.PredatorSounds) {
                    string gebpredatorsoundmessage = "Predator sound played for player within " + cfg.PredatorSettings.PredatorWarningSoundRadius + " meters of " + triggeringPlayerName;
                    SendToCFTools(nearbyPlayer, "", "", gebpredatorsoundmessage);
                }
            #endif
        }

        soundPlayed = true;
    }

    // Sends the configured chat-message broadcast to the triggering player.
    // Only fires if PredatorWarningMessageEnable is on, then routes via the
    // first color flag that's set.
    protected static void BroadcastPredatorMessage(gebsfishConfig cfg, PlayerBase player) {
        if (!cfg.PredatorSettings.PredatorWarningMessageEnable)
            return;

        string pred_message = Widget.TranslateString("#STR_action_predatorspawn");

        if (cfg.PredatorSettings.PredatorWarningMessageGreen)
            player.MessageFriendly(pred_message);
        if (cfg.PredatorSettings.PredatorWarningMessageGrey)
            player.MessageStatus(pred_message);
        if (cfg.PredatorSettings.PredatorWarningMessageRed)
            player.MessageImportant(pred_message);
        if (cfg.PredatorSettings.PredatorWarningMessageYellow)
            player.MessageAction(pred_message);
    }
}
