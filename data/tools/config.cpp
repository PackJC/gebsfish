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
		"DZ_Weapons_Melee",
		// Defines FishingRod. Without it the load order against
		// gear_tools.pbo is undefined, and whenever vanilla loaded after us
		// its plain inventorySlot[]={"Backpack_1"} wiped the Shoulder/Melee
		// slots we add -- the long-standing "rod bug".
		"DZ_Gear_Tools",
		"DZ_Weapons_Melee_Blade"  // HuntingKnife, parent of the fish knives
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
		// A fish silhouette from the mod's own imageset (gui/gebsfish.imageset,
		// registered in config.cpp's CfgMods defs). ghostIcon must name an
		// imageset entry, not a texture path; a bare name like "hook" means
		// vanilla's set:dayz_inventory.
		ghostIcon = "set:gebsfish image:fishmount";
	};
};

class cfgVehicles {
	//Instantiate Needed Classes
	class HuntingKnife;
	class Container_Base;
	class Inventory_Base;
	class FishingRod_Base_New;

	/*

		TOOLS

	*/

	// Trophy mounts: an oval plaque of edge-glued planks with a brass nameplate,
	// in three sizes. Each has the single GebFishMount slot and the player
	// attaches the actual caught fish: its model renders on the board through
	// the gebfishmount proxy, and its weight and quality persist like any
	// attachment. The script (scripts/4_world/entities/itembase/gear/
	// geb_fishmount.c) poses every species side-on through the model's fish_*
	// animations and refuses fish too big for the board; wall placement comes
	// from the modded Hologram in the same file.
	// geb_WoodenFishMount is the small plaque (the class name is kept so placed
	// mounts survive); the medium and large boards inherit all of it.
	class geb_WoodenFishMount: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_smallfishmount";
		descriptionShort = "$STR_tools_smallfishmount_desc";
		model = "\gebsfish\data\tools\smallfishmount.p3d";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\smallfishmount_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\smallfishmount.rvmat"};
		weight = 1200;
		itemSize[] = {3,3};
		attachments[] = {"GebFishMount"};
		rotationFlags = 2;
		physLayer = "item_large";
		// Picks the deploy animation (ActionDeployObject.SetupAnimation, 2 =
		// two-handed). Without it the action logged an error and replayed
		// whatever animation the last deployed item used.
		itemBehaviour = 2;
		// Placement hologram. Without a hiddenSelection the engine has no
		// slot to swap the ghost material into and the projection renders as
		// the normal textured plaque; "placing" is the selection the p3d
		// carries over the whole board. The material pair is resolved as
		// <hologramMaterialPath>\<hologramMaterial>_deployable.rvmat and
		// ..._undeployable.rvmat, shared by all three sizes.
		hiddenSelections[] = {"placing"};
		// A hidden selection that is also declared as a section in Model.cfg gets
		// its texture and material from the hiddenSelections lists above --
		// leaving them out doesn't mean "keep the model's own", it means "no
		// texture", and the plaque renders invisible. The hologram swaps its own
		// material over the top only while placing.
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		// Don't force ground alignment -- the modded Hologram builds the
		// orientation from the wall normal when the player aims at a wall.
		// Vanilla's key really is spelled "Terain" (hologram.c reads that
		// exact name); the "Terrain" spelling was silently ignored.
		alignHologramToTerain = 0;
		// Hologram.IsCollidingAngle rejects placement when |pitch| or |roll|
		// exceeds these limits. Flat against a vertical wall is ~90 degrees of
		// pitch, so the old 89 blocked the exact orientation this item exists
		// for. Opened up -- the plaque is meant to hang at any wall angle.
		yawPitchRollLimit[] = {180,180,180};
		// The mounted fish's pose (Model.cfg smallfishmount): three shifts along
		// the board (0.5 = none, then 4 m per phase) and three turns (one full
		// turn per phase), all set by the script when a fish is attached.
		class AnimationSources {
			class fish_x {
				source = "user";
				animPeriod = 0.01;
				initPhase = 0.5;
			};
			class fish_y: fish_x {};
			class fish_z: fish_x {};
			class fish_yaw {
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class fish_pitch: fish_yaw {};
			class fish_roll: fish_yaw {};
		};
		// The DamageSystem below restates the vanilla parent's hit points in full:
		// "class DamageSystem: DamageSystem" only compiles against a class defined
		// in this same config, and the parent here comes from another addon.
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 100;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\smallfishmount.rvmat"}},
						{0.7,{"gebsfish\data\tools\smallfishmount.rvmat"}},
						{0.5,{"gebsfish\data\tools\smallfishmount_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\smallfishmount_damage.rvmat"}},
						{0,{"gebsfish\data\tools\smallfishmount_destruct.rvmat"}}
					};
				};
			};
		};
	};
	// For pike, muskies, catfish, cod and the crabs (up to 2 m of model). Made
	// from three planks.
	class geb_MediumFishMount: geb_WoodenFishMount {
		displayName = "$STR_tools_mediumfishmount";
		descriptionShort = "$STR_tools_mediumfishmount_desc";
		model = "\gebsfish\data\tools\mediumfishmount.p3d";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\mediumfishmount_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\mediumfishmount.rvmat"};
		weight = 4500;
		itemSize[] = {8,4};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 200;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\mediumfishmount.rvmat"}},
						{0.7,{"gebsfish\data\tools\mediumfishmount.rvmat"}},
						{0.5,{"gebsfish\data\tools\mediumfishmount_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\mediumfishmount_damage.rvmat"}},
						{0,{"gebsfish\data\tools\mediumfishmount_destruct.rvmat"}}
					};
				};
			};
		};
	};
	// For the sturgeon, billfish, mahi-mahi and sharks. Made from six planks.
	// Too big for any cargo: a heavy item (itemBehaviour 0), carried in both
	// hands and placed with vanilla's heavy deploy animation, like a sea chest.
	class geb_LargeFishMount: geb_WoodenFishMount {
		displayName = "$STR_tools_largefishmount";
		descriptionShort = "$STR_tools_largefishmount_desc";
		model = "\gebsfish\data\tools\largefishmount.p3d";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\largefishmount_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\largefishmount.rvmat"};
		weight = 9000;
		itemSize[] = {10,6};
		itemBehaviour = 0;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 400;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\largefishmount.rvmat"}},
						{0.7,{"gebsfish\data\tools\largefishmount.rvmat"}},
						{0.5,{"gebsfish\data\tools\largefishmount_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\largefishmount_damage.rvmat"}},
						{0,{"gebsfish\data\tools\largefishmount_destruct.rvmat"}}
					};
				};
			};
		};
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
		// Four repairs per kit: RepairFishingPole takes 1 per repair, plus the
		// rod's repairCosts 0.1. The emptied kit is deleted by
		// varQuantityDestroyOnMin, inherited from Inventory_Base.
		varQuantityInit = 4;
		varQuantityMin = 0;
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
					healthLevels[] = {
						{1,{"gebsfish\data\tools\fishingline_biggame.rvmat"}},
						{0.7,{"gebsfish\data\tools\fishingline_biggame.rvmat"}},
						{0.5,{"gebsfish\data\tools\fishingline_biggame_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\fishingline_biggame_damage.rvmat"}},
						{0,{"gebsfish\data\tools\fishingline_biggame_destruct.rvmat"}}
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
		//   1. Durability: hitpoints=200 is ~54% more than vanilla's 130.
		//      Above KitchenKnife (85) and KukriKnife (150), level with the
		//      Machete (200) -- a "premium fishing tool" for heavy filleting.
		//   2. Filleting speed: 10% faster than vanilla via the
		//      GeneralSettings.FishKnifeSpeedMultiplier knob in general.json
		//      (default 0.9). The bonus only applies when the fillet is cut
		//      with a geb_FishKnife_Base derivative (geb_cacontinuouscraft.c);
		//      a vanilla knife still cuts at vanilla speed. Multiplier values
		//      much below 0.9 cause visible animation desync (recipe finishes
		//      before the skinning finish-animation lands) -- see the info
		//      string on FishKnifeSpeedMultiplier in gebsfishConfig.c for the
		//      full explanation.
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints=200;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\fishknife.rvmat","gebsfish\data\tools\fishknife_blade.rvmat"}},
						{0.7,{"gebsfish\data\tools\fishknife.rvmat","gebsfish\data\tools\fishknife_blade.rvmat"}},
						{0.5,{"gebsfish\data\tools\fishknife_damage.rvmat","gebsfish\data\tools\fishknife_blade_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\fishknife_damage.rvmat","gebsfish\data\tools\fishknife_blade_damage.rvmat"}},
						{0,{"gebsfish\data\tools\fishknife_destruct.rvmat","gebsfish\data\tools\fishknife_blade_destruct.rvmat"}}
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
	class geb_LimeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_limefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_lime_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_LightBlueFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_lightbluefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_lightblue_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_CamoFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_camofishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_camo_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_BrownFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_brownfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_brown_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_PinkFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_pinkfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_pink_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	// Restated DamageSystem block on the modded FishingRod base so every
	// rod variant (vanilla FishingRod + geb_RedFishingRod / Green / Blue /
	// Purple / Orange / Yellow / Brown / LightBlue / Lime / Pink) shares a single source of truth for HP and visual-state
	// thresholds. hitpoints=150 and the healthLevels[] paths below are
	// identical to vanilla's FishingRod config -- carried over verbatim so
	// repair kits, market mods, and any other system that reads rod HP
	// behaves the same with or without gebsfish loaded.
	class FishingRod : FishingRod_Base_New
	{
		// Rod on the back like a rifle. Vanilla only has the backpack rod
		// loop ("Backpack_1"), restated here because this plain assignment
		// replaces the list. Plain on purpose: += made the result depend on
		// merge order against vanilla gear_tools (see DZ_Gear_Tools in
		// requiredAddons). fishingpole/fishingrod1-10 are cross-mod
		// rod-holder compat, inert without such a mod (MAYBE_ISSUES.md #4).
		inventorySlot[] = {"Backpack_1", "Shoulder", "Melee", "fishingpole", "fishingrod1", "fishingrod2", "fishingrod3", "fishingrod4", "fishingrod5", "fishingrod6", "fishingrod7", "fishingrod8", "fishingrod9", "fishingrod10"};
		hiddenSelections[]={"zbytek"};
		repairableWithKits[] = {33033};  // Use the same repairKitType as above
		repairCosts[] = {0.1};          // kit units, charged on top of the recipe's 1 per repair; a kit still gives 4 repairs
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
	// Crafted improvised rod carries on the back too. Vanilla already lists
	// Shoulder + Melee, but the mod restates it (plain assignment, pinned by
	// DZ_Gear_Tools in requiredAddons) so load order can't drop it, and adds
	// the same fishingpole/fishingrod1-10 rod-holder compat slots the real
	// rods carry. No Backpack_1: that is the vanilla rod's own bag slot, which
	// the improvised rod does not have.
	class ImprovisedFishingRod : FishingRod_Base_New {
		inventorySlot[] = {"Shoulder", "Melee", "fishingpole", "fishingrod1", "fishingrod2", "fishingrod3", "fishingrod4", "fishingrod5", "fishingrod6", "fishingrod7", "fishingrod8", "fishingrod9", "fishingrod10"};
	};
	class geb_RedFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_redrod";
		descriptionShort = "$STR_tools_redrod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_red_co.paa"};
	};
	class geb_GreenFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_greenrod";
		descriptionShort = "$STR_tools_greenrod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_green_co.paa"};
	};
	class geb_BlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_bluerod";
		descriptionShort = "$STR_tools_bluerod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_blue_co.paa"};
	};
	class geb_PurpleFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_purplerod";
		descriptionShort = "$STR_tools_purplerod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_purple_co.paa"};
	};
	class geb_OrangeFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_orangerod";
		descriptionShort = "$STR_tools_orangerod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_orange_co.paa"};
	};
	class geb_YellowFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_yellowrod";
		descriptionShort = "$STR_tools_yellowrod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_yellow_co.paa"};
	};
	class geb_BrownFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_brownrod";
		descriptionShort = "$STR_tools_brownrod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_brown_co.paa"};
	};
	class geb_LightBlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_lightbluerod";
		descriptionShort = "$STR_tools_lightbluerod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_lightblue_co.paa"};
	};
	class geb_LimeFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_limerod";
		descriptionShort = "$STR_tools_limerod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_lime_co.paa"};
	};
	class geb_PinkFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_pinkrod";
		descriptionShort = "$STR_tools_pinkrod_desc";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_pink_co.paa"};
	};
	class geb_BambooFishingNet : Container_Base {
		scope = 2;
		rotationFlags = 17;
		displayName = "$STR_tools_fishingnet";
		descriptionShort = "$STR_tools_fishingnet_desc";
		model = "\gebsfish\data\tools\bamboofishingnet.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\bamboofishingnet_co.paa"};
		itemInfo[] = {"CatchWithNet"};
		weight = 100;
		itemSize[] = {1,3};
		itemsCargoSize[] = {4,4};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		// No repairableWithKits: the net mends only with Netting
		// (RepairBambooFishingNet, which RecipeToggles can switch off). Kit
		// type 2 let vanilla's Sewing Kit repair it as well, outside the toggle.
		isMeleeWeapon = 1;
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 80;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\bamboofishingnet.rvmat","gebsfish\data\tools\bamboofishingnet_net.rvmat"}},
						{0.7,{"gebsfish\data\tools\bamboofishingnet.rvmat","gebsfish\data\tools\bamboofishingnet_net.rvmat"}},
						{0.5,{"gebsfish\data\tools\bamboofishingnet_damage.rvmat","gebsfish\data\tools\bamboofishingnet_net_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\bamboofishingnet_damage.rvmat","gebsfish\data\tools\bamboofishingnet_net_damage.rvmat"}},
						{0,{"gebsfish\data\tools\bamboofishingnet_destruct.rvmat","gebsfish\data\tools\bamboofishingnet_net_destruct.rvmat"}}
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
