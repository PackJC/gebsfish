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
	class gebsfishs { 	//Never Use same name for patch, because conflict message.
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts"
		};
	};
};
class cfgVehicles
{		//Instantiate Needed Classes
	class Bait;
	class Worm;
	class Hook;
	class Rope;
	class Carp;
	class House;
	class Clothing;
	class NotCookable;
	class Edible_Base;
	class WaterBottle;
	class Bottle_Base;
	class HuntingKnife;
	class CarpFilletMeat;
	class Container_Base;
	class Inventory_Base;
	class TShirt_ColorBase;
	class MackerelFilletMeat;
	class FishingRod_Base_New;
	class NBCGloves_ColorBase;
	class FoodAnimationSources;
	class BaseballCap_ColorBase;
	
	/*

	DYNAMIC FISH

	*/
	class geb_Ambientfish1: House {
		scope=1;
		model = "gebsfish\data\ambientfish\geb_Ambientfish1.p3d";
		class AnimationSources
		{
			class Wheel1
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
			class Wheel2
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
			class Wheel3
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
		};
	};

	/*

		CLOTHES

	*/
	//Gloves
	class geb_OrangeFishGloves: NBCGloves_ColorBase {
		displayName="$STR_fishinggloves_orange";
		descriptionShort="$STR_fishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=	{
			"\gebsfish\data\clothes\geb_orangefishgloves.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves.paa"
		};
	};
	class geb_BlueFishGloves: NBCGloves_ColorBase {
		displayName="$STR_fishinggloves_blue";
		descriptionShort="$STR_fishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishgloves.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves.paa"
		};
	};

	//Hats
	class geb_BlueFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_blue";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishhat.paa",
			"\gebsfish\data\clothes\geb_bluefishhat.paa",
			"\gebsfish\data\clothes\geb_bluefishhat.paa"
		};
	};
	class geb_RedFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_red";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishhat.paa",
			"\gebsfish\data\clothes\geb_redfishhat.paa",
			"\gebsfish\data\clothes\geb_redfishhat.paa"
		};
	};	
	class geb_GreenFishHat: BaseballCap_ColorBase {
		scope=2;
		displayName="$STR_fishing_hat_green";
		descriptionShort="$STR_fishing_hat_desc";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishhat.paa",
			"\gebsfish\data\clothes\geb_greenfishhat.paa",
			"\gebsfish\data\clothes\geb_greenfishhat.paa"
		};
	};	
	class geb_PurpleFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_purple";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishhat.paa",
			"\gebsfish\data\clothes\geb_purplefishhat.paa",
			"\gebsfish\data\clothes\geb_purplefishhat.paa"
		};
	};	

	//Shirts
	class geb_RedFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_red";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_red_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt.paa",
			"\gebsfish\data\clothes\geb_redfishshirt.paa"
		};
	};
	class geb_GreenFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_green";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_green_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt.paa"
		};
	};
	class geb_BlueFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_blue";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_blue_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt.paa"
		};
	};
	class geb_PurpleFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_purple";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_black_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt.paa"
		};
	};

	/*

		CONTAINERS

	*/
	class geb_RedTackle: Container_Base {
		scope = 2;
		displayName = "$STR_redtackle";
		descriptionShort = "$STR_tackle_desc";
		model = "gebsfish\data\tackle\geb_RedTackle.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_redtackle.paa"};
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
	class geb_YellowTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_yellowtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] ={"gebsfish\data\tackle\geb_yellowtackle.paa"};
	};
	class geb_BlueTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_bluetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_bluetackle.paa"};
	};
	class geb_OrangeTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_orangetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_orangetackle.paa"};
	};
	class geb_BrownTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_browntackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_browntackle.paa"};
	};
	class geb_PurpleTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_purpletackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_purpletackle.paa"};
	};
	class geb_PinkTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_pinktackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_pinktackle.paa"};
	};
	class geb_LimeTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_limetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_limetackle.paa"};
	};
	class geb_LightBlueTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_lightbluetackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_lightbluetackle.paa"};
	};
	class geb_GreenTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_greentackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_greentackle.paa"};
	};
	class geb_CamoTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_camotackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_camotackle.paa"};
	};
	class geb_FunYellowTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_funyellowtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funyellowtackle.paa"};
	};
	class geb_FunRedTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_funredtackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funredtackle.paa"};
	};
	class geb_FunPurpleTackle: geb_RedTackle {
		scope = 2;
		displayName = "$STR_funpurpletackle";
		descriptionShort = "$STR_tackle_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"gebsfish\data\tackle\geb_funpurpletackle.paa"};
	};
	class geb_FunGreenTackle: geb_RedTackle {
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

	/*

		TOOLS

	*/
	class geb_BlueFishKnife: HuntingKnife {
		scope=2;
		displayName="$STR_blue_fishknife";
		descriptionShort="$STR_fishingknife_desc";
		model="\gebsfish\data\tools\geb_bluefishknife.p3d";
		inventorySlot[]={"Knife"};
		repairableWithKits[]={4};
		repairCosts[]={10};
		rotationFlags=17;
		RestrainUnlockType=1;
		canSkinBodies=1;
		weight=100;
		itemSize[]={1,3};
		lootTag[]={"Hunting","Camping"};
		lootCategory="Tools";
		itemInfo[]={"Knife"};
		openItemSpillRange[]={10,20};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="onehanded";
		class MeleeModes {
			class Default {
				ammo="MeleeKnife";
				range=1.2;
			};
			class Heavy {
				ammo="MeleeKnife_Heavy";
				range=1.2;
			};
			class Sprint {
				ammo="MeleeKnife_Heavy";
				range=3.3;
			};
		};
		class AnimEvents {
			class SoundWeapon {
				class animalSkinning_in {
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning {
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out {
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
				class CutTies_end {
					soundSet="CutTies_end_SoundSet";
					id=519;
				};
				class CutTies_loop {
					soundSet="CutTies_loop_SoundSet";
					id=520;
				};
				class shaving_knife_clean {
					soundSet="shaving_knife_clean_SoundSet";
					id=600;
				};
				class shaving_knife1 {
					soundSet="shaving_knife1_SoundSet";
					id=601;
				};
				class shaving_knife2 {
					soundSet="shaving_knife2_SoundSet";
					id=602;
				};
				class shaving_knife3 {
					soundSet="shaving_knife3_SoundSet";
					id=603;
				};
				class shaving_knife4 {
					soundSet="shaving_knife4_SoundSet";
					id=604;
				};
				class shaving_knife5 {
					soundSet="shaving_knife5_SoundSet";
					id=605;
				};
				class shaving_knife6 {
					soundSet="shaving_knife6_SoundSet";
					id=606;
				};
				class shaving_knife7 {
					soundSet="shaving_knife7_SoundSet";
					id=607;
				};
				class shaving_knife8 {
					soundSet="shaving_knife8_SoundSet";
					id=608;
				};
				class shaving_knife9 {
					soundSet="shaving_knife9_SoundSet";
					id=609;
				};
				class shaving_knife10 {
					soundSet="shaving_knife10_SoundSet";
					id=610;
				};
				class shaving_knife11 {
					soundSet="shaving_knife11_SoundSet";
					id=611;
				};
				class shaving_knife12 {
					soundSet="shaving_knife12_SoundSet";
					id=612;
				};
				class shaving_knife13 {
					soundSet="shaving_knife13_SoundSet";
					id=613;
				};
				class shaving_knife14 {
					soundSet="shaving_knife14_SoundSet";
					id=614;
				};
				class shaving_knife15 {
					soundSet="shaving_knife15_SoundSet";
					id=615;
				};
				class shaving_knife16 {
					soundSet="shaving_knife16_SoundSet";
					id=616;
				};
				class shaving_knife17 {
					soundSet="shaving_knife17_SoundSet";
					id=617;
				};
				class shaving_knife18 {
					soundSet="shaving_knife18_SoundSet";
					id=618;
				};
				class shaving_knife19 {
					soundSet="shaving_knife19_SoundSet";
					id=619;
				};
				class shaving_knife20 {
					soundSet="shaving_knife20_SoundSet";
					id=620;
				};
				class shaving_knife21 {
					soundSet="shaving_knife21_SoundSet";
					id=621;
				};
				class pickup_light {
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup {
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop {
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet {
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet {
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
			};
		};
	};
	class geb_OrangeFishKnife: geb_BlueFishKnife {
		scope = 2;
		displayName = "$STR_orange_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_orangefishknife.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_GreenFishKnife: geb_BlueFishKnife {
		scope = 2;
		displayName = "$STR_green_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_greenfishknife.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_YellowFishKnife: geb_BlueFishKnife {
		scope = 2;
		displayName = "$STR_yellow_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_yellowfishknife.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_RedFishKnife: geb_BlueFishKnife {
		scope = 2;
		displayName = "$STR_red_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_redfishknife.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_PurpleFishKnife: geb_BlueFishKnife {
		scope = 2;
		displayName = "$STR_purple_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_purplefishknife.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[]={
						{1,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},
						{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},
						{0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}
					};
				};
			};
		};
	};

	class FishingRod: FishingRod_Base_New {
		//Issue with this, don't update until I figure this out
		inventorySlot[] += {
			"Shoulder",
			"Melee",
			"fishingpole",
			"fishingrod1",
			"fishingrod2",
			"fishingrod3",
			"fishingrod4",
			"fishingrod5",
			"fishingrod6",
			"fishingrod7",
			"fishingrod8",
			"fishingrod9",
			"fishingrod10"
		};
	}; 
	class geb_RedFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_redrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		model = "\dz\gear\tools\fishing_rod.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 12;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_red.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.7,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.5,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0.3,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_GreenFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_greenrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		model = "\dz\gear\tools\fishing_rod.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 12;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_green.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.7,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.5,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0.3,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_BlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_bluerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		model = "\dz\gear\tools\fishing_rod.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 12;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_blue.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.7,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.5,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0.3,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_PurpleFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_purplerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		model = "\dz\gear\tools\fishing_rod.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 12;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_purple.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.7,{"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.5,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0.3,{"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}
					};
				};
			};
		};
	};	

	class geb_BambooFishingNet : Container_Base {
		scope = 2;
		rotationFlags = 17;
		displayName = "$STR_fishingnet";
		descriptionShort = "$STR_fishingnet_desc";
		model = "\gebsfish\data\tools\geb_fishingnet.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingnet.paa"};
		itemInfo[] = {"CatchBugs"};
		weight = 100;
		itemSize[] = {1,3};
		itemsCargoSize[] = {1,1};
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

		FISH

	*/
	//Freshwater Fish
	class geb_Bluegill: Edible_Base {
		scope = 2;
		displayName = "$STR_bluegill";
		descriptionShort = "$STR_bluegill_desc";
		model = "\gebsfish\data\fish\bluegill.p3d";
		itemSize[] = {3,2};
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
	class geb_Blackbass: Edible_Base {
		scope = 2;
		displayName = "$STR_blackbass";
		descriptionShort = "$STR_blackbass_desc";
		model = "\gebsfish\data\fish\blackbass.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		debug_ItemCategory = 6;
		rotationFlags = 17;
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
	class geb_Catfish: Edible_Base {
		scope = 2;
		displayName = "$STR_catfish";
		descriptionShort = "$STR_catfish_desc";
		model = "\gebsfish\data\fish\catfish.p3d";
		itemSize[] = {7,2};
		weight = 4000;
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
	class geb_Walleye: Edible_Base {
		scope = 2;
		displayName = "$STR_walleye";
		descriptionShort = "$STR_walleye_desc";
		model = "\gebsfish\data\fish\walleye.p3d";
		itemSize[] = {4,2};
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
	class geb_Sunfish: Edible_Base {
		scope = 2;
		displayName = "$STR_sunfish";
		descriptionShort = "$STR_sunfish_desc";
		model = "\gebsfish\data\fish\sunfish.p3d";
		itemSize[] = {3,2};
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
	class geb_Smallmouthbass: Edible_Base {
		scope = 2;
		displayName = "$STR_smallmouthbass";
		descriptionShort = "$STR_smallmouthbass_desc";
		model = "\gebsfish\data\fish\smallmouthbass.p3d";
		itemSize[] = {3,2};
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
	class geb_Largemouthbass: Edible_Base {
		scope = 2;
		displayName = "$STR_largemouthbass";
		descriptionShort = "$STR_largemouthbass_desc";
		model = "\gebsfish\data\fish\largemouthbass.p3d";
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
	class geb_Minnow: Edible_Base {
		scope = 2;
		displayName = "$STR_minnow";
		descriptionShort = "$STR_minnow_desc";
		model = "\gebsfish\data\fish\minnow.p3d";
		itemSize[] = {1,1};
		weight = 300;
		debug_ItemCategory = 6;
		rotationFlags = 17;
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
	class geb_Northernpike: Edible_Base {
		scope = 2;
		displayName = "$STR_northernpike";
		descriptionShort = "$STR_northernpike_desc";
		model = "\gebsfish\data\fish\northernpike.p3d";
		itemSize[] = {6,2};
		weight = 4000;
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
	class geb_Perch: Edible_Base {
		scope = 2;
		displayName = "$STR_perch";
		descriptionShort = "$STR_perch_desc";
		model = "\gebsfish\data\fish\perch.p3d";
		itemSize[] = {4,3};
		weight = 3000;
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
	class geb_Sauger: Edible_Base {
		scope = 2;
		displayName = "$STR_sauger";
		descriptionShort = "$STR_sauger_desc";
		model = "\gebsfish\data\fish\sauger.p3d";
		itemSize[] = {4,1};
		weight = 1500;
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
	class geb_Crayfish: Edible_Base {
		scope = 2;
		displayName = "$STR_crayfish";
		descriptionShort = "$STR_crayfish_desc";
		model = "\gebsfish\data\fish\Crayfish.p3d";
		itemSize[] = {2,1};
		weight = 200;
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
	class geb_Trout_Base: Edible_Base {
		scope = 0;
		model = "\gebsfish\data\fish\geb_Trout_Base.p3d";
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
	class geb_Whitebass: Edible_Base {
		scope = 2;
		displayName = "$STR_whitebass";
		descriptionShort = "$STR_whitebass_desc";
		model = "\gebsfish\data\fish\whitebass.p3d";
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
	class geb_Bowfin: Edible_Base {
		scope = 2;
		displayName = "$STR_bowfin";
		descriptionShort = "$STR_bowfin_desc";
		model = "\gebsfish\data\fish\bowfin.p3d";
		itemSize[] = {4,2};
		weight = 1500;
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
	class geb_Slimysculpin: Edible_Base {
		scope = 2;
		displayName = "$STR_slimysculpin";
		descriptionShort = "$STR_slimysculpin_desc";
		model = "\gebsfish\data\fish\slimysculpin.p3d";
		itemSize[] = {2,1};
		weight = 300;
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

	//Saltwater Fish
	class geb_Angelfish: Edible_Base {
		scope = 2;
		displayName = "$STR_angelfish";
		descriptionShort = "$STR_angelfish_desc";
		model = "\gebsfish\data\fish\angelfish.p3d";
		debug_ItemCategory = 6;
		weight = 2500;
		itemSize[] = {4,3};
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
	class geb_Asianseabass: Edible_Base {
		scope = 2;
		displayName = "$STR_asianseabass";
		descriptionShort = "$STR_asianseabass_desc";
		model = "\gebsfish\data\fish\asianseabass.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Bluemarlin: Edible_Base {
		scope = 2;
		displayName = "$STR_bluemarlin";
		descriptionShort = "$STR_bluemarlin_desc";
		model = "\gebsfish\data\fish\bluemarlin.p3d";
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
	class geb_Sailfish: Edible_Base {
		scope = 2;
		displayName = "$STR_sailfish";
		descriptionShort = "$STR_sailfish_desc";
		model = "\gebsfish\data\fish\sailfish.p3d";
		debug_ItemCategory = 6;
		weight = 3700;
		itemSize[] = {20,7};
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
	class geb_Mahimahi: Edible_Base {
		scope = 2;
		displayName = "$STR_mahimahi";
		descriptionShort = "$STR_mahimahi_desc";
		model = "\gebsfish\data\fish\mahimahi.p3d";
		debug_ItemCategory = 6;
		weight = 3700;
		itemSize[] = {18,8};
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
	class geb_Bonita: Edible_Base {
		scope = 2;
		displayName = "$STR_bonita";
		descriptionShort = "$STR_bonita_desc";
		model = "\gebsfish\data\fish\bonita.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Cherrysalmon: Edible_Base {
		scope = 2;
		displayName = "$STR_cherrysalmon";
		descriptionShort = "$STR_cherrysalmon_desc";
		model = "\gebsfish\data\fish\cherrysalmon.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Sockeyesalmon: Edible_Base {
		scope = 2;
		displayName = "$STR_sockeyesalmon";
		descriptionShort = "$STR_sockeyesalmon_desc";
		model = "\gebsfish\data\fish\sockeyesalmon.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Chinooksalmon: Edible_Base {
		scope = 2;
		displayName = "$STR_chinooksalmon";
		descriptionShort = "$STR_chinooksalmon_desc";
		model = "\gebsfish\data\fish\chinooksalmon.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Flatheadmullet: Edible_Base {
		scope = 2;
		displayName = "$STR_flatheadmullet";
		descriptionShort = "$STR_flatheadmullet_desc";
		model = "\gebsfish\data\fish\flatheadmullet.p3d";
		debug_ItemCategory = 6;
		weight = 1000;
		itemSize[] = {2,1};
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
	class geb_Leopardshark: Edible_Base {
		scope = 2;
		displayName = "$STR_leopardshark";
		descriptionShort = "$STR_leopardshark_desc";
		model = "\gebsfish\data\fish\leopardshark.p3d";
		debug_ItemCategory = 6;
		weight = 8000;
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
	class geb_Pacificcod: Edible_Base {
		scope = 2;
		displayName = "$STR_pacificcod";
		descriptionShort = "$STR_pacificcod_desc";
		model = "\gebsfish\data\fish\pacificcod.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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
	class geb_Redheadcichlid: Edible_Base {
		scope = 2;
		displayName = "$STR_redheadcichlid";
		descriptionShort = "$STR_redheadcichlid_desc";
		model = "\gebsfish\data\fish\redheadcichlid.p3d";
		debug_ItemCategory = 6;
		weight = 3000;
		itemSize[] = {4,3};
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
	class geb_Roughneckrock: Edible_Base {
		scope = 2;
		displayName = "$STR_roughneckrock";
		descriptionShort = "$STR_roughneckrock_desc";
		model = "\gebsfish\data\fish\roughneckrock.p3d";
		debug_ItemCategory = 6;
		weight = 3000;
		itemSize[] = {4,3};
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
	class geb_Severum: Edible_Base {
		scope = 2;
		displayName = "$STR_severum";
		descriptionShort = "$STR_severum_desc";
		model = "\gebsfish\data\fish\severum.p3d";
		debug_ItemCategory = 6;
		weight = 3600;
		itemBehaviour = 0;
		itemSize[] = {5,4};
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
	class geb_Shrimp: Edible_Base {
		scope = 2;
		displayName = "$STR_shrimp";
		descriptionShort = "$STR_shrimp_desc";
		model = "\gebsfish\data\fish\shrimp.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 200;
		itemSize[] = {2,1};
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
	class geb_Bluetang: Edible_Base {
		scope = 2;
		displayName = "$STR_bluetang";
		descriptionShort = "$STR_bluetang_desc";
		model = "\gebsfish\data\fish\bluetang.p3d";
		debug_ItemCategory = 6;
		weight = 2000;
		itemSize[] = {4,3};
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
	class geb_Hairtailfish: Edible_Base {
		scope = 2;
		displayName = "$STR_hairtailfish";
		descriptionShort = "$STR_hairtailfish_desc";
		model = "\gebsfish\data\fish\hairtailfish.p3d";
		debug_ItemCategory = 6;
		weight = 800;
		itemSize[] = {4,1};
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
	class geb_Humpheadwrasse: Edible_Base {
		scope = 2;
		displayName = "$STR_humpheadwrasse";
		descriptionShort = "$STR_humpheadwrasse_desc";
		model = "\gebsfish\data\fish\humpheadwrasse.p3d";
		debug_ItemCategory = 6;
		weight = 3500;
		itemSize[] = {5,4};
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
	class geb_Siamesetigerfish: Edible_Base {
		scope = 2;
		displayName = "$STR_siamesetigerfish";
		descriptionShort = "$STR_siamesetigerfish_desc";
		model = "\gebsfish\data\fish\siamesetigerfish.p3d";
		debug_ItemCategory = 6;
		weight = 2500;
		itemSize[] = {3,3};
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
	class geb_Angelshark: Edible_Base {
		scope = 2;
		displayName = "$STR_angelshark";
		descriptionShort = "$STR_angelshark_desc";
		model = "\gebsfish\data\fish\angelshark.p3d";
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
	class geb_Greatwhiteshark: Edible_Base {
		scope = 2;
		displayName = "$STR_greatwhiteshark";
		descriptionShort = "$STR_greatwhiteshark_desc";
		model = "\gebsfish\data\fish\greatwhiteshark.p3d";
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
	class geb_Yellowfintuna: Edible_Base {
		scope = 2;
		displayName = "$STR_yellowfintuna";
		descriptionShort = "$STR_yellowfintuna_desc";
		model = "\gebsfish\data\fish\yellowfintuna.p3d";
		debug_ItemCategory = 6;
		weight = 1700;
		itemSize[] = {5,2};
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

	//Crustaceans Fish
	class geb_Bloodclam: Edible_Base {
		scope = 2;
		displayName = "$STR_bloodclam";
		descriptionShort = "$STR_bloodclam_desc";
		model = "\gebsfish\data\fish\bloodclam.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
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
	class geb_Mussel: Edible_Base {
		scope = 2;
		displayName = "$STR_mussel";
		descriptionShort = "$STR_mussel_desc";
		model = "\gebsfish\data\fish\mussel.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
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
	class geb_Blackdevilsnail: Edible_Base {
		scope = 2;
		displayName = "$STR_blackdevilsnail";
		descriptionShort = "$STR_blackdevilsnail_desc";
		model = "\gebsfish\data\fish\blackdevilsnail.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 100;
		itemSize[] = {1,1};
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
	class geb_Starfish: Edible_Base {
		scope = 2;
		displayName = "$STR_starfish";
		descriptionShort = "$STR_starfish_desc";
		model = "\gebsfish\data\fish\starfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 2500;
		itemSize[] = {2,2};
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
	class geb_Kingcrab: Edible_Base {
		scope = 2;
		displayName = "$STR_kingcrab";
		descriptionShort = "$STR_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrab.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
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
	class geb_Jellyfish: Edible_Base {
		scope = 2;
		displayName = "$STR_jellyfish";
		descriptionShort = "$STR_jellyfish_desc";
		model = "\gebsfish\data\fish\jellyfish.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 500;
		itemSize[] = {2,2};
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
	class geb_Lobster: Edible_Base {
		scope = 2;
		displayName = "$STR_lobster";
		descriptionShort = "$STR_lobster_desc";
		model = "\gebsfish\data\fish\lobster.p3d";
		debug_ItemCategory = 6;
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,2};
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
