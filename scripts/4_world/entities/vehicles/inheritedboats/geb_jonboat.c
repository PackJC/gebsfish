/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// ---------------------------------------------------------------------------
// Jon boat lights: an LED flood bar on the bow, a red/green bow light, a white
// stern light on a pole and blue deck strips. They only work with a charged
// car battery in the battery box (vanilla CarBattery slot). Modelled on 1.30's
// MotorbikeScript, the one vanilla Transport with lights that isn't a car.
// ---------------------------------------------------------------------------

// The flood bar: one wide spot, LED white.
class GebJonBoatFloodProfile : VehicleLightProfileBase {
	void GebJonBoatFloodProfile() {
		m_DaylightVisible = true;
		m_SegregatedBrightness = 16;
		m_SegregatedRadius = 45;
		m_SegregatedAngle = 110;
		m_SegregatedColorRGB = Vector(0.92, 0.96, 1.0);
		m_AggregatedBrightness = 16;
		m_AggregatedRadius = 45;
		m_AggregatedAngle = 110;
		m_AggregatedColorRGB = Vector(0.92, 0.96, 1.0);
	}
}

// The three navigation lights: small 180 degree spots, so each one glows like a
// point light over a half sphere (VehicleLightsComponent only makes spots).
class GebJonBoatNavProfile : VehicleLightProfileBase {
	void GebJonBoatNavProfile(vector color, float brightness, float radius) {
		m_DaylightVisible = false;
		m_CastShadow = false;
		m_SegregatedBrightness = brightness;
		m_SegregatedRadius = radius;
		m_SegregatedAngle = 180;
		m_SegregatedColorRGB = color;
		m_AggregatedBrightness = brightness;
		m_AggregatedRadius = radius;
		m_AggregatedAngle = 180;
		m_AggregatedColorRGB = color;
	}
}

// VehicleLightBase ignores the profile's shadow/daylight flags; this applies them.
class GebJonBoatLightsComponent : VehicleLightsComponent {
	void GebJonBoatLightsComponent(notnull EntityAI parent) {
	}

	void GebApplyFlags(string name) {
		VehicleLightData data = m_LightMap.Get(name);
		if (data && data.m_Light && data.m_LightProfile) {
			data.m_Light.SetCastShadow(data.m_LightProfile.m_CastShadow);
			data.m_Light.SetVisibleDuringDaylight(data.m_LightProfile.m_DaylightVisible);
		}
	}
}

// Script class for the jon boat. The config's geb_jonboat_base inherits
// Boat_01_ColorBase, so without this the boat was running on the vanilla rubber
// boat's script class and inheriting its sounds wholesale.
//
// The colour variants (geb_jonboat_greenaluminum and friends) declare no script
// class of their own, so the engine walks up the config chain and lands here --
// one class covers every variant.
class geb_jonboat_base extends Boat_01_ColorBase {

	static const float GEB_BATTERY_DRAIN = 0.1;      // energy per second with the lights on (a full car battery holds 500)
	static const float GEB_BATTERY_RECHARGE = 0.15;  // per second while the motor runs (CarScript's alternator rate)
	static const int GEB_BATTERY_TICK_MS = 5000;     // server battery update interval
	static const string GEB_LIGHT_SELECTION = "geb_lights";   // hidden selection: every lens + the deck strips
	static const string GEB_MAT_OFF = "gebsfish\\data\\vehicles\\geb_jonboat_lights_off.rvmat";
	static const string GEB_MAT_OFF_DAMAGE = "gebsfish\\data\\vehicles\\geb_jonboat_lights_off_damage.rvmat";
	static const string GEB_MAT_OFF_DESTRUCT = "gebsfish\\data\\vehicles\\geb_jonboat_lights_off_destruct.rvmat";
	static const string GEB_MAT_ON = "gebsfish\\data\\vehicles\\geb_jonboat_lights_on.rvmat";
	static const string GEB_MAT_ON_DAMAGE = "gebsfish\\data\\vehicles\\geb_jonboat_lights_on_damage.rvmat";

	protected ref GebJonBoatLightsComponent m_GebLights;
	protected ref TStringArray m_GebLightNames;
	protected string m_GebLensMaterial;
	// The engine's own light flag (LightIsOn) only reaches the other machines
	// while someone drives the boat; switched from the battery box with nobody
	// aboard, everyone else kept seeing the lights on. So the server copies the
	// flag here and the boat's own sync carries it; clients draw from this.
	protected bool m_GebLightsOn;

