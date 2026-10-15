/*

  CREATED BY PACKJC
  https://github.com/PackJC/gebsfish
  https://steamcommunity.com/sharedfiles/filedetails/?id=2757509117
  https://discord.com/invite/G8uSGZ8yyf
  Contributions welcome via github

*/

// The Fish Drying Rack (FUTURE_IDEAS F21): an A-frame of long sticks lashed with
// rope, with six fillet slots, GebDryingRackA-F, three on each side (CfgSlots in
// data/tools/config.cpp; the fillets list them in inventorySlot[] in
// data/fish/config.cpp).
//
// Raw fillets hung on a rack standing in the world dry to the DRIED food stage
// without a fire, the way vanilla's smoking slots dry them (Cooking.SmokeItem):
// a server timer adds progress while rain and snowfall stay at or below
// DryingRackSettings.StallThreshold, faster in wind, and after MinutesToDry
// calls ChangeFoodStage(DRIED). While the weather lets them dry, fillets on the
// rack don't rot (Edible_Base.ProcessDecay in geb_ediblebase.c); in rain or
// snow they decay as usual. Progress is kept per slot through restarts and
// starts over when a fillet is taken off.
//
// The rack is assembled on the ground where its kit lies (geb_FishDryingRackKit,
// below) and stays there: once built it can't be picked up, carried or put in
// any inventory (Cole, 2026-10-14), so lay the kit where the rack should stand.
class geb_FishDryingRack : ItemBase {

	static const int GEB_DRY_SLOTS = 6;
	// Seconds between drying ticks on the server.
	static const float GEB_DRY_TICK = 10.0;
	// Saved in front of the rack's drying progress. Raise it when the saved
	// layout changes, and keep reading the layouts before it.
	static const int GEB_DRY_STORAGE_VERSION = 1;

	// Drying progress per slot (A-F), 0 to 1. Server only.
	protected ref array<float> m_GebDryProgress;
	protected ref Timer m_GebDryTimer;

	void geb_FishDryingRack() {
		m_GebDryProgress = new array<float>();
		for (int i = 0; i < GEB_DRY_SLOTS; i++)
			m_GebDryProgress.Insert(0);
	}

	// "GebDryingRackA" .. "GebDryingRackF".
	static string GebSlotName(int index) {
		string letters = "ABCDEF";
		return "GebDryingRack" + letters.Substring(index, 1);
	}

	// The rack's slot index for a slot id, -1 for any other slot.
	static int GebSlotIndex(int slotId) {
		for (int i = 0; i < GEB_DRY_SLOTS; i++) {
			if (InventorySlots.GetSlotIdFromString(GebSlotName(i)) == slotId)
				return i;
		}
		return -1;
	}

	// How a fillet model hangs. The slot proxy holds vanilla's mackerel fillet
	// by its tail; every other model is turned about its own X axis (turn), then
	// its own Z axis (yaw), in degrees, then shifted along its own X, Y and Z (in
	// metres) until its tail tip sits on the twine loop. The numbers are measured
	// on the models. A fillet on any other model isn't taken: it would hang the
	// wrong way (the lobster tails and claws and the crab legs have their own).
	static bool GebHangPose(EntityAI item, out float turn, out float yaw, out vector shift) {
		turn = 0;
		yaw = 0;
		shift = vector.Zero;
		if (!item)
			return false;
		string model;
		g_Game.ConfigGetText("CfgVehicles " + item.GetType() + " model", model);
		model.ToLower();
		if (model.Contains("mackerel_fillet"))
			return true;
		if (model.Contains("carp_fillet")) {
			turn = 180;
			shift = Vector(0.0146, 0.0081, 0.0205);
			return true;
		}
		if (model.Contains("steelhead_trout_fillet")) {
			shift = Vector(-0.0068, -0.0071, -0.0267);
			return true;
		}
		if (model.Contains("walleye_pollock_fillet")) {
			shift = Vector(-0.0099, 0.0040, -0.0030);
			return true;
		}
		// ---- Catfish-model fillets: BEGIN ----
		// Vanilla's DayZ 1.30 CatfishFilletMeat and the mod's fillets on its model
		// lie along their Y axis: a quarter turn stands them up, a half turn about
		// the vertical shows the flesh side like the others. Delete this block, and
		// the CatfishFilletMeat block in data/fish/config.cpp, to take them off.
		if (model.Contains("catfish_fillet")) {
			turn = -90;
			yaw = 180;
			shift = Vector(-0.0289, -0.0086, 0.0288);
			return true;
		}
		// ---- Catfish-model fillets: END ----
		return false;
	}

