/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Footsteps on the jon boat's deck.
//
// The engine finds a step's surface (CGame.GetSurfaceInfoUnderObjectByBone, and
// GetSurfaceInfoUnderObject for landings) by checking the sea first: when the
// foot bone is at or below the sea surface at that spot (sea level plus the
// waves), it returns the sea and never looks at what the foot stands on. The jon
// boat is a flat-bottomed hull whose floor sits below its own waterline (floor
// 0.10 m, waterline about 0.21 m up the model, empty, in calm water), so every
// step on its deck came back as sea water and played a splash. Vanilla's rubber
// boat gets away with it because its floor sits above its waterline.
//
// While a player stands on a jon boat, vanilla OnStepEvent still runs as usual
// (AI noise, feet damage and the rest); only the sound it plays is held back and
// replaced with the deck's own step sound. The deck surface below matches the
// texture on the boat's Roadway LOD, so steps sound the same when the engine
// does reach the roadway (hull out of the water, or in a wave trough).
modded class DayZPlayerImplement {
	// CfgSurfaces class of the jon boat's roadway (dz\surfaces\data\roadway\metal_thin_ext.paa)
	static const string GEB_JONBOAT_DECK_SURFACE = "metal_thin_ext";

	// True only while vanilla OnStepEvent runs for a step on a jon boat deck.
	protected bool m_GebMuteStepSound;

	override void OnStepEvent(string pEventType, string pUserString, int pUserInt) {
		// Cleared up front so a step that broke off half way can never leave
		// this character's sounds muted.
		m_GebMuteStepSound = false;

		#ifndef SERVER
		#ifndef NO_GUI
		if (GebStandsOnJonBoat()) {
			m_GebMuteStepSound = true;
			super.OnStepEvent(pEventType, pUserString, pUserInt);
			m_GebMuteStepSound = false;

			GebPlayJonBoatDeckStep(pUserInt);
			return;
		}
		#endif
		#endif

		super.OnStepEvent(pEventType, pUserString, pUserInt);
	}

	// During a deck step this swallows vanilla's sea-water step sound (and the
	// brush-through-vegetation rustle, which only plays near bushes).
	override AbstractWave PlaySound(SoundObject so, SoundObjectBuilder sob) {
		if (m_GebMuteStepSound)
			return null;

		return super.PlaySound(so, sob);
	}

	// A character standing on a boat is linked to it; the floor entity covers the
	// moment before the link is made.
	protected bool GebStandsOnJonBoat() {
		IEntity under = PhysicsGetLinkedEntity();
		if (!under)
			under = PhysicsGetFloorEntity();

		return geb_jonboat_base.Cast(under) != null;
	}

	// The same lookup vanilla makes for a step, with the deck surface instead of
	// the sea: walk/run/sprint and boots/sneakers/barefoot all still apply.
	protected void GebPlayJonBoatDeckStep(int pUserInt) {
		if (!g_Game.GetPlayer())
			return;

		DayZPlayerTypeStepSoundLookupTable table = GetDayZPlayerType().GetStepSoundLookupTable();
		if (!table)
			return;

		HumanMovementState state = new HumanMovementState();
		GetMovementState(state);

		string deckSurface = GEB_JONBOAT_DECK_SURFACE;
		SoundObjectBuilder soundBuilder = table.GetSoundBuilder(pUserInt, state.m_iMovement, deckSurface.Hash(), GetBootsType());
		if (!soundBuilder)
			return;

		SoundObject soundObject = soundBuilder.BuildSoundObject();
		if (!soundObject)
			return;

		AttenuateSoundIfNecessary(soundObject);
		PlaySound(soundObject, soundBuilder);
	}
}
