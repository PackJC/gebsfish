/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Canned fish (data/food). Every vanilla can names its own opened class in
// Open(), so a can built on one would open into the vanilla can (tuna,
// sardines, pate, pork...). Each closed can here opens into its own _Opened
// class instead. The opened classes need no script: they run as the vanilla
// opened can they're built on (eating, rotting once open).

// Flat tins: ring pull, opened by hand (vanilla's ActionOpen).
class geb_SpratsCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SpratsCan_Opened");
    }
}

class geb_AnchoviesCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_AnchoviesCan_Opened");
    }
}

class geb_KipperSnacksCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_KipperSnacksCan_Opened");
    }
}

class geb_MackerelTomatoCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_MackerelTomatoCan_Opened");
    }
}

class geb_SmokedTroutCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SmokedTroutCan_Opened");
    }
}

class geb_SmokedMusselsCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SmokedMusselsCan_Opened");
    }
}

class geb_SmokedOystersCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SmokedOystersCan_Opened");
    }
}

class geb_SquidInkCan extends TunaCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SquidInkCan_Opened");
    }
}

// Round cans: opened with a tool (vanilla's OpenCan recipe, which takes any SardinesCan).
class geb_SalmonCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SalmonCan_Opened");
    }
}

class geb_CodLiverCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_CodLiverCan_Opened");
    }
}

class geb_SauryCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_SauryCan_Opened");
    }
}

class geb_CrabMeatCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_CrabMeatCan_Opened");
    }
}

class geb_BonitoCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_BonitoCan_Opened");
    }
}

class geb_CaviarCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_CaviarCan_Opened");
    }
}

class geb_MincedClamsCan extends SardinesCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_MincedClamsCan_Opened");
    }
}

// Pate tins (vanilla FoodCan_100g) and 250 g ring-pull cans: opened by hand (vanilla's ActionOpen).
class geb_CodRoeSpread extends Pajka {
    override void Open() {
        ReplaceEdibleWithNew("geb_CodRoeSpread_Opened");
    }
}

class geb_SalmonPate extends Pate {
    override void Open() {
        ReplaceEdibleWithNew("geb_SalmonPate_Opened");
    }
}

class geb_SmokedFishSpread extends BrisketSpread {
    override void Open() {
        ReplaceEdibleWithNew("geb_SmokedFishSpread_Opened");
    }
}

class geb_FishSoupCan extends PorkCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_FishSoupCan_Opened");
    }
}

class geb_ClamChowderCan extends PorkCan {
    override void Open() {
        ReplaceEdibleWithNew("geb_ClamChowderCan_Opened");
    }
}

class geb_FishBallsCan extends Lunchmeat {
    override void Open() {
        ReplaceEdibleWithNew("geb_FishBallsCan_Opened");
    }
}

class geb_HerringMustardCan extends Lunchmeat {
    override void Open() {
        ReplaceEdibleWithNew("geb_HerringMustardCan_Opened");
    }
}
