# FUTURE_IDEAS — things the mod could add or reuse

Ideas from the 2026-10-01 review against the decompiled vanilla game (build
125372: scripts, debinarized configs, CE XML, engine natives). None of these are
bugs — bugs and suspected bugs live in `MAYBE_ISSUES.md`. Each idea names the
vanilla/engine piece it would build on. Delete an entry when it ships or is
rejected.

**Animations: only what is already in the game.** No idea may need a custom
animation. Every player action uses a vanilla `CMD_ACTIONMOD_*` /
`CMD_ACTIONFB_*` command (as spear fishing uses `CMD_ACTIONFB_DIGMANIPULATE`),
and each idea that adds an action names the one it would use. The 2026-10-02 review added the bigger feature ideas at the end
(F1–F25).

---

## Fishing realism

Anything new that feeds the catch math (snow, tide, depth, sunrise...) must go
into `GebFishingSnapshot`, not be read live: the context runs on client and
server in lockstep and both must see the same value.

### Water temperature: what's left
- **Altitude.** Mountain lakes could run colder:
  `m_TemperaturePerHeightReductionModifier` x the cast point's height, as
  vanilla does for air. The cast point would need to be part of the snapshot.
- **Custom maps** without their own water temperatures get Chernarus's. A table
  of known custom-map values (Namalsk, Deer Isle...) in `gebsfish.c` would save
  admins the `WaterTempOffset` tuning.

