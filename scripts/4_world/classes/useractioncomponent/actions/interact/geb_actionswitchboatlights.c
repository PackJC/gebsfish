/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// Jon boat light switch, three ways in:
//  - the vanilla lights key (UAToggleVehicleLights) from the driver seat;
//  - an interact prompt from the driver seat, in case that key doesn't fire in boats;
//  - an interact prompt when standing at the battery box.
//
// Vanilla ActionSwitchLights plays CMD_ACTIONMOD_HEADLIGHT, but the Boat_01 seat
// animation set has no "DriverLights" move (only the cars do), so the player
// could hang in the seat. The boat set does have DriverShiftGear, which carries
// the ActionExec event the action waits for, so the seat versions use that.

// Lights key, driver seat (added to the boat's own actions).
class GebActionSwitchBoatLights : ActionSwitchLights {
	void GebActionSwitchBoatLights() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_SHIFTGEAR;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if (!vehCommand || !geb_jonboat_base.Cast(vehCommand.GetTransport())) {
			return false;
		}
		return super.ActionCondition(player, target, item);
	}

	// vanilla toggles the engine's light flag; the boat passes it on to everyone
	override void OnExecuteServer(ActionData action_data) {
		super.OnExecuteServer(action_data);
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if (vehCommand) {
			geb_jonboat_base boat = geb_jonboat_base.Cast(vehCommand.GetTransport());
			if (boat)
				boat.GebSyncLights();
		}
	}
}

// Interact prompt, driver seat (added to the player's actions, see geb_playerbase.c).
class GebActionSwitchBoatLightsSeat : GebActionSwitchBoatLights {
	override typename GetInputType() {
		return InteractActionInput;
	}
}

// Interact prompt, standing at the battery box (View Geometry piece "geb_battery").
class GebActionSwitchBoatLightsAtBattery : ActionInteractBase {
	static const float GEB_REACH = 1.6;

	void GebActionSwitchBoatLightsAtBattery() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#switch_lights";
	}

	// The default CCTObject measures to the boat's origin (mid-boat, over 2 m from the
	// stern), so reach is checked against the box's memory point instead, as
	// ActionFillFuel does with the refill point.
	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (!target || player.IsInVehicle()) {
			return false;
		}
		geb_jonboat_base boat = geb_jonboat_base.Cast(target.GetObject());
		if (!boat || boat.IsDamageDestroyed()) {
			return false;
		}

		TStringArray selections = new TStringArray();
		boat.GetActionComponentNameList(target.GetComponentIndex(), selections);
		if (selections.Find("geb_battery") < 0) {
			return false;
		}

		if (vector.Distance(player.GetPosition(), boat.ModelToWorld(boat.GetMemoryPointPos("geb_battery"))) > GEB_REACH) {
			return false;
		}

		// switching off always works; switching on needs a charged battery
		return boat.GebLightsOn() || boat.OnBeforeLightOn();
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_jonboat_base boat = geb_jonboat_base.Cast(action_data.m_Target.GetObject());
		if (boat) {
			boat.GebSetLights(!boat.LightIsOn());
		}
	}
}

// Vanilla 1.30 bug: ToggleVehicleLightsActionInput counts a vehicle's lights
// actions before checking it has any, and keeps the last vehicle sat in as its
// target after getting out. A boat with no lights action (vanilla Boat_01)
// answers null: a script exception every frame while seated and after getting
// out, until the player sits in a car (706 in 32 s, client log 2026-10-14).
// An empty list gives the same answer without the exception.
modded class BoatScript {
	protected static ref array<ActionBase_Basic> s_GebNoLightsActions = new array<ActionBase_Basic>;

	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions) {
		super.GetActions(action_input_type, actions);
		if (!actions && action_input_type == ToggleVehicleLightsActionInput) {
			actions = s_GebNoLightsActions;
		}
	}
}
