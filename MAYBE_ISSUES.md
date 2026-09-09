# MAYBE_ISSUES — repo audit findings

Living list of unresolved maybe-issues. Delete entries as they are resolved.
Last full audit: 2026-08-18 (scripts, configs, stringtable, seeded pools, asset
paths, wiki data — binaries excluded).

The 2026-09-09 gameplay fixes are applied in source. Custom fish now share one
registration, resolve live settings per craft, and roll outputs at execution.
Runtime acceptance checks are recorded below.

---

## Open — needs a decision

### 1. Version stamps disagree
- Code says `3.3.2` consistently (`constants.c` `VERSION_GEBSFISH`, `mod.cpp`,
  root `config.cpp`).
- `CHANGELOG.md` heads `v4.0.0 — Unreleased`; the wiki badge and banner say the
  current Workshop release is `v3.3.0`.
- Not a bug — the release simply hasn't been cut — but the `3.3.2` stamp needs
  bumping to `4.0.0` when it ships, in all three code spots at once.

## Watch — verified benign, keep in mind

### 3. Seventeen species sit in no bait category
- All invertebrates/shellfish (lobsters, crayfish, snail, clam, jellyfish,
  shrimp…): every bait multiplier stays 1.0 for them.
- Reads as intentional (the preference matrix targets fin fish). If crays are
  ever meant to favour worms/jigs, they need a category row in
  `EnsureCategories()`.

### 4. Rod-holder slots are referenced but never defined
- `FishingRod_Base_New` adds `fishingpole` + `fishingrod1`–`fishingrod10` to
  `inventorySlot[]`. No CfgSlots in this mod or vanilla defines them — they are
  cross-mod compat with rod-holder/rack mods and are inert without one.
  Intentional; listed so nobody "fixes" it.

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
