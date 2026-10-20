[img]https://i.imgur.com/3rhti8A.gif[/img]
[url=https://discord.gg/G8uSGZ8yyf][img]https://i.imgur.com/4IyA522.png[/img][/url]

[h1]Mod Information[/h1]
Gebsfish overhauls DayZ fishing. It adds [b]87 new species[/b] (58 fish, 11 squid, 11 crayfish, lobsters and crabs, 5 shellfish and other sea life, and 2 amphibians), for 94 catchable species with vanilla's. It also adds 18 fishing rods, 17 lures, 3 live insect baits, 14 fish knives, 29 tackle boxes, 14 coolers, 84 pieces of fishing clothing, 30 canned fish and fish foods, the jon boat, a boat trailer, fish mounts, a fishing locker, a drying rack and a fish tank.

It's meant to add immersion, not to make survival easier: catch chances, prep time, fillet counts and fish weights are balanced with that in mind.

[b]Wiki (every species, item and the odds):[/b] [url=https://packjc.github.io/gebsfish/]packjc.github.io/gebsfish[/url]

[h1]Requirements[/h1]
[list]
[*] [url=https://steamcommunity.com/sharedfiles/filedetails/?id=1559212036]Community Framework (CF)[/url], loaded on both server and client.
[*] DayZ 1.30.
[/list]

[h1]Features[/h1]
[list]
[*] [b]Fish that behave like fish:[/b] each species has its own water (fresh, salt or both), catch method, weather and time-of-day habits and a 24-hour bite cycle. Moon phase changes night fishing, and water temperature can be turned on too.
[*] [b]Bait matters:[/b] about 2,000 bait and fish pairings. Worms for panfish, spinners for bass and pike, live minnows for pike and walleye, crayfish for bass and catfish, shrimp for reef fish, squid for the big sea fish.
[*] [b]Live bait:[/b] dig for worms and bugs. Live bait dies in about 90 minutes unless it's kept in a Worm Container, Bug Catcher or cooler, and the Bait Bucket keeps small aquatic catches fresh.
[*] [b]More ways to fish:[/b] rods, fish traps, a bamboo fishing net, and spear fishing in the shallows.
[*] [b]Coolers[/b] chill to -5°C and can freeze your catch; a frozen fish has to thaw before you can fillet it.
[*] [b]Caviar[/b] from roe fish, lobster tails and claws, and crab legs.
[*] [b]Ultra-rare treasure catches[/b] (about 1 in 5000 catches, on a proper rod only), and the odd hook or lure found inside a fish.
[*] [b]Jon boat:[/b] a drivable boat in six looks, with two deck slots for coolers or tackle boxes, a fuel tank, a battery and lights. It spawns at the map's boat spawns.
[*] [b]Boat trailer:[/b] hitch it to a car, winch a boat on, tow it, back it into the water and launch.
[*] [b]Fish mounts[/b] in three sizes. Hang the actual fish you caught on your wall.
[*] [b]Fishing locker[/b], a [b]drying rack[/b] that dries fillets without a fire, and a [b]fish tank[/b] for your base.
[*] [b]Canned fish and fish foods[/b] on vanilla's packaging. They share vanilla's spawns rather than adding loot.
[*] [b]Fishing clothes:[/b] hats, shirts, raincoats, vests, wellies and gloves in ten colours and four camos. Each colour is the same shade on every item in the mod.
[*] [b]Predators[/b] can turn up while you fish, fillet, net or spear fish. They spawn on land only, are capped, and despawn on their own.
[*] [b]Junk catches[/b], about one rod catch in ten.
[*] [b]Fishing effects:[/b] blood when you fillet, flies over rotting fish, and a cold mist rising off every cooler.
[*] [b]Works on custom maps[/b]: the map's own extra catches are kept. Deadfall is supported.
[/list]

[h1]Server Configuration[/h1]
The config files are in your server profile, in [b]$profile:Gebs/[/b]:
[list]
[*] [b]general.json[/b]: weather, predators, nets, spear fishing, digging, treasure, recipes.
[*] [b]fish.json[/b]: one row per species (water, method, chance, weather, temperature, bite cycle, fillets).
[*] [b]bait.json[/b]: which fish each bait and lure attracts.
[*] [b]junk.json[/b]: what junk comes up and how often.
[/list]
Every setting is explained inside the file, and every major system has its own on/off switch. A mod update only adds what's missing, so your values are kept. To turn something off, set its chance or weight to 0; a deleted entry comes back on the next update.

The wiki has a [b]visual config editor[/b]: drop your files in, edit, download. Its "What will bite?" tab shows each species' odds.

[b]Updating from 3.x:[/b] fishingsettings.json is replaced by the files above, with no migration. The old file is archived to $profile:Gebs/gebs_oldfiles/ so you can copy your tuning across by hand. The four Fun tackle boxes are gone and geb_Bonita is now geb_PacificBonito: take the old names out of your types and trader files.

[h1]Types, Spawns & Events[/h1]
The mod writes [b]gebsfish-types.xml[/b], [b]gebsfish-spawnabletypes.xml[/b] and [b]gebsfish-events.xml[/b] (jon boat spawns) to $profile:Gebs/mpmissions/ whenever the mod's version changes. Register them in cfgeconomycore.xml; each file's header shows how. Delete a file to have it written again.

[h1]Adjust Fishing Chances[/h1]
In fish.json, [b]CatchProbability[/b] sets how common each species is. We recommend 0-25. Set it to 0 to stop a species being caught.

[h1]Adjust Predator Chances[/h1]
In general.json, each action has its own chance (fishing, filleting, a failed catch, the net, the spear). The default is 0.01, a 1% chance per action. Set it higher for more danger, or 0 to turn predators off.

[h1]Trader Compatibility[/h1]
Fish are caught full by default ([b]FishQuality[/b] 1.0), because most trader mods only buy full items.

[h1]Supported Languages[/h1]
English, Czech, German, Russian, Polish, Hungarian, Italian, Spanish, French, Chinese (Traditional), Chinese (Simplified), Japanese, Portuguese.

If you're a native speaker and spot a bad translation, please tell us in the Discord.

[h1]Contributors & Credits[/h1]
[list]
[*] Lothsun for features, updates, and helping the direction of this mod!
[*] TunaBomber for community files and the trader spreadsheet
[*] NekoSensei and iiiii42 for the first translations
[*] Doriiiiija and Echo#4343 for community files
[*] Gramps#4914 for compatibility help in the early days
[*] DannyDoomno1 for help sending config data from server to client
[*] NekoSensei and the players of the Le Murmure des Sans-Ames server
[*] cadnav.com for models and textures of fish
[*] The Cornell Lab's Macaulay Library for the loon call
[*] Squid skins made from photos by Attila Oláh, Michael Vecchione (NOAA), Philip Schaffer, Fumikas Sagisavas, Ocdp, moriza, Binh Giang, Obsidian Soul, Chiswick Chap, Marina Drago Marchesi and Astromessier (CC BY, CC BY-SA, CC0 and public domain; licences and links on [url=https://github.com/PackJC/gebsfish]GitHub[/url])
[*] Cherry salmon, rainbow trout fillet and stingray skins made from photos by Σ64, Ken Hammond (USDA), the US Food and Drug Administration and Jim Capaldi (CC BY 4.0, CC BY 2.0 and public domain; links on [url=https://github.com/PackJC/gebsfish]GitHub[/url])
[*] My close friends for motivation during this project
[*] The DayZ Modding Community <3
[/list]

[h1]Usage & Terms[/h1]
This item is NOT authorized (strictly forbidden) for any of these conditions:
[list]
[*] posting on Steam, except under the Steam account Cole.
[*] hosting on any download server other than gebsfish current workshop download.
[*] hosting on any launcher for distribution other than gebsfish current workshop download.
[*] to be packaged in any form other than gebsfish current workshop download.
[*] to create derivative works.
[/list]

[h1]PERMISSION IS NOT GRANTED FOR THIS MOD TO BE INCLUDED IN A "SERVER PACK" or "MOD PACK" DO NOT EVEN ASK TO REPACK. NO. NOT ALLOWED.[/h1]
Use a Collection if you want to include this mod on your server for your users.

[h1]Monetization[/h1]
You are hereby given monetization approval under the conditions that you follow the DayZ Server Monetization agreement and have obtained permission from Bohemia. Read more here https://www.bohemia.net/monetization

[h1]Donations[/h1]
We accept donations at https://www.paypal.com/paypalme/packjc. Every dollar counts and we greatly appreciate any contributions!

Copyright © Smoky Mountain Software 2022-2026
