/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

class ActionSpearFishCB : ActionContinuousBaseCB {
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(2.5);
	}
};

// "Spear Fish" on the vanilla spears (Spear / SpearStone / SpearBone): aim at
// a fish from a chum school (GebsChumSystem) and stab. The caught fish is the
// actual swimming entity and rides the spear's GebSpearedFish attachment slot
// (data/tools/config.cpp); if the slot is taken the fish lands at the
// player's feet instead.
class ActionSpearFish : ActionContinuousBase {
	void ActionSpearFish() {
		m_CallbackClass = ActionSpearFishCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_POKE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#str_geb_action_spearfish";
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		// REPAIR (3m) -- a spear has reach, but the fish still has to be close.
		m_ConditionTarget = new CCTObject(UAMaxDistances.REPAIR);
	}

	// A chum swimmer is the only fish item in the world that is underwater AND
	// non-takeable (GebsChumSystem sets SetTakeable(false) on spawn), so the
	// client can identify one without access to the server-side school list.
	// The server-side registry stays authoritative: OnFinishProgressServer
	// only lands the catch when ClaimFish finds the entity in a live school.
	protected bool IsChumSwimmer(Object obj) {
		ItemBase fishItem = ItemBase.Cast(obj);
		if (!fishItem || fishItem.IsTakeable())
			return false;
		if (fishItem.GetHierarchyRoot() != fishItem)
			return false; // attached/carried somewhere, not swimming
		return g_Game.GetWaterDepth(fishItem.GetPosition()) > 0.05;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		if (player.IsPlacingLocal())
			return false;

		ChumConf conf = GebsChumSystem.GetConf();
		if (conf && !conf.Enable)
			return false;

		if (!target)
			return false;
		return IsChumSwimmer(target.GetObject());
	}

	override bool ActionConditionContinue(ActionData action_data) {
		return true;
	}

	override bool HasTarget() {
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		if (!action_data || !action_data.m_Player || !action_data.m_Target)
			return;

		PlayerBase player = action_data.m_Player;
		ItemBase spear = action_data.m_MainItem;

		// The school may have expired (or the fish been speared by someone
		// else) during the stab -- ClaimFish returning null is the miss case.
		ItemBase fish = GebsChumSystem.ClaimFish(action_data.m_Target.GetObject());
		if (!fish) {
			player.MessageStatus(Widget.TranslateString("#str_geb_spearfish_missed"));
			return;
		}

		// Ride the spear when the slot is free; otherwise drop the catch at
		// the player's feet. ServerTakeToDst keeps the entity (and therefore
		// its weight/quality) instead of respawning a fresh item.
		bool attached = false;
		if (spear) {
			int slotId = InventorySlots.GetSlotIdFromString("GebSpearedFish");
			if (slotId != InventorySlots.INVALID && !spear.GetInventory().FindAttachment(slotId)) {
				InventoryLocation src = new InventoryLocation;
				InventoryLocation dst = new InventoryLocation;
				if (fish.GetInventory().GetCurrentInventoryLocation(src)) {
					dst.SetAttachment(spear, fish, slotId);
					attached = player.ServerTakeToDst(src, dst);
				}
			}
			spear.DecreaseHealth("", "", 5);
		}

		if (!attached) {
			fish.SetPosition(player.GetPosition());
			fish.PlaceOnSurface();
		}

		player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
		player.MessageStatus(Widget.TranslateString("#str_geb_spearfish_success"));
	}
};
