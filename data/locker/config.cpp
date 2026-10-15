/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

// The Fishing Locker: a tall open-fronted locker of weathered planks that keeps
// a fisherman's whole kit where it can be seen -- six rods in a rack, hat and
// gloves on a shelf, raincoat, shirt and vest on pegs, tackle boxes, a cooler,
// the bait bucket and a worm or bug container on the shelves, wellies on the
// floor, a backpack on a peg outside, two fish traps on the roof and a cabinet
// of cargo along the top. Model, maps and Model.cfg are built by
// tools/locker (build.py; layout.py holds every spot). The script is
// scripts/4_world/entities/itembase/gear/geb_fishinglocker.c.

class CfgPatches {
	class gebsLockerCfgPatches {
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts",
		"DZ_Gear_Camping",  // the sea chest's sound sets
		"DZ_Gear_Traps"     // SmallFishTrap and FishNetTrap get locker slots below
		};
	};
};

// Attachment proxies, one per spot: the class name is "Proxy" + the proxy p3d's
// file name, and inventorySlot binds it to its slot (as Proxygebfishmount in
// data/tools/config.cpp). The locker's model holds the proxies in Model.cfg
// bones the script moves; the proxy files themselves are never drawn.
class CfgNonAIVehicles {
	class StaticObject;
	class ProxyAttachment;
	class Proxygeblocker_rod1: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod1";
		model = "\gebsfish\data\proxy\geblocker_rod1.p3d";
	};
	class Proxygeblocker_rod2: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod2";
		model = "\gebsfish\data\proxy\geblocker_rod2.p3d";
	};
	class Proxygeblocker_rod3: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod3";
		model = "\gebsfish\data\proxy\geblocker_rod3.p3d";
	};
	class Proxygeblocker_rod4: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod4";
		model = "\gebsfish\data\proxy\geblocker_rod4.p3d";
	};
	class Proxygeblocker_rod5: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod5";
		model = "\gebsfish\data\proxy\geblocker_rod5.p3d";
	};
	class Proxygeblocker_rod6: ProxyAttachment {
		scope = 2;
		inventorySlot = "fishingrod6";
		model = "\gebsfish\data\proxy\geblocker_rod6.p3d";
	};
	class Proxygeblocker_hat: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerHat";
		model = "\gebsfish\data\proxy\geblocker_hat.p3d";
	};
	class Proxygeblocker_gloves: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerGloves";
		model = "\gebsfish\data\proxy\geblocker_gloves.p3d";
	};
	class Proxygeblocker_shirt: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerShirt";
		model = "\gebsfish\data\proxy\geblocker_shirt.p3d";
	};
	class Proxygeblocker_coat: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerCoat";
		model = "\gebsfish\data\proxy\geblocker_coat.p3d";
	};
	class Proxygeblocker_vest: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerVest";
		model = "\gebsfish\data\proxy\geblocker_vest.p3d";
	};
	class Proxygeblocker_boots: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerBoots";
		model = "\gebsfish\data\proxy\geblocker_boots.p3d";
	};
	// Vanilla's own Back slot: every backpack already carries it, the mod's,
	// vanilla's and other mods' alike. Vanilla only reads that slot on players.
	class Proxygeblocker_pack: ProxyAttachment {
		scope = 2;
		inventorySlot = "Back";
		model = "\gebsfish\data\proxy\geblocker_pack.p3d";
	};
	class Proxygeblocker_tackle1: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerTackle1";
		model = "\gebsfish\data\proxy\geblocker_tackle1.p3d";
	};
	class Proxygeblocker_tackle2: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerTackle2";
		model = "\gebsfish\data\proxy\geblocker_tackle2.p3d";
	};
	class Proxygeblocker_cooler: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerCooler";
		model = "\gebsfish\data\proxy\geblocker_cooler.p3d";
	};
	class Proxygeblocker_bucket: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerBucket";
		model = "\gebsfish\data\proxy\geblocker_bucket.p3d";
	};
	class Proxygeblocker_bait: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerBait";
		model = "\gebsfish\data\proxy\geblocker_bait.p3d";
	};
	class Proxygeblocker_trap1: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerTrap1";
		model = "\gebsfish\data\proxy\geblocker_trap1.p3d";
	};
	class Proxygeblocker_trap2: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebLockerTrap2";
		model = "\gebsfish\data\proxy\geblocker_trap2.p3d";
	};
};

