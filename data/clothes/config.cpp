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
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts"
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
	
    /*

		CLOTHES

	*/
	//Gloves
	class geb_OrangeFishGloves: NBCGloves_ColorBase {
		displayName="$STR_clothes_orangefishinggloves";
		descriptionShort="$STR_clothes_orangefishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=	{
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves_co.paa",
		};
	};
	class geb_BlueFishGloves: NBCGloves_ColorBase {
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
		scope=2;
		displayName="$STR_clothes_greenfishinghat";
		descriptionShort="$STR_clothes_greenfishinghat_desc";
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

	//Shirts
	class geb_RedFishShirt: TShirt_ColorBase {
		displayName="$STR_clothes_redfishingshirt";
		descriptionShort="$STR_clothes_redfishingshirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_red_co.paa",
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
			"\dz\characters\tops\data\tshirt_ground_green_co.paa",
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
			"\dz\characters\tops\data\tshirt_ground_blue_co.paa",
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
			"\dz\characters\tops\data\tshirt_ground_black_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt_co.paa"
		};
	};
};