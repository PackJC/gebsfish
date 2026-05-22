# Changelog

## v4.0.0

### Added or Changed

- 1.29 compatibility
- Community Framework (CF) now a required dependency; RPC system migrated to CF
- `DZ_Weapons_Melee` added as a required addon
- All fish now have melee functionality (matching vanilla)
- All p3ds now use a `Camo` hidden selection to support retexturing
- Added skinning action to Neosho Bass and Striped Bass
- Renamed `Sturgeon` -> `LakeSturgeon`
- Renamed `OldTackle` -> `MediumTackle` (class names finalized next wipe)
- Bug Container moved from `data/tools/` to `data/tackle/`
- Default predator spawn chance reduced from 25% to 5%
- 30% chance of caviar when filleting Trout or Salmon
- Small crustaceans and minnows can now be caught in large traps
- Adjusted bait bucket size
- Added cargo to the jonboat
- AmericanBullFrog and RedSalamander added to net catches (equal chance for now)
- Added stringtables for: Hammerhead Shark, Sturgeon, Cooler, Wooden Fish Mount, Craft Metal Hook, Rougheye Rock
- Sahrani, Artseinen, and MelkartV2 yield support
- **Weather catch buff system**
    * Global rain / storm / night multipliers, configurable in `WeatherSettings`
    * Per-fish `RainMultiplier` / `StormMultiplier` / `NightMultiplier` on every fish section in the config
    * Stacked-multiplier cap prevents storm + night from compounding past 2.0x
    * Default species sensitivities: trout / salmon favour rain, walleye / pike / catfish favour night, sturgeon favours storms, carp / reef fish are penalised
    * Fishing rod description hints at the mechanic
- **Per-action settings sections**
    * Each "find something" action now has its own consolidated config section: `BambooFishingNetSettings`, `DigBugsSettings`, `DigWormsSettings`
    * Each section owns its `FindChance` (0-1 per-attempt probability of finding anything) and a weighted `Catches[]` spawn table
    * The bamboo net section also owns `PredatorSpawnChance` for predators spawning after the action
    * Replaces the earlier scattered `ForageSettings.*FindChance` fields, top-level `Bugs[]` / `DigWorms[]` / `NetItems[]` arrays, and `PredatorSettings.PredatorSpawnChanceFishingNet`
    * Tool wear still applies on a miss
- **Configurable fishing net catches**
    * `BambooFishingNetSettings.Catches[]` uses a new `NetEntry` type (Classname + CatchChance + Environment) so the same table can hold freshwater and saltwater entries
    * `Environment` is 1=pond, 2=sea, 3=both -- entries that don't match the cast surface are skipped
    * Replaces the previously hardcoded minnow / frog / salamander switch
    * Seeded with the three previous classnames at equal weights (all Environment=1) so vanilla behaviour is preserved
    * Net catches now spawn into the net's cargo first (4x4), fall back to the player's feet when the net is full
    * Cargo whitelist extended to include the bullfrog and salamander so the net can hold its own catches
- **Realistic catch probabilities**
    * All 79 fish `CatchProbability` defaults updated to reflect real-world abundance and bite habit
    * Bait / abundant 20-25, common gamefish 12-18, uncommon 7-11, trophy / rare 2-5
- **Bait-fish preference system**
    * Per-bait `BaitPreferences[]` table on the global config — every bait/lure carries a list of fish it favours
    * 24 baits (`Worm`, `geb_GrassHopper`, `geb_FieldCricket`, `geb_GrubWorm`, `geb_RubberWorm`, `Shrimp`, `geb_FatHeadMinnow`, `geb_RedSalamander`, `geb_SpinnerBait1-4`, `geb_SpoonLure1-4`, `geb_Lure1-4`, `geb_CurlyTailJig1-4`) × every one of the 79 fish = a fully populated 1,896-entry preference table seeded with biologically defensible defaults
    * Multiplier > 1.0 makes that fish more likely to be the selected catch when this bait is on the hook; < 1.0 makes it less likely; 1.0 is neutral. Default range 0.3-2.5
    * Layered on top of the per-species weather + time-of-day multipliers in `PickWeightedYieldIndex`, so final weight = CatchProbability × WeatherSpeciesMul × TimeOfDayMul × BaitMul
    * Detection: rod's `m_Bait` slot (worms / live bait) is preferred; falls back to `m_Hook` (gebsfish lures self-identify as hooks via `hookType`). Unknown baits and empty hooks default to a neutral 1.0 across all fish so the system is fully opt-in
    * Worms and insects favour panfish & trout, soft-plastic worms favour bass, live minnow & salamander favour pike / musky / walleye / catfish, spinnerbaits favour bass / pike / musky, spoons favour trout & salmon, jigs favour bass / walleye
    * `DebugLogs = 2` (elevated) prints a per-cast table: `species | weatherMul | baitMul | scaled` for each fish in the pool
