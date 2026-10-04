// A map's WorldData can clear the yield bank right after the yield invoker
// has run (vanilla Livonia and Sakhal do, and so do some custom maps),
// wiping the mod's yields. The overrides below skip the map's own list and
// only fire the invoker. Any map not listed here is covered by
// MissionBase.GebRepairYieldBank in geb_missionbase.c, which registers the
// mod's yields again once the world data is built and keeps the map's own
// extra catches.

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

#ifdef BANOVMAP

modded class banovData {
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

