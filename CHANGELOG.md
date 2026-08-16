# Changelog

## v4.0.0 — Unreleased

### Requirements & Compatibility

- DayZ 1.29 compatibility
- **Community Framework (CF) is now a required dependency** — the RPC system migrated to CF's RPCManager
- `DZ_Weapons_Melee` added as a required addon; all fish now have melee functionality (matching vanilla)
- New map yield support: Sahrani, Artseinen, MelkartV2, and Deadfall (credits: DapperDan)

### New Systems

- **Weather catch buffs** — global rain / storm / time-of-day multipliers in `WeatherSettings`, plus per-fish Rain/Storm/Dawn/Day/Dusk/Night multipliers on every species (trout favour rain, walleye / pike / catfish favour night, sturgeon favours storms). A stacked-multiplier cap prevents storm + night from compounding past 2.0x. Fishing rod description hints at the mechanic
- **Moon phase** — accurate synodic phase (Meeus Julian Date algorithm) computed from the in-game date drives a night-only catch buff: full-moon nights up to +20%, new-moon nights down to -10%. Independently toggleable
- **Water temperature** — per-fish `TempOptimal` / `TempMin` / `TempMax` (degrees C) form a bell curve seeded from ecological buckets (cold deepwater, cold, cool, warm, tropical). Ambient air temperature serves as the water proxy, and a global `WaterTempOffset` shifts the whole curve for winter maps (e.g. Sakhal `-5`) or tropical servers (`+5`) without editing every fish
- **Bite-speed cycle scaling** — every fish carries a 24-hour `BiteSpeed` curve tuned to its real-world circadian pattern; the catching system aggregates the active pool (weighted by abundance and time of day) to drive how long you wait between bites
- **Bait / lure preference matrix** — every bait and lure carries per-fish multipliers that bias which fish takes the hook: worms and insects favour panfish and trout, soft-plastic worms favour bass, live minnow and salamander favour pike / musky / walleye, spinnerbaits favour bass / pike / musky, spoons favour trout and salmon, jigs favour bass / walleye. Numbered lure variants share one family entry (`geb_SpinnerBait` covers `geb_SpinnerBait1-4`; an exact numbered entry still overrides). Roughly 700 seeded pairings, all overridable in JSON, master `Enable` toggle at the top of `bait.json`. Final pick weight = CatchProbability x weather x time-of-day x bait
- **Hook-from-fish recovery** — filleting a fish has a small configurable chance (default ~1/250) to recover a damaged hook or lure "stuck in the fish"; the hook pool, weights, and health range are admin-tunable
- **Cooler freezer system** — coolers keep contents cold, live bait is perishable, and a frozen-fillet guard prevents prep on frozen fillets
- **Bait freshness rules** — each container has one job, and they do not overlap:
    * **Worm Container / Bug Container** — hold worms, grubs and insects, and pause the ~90 minute live-bait death timer
    * **Cooler** — pauses both food rot and the live-bait timer for anything inside
    * **Bait Bucket** — holds small aquatic catches only (minnows, crayfish, shrimp, frogs, salamanders) and stops them rotting. It does not accept worms or insects and is not a live-bait keeper
    * **Tackle boxes** — can carry bait for convenience but preserve nothing
    * Artificial lures (rubber worm and all hard baits) never perish
- **Predator spawn rework** — three independent gates (per-action chance, weighted predator pick, per-predator min/max count) with separate chance values for fishing, filleting, failed casts, and net use. Land-only spawn search (no underwater wolves), optional warning sound RPC, configurable chat warning
- **Per-action config sections** — `BambooFishingNetSettings`, `DigBugsSettings`, `DigWormsSettings`, each owning its `FindChance` (per-attempt probability of finding anything) and a weighted `Catches[]` table. Tool wear still applies on a miss
- **Configurable net catches** — net spawn table entries carry an `Environment` field (1 pond, 2 sea, 3 both) for per-environment filtering; catches spawn into the net's cargo (4x4) first, falling back to the player's feet when full. New bamboo net repair recipe: one Netting + a damaged net restores it to Worn

### Config Overhaul