	// An animation phase for an angle: one full turn per phase.
	static float GebTurnPhase(float degrees) {
		float phase = degrees / 360.0;
		while (phase < 0)
			phase += 1.0;
		return phase;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		// Only a rack standing in the world takes fillets, as with the fish
		// mounts: vanilla's take action looks for a free spot through everything
		// the player carries, slots included.
		if (GetHierarchyParent())
			return false;

		if (IsRuined())
			return false;

		Edible_Base food = Edible_Base.Cast(attachment);
		if (!food || food.IsRuined())
			return false;
		if (food.HasFoodStage() && food.GetFoodStageType() == FoodStageType.ROTTEN)
			return false;

		float turn;
		float yaw;
		vector shift;
		return GebHangPose(attachment, turn, yaw, shift);
	}

	override void EEInit() {
		super.EEInit();
		GebStartDrying();
	}

	override void EEDelete(EntityAI parent) {
		if (m_GebDryTimer)
			m_GebDryTimer.Stop();
		super.EEDelete(parent);
	}

	// Runs on the server and on every client that sees the fillet, so each side
	// poses it from the same table (the fish mounts do the same).
	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		int index = GebSlotIndex(InventorySlots.GetSlotIdFromString(slot_name));
		if (index < 0)
			return;
		GebPoseFillet(index, item);
		GebStartDrying();
	}

	// A fillet taken off starts over the next time it is hung. Attachments
	// coming back after a restart only attach, so saved progress survives.
	override void EEItemDetached(EntityAI item, string slot_name) {
		super.EEItemDetached(item, slot_name);
		int index = GebSlotIndex(InventorySlots.GetSlotIdFromString(slot_name));
		if (index < 0)
			return;
		m_GebDryProgress[index] = 0;
		GebPoseFillet(index, null);
	}

	// Covers a load order where the rack's own state arrives after its fillets.
	override void AfterStoreLoad() {
		super.AfterStoreLoad();
		for (int i = 0; i < GEB_DRY_SLOTS; i++)
			GebPoseFillet(i, GebFilletAt(i));
		GebStartDrying();
	}

	override void OnStoreSave(ParamsWriteContext ctx) {
		super.OnStoreSave(ctx);
		int storage = GEB_DRY_STORAGE_VERSION;
		ctx.Write(storage);
		for (int i = 0; i < GEB_DRY_SLOTS; i++) {
			float progress = m_GebDryProgress[i];
			ctx.Write(progress);
		}
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version) {
		if (!super.OnStoreLoad(ctx, version))
			return false;
		int storage;
		if (!ctx.Read(storage))
			return true;   // nothing saved after the base data: start from empty
		// A layout from a newer build than this one: keep the rack, drop the progress.
		if (storage < 1 || storage > GEB_DRY_STORAGE_VERSION)
			return true;
		for (int i = 0; i < GEB_DRY_SLOTS; i++) {
			float progress;
			if (!ctx.Read(progress))
				return false;
			m_GebDryProgress[i] = Math.Clamp(progress, 0, 1);
		}
		return true;
	}

	protected EntityAI GebFilletAt(int index) {
		if (!GetInventory())
			return null;
		return GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString(GebSlotName(index)));
	}

	// Sets the slot's hang_<x>_* animations (Model.cfg fishdryingrack) for the
	// fillet on it, or back to rest for an empty slot.
	protected void GebPoseFillet(int index, EntityAI item) {
		float turn = 0;
		float yaw = 0;
		vector shift = vector.Zero;
		if (item)
			GebHangPose(item, turn, yaw, shift);
		string letters = "abcdef";
		string prefix = "hang_" + letters.Substring(index, 1) + "_";
		SetAnimationPhase(prefix + "x", 0.5 + shift[0] / 4.0);
		SetAnimationPhase(prefix + "y", 0.5 + shift[1] / 4.0);
		SetAnimationPhase(prefix + "z", 0.5 + shift[2] / 4.0);
		SetAnimationPhase(prefix + "turn", GebTurnPhase(turn));
		SetAnimationPhase(prefix + "yaw", GebTurnPhase(yaw));
	}

	// ------------------------------------------------------------ drying

	static DryingRackConf GebDryConf() {
		if (!m_gebsConfig || !m_gebsConfig.General)
			return null;
		return m_gebsConfig.General.DryingRackSettings;
	}

	// True while rain and snowfall are both at or below StallThreshold.
	static bool GebIsDryingWeather(DryingRackConf cfg) {
		Weather weather = g_Game.GetWeather();
		if (!cfg || !weather)
			return false;
		float wet = 0;
		if (weather.GetRain())
			wet = weather.GetRain().GetActual();
		if (weather.GetSnowfall())
			wet = Math.Max(wet, weather.GetSnowfall().GetActual());
		return wet <= cfg.StallThreshold;
	}

	// 1 in still air, 1 + WindScale at the map's strongest wind.
	static float GebWindFactor(DryingRackConf cfg) {
		Weather weather = g_Game.GetWeather();
		if (!cfg || !weather || weather.GetWindMaximumSpeed() <= 0)
			return 1.0;
		float wind = Math.Clamp(weather.GetWindSpeed() / weather.GetWindMaximumSpeed(), 0, 1);
		return 1.0 + Math.Max(cfg.WindScale, 0) * wind;
	}

	// Whether fillets on this rack are drying right now: drying is on, the rack
	// stands in the world, isn't ruined, and the weather is dry enough. Also
	// what pauses their decay (geb_ediblebase.c).
	bool GebIsDrying() {
		if (GetHierarchyParent() || IsRuined())
			return false;
		DryingRackConf cfg = GebDryConf();
		return cfg && cfg.Enable && GebIsDryingWeather(cfg);
	}

	protected void GebStartDrying() {
		if (!g_Game.IsServer())
			return;
		if (!GetInventory() || GetInventory().AttachmentCount() == 0)
			return;
		if (!m_GebDryTimer)
			m_GebDryTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
		if (!m_GebDryTimer.IsRunning())
			m_GebDryTimer.Run(GEB_DRY_TICK, this, "GebDryTick", null, true);
	}

	// Server, every GEB_DRY_TICK seconds while the rack holds a fillet.
	void GebDryTick() {
		if (!GetInventory() || GetInventory().AttachmentCount() == 0) {
			m_GebDryTimer.Stop();
			return;
		}
		if (!GebIsDrying())
			return;
		DryingRackConf cfg = GebDryConf();
		float minutes = Math.Max(cfg.MinutesToDry, 0.1);
		float step = GEB_DRY_TICK * GebWindFactor(cfg) / (minutes * 60.0);
		for (int i = 0; i < GEB_DRY_SLOTS; i++) {
			Edible_Base fillet = Edible_Base.Cast(GebFilletAt(i));
			if (!fillet || !fillet.HasFoodStage() || fillet.GetFoodStageType() != FoodStageType.RAW || fillet.GetIsFrozen())
				continue;
			m_GebDryProgress[i] = m_GebDryProgress[i] + step;
			if (m_GebDryProgress[i] >= 1.0) {
				fillet.ChangeFoodStage(FoodStageType.DRIED);
				fillet.ResetCookingTime();
				m_GebDryProgress[i] = 0;
			}
		}
	}

	// ------------------------------------------------------------ staying put

	// A built rack stays where it was assembled: no "Pick up", no dragging it
	// into hands or any inventory. (It used to be carried and placed with
	// vanilla's hologram; the kit took over its placing.)
	override bool CanPutIntoHands(EntityAI parent) {
		return false;
	}

	override bool CanPutInCargo(EntityAI parent) {
		return false;
	}
}

