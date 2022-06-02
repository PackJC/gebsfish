class CfgPatches {
  class gebsfish {
    units[] = {
      "Bluegill",
      "Blackbass",
      "Catfish",
      "Largemouthbass",
      "Minnow",
      "Northernpike",
      "Perch",
      "Sauger",
      "Crayfish",
      "Trout",
      "Whitebass",
      "Angelfish",
      "Asianseabass",
      "Bluemarlin",
      "Bonita",
      "Cherrysalmon",
      "Flatheadmullet",
      "Leopardshark",
      "Pacificcod",
      "Redheadcichlid",
      "Roughneckrock",
      "Severum",
      "Shrimp",
      "Bownfin",
      "Slimysculpin",
      "Bluetang",
      "Hairtailfish",
      "Humpheadwrasse",
      "Siamesetigerfish",
      "Bloodclam",
      "Mussel",
      "Blackdevilsnail",
      "Starfish",
      "Kingcrab",
      "Jellyfish"
    };
    weapons[] = {};
    requiredVersion = 0.1;
    requiredAddons[] = {
      "DZ_Data",
      "DZ_Characters",
      "DZ_Scripts"
    };
	
	
	
  };
};
class cfgVehicles {

  //Instantiate Needed Classes
  class FoodAnimationSources;
  class NotCookable;
  class Edible_Base;
  class WaterBottle;
	
  /*
	
    CLOTHES
	
  */

