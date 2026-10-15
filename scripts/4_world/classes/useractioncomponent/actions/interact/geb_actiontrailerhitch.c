/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The boat trailer's prompts. Hitch and unhitch stand at the coupler
// (geb_BoatTrailer.GEB_PLAYER_REACH), looking at the trailer or at the car:
// hitching wants a stopped car with its hitch ball (just behind its back end)
// within GEB_HITCH_REACH of the coupler and not towing already; unhitching
// wants the car stopped. Winching a boat on and launching it stand at the
// bow roller (GEB_WINCH_REACH), with the car (if any) stopped. A boat on a
// trailer can't be got into or pushed.
class GebActionHitchTrailer : ActionInteractBase {
	void GebActionHitchTrailer() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_hitch";
	}

	// The default CCTObject measures to the trailer's origin (its axle, over 4 m
	// from the coupler), so reach is checked against the coupler instead.
	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	// Looking at the trailer or at one of its wheels.
	static geb_BoatTrailer GebTrailerOf(ActionTarget target) {
		if (!target)
			return null;
		geb_BoatTrailer trailer = geb_BoatTrailer.Cast(target.GetObject());
		if (!trailer)
			trailer = geb_BoatTrailer.Cast(target.GetParent());
		// a boat on the trailer covers its bunks and bow roller: looking at the
		// boat counts as looking at the trailer it rides on
		if (!trailer)
			trailer = geb_BoatTrailer.GebCarrierOf(target.GetObject());
		if (!trailer)
			trailer = geb_BoatTrailer.GebCarrierOf(target.GetParent());
		return trailer;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		geb_BoatTrailer trailer = GebTrailerOf(target);
		if (trailer)
			geb_BoatTrailer.GebDiag("hitch, looking at the trailer", trailer.GebDiagHitch(player));    // TEMPORARY
		if (!trailer || trailer.GebIsHitched() || !trailer.GebAtCoupler(player))
			return false;
		return trailer.GebFindHauler() != null;
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = GebTrailerOf(action_data.m_Target);
		if (!trailer)
			return;
		CarScript hauler = trailer.GebFindHauler();
		if (hauler)
			trailer.GebHitch(hauler);
	}
}

class GebActionUnhitchTrailer : ActionInteractBase {
	void GebActionUnhitchTrailer() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_unhitch";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(target);
		if (!trailer || !trailer.GebIsHitched() || !trailer.GebAtCoupler(player))
			return false;
		CarScript hauler = trailer.GebGetCar();
		return !hauler || GetVelocity(hauler).Length() <= geb_BoatTrailer.GEB_STOPPED;
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(action_data.m_Target);
		if (trailer)
			trailer.GebBreakOff(true);
	}
}

// The same two from the car's end, looking at the car (or its doors, hood,
// trunk or wheels) while standing at the coupler.
class GebActionHitchTrailerCar : ActionInteractBase {
	void GebActionHitchTrailerCar() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_hitch";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	static CarScript GebCarOf(ActionTarget target) {
		if (!target)
			return null;
		CarScript car = CarScript.Cast(target.GetObject());
		if (!car)
			car = CarScript.Cast(target.GetParent());
		return car;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		if (GebCarOf(target))
			geb_BoatTrailer.GebDiag("hitch, looking at the car", geb_BoatTrailer.GebDiagFromCar(GebCarOf(target), player));    // TEMPORARY
		geb_BoatTrailer trailer = geb_BoatTrailer.GebFreeTrailerFor(GebCarOf(target));
		return trailer != null && trailer.GebAtCoupler(player);
	}

	override void OnExecuteServer(ActionData action_data) {
		CarScript car = GebCarOf(action_data.m_Target);
		geb_BoatTrailer trailer = geb_BoatTrailer.GebFreeTrailerFor(car);
		if (trailer)
			trailer.GebHitch(car);
	}
}

class GebActionUnhitchTrailerCar : ActionInteractBase {
	void GebActionUnhitchTrailerCar() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_unhitch";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		CarScript car = GebActionHitchTrailerCar.GebCarOf(target);
		if (!car || GetVelocity(car).Length() > geb_BoatTrailer.GEB_STOPPED)
			return false;
		geb_BoatTrailer trailer = geb_BoatTrailer.GebTowedBy(car);
		return trailer != null && trailer.GebAtCoupler(player);
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = geb_BoatTrailer.GebTowedBy(GebActionHitchTrailerCar.GebCarOf(action_data.m_Target));
		if (trailer)
			trailer.GebBreakOff(true);
	}
}

