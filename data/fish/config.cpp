/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

class CfgNonAIVehicles {
	class StaticObject;
};

class CfgPatches {
	class gebsFishCfgPatches { 	
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts"
		};
	};
};

class cfgVehicles {		
	//Instantiate Needed Classes
	class Carp;
	class Shrimp;
	class NotCookable;
	class Edible_Base;
	class CarpFilletMeat;
	class MackerelFilletMeat;
	class FoodAnimationSources;
	class Food;
	class FoodStages;
	class Raw;
	class Baked;
	class Boiled;
	class Dried;
	class Burned;
	class RedCaviar;

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
		rotationFlags=17;
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
		rotationFlags=17;
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
	class geb_PikeMuskellunge_Base: geb_FreshFish_Base {
		scope = 0;
		model = "\gebsfish\data\fish\northernpike.p3d";
		hiddenSelections[] = {"Camo"};
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
	};
	class geb_Lobster_Base : geb_SaltFish_Base {
		scope = 0;
		model = "\gebsfish\data\fish\lobster.p3d";
		weight = 3000;
		itemSize[] = {3,2};
	};
	class geb_LobsterTail_Base : MackerelFilletMeat {
		scope = 0;
		model = "\gebsfish\data\fish\lobstertail.p3d";
		itemSize[] = {1,3};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1,105,70,1,0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,130,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,108,84,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1,145,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1,20,0,1,0};
				};
			};
		};
	};
	class geb_LobsterClaw_Base : MackerelFilletMeat {
		scope = 0;
		model = "\gebsfish\data\fish\lobsterclaw.p3d";
		itemSize[] = {2,2};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1,84,66,1,0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,106,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,90,80,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1,122,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1,20,0,1,0};
				};
			};
		};
	};
	class geb_Crayfish_Base: Shrimp {
		scope = 0;
		rotationFlags = 34;
		model = "\gebsfish\data\fish\crayfish.p3d";
		itemSize[] = {2,1};
		weight = 200;
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "dz\gear\food\data\shrimp_raw_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "dz\gear\food\data\shrimp_raw.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };
	};
	class geb_FreshWater_Fillet_Lean: CarpFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 55, 55, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 75, 20, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 65, 70, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 95, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_FreshWater_Fillet_Medium: CarpFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 65, 60, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 90, 20, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 75, 75, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 110, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_FreshWater_Fillet_Heavy: CarpFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 80, 65, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 110, 22, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 90, 80, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 130, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_SaltWater_Fillet_Lean: MackerelFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 60, 55, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 85, 20, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 70, 75, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 105, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_SaltWater_Fillet_Medium: MackerelFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 75, 60, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 100, 20, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 85, 75, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 120, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_SaltWater_Fillet_Fatty: MackerelFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 95, 65, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 125, 22, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 100, 80, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 145, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
	};
	class geb_SaltWater_Fillet_Predator: MackerelFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1, 115, 70, 1, 0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1, 145, 22, 1, 0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1, 120, 85, 1, 0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1, 165, 10, 1, 0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1, 20, 0, 1, 0};
				};
			};
		};
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
	//Needs to be renamed RedBreastSunFish next wipe
	class geb_SunFish: geb_BlueGill {
		scope = 2;
		displayName = "$STR_fish_redbreastsunfish";
		descriptionShort = "$STR_fish_redbreastsunfish_desc";
		itemSize[] = {3,2};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\redbreastsunfish_co.paa"};
	};
	class geb_BlackBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_spottedbass";
		descriptionShort = "$STR_fish_spottedbass_desc";
		model = "\gebsfish\data\fish\spottedbass.p3d";
	};
	class geb_StripedBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_stripedbass";
		descriptionShort = "$STR_fish_stripedbass_desc";
		model = "\gebsfish\data\fish\stripedbass.p3d";
	};
	class geb_NeoshoBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_neoshobass";
		descriptionShort = "$STR_fish_neoshobass_desc";
		model = "\gebsfish\data\fish\neoshobass.p3d";
	};
	class geb_FlatHeadCatFish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\gebsfish\data\fish\flatheadcatfish.p3d";
		itemSize[] = {7,2};
		weight = 4000;
		rotationFlags = 0;
	};
	class geb_WallEye: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_walleye";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\gebsfish\data\fish\walleye.p3d";
		itemSize[] = {4,2};
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
	class geb_FatHeadMinnow: Shrimp {
		scope = 2;
		displayName = "$STR_fish_fatheadminnow";
		descriptionShort = "$STR_fish_fatheadminnow_desc";
		model = "\gebsfish\data\fish\minnow.p3d";
		weight = 100;
		itemSize[] = {1,1};
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2"
		};
		class Food
        {
            class FoodStages
            {
                class Raw
                {
                    visual_properties[]={0, 0, 0};
                    nutrition_properties[]={5, 10, 20, 1, 0, 16, 1, 8};
                    cooking_properties[]={0, 0};
                };
                class Rotten
                {
                    visual_properties[]={-1, -1, 5};
                    nutrition_properties[]={10, 5, 8, 1, 0, 20, 1, 16};
                    cooking_properties[]={0, 0};
                };
                class Baked
                {
                    visual_properties[]={0, 1, 1};
                    nutrition_properties[]={2, 50, 12, 1, 0};
                    cooking_properties[]={70, 45};
                };
                class Boiled
                {
                    visual_properties[]={0, 2, 2};
                    nutrition_properties[]={2, 40, 32, 1, 0};
                    cooking_properties[]={105, 55};
                };
                class Dried
                {
                    visual_properties[]={0, 3, 3};
                    nutrition_properties[]={3, 40, 4, 1, 0};
                    cooking_properties[]={70, 45, 80};
                };
                class Burned
                {
                    visual_properties[]={0, 4, 4};
                    nutrition_properties[]={5, 10, 0, 1, 0, 16, 1, 3};
                    cooking_properties[]={100, 30};
                };
            };
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
	class geb_AmericanBullFrog: Shrimp {
		scope = 2;
		displayName = "$STR_fish_americanbullfrog";
		descriptionShort = "$STR_fish_americanbullfrog_desc";
		model = "\gebsfish\data\fish\americanbullfrog.p3d";
		weight = 100;
		itemSize[] = {1,1};
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2"
		};
		class Food
        {
            class FoodStages
            {
                class Raw
                {
                    visual_properties[]={0, 0, 0};
                    nutrition_properties[]={5, 10, 20, 1, 0, 16, 1, 8};
                    cooking_properties[]={0, 0};
                };
                class Rotten
                {
                    visual_properties[]={-1, -1, 5};
                    nutrition_properties[]={10, 5, 8, 1, 0, 20, 1, 16};
                    cooking_properties[]={0, 0};
                };
                class Baked
                {
                    visual_properties[]={0, 1, 1};
                    nutrition_properties[]={2, 50, 12, 1, 0};
                    cooking_properties[]={70, 45};
                };
                class Boiled
                {
                    visual_properties[]={0, 2, 2};
                    nutrition_properties[]={2, 40, 32, 1, 0};
                    cooking_properties[]={105, 55};
                };
                class Dried
                {
                    visual_properties[]={0, 3, 3};
                    nutrition_properties[]={3, 40, 4, 1, 0};
                    cooking_properties[]={70, 45, 80};
                };
                class Burned
                {
                    visual_properties[]={0, 4, 4};
                    nutrition_properties[]={5, 10, 0, 1, 0, 16, 1, 3};
                    cooking_properties[]={100, 30};
                };
            };
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
	class geb_RedSalamander: Shrimp {
		scope = 2;
		displayName = "$STR_fish_redsalamander";
		descriptionShort = "$STR_fish_redsalamander_desc";
		model = "\gebsfish\data\fish\redsalamander.p3d";
		weight = 100;
		itemSize[] = {1,1};
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2"
		};
		class Food
        {
            class FoodStages
            {
                class Raw
                {
                    visual_properties[]={0, 0, 0};
                    nutrition_properties[]={5, 10, 20, 1, 0, 16, 1, 8};
                    cooking_properties[]={0, 0};
                };
                class Rotten
                {
                    visual_properties[]={-1, -1, 5};
                    nutrition_properties[]={10, 5, 8, 1, 0, 20, 1, 16};
                    cooking_properties[]={0, 0};
                };
                class Baked
                {
                    visual_properties[]={0, 1, 1};
                    nutrition_properties[]={2, 50, 12, 1, 0};
                    cooking_properties[]={70, 45};
                };
                class Boiled
                {
                    visual_properties[]={0, 2, 2};
                    nutrition_properties[]={2, 40, 32, 1, 0};
                    cooking_properties[]={105, 55};
                };
                class Dried
                {
                    visual_properties[]={0, 3, 3};
                    nutrition_properties[]={3, 40, 4, 1, 0};
                    cooking_properties[]={70, 45, 80};
                };
                class Burned
                {
                    visual_properties[]={0, 4, 4};
                    nutrition_properties[]={5, 10, 0, 1, 0, 16, 1, 3};
                    cooking_properties[]={100, 30};
                };
            };
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
	class geb_NorthernPike: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_northernpike";
		descriptionShort = "$STR_fish_northernpike_desc";
		model = "\gebsfish\data\fish\northernpike.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\northernpike_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\northernpike.rvmat"};

		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
	};
	class geb_TigerMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_tigermuskellunge";
		descriptionShort = "$STR_fish_tigermuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\tigermuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\tigermuskellunge.rvmat"};
	};
	class geb_Muskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_muskellunge";
		descriptionShort = "$STR_fish_muskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\muskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\muskellunge.rvmat"};
	};
	class geb_SpottedMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_spottedmuskellunge";
		descriptionShort = "$STR_fish_spottedmuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\spottedmuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\spottedmuskellunge.rvmat"};
	};
	class geb_BarredMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_barredmuskellunge";
		descriptionShort = "$STR_fish_barredmuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 4000;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\barredmuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\barredmuskellunge.rvmat"};
	};
	class geb_AlligatorGar: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_alligatorgar";
		descriptionShort = "$STR_fish_alligatorgar_desc";
		model = "\gebsfish\data\fish\alligatorgar.p3d";
		itemSize[] = {6,2};
		weight = 4000;
		rotationFlags = 0;
	};
	class geb_NorthernSnakeHead: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_northernsnakehead";
		descriptionShort = "$STR_fish_northernsnakehead_desc";
		model = "\gebsfish\data\fish\northernsnakehead.p3d";
		itemSize[] = {6,2};
		weight = 4000;
		rotationFlags = 0;
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
	class geb_RainbowTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\gebsfish\data\fish\rainbowtrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rainbowtrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\rainbowtrout.rvmat"};
	};
	class geb_BrookTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_brooktrout";
		descriptionShort = "$STR_fish_brooktrout_desc";
		model = "\gebsfish\data\fish\brooktrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\brooktrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\brooktrout.rvmat"};
	};
	class geb_BrownTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_browntrout";
		descriptionShort = "$STR_fish_browntrout_desc";
		model = "\gebsfish\data\fish\browntrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\browntrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\browntrout.rvmat"};
	};
	class geb_CutThroatTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_cutthroattrout";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		model = "\gebsfish\data\fish\cutthroattrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cutthroattrout.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\cutthroattrout.rvmat"};
	};
	class geb_LakeTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_laketrout";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\gebsfish\data\fish\laketrout.p3d";
		itemSize[] = {5,2};
		weight = 1700;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\laketrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\laketrout.rvmat"};
	};
	class geb_LakeSturgeon: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_lakesturgeon";
		descriptionShort = "$STR_fish_lakesturgeon_desc";
		model = "\gebsfish\data\fish\lakesturgeon.p3d";
		itemSize[] = {5,2};
		rotationFlags = 0;
		weight = 1700;
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
		rotationFlags = 0;
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
		rotationFlags = 0;
	};
	class geb_AtlanticSailFish: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\gebsfish\data\fish\sailfish.p3d";
		itemSize[] = {20,7};
		rotationFlags = 0;
	};
	class geb_MahiMahi: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_mahimahi";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\gebsfish\data\fish\mahimahi.p3d";
		itemSize[] = {18,8};
		rotationFlags = 0;
	};
	//Needs to be changed to Bonito next wipe
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
	class geb_HammerHeadShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_hammerheadshark";
		descriptionShort = "$STR_fish_hammerheadshark_desc";
		model = "\gebsfish\data\fish\hammerheadshark.p3d";
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
		rotationFlags = 0;
	};
	//Needs to be renamed RoughEyeRock next wipe
	class geb_RoughNeckRock: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_rougheyerock";
		descriptionShort = "$STR_fish_rougheyerock_desc";
		model = "\gebsfish\data\fish\rougheyerock.p3d";
		weight = 3000;
		itemSize[] = {4,3};
	};
	class geb_Severum: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_severum";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\gebsfish\data\fish\severum.p3d";
		weight = 3600;
		itemBehaviour = 0;
		itemSize[] = {5,4};
		rotationFlags = 0;
	};
	class geb_BlueTang: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bluetang";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\gebsfish\data\fish\bluetang.p3d";
		weight = 2000;
		itemSize[] = {4,3};
		rotationFlags = 0;
	};
	class geb_LargeHeadHairTailFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\gebsfish\data\fish\hairtailfish.p3d";
		weight = 800;
		itemSize[] = {8,2};
		rotationFlags = 0;
	};
	class geb_HumpHeadWrasse: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\gebsfish\data\fish\humpheadwrasse.p3d";
		weight = 3500;
		itemSize[] = {5,4};
		rotationFlags = 0;
	};
	class geb_SiameseTigerFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\gebsfish\data\fish\siamesetigerfish.p3d";
		weight = 2500;
		itemSize[] = {3,3};
		rotationFlags = 0;
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
	class geb_WhiteGrunt: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_whitegrunt";
		descriptionShort = "$STR_fish_whitegrunt_desc";
		model = "\gebsfish\data\fish\whitegrunt.p3d";
	};
	class geb_SouthernFlounder: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_southernflounder";
		descriptionShort = "$STR_fish_southernflounder_desc";
		model = "\gebsfish\data\fish\southernflounder.p3d";
		weight = 2000;
		rotationFlags = 0;
	};
	class geb_YellowSnapper: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowsnapper";
		descriptionShort = "$STR_fish_yellowsnapper_desc";
		model = "\gebsfish\data\fish\yellowsnapper.p3d";
	};
	//8 Saltwater crustaceans
	class geb_BloodClam: Shrimp {
		scope = 2;
		displayName = "$STR_fish_bloodclam";
		descriptionShort = "$STR_fish_bloodclam_desc";
		model = "\gebsfish\data\fish\bloodclam.p3d";
		weight = 100;
		itemSize[] = {1,1};
	};
	//Needs to be renamed geb_BlueMussel next wipe
	class geb_Mussel: Shrimp {
		scope = 2;
		displayName = "$STR_fish_mussel";
		descriptionShort = "$STR_fish_mussel_desc";
		model = "\gebsfish\data\fish\mussel.p3d";
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_BlackDevilSnail: Shrimp {
		scope = 2;
		displayName = "$STR_fish_blackdevilsnail";
		descriptionShort = "$STR_fish_blackdevilsnail_desc";
		model = "\gebsfish\data\fish\blackdevilsnail.p3d";
		weight = 100;
		itemSize[] = {1,1};
	};
	class geb_StarFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_starfish";
		descriptionShort = "$STR_fish_starfish_desc";
		model = "\gebsfish\data\fish\starfish.p3d";
		weight = 2500;
		itemSize[] = {2,2};
	};
	class geb_BlueJellyFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_bluejellyfish";
		descriptionShort = "$STR_fish_bluejellyfish_desc";
		model = "\gebsfish\data\fish\bluejellyfish.p3d";
		weight = 500;
		itemSize[] = {2,2};
	};
	class geb_AmericanLobster: geb_Lobster_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobster_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobster.rvmat"};
	};	
	class geb_EuropeanLobster: geb_Lobster_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobster_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobster.rvmat"};
	};
	class geb_KingCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_kingcrab";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrab.p3d";
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
	};
	class geb_SnowCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_snowcrab";
		descriptionShort = "$STR_fish_snowcrab_desc";
		model = "\gebsfish\data\fish\snowcrab.p3d";
		rotationFlags = 17;
		weight = 3000;
		itemSize[] = {3,3};
	};
	//Freshwater crustaceans
	class  geb_EuropeanCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_europeancrayfish";
		descriptionShort = "$STR_fish_europeancrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_european_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_european.rvmat",
            "\gebsfish\data\fish\crayfish_european.rvmat",
            "\gebsfish\data\fish\crayfish_european.rvmat",
            "\gebsfish\data\fish\crayfish_european.rvmat",
            "\gebsfish\data\fish\crayfish_european.rvmat",
            "\gebsfish\data\fish\crayfish_european.rvmat",
        };
	};
	class  geb_SignalCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_signalcrayfish";
		descriptionShort = "$STR_fish_signalcrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_signal_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_signal.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };
	};
	class  geb_FloridaCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_floridacrayfish";
		descriptionShort = "$STR_fish_floridacrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_florida_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_florida.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };	
	};
	class  geb_RustyCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_rustycrayfish";
		descriptionShort = "$STR_fish_rustycrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_rusty_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_rusty.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };	
	};
	class  geb_RedSwampCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_redswampcrayfish";
		descriptionShort = "$STR_fish_redswampcrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_redswamp_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_redswamp.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };	
	};
	class  geb_MonongahelaCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_monongahelacrayfish";
		descriptionShort = "$STR_fish_monongahelacrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_monongahela_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_monongahela.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };	
	};
	class  geb_CaveCrayFish: geb_Crayfish_Base {
		scope = 2;
		displayName = "$STR_fish_cavecrayfish";
		descriptionShort = "$STR_fish_cavecrayfish_desc";
		hiddenSelections[] =
        {
            "Camo"
        };
		hiddenSelectionsTextures[] =
        {
            "\gebsfish\data\fish\crayfish_cave_co.paa",
            "\gebsfish\data\fish\crayfish_baked.paa",
            "\gebsfish\data\fish\crayfish_boiled.paa",
            "\gebsfish\data\fish\crayfish_dried.paa",
            "\gebsfish\data\fish\crayfish_burned.paa",
            "\gebsfish\data\fish\crayfish_rotten.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "\gebsfish\data\fish\crayfish_cave.rvmat",
            "dz\gear\food\data\shrimp_baked.rvmat",
            "dz\gear\food\data\shrimp_boiled.rvmat",
            "dz\gear\food\data\shrimp_dried.rvmat",
            "dz\gear\food\data\shrimp_burnt.rvmat",
            "dz\gear\food\data\shrimp_rotten.rvmat"
        };	
	};

	//Freshwater Fish Fillets
	class geb_BlueGillFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_bluegill_fillet";
		descriptionShort = "$STR_fish_bluegill_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluegill_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	//Will need to be renamed SpottedBassFilletMeat next wipe
	class geb_BlackBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_blackbass_fillet";
		descriptionShort = "$STR_fish_blackbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\blackbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_StripedBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_stripedbass_fillet";
		descriptionShort = "$STR_fish_stripedbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\stripedbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_NeoshoBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_neoshobass_fillet";
		descriptionShort = "$STR_fish_neoshobass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\neoshobass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SmallMouthBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_Smallmouthbass_fillet";
		descriptionShort = "$STR_fish_Smallmouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\smallmouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WallEyeFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_walleye_fillet";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\walleye_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	//Will need to be renamed RedBreastSunFishFillet next wipe
	class geb_SunFishFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_redbreastsunfish_fillet";
		descriptionShort = "$STR_fish_redbreastsunfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redbreastsunfish_fillet_raw_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_FlatHeadCatFishFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish_fillet";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadcatfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LargeMouthBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_largemouthbass_fillet";
		descriptionShort = "$STR_fish_largemouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\largemouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_NorthernPikeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_northernpike_fillet";
		descriptionShort = "$STR_fish_northernpike_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernpike_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_MuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_muskellunge_fillet";
		descriptionShort = "$STR_fish_muskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\muskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SpottedMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_spottedmuskellunge_fillet";
		descriptionShort = "$STR_fish_spottedmuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\spottedmuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BarredMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_barredmuskellunge_fillet";
		descriptionShort = "$STR_fish_barredmuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\barredmuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_TigerMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_tigermuskellunge_fillet";
		descriptionShort = "$STR_fish_tigermuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\tigermuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_AlligatorGarFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_alligatorgar_fillet";
		descriptionShort = "$STR_fish_alligatorgar_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\alligatorgar_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_NorthernSnakeHeadFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_northernsnakehead_fillet";
		descriptionShort = "$STR_fish_northernsnakehead_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernsnakehead_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowPerchFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_yellowperch_fillet";
		descriptionShort = "$STR_fish_yellowperch_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\perch_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SaugerFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_sauger_fillet";
		descriptionShort = "$STR_fish_sauger_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sauger_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_RainbowTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout_fillet";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\rainbowtrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BrownTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_browntrout_fillet";
		descriptionShort = "$STR_fish_browntrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\browntrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BrookTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_brooktrout_fillet";
		descriptionShort = "$STR_fish_brooktrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\brooktrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_CutThroatTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_cuthroattrout_fillet";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cutthroattrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LakeTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_laketrout_fillet";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\laketrout_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_LakeSturgeonFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_lakesturgeon_fillet";
		descriptionShort = "$STR_fish_lakesturgeon_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\lakesturgeon_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_WhiteBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_whitebass_fillet";
		descriptionShort = "$STR_fish_whitebass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitebass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_BowFinFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_bowfin_fillet";
		descriptionShort = "$STR_fish_bowfin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bowfin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};
	class geb_SlimySculpinFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_slimysculpin_fillet";
		descriptionShort = "$STR_fish_slimysculpin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\slimysculpin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"
		};
	};

	//Saltwater Fish fillets
	class geb_AngelFishFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_angelfish_fillet";
		descriptionShort = "$STR_fish_angelfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AsianSeaBassFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_asianseabass_fillet";
		descriptionShort = "$STR_fish_asianseabass_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\asianseabass_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AtlanticBlueMarlinFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_atlanticbluemarlin_fillet";
		descriptionShort = "$STR_fish_atlanticbluemarlin_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AtlanticSailFishFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish_fillet";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_MahiMahiFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_mahimahi_fillet";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\mahimahi_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	//Needs to be changed to Bonito next wipe
	class geb_BonitaFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_bonita_fillet";
		descriptionShort = "$STR_fish_bonita_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bonita_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_CherrySalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_cherrysalmon_fillet";
		descriptionShort = "$STR_fish_cherrysalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\cherrysalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SockEyeSalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_sockeyesalmon_fillet";
		descriptionShort = "$STR_fish_sockeyesalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sockeyesalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_ChinookSalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_chinooksalmon_fillet";
		descriptionShort = "$STR_fish_chinooksalmon_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\chinooksalmon_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_FlatHeadMulletFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_flatheadmullet_fillet";
		descriptionShort = "$STR_fish_flatheadmullet_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadmullet_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LeopardSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_leopardshark_fillet";
		descriptionShort = "$STR_fish_leopardshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\leopardshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_HammerHeadSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_hammerheadshark_fillet";
		descriptionShort = "$STR_fish_hammerheadshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hammerheadshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_PacificCodFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_pacificcod_fillet";
		descriptionShort = "$STR_fish_pacificcod_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\pacificcod_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_RedHeadCichlidFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_redheadcichlid_fillet";
		descriptionShort = "$STR_fish_redheadcichlid_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redheadcichlid_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	//Will need to be renamed RoughEyeRockFilletMeat next wipe
	class geb_RoughNeckRockFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_rougheyerock_fillet";
		descriptionShort = "$STR_fish_rougheyerock_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\rougheyerock_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SeverumFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_severum_fillet";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\severum_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_BlueTangFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_bluetang_fillet";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluetang_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_LargeHeadHairTailFishFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish_fillet";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hairtailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_HumpHeadWrasseFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse_fillet";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\humpheadwrasse_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SiameseTigerFishFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish_fillet";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\siamesetigerfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_GreatWhiteSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_greatwhiteshark_fillet";
		descriptionShort = "$STR_fish_greatwhiteshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\greatwhiteshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_AngelSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_angelshark_fillet";
		descriptionShort = "$STR_fish_angelshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowFinTunaFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_yellowfintuna_fillet";
		descriptionShort = "$STR_fish_yellowfintuna_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowfintuna_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_WhiteGruntFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_whitegrunt_fillet";
		descriptionShort = "$STR_fish_whitegrunt_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitegrunt_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_SouthernFlounderFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_southernflounder_fillet";
		descriptionShort = "$STR_fish_southernflounder_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\southernflounder_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	class geb_YellowSnapperFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_yellowsnapper_fillet";
		descriptionShort = "$STR_fish_yellowsnapper_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowsnapper_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
	};
	//Crustacean Fillets/Legs/Claws
	class geb_KingCrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_kingcrab_legs";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrablegs.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\kingcrab.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
		};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1,95,68,1,0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,120,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,100,82,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1,135,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1,20,0,1,0};
				};
			};
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
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {1,78,64,1,0};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,100,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,86,80,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {1,118,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {1,20,0,1,0};
				};
			};
		};
	};
	class geb_AmericanLobsterTail : geb_LobsterTail_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster_tail";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobstertail_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobstertail.rvmat"};
	};
	class geb_EuropeanLobsterTail : geb_LobsterTail_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_tail";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobstertail_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobstertail.rvmat"};
	};	
	class geb_AmericanLobsterClaw : geb_LobsterClaw_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster_claw";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobsterclaw_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobsterclaw.rvmat"};
	};
	class geb_EuropeanLobsterClaw : geb_LobsterClaw_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_claw";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobsterclaw_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobsterclaw.rvmat"};
	};
	class geb_YellowCaviar: RedCaviar {
		scope=2;
		displayName="$STR_YellowCaviar";
		descriptionShort="$STR_YellowCaviar_desc";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\fish\pike_caviar_raw_CO.paa",
			"dz\gear\food\data\red_caviar_rotten_CO.paa"
		};
	};
	class geb_BlackCaviar: RedCaviar {
		scope=2;
		displayName="$STR_BlackCaviar";
		descriptionShort="$STR_BlackCaviar_desc";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\fish\sturgeon_caviar_raw_CO.paa",
			"dz\gear\food\data\red_caviar_rotten_CO.paa"
		};
	};
};