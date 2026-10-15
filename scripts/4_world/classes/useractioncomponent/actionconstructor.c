/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class ActionConstructor {
	override void RegisterActions(TTypenameArray actions) {
		super.RegisterActions(actions);
		actions.Insert(ActionDigBugs);
		actions.Insert(ActionBambooFishingNet);
		actions.Insert(ActionGebSpearFishing);
		actions.Insert(GebActionSwitchBoatLights);
		actions.Insert(GebActionSwitchBoatLightsSeat);
		actions.Insert(GebActionSwitchBoatLightsAtBattery);
		actions.Insert(GebActionHitchTrailer);
		actions.Insert(GebActionUnhitchTrailer);
		actions.Insert(GebActionHitchTrailerCar);
		actions.Insert(GebActionUnhitchTrailerCar);
		actions.Insert(GebActionUnhitchTrailerSeat);
		actions.Insert(GebActionWinchBoatOn);
		actions.Insert(GebActionLaunchBoat);
		actions.Insert(GebActionAssembleDryingRack);
	}
};
