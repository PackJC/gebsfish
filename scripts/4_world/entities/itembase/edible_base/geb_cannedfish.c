/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Canned fish (data/food). Every vanilla can names its own opened class in
// Open(), so a can built on one would open into the vanilla can (tuna,
// sardines, pate, pork...). Each closed can here opens into its own class
// instead, its name plus "_Opened" (geb_SpratsCan -> geb_SpratsCan_Opened).
// The opened classes need no script: they run as the vanilla opened can
// they're built on (eating, rotting once open).
//
// One base per vanilla can, and each can's own script class (the engine runs
// the script class with the config name) extends its base.

class geb_TunaCan_Base extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_SardinesCan_Base extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_Pajka_Base extends Pajka {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_Pate_Base extends Pate {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_BrisketSpread_Base extends BrisketSpread {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_PorkCan_Base extends PorkCan {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

class geb_Lunchmeat_Base extends Lunchmeat {
    override void Open() {
        ReplaceEdibleWithNew(GetType() + "_Opened");
    }
}

// Flat tins: ring pull, opened by hand (vanilla's ActionOpen).
class geb_SpratsCan extends geb_TunaCan_Base {}
class geb_AnchoviesCan extends geb_TunaCan_Base {}
class geb_KipperSnacksCan extends geb_TunaCan_Base {}
class geb_MackerelTomatoCan extends geb_TunaCan_Base {}
class geb_SmokedTroutCan extends geb_TunaCan_Base {}
class geb_SmokedMusselsCan extends geb_TunaCan_Base {}
class geb_SmokedOystersCan extends geb_TunaCan_Base {}
class geb_SquidInkCan extends geb_TunaCan_Base {}

// Round cans: opened with a tool (vanilla's OpenCan recipe, which takes any SardinesCan).
class geb_SalmonCan extends geb_SardinesCan_Base {}
class geb_CodLiverCan extends geb_SardinesCan_Base {}
class geb_SauryCan extends geb_SardinesCan_Base {}
class geb_CrabMeatCan extends geb_SardinesCan_Base {}
class geb_BonitoCan extends geb_SardinesCan_Base {}
class geb_CaviarCan extends geb_SardinesCan_Base {}
class geb_MincedClamsCan extends geb_SardinesCan_Base {}

// Pate tins (vanilla FoodCan_100g) and 250 g ring-pull cans: opened by hand (vanilla's ActionOpen).
class geb_CodRoeSpread extends geb_Pajka_Base {}
class geb_SalmonPate extends geb_Pate_Base {}
class geb_SmokedFishSpread extends geb_BrisketSpread_Base {}
class geb_FishSoupCan extends geb_PorkCan_Base {}
class geb_ClamChowderCan extends geb_PorkCan_Base {}
class geb_FishBallsCan extends geb_Lunchmeat_Base {}
class geb_HerringMustardCan extends geb_Lunchmeat_Base {}