	void geb_jonboat_base() {
		RegisterNetSyncVariableBool("m_GebLightsOn");
		m_GebLights = new GebJonBoatLightsComponent(this);
		m_GebLights.RegisterLight("Flood", new VehicleLightData(new GebJonBoatFloodProfile()));
		m_GebLights.RegisterLight("NavPort", new VehicleLightData(new GebJonBoatNavProfile(Vector(1.0, 0.06, 0.04), 1.4, 3.5)));
		m_GebLights.RegisterLight("NavStbd", new VehicleLightData(new GebJonBoatNavProfile(Vector(0.1, 1.0, 0.3), 1.4, 3.5)));
		m_GebLights.RegisterLight("NavStern", new VehicleLightData(new GebJonBoatNavProfile(Vector(1.0, 0.95, 0.85), 1.8, 5)));
		m_GebLightNames = new TStringArray;
		m_GebLightNames.Insert("Flood");
		m_GebLightNames.Insert("NavPort");
		m_GebLightNames.Insert("NavStbd");
		m_GebLightNames.Insert("NavStern");
	}

	override void EEInit() {
		super.EEInit();
		if (g_Game.IsServer()) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebBatteryTick, GEB_BATTERY_TICK_MS, true);
			// a lit boat after a restart: everyone sees it lit at once, not
			// from the first battery tick
			GebSyncLights();
		} else {
			UpdateLights();
		}
	}

	override void EEDelete(EntityAI parent) {
		super.EEDelete(parent);
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebBatteryTick);
		#ifndef SERVER
		foreach (string name : m_GebLightNames) {
			m_GebLights.DestroyLight(name);
		}
		#endif
	}

	override protected void SetActions() {
		super.SetActions();
		AddAction(GebActionSwitchBoatLights);
		AddAction(GebActionSwitchBoatLightsAtBattery);
	}

	// ---- refuelling: the 6 gal tank on the stern shelf
	// Vanilla ActionFillFuel measures from the tank's cap (memory point "refill",
	// inside the hull behind the gunwale) to the player's FEET, and Transport allows
	// 1.5 m. Beside a floating boat your feet are on the bottom, a metre or more
	// below the cap, so pouring only worked from a narrow strip on the tank's own
	// side in shallow water. 2.2 m reaches the cap from either side in waist-deep
	// water, from the shore or from inside the boat; you still have to look at the
	// tank (its refill View Geometry piece) for the action to show.
	static const float GEB_REFUEL_DISTANCE = 2.2;

	override float GetActionDistanceFuel() {
		return GEB_REFUEL_DISTANCE;
	}

	// ---- power: the car battery in the box
	// Holding a car battery and looking at the box offers vanilla's "Attach":
	// ActionAttachOnSelection reads the View Geometry piece it looks at, and the
	// box's is named geb_battery, not after the slot.
	override bool TranslateSlotFromSelection(string selection_name, out int slot_id) {
		if (selection_name == "geb_battery") {
			slot_id = InventorySlots.GetSlotIdFromString("CarBattery");
			return true;
		}
		return super.TranslateSlotFromSelection(selection_name, slot_id);
	}

	override EntityAI GetElectricitySourceDevice() {
		return FindAttachmentBySlotName("CarBattery");
	}

	override string GetElectricitySourceDeviceType() {
		return "CarBattery";
	}

	bool GebHasPower() {
		EntityAI battery = GetElectricitySourceDevice();
		if (!battery || battery.IsRuined() || !battery.GetCompEM()) {
			return false;
		}
		return battery.GetCompEM().GetEnergy() > 0;
	}

	// Lit, as this machine knows it: the engine's flag on the server, the synced copy elsewhere.
	bool GebLightsOn() {
		if (g_Game.IsServer())
			return LightIsOn();
		return m_GebLightsOn;
	}

	// Server: switch the lights and tell everyone.
	void GebSetLights(bool on) {
		if (on)
			LightOn();
		else
			LightOff();
		GebSyncLights();
	}

	// Server: copy the engine's flag into the synced one (after any switch,
	// whoever made it), and redraw.
	void GebSyncLights() {
		if (!g_Game.IsServer())
			return;
		bool on = LightIsOn();
		if (on != m_GebLightsOn) {
			m_GebLightsOn = on;
			SetSynchDirty();
		}
		UpdateLights();
	}

	override void OnUpdateLight() {
		super.OnUpdateLight();
		GebSyncLights();
	}

	// Called by the engine before LightOn() takes effect.
	override bool OnBeforeLightOn() {
		if (IsDamageDestroyed()) {
			return false;
		}
		return GebHasPower();
	}

	// Server: drain the battery while the lights are on, top it up while the
	// motor runs (like a car's alternator), switch off when it goes flat.
	protected void GebBatteryTick() {
		bool lightsOn = LightIsOn();
		EntityAI battery = GetElectricitySourceDevice();
		if (!battery || !battery.GetCompEM()) {
			if (lightsOn) {
				GebSetLights(false);
			}
			return;
		}

		float seconds = GEB_BATTERY_TICK_MS / 1000.0;
		if (EngineIsOn()) {
			battery.GetCompEM().AddEnergy(GEB_BATTERY_RECHARGE * seconds);
		} else if (lightsOn) {
			battery.GetCompEM().ConsumeEnergy(GEB_BATTERY_DRAIN * seconds);
		}

		if (lightsOn && (battery.IsRuined() || IsDamageDestroyed() || battery.GetCompEM().GetEnergy() <= 0)) {
			GebSetLights(false);
		}
		GebSyncLights();      // catches a switch made any other way
	}

	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		if (slot_name == "CarBattery") {
			UpdateLights();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name) {
		super.EEItemDetached(item, slot_name);
		if (slot_name == "CarBattery") {
			if (g_Game.IsServer()) {
				GebSetLights(false);
			}
			UpdateLights();
		}
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		if (zone == "") {
			if (g_Game.IsServer() && newLevel >= GameConstants.STATE_RUINED) {
				GebSetLights(false);
			}
			UpdateLights();
		}
	}

	override void OnVariablesSynchronized() {
		super.OnVariablesSynchronized();
		UpdateLights();
	}

	// Every machine rebuilds its look from GebLightsOn() whenever it changes.
	// The battery's charge is the server's business (OnBeforeLightOn and the
	// drain tick switch the lights off), so a client only checks that a
	// battery is in the box.
	override void UpdateLights(int new_gear = -1) {
		bool on = GebLightsOn() && GetElectricitySourceDevice() != null && !IsDamageDestroyed();
		#ifndef SERVER
		GebUpdateLightSources(on);
		#endif
		GebUpdateLensMaterial(on);
	}

	protected void GebUpdateLightSources(bool on) {
		if (on) {
			GebEnableLight("Flood", "light_flood", "light_flood_dir");
			GebEnableLight("NavPort", "light_nav_port", "light_nav_port_dir");
			GebEnableLight("NavStbd", "light_nav_stbd", "light_nav_stbd_dir");
			GebEnableLight("NavStern", "light_nav_stern", "light_nav_stern_dir");
		} else {
			foreach (string name : m_GebLightNames) {
				if (m_GebLights.LightExist(name)) {
					m_GebLights.DisableLight(name);
				}
			}
		}
	}

	protected void GebEnableLight(string name, string point, string dirPoint) {
		if (m_GebLights.LightExist(name) || !MemoryPointExists(point)) {
			return;
		}
		m_GebLights.EnableLight(name);
		m_GebLights.AttachLightOnPoint(name, point, dirPoint, VehicleLightMode.SEGREGATED);
		m_GebLights.GebApplyFlags(name);
	}

	// Lens look: glowing or dark, with the boat's worn/ruined copies.
	protected void GebUpdateLensMaterial(bool on) {
		int index = GetHiddenSelectionIndex(GEB_LIGHT_SELECTION);
		if (index < 0) {
			return;
		}
		int level = GetHealthLevel("");
		string material = GEB_MAT_OFF;
		if (level >= GameConstants.STATE_RUINED) {
			material = GEB_MAT_OFF_DESTRUCT;
		} else if (level >= GameConstants.STATE_DAMAGED) {
			material = GEB_MAT_OFF_DAMAGE;
			if (on) {
				material = GEB_MAT_ON_DAMAGE;
			}
		} else if (on) {
			material = GEB_MAT_ON;
		}
		if (material != m_GebLensMaterial) {
			m_GebLensMaterial = material;
			SetObjectMaterial(index, material);
		}
	}

	// Kill the rubber-boat engine shutdown sting. BoatScript hardcodes its
	// soundsets in its constructor (m_SoundEngineStop = "boat_01_engine_stop_SoundSet"
	// and friends), and every one of them is a Boat_01 asset, so the jon boat was
	// announcing itself as an assault boat every time the engine cut -- including
	// the moment you step out of the driver seat, which is what stops the engine.
	//
	// Blanking m_SoundEngineStop is NOT a safe way to do this: BoatScript.PlaySound
	// calls SEffectManager.PlaySoundCachedParams(soundset, ...) and then immediately
	// dereferences the result with SetAttachmentParent, so a soundset that fails to
	// resolve takes the client down. Suppressing the playback is the safe route.
	override protected void HandleEngineSound(EBoatEngineSoundState state) {
		if (state == EBoatEngineSoundState.STOP_OK || state == EBoatEngineSoundState.STOP_NO_FUEL) {
			// Skipping super entirely would silence the sting but also skip the
			// teardown it normally does on the way past, leaving the running
			// engine loop with nothing to stop it. So do the teardown here and
			// just never start the replacement sound.
			if (m_SoundEngineEffect) {
				m_SoundEngineEffectDeletion = m_SoundEngineEffect;
				m_SoundEngineEffectDeletion.SoundStop();
				m_SoundEngineEffect = null;
			}
			return;
		}

		super.HandleEngineSound(state);
	}
}

