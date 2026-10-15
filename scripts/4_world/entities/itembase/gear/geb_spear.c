/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Vanilla's crafted spears can fish the shallows (ActionGebSpearFishing).
// SpearBone and SpearStone inherit from Spear, so all three get it.
modded class Spear {
	override void SetActions() {
		super.SetActions();
		AddAction(ActionGebSpearFishing);
	}
};
