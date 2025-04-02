modded class CatchingContextBase {
    //helper function for cftools logging; outputs the display name of the catch.
    string GebGetCatchingResult() { 
        string geboutput = m_Result.GebGetFishingResultName();
        return geboutput;
    }
}