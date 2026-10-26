// A map's WorldData can clear the yield bank right after the yield invoker
// has run (vanilla Livonia and Sakhal do, and so do some custom maps),
// wiping the mod's yields. The overrides below skip the map's own list and
// only fire the invoker. Any map not listed here is covered by
// MissionBase.GebRepairYieldBank in geb_missionbase.c, which registers the
// mod's yields again once the world data is built and keeps the map's own
// extra catches. Vanilla ChernarusPlusData has no InitYieldBank of its own
// (WorldData's only fires the invoker), so its hook does the same thing; it
// is kept so all three vanilla maps go through one path.
//
// None of them calls super, on purpose. On Livonia and Sakhal super would
// also run their vanilla clear-and-list, and every catch on those lists would
// come back wherever an admin's files leave it out: an emptied junk table
// (the config keeps one) would still catch vanilla's wellies and pot, and a
// deleted fish row would come back at vanilla's weight. The cost: a mod
// loaded before gebsfish that adds catches to these maps in its own
// InitYieldBank override loses them. One loaded after keeps them, since its
// super runs the override here.

modded class SakhalData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

modded class EnochData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

modded class ChernarusPlusData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#ifdef Deadfall_Data
//Credits and huge thank you to DapperDan for figuring out world data classname
// No super call, matching every other world override here: vanilla's
// InitYieldBank only fires this same invoker (the bank is created separately
// in CreateYieldBank), and Deadfall's own InitYieldBank clears the bank right
// after it, so super + a second Invoke would register the yields twice per
// boot for nothing.
modded class DeadfallData
{
    override void InitYieldBank()
    {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
};

#endif

// Banov and BanovFrost ship the same Banovmap.pbo, whose common script
// #defines BANOVMAP, so BANOVMAP is set on both maps. Gated on it, the hook on
// Banov's BanovData stopped the World module compiling on BanovFrost, which has
// no such class: its world data is BanovFrostData. Each hook is gated on the
// CfgPatches class of the scripts PBO that declares its world data instead,
// a name only that map has: BanovMiscScripts (BanovScripts.pbo,
// scripts/4_World/banov.c) and BanovfrostMiscScripts (BanovFrostScripts.pbo,
// scripts/4_World/banovfrost.c). A hook left out costs no fish: both maps
// clear the catch list in their own InitYieldBank, and
// MissionBase.GebRepairYieldBank then puts the mod's catches back.
#ifdef BanovMiscScripts

// Banov's WorldData was banovData until Banov renamed it BanovData; the old
// name stopped the World module compiling on Banov servers.
modded class BanovData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif

#ifdef BanovfrostMiscScripts

modded class BanovFrostData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif

#ifdef NAMALSK_SURVIVAL

modded class NamalskData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif

#ifdef TemScriptsMod

modded class LuxData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif

#ifdef DeerIsleScripts

modded class DeerisleData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif

#ifdef NavalScripts

modded class NavalPlusData {
    override void InitYieldBank() {
        GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
    }
}

#endif
