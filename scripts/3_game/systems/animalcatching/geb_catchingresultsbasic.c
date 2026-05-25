modded class CatchingResultBasic {
    // Returns the species classname (e.g. "geb_BlueGill") of the yield this
    // result is bound to. Used by the catching context's debug logs to print
    // a readable identifier for the pre-determined catch -- vanilla's default
    // object-to-string on YieldItemBase produces an array-like dump that's
    // not useful in logs.
    string GebGetFishingResultName() {
        if (!m_YItem)
            return "<unresolved>";
        return m_YItem.GetType();
    }
}