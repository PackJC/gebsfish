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
	class gebsClothingCfgPatches {
		//Never Use same name for patch, because conflict message.
		// The patches defining each vanilla parent, so they always load first.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts",
		"DZ_Characters_Gloves",    // NBCGloves_ColorBase
		"DZ_Characters_Headgear",  // BaseballCap_ColorBase
		"DZ_Characters_Shoes",     // Wellies_ColorBase
		"DZ_Characters_Tops",      // TShirt_ColorBase, Raincoat_ColorBase
		"DZ_Characters_Vests"      // HuntingVest
		};
	};
};

class cfgVehicles {
	//Instantiate Needed Classes
	class Clothing;
	class Inventory_Base;
	class TShirt_ColorBase;
	class NBCGloves_ColorBase;
	class BaseballCap_ColorBase;
	class Raincoat_ColorBase;
	class Wellies_ColorBase;
	class HuntingVest;

	/*

		CLOTHES

	*/
	// Every colour is the large tackle box's shade (green the green cooler's), the same on every item.

	//Gloves: knit work gloves dipped in black grip rubber over the whole hand (the knit cuff in the glove's colour or camo),
	//on vanilla's NBC glove model, with their
	//own material (knit relief and a matte knit, the rubber's grain and soft sheen) and its damaged and ruined copies.
	class geb_FishGloves_Base: NBCGloves_ColorBase {
		scope=0;
		// The Fishing Locker's spot for gloves (data/locker/config.cpp), added to the Gloves slot.
		inventorySlot[] += {"GebLockerGloves"};
		hiddenSelectionsMaterials[]=
		{
			"gebsfish\data\clothes\geb_fishgloves.rvmat",
			"gebsfish\data\clothes\geb_fishgloves.rvmat",
			"gebsfish\data\clothes\geb_fishgloves.rvmat"
		};
		// Fishing gloves, not hazmat gear: the NBC parent's chemical = 1 made
		// them full hand protection in toxic zones.
		class Protection {
			biological = 0;
			chemical = 0;
		};
		// Restated whole: a DamageSystem can't inherit across addons. The model's faces carry vanilla's
		// nbc_gloves material, so that is the reference the levels swap out.
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 120;
					RefTexsMats[] = {"DZ\characters\gloves\data\nbc_gloves.rvmat"};
					healthLevels[] = {
						{1, {"gebsfish\data\clothes\geb_fishgloves.rvmat"}},
						{0.7, {"gebsfish\data\clothes\geb_fishgloves.rvmat"}},
						{0.5, {"gebsfish\data\clothes\geb_fishgloves_damage.rvmat"}},
						{0.3, {"gebsfish\data\clothes\geb_fishgloves_damage.rvmat"}},
						{0, {"gebsfish\data\clothes\geb_fishgloves_destruct.rvmat"}}
					};
				};
			};
			class GlobalArmor {
				class Melee {
					class Health { damage = 0.95; };
					class Blood { damage = 0.9; };
					class Shock { damage = 1; };
				};
			};
		};
	};
	class geb_OrangeFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_orangefishinggloves";
		descriptionShort="$STR_clothes_orangefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa"
		};
	};
	class geb_BlueFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_bluefishinggloves";
		descriptionShort="$STR_clothes_bluefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves_co.paa"
		};
	};
	class geb_YellowFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_yellowfishinggloves";
		descriptionShort="$STR_clothes_yellowfishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_yellowfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishgloves_co.paa"
		};
	};
	class geb_RedFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_redfishinggloves";
		descriptionShort="$STR_clothes_redfishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_redfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_redfishgloves_co.paa"
		};
	};
	class geb_GreenFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_greenfishinggloves";
		descriptionShort="$STR_clothes_greenfishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_greenfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_greenfishgloves_co.paa"
		};
	};
	class geb_PurpleFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_purplefishinggloves";
		descriptionShort="$STR_clothes_purplefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_purplefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_purplefishgloves_co.paa"
		};
	};
	class geb_BrownFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_brownfishinggloves";
		descriptionShort="$STR_clothes_brownfishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_brownfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_brownfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_brownfishgloves_co.paa"
		};
	};
	class geb_LightBlueFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_lightbluefishinggloves";
		descriptionShort="$STR_clothes_lightbluefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_lightbluefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishgloves_co.paa"
		};
	};
	class geb_LimeFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_limefishinggloves";
		descriptionShort="$STR_clothes_limefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_limefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_limefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_limefishgloves_co.paa"
		};
	};
	class geb_PinkFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_pinkfishinggloves";
		descriptionShort="$STR_clothes_pinkfishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishgloves_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishgloves_co.paa"
		};
	};
	class geb_CamoFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_camofishinggloves";
		descriptionShort="$STR_clothes_camofishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_camofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_camofishgloves_co.paa"
		};
	};
	class geb_DesertCamoFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_desertcamofishinggloves";
		descriptionShort="$STR_clothes_desertcamofishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishgloves_co.paa"
		};
	};
	class geb_SnowCamoFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_snowcamofishinggloves";
		descriptionShort="$STR_clothes_snowcamofishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishgloves_co.paa"
		};
	};
	class geb_PinkCamoFishGloves: geb_FishGloves_Base {
		displayName="$STR_clothes_pinkcamofishinggloves";
		descriptionShort="$STR_clothes_pinkcamofishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishgloves_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishgloves_co.paa"
		};
	};

	//Hats
	// The base of every colour below: the Fishing Locker's spot for it
	// (data/locker/config.cpp), added to the slot it is worn in.
	class geb_FishHat_Base: BaseballCap_ColorBase {
		scope=0;
		inventorySlot[] += {"GebLockerHat"};
	};
	class geb_BlueFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_bluefishinghat";
		descriptionShort="$STR_clothes_bluefishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishhat_co.paa",
			"\gebsfish\data\clothes\geb_bluefishhat_co.paa",
			"\gebsfish\data\clothes\geb_bluefishhat_co.paa"
		};
	};
	class geb_RedFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_redfishinghat";
		descriptionShort="$STR_clothes_redfishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishhat_co.paa",
			"\gebsfish\data\clothes\geb_redfishhat_co.paa",
			"\gebsfish\data\clothes\geb_redfishhat_co.paa"
		};
	};
	class geb_GreenFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_greenfishinghat";
		descriptionShort="$STR_clothes_greenfishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishhat_co.paa",
			"\gebsfish\data\clothes\geb_greenfishhat_co.paa",
			"\gebsfish\data\clothes\geb_greenfishhat_co.paa"
		};
	};
	class geb_PurpleFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_purplefishinghat";
		descriptionShort="$STR_clothes_purplefishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishhat_co.paa",
			"\gebsfish\data\clothes\geb_purplefishhat_co.paa",
			"\gebsfish\data\clothes\geb_purplefishhat_co.paa"
		};
	};
	class geb_OrangeFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_orangefishinghat";
		descriptionShort="$STR_clothes_orangefishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_orangefishhat_co.paa",
			"\gebsfish\data\clothes\geb_orangefishhat_co.paa",
			"\gebsfish\data\clothes\geb_orangefishhat_co.paa"
		};
	};
	class geb_YellowFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_yellowfishinghat";
		descriptionShort="$STR_clothes_yellowfishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_yellowfishhat_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishhat_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishhat_co.paa"
		};
	};
	class geb_BrownFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_brownfishinghat";
		descriptionShort="$STR_clothes_brownfishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_brownfishhat_co.paa",
			"\gebsfish\data\clothes\geb_brownfishhat_co.paa",
			"\gebsfish\data\clothes\geb_brownfishhat_co.paa"
		};
	};
	class geb_LightBlueFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_lightbluefishinghat";
		descriptionShort="$STR_clothes_lightbluefishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_lightbluefishhat_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishhat_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishhat_co.paa"
		};
	};
	class geb_LimeFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_limefishinghat";
		descriptionShort="$STR_clothes_limefishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_limefishhat_co.paa",
			"\gebsfish\data\clothes\geb_limefishhat_co.paa",
			"\gebsfish\data\clothes\geb_limefishhat_co.paa"
		};
	};
	class geb_PinkFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_pinkfishinghat";
		descriptionShort="$STR_clothes_pinkfishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkfishhat_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishhat_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishhat_co.paa"
		};
	};
	class geb_CamoFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_camofishinghat";
		descriptionShort="$STR_clothes_camofishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishhat_co.paa",
			"\gebsfish\data\clothes\geb_camofishhat_co.paa",
			"\gebsfish\data\clothes\geb_camofishhat_co.paa"
		};
	};
	class geb_DesertCamoFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_desertcamofishinghat";
		descriptionShort="$STR_clothes_desertcamofishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishhat_co.paa"
		};
	};
	class geb_SnowCamoFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_snowcamofishinghat";
		descriptionShort="$STR_clothes_snowcamofishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishhat_co.paa"
		};
	};
	class geb_PinkCamoFishHat: geb_FishHat_Base {
		displayName="$STR_clothes_pinkcamofishinghat";
		descriptionShort="$STR_clothes_pinkcamofishinghat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishhat_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishhat_co.paa"
		};
	};

	//Shirts: a fish on the back, the Gebsfish logo on the chest
	// The base of every colour below: the Fishing Locker's spot for it
	// (data/locker/config.cpp), added to the slot it is worn in.
	class geb_FishShirt_Base: TShirt_ColorBase {
		scope=0;
		inventorySlot[] += {"GebLockerShirt"};
	};
	class geb_RedFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_redfishingshirt";
		descriptionShort="$STR_clothes_redfishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_redfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt_co.paa"
		};
	};
	class geb_GreenFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_greenfishingshirt";
		descriptionShort="$STR_clothes_greenfishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_greenfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt_co.paa"
		};
	};
	class geb_BlueFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_bluefishingshirt";
		descriptionShort="$STR_clothes_bluefishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_bluefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt_co.paa"
		};
	};
	class geb_PurpleFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_purplefishingshirt";
		descriptionShort="$STR_clothes_purplefishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_purplefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa"
		};
	};
	class geb_OrangeFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_orangefishingshirt";
		descriptionShort="$STR_clothes_orangefishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_orangefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_orangefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_orangefishshirt_co.paa"
		};
	};
	class geb_YellowFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_yellowfishingshirt";
		descriptionShort="$STR_clothes_yellowfishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_yellowfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishshirt_co.paa"
		};
	};
	class geb_BrownFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_brownfishingshirt";
		descriptionShort="$STR_clothes_brownfishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_brownfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_brownfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_brownfishshirt_co.paa"
		};
	};
	class geb_LightBlueFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_lightbluefishingshirt";
		descriptionShort="$STR_clothes_lightbluefishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_lightbluefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishshirt_co.paa"
		};
	};
	class geb_LimeFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_limefishingshirt";
		descriptionShort="$STR_clothes_limefishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_limefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_limefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_limefishshirt_co.paa"
		};
	};
	class geb_PinkFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_pinkfishingshirt";
		descriptionShort="$STR_clothes_pinkfishingshirt_desc";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_pinkfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishshirt_co.paa"
		};
	};
	class geb_CamoFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_camofishingshirt";
		descriptionShort="$STR_clothes_camofishingshirt_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_camofishshirt_co.paa",
			"\gebsfish\data\clothes\geb_camofishshirt_co.paa"
		};
	};
	class geb_DesertCamoFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_desertcamofishingshirt";
		descriptionShort="$STR_clothes_desertcamofishingshirt_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishshirt_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishshirt_co.paa"
		};
	};
	class geb_SnowCamoFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_snowcamofishingshirt";
		descriptionShort="$STR_clothes_snowcamofishingshirt_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishshirt_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishshirt_co.paa"
		};
	};
	class geb_PinkCamoFishShirt: geb_FishShirt_Base {
		displayName="$STR_clothes_pinkcamofishingshirt";
		descriptionShort="$STR_clothes_pinkcamofishingshirt_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishshirt_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishshirt_co.paa"
		};
	};

	//Raincoats: vanilla's raincoat (its warmth, cargo and damage looks) in the fishing colours,
	//with the Gebsfish logo on the chest beside the zip, where the shirts carry it.
	// The base of every colour below: the Fishing Locker's spot for it
	// (data/locker/config.cpp), added to the slot it is worn in.
	class geb_FishRaincoat_Base: Raincoat_ColorBase {
		scope=0;
		inventorySlot[] += {"GebLockerCoat"};
	};
	class geb_RedFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_redfishingraincoat";
		descriptionShort="$STR_clothes_redfishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_redfishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_redfishraincoat_co.paa"
		};
	};
	class geb_GreenFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_greenfishingraincoat";
		descriptionShort="$STR_clothes_greenfishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_greenfishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_greenfishraincoat_co.paa"
		};
	};
	class geb_BlueFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_bluefishingraincoat";
		descriptionShort="$STR_clothes_bluefishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_bluefishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_bluefishraincoat_co.paa"
		};
	};
	class geb_PurpleFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_purplefishingraincoat";
		descriptionShort="$STR_clothes_purplefishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_purplefishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_purplefishraincoat_co.paa"
		};
	};
	class geb_OrangeFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_orangefishingraincoat";
		descriptionShort="$STR_clothes_orangefishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_orangefishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_orangefishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_orangefishraincoat_co.paa"
		};
	};
	class geb_YellowFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_yellowfishingraincoat";
		descriptionShort="$STR_clothes_yellowfishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_yellowfishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishraincoat_co.paa"
		};
	};
	class geb_BrownFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_brownfishingraincoat";
		descriptionShort="$STR_clothes_brownfishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_brownfishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_brownfishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_brownfishraincoat_co.paa"
		};
	};
	class geb_LightBlueFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_lightbluefishingraincoat";
		descriptionShort="$STR_clothes_lightbluefishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_lightbluefishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishraincoat_co.paa"
		};
	};
	class geb_LimeFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_limefishingraincoat";
		descriptionShort="$STR_clothes_limefishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_limefishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_limefishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_limefishraincoat_co.paa"
		};
	};
	class geb_PinkFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_pinkfishingraincoat";
		descriptionShort="$STR_clothes_pinkfishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkfishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishraincoat_co.paa"
		};
	};
	class geb_CamoFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_camofishingraincoat";
		descriptionShort="$STR_clothes_camofishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_camofishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_camofishraincoat_co.paa"
		};
	};
	class geb_DesertCamoFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_desertcamofishingraincoat";
		descriptionShort="$STR_clothes_desertcamofishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishraincoat_co.paa"
		};
	};
	class geb_SnowCamoFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_snowcamofishingraincoat";
		descriptionShort="$STR_clothes_snowcamofishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishraincoat_co.paa"
		};
	};
	class geb_PinkCamoFishRaincoat: geb_FishRaincoat_Base {
		displayName="$STR_clothes_pinkcamofishingraincoat";
		descriptionShort="$STR_clothes_pinkcamofishingraincoat_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishraincoat_ground_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishraincoat_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishraincoat_co.paa"
		};
	};

	//Wellies: vanilla's rubber boots in the same colours, the Gebsfish logo in place of the brand badge.
	// The base of every colour below: the Fishing Locker's spot for it
	// (data/locker/config.cpp), added to the slot it is worn in.
	class geb_FishWellies_Base: Wellies_ColorBase {
		scope=0;
		inventorySlot[] += {"GebLockerBoots"};
	};
	class geb_RedFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_redfishingwellies";
		descriptionShort="$STR_clothes_redfishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_redfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_redfishwellies_co.paa"
		};
	};
	class geb_GreenFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_greenfishingwellies";
		descriptionShort="$STR_clothes_greenfishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_greenfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_greenfishwellies_co.paa"
		};
	};
	class geb_BlueFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_bluefishingwellies";
		descriptionShort="$STR_clothes_bluefishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_bluefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_bluefishwellies_co.paa"
		};
	};
	class geb_PurpleFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_purplefishingwellies";
		descriptionShort="$STR_clothes_purplefishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_purplefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_purplefishwellies_co.paa"
		};
	};
	class geb_OrangeFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_orangefishingwellies";
		descriptionShort="$STR_clothes_orangefishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_orangefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_orangefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_orangefishwellies_co.paa"
		};
	};
	class geb_YellowFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_yellowfishingwellies";
		descriptionShort="$STR_clothes_yellowfishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_yellowfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishwellies_co.paa"
		};
	};
	class geb_BrownFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_brownfishingwellies";
		descriptionShort="$STR_clothes_brownfishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_brownfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_brownfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_brownfishwellies_co.paa"
		};
	};
	class geb_LightBlueFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_lightbluefishingwellies";
		descriptionShort="$STR_clothes_lightbluefishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_lightbluefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishwellies_co.paa"
		};
	};
	class geb_LimeFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_limefishingwellies";
		descriptionShort="$STR_clothes_limefishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_limefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_limefishwellies_co.paa",
			"\gebsfish\data\clothes\geb_limefishwellies_co.paa"
		};
	};
	class geb_PinkFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_pinkfishingwellies";
		descriptionShort="$STR_clothes_pinkfishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishwellies_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishwellies_co.paa"
		};
	};
	class geb_CamoFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_camofishingwellies";
		descriptionShort="$STR_clothes_camofishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_camofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_camofishwellies_co.paa"
		};
	};
	class geb_DesertCamoFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_desertcamofishingwellies";
		descriptionShort="$STR_clothes_desertcamofishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishwellies_co.paa"
		};
	};
	class geb_SnowCamoFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_snowcamofishingwellies";
		descriptionShort="$STR_clothes_snowcamofishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishwellies_co.paa"
		};
	};
	class geb_PinkCamoFishWellies: geb_FishWellies_Base {
		displayName="$STR_clothes_pinkcamofishingwellies";
		descriptionShort="$STR_clothes_pinkcamofishingwellies_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishwellies_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishwellies_co.paa"
		};
	};

	//Vests: vanilla's hunting vest (its stats, cargo and damage looks) in the muted fishing colours and the four camos,
	//with black mesh pockets and the Gebsfish logo on the right chest. Vanilla's HuntingVest has no hiddenSelections,
	//so they are named here as on its winter version.
	// The base of every colour below: the Fishing Locker's spot for it
	// (data/locker/config.cpp), added to the slot it is worn in.
	class geb_FishVest_Base: HuntingVest {
		scope=0;
		inventorySlot[] += {"GebLockerVest"};
	};
	class geb_RedFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_redfishingvest";
		descriptionShort="$STR_clothes_redfishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishvest_co.paa",
			"\gebsfish\data\clothes\geb_redfishvest_co.paa",
			"\gebsfish\data\clothes\geb_redfishvest_co.paa"
		};
	};
	class geb_GreenFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_greenfishingvest";
		descriptionShort="$STR_clothes_greenfishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishvest_co.paa",
			"\gebsfish\data\clothes\geb_greenfishvest_co.paa",
			"\gebsfish\data\clothes\geb_greenfishvest_co.paa"
		};
	};
	class geb_BlueFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_bluefishingvest";
		descriptionShort="$STR_clothes_bluefishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishvest_co.paa",
			"\gebsfish\data\clothes\geb_bluefishvest_co.paa",
			"\gebsfish\data\clothes\geb_bluefishvest_co.paa"
		};
	};
	class geb_PurpleFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_purplefishingvest";
		descriptionShort="$STR_clothes_purplefishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishvest_co.paa",
			"\gebsfish\data\clothes\geb_purplefishvest_co.paa",
			"\gebsfish\data\clothes\geb_purplefishvest_co.paa"
		};
	};
	class geb_OrangeFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_orangefishingvest";
		descriptionShort="$STR_clothes_orangefishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_orangefishvest_co.paa",
			"\gebsfish\data\clothes\geb_orangefishvest_co.paa",
			"\gebsfish\data\clothes\geb_orangefishvest_co.paa"
		};
	};
	class geb_YellowFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_yellowfishingvest";
		descriptionShort="$STR_clothes_yellowfishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_yellowfishvest_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishvest_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishvest_co.paa"
		};
	};
	class geb_BrownFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_brownfishingvest";
		descriptionShort="$STR_clothes_brownfishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_brownfishvest_co.paa",
			"\gebsfish\data\clothes\geb_brownfishvest_co.paa",
			"\gebsfish\data\clothes\geb_brownfishvest_co.paa"
		};
	};
	class geb_LightBlueFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_lightbluefishingvest";
		descriptionShort="$STR_clothes_lightbluefishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_lightbluefishvest_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishvest_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishvest_co.paa"
		};
	};
	class geb_LimeFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_limefishingvest";
		descriptionShort="$STR_clothes_limefishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_limefishvest_co.paa",
			"\gebsfish\data\clothes\geb_limefishvest_co.paa",
			"\gebsfish\data\clothes\geb_limefishvest_co.paa"
		};
	};
	class geb_PinkFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_pinkfishingvest";
		descriptionShort="$STR_clothes_pinkfishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkfishvest_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishvest_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishvest_co.paa"
		};
	};
	class geb_CamoFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_camofishingvest";
		descriptionShort="$STR_clothes_camofishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_camofishvest_co.paa",
			"\gebsfish\data\clothes\geb_camofishvest_co.paa",
			"\gebsfish\data\clothes\geb_camofishvest_co.paa"
		};
	};
	class geb_DesertCamoFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_desertcamofishingvest";
		descriptionShort="$STR_clothes_desertcamofishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_desertcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_desertcamofishvest_co.paa"
		};
	};
	class geb_SnowCamoFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_snowcamofishingvest";
		descriptionShort="$STR_clothes_snowcamofishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_snowcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_snowcamofishvest_co.paa"
		};
	};
	class geb_PinkCamoFishVest: geb_FishVest_Base {
		displayName="$STR_clothes_pinkcamofishingvest";
		descriptionShort="$STR_clothes_pinkcamofishingvest_desc";
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_pinkcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishvest_co.paa",
			"\gebsfish\data\clothes\geb_pinkcamofishvest_co.paa"
		};
	};
};
