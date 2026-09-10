# MAYBE_ISSUES — repo audit findings

Living list of unresolved maybe-issues. Delete entries as they are resolved.
Last full audit: 2026-09-10 (scripts, configs, stringtable, seeded pools, asset
paths, wiki data, and the new `docs/config-editor.html` — binaries excluded).
Prior full audit: 2026-08-18.

The 2026-09-09 gameplay fixes are applied in source. Custom fish now share one
registration, resolve live settings per craft, and roll outputs at execution.
Runtime acceptance checks are recorded below.

The 2026-09-10 audit fixed the confirmed issues in source (snow-crab-legs
texture, the misleading `MergeNewDefaults` comment, the mislabeled
"Random number rolled" debug line, stale cooler placeholder comments, several
config-editor bugs, and wiki gaps/typos). The entries below are what it flagged
but deliberately left — the script items need checking against the vanilla 1.29
scripts before touching, and the rest are cosmetic.

---

## Open — needs a decision

### 1. Version stamps disagree
- Code says `3.3.2` consistently (`constants.c` `VERSION_GEBSFISH`, `mod.cpp`,
  root `config.cpp`).
- `CHANGELOG.md` heads `v4.0.0 — Unreleased`; the wiki badge and banner say the
  current Workshop release is `v3.3.0`.
- Not a bug — the release simply hasn't been cut — but the `3.3.2` stamp needs
  bumping to `4.0.0` when it ships, in all three code spots at once.

## Needs verification — suspected, latent (check against vanilla 1.29 scripts first)

These four came out of the 2026-09-10 script audit as SUSPECTED. Each depends on
vanilla behavior that wasn't confirmed, and none is a live crash on the default
config — so they are listed, not "fixed", to avoid a regression from guessing.

### 5. ELEVATED_DEBUG yield dump derefs a map element without a null guard
- `scripts/5_mission/mission/geb_missionserver.c:49-51`. The loop does
  `yItem = mGeb_YieldsMapAll.GetElement(i); ... yItem.GetType()` with no null
  check on `yItem`, though the function comment (line ~38) claims it null-guards
  each link. The wd/bank/map chain is guarded; the per-element result isn't.
- Only reachable with `DebugLogs = 2`. Latent in practice (the map holds
  non-null yields), but it's the one spot missing the promised guard. If a
  `GetElement(i)` can return null in `[0, Count())`, add a `if (!yItem) continue;`.

### 6. Net catch not in the bamboo net's allow-list silently drops at the player's feet
- `scripts/4_world/.../geb_actionfishingnet.c` (~247-250) calls
  `net.GetInventory().CreateInInventory(spawnType)`, filtered by
  `geb_BambooFishingNet.s_Allowed` (`containers.c:124`, a hard-coded 6-entry list).
- If an admin adds a `NetEntry` whose `Classname` isn't in that list,
  `CreateInInventory` returns null and the catch always falls to the ground
  instead of the net cargo — no crash, no log explaining why. Consider logging
  the fallback, or documenting that net catches must be in `s_Allowed`.

### 7. ContainerJunk health-level range may be ignored
- `scripts/4_world/.../yielditems/geb_yieldjunk.c` +
  `scripts/5_mission/mission/geb_missionbase.c:142-143`. Only `YieldItemJunk` is
  modded with the `OnEntityYieldSpawned` health-level override; `ContainerJunk`
  routes through `YieldItemJunkEmpty`. If vanilla's `YieldItemJunkEmpty` declares
  its own `OnEntityYieldSpawned`, the modded override is bypassed and
  `ContainerJunk` `MinHealthLevel`/`MaxHealthLevel` is silently ignored. Verify
  whether vanilla overrides that method.

### 8. Caviar deletion assumes vanilla `Do()` leaves the caviar at `results[0]`
- `scripts/4_world/classes/recipes/Fish/preparefish.c:189-191, 198-206`. `Do()`
  captures `caviar = results[0]` and `ApplyConfiguredCaviarChance()` deletes
  `results[0]` after `super.Do()` runs. Fragile if vanilla `PrepareAnimal`/
  `PrepareFish.Do` ever reorders or removes results. Couldn't confirm a live
  failure without the vanilla `Do` body.

## Watch — verified benign, keep in mind

### 3. Seventeen species sit in no bait category
- All invertebrates/shellfish (lobsters, crayfish, snail, clam, jellyfish,
  shrimp…): every bait multiplier stays 1.0 for them.
