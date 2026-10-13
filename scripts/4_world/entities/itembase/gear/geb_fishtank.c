/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The Fish Tank's hood light: a small, cheap point light just under the hood
// (memory point "light_pos"), a slightly cool aquarium white. No shadows, no
// flare. DayZ has no area lights, so this and the glowing strip on the hood's
// underside stand in for the rectangular tube.
class geb_FishTankLight extends PointLightBase {

	void geb_FishTankLight() {
		SetVisibleDuringDaylight(false);
		SetRadiusTo(1.4);
		SetBrightnessTo(1.1);
		SetCastShadow(false);
		SetFlareVisible(false);
		SetDiffuseColor(0.80, 0.90, 1.0);
		SetAmbientColor(0.80, 0.90, 1.0);
		FadeIn(0.3);
		SetFadeOutTime(0.2);
	}
}

// The Fish Tank (geb_FishTank in data/tools/config.cpp): a tabletop aquarium with
// five mini fish and a minnow school, a volcano bubbler, a sunken wreck, a treasure
// chest, a helmet diver, a starfish, a snail, a crab, swaying plants, a printed
// backdrop and a hang-on-back filter. A trader or admin item: there is no recipe
// and it is never world loot (typesxml.c writes it with nominal 0).
//
// Almost everything that moves in it runs by itself. Model.cfg fishtank drives the
// fish, the minnows, the plants, the snail and the crab from the engine's "time"
// animation source, so nothing here touches them. The chest lid is the exception:
// it is the user source "chest_lid", which this class opens and closes on a 12 s
// cycle so the bubble burst can come exactly when the lid is open (a time-driven
// lid and a script-started particle would drift apart). This class does placement (vanilla's hologram and deploy
// actions, like the drying rack) and the effects, on clients only, while the tank
// stands in the world on its own or on a Fish Tank Stand (geb_fishtankstand.c,
// slot GebFishTank):
//   - two looping bubble streams: the air stone's (ParticleList.GEB_BUBBLES_TANK,
//     memory point "bubbles") and the volcano's (GEB_BUBBLES_VOLCANO, "bubbles2");
//   - the hood light: geb_FishTankLight at "light_pos", and the strip on the
//     hood's underside (hidden selection 1, "light_strip") swapped to its glowing
//     material;
//   - the hang-on-back filter's water: a thin falling sheet from its spout lip
//     (GEB_FILTER_STREAM, "filter_spout") and the small splash where it lands
//     (GEB_FILTER_SPLASH, "filter_splash"), the tank's only splash;
//   - the chest: lid open over 3 s, a gush of bubbles (GEB_BUBBLES_CHEST,
//     "chest_bubbles") when fully open, closed again from 5 s to 8 s;
//   - a soft bubble hum and filter trickle, vanilla samples through the tank's own
//     sound sets (data/tools/config.cpp), audible only within a few metres.
// All of it stops when the tank is picked up, put somewhere else or deleted.
class geb_FishTank : ItemBase {

	static const int GEB_LIGHT_STRIP = 1;   // index in hiddenSelections
	static const string GEB_LIGHT_ON = "gebsfish\\data\\tools\\fishtank_light_on.rvmat";
	static const string GEB_LIGHT_OFF = "gebsfish\\data\\tools\\fishtank_light_off.rvmat";
	static const int GEB_CHEST_CYCLE = 12;  // seconds; the chest ticks once a second

	// Client only: the running effects, null while there are none.
	protected ParticleSource m_GebBubbles;
	protected ParticleSource m_GebVolcano;
	protected ParticleSource m_GebFilterStream;
	protected ParticleSource m_GebFilterSplash;
	protected geb_FishTankLight m_GebLight;
	protected EffectSound m_GebHum;
	protected EffectSound m_GebTrickle;
	protected int m_GebChestStep = -1;      // -1 while the chest cycle is off

