/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Script class for the jon boat. The config's geb_jonboat_base inherits
// Boat_01_ColorBase, so without this the boat was running on the vanilla rubber
// boat's script class and inheriting its sounds wholesale.
//
// The colour variants (geb_jonboat_greenaluminum and friends) declare no script
// class of their own, so the engine walks up the config chain and lands here --
// one class covers every variant.
class geb_jonboat_base extends Boat_01_ColorBase {

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