class CfgSlots {
	// The rod rack reuses the cross-mod rod slot names every rod already
	// carries (FishingRod and ImprovisedFishingRod list fishingrod1..10 in
	// data/tools/config.cpp), so any rod fits, other mods' too. Ghost icons are
	// vanilla's (a bare name means set:dayz_inventory).
	class Slot_fishingrod1 {
		name = "fishingrod1";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	class Slot_fishingrod2 {
		name = "fishingrod2";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	class Slot_fishingrod3 {
		name = "fishingrod3";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	class Slot_fishingrod4 {
		name = "fishingrod4";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	class Slot_fishingrod5 {
		name = "fishingrod5";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	class Slot_fishingrod6 {
		name = "fishingrod6";
		displayName = "$STR_locker_slot_rod";
		ghostIcon = "shoulderleft";
	};
	// The fishing clothes opt in through inventorySlot[] on their bases in
	// data/clothes/config.cpp, so vanilla clothes don't fit; the shirt and the
	// raincoat get a peg each.
	class Slot_GebLockerHat {
		name = "GebLockerHat";
		displayName = "$STR_locker_slot_hat";
		ghostIcon = "headgear";
	};
	class Slot_GebLockerGloves {
		name = "GebLockerGloves";
		displayName = "$STR_locker_slot_gloves";
		ghostIcon = "gloves";
	};
	class Slot_GebLockerShirt {
		name = "GebLockerShirt";
		displayName = "$STR_locker_slot_shirt";
		ghostIcon = "body";
	};
	class Slot_GebLockerCoat {
		name = "GebLockerCoat";
		displayName = "$STR_locker_slot_coat";
		ghostIcon = "body";
	};
	class Slot_GebLockerVest {
		name = "GebLockerVest";
		displayName = "$STR_locker_slot_vest";
		ghostIcon = "vest";
	};
	class Slot_GebLockerBoots {
		name = "GebLockerBoots";
		displayName = "$STR_locker_slot_boots";
		ghostIcon = "feet";
	};
	// Tackle boxes (large, old and small), coolers, the bait bucket and the
	// worm and bug containers opt in in data/tackle/config.cpp.
	class Slot_GebLockerTackle1 {
		name = "GebLockerTackle1";
		displayName = "$STR_locker_slot_tackle";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_GebLockerTackle2 {
		name = "GebLockerTackle2";
		displayName = "$STR_locker_slot_tackle";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_GebLockerCooler {
		name = "GebLockerCooler";
		displayName = "$STR_locker_slot_cooler";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_GebLockerBucket {
		name = "GebLockerBucket";
		displayName = "$STR_locker_slot_bucket";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_GebLockerBait {
		name = "GebLockerBait";
		displayName = "$STR_locker_slot_bait";
		ghostIcon = "trapbait";
	};
	// Vanilla's two fish traps (their slots are added below).
	class Slot_GebLockerTrap1 {
		name = "GebLockerTrap1";
		displayName = "$STR_locker_slot_trap";
		ghostIcon = "cat_common_cargo";
	};
	class Slot_GebLockerTrap2 {
		name = "GebLockerTrap2";
		displayName = "$STR_locker_slot_trap";
		ghostIcon = "cat_common_cargo";
	};
};

class cfgVehicles {
	class Container_Base;
	class Trap_Base;

	// Vanilla's fish traps, on the locker's roof. Appended (+=) so other mods'
	// slots on them stay.
	class SmallFishTrap: Trap_Base {
		inventorySlot[] += {"GebLockerTrap1","GebLockerTrap2"};
	};
	class FishNetTrap: Trap_Base {
		inventorySlot[] += {"GebLockerTrap1","GebLockerTrap2"};
	};

	// Crafted from 10 planks and 20 nails with a hammer on you (CraftFishingLocker,
	// RecipeToggles.CraftFishingLocker), carried in both hands and placed with
	// vanilla's hologram like the sea chest and the wooden crate it is built
	// like; it can only be picked up again once it is empty. The cargo is the
	// cabinet along the top: the wooden crate's 50 slots.
	class geb_FishingLocker: Container_Base {
		scope = 2;
		displayName = "$STR_locker_fishinglocker";
		descriptionShort = "$STR_locker_fishinglocker_desc";
		model = "\gebsfish\data\locker\fishinglocker.p3d";
		weight = 20000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		physLayer = "item_large";
		carveNavmesh = 1;
		canBeDigged = 0;
		rotationFlags = 2;
		// The placing hologram (as the fish mounts): "placing" covers every face
		// and is a Model.cfg section, so its texture and material are listed.
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"\gebsfish\data\locker\fishinglocker_co.paa"};
		hiddenSelectionsMaterials[] = {"\gebsfish\data\locker\fishinglocker.rvmat"};
		hologramMaterial = "fishmount";
		hologramMaterialPath = "gebsfish\data\tools";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45,45,45};
		soundImpactType = "wood";
		attachments[] = {
			"fishingrod1","fishingrod2","fishingrod3","fishingrod4","fishingrod5","fishingrod6",
			"GebLockerHat","GebLockerShirt","GebLockerCoat","GebLockerVest","GebLockerGloves","GebLockerBoots",
			"Back",
			"GebLockerTackle1","GebLockerTackle2","GebLockerCooler","GebLockerBucket","GebLockerBait",
			"GebLockerTrap1","GebLockerTrap2"
		};
		class Cargo {
			itemsCargoSize[] = {10,5};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		// Each spot's moves (Model.cfg, generated with it): 0.5 is none, then
		// two metres either way; set by the script from the item's loot box.
		class AnimationSources {
			class rod1_y {
				source = "user";
				animPeriod = 0.01;
				initPhase = 0.5;
			};
			class rod2_y: rod1_y {};
			class rod3_y: rod1_y {};
			class rod4_y: rod1_y {};
			class rod5_y: rod1_y {};
			class rod6_y: rod1_y {};
			class hat_x: rod1_y {};
			class hat_y: rod1_y {};
			class hat_z: rod1_y {};
			class gloves_x: rod1_y {};
			class gloves_y: rod1_y {};
			class gloves_z: rod1_y {};
			class bucket_x: rod1_y {};
			class bucket_y: rod1_y {};
			class bucket_z: rod1_y {};
			class tackle1_x: rod1_y {};
			class tackle1_y: rod1_y {};
			class tackle1_z: rod1_y {};
			class boots_x: rod1_y {};
			class boots_y: rod1_y {};
			class boots_z: rod1_y {};
			class tackle2_x: rod1_y {};
			class tackle2_y: rod1_y {};
			class tackle2_z: rod1_y {};
			class cooler_x: rod1_y {};
			class cooler_y: rod1_y {};
			class cooler_z: rod1_y {};
			class bait_x: rod1_y {};
			class bait_y: rod1_y {};
			class bait_z: rod1_y {};
			class coat_x: rod1_y {};
			class coat_y: rod1_y {};
			class coat_z: rod1_y {};
			class shirt_x: rod1_y {};
			class shirt_y: rod1_y {};
			class shirt_z: rod1_y {};
			class vest_x: rod1_y {};
			class vest_y: rod1_y {};
			class vest_z: rod1_y {};
			class pack_x: rod1_y {};
			class pack_y: rod1_y {};
			class pack_z: rod1_y {};
			class trap1_x: rod1_y {};
			class trap1_y: rod1_y {};
			class trap1_z: rod1_y {};
			class trap2_x: rod1_y {};
			class trap2_y: rod1_y {};
			class trap2_z: rod1_y {};
		};
		// The wooden crate's hit points and grenade armour, restated in full:
		// "class DamageSystem: DamageSystem" only compiles against a class from
		// this same config.
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 500;
					transferToAttachmentsCoef = 0.06;
					healthLevels[] = {
						{1,{"gebsfish\data\locker\fishinglocker.rvmat"}},
						{0.7,{"gebsfish\data\locker\fishinglocker.rvmat"}},
						{0.5,{"gebsfish\data\locker\fishinglocker_damage.rvmat"}},
						{0.3,{"gebsfish\data\locker\fishinglocker_damage.rvmat"}},
						{0,{"gebsfish\data\locker\fishinglocker_destruct.rvmat"}}
					};
				};
			};
			class GlobalArmor {
				class FragGrenade {
					class Health {
						damage = 8;
					};
					class Blood {
						damage = 8;
					};
					class Shock {
						damage = 8;
					};
				};
			};
		};
		// The sea chest's sounds.
		class AnimEvents {
			class SoundWeapon {
				class movement {
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light {
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem {
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop {
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
