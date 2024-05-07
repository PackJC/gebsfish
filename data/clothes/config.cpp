/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

class CfgNonAIVehicles
{
	class StaticObject;
};

class CfgPatches
{
	class gebsClothingCfgPatches { 	
		//Never Use same name for patch, because conflict message.
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts"
		};
	};
};
class cfgVehicles
{		
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
		displayName="$STR_fishinggloves_orange";
		descriptionShort="$STR_fishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=	{
			"\gebsfish\data\clothes\geb_orangefishgloves.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves.paa",
			"\gebsfish\data\clothes\geb_orangefishgloves.paa"
		};
	};
	class geb_BlueFishGloves: NBCGloves_ColorBase {
		displayName="$STR_fishinggloves_blue";
		descriptionShort="$STR_fishinggloves_desc";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishgloves.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves.paa",
			"\gebsfish\data\clothes\geb_bluefishgloves.paa"
		};
	};

	//Hats
	class geb_BlueFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_blue";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_bluefishhat.paa",
			"\gebsfish\data\clothes\geb_bluefishhat.paa",
			"\gebsfish\data\clothes\geb_bluefishhat.paa"
		};
	};
	class geb_RedFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_red";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_redfishhat.paa",
			"\gebsfish\data\clothes\geb_redfishhat.paa",
			"\gebsfish\data\clothes\geb_redfishhat.paa"
		};
	};	
	class geb_GreenFishHat: BaseballCap_ColorBase {
		scope=2;
		displayName="$STR_fishing_hat_green";
		descriptionShort="$STR_fishing_hat_desc";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_greenfishhat.paa",
			"\gebsfish\data\clothes\geb_greenfishhat.paa",
			"\gebsfish\data\clothes\geb_greenfishhat.paa"
		};
	};	
	class geb_PurpleFishHat: BaseballCap_ColorBase {
		displayName="$STR_fishing_hat_purple";
		descriptionShort="$STR_fishing_hat_desc";
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\gebsfish\data\clothes\geb_purplefishhat.paa",
			"\gebsfish\data\clothes\geb_purplefishhat.paa",
			"\gebsfish\data\clothes\geb_purplefishhat.paa"
		};
	};	

	//Shirts
	class geb_RedFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_red";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_red_co.paa",
			"\gebsfish\data\clothes\geb_redfishshirt.paa",
			"\gebsfish\data\clothes\geb_redfishshirt.paa"
		};
	};
	class geb_GreenFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_green";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_green_co.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt.paa",
			"\gebsfish\data\clothes\geb_greenfishshirt.paa"
		};
	};
	class geb_BlueFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_blue";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_blue_co.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt.paa",
			"\gebsfish\data\clothes\geb_bluefishshirt.paa"
		};
	};
	class geb_PurpleFishShirt: TShirt_ColorBase {
		displayName = "$STR_fishing_shirt_purple";
		descriptionShort = "$STR_fishing_shirt_desc";
		scope = 2;
		visibilityModifier = 0.94999999;
		hiddenSelectionsTextures[] =
		{
			"\dz\characters\tops\data\tshirt_ground_black_co.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt.paa",
			"\gebsfish\data\clothes\geb_purplefishshirt.paa"
		};
	};
};