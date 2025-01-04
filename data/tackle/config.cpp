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
	class gebsTackleCfgPatches { 	
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
	class Rope;
	class Jig;
	class Worm;
	class NotCookable;
	class Edible_Base;
	class WaterBottle;
	class Container_Base;
	class Inventory_Base;
	class FoodAnimationSources;
	
    /*

		CONTAINERS

	*/
	class geb_Tackle_Base: Container_Base {
		scope = 2;
		displayName = "Tackle Base";
		descriptionShort = "Tackle Base Class";
		model = "gebsfish\data\tackle\geb_RedTackle.p3d";
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_redtackle.paa"};
		hiddenSelections[] = {"Camo"};
		rotationFlags = 8;
		weight = 140;
		itemSize[] = {3,2};
		itemsCargoSize[] = {9,1};
		canBeDigged = 1;
		absorbency = 0;
		isMeleeWeapon = 1;
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30,25};
		lootTag[] = {"Hunting","Work","Camping"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};

	class geb_RedTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_redtackle";
		descriptionShort = "$STR_tackle_desc";
		model = "gebsfish\data\tackle\geb_RedTackle.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_redtackle.paa"};
	};
	class geb_YellowTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_yellowtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] ={"gebsfish\data\tackle\geb_yellowtackle.paa"};
	};
	class geb_BlueTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_bluetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_bluetackle.paa"};
	};
	class geb_OrangeTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_orangetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_orangetackle.paa"};
	};
	class geb_BrownTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_browntackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_browntackle.paa"};
	};
	class geb_PurpleTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_purpletackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_purpletackle.paa"};
	};
	class geb_PinkTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_pinktackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_pinktackle.paa"};
	};
	class geb_LimeTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_limetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_limetackle.paa"};
	};
	class geb_LightBlueTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_lightbluetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_lightbluetackle.paa"};
	};
	class geb_GreenTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_greentackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_greentackle.paa"};
	};
	class geb_CamoTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_camotackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_camotackle.paa"};
	};
	class geb_FunYellowTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_funyellowtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funyellowtackle.paa"};
	};
	class geb_FunRedTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_funredtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funredtackle.paa"};
	};
	class geb_FunPurpleTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_funpurpletackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funpurpletackle.paa"};
	};
	class geb_FunGreenTackle: geb_Tackle_Base {
		scope = 2;
		displayName = "$STR_fungreentackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_fungreentackle.paa"};
	};
	class geb_SmallTackle: Container_Base {
		scope = 2;
		displayName = "$STR_smalltackle";
		descriptionShort = "$STR_smalltackle_desc";
		model = "\gebsfish\data\tackle\geb_smalltackle.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_smalltackle.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {2,1};
		itemsCargoSize[] = {6,1};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_WormContainer: Container_Base {
		scope = 2;
		displayName = "$STR_wormcontainer";
		descriptionShort = "$STR_wormcontainer_desc";
		model = "\gebsfish\data\tackle\geb_wormcontainer.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_wormcontainer.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {2,2};
		itemsCargoSize[] = {3,2};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_BugContainer: Container_Base {
		scope = 2;
		displayName = "$STR_bugcontainer";
		descriptionShort = "$STR_bugcontainer_desc";
		model = "\gebsfish\data\tools\geb_bugcontainer.p3d"; 
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_bugcontainer.paa"};
		itemInfo[] = {"CatchBugs"};
		rotationFlags = 12;
		weight = 140;
		itemSize[] = {1,3};
		itemsCargoSize[] = {10,1};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_MinnowBucket: WaterBottle {
		scope = 2;
		displayName = "$STR_minnowcontainer";
		descriptionShort = "$STR_minnowcontainer_desc";
		model = "\gebsfish\data\tackle\geb_minnowbucket.p3d";
		debug_ItemCategory = 6;
		weight = 25;
		itemSize[] = {3,3};
		itemsCargoSize[] = {4,4};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536	- (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 50;
					healthLevels[] = {
						{1,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},
						{0.7,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},
						{0.5,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},
						{0.3,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},
						{0,{"DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class WaterBottle_in_B {
					soundSet = "WaterBottle_in_B_SoundSet";
					id = 202;
				};
				class WaterBottle_in_C {
					soundSet = "WaterBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1 {
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterBottle_out_A {
					soundSet = "WaterBottle_out_A_SoundSet";
					id = 205;
				};
				class WaterBottle_out_B {
					soundSet = "WaterBottle_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "WaterBottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_OldGreenTackleBox: Container_Base {
		scope = 2;
		displayName = "$STR_oldgreentackle";
		descriptionShort = "$STR_tackle_desc";
		model = "\gebsfish\data\tackle\geb_old_greentackle.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_old_greentackle.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,2};
		itemsCargoSize[] = {3,2};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_OldRedTackleBox: Container_Base {
		scope = 2;
		displayName = "$STR_oldredtackle";
		descriptionShort = "$STR_tackle_desc";
		model = "\gebsfish\data\tackle\geb_old_redtackle.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_old_redtackle.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,2};
		itemsCargoSize[] = {3,2};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_OldBlueTackleBox: Container_Base {
		scope = 2;
		displayName = "$STR_oldbluetackle";
		descriptionShort = "$STR_tackle_desc";
		model = "\gebsfish\data\tackle\geb_old_bluetackle.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_old_bluetackle.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,2};
		itemsCargoSize[] = {3,2};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class geb_OldPurpleTackleBox: Container_Base {
		scope = 2;
		displayName = "$STR_oldpurpletackle";
		descriptionShort = "$STR_tackle_desc";
		model = "\gebsfish\data\tackle\geb_old_purpletackle.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_old_purpletackle.paa"};
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,2};
		itemsCargoSize[] = {3,2};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		repairableWithKits[] = {2};
		repairCosts[] = {25};
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},
						{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},
						{0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}
					};
				};
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class pickUpItem_Light {
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};


	/*

		INSECTS & BAITS

	*/
	class geb_GrassHopper: Worm {
		scope = 2;
		displayName = "$STR_grasshopper";
		descriptionShort = "$STR_grasshopper_desc";
		model = "\gebsfish\data\tackle\geb_grasshopper.p3d";
		rotationFlags = 17;
		weight = 21;
	};
	class geb_FieldCricket: Worm {
		scope = 2;
		displayName = "$STR_fieldcricket";
		descriptionShort = "$STR_fieldcricket_desc";
		model = "\gebsfish\data\tackle\geb_fieldcricket.p3d";
		rotationFlags = 17;
		weight = 21;
	};
	class geb_GrubWorm: Worm {
		scope=2;
		displayName = "$STR_grubworm";
		descriptionShort = "$STR_grubworm_desc";
		model = "\dz\gear\food\bait_worm.p3d";
		rotationFlags = 17;
	};
	class geb_RubberWorm: Worm {
		scope = 2;
		displayName = "$STR_rubberworm";
		descriptionShort = "$STR_rubberworm_desc";
		model = "\dz\gear\food\bait_worm.p3d";
		rotationFlags = 17;
	};

	/*

			HOOKS

	*/

	class geb_Lure: Jig
	{
	};
	class geb_SpinnerBait1: geb_Lure {
		scope = 2;
		displayName = "$STR_spinnerbait1";
		descriptionShort = "$STR_spinnerbait_desc";
		model = "\gebsfish\data\tackle\geb_SpinnerBait1.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait1.paa"};
		rotationFlags = 17;
		hookType = "geb_SpinnerBait1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SpinnerBait2: geb_SpinnerBait1 {
		scope = 2;
		displayName = "$STR_spinnerbait2";
		descriptionShort = "$STR_spinnerbait_desc";
		hookType = "geb_SpinnerBait2";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait2.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SpinnerBait3: geb_SpinnerBait1 {
		scope = 2;
		displayName = "$STR_spinnerbait3";
		descriptionShort = "$STR_spinnerbait_desc";
		hookType = "geb_SpinnerBait3";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait3.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SpinnerBait4: geb_SpinnerBait1 {
		scope = 2;
		displayName = "$STR_spinnerbait4";
		descriptionShort = "$STR_spinnerbait_desc";
		hookType = "geb_SpinnerBait4";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait4.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_Lure1: geb_Lure {
		scope = 2;
		displayName = "$STR_lure1";
		descriptionShort = "$STR_lure1_desc";
		model = "\gebsfish\data\tackle\lure1.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure1.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_Lure2: geb_Lure {
		scope = 2;
		displayName = "$STR_lure2";
		descriptionShort = "$STR_lure2_desc";
		model = "\gebsfish\data\tackle\lure2.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure2.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_Lure3: geb_Lure {
		scope = 2;
		displayName = "$STR_lure3";
		descriptionShort = "$STR_lure3_desc";
		model = "\gebsfish\data\tackle\lure3.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure3.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_Lure4: geb_Lure {
		scope = 2;
		displayName = "$STR_lure4";
		descriptionShort = "$STR_lure4_desc";
		model = "\gebsfish\data\tackle\lure4.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure3.paa"};
		rotationFlags = 12;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bait.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bait_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bait_destruct.rvmat"}}
					};
				};
			};
		};
	};

};