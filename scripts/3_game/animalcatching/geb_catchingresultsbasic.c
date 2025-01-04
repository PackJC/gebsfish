modded class CatchingResultBasic {

    string GebGetFishingResultName(){ //helper function for cftools logging; outputs the item type name
        string gebFishName = m_YItem.GetType();
        return gebFishName;
    }
}