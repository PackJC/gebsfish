# File-generation upgrade: old-file archiving + additive JSON merge

Working notes for the config/file-generator upgrade. **No commits — Cole commits.**
Update the checkboxes at the bottom as work lands so a future session can resume.

## Goal (Cole's request, 2026-08-12)

1. **Archive old-update files.** On server start, the generator detects files from
   the *previous* mod layout inside `$profile:Gebs` and moves them into
   `$profile:Gebs/gebs_oldfiles/` instead of leaving them mixed with the new files.
2. **Additive, non-destructive JSON updates.** When a mod update adds content
   (e.g. a new fish), the loader must **add the new entries to the existing
   .json files** — never wipe them, never rename them to `_old`. Admin-tuned
   values are always preserved. Applies to **every** JSON in the new build.

## Current layout (facts, verified in code)

- Configs (all in `scripts/3_game/FileGenerators/gebsfishConfig.c`):
  - `$profile:Gebs/general.json` → `GeneralConfig` (sections + 5 entry arrays:
    `Predators`, `BambooFishingNetSettings.Catches`, `DigBugsSettings.Catches`,
    `DigWormsSettings.Catches`, `HookFromFishCatches`)
  - `$profile:Gebs/bait.json` → `BaitSettingsConf` (`Preferences`: array of
    `BaitConfig { BaitClassname, Preferences: array of BaitPreferenceEntry
    { FishClassname, Multiplier } }`)
  - `$profile:Gebs/junk.json` → `JunkConfig` (`Junk`, `ContainerJunk`)
  - `$profile:Gebs/fish.json` → `FishConfig` (`Species`: array of `FishConf`,
    keyed by `Classname`; `FishConfig.Get(classname)` exists)
- Facade `gebsfishConfig.LoadAll()` (same file, ~line 589) loads all four on the
  server only. Entry point: `GetGebSettingsConfig()`.
- Version: `VERSION_GEBSFISH = "3.3"` in `scripts/3_game/constants.c`. Every
  file stores `ConfigVersion`; every `Load()` already has the hook point:
  `if (ConfigVersion != VERSION_GEBSFISH) { ... changed = true; }`.
- Current `Backfill()`s only seed **wholly missing/null sections** — a new fish
  added to the defaults today would NOT appear in an existing fish.json. That's
  the gap being fixed.
- Old-update layout (seen in Desktop `Gebs_old`, which is a copy of an old
  profile `Gebs` folder — real location is always `$profile:Gebs`):
  - `Gebs/fishingsettings.json` (old monolithic config; superseded — we do NOT
    migrate its values, by prior decision)
  - `Gebs/Fish/Logs/*.log` (old logger dir; new logger uses `Gebs/logs/`)
  - `Gebs/extras/mpmissions/gebsfish-types.xml`, `gebsfish-spawnabletypes.xml`
    (old xml output dir; new generators write `Gebs/mpmissions/`)
- DayZ engine constraints: string members > ~1024 chars crash JsonLoader (keep
  literals < ~900); no directory-delete API in EnforceScript (moving a folder =
  move its files, the empty husk stays); file move = `CopyFile` + `DeleteFile`;
  wildcard listing via `FindFile`/`FindNextFile`/`CloseFindFile`.

## Design

### A. Old-file archiving — new `GebsfishMigration.c`

New static class `GebsfishMigration` in
`scripts/3_game/FileGenerators/GebsfishMigration.c`:

- `static void ArchiveOldFiles()` — called from `gebsfishConfig.LoadAll()`
  (server branch, before the four `Load()`s).
- Detects, and moves into `$profile:Gebs/gebs_oldfiles/`:
  - `fishingsettings.json` → `gebs_oldfiles/fishingsettings.json`
  - every file in `Fish/Logs/` → `gebs_oldfiles/Fish_Logs/<name>`
  - every file in `extras/mpmissions/` → `gebs_oldfiles/mpmissions/<name>`
  - (wildcard sweep so stray/renamed old files still get caught)
- Creates `gebs_oldfiles/` (and subdirs) only when something old actually
  exists — a clean install never grows the folder.
- Empty old husk dirs (`Fish/`, `extras/`) cannot be deleted from script; log
  one INFO line telling the admin they're safe to delete manually.
- Every move logged via `GebsfishLogger.Info(..., "Migrate")`; failures via
  `GebsfishLogger.Error` and the source file is left in place (never delete
  without a verified copy).

### B. Additive merge — `MergeNewDefaults()` per config class

