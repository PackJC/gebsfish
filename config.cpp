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
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
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
		picture = "gebsfish\logo.paa";					// picture in expanded description
		logoSmall = "gebsfish\logo.paa";				// icon next to mod name when description is not expanded
		logo = "gebsfish\logo.paa";						// logo below game menu
		logoHover = "gebsfish\logo_hover.paa";			// logo hovered
		overview = "Fish Expansion"
		action="";
		name="gebsfish";
		credits="Geb & DayZ Modding Community";
		author="Geb";
		authorID="0";
		version="1.18";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
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
