/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The Fish Tank Stand (geb_FishTankStand in data/tools/config.cpp): a wooden
// aquarium cabinet with a 10x5 cupboard, and one slot, GebFishTank, on its top.
// The Fish Tank attached there renders on the proxy gebfishtank and keeps its
// own swimming fish and bubbles (geb_fishtank.c). Crafted from 8 planks and 16
// nails (CraftFishTankStand), never world loot (typesxml.c, nominal 0).
//
// A placed container like the Fishing Locker: vanilla's DeployableContainer_Base
// gives the hologram and place actions and spills the contents when ruined.
class geb_FishTankStand : DeployableContainer_Base {

	void geb_FishTankStand() {
		// Where vanilla spreads the contents when the stand is ruined
		// (DeployableContainer_Base.EEHealthLevelChanged): half the footprint,
		// and in y a height offset rather than a half extent.
		m_HalfExtents = Vector(0.33, 0.1, 0.18);
	}

	// Back into hands only when empty, the tank off and the cupboard cleared:
	// carried about with a tank on top it would be a stash on legs.
	override bool CanPutIntoHands(EntityAI parent) {
		if (!super.CanPutIntoHands(parent))
			return false;
		return GetInventory().CountInventory() <= 1;
	}

	// Only a stand standing in the world takes the tank. Vanilla's take action
	// looks for a free slot through everything the player carries, so a stand in
	// hands could otherwise swallow a picked-up tank.
	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		return !GetHierarchyParent();
	}
}