Trigger: **only when `ConfigVersion != VERSION_GEBSFISH`** (i.e. once per mod
update), inside each `Load()`, before the version is restamped. Rationale: if
we merged every boot, an admin deleting a default entry would see it resurrect
constantly. With version-gating, deletions stick for the whole version; the
documented way to remove content permanently is weight/probability `0`, not
deletion.

Merge = *insert what's missing, never touch what exists*:

- `FishConfig.MergeNewDefaults()`: build a temp `FishConfig` + `SeedSpecies()`;
  for each default `FishConf` whose `Classname` isn't in `Species` → insert.
- `JunkConfig.MergeNewDefaults()`: temp seeds; merge `Junk` and `ContainerJunk`
  by `Classname`.
- `GeneralConfig.MergeNewDefaults()`: temp `SeedDefaults()`; merge by
  `Classname`: `Predators`, `BambooFishingNetSettings.Catches`,
  `DigBugsSettings.Catches`, `DigWormsSettings.Catches`, `HookFromFishCatches`.
  (Run after `Backfill()` so the arrays exist.)
- `BaitSettingsConf.MergeNewDefaults()`: temp `SeedDefaultPreferences()`; for
  each default bait row: missing `BaitClassname` → insert whole row; existing
  row → insert only missing `FishClassname` prefs. **This is how a new fish
  propagates into every existing bait table.**
- New **scalar fields** in existing sections need no merge code: JsonFileLoader
  leaves members missing from the file at their compiled defaults, and the
  version-bump `Save()` persists them into the file. Only *array entries* need
  the merge above.
- Each merge returns the number of inserted entries; log
  `"<file>: merged N new default entries (vX -> vY)"` via logger tag "Migrate".

### C. Out of scope / later

- **Pre-existing (not introduced here):** if a JSON fails to parse (corrupt
  file), `LoadFile` logs the error, the object keeps compiled defaults, and
  the version-bump save then overwrites the corrupt user file. Good follow-up:
  on parse failure, copy the broken file into `gebs_oldfiles/` (e.g.
  `fish.json.broken`) before it gets overwritten. Would reuse
  `GebsfishMigration.MoveFile` (make it public/static-accessible).

- `mpmissions/gebsfish-types.xml` + `gebsfish-spawnabletypes.xml` generators
  already regenerate; not part of this change.
- Bump `VERSION_GEBSFISH` when the next update ships (Cole decides version).
- README/CHANGELOG blurb about `gebs_oldfiles/` and merge behavior.

## Testing (do on a local server once implemented)

1. Copy Desktop `Gebs_old` contents into the server's `$profile:Gebs`, start
   server → old files end up in `Gebs/gebs_oldfiles/`, new 4 jsons generate,
   log shows Migrate lines. Husk dirs `Fish/`, `extras/` remain but empty.
2. Take a current-version `fish.json`, delete one species + hand-edit another's
   `CatchProbability`, set file's `ConfigVersion` to `"3.2"`, restart → deleted
   species re-added with defaults, edited value untouched, version restamped.
3. Same-version restart → files byte-identical (no rewrite; `changed` stays
   false).
4. bait.json with one bait row deleted and one fish pref deleted, old version →
   row and pref restored; tuned multipliers untouched.
5. Junk/general arrays: remove an entry, old version → restored on boot.

## Progress checklist

- [x] Explore code, verify layout facts above
- [x] Write this plan
- [x] `GebsfishMigration.c` — ArchiveOldFiles + move/sweep helpers (NEW FILE, done this session)
- [x] Wire `GebsfishMigration.ArchiveOldFiles()` into `gebsfishConfig.LoadAll()` (server branch)
- [x] `FishConfig.MergeNewDefaults()` + Load() wiring
- [x] `JunkConfig.MergeNewDefaults()` + Load() wiring
- [x] `GeneralConfig.MergeNewDefaults()` + Load() wiring (after Backfill)
- [x] `BaitSettingsConf.MergeNewDefaults()` (two-level) + Load() wiring
- [ ] Compile check on a dev server / workbench (NOT DONE — needs DayZ tooling)
- [ ] Run tests 1–5 above (NOT DONE)
- [ ] README/CHANGELOG note about gebs_oldfiles + additive merge (optional)

## Status log

- 2026-08-12: Plan written. Implementation done same session (all code items
  checked above). Everything left UNCOMMITTED on master per Cole's workflow.
  Remaining: in-game compile + the 5 tests, then optional docs blurb.
