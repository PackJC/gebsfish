/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Whole fish behave like vanilla Carp: a raw corpse that rots, cooked only
// as fillets. A config class with no script class of its own runs as its
// nearest scripted config ancestor, so the config-only fish bases need these
// script twins -- without them every species under them ran as plain
// Edible_Base, whose CanDecay() is false, and never rotted.
class geb_FishBase extends Edible_Base {
	override bool CanBeCookedOnStick() {
		return false;
	}

	override bool CanBeCooked() {
		return false;
	}

	override bool IsCorpse() {
		return true;
	}

	override bool CanDecay() {
		return true;
	}
}

class geb_FreshFish_Base extends geb_FishBase {}
class geb_SaltFish_Base extends geb_FishBase {}
class geb_LargeFish_Base extends geb_FishBase {}

// Big fish: carried two-handed like a heavy item.
class geb_EdibleBase extends geb_FishBase {
	// No CanSaveItemInHands here: the game asks the holder (the player), never
	// the item, so an override on the fish never ran.
	override bool IsHeavyBehaviour() {
		return true;
	}

	override bool IsTwoHandedBehaviour() {
		return true;
	}
}

class geb_AngelShark extends geb_EdibleBase {}
class geb_AtlanticBlueMarlin extends geb_EdibleBase {}
class geb_AtlanticSailFish extends geb_EdibleBase {}
class geb_GreatWhiteShark extends geb_EdibleBase {}
class geb_HammerHeadShark extends geb_EdibleBase {}
class geb_LeopardShark extends geb_EdibleBase {}
class geb_MahiMahi extends geb_EdibleBase {}
class geb_LakeSturgeon extends geb_EdibleBase {}