// TEMPORARY (2026-10-13, with the auto-hitch): "Unhitch trailer" from the
// driver seat of a car towing one, stopped, while the prompts at the trailer
// don't show. The headlight switch move is in every vanilla car's seat set.
class GebActionUnhitchTrailerSeat : ActionInteractBase {
	void GebActionUnhitchTrailerSeat() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_HEADLIGHT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#STR_action_trailer_unhitch";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget() {
		return false;
	}

	override bool CanBeUsedInVehicle() {
		return true;
	}

	static CarScript GebDrivenCar(PlayerBase player) {
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if (!vehCommand)
			return null;
		CarScript car = CarScript.Cast(vehCommand.GetTransport());
		if (!car || car.CrewMemberIndex(player) != DayZPlayerConstants.VEHICLESEAT_DRIVER)
			return null;
		return car;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		CarScript car = GebDrivenCar(player);
		if (!car || GetVelocity(car).Length() > geb_BoatTrailer.GEB_STOPPED)
			return false;
		return geb_BoatTrailer.GebTowedBy(car) != null;
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = geb_BoatTrailer.GebTowedBy(GebDrivenCar(action_data.m_Player));
		if (trailer)
			trailer.GebBreakOff(true);
	}
}

class GebActionWinchBoatOn : ActionInteractBase {
	void GebActionWinchBoatOn() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_winchon";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(target);
		if (trailer)
			geb_BoatTrailer.GebDiag("winch", trailer.GebDiagWinch(player));    // TEMPORARY
		if (!trailer || !trailer.GebAtWinch(player) || !trailer.GebCarStopped())
			return false;
		return trailer.GebFindBoat() != null;
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(action_data.m_Target);
		if (!trailer)
			return;
		BoatScript boat = trailer.GebFindBoat();
		if (boat)
			trailer.GebLoadBoat(boat);
	}
}

class GebActionLaunchBoat : ActionInteractBase {
	void GebActionLaunchBoat() {
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#STR_action_trailer_launch";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsInVehicle())
			return false;
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(target);
		if (!trailer || trailer.GebBoatState() != geb_BoatTrailer.GEB_BOAT_LOADED)
			return false;
		return trailer.GebAtWinch(player) && trailer.GebCarStopped();
	}

	override void OnExecuteServer(ActionData action_data) {
		geb_BoatTrailer trailer = GebActionHitchTrailer.GebTrailerOf(action_data.m_Target);
		if (trailer)
			trailer.GebLaunchBoat();
	}
}

// A boat riding on a trailer: no getting in, no pushing.
modded class ActionGetInTransport {
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (target && geb_BoatTrailer.GebIsCarried(target.GetObject()))
			return false;
		return super.ActionCondition(player, target, item);
	}
}

modded class ActionPushBoat {
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (target && geb_BoatTrailer.GebIsCarried(target.GetObject()))
			return false;
		return super.ActionCondition(player, target, item);
	}
}

// Vanilla's push sets a car's driverless brakes back on when it ends. A
// hitched trailer keeps them off (GebJoin), or it would tow with its wheels
// braked until it was unhitched.
modded class ActionPushCar {
	override void OnEndServer(ActionData action_data) {
		super.OnEndServer(action_data);
		ActionPushObjectData data = ActionPushObjectData.Cast(action_data);
		if (!data)
			return;
		geb_BoatTrailer trailer = geb_BoatTrailer.Cast(data.m_Object);
		if (trailer && trailer.GebIsHitched())
			trailer.SetBrakesActivateWithoutDriver(false);
	}
}

// A loaded boat covers the trailer's bunks and bow roller, and the game only
// offers the actions of what the player looks at: the boat offers "Launch boat"
// too (its condition finds the trailer it rides on, GebCarrierOf).
modded class BoatScript {
	override protected void SetActions() {
		super.SetActions();
		AddAction(GebActionLaunchBoat);
	}
}
