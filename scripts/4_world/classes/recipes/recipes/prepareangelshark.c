class PrepareAngelshark extends PrepareFish
{
	int ran;	
	override void Init(){
		super.Init();
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"geb_Angelshark");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = true;//true = destroy, false = do nothing


		
		m_IngredientAddHealth[1] = -4;// 0 = do nothing // damages health of knife/tool from the fillet action
		//----------------------------------------------------------------------------------------------------------------------
		ran = Math.RandomFloatInclusive(m_gebsConfig.AngelShark.MeatMin,m_gebsConfig.AngelShark.MeatMax);
		for (int i = 0; i < ran; ++i){
			AddResult("geb_AngelsharkFilletMeat");//add results here
			m_ResultSetFullQuantity[i] = false;//true = set full quantity, false = do nothing
			m_ResultSetQuantity[i] = -1;//-1 = do nothing
			m_ResultSetHealth[i] = -1;//-1 = do nothing
			m_ResultInheritsHealth[i] = 0;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
			m_ResultInheritsColor[i] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
			m_ResultToInventory[i] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
			m_ResultUseSoftSkills[i] = false;// set 'true' to allow modification of the values by softskills on this result
			m_ResultReplacesIngredient[i] = 0;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
		}
		//----------------------------------------------------------------------------------------------------------------------
	}

	//final check for recipe's validity
	override bool CanDo(ItemBase ingredients[], PlayerBase player){
		return true;
	}

	//gets called upon recipe's completion
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight){
		// Adjusts quantity of results to the quantity of the 1st ingredient
		super.Do(ingredients, player, results, specialty_weight);
	}
};
