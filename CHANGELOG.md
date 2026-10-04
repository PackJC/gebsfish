# Changelog

## v3.3.3 — Unreleased

### Requirements & Compatibility

- DayZ 1.29 compatibility
- **Community Framework (CF) is now a required dependency** — the RPC system migrated to CF's RPCManager
- `DZ_Weapons_Melee` added as a required addon; all fish now have melee functionality (matching vanilla)
- New map yield support: Deadfall (credits: DapperDan)
- **Custom maps keep the mod's fish** — a map without a hook in the mod whose world data clears the game's catch list after the mod has registered wiped every gebsfish catch. Once the mission has built its world data, the mod now registers its catches again, ahead of the map's own: where both define a catch, `fish.json` and `junk.json` decide, and the map's extra catches stay. Third-party map fixes that fire the yield invoker again work too

### New Systems

- **Weather catch buffs** — global rain / storm / time-of-day multipliers in `WeatherSettings`, plus per-fish Rain/Storm/Dawn/Day/Dusk/Night multipliers on every species (trout favour rain, walleye / pike / catfish favour night, sturgeon favours storms). A stacked-multiplier cap prevents storm + night from compounding past 2.0x. Snowfall counts as rain (the heavier of the two picks the band), so the buffs also work on Sakhal, which snows instead of raining. Fishing rod description hints at the mechanic
- **Moon phase** — accurate synodic phase (Meeus Julian Date algorithm) computed from the in-game date drives a night-only catch buff: full-moon nights up to +20%, new-moon nights down to -10%. Independently toggleable
- **Water temperature** — per-fish `TempOptimal` / `TempMin` / `TempMax` (degrees C) form a bell curve seeded from ecological buckets (cold deepwater, cold, cool, warm, tropical). The water temperature is the map's own from the game's world data (Chernarus 15 °C fresh / 23 °C sea, Livonia 20 / 25, Sakhal 2 / -0.5) with a seasonal swing (±6 °C fresh, ±3 °C sea, warmest in early August), so Sakhal fishes like an arctic map out of the box; a global `WaterTempOffset` shifts the whole curve for custom maps or themed servers (frozen lake `-10`, tropical `+5`) without editing every fish. **If you followed the earlier advice to set `WaterTempOffset` to `-5` for Sakhal, set it back to `0`:** the map's own cold water is now built in, and the old offset would push Sakhal 5 °C colder still
- **Bite-speed cycle scaling** — every fish carries a 24-hour `BiteSpeed` curve tuned to its real-world circadian pattern; the catching system aggregates the active pool (weighted by abundance and time of day) to drive how long you wait between bites
- **Bait / lure preference matrix** — every bait and lure carries per-fish multipliers that bias which fish takes the hook: worms and insects favour panfish and trout, soft-plastic worms favour bass, live minnow and salamander favour pike / musky / walleye, live shrimp favours reef / tropical fish, spinnerbaits favour bass / pike / musky, spoons favour trout and salmon, jigs favour bass / walleye. Numbered lure variants share one family entry (`geb_SpinnerBait` covers `geb_SpinnerBait1-4`; an exact numbered entry still overrides). Roughly 700 seeded pairings, all overridable in JSON, master `Enable` toggle at the top of `bait.json`. Final pick weight = CatchProbability x weather x time-of-day x bait
- **Hook-from-fish recovery** — filleting a fish has a small configurable chance (default ~1/250) to recover a damaged hook or lure "stuck in the fish", which drops on the ground with the fillets; the hook pool, weights, and health range are admin-tunable
- **Ultra-rare treasure catches** — an extremely rare chance on a successful catch to pull up a container full of loot. Two independent admin-defined pools: `TreasureContainers` decides what the treasure arrives as (weight, health range, and its own item count), `TreasureLoot` decides what goes inside (weight, health range, quantity range for stackables). Every item slot rolls the loot pool separately, so no two hauls match even from the same container. Default chance is `0.0002` — roughly **1 in 5000 catches**, not casts, so a session landing 60 fish has about a 1.2% chance of seeing one. Treasure only bites on a **proper fishing rod** — the crafted improvised rod never rolls (`RequireRealRod`, on by default) — and winching a haul up is brutal on tackle: each pull costs the rod a third of its maximum health, ruining a pristine rod in **three treasures** (`RodCatchesToRuin`, `0` disables the wear). Seeded with plain vanilla classnames so it works out of the box, and meant to be replaced. Toggle with `TreasureSettings.Enable`, or set `Chance` to 0
- **Spear fishing** — hold a Spear, Bone Spear or Stone Spear and stab into shallow water (up to 1 m deep, within 3 m): no bait, a quick action, and the fish of the shallows (carp, panfish, bass, bowfin and bullfrogs in fresh water; flounder, grunts and blue tang at sea; mullet and gar in both). A new `SpearFishingSettings` section in `general.json` holds an on/off switch, the find chance, the maximum depth, a predator chance and a weighted catch table with water types; the config editor edits it. Each stab wears the spear
- **Cooler freezer system** — coolers keep contents cold, live bait is perishable, and a frozen fish can't be filleted until it thaws
- **Bait freshness rules** — each container has one job, and they do not overlap:
    * **Worm Container / Bug Catcher** — hold worms, grubs and insects, and pause the ~90 minute live-bait death timer
    * **Cooler** — pauses both food rot and the live-bait timer for anything inside
    * **Bait Bucket** — holds small aquatic catches only (minnows, crayfish, shrimp, frogs, salamanders, clams, mussels, snails, starfish and jellyfish) and stops them rotting, which keeps the minnow, salamander and shrimp hook baits fresh. It does not accept worms or insects, so it is no help with their ~90 minute clock
    * **Tackle boxes** — can carry bait for convenience but preserve nothing
    * Artificial lures (rubber worm and all hard baits) never spoil - they have no freshness timer. They still take hook wear on every catch and can be lost like any hook
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
    * **Deleting an entry is not how you disable it.** A row you remove is treated as missing and gets re-added on the next version bump. To retire something permanently set its weight / chance / `CatchProbability` to `0` — that survives every update. A whole section emptied on purpose is respected, except `HookFromFishCatches`, `TreasureContainers` and `TreasureLoot`, which refill with the defaults when empty (set their weights to `0` instead); a section that is entirely absent gets re-seeded
    * **New on/off toggles are re-applied during migration.** The engine's JSON loader zeroes any field your file doesn't mention rather than using the built-in default, so a toggle introduced in a later version would otherwise arrive switched off on every existing server. On startup the mod checks whether your file contains each newer toggle (`CraftFishMount`, `RequireRealRod`, `RodCatchesToRuin`): a missing one gets its intended default, and once it is in your file the value you set, including `0`, is kept through every future update
    * Pre-3.3 layout files (`fishingsettings.json`, `Fish/Logs/`, `extras/mpmissions/`) are swept into `$profile:Gebs/gebs_oldfiles/` on first start so old and new never sit mixed together, and the emptied folders are removed afterwards. Nothing from the old monolithic config is migrated into the new files — it is archived so you can still read your old tuning