	override void EEInit() {
		super.EEInit();
		// A tank streamed in from the network may get its inventory location
		// (and the placement hologram its hologram flag) just after EEInit, so
		// look a moment later.
		if (!g_Game.IsDedicatedServer())
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebUpdateEffects, 250, false);
	}

	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc) {
		super.EEItemLocationChanged(oldLoc, newLoc);
		// Start over at the new spot: from the ground onto a stand the tank's
		// transform comes from the stand's proxy instead.
		GebStopEffects();
		GebUpdateEffects();
	}

	override void EEDelete(EntityAI parent) {
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebUpdateEffects);
		GebStopEffects();
		super.EEDelete(parent);
	}

	// One step of the chest's 12 s cycle: 0 open (the lid takes 3 s, config
	// animPeriod), 3 the burst, 5 close (3 s), then shut until the next cycle.
	protected void GebChestTick() {
		int step = m_GebChestStep % GEB_CHEST_CYCLE;
		if (step == 0)
			SetAnimationPhase("chest_lid", 1);
		else if (step == 3)
			ParticleManager.GetInstance().PlayOnObject(ParticleList.GEB_BUBBLES_CHEST, this, GetMemoryPointPos("chest_bubbles"), "0 0 0", true);
		else if (step == 5)
			SetAnimationPhase("chest_lid", 0);
		m_GebChestStep++;
	}

	// Effects while the tank stands loose in the world or on a stand that does.
	// Not in hands, in a vehicle or anywhere else, and not on the placement
	// hologram.
	protected void GebUpdateEffects() {
		if (g_Game.IsDedicatedServer())
			return;
		bool standing = !IsSetForDeletion() && !IsHologram() && GebStandingInWorld();
		if (!standing) {
			GebStopEffects();
			return;
		}
		// World rotation, so the bubbles rise straight up even on a slope.
		if (!m_GebBubbles)
			m_GebBubbles = GebPlayBubbles(ParticleList.GEB_BUBBLES_TANK, "bubbles");
		if (!m_GebVolcano)
			m_GebVolcano = GebPlayBubbles(ParticleList.GEB_BUBBLES_VOLCANO, "bubbles2");
		if (!m_GebFilterStream)
			m_GebFilterStream = GebPlayBubbles(ParticleList.GEB_FILTER_STREAM, "filter_spout");
		if (!m_GebFilterSplash)
			m_GebFilterSplash = GebPlayBubbles(ParticleList.GEB_FILTER_SPLASH, "filter_splash");
		if (!m_GebLight) {
			m_GebLight = geb_FishTankLight.Cast(ScriptedLightBase.CreateLight(geb_FishTankLight, "0 0 0"));
			if (m_GebLight)
				m_GebLight.AttachOnMemoryPoint(this, "light_pos");
			SetObjectMaterial(GEB_LIGHT_STRIP, GEB_LIGHT_ON);
		}
		if (!m_GebHum)
			m_GebHum = SEffectManager.PlaySoundOnObject("geb_FishTankHum_SoundSet", this, 1.0, 0.5, true);
		if (!m_GebTrickle)
			m_GebTrickle = SEffectManager.PlaySoundOnObject("geb_FishTankTrickle_SoundSet", this, 1.0, 0.5, true);
		if (m_GebChestStep < 0) {
			m_GebChestStep = 0;
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebChestTick, 1000, true);
		}
	}

	protected ParticleSource GebPlayBubbles(int particleId, string memoryPoint) {
		ParticleSource p = ParticleManager.GetInstance().PlayOnObject(particleId, this, GetMemoryPointPos(memoryPoint), "0 0 0", true);
		if (p)
			p.SetParticleAutoDestroyFlags(ParticleAutoDestroyFlags.ON_STOP);
		return p;
	}

	// Loose on the ground, or attached to a Fish Tank Stand that is.
	protected bool GebStandingInWorld() {
		EntityAI parent = GetHierarchyParent();
		if (!parent)
			return true;
		return parent.IsInherited(geb_FishTankStand) && !parent.GetHierarchyParent();
	}

	protected void GebStopEffects() {
		if (m_GebBubbles) {
			m_GebBubbles.Stop();
			m_GebBubbles = null;
		}
		if (m_GebVolcano) {
			m_GebVolcano.Stop();
			m_GebVolcano = null;
		}
		if (m_GebFilterStream) {
			m_GebFilterStream.Stop();
			m_GebFilterStream = null;
		}
		if (m_GebFilterSplash) {
			m_GebFilterSplash.Stop();
			m_GebFilterSplash = null;
		}
		if (m_GebHum) {
			m_GebHum.SoundStop();
			SEffectManager.DestroyEffect(m_GebHum);
			m_GebHum = null;
		}
		if (m_GebTrickle) {
			m_GebTrickle.SoundStop();
			SEffectManager.DestroyEffect(m_GebTrickle);
			m_GebTrickle = null;
		}
		if (m_GebChestStep >= 0) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebChestTick);
			m_GebChestStep = -1;
			if (!g_Game.IsDedicatedServer())
				SetAnimationPhase("chest_lid", 0);
		}
		if (m_GebLight) {
			m_GebLight.FadeOut();
			m_GebLight = null;
			if (!g_Game.IsDedicatedServer())
				SetObjectMaterial(GEB_LIGHT_STRIP, GEB_LIGHT_OFF);
		}
	}

	// ------------------------------------------------------------ placement

	// ItemBase.IsDeployable() is false by default, so without this the
	// hold-to-place hologram never appears.
	override bool IsDeployable() {
		return true;
	}

	override void SetActions() {
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}
