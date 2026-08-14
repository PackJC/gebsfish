/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

class CfgNonAIVehicles {
	class StaticObject;
	class ProxyAttachment;
	// Attachment proxy for the fish mount slot. The class name must be
	// "Proxy" + the proxy p3d's filename. The plaque model places a proxy
	// named gebfishmount in its resolution LODs -- the attached fish renders
	// at that proxy's position/rotation. The proxy p3d itself is never
	// rendered; any tiny placeholder p3d renamed to gebfishmount.p3d works.
	class Proxygebfishmount: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebFishMount";
		model = "\gebsfish\data\proxy\gebfishmount.p3d";
	};
};

class CfgPatches {
	class gebsToolsCfgPatches {
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts",
		"DZ_Weapons_Melee"
		};
	};
};

class CfgSlots {
	// One slot shared by every catchable -- the mounted trophy IS the caught
	// fish (weight/quality persist via normal attachment save). Fish opt in
	// via inventorySlot[] on the fish config bases in data/fish/config.cpp.
	class Slot_GebFishMount {
		name = "GebFishMount";
		displayName = "$STR_tools_fishmount";
		// Resolves to "set:dayz_inventory image:hook" -- ghostIcon must name
		// an imageset entry, not a texture path. Swap for a gebsfish set once
		// fishmount_ghost.paa is registered as an imageset in Workbench.
		ghostIcon = "hook";
	};
};

class cfgVehicles {		
	//Instantiate Needed Classes
	class HuntingKnife;
	class Container_Base;
	class Inventory_Base;
	class FishingRod_Base;
	class ItemBase;

    /*

		TOOLS

	*/