- **Config editor** — `docs/config-editor.html` (the wiki's 🛠️ Config Editor link) opens your four JSON files in the browser, edits them with sliders, toggles and tables, and downloads them again; nothing is uploaded anywhere. Its **What will bite?** tab shows the odds of every species for a map, date, hour, rain, water and bait, computed from your own files with the same maths the server runs, plus the junk share, the bite timing, the moon and the treasure odds

### New Fish & Creatures

- Hammerhead Shark
- Lake Sturgeon (with roe -> new Black Caviar item)
- Alligator Gar
- Muskellunge, Barred Muskellunge, Tiger Muskellunge, Spotted Muskellunge
- Northern Snakehead
- Neosho Bass, Striped Bass
- White Grunt, Southern Flounder, Yellowtail Snapper
- American Bullfrog, Red Salamander
- New Crayfish variants: Cave, Florida, Monongahela, Red Swamp, Rusty
- Northern Pike and the muskellunges gain roe -> new Yellow Caviar item

### New & Reworked Models

Major art pass across the existing roster — new or reworked models and textures for:

- Northern Pike, Bluegill, Red Breast Sunfish, Yellow Perch, Fathead Minnow, Sauger, Walleye
- Brown / Brook / Rainbow / Cut Throat Trout, Lake Trout, Chinook Salmon
- Spotted Bass, Bonito, Bowfin, Large Mouth Bass, Small Mouth Bass, White Bass
- Blue Marlin, Sailfish, Humphead Wrasse, Yellowfin Tuna
- Asian Sea Bass, Siamese Tigerfish, Angelfish, Pacific Cod, Perch, Severum, Rougheye Rockfish, Redhead Cichlid, Blue Tang
- Snow Crab + Snow Crab Legs, Blue Jellyfish, Black Devil Snail, Mussel, Starfish, Blood Clam
- **Fillet meat in its real colour** — every fillet's raw meat now has its species' colour: white for most freshwater and reef fish, pinkish-white for bass, snapper, rockfish and sharks, orange-pink for trout and salmon, deep red for sockeye, tuna and bonito, pink-red for marlin and sailfish. Most fillets showed the carp's or mackerel's pink before, and the flounder and yellowtail snapper were tuna-red. The cut edges of the fillets show the same meat
- **Walleye and trout fillets on vanilla's models** — the walleye, sauger, yellow perch and Pacific cod fillets now use vanilla's walleye pollock fillet, and the rainbow, brown, brook, cutthroat and lake trout and the cherry, sockeye and chinook salmon fillets vanilla's steelhead trout fillet. Each keeps its own raw texture (vanilla's, tinted to the species' skin) and gets vanilla's cooked and rotten looks for that fillet instead of the carp's or mackerel's
- **Leopard shark and cherry salmon look like the real fish** — the cherry salmon now wears vanilla's photographic steelhead skin (scales, gill cover, eye, fin rays), turned into a fresh-run masu salmon: dark blue-green back with small black spots, silver sides, a soft rosy band, clean lower flanks, and vanilla's wet-fish sheen. The leopard shark has a new texture, normal map and shine map at 2048: bronze-grey back fading to a cream belly, ragged black saddles (the big ones with paler centres), irregular spots, a banded tail, five gill slits, snout pores, a slit-pupil eye, rough skin and pale fin undersides. Both fillets' skin sides come from the new skins, and the wiki pictures are updated
- **Bass and hairtail look real** — the largemouth and smallmouth bass keep their photographs but lose the dark rim round every fin (the cut-out edges blended in the black background), and get relief maps made from the photos (scales, fin rays, gill covers) and a wet sheen; the largemouth is a touch more olive, the smallmouth bronze rather than lemon-yellow, with its red eye. The largehead hairtail is re-skinned from a real fish photograph (vanilla's mackerel): its head and real eye from the photo, its long ribbon body from the photo's silver flank at true scale (cross-faded sections, no stretching or repeats), its long dorsal fin from the photo's fin rays; graded to chrome silver with a steel-blue line along the back and pale see-through fins, with a shine map of its own (it used the carp's). Their fillets' skin sides come from the new skins, and the wiki pictures are updated
- **Siamese tigerfish and redhead cichlid look real** — both keep their photographs, repaired so they hold up from every side: the strips along the back and belly, the lips, the throat and the skin hidden in the jaw's folds showed streaked, stretched photo (and dark outlines) from the front and below; they now continue the skin around them, the seams where the two side photos meet are gone, and each eye shows the photographed eye with its dark rim on every face of the eyeball and its socket, from any angle. The tigerfish is warm gold instead of neon yellow, with brown-black bars that now run over the back and under the chin and a cream belly; the redhead cichlid has a rose-red head and throat, its body as photographed. New relief and shine maps without the old streaks, a wet-fish sheen, the fillets' skin from the new skins, and new wiki pictures
- **Bluegill looks real from every side** — the photo is kept, but the forehead, the front of the mouth, the throat and the ridges along the back and belly no longer show the photo's stretched outline (stripes on the forehead, a mask-like mouth, a chevron on the throat); the white fringe round the fins is gone; the pectoral fins, which carried a patch of scaly breast skin, are now thin see-through amber fins with rays; new relief and shine maps and a wet sheen. The fillet's skin side comes from the new skin, and the wiki picture is updated
- **Atlantic blue marlin looks real** — a new 2048 skin built from a real fish photograph (vanilla's mackerel): every part of the marlin takes the photographed skin from the same place on that fish, so it has real skin texture, sheen, fin rays and a real eye, graded to a blue marlin: cobalt-navy back, steel-blue to silver flanks, a silvery-white belly, navy fins, a dark slate bill and faint pale-cobalt bars; toward the tail the navy spreads down the narrow wrist and the silver fades out, so the body runs smoothly into the dark tail. The back, belly and throat are sampled around the body so they don't streak from above or below. It replaces a texture with teal stripes, a brown belly and blurred patches. New relief and shine maps and a wet sheen; the fillet's skin side comes from the new skin, and the wiki picture is updated
- **Angel shark looks real** — a new 2048 skin (it was 256, blocky up close) grown from real photographed skin (vanilla 1.30's catfish, a scaleless fish) at one true scale over the whole shark, so there is no stretching and no repeating pattern: a sandy grey-brown back with fine marbling and scattered small pale and dark spots, as on a real angel shark, in place of a pale green back with painted rings and a white outline. The underside is white with fine skin grain, the mouth across the front of the head, five gill slits on each side and the vent. The model's own eye parts are collapsed to a point inside the body, so it had no eyes: they are now on top of the head where a real angel shark has them (from the catfish's photographed eye), with the crescent spiracles behind them. New relief and shine maps and a wet sheen; the fillet's skin side comes from the new skin, and the wiki picture is updated
- **Southern flounder looks real up close** — it keeps its photograph, but its eyes were painted dots (a black pupil in a white ring) a third the size of the eye bulges on the model; they are now real photographed fish eyes (vanilla's mackerel) with a golden-bronze iris, laid onto the bulges in 3D so they stay round from every side. The eyed side goes from orange-brown toward the olive-brown of a real southern flounder, and the blind-side pectoral fin, which was mauve, is pale and see-through like the rest of the blind side. New relief and shine maps and a wet sheen; the fillet's skin side comes from the new skin at its true size (it was a blurred close-up with a few big spots), and the wiki picture is updated
- **Hammerhead shark looks real** — a new 2048 skin in place of a smeared 1024 one with dark blotches: real photographed skin (vanilla 1.30's catfish, a scaleless fish) grown into one large sheet at true scale and laid on from three directions, so its fine grain is the same size everywhere, in a real hammerhead's countershading: bronze-grey above, white below the line along the lower flank, the hammer grey on top and white beneath with the fine pores along its front, dusky tips under the pectoral fins, five gill slits on each side and the nostrils on the hammer's front edge. Its eyes showed a shrunken copy of the whole skin, tiled (the model mapped each eye over the entire texture three times); the model's eye faces now have a place of their own on the texture, in every detail level, and a photographed fish eye with a golden iris. New relief and shine maps and a wet sheen; the fillet's skin side comes from the new skin, and the wiki picture is updated
- **Flathead catfish looks real up close** — it keeps its photograph, now at 2048 with real skin grain from vanilla 1.30's photographed catfish laid over it, so it stays sharp in hand. Its back and sides get a real flathead's dark brown mottling (from the catfish photo's own patches), and its fins are olive-brown like the body instead of grey-black. The head's cheeks are mottled like the body, the throat's strong pink veins are toned down to a cream throat, and the barbels, which were uniform grey wires, carry vanilla catfish's photographed barbel: the long whiskers and the small ones on the forehead dark olive-brown, paling toward their tips, the four chin barbels pale yellowish-white. The pectoral and pelvic fins lost the black wedges along their edges (gaps in the fin texture), and the straight seam across the throat, where the bright belly met the pinker throat, is softened into a gradual change. It had no relief or shine map and a flat placeholder material; it now has a relief map (fin rays, skin, the folds of the head), a shine map and vanilla catfish's slimy sheen, also when damaged, ruined or rotten. The fillet's skin side comes from the new skin, and the wiki picture is updated
- **Walleye, sauger and bowfin cleaned up** — they keep their photographs. The walleye's and sauger's mouths were see-through (the strip between the jaws was cut out, so light showed through a closed mouth); it is now a dark mouth line, and the slivers along their back and belly seams are solid. The bowfin lost the bright red lipstick stripe round its mouth (the front of the lower jaw is now the pale cream-olive of the jaw) and the pale knobs where its pectoral fins join. The fins' cut-out outlines no longer have a dark fringe. The walleye and the bowfin had no relief map at all; all three get one, plus new shine maps and a wet sheen, and the bowfin's fillet skin comes from its own skin (it had painted diagonal bands)
- **Mussel looks real** — its shell showed blocky grey squares. Two causes: the model shaded every face flat (41% of its edges were marked sharp), so each facet of the glossy shell caught the light on its own, and the shell photo was a heavily compressed JPEG whose dark areas were full of 8x8 blocks and false-colour blotches. The model's normals are now smooth (only the valves' rims stay sharp; shape, UVs and size unchanged) and the shell texture is rebuilt at 1024 from the photo's shading and growth rings in a clean glossy blue-black, with the pearly nacre inside kept. The meat, flat mustard-yellow paint before, is now a blue mussel's apricot-orange with a dark wavy mantle edge, and it has a material of its own (it had none), so it is wet and glossy too
- **Pacific cod has a new model** — a better-shaped, smooth cod in place of the old model, with three detail levels for distance; it is as long as before (76 cm) and sits in the hands, the inventory and on the ground the same way. Its 2048 skin is made from the real cod photographs the old one used: a spotted golden-brown back, silver-white belly, gill covers and cheeks, real photographed eyes, and dusky olive-brown fins with rays, fine speckles and pale edges on the dorsal, anal and tail fins. It has one barbel under the middle of the chin (the source model had whiskers at the corners of the jaw, like a catfish), and its pectoral fins lie close along the body like a landed fish's. The old model's hidden leftovers (yellowfin tuna finlets inside its back, a lump inside its head) are gone with it, so the cod no longer loads the tuna's texture
- **Rougheye rockfish looks real** — its pectoral fins are sculpted lying against the body, but the photo's red fin covered only their lower part; the upper part showed the photo's dark shadow and the body's scales, so the fin looked like a flame painted on the flank. The photographed fin now fills the whole sculpted fin (its rays fanned out to the fin's real outline) with a fleshy pink base, and the fins' inner faces are red too. The photos' yellow-green cast is now a rougheye's pink-red, the dark smeared underside of the head and belly is a rockfish's pale pink, and the seams between the photos are blended
- **Bonito looks real** — its photographs (a striped bonito, as its Japanese and Chinese names say) had a strong blue-lavender cast even on the white belly, a bright cyan streak along the back and tan stains by the tail. The lower body is silver-white now, the back a deep steel blue under its dark stripes, with no streak or stains, and the underside of the head (stretched lavender-grey) is silver-white
- **Sockeye salmon, striped bass and white bass look real from every side** — each is one side-on photograph on both flanks. The forehead, the front of the mouth, the throat and the ridges along the back and belly showed its stretched outline and are skin now; the eyes are the photo's eye laid over the whole eyeball; the fins lost the photo's background fringe and the pectoral fins are thin see-through fins with rays. The sockeye's neon red is a deep crimson, darker on the back, with a spawning male's olive-green head and pale jaws; its flash glare is gone and its own scales show. The striped and white bass lost their yellow cast and have darker backs
- **Every fish and shellfish has a real relief map and a wet sheen** — all 76 live-creature materials. The old relief maps were made from the photos, but half had under half the strength of vanilla's own fish maps (the ones made this year were fainter still), and 45 had the relief inside out or one direction flipped, so bumps were lit from the wrong side; the walleye, bowfin, brook trout (its relief map sat in the shine slot), brown trout and blue jellyfish had none. Each now has one at the strength of vanilla's own fish maps, made from its photograph (scales, fin rays, gill covers, shell ridges); the ten that weren't made from the photo (the starfish's bumps, the snow crab's shell, the lobster tails, the pike, snakehead, great white and others) are kept and the photo's detail added. The sheen follows vanilla's own materials: scaled fish like vanilla's walleye pollock, trout and salmon like its steelhead, silvery ocean fish like its mackerel, pike and gar like its carp, the catfish and bowfin slimy like its catfish, crayfish, lobsters, crabs and shellfish like its shrimp; most had the same flat, dull sheen. 51 shine maps are made even (the old ones followed the photo's lightness, so dark spots looked dry and pale patches oily, a few the other way round), and the redbreast sunfish gets its own material and relief map instead of the bluegill's
- **Cooked and rotten looks** — lobster tails and claws and king and snow crab legs turn red-orange when baked or boiled, and get their own dried and burned looks (they kept the raw look before). Rotting whole fish, lobsters, crabs, the crab and lobster parts and the Fathead Minnow now show vanilla's mould, the way rotten fillets and meat do.

### New Vehicle

- **Jon boat** — new drivable flat-bottomed boat with five variants (green aluminum, gray aluminum, desert / snow / forest camo), custom damage zones (chassis, engine, three floaters), SparkPlug slot, and cargo space. More boat content coming in a future update
- **Jon boat deck mounts** — two deck slots that take any cooler or tackle box and show it sitting on the deck. Both accept the same families so you can run two coolers, two boxes, or one of each. The vanilla jerry can is deliberately not included: a proxy gives one position and rotation to everything attached to it, and the can's model axes don't match the gebsfish containers, so no single orientation suits both

### New Items & Crafting

- Grub Worm (chance to find when digging for worms)
- Coolers in 11 colors (with the freezer system)
- **Wooden Fish Mount** — a trophy plaque you hang on a wall and mount your catch on:
    * **Crafted** from **1 Wooden Plank + 1 Metal Wire**, with a **Hacksaw** on you. Combine the plank and wire; the saw isn't consumed but takes durability, and the craft is refused without one. (DayZ caps recipes at two ingredients, so the saw is enforced as a tool rather than a third slot.) Disable it with `RecipeToggles.CraftFishMount` in `general.json`
    * **Placed on walls** — hold to place and it snaps flat against any near-vertical surface, hanging face-out like a picture. Aim somewhere without a wall and it falls back to normal ground placement
    * **The trophy is the actual fish** you caught, not a generic model — its weight and quality persist through the attachment, so a personal-best catch stays a personal-best on the wall
    * **Mounting is permanent.** Once a fish is on the plaque it can't be detached, dragged out, or taken to hands. Ruined and rotten fish are refused up front. Destroying the mount does **not** give the fish back — the trophy is destroyed along with the plaque. Mounting a catch is a one-way decision, which is what stops the plaque doubling as a free never-rots fish locker
    * **Mounted fish never rot.** Decay is paused entirely while the fish is on the plaque, so a trophy is taxidermy rather than a countdown
    * **The plaque itself lasts 45 days** untouched — the same lifetime as tents and barrels rather than the 4-hour gear lifetime, so wall trophies persist like a base fixture and abandoned ones clean themselves up on the same schedule
    * Placeholder model until the final plaque p3d lands
- Craft metal hook from metal wire + pliers
- Bamboo net repair recipe (Netting + damaged net -> Worn)
- New Bamboo Fishing Net model and full texture set

### New Tackle & Lures

- 4 Spoon Lures
- 4 Curly Tail Jigs
- In-Line Spinners 1-4 (new models)
- Squarebill Lure (replaces Lure4)
- Yellow Crank, Purple Crank, Popper lures (replace old lures)
- New Small Tackle and Large Tackle models
- New Worm Container and Bait Bucket models

### Balance

- **Shrimp is now hook bait** — vanilla Shrimp, caught in fish traps at sea, attaches to the hook (and traps) like the minnow does, with its own bait-matrix row: the signature reef/tropical bait (2.5x — the one category no other bait favored) and a strong general saltwater choice (1.8x small, 1.5x medium saltwater). Trap it, keep it fresh in the Bait Bucket, hook it
- **Fishing rods carry on the back** — the vanilla rod, all four gebsfish color rods, and the crafted improvised rod now attach to the Shoulder/Melee slots like a rifle. Fixes the long-standing rod bug: the mod's slot additions could be wiped by config load order against vanilla `gear_tools`, now pinned via `requiredAddons`. All rods also carry the `fishingpole`/`fishingrod1-10` slots for cross-mod rod-holder compatibility
- **Realistic catch probabilities** — all 79 fish `CatchProbability` defaults reflect real-world abundance and bite habit: bait / abundant 20-25, common gamefish 12-18, uncommon 6-11, trophy / rare 2-5
- **Realistic fish weights** — 63 fish `weight` values rebalanced against real-world adult catch sizes: panfish / reef fish dropped (BlueGill 1700 -> 400 g), trophy pelagics raised (GreatWhiteShark 3700 -> 20000 g, Blue Marlin -> 15000 g), pike / muskellunge and trout / salmon families tiered by species. Landing the largest pelagics now carries real encumbrance — by design
- **Ecology pass** — White Bass and Bowfin moved to behaviorally correct bait-preference buckets; 12 fish `Environment` values corrected (anadromous salmonids, Striped Bass, Barramundi, mullet, and gar now appear in both fresh and salt water; three freshwater species un-misclassified from saltwater)
- **Junk is about one rod catch in ten everywhere** — junk's weight is set on every cast from the fish that can bite there, so junk comes to `JunkShare` of rod catches (new in `junk.json`, default `0.1`, close to vanilla's ~10.6% on Chernarus and Livonia) on every map, in every season and at every hour, with or without bait. With a fixed weight, cold water that shrinks every fish left Sakhal's sea almost half junk. Each junk entry's `CatchProbability` now only sets which junk item comes up; where no fish can bite, a rod pulls only junk, as in vanilla. Existing `junk.json` files gain the key at `0.1`, and the config editor's Junk tab has a slider for it
- Default predator spawn chance reduced from 25% to 1% per action
- Geb fish knives: +54% durability over vanilla HuntingKnife and 10% faster filleting (configurable via `FishKnifeSpeedMultiplier`)
- 30% keep-chance for caviar when filleting roe fish (configurable via `CaviarChance`)
- Shrimp, mussels, crabs and lobsters can now be caught in large traps as well as small ones (crayfish and blood clams stay small-trap-only)
- Fishing rods repair to Worn at best; Ruined tools can no longer be repaired
- Adjusted bait bucket size
- Raw and burned fish fillets, lobster and crab now risk food poisoning like vanilla meat, and they fill the stomach like vanilla's carp and mackerel fillets (raw and burned the most, cooked the least). Energy and water values are unchanged
- Fishing gloves no longer protect your hands in toxic zones — they had inherited the NBC gloves' chemical protection
- Gebsfish gear left untouched on the ground now lasts 4 hours, vanilla's lifetime for fishing rods, knives and most tools, instead of 2. A stocked cooler or tackle box left outside a base no longer vanishes with its contents after 2 hours
- Lake Trout now carries roe (Red Caviar) like the other trout and salmon
- Whole fish use vanilla Carp's temperature settings: they freeze and thaw at 0 °C instead of -2 °C, take about 110 minutes to freeze or thaw instead of about 66, change temperature more slowly the bigger they are, and heat to 110 °C at most. They also make Carp's organic impact sound

### Localization

- New stringtable entries: Hammerhead Shark, Lake Sturgeon, Cooler, Wooden Fish Mount, Craft Metal Hook, Rougheye Rockfish, the treasure announcement and the spear fishing prompt
- Jon boats now display "Jon Boat" with a proper description in all 13 languages (previously vanilla "Rubber Boat" and a missing description key)
- Minnow Container renamed to Bait Bucket, name retranslated in all 13 languages
- Orphaned rows pruned (fillet keys for species without fillet items, superseded king crab tail, generic clothing descriptions replaced by per-color keys, unused tackle box name)
- **Translation pass over all 12 other languages** — about 970 cells fixed, in names and in the descriptions that repeated them. Species and items that were translated as the wrong thing now use their established common names: the bluegill was a kingfisher in French, the walleye a salmon in Chinese and a porpoise fillet in Russian, the sauger a deer in Portuguese, the fathead minnow a mahi-mahi in German, the field cricket the sport, the rubber worm a worm gear, the king crab a horseshoe crab, the tackle boxes "tactics boxes" in French, and the coolers fans in Russian. Stale names after renames are fixed (the four lures, Lake Sturgeon, Spotted Bass), untranslated cells are translated, the predator warning no longer says it attracted "some companies", and the Simplified Chinese Chinook and Sockeye names, which held whole paragraphs, are names again
- English names made consistent: Redhead Cichlid (was "Readhead"), Rougheye Rockfish, Snow Crab Legs, Yellowfin Tuna Fillet, Angel Shark Fillet, Asian Seabass Fillet, Siamese Tigerfish Fillet, Redbreast Sunfish Fillet, Largehead Hairtail Fillet, American Bullfrog, Light Blue, and every "… Tackle Box" (the small one is now "Small Tackle Box")
- **Every item description checked against the English in all 12 languages** — about 1,080 description cells rewritten. Machine translation had turned animals into other animals (crappies into crabs in five languages, the muskellunge into a muskrat, the sauger into a seal, cod, char or lobster, the walleye into a pike), used ocean-sunfish words for the North American sunfishes, garbled or dropped sentences, changed numbers, and translated English nicknames word for word. The Simplified Chinese descriptions, which were short and often wrong summaries, are now full translations, and the Traditional Chinese column now uses Traditional characters throughout (most of it was Simplified)
- About 480 item names corrected: established local names instead of word-for-word calques or the wrong species (the bonito, barramundi, alligator gar, Louisiana crayfish, white grunt and northern snakehead among them), no English left in names ("Fun Green Tackle Box", "In-Line Spinnerbait"), the four in-line spinners named as in-line spinners, fillets that match their fish, the fishing hats and shirts named as the caps and T-shirts they are, and the fish mount named as a trophy plaque rather than a bracket. Craft prompts follow the renamed items
- Action prompts follow vanilla's wording ("Dig bugs", "Gather minnows"), and the predator warning no longer says "attracted some company" word for word in Polish, Italian, Spanish and Portuguese
- English descriptions: Wikipedia citation and footnote markers removed, characters lost to a bad encoding restored ("M?ori", "?ahi", "so mei ??"), and typos fixed (Lake Petén, electroreceptors, aquaria, Cottus bairdii, a broken White Bass sentence, a few grammar slips)
- Descriptions that described the wrong fish, rewritten in every language: the Angelfish (the cichlid family's text, tilapia and all) is now the gray angelfish, the marine reef fish the model shows; the Redbreast Sunfish and Lake Sturgeon describe their own species instead of the sunfish family and sturgeons in general; Yellow Caviar is pike and muskellunge roe instead of a copy of Black Caviar's sturgeon text; the Neosho Bass is a species of its own (Micropterus velox); and the Smallmouth Bass is placed in Centrarchiformes like the other basses. The Leopard Shark's text no longer ends with "Way too heavy to carry!" (it weighs 5 kg). Renamed in English to match their descriptions and the other languages: Bonito (was "Bonita"), Yellowtail Snapper (was "Yellow Snapper") and In-Line Spinner #1–#4 (was "In-Line Spinnerbait")

### Code & Internals

- Replaced all `GetGame()` calls with `g_Game` for consistency
- Config tidy-up: vanilla's `NotCookable` and `FoodAnimationSources` are declared at the top level, where vanilla defines them, so whole fish inherit the real classes instead of empty stand-ins made inside `cfgVehicles`. The bamboo net's texture override targets its real `Camo` part, and the net and the bug catcher get the `Model.cfg` entries their overrides need
- Removed invalid `ref` keywords from RPC handler parameters (CF compatibility)
- Data-driven pipeline: one generic catch yield and one generic fillet recipe seeded per Species row replace 79 per-fish yield classes and per-fish recipe classes (vanilla fish keep their modded Prepare* overrides)
- BiteSpeed data consolidated from 79 inline 24-hour arrays into 8 named circadian curves
- Weighted-pick logic consolidated into a shared `GebWeightedPick` helper; the catch pick memoizes per-species weather/bait multipliers instead of recomputing per pool entry
- Yield bank init no longer registers vanilla's 15 default yields just to clear them (vanilla's clear leaves stale sync indices). Every registration rebuilds the bank with gebsfish's yields first and everything else behind them, so a world that fires the init twice does no harm and a client's rebuild on config sync matches the server's list. Another mod registering a catch gebsfish also registers no longer replaces gebsfish's (Ice Fishing's carp, mackerel, sardines and bitterlings on Sakhal)
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
- Renamed `Sturgeon` -> `LakeSturgeon`; `OldTackle` model files -> `MediumTackle` (class names finalized next wipe); Bug Catcher (`geb_BugContainer`) moved from `data/tools/` to `data/tackle/`
- Predator chat-warning code and docs renamed to match reality: the message goes to the triggering player only (the warning sound is what nearby players hear)
- Removed a redundant modded `YieldItemBase` constructor that made every yield item run `Init()` twice per construction
- All p3ds now use a `Camo` hidden selection to support retexturing
- Asset naming pass: tool and clothing textures renamed to engine conventions (`_co` / `_normals` / `_smdi`); fish knife and big-game fishing line materials updated
- Added skinning action to Neosho Bass and Striped Bass
- The root config's hover logo uses `logoOver`, the key DayZ reads for mods (as mod.cpp already did); `logoHover` was ignored
- Tools: the changelog builder keeps paragraphs and `*` bullets (the wiki was missing v3.3.0's Removed list, the v3.0.0 intro and a line of the art-pass notes) and keeps the page's line endings; the render manifests store repo-relative paths, are written by the builders themselves (a PowerShell redirect wrote UTF-16 the renderers couldn't read) and leave out proxy classes; default folders follow your own Desktop, and Blender and fonts are found automatically; `batch_gifs.py` takes proper arguments and old frames no longer leak into a re-rendered GIF; the wiki's item gallery files the Worm Container and Bait Bucket under gear; `build_wiki_assets.py` won't rewrite the fish details without renders; `make_posters.py` names items through config inheritance and no longer deletes files from its output folder; `compare_rig.py`, a humanoid-rig tool from another mod, is removed; the fish renders (wiki pictures, GIFs) show each item's relief map, shine map and sheen from its material, not the colour texture alone, and the fish manifest records each species' material. Every wiki fish picture is re-rendered that way
- Removed `geb_CAContinuousRepeatFishing.c`, a line-for-line copy of vanilla's fishing signal timing that only sent four debug messages to the Gebs log; replacing vanilla's function would have hidden any future vanilla change to it. Vanilla still logs those cases in its own script log
- Live bait ages on the Central Economy's periodic item update, the clock vanilla food rot runs on, instead of a timer per worm: hundreds of loose worms meant hundreds of timers ticking every frame, and dead ones kept ticking. Same 90-minute lifetime, same pauses in the worm and bug containers and coolers

### Fixed

- **Gebsfish gear never spawned as world loot.** The generated `gebsfish-types.xml` marked every item `crafted="1"`, and the Central Economy never spawns crafted types as loot, whatever their nominal — so rods, knives, tackle boxes, lures, coolers and clothing never appeared, and the spawnabletypes cargo inside them never rolled either. Gear is now written `crafted="0"` with vanilla's `-1` quantities (any other range made the CE re-roll quantities, e.g. repair kits with random uses left). Live insect bait (grasshopper, cricket, grub) stays crafted with nominal 0 like vanilla worms, since it starts dying the moment it exists; the fish mount is crafted with nominal 0 like other placed structures. **Re-merge the regenerated file into your mission's types.xml after updating**
- **Most fish never rotted.** Every whole fish except the eight big ones — plus lobsters and crabs — ran as plain `Edible_Base`, whose decay is off, so their Rotten stage was unreachable and the cooler and trophy-mount preservation had nothing to do. They now rot like vanilla Carp. Minnows, bullfrogs and salamanders now use vanilla Shrimp's script behaviour as their config already said: they rot, can be eaten as meat, and cook through Baked/Boiled/Dried instead of jumping straight to Burned
- **Shrimp didn't work as bait.** It could be put on a hook and in a trap's bait slot, but vanilla only treats an item as bait when its config has a `Fishing` (hook) or `Trapping` (trap) block, and Shrimp had neither — so a hooked shrimp was never eaten and its bait-preference row never applied. Both blocks added, matching the minnow
- **Client and server could disagree on bites.** The catch math runs on both sides in lockstep, but the water temperature came from the air temperature, which a multiplayer client computes once at login and never updates, and rain and the hour were read live on each side. Once those drifted apart, a bite the player saw could be a miss on the server, or the reverse. Every cast now runs on one snapshot of the date, time and rain taken when it starts — the client sends it with the action and the server checks it against its own reading — and water temperature comes from the map instead of the air (see Water temperature above)
- **Worn, damaged and ruined items looked brand new.** The health levels of the tackle boxes, coolers, worm and bug containers, Bait Bucket, lures, fish knives, repair kit, fishing net and jon boat named vanilla materials (first-aid kit, water bottle, hunting knife, rubber boat) that the gebsfish models don't use, and the fish, crustaceans, insects and fish mount named none. Every gebsfish model now lists its own materials plus `_damage` and `_destruct` copies carrying vanilla's scratch and wreck overlays, so wear shows like it does on vanilla gear. Hit points are unchanged. Variants that recolour a shared model (crayfish, muskies, the European lobster and its claw and tail) map the model's material to their own, as vanilla does for car colours. Models fixed along the way: the Fathead Minnow, Flathead Catfish and Blue Jellyfish had no material at all (the minnow now uses the one it shipped with, the other two a plain one); the Bowfin's material path pointed at a folder on a PC, not into the mod; the crayfish model named a material and texture that don't exist; the Purple Crankbait's clear lip had the same PC-path problem and its second material was missing, and its files, still named after its earlier green and red looks, are now `purplecrank`; the Redbreast Sunfish wore vanilla carp's material on its bluegill model; the Bait Bucket, old tackle boxes and Black Devil Snail used Arma 3 reflection textures that DayZ doesn't have (now DayZ's own); and the lobster parts, cooler, old tackle box, spinner and fish knife models named textures that don't exist (now each item's own)
- The "after a catch" predator chance and the treasure roll no longer fire on a reel-in that caught nothing. Vanilla still reports success when the hook breaks on that same reel-in, so both now check that a catch actually spawned
- Crafting or repairing the Bamboo Fishing Net consumed the whole Netting stack instead of one piece
- Wooden Fish Mount tilted to the ground slope when placed on the floor: the config key is `alignHologramToTerain` (vanilla's spelling), so the `alignHologramToTerrain` line was ignored
- Tackle boxes, coolers, and the worm and bug containers were repairable with the Sewing Kit (kit type 2) instead of duct tape; they now take Duct Tape or Epoxy Putty, like vanilla's hard cases
- Treasure `Chance` is now honoured as configured. The roll used the engine's 15-bit random number, so the default `0.0002` really hit about 1 in 4,681 and nothing could be rarer than 1 in 32,768; it now uses a 30-bit roll
- fish.json validation now rejects an empty `ResultBonus` on caviar/lobster recipe rows instead of letting it through
- `FishQuality` help text: it sets how full each caught fish comes out (0–1) and values above 1.0 act exactly like 1.0 — there is no payout boost. The config editor's slider now stops at 1.0. The bait help text no longer claims bait is lost on a missed reel-in (a bite eats it; reeling in with no bite keeps it)
- Tackle boxes, coolers and bait tins follow vanilla's container rules: they don't take new items while sitting inside another container's cargo
- A fish on a trophy mount can no longer be filleted — mounting is permanent, and with decay paused on the mount an old trophy came off as fresh fillets
- Treasure loot quantities now work for ammo and magazines (they count rounds, which the old quantity call ignored)
- Treasure containers nobody touches now despawn after about two hours instead of sitting for 45–90 days and counting toward the loot economy's caps
- The rod now also wears on a bite where the hook breaks
- Custom fish.json catches without a quantity now give full fillets; they used to give none
- **The Wooden Fish Mount could be hung in mid-air.** Its placement switched off the hologram's "floating" test, which in vanilla means the aim point was out of reach (not "nothing underneath"), so aiming at the sky or at a far wall placed the plaque hovering. The test is back, and the crosshair must be on a wall or floor. To keep trophies reachable above eye level, the mount's reach is 2.5 m from your feet instead of 2 m, and the server now refuses a placement further away than that
- The Wooden Fish Mount had no item behaviour, so placing it replayed whatever deploy animation the last item used (in a fresh session, a prone drinking animation) and logged an error. It now uses the two-handed deploy
- On Sakhal, snares caught chickens and roosters, and rabbits outnumbered foxes 2:1. The mod registered Chernarus's trap animals on every map; Sakhal now gets vanilla's own list (rabbits and foxes, 1:1)
- Namalsk's snares had the same problem; they now catch rabbits and foxes 1:1, as Namalsk's own list does
- Config files are written even when `$profile:Gebs` doesn't exist yet: the folder is created first, and a write that fails is logged. It relied on the logger having made the folder, and vanilla's old save call gives up silently
- Filleting with a fish knife no longer leaves you stuck in the animation after the fillets drop. The knife's speed-up was written into the fillet recipe, which every player shares, and the server only refreshed it when a fillet completed, so it often ran the previous player's knife speed. It is now applied to each fillet when it starts, on both your game and the server
- The fish mount's placement hologram now cancels while you jump, swim, climb (a ladder or an obstacle), raise a weapon, or are restrained or unconscious, as vanilla's does
- The Bait Bucket keeps its water but can no longer go on a stone oven's or closed barrel's cooking slots or into a cooler. Its config is a WaterBottle, which made both treat it as food
- Predators spawn through vanilla's AI spawn path (`SpawnEntityOnGroundPos`: placed on the surface, AI initialised, attachments equipped) and onto bridges, rocks and other walkable surfaces rather than the bare terrain under them
- Crafting a fish mount or a bamboo net could use up planks, wire or long sticks that were part of something else: a fence, watchtower, gate or flag pole (even locked ones), a car battery, or a shelter frame. Those are refused now, as vanilla's own kit recipes do; items you carry still work
- Config editor: fillet counts (`MeatMin`/`MeatMax`) are limited to 0–10 like the server, and the maximum can't go below the minimum
- A bamboo net catch that isn't on the net's allow-list drops at the player's feet, as intended. The game created it straight in the net without asking the net's filter, and the net's load check then threw it away on the next restart
- The predator warning and the treasure announcement show in each player's own language. The server used to translate the predator warning into the server's language for everyone, and the treasure message was English only; both now send their stringtable key, which the player's game translates
- Config editor: every setting has a help button (fields the config explains as a group, such as the rain, time-window and moon values, show the group's text); the toggles are their normal size again; the treasure chance goes down to 0.00001, so a 1-in-20,000 setting can be made and reads correctly; a debug level above 2 shows as Elevated (what the game does with it), and a fish or net entry with Environment 0 shows as disabled instead of looking like "both" or "pond"; a roe or lobster recipe without its bonus result is flagged, since the server drops that recipe; and the simulator says plainly when it filled a missing setting with the default
- Filleting with the fish in hand (and the knife as the target) played the generic crafting animation; it now plays the skinning animation with the fish hidden, like vanilla's carp
- The bamboo net's animation was rewritten on every use: the first net after a restart could cancel itself (as digging for bugs did), and from then on it could start standing, which its crouched-only animation can't play. The net now crouches first every time, like digging for bugs
- Digging for bugs is crouch-only: the character crouches before the dig, and standing up cancels it. The first bug-dig after a restart could also cancel itself, because the action switched its animation and stances after vanilla had recorded the allowed stance; both are now fixed in the action's constructor
- Players' PCs no longer create or rewrite `Gebs\general.json`, `bait.json`, `junk.json` and `fish.json`, or run the pre-3.3 file migration, at the main menu. DayZ runs the menu as an offline session, so the mod took its server path there. The menu now keeps the built-in defaults in memory, as a joining client does, and drops them when it closes; offline single-player still reads the profile's files and a server still sends its own config on connect
- **Predators the mod spawned were never removed**, and a predator's `MaxCount` had no upper limit, so on a busy server wolves and bears piled up until restart. One spawn now brings at most 10, at most 30 are alive at once server-wide (further spawns are skipped until some die or despawn), and one still alive 15 minutes after spawning is removed once no player is within 150 m. Killed predators are left as ordinary corpses
- The Bamboo Fishing Net takes all seven crayfish. It allowed only the Signal and European crayfish, so adding another crayfish to the net's catch table set off the startup warning and dropped that catch at the player's feet
- Severum is carried two-handed; it was flagged as a "heavy" item that blocked crouching
- Clients no longer log a "GetHealth cannot be called on client" engine error whenever bait or a hook is used up
- `requiredAddons` now name the vanilla patch behind every parent class the mod inherits from, and the nonexistent `DZ_Vehicles` is now `DZ_Vehicles_Water`
- RPCs are now registered on dedicated servers too; the registration point used before never runs there
- Bamboo net: a catch that can't go into the net is logged, the server warns at startup about net catches that aren't on the net's allow-list, and a net action without a valid water type is refused before it plays
- Tackle boxes accept the vanilla Wooden Hook, and coolers insulate their contents while carried or stored
- Gebsfish warnings and errors also go to the server RPT
- Generated types.xml gives fish entries vanilla's `-1` quantities; fish.json duplicate detection ignores letter case; removed config keys nothing reads (`hookType` on the lures, `quantityBarColor`, `destroyOnEmpty`)
- **Fish catches and modded-fish filleting were both broken.** Vanilla's `YieldItemBase` and `RecipeBase` constructors call `Init()` themselves, so `Init()` ran before the per-species row could be handed over and bailed on its null guard — and registration never runs it again. Every fish yield registered with an empty type and zero environment/method masks, and since the yield bank keys on the type hash, all 79 species collapsed onto one empty entry matching nothing: junk was the only possible catch. The data-driven fillet recipes likewise registered with no ingredients and no results, so no modded fish offered a Gut action (the four vanilla fish kept working through their own `Prepare*` overrides). Setup now applies from the setter instead of relying on constructor-time `Init()`
- Clients registered zero fillet recipes: the config left the Species table null on clients until the `ConfigSync` RPC, which lands after `PluginRecipesManager` has already registered. Clients now seed the compiled defaults in memory, and the RPC still overwrites them with the server's file
- Jon boat deck attachments were invisible — the model carried the proxies and the config declared the slots, but nothing tied the two together. Added the `ProxyAttachment` entries that bind each proxy to its slot. They must live in `CfgNonAIVehicles`; in `cfgVehicles` the base class resolves to a new empty one and the malformed entries break the boat's crew config, locking players out of both seats
- Wooden Fish Mount placement hologram rendered as the normal textured plaque instead of the white ghost: `placing` was listed in `hiddenSelections[]` but never declared as a section in `Model.cfg`, so the hologram material had no swappable selection to land on. The deployable/undeployable materials also needed vanilla's `Super` shader and full stage chain — flat `Normal`/`Basic` with no stages loses the fresnel sheen that makes a hologram read as one
- Wooden Fish Mount couldn't be placed on walls despite the wall-snapping logic working: `EvaluateCollision` rejected it through `IsBaseViable`, `IsClippingRoof` and `HeightPlacementCheck`, all of which assume ground placement, and `yawPitchRollLimit` capped pitch at 89 degrees — one short of flat against a vertical wall. Player collision, permitted-area, underwater and in-terrain checks still apply
- Jon boat no longer plays the vanilla rubber boat's engine shutdown sound when the engine cuts, including when stepping out of the driver seat. `BoatScript` hardcodes Boat_01 soundsets for every boat, so the jon boat now has its own script class that suppresses it
- XML generator crash at startup: `FPrint` without newlines produced a single-line 85 KB file that overflowed the engine's line-read buffer as fish were added — generators now emit proper line breaks
- Bait preferences and the temperature curve now apply independently of `WeatherCatchBoostEnable` — previously the weighted catch pick only ran when the weather toggle was on, silently disabling both systems despite their own toggles
- BiteSpeed aggregate no longer applies `CatchProbability` twice (the probability pool already repeats each fish by its weight) — abundant fish were quadratically dominating the bite-cycle timing over rare ones
- Rods no longer take double durability damage per catch outcome — a leftover duplicate `AddHealth` call made rods wear at 2x the intended 1.5 HP
- Hardened edge-case null handling: junk-yield registration now logs and skips (instead of crashing at mission init) when the config failed to load; cooler tick, hook-crafting check, rod-repair plugin lookups, and the debug yield dump all guard references that could be null in broken states
- Dug bugs now spawn as networked objects (were server-local and invisible to players); dig-bugs also wears the tool on every completed dig, matching dig-worms, and trains soft skills
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
- The brown, cutthroat, lake and rainbow trout, slimy sculpin, great white and hammerhead sharks, king crab (and its legs) and all seven crayfish used vanilla's carp shine map, which is laid out for the carp's model, so their gloss fell in random patches. Each now has its own: the four trouts' had been made but were never used, the others are new.
- Materials with empty shader stages: the Spoon Lures, Squarebill Lure and Curly Tail Jigs had no shine map stage, the Bamboo Fishing Net and Wooden Fish Mount no ambient-shadow stage, the jon boat neither. They now have vanilla's standard procedural ones (the spoons shine like polished metal, the Squarebill like glossy plastic, the jigs softer)
- Normal maps: the great white shark, king and snow crab, blue tang, slimy sculpin, blood clam and both lobster claws had theirs in vanilla's swizzled layout (the sideways part in the alpha channel). The game reads that, but model viewers showed one half of the model lit and the other dark with a seam down the middle. Thirteen others (alligator gar, Asian sea bass, brook trout, European crayfish, sauger, spotted, striped and white bass, walleye, medium tackle box, spinner, bamboo net and fish knife) had black round their UV islands, which bleeds into the edges at a distance as lines along the seams. All are re-saved in one plain layout with padded edges; the relief itself is unchanged
- Snow Crab and Snow Crab Legs material: its shine map sat in the detail-map slot and the shader's other stages were missing; it now has the standard layout, so the shell's normal and shine maps are read as intended

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
- Added bone min/max for crustaceans
- Added new worm and grub textures
- New licence for the mod
- Crayfish, Mussels, and Bloodclams are now food that can be eaten raw or cooked
- Changed sizing on crayfish to fit the model better
- Config update to change min/max to integers instead of floats
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
- Grub Worm and Rubber Worm show as regular worm when on hook

## v3.2.1

### Hotfix 1
- RPC bug fix (thanks DannyDoomNo1 for direction)
- Fixed misspelling of AtlanticSailfish meat

## v3.2.0

### Added or Changed
- Updated config to reflect classname changes in last update that we overlooked
- Revamped the junk config to add probability to it to change each junk items rarity
- Added predator messages to stringtable for proper localization
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
- Overall code improvements
