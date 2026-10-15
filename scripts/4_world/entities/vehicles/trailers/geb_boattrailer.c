/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// ---------------------------------------------------------------------------
// Boat trailer: hitch it to a car, tow it, back it up. It breaks off when it
// jackknifes, when the car crashes or rolls, or when the car is gone. It
// carries a boat (the jon boat or vanilla's rubber boat): winch one on at the
// bow roller, tow it, launch it. A hitched trailer stays hitched through a
// restart, and the server decides which cars may tow (general.json).
//
// It is a vehicle of its own: a car with no engine and no seats that rolls
// freely on two Gunter 2 wheels (Hatchback_02_Wheel, in its two wheel slots)
// and, parked, rests its tongue on its jack foot (a collision box a little
// above the ground when the trailer is level).
// Hitched, a physics ball joint holds its coupler to the car's hitch ball and
// physics does the rest: it follows, turns, backs up and bounces like the car
// does. This is how LM's semi trailer works too (two physics vehicles,
// coupled), except that a vanilla car has no fifth-wheel slot in its
// collision, so the coupling is a joint. The joint is the server's: the
// server simulates the trailer (nobody drives it) and everyone sees it move
// through the network. (A client joint of its own tied the driver's car to its
// copy of the trailer, which a client doesn't simulate, and jacked the car's
// rear up, 2026-10-14.) The joint keeps the two from colliding.
//
// Script still decides when it breaks off (jackknife, crash, rolled or
// wrecked car, car gone, coupler pulled off the ball), plays the sounds, and
// lights the tail lights with the car's.
//
// The boat is the real boat, so its colour, deck gear, fuel, cargo and
// lights travel with it. On the trailer its physics body is made kinematic
// and it is posed from the trailer every frame: on the server, which syncs it
// to everyone, and on each client from its own copy of the trailer, so it
// never slides about on the bunks. Winching it on slides it from where it lies
// onto the bunks; launching slides it back off the rear and gives it its
// physics back, so it floats off (or settles on dry ground). Nobody can get in
// or push it while it is on the trailer. While it is on (or sliding) it's on
// the small-item layer, which vehicles pass through, so it never shoves the
// trailer under it. A trailer saved with a boat on it finds the boat again
// after a restart (by its persistent ID).
// ---------------------------------------------------------------------------
class geb_BoatTrailer extends CarScript {
	static const float GEB_WHEEL_RADIUS = 0.304;     // Hatchback_02_Wheel
	static const float GEB_TRACK = 0.88;             // wheel centre from the middle
	static const float GEB_COUPLER_Y = 0.15;         // coupler cup above the axle (the model's "coupler" point)
	static const float GEB_COUPLER_Z = 4.2;          // and ahead of it
	static const float GEB_JACK_TRAVEL = 0.22;       // the jack winds up this far when hitched (Model.cfg)
	// Ball above the ground under the car: 0.454 would keep the trailer level; a
	// little higher lifts the jack foot (4 cm over level ground, tools/trailer
	// JACK_LIFT) about 8 cm clear while towing.
	static const float GEB_HITCH_HEIGHT = 0.50;
	static const float GEB_HITCH_BEHIND = 0.25;      // ball behind the car's geometry
	// Hitching is zone to zone (Cole, 2026-10-13: "the tow point should be the whole
	// bumper ... and the tow point for the trailer should be the whole front"): the
	// car's back end, its full width, to the trailer's front, the tongue and the
	// A-frame back to the cross-member. Hitched, it still swings onto the ball in
	// the middle of the car's back end.
	static const float GEB_HITCH_REACH = 2.0;        // gap between the two zones, to hitch
	static const float GEB_AFRAME_Z = 2.58;          // the A-frame meets the frame's front cross-member here
	static const float GEB_AFRAME_X = 0.62;          // and is this wide there
	static const float GEB_HITCH_MAX_ANGLE = 65.0;   // car to trailer once it swings onto the ball (it breaks off past GEB_JACKKNIFE)
	static const float GEB_PLAYER_REACH = 3.5;       // player to coupler
	static const float GEB_STOPPED = 1.0;            // m/s: the car must be this slow to hitch, unhitch, winch or launch
	// TEMPORARY (2026-10-13, Cole: "if you back into it it will auto connect"):
	// a parked trailer hitches itself to a car backed up to it
	static const float GEB_AUTO_REACH = 2.0;         // the zones' gap (GEB_HITCH_REACH), backing in
	static const float GEB_AUTO_SPEED = 4.0;         // m/s, at most
	static const float GEB_AUTO_REARM = 3.5;         // after letting go, that car's back end must first move this far off
	static const int GEB_AUTO_SCAN_MS = 250;
	static const float GEB_JACKKNIFE = 80.0;         // degrees between car and trailer: it breaks off
	static const float GEB_CRASH_DV = 6.0;           // m/s the car's speed changes within 0.15 s: a crash (about 4 g)
	static const float GEB_MIN_CAR_UP = 0.4;         // the car's up axis, upward part: below this it has rolled
	static const float GEB_BREAK_GAP = 1.0;          // m between the coupler and the ball: pulled apart
	static const float GEB_SNAP_MAX = 6.0;           // m: a client puts its trailer copy on its own car's ball when it is this close (GebSnapToBall)
	static const string GEB_MAT = "gebsfish\\data\\vehicles\\boattrailer";
	// vanilla sounds: the wheel clunks for hitching and unhitching, the metal
	// crash for breaking loose, the combination lock's dial click as the winch
	// ratchet, the metal plank's thud as the boat settles on the bunks
	static const string GEB_SND_HITCH = "Offroad_Wheel_Attach_SoundSet";
	static const string GEB_SND_UNHITCH = "Offroad_Wheel_Remove_SoundSet";
	static const string GEB_SND_BREAK = "Crash_MetalPlank_SoundSet";
	static const string GEB_SND_RATCHET = "combinationlock_changedial_SoundSet";
	static const string GEB_SND_SETTLE = "putDown_MetalPlank_SoundSet";
	static const float GEB_RATCHET_EVERY = 0.25;     // seconds between winch clicks

	// The boats it carries, each on a seat of its own: where its origin sits in
	// the trailer's model space (turned to face the coupler: both have their
	// bow at their -Z), and its bow in its own model space, for winching on.
	//  - the jon boat (geb_jonboat_base): flat bottom 4 cm above its origin on
	//    the bunk tops (0.40), bow against the bow roller, motor past the rear;
	//  - vanilla's rubber boat (Boat_01_ColorBase; the jon boat is built on it,
	//    so it is checked first): its floor 5 cm above its origin where the
	//    bunks run, keel just over the keel roller, bow tube at the bow roller,
	//    side tubes over the fenders.
	static const float GEB_JON_SEAT_Y = 0.359;
	static const float GEB_JON_SEAT_Z = 0.32;
	protected const vector GEB_JON_BOW = "0 0.45 -2.75";
	static const float GEB_RIB_SEAT_Y = 0.35;
	static const float GEB_RIB_SEAT_Z = 0.75;
	protected const vector GEB_RIB_BOW = "0 0.45 -2.25";
	protected const vector GEB_ROLLER = "0 0.86 3.19";       // bow roller, trailer model space
	static const float GEB_WINCH_REACH = 4.0;        // player to the bow roller
	static const float GEB_BOAT_REACH = 8.0;         // the boat's bow to the bow roller, to winch it on (the strap's length:
	                                                 // a boat floating just behind the trailer is in reach)
	static const float GEB_BOAT_ALIGN = 100.0;       // degrees between boat and trailer, to winch it on (side-on is fine;
	                                                 // pointing away is not)
	static const float GEB_BOAT_STILL = 2.0;         // m/s: the boat must be this slow to winch it on
	static const float GEB_WINCH_SPEED = 0.6;        // m/s, winching on
	static const float GEB_LAUNCH_BACK = 5.4;        // launching slides it back this far: clear of the trailer
	static const float GEB_LAUNCH_SPEED = 1.5;       // m/s
	static const float GEB_BOAT_SYNC = 0.2;          // seconds between the server's boat syncs while it moves

	static const int GEB_BOAT_NONE = 0;
	static const int GEB_BOAT_LOADING = 1;
	static const int GEB_BOAT_LOADED = 2;
	static const int GEB_BOAT_LAUNCHING = 3;
	static const int GEB_STORE_VERSION = 2;          // 1: the boat; 2: and the car it was hitched to

	// Trailers hitched on this machine, so a car tows one at most; trailers
	// with a boat on (or sliding on or off), so a boat rides on one at most.
	protected static ref array<geb_BoatTrailer> s_GebHitched = new array<geb_BoatTrailer>();
	protected static ref array<geb_BoatTrailer> s_GebCarriers = new array<geb_BoatTrailer>();

	// synced
	protected bool m_GebHitched;
	protected int m_GebCarLow;
	protected int m_GebCarHigh;
	protected float m_GebBallX;           // the ball, in the car's model space
	protected float m_GebBallY;
	protected float m_GebBallZ;
	protected bool m_GebBrokeLoose;       // it was last let go by breaking off, not by hand
	protected int m_GebBoatLow;
	protected int m_GebBoatHigh;
	protected int m_GebBoatState;         // GEB_BOAT_*
	protected float m_GebBoatLen;         // seconds the current slide takes

