/*

	CREATED BY PACKJC
	https://github.com/PackJC/gebsfish
	https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
	https://discord.com/invite/G8uSGZ8yyf
	Contributions welcome via github

*/

// Canned fish: reskins of vanilla's two fish cans. Everything about eating,
// opening, rotting once open, sounds and food values is inherited; only the
// print, the food inside and the materials change.
//
// Flat tins are built on TunaCan (the ring-pull tin, opened by hand), round
// cans on SardinesCan (opened with a knife or another tool). The closed cans
// open into their own _Opened class in scripts (vanilla's Open() names its own
// opened class). The opened flat tins use fishtin_open.p3d, the mod's own
// opened tin (vanilla's size and texture layout, its food in camoGround):
// vanilla's opened tuna tin keeps its food outside camoGround, so on that
// model every opened tin would still show tuna.
//
// Each can has its own material (and damage copies) because the relief of the
// food differs per can; RefTexsMats names the vanilla material on the model's
// faces so the wear swap still finds them.

class CfgPatches {
	class gebsFoodCfgPatches {
		requiredAddons[] = {
		"DZ_Data",
		"DZ_Scripts",
		"DZ_Gear_Food",  // TunaCan, SardinesCan and their opened classes
		"DZ_Gear_Medical"  // VitaminBottle
		};
	};
};
class cfgVehicles {
	class TunaCan;
	class TunaCan_Opened;
	class SardinesCan;
	class SardinesCan_Opened;
	class VitaminBottle;
	class Pajka;
	class Pajka_Opened;
	class Pate;
	class Pate_Opened;
	class BrisketSpread;
	class BrisketSpread_Opened;
	class PorkCan;
	class PorkCan_Opened;
	class Lunchmeat;
	class Lunchmeat_Opened;
	class Honey;
	class Crackers;
	class Chips;
	class SaltySticks;
	class BoxCerealCrunchin;

