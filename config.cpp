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
			"DZ_Characters",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class gebsfish
	{
		dir="gebsfish";
		picture = "gebsfish\logo.paa";			// picture in expanded description
		logoSmall = "gebsfish\logo.paa";	// icon next to mod name when description is not expanded
		logo = "gebsfish\logo.paa";				// logo below game menu
		overview = "Fish Expansion"
		action="";
		name="gebsfish";
		credits="Geb & DayZ Modding Community";
		author="Geb";
		authorID="0";
		version="1.0";
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
		};
	};
};
