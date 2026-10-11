# MAYBE_ISSUES — repo audit findings

Living list of unresolved maybe-issues. Delete entries as they are resolved.

Latest review: 2026-10-09, a bug hunt over every script, config, material,
tool and wiki page, then every open finding fixed or decided on Cole's word
("fix it all"; both in the list below). Still open: A36 (commit the untracked
files). Before it, 2026-10-05, evening — a
fifth full pass after the fish mount
rework (scripts, configs, models, materials and the stringtable, the docs, the
wiki, the config editor and the tools), checked against the decompiled game;
the scripts also got a static compile check (no local declared twice in a
function, every override matching its base, no string literal over 900 bytes)
and the new mount models went through DayZ Tools' binarizer. Its open findings
are C1-C11 under "Open — 2026-10-05 review (fifth full pass)". Fixed the same
day: a 3.3.2 mount's trophy too big for the new small plaque can be taken off
(it was stuck there for good), the mounts' size check and pose follow a
subclass of a listed fish, a ruined board takes no fish, a ruined cooler stops
holding its contents' temperature (a frozen fish in it never thawed or rotted),
a stray brace in data/tools/Model.cfg, the boards' nameplate edges had no
texture area and a needless shadow setting, the unused `class Rope;` in the
tackle config, and docs that were wrong: three spears that are two Improvised
Spears, four colour rods that are ten, the mount size lists (sockeye, tuna and
seven reef fish), the rubber worm "lost like a hook", bait being needed to
fish, the bait formula without its cap, the rarity tiers, vanilla items under
the wrong names, the Items-tab crafting card, the editor's spear predator
label ("per stab", it is per fish landed) and fish-tab caption, the stringtable's
`original` column (20 rows) and the slot label "Wooden Fish Mount" (runtime
cases 96-99). Then, on Cole's word, C3 (the Bamboo Fishing Net mends with
Netting only, no Sewing Kit), C6 (the fishing clothes are typed as clothes
in the generated types.xml), C5 (every classname lookup in the config files
ignores case: GebSameClassname) and C8 (the tackle boxes take the gloves by
geb_FishGloves_Base) (runtime cases 100-101), and C1 (a fish only goes on a
board standing in the world, so a carried board can't take one; runtime case
97).

Fixed on Cole's word: B14. The seven colour textures whose alpha no model
uses (the four medium tackle boxes, the European crayfish, the great white
and the snow crab, measured over every face that samples them) are DXT1 now,
their unused texels padded with the nearest colour; the bowfin, brook trout
and walleye keep their alpha, which cuts their fins' outlines (the walleye's
spines, for one), so the review had them wrong. The brook trout's misspelled
" Forcenotalpha" model property, which did nothing, is gone rather than
switched on: turned on it would have pushed the fin cut-outs into the opaque
pass (runtime case 102).

Fixed on Cole's word (2026-10-06): B13's fish half, C4 and Watch 14. The
models keep their size and every fish now weighs what its model shows (48
species changed, e.g. the angelfish 300 g -> 11 kg, the pike 4.5 -> 23 kg, the
yellowfin tuna 12 -> 3 kg; the giants their real weight, up to 2.5 t for the
great white; the crayfish, which the first survey missed, 200 -> 50 g for
their 13 cm model), so the mount sizes that go by the models fit the weights
too. Each catch's weight now rides on its quantity the way vanilla's carp's
does (an eighth fixed, the rest per unit): a full fish weighs exactly its
figure, without the 1 g a unit it used to inherit on top (1 kg on a fish,
149 g on the Shrimp-based small catches), and a part-eaten or less full one
weighs less (runtime case 103).

Fixed 2026-10-06 on Cole's word ("fix all these"):
- Docs: the predator chances now include spear fishing and the master switch
  (B18, also in general.json's help text); a reel-in with no bite never costs
  the bait, only rarely the hook (B19); "The five methods" (B20); the treasure
  odds are averaged over each container's slot range (B21: Rag 45.0%, black
  caviar 4.6%, about 1 in 107,600 catches); the CHANGELOG's pick-weight formula
  has the water temperature and the cap (B22); the last GetGame() call is
  g_Game (B23).
- C7: the tolerance stays (snapping to the server's reading would desync honest
  casts at every dawn and dusk); the comments now say what it guarantees and
  what it allows.
- C11: the vanilla rows live in tools/vanilla_mount_poses.json, and
  `build_mount_poses.py --dz <root>` recomputes them from the debinarized game
  models and flags a new *_live.p3d catch (checked: all five reproduce exactly).
- A8: a startup check names every net or spear catch row whose Environment
  isn't 1-3, a treasure container with MaxItems 0 or Min above Max, health
  levels out of order, a predator row with MaxCount 0, and a bait row or
  preference with no classname, saying what each will do; nothing is changed.
  The Environment and item-count help texts say to always set them.
- A18: the CanSaveItemInHands override on the giant fish is gone (the game asks
  the holder, so it never ran; nothing changes in game).
- A19: the log pruner and the old-layout sweep tell a folder from a file by
  whether it opens as a file (FileAttr.DIRECTORY is 0, so the old test always
  passed); subfolders no longer log "Could not copy" on every boot.
- A20: the fish.json validator names a skipped row as it sits in the file, with
  its classname and the reason.
- B26: the jon boat's Model.cfg lost the bones, sections and animations its
  model doesn't have (camo1, damage_unhide, zbytek, lever, and EngineFolding,
  whose "tilt" source neither the config nor the engine provides); binarize
  gives the same warnings as before. GebsfishBanner.txt and data/proxy/model.cfg
  are deleted (Cole's OK).
- A35: the plan's tests moved here (runtime case 104) and
  FILEGEN_UPGRADE_PLAN.md is deleted (Cole's OK).
- A3: fish.json and bait.json rename geb_Bonita to geb_PacificBonito on load,
  before the version merge, so a 3.3.2 server keeps its bonito tuning and its
  bait preferences; a file that already has both (Cole's test profile) drops
  the old row. The config editor flags classnames it doesn't know (geb_Bonita
  reads "renamed geb_PacificBonito in 3.3.3"), and What will bite? renames it
  the same way and leaves out other unknown species.
- A4: the predator warning sound set is non-positional (each warned client
  plays it on its own character, and the samples are stereo), its shader has a
  range, and AddonBuilder's "files to copy directly" list now has *.ogg (in its
  user.config; the sounds never reached the PBO). Needs a rebuild (case 108).
- A23: the Yellow Crankbait's 188 clear-lip faces use their own flat
  yellowcrank_lip.rvmat (+ _damage/_destruct, copies of the purple lure's), named
  in its healthLevels; binarize gives the same warnings as before.
- A27: exclude.lst (DayZ Tools\Bin\PboUtils) also lists the top-level
  Workbench\, .claude\, .vs\, .idea\ and .github\ folders and the root tools\
  JSON files by name (*_manifest.json, *vanilla_mount_poses.json), never a
  tools folder pattern. Both tool settings files were backed up first.
- B17: the config editor no longer blanks a tab on a row it can't draw (a null
  row, a fish, bait or preference without a classname, a section that isn't an
  object, a null row in any general.json table): the row is named in a notice
  with Remove (and a Set Classname box), stays in the download unless removed,
  and anything else that throws shows a red notice and one toast while the rest
  of the tab and the download bar stay.
- C10: the nine fish fields (six weather multipliers, TempMin/Optimal/Max) have
  help buttons, and so do Catch chance, the bite rhythm, the bait multipliers
  and every general.json table. Checked with a fake-DOM harness (209 checks on
  Cole's 3.3.2 files) and in a browser.
- C9: tools/extract_vanilla.py builds a local folder of the vanilla models the
  rods, clothes and Rubber Worm use (debinarized, PBO prefixes kept; never in
  the repo), render_p3d.py finds them with --dz, and their render settings live
  in build_item_manifest.py's MODEL_OVERRIDES (which prints every class it
  skips). All 61 pictures rebuilt; 60 are pixel-identical to the published ones.
- B25: the manifest records each class's materials per slot and render_p3d.py
  applies them per slot; the five jon boat pictures were re-rendered (their own
  hull relief, and no grey proxy shard).
- B8 (2026-10-07, Cole: "it should be like vanilla fish rotting"): the catches
  look like vanilla food. Vanilla food has no worn/damaged/ruined looks (its
  healthLevels are empty) and only swaps to a rotten material; ours had both on
  the same part, so a rotten fish at full health might have looked fresh. The 78
  damage blocks in data/fish/config.cpp are gone: whole fish, creatures, crabs,
  lobsters, crayfish, fillets, crab legs, lobster parts and caviar inherit their
  bases' or vanilla's (same hit points, empty looks) and keep their rotten look.
  The bait bugs don't rot and keep their wear looks.
- A10 (2026-10-08, Cole: "do option 1"): a predator spawn point whose walkable
  surface sits more than 1 m above the bare terrain (a roof, a bridge, a big
  rock) is skipped like water, and another of the 20 tries is used; with no
  open ground anywhere in the ring the spawn is skipped. Vanilla never meets
  this: its wolves and bears come from the Central Economy's territories, out
  in the wild, never from a point picked next to a player.
- C12 (2026-10-08, Cole: "yes do it"): general.json, bait.json and fish.json
  put the current help text in every ...Info field on each start (each
  section and every table row in general.json), copied by name from freshly
  made objects (GebRefreshInfo, which uses Enforce's reflection: the typename
  variable list and EnScript.SetClassVar). Settings are never touched, and a
  file is only rewritten when a text actually changed, so a same-version
  restart still leaves it byte-identical. junk.json keeps its own refresh.
- A13 (2026-10-08, Cole: "okay then fix it"): every item model has a physics
  shape. The seven hard lures (an empty Geometry LOD) got a box round the lure,
  Component01 and a mass; 13 Geometry LODs and 6 View/Fire LODs without a
  component got Component01; 29 boxes copied from other models (the pike's ran
  25 cm past each end, the bonito's 63 cm out to one side, the bullfrog's,
  minnow's and salamander's were a twisted shape) were refitted to their own
  model, a creature's box hugging its body's thickness the way vanilla's fish
  boxes do, so it lies on its side instead of on a fin tip. Every Geometry LOD
  without a mass took its item's full config weight (no config weight: 0.5 kg,
  the grub 0.05). The crab legs, which are auto-centred, kept their boxes (a new
  one would have moved them). Checked with the binarizer: every "No
  components" warning gone, no new warning, autoCenter and boundingCenter
  unchanged on all 83 models (scratchpad a13/).
