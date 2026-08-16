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
	// Attachment proxies for the two deck slots -- THIS is what makes an attached
	// item actually render on the boat. Same pattern as Proxygebfishmount in
	// data/tools/config.cpp: the class name must be "Proxy" + the proxy p3d's
	// filename, and inventorySlot binds that proxy to the slot. Without these
	// entries the slots still accept items and show them in the vehicle inventory
	// panel, but nothing appears on the deck: the model carries the proxies and
	// the config declares the slots, yet the engine has nothing tying the two
	// together, so it never places the attached entity. The proxy p3d itself is
	// never drawn; it only supplies the position and rotation.
	//
	// These MUST live in CfgNonAIVehicles, not cfgVehicles. Putting them in
	// cfgVehicles makes ProxyAttachment resolve to a new empty class there and
	// turns these into bogus vehicle entries, which breaks the jon boat's crew
	// config -- you can't board as driver or passenger.
	class Proxygebboatdeck1: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebBoatDeck1";
		model = "\gebsfish\data\proxy\gebboatdeck1.p3d";
	};
	class Proxygebboatdeck2: ProxyAttachment {
		scope = 2;
		inventorySlot = "GebBoatDeck2";
		model = "\gebsfish\data\proxy\gebboatdeck2.p3d";
	};
};

class CfgSlots {
	// Two general-purpose deck spots on the jon boat. Both accept the same
	// item families (coolers, tackle boxes, jerry cans) so a player can pick
	// any combination rather than being forced into one of each.
	class Slot_GebBoatDeck1 {
		name = "GebBoatDeck1";
		displayName = "$STR_vehicles_jonboat_deck";
		ghostIcon = "missing";
	};
	class Slot_GebBoatDeck2 {
		name = "GebBoatDeck2";
		displayName = "$STR_vehicles_jonboat_deck";
		ghostIcon = "missing";
	};
};

class CfgPatches {
	class gebsVehiclesCfgPatches { 	
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
			"DZ_Scripts",
			"DZ_Data",
            "DZ_Vehicles",
            "DZ_Sounds_Effects"
		};
	};
};

class cfgVehicles {
	class Boat_01_ColorBase;
	class Crew;
	class Driver;
	class Bottle_Base;