### Seasonal dawn and dusk
- `WorldData.GetApproxSunriseTime(month + day / 32.0)` /
  `GetApproxSunsetTime(...)` give per-map, per-season sunrise and sunset; the
  Dawn/Day/Dusk/Night windows could follow them instead of fixed hours.
  Deterministic, so safe for client/server lockstep. (Vanilla's own
  `GetDaytime()` only resolves whole months, and its enum order is
  NIGHT/DAY/DUSK/DAWN — not the mod's.)

### Moon
- `World.GetMoonIntensity()` returns the lit fraction the sky actually shows.
  The Meeus calculation is fine to keep: it only uses the synced date, so it is
  guaranteed identical on both sides. Switch only if matching the visible sky
  matters more than that guarantee.

### Tide and depth
- `SurfaceGetSeaLevel()` vs `SurfaceGetSeaLevelMin/Max()` could give a
  "tide is turning" bite bonus at sea; `GetWaterDepth()` at the cast point could
  separate deep-water from shallow-water species. Check the tide clock is the
  same on client and server before using it in shared catch math.

## Catch and tackle tuning

### Per-item tuning through `class Fishing`
- Vanilla reads per-item fishing modifiers from config (`InitItemValues`):
  `hookLossChanceMod`, `baitLossChanceMod`, `signalCycleTargetAdjustment`,
  `signalCycleTargetEndAdjustment`, `signalDurationMin/Max`,
  `resultQuantityBaseMod`, `resultQuantityDispersionMin/Max`.
- Today every geb lure inherits Jig's numbers and every geb bait inherits
  Worm's, so they only differ through the preference matrix. Giving lures/baits
  their own blocks would make tackle choice matter mechanically. A non-zero
  `baitLossChanceMod` would also make "bait can come off on a miss" real.

### Unused per-species hooks on the yield class
- `GetQualityForYieldItem` — per-species catch size (how full the fish comes
  out).
- `GetCatchParticleID` / `GetCatchDeathSoundset` — a bigger splash or sound for
  big fish.
- `GetCycleTimeForYieldItem` — per-species bite curves. Vanilla gives
  WalleyePollock, SteelheadTrout and Shrimp their own hourly curves
  (`yieldsfish.c`); the mod's generic yields reset them to the default.
- `OnEntityYieldSpawned` — any per-species setup after the catch spawns.

### Bait crafting
- Vanilla's `CraftBait` / `CraftBoneBait` recipes are commented out
  (`pluginrecipesmanagerbase.c`), so there's room for the mod's own bait
  recipes (cut bait from fish scraps, etc.).

## Items and visuals

- **Carry behaviour:** set `itemBehaviour` 1/2 on the fish to match the
  one-/two-handed lists in `geb_dayzplayercfgbase.c`.

## Server and admin quality of life

- **Smaller ConfigSync.** About 70 KB goes to every joining player, nearly half
  of it Info prose the client never reads (≈16 KB once per section, ≈15 KB
  repeated in every array entry); the fish table and bait matrix are ~33 KB.
  Send clients a slim object (Fish, Bait, the toggles they use), or move
  per-entry Info to the parent.
- Shipped 2026-10-02: a map whose WorldData clears the yield bank no longer
  wipes the mod's fish. Once the mission has built its world data,
  `MissionBase.GebRepairYieldBank` rebuilds the bank with the mod's yields
  first. (Re-registering inside `ClearAllRegisteredItems` wouldn't have held:
  the map registers its own list after the clear, over the mod's.)
- Shipped 2026-10-02: predators spawn through `SpawnEntityOnGroundPos` at the
  walkable surface (`SurfaceRoadY`), so they land on bridges and rocks.
- **Client log folder.** The client's routine lines (config sync, yield
  registration) log only with DebugLogs on since 2026-10-08, so a player's PC
  writes `$profile:Gebs/logs` only for a warning or an error. What's left: the
  logger itself still makes that folder on any machine the first time it
  writes; a client-only switch could send even those lines to the RPT alone.
- **XML generators.** Regenerate when the content changes, not only on a
  version bump, so custom fish.json species get types entries; containers
  could get their own category as the clothes did (2026-10-05).
- **Config backups.** A `.bak` via `CopyFile` before each config overwrite
  (there's no rename native, and the writer truncates first).
- **Server-side net and spear checks.** The net trusts the client's water
  type, and the spear its water type and depth (its water-surface check does
  run on the server); re-check them from the cursor position on the server
  (`CCTWaterSurfaceEx`, as vanilla fishing does). Dig-bugs and the net could
  also use vanilla dig-worms' free-space and on-ground checks.

## Code health

- **Config sections.** Pre-allocate nested sections the vanilla way
  (`cfggameplaydatajson.c`: `ref X Section = new X;`). The loader fills an
  object that already exists in place, so a field deleted from a section would
  keep its default instead of loading as 0 (settled from the engine
  2026-10-09, MAYBE_ISSUES #26). Lists still need GebJsonKeys' key checks: the
  loader empties a list before reading it, and builds list rows without their
  defaults. Check the clients first: before the server's config arrives they
  hold `new GeneralConfig()`, so pre-allocated sections there would stop being
  null.
- **Very rare chances elsewhere.** Engine `rand()` is 15-bit; anything that must
  go below 1 in 32,768 needs the two-draw roll the treasure spawner now uses.

## Bigger features (2026-10-02 review)

Feature ideas from the second review. Sizes: S = a day or two, M = about a week,
L = more. "Art" says what models or textures it needs. One fact several ideas
lean on: the cast point is already identical on client and server (vanilla
`ActionBase.WriteToContext` sends `m_Target.GetCursorHitPos()` and the server
re-checks the water target), so a position-based rule only needs a local copy
of the point in `GebFishingSnapshot`; nothing new goes over the network.

**Top picks:** catch measurements (F1) first, since it is the base for
trophies, derbies, the journal and legends; then named waters (F2), message in
a bottle (F3), legendary fish (F4) and derbies (F5). **Quick wins:** mercury
(F6), brag feed (F7), quick re-bait (F8), live config reload (F9).

### F1. Catch measurements and certificates (M, no art)
- Every fish comes up with its own size ("Walleye, 63 cm, 2.41 kg") shown in
  its name and tooltip, plus who caught it, when and where. A trophy mount
  keeps all of it. A Release action records the fish and lets it go (vanilla
  drop-from-hands animation, `CMD_ACTIONMOD_DROPITEM_HANDS`).
- Per-species `LengthMinCm`, `LengthMaxCm`, `WeightMaxKg`. Roll the size on the
  server in the existing `TrySpawnCatch` override, skewed so giants are rare;
  weight scales with length cubed. Sync with `RegisterNetSyncVariableFloat`,
  show through `NameOverride` / `DescriptionOverride` (vanilla's map item uses
  the same hooks). Keep size separate from quantity so traders still pay full.
- Persistence: fish saved by 3.3 must still load, so store fish data through
  CF's ModStorage. The mount shipped in 3.3.2 (as the Wooden Fish Mount, now
  the small plaque, same class), so mounts with trophies are already in
  storage: any field added to its `OnStoreSave` needs a storage-version guard
  as well (the `version` argument of `OnStoreLoad`, or ModStorage).

### F2. Named waters (M, no art)
- Admin-defined zones (centre, radius, name) with per-species multipliers or
  allow-lists: a pike lake, a trout river, a reef. A zone can also be
  NoFishing (safe zones, PvE lakes). Phase 2: each water has a fish stock that
  drops with heavy fishing and refills over real hours (also an anti-AFK "this
  spot is fished out" rule).
- `Waters[]` in fish.json; store the centre as a static `float Pos[3]` the way
  vanilla's `ITEM_SpawnerObject.pos` does — never a dynamic `array<float>`
  inside an array element (the BiteSpeed crash). Apply the zone factor next to
  the bait factor in `PickWeightedYieldIndex` and `ComputeAggregateBiteSpeed`;
  zones reach clients with ConfigSync. Traps and the net can use the same
  lookup for free (server-only). Stock is server state: send it to nearby
  clients and carry it in the snapshot with a tolerance, like Rain.

### F3. Message in a bottle (M, no art)
- A rare junk catch is a water-stained chart; opening it shows the map with an
  X; dig there with a shovel to find a buried crate.
- `geb_TreasureChart extends ChernarusMap` (vanilla `ItemMap`; one item works
  on every map). On the catch the server calls `InsertMarker` +
  `SyncMapMarkers()`; markers persist in the map item's own save data. Pick a
  land point 0.3–1.5 km away where `IsSurfaceDigable(SurfaceGetType(...))`;
  create a vanilla `UndergroundStash` (`PlaceOnGround()`), put a container in
  it, fill it with the treasure loot code, `SetLifetime` a few days. Players
  dig it up with vanilla `ActionDigOutStash`. All server-side.

### F4. Legendary fish (M, art: retextures)
- A handful of named fish, one of each per server ("Old Ironjaw", a giant pike
  in one lake that only takes live minnow at night). Landing one is announced
  server-wide; it comes back after N days.
- `Legends[]` config (base species, legend class, water, time window, bait,
  chance, respawn days) + a `legends.json` state file. After `TrySpawnCatch`,
  if the conditions match, roll with the treasure spawner's 30-bit
  `RollPrecise01`; on a hit swap the fish for the legend class (`CreateObjectEx`,
  `TransferItemProperties`, delete the original), give it maximum size,
  announce, write an ADM line, record it in the journal. Each legend is a
  config child with a new texture on the existing `Camo` selection. After the
  catch and server-only, so it never touches the shared catch math. Builds on
  F1 and F2.

### F5. Fishing derbies (M, or L with a custom UI; no art)
- Scheduled tournaments ("Saturday 20:00 UTC, 60 minutes, heaviest bass"),
  live standings as on-screen messages, prizes for the top three, results
  posted afterwards, and an admin-placed board with all-time records.
- Schedule with `GetYearMonthDayUTC` / `GetHourMinuteSecondUTC`, score from F1's
  measurements in the catch hook, broadcast with `NotificationSystem`. Prizes
  reuse `GebsTreasureSpawner.FillContainer`; results to
  `$profile:Gebs/derbies/`. The board is a config object placed with vanilla
  `ObjectSpawnerHandler` (`objectSpawnersArr` in cfggameplay.json), text via
  `DescriptionOverride` + an RPC. All server-side.

### F6. Mercury in apex predators (S, no art)
- Shark, marlin, tuna, pike and musky meat carries heavy metals; eat too much
  and vanilla heavy-metal poisoning sets in; panfish are safe; chelating
  tablets cure it.
- Per-species `HeavyMetal` value; `InsertAgent(eAgents.HEAVYMETAL, n)` on the
  caught fish on the server. Vanilla does the rest: `PrepareAnimal.Do` →
  `TransferItemProperties` copies agents to the fillets,
  `Edible_Base.HandleFoodStageChangeAgents` keeps HEAVYMETAL through cooking,
  and `MDF_HEAVYMETAL1-3` + `ChelatingTablets` already exist (Sakhal's
  polluted water uses the same agent). About 30 lines.

### F7. Brag feed (S, no art)
- A server-wide message for legends, treasures, records and rare species
  ("Kopec landed a 214 kg Great White at 128 042").
- Thresholds in config; `SendNotificationToPlayerIdentityExtended(null, …)`
  (null identity = every player) from the catch hook. Location from
  `MapNavigationBehaviour.OrderedPositionNumbersFromGridCoords`, or the
  nearest `CfgWorlds <world> Names` entry (e.g. `Settlement_Berezino`).

### F8. Quick re-bait and rig readout (S, no art)
- With the rod in hand, one action puts the next bait from your worm tin, bug
  catcher or bucket on the hook. The rod's name shows what's rigged ("Fishing
  Rod, Spoon Lure, Worm"); the tooltip shows hook wear and bait freshness.
- `ActionSingleUseBase` on `FishingRod_Base_New`: find a compatible bait (bait
  containers first), `PredictiveTakeEntityToTargetAttachment(hook, bait)` into
  the hook's `Bait` slot, with vanilla's attach animation
  (`CMD_ACTIONMOD_ATTACHITEM`). `NameOverride` / `DescriptionOverride` on the
  rod read the hook and bait (their health level is already synced).

### F9. Live config reload (M, no art)
- Edit fish.json, drop a trigger file (or an admin-only RPC), and every player
  gets the new tuning without a restart.
- Poll `$profile:Gebs/reload` on the server, or a CF RPC limited to listed
  Steam IDs. Load all four files into a NEW config object and swap it in only
  if all four load. Re-run `InitWorldYieldDataDefaults` on `g_GebYieldBank`
  (its duplicate guard is keyed on the config object, and
  `GebBeginRegistration` already rebuilds the mod's block), then ConfigSync to
  everyone (null identity). Clients already rebuild their yields on ConfigSync,
  and fillets use the single `GebPrepareFishData` recipe that reads live config.
  Caveat: a cast in progress during the swap can mismatch once.

### F10. Seasonal runs and weather fronts (runs S, fronts M; no art)
- Species get date windows (a salmon run in Sep–Oct at ×3) announced when they
  open; fish feed hard just before a front and go quiet after it.
- Runs: `RunStartDay`, `RunEndDay`, `RunMultiplier` on FishConf, checked against
  the snapshot's Month/Day (same answer on both sides, no network change).
  Announce with `SendNotificationToPlayerIdentityExtended(null, …)`.
- Fronts: add overcast actual + forecast to `GebFishingSnapshot` (Write/Read and
  a tolerance in `IsCloseTo`). "Front coming" can use vanilla's own test
  `GetOvercast().GetForecast() - GetActual() >= 0.4` (`WeatherOnBeforeChange` in
  chernarusplus.c / enoch.c) — the moment vanilla raises the wind to 14–17 m/s,
  so players can feel it coming.

### F11. Hotspots: fish rising (L, no art)
- A few patches of water "boil" with rising fish for 20–40 minutes, visible and
  audible from shore; casting into one shortens the wait and favours a
  schooling species; then it moves.
- Server picks points where `SurfaceIsSea`/`SurfaceIsPond` and `GetWaterDepth`
  > 1 m (optionally inside named waters), rotates them on a timer, sends the
  list by CF RPC (also to joining players). Cues:
  `SEffectManager.CreateParticleServer` with `ParticleList.IMPACT_WATER_SMALL_ENTER`
  + vanilla `Fish_splash_random_SoundSet`. Sync: the client writes `HotspotId`
  into the snapshot; the server keeps it only if that hotspot exists and the
  cast point is inside its radius, else uses its own reading (same pattern as
  time and rain).

### F12. Chum (M, art: retexture only)
- Mix guts and fish meat into a chum bucket and throw it: for ~10 minutes the
  slick draws sharks and big pelagics at sea, or pike and musky in lakes; the
  smell also raises the chance of wolves or bears on land.
- Vanilla `Guts` (from skinning) + fish meat → `geb_ChumBucket` (Bait Bucket
  model, new texture). A pour-out action on `CCTWaterSurfaceEx` (vanilla's
  empty-a-bottle animation, `CMD_ACTIONMOD_EMPTY_VESSEL`) registers a
  short-lived player-made hotspot with a predator bias, reusing F11's sync and
  snapshot code and staying under `MaxStackedMultiplier`. Land predators via
  `GebsPredatorSpawner.TrySpawn(player, ChumPredatorChance, …)`.

### F13. Tackle classes: reel, line, landing net (M, art: small models)
- Rods take a reel and a line. Light line snaps on sharks, marlin and sturgeon;
  heavy line puts off panfish. A landing net in your pack saves big fish at the
  bank. Stronger rods cast farther, which matters once 1.30 cuts casting range
  to 20 m.
- New rod slots with their own names (not the cross-mod `fishingrod1-10`). The
  items carry vanilla `class Fishing` blocks — no context code needed for their
  stats: vanilla `CatchingContextBase.InitCatchingItemData` already walks every
  rod attachment (`EnumerateInventory(PREORDER)`) and adds up
  `hookLossChanceMod`, `signalDuration*`, `signalCycleTarget*`. Give items a
  `TackleRating` and species a `MinTackle`; use the gap in the pick weight or
  the hook-loss chance. Per-rod cast distance in `ActionCondition` (inventory
  is synced, so both sides agree).

### F14. Ice fishing on Sakhal (L, art: ice-hole model or decal)
- Cut a hole in a frozen lake or sea ice with an ice axe or pickaxe and fish
  through it; the hole refreezes after a while; cold-water species dominate.
- A new action on vanilla `Iceaxe` / `Pickaxe` when `SurfaceGetType` returns
  `sakhal_ice_lake` / `sakhal_ice_sea` (not liquid in
  `DZ\surfaces_sakhal\config.cpp`, so vanilla fishing never targets them)
  spawns a short-lived `geb_IceHole`, with vanilla's mining animation
  (`CMD_ACTIONFB_MINEROCK`). `ActionFishingIceHole extends
  ActionFishingNew` with a `CCTObject` target, deciding sea or lake from the
  surface name; the context, snapshot, splash and predator/treasure hooks carry
  over. Optional tip-up = a trap placed on the hole.

### F16. Crab pots and trotlines (M, art: retexture fishnettrap.p3d or new pot)
- Bait a pot with guts, drop it at sea, come back for lobsters and crabs. A
  trotline on a river takes catfish and bowfin overnight.
- `geb_CrabPot extends Trap_FishNet`; its `InitCatchingComponent` builds a
  `CatchingContextTrapsBase` subclass whose `InitCatchMethodMask` returns
  `1<<4` (vanilla uses bits 0–3). Add 16 to the crustaceans' `CatchMethod`;
  meat bait through `Trapping { baitTypes[] }` (`BAIT_TYPE_MEAT_SMALL/LARGE`).
  Server-only. Trotline: same class with bit `1<<5`. Gives the 17
  bait-category-less shellfish (MAYBE #3) their own loop; pairs with the jon
  boat.

### F17. Jon boat trolling kit (L, art: rod-holder proxies, live-well model)
- Two rods in stern holders, troll slowly; a strike sounds a clicker and the
  fish goes into a live well that keeps it fresh.
- Two boat slots + `ProxyAttachment` entries in `CfgNonAIVehicles` (same as the
  deck slots). A server timer on `geb_jonboat_base` checks `EngineIsOn()` and a
  trolling speed band (`GetVelocity(this)`); each held rod with a lure rolls a
  trap-style context (a "troll" method bit, environment from the boat's
  position). Catches go into a live-well deck container (add it to the parent
  walk in `Edible_Base.ProcessDecay`). Strike sound: vanilla
  `Fish_bite_splash_SoundSet` via the predator-warning RPC pattern. Delivers
  the "more boat content" the changelog promises.

### F18. Angler's Journal and Field Guide (M, art: book covers)
- A journal that survives death: species caught, counts, personal bests,
  firsts, releases; milestones award the mod's hats, shirts and knives. A fixed
  Field Guide teaches each species' best bait, water temperature and hours.
- Per-player server JSON keyed by `identity.GetPlainId()` under
  `$profile:Gebs/anglers/`, updated from the catch hook; "New species!" via
  `NotificationSystem`. UI: vanilla's dormant book reader (`ItemBook`,
  `BookMenu`, `MENU_BOOK`, `day_z_book.layout`; its `HtmlWidget` is a
  `RichTextWidget`, so text sent by CF RPC can be set at runtime). The Field
  Guide can be pure config (`title`, `author`, an html `file`) generated from
  the wiki data by the `tools\` scripts. Vanilla books no longer spawn, so add
  a small Read action (vanilla `CMD_ACTIONFB_VIEWNOTE`). (Death-resetting alternative: `Man.StatRegister` /
  `StatUpdate`, names ≤ 31 chars, ≤ 455 stats, saved like playtime.)

### F19. Fishmonger contracts (M, no art)
- A market stall in a trader or safe zone posts daily orders ("3 walleye", "a
  pike over 5 kg", "black caviar") and pays rewards; works without a trader mod.
- A config object on a vanilla crate model placed by `ObjectSpawnerHandler`
  (`ITEM_SpawnerObject.customString`, passed to `OnSpawnByObjectSpawner`, says
  which board it is). Interact action with the fish in hands (vanilla
  `CMD_ACTIONMOD_INTERACTONCE`): the server checks
  species (and F1 size), deletes the fish, spawns the reward classnames
  (vanilla items or a trader mod's money). Orders rotate daily from the real
  date; state in JSON.

### F20. Fish oil and byproducts (M, art: retextures)
- Boil fatty fillets and skim off fish oil: it fuels torches, and a spoonful
  gives vitamin-style immunity. Big fish leave scraps for garden fertilizer, and
  bones for hooks.
- `geb_FishOil extends Lard`, so vanilla `UpgradeTorchWithLard` accepts it
  (recipes match on inheritance; vanilla's frying check compares the exact
  `Lard` type, so frying needs a patch). `OnConsume` → `MDF_IMMUNITYBOOST` like
  `VitaminBottle`. Recipe: a boiled (`IsFoodBoiled`) fatty fillet + a Pot as a
  tool. Scraps: an extra result in `PrepareFish.SpawnItems` with a
  `Horticulture` block and `ActionFertilizeSlot` (the `GardenLime` /
  `PlantMaterial` pattern). Bones: vanilla `Bone`, which already feeds
  `CraftBoneHook`.

### F21. Stockfish drying rack (M, art: rack model)
- Hang fillets on a rack to air-dry without fire; cold, dry, windy weather
  dries fastest (Sakhal is ideal), rain or snow stalls it; dried fish keeps a
  long time.
- A placeable rack whose slots are added to the fillets' `inventorySlot[]`
  (vanilla does this for the fireplace smoking slots `SmokingA–D`). A server
  timer advances `SetCookingTime` while `GetRain()` and `GetSnowfall()` are low,
  scaled by `GetWindSpeed()`; at the DRIED cook time call
  `ChangeFoodStage(FoodStageType.DRIED)` like `Cooking.SmokeItem`. Pause decay
  on the rack through the existing `ProcessDecay` hook.

### F22. Shoreline and after-rain foraging (S, no art)
- Dig clams and mussels at the waterline on beaches; nightcrawlers are easier
  to find after rain and at night.
- Clone `ActionDigBugs` with a `DigClamsSettings` table (`geb_BloodClam`,
  `geb_Mussel`, `geb_StarFish`, crabs), allowed only on beach surfaces
  (`sakhal_beach`; Chernarus beaches are `cp_gravel`) with sea a few metres
  seaward (`SurfaceIsSea`). For worms, multiply the dig-worms `FindChance` after
  recent rain or at night. Server-only.

### F23. Angler's instruments (thermometer S, sonar M; art: optional sonar)
- Dip the vanilla Thermometer in water to read the temperature the fish feel;
  a barometer reading warns of a front (F10); a battery fish finder (handheld or
  on the boat deck) shows depth, temperature, bite activity and the three
  likeliest species for your bait.
- Dipping uses vanilla's fill-bottle-at-a-pond animation
  (`CMD_ACTIONFB_FILLBOTTLEPOND`). Display only, client-side, via
  `NotificationSystem.AddNotificationExtended`.
  Power via `ComponentEnergyManager` with a 9V battery (like `GPSReceiver`);
  depth from `GetWaterDepth`. Move `GetCurrentWaterTemp`,
  `GetSpeciesWeatherMultiplier` and the BiteSpeed aggregate into a shared static
  helper so the readout matches the cast exactly. The gadget never feeds a cast,
  so it can't cause a client/server mismatch.

### F25. Catch telemetry and ADM log lines (S, no art)
- A CSV line per catch (time, player id, species, size, bait, water, weather,
  position), a summary at restart (top species, junk %, treasures, predators),
  and ADM log lines for notable events so CFTools, BattleMetrics or Discord
  bots can react.
- Same open/write/close pattern as `GebsfishLogger`, one file per day under the
  existing log retention; ADM lines via `g_Game.AdminLog()` or
  `PluginAdminLog.DirectAdminLogPrint`.

## Ideas from the 2026-10-04 review (F26–F43)

### F26. Blast fishing (S, no art; off by default)
Hook vanilla ExplosivesBase / Grenade_Base OnExplode on the server. When the
blast is in water (SurfaceIsPond/SurfaceIsSea, GetWaterDepth > 0.5), spawn 1-4
stunned, damaged fish of the local pool at the surface. It uses the vanilla
throw, so no new animation.

### F27. Night light fishing (S, no art)
A lit vanilla PortableGasLamp, Roadflare, Chemlight or Torch within about 3 m
adds a night bite bonus. Carry a LightNearby flag in GebFishingSnapshot, and
have the server confirm it with GetObjectsAtPosition before trusting the
client's value, the same pattern as Rain. No new action.

### F30. Shark and sturgeon skin (M, art: retexture)
A geb_FishSkin : Pelt_Base as an extra fillet result for the big species.
Vanilla CraftTannedLeather (Pelt_Base + GardenLime, vanilla crafting animation)
already takes any Pelt_Base, so it tans into vanilla TannedLeather.

### F31. Startup classname report for all four files (S, no art)
Check every classname in general, bait, junk and fish.json with
CGame.ConfigIsExisting and IsKindOf (Inventory_Base for items, DayZCreature for
predators): BaitClassname, FishClassname, treasure, hook, predator, net, spear
and dig. Write one summary block to the Gebs log and the RPT, so typos and
renamed classes (geb_Bonita) show at boot instead of at the first spawn. Today
only fish.json is validated.

### F32. Shared loot presets (S, no art)
Have the generator write gebsLures, gebsKnives and gebsLiveBait presets for
vanilla cfgrandompresets.xml and use them itself in cfgspawnabletypes
(`<cargo preset="...">`). Admins could then give any vanilla container a lure
chance with one line. Keeping each list in one place prevents omissions like
A1.

### F34. A second chance at the config sync (S, no art)
If g_GebConfigReceived is still false a few seconds after
MissionGameplay.OnMissionStart, the client asks once by CF RPC. The server
could also resend from vanilla OnClientReadyEvent. Today a lost sync leaves that
client unable to fish for the whole session, with no message.

### F35. Cook small panfish whole (S, no art)
Vanilla Bitterlings and Sardines cook whole (CanBeCookedOnStick and
CanBeCooked, AnimalCorpsesStageTransitions, baked/boiled/dried/burned looks).
Let the bluegill, sunfish, perch, sculpin and white grunt do the same through
their existing Camo material swap. It uses vanilla ActionCookOnStick, a pot or
a pan.

### F36. Rod rack (M, art: one model)
A placeable rack with 4-6 rod slots, built like the fish mount (CfgSlots plus
Proxy attachments) and placed with vanilla ActionDeployObject. Naming its slots
fishingrod1-N would give the cross-mod rod slots every rod already carries
(Watch #4) a use inside the mod.

### F37. A jerry can on the jon boat (S, no art)
Add Slot_GebBoatFuel with its proxy, and `inventorySlot[] += {"GebBoatFuel"}`
on vanilla CanisterGasoline (DZ_Vehicles_Parts in requiredAddons), so a spare
can rides on deck. Attaching is plain inventory, so no animation is needed.

### F39. Editor: class check and rename helper (S)
Flag classnames that aren't gebsfish or vanilla, and offer one-click renames
for known renames (geb_Bonita → geb_PacificBonito) that carry the admin's values
over.

### F40. Editor: add or clone a species (S)
Add a fish.json row for another mod's fish by copying an existing species, and
include custom species in the bait tab's "Add a fish" list, which today offers
only the 79 defaults.

### F41. Editor: "changed from default" view (S)
Highlight values that differ from the shipped defaults, with a reset per
field, and show a summary of changes before download.

### F42. Simulator: "best bait for X" (S)
Rank every bait for one species under the chosen conditions, with a 24-hour by
12-month heat map of that species' share.

### F43. Build checks: tools/check_pbo.py and generated odds (S)
check_pbo.py reads a built PBO's header and fails if it contains docs, tools,
.claude or Workbench files, or lacks a file config.cpp references (the .ogg
sounds, A4). Also run the editor's simulator in node at build time to fill in
the wiki's odds numbers, the way build_changelog_html.py rebuilds the
changelog, so hand-typed figures can't drift.

## Ideas from the 2026-10-05 review (F44–F65)

### F44. Simulator: paste a server log cast (S, no art)
Paste a DebugLogs=1 cast block from $profile:Gebs/logs and the "What will bite?"
tab fills in the map water, date, hour, rain or snow and the bait, then shows
the odds beside the species the log picked. Makes runtime case 28 a copy-paste
job. Builds on GebFishingSnapshot.Describe() and the water-temperature log line.

### F45. Editor: draft autosave (S, no art)
Unsaved edits survive a closed tab or a crash: on load the editor offers to
restore the edits you hadn't downloaded. localStorage, wrapped in try/catch.

### F46. Editor: economy-file helper (M, no art)
Drop in the mission's db/events.xml, types.xml and cfgeconomycore.xml with the
generated gebsfish files: the page reports missing or duplicate types (jon boats
not in types.xml), shows the <ce> block to add, and writes a merged types.xml.

### F47. tools/check_docs.py (S, no art)
One command that fails when the wiki or editor drifts from the code: the FISH
array vs the seeds, item-details.js vs the scope-2 classes, the render manifests
vs a fresh build, the changelog tab vs CHANGELOG.md, and counts quoted in prose
(species, bait pairings, colours).

### F48. Wiki: best baits and best hours per species (S, no art)
Each fish's panel in the Fish Database shows its top three baits, the one to
avoid, and its peak bite hours, generated from the seeded matrix and its
BiteSpeed curve by build_wiki_assets.py.

### F49. Wiki: "Upgrading to 3.3.3" checklist for admins (S, no art)
One page of what an existing server must do on this update: re-merge
gebsfish-types.xml, register gebsfish-events.xml, rename geb_Bonita rows, take
the Fun tackle boxes out of trader lists, set Sakhal's WaterTempOffset back to 0,
expect all four config files rewritten.

### F50. Economy self-check at startup (S, no art)
At boot the server reads $mission:cfgeconomycore.xml and the files it registers,
and warns in the Gebs log and RPT when gebsfish's XML isn't registered, is from
an older version, or names geb_ types that no longer exist (geb_Bonita, the Fun
boxes). Same line reader as eventsxml.c, ConfigIsExisting for each type.

### F51. Version handshake on ConfigSync (S, no art)
A player whose Gebsfish build doesn't match the server's gets a clear message
("restart DayZ so Steam updates the mod") instead of a rod that never casts. The
server sends the version as its own Param ahead of the config; the client checks
it before reading the config (a single Param2 would lose the version too).

### F52. Jon boat event settings in general.json (S, no art)
How many jon boats per colour, which colours, how much the VehicleBoat count
goes up, and an Enable switch, instead of hand-editing XML the mod rewrites at
every start. Feeds gebsfishEvents.GenerateEventsXML.

### F53. Show what changed in regenerated types.xml (S, no art)
A regenerated gebsfish-types.xml lists "Added since 3.3.2" and "Removed since
3.3.2: geb_FunGreenTackle, geb_Bonita, ..." in its header and the log, so admins
know which merged entries to delete. Same for the spawnabletypes file.

### F54. Per-map species switch (S, no art)
An optional Worlds field on each Species row ("" = every map, or e.g. "enoch
chernarusplus"), so one config serves a cluster of maps without zeroing species
everywhere. Checked in RegisterFishYieldData against the world name, which both
sides share (lockstep-safe).

### F55. Coolers need ice (S, no art; optional ice-pack retexture)
A cooler chills and stops rot only while its cargo holds something frozen (a
frozen bottle, a pot of snow on Sakhal), using up the cold as it goes. Cold
nights and Sakhal make ice; summer days make the cooler a choice. Admin toggle
CoolerNeedsIce keeps today's behaviour available. No new action.

### F56. The Bait Bucket needs its water (S, no art)
The bucket keeps bait alive only while it holds water (half full or more); the
water slowly evaporates on warm days and players top it up at a pond with
vanilla's fill action (CMD_ACTIONFB_FILLBOTTLEPOND). Needs B16's water mask.

### F57. Bait condition matters (S, no art)
A baked, boiled, dried or burned bait fishes like a fresh one today. Scale the
bait by its food stage: raw 1.0, rotten 0.6 (but 1.3 for catfish, bowfin and
other scavengers), cooked 0.3, burned 0. The food stage is synced, so reading it
at cast start keeps client and server in step.

### F58. A whetstone sharpens hooks and lures (S, config only)
Give Hook, BoneHook and the geb_Lure family repairableWithKits[] = {4} and a
repair cost: vanilla's SharpenMelee recipe (Whetstone) then repairs them up to
Worn with no script, using its crafting animation.

### F59. Fresher fish give more fillets (S, no art)
A pristine fish filleted early in its rot timer gives MeatMax, one close to
rotting or Badly Damaged gives MeatMin. Rewards icing the catch. Server-only.

### F60. Worm farm (S, no art)
A Worm Container with two live worms and some feed (plant material or rotten
fruit) breeds a worm every few in-game hours into its own cargo until full. A
renewable bait source and a use for rotten food. No new action.

### F61. A worn rod loses more hooks (S, no art)
A worn or damaged rod adds to the hook-loss chance on the strike (from its
health level, which clients see too), so the repair kit is worth carrying before
a rod is ruined.

### F62. Scheduled bite boosts (S, no art)
Admin-scheduled "fishing weekend" windows (UTC start and end, a bite multiplier,
an optional junk-share override), announced when they open. The window goes in
GebFishingSnapshot and stays under MaxStackedMultiplier.

### F63. Boil whole lobsters and crabs (S, art: recoloured shells)
A whole lobster, king crab or snow crab cooks red in a pot, to eat or still
butcher, using vanilla Shrimp's food stages as the crayfish do. Needs cooked,
dried and burned recolours of the shells.

### F65. Cooked fillets that look like their fish (M, art: 4 groups x 4 textures)
Every fillet cooks with vanilla's carp, mackerel, walleye or steelhead look
today. Group the species (white fish, trout and salmon, tuna and billfish,
shark) and give each group its own baked, boiled, dried and burned textures on
the same fillet models.

## Ideas from the 2026-10-05 review (F66–F90)

From the fifth full pass, each checked against F1–F65 (where one is close, the entry says what is new). Sizes: S = a day or two, M = about a week, L = more. Ranked by value for effort: F85, F78, F80, F76, F66, F81, F73, F67, F86, F82, F69, F83, F84, F68, F87, F72, F71, F77, F70, F88, F74, F75, F79, F89, F90.

**Fishing loop and the world around the water**

### F66. Snag what's on the bottom (S, art: none)
When a rod cast comes up junk, the server first looks for a real item lying
underwater near the cast point and drags that ashore instead: the pistol dropped
off the pier, the backpack of a player who drowned, cargo from a sunk boat. Vanilla
spawns every catch at the player's feet from `ActionFishingNew.TrySpawnCatch`
(actionfishingnew.c, then `CatchingResultBasic.SpawnAndSetup` in
catchingresultbasic.c), and the mod already overrides TrySpawnCatch: on a junk
result, run `GetObjectsAtPosition(m_Target.GetCursorHitPos(), SnagRadius, ...)`
(3_game/global/game.c; the 2D form, which geyserarea.c uses with y = 0, so items on a
deep bottom below the surface point are found), keep loose `ItemBase`s with no
hierarchy parent where `GetWaterDepth(pos) > 0`, and move the nearest one under
`SnagMaxWeightKg` to the
spawn point instead of creating the junk item. The pick itself is unchanged (both
sides still agree it was junk; only what the server hands over differs), so the
lockstep catch math is untouched, and there is no new action. Config:
`SnagSunkenItems`, `SnagRadius` (3 m), `SnagMaxWeightKg` in junk.json, plus a log/ADM
line naming the item and where it lay; open question: check that items lying in deep
water keep their position across restarts before advertising "a drowned player's gear".

### F67. Secret spots: your map remembers your catches (S, art: optional map icon)
A player carrying a vanilla map gets a pin with the species name at the cast point
when they land something notable, so a well-used map becomes a personal fishing
chart, and looting a dead angler's map gives his spots away. Server-side after the
catch: find an `ItemMap` in the player's inventory, `InsertMarker(castPoint, name,
colour, icon)` and `SyncMapMarkers()` (4_world/entities/core/inherited/inventoryitem.c);
the markers are saved in the map's own `OnStoreSave`, and vanilla
`MapMenu.LoadMapMarkers` (5_mission/gui/mapmenu.c) already draws them with their text.
Vanilla has no fish icon among `eMapMarkerTypes`, so reuse `MARKERTYPE_MAP_TSIGN` or
register one with `MapMarkerTypes.RegisterMarkerType` (5_mission/gui/mapmarkersinfo.c);
check whether a `#STR_` key in marker text gets translated, else store the display name.
Config: `MapMarkCatches` (0 off, 1 only species with CatchProbability at or below
`MapMarkMaxProbability`, 2 every catch), a per-map cap (oldest dropped) and one pin per
species per ~50 m. Not F3: F3 marks one treasure on a found chart; this turns the
player's own maps into a record of real catches.

### F68. Waterlogged notes (S, art: retexture of a vanilla leaflet)
A rare junk catch is a soggy note whose text the admin writes: server lore, a rumour
about a big pike in a named lake, an event teaser, the Discord invite. New
`geb_SoggyNote` (vanilla `MorseCodeLeaflet.p3d`, whose `camo1`/`camo2` selections take a
stained-paper texture; `Paper.p3d` has no hidden selections) in the junk table; junk.json
gets `Notes[]` (each under ~900 characters, the JsonLoader limit), the server picks one
in `YieldItemJunk.OnEntityYieldSpawned` and stores only its index (net-synced int,
saved), and the client shows the text through `DescriptionOverride` from its own
ConfigSync copy of junk.json (`InventoryItem.GetTooltip`, 3_game/entities/inventoryitem.c).
No new action needed: it reads as the tooltip; a full-page read could reuse vanilla's
deprecated-but-present `ActionReadPaper` + `MENU_NOTE` (`CMD_ACTIONFB_VIEWNOTE`), which
1.29's `Paper.SetActions` no longer registers. Config: the note's junk row plus
`Notes[]` (empty list = off); not F3 (a treasure chart) but a channel for the admin's
own words, which can point players at F3/F4/F5 content.

### F69. Spines, teeth and claws (S, art: none)
Taking a catfish, pike, gar, snakehead, sculpin, rockfish, crab or lobster off the hook
bare-handed can cut you, and a jellyfish stings; any intact gloves prevent it, which
finally gives the mod's knit-and-rubber fishing gloves a job (they stay bonus-free
otherwise). Server-side right after a catch spawns (rod, spear, net): if
`FindAttachmentBySlotName("Gloves")` is missing or ruined, roll the species' new
`HandlingRisk` and call `GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(
"LeftForeArmRoll" / "RightForeArmRoll")`, exactly vanilla's barbed-bat recipe
(4_world/classes/recipes/recipes/craftbaseballbatbarbed.c, a cut one time in ten without
gloves); a jellyfish deals a shock hit instead. No action or animation: it rides the
existing reel-in, after the shared catch math. Config: per-species `HandlingRisk` in
fish.json (seeded 0 for panfish, ~0.05 spined and toothed fish, ~0.15 crabs and
lobsters) and `HandlingInjuryEnable`; the cut then follows vanilla's wound rules
(closing it with a dirty rag can infect, bleedingsourcesmanagerserver.c).

### F70. Leeches (S, art: recolour of the vanilla worm)
Wading in fresh water (spear fishing, netting, fording a river) sometimes leaves a leech
on you: a little blood lost, and a live bait that walleye and catfish love. A server
tick checks players with `GetCurrentWaterLevel()` above knee height
(dayzplayerimplement.c; vanilla already reads it server-side for hot-spring burns in
playerbase.c `OnUpdateEffectAreaServer`) and `SurfaceIsPond` at the feet; trousers halve
the chance and rubber ones (vanilla NBC pants) stop it; on a hit, `geb_Leech` goes into
the inventory (or at the feet), some blood is removed and the player gets a message.
`geb_Leech extends Worm`, so the mod's modded `Worm` aging (~90 min), the Worm Container /
Bug Catcher allow-lists and the hook's Bait slot all work without new code; it needs one
bait.json row (walleye 2.2, catfish 1.8, bass 1.5) and can join the net and spear tables.
No action; config `LeechSettings` {Enable, ChancePerMinute, MinWaterLevel}; art: vanilla
`bait_worm.p3d` with a dark, spotted texture from a leech photograph.

### F71. Hot-spring fishing on Sakhal (S, art: none)
Sakhal's steaming hot-spring pools become the arctic map's one patch of warm water: cast
into one and the existing temperature system hands the pool to warm-water fish (redhead
cichlid, severum, Siamese tigerfish, snakehead) while the lakes around are near
freezing. The pools are an ordinary water surface (`sakhal_hotwater`,
DZ/surfaces_sakhal/config.cpp) whose liquid is `LIQUID_HOTWATER`
(3_game/constants.c), and the rod refuses them only because its target condition allows
`LIQUID_SALTWATER|LIQUID_FRESHWATER` (`CCTWaterSurfaceEx`, cctwatersurface.c,
actionfishingnew.c). Add hot water to that mask, detect it at the cursor hit point in
`ComposeLocalContextData` (the point is identical on both sides, so a local copy in
`GebFishingSnapshot` is enough), treat it as pond water and use `HotSpringWaterTemp`
(default 30 °C) instead of the map's lake temperature. Config: `HotSpringFishing`,
`HotSpringWaterTemp`, optional `HotSpringSpecies[]`; vanilla burns anyone standing in a
spring above 0.5 m water level (playerbase.c), so anglers fish from the edge. Open
questions: the pools are small (Sakhal's cfgeffectarea.json lists ~30 `HotSpringArea`s a
few metres apart), and 1.30 moves the rod's range check to a liquid condition (CCTLiquid),
so the mask change must follow it.

### F72. Toxic-zone catches (S, art: none)
Fish caught in a contaminated zone carry heavy metals into whoever eats them, and
Chernarus's Rify wreck is a static zone sitting in the sea (`Ship-Bow`, `Ship-Center`,
`Ship-Stern`, `Ship-East` in DZ/worlds/chernarusplus/ce/cfgeffectarea.json); dynamic gas
zones can land on any lake. Server-side after the catch: if the player is inside a
contaminated area (vanilla `PlayerBase.m_ContaminatedAreaCount`, raised by the
contaminated trigger, contaminatedarea.c) or the cast point is, call
`InsertAgent(eAgents.HEAVYMETAL, ToxicCatchDose)` on the fish. HEAVYMETAL is the right
agent because vanilla cooking strips every agent except it (`RemoveAllAgentsExcept(
eAgents.HEAVYMETAL)`, cooking.c), so a cooked Rify cod still poisons and chelating
tablets cure it; fillets inherit it through F6's agent chain. Not F6 (which is by
species, apex predators): this is by place and shares F6's helper; config
`ToxicCatchEnable`, `ToxicCatchDose`, optionally a higher F75 morph chance in toxic
water for a mutant flavour.

### F73. Species of the day (S, art: none)
Each in-game day one species is "on the bite": it gets a pick-weight bonus and every
player hears about it at login and when the day turns ("The walleye are biting today").
Pick it deterministically from the cast snapshot's Year/Month/Day (a hash into the
rod-catchable species whose temperature window fits this month's water on this map), so
client and server agree with no new snapshot field or network traffic, and apply it in
`PickWeightedYieldIndex` next to the bait factor, under `MaxStackedMultiplier`. The
client can compute and announce it locally with `NotificationSystem.AddNotificationExtended`
(3_game/client/notifications/notificationsystem.c). Not F10 or F62, which are
admin-scheduled: this is zero-configuration daily variety that also gives F7 and F19 a
theme. Config: `DailyFeatureEnable`, `DailyFeatureMultiplier` (1.5), optional
`DailyFeatureExclude[]`.

**Tackle and bait**

### F74. Lure colour matters (M, art: none)
The numbered lure variants (In-Line Spinner #1–#4, Spoon Lure #1–#4, Curly Tail Jig
#1–#4) differ only in colour and share one bait.json family row, so which one is tied on
never matters today. Give each variant a colour class read off its texture (spoons:
blue, red, white, yellow; curly tails: blue, green, purple, red; cranks: purple, yellow)
and a small bite-rate factor by light and water: bright colours win at dawn, dusk and in
rain-stained water, natural ones in clear daylight, dark ones at night, applied in
`ModifySignalProbability` beside the weather multiplier from the snapshot's hour and rain
(lockstep-safe, no new snapshot field). Rename the variants by colour ("Spoon Lure, Red"
rather than a number, stringtable in all 14 languages) so players can tell them apart. Config:
a `LureColours` block in bait.json (classname to class, class-by-window factors, default
about ±15 %, `Enable`), shown in the editor's simulator; it makes every colour in the
tackle box worth carrying without touching the species matrix.

### F75. Rare colour morphs (M, art: one recolour per morph)
About one catch in several hundred of a few species comes up as a real colour morph: a
golden (palomino) rainbow trout, a blue walleye, a silver-phase northern pike, a xanthic
largemouth bass; a collector's catch for the mounts and for traders. Each morph is a
config child of its species with its own texture on the existing `Camo` hidden
selection, swapped in server-side after `TrySpawnCatch` the way F4 plans for legends
(create, `TransferItemProperties`, delete the original), rolled with the treasure
spawner's 30-bit `RollPrecise01`, nominal 0 in types.xml (no new world loot). Every
lookup keyed on the exact class needs a fall-back to the parent: the fish.json row in
`PrepareFish.GebResolveRecipe`, `GebMountPoses` (which since 2026-10-05 falls back to a
listed parent class), the bait matrix and the wiki builders. Config:
`Morphs[]` {BaseClassname, MorphClassname, Chance} in fish.json; art: each texture graded
from the species' own photo texture and checked against photographs of the real morph,
eyes untouched. Not F4: legends are named, one-per-server fish; morphs are a rarity tier
anyone can hit.

### F76. Roe and livers on the hook (S, art: none)
Two classic real baits from things players already carry: salmon eggs (vanilla
`RedCaviar`, which the mod's trout and salmon drop) for trout, steelhead and salmon, and
chicken livers (vanilla `SmallGuts`, from gutting chickens) for catfish, bowfin, gar and
carp. Config only, as 3.3.3 did for Shrimp, Bitterlings and Sardines in
data/fish/config.cpp: `inventorySlot[] += {"Bait"}` and a `class Fishing` block on
`RedCaviar` (the mod's Yellow and Black Caviar inherit it) and on `SmallGuts`
(DZ/gear/food/config.cpp), plus one bait.json row each (roe: trout and salmon 2.5;
livers: catfish 2.5, bowfin 2.0, gar and carp 1.5). A whole tub of caviar goes on as one
bait, a real choice between a delicacy and a trophy steelhead; vanilla caviar has a gram
quantity (50 of 200), so a later pass could take a portion instead. Not the "Bait
crafting" note (cut bait made by recipe): these are vanilla items used as they are;
check they read acceptably on the hook proxy, as the sardine already does.

### F77. Feather jigs (S, art: small model edit)
A lure a player can make instead of loot: Hook (or Bone Hook) + Chicken Feathers gives a
marabou-style feather jig that never rots. Vanilla `ChickenFeather` (a stack of up to 20
from plucking chickens: `CraftFeathers`, `PrepareChicken`) is used only for arrows
today (`CraftArrow`, 4_world/classes/recipes/recipes/craftarrow.c); the jig reuses
vanilla `jig.p3d` (already a hook-slot lure, `hookType="Hook"`) with a texture made from
the feather's own, and extends `geb_Lure` so the tackle boxes and hook slot take it.
Normal two-ingredient recipe with vanilla's crafting animation (`CMD_ACTIONFB_CRAFTING`,
recipebase.c), one feather used; bait.json row trout and salmon 2.0, panfish 1.8, bass
1.3, and lower durability than a found lure. Config: `RecipeToggles.CraftFeatherJig`
(with its key check in `GeneralConfig.Backfill`, like `CraftFishMount`); art: vanilla's jig
has no hidden selections, so it needs a debinarized copy with a `camo` selection.

**Trophies, base life and quality of life**

### F78. Trophy poses (S, art: none)
Let the owner turn a mounted fish to face left (so two plaques can face each other
across a wall) or set it leaping, nose up, instead of every trophy hanging the same way.
A target action on the placed mount (`ActionInteractBase` subclass with
`CMD_ACTIONMOD_INTERACTONCE`, 3_game/dayzplayer.c) cycles a pose index that the server
stores and net-syncs; `GebPoseTrophy` (geb_fishmount.c) adds 180° to `fish_yaw` and
mirrors the side shift, or adds pitch for the leap, on every client. The mount shipped in
3.3.2, so the pose byte needs a storage-version guard in `OnStoreSave`/`OnStoreLoad`;
make it one versioned block that F1's size, catcher and date can join later. Risk: some
skins are only good on one flank (the "good side out" choice in tools/build_mount_poses.py),
so the builder should emit a left-facing pose per species and flag one-sided fish as
right-only.

### F79. Lure shadow box (M, art: one model)
A glass-fronted wall case with a dozen lure slots, so a collection of spinners, spoons,
cranks and jigs can hang beside the trophies; unlike the mount, lures can be taken back
out. Built like the mounts: CfgSlots + proxies in the model, `inventorySlot[] +=` the
new slots on `geb_Lure`, vanilla `Jig`, `Hook` and `BoneHook`, the 45-day board lifetime,
and the same wall placement: generalize the modded `Hologram`'s
`IsInherited(geb_WoodenFishMount)` checks to a shared wall-hung base (or a
`GebHangsOnWall()` virtual) so both items snap to walls. Crafted like the small mount
(planks + wire, hacksaw as a tool), toggle `RecipeToggles.CraftLureBox`; art: one model
using the mounts' walnut wood and a clear cover. Not F36 (a floor rack for rods): this is
wall décor for the small tackle.

### F80. Catches go into your creel (S, M with the creel; art: retexture of a vanilla bag)
Vanilla drops every catch on the ground at your feet (`CatchingResultBasic.SpawnAndSetup`
uses `CreateObjectEx(..., ECE_PLACE_ON_SURFACE)`), which means a stoop and a drag after
every fish. Phase 1 (S): right after `TrySpawnCatch`, the server moves the fish into the
player's clothing or backpack cargo if it fits, with `ServerTakeEntityToInventory` /
`ServerTakeEntityToCargo` (3_game/entities/entityai.c, man.c), never into the hands that
hold the rod and never into a filtered bait container that would refuse it after a
restart (`GebAcceptsType`). Phase 2 (M): a fishing creel, a retexture of vanilla
`CourierBag` (its `camoGround/camoMale/camoFemale` selections; canvas and leather from
vanilla textures) on the Back slot with a fish-and-fillet allow-list; catches go there
first, and a damp creel halves rot through the existing `Edible_Base.ProcessDecay` hook.
Config: `CatchToInventory` (0 ground as vanilla, 1 creel only, 2 any cargo).

### F81. Fillets land where the fish was (S, art: none)
Fillet a fish that sits in a cooler and the fillets go back into that cooler instead of
onto the floor; base cooks working through a cooler of catch stop shuffling meat by hand.
The mod's `PrepareFish` sets every result to the ground (`m_ResultToInventory = -2`,
preparefish.c; vanilla RecipeBase runs SpawnItems, ingredient changes, then Do), so
remember the fish's hierarchy parent in the existing `SpawnItems` override and, after
`Do`, move each result there with `ServerTakeEntityToTargetCargo` when the container
accepts it (`CanReceiveItemIntoCargo`, plus `GebAcceptsType` for the filtered
containers); anything that doesn't fit stays on the ground as today. Server-only, no
action change, toggle `FilletsToSourceContainer` in GeneralSettings.

### F82. Species and bait tips in the tooltip (S, art: none)
A fish's tooltip adds a line from the server's own tuning ("Bites best on: Live Minnow,
In-Line Spinner, Bitterlings. Most active: dusk and night. Likes 12–18 °C water"), and a
bait's tooltip lists the three species it attracts most. The client already holds the
full config after ConfigSync, so `DescriptionOverride` (object.c; used by
`InventoryItem.GetTooltip`) can rank the bait matrix rows, read the BiteSpeed curve's peak
hours and the TempMin/TempOptimal/TempMax for the item's type, covering vanilla species
too through the modded `Edible_Base`. Labels need stringtable keys in all 14 languages;
config `TooltipTips` (off for servers that want the matrix kept secret). Not F18 or F48
(a book and the wiki): those are static, while this is always the server's live numbers,
in the item the player is holding.

**Server and admin tools**

### F83. Bag limits (S/M, art: none)
Per-species daily limits (three lake sturgeon, one great white a day) and an optional
hourly cap per player stop caviar and shark farming on trader servers, the way real
fishing regulations do. Server-only and after the shared catch math: in the mod's
`TrySpawnCatch` override, if the player (keyed by `identity.GetPlainId()`) is over the
limit for the picked species, skip the spawn and tell them it was released ("over your
daily limit"), so client and server never disagree about the pick; F1's Release can
share the record. Counts live in memory and in `$profile:Gebs/baglimits.json` so a
restart doesn't clear them, and roll over at UTC midnight from `GetYearMonthDayUTC`
(1_core/proto/ensystem.c), with a log/ADM line on each limit hit. Config: per-species
`DailyBagLimit` (0 = none) in fish.json and `MaxCatchesPerHour` (0 = off) in
general.json, both in the editor. Not F2's "fished out" stock, which is per water: this
is per player, the stronger tool where fish are money.

### F84. Sea junk and lake junk (S, art: none)
Junk comes from one table on every water, so a sea cast pulls up the same wellies and
cooking pot as a farm pond. Give `JunkEntry` and `ContainerJunkEntry` an `Environment`
(1 pond, 2 sea, 3 both; default 3 so existing files behave as today) like the net and
spear tables, and set it as the junk yield's `m_EnviroMask` in the modded `YieldItemJunk`
(vanilla's `Init` hard-codes `MASK_ENVIRO_WATER_ALL`, yieldsfishingjunk.c); both sides
build their yields from the same synced junk.json, so the pick stays in lockstep and
`JunkShare` keeps working on the filtered pool. Seed sea junk from vanilla rope, netting
and a water bottle, keep wellies and the pot for lakes, and give `TreasureContainerEntry`
the same field (server-only) so the sea gives up sea chests and dry bags and lakes give
crates. Pairs with F66 (real sunken items) and F68 (notes).

### F85. Script events for other mods (S, art: none)
Publish what happens as `ScriptInvoker` events (2_gamelib/tools.c; the mod already
exposes one, `GebGetConfigReadyInvoker` in scripts/3_game/dayzgame.c): `OnCatch(player,
item, baitType, snapshot)`, `OnRelease`, `OnFillet(player, fish, results)`,
`OnTreasure(player, container)`, `OnPredatorSpawn(player, animals)` and
`OnTrophyMounted(player, mount, fish)`. Quest, leaderboard, trader and logging mods can
react without patching gebsfish, and the mod's own planned F5, F7, F18, F25, F83 and
F86 subscribe to the same events instead of each adding code to `TrySpawnCatch` and
`PrepareFish.Do`. Fired server-side after the shared catch math, so lockstep is
unaffected; the signatures go in the wiki's admin section and stay stable across
versions. No config.

### F86. Discord webhook (S, art: none)
The server posts treasures, rare species, legends, records and derby results straight
to a Discord channel, with no bot or log scraper needed. Vanilla ships an HTTP client:
`CreateRestApi()`, `GetRestContext(url)`, `SetHeader("application/json")` and the
asynchronous `POST(callback, path, body)` (3_game/http/restapi.c); queue the messages and
send at most one every few seconds to stay under Discord's rate limit. The URL is a
secret and general.json goes to every player through ConfigSync (`OnClientPrepareEvent`,
geb_missionserver.c), so it must live in a server-only file such as
`$profile:Gebs/webhook.json`, never in the four synced files. Config: `WebhookUrl`, which
events to post, the rarity (CatchProbability) worth posting, an optional daily summary
(biggest catches, treasure count); it listens to F85's events. Complements F7 (in-game
messages) and F25 (log lines for third-party tools).

### F87. Editor: server-style presets (S, art: none)
One click in the config editor sets a whole style: Casual (no predators, junk share
0.05, treasure about 1 in 2,000 with no rod wear, caviar always kept), Default (the
shipped values) and Hardcore (predators 5 % per action, junk 0.2, treasure 1 in 20,000,
three treasures still ruin a rod, a lower `MaxStackedMultiplier`). The page already loads
and writes all four files and has presets only for BiteSpeed curves (`BITE_PRESETS` in
docs/config-editor.html); a preset is a plain list of field paths and values applied on
top of the admin's files, listing the changed fields before download (pairs with F41's
changed-from-default view). Admins who don't want to learn 80 fields get a sensible
server in a minute, and community presets can be shared as small JSON files.

### F88. Editor: trader price export (S/M, art: none)
Trader setup is the first question admins of a 79-species mod ask (the README credits a
community trader spreadsheet): the editor suggests a buy and sell price for every fish,
fillet, caviar, lure and piece of gear from the admin's own files (rarity from
CatchProbability and the method/environment masks, weight, fillet count) and exports an
Expansion Market category file and TraderPlus price lines. Prices follow the tuning, so a
species made rarer is worth more, and one base-value slider scales the whole economy.
The export page repeats the existing trap: traders refuse partly full items unless
`FishQuality` is 1.0. Browser-only like the rest of the editor; open question: the trader
mods' file formats change between versions, so keep the exporters small and dated.

**Bigger features**

### F89. Native species for the maps (L, art: new models)
The roster is mostly North American and tropical, while the maps are Central European
(Chernarus, Livonia) and the Russian Far East (Sakhal). A European pack (wels catfish,
a true giant for the large mount; zander, tench, bream, roach, European eel, burbot,
grayling) and a Far East pack (Arctic char, Dolly Varden, Sakhalin taimen, saffron cod,
Pacific herring, greenling) would make each map's water feel local, with F54's per-map
switch keeping them where they belong. Each species is the full new-variant job (config,
stringtable in 14 languages, types and spawnable generators, recipe row, manifest
builder, item-details.js, webp, wiki lists) plus a photo-textured model (CadNav and real
photographs, never procedural), a fillet group, temperature and BiteSpeed rows, bait
matrix entries and a mount pose. Ship in packs of three or four so the art pipeline
(relief maps, sheen, all-angle checks) stays manageable; burbot and taimen also give
F14's ice fishing a reason to exist on Sakhal.

### F90. Fish pen (L, art: one model)
A staked net pen set in shallow water at a base: live catches put in it stay fresh, and
two of a species plus feed (worms, grubs, fish scraps) breed a third every few real
hours until the pen is full, so a group can farm bluegill, carp or perch. Placement
inverts vanilla's rule: `Hologram.IsUnderwater` (hologram.c) refuses water, so the pen
opts out the way the fish mount opts out of the ground checks (geb_fishmount.c) and
instead requires `GetWaterDepth` of about 0.4–1.5 m under its corners; it is placed with
vanilla `ActionDeployObject` (the `CMD_ACTIONFB_PLACING_*` animations). Freshness reuses
the live-well rule in `Edible_Base.ProcessDecay` (geb_ediblebase.c, as the water barrel
does) and breeding is a server timer like F60's worm farm; the pen is a container, so
fish come out by hand. Config: `FishPenSettings` {Enable, BreedHours, MaxFish,
FeedClassnames, AllowedSpecies} and a 45-day lifetime like the mounts; art: one model
from vanilla netting and wood textures; risk: breeding valuable species is an economy
lever, so sturgeon and sharks start off the allowed list.
