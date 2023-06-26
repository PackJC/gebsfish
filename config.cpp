/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class CfgPatches
{
	class gebsfish
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class gebsfish
	{
		dir="gebsfish";
		picture = "gebsfish\data\logo.paa";					// picture in expanded description
		logoSmall = "gebsfish\data\logo.paa";				// icon next to mod name when description is not expanded
		logo = "gebsfish\data\logo.paa";					// logo below game menu
		logoHover = "gebsfish\data\logo_hover.paa";			// logo hovered
		overview = "DayZ Fish Expansion";
		action="";
		name="gebsfish";
		credits="Geb & DayZ Modding Community";
		author="Geb";
		authorID="0";
		version="1.19";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"gebsfish\Scripts\3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"gebsfish\scripts\4_world"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"gebsfish\scripts\5_mission"
				};
			};
		};
	};
};
