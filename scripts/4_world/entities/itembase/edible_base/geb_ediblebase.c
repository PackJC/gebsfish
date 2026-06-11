/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class geb_EdibleBase extends Edible_Base {
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

	override bool CanSaveItemInHands(EntityAI item_in_hands) {
		return false;
	}

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

class geb_FatHeadMinnow extends Edible_Base {
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

class geb_AmericanBullFrog extends Edible_Base {
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

class geb_RedSalamander extends Edible_Base {
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
//   3. The preservation factor is a class-level constant (not a hardcoded
//      literal scattered through the function). A sub-mod can extend
//      Edible_Base further and override this constant to retune without
//      copying the override.
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
	// scale. Keep as `protected const` so sub-mods can override it via
	// further inheritance without touching this file.
	protected const float GEBSFISH_COOLER_DECAY_MULTIPLIER = 0.0;

	override void ProcessDecay(float delta, bool hasRootAsPlayer) {
		// Only intervene when the item is inside one of our preserving
		// containers. Every other code path passes through untouched so
		// vanilla / other mods' decay tuning still applies normally.
		if (GebsfishIsInsideCooler())
			delta = delta * GEBSFISH_COOLER_DECAY_MULTIPLIER;
		else if (GebsfishIsInsideBaitContainer())
			delta = 0;   // worm/bug/minnow containers keep live bait fresh

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
			if (Class.CastTo(cooler, parent))
				return true;
			parent = parent.GetHierarchyParent();
		}
		return false;
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
			if (Class.CastTo(wormContainer, parent) || Class.CastTo(bugContainer, parent) || Class.CastTo(minnowBucket, parent))
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
// Aging drains item health in steps; at Ruined the bait is dead. It pauses
// while the bait sits in a worm/bug container (its natural habitat) or a
// cooler (refrigerated bait keeps, like real anglers do with worms). Tackle
// boxes do NOT pause it -- the dedicated containers are the point.
//   BAIT_LIFETIME_SECS   = real seconds from pristine to ruined when exposed
//   BAIT_AGING_TICK_SECS = seconds between aging steps
modded class Worm {
	protected const float BAIT_LIFETIME_SECS   = 5400.0;  // 90 minutes
	protected const float BAIT_AGING_TICK_SECS = 300.0;   // 5 minutes

	protected ref Timer m_GebAgingTimer;

	override void EEInit() {
		super.EEInit();
		if (!g_Game.IsServer())
			return;
		// Artificial lure: never dies.
		if (IsKindOf("geb_RubberWorm"))
			return;
		m_GebAgingTimer = new Timer(CALL_CATEGORY_SYSTEM);
		m_GebAgingTimer.Run(BAIT_AGING_TICK_SECS, this, "OnGebBaitAgingTick", null, true);
	}

	override void EEDelete(EntityAI parent) {
		super.EEDelete(parent);
		if (m_GebAgingTimer)
			m_GebAgingTimer.Stop();
	}

	void OnGebBaitAgingTick() {
		if (IsRuined())
			return;
		if (GebsfishIsBaitPreserved())
			return;

		float step = GetMaxHealth("", "") * (BAIT_AGING_TICK_SECS / BAIT_LIFETIME_SECS);
		DecreaseHealth("", "", step);
	}

	protected bool GebsfishIsBaitPreserved() {
		EntityAI parent = GetHierarchyParent();
		while (parent) {
			geb_WormContainer wormContainer;
			geb_BugContainer bugContainer;
			geb_Cooler_base cooler;
			if (Class.CastTo(wormContainer, parent) || Class.CastTo(bugContainer, parent) || Class.CastTo(cooler, parent))
				return true;
			parent = parent.GetHierarchyParent();
		}
		return false;
	}
}
