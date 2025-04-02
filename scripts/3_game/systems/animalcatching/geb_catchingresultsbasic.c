modded class CatchingResultBasic {
    //helper function for cftools logging; outputs the item type name
    string GebGetFishingResultName(){ 
        string gebFishName = m_YItem.GetType();
        return gebFishName;
    }
}