- `fishingsettings.json` replaced by four self-documenting files in `$profile:Gebs/`: `general.json`, `bait.json`, `junk.json`, `fish.json`. **Clean break — no migration**: servers regenerate fresh defaults and re-apply their custom tuning by hand
- Fish are fully data-driven: one `Species` row per fish (classname, recipe shape, fillet/caviar/lobster results, meat counts, environment, catch method, catch probability, weather multipliers, temperature preference, BiteSpeed curve) feeds a single generic yield + fillet-recipe pipeline
- Master enable toggles for every catch-modifying system — disabled systems keep their tuned JSON values with no in-game effect
- Bait multipliers are written rounded to the nearest 0.01, so the file shows clean values instead of float noise
- Missing config sections re-seed with fully populated defaults; all four files carry a `ConfigVersion` stamp for future migrations
- Detailed admin-facing documentation strings on every field, kept under the engine's JSON string-length crash ceiling
- **How the config updates itself** — worth reading once before you tune anything, because it decides which of your edits survive a mod update:
    * Each of the four files carries its own `ConfigVersion`. On startup a file is only rewritten if something actually changed: a fresh generation, a section that had to be re-seeded, or a version bump. An up-to-date file is left completely alone — no rewrite, no modified timestamp
    * **A version bump rewrites all four files, not just the one that changed.** The stamp is per-file and every file compares it, so bumping the mod version touches `general`, `bait`, `junk` and `fish` even when only one of them gained anything. Your values are carried through untouched — the file is re-serialized from what was loaded, not regenerated from defaults
    * **Your existing values are never overwritten.** The update is strictly additive: default entries missing from a list get inserted, entries already there are left exactly as you set them
    * **Deleting an entry is not how you disable it.** A row you remove is treated as missing and gets re-added on the next version bump. To retire something permanently set its weight / chance / `CatchProbability` to `0` — that survives every update. A whole section emptied on purpose is respected; a section that is entirely absent gets re-seeded
    * **New on/off toggles are re-applied during migration.** The engine's JSON loader zeroes any field your file doesn't mention rather than using the built-in default, so a toggle introduced in a later version would otherwise arrive switched off on every existing server. Migrating from a version older than the one that added it restores the intended default; once your file is stamped at or past that version, a toggle you turned off stays off through every future update
    * Pre-3.3 layout files (`fishingsettings.json`, `Fish/Logs/`, `extras/mpmissions/`) are swept into `$profile:Gebs/gebs_oldfiles/` on first start so old and new never sit mixed together, and the emptied folders are removed afterwards. Nothing from the old monolithic config is migrated into the new files — it is archived so you can still read your old tuning

### New Fish & Creatures

- Hammerhead Shark
- Lake Sturgeon (with roe -> new Black Caviar item)
- Alligator Gar
- Muskellunge, Barred Muskellunge, Tiger Muskellunge, Spotted Muskellunge
- Northern Snakehead
- Neosho Bass, Striped Bass
- White Grunt, Southern Flounder, Yellow Snapper
- American Bullfrog, Red Salamander
- New Crayfish variants: Cave, Florida, Monongahela, Red Swamp, Rusty
- Northern Pike gains roe -> new Yellow Caviar item

### New & Reworked Models

Major art pass across the existing roster — new or reworked models and textures for:

- Northern Pike, Bluegill, Red Breast Sunfish, Yellow Perch, Fathead Minnow, Sauger, Walleye
- Brown / Brook / Rainbow / Cut Throat Trout, Lake Trout, Chinook Salmon
- Black Bass, Bonito, Bowfin, Large Mouth Bass, Small Mouth Bass, White Bass
- Blue Marlin, Sailfish, Humphead Wrasse, Yellowfin Tuna
- Asian Sea Bass, Siamese Tigerfish, Angelfish, Pacific Cod, Perch, Severum, Rougheye Rock, Red Head Cichlid, Blue Tang
- Snow Crab + Snow Crab Legs, Blue Jellyfish, Black Devil Snail, Mussel, Starfish, Blood Clam

### New Vehicle

- **Jon boat** — new drivable flat-bottomed boat with five variants (green aluminum, gray aluminum, desert / snow / forest camo), custom damage zones (chassis, engine, three floaters), SparkPlug slot, and cargo space. More boat content coming in a future update
- **Jon boat deck mounts** — two deck slots that take any cooler or tackle box and show it sitting on the deck. Both accept the same families so you can run two coolers, two boxes, or one of each. The vanilla jerry can is deliberately not included: a proxy gives one position and rotation to everything attached to it, and the can's model axes don't match the gebsfish containers, so no single orientation suits both

