modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(ActionDigBugs);
		actions.Insert(ActionDigFieldCricket);
		actions.Insert(ActionDigGrubWorm);
		actions.Insert(ActionBambooFishingNet);

	}
};