	// each machine's own
	protected CarScript m_GebCar;
	protected CarScript m_GebAutoBlock;   // TEMPORARY: the car it last let go of (no instant re-hitch)
	protected bool m_GebWasHitched;
	protected PhysicsBallSocketJoint m_GebJoint;    // this machine's coupler-to-ball joint (an engine handle:
	                                                // never compared with null, m_GebJoined says if it is there)
	protected bool m_GebJoined;
	protected CarScript m_GebJointCar;    // the car it joins (null: gone, and the engine dropped the joint)
	protected float m_GebTowLogClock;     // TEMPORARY: the once-a-second tow log
	protected float m_GebSnapGap;         // client: how far its copy was off the ball before this frame's snap
	protected bool m_GebTicking;          // wants a tick every frame
	protected bool m_GebInQueue;          // in the post-update queue
	protected vector m_GebVelRef;         // server: the car's velocity up to 0.15 s ago (crash test)
	protected float m_GebVelClock;
	protected bool m_GebLoaded;
	protected int m_GebLightState;        // 0 off, 1 tail, 2 brake
	protected int m_GebLightLevel;        // the health level the lens material was picked for
	protected bool m_GebSynced;           // a client has had its first sync (a trailer streaming in makes no sound)
	protected float m_GebRatchetClock;
	protected string m_GebLensMaterial;

	protected BoatScript m_GebBoat;
	protected int m_GebBoatSeen;          // the boat state this machine last acted on
	protected int m_GebBoatSeenLow;
	protected int m_GebBoatSeenHigh;
	protected float m_GebBoatT;           // seconds into the current slide
	protected vector m_GebBoatFrom[4];    // where a winch-on starts, trailer model space
	protected bool m_GebBoatFromSet;
	protected bool m_GebBoatFrozen;       // its body is kinematic on this machine
	protected bool m_GebBoatSmall;        // it is on the small-item layer on this machine
	protected int m_GebBoatLayer;         // its own layer meanwhile
	protected float m_GebBoatSyncClock;
	protected vector m_GebParkedAt;       // server, parked with a boat on: where the boat was last posed
	protected vector m_GebParkedTurn;
	protected bool m_GebParkedMoved;
	protected bool m_GebRelink;           // server, after a restart: find the boat it was saved with
	protected int m_GebPid1;
	protected int m_GebPid2;
	protected int m_GebPid3;
	protected int m_GebPid4;
	protected bool m_GebRelinkCar;        // server, after a restart: hitch the car it was saved with
	protected int m_GebCarPid1;
	protected int m_GebCarPid2;
	protected int m_GebCarPid3;
	protected int m_GebCarPid4;

	void geb_BoatTrailer() {
		m_dmgContactCoef = 0.02;          // a towed trailer clips kerbs and posts: it takes less than a car
		RegisterNetSyncVariableBool("m_GebHitched");
		RegisterNetSyncVariableInt("m_GebCarLow", int.MIN, int.MAX);
		RegisterNetSyncVariableInt("m_GebCarHigh", int.MIN, int.MAX);
		RegisterNetSyncVariableFloat("m_GebBallX", -20, 20, 3);
		RegisterNetSyncVariableFloat("m_GebBallY", -20, 20, 3);
		RegisterNetSyncVariableFloat("m_GebBallZ", -20, 20, 3);
		RegisterNetSyncVariableBool("m_GebBrokeLoose");
		RegisterNetSyncVariableInt("m_GebBoatLow", int.MIN, int.MAX);
		RegisterNetSyncVariableInt("m_GebBoatHigh", int.MIN, int.MAX);
		RegisterNetSyncVariableInt("m_GebBoatState", 0, 3);
		RegisterNetSyncVariableFloat("m_GebBoatLen", 0, 60, 2);
	}