- B9 (2026-10-08, Cole: "okay fix this"): the jon boat's Geometry, buoyancy,
  Land Contact, Roadway, View and Fire Geometry LODs are rebuilt round its own
  hull, seats and motor (they were vanilla Boat_01's): the hull's flat bottom,
  straight sides, raked bow and transom, the outboard's head and leg (the leg
  below the hull and the propeller in the view and fire LODs only, as vanilla
  leaves them out of the physics). Mass stays 900 kg, spread so the boat floats
  level (centre of mass 3 cm behind the centre of buoyancy; 17 cm draft against
  vanilla's 21). The walkway is the floor (and the bow deck), not a plane 30 cm
  past each side. The fire geometry's driver hit proxy sits where the view
  geometry seats him; passenger 1 sits on the bow deck, 2 and 3 side by side on
  the middle bench (they were the Zodiac's seats). Damage zones keep their
  names, now on the hull's bottom, sides and bow and on the motor; the motor's
  pieces carry `engine`, so they turn with the steering. Binarizer: the two
  "component faces less than 4" warnings gone, nothing new (scratchpad b9/).
- A24 (2026-10-08, Cole: "yeah fix it all"): 27 models have a real chain of
  detail levels, built from each one's full-detail mesh by an edge-collapse
  simplifier: every corner that stays keeps its position, normal and UVs (all
  UV sets), texture, UV, sharp-edge and named-selection boundaries hold, a
  point of an animated part (the jon boat's engine, propeller and tiller) only
  merges into one of the same part, a double-sided sheet (the net's bag, the
  jellyfish's tentacles) is simplified on one side and its back rebuilt from
  it, and each level stays within a set distance of the full model both ways
  (0.4 % of its middle dimension for LOD 0 up to 3.5 % for the sixth), so
  legs, fins, handles and hooks keep their shape. The jon boat keeps its
  32,751-face model for close up and steps down to 16,005, 8,005, 3,205, 1,205
  and 599 faces. The snow crab, flathead mullet, blue tang, jellyfish, lobster,
  snakehead, snail and grasshopper have a lighter full-detail model (about
  half the faces or less, the same look up close); the lobster's and angel
  shark's meshes were stored twice (one copy dropped); the angelfish, angel
  shark, chinook and lobster no longer repeat their first level; the
  flounder, gar, hammerhead, hairtail, bait bucket and worm container step
  down evenly; the six lures, the knife, the net and the small tackle box (one
  level each) have two to four. Teeth, rivets and leg hairs go from LOD 2 or
  3; eyes stay. The chinook was stored as loose triangles (every face its own
  corners), so it was welded first; where a model's own lighter levels were
  sound (the jellyfish's, the grasshopper's last two) they carry on. Normals
  of the simplified levels were checked and mended (none lit from behind).
  Shadows: DayZ has no shadow LODs (none in about 1,350 vanilla models); the
  binarizer draws a model's shadow from its last visual level and switches
  shadows off when that level has about 2,000 faces or more (1,877 passed,
  2,044 did not) unless it carries lodnoshadow. It had switched them off for
  the snow crab, blue tang, alligator gar, angel shark, black devil snail,
  jellyfish, hairtail, small tackle box and bamboo net; all nine get a light
  enough last level now (the jellyfish's, 1,252 faces, made from its own
  lowest level with UV seams let go, so its far texture may smear a little).
  The jon boat's levels carry lodnoshadow=1 exactly like vanilla's rubber boat
  and sedan, so it stays as vanilla. Binarizer: the "LODs not ordered by face
  count" and "Too detailed shadow lod" warnings gone, nothing new, autoCenter
  and boundingCenter unchanged on all 27 (scratchpad a24/).
- C2 (2026-10-08, Cole: "fix c2 and a9"): a fish mount skips vanilla's
  ground-placement tests (the two box tests, base, roof clipping, height) only
  while it hangs on a wall. Standing on the floor it gets them all, the two box
  tests measured where the board stands (vanilla's put the box half a board
  too high, taking the origin for the bottom), so it can't be stood in a
  doorway or through a door, a car or a tent. Wall or floor is decided the same
  way on the client and on the server, from the board's own position: five
  short rays out of its back (the middle and four points towards the corners)
  must meet a wall within 6 cm, the middle and at least three of the others.
  Only things that stay put count as a wall: the ground, rocks, trees, map
  buildings and player-built walls; a building's door, a vehicle, a tent or
  any other item does not, so a board hung on a door is no longer left
  standing in the doorway once the door opens.
- A9 (2026-10-08, same ask): each fishing cycle's length (5.5-6.5 s by the
  hour) comes from the cast's snapshot hour on both sides (a modded
  FishYieldItemBase.GetCycleTimeForYieldItem), not from each side's own clock,
  so a cast started around one of the 13 hours where the length changes no
  longer runs different cycles on the client and the server.
- Sixth audit pass (2026-10-08, Cole: "go through the entire app and look for
  more issues, files that aren't used"): every file in data/, gui/, docs/ and
  tools/ is referenced or a valid manual tool, all 434 stringtable keys are
  used, every JSON setting is read by gameplay code, and the wiki builders
  reproduce their files exactly. Done on Cole's word: a stray crash dump and an
  empty script folder removed (Recycle Bin); the five mount poses the LOD work
  moved (lobsters, jellyfish, blue tang, snow crab; under 0.5 mm) regenerated;
  the snow crab's colour and relief maps cut to 1024 (the colour map was the
  mod's only 4096, 6.6 MB). Script clean-up: dead helpers gone (the logger's
  unused Reset and never-set level filter, PrepareFish.GetInclusiveRandom, the
  debug out-parameters of the per-species weather multiplier and the bait
  lookup that nothing read); the one Debug line that ignored DebugLogs and the
  routine Info lines (client config sync, yield-registration progress, the
  per-player connect line) now log only with DebugLogs on; seven stale
  comments corrected. Also on Cole's word: the old Workbench/ folder (dev
  project settings, an empty plugin file, a plugin calling a missing .bat) went
  to the Recycle Bin; docs/logo.paa and .github/logo.paa stay.
- DayZ 1.30 script folders (2026-10-08, Cole: "fix this on the entire app
  too"): DayZ 1.30 Experimental (1.30.164014) silently skips a CfgMods script
  folder whose path has a backslash (no error, no log line; 1.29 loads it; it
  looks like Bohemia's DZEXP-134 FindFile bug). config.cpp's three script
  modules were "gebsfish\scripts\3_Game" etc., so on 1.30 none of the scripts
  loaded. Now "gebsfish/scripts/3_game", "/4_world", "/5_mission" (also the
  folders' own case). Nothing else in the repo declares script modules;
  imageset, logo and texture paths aren't affected. CfgConvert binarizes the
  config and reads the three paths back unchanged. Runtime case 123.
- D3 (2026-10-08, Cole: "fix this"): one copy of each piece of duplicated
  script code. The three generated XML files share GebXmlFiles (3_game): their
  folder, the version line the types files are skipped by, and the five jon
  boats, which were written out three times. The bamboo net and the spear share
  ActionGebWaterBase, the water type each reads where the player aims, sends
  with the action and checks on the server. The minnow, bullfrog and
  salamander share geb_LiveBaitBase, their hooked look. Every classname
  comparison goes through GebSameClassname (the catching context's
  ClassnamesMatch is gone, the containers' checks use it), the find-chance
  rolls of the net, the spear and both digs use GebRollChance, and the three
  health-level rolls (treasure, hooks found in fish, junk) GebRollHealthLevel.
  No behaviour change: a FindChance of 1 now skips the roll everywhere, as the
  net and the digs already did. Item class names are untouched.
- Bug hunt (2026-10-09, Cole: "look for bugs anywhere in the program, fix
  white spaces and code hygiene in the entire app, do not review
  stringtables"): four agents read every script (against the decompiled
  game), config, material, Model.cfg, tool and wiki page. Fixed: on a
  dedicated server the mod's catches were never put back on a map gebsfish.c
  doesn't hook whose world data clears the catch list (vanilla MissionServer
  builds the world data a second time once the gameplay settings load, with a
  new catch list, after both checks had run on the first; the server now
  checks again in OnGameplayDataHandlerLoad, runtime case 124); treasure loot
  skips what a gebsfish container listed in TreasureContainers would refuse
  (runtime case 125); containers.c's comment that the cargo checks keep craft
  results out (a new item placed by classname is never checked: vanilla's
  CreateInInventory finds the spot by type, before any item exists to ask
  about); the wiki's fish table works from the keyboard, a malformed % in a
  wiki link no longer throws, the config editor only asks for pictures the
  wiki lists, and the counts the barracuda changed (80 species, the sea pool
  29 / 282 and its odds, the great white's 157 / 108, the Medium Fish Mount
  list, also in the CHANGELOG); the manifest builders refuse an option as the
  output path; extract_vanilla and batch_gifs survive undecodable output; the
  CHANGELOG's bonito note (the old rows are renamed on load). Hygiene:
  whitespace, indentation and final newlines in 13 4_world, 7 3_game/5_mission,
  54 config/material and 7 tool/wiki files (each keeps its own tabs or spaces
  and line endings; a token check shows only whitespace and comments changed in
  the scripts, and CfgConvert gave byte-identical output for all 287 configs,
  rvmats and Model.cfgs after the whitespace pass); about twenty wrong
  comments (the JSON string limit and the BiteSpeed crash in
  gebsfishConfig.c, the dawn and storm examples, a vanilla method that doesn't
  exist, the caviar example and others); the unused `class ItemBase;` in
  data/tools/config.cpp, the Rubber Worm's two unread textures, a repeated
  help-text refresh in JunkConfig.Backfill and three debug lines that never
  printed on a client (checked before the server's config was in). On
  Cole's word, the stray grep.exe.stackdump at the repo root (an untracked
  crash dump from a Git Bash grep) went to the Recycle Bin.
- Fix it all (2026-10-09, Cole: "fix it all"): every open finding, by four
  agents, then the lead's review against the decompiled game. A2: the old
  classes load as hidden scope 1 aliases until a wipe:
  geb_Fun{Yellow,Red,Purple,Green}Tackle on their twins (with duct tape and
  epoxy repairs, geb_repairlegacytackle.c) and geb_Bonita on geb_PacificBonito
  (it fillets by the Pacific Bonito's row). On Cole's word geb_BonitaFilletMeat
  got no alias (old fillets go); fish.json rows naming it are renamed on load.
  E1: on Cole's word ("remove filleting fish from other mods") a fish fillets
  only by its own class's fish.json row, never a parent's; each vanilla
  Prepare* recipe takes only its own fish, so a modded fish with a row shows
  one fillet option, not two (Watch). E2: a crafted mount goes to the first
  normal inventory spot, never into a filtered container that refuses it, else
  the ground. E3: the fillet recipes no longer list vanilla's fish twice, or
  each fish knife next to the HuntingKnife entry it already matches. E5: the
  wiki builder files the Rubber Worm as a lure, as the posters do. D1: the king
  and snow crab are carried one-handed like the lobsters (5 kg and 1.5 kg, both
  under the two-handed fish); in-hands profiles follow config parents, so the
  aliases carry like their parents. A16: a refused cast releases the rod's
  reservation and says "Nothing seems to be biting here..."
  (str_action_nothingbiting, all 14 languages). #28: ConfigSync goes with no
  target, and the main menu no longer drops the config when it closes: the
  config arrives while the menu is still up, so every join from the menu lost
  it until a respawn; the next menu or offline game drops it instead. A11: the
  Chernarus hook was deleted (vanilla's base does the same), then put back on
  Cole's word 2026-10-10; all three map hooks stay (Watch). #26: settled from the engine: a section missing from the
  file loads as an all-zero object, never null, a missing list as an empty one,
  and fields in loader-made sections and rows as 0. Backfill now asks the file
  which keys it holds (GebJsonKeys), so an upgraded server gets the new
  sections (spear fishing, treasure) with their defaults instead of switched
  off. E4 went to Watch. Runtime cases 126-130.
- Reviews of the fix-it-all changes (2026-10-11, two agents acting as the
  compiler and a runtime reviewer, checked against the decompiled game): no
  compile errors. Fixed from them: GebJsonKeys reads the file line by line
  (string.Get walks the whole string to its end on every call, so the
  character-by-character pass over a whole file cost the square of its size,
  an estimated 3-8 s per start on bait.json); a file it can't read re-seeds
  nothing (it answered "missing" to everything, and the defaults would have
  been saved over the admin's file); fish.json and bait.json are only asked
  when their loaded list is empty; a config the main menu or a client's game
  leaves is marked stale (g_GebConfigStale) and dropped at the next menu or
  offline game, so a direct offline start or restart no longer loads it twice;
  one geb_FilteredContainerBase.GebCreateInInventory places the crafted mount
  and treasure loot (the treasure now checks a container an earlier slot put
  inside, too); a vanilla fish with no fish.json row gives vanilla's two
  fillets. E8 (hidden aliases on the ground) went to Watch, accepted.
- B24: the ten-colour rods, raincoats and wellies have their own descriptions
  (one key per colour, all 13 languages), in game and in the wiki gallery.

Cole's asks, 2026-10-06: every lure hook is the Purple Crankbait's light silver
(the flat mid-grey colour with a shared lure_hook.rvmat, a copy of the purple's
hook material, + _damage/_destruct in healthLevels): the popper's, yellow
crankbait's and squarebill's trebles, split rings and hangers, and the curly
tail jig's hook (welded into its body mesh, picked by the neutral dark grey it
samples and taken out of the Camo selection so the four colours don't paint it
again). The Squarebill was then reworked on Cole's word: its own square bill
(441 faces, the face untouched) is the other lures' clear blue plastic
(squarebill_lip.rvmat), and its hooks are the Purple Crankbait's two hook sets
(eyelet, split ring, treble, at twice the purple's size) on its belly and tail
eyelets. The old hardware went: the tail treble pieces, the belly treble that
was welded into the body, the red split ring, a welded hook point, and the
belly opening where the old eyelet entered was closed in the belly's colour.
Then ("the invisible piece be two pieces because now you can see through
it"): the head's skin and the bill were both open where the bill was welded
in, so through the clear bill you saw into the hollow head; both openings are
capped now (the head's in its own texture), and every clear face has a
reversed twin, so the game draws the near and the far side of the plastic.
All four models binarize with the same warnings as before; their wiki pictures
were re-rendered. (The Yellow Crankbait briefly got the purple's round lip;
Cole had meant the Squarebill, so the yellow one keeps its own lip, with A23's
flat lip material.)

Dropped as intended: B5, a treasure container rolled Ruined spilling its loot
at the next restart. Cole: anything ruined should spill its loot on restart,
as vanilla's ruined containers do. Also not issues on Cole's word
(2026-10-06): A14, containers holding more than they take up, and A25, heavy
fish that fit a backpack (both balance calls); B4, a Bait Bucket stored in a cooler on 3.3.2 falling out on
the 3.3.3 update (coolers refuse the bucket since 3.3.3), and B13's lure half,
the crankbait models being longer than vanilla's 7.7 cm jig (yellow 32 cm,
squarebill 29 cm, purple 18 cm); listed so nobody re-flags them.

Previous review: 2026-10-05 — a fourth full pass (scripts, configs and models,
the docs, the config editor and the tools; stringtables left out), checked
against the decompiled game and engine. Its findings are B1-B26 under "Open —
2026-10-05" below. It also caught a bug in the day-old jon boat events file,
fixed the same day: the economy clears an event's flags when a later file
leaves them out, so gebsfish-events.xml switched off remove_damaged (wrecks
never cleaned up); it now repeats the map's own flags line. Fixed with it: the
wiki's bait-pairing count, the tackle-box text (bitterlings and sardines, fish
knives), the fish render manifest after the cooked looks, and
build_wiki_assets.py writing pictures for renders that aren't species.
Fixed after the review the same day: B1, B2, B3, B6, B7, B12, B15 and B16
(runtime cases 78-85), most of B24 (the gallery pictures), and B10: the fish
mount now comes in three sizes, each refusing catches too big for it, with
every species posed side-on (runtime cases 92-94), and B11: vanilla's carp,
mackerel, walleye pollock and steelhead trout mount too (runtime case 95). Added the same day: the
fishing clothes in ten colours, with raincoats and wellies, and every colour
matched across the mod (runtime cases 86-91).

Previous review: 2026-10-04 — a third full pass (scripts, configs and assets,
the docs, the config editor, the tools and the packaging; translations left
out), checked against the decompiled game. Its findings are A1-A36 under
"Open — 2026-10-04" below; ten of them (A1, A5-A7, A12, A15, A17, A21, A22,
A26) were fixed the same day, and A28-A34 and A25's container weights on
2026-10-05.

Previous review: 2026-10-02 — a second full pass (scripts, configs, docs, the
config editor, the stringtable and the tools), again checked against the
decompiled vanilla game. It fixed in source: the fish mount hanging in mid-air
and replaying a random deploy animation, Sakhal snares catching poultry, gear
despawning after 2 hours untouched (now vanilla's 4), the mount and net recipes
using up planks, wire or sticks that were part of a fence, gate, battery or
shelter, Lake Trout without roe, the editor's fillet range, about 25 wrong
statements across the README, wiki, CHANGELOG and the config help text, and
the stringtable's swapped, stale and garbled translations. It also added the
editor's "What will bite?" simulator. None of its findings are still open:
#32 (a hooked worm dying mid-cast) was dropped as not an issue, and the
rest were fixed the same day: #29 (the main menu running the
server's config code on players' PCs), #30 (the first bug-dig after a restart
cancelling itself; digging bugs is now crouch-only), #33 (spawned predators
never cleaned up), #34 (a timer per live worm), #41 (the net's crayfish
allow-list and the Bait Bucket docs), #31 (net catches skipping the net's
allow-list), #35 (chat messages in the server's
language), #36 (a copy of vanilla's signal timing, removed), #37 (the config editor leftovers), #38 (the tools), #39 (Sakhal's sea
almost half junk; junk is now a set share of rod catches), #40 (custom maps
without a hook that clear the catch list wiping the mod's fish), the old #9
(the root config's hover-logo key) and #42: every item description in all 12
languages checked against the English and rewritten where wrong, about 480
item names corrected, the Traditional Chinese column converted to Traditional
characters, the English texts that described the wrong fish (angelfish,
redbreast sunfish, lake sturgeon, yellow caviar) rewritten in every language,
and Bonito (now Pacific Bonito), Yellowtail Snapper and In-Line Spinner renamed in English.
Also fixed that day: #23 (the Bait Bucket keeps its water, but ovens, barrels
and coolers no longer take it as food), #16 (the fish-knife fillet speed lived
on the shared recipe, so the server could use another player's knife and
leave you stuck in the animation) and two of #28's items (config saves into a
missing folder, the mount hologram's placement checks), then #1 (the version
is 3.3.3 everywhere) and #28's config tidy-up (vanilla's food classes declared
at the top level, texture overrides aimed at the models' real parts). The
jon boat's `Crew`/`Driver` declarations stay: the boat defines its own seats.
On 2026-10-03 every gebsfish model got its own worn, damaged and ruined
looks, and the whole-fish bases got their `cs_raw` lists back: vanilla's
`FoodStage.UpdateVisualsEx` reads entry 0 of them on every spawn, and no
vanilla food item leaves them empty. The same day, #28's hook-in-fish reward
moved out of the inventory: it now drops on the ground with the fillets, so a
worm container, bug catcher or bait bucket can't take it. Cooked looks for
the crab and lobster parts and rotten looks for whole fish shipped too,
including the Pacific cod (#43) once a hidden tuna-textured scrap inside its
model left the retexturable part.

Previous review: 2026-10-01 — compared against the decompiled vanilla game (build
125372: the complete script source, every debinarized vanilla config, the CE
XML, and the engine's native C++), which settles questions earlier audits could
only guess at. Last full audit: 2026-09-10 (scripts, configs, stringtable,
seeded pools, asset paths, wiki data, and `docs/config-editor.html` — binaries
excluded). Prior full audit: 2026-08-18.

The 2026-10-01 review closed #5, #7 and #8 (vanilla/engine show they can't
happen) and fixed its confirmed bugs in source: generated types.xml marking all
gear `crafted="1"` (never spawned as loot), whole fish and live bait that never
rotted, Shrimp not working as bait, the bamboo net recipes eating whole Netting
stacks, the misspelled `alignHologramToTerain`, container repair kit ids, the
low-resolution treasure roll, an empty `ResultBonus` passing validation, wrong
FishQuality / bait-loss docs, client and server disagreeing on bites (now one
cast snapshot plus the map's water temperature), and the "after a catch"
predator/treasure rolls firing when nothing was caught. A second pass the same
day fixed #6, #17, #18, #19, #21, #24, #25, #27 and most of #28, and settled
the balance calls #20 (fillets now poison and fill like vanilla) and #22
(fishing gloves lost the NBC chemical protection) -- see the CHANGELOG. From
that review: #15 and #16 are likely bugs to fix and test, #23 needs a decision,
and #26 and #28 are lower-priority notes.

---

## Open — 2026-10-09 bug hunt (seventh pass)

Findings E1-E5 (E for this pass): all settled the same day (the list at the
top); E1 and E4 are under Watch. A test server that generated
gebsfish-types.xml / -spawnabletypes.xml under an earlier 3.3.3 build keeps
those lists until VERSION_GEBSFISH changes: delete both once before testing
(as runtime case 122 does).

## Open — 2026-10-08 audit (sixth pass)

Findings D1-D3 (D for this pass): D2 is under Watch, D3 was fixed the same
day and D1 on 2026-10-09 (the list at the top).

## Open — 2026-10-05 review (fifth full pass)

Findings C1-C11 (C for this pass). Each was checked against the code; the ones
fixed the same day are listed at the top of this file, not here.

## Open — 2026-10-05 review (fourth full pass)

Findings B1-B26 (B for this pass). Each was checked against the code, the
configs or the files; "possible" means only a test in game settles it.

## Open — 2026-10-04 review (third full pass)

Findings A1–A36 (A for this audit, so they don't clash with the runtime cases'
numbers). Each was checked against the code or the files; "possible" means it
needs a test to confirm. Fixed the same day and taken off this list: A1, A5,
A6, A7, A12, A15, A17, A21, A22 and A26 (see the CHANGELOG; runtime cases
63-72 check them). Fixed 2026-10-05: A28-A34 and A25's container weights
(runtime cases 75-77). Fixed 2026-10-09: A2 and A16; A11 is kept as it was,
under Watch.

### A36. 313 new files are untracked in git (and 193 deleted ones unstaged)
On 2026-10-09 the configs audit counted 234 untracked files that the configs,
materials and models use (all of gui\, 232 under data\: clothes 65, fish 63,
tools 43, tackle 33, vehicles 28); they have to go in with the configs.
Counted 2026-10-06; the list below is from 2026-10-05, since then the new tools
(tools/extract_vanilla.py, tools/vanilla_mount_poses.json), the lip and hook
materials (data/tackle/yellowcrank_lip*.rvmat, lure_hook*.rvmat, squarebill_lip*.rvmat)
joined it.
They include the Pacific bonito's files (data/fish/pacificbonito*), the cooked
and rotten looks for eight creatures (32 textures, 15 materials), the medium
tackle boxes' and jon boat's textures renamed to _co, the jon boat's materials
and relief maps, the bug catcher, the tackle boxes' _as maps, the lure relief
maps, the net and knife-blade materials, the jon boat events generator
(scripts/3_game/FileGenerators/eventsxml.c), the fishing shirts' ground
textures (data/clothes/geb_*fishshirt_ground_co.paa), the ten-colour fishing
set's textures (data/clothes/geb_*fishraincoat*, geb_*fishwellies*, the new
hats, shirts and gloves, the gloves' material geb_fishgloves*.rvmat with its
_normals and _smdi, data/tools/fishingrod_*_co.paa and fishknife_pink_co.paa),
the three fish mounts (data/tools/{small,medium,large}fishmount.p3d with
their textures and materials, the generated
scripts/4_world/entities/itembase/gear/geb_fishmountposes.c and
tools/build_mount_poses.py), tools/build_container_lists.py, and the new wiki
pictures
(docs/fish/geb_PacificBonito.webp, the four new knives',
geb_{Green,Purple,Red,Yellow}Tackle.webp, the rods, hats, shirts, gloves,
Rubber Worm and fish mounts added 2026-10-05, and the 47 new set pieces). The
files they replace show as deleted, so a commit needs both. Local PBO builds
include them, but the repo and the published wiki don't until they're
committed (`git status` lists them).

## Also noted — lower priority

Nothing open: #26 and #28 were fixed 2026-10-09 (the list at the top).

## Watch — verified benign, keep in mind

### D2. Unprefixed names on vanilla classes — kept as they are
44 methods and members the mod adds to 8 vanilla classes carry no Geb prefix:
CatchingContextFishingRodAction (24, e.g. GetBaitMultiplier, GetCurrentHour,
GetWeatherCatchMultiplier), PrepareFish (8, e.g. SetupFishRecipe),
ActionDigWorms (3), MissionBase (3, Register*YieldData), MissionServer (3
dump helpers), DayZGame (ConfigSync and PlayPredatorSound, which the RPC
registrations name too) and Worm (BAIT_LIFETIME_SECS); the full list is the
scratchpad's audit6/unprefixed.py output. Another mod adding the same name to the
same class won't compile alongside gebsfish.
Cole chose not to rename them (2026-10-08: "nah dont do the renames"); listed so audits don't re-flag it.

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

### 15. Sea or pond follows vanilla's test — accepted
- The rod, net and spear decide sea or pond with vanilla's `SurfaceIsSea` /
  `SurfaceIsPond` at the aim point (terrain below the current tide), not the
  surface's liquid type, so surf above the tide line can count as a pond and a
  lagoon below sea level as the sea. Kept as vanilla does it (2026-10-02);
  listed so nobody re-flags it.

### E1. Other mods' fish fillet only with a fish.json row of their own — by design
A fish from another mod, even one built on a vanilla or gebsfish fish, is
filleted only when its own class has a fish.json row (Cole 2026-10-09: "remove
filleting fish from other mods"). Listed so nobody adds parent-row lookups
again.

### E4. The jon boat's damage and engine-fold animation sources animate nothing
FoldingEngine, ShowDamage and HideDamage have no animation in
data/vehicles/Model.cfg, so vanilla Boat_01's SetAnimationPhase calls for them
do nothing (HideAntiwater is wired up). Harmless until the boat model gets
damage or engine-fold parts.

### E8. Hidden aliases lying loose in the world vanish after the second restart — accepted
The world save skips an entity with no Central Economy item profile, and a
scope 1 class can't get one (the types.xml reader ignores it: "Not spawnable.
(Scope is not public?)"). So a geb_Fun*Tackle or geb_Bonita lying loose on the
ground loads at the first restart after the update and is gone after the
second, box contents included; ones inside something (tents, barrels, cars,
jon boat decks, inventories, coolers, mounts) stay. Found by the 2026-10-11
review from the decompiled engine. Cole 2026-10-11: leave it (not an
auto-convert, not scope 2 with a types.xml row). The CHANGELOG tells admins to
move such items into something before updating.

### E7. The Bait Bucket takes no slots — intended
geb_MinnowBucket has `inventorySlot[] = {}` (kept off stone ovens and barrels
as food). On 3.3.2 it inherited WaterBottle's Belt_Left and DirectCookingA-C
slots, so a bucket stored on a belt or a cooking slot at the update may not
load back. Cole 2026-10-10: as intended.

### A11. The three vanilla maps keep their yield hooks
gebsfish.c's SakhalData, EnochData and ChernarusPlusData InitYieldBank skip
super on purpose: on Livonia and Sakhal super would bring vanilla's own
catches back wherever a config leaves them out (an emptied junk table, a
deleted fish row). The cost: a mod loaded before gebsfish that adds catches to
those maps in its own InitYieldBank loses them; one loaded after keeps them.
Chernarus's hook does what vanilla's base does (ChernarusPlusData has none of
its own); it was deleted 2026-10-09 and put back on Cole's word 2026-10-10.
Deleting the Livonia and Sakhal hooks would hand those maps to
GebRepairYieldBank (client and server lists stay identical).

---

## Compatibility

Deploy the same build to clients and server, then restart/reconnect. The number
of custom recipe registrations changes, the net action payload gains an int, and
(2026-10-01) the rod-fishing action payload gains the cast snapshot (date, time,
rain); mixing old and new peers is unsupported. Keep the same mod load order on
peers.

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
- 2026-10-01: static comparison against the decompiled build 125372 (vanilla
  scripts, debinarized configs, CE XML, engine natives). No game launched; the
  2026-10-01 fixes have not been compiled or played yet.
- 2026-10-02: same method for the second pass. Configs pass CfgConvert, the
  editor's scripts pass `node --check`, scripts are brace-balanced with no BOM.
  Nothing compiled in game or played yet.

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
9. (2026-10-01) Regenerate `gebsfish-types.xml` (delete the old one or bump the
   version), merge it, and confirm rods, tackle, coolers and lures appear in the
   world, tackle/worm/bug containers and bait buckets spawn with their
   spawnabletypes cargo, and the fish mount and live insects never spawn loose.
10. (2026-10-01) With food decay on, leave a whole fish (e.g. BlueGill) loose
    and in inventory until it turns Rotten; confirm a cooler and a trophy mount
    keep it fresh. Cook a minnow, frog and salamander on a stick and in a pot and
    confirm Baked/Boiled/Dried are reachable (not straight to Burned).
    (2026-10-05: they go on a fire's cooking and smoking slots since B12,
    but not on a stick: no Shrimp-family creature has the stick's slot, as
    in vanilla.)
11. (2026-10-01) Hook a Shrimp: it should be eaten on a bite, and DebugLogs=1
    should show Shrimp as the bait. Put one in a trap's bait slot.
12. (2026-10-01) Craft and repair the bamboo net from a Netting stack of 3:
    exactly one piece is used each time. Repair a cooler and a tackle box with
    duct tape and with epoxy putty.
13. (2026-10-01) Place a fish mount on sloped ground (floor fallback): it should
    no longer tilt to the slope. Wall placement should be unchanged.
14. (2026-10-01) Bite sync: dedicated server, two clients, DebugLogs=1 on both
    sides. Cast across a dawn/dusk boundary and while rain is building. Each
    cast's "Cast conditions" and "Water temperature this cast" lines should be
    identical in the client and server logs, normal play should never log
    "don't match the server's", and every bite shown should land (unless the
    hook breaks).
15. (2026-10-01) Water temperature: on Chernarus, Livonia and Sakhal, set
    winter and summer dates and cast in fresh water and at sea; check the logged
    temperatures (Chernarus fresh about 9 / 21 C, sea 20 / 26) and that the
    species mix shifts with the season.
16. (2026-10-01) Fish with a bone or wooden hook until one breaks on a bite: the
    log should show the fail-catch predator chance and no treasure roll, the
    rod should still lose health, and the client's RPT should have no
    "GetHealth cannot be called on client" line.
17. (2026-10-01) Containers: a tackle box sitting in a backpack refuses new
    items (vanilla behaviour) and still holds its contents after a restart;
    filling the net, a cooler and a worm tin from your hands still works; a
    Wooden Hook fits in tackle boxes.
18. (2026-10-01) Try to fillet a fish on a trophy mount (refused). Give
    TreasureLoot an ammo entry (e.g. Ammo_9x19, 1-30) and a magazine and check
    the round counts. Leave a pulled treasure chest untouched: it should be gone
    after about two hours.
19. (2026-10-01) Add a net catch that isn't on the net's allow-list (e.g.
    Shrimp): a startup warning names it in the Gebs log and the server RPT, and
    with DebugLogs=1 each such catch logs that it dropped at the player's feet.
    It is never in the net, and nothing in the net goes missing after a
    restart.
20. (2026-10-01) Dedicated server: config sync and the predator warning sound
    still reach clients (the RPC registration moved), and the RPT shows no
    missing-addon warnings for gebsfish.
21. (2026-10-01) Eat raw and burned mod fillets, lobster and crab: food
    poisoning should be possible and the stomach should fill like vanilla raw
    fish. Wear the fishing gloves in a toxic zone: they should give no hand
    protection.
22. (2026-10-02) Fish mount placement: aim at the sky, at a wall 3+ m away and
    at a wall within reach; only the last turns green, and the plaque never
    hangs in mid-air (first and third person). Hang one about 2.3 m up a wall.
    The deploy animation is the two-handed one, with no prone drink and no
    "check ... behaviour" line in the script log.
23. (2026-10-02) Sakhal: snares in fields and forest catch only rabbits and
    foxes. Chernarus and Livonia are unchanged.
24. (2026-10-02) Regenerate `gebsfish-types.xml`: gear lifetime is 14400; a
    stocked cooler dropped outside a base is still there after 3 hours.
25. (2026-10-02) Craft a fish mount from a fence's planks or a gate's wire
    (refused) and from loose ones (works); craft a bamboo net with a long stick
    from a shelter frame (refused) and from your shoulder slot (works).
26. (2026-10-02) Fillet a Lake Trout a few times: red caviar at the caviar
    chance.
27. (2026-10-02) Spot-check the corrected translations in game: the Simplified
    Chinese Chinook and Sockeye names, the four renamed lures, Spotted Bass and
    Lake Sturgeon in two or three languages.
28. (2026-10-02) Config editor: fillet counts stop at 10 and the maximum
    follows the minimum. In the "What will bite?" tab, set a staging server's
    conditions (map, date, hour, rain, bait) and compare its odds with a few
    hundred DebugLogs=1 casts.
29. (2026-10-02) Main menu: start the game with no `Gebs` folder in the
    profile and stay at the menu — no `general/bait/junk/fish.json` appear (a
    `logs` folder still can; that's the logger). Start an offline game with a
    customised fish.json: it's used. Join a server: fishing works once the
    server's config arrives, and leaving to the menu and joining another server
    uses the new server's config.
30. (2026-10-02) Dig bugs with the bug catcher: from standing, the character
    crouches and digs; standing up mid-dig cancels it; the first dig after a
    restart completes, from standing and from crouching.
31. (2026-10-02) Predators: set a predator's MinCount/MaxCount to 50/50 and a
    fishing chance of 1. One cast brings 10; keep casting and the count stops
    at 30 alive (DebugLogs=1 logs "Predator cap reached"). Walk more than
    150 m away for 15 minutes: they're gone. Stay close: they stay. Killed ones
    stay as corpses.
32. (2026-10-02) Live bait: drop a worm on the ground and keep one in your
    pockets; both are ruined after about 90 minutes. A worm in a worm
    container or a cooler keeps its health; a rubber worm never changes.
33. (2026-10-02) Add a Rusty Crayfish to the net's catch table: no startup
    warning, and the catch lands in the net. A Bait Bucket takes a clam, a
    snail and a starfish.
34. (2026-10-02) Translations: in three or four languages (including Chinese
    and Japanese), inspect the bluegill, sauger, walleye, a muskellunge, a
    tackle box, an in-line spinner, a cap and a T-shirt. Names and
    descriptions agree, multi-paragraph descriptions keep their breaks, and
    nothing renders as boxes or blanks.
35. (2026-10-02) Chat language: dedicated server in English, a client set to
    another language (e.g. German). Trigger a predator spawn with the chat
    warning on, and force a treasure catch (Chance 1): both chat lines show in
    the client's language, not English and not a raw "#STR_" key.
36. (2026-10-02) Junk share: start a server with an old `junk.json` (no
    `JunkShare`): the file gains `JunkShare` 0.1 and the new help text. With
    DebugLogs=1, cast at sea on Sakhal and on a Chernarus pond: each cast logs
    "Junk: 25 entries at weight ... (JunkShare 0.1, ...)", and over a hundred
    catches about 1 in 10 is junk on both. Set `JunkShare` to 0: no junk at
    all; to 0.5: about half.
37. (2026-10-02) Custom maps: on a map gebsfish.c doesn't hook whose world
    data clears the catch list (check Sahrani, Artseinen or MelkartV2), the
    server and client logs show "<map>Data left the mod's yields out of its
    catch list", rod catches include gebsfish species, and a snare catch plays
    its sound on the client with no script error. Deadfall still works through
    its own hook, with or without THC GebsFishingFix loaded. On Namalsk,
    snares catch only rabbits and foxes. On Sakhal with Ice Fishing
    loaded and DebugLogs 2, the startup yield dump lists Carp as a
    geb_YieldFishGeneric, not a YieldItemCarp.
39. (2026-10-02) Config folder: start a server whose profile has no `Gebs`
    folder, with DebugLogs 0: general, bait, junk and fish.json are written.
    Make one of them read-only and change a setting that triggers a save: the
    log says the file "could not be written" and why.
40. (2026-10-02) Mount hologram: start placing the fish mount, then jump,
    walk into deep water or climb a ladder: the hologram closes, as a tent's
    does.
41. (2026-10-02) Bait Bucket: it spawns with water. It won't go into a
    cooler, onto a stone oven's cooking slots, or onto a closed barrel's.
42. (2026-10-02) Snow: on Sakhal with DebugLogs 1, cast during snowfall above
    0.3: the "Cast conditions" line shows snow=..., and species with a
    RainMultiplier get it (StormMultiplier above 0.7).
43. (2026-10-02) Predators: with a short MinRadius/MaxRadius, trigger spawns
    beside a bridge and among rocks: they appear on top, not underneath or
    inside, and behave like normal wildlife.
44. (2026-10-02) Spear fishing: with an Improvised Spear (bone- and
    stone-tipped) in hand, aim at water within 3 m and under 1 m deep: "Spear fish!"
    shows; deeper water doesn't. The animation plays and ends (no hang),
    about 1 stab in 25 drops a catch at your feet (4%, a fish every 2.5
    minutes or so), and each stab costs the spear 1 health.
    `Enable` 0 removes the prompt; the config editor shows the section.
45. (2026-10-02) Fish-knife speed: on a dedicated server, two players fillet
    back to back, one with a gebsfish knife and one with a vanilla knife, then
    swap. Each fillet takes its own knife's time, and nobody is left in the
    animation after the fillets drop.
38. (2026-10-02) Item text: in English and two or three other languages,
    inspect the angelfish (now the semicircle angelfish), redbreast sunfish, lake
    sturgeon, yellow caviar (pike roe), Neosho bass and smallmouth bass, and
    the leopard shark (no "too heavy to carry" at the end). The
    Pacific bonito, yellowtail snapper and in-line spinners show their new
    English names, and so do the Pacific bonito and yellowtail snapper fillets.
46. (2026-10-03) Damage looks: lower the health (a weapon, or `SetHealth01` in
    a debug console) of a tackle box, cooler, the Bait Bucket, a lure of each
    kind, a fish knife, the fish mount, a few fish and a crayfish, and hit the
    jon boat's motor and a float. Worn looks pristine; damaged shows scratches
    and grime; ruined looks wrecked. Each muskie and crayfish variant keeps its
    own colours when damaged. At full health, check the Fathead Minnow,
    Flathead Catfish and Blue Jellyfish (they now have a material), the Bowfin,
    the Redbreast Sunfish and the Purple Crankbait look right, and that placing
    the mount still shows the green/red hologram. The PBO must include the
    new `*_damage.rvmat` / `*_destruct.rvmat` files and the new materials.
47. (2026-10-03) Hook from a fish: with `HookFromFishChance` at 1, fillet a
    few fish while carrying a worm container, bug catcher and bait bucket with
    free space. Each hook drops on the ground beside you with the fillets, at
    a health level inside its pool entry's range, and none goes into a bag.
48. (2026-10-03) Animations: fillet a mod fish with the fish in your hands and
    a fish knife on the ground: the skinning animation plays and the fish is
    hidden. Use the bamboo net standing, right after a restart: you crouch,
    the net animation plays through, and a second and third net also start
    crouched (never standing).
49. (2026-10-03) Cooked and rotten looks: bake, boil, dry and burn an American
    and a European lobster tail and claw, king crab legs and snow crab legs.
    Baked and boiled look red-orange, dried dull brown-red, burned charred.
    Let a few whole fish (a walleye, a muskie, the alligator gar, the Pacific
    cod), a whole lobster, a crab part and a Fathead Minnow rot: grey-green
    mould appears and the texture underneath stays; the gar's teeth stay
    clean. Also lower a rotten fish's health below half: if the damage look
    replaces the mould, the two share the material swap (expected trade-off,
    not a crash). Check a rotten one at full health too (B8): if it still
    looks fresh, the damage materials win over the rotten one.
50. (2026-10-03) Fillets: fillet a walleye, a rainbow trout and a sockeye salmon.
    The fillets have vanilla's walleye/steelhead shapes, sit right in hands,
    in inventory and on the ground, and bake, boil, dry, burn and rot with
    vanilla's looks for those fillets. Fillet a bass, a tuna and a flounder:
    raw meat is translucent pinkish-white with white membranes (not
    paper-white, which is how cooked fish looks), deep red with white
    sinew, and translucent white; lay a few raw mod fillets beside a
    vanilla raw fillet: about as bright. Check the leopard shark
    (saddles with paler centres, spots, gill slits, fine rough skin up close;
    fin undersides pale) and the cherry salmon (real scales and fin rays, dark
    back, silver sides, rosy band, wet sheen) whole, damaged, rotten and as
    fillets, in hands, in inventory and on the ground. Same for the largemouth
    and smallmouth bass (fins cut cleanly with no dark rim, also from a
    distance; the smallmouth's eye red) and the hairtail (silver all over,
    pale dorsal fin; check it isn't see-through or flickering; in daylight
    a soft silver reflection along its body in smooth sheens, its skin
    pattern still showing, not crumpled like foil and not a mirror; in
    Buldozer it reflects Buldozer's purple-blue backdrop, so judge it in
    game too; its raw fillet's skin side the same, meat side only wet,
    cooked fillets dull). The yellowfin tuna from above, the side and the
    front: a very dark navy back (no grey or violet chrome, no crumpled
    edges), silver sides and head without a lavender cast. Also the
    Siamese tigerfish (gold, brown-black bars running over the back and
    under the chin) and the redhead cichlid (red head and throat, the eyes
    as photographed, sitting cleanly in its socket): look at both from the
    front, above and below too, and close at the eyes, for
    streaks, seams or odd colours. Whole and as fillets. The bluegill the same
    way (pectoral fins see-through, no white fringe on the fins). The great
    white shark, crabs, lobster claws, blue tang, sculpin, blood clam, gar,
    basses, walleye, sauger, trout, crayfish, tackle box, spinner, net and
    knife: lighting even on both sides of the body, no line along the belly
    or along other seams, near and at a distance. The blue marlin from every
    side (navy back, silver sides with pale bars, white belly, dark fins and
    bill; the wrist darkens smoothly into the tail, no white band against the
    tail fin), whole and as a fillet. The angel shark from above and below
    (sandy marbled back with small pale and dark spots, no repeating
    pattern; eyes and spiracles on top of the head; white underside with the
    mouth, gill slits and vent), whole, damaged, rotten and as a fillet.
    The southern flounder close at the head: two round golden-bronze eyes on
    the eye bulges, from the side, the front and above; the blind-side
    pectoral fin pale. Fillets: look along a few fillets' cut edges (flounder,
    angel shark, great white, tigerfish, wrasse, mahi-mahi, yellowtail
    snapper, tuna): meat-coloured, no cyan or green line. The hammerhead
    from every side and close at the hammer's tips: bronze-grey back, white
    belly and hammer underside, gill slits, and real eyes with a golden iris
    (not a pale or patterned ball), also from a distance (lower detail
    levels); whole, damaged, rotten and as a fillet. Its model's eye UVs
    were remapped: open it in Object Builder once to be sure it loads. The
    flathead catfish up close: dark brown mottling on the back and sides,
    olive-brown fins, dark barbels paling to the tips with pale chin barbels,
    wet slimy sheen, fine skin grain, no black
    wedges on the pectoral or pelvic fins, no line across the throat; whole,
    damaged, rotten and as a fillet. The walleye and sauger close at the
    mouth (a dark line, nothing see-through) and the bowfin's jaw (pale, no
    red stripe). Relief and sheen on every fish, crustacean and shellfish:
    in daylight and at night, near and far, scales and shell ridges should
    read as raised (not dented) with the light from any side, the skin wet
    but not chrome; the redbreast sunfish looks like itself, not a bluegill.
    The mussel: smooth glossy blue-black shell with no squares or facets,
    pearly inside, orange meat with a dark edge; its model's normals were
    smoothed and the meat given a material, so open it in Object Builder once.
    The Pacific cod has a new model: check it held in one hand (the carp
    hold), lying on the ground on its side (no fins sunk into the ground),
    its inventory icon, at a distance (detail levels 1 and 2), and whole,
    damaged, ruined, rotten and burnt; open pacificcod.p3d in Object Builder
    once. The rougheye rockfish: red pectoral
    fins filling their sculpted shape, a pink-red body (no yellow), a pale
    pink underside. The bonito: silver-white belly (not lavender), a dark
    steel-blue striped back, no cyan streak. The sockeye, striped bass and
    white bass from the front, above and below: no stretched streaks.
    The angelfish from every side and close at the head: brownish green
    with a blue spot on each scale, navy toward the tail, a yellowish face
    with a blue line round the gill cover, a blue-ringed eye, blue edges on
    the dorsal, anal and tail fins, yellow pectoral fins, dark pelvic fins
    edged in blue; no seam along the back or belly; whole, damaged, rotten
    and as a fillet (skin side olive to navy with blue spots).
51. (2026-10-04) Relief maps: every `_normals` map is now stored pre-corrected
    for the game (it reads them as colour images through the sRGB curve).
    The sauger, yellowfin tuna and great white were checked in Buldozer: no
    light/dark breaks at texture seams. Look at a handful of others the same
    way (Object Builder + Buldozer, zoomed in and turned round): a bass, a
    trout, the pike, a crayfish, the lobster, the hammerhead, the angelfish,
    the hairtail, a lure, the tackle box, the fish knife and the jon boat
    motor and hull on all five boats (each skin and motor colour has its own
    relief map and materials now: seams, deck ribs and edges should catch
    the light, the camo should not look raised; damage a boat's hull, floats
    and engine and check each part shows the worn look in its own colour):
    no edge where texture pieces meet, no side of a fish darker than
    the other, relief that reads as bumps (scales, rays, gill covers), not as
    a tilt. The sauger also has a new body mapping: check it loads, no fin or
    gill cover has a hole, the eyes, mouth and fins look as before and the
    pattern runs on across the middle.
52. (2026-10-04) Bamboo Fishing Net: new model (pole, hoop, lashing, net bag)
    and textures. Open data/tools/bamboofishingnet.p3d in Object Builder +
    Buldozer: the pole straight with thin node rings, the hoop round, the
    twine lashing where they meet, the net see-through with knots and no dark
    fringe round the twine, the far side of the bag showing through the near
    side. In game: it sits in the hands where it did, the net fades to a haze
    at a distance rather than turning solid or vanishing, and when damaged
    the bamboo and the net both show wear. The physics shape (geometry LOD)
    was left as it was and covers only the middle of the handle: drop the
    net and see whether the hoop or the bag sinks into the ground.
53. (2026-10-04) Bug Catcher: new model (mesh tube, yellow caps, funnel and
    stopper) and textures, files renamed bugcontainer.* -> bugcatcher.*. Open
    data/tackle/bugcatcher.p3d in Object Builder + Buldozer: the mesh
    see-through with the far side and the caps' insides showing, the caps'
    grip ribs and plastic grain catching the light, both detail levels. In
    game: it sits in the hands where it did, the mesh reads as a dark haze at
    a distance, damaged and ruined show on the caps and the mesh. Its physics
    shape (geometry LOD) was left as it was: a box round the old tube, so the
    caps reach a few mm past it on one side.
54. (2026-10-04) Lure relief maps: the Curly Tail Jigs (all four colours),
    Spoon Lures and Squarebill now have relief maps; in Buldozer they should
    read as fine surface detail (flakes, scales, eyes), not bumps. The spoon
    lures' hook, split ring and eyelets are plain steel in all four colours
    now (in game they used to take the lure's texture).
55. (2026-10-04) Fish knife: new model, textures and a chrome blade. Open
    data/tools/fishknife.p3d in Object Builder + Buldozer: the blade should
    reflect like a mirror (Buldozer tints reflections with its purple-blue
    backdrop), flat and clean rather than crumpled; the handle's chevron grip,
    black finger guard and rounded butt. In game, in all ten colours: first
    person (LOD 1100) and third person, the hand still closes round the
    handle (now 17.5 mm thick like the hunting knife's), the blade is chrome
    outdoors, damaged and ruined show on the handle and the blade.
56. (2026-10-04) Creatures: in Object Builder + Buldozer step through the
    detail levels of data/tackle/grasshopper.p3d and fieldcricket.p3d (legs
    and antennae at every distance, no holes), data/fish/redsalamander.p3d
    (straight, feet on the ground, gentler skin relief) and
    americanbullfrog.p3d (smooth, no white rim, pale belly). In game: hold
    each, put one on a hook, drop one: nothing floats or sinks oddly (the
    salamander is longer now: 166 mm, was 142).
57. (2026-10-04) Large tackle box: new textures in all eleven colours after a
    closed three-drawer box (cream lid, smoky top cover, smoky front panel
    over cream drawers, smoky side door, darker latches and handle) and a
    repaired model (holes closed, inside-out faces turned, stray texture
    patches gone). In game check a few colours: the top cover and front
    panel should read as smoky clear plastic, not chrome; damaged and
    ruined show plastic wear; the detail levels hold up at a distance; the
    box still sits right on the jon boat deck and in the hands.
58. (2026-10-04) Small tackle box: new textures (blue see-through lids with
    the tray's compartments showing, grey tray, blue/grey hinges and latch)
    and a repaired model (cracks in the bottom lid closed, hinge and latch
    faces turned, normals redone so the grey sides are smooth, not
    crumpled). Open data/tackle/smalltackle.p3d in Object Builder + Buldozer:
    both lids, the hinges and the latch, no light through the bottom lid.
    In game: it still sits right in the hands, on the ground and on the jon
    boat deck, and opens with its 12 slots. Both lids are blue all round,
    their end walls by the hang loop included (they were grey there).
59. (2026-10-04) Four new fish knives (Lime, Light Blue, Camouflage,
    Brown): after the mod writes its types.xml / cfgspawnabletypes.xml
    again, each spawns (and in fishing shirts' cargo), fillets a fish with
    the knife staying in the hands, and the handle shows its colour (the
    camo a woodland pattern). Their names in a few languages. The Bug
    Catcher's caps are yellow now (were orange). The Green knife's handle
    is now the green cooler's dark green (was a light mint): beside a green
    cooler in Buldozer or in game, the two should read as the same green.
    The Yellow knife and the Yellow Cooler are now the Yellow Tackle Box's
    golden yellow (were a greenish lemon and a mustard): the three together.
60. (2026-10-04) Fish looks: the mahi-mahi's toned-down gold and softer
    relief, and the northern snakehead's new eyes (dark amber iris, black
    pupil). In Object Builder + Buldozer and in hand.
61. (2026-10-04) The four Fun tackle boxes are removed (they were the Green,
    Purple, Red and Yellow Tackle Box under a second class name). After the
    update the server log has no errors about geb_Fun* classes, and the
    generated types.xml and cfgspawnabletypes.xml list eleven large tackle
    boxes. A test server that already wrote its 3.3.3 files (in the
    profile's Gebs/mpmissions folder) keeps them until they are deleted, so
    delete them once to see the new lists (and the four new knives).
62. (2026-10-04) Pacific Bonito (was Bonito; classes geb_Bonita and
    geb_BonitaFilletMeat renamed geb_PacificBonito and
    geb_PacificBonitoFilletMeat, files pacificbonito.*, keys
    str_fish_pacificbonito*): a new model and skin. Open
    data/fish/pacificbonito.p3d in Object Builder + Buldozer: the stripes,
    the spiny first dorsal fin, the finlets, the forked tail and its join
    with the stalk, the eye. In game it sits in the hands as before and
    fillets into Pacific Bonito Fillets. TRANSLATIONS TO DO: only English
    says Pacific Bonito; the other 12 languages still name a plain bonito
    (and 狐鰹 / ハガツオ are the striped bonito). A test server's 3.3.3
    fish.json and bait.json still say geb_Bonita: rename it there, or let
    the files be written fresh.
63. (2026-10-04) Bamboo net repair: a Worn net offers no repair; a Damaged
    net repairs to Worn with one Netting, and holding the key takes no more.
64. (2026-10-04) Emptied lists: set "Predators": [] in general.json and
    "Junk": [] in junk.json, change each file's ConfigVersion to 3.3.2 and
    restart: both stay empty. Delete one row from a list that still has
    entries: it comes back. Empty HookFromFishCatches: it refills.
65. (2026-10-04) Lake Sturgeon: a rotten one shows the mould look.
66. (2026-10-04) Jon boats: after the XML is written again (#61),
    types.xml and cfgspawnabletypes.xml list the five jon boats; spawn one,
    restart, it is still there, and the RPT has no CE type warnings.
67. (2026-10-04) Spear fishing: about 1 stab in 25 catches (a fish every
    2.5 minutes or so), a stab costs the spear 1 health. A test server that
    already wrote SpearFishingSettings keeps FindChance 0.4 until edited
    (existing values are never overwritten).
68. (2026-10-04) Coolers: a fish in a cooler chills over a few minutes and
    freezes later, as before (the cooling now runs on the CE item update).
69. (2026-10-04) Cooked looks: bake, boil, dry, burn and let rot a bullfrog,
    red salamander, blood clam, mussel (its inside changes, the shell stays),
    black devil snail, starfish, blue jellyfish and fathead minnow: each
    stage looks different.
70. (2026-10-04) Chinook: a rotten chinook is rotten all over.
71. (2026-10-04) Renamed textures: the four Old tackle boxes and all five
    jon boat colours (hull and motor) show their textures in Object Builder,
    Buldozer and in game.
72. (2026-10-04) Water barrel: a whole fish and a minnow in a vanilla barrel
    at least half full of water don't rot; under half full, or in a box
    inside the barrel, they rot as usual; a worm in the barrel still dies.
73. (2026-10-04) Trap baitfish as bait: a Bitterlings and a Sardines each go on
    a rod's hook, a cast with one gets bites, and the bait is used up on a
    catch like the shrimp. bait.json has a Bitterlings and a Sardines row (a
    3.3.2 file gains them on the update; one already written at 3.3.3 keeps
    its rows until deleted). Both go in the Bait Bucket and don't rot there.
74. (2026-10-04) Jon boats at boat spawn points: after a start,
    $profile:Gebs/mpmissions/gebsfish-events.xml has the VehicleBoat event
    with the five jon boats (max 1 each) and nominal/max five above the
    mission's db/events.xml (Chernarus 22/29). Copy it to the mission's
    gebsfish folder, register it in cfgeconomycore.xml next to the types
    file, wipe the storage: jon boats appear at vanilla boat positions, no
    more than one per colour, the vanilla boats are as many as before, and
    the RPT has no [CE][DE] error for VehicleBoat. On a map without a boat
    event the file has no event in it. The file repeats the event's flags
    line: wreck a jon boat and a vanilla boat, and both are still cleaned up
    (remove_damaged) and spawn again.
75. (2026-10-05) Container weights: empty, a Large tackle box weighs 4.5 kg,
    an Old one 1.4 kg, the small one 110 g, the Bait Bucket 2.9 kg (3.9 kg
    full of water); a cooler still 1.2 kg.
76. (2026-10-05) junk.json help text: a junk.json written by 3.3.2 has, after
    the update, the new CatchProbInfo text on every Junk and ContainerJunk
    entry. One already written at 3.3.3 keeps its text until deleted.
77. (2026-10-05) Config editor: a species description with quotes or
    apostrophes shows them as typed; raising TempMin above Optimal raises
    Optimal (and TempMax) with it; TempMax can't go below Optimal, and
    Optimal stays between the two.
78. (2026-10-05) Spear predators: with SpearFishingSettings'
    PredatorSpawnChance set to 1 for the test, stabs that miss draw no
    predator and a stab that lands a fish draws one; at the default 0.01,
    about one per 100 fish.
79. (2026-10-05) Ruined containers: ruin a cooler (its fish stop chilling
    and rot), a Worm Container and a Bug Catcher (a worm in each starts
    dying), a Bait Bucket (its minnow rots) and a water barrel (its fish
    rots); undamaged ones keep working.
80. (2026-10-05) Live bait and food decay: with FoodDecay 0 in globals.xml a
    loose worm doesn't age; with 2 it dies in about 45 minutes.
81. (2026-10-05) Bug Catcher: a successful dig puts the bug into the catcher
    in hand; with the catcher full it lands where you dug.
82. (2026-10-05) Tackle boxes: a shrimp, a bitterling and a sardine go into a
    small, a large and an Old tackle box; a crayfish, a clam and a jellyfish
    are still refused; a minnow still goes in.
83. (2026-10-05) Fire cooking: a minnow, a frog and a salamander go on a
    fireplace's direct-cooking and smoking slots and bake or dry there.
84. (2026-10-05) Bait Bucket water: drain the bucket into a bottle, fill the
    bottle at a pond and pour it back into the bucket; the same with well
    and rain water.
85. (2026-10-05) Fishing shirts on the ground and in a tent or the inventory
    show their colour (purple is purple) and their fish print on the folded
    front. Worn shirts and caps show the new prints (tigerfish, severum, red
    swamp crayfish, pike) and the smaller logo, upright on the cap's front.
86. (2026-10-05) Fishing raincoats, all ten: worn, the Gebsfish logo sits on
    the chest beside the zip and reads the right way round; on the ground and
    in the inventory the folded coat shows its colour and the logo; rain,
    warmth, cargo and the damaged and ruined looks are vanilla's; they spawn
    with empty pockets.
87. (2026-10-05) Fishing wellies, all ten: the logo on the outer side below
    the rim where vanilla's badge was, "GEBSFISH" on the sole plate; no
    vanilla colour anywhere on male or female characters (openings too).
88. (2026-10-05) The new hats, shirts (each with its fish on the back) and
    rods in orange, yellow, brown, light blue, lime and pink, gloves in all
    ten colours, and the Pink Fish Knife: they spawn, look right worn, on the
    ground and in hand; the rods cast and repair like the others; the pink
    knife fillets; every glove goes into the tackle boxes.
89. (2026-10-05) Side by side in daylight each colour is one shade on every
    item: hats, shirts, raincoats, wellies, gloves, rods, knives, coolers and
    the large tackle box of that colour (green: the green cooler's, the green
    tackle box included). Bright colours are much brighter than vanilla's
    fabrics; say if any glow.
90. (2026-10-05) Loot: the generated types.xml has each of the 50 fishing
    clothes at nominal 1, min 1 and the ten rods at 2/1 (20, as before);
    cfgspawnabletypes gives only the shirts pocket loot.
91. (2026-10-05) Fishing gloves: worn, the palm, fingers and fingertips are
    black textured rubber and the back and cuff a coloured knit, on male and
    female characters; damaged and ruined gloves show wear (their own
    material's copies, RefTexsMats on vanilla's nbc_gloves material).
92. (2026-10-05) Fish mounts: craft the small, medium and large mount from a
    stack of 10 planks and a wire with a hacksaw on you (1, 3 and 6 planks
    taken; refused without the saw). Hang each on a wall (white ghost, then
    flat on the wall) and stand each on the floor with no wall in reach (it
    should stand on its bottom edge, not half sunk). The large one only goes
    in your hands and uses the heavy deploy animation; the medium fits a big
    backpack. The damaged and ruined looks show on each.
93. (2026-10-05) Mount poses: on the small mount a bluegill, a largemouth bass,
    an American lobster, a starfish, a red salamander and a shrimp; on the
    medium a pike, a king crab and a hairtail; on the large the blue marlin,
    the great white and the angel shark. Each hangs upright and side-on, its
    head to the viewer's right and its good side out, centred above the
    nameplate with its back just clear of the board. A fish facing left or
    showing the wall its good side means the engine turns the other way:
    name the species (the turns in tools/build_mount_poses.py follow
    vanilla's sedan trunk and doors).
94. (2026-10-05) Mount sizes: the small mount refuses a pike and a crab, the
    small and medium a marlin and a shark, and any mount takes a bass. A
    mounted fish keeps its pose after a restart and for a player who arrives
    later. A mount placed before this update (same class) is the new small
    plaque, its fish posed.
95. (2026-10-05) Vanilla catches on the small mount: a carp, a mackerel, a
    walleye pollock and a steelhead trout each mount, hang side-on with the
    head to the right, centred above the nameplate, and stay fresh; none can
    be filleted off the mount.
96. (2026-10-05) Legacy trophies: on a save from 3.3.2 with a pike and a
    bass each on a Wooden Fish Mount, update and restart: both mounts are
    small plaques; the pike can be dragged off (too big for it) and hung on
    a medium mount, where it can't be taken off again; the bass can't be
    taken off at all.
97. (2026-10-05) Hold an empty small mount, look at a bluegill on the ground
    and press F: the bluegill goes into your cargo, not onto the board. A
    board in hands or in a backpack refuses a fish dragged onto it; hung on a
    wall or set on the floor it takes one from the vicinity. A mount lying
    ruined on the ground refuses a fish.
98. (2026-10-05) Floor placement of the large mount: aim at the floor of a
    doorway, through a parked car and into a tent; note whether the hologram
    goes green (C2).
99. (2026-10-05) Ruin a cooler while carrying it with a frozen fish inside,
    then set it down: the fish thaws and later rots (before the fix it stayed
    frozen and fresh).
100. (2026-10-05) A damaged Bamboo Fishing Net offers no repair with a Sewing
    Kit, and Netting still repairs it to Worn (not with
    RepairBambooFishingNet off). The generated gebsfish-types.xml has the 50
    fishing clothes under `<category name="clothes"/>` and every other gear
    item under "tools"; after a wipe the clothes turn up on clothing spots.
101. (2026-10-05) In fish.json rename the bluegill's row to "geb_bluegill"
    and restart: a caught bluegill fillets with that row's MeatMin/MeatMax,
    bait still favours it, and the log shows no duplicate-row error (the
    version merge doesn't add "geb_BlueGill" again). Each of the ten fishing
    gloves still goes into the small and the large tackle box.
102. (2026-10-05) The four medium tackle boxes, the European crayfish, the
    great white and the snow crab look as before up close and at a distance
    (no dark rims along texture seams), now that their textures carry no
    alpha; the bowfin's, brook trout's and walleye's fins keep their cut-out
    outlines (the walleye's spiny dorsal fin shows gaps between the spines).
103. (2026-10-06) Fish weights: a full angelfish, northern pike, yellowfin
    tuna and great white show 11 kg, 23 kg, 3 kg and 2,500 kg in the inventory
    (the inspect text rounds), a red salamander under 0.25 kg and a crayfish
    50 g; eating half of the pike leaves it at about 13 kg. Holding the pike
    shrinks the stamina bar by about 40 points (1.75 a kg past 6 kg of load);
    holding the great white shrinks it to the minimum: no sprinting, jumping,
    vaulting or climbing, but jogging still works. Nothing else about them
    changed (fillets, mount size, bait).
104. (2026-10-06, the never-run tests of the retired FILEGEN_UPGRADE_PLAN.md,
    rewritten for today's behaviour) Config upgrade path on a local server:
    a. Put a pre-3.3 profile (fishingsettings.json, Fish/Logs/ and
       extras/mpmissions/, with a subfolder inside it) into $profile:Gebs and
       start: the files land in Gebs/gebs_oldfiles/, the four JSON files
       generate, the log shows Migrate lines, and the subfolder stays put with
       no "Could not copy" line (A19); folders the sweep emptied are removed.
    b. In a current fish.json delete one species, change another's
       CatchProbability and set ConfigVersion to "3.2"; restart: the deleted
       species is back with its defaults, the edited value is untouched and the
       version is restamped.
    c. Restart again at the same version: all four files are byte-identical.
    d. In bait.json delete one bait row and one fish preference and set an old
       version: both come back, tuned multipliers untouched.
    e. Remove one entry from junk.json and one from a general.json array, old
       version: both are restored.
105. (2026-10-06) Startup row checks (A8, A20): add a net catch row without
    "Environment" (or with 0), a treasure container with "MaxItems": 0, a
    predator row with "MaxCount": 0 and a fish.json species with a misspelled
    Classname; restart: the log names each with its row number, classname and
    what it will do; the files are unchanged and everything else works.
106. (2026-10-06) Jon boat after its Model.cfg cleanup: in Buldozer and in
    game it steers (the motor turns), the propeller spins, the anti-water
    plane hides as before, and all five skins look as before; nothing folds
    (nothing ever did).
107. (2026-10-06) Bonito rename (A3): start with a 3.3.2 fish.json whose
    geb_Bonita row has a tuned CatchProbability and a bait.json with geb_Bonita
    preferences: the log says both were renamed, the files now name
    geb_PacificBonito with the tuned values, and no "Skipping fish.json Species
    row" error appears. With Cole's test profile (both rows present) the old row
    is dropped instead.
108. (2026-10-06) Packaging (A4, A27): rebuild the PBO with AddonBuilder and
    list it (BankRev or PBO Manager): data\sounds\*.ogg are inside;
    Workbench\, tools\*_manifest.json and tools\vanilla_mount_poses.json are
    not, and data\tools plus the two script folders called tools still are. In
    game, a predator spawn plays the warning sound for players within
    PredatorWarningSoundRadius (50 m) and not beyond it.
109. (2026-10-06) Yellow Crankbait lip (A23): up close in hands and on the
    ground, the clear lip reads as smooth clear plastic (no body relief or
    sheen across it), as on the Purple Crankbait, also when damaged and ruined.
130. (2026-10-09) Crabs and mounts (D1, E2): hold a king crab
    and a snow crab: both use the one-handed carp hold like a lobster (walk,
    run, crouch, prone, first and third person; the snow crab model lies flat,
    so check it sits right), and the crab legs the mackerel-fillet hold.
    Craft each fish mount with room in a backpack: the small one lands in the
    backpack; with a full inventory it drops beside you, never into a cooler,
    Bait Bucket or tackle box.
129. (2026-10-09) Config sections (#26): back up Documents\DayZServer\Gebs.
    In general.json delete the WeatherSettings and TreasureSettings blocks, set
    "PredatorSettings": null, delete CraftFishMount from RecipeToggles, delete
    only Catches from DigBugsSettings and set DigWormsSettings.Catches to [];
    restart: WeatherSettings and PredatorSettings come back with defaults,
    TreasureSettings as Enable 1, Chance 0.0002, Announce 1, CraftFishMount is
    1, DigBugs has its 4 default rows with its FindChance kept, DigWorms stays
    []. In fish.json delete Species: all 80 rows come back. In junk.json delete
    ContainerJunk and set "Junk": []: the Pot row is back and Junk stays [].
    Cole's own dev general.json holds a TreasureSettings an earlier build saved
    all zero (Enable 0, Chance 0): delete that block once (and
    SpearFishingSettings if it shows Enable 0 with no catches) so they come
    back with their defaults; the mod can't tell them from a deliberate 0.
128. (2026-10-09) Joining from the main menu (#28): with DebugLogs 1, start the
    game fresh, join a server from the menu and fish before dying: it works at
    once, and the client's log shows "Client received config data ... from
    the server." with no "Initializing gebsfish config." after it. Leave to the
    menu and join again (or join another server), and reconnect while the old
    body is still in the world: fishing works at once each time. Offline with a
    customised fish.json, the custom file is used.
127. (2026-10-09) Refused cast (A16): back up the Gebs folder, set every
    fish.json CatchProbability to 0 and junk.json JunkShare to 0, restart and
    cast: no cast, one chat line "Nothing seems to be biting here..." in the
    game's language, and casting again works at once (no 5 s dead rod; the rod
    can be moved or dropped straight away). Holding the button gives one
    line. Restore the backup.
126. (2026-10-09) Old items through the update (A2): on a 3.3.2 server spawn
    the four Fun tackle boxes (one full of lures, a knife and a repair kit, one
    on a jon boat deck) and geb_Bonita fish (in the inventory, in a cooler, on
    a fish mount); stop it, install this build on the same storage and start:
    no create errors for geb_Fun* or geb_Bonita; the boxes load as the Yellow,
    Red, Purple and Green Tackle Box with their contents, on their deck; the
    bonitos show as Pacific Bonito everywhere and fillet into Pacific Bonito
    fillets (one option); a Fun box takes duct tape and epoxy repairs. Old
    bonito fillets are gone (expected). The admin spawn lists don't show the
    aliases; a mission types.xml still naming them logs "will be ignored (Not
    spawnable...)".
125. (2026-10-09) Treasure in a gebsfish container: list geb_RedTackle in
    general.json's TreasureContainers (and nothing else), set the treasure
    Chance to 1 and DebugLogs to 1, and land a few catches: each red tackle
    box holds only tackle-box items, the log names the loot it skipped ("isn't
    allowed in a geb_RedTackle"), and after a restart nothing in the boxes has
    gone. Set the chance back afterwards.
124. (2026-10-09) Custom maps on a dedicated server: on a dedicated server
    running a map gebsfish.c doesn't hook whose world data clears the catch
    list (Sahrani, Artseinen or MelkartV2, as in case 37), with DebugLogs 2,
    the server log shows "<map>Data left the mod's yields out of its catch
    list" after the gameplay settings load, the yield dump that follows lists
    the gebsfish catches first and the map's own after them, rod catches
    include gebsfish species, and a snare catch plays its sound on the client
    with no script error. On Chernarus no such line appears.
123. (2026-10-08) DayZ 1.30 script folders: rebuild the PBO and start a server
    on 1.30 Experimental and one on 1.29 stable: on both, the startup log
    shows the mod's lines (the Gebs config folder and gebsfish-types.xml are
    written), fishing with a rod, the bamboo net, digging bugs and filleting
    a fish all work. In the PBO, $PREFIX$ stays gebsfish and the folders are
    scripts/3_game, 4_world and 5_mission.
122. (2026-10-08) Shared code (D3): on a dedicated server, net in a pond and
    in the sea (each gives its own water's catches), stab with a spear and dig
    for bugs and worms. Hook a minnow, a bullfrog and a salamander: each shows
    its hooked look on the rod and its loose look again when taken off. Fillet
    fish until a hook comes out, catch junk and land a treasure catch: their
    health levels stay inside the configured ranges. Delete
    gebsfish-types.xml and gebsfish-spawnabletypes.xml from
    $profile:Gebs/mpmissions and restart: both come back with the five jon
    boats, gebsfish-events.xml too; the next restart logs them as already at
    this version. A bait preference typed in lower case in bait.json still
    applies.
121. (2026-10-08) Slot icons (F38): look at a jon boat's attachments: both
    deck spots show a crate. Look at an empty fish mount: its slot shows a
    white fish (a bass side-on). A blank slot there means the mod's imageset
    didn't load: gui\gebsfish.imageset has to be in the PBO, and AddonBuilder
    only copies *.imageset when it is in its "files to copy directly" list.
120. (2026-10-08) Bite timing (A9): on a dedicated server with time
    acceleration, cast just before 05:00 and just before 17:00 (two of the
    hours where the cycle length changes) and let the cast run across the
    hour: every bite the client shows lands, and with DebugLogs=1 the client
    and server log the same "Cast conditions". Runtime case 14 covers the rest.
119. (2026-10-08) Mount placement (C2): with each board, aim at the floor of
    a doorway, across a parked car, into a tent and through a closed door: the
    hologram is red and the server refuses it (a modified client can't push it
    through). Open floor: green, and the board stands on its bottom edge. Hang
    it on a house wall, a log cabin wall, a player-built wall and a rock face:
    green as before, also above head height. Aim at a closed door, a car's
    side, a tent and another mounted board: red. A board on the floor pushed
    back against a wall still places.
118. (2026-10-08) Detail levels and shadows (A24): walk away from the jon
    boat, on land and afloat (5 to 400 m), and from a snow crab, flathead
    mullet, blue tang, jellyfish, lobster, angel shark, chinook, gar, a
    crankbait, the bait bucket and the fish knife lying on the ground (1 to
    80 m): each steps down without holes, spikes, webbing between legs, a lost
    eye or a colour jump, and up close each looks as before. On the jon boat
    at every distance the motor turns with the steering and the propeller
    spins with nothing left behind. In sunlight, the snow crab, blue tang,
    alligator gar, angel shark, black devil snail, jellyfish, hairtail, small
    tackle box and bamboo net lying on the ground cast a shadow (they had
    none). Open geb_jonboat.p3d, bamboofishingnet.p3d and one lure in Object
    Builder once.
117. (2026-10-08) Great Barracuda (new): in warm sea water with a rod and a
    spoon or sardine, at dawn, catch one (/give geb_GreatBarracuda works too).
    Check it in hands (two-handed, like the pike, not through the arms),
    lying on the ground on its side, its inventory icon, at 10, 30 and 80 m
    (four detail levels switch without popping), whole, damaged and rotten.
    Up close: the photo's own eye (golden ring, dark pupil), its dark bars
    and silver flanks on both sides, the back dark with the bars crossing it,
    no seam along the back or belly, golden dorsal and anal fins, the dark
    tail running out of the stalk without a white edge. The mouth: slightly open, the fangs ivory, the inside
    dark from every side (no daylight through it); the teeth go only at a
    distance (the two far detail levels have none). Fillet it (2-4 fillets): the fillet
    shows barracuda skin and white meat, and cooks and rots like the others.
    Hang it on a medium mount: head right, upright, inside the field. Open
    greatbarracuda.p3d in Object Builder once.
116. (2026-10-08) Jon boat physics (B9): drive it into a pier, a rock and the
    shore bow first and stern first: the bow and the motor touch them where
    they are drawn (nothing passes into them, no invisible wall beside the
    hull). Afloat it sits level, the waterline a little below the floor's
    edge; beached it rests on its bottom. Stand in it: on the floor and the bow
    deck, not on air beside it. Sit in every seat: the driver on the rear deck
    at the tiller, passenger 1 on the bow deck, 2 and 3 on the middle bench, no
    one inside a bench; the get-in prompt shows looking at each seat. Shoot the
    driver, the sides, the bow, the motor and the propeller: each hit lands
    (driver hurt, the right damage zone loses health). Steer: nothing about
    the motor's collision stays behind when it turns.
115. (2026-10-08) Physics shapes (A13): drop and throw each hard lure, a
    bullfrog, minnow, salamander, crayfish, snail, clam, mussel, starfish,
    jellyfish, lobster claw, the small tackle box, a pike, a bonito, a great
    white and the fish knife onto a road, grass and a floor: each lands and lies
    still on its side on the surface (no falling through, no floating above
    it, no standing on a fin); a lure on a rod and every item in hands sit as
    before.
114. (2026-10-08) Help texts (C12): start a server on Cole's 3.3.2
    general.json (five TreasureSettings ...Info strings blank): the log says
    "general.json: brought N help texts up to date", the file now has the
    current text in those five and every other ...Info, all settings are as
    they were, and the config editor shows the "i" for the five treasure
    fields. Restart: no such line, and the file is byte-identical.
113. (2026-10-08) Predators near a town (A10): with PredatorSpawnChanceFishing
    at 1 and DebugLogs at 2, fish from a pier in a coastal town until several
    wolves or bears have come: every one stands on open ground (none on a roof
    or a bridge), and the log shows "on a building or rock ... Retrying" lines.
112. (2026-10-07) Catches like vanilla food (B8): a whole fish, a crayfish and a
    fillet look the same at every health level, and once rotten they show the
    mould at full health as well as when damaged.
110. (2026-10-06) Lure hooks and lip: the Popper, Yellow Crankbait, Squarebill
    and all four Curly Tail Jigs show light silver hooks like the Purple
    Crankbait's, in hands, on the ground and on a rod, and still look right
    when damaged and ruined; each jig keeps its own colour with a silver hook;
    the Squarebill carries the same hook sets as the others, its bill is clear
    blue, its face looks as before and its belly has no hole where the old
    eyelet was; the Yellow Crankbait keeps its own clear lip.
111. (2026-10-06) Config editor (B17, C10, A3): load a fish.json with a null
    Species row, a row without Classname and a geb_Bonita row, and a bait.json
    with a bait row without BaitClassname: every tab draws, the bad rows are
    named with Remove, geb_Bonita is flagged as renamed, the download keeps the
    file as loaded, and the nine fish fields have working "i" buttons.
