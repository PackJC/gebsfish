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
    class ProxyVehiclePart;
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
    // The car battery in the box, the same way: the model first used vanilla's
    // own car-battery proxy (ProxyBattery_Car, which serves the CarBattery and
    // LargeBattery slots), and an attached battery never appeared on the boat.
    class Proxygebboatbattery: ProxyAttachment {
        scope = 2;
        inventorySlot = "CarBattery";
        model = "\gebsfish\data\proxy\gebboatbattery.p3d";
    };
    // The boat trailer's two wheels, vehicle parts like vanilla's car wheels
    // (ProxyVehiclePart, DZ_Vehicles_Wheeled). The proxies sit in the model's
    // wheel bones, so the attached wheels turn and spring with them; their
    // copies in the fire geometry are where the engine puts the wheels.
    class Proxygebtrailerwheel_l: ProxyVehiclePart {
        scope = 2;
        inventorySlot = "GebTrailerWheel_L";
        model = "\gebsfish\data\proxy\gebtrailerwheel_l.p3d";
    };
    class Proxygebtrailerwheel_r: ProxyVehiclePart {
        scope = 2;
        inventorySlot = "GebTrailerWheel_R";
        model = "\gebsfish\data\proxy\gebtrailerwheel_r.p3d";
    };
    // The trailer's dummy Front hubs. Nothing is ever drawn on them, but the
    // engine places every wheel (and links its tyre) by the proxy of its slot
    // in the model's fire geometry, so each hub needs one.
    class Proxygebtrailerjack_l: ProxyVehiclePart {
        scope = 2;
        inventorySlot = "GebTrailerJack_L";
        model = "\gebsfish\data\proxy\gebtrailerjack_l.p3d";
    };
    class Proxygebtrailerjack_r: ProxyVehiclePart {
        scope = 2;
        inventorySlot = "GebTrailerJack_R";
        model = "\gebsfish\data\proxy\gebtrailerjack_r.p3d";
    };
};

class CfgSlots {
    // Two general-purpose deck spots on the jon boat. Both accept the same
    // item families (coolers and tackle boxes) so a player can pick any
    // combination rather than being forced into one of each.
    // Ghost icon: vanilla's crate (set:dayz_inventory image:cat_common_cargo),
    // as both spots take a cooler or a tackle box.
    class Slot_GebBoatDeck1 {
        name = "GebBoatDeck1";
        displayName = "$STR_vehicles_jonboat_deck";
        ghostIcon = "cat_common_cargo";
    };
    class Slot_GebBoatDeck2 {
        name = "GebBoatDeck2";
        displayName = "$STR_vehicles_jonboat_deck";
        ghostIcon = "cat_common_cargo";
    };
    // The boat trailer's wheels: vanilla Gunter 2 wheels, named and drawn as
    // vanilla's own wheel slots are.
    class Slot_GebTrailerWheel_L {
        name = "GebTrailerWheel_L";
        displayName = "#STR_CfgWheel0";
        ghostIcon = "set:dayz_inventory image:wheel";
    };
    class Slot_GebTrailerWheel_R {
        name = "GebTrailerWheel_R";
        displayName = "#STR_CfgWheel0";
        ghostIcon = "set:dayz_inventory image:wheel";
    };
    // The trailer's dummy Front hubs. Every vehicle wheel must name a slot that
    // exists (an empty one crashed the server); no item fits these and the
    // trailer doesn't list them as attachments, so the hubs stay bare.
    class Slot_GebTrailerJack_L {
        name = "GebTrailerJack_L";
        displayName = "#STR_CfgWheel0";
        ghostIcon = "set:dayz_inventory image:wheel";
    };
    class Slot_GebTrailerJack_R {
        name = "GebTrailerJack_R";
        displayName = "#STR_CfgWheel0";
        ghostIcon = "set:dayz_inventory image:wheel";
    };
};

class CfgPatches {
    class gebsVehiclesCfgPatches {
        //Never Use same name for patch, because conflict message.
        requiredAddons[] = {
            "DZ_Scripts",
            "DZ_Data",
            "DZ_Vehicles_Water",  // defines Boat_01_ColorBase (there is no "DZ_Vehicles" patch)
            "DZ_Vehicles_Wheeled",  // Hatchback_02_Wheel, on the boat trailer
            "DZ_Sounds_Effects"
        };
    };
};

class cfgVehicles {
    class Boat_01_ColorBase;
    class Crew;
    class Driver;
    class Inventory_Base;
    class CarWheel;
    class CarScript;