// The live baits are Shrimp in config, so they extend vanilla's Shrimp
// script class too: that is what makes them cookable, eatable as meat, and
// perishable (plain Edible_Base gave them none of it). On a hook they show
// their hooked model instead of the loose one.
class geb_LiveBaitBase extends Shrimp {
	override void OnWasAttached(EntityAI parent, int slot_id) {
		super.OnWasAttached(parent, slot_id);

		if (InventorySlots.GetSlotName(slot_id) == "Bait") {
			SetAnimationPhase("bait_unhooked",1);
			SetAnimationPhase("bait_hooked",0);
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id) {
		super.OnWasDetached(parent, slot_id);

		if (InventorySlots.GetSlotName(slot_id) == "Bait") {
			SetAnimationPhase("bait_unhooked",0);
			SetAnimationPhase("bait_hooked",1);
		}
	}
}

class geb_FatHeadMinnow extends geb_LiveBaitBase {}
class geb_AmericanBullFrog extends geb_LiveBaitBase {}
class geb_RedSalamander extends geb_LiveBaitBase {}

// =============================================================================
// geb_Cooler preservation hook
// =============================================================================
// Slows / stops the natural food-spoilage cycle on items stored inside a
// geb_Cooler. Implemented as a modded class override of Edible_Base so it
// applies to vanilla fish, gebsfish fillets, lobster parts, and any other
// edible loaded by another mod -- as long as the item ends up parented
// (anywhere in the hierarchy chain) to a geb_Cooler.
//
// Mod-conflict safety:
//   1. Uses `modded class` -- Enforce's standard composition idiom. Other
//      mods that also `modded class Edible_Base` chain via super, so each
//      mod's pre-super logic runs in load order, then vanilla, then each
//      mod's post-super logic. Our override only modifies the `delta`
//      parameter before calling super, so downstream overrides see a
//      smaller (or zero) decay tick rather than getting clobbered.
//   2. Behavior is gated on the item actually being inside a geb_Cooler.
//      Items not in a cooler hit the early-out and pass straight through
//      to super with vanilla delta intact -- no global side effect.
//   3. The preservation factor is one class-level constant, not a literal
//      scattered through the function.
//   4. Walks the full hierarchy parent chain rather than just the direct
//      parent, so a fillet stored inside a ziploc / sealed bag / nested
//      container that itself sits in the cooler still benefits.
//
// Tuning:
//   GEBSFISH_COOLER_DECAY_MULTIPLIER controls how strongly the cooler
//   preserves food.
//     0.0  = perfectly preserved (rotting stops entirely) -- default
//     0.05 = 20x slower than vanilla decay
//     0.5  = half-speed decay
//     1.0  = no preservation (cooler does nothing -- useful for testing)
modded class Edible_Base {

	// Decay multiplier applied to ProcessDecay's `delta` when the item is
	// hierarchy-parented to a geb_Cooler. See comment block above for the
	// scale.
	protected const float GEBSFISH_COOLER_DECAY_MULTIPLIER = 0.0;

	// A vanilla barrel at least this full of water is a live well for whole
	// fish and minnows (see GebsfishIsInWaterBarrel).
	protected const float GEBSFISH_BARREL_MIN_WATER = 0.5;

	override void ProcessDecay(float delta, bool hasRootAsPlayer) {
		// Only intervene when the item is inside one of our preserving
		// containers. Every other code path passes through untouched so
		// vanilla / other mods' decay tuning still applies normally.
		if (GebsfishIsInsideCooler())
			delta = delta * GEBSFISH_COOLER_DECAY_MULTIPLIER;
		else if (GebsfishIsInsideBaitContainer())
			delta = 0;   // worm/bug/minnow containers keep live bait fresh
		else if (GebsfishIsMountedTrophy())
			delta = 0;   // taxidermy: a fish on the wall mount never rots
		else if (GebsfishIsInWaterBarrel() && GebsfishIsLiveCatch())
			delta = 0;   // a water barrel half full or more is a live well

		super.ProcessDecay(delta, hasRootAsPlayer);
	}

	// Walks the hierarchy parent chain looking for a geb_Cooler_base ancestor.
	// Returns true on the first match. Null-safe: world-loose items
	// (GetHierarchyParent returns null immediately) fall straight to false.
	// Loop is bounded by the inventory tree depth which is shallow in
	// practice, so no iteration cap is needed.
	//
	// The cast targets geb_Cooler_base (the script base class) so every
	// colored variant -- geb_RedCooler, geb_BlueCooler, etc. -- matches
	// without needing per-color cast attempts. DayZ instantiates colored
	// variants against the parent's script class, and Class.CastTo
	// succeeds on the parent type for any derived runtime instance.
	protected bool GebsfishIsInsideCooler() {
		EntityAI parent = GetHierarchyParent();
		while (parent) {
			geb_Cooler_base cooler;
			// A ruined cooler is just a box: it no longer chills or preserves.
			if (Class.CastTo(cooler, parent) && !cooler.IsRuined())
				return true;
			parent = parent.GetHierarchyParent();
		}
		return false;
	}

	// A vanilla barrel holding water (any kind, fresh, clean or salt) at least
	// half full: the item sits in its cargo, in the water. Only the direct
	// parent counts -- a fish inside a box inside the barrel isn't in the water.
	protected bool GebsfishIsInWaterBarrel() {
		Barrel_ColorBase barrel = Barrel_ColorBase.Cast(GetHierarchyParent());
		if (!barrel || barrel.IsRuined() || barrel.GetQuantityMax() <= 0)
			return false;
		if ((barrel.GetLiquidType() & LIQUID_GROUP_WATER) == 0)
			return false;
		return barrel.GetQuantity() >= barrel.GetQuantityMax() * GEBSFISH_BARREL_MIN_WATER;
	}

	// What a water barrel keeps alive: whole fish (the mod's fish bases and
	// vanilla's whole fish) and the minnow. Worms and insects age in modded
	// Worm, which doesn't look at barrels, so they still die there.
	protected bool GebsfishIsLiveCatch() {
		return IsKindOf("geb_FreshFish_Base") || IsKindOf("geb_SaltFish_Base") || IsKindOf("geb_LargeFish_Base") || IsKindOf("geb_FatHeadMinnow") || IsKindOf("Carp") || IsKindOf("Mackerel") || IsKindOf("WalleyePollock") || IsKindOf("SteelheadTrout") || IsKindOf("Sardines") || IsKindOf("Bitterlings");
	}

	// Trophy check: the fish attaches directly to the plaque, so a single
	// parent hop is enough -- no full hierarchy walk needed.
	protected bool GebsfishIsMountedTrophy() {
		return geb_WoodenFishMount.Cast(GetHierarchyParent()) != null;
	}

	// Same hierarchy walk for the dedicated bait containers. Tackle boxes are
	// deliberately NOT in this list -- stashing bait in a tackle box is allowed
	// but doesn't keep it fresh, so the dedicated containers stay worth carrying.
	protected bool GebsfishIsInsideBaitContainer() {
		EntityAI parent = GetHierarchyParent();
		while (parent) {
			geb_WormContainer wormContainer;
			geb_BugContainer bugContainer;
			geb_MinnowBucket minnowBucket;
			// A ruined one no longer keeps anything fresh.
			if ((Class.CastTo(wormContainer, parent) || Class.CastTo(bugContainer, parent) || Class.CastTo(minnowBucket, parent)) && !parent.IsRuined())
				return true;
			parent = parent.GetHierarchyParent();
		}
		return false;
	}
}

// Live bait dies over time. The geb insect baits (geb_GrassHopper,
// geb_FieldCricket, geb_GrubWorm) all config-extend vanilla Worm, so this one
// modded class ages every live bait in the mod plus vanilla worms. The
// artificial geb_RubberWorm also extends Worm and is explicitly exempted.
//
// Aging drains item health; at Ruined the bait is dead. It pauses while the
// bait sits in a worm/bug container (its natural habitat) or a cooler, as
// long as that container isn't ruined
// (refrigerated bait keeps, like real anglers do with worms). Tackle boxes do
// NOT pause it -- the dedicated containers are the point.
//
// It runs on the Central Economy's periodic item update (OnCEUpdate), the
// same clock vanilla uses for food rot and item temperature, rather than a
// timer per worm: hundreds of loose worms meant hundreds of timers ticking
// every frame, and dead ones kept ticking. The update hands over the seconds
// since the item's last one, so the rate doesn't depend on how often it runs.
//   BAIT_LIFETIME_SECS = real seconds from pristine to ruined when exposed,
//                        at the server's normal food decay (FoodDecay 1)
modded class Worm {
	protected const float BAIT_LIFETIME_SECS = 5400.0;  // 90 minutes

	override void OnCEUpdate() {
		super.OnCEUpdate();
		if (!g_Game.IsServer() || IsRuined())
			return;
		// Artificial lure: never dies.
		if (IsKindOf("geb_RubberWorm"))
			return;
		if (m_ElapsedSinceLastUpdate <= 0 || GebsfishIsBaitPreserved())
			return;
		// The server's food decay setting (FoodDecay in the CE's globals.xml)
		// sets the pace, as it does for vanilla food rot: 0 stops the clock,
		// 0.5 doubles the 90 minutes.
		float decay = g_Game.GetFoodDecayModifier();
		if (decay <= 0)
			return;

		float step = GetMaxHealth("", "") * (m_ElapsedSinceLastUpdate / BAIT_LIFETIME_SECS) * decay;
		DecreaseHealth("", "", step);
	}

	// geb_MinnowBucket is deliberately NOT listed here, even though the rot
	// walk in Edible_Base does list it. The bucket is for small aquatic
	// catches (minnows, crayfish, shrimp, frogs, salamanders) and its cargo
	// filter rejects worms and insects by design, so live bait can never be
	// inside one and there is nothing for this check to catch. Don't "fix"
	// the asymmetry by adding it -- that would only matter if the bucket
	// started accepting insects, which it should not.
	protected bool GebsfishIsBaitPreserved() {
		EntityAI parent = GetHierarchyParent();
		while (parent) {
			geb_WormContainer wormContainer;
			geb_BugContainer bugContainer;
			geb_Cooler_base cooler;
			// A ruined container no longer keeps bait alive.
			if ((Class.CastTo(wormContainer, parent) || Class.CastTo(bugContainer, parent) || Class.CastTo(cooler, parent)) && !parent.IsRuined())
				return true;
			parent = parent.GetHierarchyParent();
		}
		return false;
	}
}
