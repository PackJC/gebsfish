# MAYBE_ISSUES — repo audit findings (2026-08-11)

Findings from a full-repo audit. "Verified" items were manually confirmed against the
vanilla DayZ sources on `P:\scripts`. Everything else was reported by audit passes and
read directly from the mod source, but has not been fixed. Delete entries as they are
resolved.

---

## Critical — fishing is broken in current master (unreleased)

Introduced by the data-driven refactor ("Config optimization - TBC"). Released 3.3
predates these; a build from current master would ship them.

### 1. No fish yield is ever configured (VERIFIED)
- `scripts/4_world/systems/animalcatchingsystem/yielditems/geb_YieldFishGeneric.c:17-26`
- `scripts/5_mission/mission/geb_missionbase.c:46-48`
- Vanilla `YieldItemBase(int)` constructor calls `Init()` (P:\scripts\3_Game\DayZ\Systems\AnimalCatching\CatchYieldItemBase.c),
  so `Init()` runs during `new geb_YieldFishGeneric(...)` BEFORE `SetConf()`, hits the
  `if (!m_Conf) return` guard, and never runs again — `CatchYieldBank.RegisterYieldItem`
  only sets a registration index and inserts into a map; it does NOT call `Init()`.
- Result: every species registers with empty classname / enviro mask / method mask, and
  since the bank keys on `GetType().Hash()`, all 79 fish collapse onto one map entry.
- The comment in geb_YieldFishGeneric.c claiming RegisterYieldItem "triggers Init()" is wrong.
- Fix shape: make `SetConf()` call `Init()` itself (or move the setup into `SetConf`).

### 2. Every data-driven fillet/caviar/lobster recipe registers empty (VERIFIED)
- `scripts/4_world/classes/recipes/Fish/geb_PrepareFishData.c:19-30`
- `scripts/4_world/classes/recipes/recipeconstructor.c:24-26`
- Identical ordering bug: vanilla `RecipeBase()` constructor calls `Init()` before
  `SetConf()` can run; `PluginRecipesManager.RegisterRecipe` does not call `Init()`.
- Result: ~70 recipes registered with no ingredients and no results.
- Same fix shape as #1. Also note: every instance shares `ClassName() == "GebPrepareFishData"`
  and PluginRecipesManager keys `m_RecipeNamesList` by classname, so all registrations
  collide on one key.

### 3. Rods take double damage per catch/pass event (VERIFIED)
- `geb_CatchingContextFishingRodAction.c:1030-1031` and `:1046`
- Both sites call the identical single-arg `m_MainItem.AddHealth(-DAMAGE_HOOK)`. The
  comment claims the first call is the 3-arg form; it is not. Rods wear at 2x rate.

---

## Design / logic issues (decide intent, then fix)

- **Bait + temperature gated behind weather toggle** — `GenerateResult` only runs the
  weighted pick when `WeatherCatchBoostEnable` is on (`geb_CatchingContextFishingRodAction.c:202-206`,
  `:812-813`), so with it off, bait preferences and the temperature curve do nothing —
  contradicting three config descriptions that call them independent.
- **CatchProbability applied twice in the BiteSpeed aggregate** (`geb_CatchingContextFishingRodAction.c:103-114`) —
  the vanilla probability array already repeats each yield by weight; multiplying by
  `GetCatchProbability()` again makes the effective weight probability².
  (`PickWeightedYieldIndex` gets this right.)
- **types.xml generator emits duplicates/collisions** (`typesxml.c:96-98`) — one <type>
  per species for Classname/ResultMain/ResultBonus with no dedup: RedCaviar x8,
  geb_YellowCaviar x5; vanilla classnames (Carp, Mackerel, Sardines, Bitterlings, Shrimp,
  SteelheadTrout, WalleyePollock, RedCaviar) also emitted and collide with mission types.xml.
- **geb_KingCrab / geb_SnowCrab IK registration still missing** (`geb_dayzplayercfgbase.c:48-49`) —
  both are live catchables with fillet results.
- **Latent recipe-results overflow** (`geb_preparefishbase.c:44-58`) — results = 1 + MeatMax,
  vanilla AddResult has no bounds check against MAXIMUM_RESULTS=10; GreatWhiteShark
  (MeatMax=10) sits exactly at the cap; a hand-edited fish.json above that overflows.
- **`== ELEVATED_DEBUG` gating** — DebugLogs=3 silently disables verbose logging
  (10 sites in geb_CatchingContextFishingRodAction.c).
- **Per-cast log I/O** — GebsfishLogger opens/closes the log file per line, and the pool
  dump iterates the duplicate-expanded probability array (one row per weight point).