- Reads as intentional (the preference matrix targets fin fish). If crays are
  ever meant to favour worms/jigs, they need a category row in
  `EnsureCategories()`.
- Note: Shrimp is now itself a *bait* with its own `SeedBait` row (reef/
  tropical 2.5x). That is a bait row, not a fish category — catching the
  Shrimp species is still bait-neutral, unchanged.

### 4. Rod-holder slots are referenced but never defined
- The `FishingRod` and `ImprovisedFishingRod` overrides add `fishingpole` +
  `fishingrod1`–`fishingrod10` to `inventorySlot[]`. No CfgSlots in this mod or
  vanilla defines them — they are cross-mod compat with rod-holder/rack mods and
  are inert without one. Intentional; listed so nobody "fixes" it.

### 9. `mod.cpp` vs root `config.cpp` metadata disagree (cosmetic)
- `overview`: `mod.cpp:2` says "Gebs Fishing Expansion", root `config.cpp:30`
  says "DayZ Fish Expansion".
- Hover logo: `mod.cpp:11` uses `logoOver` (the recognized CfgMods key), root
  `config.cpp:29` uses `logoHover`, which isn't a CfgMods key and is ignored in
  game (the launcher still gets the hover logo from `mod.cpp`). Align the two if
  you care; no functional effect.

### 10. Same fish spelled differently across docs (cosmetic)
- One classname, several display names: `geb_RoughNeckRock` shows as "Rough Neck
  Rock" (fish DB) / "Roughneck Rock" (odds table) / "Rougheye Rock" (changelog);
  `geb_Bonita` is "Bonita" in the wiki, "Bonito" in the changelog. Pick one
  spelling per fish. (Real species are "Rougheye rockfish" and "Bonito".)

### 11. Trailing commas in two config arrays (benign)
- `data/fish/config.cpp` (`geb_EuropeanCrayFish` materials) and
  `data/clothes/config.cpp` (`geb_OrangeFishGloves` textures) have a trailing
  comma before the closing `}`, unlike their sibling classes. The binarizer
  tolerates it — just inconsistent.

---

## Compatibility

Deploy the same build to clients and server, then restart/reconnect. The number
of custom recipe registrations changes and the net action payload gains an int;
mixing old and new peers is unsupported. Keep the same mod load order on peers.

Custom catch classnames must inherit Inventory_Base, as fish and normal inventory
items do. Invalid or empty result classnames disable preparation rather than
consuming a fish and then attempting an invalid result spawn. A missing vanilla
species row retains the prior one-piece fallback; an explicit empty ResultMain
disables that row. Zero MeatMin/MeatMax is allowed and may yield no meat.

Default net catches are freshwater-only. A sea cast with the untouched default
table still returns no catch; add sea/both entries if sea netting is desired.

## Verification performed

- Read installed DayZ scripts extracted from dta/scripts.pbo with BankRev.
- Matched SpawnItems/PerformRecipe/PrepareAnimal.Do order, recipe ingredient-cache
  inheritance, and ActionBase receive/setup sequencing against those scripts.
- Verified fixed registration membership, bounded counts, live config lookup,
  bonus placement, payload write/read/receive/use, and preservation of earlier fixes.
- Built a temporary script-only PBO with FileBank for a diagnostic launch.
- Diagnostic startup exited twice before script logging with -1073741515
  (0xC0000135, missing DLL dependency). No Enforce compile or gameplay pass claimed.

## Required runtime cases

1. On a staging server, run malformed-file preservation tests for all four JSON
   files. Compare bytes/mtime, then repair each file and restart.
2. Force hook rewards; test migration weights and an externally-defined FishingHook.
3. Craft mounts from stacks of 1 and 10 planks; verify saw requirements and wear.
4. Force invalid/valid predator spawns; test warnings with sound off/on.
5. Test all gathering FindChance endpoints 0 and 1, including tool wear.
6. Prepare normal, caviar, and lobster fish repeatedly with 1-2 meat pieces;
   test negative/inverted/huge bounds, 0/0, and the maximum result capacity.
   Check one caviar roll, guaranteed lobster tail, inherited quantity and health.
7. Reorder/delete/add server Species rows, toggle ResultMain, and reconnect.
   Check both ingredient orders (fish+knife and knife+fish), all four vanilla
   recipes, custom catch items, frozen fish, and an invalid output classname.
8. Give the net distinct pond/sea/both entries. Test shoreline sea casts, ponds,
   singleplayer, listen server, and dedicated server. Verify missing/truncated
   action payloads are rejected and no freshwater fallback occurs.
