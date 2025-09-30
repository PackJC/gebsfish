# Changelog

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
