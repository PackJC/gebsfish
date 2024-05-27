class PrepareGreatwhiteshark extends PrepareFish
{
	int ran;	
	override void Init()
	{



		auto fillets_chance_map = FileReader.GetFilletsChanceMap();
		//this returns a string
		auto parts = fillets_chance_map.Get("geb_Greatwhiteshark");
		//create an array to hold the two string that will need to be turned into floats
		array<string> myArray = new array<string>; 
		//split the string into myArray
		parts.Split(",", myArray);
		//turn the strings into floats
		float lowChance = myArray[0].ToFloat();
		float highChance = myArray[1].ToFloat();
		ran = Math.RandomFloatInclusive(lowChance,highChance);


		m_Name = "#STR_gutandprepare0";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1.5;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"geb_Greatwhiteshark");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"Sickle");//you can insert multiple ingredients this way
		InsertIngredient(1,"KukriKnife");
		InsertIngredient(1,"FangeKnife");
		InsertIngredient(1,"Hacksaw");
		InsertIngredient(1,"HandSaw");
		InsertIngredient(1,"KitchenKnife");
		InsertIngredient(1,"SteakKnife");
		InsertIngredient(1,"StoneKnife");
		InsertIngredient(1,"Cleaver");
		InsertIngredient(1,"CombatKnife");
		InsertIngredient(1,"HuntingKnife");
		InsertIngredient(1,"Machete");
		InsertIngredient(1,"CrudeMachete");
		InsertIngredient(1,"OrientalMachete");
		InsertIngredient(1,"WoodAxe");
		InsertIngredient(1,"Hatchet");
		InsertIngredient(1,"FirefighterAxe");
		InsertIngredient(1,"Sword");
		InsertIngredient(1,"AK_Bayonet");
		InsertIngredient(1,"M9A1_Bayonet");
		InsertIngredient(1,"Mosin_Bayonet");
		InsertIngredient(1,"SKS_Bayonet");
		InsertIngredient(1,"BoneKnife");
		InsertIngredient(1,"geb_BlueFishKnife");
		InsertIngredient(1,"geb_OrangeFishKnife");
		InsertIngredient(1,"geb_GreenFishKnife");
		InsertIngredient(1,"geb_YellowFishKnife");
		InsertIngredient(1,"geb_RedFishKnife");
		InsertIngredient(1,"geb_PurpleFishKnife");
		
		m_IngredientAddHealth[1] = -12;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------

		for (int i = 0; i < ran; ++i){
			AddResult("geb_GreatwhitesharkFilletMeat");//add results here
			m_ResultSetFullQuantity[i] = false;//true = set full quantity, false = do nothing
			m_ResultSetQuantity[i] = -1;//-1 = do nothing
			m_ResultSetHealth[i] = -1;//-1 = do nothing
			m_ResultInheritsHealth[i] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
			m_ResultInheritsColor[i] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
			m_ResultToInventory[i] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
			m_ResultUseSoftSkills[i] = false;// set 'true' to allow modification of the values by softskills on this result
			m_ResultReplacesIngredient[i] = 0;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		}
		AddResult("Bone");
		AddResult("Bone");
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		// Adjusts quantity of results to the quantity of the 1st ingredient
		super.Do(ingredients, player, results, specialty_weight);
	}
};
