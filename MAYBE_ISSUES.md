# MAYBE_ISSUES — repo audit findings

Living list of unresolved maybe-issues. Delete entries as they are resolved.
Last full audit: 2026-08-18 (scripts, configs, stringtable, seeded pools, asset
paths, wiki data — binaries excluded).

Both criticals from the 2026-08-11 audit (yield Init-ordering, recipe
Init-ordering) are **fixed and verified in code** — `SetConf()` now applies the
conf itself in `geb_YieldFishGeneric` and `GebPrepareFishData` — and have been
deleted per the rule above.

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

### 2. All data-driven fish recipes share one ClassName
- Every `GebPrepareFishData` instance registers into vanilla's
  `m_RecipeNamesList` under the same key (`map.Insert` by `ClassName()`,
  PluginRecipesManager.c:446), so ~70 registrations collide on one entry.
- Verified against vanilla on P:\ that the map is only read by
  `RecipeIDFromClassname` / `UnregisterRecipe`; actual crafting resolves by
  recipe ID, which is unique per instance. Nothing in the mod or vanilla calls
  the by-name path for these. Only matters if some other mod ever does.

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
