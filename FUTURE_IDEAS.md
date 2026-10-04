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
- Shipped 2026-10-01: each cast uses the map's own water temperature from
  vanilla WorldData plus a seasonal swing (`GetCurrentWaterTemp`).
- Shipped 2026-10-02: junk is scaled to the fish pool (`JunkShare` in
  junk.json, default 0.1), so cold maps get the same one rod catch in ten as
  warm ones instead of drowning in boots.
- **Altitude.** Mountain lakes could run colder:
  `m_TemperaturePerHeightReductionModifier` x the cast point's height, as
  vanilla does for air. The cast point would need to be part of the snapshot.
- **Custom maps** without their own water temperatures get Chernarus's. A table
  of known custom-map values (Namalsk, Deer Isle...) in `gebsfish.c` would save
  admins the `WaterTempOffset` tuning.

### Snow counts as weather on Sakhal
- Shipped 2026-10-02: the cast snapshot carries snowfall, and the heavier of
  rain and snowfall picks the rain/storm band, so Sakhal gets the bonuses.

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

- **Refresh `*Info` text on version bumps.** Config files keep whatever Info
  prose they were written with, so corrected help text (e.g. the 2026-10-01
  FishQuality and bait-loss fixes) only reaches new installs. Copy every
  `...Info` string from a fresh defaults instance during the version-bump merge.
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
- **Client log folder.** Warnings and errors now also go to the RPT; the
  remaining logging idea is to gate the client-side ConfigSync Info lines so
  player PCs don't get a `$profile:Gebs/logs` folder. The main menu no longer
  runs the server config path (2026-10-02), so what's left is the logger
  itself, which writes `$profile:Gebs/logs` on any machine.
- **XML generators.** Per-item categories (clothes, containers), and
  regenerate when the content changes, not only on a version bump, so custom
  fish.json species get types entries. (Gear has used vanilla's 14400 s tool
  lifetime since 2026-10-02.)
- **Safer saves.** Shipped 2026-10-02: every config save makes the folder
  first and uses `SaveFile`, logging why a write failed. Left: a `.bak` via
  `CopyFile` before overwriting (there's no rename native, and the writer
  truncates first).
- **Server-side net and spear checks.** The net trusts the client's water
  type, and the spear its water type and depth (its water-surface check does
  run on the server); re-check them from the cursor position on the server
  (`CCTWaterSurfaceEx`, as vanilla fishing does). Dig-bugs and the net could
  also use vanilla dig-worms' free-space and on-ground checks.

## Code health

- **Config sections.** Pre-allocate nested sections the vanilla way
  (`cfggameplaydatajson.c`: `ref X Section = new X;`) and retire
  `GebJsonFileHasKey` once the staging test in MAYBE_ISSUES #26 confirms
  missing keys keep their defaults.
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
  CF's ModStorage. The mount is new in 3.3.3, so it can get plain `OnStoreSave`
  fields now with no migration ever needed — do that before 3.3.3 ships.

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

### F15. Spear fishing (M, no art)
- Shipped 2026-10-02: `ActionGebSpearFishing` on vanilla spears, configured
  by `SpearFishingSettings`. Its animation (DIGMANIPULATE, standing) still
  needs checking in game.

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

(F24, the "what will bite?" simulator, shipped in the config editor on
2026-10-02.)