### New Items & Crafting

- Grub Worm (chance to find when digging for worms)
- Coolers in 12 colors (with the freezer system)
- **Wooden Fish Mount** — a trophy plaque you hang on a wall and mount your catch on:
    * **Crafted** from **1 Wooden Plank + 1 Metal Wire**, with a **Hacksaw** on you. Combine the plank and wire; the saw isn't consumed but takes durability, and the craft is refused without one. (DayZ caps recipes at two ingredients, so the saw is enforced as a tool rather than a third slot.) Disable it with `RecipeToggles.CraftFishMount` in `general.json`
    * **Placed on walls** — hold to place and it snaps flat against any near-vertical surface, hanging face-out like a picture. Aim somewhere without a wall and it falls back to normal ground placement
    * **The trophy is the actual fish** you caught, not a generic model — its weight and quality persist through the attachment, so a personal-best catch stays a personal-best on the wall
    * **Mounting is permanent.** Once a fish is on the plaque it can't be detached, dragged out, or taken to hands. Ruined and rotten fish are refused up front. The only way to recover a mounted fish is to destroy the mount, which drops its attachment like any ruined container — this is deliberate, so the plaque can't double as a free never-rots fish locker
    * **Mounted fish never rot.** Decay is paused entirely while the fish is on the plaque, so a trophy is taxidermy rather than a countdown
    * **The plaque itself lasts 45 days** untouched — the same lifetime as tents and barrels rather than the 2-hour gear lifetime, so wall trophies persist like a base fixture and abandoned ones clean themselves up on the same schedule
    * Placeholder model until the final plaque p3d lands
- Craft metal hook from metal wire + pliers
- Bamboo net repair recipe (Netting + damaged net -> Worn)
- New Bamboo Fishing Net model and full texture set

### New Tackle & Lures

- 4 Spoon Lures
- 4 Curly Tail Jigs
- Spinner Baits 1-4 (new models)
- Squarebill Lure (replaces Lure4)
- Yellow Crank, Purple Crank, Popper lures (replace old lures)
- New Small Tackle and Large Tackle models
- New Worm Container and Bait Bucket models

### Balance

- **Realistic catch probabilities** — all 79 fish `CatchProbability` defaults reflect real-world abundance and bite habit: bait / abundant 20-25, common gamefish 12-18, uncommon 7-11, trophy / rare 2-5
- **Realistic fish weights** — 63 fish `weight` values rebalanced against real-world adult catch sizes: panfish / reef fish dropped (BlueGill 1700 -> 400 g), trophy pelagics raised (GreatWhiteShark 3700 -> 20000 g, Blue Marlin -> 15000 g), pike / muskellunge and trout / salmon families tiered by species. Landing the largest pelagics now carries real encumbrance — by design
- **Ecology pass** — White Bass and Bowfin moved to behaviorally correct bait-preference buckets; 12 fish `Environment` values corrected (anadromous salmonids, Striped Bass, Barramundi, mullet, and gar now appear in both fresh and salt water; three freshwater species un-misclassified from saltwater)
- Default predator spawn chance reduced from 25% to 1% per action
- Geb fish knives: +54% durability over vanilla HuntingKnife and 10% faster filleting (configurable via `FishKnifeSpeedMultiplier`)
- 30% keep-chance for caviar when filleting roe fish (configurable via `CaviarChance`)
- Small crustaceans and minnows can now be caught in large traps
- Fishing rods repair to Worn at best; Ruined tools can no longer be repaired
- Adjusted bait bucket size

### Localization

- New stringtable entries: Hammerhead Shark, Lake Sturgeon, Cooler, Wooden Fish Mount, Craft Metal Hook, Rougheye Rock
- Jon boats now display "Jon Boat" with a proper description in all 14 languages (previously vanilla "Rubber Boat" and a missing description key)
- Minnow Container renamed to Bait Bucket, name retranslated in all 14 languages
- Orphaned rows pruned (fillet keys for species without fillet items, superseded king crab tail, generic clothing descriptions replaced by per-color keys, unused tackle box name)

### Code & Internals

