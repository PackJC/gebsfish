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
// in CreateYieldBank), so super + a second Invoke ran the yield registration
// twice per boot -- and if the map's own InitYieldBank clears the bank, the
// re-entry guard in geb_missionbase would leave that clear unrepaired.
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

// #ifdef AlteriaScripts no world data for alteria yet. 

// modded class AlteriaData {
//     override void InitYieldBank() {
// 		    GetDayZGame().GetYieldDataInitInvoker().Invoke(m_YieldBank);
//     }
// }

// #endif