    // Vanilla's Gunter 2 wheel also fits the boat trailer. Appended (+=) so
    // other mods' slots on it stay; the ruined wheel inherits the list.
    class Hatchback_02_Wheel: CarWheel {
        inventorySlot[] += {"GebTrailerWheel_L","GebTrailerWheel_R"};
    };

    // Boat trailer: a vehicle with no engine and no seats. It rolls freely on
    // two Gunter 2 wheels (Rear axle, braked only while parked) and parks on
    // its jack foot (a collision box that clears the ground while it is towed;
    // the Front axle, which the engine needs, is two dummy hubs up on the
    // tongue that never reach the ground). Hitched, a physics ball joint holds
    // its coupler on the car's hitch ball (geb_boattrailer.c; hitch and unhitch
    // in geb_actiontrailerhitch.c). It breaks off when it jackknifes, the car
    // crashes or rolls, or the car is gone. A new trailer comes with its wheels.
    // Assets built by tools/trailer (original model, nothing from vanilla).
    class geb_BoatTrailer: CarScript {
        scope = 2;
        displayName = "$STR_vehicles_boattrailer";
        descriptionShort = "$STR_vehicles_boattrailer_desc";
        model = "\gebsfish\data\vehicles\boattrailer.p3d";
        fuelCapacity = 0;
        fuelConsumption = 0;
        brakeFluidCapacity = 0;
        oilCapacity = 0;
        coolantCapacity = 0;
        attachments[] = {
            "GebTrailerWheel_L",
            "GebTrailerWheel_R"
        };
        // "lights" = the two tail-light lenses: the script swaps in a glowing
        // material with the car's tail and brake lights (and picks the worn or
        // ruined one itself, so the lit looks aren't in healthLevels)
        hiddenSelections[] = {"camo","lights"};
        hiddenSelectionsTextures[] = {"\gebsfish\data\vehicles\boattrailer_co.paa","\gebsfish\data\vehicles\boattrailer_co.paa"};
        hiddenSelectionsMaterials[] = {"\gebsfish\data\vehicles\boattrailer.rvmat","\gebsfish\data\vehicles\boattrailer.rvmat"};
        // Nobody rides it: one driver place, as every vehicle has, with nothing
        // in the model to get in by (and no get-in action, geb_boattrailer.c).
        class Crew {
            class Driver {
                actionSel = "seat_driver";
                proxyPos = "crewDriver";
                getInPos = "pos_driver";
                getInDir = "pos_driver_dir";
                isDriver = 1;
            };
        };
        class SimulationModule {
            class Steering {
                maxSteeringAngle = 1;
                increaseSpeed[] = {0, 50, 100, 15};
                decreaseSpeed[] = {0, 90, 100, 20};
                centeringSpeed[] = {0, 0, 100, 60};
            };
            class Throttle {
                reactionTime = 1;
                defaultThrust = 0.5;
                gentleThrust = 0.5;
                turboCoef = 1;
                gentleCoef = 1;
            };
            // nobody ever drives it, so the "driverless" brake is on whenever
            // it is parked: its parking brake. Hitched (and pushed by hand, as
            // vanilla's push does) the script lets it off, so it rolls freely.
            class Brake {
                pressureBySpeed[] = {0, 1, 100, 1};
                reactionTime = 0.2;
                driverless = 1;
            };
            class Aerodynamics {
                frontalArea = 1.2;
                dragCoefficient = 0.4;
                downforceCoefficient = 0;
                downforceOffset[] = {0, 0, 0};
            };
            // The drive is on the dummy Front hubs, so the wheels roll free: on the
            // driven axle they'd be geared to an engine that never runs.
            drive = "DRIVE_FWD";
            // no engine ever runs: a minimal one, as every vehicle has
            class Engine {
                torqueCurve[] = {850, 0, 1150, 20, 2000, 20, 4400, 20, 5800, 20, 7500, 0};
                inertia = 0.21;
                frictionTorque = 150;
                rollingFriction = 0.2;
                viscousFriction = 0.5;
                rpmIdle = 1250;
                rpmMin = 1500;
                rpmClutch = 2000;
                rpmRedline = 6250;
            };
            class Clutch {
                maxTorqueTransfer = 100;
                uncoupleTime = 0.25;
                coupleTime = 0.35;
            };
            class Gearbox {
                type = "GEARBOX_MANUAL";
                reverse = 3.167;
                ratios[] = {3.455};
            };
            class Axles {
                // dummy: two 5 cm bare hubs up on the tongue that never reach the
                // ground (the engine needs two axles; as a jack caster near the
                // ground they levered the trailer about, 2026-10-14). Their slots
                // exist but take nothing (an empty slot name crashes the engine).
                class Front {
                    maxBrakeTorque = 4000;
                    maxHandbrakeTorque = 4000;
                    wheelHubMass = 3;
                    wheelHubRadius = 0.05;
                    class Differential {
                        ratio = 3.667;
                        type = "DIFFERENTIAL_OPEN";
                    };
                    class Suspension {
                        stiffness = 100000;
                        compression = 1500;
                        damping = 3000;
                        travelMaxUp = 0.02;
                        travelMaxDown = 0.01;
                    };
                    class Wheels {
                        class Left {
                            inventorySlot = "GebTrailerJack_L";
                            animTurn = "";
                            animRotation = "";
                            animDamper = "";
                            wheelHub = "wheel_1_1_damper_land";
                        };
                        class Right {
                            inventorySlot = "GebTrailerJack_R";
                            animTurn = "";
                            animRotation = "";
                            animDamper = "";
                            wheelHub = "wheel_2_1_damper_land";
                        };
                    };
                };
                // the wheels: leaf springs for a 300 kg trailer; braked only by
                // the parking brake (unhitched: enough for a steep ramp)
                class Rear {
                    maxBrakeTorque = 400;
                    maxHandbrakeTorque = 0;
                    wheelHubMass = 5;
                    wheelHubRadius = 0.14;
                    class Suspension {
                        stiffness = 23000;
                        compression = 450;
                        damping = 1600;
                        travelMaxUp = 0.08;
                        travelMaxDown = 0.08;
                    };
                    class Wheels {
                        class Left {
                            inventorySlot = "GebTrailerWheel_L";
                            animTurn = "";
                            animRotation = "wheelbackleft";
                            animDamper = "damper_1_2";
                            wheelHub = "wheel_1_2_damper_land";
                        };
                        class Right {
                            inventorySlot = "GebTrailerWheel_R";
                            animTurn = "";
                            animRotation = "wheelbackright";
                            animDamper = "damper_2_2";
                            wheelHub = "wheel_2_2_damper_land";
                        };
                    };
                };
            };
        };
        class GUIInventoryAttachmentsProps {
            class Chassis {
                name = "$STR_attachment_Chassis0";
                description = "";
                icon = "set:dayz_inventory image:cat_vehicle_chassis";
                attachmentSlots[] = {
                    "GebTrailerWheel_L",
                    "GebTrailerWheel_R"
                };
            };
        };
        // its own (not a car's doors and hit-zone sources)
        class AnimationSources {
            // 0 parked, 0.22 hitched: about a second either way
            class jackraise {
                source = "user";
                animPeriod = 4;
                initPhase = 0;
            };
        };
        class DamageSystem {
            class GlobalHealth {
                class Health {
                    hitpoints = 1000;
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\boattrailer.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\boattrailer.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\boattrailer_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\boattrailer_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\boattrailer_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    // The vanilla jerry can (CanisterGasoline) deliberately does NOT opt into the
    // deck slots. A proxy supplies one position and rotation for everything that
    // lands on it, and the gebsfish coolers and tackle boxes all share an axis
    // convention the jerry can doesn't -- one orientation cannot suit both. The
    // deck proxies are aimed at the 27 gebsfish containers; adding the can back
    // would put it back to sitting wrong. If it's wanted later it needs its own
    // slot and its own proxy, not a share of these.
    class geb_jonboat_base : Boat_01_ColorBase {
        scope = 0;
        displayName = "$STR_vehicles_jonboat";
        descriptionShort = "$STR_vehicles_jonboat_desc";
        model="\gebsfish\data\vehicles\geb_jonboat.p3d";
        fuelCapacity = 23;  // the 6 gal portable tank on the stern shelf
        fuelConsumption = 5.5;
        animPhysDetachSpeed = 5;
        attachments[] = {
            "SparkPlug",
            "GebBoatDeck1",
            "GebBoatDeck2",
            "CarBattery"
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
                    // The whole boat: hull, motor and the gear atlas (fuel tank, battery box,
                    // hoses, light housings). The engine draws EITHER these global looks (while
                    // no damage zone below is worn) OR the zones' own looks (once any zone is
                    // worn), never both, so the global list must name every part: with only
                    // the gear here, damage dealt to the boat as a whole (an admin tool's
                    // health slider, script damage) never showed on the hull or the motor.
                    // The light lenses are switched by script (geb_jonboat.c).
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
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
                        // the hull, and the gear (tank, battery box, hoses): the model's
                        // visual dmgzone_chassis selection takes in the gear's faces too
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
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
                            {1,{"gebsfish\data\vehicles\geb_jonboat_motor.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_motor.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat"}}
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
                            {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat"}}
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
                            {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat"}}
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
                            {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat"}}
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
                icon = "set:gebsfish image:outboard";
                attachmentSlots[] = {
                    "SparkPlug"
                };
            };
            // Category icons: the jon boat's own (gui/gebsfish.imageset), not vanilla's car ones.
            // The vehicle inventory panel draws attachment slots per category
            // here -- a slot listed only in attachments[] above gets no visible
            // spot to drop an item on. Both deck slots need to appear in one.
            class Deck {
                name = "$STR_vehicles_jonboat_deck";
                description = "";
                icon = "set:gebsfish image:boat";
                attachmentSlots[] = {
                    "GebBoatDeck1",
                    "GebBoatDeck2"
                };
            };
            // the car battery in the box beside the fuel tank: powers the lights only
            class Battery {
                name = "$STR_vehicles_jonboat_battery";
                description = "";
                icon = "set:gebsfish image:battery";
                attachmentSlots[] = {
                    "CarBattery"
                };
            };
        };
    };
    class geb_jonboat_greenaluminum : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_greenaluminum_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Engine: Engine {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat_motor.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_motor_white_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
    class geb_jonboat_grayaluminum : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_grayaluminum_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_white_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Chassis: Chassis {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
                    };
                };
                class LeftFloat: LeftFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_destruct.rvmat"}}
                        };
                    };
                };
                class RightFloat: RightFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_destruct.rvmat"}}
                        };
                    };
                };
                class FrontFloat: FrontFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_grayaluminum_destruct.rvmat"}}
                        };
                    };
                };
                class Engine: Engine {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat_motor.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_motor_white_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_motor_white_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
    class geb_jonboat_camo_desert : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_desertcamo_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_black_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Chassis: Chassis {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
                    };
                };
                class LeftFloat: LeftFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_destruct.rvmat"}}
                        };
                    };
                };
                class RightFloat: RightFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_destruct.rvmat"}}
                        };
                    };
                };
                class FrontFloat: FrontFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_desertcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_desertcamo_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
    class geb_jonboat_camo_snow : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_snowcamo_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_black_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Chassis: Chassis {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
                    };
                };
                class LeftFloat: LeftFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_destruct.rvmat"}}
                        };
                    };
                };
                class RightFloat: RightFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_destruct.rvmat"}}
                        };
                    };
                };
                class FrontFloat: FrontFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_snowcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_snowcamo_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
    class geb_jonboat_camo_pink : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_pinkcamo_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_black_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Chassis: Chassis {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
                    };
                };
                class LeftFloat: LeftFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_destruct.rvmat"}}
                        };
                    };
                };
                class RightFloat: RightFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_destruct.rvmat"}}
                        };
                    };
                };
                class FrontFloat: FrontFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_pinkcamo_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
    class geb_jonboat_camo_forest : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo",
            "geb_lights"
        };

        hiddenSelectionsTextures[] = {
            "\gebsfish\data\vehicles\geb_jonboat_forestcamo_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_black_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
            // the whole boat in this skin (see geb_jonboat_base's GlobalHealth)
            class GlobalHealth: GlobalHealth {
                class Health: Health {
                    RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                    healthLevels[] = {
                        {1,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.7,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_motor.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                        {0.5,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0.3,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                        {0,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_motor_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                    };
                };
            };
            class DamageZones: DamageZones {
                class Chassis: Chassis {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat","gebsfish\data\vehicles\geb_jonboat_gear.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_destruct.rvmat","gebsfish\data\vehicles\geb_jonboat_gear_destruct.rvmat"}}
                        };
                    };
                };
                class LeftFloat: LeftFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_destruct.rvmat"}}
                        };
                    };
                };
                class RightFloat: RightFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_destruct.rvmat"}}
                        };
                    };
                };
                class FrontFloat: FrontFloat {
                    class Health: Health {
                        RefTexsMats[] = {"gebsfish\data\vehicles\geb_jonboat.rvmat"};
                        healthLevels[] = {
                            {1,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.7,{"gebsfish\data\vehicles\geb_jonboat_forestcamo.rvmat"}},
                            {0.5,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0.3,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_damage.rvmat"}},
                            {0,{"gebsfish\data\vehicles\geb_jonboat_forestcamo_destruct.rvmat"}}
                        };
                    };
                };
            };
        };
    };
};