- Replaced all `GetGame()` calls with `g_Game` for consistency
- Removed invalid `ref` keywords from RPC handler parameters (CF compatibility)
- Data-driven pipeline: one generic catch yield and one generic fillet recipe seeded per Species row replace 79 per-fish yield classes and per-fish recipe classes (vanilla fish keep their modded Prepare* overrides)
- BiteSpeed data consolidated from 79 inline 24-hour arrays into 8 named circadian curves
- Weighted-pick logic consolidated into a shared `GebWeightedPick` helper; the catch pick memoizes per-species weather/bait multipliers instead of recomputing per pool entry
- Yield bank init no longer registers vanilla's 15 default yields just to clear them (vanilla's clear leaves stale sync indices); re-entry guard prevents double registration on worlds that fire the init twice
- XML generators: types.xml emits each classname exactly once and only geb_-prefixed entries (no more collisions with the mission's own types.xml); spawnabletypes chance values formatted correctly; generation batched, version detection hardened, files no longer regenerate every restart, server-only guard
- Logger: filename sanitization, `Reset()`, initialization fix; `DebugLogs` values above 2 clamp to elevated instead of silently disabling verbose logs
- Logger no longer holds the session file handle open. Enforce exposes no flush, so `CloseFile` is the only thing that commits bytes to disk — opening and closing around each write means a hard crash can't take the tail of the log with it, and the file stays unlocked so it can be read or moved while the server is running
- Log retention: session logs older than 3 days are deleted at startup, so an unattended server stops accumulating one file per restart. Age is read from the filename (the generator owns the `YYYYMMDD-HHMMSS_tag.log` format) because Enforce's file API exposes no modification time; anything that doesn't parse as that format is left untouched, and the live session file is never a candidate
- Old-layout migration now removes the folders it empties. After sweeping `fishingsettings.json`, `Fish/Logs/` and `extras/mpmissions/` into `gebs_oldfiles`, the emptied `Fish/` and `extras/` trees are deleted deepest-first. Enforce has no remove-directory call, so this depends on the engine accepting an empty directory — each folder is confirmed empty before the attempt, and any that survive are logged by path for manual cleanup instead of a blanket "delete these yourself" message
- Craft and repair recipes (bamboo net, fishing pole, hook from wire) now register before the data-driven fish loop. `RegisterRecipe` hands out sequential IDs and actions send that ID over the network, so anything registered after a variable-length loop shifted by however many species that side happened to register
- In-hands IK registrations collapsed to three name-array loops
- Consolidated repeated classes into shared base files; sorted large files by category; standardized brace style
- Replaced `Param3` usage with `XmlTypeEntry` class for clarity
- Added base classes and inheritance cleanup for containers; all four bait containers now share the same self-nesting guard, and redundant `IsContainer()` overrides (vanilla `Container_Base` already returns true) were removed
- Vanilla-fish fillet recipes (Carp / SteelheadTrout / Mackerel / WalleyePollock) collapsed from four near-identical ~40-line Init bodies into one shared `SetupVanillaFilletRecipe` helper on `PrepareFish` — they now get the same MeatMin/MeatMax inversion guard, `MAXIMUM_RESULTS` clamp, and caviar-chance logic as every other fish; no-op `CanDo`/`Do` overrides deleted
- Renamed `Sturgeon` -> `LakeSturgeon`; `OldTackle` model files -> `MediumTackle` (class names finalized next wipe); Bug Container moved from `data/tools/` to `data/tackle/`
- Predator chat-warning code and docs renamed to match reality: the message goes to the triggering player only (the warning sound is what nearby players hear)
- Removed a redundant modded `YieldItemBase` constructor that made every yield item run `Init()` twice per construction
- All p3ds now use a `Camo` hidden selection to support retexturing
- Asset naming pass: tool and clothing textures renamed to engine conventions (`_co` / `_normals` / `_smdi`); fish knife and big-game fishing line materials updated
- Added skinning action to Neosho Bass and Striped Bass

### Fixed

- **Fish catches and modded-fish filleting were both broken.** Vanilla's `YieldItemBase` and `RecipeBase` constructors call `Init()` themselves, so `Init()` ran before the per-species row could be handed over and bailed on its null guard — and registration never runs it again. Every fish yield registered with an empty type and zero environment/method masks, and since the yield bank keys on the type hash, all 79 species collapsed onto one empty entry matching nothing: junk was the only possible catch. The data-driven fillet recipes likewise registered with no ingredients and no results, so no modded fish offered a Gut action (the four vanilla fish kept working through their own `Prepare*` overrides). Setup now applies from the setter instead of relying on constructor-time `Init()`
- Clients registered zero fillet recipes: the config left the Species table null on clients until the `ConfigSync` RPC, which lands after `PluginRecipesManager` has already registered. Clients now seed the compiled defaults in memory, and the RPC still overwrites them with the server's file
- Jon boat deck attachments were invisible — the model carried the proxies and the config declared the slots, but nothing tied the two together. Added the `ProxyAttachment` entries that bind each proxy to its slot. They must live in `CfgNonAIVehicles`; in `cfgVehicles` the base class resolves to a new empty one and the malformed entries break the boat's crew config, locking players out of both seats
- Wooden Fish Mount placement hologram rendered as the normal textured plaque instead of the white ghost: `placing` was listed in `hiddenSelections[]` but never declared as a section in `Model.cfg`, so the hologram material had no swappable selection to land on. The deployable/undeployable materials also needed vanilla's `Super` shader and full stage chain — flat `Normal`/`Basic` with no stages loses the fresnel sheen that makes a hologram read as one
- Wooden Fish Mount couldn't be placed on walls despite the wall-snapping logic working: `EvaluateCollision` rejected it through `IsFloating`, `IsBaseViable`, `IsClippingRoof` and `HeightPlacementCheck`, all of which assume ground placement, and `yawPitchRollLimit` capped pitch at 89 degrees — one short of flat against a vertical wall. Player collision, permitted-area, underwater and in-terrain checks still apply
- Jon boat no longer plays the vanilla rubber boat's engine shutdown sound when the engine cuts, including when stepping out of the driver seat. `BoatScript` hardcodes Boat_01 soundsets for every boat, so the jon boat now has its own script class that suppresses it
- XML generator crash at startup: `FPrint` without newlines produced a single-line 85 KB file that overflowed the engine's line-read buffer as fish were added — generators now emit proper line breaks
- Bait preferences and the temperature curve now apply independently of `WeatherCatchBoostEnable` — previously the weighted catch pick only ran when the weather toggle was on, silently disabling both systems despite their own toggles
- BiteSpeed aggregate no longer applies `CatchProbability` twice (the probability pool already repeats each fish by its weight) — abundant fish were quadratically dominating the bite-cycle timing over rare ones
- Rods no longer take double durability damage per catch outcome — a leftover duplicate `AddHealth` call made rods wear at 2x the intended 1.5 HP
- Hardened edge-case null handling: junk-yield registration now logs and skips (instead of crashing at mission init) when the config failed to load; cooler tick, hook-crafting check, rod-repair plugin lookups, and the debug yield dump all guard references that could be null in broken states
- Dug bugs now spawn as networked objects (were server-local and invisible to players); dig-bugs also wears the tool and trains soft skills on every completed dig, matching dig-worms
- Generated spawnabletypes chance attributes were the literal text `.2f` instead of numbers
- Predator warning chat message sends once through the first enabled color instead of once per enabled color
- Recipe result count clamped to the engine cap so an oversized `MeatMax` in a hand-edited fish.json can't corrupt memory
- Multiplayer check in `TryDamageItems`
- Config sync and predator sound RPCs
- Net not taking damage when used
- Grub worm digging; vanilla worm fallback when the grub entry is removed from config
- Sauger normal map re-enabled; Sturgeon rvmat typo; Blue Marlin normals; Tacklebox normals; Hammerhead Shark materials mapping
- Fillet textures (Chinook Salmon, Sailfish, Humphead Wrasse, others); fillets showing as wrong fish or blank; old extra Bluegill fillet texture; Fathead Minnow rotten fillet bug
- Crayfish position in inventory; crayfish becoming invisible after cooking; fixed crayfish rotten texture
- Lobster Tail on ground / in inventory / in hand; lobster can be cut on the ground
- Bonito hand position; two-hand fish positioning (mostly — slight inventory orientation issue remains)
- Scope on base classes so they no longer spawn in
- p3d selections renamed to `Camo` where missing; `FlatHeadMullet` classname typo; Grasshopper texture naming convention
- Missing semicolons causing config parse errors
- Boat sound issue; Mahi Mahi LOD texture disappearing at distance
- Duplicate bamboo net recipe removed; crafting hook from wires
- Repeated tackles removed from spawnable types; missing clothes added to typesxml

### Removed

- `fishingsettings.json` and its one-time migration (replaced by the four-file config, clean break)
- Bundled trader/economy support files (`Expansion` market configs, TraderPlus configs, Dr. Jones price list, classnames list, pricing calculator)
- Old expansion files
- Old README
- Fishing Calc (outdated)
- Old `newtackle` textures
- Old lure models (replaced by crank/popper variants)
- Unreferenced normal-map textures (6.4 MB)
- Dead code purge: fully commented-out jon boat script file, Alteria world-data placeholder block, commented-out RPC registrations, unused locals, and no-op recipe overrides

### Known Issues

- Two-hand fish inventory orientation is slightly angled
- King Crab and Snow Crab have no in-hands carry pose yet
- Unreleased-build regressions under investigation (tracked in MAYBE_ISSUES.md): the data-driven yield and recipe registration runs before each entry's config row is attached

## v3.3.0

### Added or Changed

- New Creatures
    * American Lobster
    * European Lobster
    * Snow Crab
    * Signal Crayfish
    * European Crayfish
- Updated stringtables to add new items and remove items
- Updated yield script to include super
- Added small crustaceans to be allowed in the minnow bucket
- New LODs, RVMATs, and normals to every fish
- Added versioning to the xml generation
- Added repair kit for fishing rods
- New models for:
    * Old Tackle Box
    * Great White Shark
    * Large Mouth Bass
    * Small Mouth Bass
- Added bone min/mzx for crustaceans
- Added new worm and grub textures
- New licence for the mod
- Crayfish, Mussels, and Bloodclams are now food that can be eaten raw or cooked
- Changed sizing on crayfish to fit the model better
- Config update to change min/max to intergers instead of floats
- Recipe name change from CraftWoodNet to CraftBambooNet
- Updated the Types&classnames folder to .types within the mod folder

### Removed
* CrayFish
* CrayFishTail
* Lobster
* LobsterTail
* LobsterFilet
* KingCrabFilet
* BloodClamFilet
* MusselFilet

### Known Issues
- Grub Worm and Rubber Worm show as regualr worm when on hook

## v3.2.1

### Hotfix 1
- RPC bug fix (thanks DannyDoomNo1 for direction)
- Fixed mispelling of AtlanticSailfish meat

## v3.2.0

### Added or Changed
- Updated config to reflect classname changes in last update that we overlooked
- Revamped the junk config to add probability to it to change each junk items rarity
- Added predator messages to stingtable for proper localization
- Fixed client-server config sync
- New debugging messages to help troubleshoot issues on servers
- Revamped several textures for fish and items
- Reworked the predator spawn system to prevent predators being spawned under water
- Fixed an issue with minnows being able to be used as infinite bait. Minnows are now removed like other bait
- Types and Spawnable types now generate in $profiles/Geb/Extras/
- Added map support for:
    * Banov
    * Namalsk
    * Lux
    * Deer Isle
    * Sahinkaya


## v3.1.0

### Added or Changed
- New models for Blue Tang, Blood Clam, and Mussel
- Classname updates
    * Catfish -> FlatheadCatfish
    * Trout -> RainbowTrout
    * Perch -> YellowPerch
    * Minnow -> FatheadMinnow
- Stringtable fixes for Simplified Chinese
- Fixed implementation for Livonia and Sakhal maps
- Moved config location from $profiles/gebsfish to $profiles/Geb to standardize files as we rework older mods
- Config updates
- General code cleanup and refactoring to make it more extensible and easier to maintain in the future. 


## v3.0.0

With 1.26, Bohemia completely changed the fishing system in DayZ. This update brings the mod in line with those changes. 

### Complete New Fishing System
- Reworked all the gear to work with the new system. 
- Added minnows as bait
- Fixed knife model positions in the hand
- New predator system to make fishing less safe
- New fish config to control catch rate and meat when processed 
- New junk config to configure your own junk items easily
- Logging system for troubleshooting
- Overall code imporvements