	// Canned Sprats (flat tin)
	class geb_SpratsCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_cannedsprats";
		descriptionShort="$STR_food_cannedsprats_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsprats_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsprats.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsprats.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsprats.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsprats_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsprats_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsprats_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SpratsCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedsprats";
		descriptionShort="$STR_food_cannedsprats_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsprats_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsprats.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsprats.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsprats.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsprats_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsprats_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsprats_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Anchovies (flat tin)
	class geb_AnchoviesCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_cannedanchovies";
		descriptionShort="$STR_food_cannedanchovies_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedanchovies_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedanchovies.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedanchovies.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedanchovies.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedanchovies_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedanchovies_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedanchovies_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_AnchoviesCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedanchovies";
		descriptionShort="$STR_food_cannedanchovies_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedanchovies_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedanchovies.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedanchovies.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedanchovies.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedanchovies_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedanchovies_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedanchovies_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Kipper Snacks (flat tin)
	class geb_KipperSnacksCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_kippersnacks";
		descriptionShort="$STR_food_kippersnacks_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\kippersnacks_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\kippersnacks.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\kippersnacks.rvmat"}},
						{0.69999999, {"gebsfish\data\food\kippersnacks.rvmat"}},
						{0.5, {"gebsfish\data\food\kippersnacks_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\kippersnacks_damage.rvmat"}},
						{0, {"gebsfish\data\food\kippersnacks_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_KipperSnacksCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_kippersnacks";
		descriptionShort="$STR_food_kippersnacks_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\kippersnacks_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\kippersnacks.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\kippersnacks.rvmat"}},
						{0.69999999, {"gebsfish\data\food\kippersnacks.rvmat"}},
						{0.5, {"gebsfish\data\food\kippersnacks_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\kippersnacks_damage.rvmat"}},
						{0, {"gebsfish\data\food\kippersnacks_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Mackerel in Tomato Sauce (flat tin)
	class geb_MackerelTomatoCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_mackerelintomato";
		descriptionShort="$STR_food_mackerelintomato_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\mackerelintomato_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\mackerelintomato.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\mackerelintomato.rvmat"}},
						{0.69999999, {"gebsfish\data\food\mackerelintomato.rvmat"}},
						{0.5, {"gebsfish\data\food\mackerelintomato_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\mackerelintomato_damage.rvmat"}},
						{0, {"gebsfish\data\food\mackerelintomato_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_MackerelTomatoCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_mackerelintomato";
		descriptionShort="$STR_food_mackerelintomato_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\mackerelintomato_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\mackerelintomato.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\mackerelintomato.rvmat"}},
						{0.69999999, {"gebsfish\data\food\mackerelintomato.rvmat"}},
						{0.5, {"gebsfish\data\food\mackerelintomato_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\mackerelintomato_damage.rvmat"}},
						{0, {"gebsfish\data\food\mackerelintomato_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Smoked Trout (flat tin)
	class geb_SmokedTroutCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_smokedtrout";
		descriptionShort="$STR_food_smokedtrout_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedtrout_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedtrout.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedtrout.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedtrout.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedtrout_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedtrout_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedtrout_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SmokedTroutCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_smokedtrout";
		descriptionShort="$STR_food_smokedtrout_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedtrout_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedtrout.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedtrout.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedtrout.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedtrout_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedtrout_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedtrout_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Smoked Mussels (flat tin)
	class geb_SmokedMusselsCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_smokedmussels";
		descriptionShort="$STR_food_smokedmussels_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedmussels_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedmussels.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedmussels.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedmussels.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedmussels_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedmussels_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedmussels_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SmokedMusselsCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_smokedmussels";
		descriptionShort="$STR_food_smokedmussels_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedmussels_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedmussels.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedmussels.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedmussels.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedmussels_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedmussels_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedmussels_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Smoked Oysters (flat tin)
	class geb_SmokedOystersCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_smokedoysters";
		descriptionShort="$STR_food_smokedoysters_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedoysters_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedoysters.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedoysters.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedoysters.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedoysters_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedoysters_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedoysters_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SmokedOystersCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_smokedoysters";
		descriptionShort="$STR_food_smokedoysters_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedoysters_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\smokedoysters.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\smokedoysters.rvmat"}},
						{0.69999999, {"gebsfish\data\food\smokedoysters.rvmat"}},
						{0.5, {"gebsfish\data\food\smokedoysters_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\smokedoysters_damage.rvmat"}},
						{0, {"gebsfish\data\food\smokedoysters_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Squid in Ink (flat tin)
	class geb_SquidInkCan: TunaCan
	{
		scope=2;
		displayName="$STR_food_squidinink";
		descriptionShort="$STR_food_squidinink_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\squidinink_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\squidinink.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\squidinink.rvmat"}},
						{0.69999999, {"gebsfish\data\food\squidinink.rvmat"}},
						{0.5, {"gebsfish\data\food\squidinink_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\squidinink_damage.rvmat"}},
						{0, {"gebsfish\data\food\squidinink_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SquidInkCan_Opened: TunaCan_Opened
	{
		scope=2;
		displayName="$STR_food_squidinink";
		descriptionShort="$STR_food_squidinink_desc";
		model="\gebsfish\data\food\fishtin_open.p3d";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\squidinink_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\squidinink.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\tuna.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\squidinink.rvmat"}},
						{0.69999999, {"gebsfish\data\food\squidinink.rvmat"}},
						{0.5, {"gebsfish\data\food\squidinink_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\squidinink_damage.rvmat"}},
						{0, {"gebsfish\data\food\squidinink_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Salmon (round can)
	class geb_SalmonCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedsalmon";
		descriptionShort="$STR_food_cannedsalmon_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsalmon_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsalmon.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsalmon.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsalmon.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsalmon_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsalmon_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsalmon_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SalmonCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedsalmon";
		descriptionShort="$STR_food_cannedsalmon_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsalmon_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsalmon.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsalmon.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsalmon.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsalmon_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsalmon_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsalmon_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Cod Liver (round can)
	class geb_CodLiverCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedcodliver";
		descriptionShort="$STR_food_cannedcodliver_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcodliver_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcodliver.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcodliver.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcodliver.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcodliver_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcodliver_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcodliver_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_CodLiverCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedcodliver";
		descriptionShort="$STR_food_cannedcodliver_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcodliver_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcodliver.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcodliver.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcodliver.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcodliver_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcodliver_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcodliver_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Saury (round can)
	class geb_SauryCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedsaury";
		descriptionShort="$STR_food_cannedsaury_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsaury_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsaury.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsaury.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsaury.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsaury_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsaury_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsaury_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_SauryCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedsaury";
		descriptionShort="$STR_food_cannedsaury_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedsaury_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedsaury.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedsaury.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedsaury.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedsaury_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedsaury_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedsaury_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Crab Meat (round can)
	class geb_CrabMeatCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedcrabmeat";
		descriptionShort="$STR_food_cannedcrabmeat_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcrabmeat_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcrabmeat.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcrabmeat.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcrabmeat.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcrabmeat_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcrabmeat_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcrabmeat_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_CrabMeatCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedcrabmeat";
		descriptionShort="$STR_food_cannedcrabmeat_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcrabmeat_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcrabmeat.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcrabmeat.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcrabmeat.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcrabmeat_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcrabmeat_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcrabmeat_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Bonito (round can)
	class geb_BonitoCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedbonito";
		descriptionShort="$STR_food_cannedbonito_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedbonito_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedbonito.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedbonito.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedbonito.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedbonito_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedbonito_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedbonito_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_BonitoCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedbonito";
		descriptionShort="$STR_food_cannedbonito_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedbonito_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedbonito.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedbonito.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedbonito.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedbonito_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedbonito_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedbonito_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Canned Caviar (round can)
	class geb_CaviarCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_cannedcaviar";
		descriptionShort="$STR_food_cannedcaviar_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcaviar_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcaviar.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcaviar.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcaviar.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcaviar_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcaviar_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcaviar_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_CaviarCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_cannedcaviar";
		descriptionShort="$STR_food_cannedcaviar_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\cannedcaviar_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\cannedcaviar.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\cannedcaviar.rvmat"}},
						{0.69999999, {"gebsfish\data\food\cannedcaviar.rvmat"}},
						{0.5, {"gebsfish\data\food\cannedcaviar_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\cannedcaviar_damage.rvmat"}},
						{0, {"gebsfish\data\food\cannedcaviar_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Minced Clams (round can)
	class geb_MincedClamsCan: SardinesCan
	{
		scope=2;
		displayName="$STR_food_mincedclams";
		descriptionShort="$STR_food_mincedclams_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\mincedclams_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\mincedclams.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\mincedclams.rvmat"}},
						{0.69999999, {"gebsfish\data\food\mincedclams.rvmat"}},
						{0.5, {"gebsfish\data\food\mincedclams_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\mincedclams_damage.rvmat"}},
						{0, {"gebsfish\data\food\mincedclams_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class geb_MincedClamsCan_Opened: SardinesCan_Opened
	{
		scope=2;
		displayName="$STR_food_mincedclams";
		descriptionShort="$STR_food_mincedclams_desc";
		hiddenSelectionsTextures[]={"\gebsfish\data\food\mincedclams_co.paa"};
		hiddenSelectionsMaterials[]={"gebsfish\data\food\mincedclams.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					RefTexsMats[]={"DZ\gear\food\data\Sardines.rvmat"};
					healthLevels[]=
					{
						{1, {"gebsfish\data\food\mincedclams.rvmat"}},
						{0.69999999, {"gebsfish\data\food\mincedclams.rvmat"}},
						{0.5, {"gebsfish\data\food\mincedclams_damage.rvmat"}},
						{0.30000001, {"gebsfish\data\food\mincedclams_damage.rvmat"}},
						{0, {"gebsfish\data\food\mincedclams_destruct.rvmat"}}
					};
				};
			};
		};
	};

	// Fish Oil Pills: vanilla's vitamin bottle with a fish oil label (navy, gold and
	// vanilla's ocean blue, three softgels; its paper, stains, barcode and facts
	// panel are vanilla's). Taking them works as vitamins do, all inherited, and
	// vanilla's materials stay: their relief and shine carry no lettering. The
	// model's one selection, zbytek, takes the texture, as on vanilla's AntiChem
	// injector.
	class geb_FishOilPills: VitaminBottle
	{
		scope=2;
		displayName="$STR_food_fishoilpills";
		descriptionShort="$STR_food_fishoilpills_desc";
		hiddenSelections[]={"zbytek"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishoilpills_co.paa"};
	};

	// Fish foods on vanilla's other packaging. Same food, opening, actions and
	// materials as the vanilla item each is built on; only the print and the food
	// that shows inside change. The closed cans open into their own _Opened class
	// (scripts, geb_cannedfish.c).
	// Cod Roe Spread: vanilla's pate tin (Pajka), its printed lid and the spread inside
	class geb_CodRoeSpread: Pajka
	{
		scope=2;
		displayName="$STR_food_codroespread";
		descriptionShort="$STR_food_codroespread_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\codroespread_co.paa"};
	};
	class geb_CodRoeSpread_Opened: Pajka_Opened
	{
		scope=2;
		displayName="$STR_food_codroespread";
		descriptionShort="$STR_food_codroespread_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\codroespread_co.paa"};
	};
	// Salmon Pate: vanilla's liver pate tin
	class geb_SalmonPate: Pate
	{
		scope=2;
		displayName="$STR_food_salmonpate";
		descriptionShort="$STR_food_salmonpate_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\salmonpate_co.paa"};
	};
	class geb_SalmonPate_Opened: Pate_Opened
	{
		scope=2;
		displayName="$STR_food_salmonpate";
		descriptionShort="$STR_food_salmonpate_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\salmonpate_co.paa"};
	};
	// Smoked Fish Spread: vanilla's brisket spread tin
	class geb_SmokedFishSpread: BrisketSpread
	{
		scope=2;
		displayName="$STR_food_smokedfishspread";
		descriptionShort="$STR_food_smokedfishspread_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedfishspread_co.paa"};
	};
	class geb_SmokedFishSpread_Opened: BrisketSpread_Opened
	{
		scope=2;
		displayName="$STR_food_smokedfishspread";
		descriptionShort="$STR_food_smokedfishspread_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\smokedfishspread_co.paa"};
	};
	// Fish Soup: vanilla's 250 g ring-pull can (canned pork), its label band and the soup inside
	class geb_FishSoupCan: PorkCan
	{
		scope=2;
		displayName="$STR_food_fishsoup";
		descriptionShort="$STR_food_fishsoup_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishsoup_co.paa"};
	};
	class geb_FishSoupCan_Opened: PorkCan_Opened
	{
		scope=2;
		displayName="$STR_food_fishsoup";
		descriptionShort="$STR_food_fishsoup_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishsoup_co.paa"};
	};
	// Clam Chowder: vanilla's 250 g can (canned pork)
	class geb_ClamChowderCan: PorkCan
	{
		scope=2;
		displayName="$STR_food_clamchowder";
		descriptionShort="$STR_food_clamchowder_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\clamchowder_co.paa"};
	};
	class geb_ClamChowderCan_Opened: PorkCan_Opened
	{
		scope=2;
		displayName="$STR_food_clamchowder";
		descriptionShort="$STR_food_clamchowder_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\clamchowder_co.paa"};
	};
	// Fish Balls in Tomato Sauce: vanilla's 250 g can (lunchmeat)
	class geb_FishBallsCan: Lunchmeat
	{
		scope=2;
		displayName="$STR_food_fishballs";
		descriptionShort="$STR_food_fishballs_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishballs_co.paa"};
	};
	class geb_FishBallsCan_Opened: Lunchmeat_Opened
	{
		scope=2;
		displayName="$STR_food_fishballs";
		descriptionShort="$STR_food_fishballs_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishballs_co.paa"};
	};
	// Herring in Mustard Sauce: vanilla's 250 g can (lunchmeat)
	class geb_HerringMustardCan: Lunchmeat
	{
		scope=2;
		displayName="$STR_food_herringmustard";
		descriptionShort="$STR_food_herringmustard_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\herringmustard_co.paa"};
	};
	class geb_HerringMustardCan_Opened: Lunchmeat_Opened
	{
		scope=2;
		displayName="$STR_food_herringmustard";
		descriptionShort="$STR_food_herringmustard_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\herringmustard_co.paa"};
	};
	// Pickled Herring: vanilla's honey jar (every face in camoGround; vanilla's marmalade jar has none in its closest LOD), its label, lid and what fills it; the glass keeps vanilla's alpha
	class geb_PickledHerring: Honey
	{
		scope=2;
		displayName="$STR_food_pickledherring";
		descriptionShort="$STR_food_pickledherring_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\pickledherring_ca.paa"};
	};
	// Red Caviar: vanilla's honey jar
	class geb_RedCaviarJar: Honey
	{
		scope=2;
		displayName="$STR_food_redcaviarjar";
		descriptionShort="$STR_food_redcaviarjar_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\redcaviarjar_ca.paa"};
	};
	// Pickled Mussels: vanilla's honey jar
	class geb_PickledMussels: Honey
	{
		scope=2;
		displayName="$STR_food_pickledmussels";
		descriptionShort="$STR_food_pickledmussels_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\pickledmussels_ca.paa"};
	};
	// Prawn Crackers: vanilla's snack bag
	class geb_PrawnCrackers: Crackers
	{
		scope=2;
		displayName="$STR_food_prawncrackers";
		descriptionShort="$STR_food_prawncrackers_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\prawncrackers_co.paa"};
	};
	// Dried Squid: vanilla's snack bag
	class geb_DriedSquidSnack: Chips
	{
		scope=2;
		displayName="$STR_food_driedsquid";
		descriptionShort="$STR_food_driedsquid_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\driedsquid_co.paa"};
	};
	// Fish Jerky: vanilla's stick pack; its print is opaque, so vanilla's pretzel sticks (outside camoGround) no longer show through
	class geb_FishJerky: SaltySticks
	{
		scope=2;
		displayName="$STR_food_fishjerky";
		descriptionShort="$STR_food_fishjerky_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\fishjerky_co.paa"};
	};
	// Bonito Flakes: vanilla's cereal box
	class geb_BonitoFlakes: BoxCerealCrunchin
	{
		scope=2;
		displayName="$STR_food_bonitoflakes";
		descriptionShort="$STR_food_bonitoflakes_desc";
		hiddenSelections[]={"camoGround"};
		hiddenSelectionsTextures[]={"\gebsfish\data\food\bonitoflakes_co.paa"};
	};
};
