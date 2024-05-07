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
	class gebsAmbientCfgPatches { 	
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
	class House;
	
    /*

	DYNAMIC FISH

	*/
	class geb_Ambientfish1: House {
		scope=1;
		model = "gebsfish\data\ambientfish\geb_Ambientfish1.p3d";
		class AnimationSources
		{
			class Wheel1
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
			class Wheel2
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
			class Wheel3
			{
				source="time";
				animPeriod=55;
				initPhase=1;
			};
		};
	};
};