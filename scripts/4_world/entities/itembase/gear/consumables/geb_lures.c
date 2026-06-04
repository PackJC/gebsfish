// Script twins mirror the config (CfgVehicles) inheritance chain: geb_Lure
// extends Jig, and every lure/spinner/spoon/jig variant extends geb_Lure.
// Keeping the script hierarchy identical to the config means any future
// behaviour added to geb_Lure is inherited by all 16 variants (and the
// IsKindOf("geb_Lure") tackle-box filter stays correct).
class geb_Lure: Jig {};

class geb_SpinnerBait1: geb_Lure {};
class geb_SpinnerBait2: geb_Lure {};
class geb_SpinnerBait3: geb_Lure {};
class geb_SpinnerBait4: geb_Lure {};
class geb_Lure1: geb_Lure {};
class geb_Lure2: geb_Lure {};
class geb_Lure3: geb_Lure {};
class geb_Lure4: geb_Lure {};
class geb_SpoonLure1: geb_Lure {};
class geb_SpoonLure2: geb_Lure {};
class geb_SpoonLure3: geb_Lure {};
class geb_SpoonLure4: geb_Lure {};
class geb_CurlyTailJig1: geb_Lure {};
class geb_CurlyTailJig2: geb_Lure {};
class geb_CurlyTailJig3: geb_Lure {};
class geb_CurlyTailJig4: geb_Lure {};
