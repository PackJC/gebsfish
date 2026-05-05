

/*

class geb_jonboat_base : BoatScript
{
	override void EEInit()
	{		
		super.EEInit();

		SetAnimationPhase("ShowDamage",0);
		SetAnimationPhase("HideDamage",1);
	}

	override int GetAnimInstance()
	{
		return VehicleAnimInstances.ZODIAC;
	}

	override int GetSeatAnimationType(int posIdx)
	{
		switch (posIdx)
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (!super.CanReleaseAttachment(attachment))
			return false;
		
		string attType = attachment.GetType();
		
		if (EngineIsOn() && attType == "SparkPlug")
			return false;

		return true;
	}

	override bool CanDisplayAttachmentCategory(string category_name)
	{
		if ( !super.CanDisplayAttachmentCategory(category_name))
		{
			return false;
		}

		return true;
	}
	
	override bool CanDisplayCargo()
	{
		if (!super.CanDisplayCargo())
			return false;

		return true;
	}

	override bool CanReachSeatFromSeat(int currentSeat, int nextSeat)
	{
		return true;
	}

	override void OnDamageDestroyed(int oldLevel)
	{
		SetAnimationPhase("HideAntiwater",1);
	}

	override void OnDebugSpawn()
	{
		float amount = GetFluidCapacity(BoatFluid.FUEL);
		Fill(BoatFluid.FUEL, amount);

		//-----ATTACHMENTS
		GetInventory().CreateInInventory("Sparkplug");

	}
	
	// DEPRECATED
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaEngine m_UTSLEngine;
}



class geb_jonboat_greenaluminum : geb_jonboat_base {}
class geb_jonboat_grayaluminum : geb_jonboat_base {}
class geb_jonboat_camo_desert : geb_jonboat_base {}
class geb_jonboat_camo_snow : geb_jonboat_base {}
class geb_jonboat_camo_forest : geb_jonboat_base {}

*/