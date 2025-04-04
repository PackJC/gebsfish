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
	class FishingRod_Base;

    /*

		TOOLS

	*/
    class geb_FishKnife_Base: HuntingKnife{
        scope=0;
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
		displayName="$STR_tools_bluefishknife";
		descriptionShort="$STR_fishingknife_desc";
        hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_bluefishknife.paa"};
	};
	class geb_OrangeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_orangefishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_orangefishknife.paa"};
	};
	class geb_GreenFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_greenfishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_greenfishknife.paa"};
	};
	class geb_YellowFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_yellowfishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_yellowfishknife.paa"};
	};
	class geb_RedFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_redfishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_redfishknife.paa"};
	};
	class geb_PurpleFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_purplefishknife";
		descriptionShort = "$STR_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_purplefishknife.paa"};
	};
	
	class FishingRod_Base_New : FishingRod_Base {
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
	class FishingRod : FishingRod_Base_New
    {
		inventorySlot[]+={"Shoulder", "Melee", "fishingpole", "fishingrod1", "fishingrod2", "fishingrod3", "fishingrod4", "fishingrod5", "fishingrod6", "fishingrod7", "fishingrod8", "fishingrod9", "fishingrod10"};
        repairableWithKits[]={5};
        repairCosts[]={30, 25};
        hiddenSelections[]={"zbytek"};
        hiddenSelectionsTextures[]={"\DZ\gear\tools\data\fishing_rod_co.paa"};
    };
	class geb_RedFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_redrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_red.paa"};
	};
	class geb_GreenFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_greenrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_green.paa"};
	};
	class geb_BlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_bluerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_blue.paa"};
	};
	class geb_PurpleFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_purplerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\geb_fishingrod_purple.paa"};
	};	
	class geb_BambooFishingNet : Container_Base {
		scope = 2;
		rotationFlags = 17;
		displayName = "$STR_tools_fishingnet";
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