# FUTURE_IDEAS — things the mod could add or reuse

Ideas from the 2026-10-01 review against the decompiled vanilla game (build
125372: scripts, debinarized configs, CE XML, engine natives). None of these are
bugs — bugs and suspected bugs live in `MAYBE_ISSUES.md`. Each idea names the
vanilla/engine piece it would build on. Delete an entry when it ships or is
rejected.

**Animations: only what is already in the game.** No idea may need a custom
animation. Every player action uses a vanilla `CMD_ACTIONMOD_*` /
`CMD_ACTIONFB_*` command (as spear fishing uses `CMD_ACTIONFB_DIGGIN_WORMS`), and the held item's animation set must define it or the player freezes,
and each idea that adds an action names the one it would use. The 2026-10-02 review added the bigger feature ideas at the end
(F1–F25).

Anything new that feeds the catch math (light, weather, a time window...) must
go into `GebFishingSnapshot`, not be read live: the context runs on client and
server in lockstep and both must see the same value.

---

## Catch and tackle tuning

### Unused per-species hooks on the yield class
- `GetQualityForYieldItem` — per-species catch size (how full the fish comes
  out).
- `GetCatchParticleID` / `GetCatchDeathSoundset` — a bigger splash or sound for
  big fish.
- `GetCycleTimeForYieldItem` — per-species bite curves. Vanilla gives
  WalleyePollock, SteelheadTrout and Shrimp their own hourly curves
  (`yieldsfish.c`); the mod's generic yields reset them to the default.
- `OnEntityYieldSpawned` — any per-species setup after the catch spawns.

## Server and admin quality of life

- **Smaller ConfigSync.** About 70 KB goes to every joining player, nearly half
  of it Info prose the client never reads (≈16 KB once per section, ≈15 KB
  repeated in every array entry); the fish table and bait matrix are ~33 KB.
  Send clients a slim object (Fish, Bait, the toggles they use), or move
  per-entry Info to the parent.
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

## Code health

- **Very rare chances elsewhere.** Engine `rand()` is 15-bit; anything that must
  go below 1 in 32,768 needs the two-draw roll the treasure spawner now uses.

## Bigger features (2026-10-02 review)

Feature ideas from the second review. Sizes: S = a day or two, M = about a week,
L = more. "Art" says what models or textures it needs. One fact several ideas
lean on: the cast point is already identical on client and server (vanilla
`ActionBase.WriteToContext` sends `m_Target.GetCursorHitPos()` and the server
re-checks the water target), so a position-based rule only needs a local copy
of the point in `GebFishingSnapshot`; nothing new goes over the network.

**Quick win:** mercury (F6).

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

### F12. Chum (M, art: retexture only)
- Mix guts and fish meat into a chum bucket and throw it: for ~10 minutes the
  slick draws sharks and big pelagics at sea, or pike and musky in lakes; the
  smell also raises the chance of wolves or bears on land.
- Vanilla `Guts` (from skinning) + fish meat → `geb_ChumBucket` (Bait Bucket
  model, new texture). A pour-out action on `CCTWaterSurfaceEx` (vanilla's
  empty-a-bottle animation, `CMD_ACTIONMOD_EMPTY_VESSEL`) registers a
  short-lived slick with a predator bias, staying under `MaxStackedMultiplier`.
  The server sends nearby clients the slick list; the client writes a `SlickId`
  into the snapshot and the server keeps it only if that slick exists and the
  cast point is inside its radius (same pattern as time and rain). Land predators via
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
  `DZ/surfaces_sakhal/config.cpp`, so vanilla fishing never targets them)
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
  a battery fish finder (handheld or
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

### F27. Night light fishing (S, no art)
A lit vanilla PortableGasLamp, Roadflare, Chemlight or Torch within about 3 m
adds a night bite bonus. Carry a LightNearby flag in GebFishingSnapshot, and
have the server confirm it with GetObjectsAtPosition before trusting the
client's value, the same pattern as Rain. No new action.

### F30. Shark and sturgeon skin (M, art: retexture)
A geb_FishSkin : Pelt_Base as an extra fillet result for the big species.
Vanilla CraftTannedLeather (Pelt_Base + GardenLime, vanilla crafting animation)
already takes any Pelt_Base, so it tans into vanilla TannedLeather.

### F32. Shared loot presets (S, no art)
Have the generator write gebsLures, gebsKnives and gebsLiveBait presets for
vanilla cfgrandompresets.xml and use them itself in cfgspawnabletypes
(`<cargo preset="...">`). Admins could then give any vanilla container a lure
chance with one line. Keeping each list in one place prevents omissions like
A1.

### F36. Rod rack (M, art: one model)
A placeable rack with 4-6 rod slots, built like the fish mount (CfgSlots plus
Proxy attachments) and placed with vanilla ActionDeployObject. Naming its slots
fishingrod1-N would give the cross-mod rod slots every rod already carries
(Watch #4) a use inside the mod.

### F39. Editor: class check and rename helper (S)
Flag classnames that aren't gebsfish or vanilla, and offer one-click renames
for known renames (geb_Bonita → geb_PacificBonito) that carry the admin's values
over.

### F41. Editor: "changed from default" view (S)
Highlight values that differ from the shipped defaults, with a reset per
field, and show a summary of changes before download.

## Ideas from the 2026-10-05 review (F66–F90)

From the fifth full pass, each checked against F1–F65 (where one is close, the entry says what is new). Sizes: S = a day or two, M = about a week, L = more. Ranked by value for effort: F69, F84, F87, F71, F77, F88, F75, F79.

**Fishing loop and the world around the water**

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

**Tackle and bait**

### F75. Rare colour morphs (M, art: one recolour per morph)
About one catch in several hundred of a few species comes up as a real colour morph: a
golden (palomino) rainbow trout, a blue walleye, a silver-phase northern pike, a xanthic
largemouth bass; a collector's catch for the mounts and for traders. Each morph is a
config child of its species with its own texture on the existing `Camo` hidden
selection, swapped in server-side after `TrySpawnCatch` (create the morph,
`TransferItemProperties`, delete the original), rolled with the treasure
spawner's 30-bit `RollPrecise01`, nominal 0 in types.xml (no new world loot). Every
lookup keyed on the exact class needs a fall-back to the parent: the fish.json row in
`PrepareFish.GebResolveRecipe`, `GebMountPoses` (which since 2026-10-05 falls back to a
listed parent class), the bait matrix and the wiki builders. Config:
`Morphs[]` {BaseClassname, MorphClassname, Chance} in fish.json; art: each texture graded
from the species' own photo texture and checked against photographs of the real morph,
eyes untouched.

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

**Server and admin tools**

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
crates.

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
