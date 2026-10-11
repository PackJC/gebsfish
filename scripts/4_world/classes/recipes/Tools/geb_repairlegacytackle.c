// The four "Fun" tackle boxes kept as hidden aliases for old storage
// (data/tackle/config.cpp, scope 1, until the next wipe) take vanilla's duct
// tape and epoxy repairs like every other box. Those recipes accept any item
// (Inventory_Base), but the crafting cache reaches only scope 2 classes
// through their parents (PluginRecipesManager.GenerateRecipeCache), so a
// scope 1 class is offered a recipe only where it is named. Remove this file
// with the aliases.
class GebLegacyTackle {
	static ref TStringArray s_Aliases = {"geb_FunYellowTackle", "geb_FunRedTackle", "geb_FunPurpleTackle", "geb_FunGreenTackle"};
}

modded class RepairWithTape {
	override void Init() {
		super.Init();
		foreach (string box : GebLegacyTackle.s_Aliases)
			InsertIngredient(1, box);
	}
}

modded class RepairEpoxy {
	override void Init() {
		super.Init();
		foreach (string box : GebLegacyTackle.s_Aliases)
			InsertIngredient(1, box);
	}
}
