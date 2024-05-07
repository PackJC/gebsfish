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
	class NotCookable;
	class Edible_Base;
	class CarpFilletMeat;
	class MackerelFilletMeat;
	class FoodAnimationSources;

	class geb_FreshFish_Base: Edible_Base {
		scope = 2;
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
		scope = 2;
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
		scope = 2;
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
    /*

		FISH

	*/
	//Freshwater Fish
	class geb_Bluegill: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_bluegill";
		descriptionShort = "$STR_bluegill_desc";
		model = "\gebsfish\data\fish\bluegill.p3d";
		itemSize[] = {3,2};
	};
	class geb_Blackbass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_blackbass";
		descriptionShort = "$STR_blackbass_desc";
		model = "\gebsfish\data\fish\blackbass.p3d";
		rotationFlags = 17;
	};
	class geb_Catfish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_catfish";
		descriptionShort = "$STR_catfish_desc";
		model = "\gebsfish\data\fish\catfish.p3d";
		itemSize[] = {7,2};
		weight = 4000;
	};
	class geb_Walleye: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_walleye";
		descriptionShort = "$STR_walleye_desc";
		model = "\gebsfish\data\fish\walleye.p3d";
		itemSize[] = {4,2};
	};
	class geb_Sunfish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_sunfish";
		descriptionShort = "$STR_sunfish_desc";
		model = "\gebsfish\data\fish\sunfish.p3d";
		itemSize[] = {3,2};
	};
	class geb_Smallmouthbass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_smallmouthbass";
		descriptionShort = "$STR_smallmouthbass_desc";
		model = "\gebsfish\data\fish\smallmouthbass.p3d";
		itemSize[] = {3,2};
	};
	class geb_Largemouthbass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_largemouthbass";
		descriptionShort = "$STR_largemouthbass_desc";
		model = "\gebsfish\data\fish\largemouthbass.p3d";
	};
	class geb_Minnow: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_minnow";
		descriptionShort = "$STR_minnow_desc";
		model = "\gebsfish\data\fish\minnow.p3d";
		itemSize[] = {1,1};
		weight = 300;
		rotationFlags = 17;
	};
	class geb_Northernpike: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_northernpike";
		descriptionShort = "$STR_northernpike_desc";
		model = "\gebsfish\data\fish\northernpike.p3d";
		itemSize[] = {6,2};
		weight = 4000;
	};
	class geb_Perch: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_perch";
		descriptionShort = "$STR_perch_desc";
		model = "\gebsfish\data\fish\perch.p3d";
		itemSize[] = {4,3};
		weight = 3000;
	};
	class geb_Sauger: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_sauger";
		descriptionShort = "$STR_sauger_desc";
		model = "\gebsfish\data\fish\sauger.p3d";
		itemSize[] = {4,1};
		weight = 1500;
	};
	class geb_Crayfish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_crayfish";
		descriptionShort = "$STR_crayfish_desc";
		model = "\gebsfish\data\fish\Crayfish.p3d";
		itemSize[] = {2,1};
		weight = 200;
	};
	class geb_Trout_Base: geb_FreshFish_Base {
		scope = 2;
		model = "\gebsfish\data\fish\geb_Trout_Base.p3d";
	};
	class geb_Trout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_trout";
		descriptionShort = "$STR_trout_desc";
		model = "\gebsfish\data\fish\rainbowtrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rainbowtrout.paa"};
	};
	class geb_BrookTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_brooktrout";
		descriptionShort = "$STR_brooktrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\brooktrout.paa"};
	};
	class geb_BrownTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_browntrout";
		descriptionShort = "$STR_browntrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\browntrout.paa"};
	};
	class geb_CutthroatTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_cutthroattrout";
		descriptionShort = "$STR_cutthroattrout_desc";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cutthroattrout.paa"};
	};
	class geb_LakeTrout: geb_Trout_Base {
		scope = 2;
		displayName = "$STR_laketrout";
		descriptionShort = "$STR_laketrout_desc";
		model = "\gebsfish\data\fish\laketrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\laketrout.paa"};
	};
	class geb_Whitebass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_whitebass";
		descriptionShort = "$STR_whitebass_desc";
		model = "\gebsfish\data\fish\whitebass.p3d";
	};
	class geb_Bowfin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_bowfin";
		descriptionShort = "$STR_bowfin_desc";
		model = "\gebsfish\data\fish\bowfin.p3d";
		itemSize[] = {4,2};
		weight = 1500;
	};
	class geb_Slimysculpin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_slimysculpin";
		descriptionShort = "$STR_slimysculpin_desc";
		model = "\gebsfish\data\fish\slimysculpin.p3d";
		itemSize[] = {2,1};
		weight = 300;
	};
    //20 fresh water fish 11/19/2023

	//Saltwater Fish
	class geb_Angelfish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_angelfish";
		descriptionShort = "$STR_angelfish_desc";
		model = "\gebsfish\data\fish\angelfish.p3d";
		weight = 2500;
		itemSize[] = {4,3};
	};
	class geb_Asianseabass: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_asianseabass";
		descriptionShort = "$STR_asianseabass_desc";
		model = "\gebsfish\data\fish\asianseabass.p3d";
	};
	class geb_Bluemarlin: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_bluemarlin";
		descriptionShort = "$STR_bluemarlin_desc";
		model = "\gebsfish\data\fish\bluemarlin.p3d";
	};
	class geb_Sailfish: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_sailfish";
		descriptionShort = "$STR_sailfish_desc";
		model = "\gebsfish\data\fish\sailfish.p3d";
		itemSize[] = {20,7};
	};
	class geb_Mahimahi: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_mahimahi";
		descriptionShort = "$STR_mahimahi_desc";
		model = "\gebsfish\data\fish\mahimahi.p3d";
		itemSize[] = {18,8};
	};
	class geb_Bonita: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_bonita";
		descriptionShort = "$STR_bonita_desc";
		model = "\gebsfish\data\fish\bonita.p3d";
	};
	class geb_Cherrysalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_cherrysalmon";
		descriptionShort = "$STR_cherrysalmon_desc";
		model = "\gebsfish\data\fish\cherrysalmon.p3d";
	};
	class geb_Sockeyesalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_sockeyesalmon";
		descriptionShort = "$STR_sockeyesalmon_desc";
		model = "\gebsfish\data\fish\sockeyesalmon.p3d";
	};
	class geb_Chinooksalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_chinooksalmon";
		descriptionShort = "$STR_chinooksalmon_desc";
		model = "\gebsfish\data\fish\chinooksalmon.p3d";
	};
	class geb_Flatheadmullet: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_flatheadmullet";
		descriptionShort = "$STR_flatheadmullet_desc";
		model = "\gebsfish\data\fish\flatheadmullet.p3d";
		weight = 1000;
		itemSize[] = {2,1};
	};
	class geb_Leopardshark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_leopardshark";
		descriptionShort = "$STR_leopardshark_desc";
		model = "\gebsfish\data\fish\leopardshark.p3d";
		weight = 8000;
	};
	class geb_Pacificcod: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_pacificcod";
		descriptionShort = "$STR_pacificcod_desc";
		model = "\gebsfish\data\fish\pacificcod.p3d";
	};
	class geb_Redheadcichlid: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_redheadcichlid";
		descriptionShort = "$STR_redheadcichlid_desc";
		model = "\gebsfish\data\fish\redheadcichlid.p3d";
		weight = 3000;
		itemSize[] = {4,3};
	};
	class geb_Roughneckrock: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_roughneckrock";
		descriptionShort = "$STR_roughneckrock_desc";
		model = "\gebsfish\data\fish\roughneckrock.p3d";
		debug_ItemCategory = 6;
		weight = 3000;
		itemSize[] = {4,3};
		
	};
	class geb_Severum: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_severum";
		descriptionShort = "$STR_severum_desc";
		model = "\gebsfish\data\fish\severum.p3d";
		debug_ItemCategory = 6;
		weight = 3600;
		itemBehaviour = 0;
		itemSize[] = {5,4};
	};
	class geb_Shrimp: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_shrimp";
		descriptionShort = "$STR_shrimp_desc";
		model = "\gebsfish\data\fish\shrimp.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 200;
		itemSize[] = {2,1};
	};
	class geb_Bluetang: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_bluetang";
		descriptionShort = "$STR_bluetang_desc";
		model = "\gebsfish\data\fish\bluetang.p3d";
		debug_ItemCategory = 6;
		weight = 2000;
		itemSize[] = {4,3};
	};
	class geb_Hairtailfish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_hairtailfish";
		descriptionShort = "$STR_hairtailfish_desc";
		model = "\gebsfish\data\fish\hairtailfish.p3d";
		debug_ItemCategory = 6;
		weight = 800;
		itemSize[] = {4,1};
	};
	class geb_Humpheadwrasse: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_humpheadwrasse";
		descriptionShort = "$STR_humpheadwrasse_desc";
		model = "\gebsfish\data\fish\humpheadwrasse.p3d";
		debug_ItemCategory = 6;
		weight = 3500;
		itemSize[] = {5,4};
	};
	class geb_Siamesetigerfish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_siamesetigerfish";
		descriptionShort = "$STR_siamesetigerfish_desc";
		model = "\gebsfish\data\fish\siamesetigerfish.p3d";
		debug_ItemCategory = 6;
		weight = 2500;
		itemSize[] = {3,3};
	};
	class geb_Angelshark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_angelshark";
		descriptionShort = "$STR_angelshark_desc";
		model = "\gebsfish\data\fish\angelshark.p3d";
	};
	class geb_Greatwhiteshark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_greatwhiteshark";
		descriptionShort = "$STR_greatwhiteshark_desc";
		model = "\gebsfish\data\fish\greatwhiteshark.p3d";
	};
	class geb_Yellowfintuna: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_yellowfintuna";
		descriptionShort = "$STR_yellowfintuna_desc";
		model = "\gebsfish\data\fish\yellowfintuna.p3d";
	};
    //23 salt water fish 11/19/2023

	//Crustaceans Fish
	class geb_Bloodclam: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_bloodclam";
		descriptionShort = "$STR_bloodclam_desc";
		model = "\gebsfish\data\fish\bloodclam.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
		
	};
	class geb_Mussel: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_mussel";
		descriptionShort = "$STR_mussel_desc";
		model = "\gebsfish\data\fish\mussel.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_Blackdevilsnail: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_blackdevilsnail";
		descriptionShort = "$STR_blackdevilsnail_desc";
		model = "\gebsfish\data\fish\blackdevilsnail.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_Starfish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_starfish";
		descriptionShort = "$STR_starfish_desc";
		model = "\gebsfish\data\fish\starfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 2500;
		itemSize[] = {2,2};
	};
	class geb_Kingcrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_kingcrab";
		descriptionShort = "$STR_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrab.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
	};
	class geb_Jellyfish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_jellyfish";
		descriptionShort = "$STR_jellyfish_desc";
		model = "\gebsfish\data\fish\jellyfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 500;
		itemSize[] = {2,2};
	};
	class geb_Lobster: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_lobster";
		descriptionShort = "$STR_lobster_desc";
		model = "\gebsfish\data\fish\lobster.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,2};
	};
	class geb_Bluelobster: geb_Lobster {
		scope = 2;
		displayName = "Blue Lobster";
		descriptionShort = "$STR_bluelobster_desc";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,2};
		hiddenSelections[] = {"lobster"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluelobster_ca.paa"};
	};
	//8 crustaceans 11/19/2023
	//Freshwater Fish Fillets
	class geb_BluegillFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_bluegill_fillet";
		descriptionShort = "$STR_bluegill_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluegill_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BlackbassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_blackbass_fillet";
		descriptionShort = "$STR_blackbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\blackbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SmallmouthbassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_Smallmouthbass_fillet";
		descriptionShort = "$STR_Smallmouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\smallmouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WalleyeFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_walleye_fillet";
		descriptionShort = "$STR_walleye_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\walleye_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SunfishFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_sunfish_fillet";
		descriptionShort = "$STR_sunfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sunfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_CatfishFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_catfish_fillet";
		descriptionShort = "$STR_catfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\catfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LargemouthbassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_largemouthbass_fillet";
		descriptionShort = "$STR_largemouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\largemouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_MinnowFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_minnow_fillet";
		descriptionShort = "$STR_minnow_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
	};
	class geb_NorthernpikeFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_northernpike_fillet";
		descriptionShort = "$STR_northernpike_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernpike_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_PerchFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_perch_fillet";
		descriptionShort = "$STR_perch_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\perch_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SaugerFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_sauger_fillet";
		descriptionShort = "$STR_sauger_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sauger_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_CrayfishFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_crayfish_fillet";
		descriptionShort = "$STR_crayfish_desc";
		model = "\gebsfish\data\fish\crayfishtail.p3d";
	};
	class geb_TroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_trout_fillet";
		descriptionShort = "$STR_trout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\trout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BrownTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_browntrout_fillet";
		descriptionShort = "$STR_browntrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\browntrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BrookTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_brooktrout_fillet";
		descriptionShort = "$STR_brooktrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\brooktrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_CutthroatTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_cuthroattrout_fillet";
		descriptionShort = "$STR_cutthroattrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cutthroattrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LakeTroutFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_laketrout_fillet";
		descriptionShort = "$STR_laketrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\laketrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WhitebassFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_whitebass_fillet";
		descriptionShort = "$STR_whitebass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitebass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BowfinFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_bowfin_fillet";
		descriptionShort = "$STR_bowfin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bowfin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SlimysculpinFilletMeat: CarpFilletMeat {
		scope = 2;
		displayName = "$STR_slimysculpin_fillet";
		descriptionShort = "$STR_slimysculpin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\slimysculpin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};

	//Saltwater Fish fillets
	class geb_AngelfishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_angelfish_fillet";
		descriptionShort = "$STR_angelfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AsianseabassFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_asianseabass_fillet";
		descriptionShort = "$STR_asianseabass_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\asianseabass_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BluemarlinFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bluemarlin_fillet";
		descriptionShort = "$STR_bluemarlin_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SailfishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_sailfish_fillet";
		descriptionShort = "$STR_sailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_MahimahiFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_mahimahi_fillet";
		descriptionShort = "$STR_mahimahi_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\mahimahi_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BonitaFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bonita_fillet";
		descriptionShort = "$STR_bonita_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bonita_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_CherrysalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_cherrysalmon_fillet";
		descriptionShort = "$STR_cherrysalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cherrysalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SockeyesalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_sockeyesalmon_fillet";
		descriptionShort = "$STR_sockeyesalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sockeyesalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_ChinooksalmonFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_chinooksalmon_fillet";
		descriptionShort = "$STR_chinooksalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\chinooksalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_FlatheadmulletFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_flatheadmullet_fillet";
		descriptionShort = "$STR_flatheadmullet_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadmullet_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LeopardsharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_leopardshark_fillet";
		descriptionShort = "$STR_leopardshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\leopardshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_PacificcodFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_pacificcod_fillet";
		descriptionShort = "$STR_pacificcod_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\pacificcod_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_RedheadcichlidFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_redheadcichlid_fillet";
		descriptionShort = "$STR_redheadcichlid_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redheadcichlid_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_RoughneckrockFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_roughneckrock_fillet";
		descriptionShort = "$STR_roughneckrock_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\roughneckrock_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SeverumFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_severum_fillet";
		descriptionShort = "$STR_severum_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\severum_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_ShrimpFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_shrimp_fillet";
		descriptionShort = "$STR_shrimp_desc";
		model = "\gebsfish\data\fish\shrimptail.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\shrimp_ca.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BluetangFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bluetang_fillet";
		descriptionShort = "$STR_bluetang_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluetang_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_HairtailfishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_hairtailfish_fillet";
		descriptionShort = "$STR_hairtailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hairtailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_HumpheadwrasseFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_humpheadwrasse_fillet";
		descriptionShort = "$STR_humpheadwrasse_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\humpheadwrasse_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SiamesetigerfishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_siamesetigerfish_fillet";
		descriptionShort = "$STR_siamesetigerfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\siamesetigerfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_GreatwhitesharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_greatwhiteshark_fillet";
		descriptionShort = "$STR_greatwhiteshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\greatwhiteshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AngelsharkFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_angelfish_fillet";
		descriptionShort = "$STR_angelfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowFinTunaFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_yellowfintuna_fillet";
		descriptionShort = "$STR_yellowfintuna_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowfintuna_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};

	//Crustaceans Fish Fillets
	class geb_ClamFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bloodclam_fillet";
		descriptionShort = "$STR_bloodclam_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\clamfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_MusselFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_mussel_fillet";
		descriptionShort = "$STR_mussel_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\musselfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_KingcrabFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_kingcrab_fillet";
		descriptionShort = "$STR_kingcrab_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\kingcrabfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_KingcrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_kingcrab_legs";
		descriptionShort = "$STR_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrablegs.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\kingcrab.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_JellyfishFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_jellyfish_fillet";
		descriptionShort = "$STR_jellyfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\jellyfishfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LobsterFilletMeat: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_lobster_fillet";
		descriptionShort = "$STR_lobster_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\lobsterfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BlueLobsterFilletMeat : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bluelobster_fillet";
		descriptionShort = "$STR_bluelobster_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluelobsterfillet.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LobsterTail : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_lobster_tail";
		descriptionShort = "$STR_lobster_desc";
		model = "\gebsfish\data\fish\lobstertail.p3d";
		itemSize[] = {1,3};
	};
	class geb_BlueLobsterTail : MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_bluelobster_tail";
		descriptionShort = "$STR_bluelobster_desc";
		model = "\gebsfish\data\fish\lobstertail.p3d";
		hiddenSelections[] = {"shrimp"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluelobstertail.paa"};
		itemSize[] = {1,3};
	};
};
	