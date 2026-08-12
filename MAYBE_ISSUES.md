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

---

## Design / logic issues (decide intent, then fix)

- **geb_KingCrab / geb_SnowCrab IK registration still missing** (`geb_dayzplayercfgbase.c:48-49`) —
  both are live catchables with fillet results.

---

## Cleanup / dead code

- `GebsAsciiArt.Write` never called; `GebsfishRPC` enum unused (CF string-named RPCs used
  instead); `GebsfishLogger.SetMinLevel` / `Reset` never called.
- The two "is it in a preserving container" hierarchy walks in `geb_ediblebase.c` differ:
  the Edible_Base rot-pause list includes geb_MinnowBucket, the Worm aging-pause list
  doesn't. NOT a live bug — the bucket's allow list rejects worms/insects, so the aging
  walk can never encounter one there. A defensive add only; decide if wanted.
- `geb_catchingcontextbase.c:36` — `!= ""` check can never be false (accessor returns
  "<unresolved>", never "").

---

## Not audited

- Config/asset cross-check (model/texture/rvmat paths vs files on disk, scope-2 classes
  missing displayName, orphaned assets) — that audit pass was stopped before it ran.
