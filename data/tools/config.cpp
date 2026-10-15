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
	// Attachment proxies for the Fish Drying Rack's six fillet slots, the same
	// pattern as Proxygebfishmount: the rack's model places proxies named
	// gebdryingracka..f, and the hung fillet renders there (geb_fishdryingrack.c
	// turns and shifts it so every fillet model hangs by its tail).
	class Proxygebdryingracka: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackA";
		model = "\gebsfish\data\proxy\gebdryingracka.p3d";
	};
	class Proxygebdryingrackb: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackB";
		model = "\gebsfish\data\proxy\gebdryingrackb.p3d";
	};
	class Proxygebdryingrackc: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackC";
		model = "\gebsfish\data\proxy\gebdryingrackc.p3d";
	};
	class Proxygebdryingrackd: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackD";
		model = "\gebsfish\data\proxy\gebdryingrackd.p3d";
	};
	class Proxygebdryingracke: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackE";
		model = "\gebsfish\data\proxy\gebdryingracke.p3d";
	};
	class Proxygebdryingrackf: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebDryingRackF";
		model = "\gebsfish\data\proxy\gebdryingrackf.p3d";
	};
	// The Fish Tank Stand's top: the stand's model places a proxy named gebfishtank there,
	// and the attached Fish Tank renders standing on it.
	class Proxygebfishtank: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebFishTank";
		model = "\gebsfish\data\proxy\gebfishtank.p3d";
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
		"DZ_Weapons_Melee_Blade",  // HuntingKnife, parent of the fish knives
		// Defines LongWoodenStick, whose inventorySlot[] gets the drying rack
		// kit's slot below: vanilla must load first or its list wipes ours.
		"DZ_Gear_Crafting"
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
	// The Fish Drying Rack's six fillet slots, three on each side (A-C, D-F).
	// The fillets opt in through inventorySlot[] in data/fish/config.cpp.
	class Slot_GebDryingRackA {
		name = "GebDryingRackA";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	class Slot_GebDryingRackB {
		name = "GebDryingRackB";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	class Slot_GebDryingRackC {
		name = "GebDryingRackC";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	class Slot_GebDryingRackD {
		name = "GebDryingRackD";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	class Slot_GebDryingRackE {
		name = "GebDryingRackE";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	class Slot_GebDryingRackF {
		name = "GebDryingRackF";
		displayName = "$STR_tools_fishdryingrack_slot";
		ghostIcon = "set:gebsfish image:fishmount";
	};
	// The Fish Drying Rack Kit's slot for the six long sticks still to go in. Long
	// sticks only stack in a slot of their own (vanilla's varStackMax is 1, the
	// shelter frame slot takes 4), so stackMax here is what lets six in.
	class Slot_GebDryingRackSticks {
		name = "GebDryingRackSticks";
		displayName = "$STR_CfgVehicles_LongWoodenStick0";
		ghostIcon = "set:dayz_inventory image:woodenstick";
		stackMax = 6;
	};
	// The Fish Tank Stand's one slot: the Fish Tank stands on it (geb_FishTank lists it in inventorySlot[]).
	class Slot_GebFishTank {
		name = "GebFishTank";
		displayName = "$STR_tools_fishtank";
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

	// The Fish Drying Rack (geb_fishdryingrack.c, FUTURE_IDEAS F21): an A-frame
	// of long sticks lashed with rope, every face on vanilla's long wooden stick
	// material. Six fillet slots; raw fillets hung on a rack standing in the
	// world dry to the dried stage without a fire (general.json
	// DryingRackSettings). Assembled where its kit (geb_FishDryingRackKit below)
	// lies, and it stays there: a built rack can't be picked up or carried
	// (geb_fishdryingrack.c). itemBehaviour 0, a heavy item, never in cargo.
	class geb_FishDryingRack: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_fishdryingrack";
		descriptionShort = "$STR_tools_fishdryingrack_desc";
		model = "\gebsfish\data\tools\fishdryingrack.p3d";
		weight = 5000;
		itemSize[] = {10,6};
		itemBehaviour = 0;
		physLayer = "item_large";
		rotationFlags = 2;
		attachments[] = {"GebDryingRackA","GebDryingRackB","GebDryingRackC","GebDryingRackD","GebDryingRackE","GebDryingRackF"};
		// The hologram's section, as on the fish mounts: "placing" covers every
		// face, so its texture and material must be listed (vanilla's own).
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\crafting\data\wooden_stick_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\crafting\data\wooden_stick.rvmat"};
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		// How each slot hangs its fillet (Model.cfg fishdryingrack): three shifts
		// along the fillet's own axes (0.5 = none, then 4 m per phase) and two
		// turns (one full turn per phase), set by the script per fillet model.
		class AnimationSources {
			class hang_a_x {
				source = "user";
				animPeriod = 0.01;
				initPhase = 0.5;
			};
			class hang_a_y: hang_a_x {};
			class hang_a_z: hang_a_x {};
			class hang_a_turn {
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class hang_a_yaw: hang_a_turn {};
			class hang_b_x: hang_a_x {};
			class hang_b_y: hang_a_x {};
			class hang_b_z: hang_a_x {};
			class hang_b_turn: hang_a_turn {};
			class hang_b_yaw: hang_a_turn {};
			class hang_c_x: hang_a_x {};
			class hang_c_y: hang_a_x {};
			class hang_c_z: hang_a_x {};
			class hang_c_turn: hang_a_turn {};
			class hang_c_yaw: hang_a_turn {};
			class hang_d_x: hang_a_x {};
			class hang_d_y: hang_a_x {};
			class hang_d_z: hang_a_x {};
			class hang_d_turn: hang_a_turn {};
			class hang_d_yaw: hang_a_turn {};
			class hang_e_x: hang_a_x {};
			class hang_e_y: hang_a_x {};
			class hang_e_z: hang_a_x {};
			class hang_e_turn: hang_a_turn {};
			class hang_e_yaw: hang_a_turn {};
			class hang_f_x: hang_a_x {};
			class hang_f_y: hang_a_x {};
			class hang_f_z: hang_a_x {};
			class hang_f_turn: hang_a_turn {};
			class hang_f_yaw: hang_a_turn {};
		};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 200;
					healthLevels[] = {
						{1,{"dz\gear\crafting\data\wooden_stick.rvmat"}},
						{0.7,{"dz\gear\crafting\data\wooden_stick.rvmat"}},
						{0.5,{"dz\gear\crafting\data\wooden_stick_damage.rvmat"}},
						{0.3,{"dz\gear\crafting\data\wooden_stick_damage.rvmat"}},
						{0,{"dz\gear\crafting\data\wooden_stick_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// The Fish Drying Rack Kit (geb_fishdryingrack.c): a long stick and a rope
	// (CraftDryingRack), made on the ground like vanilla's Shelter Kit and on its
	// model. Long sticks don't stack in 1.30, so the other six go into the kit's
	// GebDryingRackSticks slot one at a time while it lies there, as a shelter's
	// frame takes its sticks; "Assemble drying rack" then turns kit and sticks
	// into the rack. A kit holding sticks stays where it is.
	class geb_FishDryingRackKit: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_fishdryingrackkit";
		descriptionShort = "$STR_tools_fishdryingrackkit_desc";
		model = "\DZ\gear\camping\watchtower_kit.p3d";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 950;   // a long stick (670 g) and a rope (280 g)
		itemBehaviour = 1;
		attachments[] = {"GebDryingRackSticks"};
		soundImpactType = "wood";
		// Vanilla's Shelter Kit damage values, written out: "class DamageSystem:
		// DamageSystem" only compiles against a class in this same config.
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 200;
					healthLevels[] = {
						{1,{}},
						{0.7,{}},
						{0.5,{}},
						{0.3,{}},
						{0,{}}
					};
				};
			};
		};
	};
	// Long sticks also fit the kit's slot. The vanilla class itself, so += keeps
	// vanilla's Shoulder, Melee and shelter frame slots.
	class LongWoodenStick: Inventory_Base {
		inventorySlot[] += {"GebDryingRackSticks"};
	};

	// The Fish Tank: a 60 x 30 x 35 cm tabletop aquarium (gravel, plants, a rock, an air stone) with four
	// mini reef fish -- Siamese tigerfish, blue tang, angelfish, redhead cichlid -- swimming loops. A trader
	// or admin item: never world loot and never crafted (typesxml.c writes it with nominal 0). The fish move on
	// Model.cfg fishtank's "time" animations, no script; the air stone's bubbles are a client-side particle
	// (geb_fishtank.c). Placed like the drying rack: a heavy item set down with vanilla's hologram and
	// deploy actions. "placing" is only the opaque section (frame, hood, gravel, rocks, sword plants), so the
	// hologram ghosts that while the glass, water, plants and fish show as they are. The glass and water
	// are one alpha-blended layer (fishtank_glass, drawn last), the elder plants alpha-tested.
	class geb_FishTank: Inventory_Base {
		scope = 2;
		displayName = "$STR_tools_fishtank";
		descriptionShort = "$STR_tools_fishtank_desc";
		model = "\gebsfish\data\tools\fishtank.p3d";
		inventorySlot[] = {"GebFishTank"};
		weight = 14000;
		itemSize[] = {6,4};
		itemBehaviour = 0;
		physLayer = "item_large";
		rotationFlags = 2;
		// 0: the opaque section (hologram), 1: the hood light strip, off until geb_fishtank.c turns it on.
		hiddenSelections[] = {"placing","light_strip"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishtank_co.paa","#(argb,8,8,3)color(1,1,1,1,CO)"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishtank.rvmat","\gebsfish\data\tools\fishtank_light_off.rvmat"};
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		// The treasure chest lid (Model.cfg chest_lid): opened and closed by geb_fishtank.c, 3 s each way.
		class AnimationSources {
			class chest_lid {
				source = "user";
				animPeriod = 3;
				initPhase = 0;
			};
		};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 100;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\fishtank.rvmat","gebsfish\data\tools\fishtank_glass.rvmat","gebsfish\data\tools\fishtank_plant.rvmat","gebsfish\data\tools\fishtank_backdrop.rvmat"}},
						{0.7,{"gebsfish\data\tools\fishtank.rvmat","gebsfish\data\tools\fishtank_glass.rvmat","gebsfish\data\tools\fishtank_plant.rvmat","gebsfish\data\tools\fishtank_backdrop.rvmat"}},
						{0.5,{"gebsfish\data\tools\fishtank_damage.rvmat","gebsfish\data\tools\fishtank_glass_damage.rvmat","gebsfish\data\tools\fishtank_plant_damage.rvmat","gebsfish\data\tools\fishtank_backdrop_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\fishtank_damage.rvmat","gebsfish\data\tools\fishtank_glass_damage.rvmat","gebsfish\data\tools\fishtank_plant_damage.rvmat","gebsfish\data\tools\fishtank_backdrop_damage.rvmat"}},
						{0,{"gebsfish\data\tools\fishtank_destruct.rvmat","gebsfish\data\tools\fishtank_glass_destruct.rvmat","gebsfish\data\tools\fishtank_plant_destruct.rvmat","gebsfish\data\tools\fishtank_backdrop_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// The Fish Tank Stand: a varnished wooden aquarium cabinet, 0.66 x 0.36 x 0.75 m, with two panelled
	// doors and a 10x5 cupboard for fish food and tackle. The Fish Tank stands on its top (slot
	// GebFishTank). Crafted from 8 planks and 16 nails (CraftFishTankStand; trader or admin only until
	// 2026-10-14), nominal 0 in typesxml.c. A placed
	// container like the Fishing Locker (geb_fishtankstand.c): vanilla's hologram and place actions,
	// carried in both hands and only when empty. Every face is on vanilla's wardrobe photo (almara02).
	class geb_FishTankStand: Container_Base {
		scope = 2;
		displayName = "$STR_tools_fishtankstand";
		descriptionShort = "$STR_tools_fishtankstand_desc";
		model = "\gebsfish\data\tools\fishtankstand.p3d";
		weight = 18000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		physLayer = "item_large";
		carveNavmesh = 1;
		canBeDigged = 0;
		rotationFlags = 2;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\structures\furniture\cases\almara\data\almara02_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishtankstand.rvmat"};
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45,45,45};
		soundImpactType = "wood";
		attachments[] = {"GebFishTank"};
		class Cargo {
			itemsCargoSize[] = {10,5};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 200;
					healthLevels[] = {
						{1,{"gebsfish\data\tools\fishtankstand.rvmat"}},
						{0.7,{"gebsfish\data\tools\fishtankstand.rvmat"}},
						{0.5,{"gebsfish\data\tools\fishtankstand_damage.rvmat"}},
						{0.3,{"gebsfish\data\tools\fishtankstand_damage.rvmat"}},
						{0,{"gebsfish\data\tools\fishtankstand_destruct.rvmat"}}
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
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_blue_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_OrangeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_orangefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_orange_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_GreenFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_greenfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_green_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_YellowFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_yellowfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_yellow_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_RedFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_redfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_red_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_PurpleFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_purplefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_purple_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_LimeFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_limefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_lime_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_LightBlueFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_lightbluefishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_lightblue_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_CamoFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_camofishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_camo_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_DesertCamoFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_desertcamofishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_desertcamo_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_SnowCamoFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_snowcamofishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_snowcamo_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_PinkCamoFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_pinkcamofishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_pinkcamo_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_BrownFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_brownfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_brown_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	class geb_PinkFishKnife: geb_FishKnife_Base {
		scope = 2;
		displayName = "$STR_tools_pinkfishknife";
		descriptionShort="$STR_tools_fishingknife_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishknife_pink_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\fishknife.rvmat"};
	};
	// Restated DamageSystem block on the modded FishingRod base so every
	// rod variant (vanilla FishingRod + geb_RedFishingRod / Green / Blue /
	// Purple / Orange / Yellow / Brown / LightBlue / Lime / Pink, and the Camo / DesertCamo / SnowCamo /
	// PinkCamo rods) shares a single source of truth for HP and visual-state
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
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_red_co.paa"};
	};
	class geb_GreenFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_greenrod";
		descriptionShort = "$STR_tools_greenrod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_green_co.paa"};
	};
	class geb_BlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_bluerod";
		descriptionShort = "$STR_tools_bluerod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_blue_co.paa"};
	};
	class geb_PurpleFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_purplerod";
		descriptionShort = "$STR_tools_purplerod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_purple_co.paa"};
	};
	class geb_OrangeFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_orangerod";
		descriptionShort = "$STR_tools_orangerod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_orange_co.paa"};
	};
	class geb_YellowFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_yellowrod";
		descriptionShort = "$STR_tools_yellowrod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_yellow_co.paa"};
	};
	class geb_BrownFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_brownrod";
		descriptionShort = "$STR_tools_brownrod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_brown_co.paa"};
	};
	class geb_LightBlueFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_lightbluerod";
		descriptionShort = "$STR_tools_lightbluerod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_lightblue_co.paa"};
	};
	class geb_LimeFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_limerod";
		descriptionShort = "$STR_tools_limerod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_lime_co.paa"};
	};
	class geb_PinkFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_pinkrod";
		descriptionShort = "$STR_tools_pinkrod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_pink_co.paa"};
	};
	class geb_CamoFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_camorod";
		descriptionShort = "$STR_tools_camorod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_camo_co.paa"};
	};
	class geb_DesertCamoFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_desertcamorod";
		descriptionShort = "$STR_tools_desertcamorod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_desertcamo_co.paa"};
	};
	class geb_SnowCamoFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_snowcamorod";
		descriptionShort = "$STR_tools_snowcamorod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_snowcamo_co.paa"};
	};
	class geb_PinkCamoFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_pinkcamorod";
		descriptionShort = "$STR_tools_pinkcamorod_desc";
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\fishingrod_pinkcamo_co.paa"};
	};
	// The fly, spincast, baitcast and heavy surf rods are models of their own
	// (built by tools/rods, no vanilla geometry), not retextures. Everything else they get
	// from FishingRod: they fish, wear, repair and carry like the colour rods,
	// and the hands hold them as they hold vanilla's, since each model keeps
	// vanilla's frame (rod along +Y, grip round y 0.06-0.16, crank on the left).
	// Like vanilla's rod they telescope out while fishing: AnimateRod drives
	// the five sections' translations in data/tools/Model.cfg (the surf rod's
	// reach about 2.6 m, the others vanilla's 1.4 m). hiddenSelections
	// is "camo", the one section of all three models, so a colour variant only
	// needs another texture on the same layout.
	class geb_FlyFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_flyrod";
		descriptionShort = "$STR_tools_flyrod_desc";
		model = "\gebsfish\data\tools\flyfishingrod.p3d";
		weight = 700;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\flyfishingrod_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\flyfishingrod.rvmat"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1, {"gebsfish\data\tools\flyfishingrod.rvmat"}},
						{0.7, {"gebsfish\data\tools\flyfishingrod.rvmat"}},
						{0.5, {"gebsfish\data\tools\flyfishingrod_damage.rvmat"}},
						{0.3, {"gebsfish\data\tools\flyfishingrod_damage.rvmat"}},
						{0, {"gebsfish\data\tools\flyfishingrod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SpincastFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_spincastrod";
		descriptionShort = "$STR_tools_spincastrod_desc";
		model = "\gebsfish\data\tools\spincastfishingrod.p3d";
		weight = 950;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\spincastfishingrod_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\spincastfishingrod.rvmat"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1, {"gebsfish\data\tools\spincastfishingrod.rvmat"}},
						{0.7, {"gebsfish\data\tools\spincastfishingrod.rvmat"}},
						{0.5, {"gebsfish\data\tools\spincastfishingrod_damage.rvmat"}},
						{0.3, {"gebsfish\data\tools\spincastfishingrod_damage.rvmat"}},
						{0, {"gebsfish\data\tools\spincastfishingrod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_BaitcastFishingRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_baitcastrod";
		descriptionShort = "$STR_tools_baitcastrod_desc";
		model = "\gebsfish\data\tools\baitcastfishingrod.p3d";
		weight = 850;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\baitcastfishingrod_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\baitcastfishingrod.rvmat"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1, {"gebsfish\data\tools\baitcastfishingrod.rvmat"}},
						{0.7, {"gebsfish\data\tools\baitcastfishingrod.rvmat"}},
						{0.5, {"gebsfish\data\tools\baitcastfishingrod_damage.rvmat"}},
						{0.3, {"gebsfish\data\tools\baitcastfishingrod_damage.rvmat"}},
						{0, {"gebsfish\data\tools\baitcastfishingrod_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_HeavySurfRod: FishingRod {
		scope = 2;
		displayName = "$STR_tools_heavysurfrod";
		descriptionShort = "$STR_tools_heavysurfrod_desc";
		model = "\gebsfish\data\tools\heavysurfrod.p3d";
		weight = 1400;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\tools\heavysurfrod_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\tools\heavysurfrod.rvmat"};
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 150;
					healthLevels[] = {
						{1, {"gebsfish\data\tools\heavysurfrod.rvmat"}},
						{0.7, {"gebsfish\data\tools\heavysurfrod.rvmat"}},
						{0.5, {"gebsfish\data\tools\heavysurfrod_damage.rvmat"}},
						{0.3, {"gebsfish\data\tools\heavysurfrod_damage.rvmat"}},
						{0, {"gebsfish\data\tools\heavysurfrod_destruct.rvmat"}}
					};
				};
			};
		};
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

// The Fish Tank's soft sounds (geb_fishtank.c plays both, looping, while the tank runs): vanilla's geyser bubbling
// and water stream samples, quiet and audible only within about four metres.
class CfgSoundShaders {
	class geb_FishTankHum_SoundShader {
		samples[] = {{"DZ\sounds\environment\water\Geyser_bubbling_loop", 1}};
		volume = 0.16;
		range = 4;
	};
	class geb_FishTankTrickle_SoundShader {
		samples[] = {{"DZ\sounds\environment\water\WaterStream_1_-30db", 1}, {"DZ\sounds\environment\water\WaterStream_2_-30db", 1}};
		volume = 0.30;
		range = 4;
	};
};
class CfgSoundSets {
	class geb_FishTankHum_SoundSet {
		soundShaders[] = {"geb_FishTankHum_SoundShader"};
		volumeFactor = 1;
		frequencyRandomizer = 0;
		spatial = 1;
		doppler = 0;
		loop = 1;
		volumeCurve = "objectInner7VolumeCurve";
		distanceFilter = "BaseCharacter_AttenuationFilter";
	};
	class geb_FishTankTrickle_SoundSet: geb_FishTankHum_SoundSet {
		soundShaders[] = {"geb_FishTankTrickle_SoundShader"};
	};
};
