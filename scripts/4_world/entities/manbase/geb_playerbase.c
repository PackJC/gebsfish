/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Seated actions come from the player, not the vehicle: the jon boat's
// "switch lights" interact prompt for the driver seat, and (for now) the
// trailer's unhitch from the car's seat.
modded class PlayerBase {
	override void SetActions(out TInputActionMap InputActionMap) {
		super.SetActions(InputActionMap);
		AddAction(GebActionSwitchBoatLightsSeat, InputActionMap);
		AddAction(GebActionUnhitchTrailerSeat, InputActionMap);    // TEMPORARY, with the trailer's auto-hitch
	}
}
