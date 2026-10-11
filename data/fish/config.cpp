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
		"DZ_Scripts",
		// Defines Shrimp. Without it the load order against gear_food.pbo is
		// undefined and the Shrimp override below can be wiped by vanilla
		// loading after us.
		"DZ_Gear_Food"
		};
	};
};

// Vanilla's top-level food classes (gear/food). Declared at the root: inside
// cfgVehicles they would be empty stand-ins, and the fish below would inherit
// nothing from them.
class NotCookable;
class FoodAnimationSources;

class cfgVehicles {
	//Instantiate Needed Classes
	class Edible_Base;
	class CarpFilletMeat;
	class MackerelFilletMeat;
	class Food;
	class FoodStages;
	class Raw;
	class Baked;
	class Boiled;
	class Dried;
	class Burned;
	class Rotten;
	class RedCaviar;

	// Vanilla Shrimp override: net-caught shrimp double as hook bait (the
	// vanilla Hook's attachment slot is "Bait"), trap bait, and a mountable
	// trophy -- the same slot set as geb_FatHeadMinnow. += appends to
	// vanilla's cooking/smoking slots; DZ_Gear_Food in requiredAddons
	// guarantees the vanilla definition loads first, which is what makes the
	// append deterministic. The invertebrates that inherit from Shrimp
	// (crayfish, clam, mussel, snail, starfish, jellyfish) must NOT become
	// hookable, so they restate their slot list in full instead of using +=.
	//
	// The slots alone don't make it bait: vanilla only counts an item on the
	// hook as bait if it has a Fishing class (CatchingContextFishingRodAction.
	// InitItemValues), and only as trap bait with a Trapping class. Without
	// them a hooked shrimp was never eaten and its bait-preference row never
	// applied. Values match geb_FatHeadMinnow / vanilla Worm. The subclasses
	// above inherit both classes but can't reach a bait slot, so they stay
	// inert.
	class Shrimp: Edible_Base {
		inventorySlot[] += {
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2",
			"GebFishMount"
		};
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

	// Vanilla's rod catches go on the fish mounts too: += appends the mount slot
	// to vanilla's {"TrapPrey_1"}, and DZ_Gear_Food in requiredAddons makes
	// vanilla's definitions load first. All four fit the small mount, and
	// tools/vanilla_mount_poses.json holds their poses (build_mount_poses.py reads it).
	class Carp: Edible_Base {
		inventorySlot[] += {"GebFishMount"};
	};
	class Mackerel: Edible_Base {
		inventorySlot[] += {"GebFishMount"};
	};
	class WalleyePollock: Edible_Base {
		inventorySlot[] += {"GebFishMount"};
	};
	class SteelheadTrout: Edible_Base {
		inventorySlot[] += {"GebFishMount"};
	};

	// Vanilla's trap baitfish go on the hook too, like the shrimp above: the
	// Bait slot, and vanilla Worm's fishing values (an item is bait only with
	// class Fishing). What each one draws is its row in bait.json.
	class Bitterlings: Edible_Base {
		inventorySlot[] += {
			"Bait"
		};
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
	};
	class Sardines: Edible_Base {
		inventorySlot[] += {
			"Bait"
		};
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
	};

