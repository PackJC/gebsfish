/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

modded class ModItemRegisterCallbacks {
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior) {
        super.RegisterTwoHanded(pType, pBehavior);

        // Large fish carried with both hands (firewood-style carry).
        TStringArray twoHandedFish = {
            "geb_GreatWhiteShark", "geb_AngelShark", "geb_LeopardShark", "geb_HammerHeadShark",
            "geb_HumpHeadWrasse", "geb_AtlanticBlueMarlin", "geb_MahiMahi", "geb_AtlanticSailFish",
            "geb_LargeHeadHairTailFish", "geb_BlueTang", "geb_AngelFish", "geb_RedHeadCichlid",
            "geb_Severum", "geb_SiameseTigerFish", "geb_AlligatorGar", "geb_NorthernPike",
            "geb_Muskellunge", "geb_TigerMuskellunge", "geb_BarredMuskellunge", "geb_SpottedMuskellunge",
            "geb_FlatHeadCatFish", "geb_LakeSturgeon", "geb_NorthernSnakeHead", "geb_SouthernFlounder"
        };
        foreach (string twoHandedName : twoHandedFish) {
            pType.AddItemInHandsProfileIK(twoHandedName, "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
        }
    }

    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior) {
        super.RegisterOneHanded(pType, pBehavior);

        // Medium fish held one-handed (carp-style carry).
        TStringArray oneHandedFish = {
            "geb_LargeMouthBass", "geb_SmallMouthBass", "geb_WhiteBass", "geb_BlackBass",
            "geb_NeoshoBass", "geb_StripedBass", "geb_Sauger", "geb_RainbowTrout",
            "geb_BrookTrout", "geb_BrownTrout", "geb_CutThroatTrout", "geb_LakeTrout",
            "geb_SockEyeSalmon", "geb_ChinookSalmon", "geb_WallEye", "geb_YellowPerch",
            "geb_BowFin", "geb_BlueGill", "geb_AsianSeaBass", "geb_FlatHeadMullet",
            "geb_CherrySalmon", "geb_Bonita", "geb_PacificCod", "geb_YellowFinTuna",
            "geb_YellowSnapper", "geb_WhiteGrunt", "geb_RoughNeckRock", "geb_SunFish",
            "geb_SlimySculpin", "geb_AmericanLobster", "geb_EuropeanLobster"
        };
        foreach (string fishName : oneHandedFish) {
            pType.AddItemInHandsProfileIK(fishName, "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/carp_live.anm");
        }

        // Small / passive species (shrimp-style palm carry).
        // NOTE: geb_KingCrab and geb_SnowCrab still need to be added here --
        // they currently have no in-hands profile at all.
        TStringArray oneHandedSmall = {
            "geb_StarFish", "geb_BlackDevilSnail", "geb_Mussel", "geb_BloodClam",
            "geb_FatHeadMinnow", "geb_AmericanBullFrog", "geb_RedSalamander", "geb_BlueJellyFish",
            "geb_SignalCrayFish", "geb_EuropeanCrayFish", "geb_FloridaCrayFish", "geb_RedSwampCrayFish",
            "geb_CaveCrayFish", "geb_RustyCrayFish", "geb_MonongahelaCrayFish"
        };
        foreach (string smallName : oneHandedSmall) {
            pType.AddItemInHandsProfileIK(smallName, "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/shrimp.anm");
        }
    }
};
