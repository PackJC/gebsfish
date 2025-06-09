/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

class CfgNonAIVehicles
{
	class StaticObject;
};

class CfgPatches
{
	class gebsFishCfgPatches { 	
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts"
		};
	};
};
class cfgVehicles
{		
	//Instantiate Needed Classes
	class Carp;
	class Shrimp;
	class NotCookable;
	class Edible_Base;
	class CarpFilletMeat;
	class MackerelFilletMeat;
	class FoodAnimationSources;

	//Base classes for fish
	class geb_FreshFish_Base: Edible_Base {
		scope = 0;
		itemSize[] = {5,2};
		weight = 1700;
		debug_ItemCategory = 6;
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 50;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		class MeleeModes {
			class Default {
				ammo = "MeleeSoft";
				range = 1;
			};
			class Heavy {
				ammo = "MeleeSoft_Heavy";
				range = 1;
			};
			class Sprint {
				ammo = "MeleeSoft_Heavy";
				range = 2.8;
			};
		};
		inventorySlot[] = {"TrapPrey_1"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\carp_live_co.paa","dz\gear\food\data\carp_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\carp_live.rvmat","dz\gear\food\data\carp_live.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,20,60,70,1};
					cooking_properties[] = {0,0};
				};
				class Rotten {
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood {
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen {
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake {
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd {
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};

	class geb_SaltFish_Base: Edible_Base {
		scope = 0;
		itemSize[] = {5,2};
		weight = 1700;
		debug_ItemCategory = 6;
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 50;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		class MeleeModes {
			class Default {
				ammo = "MeleeSoft";
				range = 1;
			};
			class Heavy {
				ammo = "MeleeSoft_Heavy";
				range = 1;
			};
			class Sprint {
				ammo = "MeleeSoft_Heavy";
				range = 2.8;
			};
		};
		inventorySlot[] = {"TrapPrey_1"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_live_co.paa","dz\gear\food\data\mackerel_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_live.rvmat","dz\gear\food\data\mackerel_live.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,20,60,70,1};
					cooking_properties[] = {0,0};
				};
				class Rotten {
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood {
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen {
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake {
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd {
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};

	class geb_LargeFish_Base: Edible_Base {
		scope = 0;
		debug_ItemCategory = 6;
		weight = 3700;
		itemSize[] = {25,8};
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 50;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		class MeleeModes {
			class Default {
				ammo = "MeleeSoft";
				range = 1;
			};
			class Heavy {
				ammo = "MeleeSoft_Heavy";
				range = 1;
			};
			class Sprint {
				ammo = "MeleeSoft_Heavy";
				range = 2.8;
			};
		};
		inventorySlot[] = {"TrapPrey_1"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_live_co.paa","dz\gear\food\data\mackerel_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_live.rvmat","dz\gear\food\data\mackerel_live.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {0,0};
				};
				class Rotten {
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood {
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen {
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake {
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd {
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
    class geb_Trout_Base: geb_FreshFish_Base {
		scope = 0;
		model = "\gebsfish\data\fish\geb_Trout_Base.p3d";
	};
	
	/*

		FISH

	*/
	//19 Freshwater Fish
	class geb_BlueGill: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_bluegill";
		descriptionShort = "$STR_fish_bluegill_desc";
		model = "\gebsfish\data\fish\bluegill.p3d";
		itemSize[] = {3,2};
	};
	class geb_BlackBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_blackbass";
		descriptionShort = "$STR_fish_blackbass_desc";
		model = "\gebsfish\data\fish\blackbass.p3d";
		rotationFlags = 17;
	};
	class geb_FlatHeadCatFish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\gebsfish\data\fish\flatheadcatfish.p3d";
		itemSize[] = {7,2};
		weight = 4000;
	};
	class geb_WallEye: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_walleye";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\gebsfish\data\fish\walleye.p3d";
		itemSize[] = {4,2};
	};
	class geb_SunFish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_sunfish";
		descriptionShort = "$STR_fish_sunfish_desc";
		model = "\gebsfish\data\fish\sunfish.p3d";
		itemSize[] = {3,2};
	};
	class geb_SmallMouthBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_smallmouthbass";
		descriptionShort = "$STR_fish_smallmouthbass_desc";
		model = "\gebsfish\data\fish\smallmouthbass.p3d";
		itemSize[] = {3,2};
	};
	class geb_LargeMouthBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_largemouthbass";
		descriptionShort = "$STR_fish_largemouthbass_desc";
		model = "\gebsfish\data\fish\largemouthbass.p3d";
	};
	class geb_FatHeadMinnow: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_fatheadminnow";
		descriptionShort = "$STR_fish_fatheadminnow_desc";
		model = "\gebsfish\data\fish\minnow.p3d";
		itemSize[] = {1,1};
		weight = 300;
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2"
		};
		class AnimationSources: FoodAnimationSources
		{
			class Bait_Hooked
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class Bait_Unhooked
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
		soundImpactType="organic";
		class Fishing
		{
			signalCycleTargetAdjustment=-12;
			signalCycleTargetEndAdjustment=-20;
			signalDurationMin=1.2;
			signalDurationMax=1.6;
			resultQuantityBaseMod=0;
			resultQuantityDispersionMin=0;
			resultQuantityDispersionMax=0;
			hookLossChanceMod=0;
			baitLossChanceMod=0;
		};
		class Trapping
		{
			baitTypes[]={1,2};
			baitTypeChances[]={0.75,0.050000001};
			resultQuantityBaseMod=0;
			resultQuantityDispersionMin=0;
			resultQuantityDispersionMax=0;
		};
	};
	class geb_NorthernPike: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_northernpike";
		descriptionShort = "$STR_fish_northernpike_desc";
		model = "\gebsfish\data\fish\northernpike.p3d";
		itemSize[] = {6,2};
		weight = 4000;
	};
	class geb_YellowPerch: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowperch";
		descriptionShort = "$STR_fish_yellowperch_desc";
		model = "\gebsfish\data\fish\perch.p3d";
		itemSize[] = {4,3};
		weight = 3000;
	};
	class geb_Sauger: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_sauger";
		descriptionShort = "$STR_fish_sauger_desc";
		model = "\gebsfish\data\fish\sauger.p3d";
		itemSize[] = {4,1};
		weight = 1500;
	};
	class geb_RainbowTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\gebsfish\data\fish\rainbowtrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rainbowtrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\rainbowtrout.rvmat"};
	};
	class geb_BrookTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_fish_brooktrout";
		descriptionShort = "$STR_fish_brooktrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\brooktrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\brooktrout.rvmat"};
	};
	class geb_BrownTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_fish_browntrout";
		descriptionShort = "$STR_fish_browntrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\browntrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\browntrout.rvmat"};
	};
	class geb_CutThroatTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_fish_cutthroattrout";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cutthroattrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\cutthroattrout.rvmat"};
	};
	class geb_LakeTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_fish_laketrout";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\gebsfish\data\fish\laketrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\laketrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\laketrout.rvmat"};
	};
	class geb_WhiteBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_whitebass";
		descriptionShort = "$STR_fish_whitebass_desc";
		model = "\gebsfish\data\fish\whitebass.p3d";
	};
	class geb_BowFin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_bowfin";
		descriptionShort = "$STR_fish_bowfin_desc";
		model = "\gebsfish\data\fish\bowfin.p3d";
		itemSize[] = {4,2};
		weight = 1500;
	};
	class geb_SlimySculpin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_slimysculpin";
		descriptionShort = "$STR_fish_slimysculpin_desc";
		model = "\gebsfish\data\fish\slimysculpin.p3d";
		itemSize[] = {2,1};
		weight = 300;
	};

	//22 Saltwater Fish
	class geb_AngelFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_angelfish";
		descriptionShort = "$STR_fish_angelfish_desc";
		model = "\gebsfish\data\fish\angelfish.p3d";
		weight = 2500;
		itemSize[] = {4,3};
	};
	class geb_AsianSeaBass: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_asianseabass";
		descriptionShort = "$STR_fish_asianseabass_desc";
		model = "\gebsfish\data\fish\asianseabass.p3d";
	};
	class geb_AtlanticBlueMarlin: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_atlanticbluemarlin";
		descriptionShort = "$STR_fish_atlanticbluemarlin_desc";
		model = "\gebsfish\data\fish\bluemarlin.p3d";
	};
	class geb_AtlanticSailFish: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\gebsfish\data\fish\sailfish.p3d";
		itemSize[] = {20,7};
	};
	class geb_MahiMahi: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_mahimahi";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\gebsfish\data\fish\mahimahi.p3d";
		itemSize[] = {18,8};
	};
	class geb_Bonita: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bonita";
		descriptionShort = "$STR_fish_bonita_desc";
		model = "\gebsfish\data\fish\bonita.p3d";
	};
	class geb_CherrySalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_cherrysalmon";
		descriptionShort = "$STR_fish_cherrysalmon_desc";
		model = "\gebsfish\data\fish\cherrysalmon.p3d";
	};
	class geb_SockEyeSalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_sockeyesalmon";
		descriptionShort = "$STR_fish_sockeyesalmon_desc";
		model = "\gebsfish\data\fish\sockeyesalmon.p3d";
	};
	class geb_ChinookSalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_chinooksalmon";
		descriptionShort = "$STR_fish_chinooksalmon_desc";
		model = "\gebsfish\data\fish\chinooksalmon.p3d";
	};
	class geb_FlatHeadMullet: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_flatheadmullet";
		descriptionShort = "$STR_fish_flatheadmullet_desc";
		model = "\gebsfish\data\fish\flatheadmullet.p3d";
		weight = 1000;
		itemSize[] = {2,1};
	};
	class geb_LeopardShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_leopardshark";
		descriptionShort = "$STR_fish_leopardshark_desc";
		model = "\gebsfish\data\fish\leopardshark.p3d";
		weight = 8000;
	};
	class geb_PacificCod: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_pacificcod";
		descriptionShort = "$STR_fish_pacificcod_desc";
		model = "\gebsfish\data\fish\pacificcod.p3d";
	};
	class geb_RedHeadCichlid: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_redheadcichlid";
		descriptionShort = "$STR_fish_redheadcichlid_desc";
		model = "\gebsfish\data\fish\redheadcichlid.p3d";
		weight = 3000;
		itemSize[] = {4,3};
	};
	class geb_RoughNeckRock: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_roughneckrock";
		descriptionShort = "$STR_fish_roughneckrock_desc";
		model = "\gebsfish\data\fish\roughneckrock.p3d";
		debug_ItemCategory = 6;
		weight = 3000;
		itemSize[] = {4,3};
		
	};
	class geb_Severum: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_severum";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\gebsfish\data\fish\severum.p3d";
		debug_ItemCategory = 6;
		weight = 3600;
		itemBehaviour = 0;
		itemSize[] = {5,4};
	};
	class geb_BlueTang: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bluetang";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\gebsfish\data\fish\bluetang.p3d";
		debug_ItemCategory = 6;
		weight = 2000;
		itemSize[] = {4,3};
	};
	class geb_LargeHeadHairTailFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\gebsfish\data\fish\hairtailfish.p3d";
		debug_ItemCategory = 6;
		weight = 800;
		itemSize[] = {4,1};
	};
	class geb_HumpHeadWrasse: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\gebsfish\data\fish\humpheadwrasse.p3d";
		debug_ItemCategory = 6;
		weight = 3500;
		itemSize[] = {5,4};
	};
	class geb_SiameseTigerFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\gebsfish\data\fish\siamesetigerfish.p3d";
		debug_ItemCategory = 6;
		weight = 2500;
		itemSize[] = {3,3};
	};
	class geb_AngelShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_angelshark";
		descriptionShort = "$STR_fish_angelshark_desc";
		model = "\gebsfish\data\fish\angelshark.p3d";
	};
	class geb_GreatWhiteShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_greatwhiteshark";
		descriptionShort = "$STR_fish_greatwhiteshark_desc";
		model = "\gebsfish\data\fish\greatwhiteshark.p3d";
	};
	class geb_YellowFinTuna: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowfintuna";
		descriptionShort = "$STR_fish_yellowfintuna_desc";
		model = "\gebsfish\data\fish\yellowfintuna.p3d";
	};

	//8 Saltwater crustaceans
	class geb_BloodClam: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bloodclam";
		descriptionShort = "$STR_fish_bloodclam_desc";
		model = "\gebsfish\data\fish\bloodclam.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_Mussel: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_mussel";
		descriptionShort = "$STR_fish_mussel_desc";
		model = "\gebsfish\data\fish\mussel.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_BlackDevilSnail: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_blackdevilsnail";
		descriptionShort = "$STR_fish_blackdevilsnail_desc";
		model = "\gebsfish\data\fish\blackdevilsnail.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_StarFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_starfish";
		descriptionShort = "$STR_fish_starfish_desc";
		model = "\gebsfish\data\fish\starfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 2500;
		itemSize[] = {2,2};
	};
	class geb_BlueJellyFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bluejellyfish";
		descriptionShort = "$STR_fish_bluejellyfish_desc";
		model = "\gebsfish\data\fish\jellyfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 500;
		itemSize[] = {2,2};
	};
	class geb_AmericanLobster: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"lobster"};
		model = "\gebsfish\data\fish\lobster.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,2};
	};	
	class geb_EuropeanLobster: geb_AmericanLobster {
		scope = 2;
		displayName = "$STR_fish_europeanlobster";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,2};
		hiddenSelections[] = {"lobster"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobster_ca.paa"};
	};
	class geb_KingCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_kingcrab";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrab.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
	};
	class geb_SnowCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_snowcrab";
		descriptionShort = "$STR_fish_snowcrab_desc";
		model = "\gebsfish\data\fish\snowcrab.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
	};
	//Freshwater crustaceans
	class  geb_EuropeanCrayFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_europeancrayfish";
		descriptionShort = "$STR_fish_europeancrayfish_desc";
		model = "\gebsfish\data\fish\Crayfish.p3d";
		itemSize[] = {1,2};
		weight = 200;
	};
	class  geb_SignalCrayFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_signalcrayfish";
		descriptionShort = "$STR_fish_signalcrayfish_desc";
		model = "\gebsfish\data\fish\Crayfish.p3d";
		itemSize[] = {1,2};
		weight = 200;
	};
	//Freshwater Fish Fillets
	class geb_BlueGillFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_bluegill_fillet";
		descriptionShort = "$STR_fish_bluegill_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluegill_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BlackBassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_blackbass_fillet";
		descriptionShort = "$STR_fish_blackbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\blackbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SmallMouthBassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_Smallmouthbass_fillet";
		descriptionShort = "$STR_fish_Smallmouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\smallmouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WallEyeFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_walleye_fillet";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\walleye_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SunFishFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_sunfish_fillet";
		descriptionShort = "$STR_fish_sunfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sunfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_FlatHeadCatFishFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish_fillet";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadcatfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LargeMouthBassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_largemouthbass_fillet";
		descriptionShort = "$STR_fish_largemouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\largemouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_FatHeadMinnowFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_fatheadminnow_fillet";
		descriptionShort = "$STR_fish_fatheadminnow_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
	};
	class geb_NorthernPikeFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_northernpike_fillet";
		descriptionShort = "$STR_fish_northernpike_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernpike_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowPerchFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_yellowperch_fillet";
		descriptionShort = "$STR_fish_yellowperch_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\perch_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SaugerFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_sauger_fillet";
		descriptionShort = "$STR_fish_sauger_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sauger_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_RainbowTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout_fillet";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\trout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BrownTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_browntrout_fillet";
		descriptionShort = "$STR_fish_browntrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\browntrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};

	};
	class geb_BrookTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_brooktrout_fillet";
		descriptionShort = "$STR_fish_brooktrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\brooktrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};

	};
	class geb_CutThroatTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_cuthroattrout_fillet";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cutthroattrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};

	};
	class geb_LakeTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_laketrout_fillet";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\laketrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WhiteBassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_whitebass_fillet";
		descriptionShort = "$STR_fish_whitebass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitebass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BowFinFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_bowfin_fillet";
		descriptionShort = "$STR_fish_bowfin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bowfin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SlimySculpinFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_fish_slimysculpin_fillet";
		descriptionShort = "$STR_fish_slimysculpin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\slimysculpin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};

	//Saltwater Fish fillets
	class geb_AngelFishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_angelfish_fillet";
		descriptionShort = "$STR_fish_angelfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AsianSeaBassFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_asianseabass_fillet";
		descriptionShort = "$STR_fish_asianseabass_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\asianseabass_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AtlanticBlueMarlinFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_atlanticbluemarlin_fillet";
		descriptionShort = "$STR_fish_atlanticbluemarlin_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AtlanticSailFishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish_fillet";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_MahiMahiFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_mahimahi_fillet";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\mahimahi_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BonitaFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_bonita_fillet";
		descriptionShort = "$STR_fish_bonita_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bonita_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_CherrySalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_cherrysalmon_fillet";
		descriptionShort = "$STR_fish_cherrysalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cherrysalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SockEyeSalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_sockeyesalmon_fillet";
		descriptionShort = "$STR_fish_sockeyesalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sockeyesalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_ChinookSalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_chinooksalmon_fillet";
		descriptionShort = "$STR_fish_chinooksalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\chinooksalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_FlatHeadMulletFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_flatheadmullet_fillet";
		descriptionShort = "$STR_fish_flatheadmullet_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadmullet_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LeopardSharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_leopardshark_fillet";
		descriptionShort = "$STR_fish_leopardshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\leopardshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_PacificCodFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_pacificcod_fillet";
		descriptionShort = "$STR_fish_pacificcod_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\pacificcod_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_RedHeadCichlidFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_redheadcichlid_fillet";
		descriptionShort = "$STR_fish_redheadcichlid_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redheadcichlid_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_RoughNeckRockFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_roughneckrock_fillet";
		descriptionShort = "$STR_fish_roughneckrock_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\roughneckrock_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SeverumFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_severum_fillet";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\severum_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};

	class geb_BlueTangFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_bluetang_fillet";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluetang_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LargeHeadHairTailFishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish_fillet";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hairtailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_HumpHeadWrasseFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse_fillet";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\humpheadwrasse_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SiameseTigerFishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish_fillet";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\siamesetigerfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_GreatWhiteSharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_greatwhiteshark_fillet";
		descriptionShort = "$STR_fish_greatwhiteshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\greatwhiteshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AngelSharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_angelshark_fillet";
		descriptionShort = "$STR_fish_angelshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowFinTunaFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_yellowfintuna_fillet";
		descriptionShort = "$STR_fish_yellowfintuna_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowfintuna_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};

	//Crustacean Fillets
	class geb_KingCrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_kingcrab_legs";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrablegs.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\kingcrab.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SnowCrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_snowcrab_legs";
		descriptionShort = "$STR_fish_snowcrab_desc";
		model = "\gebsfish\data\fish\snowcrablegs.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\kingcrab.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BlueJellyFishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_bluejellyfish_fillet";
		descriptionShort = "$STR_fish_bluejellyfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\jellyfishfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AmericanLobsterTail : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_americanlobster_tail";
		descriptionShort = "$STR_fish_americanlobster_desc";
		model = "\gebsfish\data\fish\lobstertail.p3d";
		itemSize[] = {1,3};
	};
	class geb_EuropeanLobsterTail : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_tail";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		model = "\gebsfish\data\fish\lobstertail.p3d";
		hiddenSelections[] = {"lobster"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobstertail.paa"};
		itemSize[] = {1,3};
	};	
	class geb_AmericanLobsterClaw : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_americanlobster_claw";
		descriptionShort = "$STR_fish_americanlobster_desc";
		model = "\gebsfish\data\fish\lobsterclaw.p3d";
		itemSize[] = {2,2};
	};
	class geb_EuropeanLobsterClaw : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_claw";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		model = "\gebsfish\data\fish\lobsterclaw.p3d";
		hiddenSelections[] = {"lobster"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobstertail.paa"};
		itemSize[] = {2,2};

	};
};
	