	// Vanilla jerry can opted into the deck slots. The gebsfish coolers and
	// tackle boxes get the same treatment where they are defined, in
	// data/tackle/config.cpp, so this stays independent of config load order.
	// Base must match vanilla exactly (dz\vehicles\parts\config.cpp) -- reopening
	// a class under a different parent reparents it.
	class CanisterGasoline: Bottle_Base {
		inventorySlot[] += {"GebBoatDeck1", "GebBoatDeck2"};
	};
    class geb_jonboat_base : Boat_01_ColorBase {
        scope = 0;
        displayName = "$STR_vehicles_jonboat";
        descriptionShort = "$STR_vehicles_jonboat_desc";
		model="\gebsfish\data\vehicles\geb_jonboat.p3d";
        fuelCapacity = 25;
        fuelConsumption = 5.5;
        animPhysDetachSpeed = 5;
        attachments[] = {
            "SparkPlug",
            "GebBoatDeck1",
            "GebBoatDeck2"
        };
		class Cargo
		{
			itemsCargoSize[] = {10,30};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
        class AnimationSources {
            class FoldingEngine {
                source = "user";
                animPeriod = 2;
                initPhase = 0;
            };
            class ShowDamage {
                source = "user";
                animPeriod = 0.0001;
                initPhase = 0;
            };
            class HideDamage {
                source = "user";
                animPeriod = 0.0001;
                initPhase = 1;
            };
            class HideAntiwater {
                source = "user";
                animPeriod = 0.0001;
                initPhase = 0;
            };
        };
        class Crew : Crew {
            class Driver : Driver {
            };
            class Cargo1 {
                actionSel = "seat_cargo1";
                proxyPos = "crewCargo1";
                getInPos = "pos_cargo1";
                getInDir = "pos_cargo1_dir";
            };
            class Cargo2 {
                actionSel = "seat_cargo2";
                proxyPos = "crewCargo2";
                getInPos = "pos_cargo2";
                getInDir = "pos_cargo2_dir";
            };
            class Cargo3 {
                actionSel = "seat_Cargo3";
                proxyPos = "crewCargo3";
                getInPos = "pos_cargo3";
                getInDir = "pos_cargo3_dir";
            };
        };
        class SimulationModule {
            class Engine {
                torqueCurve[] = {500, 50, 1000, 90, 1500, 130, 2500, 220, 3500, 310, 4800, 220, 6500, 50, 7000, 0};
                inertia = 1.1;
                frictionTorque = 200;
                rollingFriction = 1.5;
                viscousFriction = 0.8;
                rpmIdle = 700;
                rpmMin = 750;
                rpmClutch = 1250;
                rpmRedline = 6500;
            };
            class Clutch {
                maxTorqueTransfer = 500;
                uncoupleTime = 0.7;
                coupleTime = 0.7;
            };
            class Gearbox {
                reverse = 1.2;
                ratios[] = {0.88};
            };
            class Throttle {
                defaultThrust = 0.75;
                turboIncrease = 2.4;
                regularIncrease = 1.35;
                slowIncrease = 1.12;
                turboDecrease = 1.5;
                regularDecrease = 1.5;
                slowDecrease = 1;
                autoDecrease = 1;
            };
            class Steering {
                maxSteeringAngle = 21;
                increaseSpeed[] = {0, 12, 30, 8, 50, 4};
                decreaseSpeed[] = {0, 24, 30, 16, 50, 8};
                centeringSpeed[] = {0, 12, 30, 8, 50, 4};
            };
            class Propeller {
                position[] = {0, -0.11, -2.1};
                radius = 0.1245;
                outerRadius = 0.134;
                innerRadius = 0.095;
                efficiency = 0.87;
                cavitationThreshold = 0.5;
                pitch = 40;
                width = 0.1;
                numberOfBlades = 3;
                mass = 0.53;
            };
        };
        class DamageSystem {
            class GlobalHealth {
                class Health {
                    hitpoints = 600;
                    healthLevels[] = {
                        {1, {}},
                        {0.7, {}},
                        {0.5, {}},
                        {0.3, {}},
                        {0, {}}
                    };
                };
            };
            class DamageZones {
                class Chassis {
                    displayName = "$STR_CfgVehicleDmg_Chassis0";
                    fatalInjuryCoef = 0;
                    componentNames[] = {
                        "dmgZone_chassis"
                    };
                    class Health {
                        hitpoints = 600;
                        transferToGlobalCoef = 1;
                    };
                    inventorySlots[] = {};
                    inventorySlotsCoefs[] = {};
                };
                class Engine {
                    displayName = "$STR_CfgVehicleDmg_Engine0";
                    fatalInjuryCoef = 0.001;
                    memoryPoints[] = {
                        "dmgZone_engine",
                        "dmgZone_propeller"
                    };
                    componentNames[] = {
                        "dmgZone_engine",
                        "dmgZone_propeller"
                    };
                    class Health {
                        hitpoints = 300;
                        transferToGlobalCoef = 0;
                        healthLevels[] = {
                            {1, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.7, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.5, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0.3, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0, {"dz\vehicles\water\Boat_01\data\Boat_01_destruct.rvmat"}}
                        };
                    };
                    inventorySlots[] = {
                        "Sparkplug"
                    };
                    inventorySlotsCoefs[] = {0.5};
                };
                class LeftFloat {
                    displayName = "$STR_cfgvehicleDmg_Floater0";
                    fatalInjuryCoef = 0;
                    memoryPoints[] = {
                        "dmgZone_leftFloat"
                    };
                    componentNames[] = {
                        "dmgZone_leftFloat"
                    };
                    class Health {
                        hitpoints = 200;
                        transferToGlobalCoef = 1.05;
                        healthLevels[] = {
                            {1, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.7, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.5, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0.3, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0, {"dz\vehicles\water\Boat_01\data\Boat_01_destruct.rvmat"}}
                        };
                    };
                    inventorySlots[] = {};
                    inventorySlotsCoefs[] = {};
                };
                class RightFloat {
                    displayName = "$STR_cfgvehicleDmg_Floater1";
                    fatalInjuryCoef = 0;
                    memoryPoints[] = {
                        "dmgZone_rightFloat"
                    };
                    componentNames[] = {
                        "dmgZone_rightFloat"
                    };
                    class Health {
                        hitpoints = 200;
                        transferToGlobalCoef = 1.05;
                        healthLevels[] = {
                            {1, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.7, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.5, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0.3, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0, {"dz\vehicles\water\Boat_01\data\Boat_01_destruct.rvmat"}}
                        };
                    };
                    inventorySlots[] = {};
                    inventorySlotsCoefs[] = {};
                };
                class FrontFloat {
                    displayName = "$STR_cfgvehicleDmg_Floater2";
                    fatalInjuryCoef = 0;
                    memoryPoints[] = {
                        "dmgZone_frontFloat"
                    };
                    componentNames[] = {
                        "dmgZone_frontFloat"
                    };
                    class Health {
                        hitpoints = 200;
                        transferToGlobalCoef = 1.05;
                        healthLevels[] = {
                            {1, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.7, {"dz\vehicles\water\Boat_01\data\Boat_01.rvmat"}},
                            {0.5, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0.3, {"dz\vehicles\water\Boat_01\data\Boat_01_damage.rvmat"}},
                            {0, {"dz\vehicles\water\Boat_01\data\Boat_01_destruct.rvmat"}}
                        };
                    };
                    inventorySlots[] = {};
                    inventorySlotsCoefs[] = {};
                };
            };
        };
        class GUIInventoryAttachmentsProps {
            class Engine {
                name = "$STR_attachment_Engine0";
                description = "";
                icon = "set:dayz_inventory image:cat_vehicle_engine";
                attachmentSlots[] = {
                    "SparkPlug"
                };
            };
            // The vehicle inventory panel draws attachment slots per category
            // here -- a slot listed only in attachments[] above gets no visible
            // spot to drop an item on. Both deck slots need to appear in one.
            class Deck {
                name = "$STR_vehicles_jonboat_deck";
                description = "";
                icon = "set:dayz_inventory image:cat_vehicle_body";
                attachmentSlots[] = {
                    "GebBoatDeck1",
                    "GebBoatDeck2"
                };
            };
        };
    };
    class geb_jonboat_greenaluminum : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
        };