- **Ecology pass: bait-preference category audit + fish Environment corrections**
    * `geb_WhiteBass` moved from `PANFISH` to `BASS` bucket — behaviorally identical to other bass (schools chasing shad, hits spinners / jigs / minnows aggressively); the panfish weights were severely underweighting its lure response
    * `geb_BowFin` moved from `CATFISH_BOTTOM` to `PIKE_MUSKY` bucket — aggressive ambush predators that smash spinnerbaits and lures, far more pike-like than catfish-like in feeding
    * 12 fish `Environment` values corrected to match real-world ecology. `Environment` is a bitmask: `1` = pond, `2` = sea, `3` = both. Anadromous and catadromous species now correctly use `3` so they appear in both freshwater and saltwater rod pools
    * `Environment = 3` (both) now: `SteelheadTrout`, `CherrySalmon`, `ChinookSalmon`, `SockEyeSalmon` (all anadromous Pacific salmonids), `StripedBass` (anadromous), `AsianSeaBass` (Barramundi, catadromous), `FlatHeadMullet` (mullets routinely enter brackish/fresh), `AlligatorGar` (tolerates brackish coastal water), `Mussel` (both freshwater and marine species)
    * Three saltwater-misclassified fish corrected to `Environment = 1` (pond): `RedHeadCichlid`, `SiameseTigerFish`, `BlackDevilSnail` — all freshwater species in real life
- **Realistic fish weights**
    * 63 fish entity `weight` values rebalanced against real-world adult catch sizes. Previously many panfish/reef fish were 1.7-3 kg (too heavy) and trophy pelagic species were 1.7-3.7 kg (drastically too light)
    * Smaller fish dropped to realistic sizes: `BlueGill` / `SunFish` 1700 → 400 g, `YellowPerch` 3000 → 500 g, `AngelFish` 2500 → 300 g, `BlueTang` 2000 → 500 g, `Severum` 3600 → 600 g, `RedHeadCichlid` 3000 → 500 g, `StarFish` 2500 → 400 g, `SlimySculpin` 300 → 80 g
    * Trophy fish bumped to real-world proportions (still capped well below biological maximums for encumbrance playability): `GreatWhiteShark` 3700 → 20000 g, `AtlanticBlueMarlin` 3700 → 15000 g, `HumpHeadWrasse` / `YellowFinTuna` / `HammerHeadShark` → 12000 g, `AtlanticSailFish` 3700 → 10000 g, `AlligatorGar` 4000 → 8000 g, `ChinookSalmon` 1700 → 6000 g, `LakeSturgeon` 1700 → 5000 g
    * Pike / Muskellunge family tiered (4000 g flat → `Muskellunge` 6000, `Barred` 5500, `Spotted` 5000, `NorthernPike` 4500) so the size hierarchy reflects reality
    * Trout / salmon tiered by species (`BrookTrout` 1000 < `RainbowTrout` 1700 < `BrownTrout` 2000 < `LakeTrout` 3500 < `ChinookSalmon` 6000)
    * `AmericanBullFrog` 100 → 400 g (bullfrogs are 200-500 g)
    * Players landing the largest pelagic fish (sharks, marlin, tuna) will now have significant encumbrance — by design. Cleaning on-site or using boat / vehicle transport for trophy catches becomes meaningful gameplay

