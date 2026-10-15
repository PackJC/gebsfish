modded class WorldData {
    // The map's own temperature for one liquid, or false when the map's
    // liquid table doesn't list it. Vanilla's GetLiquidTypeEnviroTemperature
    // can't tell the two apart: it compares Contains() (a bool) with
    // INDEX_NOT_FOUND, which always passes, so an unlisted liquid comes back
    // as 0 C. A custom map that sets its own table without fresh or sea water
    // would otherwise fish like the Arctic.
    bool GebFindLiquidTemperature(int liquidType, out float temperature) {
        if (!m_LiquidSettings || !m_LiquidSettings.m_Temperatures)
            return false;
        if (!m_LiquidSettings.m_Temperatures.Contains(liquidType))
            return false;
        temperature = m_LiquidSettings.m_Temperatures.Get(liquidType);
        return true;
    }
}