	void ~geb_BoatTrailer() {
		if (m_GebInQueue && g_Game)
			g_Game.GetPostUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebOnPostUpdate);
		int at;
		if (s_GebHitched) {
			at = s_GebHitched.Find(this);
			if (at != -1)
				s_GebHitched.Remove(at);
		}
		if (s_GebCarriers) {
			at = s_GebCarriers.Find(this);
			if (at != -1)
				s_GebCarriers.Remove(at);
		}
	}

	// Not a car's own (getting in, doors, lights, horn): pushing it by hand,
	// and the trailer's.
	override void SetActions() {
		AddAction(ActionPushCar);
		AddAction(GebActionHitchTrailer);
		AddAction(GebActionUnhitchTrailer);
		AddAction(GebActionWinchBoatOn);
		AddAction(GebActionLaunchBoat);
	}

	// Never carried: it stands on its wheels.
	override bool CanPutInCargo(EntityAI parent) {
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent) {
		return false;
	}

	// None of a car's: no driver to brake for, no battery, no engine to drown.
	// Vanilla's damages the "Engine" zone once the car's engine point is under
	// water, and a trailer backed into a lake has no such zone: a script
	// exception every frame (1.8 million in one session, 2026-10-14).
	override void OnUpdate(float dt) {
	}

	// The wheels stay on while it is hitched.
	override bool CanReleaseAttachment(EntityAI attachment) {
		if (m_GebHitched)
			return false;
		return super.CanReleaseAttachment(attachment);
	}

	bool GebIsHitched() {
		return m_GebHitched;
	}

	// Both wheels on.
	bool GebHasWheels() {
		return GebWheelIn("GebTrailerWheel_L") && GebWheelIn("GebTrailerWheel_R");
	}

	protected bool GebWheelIn(string slot) {
		return GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString(slot)) != null;
	}

	// ------------------------------------------------------------ spawning, saving and loading

	override void EEInit() {
		super.EEInit();
		// A new trailer comes with its two wheels (economy, admin tool or debug
		// spawn alike). Checked a moment later, after a stored trailer has loaded:
		// one whose wheels a player took off stays that way.
		if (g_Game.IsServer()) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebFitNewWheels, 1000, false);
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebAutoHitchScan, GEB_AUTO_SCAN_MS, true);    // TEMPORARY
		}
	}

	// After the item's own data: a version, whether a boat is on it and the
	// boat's persistent ID, then whether it is hitched and the car's.
	override void OnStoreSave(ParamsWriteContext ctx) {
		super.OnStoreSave(ctx);
		bool carrying = m_GebBoat != null && (m_GebBoatState == GEB_BOAT_LOADED || m_GebBoatState == GEB_BOAT_LOADING);
		int b1 = 0;
		int b2 = 0;
		int b3 = 0;
		int b4 = 0;
		if (carrying)
			m_GebBoat.GetPersistentID(b1, b2, b3, b4);
		ctx.Write(GEB_STORE_VERSION);
		ctx.Write(carrying);
		ctx.Write(b1);
		ctx.Write(b2);
		ctx.Write(b3);
		ctx.Write(b4);
		bool hitched = m_GebHitched && m_GebCar != null;
		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		int c4 = 0;
		if (hitched)
			m_GebCar.GetPersistentID(c1, c2, c3, c4);
		ctx.Write(hitched);
		ctx.Write(c1);
		ctx.Write(c2);
		ctx.Write(c3);
		ctx.Write(c4);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version) {
		m_GebLoaded = true;
		if (!super.OnStoreLoad(ctx, version))
			return false;
		// a trailer saved before the boat data existed has none: it carried nothing
		int ours;
		bool carrying;
		if (!ctx.Read(ours) || !ctx.Read(carrying))
			return true;
		if (!ctx.Read(m_GebPid1) || !ctx.Read(m_GebPid2) || !ctx.Read(m_GebPid3) || !ctx.Read(m_GebPid4))
			return true;
		m_GebRelink = carrying;
		if (ours < 2)
			return true;
		bool hitched;
		if (!ctx.Read(hitched) || !ctx.Read(m_GebCarPid1) || !ctx.Read(m_GebCarPid2) || !ctx.Read(m_GebCarPid3) || !ctx.Read(m_GebCarPid4))
			return true;
		m_GebRelinkCar = hitched;
		return true;
	}

	// After a restart: its boat (saved on it) goes back on it a moment later,
	// and so does the car it was hitched to, if that car is still by the
	// coupler and may still tow; otherwise it is parked where it stands.
	override void EEOnAfterLoad() {
		super.EEOnAfterLoad();
		if (!g_Game.IsServer())
			return;
		if (m_GebRelink)
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebRelinkBoat, 2000, false);
		if (m_GebRelinkCar)
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebRelinkCar, 2500, false);
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebWheelProbe, 4000, false, 0);    // TEMPORARY
	}

	// Server, a moment after a restart.
	protected void GebRelinkCar() {
		m_GebRelinkCar = false;
		if (m_GebHitched)
			return;
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(GebCouplerWS(), 12, near, null);
		foreach (Object o : near) {
			CarScript hauler = CarScript.Cast(o);
			if (!hauler || hauler.IsDamageDestroyed() || GebIsTowing(hauler) || !GebCanTow(hauler))
				continue;
			int c1;
			int c2;
			int c3;
			int c4;
			hauler.GetPersistentID(c1, c2, c3, c4);
			if (c1 == m_GebCarPid1 && c2 == m_GebCarPid2 && c3 == m_GebCarPid3 && c4 == m_GebCarPid4) {
				GebHitch(hauler);
				if (m_GebHitched)
					return;
			}
		}
	}

	protected void GebFitNewWheels() {
		if (m_GebLoaded || IsDamageDestroyed())
			return;
		if (!GebWheelIn("GebTrailerWheel_L"))
			GetInventory().CreateAttachmentEx("Hatchback_02_Wheel", InventorySlots.GetSlotIdFromString("GebTrailerWheel_L"));
		if (!GebWheelIn("GebTrailerWheel_R"))
			GetInventory().CreateAttachmentEx("Hatchback_02_Wheel", InventorySlots.GetSlotIdFromString("GebTrailerWheel_R"));
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebWheelProbe, 3000, false, 0);    // TEMPORARY
	}

	// TEMPORARY (2026-10-14: the engine had linked no tyre, "present 0", as the
	// model's fire geometry had no wheel proxies): server, a few seconds after
	// spawn or load, log the wheels.
	protected void GebWheelProbe(int pass) {
		Print("[gebsfish trailer check] wheel probe " + pass.ToString() + ": " + GebWheelDiag());
	}

	override void EEKilled(Object killer) {
		super.EEKilled(killer);
		if (g_Game.IsServer() && m_GebHitched)
			GebBreakOff(false);
	}

	// A trailer that goes away drops its boat: it gets its physics back.
	override void EEDelete(EntityAI parent) {
		super.EEDelete(parent);
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebAutoHitchScan);    // TEMPORARY
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebWheelProbe);       // TEMPORARY
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebLaunchLog);        // TEMPORARY
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebResyncBoat);
		GebDropJoint();
		m_GebTicking = false;
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebLeaveQueue);
		if (m_GebInQueue) {
			g_Game.GetPostUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebOnPostUpdate);
			m_GebInQueue = false;
		}
		BoatScript boat = GebResolveBoat();
		if (boat && m_GebBoatState != GEB_BOAT_NONE) {
			GebUnfreezeBoat(boat);
			if (g_Game.IsServer()) {
				boat.SetAnimationPhase("FoldingEngine", 0);
				GebResyncBoat(boat);
			}
		}
	}

	// TEMPORARY (2026-10-13): Cole gets no hitch or winch prompt at all. Logs what
	// the prompts see to the client script log ("[gebsfish trailer check]"), each
	// line only when it changes. Remove once found (and the calls in
	// geb_actiontrailerhitch.c marked TEMPORARY).
	protected static ref map<string, string> s_GebDiagLast;

	static void GebDiag(string key, string line) {
		if (!s_GebDiagLast)
			s_GebDiagLast = new map<string, string>;
		string last;
		if (s_GebDiagLast.Find(key, last) && last == line)
			return;
		s_GebDiagLast.Set(key, line);
		Print("[gebsfish trailer check] " + key + ": " + line);
	}

	static string GebR(float v, float step) {
		return (Math.Round(v / step) * step).ToString();
	}

	// TEMPORARY (2026-10-14, Cole: "still in the ground, it drags worse, the
	// wheels do not spin"): the engine's own view of each wheel, and how high the
	// axle stands over the ground (0.30 on its tyres, 0.14 on its bare hubs).
	string GebWheelDiag() {
		vector pos = GetPosition();
		float ground = g_Game.SurfaceRoadY3D(pos[0], pos[1] + 2.0, pos[2], RoadSurfaceDetection.UNDER);
		string s = "axle over ground " + GebR(pos[1] - ground, 0.01) + " m, mass " + GebR(dBodyGetMass(this), 1) + ", wheels " + WheelCount().ToString() + " (present " + WheelCountPresent().ToString() + ")";
		for (int i = 0; i < WheelCount(); i++) {
			string what = "none";
			EntityAI wheel = WheelGetEntity(i);
			if (wheel)
				what = wheel.GetType();
			vector hub = WheelGetPositionLS(i);
			s += "; #" + i.ToString() + " " + what + " at " + GebR(hub[0], 0.01) + " " + GebR(hub[1], 0.01) + " " + GebR(hub[2], 0.01) + ", contact " + WheelHasContact(i).ToString() + ", locked " + WheelIsLocked(i).ToString() + ", spin " + GebR(WheelGetAngularVelocity(i), 0.1);
		}
		return s;
	}

	string GebDiagHitch(PlayerBase player) {
		string s = "turn " + GebTurn().ToString() + ", hitched " + m_GebHitched.ToString() + ", wheels " + GebHasWheels().ToString() + ", player to coupler " + GebR(vector.Distance(player.GetPosition(), GebCouplerWS()), 0.5) + " m | " + GebWheelDiag();
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(GebCouplerWS(), 15, near, null);
		int cars = 0;
		foreach (Object o : near) {
			CarScript car = CarScript.Cast(o);
			if (!car || geb_BoatTrailer.Cast(car))
				continue;
			cars++;
			s += " | " + car.GetType() + " may tow " + GebCanTow(car).ToString() + ", towing " + GebIsTowing(car).ToString() + ", speed " + GebR(GetVelocity(car).Length(), 0.5);
			vector ball;
			if (!GebHitchPoint(car, ball)) {
				s += ", NO HITCH POINT";
				continue;
			}
			vector ballWS = car.ModelToWorld(ball);
			vector along = ballWS - GetPosition();
			along[1] = 0;
			along.Normalize();
			float dot = vector.Dot(along, GebCarForward(car, ball));
			vector onTrailer = GebD(WorldToModel(ballWS));    // p3d terms: z 4.2 = the coupler (tongue tip), 0 = the axle, -1.7 = the back end
			s += ", back end to front " + GebR(GebZoneGap(car), 0.25) + " m, ball to coupler " + GebR(vector.Distance(ballWS, GebCouplerWS()), 0.5) + " m (on the trailer at z " + GebR(onTrailer[2], 0.5) + ", x " + GebR(onTrailer[0], 0.5) + "), angle " + GebR(Math.Acos(Math.Clamp(dot, -1, 1)) * Math.RAD2DEG, 5) + " deg, fits " + GebFits(car).ToString();
		}
		if (cars == 0)
			s += " | no car within 15 m of the coupler";
		return s;
	}

	string GebDiagWinch(PlayerBase player) {
		vector roller = GebRollerWS();
		string s = "boat state " + m_GebBoatState.ToString() + ", player to roller " + GebR(vector.Distance(player.GetPosition(), roller), 0.5) + " m, car stopped " + GebCarStopped().ToString();
		vector along = GebForward();
		along[1] = 0;
		along.Normalize();
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(roller, 15, near, null);
		int boats = 0;
		foreach (Object o : near) {
			BoatScript boat = BoatScript.Cast(o);
			if (!boat)
				continue;
			boats++;
			vector bowward = boat.GetDirection() * (-GebTurn());
			bowward[1] = 0;
			bowward.Normalize();
			float dot = vector.Dot(bowward, along);
			s += " | " + boat.GetType() + " carries " + GebCarries(boat).ToString() + ", crew " + GebHasCrew(boat).ToString() + ", speed " + GebR(GetVelocity(boat).Length(), 0.5) + ", bow to roller " + GebR(vector.Distance(boat.ModelToWorld(GebD(GebBowOf(boat))), roller), 0.5) + " m, angle " + GebR(Math.Acos(Math.Clamp(dot, -1, 1)) * Math.RAD2DEG, 5) + " deg";
		}
		if (boats == 0)
			s += " | no boat within 15 m of the roller";
		return s;
	}

	static string GebDiagFromCar(CarScript car, PlayerBase player) {
		string s = car.GetType();
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(car.GetPosition(), 20, near, null);
		int trailers = 0;
		foreach (Object o : near) {
			geb_BoatTrailer t = geb_BoatTrailer.Cast(o);
			if (!t)
				continue;
			trailers++;
			s += " | trailer: " + t.GebDiagHitch(player);
		}
		if (trailers == 0)
			s += " | no trailer within 20 m";
		return s;
	}

	// TEMPORARY (2026-10-13): server, four times a second while parked: a car
	// backed up with its back end at the trailer's front (GEB_AUTO_REACH), slow,
	// lined up and allowed to tow is hitched. The car it last let go of must
	// first move off.
	protected void GebAutoHitchScan() {
		if (m_GebHitched || IsDamageDestroyed() || !GebHasWheels() || m_GebRelinkCar)
			return;
		vector coupler = GebCouplerWS();
		if (m_GebAutoBlock) {
			vector blockBall;
			if (m_GebAutoBlock.IsDamageDestroyed() || !GebHitchPoint(m_GebAutoBlock, blockBall) || GebZoneGap(m_GebAutoBlock) > GEB_AUTO_REARM)
				m_GebAutoBlock = null;
		}
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(coupler, 15, near, null);
		foreach (Object o : near) {
			CarScript hauler = CarScript.Cast(o);
			if (!hauler || hauler == m_GebAutoBlock)
				continue;
			if (GebFitsWithin(hauler, GEB_AUTO_REACH, GEB_AUTO_SPEED)) {
				GebHitch(hauler);
				return;
			}
		}
	}

	// ------------------------------------------------------------ hitching

	// ------------------------------------------------------------ the p3d's numbers in the game
	// Every trailer and boat number in this file was read off the p3d files
	// (coupler +4.2 on z, the boats' bows on -z). The game's model space is
	// the p3d's turned 180 degrees about up: Cole backed every car to the
	// tongue and the log put it at z -4 (2026-10-13). So the turn is measured
	// once from the trailer's own "coupler" memory point (+1 as in the p3d,
	// -1 turned), and the numbers go through GebD on their way in.
	protected float m_GebTurn;            // 0 until measured
	protected float GebTurn() {
		if (m_GebTurn == 0) {
			m_GebTurn = 1;
			if (MemoryPointExists("coupler")) {
				vector c = GetMemoryPointPos("coupler");
				if (c[2] < 0)
					m_GebTurn = -1;
			}
		}
		return m_GebTurn;
	}

	// A point (or direction) in p3d terms, in the game's model space; it works both ways.
	vector GebD(vector v) {
		float t = GebTurn();
		return Vector(v[0] * t, v[1], v[2] * t);
	}

	// The way the tongue points, in the world, flat or not.
	vector GebForward() {
		return GetDirection() * GebTurn();
	}

	// The coupler cup, in the world.
	vector GebCouplerWS() {
		return ModelToWorld(GebD(Vector(0, GEB_COUPLER_Y, GEB_COUPLER_Z)));
	}

	bool GebAtCoupler(PlayerBase player) {
		return vector.Distance(player.GetPosition(), GebCouplerWS()) <= GEB_PLAYER_REACH;
	}

	// Not hitched, or the car pulling it stands still.
	bool GebCarStopped() {
		CarScript hauler = GebGetCar();
		return !hauler || GetVelocity(hauler).Length() <= GEB_STOPPED;
	}

	// Where a car's hitch ball is, in its model space: in the middle, just
	// behind its geometry, at the height that keeps the trailer level. The back
	// is the end with the rear damage zone, or else the end away from the
	// headlights (the M3S cargo and covered trucks have no rear zone, and the
	// cargo one no engine point either), or else away from the engine. The
	// ground is where its tyres stand. Checked on every vanilla car: the ball
	// ends up 0.17-0.29 m behind the bumper of the cars, about 0.3 m behind and
	// just under the M3S's higher bumper.
	static bool GebHitchPoint(CarScript hauler, out vector ball) {
		vector box[2];
		if (!hauler.GetCollisionBox(box))
			return false;
		vector boxMin = box[0];
		vector boxMax = box[1];

		float rear = -1;
		if (hauler.MemoryPointExists("dmgZone_back")) {
			vector back = hauler.GetMemoryPointPos("dmgZone_back");
			if (back[2] > 0)
				rear = 1;
		} else if (hauler.MemoryPointExists("light_left")) {
			vector lamp = hauler.GetMemoryPointPos("light_left");
			if (lamp[2] < 0)
				rear = 1;
		} else {
			vector engine = hauler.GetEnginePos();
			if (engine[2] < 0)
				rear = 1;
		}

		// The ground: where its tyres touch it, in its model space. With none
		// touching (in the air, or a client's copy of a parked car), its hubs
		// less the tyres' radius. WheelGetPositionLS is in the body's centre-of-
		// mass frame, not its model space (and sits a little up, at the top of
		// the suspension's travel): read as model space it put the ball 0.6 m
		// low, under the car, and the trailer's nose levered the car's rear
		// wheels off the ground (2026-10-14).
		float ground = 0;
		int wheels = 0;
		for (int i = 0; i < hauler.WheelCount(); i++) {
			if (!hauler.WheelHasContact(i))
				continue;
			vector touch = hauler.WorldToModel(hauler.WheelGetContactPosition(i));
			ground += touch[1];
			wheels++;
		}
		if (wheels == 0) {
			vector com = vector.Zero;
			if (dBodyIsSet(hauler))
				com = dBodyGetCenterOfMass(hauler);
			for (int k = 0; k < hauler.WheelCount(); k++) {
				CarWheel wheel = CarWheel.Cast(hauler.WheelGetEntity(k));
				if (!wheel)
					continue;
				vector hub = hauler.WheelGetPositionLS(k) + com;
				ground += hub[1] - wheel.GetRadius();
				wheels++;
			}
		}
		if (wheels == 0)
			return false;
		ground = ground / wheels;

		float z = boxMin[2];
		if (rear > 0)
			z = boxMax[2];
		ball = Vector((boxMin[0] + boxMax[0]) * 0.5, ground + GEB_HITCH_HEIGHT, z + rear * GEB_HITCH_BEHIND);
		return true;
	}

	// A car's forward direction, flat, from where its ball is.
	static vector GebCarForward(CarScript hauler, vector ball) {
		float back = 1;
		if (ball[2] < 0)
			back = -1;
		vector fwd = hauler.VectorToParent(Vector(0, 0, -back));
		fwd[1] = 0;
		fwd.Normalize();
		return fwd;
	}

	// A car the server lets tow: general.json BoatTrailerSettings.TowVehicles
	// (a listed class covers every car built on it; an empty list lets any car
	// tow). A client reads the synced copy.
	static bool GebCanTow(CarScript hauler) {
		if (geb_BoatTrailer.Cast(hauler))
			return false;
		gebsfishConfig cfg = m_gebsConfig;
		if (!cfg && g_Game.IsServer())
			cfg = GetGebSettingsConfig();
		if (!cfg || !cfg.General || !cfg.General.BoatTrailerSettings || !cfg.General.BoatTrailerSettings.TowVehicles)
			return true;
		TStringArray allowed = cfg.General.BoatTrailerSettings.TowVehicles;
		if (allowed.Count() == 0)
			return true;
		foreach (string kind : allowed) {
			if (kind != "" && hauler.IsKindOf(kind))
				return true;
		}
		return false;
	}

	// The car's back end (across its collision box, on the ball's line, less the
	// ball's GEB_HITCH_BEHIND) and the trailer's front (tongue, A-frame arms,
	// cross-member), closest apart on the ground.
	float GebZoneGap(CarScript hauler) {
		vector ball;
		vector box[2];
		if (!hauler || !GebHitchPoint(hauler, ball) || !hauler.GetCollisionBox(box))
			return 1000;
		float zBack = ball[2] - GEB_HITCH_BEHIND;
		if (ball[2] < 0)
			zBack = ball[2] + GEB_HITCH_BEHIND;
		vector boxMin = box[0];
		vector boxMax = box[1];
		array<vector> carPts = new array<vector>();
		for (int i = 0; i <= 8; i++) {
			float x = boxMin[0] + (boxMax[0] - boxMin[0]) * i / 8.0;
			carPts.Insert(hauler.ModelToWorld(Vector(x, ball[1], zBack)));
		}
		array<vector> frontPts = new array<vector>();
		for (int k = 0; k <= 6; k++) {
			float t = k / 6.0;
			float z = GEB_COUPLER_Z + (GEB_AFRAME_Z - GEB_COUPLER_Z) * t;
			frontPts.Insert(ModelToWorld(GebD(Vector(0, GEB_COUPLER_Y, z))));
			frontPts.Insert(ModelToWorld(GebD(Vector(GEB_AFRAME_X * t, GEB_COUPLER_Y, z))));
			frontPts.Insert(ModelToWorld(GebD(Vector(-GEB_AFRAME_X * t, GEB_COUPLER_Y, z))));
			frontPts.Insert(ModelToWorld(GebD(Vector(GEB_AFRAME_X * (2 * t - 1), GEB_COUPLER_Y, GEB_AFRAME_Z))));
		}
		float best = 1000;
		foreach (vector c : carPts) {
			foreach (vector p : frontPts) {
				float dx = c[0] - p[0];
				float dz = c[2] - p[2];
				float d = Math.Sqrt(dx * dx + dz * dz);
				if (d < best)
					best = d;
			}
		}
		return best;
	}

	// The trailer this car tows, if any.
	static geb_BoatTrailer GebTowedBy(CarScript hauler) {
		if (!hauler)
			return null;
		foreach (geb_BoatTrailer t : s_GebHitched) {
			if (t && t.GebGetCar() == hauler)
				return t;
		}
		return null;
	}

	static bool GebIsTowing(CarScript hauler) {
		return GebTowedBy(hauler) != null;
	}

	// This car may hitch this trailer: allowed to tow, not towing already,
	// stopped, its back end near the trailer's front (GebZoneGap), and facing
	// away from the trailer closely enough. Hitched, the trailer swings to point at the ball, so the
	// angle that counts is the car's to that line, not to the trailer as it stands.
	bool GebFits(CarScript hauler) {
		return GebFitsWithin(hauler, GEB_HITCH_REACH, GEB_STOPPED);
	}

	bool GebFitsWithin(CarScript hauler, float reach, float maxSpeed) {
		if (!hauler || hauler.IsDamageDestroyed() || GebIsTowing(hauler) || !GebCanTow(hauler))
			return false;
		if (GetVelocity(hauler).Length() > maxSpeed)
			return false;
		vector ball;
		if (!GebHitchPoint(hauler, ball))
			return false;
		vector ballWS = hauler.ModelToWorld(ball);
		if (GebZoneGap(hauler) > reach)
			return false;
		vector along = ballWS - GetPosition();
		along[1] = 0;
		if (along.Normalize() < 0.01)
			return false;
		return vector.Dot(along, GebCarForward(hauler, ball)) >= Math.Cos(GEB_HITCH_MAX_ANGLE * Math.DEG2RAD);
	}

	// A car parked with its ball at the coupler, not towing already.
	CarScript GebFindHauler() {
		if (m_GebHitched || IsDamageDestroyed() || !GebHasWheels())
			return null;
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(GebCouplerWS(), 15, near, null);
		foreach (Object o : near) {
			CarScript hauler = CarScript.Cast(o);
			if (GebFits(hauler))
				return hauler;
		}
		return null;
	}

	// The same from the car's end: a free trailer on its wheels with its
	// coupler at this car's ball.
	static geb_BoatTrailer GebFreeTrailerFor(CarScript hauler) {
		vector ball;
		if (!hauler || !GebHitchPoint(hauler, ball))
			return null;
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(hauler.ModelToWorld(ball), 12, near, null);
		foreach (Object o : near) {
			geb_BoatTrailer trailer = geb_BoatTrailer.Cast(o);
			if (!trailer || trailer.GebIsHitched() || trailer.IsDamageDestroyed() || !trailer.GebHasWheels())
				continue;
			if (trailer.GebFits(hauler))
				return trailer;
		}
		return null;
	}

	// Server. The car may stand up to 2 m off (the zones), and a joint pulls its
	// two points together in one hard jerk, so the trailer is first set down
	// with its coupler on the ball; then the joint holds it there.
	void GebHitch(CarScript hauler) {
		vector ball;
		if (m_GebHitched || !GebHitchPoint(hauler, ball) || !GebJoin(hauler, ball))
			return;
		m_GebCar = hauler;
		hauler.GetNetworkID(m_GebCarLow, m_GebCarHigh);
		m_GebBallX = ball[0];
		m_GebBallY = ball[1];
		m_GebBallZ = ball[2];
		m_GebHitched = true;
		m_GebBrokeLoose = false;
		m_GebVelRef = GetVelocity(hauler);
		m_GebVelClock = 0;
		GebHitchChanged();
		SetAnimationPhase("jackraise", GEB_JACK_TRAVEL);
		SetSynchDirty();
		Synchronize();
	}

	// Server: the player unhitches it or it breaks off. Either way the jack
	// winds down and the trailer settles on its wheels and jack foot.
	void GebBreakOff(bool byHand) {
		if (!m_GebHitched)
			return;
		m_GebAutoBlock = m_GebCar;    // TEMPORARY: it doesn't hitch straight back on
		GebDropJoint();
		m_GebHitched = false;
		m_GebBrokeLoose = !byHand;
		m_GebCarLow = 0;
		m_GebCarHigh = 0;
		GebHitchChanged();
		SetAnimationPhase("jackraise", 0);
		SetSynchDirty();
	}

	// Server: set the trailer down with its coupler on the ball (unless it is
	// there already) and join the two. Towed, it never sleeps (a sleeping
	// body would hang off the joint) and never brakes by itself, as vanilla's
	// car push releases a car's brakes while it pushes.
	protected bool GebJoin(CarScript hauler, vector ball) {
		if (m_GebJoined)
			return true;
		if (!dBodyIsSet(hauler) || !dBodyIsSet(this))
			return false;
		vector ballWS = hauler.ModelToWorld(ball);
		if (vector.Distance(ballWS, GebCouplerWS()) > 0.3)
			GebPoseAt(ballWS);
		vector coupler = GebD(Vector(0, GEB_COUPLER_Y, GEB_COUPLER_Z));
		if (MemoryPointExists("coupler"))
			coupler = GetMemoryPointPos("coupler");
		// The joint's points are in each body's centre-of-mass frame, not its
		// model space: given model points, the coupler hung 1.2 m off the ball
		// (2026-10-14 test), which is the two bodies' centre-of-mass offsets.
		vector p1 = ball - dBodyGetCenterOfMass(hauler);
		vector p2 = coupler - dBodyGetCenterOfMass(this);
		m_GebJoint = PhysicsJoint.CreateBallSocket(hauler, this, p1, p2, true, -1);
		if (m_GebJoint == 0)
			return false;
		m_GebJoined = true;
		m_GebJointCar = hauler;
		dBodyActive(this, ActiveState.ALWAYS_ACTIVE);
		SetBrakesActivateWithoutDriver(false);
		SetBrake(0);
		SetHandbrake(0);
		return true;
	}

	// Server. A car deleted while hitched takes the joint with it (the engine drops its body's joints), so it is
	// only destroyed while the car is there.
	protected void GebDropJoint() {
		if (m_GebJoined && m_GebJointCar && !m_GebJointCar.IsPendingDeletion() && dBodyIsSet(m_GebJointCar))
			m_GebJoint.Destroy();
		m_GebJoined = false;
		m_GebJointCar = null;
		if (dBodyIsSet(this)) {
			dBodyActive(this, ActiveState.ACTIVE);
			SetBrakesActivateWithoutDriver(true);
		}
	}

	// Server: set down with its coupler on this ball, its axle on the line from
	// where the axle is now to the ball, its wheels on the ground.
	protected void GebPoseAt(vector ballWS) {
		vector axle = GetPosition();
		vector flat = Vector(ballWS[0] - axle[0], 0, ballWS[2] - axle[2]);
		if (flat.Normalize() < 0.01) {
			flat = GebForward();
			flat[1] = 0;
			flat.Normalize();
		}
		vector right = Vector(flat[2], 0, -flat[0]);
		float probe = Math.Max(ballWS[1], axle[1]) + 1.0;
		float reach = GebReach(ballWS[1] - axle[1]);
		axle = ballWS - flat * reach;
		vector wl = axle - right * GEB_TRACK;
		vector wr = axle + right * GEB_TRACK;
		float gl = g_Game.SurfaceRoadY3D(wl[0], probe, wl[2], RoadSurfaceDetection.UNDER);
		float gr = g_Game.SurfaceRoadY3D(wr[0], probe, wr[2], RoadSurfaceDetection.UNDER);
		axle[1] = (gl + gr) * 0.5 + GEB_WHEEL_RADIUS;
		reach = GebReach(ballWS[1] - axle[1]);
		float pitch = Math.Atan2(ballWS[1] - axle[1], reach) - Math.Atan2(GEB_COUPLER_Y, GEB_COUPLER_Z);
		float roll = Math.Atan2(gr - gl, 2 * GEB_TRACK);
		vector mat[4];
		GebPose(flat, right, pitch, roll, mat);
		mat[3] = ballWS - mat[2] * GEB_COUPLER_Z - mat[1] * GEB_COUPLER_Y;
		GebApply(mat);
	}

	CarScript GebGetCar() {
		if (!m_GebHitched)
			return null;
		if (!m_GebCar && !g_Game.IsServer())
			m_GebCar = CarScript.Cast(g_Game.GetObjectByNetworkId(m_GebCarLow, m_GebCarHigh));
		return m_GebCar;
	}

	override void OnVariablesSynchronized() {
		super.OnVariablesSynchronized();
		if (g_Game.IsServer())
			return;
		m_GebCar = null;      // looked up again from the synced ids
		if (m_GebHitched != m_GebWasHitched)
			GebHitchChanged();
		if (m_GebBoatLow != m_GebBoatSeenLow || m_GebBoatHigh != m_GebBoatSeenHigh) {
			m_GebBoatSeenLow = m_GebBoatLow;
			m_GebBoatSeenHigh = m_GebBoatHigh;
			// another boat: let go of the old one here too, and look the new one up
			if (m_GebBoat)
				GebUnfreezeBoat(m_GebBoat);
			m_GebBoatFrozen = false;
			m_GebBoatSmall = false;
			m_GebBoat = null;
		}
		if (m_GebBoatState != m_GebBoatSeen)
			GebBoatChanged();
		m_GebSynced = true;
	}

	// Both sides, when it is hitched or let go.
	protected void GebHitchChanged() {
		if (m_GebHitched)
			GebPlay(GEB_SND_HITCH, GebCouplerWS());
		else if (m_GebBrokeLoose)
			GebPlay(GEB_SND_BREAK, GebCouplerWS());
		else
			GebPlay(GEB_SND_UNHITCH, GebCouplerWS());
		m_GebWasHitched = m_GebHitched;
		int at = s_GebHitched.Find(this);
		if (m_GebHitched) {
			if (at == -1)
				s_GebHitched.Insert(this);
		} else {
			if (at != -1)
				s_GebHitched.Remove(at);
			m_GebCar = null;
			GebSetLights(0);
		}
		GebBoatRefresh();
		GebUpdateTick();
	}

	// ------------------------------------------------------------ ticking

	// Every frame on both machines it ticks from the game's post-update queue,
	// which runs "after simulation of entities". (Frame events never reached
	// it as an item, even made ACTIVE: 2026-10-13.)

	// Hitched (the server checks for breaking off, a client lights the lenses),
	// or a boat on it or sliding on or off. On a parked trailer the server
	// poses its boat again only when the trailer moved (GebBoatTick).
	protected bool GebNeedsTick() {
		return m_GebHitched || m_GebBoatState != GEB_BOAT_NONE;
	}

	protected void GebUpdateTick() {
		m_GebTicking = GebNeedsTick();
		if (m_GebTicking && !m_GebInQueue) {
			g_Game.GetPostUpdateQueue(CALL_CATEGORY_GAMEPLAY).Insert(GebOnPostUpdate);
			m_GebInQueue = true;
		} else if (!m_GebTicking && m_GebInQueue) {
			// a moment later: this also runs from inside the queue's own call
			// (breaking loose, a boat settling)
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebLeaveQueue, 0, false);
		}
	}

	protected void GebLeaveQueue() {
		if (m_GebTicking || !m_GebInQueue)
			return;
		g_Game.GetPostUpdateQueue(CALL_CATEGORY_GAMEPLAY).Remove(GebOnPostUpdate);
		m_GebInQueue = false;
	}

	protected void GebOnPostUpdate(float timeslice) {
		if (m_GebTicking)
			GebTick(Math.Clamp(timeslice, 0, 0.25));
	}

	protected void GebTick(float dt) {
		if (m_GebHitched) {
			CarScript hauler = GebGetCar();
			if (!hauler) {
				// gone on the server (deleted, despawned); on a client maybe just
				// not in its bubble yet
				if (g_Game.IsServer())
					GebBreakOff(false);
			} else if (g_Game.IsServer() && GebShouldBreak(hauler, dt)) {
				GebBreakOff(false);
			} else {
				if (!g_Game.IsServer())
					GebSnapToBall(hauler);
				if (!g_Game.IsHeadlessOrDedicatedServer())
					GebUpdateLights(hauler);
				GebTowLog(hauler, dt);    // TEMPORARY
			}
		}
		GebBoatTick(dt);
	}

	// Client, every frame while hitched: its copy of the trailer moved so the
	// coupler sits on this machine's own car's ball. The trailer is the
	// server's (the joint is there), so its position reaches a client a network
	// round trip late, while the driver's own car moves at once: at speed the
	// trailer hung behind the hitch and only caught up when the car slowed
	// ("like a rubber band", Cole 2026-10-14). Only the copy on screen moves,
	// keeping the server's turn of it; the server's trailer and joint, and so
	// the physics, are untouched. The boat on it follows (the boat tick poses
	// it from this copy afterwards). A gap past GEB_SNAP_MAX (a teleport, a
	// trailer still streaming in) is left alone. The copy stays asleep as it
	// was: a client doesn't simulate it, and moving it mustn't start that.
	protected void GebSnapToBall(CarScript hauler) {
		vector ballWS = hauler.ModelToWorld(Vector(m_GebBallX, m_GebBallY, m_GebBallZ));
		vector gap = ballWS - GebCouplerWS();
		m_GebSnapGap = gap.Length();
		if (m_GebSnapGap < 0.005 || m_GebSnapGap > GEB_SNAP_MAX)
			return;
		bool body = dBodyIsSet(this);
		bool wasActive = body && dBodyIsActive(this);
		SetPosition(GetPosition() + gap);
		if (body && !wasActive && dBodyIsActive(this))
			dBodyActive(this, ActiveState.INACTIVE);
	}

	// TEMPORARY (2026-10-13): what each machine sees while it tows, once a
	// second ("[gebsfish trailer check] tow" in the server and client script logs).
	protected void GebTowLog(CarScript hauler, float dt) {
		m_GebTowLogClock += dt;
		if (m_GebTowLogClock < 1.0)
			return;
		m_GebTowLogClock = 0;
		string side = "client";
		if (g_Game.IsServer())
			side = "server";
		vector ballWS = hauler.ModelToWorld(Vector(m_GebBallX, m_GebBallY, m_GebBallZ));
		vector pos = GetPosition();
		bool active = dBodyIsSet(this) && dBodyIsActive(this);
		vector gap = hauler.VectorToLocal(GebCouplerWS() - ballWS);
		vector comCar = vector.Zero;
		if (dBodyIsSet(hauler))
			comCar = dBodyGetCenterOfMass(hauler);
		vector comTrailer = vector.Zero;
		if (dBodyIsSet(this))
			comTrailer = dBodyGetCenterOfMass(this);
		int carTouching = 0;
		for (int w = 0; w < hauler.WheelCount(); w++) {
			if (hauler.WheelHasContact(w))
				carTouching++;
		}
		Print("[gebsfish trailer check] tow " + side + " gap in car space " + gap.ToString() + ", ball height in car space " + GebR(m_GebBallY, 0.01) + ", car wheels on the ground " + carTouching.ToString() + " of " + hauler.WheelCount().ToString() + ", car centre of mass " + comCar.ToString() + ", trailer centre of mass " + comTrailer.ToString());
		Print("[gebsfish trailer check] tow " + side + " wheels: " + GebWheelDiag());
		Print("[gebsfish trailer check] tow " + side + ": joint " + m_GebJoined.ToString() + ", body active " + active.ToString() + ", coupler to ball " + GebR(vector.Distance(ballWS, GebCouplerWS()), 0.05) + " m, client snap " + GebR(m_GebSnapGap, 0.05) + " m, trailer speed " + GebR(GetVelocity(this).Length(), 0.1) + ", car speed " + GebR(GetVelocity(hauler).Length(), 0.1) + ", trailer at " + GebR(pos[0], 0.1) + " " + GebR(pos[1], 0.05) + " " + GebR(pos[2], 0.1));
	}

	// ------------------------------------------------------------ towing

	// Server: a destroyed or rolled car, a crash, a jackknife, the coupler
	// pulled off the ball (a teleport, or the joint giving), or the trailer
	// itself ruined.
	protected bool GebShouldBreak(CarScript hauler, float dt) {
		if (hauler.IsDamageDestroyed() || IsDamageDestroyed())
			return true;
		vector up = hauler.VectorToParent("0 1 0");
		if (up[1] < GEB_MIN_CAR_UP)
			return true;

		vector vel = GetVelocity(hauler);
		vel[1] = 0;
		vector before = m_GebVelRef;
		before[1] = 0;
		if (vector.Distance(vel, before) > GEB_CRASH_DV)
			return true;
		m_GebVelClock += dt;
		if (m_GebVelClock >= 0.15) {
			m_GebVelClock = 0;
			m_GebVelRef = vel;
		}

		vector ballLocal = Vector(m_GebBallX, m_GebBallY, m_GebBallZ);
		if (vector.Distance(hauler.ModelToWorld(ballLocal), GebCouplerWS()) > GEB_BREAK_GAP)
			return true;
		vector along = GebForward();
		along[1] = 0;
		along.Normalize();
		return vector.Dot(along, GebCarForward(hauler, ballLocal)) < Math.Cos(GEB_JACKKNIFE * Math.DEG2RAD);
	}

	// The tongue's length along the ground when the coupler is this far above
	// the axle.
	protected float GebReach(float rise) {
		float len2 = GEB_COUPLER_Z * GEB_COUPLER_Z + GEB_COUPLER_Y * GEB_COUPLER_Y;
		return Math.Sqrt(Math.Max(len2 - rise * rise, 1.0));
	}

	// Axes from a flat heading, pitch (nose up) and roll (right side up). DayZ
	// is left-handed: right = up x forward, up = forward x right.
	protected static void GebPose(vector flat, vector right, float pitch, float roll, inout vector mat[4]) {
		vector fwd = flat * Math.Cos(pitch) + vector.Up * Math.Sin(pitch);
		vector side = right * Math.Cos(roll) + vector.Up * Math.Sin(roll);
		vector up = fwd * side;
		up.Normalize();
		side = up * fwd;
		side.Normalize();
		mat[0] = side;
		mat[1] = up;
		mat[2] = fwd;
		mat[3] = vector.Zero;
	}

	// Server: moved there, at rest. mat is in p3d terms (z toward the coupler);
	// the model's x and z are turned.
	protected void GebApply(vector mat[4]) {
		float t = GebTurn();
		vector m[4];
		m[0] = mat[0] * t;
		m[1] = mat[1];
		m[2] = mat[2] * t;
		m[3] = mat[3];
		SetPosition(m[3]);
		SetOrientation(Math3D.MatrixToAngles(m));
		SetVelocity(this, vector.Zero);
		dBodySetAngularVelocity(this, vector.Zero);
	}

	// ------------------------------------------------------------ sounds

	// A one-shot vanilla sound where something happens. Not on a dedicated
	// server, and not on a client's first sync of a trailer that streams in
	// already hitched or loaded.
	protected void GebPlay(string soundSet, vector pos) {
		if (g_Game.IsHeadlessOrDedicatedServer())
			return;
		if (!g_Game.IsServer() && !m_GebSynced)
			return;
		EffectSound sound = SEffectManager.PlaySound(soundSet, pos);
		if (sound)
			sound.SetAutodestroy(true);
	}

	// ------------------------------------------------------------ tail lights

	// The lenses follow the car: tail lights with its headlights, brighter
	// while it brakes (its synced brake flag, so everyone sees them).
	protected void GebUpdateLights(CarScript hauler) {
		int want = 0;
		if (hauler.GebBrakesPressed())
			want = 2;
		else if (hauler.LightIsOn())
			want = 1;
		GebSetLights(want);
	}

	// A local look (clients): the lens material for the state and the trailer's
	// wear; ruined lenses stay dark.
	protected void GebSetLights(int state) {
		int level = GetHealthLevel("");
		bool same = state == m_GebLightState && level == m_GebLightLevel && m_GebLensMaterial != "";
		m_GebLightState = state;
		m_GebLightLevel = level;
		if (same || g_Game.IsHeadlessOrDedicatedServer())
			return;
		int index = GetHiddenSelectionIndex("lights");
		if (index < 0)
			return;
		string wear = "";
		if (level >= GameConstants.STATE_DAMAGED)
			wear = "_damage";
		string material = GEB_MAT + wear + ".rvmat";
		if (level >= GameConstants.STATE_RUINED)
			material = GEB_MAT + "_destruct.rvmat";
		else if (state == 2)
			material = GEB_MAT + "_lights_brake" + wear + ".rvmat";
		else if (state == 1)
			material = GEB_MAT + "_lights_tail" + wear + ".rvmat";
		if (material != m_GebLensMaterial) {
			m_GebLensMaterial = material;
			SetObjectMaterial(index, material);
		}
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone) {
		super.EEHealthLevelChanged(oldLevel, newLevel, zone);
		if (zone == "")
			GebSetLights(m_GebLightState);
	}

	// ------------------------------------------------------------ the boat

	// The bow roller, in the world.
	vector GebRollerWS() {
		return ModelToWorld(GebD(GEB_ROLLER));
	}

	bool GebAtWinch(PlayerBase player) {
		return vector.Distance(player.GetPosition(), GebRollerWS()) <= GEB_WINCH_REACH;
	}

	int GebBoatState() {
		return m_GebBoatState;
	}

	protected BoatScript GebResolveBoat() {
		if (!m_GebBoat && !g_Game.IsServer() && (m_GebBoatLow != 0 || m_GebBoatHigh != 0))
			m_GebBoat = BoatScript.Cast(g_Game.GetObjectByNetworkId(m_GebBoatLow, m_GebBoatHigh));
		return m_GebBoat;
	}

	// The boat on it (or sliding on or off), if any.
	BoatScript GebGetBoat() {
		if (m_GebBoatState == GEB_BOAT_NONE)
			return null;
		return GebResolveBoat();
	}

	static bool GebIsCarried(Object obj) {
		return GebCarrierOf(obj) != null;
	}

	// The trailer this boat rides on (or slides on or off), if any.
	static geb_BoatTrailer GebCarrierOf(Object obj) {
		if (!obj)
			return null;
		foreach (geb_BoatTrailer t : s_GebCarriers) {
			if (t && t.GebGetBoat() == obj)
				return t;
		}
		return null;
	}

	static bool GebHasCrew(Transport boat) {
		for (int i = 0; i < boat.CrewSize(); i++) {
			if (boat.CrewMember(i))
				return true;
		}
		return false;
	}

	// The boats it carries (see the seats above).
	static bool GebCarries(Object obj) {
		return geb_jonboat_base.Cast(obj) != null || Boat_01_ColorBase.Cast(obj) != null;
	}

	// A boat's seat on the bunks, the game's trailer model space (the half turn of
	// both models leaves the axes as they are and turns the offset).
	protected void GebSeatOf(BoatScript boat, inout vector seat[4]) {
		float y = GEB_RIB_SEAT_Y;
		float z = GEB_RIB_SEAT_Z;
		if (geb_jonboat_base.Cast(boat)) {
			y = GEB_JON_SEAT_Y;
			z = GEB_JON_SEAT_Z;
		}
		seat[0] = "-1 0 0";
		seat[1] = "0 1 0";
		seat[2] = "0 0 -1";
		seat[3] = GebD(Vector(0, y, z));
	}

	// A boat's bow, its own model space.
	protected vector GebBowOf(BoatScript boat) {
		if (geb_jonboat_base.Cast(boat))
			return GEB_JON_BOW;
		return GEB_RIB_BOW;
	}

	// A boat it carries, nobody in it, lying (or floating) still with its bow
	// by the bow roller, facing about the trailer's way.
	BoatScript GebFindBoat() {
		if (m_GebBoatState != GEB_BOAT_NONE || IsDamageDestroyed())
			return null;
		vector roller = GebRollerWS();
		vector along = GebForward();
		along[1] = 0;
		along.Normalize();

		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(roller, 15, near, null);
		foreach (Object o : near) {
			BoatScript boat = BoatScript.Cast(o);
			if (!boat || !GebCarries(boat) || boat.IsDamageDestroyed() || GebIsCarried(boat) || GebHasCrew(boat))
				continue;
			if (GetVelocity(boat).Length() > GEB_BOAT_STILL)
				continue;
			if (vector.Distance(boat.ModelToWorld(GebD(GebBowOf(boat))), roller) > GEB_BOAT_REACH)
				continue;
			vector bowward = boat.GetDirection() * (-GebTurn());
			bowward[1] = 0;
			bowward.Normalize();
			if (vector.Dot(bowward, along) < Math.Cos(GEB_BOAT_ALIGN * Math.DEG2RAD))
				continue;
			return boat;
		}
		return null;
	}

	// Server: winch it on, from where it lies now.
	void GebLoadBoat(BoatScript boat) {
		if (m_GebBoatState != GEB_BOAT_NONE || !boat)
			return;
		vector trailer[4];
		GetTransform(trailer);
		vector world[4];
		boat.GetTransform(world);
		GebToLocal(trailer, world, m_GebBoatFrom);
		m_GebBoatFromSet = true;
		vector seat[4];
		GebSeatOf(boat, seat);
		float dist = vector.Distance(m_GebBoatFrom[3], seat[3]);
		m_GebBoatLen = Math.Max(2.0, dist / GEB_WINCH_SPEED);
		GebSetBoat(boat, GEB_BOAT_LOADING);
	}

	// Server: slide it back off the rear.
	void GebLaunchBoat() {
		if (m_GebBoatState != GEB_BOAT_LOADED)
			return;
		m_GebBoatLen = GEB_LAUNCH_BACK / GEB_LAUNCH_SPEED;
		m_GebBoatState = GEB_BOAT_LAUNCHING;
		GebBoatChanged();
		SetSynchDirty();
	}

	// Server.
	protected void GebSetBoat(BoatScript boat, int state) {
		m_GebBoat = boat;
		boat.GetNetworkID(m_GebBoatLow, m_GebBoatHigh);
		m_GebBoatState = state;
		if (boat.EngineIsOn())
			boat.EngineStop();
		// the motor tilts up for the trip (the jon boat's TrailerTilt, Model.cfg;
		// the rubber boat's model has no animation on this source)
		boat.SetAnimationPhase("FoldingEngine", 1);
		GebBoatChanged();
		GebPlaceBoat();
		SetSynchDirty();
	}

	// Server: put a boat that is on the trailer onto its seat (once it is
	// loaded; the ticks keep it there).
	protected void GebPlaceBoat() {
		if (!g_Game.IsServer() || m_GebBoatState != GEB_BOAT_LOADED || !m_GebBoat)
			return;
		GebBoatRefresh();
		vector seat[4];
		GebSeatOf(m_GebBoat, seat);
		GebPoseBoat(m_GebBoat, seat);
		GebResyncBoat(m_GebBoat);
	}

	// Server, a moment after a restart: the boat it was saved with lies by it.
	protected void GebRelinkBoat() {
		m_GebRelink = false;
		if (m_GebBoatState != GEB_BOAT_NONE)
			return;
		array<Object> near = new array<Object>();
		g_Game.GetObjectsAtPosition3D(GetPosition(), 15, near, null);
		foreach (Object o : near) {
			BoatScript boat = BoatScript.Cast(o);
			if (!boat || !GebCarries(boat) || GebIsCarried(boat))
				continue;
			int b1;
			int b2;
			int b3;
			int b4;
			boat.GetPersistentID(b1, b2, b3, b4);
			if (b1 == m_GebPid1 && b2 == m_GebPid2 && b3 == m_GebPid3 && b4 == m_GebPid4) {
				GebSetBoat(boat, GEB_BOAT_LOADED);
				return;
			}
		}
	}

	// Both sides, when the boat state changes.
	protected void GebBoatChanged() {
		int was = m_GebBoatSeen;
		m_GebBoatSeen = m_GebBoatState;
		GebBoatLog(was);    // TEMPORARY
		if (was == GEB_BOAT_LOADING && m_GebBoatState == GEB_BOAT_LOADED)
			GebPlay(GEB_SND_SETTLE, GetPosition());
		else if (m_GebBoatState == GEB_BOAT_LAUNCHING)
			GebPlay(GEB_SND_UNHITCH, GebRollerWS());
		int at = s_GebCarriers.Find(this);
		if (m_GebBoatState == GEB_BOAT_NONE) {
			if (at != -1)
				s_GebCarriers.Remove(at);
			BoatScript boat = GebResolveBoat();
			if (boat)
				GebUnfreezeBoat(boat);
			if (boat && was == GEB_BOAT_LAUNCHING)
				g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebLaunchLog, 3000, false, boat);    // TEMPORARY
			// (a deleted boat can't be let go; the next one starts afresh either way)
			m_GebBoatFrozen = false;
			m_GebBoatSmall = false;
			m_GebBoat = null;
		} else {
			if (at == -1)
				s_GebCarriers.Insert(this);
			if (m_GebBoatState != was) {
				m_GebBoatT = 0;
				// a client starts a winch-on from where it sees the boat now
				if (!g_Game.IsServer())
					m_GebBoatFromSet = false;
			}
			GebBoatRefresh();
		}
		GebUpdateTick();
	}

	// TEMPORARY (2026-10-13, Cole: "why did the boat remove when I tried to
	// launch it"): each machine logs where the boat and the trailer are when the
	// boat's state changes ("[gebsfish trailer check] boat").
	protected void GebBoatLog(int was) {
		if (was == m_GebBoatState)
			return;
		string side = "client";
		if (g_Game.IsServer())
			side = "server";
		string where = "no boat";
		BoatScript boat = GebResolveBoat();
		if (boat) {
			vector b = boat.GetPosition();
			where = boat.GetType() + " at " + GebR(b[0], 0.1) + " " + GebR(b[1], 0.05) + " " + GebR(b[2], 0.1);
			if (g_Game.IsServer())
				where += ", health " + GebR(boat.GetHealth01("", ""), 0.01);
		}
		vector t = GetPosition();
		Print("[gebsfish trailer check] boat " + side + ": state " + was.ToString() + " -> " + m_GebBoatState.ToString() + ", " + where + ", trailer at " + GebR(t[0], 0.1) + " " + GebR(t[1], 0.05) + " " + GebR(t[2], 0.1) + ", hitched " + m_GebHitched.ToString());
	}

	// Kinematic, on the small-item layer, while it is on the trailer (or
	// sliding on or off): vehicles pass through that layer, so the posed boat
	// never shoves the trailer it sits on.
	protected void GebBoatRefresh() {
		BoatScript boat = GebGetBoat();
		if (!boat || !dBodyIsSet(boat))
			return;
		if (!m_GebBoatFrozen) {
			dBodyDynamic(boat, false);
			m_GebBoatFrozen = true;
		}
		bool small = m_GebBoatState != GEB_BOAT_NONE;
		if (small == m_GebBoatSmall)
			return;
		if (small) {
			m_GebBoatLayer = dBodyGetInteractionLayer(boat);
			dBodySetInteractionLayer(boat, PhxInteractionLayers.ITEM_SMALL);
		} else {
			dBodySetInteractionLayer(boat, m_GebBoatLayer);
		}
		m_GebBoatSmall = small;
	}

	protected void GebUnfreezeBoat(BoatScript boat) {
		if (!dBodyIsSet(boat))
			return;
		if (m_GebBoatSmall) {
			dBodySetInteractionLayer(boat, m_GebBoatLayer);
			m_GebBoatSmall = false;
		}
		if (m_GebBoatFrozen) {
			dBodyDynamic(boat, true);
			// Only the server sets it simulating; a client leaves its copy to the
			// network. Woken on a client, the copy could fall or drift on its own
			// while the server's boat stayed put.
			if (g_Game.IsServer())
				dBodyActive(boat, ActiveState.ACTIVE);
			m_GebBoatFrozen = false;
		}
	}

	// Server, as a boat is let go: lifted clear of the ground if any part of its
	// hull would start inside it. The slide off keeps the boat at the bunks'
	// height, so on ground rising behind the trailer its hull began in the
	// terrain and it dropped through and was gone (Cole, 2026-10-14, launched on
	// land). In water nothing changes: it floats.
	protected void GebClearGround(BoatScript boat) {
		vector box[2];
		if (!boat.GetCollisionBox(box))
			return;
		vector boxMin = box[0];
		vector boxMax = box[1];
		float lift = 0;
		// the bottom's four corners and its middle
		for (int i = 0; i < 5; i++) {
			float bx = (boxMin[0] + boxMax[0]) * 0.5;
			float bz = (boxMin[2] + boxMax[2]) * 0.5;
			if (i == 1 || i == 2)
				bx = boxMin[0];
			if (i == 3 || i == 4)
				bx = boxMax[0];
			if (i == 1 || i == 3)
				bz = boxMin[2];
			if (i == 2 || i == 4)
				bz = boxMax[2];
			vector corner = boat.ModelToWorld(Vector(bx, boxMin[1], bz));
			float ground = g_Game.SurfaceRoadY3D(corner[0], corner[1] + 3.0, corner[2], RoadSurfaceDetection.UNDER);
			if (ground + 0.05 - corner[1] > lift)
				lift = ground + 0.05 - corner[1];
		}
		if (lift > 0)
			boat.SetPosition(boat.GetPosition() + Vector(0, lift, 0));
	}

	// TEMPORARY (2026-10-14, Cole: the boat he launched on land disappeared):
	// each machine logs where the boat is 3 s after it was let go, and whether
	// it is moving.
	protected void GebLaunchLog(BoatScript boat) {
		string side = "client";
		if (g_Game.IsServer())
			side = "server";
		if (!boat) {
			Print("[gebsfish trailer check] after launch " + side + ": the boat is gone");
			return;
		}
		vector b = boat.GetPosition();
		float ground = g_Game.SurfaceRoadY3D(b[0], b[1] + 3.0, b[2], RoadSurfaceDetection.UNDER);
		bool active = dBodyIsSet(boat) && dBodyIsActive(boat);
		Print("[gebsfish trailer check] after launch " + side + ": " + boat.GetType() + " at " + GebR(b[0], 0.1) + " " + GebR(b[1], 0.05) + " " + GebR(b[2], 0.1) + ", ground there " + GebR(ground, 0.05) + ", speed " + GebR(GetVelocity(boat).Length(), 0.1) + ", body active " + active.ToString());
	}

	// Server: it's off the trailer, its own boat again.
	protected void GebReleaseBoat() {
		BoatScript boat = m_GebBoat;
		if (boat)
			GebClearGround(boat);
		m_GebBoatState = GEB_BOAT_NONE;
		GebBoatChanged();
		if (boat) {
			SetVelocity(boat, vector.Zero);
			boat.SetAnimationPhase("FoldingEngine", 0);
			GebResyncBoat(boat);
			// and once more when it has settled, for any player who missed it
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GebResyncBoat, 1000, false, boat);
		}
		SetSynchDirty();
	}

	// Server: tell every player where the boat really is. Posed with SetTransform
	// and sent with Synchronize alone, a player's copy stopped following partway
	// through a tow and, once the boat was let go, showed it where the network
	// last had it, hundreds of metres back up the road, while it lay by the
	// trailer (Cole, 2026-10-14: launched after a tow, the boat was gone). A
	// SetPosition at the same spot also moves it the game's own way.
	protected void GebResyncBoat(BoatScript boat) {
		if (!boat || !g_Game.IsServer())
			return;
		boat.SetPosition(boat.GetPosition());
		boat.Synchronize();
	}

	protected void GebBoatTick(float dt) {
		if (m_GebBoatState == GEB_BOAT_NONE)
			return;
		bool server = g_Game.IsServer();
		BoatScript boat = GebGetBoat();
		if (!boat) {
			// gone (deleted) on the server; on a client maybe not in its bubble yet
			if (server)
				GebReleaseBoat();
			return;
		}
		GebBoatRefresh();

		// Server, a parked trailer with its boat on: posed again only when the
		// trailer moved (pushed, bumped, settling on its jack), so the boat it
		// saves stays on it; synced once more when it comes to rest.
		if (server && m_GebBoatState == GEB_BOAT_LOADED && !m_GebHitched) {
			vector at = GetPosition();
			vector turn = GetOrientation();
			if (vector.DistanceSq(at, m_GebParkedAt) < 0.0001 && vector.DistanceSq(turn, m_GebParkedTurn) < 0.01) {
				if (m_GebParkedMoved) {
					m_GebParkedMoved = false;
					GebResyncBoat(boat);
				}
				return;
			}
			m_GebParkedAt = at;
			m_GebParkedTurn = turn;
			m_GebParkedMoved = true;
		}

		vector seat[4];
		GebSeatOf(boat, seat);
		vector pose[4];
		pose[0] = seat[0];
		pose[1] = seat[1];
		pose[2] = seat[2];
		pose[3] = seat[3];
		bool done = false;
		if (m_GebBoatState == GEB_BOAT_LOADING || m_GebBoatState == GEB_BOAT_LAUNCHING) {
			vector start[4];
			vector goal[4];
			if (m_GebBoatState == GEB_BOAT_LOADING) {
				if (!m_GebBoatFromSet) {
					vector trailer[4];
					GetTransform(trailer);
					vector world[4];
					boat.GetTransform(world);
					GebToLocal(trailer, world, m_GebBoatFrom);
					m_GebBoatFromSet = true;
				}
				start[0] = m_GebBoatFrom[0];
				start[1] = m_GebBoatFrom[1];
				start[2] = m_GebBoatFrom[2];
				start[3] = m_GebBoatFrom[3];
				goal[0] = seat[0];
				goal[1] = seat[1];
				goal[2] = seat[2];
				goal[3] = seat[3];
			} else {
				start[0] = seat[0];
				start[1] = seat[1];
				start[2] = seat[2];
				start[3] = seat[3];
				goal[0] = seat[0];
				goal[1] = seat[1];
				goal[2] = seat[2];
				goal[3] = seat[3] - GebD(Vector(0, 0, GEB_LAUNCH_BACK));
			}
			m_GebBoatT += dt;
			if (m_GebBoatState == GEB_BOAT_LOADING) {
				m_GebRatchetClock += dt;
				if (m_GebRatchetClock >= GEB_RATCHET_EVERY) {
					m_GebRatchetClock = 0;
					GebPlay(GEB_SND_RATCHET, GebRollerWS());
				}
			}
			float k = 1;
			if (m_GebBoatLen > 0)
				k = Math.Clamp(m_GebBoatT / m_GebBoatLen, 0, 1);
			GebBlend(start, goal, k * k * (3 - 2 * k), pose);
			done = k >= 1;
		}
		GebPoseBoat(boat, pose);

		if (!server)
			return;
		m_GebBoatSyncClock += dt;
		if (m_GebBoatSyncClock >= GEB_BOAT_SYNC) {
			m_GebBoatSyncClock = 0;
			GebResyncBoat(boat);
		}
		if (done) {
			if (m_GebBoatState == GEB_BOAT_LOADING) {
				m_GebBoatState = GEB_BOAT_LOADED;
				GebBoatChanged();
				GebResyncBoat(boat);
				SetSynchDirty();
			} else {
				GebReleaseBoat();
			}
		}
	}

	// The boat where its trailer-space transform puts it.
	protected void GebPoseBoat(BoatScript boat, vector pose[4]) {
		vector trailer[4];
		GetTransform(trailer);
		vector world[4];
		GebToWorld(trailer, pose, world);
		boat.SetTransform(world);
	}

	// A world transform in a parent's model space, and back (orthonormal axes:
	// rows x, y, z and the position).
	protected static void GebToLocal(vector parent[4], vector world[4], inout vector rel[4]) {
		for (int i = 0; i < 3; i++) {
			vector axis = world[i];
			rel[i] = Vector(vector.Dot(axis, parent[0]), vector.Dot(axis, parent[1]), vector.Dot(axis, parent[2]));
		}
		vector d = world[3] - parent[3];
		rel[3] = Vector(vector.Dot(d, parent[0]), vector.Dot(d, parent[1]), vector.Dot(d, parent[2]));
	}

	protected static void GebToWorld(vector parent[4], vector rel[4], inout vector world[4]) {
		for (int i = 0; i < 4; i++) {
			vector v = rel[i];
			world[i] = parent[0] * v[0] + parent[1] * v[1] + parent[2] * v[2];
		}
		world[3] = world[3] + parent[3];
	}

	// Between two transforms: the position in a straight line, the axes turned
	// part way (never opposite: a winch-on starts within GEB_BOAT_ALIGN, under 180).
	protected static void GebBlend(vector a[4], vector b[4], float s, inout vector res[4]) {
		vector z = a[2] * (1 - s) + b[2] * s;
		z.Normalize();
		vector y = a[1] * (1 - s) + b[1] * s;
		vector x = y * z;
		x.Normalize();
		y = z * x;
		y.Normalize();
		res[0] = x;
		res[1] = y;
		res[2] = z;
		res[3] = a[3] * (1 - s) + b[3] * s;
	}
}

// The boat trailer's brake lights follow the car's synced brake flag.
modded class CarScript {
	// Hitch and unhitch can be done looking at the car as well as the trailer.
	override void SetActions() {
		super.SetActions();
		AddAction(GebActionHitchTrailerCar);
		AddAction(GebActionUnhitchTrailerCar);
	}

	bool GebBrakesPressed() {
		return m_BrakesArePressed;
	}
}
