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