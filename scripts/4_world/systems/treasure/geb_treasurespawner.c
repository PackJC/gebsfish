/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Ultra-rare treasure catch. Rolled once per SUCCESSFUL catch (see
// ActionFishingNew.OnEnd), separately from the fish pool -- it is not a yield
// competing with the 79 species, so making it rare doesn't quietly starve
// anything else, and the chance can be tuned far finer than the 0-25 integer
// weights the catch pool uses.
//
// Shape mirrors GebsPredatorSpawner: caller supplies the player, this owns the
// roll, the weighted picks, the spawn and the logging.
//
// Two independent pools:
//   TreasureContainers -> which container arrives (one weighted pick)
//   TreasureLoot       -> what is inside (one weighted pick PER item slot)
// Rolling the loot per slot is what makes two hauls differ even from the same
// container -- there is no fixed loadout anywhere.
//
// Two gates sit around that, both configurable:
//   RequireRealRod    -> the improvised rod cannot pull treasure at all
//   RodCatchesToRuin  -> a successful pull wears the rod out, ruining a
//                        pristine one in this many finds
class GebsTreasureSpawner {

    static void TryPull(PlayerBase player, ItemBase rod, string logTag = "Treasure") {
        if (!player || !g_Game.IsServer())
            return;
        if (!m_gebsConfig || !m_gebsConfig.General || !m_gebsConfig.General.TreasureSettings)
            return;

        TreasureConf ts = m_gebsConfig.General.TreasureSettings;
        if (!ts.Enable || ts.Chance <= 0)
            return;

        int debugLevel = GebGetDebugLevel();

        // A crafted rod is a stick and a length of rope -- it has no business
        // winching a sea chest off the bottom. ImprovisedFishingRod is a SIBLING
        // of FishingRod (both extend FishingRod_Base_New) rather than a child, so
        // testing for FishingRod admits the vanilla rod and the four gebsfish
        // colour variants while leaving the improvised one out. Gated before the
        // roll so an ineligible rod never burns a chance.
        if (ts.RequireRealRod && (!rod || !rod.IsInherited(FishingRod))) {
            if (debugLevel == ELEVATED_DEBUG) {
                string rodType = "none";
                if (rod)
                    rodType = rod.GetType();
                GebsfishLogger.Debug("skipped: RequireRealRod is on and the rod in hand is " + rodType, logTag);
            }
            return;
        }

        float roll = Math.RandomFloat01();
        if (roll > ts.Chance) {
            if (debugLevel == ELEVATED_DEBUG)
                GebsfishLogger.Debug("miss: roll=" + roll + " chance=" + ts.Chance, logTag);
            return;
        }

        TreasureContainerEntry container = PickContainer(debugLevel, logTag);
        if (!container)
            return;

        // Containers are bulky, so they go on the ground at the player's feet
        // rather than attempting an inventory placement that would usually fail.
        EntityAI spawned = EntityAI.Cast(
            g_Game.CreateObjectEx(container.Classname, player.GetPosition(), ECE_PLACE_ON_SURFACE));
        if (!spawned) {
            // Kept on one line: Enforce ends an expression at the newline inside an
            // argument list and then wants ',' or ')', so a continuation '+' on the
            // next line will not parse. Long lines are the norm in this codebase.
            GebsfishLogger.Error("treasure hit but CreateObjectEx returned null for container '" + container.Classname + "' -- check the classname exists on this server.", logTag);
            return;
        }

        ItemBase containerItem = ItemBase.Cast(spawned);
        if (containerItem)
            containerItem.SetHealthLevel(RollHealthLevel(container.MinHealthLevel, container.MaxHealthLevel), "");

        int placed = FillContainer(spawned, container, debugLevel, logTag);

        DamageRod(rod, ts.RodCatchesToRuin, debugLevel, logTag);

        if (ts.Announce)
            player.MessageImportant("Something heavy comes up with your line...");

        // GetIdentity() is null for a player mid-disconnect, so don't chain off it.
        string who = "unknown";
        if (player.GetIdentity())
            who = player.GetIdentity().GetName();

        GebsfishLogger.Info("TREASURE: " + container.Classname + " with " + placed + " item(s) for " + who + " (roll=" + roll + " chance=" + ts.Chance + ")", logTag);
    }

    // ---- picks ----

    protected static TreasureContainerEntry PickContainer(int debugLevel, string logTag) {
        ref array<ref TreasureContainerEntry> pool = m_gebsConfig.General.TreasureContainers;
        if (!pool || pool.Count() == 0) {
            GebsfishLogger.Error("treasure hit but TreasureContainers is empty -- nothing to spawn.", logTag);
            return null;
        }

        array<ref TreasureContainerEntry> eligible = new array<ref TreasureContainerEntry>();
        TStringArray names = new TStringArray;
        TFloatArray weights = new TFloatArray;
        foreach (TreasureContainerEntry c : pool) {
            if (!c || c.Classname == "" || c.Weight <= 0)
                continue;
            eligible.Insert(c);
            names.Insert(c.Classname);
            weights.Insert(c.Weight);
        }

        int pick = GebWeightedPick.Pick(names, weights, debugLevel, logTag);
        if (pick < 0)
            return null;
        return eligible[pick];
    }

    protected static TreasureLootEntry PickLoot(int debugLevel, string logTag) {
        ref array<ref TreasureLootEntry> pool = m_gebsConfig.General.TreasureLoot;
        if (!pool || pool.Count() == 0)
            return null;

        array<ref TreasureLootEntry> eligible = new array<ref TreasureLootEntry>();
        TStringArray names = new TStringArray;
        TFloatArray weights = new TFloatArray;
        foreach (TreasureLootEntry l : pool) {
            if (!l || l.Classname == "" || l.Weight <= 0)
                continue;
            eligible.Insert(l);
            names.Insert(l.Classname);
            weights.Insert(l.Weight);
        }

        int pick = GebWeightedPick.Pick(names, weights, debugLevel, logTag);
        if (pick < 0)
            return null;
        return eligible[pick];
    }

    // ---- filling ----

    // Returns how many items actually made it in. Each slot rolls the pool
    // separately, and a slot that fails (bad classname, container full) is just
    // skipped -- a treasure with fewer items is far better than no treasure.
    protected static int FillContainer(EntityAI container, TreasureContainerEntry conf, int debugLevel, string logTag) {
        if (!container || !container.GetInventory())
            return 0;

        int slots = GetInclusiveRandomInt(conf.MinItems, conf.MaxItems);
        int placed = 0;

        for (int i = 0; i < slots; ++i) {
            TreasureLootEntry loot = PickLoot(debugLevel, logTag);
            if (!loot)
                continue;

            EntityAI made = container.GetInventory().CreateInInventory(loot.Classname);
            if (!made) {
                if (debugLevel >= 1)
                    GebsfishLogger.Debug("could not place '" + loot.Classname + "' (container full, or classname missing) -- skipping this slot.", logTag);
                continue;
            }

            ItemBase item = ItemBase.Cast(made);
            if (item) {
                item.SetHealthLevel(RollHealthLevel(loot.MinHealthLevel, loot.MaxHealthLevel), "");
                // 0/0 means "leave the item at whatever it spawns with"
                if (loot.MaxQuantity > 0) {
                    int qty = GetInclusiveRandomInt(loot.MinQuantity, loot.MaxQuantity);
                    if (qty > 0)
                        item.SetQuantity(qty);
                }
            }
            placed++;
        }
        return placed;
    }

    // ---- rod wear ----

    // Hauling a loaded container up ruins a pristine rod in catchesToRuin pulls.
    // Derived from the rod's own max health rather than a fixed number so the
    // count still holds after an admin retunes hitpoints, and so a modded rod
    // with different HP wears proportionally instead of being one-shot or barely
    // scratched.
    //
    // Every health call here is the no-arg form, which resolves to the ("", "")
    // zone/healthType pair. That pairing is deliberate: AddHealth(float) delegates
    // to AddHealth("", "", v), and it is passing "Health" as the healthType that
    // silently no-ops on rods -- the reason TryDamageItems in the fishing-rod
    // catching context uses the single-arg call. Reading the maximum with "Health"
    // would hand back 0 here and disable rod wear without a word.
    protected static void DamageRod(ItemBase rod, int catchesToRuin, int debugLevel, string logTag) {
        if (!rod || catchesToRuin <= 0)
            return;

        float maxHp = rod.GetMaxHealth();
        if (maxHp <= 0)
            return;

        float dmg = maxHp / catchesToRuin;
        float before = rod.GetHealth();
        rod.AddHealth(-dmg);

        if (debugLevel >= 1) {
            GebsfishLogger.Debug("rod wear: type=" + rod.GetType() + " max=" + maxHp + " dmg=" + dmg + " hp " + before + " -> " + rod.GetHealth(), logTag);
        }
    }

    // ---- helpers ----

    // Clamped so a typo'd config can't push SetHealthLevel out of range, and
    // inversion-safe so Min > Max degrades to "always Min" instead of breaking.
    protected static int RollHealthLevel(int minLevel, int maxLevel) {
        if (minLevel < 0) minLevel = 0;
        if (minLevel > 4) minLevel = 4;
        if (maxLevel < minLevel) maxLevel = minLevel;
        if (maxLevel > 4) maxLevel = 4;
        return Math.RandomInt(minLevel, maxLevel + 1);
    }

    protected static int GetInclusiveRandomInt(int min, int max) {
        if (min < 0) min = 0;
        if (max < min) max = min;
        return Math.RandomInt(min, max + 1);
    }
}
