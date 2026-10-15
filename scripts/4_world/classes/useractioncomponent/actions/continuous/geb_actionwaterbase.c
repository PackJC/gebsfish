/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The bamboo net and the spear: actions aimed at water that need to know
// which water it is. The peer that starts one reads it where the player aims
// (1 pond, 2 sea; 0 neither, never an implicit pond) and sends it with the
// action, as vanilla's ActionFishingNew sends its sea flag. A dedicated server
// takes it from there.
class GebWaterActionData : ActionData {
	int m_GebEnvironment;
}

class GebWaterReceiveData : ActionReciveData {
	int m_GebEnvironment;
}

class ActionGebWaterBase : ActionContinuousBase {
	int GebGetWaterType(ActionTarget target) {
		if (!target)
			return 0;
		vector position = target.GetCursorHitPos();
		if (g_Game.SurfaceIsSea(position[0], position[2]))
			return 2;
		if (g_Game.SurfaceIsPond(position[0], position[2]))
			return 1;
		return 0;
	}

	bool GebIsWaterType(int environment) {
		return environment == 1 || environment == 2;
	}

	override ActionData CreateActionData() {
		return new GebWaterActionData();
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data) {
		super.WriteToContext(ctx, action_data);
		GebWaterActionData data = GebWaterActionData.Cast(action_data);
		ctx.Write(data.m_GebEnvironment);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data) {
		if (!action_recive_data)
			action_recive_data = new GebWaterReceiveData();
		if (!super.ReadFromContext(ctx, action_recive_data))
			return false;
		GebWaterReceiveData received = GebWaterReceiveData.Cast(action_recive_data);
		if (!received || !ctx.Read(received.m_GebEnvironment))
			return false;
		return GebIsWaterType(received.m_GebEnvironment);
	}

	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data) {
		super.HandleReciveData(action_recive_data, action_data);
		GebWaterReceiveData received = GebWaterReceiveData.Cast(action_recive_data);
		GebWaterActionData data = GebWaterActionData.Cast(action_data);
		if (received && data)
			data.m_GebEnvironment = received.m_GebEnvironment;
	}

	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL) {
		if (!super.SetupAction(player, target, item, action_data, extra_data))
			return false;
		GebWaterActionData data = GebWaterActionData.Cast(action_data);
		if (!data)
			return false;
		// Super already applied the received payload on the server.
		if (data.m_GebEnvironment == 0 && !g_Game.IsDedicatedServer())
			data.m_GebEnvironment = GebGetWaterType(target);
		// A server that didn't get a valid water type refuses here. A failed
		// ReadFromContext alone doesn't stop the action starting, so it would
		// otherwise play out in full and give nothing.
		if (g_Game.IsDedicatedServer() && !GebIsWaterType(data.m_GebEnvironment))
			return false;
		return true;
	}
}