- **`GetSpeciesWeatherMultiplier` recomputed per duplicate array entry** rather than per
  species (`geb_CatchingContextFishingRodAction.c:234-257`).
- **Deadfall double-init** (`gebsfish.c:25`) — Deadfall's InitYieldBank calls super (which
  itself invokes the yield-init invoker); the six other worlds deliberately don't.
- **ClearAllRegisteredItems leaves stale sync indices** (`geb_missionbase.c:13,20`) —
  vanilla clear empties the map but not m_OrderedHashes; 15 vanilla registration indices remain.

---

## Docs — README / CHANGELOG stale

- README documents `GeneralSettings.BaitPreferenceEnable` (README:153-155) — field does
  not exist; the real toggle is `Enable` at top level of bait.json. The same stale name is
  baked into generated bait.json via `MultiplierInfo` (`gebsfishConfig.c:189`).
- README fish.json example (README:86-109) is the pre-refactor schema: keyed object
  instead of Species array, per-entry *Info fields that no longer exist, missing
  Classname/RecipeShape/ResultMain/ResultBonus, and `BiteSpeed` shown as a JSON float
  array — copying that crashes JsonFileLoader (must be a space-separated string).
- README:72 — "~1,800 bait/fish pairings" now 682 (11 bait rows x 62 fish); "shrimp
  attract reef fish" — no Shrimp bait row exists.
- README:74 — net "catches ... shrimp depending on water environment" — seeder has no
  shrimp/sea entries; all three seeds are Environment=1 (pond).
- README:64/70 — bass dawn claim inverted (BiteCrepuscular peaks at dawn, DawnMultiplier
  1.4); muskie midnight claim inverted (BiteTwilightNight hour-0 = 0.85, slowest 11:00-14:00).
- README:12-13 badges (Mod v3.3.0 / DayZ 1.28) vs CHANGELOG newest section v4.0.0 /
  "1.29 compatibility" — disagree on both numbers.
- CHANGELOG v4.0.0: "predator spawn chance 25% -> 5%" (actual defaults 1%); "BaitPreferences[]
  on the global config" (named Preferences, lives in bait.json); "24 baits ... 1,896-entry
  table" (now 11 rows / 682); "Spotted Bass (replaces Black Bass)" (geb_SpottedBass exists
  nowhere; geb_BlackBass shipped, and the next line contradicts it); Known Issues claims
  faster knife timing and storm/night/bait buffs are disabled (all are live and on by default).

---

## Cleanup / dead code

- `scripts/4_world/entities/vehicles/inheritedboats/geb_jonboat.c` — entire file is one
  commented-out block (with a SparkPlug/Sparkplug mismatch inside it).
- `GebsAsciiArt.Write` never called; `GebsfishRPC` enum unused (CF string-named RPCs used
  instead); `GebsfishLogger.SetMinLevel` / `Reset` never called.
- `geb_preparefishbase.c` — no-op `CanDo`/`Do` overrides that only `return super...`;
  `PrepareCarp`/`PrepareMackerel`/`PrepareWalleyePollock` Init() bodies are near-identical
  40-line copies not using the shared helpers.
- Duplicated "is it in a preserving container" hierarchy walk drifted
  (`geb_ediblebase.c:189-200` vs `:247-258` — one includes geb_MinnowBucket, one doesn't).
- `geb_actionfishingnet.c:222-223` comment says net predator chance "much lower than
  fishing (0.01 vs 0.05)" — both defaults are 0.01.
- `geb_predatorspawner.c:228-241` — `BroadcastPredatorMessage` only messages the
  triggering player, name/docs say broadcast.
- `geb_catchyielditembase.c:3-6` — modded constructor re-runs `m_BaseWeight = ...; Init();`
  on top of the vanilla ctor chain, so Init() executes twice per yield item.
- `geb_catchingcontextbase.c:36` — `!= ""` check can never be false (accessor returns
  "<unresolved>", never "").
- Commented-out leftovers: `geb_missionserver.c:8-10` (RPC registration),
  `gebsfish.c:82-90` (AlteriaData block); unused local `player` in `geb_actiondigworms.c:57`;
  mangled header URL in `containers.c:8`.
- `containers.c:118-124` — geb_MinnowBucket lacks the IsContainer()/self-nesting guards
  its three sibling containers have; allow list uniquely includes "Shrimp".
- Null-guard gaps (edge-case): `geb_missionbase.c:60,75`; `containers.c:256`;
  `geb_crafthookfromwire.c:63`; `geb_repairfishingpole.c:47-53`; `geb_missionserver.c:32-33`.

---

## Not audited

- Config/asset cross-check (model/texture/rvmat paths vs files on disk, scope-2 classes
  missing displayName, orphaned assets) — that audit pass was stopped before it ran.