	// Wooden trophy mount. One item covers every fish: the plaque has a
	// single GebFishMount attachment slot and the player attaches the actual
	// caught fish -- its model renders on the plaque via the gebfishmount
	// proxy, and its weight/quality persist like any attachment. Wall
	// placement comes from the modded Hologram in
	// scripts/4_world/entities/itembase/gear/geb_fishmount.c.
	// The plaque p3d still needs its gebfishmount proxy added in Object
	// Builder before an attached fish will render on it.
	class geb_WoodenFishMount: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_fishmount";
		descriptionShort = "$STR_tools_fishmount_desc";
		model = "\gebsfish\data\tools\fishmount.p3d";
		weight = 1200;
		itemSize[] = {3,3};
		attachments[] = {"GebFishMount"};
		rotationFlags = 2;
		physLayer = "item_large";
		// Placement hologram. Without a hiddenSelection the engine has no
		// slot to swap the ghost material into and the projection renders as
		// the normal textured plaque; "placing" is the selection the p3d
		// carries over the whole board. The material pair is resolved as
		// <hologramMaterialPath>\<hologramMaterial>_deployable.rvmat and
		// ..._undeployable.rvmat.
		hiddenSelections[] = {"placing"};
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		// Don't force ground alignment -- the modded Hologram builds the
		// orientation from the wall normal when the player aims at a wall.
		alignHologramToTerrain = 0;
		yawPitchRollLimit[] = {89,89,89};
	};

	class geb_FishingRodRepairKit: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_fishingrodrepairkit";
		descriptionShort = "$STR_tools_fishingrodrepairkit_desc";
		model="\gebsfish\data\tools\fishingline_biggame.p3d";
		debug_ItemCategory=2;
		animClass="Knife";
		rotationFlags=17;
		stackedUnit="percentage";
		varQuantityInit = 4;
		varQuantityMin = 0;
		quantityBarColor = "Default";
		destroyOnEmpty = 1;  // Kit is deleted when empty
		varQuantityMax = 4;
		quantityBar = 1;
		weight=150;
		weightPerQuantityUnit=0;
		itemSize[]={2,2};
		fragility=0.0099999998;
		repairKitType=33033;
		soundImpactType="wood";
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=100;
					healthLevels[]= {
						{
							1,
							{
								"DZ\gear\tools\data\cleaning_kit_wood.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\cleaning_kit_wood.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\cleaning_kit_wood_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\cleaning_kit_wood_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\cleaning_kit_wood_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeFistLight";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeFistHeavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeFistHeavy";
				range=2.8;
			};
		};
	};
    class geb_FishKnife_Base: HuntingKnife {
        scope=0;
		displayName="Fish Knife Base";
		descriptionShort="Fish Knife Base Class";
		model="\gebsfish\data\tools\fishknife.p3d";
    	hiddenSelections[] = {"Camo"};
        weight=100;
        // The geb fish knife has two intentional buffs over a vanilla HuntingKnife:
        //   1. Durability: hitpoints=200 is ~54% more than vanilla's 130. Sits
        //      between KitchenKnife (150) and KukriKnife (250) -- a "premium
        //      fishing tool" feel without being the strongest blade in the game.
        //   2. Filleting speed: 10% faster than vanilla via the
        //      GeneralSettings.FishKnifeSpeedMultiplier knob in general.json
        //      (default 0.9). The bonus only applies when the recipe's
        //      ApplyFishKnifeSpeedBonus detects a geb_FishKnife_Base derivative
        //      in the ingredient slot; a vanilla knife still cuts at vanilla
        //      speed. Multiplier values much below 0.9 cause visible animation
        //      desync (recipe finishes before the skinning finish-animation
        //      lands) -- see the info string on FishKnifeSpeedMultiplier in
        //      gebsfishConfig.c for the full explanation.
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
		descriptionShort="$STR_tools_fishingknife_desc";
        hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_blue_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_OrangeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_orangefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_orange_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_GreenFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_greenfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_green_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_YellowFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_yellowfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_yellow_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_RedFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_redfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_red_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_PurpleFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_purplefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_purple_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
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
	// Restated DamageSystem block on the modded FishingRod base so every
	// rod variant (vanilla FishingRod + geb_RedFishingRod / Green / Blue /
	// Purple) shares a single source of truth for HP and visual-state
	// thresholds. hitpoints=150 and the healthLevels[] paths below are
	// identical to vanilla's FishingRod config -- carried over verbatim so
	// repair kits, market mods, and any other system that reads rod HP
	// behaves the same with or without gebsfish loaded.
	class FishingRod : FishingRod_Base_New
    {
		inventorySlot[]+={"Shoulder", "Melee", "fishingpole", "fishingrod1", "fishingrod2", "fishingrod3", "fishingrod4", "fishingrod5", "fishingrod6", "fishingrod7", "fishingrod8", "fishingrod9", "fishingrod10"};
        hiddenSelections[]={"zbytek"};
		repairableWithKits[] = {33033};  // Use the same repairKitType as above
		repairCosts[] = {0.1};          // 10% quantity used per full repair
        hiddenSelectionsTextures[]={"\DZ\gear\tools\data\fishing_rod_co.paa"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1, {"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.7, {"DZ\gear\tools\data\fishing_rod.rvmat"}},
						{0.5, {"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0.3, {"DZ\gear\tools\data\fishing_rod_damage.rvmat"}},
						{0, {"DZ\gear\tools\data\fishing_rod_destruct.rvmat"}}
					};
				};
			};
		};
    };
	class geb_RedFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_redrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_red_co.paa"};
	};
	class geb_GreenFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_greenrod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_green_co.paa"};
	};
	class geb_BlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_bluerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_blue_co.paa"};
	};
	class geb_PurpleFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_purplerod";
		descriptionShort = "$STR_CfgVehicles_FishingRod1";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_purple_co.paa"};
	};
	class geb_BambooFishingNet : Container_Base {
		scope = 2;
		rotationFlags = 17;
		displayName = "$STR_tools_fishingnet";
		descriptionShort = "$STR_tools_fishingnet_desc";
		model = "\gebsfish\data\tools\bamboofishingnet.p3d";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\bamboofishingnet_co.paa"};
		itemInfo[] = {"CatchWithNet"};
		weight = 100;
		itemSize[] = {1,3};
		itemsCargoSize[] = {4,4};
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
