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
};

class CfgPatches {
    class gebsVehiclesCfgPatches {
        //Never Use same name for patch, because conflict message.
        requiredAddons[] = {
            "DZ_Scripts",
            "DZ_Data",
            "DZ_Vehicles_Water",  // defines Boat_01_ColorBase (there is no "DZ_Vehicles" patch)
            "DZ_Sounds_Effects"
        };
    };
};

class cfgVehicles {
    class Boat_01_ColorBase;
    class Crew;
    class Driver;

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
            "\gebsfish\data\vehicles\geb_jonboat_greenaluminum_co.paa",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white_co.paa"
        };

        hiddenSelectionsMaterials[] = {
            "\gebsfish\data\vehicles\geb_jonboat.rvmat",
            "\gebsfish\data\vehicles\geb_jonboat_motor_white.rvmat"
        };
        // its own materials for the worn, damaged and ruined looks (RefTexsMats: the model's own material)
        class DamageSystem: DamageSystem {
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
            "MotorCamo"
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
            class DamageZones: DamageZones {
                class Chassis: Chassis {
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
            "MotorCamo"
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
            class DamageZones: DamageZones {
                class Chassis: Chassis {
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
            "MotorCamo"
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
            class DamageZones: DamageZones {
                class Chassis: Chassis {
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
    class geb_jonboat_camo_forest : geb_jonboat_base {
        scope = 2;
        hiddenSelections[] = {
            "BoatCamo",
            "MotorCamo"
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
            class DamageZones: DamageZones {
                class Chassis: Chassis {
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
