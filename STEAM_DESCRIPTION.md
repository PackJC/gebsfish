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
[*] [b]Fish that behave like fish:[/b] each species has its own water (fresh, salt or both), catch method, weather and time-of-day habits and a 24-hour bite cycle; moon phase changes night fishing, and water temperature is optional.
[*] [b]Bait matters:[/b] about 2,000 bait and fish pairings: worms for panfish, spinners for bass and pike, live minnows for pike and walleye, crayfish for bass and catfish, shrimp for reef fish, squid for the big sea fish.
[*] [b]Live bait:[/b] dig for worms and bugs. It dies in about 90 minutes outside a Worm Container, Bug Catcher or cooler; the Bait Bucket keeps small aquatic catches fresh.
[*] [b]More ways to fish:[/b] rods, fish traps, a bamboo fishing net, and spear fishing in the shallows.
[*] [b]Coolers[/b] chill to -5°C and can freeze your catch; frozen fish must thaw before filleting.
[*] [b]Caviar[/b] from roe fish, lobster tails and claws, and crab legs.
[*] [b]Junk catches[/b] (about one rod catch in ten), [b]ultra-rare treasure[/b] (about 1 in 5000, on a proper rod only) and the odd hook or lure inside a fish.
[*] [b]Jon boat:[/b] a drivable boat in six looks, with deck slots for coolers or tackle boxes, a fuel tank, a battery and lights, at the map's boat spawns.
[*] [b]Boat trailer:[/b] hitch it to a car, winch a boat on, tow it, back it into the water and launch.
[*] [b]For your base:[/b] fish mounts in three sizes for the fish you actually caught, a fishing locker, a drying rack (no fire needed) and a fish tank.
[*] [b]Canned fish and fish foods[/b] on vanilla's packaging, sharing vanilla's spawns instead of adding loot.
[*] [b]Fishing clothes:[/b] hats, shirts, raincoats, vests, wellies and gloves in ten colours and four camos, each colour the same shade on every item.
[*] [b]Predators[/b] can turn up while you fish, fillet, net or spear: on land only, capped, and gone on their own.
[*] [b]Fishing effects:[/b] blood when you fillet, flies over rotting fish, and a cold mist rising off every cooler.
[*] [b]Works on custom maps[/b]: the map's own extra catches are kept. Deadfall is supported.
[/list]

[h1]Server Configuration[/h1]
The config files live in your server profile, in [b]$profile:Gebs/[/b]:
[list]
[*] [b]general.json[/b]: weather, predators, nets, spear fishing, digging, treasure, recipes.
[*] [b]fish.json[/b]: one row per species (water, method, chance, weather, temperature, bite cycle, fillets).
[*] [b]bait.json[/b]: which fish each bait and lure attracts.
[*] [b]junk.json[/b]: what junk comes up and how often.
[/list]
Every setting is explained in its file, and every major system has an on/off switch. Updates only add what's missing, so your values are kept. To turn something off, set its chance or weight to 0 (a deleted entry comes back on update).

The wiki's [b]visual config editor[/b] edits your files in the browser and shows each species' odds.

[b]Updating from 3.x:[/b] fishingsettings.json is replaced with no migration (the old file is archived in $profile:Gebs/gebs_oldfiles/). Take geb_Bonita (now geb_PacificBonito) and the four Fun tackle boxes out of your types and trader files.

[b]Types, spawns & events:[/b] gebsfish-types.xml, gebsfish-spawnabletypes.xml and gebsfish-events.xml (jon boat spawns) are written to $profile:Gebs/mpmissions/ when the mod's version changes. Register them in cfgeconomycore.xml (each file's header shows how); delete one to rewrite it.

[b]Quick tuning:[/b]
[list]
[*] Fishing chances: CatchProbability in fish.json sets how common each species is: 0-25 is recommended, 0 stops it being caught.
[*] Predators: each action (fishing, filleting, a failed catch, the net, the spear) has its own chance in general.json; the default 0.01 is 1% per action, 0 turns them off.
[*] Traders: fish are caught full by default (FishQuality 1.0), since most trader mods only buy full items.
[/list]

[h1]Supported Languages[/h1]
English, Czech, German, Russian, Polish, Hungarian, Italian, Spanish, French, Chinese (Traditional and Simplified), Japanese, Portuguese.

Native speaker and spot a bad translation? Please tell us in the Discord.

[h1]The Geb's Family[/h1]
More by Geb: [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2764114664]Geb's Animals[/url], [url=https://packjc.github.io/gebsplants/]Geb's Plants[/url], [url=https://packjc.github.io/gebsmushrooms/]Geb's Mushrooms[/url], [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2840597308]Alien Invasion[/url], [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2886269800]Thanksgiving[/url] and the [url=https://steamcommunity.com/sharedfiles/filedetails/?id=2812533524]Great Smoky Mountains[/url] map.

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
[*] Fish and squid skins made from photos by Attila Oláh, Michael Vecchione, Philip Schaffer, Fumikas Sagisavas, Ocdp, moriza, Binh Giang, Obsidian Soul, Chiswick Chap, Marina Drago Marchesi, Astromessier, Σ64, Ken Hammond, the FDA and Jim Capaldi (licences and links on [url=https://github.com/PackJC/gebsfish]GitHub[/url])
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
