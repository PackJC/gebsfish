# MAYBE_ISSUES — repo audit findings

Living list of unresolved maybe-issues. Delete entries as they are resolved.

Latest review: 2026-10-02 — a second full pass (scripts, configs, docs, the
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
and Bonito, Yellowtail Snapper and In-Line Spinner renamed in English.
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

## Also noted — lower priority

### 26. JSON "missing key loads as 0" premise may be wrong
- `gebsfishConfig.c` `GebJsonFileHasKey` (and its comment block) assume a key
  missing from the file deserializes as 0/false. The engine reader looks to
  leave a missing scalar at its current value (the class initializer), and to
  read a missing object/array as `{}`/`[]` — so `if (!Species)`-style reseed
  checks may never fire for a deleted key. Not confirmable statically for
  engine-created sections. One staging test settles it: delete one bool and one
  section from a JSON file and restart.

### 28. Smaller items
- `ConfigSync` is sent with `identity.GetPlayer()` as target
  (`geb_missionserver.c:50-51`); vanilla prepare-time syncs use null. Possible
  drop on reconnect while the old body exists (low).
- MissionMainMenu also runs the MissionBase init/teardown, and since the #29
  fix its destructor deliberately nulls `m_gebsConfig` / `g_GebConfigReceived`.
  The bank guard keeps it away from a newer mission's config, but a join test
  with DebugLogs=1 should confirm the menu is torn down before ConfigSync lands.

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

### 14. Whole fish weigh up to 1 kg more than their config weight — accepted
- No fish sets `weightPerQuantityUnit`, so they inherit Inventory_Base's 1 g per
  quantity unit, and `FishQuality = 1.0` spawns every fish at full quantity
  (1000). A SlimySculpin (weight 80) weighs 1,080 g. Left as is on purpose
  (2026-10-01); listed so nobody re-flags it.

### 15. Sea or pond follows vanilla's test — accepted
- The rod, net and spear decide sea or pond with vanilla's `SurfaceIsSea` /
  `SurfaceIsPond` at the aim point (terrain below the current tide), not the
  surface's liquid type, so surf above the tide line can count as a pond and a
  lagoon below sea level as the sea. Kept as vanilla does it (2026-10-02);
  listed so nobody re-flags it.

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
44. (2026-10-02) Spear fishing: with a Spear (and a Bone and a Stone Spear)
    in hand, aim at water within 3 m and under 1 m deep: "Spear fish!"
    shows; deeper water doesn't. The animation plays and ends (no hang),
    about 40% of stabs drop a catch at your feet, and the spear loses health.
    `Enable` 0 removes the prompt; the config editor shows the section.
45. (2026-10-02) Fish-knife speed: on a dedicated server, two players fillet
    back to back, one with a gebsfish knife and one with a vanilla knife, then
    swap. Each fillet takes its own knife's time, and nobody is left in the
    animation after the fillets drop.
38. (2026-10-02) Item text: in English and two or three other languages,
    inspect the angelfish (now the gray angelfish), redbreast sunfish, lake
    sturgeon, yellow caviar (pike roe), Neosho bass and smallmouth bass, and
    the leopard shark (no "too heavy to carry" at the end). The
    bonito, yellowtail snapper and in-line spinners show their new English
    names, and so do the bonito and yellowtail snapper fillets.
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
    not a crash).
50. (2026-10-03) Fillets: fillet a walleye, a rainbow trout and a sockeye salmon.
    The fillets have vanilla's walleye/steelhead shapes, sit right in hands,
    in inventory and on the ground, and bake, boil, dry, burn and rot with
    vanilla's looks for those fillets. Fillet a bass, a tuna and a flounder:
    raw meat is pinkish-white, deep red and white. Check the leopard shark
    (saddles with paler centres, spots, gill slits, fine rough skin up close;
    fin undersides pale) and the cherry salmon (real scales and fin rays, dark
    back, silver sides, rosy band, wet sheen) whole, damaged, rotten and as
    fillets, in hands, in inventory and on the ground. Same for the largemouth
    and smallmouth bass (fins cut cleanly with no dark rim, also from a
    distance; the smallmouth's eye red) and the hairtail (silver all over,
    pale dorsal fin; check it isn't see-through or flickering). Also the
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
