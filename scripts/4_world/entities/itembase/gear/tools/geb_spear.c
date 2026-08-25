/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// SpearStone and SpearBone both inherit from Spear without their own
// SetActions, so this one override puts Spear Fish on every vanilla spear.
// The matching GebSpearedFish attachment slot is added in
// data/tools/config.cpp.
modded class Spear {
	override void SetActions() {
		super.SetActions();
		AddAction(ActionSpearFish);
	}
};