	//Base classes for fish
	class geb_FreshFish_Base: Edible_Base {
		scope = 0;
		itemSize[] = {5,2};
		// A full catch weighs weight + varQuantityMax x weightPerQuantityUnit. Like vanilla's carp
		// (300 g + 1000 x 2 g) about an eighth is fixed and the rest rides on the quantity, so a
		// part-eaten or less full fish weighs less. A species sets both lines.
		weight = 222;
		weightPerQuantityUnit = 1.478;  // 1.7 kg full
		debug_ItemCategory = 6;
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		// Vanilla Carp's temperature settings: freeze and thaw at 0 C, 110 minutes
		// to freeze or thaw, a big fish changes temperature more slowly, 110 C at most.
		varTemperatureFreezePoint = 0;
		varTemperatureThawPoint = 0;
		varTemperatureFreezeTime = 6600;
		varTemperatureThawTime = 6600;
		varTemperatureInit = 10;  // as vanilla Carp: whole fish (IsCorpse) start at this config temperature
		temperaturePerQuantityWeight = 3;
		varTemperatureMax = 110;
		soundImpactType = "organic";
		isMeleeWeapon = 1;
		rotationFlags=17;
		// Empty here: each fish further down lists its own material and the
		// _damage/_destruct copies beside it (the worn, damaged and ruined looks).
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
		inventorySlot[] = {"TrapPrey_1", "GebFishMount"};
		// Vanilla FoodStage.UpdateVisualsEx reads entry 0 of these three lists
		// on every spawn, so they can't be empty. The mod's fish models have no
		// cs_raw part, so the carp texture never shows.
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
					// Material 1 = the fish's own _rotten.rvmat (vanilla's mould overlay,
					// as on rotten fillets); the texture stays.
					visual_properties[] = {-1,-1,1};
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
		weight = 222;
		weightPerQuantityUnit = 1.478;  // 1.7 kg full
		debug_ItemCategory = 6;
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		// Vanilla Carp's temperature settings: freeze and thaw at 0 C, 110 minutes
		// to freeze or thaw, a big fish changes temperature more slowly, 110 C at most.
		varTemperatureFreezePoint = 0;
		varTemperatureThawPoint = 0;
		varTemperatureFreezeTime = 6600;
		varTemperatureThawTime = 6600;
		varTemperatureInit = 10;  // as vanilla Carp: whole fish (IsCorpse) start at this config temperature
		temperaturePerQuantityWeight = 3;
		varTemperatureMax = 110;
		soundImpactType = "organic";
		isMeleeWeapon = 1;
		rotationFlags=17;
		// Empty here: each fish further down lists its own material and the
		// _damage/_destruct copies beside it (the worn, damaged and ruined looks).
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
		inventorySlot[] = {"TrapPrey_1", "GebFishMount"};
		// Vanilla FoodStage.UpdateVisualsEx reads entry 0 of these three lists
		// on every spawn, so they can't be empty. The mod's fish models have no
		// cs_raw part, so the mackerel texture never shows.
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
					// Material 1 = the fish's own _rotten.rvmat (vanilla's mould overlay,
					// as on rotten fillets); the texture stays.
					visual_properties[] = {-1,-1,1};
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
		weight = 483;
		weightPerQuantityUnit = 3.217;  // 3.7 kg full
		itemSize[] = {25,8};
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		// Vanilla Carp's temperature settings: freeze and thaw at 0 C, 110 minutes
		// to freeze or thaw, a big fish changes temperature more slowly, 110 C at most.
		varTemperatureFreezePoint = 0;
		varTemperatureThawPoint = 0;
		varTemperatureFreezeTime = 6600;
		varTemperatureThawTime = 6600;
		varTemperatureInit = 10;  // as vanilla Carp: whole fish (IsCorpse) start at this config temperature
		temperaturePerQuantityWeight = 3;
		varTemperatureMax = 110;
		soundImpactType = "organic";
		isMeleeWeapon = 1;
		// Empty here: each fish further down lists its own material and the
		// _damage/_destruct copies beside it (the worn, damaged and ruined looks).
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
		inventorySlot[] = {"TrapPrey_1", "GebFishMount"};
		// Vanilla FoodStage.UpdateVisualsEx reads entry 0 of these three lists
		// on every spawn, so they can't be empty. The mod's fish models have no
		// cs_raw part, so the mackerel texture never shows.
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
					// Material 1 = the fish's own _rotten.rvmat (vanilla's mould overlay,
					// as on rotten fillets); the texture stays.
					visual_properties[] = {-1,-1,1};
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
		weight = 522;
		weightPerQuantityUnit = 3.478;  // 4 kg full
	};
	class geb_Lobster_Base : geb_SaltFish_Base {
		scope = 0;
		model = "\gebsfish\data\fish\lobster.p3d";
		weight = 391;
		weightPerQuantityUnit = 2.609;  // 3 kg full
		itemSize[] = {3,2};
	};
	// nutrition_properties = {fullness, energy, water, nutritional index,
	// toxicity, agents, digestibility, agents per bite}. Fullness and the
	// raw/burned food poisoning (agents 16) copy the vanilla parent --
	// MackerelFilletMeat here and for the saltwater fillets and crab legs,
	// CarpFilletMeat for the freshwater fillets. Energy and water are this
	// mod's per-species tuning.
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
					nutrition_properties[] = {5,105,70,1,0,16,1,9};
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
					nutrition_properties[] = {2,145,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,84,66,1,0,16,1,9};
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
					nutrition_properties[] = {2,122,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
				};
			};
		};
	};
	class geb_Crayfish_Base: Shrimp {
		scope = 0;
		rotationFlags = 34;
		model = "\gebsfish\data\fish\crayfish.p3d";
		itemSize[] = {2,1};
		weight = 7;
		weightPerQuantityUnit = 0.288591;  // 50 g full
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
		hiddenSelections[] =
		{
			"Camo"
		};
		hiddenSelectionsTextures[] =
		{
			"dz\gear\food\data\shrimp_raw_co.paa",
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
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
	// Fillet nutrition: see the field note above geb_LobsterTail_Base.
	class geb_FreshWater_Fillet_Lean: CarpFilletMeat {
		scope=0;
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {5,55,55,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {2,75,20,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {2,65,70,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {3,95,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,65,60,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {2,90,20,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {2,75,75,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {3,110,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,80,65,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {2,110,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {2,90,80,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {3,130,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,60,55,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,85,20,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,70,75,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {2,105,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,75,60,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,100,20,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,85,75,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {2,120,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,95,65,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,125,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,100,80,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {2,145,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
					nutrition_properties[] = {5,115,70,1,0,16,1,9};
				};
				class Baked: Baked
				{
					nutrition_properties[] = {1,145,22,1,0};
				};
				class Boiled: Boiled
				{
					nutrition_properties[] = {1,120,85,1,0};
				};
				class Dried: Dried
				{
					nutrition_properties[] = {2,165,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
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
		weight = 52;
		weightPerQuantityUnit = 0.348;  // 400 g full
		itemSize[] = {3,2};
		// The rotten stage swaps in material 1 (see geb_FreshFish_Base).
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluegill_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bluegill.rvmat","\gebsfish\data\fish\bluegill_rotten.rvmat"};
	};
	//Needs to be renamed RedBreastSunFish next wipe
	class geb_SunFish: geb_BlueGill {
		scope = 2;
		weight = 52;
		weightPerQuantityUnit = 0.348;  // 400 g full
		displayName = "$STR_fish_redbreastsunfish";
		descriptionShort = "$STR_fish_redbreastsunfish_desc";
		itemSize[] = {3,2};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\redbreastsunfish_co.paa"};
		// Its own materials: the bluegill model it shares, with a relief map made
		// from its own skin (the bluegill's would put the bluegill's relief on it).
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\redbreastsunfish.rvmat","\gebsfish\data\fish\redbreastsunfish_rotten.rvmat"};
	};
	class geb_BlackBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_spottedbass";
		descriptionShort = "$STR_fish_spottedbass_desc";
		model = "\gebsfish\data\fish\spottedbass.p3d";
		weight = 98;
		weightPerQuantityUnit = 0.652;  // 750 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\spottedbass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\spottedbass.rvmat","\gebsfish\data\fish\spottedbass_rotten.rvmat"};
	};
	class geb_StripedBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_stripedbass";
		descriptionShort = "$STR_fish_stripedbass_desc";
		model = "\gebsfish\data\fish\stripedbass.p3d";
		weight = 46;
		weightPerQuantityUnit = 0.304;  // 350 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\stripedbass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\stripedbass.rvmat","\gebsfish\data\fish\stripedbass_rotten.rvmat"};
	};
	class geb_NeoshoBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_neoshobass";
		descriptionShort = "$STR_fish_neoshobass_desc";
		model = "\gebsfish\data\fish\neoshobass.p3d";
		weight = 78;
		weightPerQuantityUnit = 0.522;  // 600 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\neoshobass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\neoshobass.rvmat","\gebsfish\data\fish\neoshobass_rotten.rvmat"};
	};
	class geb_FlatHeadCatFish: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\gebsfish\data\fish\flatheadcatfish.p3d";
		itemSize[] = {7,2};
		weight = 5870;
		weightPerQuantityUnit = 39.13;  // 45 kg full
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\flatheadcatfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\flatheadcatfish.rvmat","\gebsfish\data\fish\flatheadcatfish_rotten.rvmat"};
	};
	class geb_WallEye: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_walleye";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\gebsfish\data\fish\walleye.p3d";
		weight = 196;
		weightPerQuantityUnit = 1.304;  // 1.5 kg full
		itemSize[] = {4,2};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\walleye_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\walleye.rvmat","\gebsfish\data\fish\walleye_rotten.rvmat"};
	};
	class geb_SmallMouthBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_smallmouthbass";
		descriptionShort = "$STR_fish_smallmouthbass_desc";
		model = "\gebsfish\data\fish\smallmouthbass.p3d";
		weight = 72;
		weightPerQuantityUnit = 0.478;  // 550 g full
		itemSize[] = {3,2};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\smallmouthbass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\smallmouthbass.rvmat","\gebsfish\data\fish\smallmouthbass_rotten.rvmat"};
	};
	class geb_LargeMouthBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_largemouthbass";
		descriptionShort = "$STR_fish_largemouthbass_desc";
		model = "\gebsfish\data\fish\largemouthbass.p3d";
		weight = 261;
		weightPerQuantityUnit = 1.739;  // 2 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\largemouthbass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\largemouthbass.rvmat","\gebsfish\data\fish\largemouthbass_rotten.rvmat"};
	};
	class geb_FatHeadMinnow: Shrimp {
		scope = 2;
		displayName = "$STR_fish_fatheadminnow";
		descriptionShort = "$STR_fish_fatheadminnow_desc";
		model = "\gebsfish\data\fish\minnow.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\minnow_co.paa","\gebsfish\data\fish\minnow_baked_co.paa","\gebsfish\data\fish\minnow_boiled_co.paa","\gebsfish\data\fish\minnow_dried_co.paa","\gebsfish\data\fish\minnow_burned_co.paa","\gebsfish\data\fish\minnow_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\minnow.rvmat","\gebsfish\data\fish\minnow_cooked.rvmat","\gebsfish\data\fish\minnow_cooked.rvmat","\gebsfish\data\fish\minnow_cooked.rvmat","\gebsfish\data\fish\minnow_cooked.rvmat","\gebsfish\data\fish\minnow_rotten.rvmat"};
		weight = 10;
		weightPerQuantityUnit = 0.436242;  // 75 g full
		itemSize[] = {1,1};
		// A full list, so the fire's cooking and smoking slots vanilla Shrimp
		// has are named again here, or this list would drop them.
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2",
			"GebFishMount",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		// ": Food" keeps Shrimp's FoodStageTransitions -- a Food class without
		// them sends every cooking method straight to Burned.
		class Food: Food
		{
			class FoodStages: FoodStages
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
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanbullfrog_co.paa","\gebsfish\data\fish\americanbullfrog_baked_co.paa","\gebsfish\data\fish\americanbullfrog_boiled_co.paa","\gebsfish\data\fish\americanbullfrog_dried_co.paa","\gebsfish\data\fish\americanbullfrog_burned_co.paa","\gebsfish\data\fish\americanbullfrog_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanbullfrog.rvmat","\gebsfish\data\fish\americanbullfrog_cooked.rvmat","\gebsfish\data\fish\americanbullfrog_cooked.rvmat","\gebsfish\data\fish\americanbullfrog_cooked.rvmat","\gebsfish\data\fish\americanbullfrog_cooked.rvmat","\gebsfish\data\fish\americanbullfrog_rotten.rvmat"};
		weight = 52;
		weightPerQuantityUnit = 2.33557;  // 400 g full
		itemSize[] = {1,1};
		// A full list, so the fire's cooking and smoking slots vanilla Shrimp
		// has are named again here, or this list would drop them.
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2",
			"GebFishMount",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		// ": Food" keeps Shrimp's FoodStageTransitions -- a Food class without
		// them sends every cooking method straight to Burned.
		class Food: Food
		{
			class FoodStages: FoodStages
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
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\redsalamander_co.paa","\gebsfish\data\fish\redsalamander_baked_co.paa","\gebsfish\data\fish\redsalamander_boiled_co.paa","\gebsfish\data\fish\redsalamander_dried_co.paa","\gebsfish\data\fish\redsalamander_burned_co.paa","\gebsfish\data\fish\redsalamander_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\redsalamander.rvmat","\gebsfish\data\fish\redsalamander_cooked.rvmat","\gebsfish\data\fish\redsalamander_cooked.rvmat","\gebsfish\data\fish\redsalamander_cooked.rvmat","\gebsfish\data\fish\redsalamander_cooked.rvmat","\gebsfish\data\fish\redsalamander_rotten.rvmat"};
		weight = 3;
		weightPerQuantityUnit = 0.147651;  // 25 g full
		itemSize[] = {1,1};
		// A full list, so the fire's cooking and smoking slots vanilla Shrimp
		// has are named again here, or this list would drop them.
		inventorySlot[]=
		{
			"Trap_Bait",
			"Bait",
			"Trap_Bait_1",
			"Trap_Bait_2",
			"GebFishMount",
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC",
			"SmokingA",
			"SmokingB",
			"SmokingC",
			"SmokingD"
		};
		// ": Food" keeps Shrimp's FoodStageTransitions -- a Food class without
		// them sends every cooking method straight to Burned.
		class Food: Food
		{
			class FoodStages: FoodStages
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
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\northernpike.rvmat","\gebsfish\data\fish\northernpike_rotten.rvmat"};

		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 3000;
		weightPerQuantityUnit = 20;  // 23 kg full
	};
	class geb_TigerMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_tigermuskellunge";
		descriptionShort = "$STR_fish_tigermuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 3261;
		weightPerQuantityUnit = 21.739;  // 25 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\tigermuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\tigermuskellunge.rvmat","\gebsfish\data\fish\tigermuskellunge_rotten.rvmat"};
	};
	class geb_Muskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_muskellunge";
		descriptionShort = "$STR_fish_muskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 3261;
		weightPerQuantityUnit = 21.739;  // 25 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\muskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\muskellunge.rvmat","\gebsfish\data\fish\muskellunge_rotten.rvmat"};
	};
	class geb_SpottedMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_spottedmuskellunge";
		descriptionShort = "$STR_fish_spottedmuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 3130;
		weightPerQuantityUnit = 20.87;  // 24 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\spottedmuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\spottedmuskellunge.rvmat","\gebsfish\data\fish\spottedmuskellunge_rotten.rvmat"};
	};
	class geb_BarredMuskellunge: geb_PikeMuskellunge_Base {
		scope = 2;
		displayName = "$STR_fish_barredmuskellunge";
		descriptionShort = "$STR_fish_barredmuskellunge_desc";
		itemSize[] = {6,2};
		rotationFlags = 0;
		weight = 3130;
		weightPerQuantityUnit = 20.87;  // 24 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\barredmuskellunge_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\barredmuskellunge.rvmat","\gebsfish\data\fish\barredmuskellunge_rotten.rvmat"};
	};
	class geb_AlligatorGar: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_alligatorgar";
		descriptionShort = "$STR_fish_alligatorgar_desc";
		model = "\gebsfish\data\fish\alligatorgar.p3d";
		itemSize[] = {6,2};
		weight = 1043;
		weightPerQuantityUnit = 6.957;  // 8 kg full
		rotationFlags = 0;
		// "Aligator Gar" is the body alone; Camo also holds the teeth (model.cfg).
		hiddenSelections[] = {"Aligator Gar"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\alligatorgar_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\alligatorgar.rvmat","\gebsfish\data\fish\alligatorgar_rotten.rvmat"};
	};
	class geb_NorthernSnakeHead: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_northernsnakehead";
		descriptionShort = "$STR_fish_northernsnakehead_desc";
		model = "\gebsfish\data\fish\northernsnakehead.p3d";
		itemSize[] = {6,2};
		weight = 1304;
		weightPerQuantityUnit = 8.696;  // 10 kg full
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\northernsnakehead_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\northernsnakehead.rvmat","\gebsfish\data\fish\northernsnakehead_rotten.rvmat"};
	};
	class geb_YellowPerch: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowperch";
		descriptionShort = "$STR_fish_yellowperch_desc";
		model = "\gebsfish\data\fish\perch.p3d";
		itemSize[] = {4,3};
		weight = 98;
		weightPerQuantityUnit = 0.652;  // 750 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\perch_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\perch.rvmat","\gebsfish\data\fish\perch_rotten.rvmat"};
	};
	class geb_Sauger: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_sauger";
		descriptionShort = "$STR_fish_sauger_desc";
		model = "\gebsfish\data\fish\sauger.p3d";
		itemSize[] = {4,1};
		weight = 143;
		weightPerQuantityUnit = 0.957;  // 1.1 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\sauger_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\sauger.rvmat","\gebsfish\data\fish\sauger_rotten.rvmat"};
	};
	class geb_RainbowTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\gebsfish\data\fish\rainbowtrout.p3d";
		itemSize[] = {5,2};
		weight = 222;
		weightPerQuantityUnit = 1.478;  // 1.7 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rainbowtrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\rainbowtrout.rvmat","\gebsfish\data\fish\rainbowtrout_rotten.rvmat"};
	};
	class geb_BrookTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_brooktrout";
		descriptionShort = "$STR_fish_brooktrout_desc";
		model = "\gebsfish\data\fish\brooktrout.p3d";
		itemSize[] = {5,2};
		weight = 183;
		weightPerQuantityUnit = 1.217;  // 1.4 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\brooktrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\brooktrout.rvmat","\gebsfish\data\fish\brooktrout_rotten.rvmat"};
	};
	class geb_BrownTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_browntrout";
		descriptionShort = "$STR_fish_browntrout_desc";
		model = "\gebsfish\data\fish\browntrout.p3d";
		itemSize[] = {5,2};
		weight = 196;
		weightPerQuantityUnit = 1.304;  // 1.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\browntrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\browntrout.rvmat","\gebsfish\data\fish\browntrout_rotten.rvmat"};
	};
	class geb_CutThroatTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_cutthroattrout";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		model = "\gebsfish\data\fish\cutthroattrout.p3d";
		itemSize[] = {5,2};
		weight = 196;
		weightPerQuantityUnit = 1.304;  // 1.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cutthroattrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\cutthroattrout.rvmat","\gebsfish\data\fish\cutthroattrout_rotten.rvmat"};
	};
	class geb_LakeTrout: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_laketrout";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\gebsfish\data\fish\laketrout.p3d";
		itemSize[] = {5,2};
		weight = 222;
		weightPerQuantityUnit = 1.478;  // 1.7 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\laketrout_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\laketrout.rvmat","\gebsfish\data\fish\laketrout_rotten.rvmat"};
	};
	class geb_LakeSturgeon: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_lakesturgeon";
		descriptionShort = "$STR_fish_lakesturgeon_desc";
		model = "\gebsfish\data\fish\lakesturgeon.p3d";
		itemSize[] = {5,2};
		rotationFlags = 0;
		weight = 11739;
		weightPerQuantityUnit = 78.261;  // 90 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\lakesturgeon_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\lakesturgeon.rvmat","\gebsfish\data\fish\lakesturgeon_rotten.rvmat"};
	};
	class geb_WhiteBass: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_whitebass";
		descriptionShort = "$STR_fish_whitebass_desc";
		model = "\gebsfish\data\fish\whitebass.p3d";
		weight = 300;
		weightPerQuantityUnit = 2;  // 2.3 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\whitebass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\whitebass.rvmat","\gebsfish\data\fish\whitebass_rotten.rvmat"};
	};
	class geb_BowFin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_bowfin";
		descriptionShort = "$STR_fish_bowfin_desc";
		model = "\gebsfish\data\fish\bowfin.p3d";
		itemSize[] = {4,2};
		weight = 170;
		weightPerQuantityUnit = 1.13;  // 1.3 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bowfin_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bowfin.rvmat","\gebsfish\data\fish\bowfin_rotten.rvmat"};
	};
	class geb_SlimySculpin: geb_FreshFish_Base {
		scope = 2;
		displayName = "$STR_fish_slimysculpin";
		descriptionShort = "$STR_fish_slimysculpin_desc";
		model = "\gebsfish\data\fish\slimysculpin.p3d";
		itemSize[] = {2,1};
		weight = 52;
		weightPerQuantityUnit = 0.348;  // 400 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\slimysculpin_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\slimysculpin.rvmat","\gebsfish\data\fish\slimysculpin_rotten.rvmat"};
	};

	//22 Saltwater Fish
	class geb_AngelFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_angelfish";
		descriptionShort = "$STR_fish_angelfish_desc";
		model = "\gebsfish\data\fish\angelfish.p3d";
		weight = 1435;
		weightPerQuantityUnit = 9.565;  // 11 kg full
		itemSize[] = {4,3};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\angelfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\angelfish.rvmat","\gebsfish\data\fish\angelfish_rotten.rvmat"};
	};
	class geb_AsianSeaBass: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_asianseabass";
		descriptionShort = "$STR_fish_asianseabass_desc";
		model = "\gebsfish\data\fish\asianseabass.p3d";
		weight = 104;
		weightPerQuantityUnit = 0.696;  // 800 g full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\asianseabass_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\asianseabass.rvmat","\gebsfish\data\fish\asianseabass_rotten.rvmat"};
	};
	class geb_AtlanticBlueMarlin: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_atlanticbluemarlin";
		descriptionShort = "$STR_fish_atlanticbluemarlin_desc";
		model = "\gebsfish\data\fish\bluemarlin.p3d";
		weight = 40435;
		weightPerQuantityUnit = 269.565;  // 310 kg full
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluemarlin_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bluemarlin.rvmat","\gebsfish\data\fish\bluemarlin_rotten.rvmat"};
	};
	class geb_AtlanticSailFish: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\gebsfish\data\fish\sailfish.p3d";
		weight = 26087;
		weightPerQuantityUnit = 173.913;  // 200 kg full
		itemSize[] = {20,7};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\sailfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\sailfish.rvmat","\gebsfish\data\fish\sailfish_rotten.rvmat"};
	};
	class geb_MahiMahi: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_mahimahi";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\gebsfish\data\fish\mahimahi.p3d";
		weight = 28696;
		weightPerQuantityUnit = 191.304;  // 220 kg full
		itemSize[] = {18,8};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\mahimahi_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\mahimahi.rvmat","\gebsfish\data\fish\mahimahi_rotten.rvmat"};
	};
	class geb_PacificBonito: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_pacificbonito";
		descriptionShort = "$STR_fish_pacificbonito_desc";
		model = "\gebsfish\data\fish\pacificbonito.p3d";
		weight = 326;
		weightPerQuantityUnit = 2.174;  // 2.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\pacificbonito_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\pacificbonito.rvmat","\gebsfish\data\fish\pacificbonito_rotten.rvmat"};
	};
	// geb_Bonita was the Pacific Bonito's class name until 3.3.3. This hidden
	// alias (scope 1: never spawned or listed, but a stored one still loads)
	// keeps the bonitos already on a server, in inventories, coolers and on
	// mounts, until the next wipe; remove it then. One lying loose on the
	// ground isn't saved again (no Central Economy profile for a scope 1
	// class) and is gone after the second restart (Cole: accepted). It fillets
	// as the Pacific Bonito (GebPrepareFishData lists it). The XML generators
	// leave it out.
	class geb_Bonita: geb_PacificBonito {
		scope = 1;
	};
	class geb_GreatBarracuda: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_greatbarracuda";
		descriptionShort = "$STR_fish_greatbarracuda_desc";
		model = "\gebsfish\data\fish\greatbarracuda.p3d";
		weight = 1304;
		weightPerQuantityUnit = 8.696;  // 10 kg full
		// 1.3 m long, laid like the northern pike (head +z, back +x) and carried the same way
		itemSize[] = {6,2};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\greatbarracuda_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\greatbarracuda.rvmat","\gebsfish\data\fish\greatbarracuda_rotten.rvmat"};
	};
	class geb_CherrySalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_cherrysalmon";
		descriptionShort = "$STR_fish_cherrysalmon_desc";
		model = "\gebsfish\data\fish\cherrysalmon.p3d";
		weight = 326;
		weightPerQuantityUnit = 2.174;  // 2.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cherrysalmon_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\cherrysalmon.rvmat","\gebsfish\data\fish\cherrysalmon_rotten.rvmat"};
	};
	class geb_SockEyeSalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_sockeyesalmon";
		descriptionShort = "$STR_fish_sockeyesalmon_desc";
		model = "\gebsfish\data\fish\sockeyesalmon.p3d";
		weight = 717;
		weightPerQuantityUnit = 4.783;  // 5.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\sockeyesalmon_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\sockeyesalmon.rvmat","\gebsfish\data\fish\sockeyesalmon_rotten.rvmat"};
	};
	class geb_ChinookSalmon: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_chinooksalmon";
		descriptionShort = "$STR_fish_chinooksalmon_desc";
		model = "\gebsfish\data\fish\chinooksalmon.p3d";
		weight = 326;
		weightPerQuantityUnit = 2.174;  // 2.5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\chinooksalmon_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\chinooksalmon.rvmat","\gebsfish\data\fish\chinooksalmon_rotten.rvmat"};
	};
	class geb_FlatHeadMullet: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_flatheadmullet";
		descriptionShort = "$STR_fish_flatheadmullet_desc";
		model = "\gebsfish\data\fish\flatheadmullet.p3d";
		weight = 130;
		weightPerQuantityUnit = 0.87;  // 1 kg full
		itemSize[] = {2,1};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\flatheadmullet_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\flatheadmullet.rvmat","\gebsfish\data\fish\flatheadmullet_rotten.rvmat"};
	};
	class geb_LeopardShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_leopardshark";
		descriptionShort = "$STR_fish_leopardshark_desc";
		model = "\gebsfish\data\fish\leopardshark.p3d";
		weight = 71739;
		weightPerQuantityUnit = 478.261;  // 550 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\leopardshark_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\leopardshark.rvmat","\gebsfish\data\fish\leopardshark_rotten.rvmat"};
	};
	class geb_HammerHeadShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_hammerheadshark";
		descriptionShort = "$STR_fish_hammerheadshark_desc";
		model = "\gebsfish\data\fish\hammerheadshark.p3d";
		weight = 78261;
		weightPerQuantityUnit = 521.739;  // 600 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\hammerheadshark_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\hammerheadshark.rvmat","\gebsfish\data\fish\hammerheadshark_rotten.rvmat"};
	};
	class geb_PacificCod: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_pacificcod";
		descriptionShort = "$STR_fish_pacificcod_desc";
		model = "\gebsfish\data\fish\pacificcod.p3d";
		weight = 652;
		weightPerQuantityUnit = 4.348;  // 5 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\pacificcod_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\pacificcod.rvmat","\gebsfish\data\fish\pacificcod_rotten.rvmat"};
	};
	class geb_RedHeadCichlid: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_redheadcichlid";
		descriptionShort = "$STR_fish_redheadcichlid_desc";
		model = "\gebsfish\data\fish\redheadcichlid.p3d";
		weight = 1304;
		weightPerQuantityUnit = 8.696;  // 10 kg full
		itemSize[] = {4,3};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\redheadcichlid_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\redheadcichlid.rvmat","\gebsfish\data\fish\redheadcichlid_rotten.rvmat"};
	};
	//Needs to be renamed RoughEyeRock next wipe
	class geb_RoughNeckRock: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_rougheyerock";
		descriptionShort = "$STR_fish_rougheyerock_desc";
		model = "\gebsfish\data\fish\rougheyerock.p3d";
		weight = 261;
		weightPerQuantityUnit = 1.739;  // 2 kg full
		itemSize[] = {4,3};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rougheyerock_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\rougheyerock.rvmat","\gebsfish\data\fish\rougheyerock_rotten.rvmat"};
	};
	class geb_Severum: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_severum";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\gebsfish\data\fish\severum.p3d";
		weight = 2217;
		weightPerQuantityUnit = 14.783;  // 17 kg full
		itemBehaviour = 2;  // two-handed, matching its in-hands registration (0 is "heavy", like a tent)
		itemSize[] = {5,4};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\severum_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\severum.rvmat","\gebsfish\data\fish\severum_rotten.rvmat"};
	};
	class geb_BlueTang: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_bluetang";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\gebsfish\data\fish\bluetang.p3d";
		weight = 2217;
		weightPerQuantityUnit = 14.783;  // 17 kg full
		itemSize[] = {4,3};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluetang_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bluetang.rvmat","\gebsfish\data\fish\bluetang_rotten.rvmat"};
	};
	class geb_LargeHeadHairTailFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\gebsfish\data\fish\hairtailfish.p3d";
		weight = 652;
		weightPerQuantityUnit = 4.348;  // 5 kg full
		itemSize[] = {8,2};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\hairtailfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\hairtailfish.rvmat","\gebsfish\data\fish\hairtailfish_rotten.rvmat"};
	};
	class geb_HumpHeadWrasse: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\gebsfish\data\fish\humpheadwrasse.p3d";
		weight = 10435;
		weightPerQuantityUnit = 69.565;  // 80 kg full
		itemSize[] = {5,4};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\humpheadwrasse_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\humpheadwrasse.rvmat","\gebsfish\data\fish\humpheadwrasse_rotten.rvmat"};
	};
	class geb_SiameseTigerFish: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\gebsfish\data\fish\siamesetigerfish.p3d";
		weight = 1017;
		weightPerQuantityUnit = 6.783;  // 7.8 kg full
		itemSize[] = {3,3};
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\siamesetigerfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\siamesetigerfish.rvmat","\gebsfish\data\fish\siamesetigerfish_rotten.rvmat"};
	};
	class geb_AngelShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_angelshark";
		descriptionShort = "$STR_fish_angelshark_desc";
		model = "\gebsfish\data\fish\angelshark.p3d";
		weight = 19565;
		weightPerQuantityUnit = 130.435;  // 150 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\angelshark_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\angelshark.rvmat","\gebsfish\data\fish\angelshark_rotten.rvmat"};
	};
	class geb_GreatWhiteShark: geb_LargeFish_Base {
		scope = 2;
		displayName = "$STR_fish_greatwhiteshark";
		descriptionShort = "$STR_fish_greatwhiteshark_desc";
		model = "\gebsfish\data\fish\greatwhiteshark.p3d";
		weight = 326087;
		weightPerQuantityUnit = 2173.913;  // 2,500 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\greatwhiteshark_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\greatwhiteshark.rvmat","\gebsfish\data\fish\greatwhiteshark_rotten.rvmat"};
	};
	class geb_YellowFinTuna: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowfintuna";
		descriptionShort = "$STR_fish_yellowfintuna_desc";
		model = "\gebsfish\data\fish\yellowfintuna.p3d";
		weight = 391;
		weightPerQuantityUnit = 2.609;  // 3 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\yellowfintuna_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\yellowfintuna.rvmat","\gebsfish\data\fish\yellowfintuna_rotten.rvmat"};
	};
	class geb_WhiteGrunt: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_whitegrunt";
		descriptionShort = "$STR_fish_whitegrunt_desc";
		model = "\gebsfish\data\fish\whitegrunt.p3d";
		weight = 783;
		weightPerQuantityUnit = 5.217;  // 6 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\whitegrunt_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\whitegrunt.rvmat","\gebsfish\data\fish\whitegrunt_rotten.rvmat"};
	};
	class geb_SouthernFlounder: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_southernflounder";
		descriptionShort = "$STR_fish_southernflounder_desc";
		model = "\gebsfish\data\fish\southernflounder.p3d";
		weight = 1696;
		weightPerQuantityUnit = 11.304;  // 13 kg full
		rotationFlags = 0;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\southernflounder_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\southernflounder.rvmat","\gebsfish\data\fish\southernflounder_rotten.rvmat"};
	};
	class geb_YellowSnapper: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_yellowsnapper";
		descriptionShort = "$STR_fish_yellowsnapper_desc";
		model = "\gebsfish\data\fish\yellowsnapper.p3d";
		weight = 235;
		weightPerQuantityUnit = 1.565;  // 1.8 kg full
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\yellowsnapper_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\yellowsnapper.rvmat","\gebsfish\data\fish\yellowsnapper_rotten.rvmat"};
	};
	//8 Saltwater crustaceans
	class geb_BloodClam: Shrimp {
		scope = 2;
		displayName = "$STR_fish_bloodclam";
		descriptionShort = "$STR_fish_bloodclam_desc";
		model = "\gebsfish\data\fish\bloodclam.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bloodclam_co.paa","\gebsfish\data\fish\bloodclam_baked_co.paa","\gebsfish\data\fish\bloodclam_boiled_co.paa","\gebsfish\data\fish\bloodclam_dried_co.paa","\gebsfish\data\fish\bloodclam_burned_co.paa","\gebsfish\data\fish\bloodclam_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bloodclam.rvmat","\gebsfish\data\fish\bloodclam_cooked.rvmat","\gebsfish\data\fish\bloodclam_cooked.rvmat","\gebsfish\data\fish\bloodclam_cooked.rvmat","\gebsfish\data\fish\bloodclam_cooked.rvmat","\gebsfish\data\fish\bloodclam_rotten.rvmat"};
		weight = 33;
		weightPerQuantityUnit = 1.456376;  // 250 g full
		itemSize[] = {1,1};
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
	};
	//Needs to be renamed geb_BlueMussel next wipe
	class geb_Mussel: Shrimp {
		scope = 2;
		displayName = "$STR_fish_mussel";
		descriptionShort = "$STR_fish_mussel_desc";
		model = "\gebsfish\data\fish\mussel.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\mussel_inside_co.paa","\gebsfish\data\fish\mussel_inside_baked_co.paa","\gebsfish\data\fish\mussel_inside_boiled_co.paa","\gebsfish\data\fish\mussel_inside_dried_co.paa","\gebsfish\data\fish\mussel_inside_burned_co.paa","\gebsfish\data\fish\mussel_inside_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\mussel_inside.rvmat","\gebsfish\data\fish\mussel_inside_cooked.rvmat","\gebsfish\data\fish\mussel_inside_cooked.rvmat","\gebsfish\data\fish\mussel_inside_cooked.rvmat","\gebsfish\data\fish\mussel_inside_cooked.rvmat","\gebsfish\data\fish\mussel_inside_rotten.rvmat"};
		weight = 10;
		weightPerQuantityUnit = 0.469799;  // 80 g full
		itemSize[] = {1,1};
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
	};
	class geb_BlackDevilSnail: Shrimp {
		scope = 2;
		displayName = "$STR_fish_blackdevilsnail";
		descriptionShort = "$STR_fish_blackdevilsnail_desc";
		model = "\gebsfish\data\fish\blackdevilsnail.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\blackdevilsnail_co.paa","\gebsfish\data\fish\blackdevilsnail_baked_co.paa","\gebsfish\data\fish\blackdevilsnail_boiled_co.paa","\gebsfish\data\fish\blackdevilsnail_dried_co.paa","\gebsfish\data\fish\blackdevilsnail_burned_co.paa","\gebsfish\data\fish\blackdevilsnail_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\blackdevilsnail.rvmat","\gebsfish\data\fish\blackdevilsnail_cooked.rvmat","\gebsfish\data\fish\blackdevilsnail_cooked.rvmat","\gebsfish\data\fish\blackdevilsnail_cooked.rvmat","\gebsfish\data\fish\blackdevilsnail_cooked.rvmat","\gebsfish\data\fish\blackdevilsnail_rotten.rvmat"};
		weight = 8;
		weightPerQuantityUnit = 0.348993;  // 60 g full
		itemSize[] = {1,1};
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
	};
	class geb_StarFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_starfish";
		descriptionShort = "$STR_fish_starfish_desc";
		model = "\gebsfish\data\fish\starfish.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\starfish_co.paa","\gebsfish\data\fish\starfish_baked_co.paa","\gebsfish\data\fish\starfish_boiled_co.paa","\gebsfish\data\fish\starfish_dried_co.paa","\gebsfish\data\fish\starfish_burned_co.paa","\gebsfish\data\fish\starfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\starfish.rvmat","\gebsfish\data\fish\starfish_cooked.rvmat","\gebsfish\data\fish\starfish_cooked.rvmat","\gebsfish\data\fish\starfish_cooked.rvmat","\gebsfish\data\fish\starfish_cooked.rvmat","\gebsfish\data\fish\starfish_rotten.rvmat"};
		weight = 26;
		weightPerQuantityUnit = 1.167785;  // 200 g full
		itemSize[] = {2,2};
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
	};
	class geb_BlueJellyFish: Shrimp {
		scope = 2;
		displayName = "$STR_fish_bluejellyfish";
		descriptionShort = "$STR_fish_bluejellyfish_desc";
		model = "\gebsfish\data\fish\bluejellyfish.p3d";
		// Cooked, burned and rotten looks (vanilla Shrimp's FoodStages: raw 0, baked 1, boiled 2,
		// dried 3, burned 4, rotten 5); the textures follow vanilla's cooked whole fish.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\bluejellyfish_co.paa","\gebsfish\data\fish\bluejellyfish_baked_co.paa","\gebsfish\data\fish\bluejellyfish_boiled_co.paa","\gebsfish\data\fish\bluejellyfish_dried_co.paa","\gebsfish\data\fish\bluejellyfish_burned_co.paa","\gebsfish\data\fish\bluejellyfish_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\bluejellyfish.rvmat","\gebsfish\data\fish\bluejellyfish_cooked.rvmat","\gebsfish\data\fish\bluejellyfish_cooked.rvmat","\gebsfish\data\fish\bluejellyfish_cooked.rvmat","\gebsfish\data\fish\bluejellyfish_cooked.rvmat","\gebsfish\data\fish\bluejellyfish_rotten.rvmat"};
		weight = 39;
		weightPerQuantityUnit = 1.751678;  // 300 g full
		itemSize[] = {2,2};
		inventorySlot[] = {"DirectCookingA", "DirectCookingB", "DirectCookingC", "SmokingA", "SmokingB", "SmokingC", "SmokingD", "GebFishMount"};
	};
	class geb_AmericanLobster: geb_Lobster_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobster_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobster.rvmat","\gebsfish\data\fish\americanlobster_rotten.rvmat"};
	};
	class geb_EuropeanLobster: geb_Lobster_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobster_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobster.rvmat","\gebsfish\data\fish\europeanlobster_rotten.rvmat"};
	};
	class geb_KingCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_kingcrab";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrab.p3d";
		rotationFlags = 17;
		weight = 652;
		weightPerQuantityUnit = 4.348;  // 5 kg full
		itemSize[] = {3,3};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\kingcrab_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab_rotten.rvmat"};
	};
	class geb_SnowCrab: geb_SaltFish_Base {
		scope = 2;
		displayName = "$STR_fish_snowcrab";
		descriptionShort = "$STR_fish_snowcrab_desc";
		model = "\gebsfish\data\fish\snowcrab.p3d";
		rotationFlags = 17;
		weight = 196;
		weightPerQuantityUnit = 1.304;  // 1.5 kg full
		itemSize[] = {3,3};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\snowcrab_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab_rotten.rvmat"};
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_european.rvmat",
			"\gebsfish\data\fish\crayfish_european.rvmat",
			"\gebsfish\data\fish\crayfish_european.rvmat",
			"\gebsfish\data\fish\crayfish_european.rvmat",
			"\gebsfish\data\fish\crayfish_european.rvmat",
			"\gebsfish\data\fish\crayfish_european.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_signal.rvmat",
			"\gebsfish\data\fish\crayfish_signal.rvmat",
			"\gebsfish\data\fish\crayfish_signal.rvmat",
			"\gebsfish\data\fish\crayfish_signal.rvmat",
			"\gebsfish\data\fish\crayfish_signal.rvmat",
			"\gebsfish\data\fish\crayfish_signal.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_florida.rvmat",
			"\gebsfish\data\fish\crayfish_florida.rvmat",
			"\gebsfish\data\fish\crayfish_florida.rvmat",
			"\gebsfish\data\fish\crayfish_florida.rvmat",
			"\gebsfish\data\fish\crayfish_florida.rvmat",
			"\gebsfish\data\fish\crayfish_florida.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_rusty.rvmat",
			"\gebsfish\data\fish\crayfish_rusty.rvmat",
			"\gebsfish\data\fish\crayfish_rusty.rvmat",
			"\gebsfish\data\fish\crayfish_rusty.rvmat",
			"\gebsfish\data\fish\crayfish_rusty.rvmat",
			"\gebsfish\data\fish\crayfish_rusty.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_redswamp.rvmat",
			"\gebsfish\data\fish\crayfish_redswamp.rvmat",
			"\gebsfish\data\fish\crayfish_redswamp.rvmat",
			"\gebsfish\data\fish\crayfish_redswamp.rvmat",
			"\gebsfish\data\fish\crayfish_redswamp.rvmat",
			"\gebsfish\data\fish\crayfish_redswamp.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_monongahela.rvmat",
			"\gebsfish\data\fish\crayfish_monongahela.rvmat",
			"\gebsfish\data\fish\crayfish_monongahela.rvmat",
			"\gebsfish\data\fish\crayfish_monongahela.rvmat",
			"\gebsfish\data\fish\crayfish_monongahela.rvmat",
			"\gebsfish\data\fish\crayfish_monongahela.rvmat"
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
			"\gebsfish\data\fish\crayfish_baked_co.paa",
			"\gebsfish\data\fish\crayfish_boiled_co.paa",
			"\gebsfish\data\fish\crayfish_dried_co.paa",
			"\gebsfish\data\fish\crayfish_burned_co.paa",
			"\gebsfish\data\fish\crayfish_rotten_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"\gebsfish\data\fish\crayfish_cave.rvmat",
			"\gebsfish\data\fish\crayfish_cave.rvmat",
			"\gebsfish\data\fish\crayfish_cave.rvmat",
			"\gebsfish\data\fish\crayfish_cave.rvmat",
			"\gebsfish\data\fish\crayfish_cave.rvmat",
			"\gebsfish\data\fish\crayfish_cave.rvmat"
		};
	};

	//Freshwater Fish Fillets
	class geb_BlueGillFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_bluegill_fillet";
		descriptionShort = "$STR_fish_bluegill_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluegill_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	// Class name kept as geb_BlackBassFilletMeat to avoid corrupting existing server inventories.
	// All player-facing content (display name, description, textures) is spotted bass.
	class geb_BlackBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_spottedbass_fillet";
		descriptionShort = "$STR_fish_spottedbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\spottedbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_StripedBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_stripedbass_fillet";
		descriptionShort = "$STR_fish_stripedbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\stripedbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_NeoshoBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_neoshobass_fillet";
		descriptionShort = "$STR_fish_neoshobass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\neoshobass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_SmallMouthBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_Smallmouthbass_fillet";
		descriptionShort = "$STR_fish_Smallmouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\smallmouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_WallEyeFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_walleye_fillet";
		descriptionShort = "$STR_fish_walleye_desc";
		model = "\dz\gear\food\walleye_pollock_fillet.p3d";
		// On vanilla WalleyePollockFilletMeat's model, with its cooked, rotten and material
		// lists; only the raw texture is this fish's own (same layout as vanilla's).
		// Its rotten stage shows the rotten texture, as vanilla's does.
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\walleye_fillet_co.paa","dz\gear\food\data\walleyepollock_fillet_baked_co.paa","dz\gear\food\data\walleyepollock_fillet_boiled_co.paa","dz\gear\food\data\walleyepollock_fillet_dried_co.paa","dz\gear\food\data\walleyepollock_fillet_burnt_co.paa","dz\gear\food\data\walleyepollock_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\walleyepollock_fillet_raw.rvmat","dz\gear\food\data\walleyepollock_fillet_baked.rvmat","dz\gear\food\data\walleyepollock_fillet_boiled.rvmat","dz\gear\food\data\walleyepollock_fillet_dried.rvmat","dz\gear\food\data\walleyepollock_fillet_burnt.rvmat","dz\gear\food\data\walleyepollock_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	//Will need to be renamed RedBreastSunFishFillet next wipe
	class geb_SunFishFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_redbreastsunfish_fillet";
		descriptionShort = "$STR_fish_redbreastsunfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redbreastsunfish_fillet_raw_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_FlatHeadCatFishFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_flatheadcatfish_fillet";
		descriptionShort = "$STR_fish_flatheadcatfish_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadcatfish_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_LargeMouthBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_largemouthbass_fillet";
		descriptionShort = "$STR_fish_largemouthbass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\largemouthbass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_NorthernPikeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_northernpike_fillet";
		descriptionShort = "$STR_fish_northernpike_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernpike_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_MuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_muskellunge_fillet";
		descriptionShort = "$STR_fish_muskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\muskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_SpottedMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_spottedmuskellunge_fillet";
		descriptionShort = "$STR_fish_spottedmuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\spottedmuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_BarredMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_barredmuskellunge_fillet";
		descriptionShort = "$STR_fish_barredmuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\barredmuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_TigerMuskellungeFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_tigermuskellunge_fillet";
		descriptionShort = "$STR_fish_tigermuskellunge_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\tigermuskellunge_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_AlligatorGarFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_alligatorgar_fillet";
		descriptionShort = "$STR_fish_alligatorgar_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\alligatorgar_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_NorthernSnakeHeadFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_northernsnakehead_fillet";
		descriptionShort = "$STR_fish_northernsnakehead_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\northernsnakehead_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_YellowPerchFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_yellowperch_fillet";
		descriptionShort = "$STR_fish_yellowperch_desc";
		model = "\dz\gear\food\walleye_pollock_fillet.p3d";
		// Vanilla WalleyePollockFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\perch_fillet_co.paa","dz\gear\food\data\walleyepollock_fillet_baked_co.paa","dz\gear\food\data\walleyepollock_fillet_boiled_co.paa","dz\gear\food\data\walleyepollock_fillet_dried_co.paa","dz\gear\food\data\walleyepollock_fillet_burnt_co.paa","dz\gear\food\data\walleyepollock_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\walleyepollock_fillet_raw.rvmat","dz\gear\food\data\walleyepollock_fillet_baked.rvmat","dz\gear\food\data\walleyepollock_fillet_boiled.rvmat","dz\gear\food\data\walleyepollock_fillet_dried.rvmat","dz\gear\food\data\walleyepollock_fillet_burnt.rvmat","dz\gear\food\data\walleyepollock_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_SaugerFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_sauger_fillet";
		descriptionShort = "$STR_fish_sauger_desc";
		model = "\dz\gear\food\walleye_pollock_fillet.p3d";
		// Vanilla WalleyePollockFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\sauger_fillet_co.paa","dz\gear\food\data\walleyepollock_fillet_baked_co.paa","dz\gear\food\data\walleyepollock_fillet_boiled_co.paa","dz\gear\food\data\walleyepollock_fillet_dried_co.paa","dz\gear\food\data\walleyepollock_fillet_burnt_co.paa","dz\gear\food\data\walleyepollock_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\walleyepollock_fillet_raw.rvmat","dz\gear\food\data\walleyepollock_fillet_baked.rvmat","dz\gear\food\data\walleyepollock_fillet_boiled.rvmat","dz\gear\food\data\walleyepollock_fillet_dried.rvmat","dz\gear\food\data\walleyepollock_fillet_burnt.rvmat","dz\gear\food\data\walleyepollock_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_RainbowTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_rainbowtrout_fillet";
		descriptionShort = "$STR_fish_rainbowtrout_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\rainbowtrout_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_BrownTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_browntrout_fillet";
		descriptionShort = "$STR_fish_browntrout_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\browntrout_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_BrookTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_brooktrout_fillet";
		descriptionShort = "$STR_fish_brooktrout_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\brooktrout_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_CutThroatTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_cuthroattrout_fillet";
		descriptionShort = "$STR_fish_cutthroattrout_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cutthroattrout_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_LakeTroutFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_laketrout_fillet";
		descriptionShort = "$STR_fish_laketrout_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\laketrout_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_LakeSturgeonFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_lakesturgeon_fillet";
		descriptionShort = "$STR_fish_lakesturgeon_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\lakesturgeon_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_WhiteBassFilletMeat: geb_FreshWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_whitebass_fillet";
		descriptionShort = "$STR_fish_whitebass_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitebass_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_BowFinFilletMeat: geb_FreshWater_Fillet_Heavy {
		scope = 2;
		displayName = "$STR_fish_bowfin_fillet";
		descriptionShort = "$STR_fish_bowfin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bowfin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};
	class geb_SlimySculpinFilletMeat: geb_FreshWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_slimysculpin_fillet";
		descriptionShort = "$STR_fish_slimysculpin_desc";
		model = "\dz\gear\food\carp_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\slimysculpin_fillet_co.paa","dz\gear\food\data\carp_fillet_baked_co.paa","dz\gear\food\data\carp_fillet_boiled_co.paa","dz\gear\food\data\carp_fillet_dried_co.paa","dz\gear\food\data\carp_fillet_burnt_co.paa"
		};
	};

	//Saltwater Fish fillets
	class geb_AngelFishFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_angelfish_fillet";
		descriptionShort = "$STR_fish_angelfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_AsianSeaBassFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_asianseabass_fillet";
		descriptionShort = "$STR_fish_asianseabass_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\asianseabass_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_AtlanticBlueMarlinFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_atlanticbluemarlin_fillet";
		descriptionShort = "$STR_fish_atlanticbluemarlin_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluemarlin_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_AtlanticSailFishFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_atlanticsailfish_fillet";
		descriptionShort = "$STR_fish_atlanticsailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\sailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_MahiMahiFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_mahimahi_fillet";
		descriptionShort = "$STR_fish_mahimahi_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\mahimahi_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_PacificBonitoFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_pacificbonito_fillet";
		descriptionShort = "$STR_fish_pacificbonito_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\pacificbonito_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_GreatBarracudaFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_greatbarracuda_fillet";
		descriptionShort = "$STR_fish_greatbarracuda_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\greatbarracuda_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_CherrySalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_cherrysalmon_fillet";
		descriptionShort = "$STR_fish_cherrysalmon_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\cherrysalmon_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_SockEyeSalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_sockeyesalmon_fillet";
		descriptionShort = "$STR_fish_sockeyesalmon_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\sockeyesalmon_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_ChinookSalmonFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_chinooksalmon_fillet";
		descriptionShort = "$STR_fish_chinooksalmon_desc";
		model = "\dz\gear\food\steelhead_trout_fillet.p3d";
		// Vanilla SteelheadTroutFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\chinooksalmon_fillet_co.paa","dz\gear\food\data\steelheadtrout_fillet_baked_co.paa","dz\gear\food\data\steelheadtrout_fillet_boiled_co.paa","dz\gear\food\data\steelheadtrout_fillet_dried_co.paa","dz\gear\food\data\steelheadtrout_fillet_burnt_co.paa","dz\gear\food\data\steelheadtrout_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\steelheadtrout_fillet_raw.rvmat","dz\gear\food\data\steelheadtrout_fillet_baked.rvmat","dz\gear\food\data\steelheadtrout_fillet_boiled.rvmat","dz\gear\food\data\steelheadtrout_fillet_dried.rvmat","dz\gear\food\data\steelheadtrout_fillet_burnt.rvmat","dz\gear\food\data\steelheadtrout_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_FlatHeadMulletFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_flatheadmullet_fillet";
		descriptionShort = "$STR_fish_flatheadmullet_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\flatheadmullet_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_LeopardSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_leopardshark_fillet";
		descriptionShort = "$STR_fish_leopardshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\leopardshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_HammerHeadSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_hammerheadshark_fillet";
		descriptionShort = "$STR_fish_hammerheadshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hammerheadshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_PacificCodFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_pacificcod_fillet";
		descriptionShort = "$STR_fish_pacificcod_desc";
		model = "\dz\gear\food\walleye_pollock_fillet.p3d";
		// Vanilla WalleyePollockFilletMeat's model and lists (see geb_WallEyeFilletMeat).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\pacificcod_fillet_co.paa","dz\gear\food\data\walleyepollock_fillet_baked_co.paa","dz\gear\food\data\walleyepollock_fillet_boiled_co.paa","dz\gear\food\data\walleyepollock_fillet_dried_co.paa","dz\gear\food\data\walleyepollock_fillet_burnt_co.paa","dz\gear\food\data\walleyepollock_fillet_rotten_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\walleyepollock_fillet_raw.rvmat","dz\gear\food\data\walleyepollock_fillet_baked.rvmat","dz\gear\food\data\walleyepollock_fillet_boiled.rvmat","dz\gear\food\data\walleyepollock_fillet_dried.rvmat","dz\gear\food\data\walleyepollock_fillet_burnt.rvmat","dz\gear\food\data\walleyepollock_fillet_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Rotten: Rotten
				{
					visual_properties[] = {0,5,5};
				};
			};
		};
	};
	class geb_RedHeadCichlidFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_redheadcichlid_fillet";
		descriptionShort = "$STR_fish_redheadcichlid_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\redheadcichlid_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	//Will need to be renamed RoughEyeRockFilletMeat next wipe
	class geb_RoughNeckRockFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_rougheyerock_fillet";
		descriptionShort = "$STR_fish_rougheyerock_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\rougheyerock_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_SeverumFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_severum_fillet";
		descriptionShort = "$STR_fish_severum_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\severum_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_BlueTangFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_bluetang_fillet";
		descriptionShort = "$STR_fish_bluetang_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\bluetang_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_LargeHeadHairTailFishFilletMeat: geb_SaltWater_Fillet_Lean {
		scope = 2;
		displayName = "$STR_fish_largeheadhairtailfish_fillet";
		descriptionShort = "$STR_fish_largeheadhairtailfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\hairtailfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
		// Raw: its own material, so the skin side reflects like the fish's silver skin (vanilla's
		// chrome landscape reflection map); cooked and rotten as vanilla's mackerel fillet.
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\hairtailfish_fillet_raw.rvmat","dz\gear\food\data\mackerel_fillet_baked.rvmat","dz\gear\food\data\mackerel_fillet_boiled.rvmat","dz\gear\food\data\mackerel_fillet_dried.rvmat","dz\gear\food\data\mackerel_fillet_burnt.rvmat","dz\gear\food\data\mackerel_fillet_rotten.rvmat"};
	};
	class geb_HumpHeadWrasseFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_humpheadwrasse_fillet";
		descriptionShort = "$STR_fish_humpheadwrasse_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\humpheadwrasse_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_SiameseTigerFishFilletMeat: geb_SaltWater_Fillet_Medium {
		scope = 2;
		displayName = "$STR_fish_siamesetigerfish_fillet";
		descriptionShort = "$STR_fish_siamesetigerfish_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\siamesetigerfish_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_GreatWhiteSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_greatwhiteshark_fillet";
		descriptionShort = "$STR_fish_greatwhiteshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\greatwhiteshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_AngelSharkFilletMeat: geb_SaltWater_Fillet_Predator{
		scope = 2;
		displayName = "$STR_fish_angelshark_fillet";
		descriptionShort = "$STR_fish_angelshark_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\angelshark_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_YellowFinTunaFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_yellowfintuna_fillet";
		descriptionShort = "$STR_fish_yellowfintuna_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowfintuna_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_WhiteGruntFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_whitegrunt_fillet";
		descriptionShort = "$STR_fish_whitegrunt_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\whitegrunt_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_SouthernFlounderFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_southernflounder_fillet";
		descriptionShort = "$STR_fish_southernflounder_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\southernflounder_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	class geb_YellowSnapperFilletMeat: geb_SaltWater_Fillet_Fatty{
		scope = 2;
		displayName = "$STR_fish_yellowsnapper_fillet";
		descriptionShort = "$STR_fish_yellowsnapper_desc";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		hiddenSelectionsTextures[] = {
			"\gebsfish\data\fish\yellowsnapper_fillet_co.paa","dz\gear\food\data\mackerel_fillet_baked_co.paa","dz\gear\food\data\mackerel_fillet_boiled_co.paa","dz\gear\food\data\mackerel_fillet_dried_co.paa","dz\gear\food\data\mackerel_fillet_burnt_co.paa"
		};
	};
	//Crustacean Fillets/Legs/Claws
	class geb_KingCrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_kingcrab_legs";
		descriptionShort = "$STR_fish_kingcrab_desc";
		model = "\gebsfish\data\fish\kingcrablegs.p3d";
		// The model's only retexturable selection is "Camo"; the fillet's
		// inherited "cs_raw" doesn't exist on it, so the texture lines did
		// nothing. The cooking stages use the crab's own cooked textures below
		// (the mackerel fillet ones it would inherit look wrong on crab).
		hiddenSelections[] = {"Camo"};
		// Textures in vanilla's fillet stage order: raw, baked, boiled, dried,
		// burned (baked and boiled share the cooked look). Materials: the
		// same for every stage, then the rotten one (stage material 5).
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\kingcrab_co.paa","\gebsfish\data\fish\kingcrablegs_cooked_co.paa","\gebsfish\data\fish\kingcrablegs_cooked_co.paa","\gebsfish\data\fish\kingcrablegs_dried_co.paa","\gebsfish\data\fish\kingcrablegs_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab.rvmat","\gebsfish\data\fish\kingcrab_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {5,95,68,1,0,16,1,9};
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
					nutrition_properties[] = {2,135,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
				};
			};
		};
	};
	class geb_SnowCrabLegs: MackerelFilletMeat {
		scope = 2;
		displayName = "$STR_fish_snowcrab_legs";
		descriptionShort = "$STR_fish_snowcrab_desc";
		model = "\gebsfish\data\fish\snowcrablegs.p3d";
		// See geb_KingCrabLegs: "Camo" is the model's real selection.
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\snowcrab_co.paa","\gebsfish\data\fish\snowcrablegs_cooked_co.paa","\gebsfish\data\fish\snowcrablegs_cooked_co.paa","\gebsfish\data\fish\snowcrablegs_dried_co.paa","\gebsfish\data\fish\snowcrablegs_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab.rvmat","\gebsfish\data\fish\snowcrab_rotten.rvmat"};
		class Food: Food
		{
			class FoodStages: FoodStages
			{
				class Raw: Raw
				{
					nutrition_properties[] = {5,78,64,1,0,16,1,9};
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
					nutrition_properties[] = {2,118,10,1,0};
				};
				class Burned: Burned
				{
					nutrition_properties[] = {5,20,0,1,0,16,1,3};
				};
			};
		};
	};
	class geb_AmericanLobsterTail : geb_LobsterTail_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster_tail";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobstertail_co.paa","\gebsfish\data\fish\americanlobstertail_cooked_co.paa","\gebsfish\data\fish\americanlobstertail_cooked_co.paa","\gebsfish\data\fish\americanlobstertail_dried_co.paa","\gebsfish\data\fish\americanlobstertail_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobstertail.rvmat","\gebsfish\data\fish\americanlobstertail.rvmat","\gebsfish\data\fish\americanlobstertail.rvmat","\gebsfish\data\fish\americanlobstertail.rvmat","\gebsfish\data\fish\americanlobstertail.rvmat","\gebsfish\data\fish\americanlobstertail_rotten.rvmat"};
	};
	class geb_EuropeanLobsterTail : geb_LobsterTail_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_tail";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobstertail_co.paa","\gebsfish\data\fish\europeanlobstertail_cooked_co.paa","\gebsfish\data\fish\europeanlobstertail_cooked_co.paa","\gebsfish\data\fish\europeanlobstertail_dried_co.paa","\gebsfish\data\fish\europeanlobstertail_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobstertail.rvmat","\gebsfish\data\fish\europeanlobstertail.rvmat","\gebsfish\data\fish\europeanlobstertail.rvmat","\gebsfish\data\fish\europeanlobstertail.rvmat","\gebsfish\data\fish\europeanlobstertail.rvmat","\gebsfish\data\fish\europeanlobstertail_rotten.rvmat"};
	};
	class geb_AmericanLobsterClaw : geb_LobsterClaw_Base {
		scope = 2;
		displayName = "$STR_fish_americanlobster_claw";
		descriptionShort = "$STR_fish_americanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\americanlobsterclaw_co.paa","\gebsfish\data\fish\americanlobsterclaw_cooked_co.paa","\gebsfish\data\fish\americanlobsterclaw_cooked_co.paa","\gebsfish\data\fish\americanlobsterclaw_dried_co.paa","\gebsfish\data\fish\americanlobsterclaw_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\americanlobsterclaw.rvmat","\gebsfish\data\fish\americanlobsterclaw.rvmat","\gebsfish\data\fish\americanlobsterclaw.rvmat","\gebsfish\data\fish\americanlobsterclaw.rvmat","\gebsfish\data\fish\americanlobsterclaw.rvmat","\gebsfish\data\fish\americanlobsterclaw_rotten.rvmat"};
	};
	class geb_EuropeanLobsterClaw : geb_LobsterClaw_Base {
		scope = 2;
		displayName = "$STR_fish_europeanlobster_claw";
		descriptionShort = "$STR_fish_europeanlobster_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\fish\europeanlobsterclaw_co.paa","\gebsfish\data\fish\europeanlobsterclaw_cooked_co.paa","\gebsfish\data\fish\europeanlobsterclaw_cooked_co.paa","\gebsfish\data\fish\europeanlobsterclaw_dried_co.paa","\gebsfish\data\fish\europeanlobsterclaw_burned_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\fish\europeanlobsterclaw.rvmat","\gebsfish\data\fish\europeanlobsterclaw.rvmat","\gebsfish\data\fish\europeanlobsterclaw.rvmat","\gebsfish\data\fish\europeanlobsterclaw.rvmat","\gebsfish\data\fish\europeanlobsterclaw.rvmat","\gebsfish\data\fish\europeanlobsterclaw_rotten.rvmat"};
	};
	class geb_YellowCaviar: RedCaviar {
		scope=2;
		displayName="$STR_fish_YellowCaviar";
		descriptionShort="$STR_fish_YellowCaviar_desc";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\fish\pike_caviar_raw_co.paa",
			"dz\gear\food\data\red_caviar_rotten_co.paa"
		};
	};
	class geb_BlackCaviar: RedCaviar {
		scope=2;
		displayName="$STR_fish_BlackCaviar";
		descriptionShort="$STR_fish_BlackCaviar_desc";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\fish\sturgeon_caviar_raw_co.paa",
			"dz\gear\food\data\red_caviar_rotten_co.paa"
		};
	};
};
