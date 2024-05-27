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
	class Bait;
	class Worm;
	class Hook;
	class Rope;
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

		ITEMS

	*/
	class geb_BigGameFishingline: Rope {
		scope = 2;
		displayName = "$STR_gameline";
		descriptionShort = "$STR_gameline_desc";
		model = "\gebsfish\data\tackle\geb_fishingline_biggame.p3d";
		OnRestrainChange = "RopeLocked";
		RestrainTime = 10;
		rotationFlags = 17;
		itemSize[] = {2,2};
		inventorySlot[] = {"Rope","Material_FPole_Rope","Material_Shelter_Rope"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_fishingline_biggame.paa"};
		override void SetActions()
		{
			super.SetActions();
  
			AddAction(ActionRepairRod);
		}
	};
	class geb_SaltwaterFishingLine: Rope {
		scope = 2;
		displayName = "$STR_saltline";
		descriptionShort = "$STR_saltline_desc";
		model = "\gebsfish\data\tackle\geb_fishingline_saltwater.p3d";
		OnRestrainChange = "RopeLocked";
		RestrainTime = 10;
		rotationFlags = 17;
		itemSize[] = {2,2};
		inventorySlot[] = {"Rope","Material_FPole_Rope","Material_Shelter_Rope"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_fishingline_saltwater.paa"};
		override void SetActions()
		{
			super.SetActions();
  
			AddAction(ActionRepairRod);
		}
	};
	class geb_FlyFishingLine: Rope {
		scope = 2;
		displayName = "$STR_flyline";
		descriptionShort = "$STR_flyline_desc";
		model = "\gebsfish\data\tackle\geb_fishingline_flyfishing.p3d";
		OnRestrainChange = "RopeLocked";
		RestrainTime = 10;
		rotationFlags = 17;
		itemSize[] = {2,2};
		inventorySlot[] = {"Rope","Material_FPole_Rope","Material_Shelter_Rope"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_fishingline_flyfishing.paa"};
		override void SetActions()
		{
			super.SetActions();
  
			AddAction(ActionRepairRod);
		}
	};
	class Bobber_ColorBase: Inventory_Base {
		scope = 0;
		model = "\gebsfish\data\tackle\geb_bobber1.p3d";
		animClass = "NoFireClass";
		weight = 50;
		itemSize[] = {1,1};
		rotationFlags = 17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 100;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\stone.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\stone.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\stone_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\stone_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\stone_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_Bobber1: Bobber_ColorBase	{
		scope = 2;
		displayName = "$STR_bobber1";
		descriptionShort = "$STR_bobber_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] ={"\gebsfish\data\tackle\geb_bobber1.paa"};
	};
	class geb_Bobber2: Bobber_ColorBase	{
		scope = 2;
		displayName = "$STR_bobber2";
		descriptionShort = "$STR_bobber_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bobber2.paa"};
	};
	class geb_Bobber3: Bobber_ColorBase	{
		scope = 2;
		displayName = "$STR_bobber3";
		descriptionShort = "$STR_bobber_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bobber3.paa"};
	};
	class geb_Bobber4: Bobber_ColorBase	{
		scope = 2;
		displayName = "$STR_bobber4";
		descriptionShort = "$STR_bobber_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bobber4.paa"};
	};

	/*

		INSECTS & BAITS

	*/
	class geb_GrassHopper: Edible_Base {
		scope = 2;
		displayName = "$STR_grasshopper";
		descriptionShort = "$STR_grasshopper_desc";
		model = "\gebsfish\data\tackle\geb_grasshopper.p3d";
		rotationFlags = 17;
		weight = 21;
		stackedUnit = "";
		canBeSplit = 0;
		quantityBar = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		inventorySlot[] = {"Trap_Bait"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=10;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		hiddenSelections[]={"cs_raw"};
		hiddenSelectionsTextures[]={"dz\gear\tackle\data\bait_co.paa"};
		hiddenSelectionsMaterials[]={"dz\gear\tackle\data\bait.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
		class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood {
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen {
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake {
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd {
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class geb_FieldCricket : Edible_Base {
		scope = 2;
		displayName = "$STR_fieldcricket";
		descriptionShort = "$STR_fieldcricket_desc";
		model = "\gebsfish\data\tackle\geb_fieldcricket.p3d";
		rotationFlags = 17;
		weight = 21;
		stackedUnit = "";
		canBeSplit = 0;
		quantityBar = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		inventorySlot[] = {"Trap_Bait"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\tackle\data\bait_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\tackle\data\bait.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
		class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood {
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen {
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake {
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd {
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class geb_GrubWorm: Edible_Base {
		scope=2;
		displayName = "$STR_grubworm";
		descriptionShort = "$STR_grubworm_desc";
		model = "\dz\gear\food\bait_worm.p3d";
		rotationFlags = 17;
		weight = 21;
		stackedUnit = "";
		canBeSplit = 0;
		quantityBar = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		inventorySlot[] = {"Trap_Bait"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_grubworm.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\tackle\data\bait.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
		class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood {
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen {
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake {
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd {
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class geb_RubberWorm: Edible_Base {
		scope = 2;
		displayName = "$STR_rubberworm";
		descriptionShort = "$STR_rubberworm_desc";
		model = "\dz\gear\food\bait_worm.p3d";
		rotationFlags = 17;
		weight = 21;
		stackedUnit = "";
		canBeSplit = 0;
		quantityBar = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		inventorySlot[] = {"Trap_Bait"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[]={{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_rubberworm.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\tackle\data\bait.rvmat"};
		class AnimationSources: FoodAnimationSources {};
		class Food {
			class FoodStages {
				class Raw {
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
		class FoodStageTransitions: NotCookable {};
		};
		class AnimEvents {
			class SoundWeapon {
				class openTunaCan {
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood {
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen {
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake {
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd {
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};

	/*

		BAITS W\ WORM

	*/
	//Metal Hooks
	class geb_metalhook_baited_worm: Inventory_Base {
		scope = 0;
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
	}
	class geb_metalhook_baited_grasshopper: Inventory_Base {
		scope = 0;
		model = "\gebsfish\data\tackle\geb_metalhook_baited_grasshopper.p3d";
	};
	class geb_metalhook_baited_fieldcricket: Inventory_Base {
		scope = 0;
		model = "\gebsfish\data\tackle\geb_metalhook_baited_fieldcricket.p3d";
	};
	class geb_metalhook_baited_minnow: Inventory_Base {
		scope = 0;
		model = "\gebsfish\data\tackle\geb_metalhook_baited_minnow.p3d";
	};

	class geb_MetalHook: Inventory_Base {
		scope = 2;
		displayName = "$STR_metalhook";
		descriptionShort = "$STR_metalhook_desc";
		model = "\gebsfish\data\tackle\geb_metalhook.p3d";
		weight = 1;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 10;
					healthLevels[] = {
						{1,{"DZ\gear\consumables\data\bone_hook.rvmat"}},
						{0.7,{"DZ\gear\consumables\data\bone_hook.rvmat"}},
						{0.5,{"DZ\gear\consumables\data\bone_hook_damage.rvmat"}},
						{0.3,{"DZ\gear\consumables\data\bone_hook_damage.rvmat"}},
						{0,{"DZ\gear\consumables\data\bone_hook_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_MetalHookBobberBase: Inventory_Base {
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\gebsfish\data\tackle\geb_MetalHookBobberBase.p3d";
		weight = 1;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};		
		rotationFlags = 12;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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

	class geb_MetalHookBobber1: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_metalhookbobber1";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1.paa"};
	};
	class geb_MetalHookBobber2: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_metalhookbobber2";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2.paa"};
	};
	class geb_MetalHookBobber3: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_metalhookbobber3";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3.paa"};
	};
	class geb_MetalHookBobber4: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_metalhookbobber4";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4.paa"};
	};

	class geb_MetalHookBobberWormBaitBase: Inventory_Base {
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\gebsfish\data\tackle\geb_MetalHookBobberWormBaitBase.p3d";
		weight = 1;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalHookBobberGrassHopperBaitBase: Inventory_Base {
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\gebsfish\data\tackle\geb_MetalHookBobberGrassHopperBaitBase.p3d";
		weight = 1;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalHookBobberMinnowBaitBase: Inventory_Base {
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\gebsfish\data\tackle\geb_MetalHookBobberMinnowBaitBase.p3d";
		weight = 1;
		absorbency = 0.80;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_minnow.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalHookBobberFieldCricketBaitBase: Inventory_Base {
		scope = 0;
		displayName = "";
		descriptionShort = "";
		model = "\gebsfish\data\tackle\geb_MetalHookBobberFieldCricketBaitBase.p3d";
		weight = 1;
		absorbency = 0.80;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};

	class geb_MetalHookBobber1WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1wormbait";
		descriptionShort	= "$STR_metalhookbobberwormbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_worm.paa"};
	};
	class geb_MetalHookBobber2WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2wormbait";
		descriptionShort	= "$STR_metalhookbobberwormbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_worm.paa"};
	};
	class geb_MetalHookBobber3WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3wormbait";
		descriptionShort	= "$STR_metalhookbobberwormbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_worm.paa"};
	};
	class geb_MetalHookBobber4WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4wormbait";
		descriptionShort	= "$STR_metalhookbobberwormbait_desc";
		hookType = "geb_MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_worm.paa"};
	};

	class geb_MetalHookBobber1RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1rubberwormbait";
		descriptionShort	= "$STR_metalhookbobberrubberwormbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_rubberworm.paa"};
	};
	class geb_MetalHookBobber2RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2rubberwormbait";
		descriptionShort	= "$STR_metalhookbobberrubberwormbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_rubberworm.paa"};
	};
	class geb_MetalHookBobber3RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3rubberwormbait";
		descriptionShort	= "$STR_metalhookbobberrubberwormbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_rubberworm.paa"};
	};
	class geb_MetalHookBobber4RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4rubberwormbait";
		descriptionShort	= "$STR_metalhookbobberrubberwormbait_desc";
		hookType = "geb_MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_rubberworm.paa"};
	};

	class geb_MetalHookBobber1GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1grubwormbait";
		descriptionShort	= "$STR_metalhookbobbergrubwormbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_grubworm.paa"};
	};
	class geb_MetalHookBobber2GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2grubwormbait";
		descriptionShort	= "$STR_metalhookbobbergrubwormbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_grubworm.paa"};
	};
	class geb_MetalHookBobber3GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3grubwormbait";
		descriptionShort	= "$STR_metalhookbobbergrubwormbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_grubworm.paa"};
	};
	class geb_MetalHookBobber4GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4grubwormbait";
		descriptionShort	= "$STR_metalhookbobbergrubwormbait_desc";
		hookType = "geb_MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_grubworm.paa"};
	};

	class geb_MetalHookBobber1GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1grasshopperbait";
		descriptionShort	= "$STR_metalhookbobbergrasshopperbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_grasshopper.paa"};
	};
	class geb_MetalHookBobber2GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2grasshopperbait";
		descriptionShort	= "$STR_metalhookbobbergrasshopperbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_grasshopper.paa"};
	};
	class geb_MetalHookBobber3GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3grasshopperbait";
		descriptionShort	= "$STR_metalhookbobbergrasshopperbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_grasshopper.paa"};
	};
	class geb_MetalHookBobber4GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4grasshopperbait";
		descriptionShort	= "$STR_metalhookbobbergrasshopperbait_desc";
		hookType = "geb_MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_grasshopper.paa"};
	};

	class geb_MetalHookBobber1MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1minnowbait";
		descriptionShort	= "$STR_metalhookbobberminnowbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_minnow.paa"};
	};
	class geb_MetalHookBobber2MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2minnowbait";
		descriptionShort	= "$STR_metalhookbobberminnowbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_minnow.paa"};
	};
	class geb_MetalHookBobber3MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3minnowbait";
		descriptionShort	= "$STR_metalhookbobberminnowbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_minnow.paa"};
	};
	class geb_MetalHookBobber4MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4minnowbait";
		descriptionShort	= "$STR_metalhookbobberminnowbait_desc";
		hookType = "geb_MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_minnow.paa"};
	};

	class geb_MetalHookBobber1FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber1fieldcricketbait";
		descriptionShort	= "$STR_metalhookbobberfieldcricketbait_desc";
		hookType = "geb_MetalHookBobber1";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber1_baited_fieldcricket.paa"};
	};
	class geb_MetalHookBobber2FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber2fieldcricketbait";
		descriptionShort	= "$STR_metalhookbobberfieldcricketbait_desc";
		hookType = "geb_MetalHookBobber2";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber2_baited_fieldcricket.paa"};
	};
	class geb_MetalHookBobber3FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber3fieldcricketbait";
		descriptionShort	= "$STR_metalhookbobberfieldcricketbait_desc";
		hookType = "geb_MetalHookBobber3";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber3_baited_fieldcricket.paa"};
	};
	class geb_MetalHookBobber4FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_metalhookbobber4fieldcricketbait";
		descriptionShort	= "$STR_metalhookbobberfieldcricketbait_desc";
		hookType = "MetalHookBobber4";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhookbobber4_baited_fieldcricket.paa"};
	};

	class geb_MetalRubberWormBait: Inventory_Base {
		scope = 2;
		displayName			= "$STR_metalhookrubberwormbait";
		descriptionShort	= "$STR_metalhookrubberwormbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		rotationFlags = 17;
		hookType = "MetalHook";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_rubberworm.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalGrubWormBait: Inventory_Base {
		scope = 2;
		displayName			= "$STR_metalhookgrubwormbait";
		descriptionShort	= "$STR_metalhookgrubwormbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_grubworm.paa"};
		rotationFlags = 17;
		hookType = "MetalHook";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalGrassHopperBait: geb_metalhook_baited_grasshopper {
		scope = 2;
		displayName			= "$STR_metalhookgrasshopperbait";
		descriptionShort	= "$STR_metalhookgrasshopperbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_grasshopper.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_grasshopper.paa"};
		rotationFlags = 17;
		hookType = "MetalHook";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalFieldCricketBait: geb_metalhook_baited_fieldcricket {
		scope = 2;
		displayName			= "$STR_metalhookfieldcricketbait";
		descriptionShort	= "$STR_metalhookfieldcricketbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_fieldcricket.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_fieldcricket.paa"};
		rotationFlags = 17;
		hookType = "MetalHook";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalWormBait: Inventory_Base {
		scope = 2;
		displayName			= "$STR_metalhookwormbait";
		descriptionShort	= "$STR_metalhookwormbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_worm.paa"};
		rotationFlags = 17;
		hookType = "MetalHook";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_MetalMinnowBait: geb_metalhook_baited_minnow {
		scope = 2;
		displayName			= "$STR_metalhookminnowbait";
		descriptionShort	= "$STR_metalhookminnowbait_desc";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_minnow.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_metalhook_baited_minnow.paa"};
		rotationFlags = 17;
		hookType = "MetalHook";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 30;
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};

	//Bone Hooks
	class geb_BoneHookBobber1: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_bonehookbobber1";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1.paa"};
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
	class geb_BoneHookBobber2: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_bonehookbobber2";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2.paa"};
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
	class geb_BoneHookBobber3: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_bonehookbobber3";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3.paa"};
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
	class geb_BoneHookBobber4: geb_MetalHookBobberBase {
		scope = 2;
		displayName = "$STR_bonehookbobber4";
		descriptionShort = "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4.paa"};
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

	class geb_BoneHookBobber1WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1wormbait";
		descriptionShort	= "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_worm.paa"};
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
		hookType = "geb_BoneHookBobber1";
	};
	class geb_BoneHookBobber2WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2wormbait";
		descriptionShort	= "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_worm.paa"};
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
		hookType = "geb_BoneHookBobber2";
	};
	class geb_BoneHookBobber3WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3wormbait";
		descriptionShort	= "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_worm.paa"};
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
		hookType = "geb_BoneHookBobber3";
	};
	class geb_BoneHookBobber4WormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4wormbait";
		descriptionShort	= "$STR_hookbobber_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_worm.paa"};
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
		hookType = "geb_BoneHookBobber4";
	};

	class geb_BoneHookBobber1RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1rubberwormbait";
		descriptionShort	= "$STR_bonehookbobberrubberwormbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_rubberworm.paa"};
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
		hookType = "geb_BoneHookBobber1";
	};
	class geb_BoneHookBobber2RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2rubberwormbait";
		descriptionShort	= "$STR_bonehookbobberrubberwormbait_desc";
		hookType = "geb_BoneHookBobber2";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_rubberworm.paa"};
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
	class geb_BoneHookBobber3RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3rubberwormbait";
		descriptionShort	= "$STR_bonehookbobberrubberwormbait_desc";
		hookType = "geb_BoneHookBobber3";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_rubberworm.paa"};
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
	class geb_BoneHookBobber4RubberWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4rubberwormbait";
		descriptionShort	= "$STR_bonehookbobberrubberwormbait_desc";
		hookType = "geb_BoneHookBobber4";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_rubberworm.paa"};
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

	class geb_BoneHookBobber1GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1grubwormbait";
		descriptionShort	= "$STR_bonehookbobbergrubwormbait_desc";
		hookType = "geb_BoneHookBobber1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_grubworm.paa"};
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
	class geb_BoneHookBobber2GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2grubwormbait";
		descriptionShort	= "$STR_bonehookbobbergrubwormbait_desc";
		hookType = "geb_BoneHookBobber2";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_grubworm.paa"};
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
	class geb_BoneHookBobber3GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3grubwormbait";
		descriptionShort	= "$STR_bonehookbobbergrubwormbait_desc";
		hookType = "geb_BoneHookBobber3";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_grubworm.paa"};
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
	class geb_BoneHookBobber4GrubWormBait: geb_MetalHookBobberWormBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4grubwormbait";
		descriptionShort	= "$STR_bonehookbobbergrubwormbait_desc";
		hookType = "geb_BoneHookBobber4";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_grubworm.paa"};
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

	class geb_BoneHookBobber1GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1grasshopperbait";
		descriptionShort	= "$STR_bonehookbobbergrasshopperbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_grasshopper.paa"};
		hookType = "geb_BoneHookBobber1";
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
	class geb_BoneHookBobber2GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2grasshopperbait";
		descriptionShort	= "$STR_bonehookbobbergrasshopperbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_grasshopper.paa"};
		hookType = "geb_BoneHookBobber2";
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
	class geb_BoneHookBobber3GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3grasshopperbait";
		descriptionShort	= "$STR_bonehookbobbergrasshopperbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_grasshopper.paa"};
		hookType = "geb_BoneHookBobber3";
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
	class geb_BoneHookBobber4GrassHopperBait: geb_MetalHookBobberGrassHopperBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4grasshopperbait";
		descriptionShort	= "$STR_bonehookbobbergrasshopperbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_grasshopper.paa"};
		hookType = "geb_BoneHookBobber4";
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

	class geb_BoneHookBobber1MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1minnowbait";
		descriptionShort	= "$STR_bonehookbobberminnowbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_minnow.paa"};
		hookType = "geb_BoneHookBobber1";
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
	class geb_BoneHookBobber2MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2minnowbait";
		descriptionShort	= "$STR_bonehookbobberminnowbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_minnow.paa"};
		hookType = "geb_BoneHookBobber2";
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
	class geb_BoneHookBobber3MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3minnowbait";
		descriptionShort	= "$STR_bonehookbobberminnowbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_minnow.paa"};
		hookType = "geb_BoneHookBobber3";
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
	class geb_BoneHookBobber4MinnowBait: geb_MetalHookBobberMinnowBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4minnowbait";
		descriptionShort	= "$STR_bonehookbobberminnowbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_minnow.paa"};
		hookType = "geb_BoneHookBobber4";
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

	class geb_BoneHookBobber1FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber1fieldcricketbait";
		descriptionShort	= "$STR_bonehookbobberfieldcricketbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber1_baited_fieldcricket.paa"};
		hookType = "geb_BoneHookBobber1";
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
	class geb_BoneHookBobber2FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber2fieldcricketbait";
		descriptionShort	= "$STR_bonehookbobberfieldcricketbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber2_baited_fieldcricket.paa"};
		hookType = "geb_BoneHookBobber2";
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
	class geb_BoneHookBobber3FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber3fieldcricketbait";
		descriptionShort	= "$STR_bonehookbobberfieldcricketbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber3_baited_fieldcricket.paa"};
		hookType = "geb_BoneHookBobber3";
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
	class geb_BoneHookBobber4FieldCricketBait: geb_MetalHookBobberFieldCricketBaitBase {
		scope = 2;
		displayName			= "$STR_bonehookbobber4fieldcricketbait";
		descriptionShort	= "$STR_bonehookbobberfieldcricketbait_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehookbobber4_baited_fieldcricket.paa"};
		hookType = "geb_BoneHookBobber4";
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

	class geb_BoneRubberWormBait: geb_metalhook_baited_worm {
		scope = 2;
		displayName			= "$STR_bonehookrubberwormbait";
		descriptionShort = "$STR_CfgVehicles_Bait1";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehook_baited_rubberworm.paa"};
		rotationFlags = 17;
		hookType = "BoneHook";
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_BoneGrubWormBait: Inventory_Base {
		scope = 2;
		displayName			= "$STR_bonehookgrubwormbait";
		descriptionShort = "$STR_CfgVehicles_Bait1";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_worm.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehook_baited_grubworm.paa"};
		rotationFlags = 17;
		hookType = "BoneHook";
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_BoneGrassHopperBait: geb_metalhook_baited_grasshopper {
		scope = 2;
		displayName			= "$STR_bonehookgrasshopperbait";
		descriptionShort = "$STR_CfgVehicles_Bait1";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_grasshopper.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehook_baited_grasshopper.paa"};
		rotationFlags = 17;
		hookType = "BoneHook";
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_BoneFieldCricketBait: geb_metalhook_baited_fieldcricket {
		scope = 2;
		displayName			= "$STR_bonehookfieldcricketbait";
		descriptionShort = "$STR_CfgVehicles_Bait1";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_fieldcricket.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehook_baited_fieldcricket.paa"};
		rotationFlags = 17;
		hookType = "BoneHook";
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class geb_BoneMinnowBait: geb_metalhook_baited_minnow {
		scope = 2;
		displayName			= "$STR_bonehookminnowbait";
		descriptionShort = "A bait to catch marine life!";
		model = "\gebsfish\data\tackle\geb_metalhook_baited_minnow.p3d";
		weight = 15;
		absorbency = 0.8;
		itemSize[] = {1,1};
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_bonehook_baited_minnow.paa"};
		rotationFlags = 17;
		hookType = "BoneHook";
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};

	class geb_SpinnerBait1: Bait {
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
		class AnimationSources {
			class cover {
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
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
	};
	class geb_SpinnerBait3: geb_SpinnerBait1 {
		scope = 2;
		displayName = "$STR_spinnerbait3";
		descriptionShort = "$STR_spinnerbait_desc";
		hookType = "geb_SpinnerBait3";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait3.paa"};
	};
	class geb_SpinnerBait4: geb_SpinnerBait1 {
		scope = 2;
		displayName = "$STR_spinnerbait4";
		descriptionShort = "$STR_spinnerbait_desc";
		hookType = "geb_SpinnerBait4";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\geb_spinnerbait4.paa"};
	};
	class geb_Lure1: Bait {
		scope = 2;
		displayName = "$STR_lure1";
		descriptionShort = "$STR_lure1_desc";
		model = "\gebsfish\data\tackle\lure1.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure1.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure1";
	};
	class geb_Lure2: Bait {
		scope = 2;
		displayName = "$STR_lure2";
		descriptionShort = "$STR_lure2_desc";
		model = "\gebsfish\data\tackle\lure2.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure2.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure2";
	};
	class geb_Lure3: Bait {
		scope = 2;
		displayName = "$STR_lure3";
		descriptionShort = "$STR_lure3_desc";
		model = "\gebsfish\data\tackle\lure3.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure3.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure3";
	};
	class geb_Lure4: Bait {
		scope = 2;
		displayName = "$STR_lure4";
		descriptionShort = "$STR_lure4_desc";
		model = "\gebsfish\data\tackle\lure4.p3d";
		inventorySlot[] = {"Hook"};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tackle\lure3.paa"};
		rotationFlags = 12;
		hookType = "geb_Lure4";
	};
};