  //Gloves
  class NBCGloves_ColorBase;
  class OrangeFishGloves: NBCGloves_ColorBase
	{
		displayName="Orange Fishing Gloves";
		descriptionShort="A pair of gloves useful when cutting fish.";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_orangefishgloves.paa",
			"gebsfish\data\food\geb_orangefishgloves.paa",
			"gebsfish\data\food\geb_orangefishgloves.paa"
		};
	};
  class BlueFishGloves: NBCGloves_ColorBase
	{
		displayName="Blue Fishing Gloves";
		descriptionShort="A pair of gloves useful when cutting fish.";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_bluefishgloves.paa",
			"gebsfish\data\food\geb_bluefishgloves.paa",
			"gebsfish\data\food\geb_bluefishgloves.paa"
		};
	};	

  //Hats
  class BaseballCap_ColorBase;
  class BlueFishHat: BaseballCap_ColorBase
	{
		displayName="Blue Fishing Hat";
		descriptionShort="A hat with a decal of a fish!";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_bluefishhat.paa",
			"gebsfish\data\food\geb_bluefishhat.paa",
			"gebsfish\data\food\geb_bluefishhat.paa"
		};
	};
  class RedFishHat: BaseballCap_ColorBase
	{
		displayName="Red Fishing Hat";
		descriptionShort="A hat with a decal of a fish!";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_redfishhat.paa",
			"gebsfish\data\food\geb_redfishhat.paa",
			"gebsfish\data\food\geb_redfishhat.paa"
		};
	};	
  class GreenFishHat: BaseballCap_ColorBase
	{
		scope=2;
		displayName="Green Fishing Hat";
		descriptionShort="A hat with a decal of a fish!";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_greenfishhat.paa",
			"gebsfish\data\food\geb_greenfishhat.paa",
			"gebsfish\data\food\geb_greenfishhat.paa"
		};
	};	
  class PurpleFishHat: BaseballCap_ColorBase
	{
		displayName="Purple Fishing Hat";
		descriptionShort="A hat with a decal of a fish!";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"gebsfish\data\food\geb_purplefishhat.paa",
			"gebsfish\data\food\geb_purplefishhat.paa",
			"gebsfish\data\food\geb_purplefishhat.paa"
		};
	};	
	
  //Shirts
  class TShirt_ColorBase;
  class RedFishShirt : TShirt_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\tops\data\tshirt_ground_red_co.paa",
            "gebsfish\data\food\geb_redfishshirt.paa",
            "gebsfish\data\food\geb_redfishshirt.paa"
        };
    };
  class GreenFishShirt : TShirt_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\tops\data\tshirt_ground_green_co.paa",
            "gebsfish\data\food\geb_greenfishshirt.paa",
            "gebsfish\data\food\geb_greenfishshirt.paa"
        };
    };
  class BlueFishShirt : TShirt_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\tops\data\tshirt_ground_blue_co.paa",
            "gebsfish\data\food\geb_bluefishshirt.paa",
            "gebsfish\data\food\geb_bluefishshirt.paa"
        };
    };
  class PurpleFishShirt : TShirt_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\tops\data\tshirt_ground_black_co.paa",
            "gebsfish\data\food\geb_purplefishshirt.paa",
            "gebsfish\data\food\geb_purplefishshirt.paa"
        };
    };

  /* 
  
  	CONTAINERS
  
  */

  class Container_Base;
  class YellowTackle : Container_Base
  {
      scope = 2;
      displayName = "Yellow Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_yellowtackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class RedTackle : YellowTackle
  {
      scope = 2;
      displayName = "Red Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_redtackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class BlueTackle : Container_Base
  {
      inventorySlot = "tacklebox";
      scope = 2;
      displayName = "Blue Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_bluetackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class OrangeTackle : Container_Base
  {
      scope = 2;
      displayName = "Orange Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_orangetackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class BrownTackle : Container_Base
  {
      scope = 2;
      displayName = "Brown Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_browntackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class PurpleTackle : Container_Base
  {
      scope = 2;
      displayName = "Purple Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_purpletackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class PinkTackle : Container_Base
  {
      scope = 2;
      displayName = "Pink Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_pinktackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class LimeTackle : Container_Base
  {
      scope = 2;
      displayName = "Lime Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_limetackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class LightBlueTackle : Container_Base
  {
      scope = 2;
      displayName = "Light Blue Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_lightbluetackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class GreenTackle : Container_Base
  {
      scope = 2;
      displayName = "Green Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_greentackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class CamoTackle : Container_Base
  {
      scope = 2;
      displayName = "Camo Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_camotackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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

  class FunYellowTackle : Container_Base
  {
      scope = 2;
      displayName = "Fun Yellow Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_funyellowtackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class FunRedTackle : Container_Base
  {
      scope = 2;
      displayName = "Fun Red Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_funredtackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class FunPurpleTackle : Container_Base
  {
      scope = 2;
      displayName = "Fun Purple Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_funpurpletackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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
  class FunGreenTackle : Container_Base
  {
      scope = 2;
      displayName = "Fun Green Tackle Box";
      descriptionShort = "A safe place to put some hooks and sinkers.";
      model = "gebsfish\data\food\geb_fungreentackle.p3d";
      rotationFlags = 17;
      weight = 140;
      itemSize[] = {
        3,
        2
      };
      itemsCargoSize[] = {
        9,
        1
      };
      canBeDigged = 1;
      absorbency = 0;
      isMeleeWeapon = 1;
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      repairableWithKits[] = { 5,2 };
      repairCosts[] = { 30,25 };
      lootTag[] =
      {
          "Hunting",
          "Work",
          "Camping"
      };
      hiddenSelections[] =
      {
          "zbytek"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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


  class SmallTackle: Container_Base {
	  
    scope = 2;
    displayName = "Mini Tackle";
    descriptionShort = "A safe place to put some worms or hooks!";
    model = "gebsfish\data\food\geb_smalltackle.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_smalltackle.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      2,
      1
    };
    itemsCargoSize[] = {
        6,
        1
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;

    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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

  }

  class WormContainer: Container_Base {
	  
    scope = 2;
    displayName = "Worm Container";
    descriptionShort = "A safe place to put some worms!";
    model = "gebsfish\data\food\geb_wormcontainer.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_wormcontainer.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      2,
      2
    };
    itemsCargoSize[] = {
      3,
      2
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;

    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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

  }
  class BugContainer: Container_Base {


    scope = 2;
    displayName = "Bug Container";
    descriptionShort = "A safe place to put some bugs, can also be used to catch them! Grasshoppers, Field Crickets, and Grubs!";
    model = "gebsfish\data\food\geb_bugcontainer.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_bugcontainer.paa";
    };
    itemInfo[] =
    {
        "CatchBugs"
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      1,
      3
    };
    itemsCargoSize[] = {
      10,
      1
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;

    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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

  }
  class MinnowBucket : WaterBottle
  {
      scope = 2;
      displayName = "Minnow Bucket";
      descriptionShort = "A great place to store small marine life. Minnows, sardines, Slimy Sculpin, Crayfish, Shrimp!";
      model = "gebsfish\data\food\geb_minnowbucket.p3d";
      debug_ItemCategory = 6;
      weight = 25;
      itemSize[] = { 3,3 };
      itemsCargoSize[] = { 4,4 };
      destroyOnEmpty = 0;
      varQuantityDestroyOnMin = 0;
      varLiquidTypeInit = 512;
      liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
      varQuantityInit = 1000;
      varQuantityMin = 0;
      varQuantityMax = 1000;
      isMeleeWeapon = 1;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 50;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\drinks\data\Loot_WaterBottle.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\drinks\data\Loot_WaterBottle.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
      class AnimEvents
      {
          class SoundWeapon
          {
              class WaterBottle_in_B
              {
                  soundSet = "WaterBottle_in_B_SoundSet";
                  id = 202;
              };
              class WaterBottle_in_C
              {
                  soundSet = "WaterBottle_in_C_SoundSet";
                  id = 203;
              };
              class WaterBottle_in_C1
              {
                  soundSet = "WaterBottle_in_C1_SoundSet";
                  id = 204;
              };
              class WaterBottle_out_A
              {
                  soundSet = "WaterBottle_out_A_SoundSet";
                  id = 205;
              };
              class WaterBottle_out_B
              {
                  soundSet = "WaterBottle_out_B_SoundSet";
                  id = 206;
              };
              class WellPond_loop
              {
                  soundSet = "WellPond_loop_SoundSet";
                  id = 209;
              };
              class WellBottle_loop
              {
                  soundSet = "WellBottle_loop_SoundSet";
                  id = 210;
              };
              class pickup
              {
                  soundSet = "WaterBottle_pickup_SoundSet";
                  id = 797;
              };
          };
      };
  };


  class OldGreenTackleBox: Container_Base {
    scope = 2;
    displayName = "Old Green Tackle Box";
    descriptionShort = "A safe place to put some hooks and sinkers.";
    model = "gebsfish\data\food\geb_old_greentackle.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_old_greentackle.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      3,
      2
    };
    itemsCargoSize[] = {
      3,
      2
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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
  class OldRedTackleBox: Container_Base {
    scope = 2;
    displayName = "Old Red Tackle Box";
    descriptionShort = "A safe place to put some hooks and sinkers.";
    model = "gebsfish\data\food\geb_old_redtackle.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_old_redtackle.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      3,
      2
    };
    itemsCargoSize[] = {
      3,
      2
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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
  class OldBlueTackleBox: Container_Base {
    scope = 2;
    displayName = "Old Blue Tackle Box";
    descriptionShort = "A safe place to put some hooks and sinkers.";
    model = "gebsfish\data\food\geb_old_bluetackle.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_old_bluetackle.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      3,
      2
    };
    itemsCargoSize[] = {
      3,
      2
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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
  class OldPurpleTackleBox: Container_Base {
    scope = 2;
    displayName = "Old Purple Tackle Box";
    descriptionShort = "A safe place to put some hooks and sinkers.";
    model = "gebsfish\data\food\geb_old_purpletackle.p3d";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_old_purpletackle.paa";
    };
    rotationFlags = 17;
    weight = 140;
    itemSize[] = {
      3,
      2
    };
    itemsCargoSize[] = {
      3,
      2
    };
    allowOwnedCargoManipulation = 1;
    randomQuantity = 2;
    canBeDigged = 1;
    repairableWithKits[] = {
      2
    };
    repairCosts[] = {
      25
    };
    isMeleeWeapon = 1;
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 80;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\containers\data\FirsAidKit.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
              }
            }
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

  /* 
  
  	HOOKS
  
  */

  class Hook;
  class Inventory_Base;

  class BambooFishingNet : Container_Base {
      scope = 2;
      rotationFlags = 17;
      displayName = "Bamboo Fishing Net";
      descriptionShort = "A safe place to put some bugs, can also be used to catch them! Grasshoppers, Field Crickets, and Grubs!";
      model = "gebsfish\data\food\geb_fishingnet.p3d";
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_fishingnet.paa";
      };
      itemInfo[] =
      {
          "CatchBugs"
      };
      weight = 140;
      itemSize[] = {
        1,
        3
      };
      itemsCargoSize[] = {
        1,
        1
      };
      allowOwnedCargoManipulation = 1;
      randomQuantity = 2;
      canBeDigged = 1;
      repairableWithKits[] = {
        2
      };
      repairCosts[] = {
        25
      };
      isMeleeWeapon = 1;

      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 80;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\containers\data\FirsAidKit.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\containers\data\FirsAidKit_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\containers\data\FirsAidKit_destruct.rvmat"
                      }
                    }
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



  class MetalHookBobber1 : Inventory_Base {
    scope = 2;
    displayName = "Metal Hook and Bobber #1";
    descriptionShort = "A hook with a bobber.";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
     "gebsfish\data\food\geb_metalhook_bobber1.paa";
    };
    model = "gebsfish\data\food\geb_metalhook_bobber1.p3d";
    rotationFlags = 12;
    weight = 1;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
  };
  class MetalHookBobber2 : Inventory_Base {
    scope = 2;
    displayName = "Metal Hook and Bobber #2";
    descriptionShort = "A hook with a bobber.";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
     "gebsfish\data\food\geb_metalhook_bobber2.paa";
    };
    model = "gebsfish\data\food\geb_metalhook_bobber2.p3d";
    rotationFlags = 12;
    weight = 1;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
  };
  class MetalHookBobber3 : Inventory_Base {
    scope = 2;
    displayName = "Metal Hook and Bobber #3";
    descriptionShort = "A hook with a bobber.";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
     "gebsfish\data\food\geb_metalhook_bobber3.paa";
    };
    model = "gebsfish\data\food\geb_metalhook_bobber3.p3d";
    rotationFlags = 12;
    weight = 1;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
  };
  class MetalHookBobber4 : Inventory_Base {
    scope = 2;
    displayName = "Metal Hook and Bobber #4";
    descriptionShort = "A hook with a bobber.";
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
     "gebsfish\data\food\geb_metalhook_bobber4.paa";
    };
    model = "gebsfish\data\food\geb_metalhook_bobber4.p3d";
    rotationFlags = 12;
    weight = 1;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
  };

  class BoneHookBobber1 : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook and Bobber #1";
      descriptionShort = "A hook with a bobber.";
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
       "gebsfish\data\food\geb_bonehook_bobber1.paa";
      };
      model = "gebsfish\data\food\geb_bonehook_bobber1.p3d";
      rotationFlags = 12;
      weight = 1;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
  };
  class BoneHookBobber2 : Inventory_Base {
      scope = 2;
      displayName = "Hook and Bobber #2";
      descriptionShort = "A hook with a bobber.";
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
       "gebsfish\data\food\geb_bonehook_bobber2.paa";
      };
      model = "gebsfish\data\food\geb_bonehook_bobber2.p3d";
      rotationFlags = 12;
      weight = 1;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
  };
  class BoneHookBobber3 : Inventory_Base {
      scope = 2;
      displayName = "Hook and Bobber #3";
      descriptionShort = "A hook with a bobber.";
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
       "gebsfish\data\food\geb_bonehook_bobber3.paa";
      };
      model = "gebsfish\data\food\geb_bonehook_bobber3.p3d";
      rotationFlags = 12;
      weight = 1;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
  };
  class BoneHookBobber4 : Inventory_Base {
      scope = 2;
      displayName = "Hook and Bobber #4";
      descriptionShort = "A hook with a bobber.";
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
       "gebsfish\data\food\geb_bonehook_bobber4.paa";
      };
      model = "gebsfish\data\food\geb_bonehook_bobber4.p3d";
      rotationFlags = 12;
      weight = 1;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
  };

  class MetalHook : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook";
      descriptionShort = "A metal hook!";
      model = "gebsfish\data\food\geb_metalhook.p3d";
      weight = 1;
      absorbency = 0.80000001;
      itemSize[] = { 1,1 };
      inventorySlot[] =
      {
          "Hook"
      };
      rotationFlags = 17;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 10;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\consumables\data\bone_hook.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\consumables\data\bone_hook.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\consumables\data\bone_hook_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\consumables\data\bone_hook_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\consumables\data\bone_hook_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
  };

  /* 
  
  	INSECTS & BAITS
  
  */
  //Bugs
  class Worm;
  class GrassHopper : Worm
	{
		scope=2;
		displayName="Grasshopper";
		descriptionShort="Grasshoppers are a group of insects belonging to the suborder Caelifera. They are among what is probably the most ancient living group of chewing herbivorous insects, dating back to the early Triassic around 250 million years ago.";
		model="gebsfish\data\food\geb_grasshopper.p3d";
		rotationFlags=17;
		weight=21;
		stackedUnit="";
		canBeSplit=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		inventorySlot[]=
		{
			"Trap_Bait"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\""""_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\bait_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\bait.rvmat"
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
			class FoodStageTransitions: NotCookable
			{
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
  class FieldCricket : Worm
    {
        scope = 2;
        displayName = "Field Cricket";
        descriptionShort = "Gryllus is a genus of field cricket (Orthoptera, Gryllidae, Gryllinae). Members of the genus are typically 15–31 mm long and darkly coloured.";
        model = "gebsfish\data\food\geb_fieldcricket.p3d";
        rotationFlags = 17;
        weight = 21;
        stackedUnit = "";
        canBeSplit = 0;
        quantityBar = 0;
        varQuantityInit = 0;
        varQuantityMin = 0;
        varQuantityMax = 0;
        inventorySlot[] =
        {
            "Trap_Bait"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 10;
                    healthLevels[] =
                    {

                        {
                            1,

                            {
                                "DZ\gear\food\data\"""".rvmat"
                            }
                        },

                        {
                            0.69999999,

                            {
                                "DZ\gear\food\data\"""".rvmat"
                            }
                        },

                        {
                            0.5,

                            {
                                "DZ\gear\food\data\""""_damage.rvmat"
                            }
                        },

                        {
                            0.30000001,

                            {
                                "DZ\gear\food\data\""""_damage.rvmat"
                            }
                        },

                        {
                            0,

                            {
                                "DZ\gear\food\data\""""_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        hiddenSelections[] =
        {
            "cs_raw"
        };
        hiddenSelectionsTextures[] =
        {
            "dz\gear\food\data\bait_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "dz\gear\food\data\bait.rvmat"
        };
        class AnimationSources : FoodAnimationSources
        {
        };
        class Food
        {
            class FoodStages
            {
                class Raw
                {
                    visual_properties[] = { 0,0,0 };
                    nutrition_properties[] = { 1,80,8,42,1 };
                    cooking_properties[] = { 0,0 };
                };
            };
            class FoodStageTransitions : NotCookable
            {
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class openTunaCan
                {
                    soundSet = "openTunaCan_SoundSet";
                    id = 204;
                };
                class Eating_TakeFood
                {
                    soundSet = "Eating_TakeFood_Soundset";
                    id = 889;
                };
                class Eating_BoxOpen
                {
                    soundSet = "Eating_BoxOpen_Soundset";
                    id = 893;
                };
                class Eating_BoxShake
                {
                    soundSet = "Eating_BoxShake_Soundset";
                    id = 894;
                };
                class Eating_BoxEnd
                {
                    soundSet = "Eating_BoxEnd_Soundset";
                    id = 895;
                };
            };
        };
    };

  //Retextures
  class GrubWorm: Worm
	{
		scope=2;
		displayName="Grub Worm";
		descriptionShort="The C-shaped larvae, called grubs, are pale yellow or white. Most adult beetles are nocturnal, although the flower chafers (Cetoniinae) and many leaf chafers (Rutelinae) are active during the day. The grubs mostly live underground or under debris, so are not exposed to sunlight. Many scarabs are scavengers that recycle dung, carrion, or decaying plant material.";
		model="\dz\gear\food\bait_worm.p3d";
        hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_grubworm.paa";
        };
		rotationFlags=17;
		weight=21;
		stackedUnit="";
		canBeSplit=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		inventorySlot[]=
		{
			"Trap_Bait"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\""""_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\bait.rvmat"
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
			class FoodStageTransitions: NotCookable
			{
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
  class RubberWorm: Worm
	{
		scope=2;
		displayName="Rubber Worm #1";
		descriptionShort="A rubber worm from the tackle shop!";
		model="\dz\gear\food\bait_worm.p3d";
        hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_rubberworm.paa";
        };
		rotationFlags=17;
		weight=21;
		stackedUnit="";
		canBeSplit=0;
		quantityBar=0;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		inventorySlot[]=
		{
			"Trap_Bait"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\"""".rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\""""_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\""""_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\bait.rvmat"
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={1,80,8,42,1};
					cooking_properties[]={0,0};
				};
			};
			class FoodStageTransitions: NotCookable
			{
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
  
  /*

    BAITS W/ WORM

  */

  class MetalHookBobber1WormBait: Inventory_Base {
    scope = 2;
    displayName = "Metal Hook & Bobber with Worm";
    descriptionShort = "A metal hook with a bobber attached, with a Worm used as bait.";
    model = "gebsfish\data\food\geb_metalhookbobber1_baited_worm.p3d";
    weight = 15;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_metalhookbobber1_baited_worm.paa";
    };
    rotationFlags = 17;
    hookType = "Hook";
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
    class AnimationSources {
      class cover {
        source = "user";
        animPeriod = 0.5;
        initPhase = 1;
      };
    };
  };
  class MetalHookBobber1RubberWormBait: Inventory_Base {
    scope = 2;
    displayName = "Metal Hook & Bobber with RubberWorm";
    descriptionShort = "A metal hook with a bobber attached, with a Rubber Worm used as bait.";
    model = "gebsfish\data\food\geb_metalhookbobber1_baited_rubberworm.p3d";
    weight = 15;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_metalhookbobber1_baited_rubberworm.paa";
    };
    rotationFlags = 17;
    hookType = "MetalHookBobber1";
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
    class AnimationSources {
      class cover {
        source = "user";
        animPeriod = 0.5;
        initPhase = 1;
      };
    };
  };
  class MetalHookBobber1GrubWormBait: Inventory_Base {
    scope = 2;
    displayName = "Metal Hook & Bobber with GrubWorm";
    descriptionShort = "A metal hook with a bobber attached, with a grubworm used as bait.";
    model = "gebsfish\data\food\geb_metalhookbobber1_baited_grubworm.p3d";
    weight = 15;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_metalhookbobber1_baited_grubworm.paa";
    };
    rotationFlags = 17;
    hookType = "MetalHookBobber1";
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
    class AnimationSources {
      class cover {
        source = "user";
        animPeriod = 0.5;
        initPhase = 1;
      };
    };
  };
  class MetalHookBobber1GrassHopperBait: Inventory_Base {
    scope = 2;
    displayName = "Metal Hook & Bobber with Grasshopper";
    descriptionShort = "A metal hook with a bobber attached, with a Grasshopper used as bait.";
    model = "gebsfish\data\food\geb_metalhookbobber1_baited_grasshopper.p3d";
    weight = 15;
    absorbency = 0.80000001;
    itemSize[] = {
      1,
      1
    };
    inventorySlot[] = {
      "Hook"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_metalhookbobber1_baited_grasshopper.paa";
    };
    rotationFlags = 17;
    hookType = "MetalHookBobber1";
    class DamageSystem {
      class GlobalHealth {
        class Health {
          hitpoints = 30;
          healthLevels[] = {

            {
              1,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.69999999,

              {
                "DZ\gear\consumables\data\bait.rvmat"
              }
            },

            {
              0.5,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0.30000001,

              {
                "DZ\gear\consumables\data\bait_damage.rvmat"
              }
            },

            {
              0,

              {
                "DZ\gear\consumables\data\bait_destruct.rvmat"
              }
            }
          };
        };
      };
    };
    class AnimationSources {
      class cover {
        source = "user";
        animPeriod = 0.5;
        initPhase = 1;
      };
    };
  };
  class MetalHookBobber1FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Field Cricket";
      descriptionShort = "A metal hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber1_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber1_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber1MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Minnow";
      descriptionShort = "A metal hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber1_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber1_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class MetalHookBobber2WormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Worm";
      descriptionShort = "A metal hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber2RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with RubberWorm";
      descriptionShort = "A metal hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber2GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with GrubWorm";
      descriptionShort = "A metal hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber2GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Grasshopper";
      descriptionShort = "A metal hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber2FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Field Cricket";
      descriptionShort = "A metal hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber2MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Minnow";
      descriptionShort = "A metal hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber2_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber2_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class MetalHookBobber3WormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Worm";
      descriptionShort = "A metal hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber3RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with RubberWorm";
      descriptionShort = "A metal hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber3GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with GrubWorm";
      descriptionShort = "A metal hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber3GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Grasshopper";
      descriptionShort = "A metal hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber3FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Field Cricket";
      descriptionShort = "A metal hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber3MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Minnow";
      descriptionShort = "A metal hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber3_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber3_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class MetalHookBobber4WormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Worm";
      descriptionShort = "A metal hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber4RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with RubberWorm";
      descriptionShort = "A metal hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber4GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with GrubWorm";
      descriptionShort = "A metal hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber4GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Grasshopper";
      descriptionShort = "A metal hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber4FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Field Cricket";
      descriptionShort = "A metal hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalHookBobber4MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook & Bobber with Minnow";
      descriptionShort = "A metal hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_metalhookbobber4_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhookbobber4_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class MetalRubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Rubber Worm";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalGrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Grub Worm";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalGrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Grasshopper";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalFieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Field Cricket";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalWormBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Worm";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class MetalMinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Metal Hook with Minnow";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_metalhook_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_metalhook_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "MetalHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class BoneHookBobber1WormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Worm";
      descriptionShort = "A bone hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber1RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with RubberWorm";
      descriptionShort = "A bone hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber1GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with GrubWorm";
      descriptionShort = "A bone hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber1GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Grasshopper";
      descriptionShort = "A bone hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber1FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Field Cricket";
      descriptionShort = "A bone hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber1MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Minnow";
      descriptionShort = "A bone hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber1_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber1_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class BoneHookBobber2WormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Worm";
      descriptionShort = "A bone hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber2RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with RubberWorm";
      descriptionShort = "A bone hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber2GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with GrubWorm";
      descriptionShort = "A bone hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber2GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Grasshopper";
      descriptionShort = "A bone hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber2FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Field Cricket";
      descriptionShort = "A bone hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber2MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Minnow";
      descriptionShort = "A bone hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber2_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber2_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class BoneHookBobber3WormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Worm";
      descriptionShort = "A bone hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber3RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with RubberWorm";
      descriptionShort = "A bone hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber3GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with GrubWorm";
      descriptionShort = "A bone hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber3GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Grasshopper";
      descriptionShort = "A bone hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber3FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Field Cricket";
      descriptionShort = "A bone hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber3MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Minnow";
      descriptionShort = "A bone hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber3_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber3_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class BoneHookBobber4WormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Worm";
      descriptionShort = "A bone hook with a bobber attached, with a Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_worm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_worm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber4RubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with RubberWorm";
      descriptionShort = "A bone hook with a bobber attached, with a Rubber Worm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber4GrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with GrubWorm";
      descriptionShort = "A bone hook with a bobber attached, with a grubworm used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber4GrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Grasshopper";
      descriptionShort = "A bone hook with a bobber attached, with a Grasshopper used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber4FieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Field Cricket";
      descriptionShort = "A bone hook with a bobber attached, with a Field Cricket used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneHookBobber4MinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook & Bobber with Minnow";
      descriptionShort = "A bone hook with a bobber attached, with a minnow used as bait.";
      model = "gebsfish\data\food\geb_bonehookbobber4_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehookbobber4_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHookBobber4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class BoneRubberWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook with Rubber Worm";
      descriptionShort = "$STR_CfgVehicles_Bait1";
      model = "gebsfish\data\food\geb_bonehook_baited_rubberworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehook_baited_rubberworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneGrubWormBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook with Grub Worm";
      descriptionShort = "$STR_CfgVehicles_Bait1";
      model = "gebsfish\data\food\geb_bonehook_baited_grubworm.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehook_baited_grubworm.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneGrassHopperBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook with Grasshopper";
      descriptionShort = "$STR_CfgVehicles_Bait1";
      model = "gebsfish\data\food\geb_bonehook_baited_grasshopper.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehook_baited_grasshopper.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneFieldCricketBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook with Field Cricket";
      descriptionShort = "$STR_CfgVehicles_Bait1";
      model = "gebsfish\data\food\geb_bonehook_baited_fieldcricket.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehook_baited_fieldcricket.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class BoneMinnowBait : Inventory_Base {
      scope = 2;
      displayName = "Bone Hook with Minnow";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_bonehook_baited_minnow.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_bonehook_baited_minnow.paa";
      };
      rotationFlags = 17;
      hookType = "BoneHook";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  class SpinnerBait1 : Inventory_Base {
      scope = 2;
      displayName = "Spinner Bait1";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_spinnerbait1.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_spinnerbait1.paa";
      };
      rotationFlags = 17;
      hookType = "SpinnerBait1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class SpinnerBait2 : Inventory_Base {
      scope = 2;
      displayName = "Spinner Bait2";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_spinnerbait2.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_spinnerbait2.paa";
      };
      rotationFlags = 17;
      hookType = "SpinnerBait2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class SpinnerBait3 : Inventory_Base {
      scope = 2;
      displayName = "Spinner Bait3";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_spinnerbait3.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_spinnerbait3.paa";
      };
      rotationFlags = 17;
      hookType = "SpinnerBait3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class SpinnerBait4 : Inventory_Base {
      scope = 2;
      displayName = "Spinner Bait4";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\geb_spinnerbait4.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\geb_spinnerbait4.paa";
      };
      rotationFlags = 17;
      hookType = "SpinnerBait4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };



  class Lure1 : Inventory_Base {
      scope = 2;
      displayName = "Lure 1";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\lure1.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\lure1.paa";
      };
      rotationFlags = 12;
      hookType = "Lure1";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class Lure2 : Inventory_Base {
      scope = 2;
      displayName = "Lure 2";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\lure2.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\lure2.paa";
      };
      rotationFlags = 12;
      hookType = "Lure2";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class Lure3 : Inventory_Base {
      scope = 2;
      displayName = "Lure 3";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\lure3.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\lure3.paa";
      };
      rotationFlags = 12;
      hookType = "Lure3";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };
  class Lure4 : Inventory_Base {
      scope = 2;
      displayName = "Lure 4";
      descriptionShort = "A bait to catch marine life!";
      model = "gebsfish\data\food\lure4.p3d";
      weight = 15;
      absorbency = 0.80000001;
      itemSize[] = {
        1,
        1
      };
      inventorySlot[] = {
        "Hook"
      };
      hiddenSelections[] = {
        "zbytek"
      };
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\lure3.paa";
      };
      rotationFlags = 12;
      hookType = "Lure4";
      class DamageSystem {
          class GlobalHealth {
              class Health {
                  hitpoints = 30;
                  healthLevels[] = {

                    {
                      1,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.69999999,

                      {
                        "DZ\gear\consumables\data\bait.rvmat"
                      }
                    },

                    {
                      0.5,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0.30000001,

                      {
                        "DZ\gear\consumables\data\bait_damage.rvmat"
                      }
                    },

                    {
                      0,

                      {
                        "DZ\gear\consumables\data\bait_destruct.rvmat"
                      }
                    }
                  };
              };
          };
      };
      class AnimationSources {
          class cover {
              source = "user";
              animPeriod = 0.5;
              initPhase = 1;
          };
      };
  };

  /* 
  
  	TOOLS
  
  */

  class HuntingKnife;
  class BlueFishKnife: HuntingKnife
	{
		scope=2;
		displayName="Blue Fillet Knife";
		descriptionShort="A blue fillet knife, good for gutting fish";
		model="gebsfish\data\food\geb_bluefishknife.p3d";
		inventorySlot[]=
		{
			"Knife"
		};
		repairableWithKits[]={4};
		repairCosts[]={10};
		rotationFlags=17;
		RestrainUnlockType=1;
		canSkinBodies=1;
		weight=200;
		itemSize[]={1,3};
		lootTag[]=
		{
			"Hunting",
			"Camping"
		};
		lootCategory="Tools";
		itemInfo[]=
		{
			"Knife"
		};
		openItemSpillRange[]={10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeKnife";
				range=1.2;
			};
			class Heavy
			{
				ammo="MeleeKnife_Heavy";
				range=1.2;
			};
			class Sprint
			{
				ammo="MeleeKnife_Heavy";
				range=3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
				class CutTies_end
				{
					soundSet="CutTies_end_SoundSet";
					id=519;
				};
				class CutTies_loop
				{
					soundSet="CutTies_loop_SoundSet";
					id=520;
				};
				class shaving_knife_clean
				{
					soundSet="shaving_knife_clean_SoundSet";
					id=600;
				};
				class shaving_knife1
				{
					soundSet="shaving_knife1_SoundSet";
					id=601;
				};
				class shaving_knife2
				{
					soundSet="shaving_knife2_SoundSet";
					id=602;
				};
				class shaving_knife3
				{
					soundSet="shaving_knife3_SoundSet";
					id=603;
				};
				class shaving_knife4
				{
					soundSet="shaving_knife4_SoundSet";
					id=604;
				};
				class shaving_knife5
				{
					soundSet="shaving_knife5_SoundSet";
					id=605;
				};
				class shaving_knife6
				{
					soundSet="shaving_knife6_SoundSet";
					id=606;
				};
				class shaving_knife7
				{
					soundSet="shaving_knife7_SoundSet";
					id=607;
				};
				class shaving_knife8
				{
					soundSet="shaving_knife8_SoundSet";
					id=608;
				};
				class shaving_knife9
				{
					soundSet="shaving_knife9_SoundSet";
					id=609;
				};
				class shaving_knife10
				{
					soundSet="shaving_knife10_SoundSet";
					id=610;
				};
				class shaving_knife11
				{
					soundSet="shaving_knife11_SoundSet";
					id=611;
				};
				class shaving_knife12
				{
					soundSet="shaving_knife12_SoundSet";
					id=612;
				};
				class shaving_knife13
				{
					soundSet="shaving_knife13_SoundSet";
					id=613;
				};
				class shaving_knife14
				{
					soundSet="shaving_knife14_SoundSet";
					id=614;
				};
				class shaving_knife15
				{
					soundSet="shaving_knife15_SoundSet";
					id=615;
				};
				class shaving_knife16
				{
					soundSet="shaving_knife16_SoundSet";
					id=616;
				};
				class shaving_knife17
				{
					soundSet="shaving_knife17_SoundSet";
					id=617;
				};
				class shaving_knife18
				{
					soundSet="shaving_knife18_SoundSet";
					id=618;
				};
				class shaving_knife19
				{
					soundSet="shaving_knife19_SoundSet";
					id=619;
				};
				class shaving_knife20
				{
					soundSet="shaving_knife20_SoundSet";
					id=620;
				};
				class shaving_knife21
				{
					soundSet="shaving_knife21_SoundSet";
					id=621;
				};
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
			};
		};
	};
  class OrangeFishKnife: HuntingKnife
	{
		scope=2;
		displayName="Orange Fillet Knife";
		descriptionShort="An orange fillet knife, good for gutting fish";
		model="gebsfish\data\food\geb_orangefishknife.p3d";
		inventorySlot[]=
		{
			"Knife"
		};
		repairableWithKits[]={4};
		repairCosts[]={10};
		rotationFlags=17;
		RestrainUnlockType=1;
		canSkinBodies=1;
		weight=200;
		itemSize[]={1,3};
		lootTag[]=
		{
			"Hunting",
			"Camping"
		};
		lootCategory="Tools";
		itemInfo[]=
		{
			"Knife"
		};
		openItemSpillRange[]={10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeKnife";
				range=1.2;
			};
			class Heavy
			{
				ammo="MeleeKnife_Heavy";
				range=1.2;
			};
			class Sprint
			{
				ammo="MeleeKnife_Heavy";
				range=3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet="animalSkinning_in_SoundSet";
					id=516;
				};
				class animalSkinning
				{
					soundSet="animalSkinning_SoundSet";
					id=517;
				};
				class animalSkinning_out
				{
					soundSet="animalSkinning_out_SoundSet";
					id=518;
				};
				class CutTies_end
				{
					soundSet="CutTies_end_SoundSet";
					id=519;
				};
				class CutTies_loop
				{
					soundSet="CutTies_loop_SoundSet";
					id=520;
				};
				class shaving_knife_clean
				{
					soundSet="shaving_knife_clean_SoundSet";
					id=600;
				};
				class shaving_knife1
				{
					soundSet="shaving_knife1_SoundSet";
					id=601;
				};
				class shaving_knife2
				{
					soundSet="shaving_knife2_SoundSet";
					id=602;
				};
				class shaving_knife3
				{
					soundSet="shaving_knife3_SoundSet";
					id=603;
				};
				class shaving_knife4
				{
					soundSet="shaving_knife4_SoundSet";
					id=604;
				};
				class shaving_knife5
				{
					soundSet="shaving_knife5_SoundSet";
					id=605;
				};
				class shaving_knife6
				{
					soundSet="shaving_knife6_SoundSet";
					id=606;
				};
				class shaving_knife7
				{
					soundSet="shaving_knife7_SoundSet";
					id=607;
				};
				class shaving_knife8
				{
					soundSet="shaving_knife8_SoundSet";
					id=608;
				};
				class shaving_knife9
				{
					soundSet="shaving_knife9_SoundSet";
					id=609;
				};
				class shaving_knife10
				{
					soundSet="shaving_knife10_SoundSet";
					id=610;
				};
				class shaving_knife11
				{
					soundSet="shaving_knife11_SoundSet";
					id=611;
				};
				class shaving_knife12
				{
					soundSet="shaving_knife12_SoundSet";
					id=612;
				};
				class shaving_knife13
				{
					soundSet="shaving_knife13_SoundSet";
					id=613;
				};
				class shaving_knife14
				{
					soundSet="shaving_knife14_SoundSet";
					id=614;
				};
				class shaving_knife15
				{
					soundSet="shaving_knife15_SoundSet";
					id=615;
				};
				class shaving_knife16
				{
					soundSet="shaving_knife16_SoundSet";
					id=616;
				};
				class shaving_knife17
				{
					soundSet="shaving_knife17_SoundSet";
					id=617;
				};
				class shaving_knife18
				{
					soundSet="shaving_knife18_SoundSet";
					id=618;
				};
				class shaving_knife19
				{
					soundSet="shaving_knife19_SoundSet";
					id=619;
				};
				class shaving_knife20
				{
					soundSet="shaving_knife20_SoundSet";
					id=620;
				};
				class shaving_knife21
				{
					soundSet="shaving_knife21_SoundSet";
					id=621;
				};
				class pickup_light
				{
					soundSet="hatchet_pickup_light_SoundSet";
					id=796;
				};
				class pickup
				{
					soundSet="hatchet_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="woodaxe_drop_SoundSet";
					id=898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet="FirefighterAxe_loop_SoundSet";
					id=1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet="FirefighterAxe_end_SoundSet";
					id=1122;
				};
			};
		};
	};
  class GreenFishKnife : HuntingKnife
    {
        scope = 2;
        displayName = "Green Fillet Knife";
        descriptionShort = "An green fillet knife, good for gutting fish";
        model = "gebsfish\data\food\geb_greenfishknife.p3d";
        inventorySlot[] =
        {
            "Knife"
        };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 10 };
        rotationFlags = 17;
        RestrainUnlockType = 1;
        canSkinBodies = 1;
        weight = 200;
        itemSize[] = { 1,3 };
        lootTag[] =
        {
            "Hunting",
            "Camping"
        };
        lootCategory = "Tools";
        itemInfo[] =
        {
            "Knife"
        };
        openItemSpillRange[] = { 10,20 };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                    healthLevels[] =
                    {

                        {
                            1,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.69999999,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.5,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0.30000001,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        isMeleeWeapon = 1;
        suicideAnim = "onehanded";
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeKnife";
                range = 1.2;
            };
            class Heavy
            {
                ammo = "MeleeKnife_Heavy";
                range = 1.2;
            };
            class Sprint
            {
                ammo = "MeleeKnife_Heavy";
                range = 3.3;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
        };
    };
  class YellowFishKnife : HuntingKnife
    {
        scope = 2;
        displayName = "Yellow Fillet Knife";
        descriptionShort = "An yellow fillet knife, good for gutting fish";
        model = "gebsfish\data\food\geb_yellowfishknife.p3d";
        inventorySlot[] =
        {
            "Knife"
        };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 10 };
        rotationFlags = 17;
        RestrainUnlockType = 1;
        canSkinBodies = 1;
        weight = 200;
        itemSize[] = { 1,3 };
        lootTag[] =
        {
            "Hunting",
            "Camping"
        };
        lootCategory = "Tools";
        itemInfo[] =
        {
            "Knife"
        };
        openItemSpillRange[] = { 10,20 };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                    healthLevels[] =
                    {

                        {
                            1,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.69999999,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.5,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0.30000001,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        isMeleeWeapon = 1;
        suicideAnim = "onehanded";
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeKnife";
                range = 1.2;
            };
            class Heavy
            {
                ammo = "MeleeKnife_Heavy";
                range = 1.2;
            };
            class Sprint
            {
                ammo = "MeleeKnife_Heavy";
                range = 3.3;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
        };
    };
  class RedFishKnife : HuntingKnife
    {
        scope = 2;
        displayName = "Red Fillet Knife";
        descriptionShort = "An red fillet knife, good for gutting fish";
        model = "gebsfish\data\food\geb_redfishknife.p3d";
        inventorySlot[] =
        {
            "Knife"
        };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 10 };
        rotationFlags = 17;
        RestrainUnlockType = 1;
        canSkinBodies = 1;
        weight = 200;
        itemSize[] = { 1,3 };
        lootTag[] =
        {
            "Hunting",
            "Camping"
        };
        lootCategory = "Tools";
        itemInfo[] =
        {
            "Knife"
        };
        openItemSpillRange[] = { 10,20 };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                    healthLevels[] =
                    {

                        {
                            1,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.69999999,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.5,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0.30000001,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        isMeleeWeapon = 1;
        suicideAnim = "onehanded";
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeKnife";
                range = 1.2;
            };
            class Heavy
            {
                ammo = "MeleeKnife_Heavy";
                range = 1.2;
            };
            class Sprint
            {
                ammo = "MeleeKnife_Heavy";
                range = 3.3;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
        };
    };
  class PurpleFishKnife : HuntingKnife
    {
        scope = 2;
        displayName = "Purple Fillet Knife";
        descriptionShort = "An purple fillet knife, good for gutting fish";
        model = "gebsfish\data\food\geb_purplefishknife.p3d";
        inventorySlot[] =
        {
            "Knife"
        };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 10 };
        rotationFlags = 17;
        RestrainUnlockType = 1;
        canSkinBodies = 1;
        weight = 200;
        itemSize[] = { 1,3 };
        lootTag[] =
        {
            "Hunting",
            "Camping"
        };
        lootCategory = "Tools";
        itemInfo[] =
        {
            "Knife"
        };
        openItemSpillRange[] = { 10,20 };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                    healthLevels[] =
                    {

                        {
                            1,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.69999999,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
                            }
                        },

                        {
                            0.5,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0.30000001,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
                            }
                        },

                        {
                            0,

                            {
                                "DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        isMeleeWeapon = 1;
        suicideAnim = "onehanded";
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeKnife";
                range = 1.2;
            };
            class Heavy
            {
                ammo = "MeleeKnife_Heavy";
                range = 1.2;
            };
            class Sprint
            {
                ammo = "MeleeKnife_Heavy";
                range = 3.3;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
        };
    };

  class FishingRod_Base_New;
  class FishingRod : FishingRod_Base_New
    {
        hiddenSelections[] =
        {
            "zbytek"
        };
        hiddenSelectionsTextures[] =
        {
            "\DZ\gear\tools\data\fishing_rod_co.paa"
        };
   }; 
  class RedFishingRod: FishingRod {
    scope = 2;
    displayName = "Red Fishing Rod";
    descriptionShort = "$STR_CfgVehicles_FishingRod1";
    model = "\dz\gear\tools\fishing_rod.p3d";
    debug_ItemCategory = 2;
    rotationFlags = 12;
    weight = 910;
    itemSize[] = {
      2,
      5
    };
    absorbency = 0;
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingrod_red.paa";
    };
  };
  class GreenFishingRod: FishingRod {
    scope = 2;
    displayName = "Green Fishing Rod";
    descriptionShort = "$STR_CfgVehicles_FishingRod1";
    model = "\dz\gear\tools\fishing_rod.p3d";
    debug_ItemCategory = 2;
    rotationFlags = 12;
    weight = 910;
    itemSize[] = {
      2,
      5
    };
    absorbency = 0;
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingrod_green.paa";
    };
  };
  class BlueFishingRod: FishingRod {
    scope = 2;
    displayName = "Blue Fishing Rod";
    descriptionShort = "$STR_CfgVehicles_FishingRod1";
    model = "\dz\gear\tools\fishing_rod.p3d";
    debug_ItemCategory = 2;
    rotationFlags = 12;
    weight = 910;
    itemSize[] = {
      2,
      5
    };
    absorbency = 0;
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingrod_blue.paa";
    };
  };
  class PurpleFishingRod: FishingRod {
    scope = 2;
    displayName = "Purple Fishing Rod";
    descriptionShort = "$STR_CfgVehicles_FishingRod1";
    model = "\dz\gear\tools\fishing_rod.p3d";
    debug_ItemCategory = 2;
    rotationFlags = 12;
    weight = 910;
    itemSize[] = {
      2,
      5
    };
    absorbency = 0;
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingrod_purple.paa";
    };
  };  /* 
  
  	ITEMS
  
  */

  class Rope;
  class BigGameFishingline: Rope {
    scope = 2;
    displayName = "Big Game Fishing Line";
    descriptionShort = "Catch a ton of bass with this line! Used to craft makeshift fishing pole, or possibly used as a string.";
    model = "gebsfish\data\food\geb_fishingline_biggame.p3d";
    OnRestrainChange = "RopeLocked";
    RestrainTime = 10;
    rotationFlags = 17;
    itemSize[] = {
      2,
      2
    };
    inventorySlot[] = {
      "Rope",
      "Material_FPole_Rope",
      "Material_Shelter_Rope"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingline_biggame.paa";
    };
  };
  class SaltwaterFishingLine: Rope {
    scope = 2;
    displayName = "Salt Water Fishing Line";
    descriptionShort = "Good fishing line for the ocean! Used to craft makeshift fishing pole, or possibly used as a string.";
    model = "gebsfish\data\food\geb_fishingline_saltwater.p3d";
    OnRestrainChange = "RopeLocked";
    RestrainTime = 10;
    rotationFlags = 17;
    itemSize[] = {
      2,
      2
    };
    inventorySlot[] = {
      "Rope",
      "Material_FPole_Rope",
      "Material_Shelter_Rope"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingline_saltwater.paa";
    };
  };
  class FlyFishingLine: Rope {
    scope = 2;
    displayName = "Fly Fishing Line";
    descriptionShort = "A pretty good spool of fly fishing line, great for trout! Used to craft makeshift fishing pole, or possibly used as a string.";
    model = "gebsfish\data\food\geb_fishingline_flyfishing.p3d";
    OnRestrainChange = "RopeLocked";
    RestrainTime = 10;
    rotationFlags = 17;
    itemSize[] = {
      2,
      2
    };
    inventorySlot[] = {
      "Rope",
      "Material_FPole_Rope",
      "Material_Shelter_Rope"
    };
    hiddenSelections[] = {
      "zbytek"
    };
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\geb_fishingline_flyfishing.paa";
    };

  };


  class Bobber1 : Inventory_Base
  {
      scope = 2;
      displayName = "Bobber 1";
      descriptionShort = "A fishing bobber. Can be combined with a hook to create a hook and bobber.";
      model = "gebsfish\data\food\geb_bobber1.p3d";
      animClass = "NoFireClass";
      weight = 50;
      itemSize[] = { 1,1 };
      rotationFlags = 17;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 100;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\consumables\data\stone_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
  };
  class Bobber2 : Inventory_Base
  {
      scope = 2;
      displayName = "Bobber 2";
      descriptionShort = "A fishing bobber. Can be combined with a hook to create a hook and bobber.";
      model = "gebsfish\data\food\geb_bobber2.p3d";
      animClass = "NoFireClass";
      weight = 50;
      itemSize[] = { 1,1 };
      rotationFlags = 17;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 100;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\consumables\data\stone_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
  };
  class Bobber3 : Inventory_Base
  {
      scope = 2;
      displayName = "Bobber 3";
      descriptionShort = "A fishing bobber. Can be combined with a hook to create a hook and bobber.";
      model = "gebsfish\data\food\geb_bobber3.p3d";
      animClass = "NoFireClass";
      weight = 50;
      itemSize[] = { 1,1 };
      rotationFlags = 17;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 100;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\consumables\data\stone_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
  };
  class Bobber4 : Inventory_Base
  {
      scope = 2;
      displayName = "Bobber 4";
      descriptionShort = "A fishing bobber. Can be combined with a hook to create a hook and bobber.";
      model = "gebsfish\data\food\geb_bobber4.p3d";
      animClass = "NoFireClass";
      weight = 50;
      itemSize[] = { 1,1 };
      rotationFlags = 17;
      class DamageSystem
      {
          class GlobalHealth
          {
              class Health
              {
                  hitpoints = 100;
                  healthLevels[] =
                  {

                      {
                          1,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.69999999,

                          {
                              "DZ\gear\consumables\data\stone.rvmat"
                          }
                      },

                      {
                          0.5,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0.30000001,

                          {
                              "DZ\gear\consumables\data\stone_damage.rvmat"
                          }
                      },

                      {
                          0,

                          {
                              "DZ\gear\consumables\data\stone_destruct.rvmat"
                          }
                      }
                  };
              };
          };
      };
  };

  /* 
  
  	FISH
  
  */
  
  //Freshwater Fish
  class Carp;
  class Bluegill: Edible_Base {
    scope = 2;
    displayName = "Bluegill";
    descriptionShort = "Bluegills can grow up to 12 inches (30 cm) long and about 4+1⁄2 pounds (2.0 kg). While their color can vary from population to population, they typically have a very distinctive coloring, with deep blue and purple on the face and gill cover, dark olive-colored bands down the side, and a fiery orange to yellow belly. The fish are omnivores and will eat anything they can fit in their mouth. They mostly feed on small aquatic insects and fish. The fish play a key role in the food chain, and are prey for bass, other sunfish, northern pike, walleye, muskies, trout, and snapping turtles";
    model = "gebsfish\data\food\bluegill.p3d";
    itemSize[] = {
      3,
      2
    };
    weight = 1700;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Blackbass: Edible_Base {
    scope = 2;
    displayName = "Black Bass";
    descriptionShort = "Black bass of all species are highly sought-after game fish, and bass fishing is an extremely popular sport. These fish are well known as strong fighters, and taste good.";
    model = "gebsfish\data\food\blackbass.p3d";
    itemSize[] = {
      5,
      2
    };
    weight = 1700;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Catfish: Edible_Base {
    scope = 2;
    displayName = "Catfish";
    descriptionShort = "Catfish belong to the bony fish order Siluriformes, and are mainly freshwater forms with representatives throughout the world. Most species of catfish lack scales, although some species are covered with heavy plates of tough, armored skin.";
    model = "gebsfish\data\food\catfish.p3d";
    itemSize[] = {
      7,
      2
    };
    weight = 4000;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Largemouthbass: Edible_Base {
    scope = 2;
    displayName = "Large Mouth Bass";
    descriptionShort = "The Large Mouth Bass is a carnivorous freshwater gamefish in the sunfish family, a species of black bass native to the eastern and central United States, southeastern Canada and northern Mexico, but widely introduced elsewhere.";
    model = "gebsfish\data\food\largemouthbass.p3d";
    itemSize[] = {
      5,
      2
    };
    weight = 1700;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Minnow: Edible_Base {
    scope = 2;
    displayName = "Minnow";
    descriptionShort = "The common minnow is a small fish which reaches a maximum total length of 14 centimetres (5+1⁄2 in), but is normally around 7 centimetres (3 in) in length. It has 3 spines and 6–8 soft rays in its dorsal fin with 3 spines and 6–8 soft rays in its anal fin.";
    model = "gebsfish\data\food\minnow.p3d";
    itemSize[] = {
      1,
      1
    };
    weight = 300;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Northernpike: Edible_Base {
    scope = 2;
    displayName = "Northernpike";
    descriptionShort = "The northernpike is a species of carnivorous fish of the genus Esox. They are typical of brackish and fresh waters of the Northern Hemisphere.";
    model = "gebsfish\data\food\northernpike.p3d";
    itemSize[] = {
      6,
      2
    };
    weight = 4000;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Perch: Edible_Base {
    scope = 2;
    displayName = "Perch";
    descriptionShort = "Perch are a popular sport fish species. They are known to put up a fight, and to be good for eating. They can be caught with a variety of methods, including float fishing, lure fishing, and legering. Fly fishing for perch using patterns that imitate small fry or invertebrates can be successful.";
    model = "gebsfish\data\food\perch.p3d";
    itemSize[] = {
      4,
      3
    };
    weight = 3000;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Sauger: Edible_Base {
    scope = 2;
    displayName = "Sauger";
    descriptionShort = "The Sauger is a freshwater perciform fish of the family Percidae that resembles its close relative, the walleye. The species is a member of the largest vertebrate order, the Perciformes. It is the most migratory percid species in North America.";
    model = "gebsfish\data\food\sauger.p3d";
    itemSize[] = {
      4,
      1
    };
    weight = 1500;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Crayfish: Edible_Base {
    scope = 2;
    displayName = "Crayfish";
    descriptionShort = "Crayfish are freshwater crustaceans resembling small lobsters (to which they are related). In some locations, they are also known as crawfish, craydids, crawdaddies, crawdads, freshwater lobsters, mountain lobsters, rock lobsters, mudbugs, or yabbies. Taxonomically, they are members of the superfamilies Astacoidea and Parastacoidea. They breathe through feather-like gills!";
    model = "gebsfish\data\food\Crayfish.p3d";
    itemSize[] = {
      2,
      1
    };
    weight = 200;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Trout: Edible_Base {
    scope = 2;
    displayName = "Trout";
    descriptionShort = "Trout are an important food source for humans and wildlife, including brown bears, birds of prey such as eagles, and other animals. They are classified as oily fish.";
    model = "gebsfish\data\food\trout.p3d";
    itemSize[] = {
      5,
      2
    };
    weight = 1700;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Whitebass: Edible_Base {
    scope = 2;
    displayName = "White Bass";
    descriptionShort = "The White Bass is a freshwater fish of the temperate bass family Moronidae. The species' main color is silver-white to pale green. Its back is dark, with white sides and belly, and with narrow dark stripes running lengthwise on its sides. It has large, rough scales and two dorsal fins. The more anterior dorsal fin is much harder and appears to have spines on them. Although these are not true spines, this type of fin is called a spinous ray. The more posterior of the two dorsal fins is much softer, and is thus called a soft-ray.";
    model = "gebsfish\data\food\whitebass.p3d";
    itemSize[] = {
      5,
      2
    };
    weight = 1700;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Bowfin: Edible_Base {
    scope = 2;
    displayName = "Bowfin";
    descriptionShort = "The bowfin is a bony fish, native to North America. Common names include mudfish, mud pike, dogfish, grindle, grinnel, swamp trout, and choupique. It is regarded a relict, being the sole surviving species of the Halecomorphi, a group of fish that first appeared during the Early Triassic, around 250 million years ago.";
    model = "gebsfish\data\food\bowfin.p3d";
    itemSize[] = {
      4,
      2
    };
    weight = 1500;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  class Slimysculpin: Edible_Base {
    scope = 2;
    displayName = "Slimy Sculpin";
    descriptionShort = "The slimy sculpin is a freshwater species of fish belonging to the family Cottidae, which is the largest sculpin family. They usually inhabit cold rocky streams or lakes across North America, ranging from the Great Lakes, southeast Minnesota, northeast Iowa, southwest Wisconsin and northeast Canada.";
    model = "gebsfish\data\food\slimysculpin.p3d";
    itemSize[] = {
      2,
      1
    };
    weight = 300;
    debug_ItemCategory = 6;
    rotationFlags = 17;
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\carp_live_co.paa",
      "dz\gear\food\data\carp_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\carp_live.rvmat",
      "dz\gear\food\data\carp_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            20,
            60,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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

  //Saltwater Fish
  class Angelfish: Edible_Base {
    scope = 2;
    displayName = "Angel Fish";
    descriptionShort = "Angel Fish, particularly tilapia, are important food fishes, while others, such as the Cichla species, are valued game fish. The family also includes many popular freshwater aquarium fish kept by hobbyists, including the angelfish, oscars, and discus.";
    model = "gebsfish\data\food\angelfish.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 2500;
    itemSize[] = {
      4,
      3
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Asianseabass: Edible_Base {
    scope = 2;
    displayName = "Asian Sea Bass";
    descriptionShort = "The barramundi or Asian sea bass, is a species of catadromous fish in the family Latidae of the order Perciformes. The species is widely distributed in the Indo-West Pacific region from South Asia to Papua New Guinea and Northern Australia. ";
    model = "gebsfish\data\food\asianseabass.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 1700;
    itemSize[] = {
      5,
      2
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Bluemarlin: Edible_Base {
    scope = 2;
    displayName = "Blue Marlin";
    descriptionShort = "Blue marlin are distributed throughout the tropical and subtropical waters of the Atlantic Ocean. A bluewater fish that spends the majority of its life in the open sea far from land,[2] the blue marlin preys on a wide variety of marine organisms, mostly near the surface, often using its bill to stun or injure its prey. Way too heavy to carry!";
    model = "gebsfish\data\food\bluemarlin.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 3700;
    itemSize[] = {
      6,
      2
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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

  }
  class Bonita: Edible_Base {
    scope = 2;
    displayName = "Bonita Fish";
    descriptionShort = "Bonitos are a tribe of medium-sized, ray-finned predatory fish in the family Scombridae – a family it shares with the mackerel, tuna, and Spanish mackerel tribes, and also the butterfly kingfish.";
    model = "gebsfish\data\food\bonita.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 1700;
    itemSize[] = {
      5,
      2
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Cherrysalmon: Edible_Base {
    scope = 2;
    displayName = "Cherry Salmon";
    descriptionShort = "The masu salmon, also known as masu or cherry trout in Japan, is a species of salmon belonging to the genus Oncorhynchus, found in the North Pacific along Northeast/East Asian coasts from the Russian Far East to south through Korea, Japan and Taiwan.";
    model = "gebsfish\data\food\cherrysalmon.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 1700;
    itemSize[] = {
      5,
      2
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Flatheadmullet: Edible_Base {
    scope = 2;
    displayName = "Flathead Mullet";
    descriptionShort = "The flathead grey mullet is an important food fish species in the mullet family Mugilidae. It is found in coastal tropical and subtropical waters worldwide. Its length is typically 30 to 75 centimetres. ";
    model = "gebsfish\data\food\flatheadmullet.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 1000;
    itemSize[] = {
      2,
      1
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Leopardshark: Edible_Base {
    scope = 2;
    displayName = "Leopard Shark";
    descriptionShort = "The Leopard shark (Triakis semifasciata) is a species of houndshark, in the family Triakidae. Typically measuring 1.2–1.5 m (3.9–4.9 ft) long, this slender-bodied shark is immediately identifiable by the striking pattern of black saddle-like markings and large spots over its back, from which it derives its common name. Way too heavy to carry!";
    model = "gebsfish\data\food\leopardshark.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 8000;
    itemSize[] = {
      10,
      4
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Pacificcod: Edible_Base {
    scope = 2;
    displayName = "Pacific Cod";
    descriptionShort = "The Pacific cod, Gadus macrocephalus, is a species of ray-finned fish in the family Gadidae. It is a bottom-dwelling fish found in the northern Pacific Ocean, mainly on the continental shelf and upper slopes, to depths of about 900 m. It can grow to a length of a meter or so and is found in large schools. ";
    model = "gebsfish\data\food\pacificcod.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 1700;
    itemSize[] = {
      5,
      2
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Redheadcichlid: Edible_Base {
    scope = 2;
    displayName = "Red Head Cichlid";
    descriptionShort = "Vieja melanurus, the quetzal cichlid, redhead cichlid or firehead cichlid, is a species of cichlid that is native to the Lake Petén system, the Grijalva–Usumacinta River basin and other Atlantic river drainages in southern Mexico, Belize and Guatemala, with introduced populations in a few other countries.";
    model = "gebsfish\data\food\redheadcichlid.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 3000;
    itemSize[] = {
      4,
      3
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Roughneckrock: Edible_Base {
    scope = 2;
    displayName = "Roughneck Rock Fish";
    descriptionShort = "The rougheye rockfish (Sebastes aleutianus) is a rockfish of the genus Sebastes. It is also known as the blackthroat rockfish or the blacktip rockfish and grows to a maximum of about 97 cm ";
    model = "gebsfish\data\food\roughneckrock.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 3000;
    itemSize[] = {
      4,
      3
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Severum: Edible_Base {
    scope = 2;
    displayName = "Severum Fish";
    descriptionShort = "Heros severus, is a species of tropical freshwater cichlid native to the upper Orinoco and upper Rio Negro basins in South America. It has historically been confused with several other species in the genus, most recently H. liberifer. This species is rarely found in the aquarium trade.";
    model = "gebsfish\data\food\severum.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 3600;
    itemBehaviour = 0;
    itemSize[] = {
      5,
      4
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Shrimp: Edible_Base {
    scope = 2;
    displayName = "Shrimp";
    descriptionShort = "Shrimp are decapod crustaceans with elongated bodies and a primarily swimming mode of locomotion – most commonly Caridea and Dendrobranchiata. More narrow definitions may be restricted to Caridea, to smaller species of either group or to only the marine species.";
    model = "gebsfish\data\food\shrimp.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 200;
    itemSize[] = {
      2,
      1
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Bluetang: Edible_Base {
    scope = 2;
    displayName = "Blue Tang";
    descriptionShort = "Paracanthurus hepatus is a species of Indo-Pacific surgeonfish. A popular fish in marine aquaria, it is the only member of the genus Paracanthurus.";
    model = "gebsfish\data\food\bluetang.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 2000;
    itemSize[] = {
      4,
      3
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Hairtailfish: Edible_Base {
    scope = 2;
    displayName = "Hair Tail Fish";
    descriptionShort = "The largehead hairtail or beltfish is a member of the cutlassfish family, Trichiuridae. This common to abundant species is found in tropical and temperate oceans throughout the world.";
    model = "gebsfish\data\food\hairtailfish.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 800;
    itemSize[] = {
      4,
      1
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Humpheadwrasse: Edible_Base {
    scope = 2;
    displayName = "Humphead Wrasse";
    descriptionShort = "The humphead wrasse is a large species of wrasse mainly found on coral reefs in the Indo-Pacific region. It is also known as the Māori wrasse, Napoleon wrasse, Napoleon fish, Napoleonfish, so mei 蘇眉, mameng, and merer in the Pohnpeian language of the Caroline Islands.";
    model = "gebsfish\data\food\humpheadwrasse.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 3500;
    itemSize[] = {
      5,
      4
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }
  class Siamesetigerfish: Edible_Base {
    scope = 2;
    displayName = "Siamese Tiger Fish";
    descriptionShort = "The Siamese tigerfish, also known as the Siamese tiger perch, is a critically endangered Asian fish native to the Chao Phraya, Mae Klong and Mekong basins. It has vertical yellow and black stripes running the length of its body. The dorsal fin has a spiny appearance. Siamese tigerfish grow to 40 cm in standard length.";
    model = "gebsfish\data\food\siamesetigerfish.p3d";
    debug_ItemCategory = 6;
    rotationFlags = 17;
    weight = 2500;
    itemSize[] = {
      3,
      3
    };
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
          healthLevels[] = {

            {
              1,
              {}
            },

            {
              0.69999999,
              {}
            },

            {
              0.5,
              {}
            },

            {
              0.30000001,
              {}
            },

            {
              0,
              {}
            }
          };
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
    inventorySlot[] = {
      "TrapPrey_1"
    };
    hiddenSelections[] = {
      "cs_raw"
    };
    hiddenSelectionsTextures[] = {
      "dz\gear\food\data\mackerel_live_co.paa",
      "dz\gear\food\data\mackerel_live_co.paa"
    };
    hiddenSelectionsMaterials[] = {
      "dz\gear\food\data\mackerel_live.rvmat",
      "dz\gear\food\data\mackerel_live.rvmat"
    };
    class AnimationSources: FoodAnimationSources {};
    class Food {
      class FoodStages {
        class Raw {
          visual_properties[] = {
            0,
            0,
            0
          };
          nutrition_properties[] = {
            1,
            69,
            172,
            70,
            1
          };
          cooking_properties[] = {
            0,
            0
          };
        };
        class Rotten {
          visual_properties[] = {
            -1,
            -1,
            5
          };
          nutrition_properties[] = {
            10,
            25,
            25,
            1,
            0
          };
          cooking_properties[] = {
            0,
            0
          };
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
  }




  //Crusts Fish
  class Bloodclam : Edible_Base {
      scope = 2;
      displayName = "Blood Clam";
      descriptionShort = "Clams have two shells of equal size connected by two adductor muscles and have a powerful burrowing foot. They live in both freshwater and marine environments; in salt water they prefer to burrow down into the mud and the turbidity of the water required varies with species and location; the greatest diversity of these is in North America.";
      model = "gebsfish\data\food\bloodclam.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 100;
      itemSize[] = {
        1,
        1
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Mussel : Edible_Base {
      scope = 2;
      displayName = "Mussel";
      descriptionShort = "Mussel is the common name used for members of several families of bivalve molluscs, from saltwater and freshwater habitats. These groups have in common a shell whose outline is elongated and asymmetrical compared with other edible clams, which are often more or less rounded or oval.";
      model = "gebsfish\data\food\mussel.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 100;
      itemSize[] = {
        1,
        1
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Blackdevilsnail : Edible_Base {
      scope = 2;
      displayName = "Black Devil Snail";
      descriptionShort = "A common freshwater snail.";
      model = "gebsfish\data\food\blackdevilsnail.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 100;
      itemSize[] = {
        1,
        1
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Starfish : Edible_Base {
      scope = 2;
      displayName = "Starfish";
      descriptionShort = "A common starfish.";
      model = "gebsfish\data\food\starfish.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 2500;
      itemSize[] = {
        2,
        2
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Kingcrab : Edible_Base {
      scope = 2;
      displayName = "King Crab";
      descriptionShort = "A Kingcrab.";
      model = "gebsfish\data\food\kingcrab.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 3000;
      itemSize[] = {
        3,
        3
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Jellyfish : Edible_Base {
      scope = 2;
      displayName = "Jellyfish";
      descriptionShort = "A Jellyfish.";
      model = "gebsfish\data\food\jellyfish.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 500;
      itemSize[] = {
        2,
        2
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }
  class Lobster : Edible_Base {
      scope = 2;
      displayName = "Lobster";
      descriptionShort = "A Lobster. DEVELOPMENT";
      model = "gebsfish\data\food\lobster.p3d";
      debug_ItemCategory = 6;
      rotationFlags = 17;
      weight = 3000;
      itemSize[] = {
        3,
        2
      };
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
                  healthLevels[] = {

                    {
                      1,
                      {}
                    },

                    {
                      0.69999999,
                      {}
                    },

                    {
                      0.5,
                      {}
                    },

                    {
                      0.30000001,
                      {}
                    },

                    {
                      0,
                      {}
                    }
                  };
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
      inventorySlot[] = {
        "TrapPrey_1"
      };
      hiddenSelections[] = {
        "cs_raw"
      };
      hiddenSelectionsTextures[] = {
        "dz\gear\food\data\mackerel_live_co.paa",
        "dz\gear\food\data\mackerel_live_co.paa"
      };
      hiddenSelectionsMaterials[] = {
        "dz\gear\food\data\mackerel_live.rvmat",
        "dz\gear\food\data\mackerel_live.rvmat"
      };
      class AnimationSources : FoodAnimationSources {};
      class Food {
          class FoodStages {
              class Raw {
                  visual_properties[] = {
                    0,
                    0,
                    0
                  };
                  nutrition_properties[] = {
                    1,
                    69,
                    172,
                    70,
                    1
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
              class Rotten {
                  visual_properties[] = {
                    -1,
                    -1,
                    5
                  };
                  nutrition_properties[] = {
                    10,
                    25,
                    25,
                    1,
                    0
                  };
                  cooking_properties[] = {
                    0,
                    0
                  };
              };
          };
          class FoodStageTransitions : NotCookable {};
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
  }




  //Freshwater Fish Fillets
  class CarpFilletMeat;
  class BluegillFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Bluegill Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\bluegill_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };
  class BlackbassFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Black Bass Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\blackbass_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };

  };
  class CatfishFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Catfish Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\catfish_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };

  };
  class LargemouthbassFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Large Mouth Bass Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\largemouthbass_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };

  };
  class MinnowFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Minnow Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";

  };
  class NorthernpikeFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Northern Pike Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\northernpike_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };
  class PerchFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Perch Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\perch_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };

  };
  class SaugerFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Sauger Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\sauger_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };

  };
  class CrayfishFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Crayfish Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "gebsfish\data\food\crayfishtail.p3d";

  };
  class TroutFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Trout Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\trout_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };
  class WhitebassFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "White Bass Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\whitebass_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };
  class BowfinFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Bowfin Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\bowfin_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };
  class SlimysculpinFilletMeat: CarpFilletMeat {
    scope = 2;
    displayName = "Slimy Sculpin Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\carp_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\slimysculpin_fillet_co.paa",
      "dz\gear\food\data\carp_fillet_baked_CO.paa",
      "dz\gear\food\data\carp_fillet_boiled_CO.paa",
      "dz\gear\food\data\carp_fillet_dried_CO.paa",
      "dz\gear\food\data\carp_fillet_burnt_CO.paa"
    };
  };

  //Saltwater Fish fillets
  class MackerelFilletMeat;
  class AngelfishFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Angelfish Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\angelfish_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class AsianseabassFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Asianseabass Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\asianseabass_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class BluemarlinFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Bluemarlin Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\bluemarlin_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class BonitaFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Bonita Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\bonita_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class CherrysalmonFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Cherrysalmon Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\cherrysalmon_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class FlatheadmulletFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Flatheadmullet Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\flatheadmullet_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class LeopardsharkFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Leopardshark Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\leopardshark_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class PacificcodFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Pacificcod Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\pacificcod_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class RedheadcichlidFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Redheadcichlid Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\redheadcichlid_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class RoughneckrockFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Roughneckrock Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\roughneckrock_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class SeverumFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Severum Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\severum_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class ShrimpFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Shrimp Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "gebsfish\data\food\shrimptail.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\shrimp_ca.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class BluetangFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Blue Tang Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\bluetang_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class HairtailfishFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Hair Tail Fish Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\hairtailfish_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class HumpheadwrasseFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Humphead Wrasse Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\humpheadwrasse_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };
  class SiamesetigerfishFilletMeat: MackerelFilletMeat {
    scope = 2;
    displayName = "Siamese Tiger Fish Fillet";
    descriptionShort = "Yum! A fish fillet";
    model = "\dz\gear\food\mackerel_fillet.p3d";
    hiddenSelectionsTextures[] = {
      "gebsfish\data\food\siamesetigerfish_fillet_co.paa",
      "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
      "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
      "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
      "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
    };
  };

  //Crusts Fish Fillets
  class ClamFilletMeat : MackerelFilletMeat {
      scope = 2;
      displayName = "Clam Meat";
      descriptionShort = "Yum! A piece of Clam meat!";
      model = "\dz\gear\food\mackerel_fillet.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\clamfillet.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class MusselFilletMeat : MackerelFilletMeat {
      scope = 2;
      displayName = "Mussel Meat";
      descriptionShort = "Yum! A piece of Mussel meat!";
      model = "\dz\gear\food\mackerel_fillet.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\musselfillet.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class KingcrabFilletMeat : MackerelFilletMeat {
      scope = 2;
      displayName = "King Crab Meat";
      descriptionShort = "Yum! A piece of King Crab meat!";
      model = "\dz\gear\food\mackerel_fillet.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\kingcrabfillet.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class KingcrabLegs : MackerelFilletMeat {
      scope = 2;
      displayName = "King Crab Legs";
      descriptionShort = "Yum! Some King Crab Legs!";
      model = "gebsfish\data\food\kingcrablegs.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\kingcrab.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class JellyfishFilletMeat : MackerelFilletMeat {
      scope = 2;
      displayName = "Jellyfish Fillet";
      descriptionShort = "Yum! A piece of jellyfish!";
      model = "\dz\gear\food\mackerel_fillet.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\jellyfishfillet.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class LobsterFilletMeat : MackerelFilletMeat {
      scope = 2;
      displayName = "Lobster Fillet";
      descriptionShort = "Yum! A piece of Lobster!";
      model = "\dz\gear\food\mackerel_fillet.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\lobsterfillet.paa",
        "dz\gear\food\data\mackerel_fillet_baked_CO.paa",
        "dz\gear\food\data\mackerel_fillet_boiled_CO.paa",
        "dz\gear\food\data\mackerel_fillet_dried_CO.paa",
        "dz\gear\food\data\mackerel_fillet_burnt_CO.paa"
      };
  };
  class LobsterTail : MackerelFilletMeat {
      scope = 2;
      displayName = "Lobster Tail";
      descriptionShort = "Yum! A piece of Lobster!";
      model = "gebsfish\data\food\lobstertail.p3d";
      hiddenSelectionsTextures[] = {
        "gebsfish\data\food\shrimptail.paa",
      };
  };

};