// The Fish Drying Rack Kit: a long stick and a rope (CraftDryingRack). Long
// sticks don't stack in DayZ 1.30 (varStackMax 1) outside a slot that allows it,
// so the rack's other six go into the kit's GebDryingRackSticks slot (stackMax 6,
// data/tools/config.cpp), one at a time, with the kit lying on the ground, the
// way a shelter's frame takes its sticks. With all six in, "Assemble drying
// rack" (GebActionAssembleDryingRack) turns the kit and its sticks into the rack
// where the kit lies.
class geb_FishDryingRackKit : ItemBase {

	static const int GEB_KIT_STICKS = 6;

	// Long sticks in the kit's slot, 0 to GEB_KIT_STICKS.
	int GebStickCount() {
		if (!GetInventory())
			return 0;
		ItemBase sticks = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("GebDryingRackSticks")));
		if (!sticks)
			return 0;
		int count = sticks.GetQuantity();
		return count;
	}

	// Ready to assemble: lying in the world, not ruined, all six sticks in.
	bool GebCanAssemble() {
		return !GetHierarchyParent() && !IsRuined() && GebStickCount() >= GEB_KIT_STICKS;
	}

	// Sticks go in only while the kit lies on the ground ...
	override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;
		return !GetHierarchyParent();
	}

	// ... and a kit holding sticks stays there: six 1x8 long sticks must not
	// travel as one 1x5 kit in a backpack.
	override bool CanPutInCargo(EntityAI parent) {
		if (!super.CanPutInCargo(parent))
			return false;
		return GebStickCount() == 0;
	}

	override bool CanPutIntoHands(EntityAI parent) {
		if (!super.CanPutIntoHands(parent))
			return false;
		return GebStickCount() == 0;
	}

	// Server: the rack takes the kit's place, upright and turned the kit's way;
	// the kit and its sticks are used up.
	void GebAssemble() {
		if (!g_Game.IsServer() || !GebCanAssemble())
			return;
		vector at = GetPosition();
		vector turn = GetOrientation();
		EntityAI rack = EntityAI.Cast(g_Game.CreateObjectEx("geb_FishDryingRack", at, ECE_PLACE_ON_SURFACE));
		if (!rack)
			return;
		rack.SetOrientation(Vector(turn[0], 0, 0));
		DeleteSafe();
	}

	override void SetActions() {
		super.SetActions();
		AddAction(GebActionAssembleDryingRack);
	}
}