#### New Fish & Creatures
- Hammerhead Shark
- Lake Sturgeon (with roe -> Black Caviar)
- Northern Pike (with roe -> Yellow Caviar) - new model
- Alligator Gar
- Spotted Bass (replaces Black Bass)
- Black Bass + fillet
- Bonito
- Brown Trout, Brook Trout, Rainbow Trout, Cut Throat Trout (new models)
- Lake Trout (new model)
- Bowfin
- Neosho Bass, Striped Bass
- Muskellunge, Barred Muskellunge, Tiger Muskellunge, Spotted Muskellunge
- Northern Snakehead
- White Grunt, Southern Flounder, Yellow Snapper
- American Bullfrog, Red Salamander
- Red Breast Sunfish, new Bluegill model
- Slimy Sculpin
- Pacific Cod, Perch, Severum
- Asian Sea Bass, Siamese Tigerfish, Angelfish
- Blue Marlin, Blue Tang
- Red Head Cichlid
- Snow Crab + Snow Crab Legs
- Fathead Minnow (new model)
- Yellow Perch (new model)
- Rougheye Rock
- Walleye, White Bass, Yellowfin Tuna
- Sockeye Salmon, Chinook Salmon
- Sauger
- Sailfish, Humphead Wrasse
- Mussel, Starfish, Blood Clam (new models)
- Blue Jellyfish
- Black Devil Snail
- Large Mouth Bass, Small Mouth Bass (new models)
- New Crayfish variants

#### New Items & Crafting
- Grub Worm (chance to find when digging for worms)
- Cooler
- Wooden Fish Mount
- Craft metal hook from metal wire + pliers

#### New Tackle & Lures
- 4 Spoon Lures
- 4 Curly Tail Jigs
- Spinner Baits 1-4 (new models)
- Squarebill Lure (replaces Lure4)
- Yellow Crank, Green Crank, Popper lures (replace old lures)
- New Small Tackle and Large Tackle models
- New Worm Container and Bait Bucket models

#### Code & System Changes
- Replaced all `GetGame()` calls with `g_Game` for consistency
- Removed invalid `ref` keywords from RPC handler parameters (CF compatibility)
- Refactored fish config to remove duplication and improve maintainability
- Consolidated repeated classes into shared base files
- Sorted large files by category for easier navigation
- Standardized brace style across the codebase
- XML regeneration fixes - version detection now reads multiple lines, files no longer regenerate every server restart, server-only guard added
- Replaced `Param3` usage with `XmlTypeEntry` class for clarity
- Logger: fixed initialization bug, added `Reset()`, filename sanitization, improved formatting consistency
- Added base classes and inheritance cleanup for containers

### Fixed

- Multiplayer check in `TryDamageItems`
- Config sync and predator sound RPCs
- Net not taking damage when used
- Grub worm digging
- Sturgeon rvmat typo
- Blue Marlin normals
- Tacklebox normals
- Hammerhead Shark materials mapping
- Fillet textures (Chinook Salmon, Sailfish, Humphead Wrasse, others)
- Fillets showing as wrong fish or blank
- Old extra Bluegill fillet texture
- Fathead Minnow rotten fillet bug
- Crayfish position in inventory
- Crayfish becoming invisible after cooking
- Lobster Tail on ground / in inventory / in hand
- Bonito hand position
- Scope on base classes so they no longer spawn in
- Two-hand fish positioning (mostly - slight inventory orientation issue remains)
- p3d selections renamed to `Camo` where missing
- `FlatHeadMullet` classname typo
- Grasshopper texture naming convention
- Missing semicolons causing config parse errors
- Boat sound issue
- Mahi Mahi LOD texture disappearing at distance
- Duplicate bamboo net recipe removed
- Crafting hook from wires
- Repeated tackles removed from spawnable types
- Missing clothes added to typesxml

### Removed

- Old expansion files
- Old README
- Fishing Calc (outdated)
- Old trader files from types
- Old `newtackle` textures
- Old lure models (replaced by crank/popper variants)

### Known Issues

- Two-hand fish inventory orientation is slightly angled
- Faster knife timing temporarily disabled while errors are worked out
- Storm/night/bait buff system is experimental and not yet enabled

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
