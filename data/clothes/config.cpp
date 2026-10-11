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
		"DZ_Characters_Tops"       // TShirt_ColorBase, Raincoat_ColorBase
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

	/*

		CLOTHES

	*/
	// Every colour is the large tackle box's shade (green the green cooler's), the same on every item.

	//Gloves: knit work gloves with a black rubber-dipped palm and fingers, on vanilla's NBC glove model, with their
	//own material (knit relief and a matte knit, the rubber's grain and soft sheen) and its damaged and ruined copies.
	class geb_FishGloves_Base: NBCGloves_ColorBase {
		scope=0;
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

	//Hats
	class geb_BlueFishHat: BaseballCap_ColorBase {
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
	class geb_RedFishHat: BaseballCap_ColorBase {
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
	class geb_GreenFishHat: BaseballCap_ColorBase {
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
	class geb_PurpleFishHat: BaseballCap_ColorBase {
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
	class geb_OrangeFishHat: BaseballCap_ColorBase {
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
	class geb_YellowFishHat: BaseballCap_ColorBase {
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
	class geb_BrownFishHat: BaseballCap_ColorBase {
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
	class geb_LightBlueFishHat: BaseballCap_ColorBase {
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
	class geb_LimeFishHat: BaseballCap_ColorBase {
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
	class geb_PinkFishHat: BaseballCap_ColorBase {
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

	//Shirts: a fish on the back, the Gebsfish logo on the chest
	class geb_RedFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_redfishingshirt";
		descriptionShort="$STR_clothes_redfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_redfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt_co.paa"
		};
	};
	class geb_GreenFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_greenfishingshirt";
		descriptionShort="$STR_clothes_greenfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_greenfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt_co.paa"
		};
	};
	class geb_BlueFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_bluefishingshirt";
		descriptionShort="$STR_clothes_bluefishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_bluefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt_co.paa"
		};
	};
	class geb_PurpleFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_purplefishingshirt";
		descriptionShort="$STR_clothes_purplefishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_purplefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa"
		};
	};
	class geb_OrangeFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_orangefishingshirt";
		descriptionShort="$STR_clothes_orangefishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_orangefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_orangefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_orangefishshirt_co.paa"
		};
	};
	class geb_YellowFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_yellowfishingshirt";
		descriptionShort="$STR_clothes_yellowfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_yellowfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_yellowfishshirt_co.paa"
		};
	};
	class geb_BrownFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_brownfishingshirt";
		descriptionShort="$STR_clothes_brownfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_brownfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_brownfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_brownfishshirt_co.paa"
		};
	};
	class geb_LightBlueFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_lightbluefishingshirt";
		descriptionShort="$STR_clothes_lightbluefishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_lightbluefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_lightbluefishshirt_co.paa"
		};
	};
	class geb_LimeFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_limefishingshirt";
		descriptionShort="$STR_clothes_limefishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_limefishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_limefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_limefishshirt_co.paa"
		};
	};
	class geb_PinkFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_pinkfishingshirt";
		descriptionShort="$STR_clothes_pinkfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\gebsfish\data\clothes\geb_pinkfishshirt_ground_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishshirt_co.paa",
			"\gebsfish\data\clothes\geb_pinkfishshirt_co.paa"
		};
	};

	//Raincoats: vanilla's raincoat (its warmth, cargo and damage looks) in the fishing colours,
	//with the Gebsfish logo on the chest beside the zip, where the shirts carry it.
	class geb_RedFishRaincoat: Raincoat_ColorBase {
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
	class geb_GreenFishRaincoat: Raincoat_ColorBase {
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
	class geb_BlueFishRaincoat: Raincoat_ColorBase {
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
	class geb_PurpleFishRaincoat: Raincoat_ColorBase {
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
	class geb_OrangeFishRaincoat: Raincoat_ColorBase {
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
	class geb_YellowFishRaincoat: Raincoat_ColorBase {
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
	class geb_BrownFishRaincoat: Raincoat_ColorBase {
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
	class geb_LightBlueFishRaincoat: Raincoat_ColorBase {
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
	class geb_LimeFishRaincoat: Raincoat_ColorBase {
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
	class geb_PinkFishRaincoat: Raincoat_ColorBase {
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

	//Wellies: vanilla's rubber boots in the same colours, the Gebsfish logo in place of the brand badge.
	class geb_RedFishWellies: Wellies_ColorBase {
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
	class geb_GreenFishWellies: Wellies_ColorBase {
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
	class geb_BlueFishWellies: Wellies_ColorBase {
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
	class geb_PurpleFishWellies: Wellies_ColorBase {
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
	class geb_OrangeFishWellies: Wellies_ColorBase {
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
	class geb_YellowFishWellies: Wellies_ColorBase {
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
	class geb_BrownFishWellies: Wellies_ColorBase {
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
	class geb_LightBlueFishWellies: Wellies_ColorBase {
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
	class geb_LimeFishWellies: Wellies_ColorBase {
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
	class geb_PinkFishWellies: Wellies_ColorBase {
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
};
