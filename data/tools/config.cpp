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
	class gebsToolsCfgPatches { 	
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
	class HuntingKnife;
	class Container_Base;
	class Inventory_Base;
	class FishingRod_Base_New;

    /*

		TOOLS

	*/
    class geb_FishKnife_Base: HuntingKnife{
        scope=2;
		displayName="Fish Knife Base";
		descriptionShort="Fish Knife Base Class";
		model="\gebsfish\data\tools\geb_bluefishknife.p3d";
        weight=100;
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
	class geb_BlueFishKnife: geb_FishKnife_Base {
		scope=2;
		displayName="$STR_blue_fishknife";
		descriptionShort="$STR_fishingknife_desc";
        hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_bluefishknife.paa"};
	};
	class geb_OrangeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_orange_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_orangefishknife.paa"};
	};
	class geb_GreenFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_green_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_greenfishknife.paa"};
	};
	class geb_YellowFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_yellow_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_yellowfishknife.paa"};
	};
	class geb_RedFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_red_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_redfishknife.paa"};
	};
	class geb_PurpleFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_purple_fishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_purplefishknife.paa"};
	};

	class FishingRod: FishingRod_Base_New {
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
    class geb_FishingRod_Base: FishingRod {
        scope = 2;
		displayName = "Modded Fishing Rod Base";
		descriptionShort = "Modded Fishing Rod Base Class";
		model = "\dz\gear\tools\fishing_rod.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 12;
		weight = 910;
		itemSize[] = {2,5};
		absorbency = 0;
		hiddenSelections[] = {"zbytek"};
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
	class geb_RedFishingRod: geb_FishingRod_Base {
		scope = 2;
		displayName = "$STR_redrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_red.paa"};
	};
	class geb_GreenFishingRod: geb_FishingRod_Base {
		scope = 2;
		displayName = "$STR_greenrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_green.paa"};
	};
	class geb_BlueFishingRod: geb_FishingRod_Base {
		scope = 2;
		displayName = "$STR_bluerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_blue.paa"};
	};
	class geb_PurpleFishingRod: geb_FishingRod_Base {
		scope = 2;
		displayName = "$STR_purplerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_purple.paa"};
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
};