        hiddenSelectionsTextures[] = {
		    "\gebsfish\data\vehicles\geb_jonboat_greenaluminum.paa",
		    "\gebsfish\data\vehicles\geb_jonboat_motor_white.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
    };
    class geb_jonboat_grayaluminum : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
        };

        hiddenSelectionsTextures[] = {
		    "\gebsfish\data\vehicles\geb_jonboat_grayaluminum.paa",
		    "\gebsfish\data\vehicles\geb_jonboat_motor_white.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
    };
    class geb_jonboat_camo_desert : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
        };

        hiddenSelectionsTextures[] = {
		    "\gebsfish\data\vehicles\geb_jonboat_desertcamo.paa",
		    "\gebsfish\data\vehicles\geb_jonboat_motor_black.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
    };
    class geb_jonboat_camo_snow : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
        };

        hiddenSelectionsTextures[] = {
		    "\gebsfish\data\vehicles\geb_jonboat_snowcamo.paa",
		    "\gebsfish\data\vehicles\geb_jonboat_motor_black.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
    };
    class geb_jonboat_camo_forest : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
        };

        hiddenSelectionsTextures[] = {
		    "\gebsfish\data\vehicles\geb_jonboat_forestcamo.paa",
		    "\gebsfish\data\vehicles\geb_jonboat_motor_black.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
    };
};