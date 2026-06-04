/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Shared weighted-random picker for the dig / net / hook / predator spawn
// tables. Callers filter their own entries first (blank/zero/env), push the
// eligible classnames + weights into parallel arrays, then call Pick once.
//
// Centralising the math here means a caller's "sum" pass and "walk" pass can
// never disagree on which entries are eligible (the bug that used to be
// possible when the two foreach loops were copied by hand), and the
// float-rounding boundary case clamps to the last eligible entry instead of
// silently returning nothing.
//
// Returns the index into names[]/weights[] that won the roll, or -1 when the
// pool is empty or every weight is <= 0. debugLevel + logTag drive an optional
// breakdown log (logTag is also used as the log category).
class GebWeightedPick {
    static int Pick(TStringArray names, TFloatArray weights, int debugLevel, string logTag) {
        if (!names || !weights)
            return -1;

        int n = names.Count();
        if (n == 0 || weights.Count() != n) {
            if (debugLevel >= 1)
                GebsfishLogger.Debug(logTag + ": empty or mismatched pool -- no pick", logTag);
            return -1;
        }

        if (debugLevel == ELEVATED_DEBUG) {
            GebsfishLogger.Debug("---" + logTag + " weighted pick---", logTag);
            GebsfishLogger.Debug("idx | classname | weight", logTag);
        }

        // Sum eligible weights. Negative weights are floored to 0 so an admin
        // typo can't drag the total (or an entry's slice) below zero.
        float total = 0;
        for (int i = 0; i < n; i++) {
            float w = weights[i];
            if (w < 0) w = 0;
            if (debugLevel == ELEVATED_DEBUG)
                GebsfishLogger.Debug("" + i + " | " + names[i] + " | " + w, logTag);
            total += w;
        }

        if (total <= 0) {
            if (debugLevel >= 1)
                GebsfishLogger.Debug(logTag + ": totalWeight=0 after filter -- no pick", logTag);
            return -1;
        }

        float roll = Math.RandomFloat(0.0, total);
        float cumulative = 0;
        for (int j = 0; j < n; j++) {
            float wj = weights[j];
            if (wj <= 0) continue;
            cumulative += wj;
            if (roll < cumulative) {
                if (debugLevel >= 1)
                    GebsfishLogger.Debug(logTag + " picked: " + names[j] + " (idx=" + j + " roll=" + roll + " total=" + total + ")", logTag);
                return j;
            }
        }

        // Float rounding left the roll fractionally past the last boundary.
        // Return the last positive-weight entry rather than dropping the catch.
        for (int k = n - 1; k >= 0; k--) {
            if (weights[k] > 0) {
                if (debugLevel >= 1)
                    GebsfishLogger.Debug(logTag + " picked (boundary clamp): " + names[k], logTag);
                return k;
            }
        }
        return -1;
    }
}
