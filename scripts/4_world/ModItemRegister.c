/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/


modded class ModItemRegisterCallbacks
{

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);
        

          //Saltwater Fish
          pType.AddItemInHandsProfileIK("geb_Asianseabass", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");

          //Freshwater Fish
          pType.AddItemInHandsProfileIK("geb_Largemouthbass", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Smallmouthbass", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Walleye", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Perch", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Trout", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Trout_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_LakeTrout", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Bluegill", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Blackbass", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Sunfish",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Northernpike",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Catfish",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Sauger",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Whitebass",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Bowfin",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Slimysculpin",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Sockeyesalmon",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
          pType.AddItemInHandsProfileIK("geb_Chinooksalmon",  "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
    }
};