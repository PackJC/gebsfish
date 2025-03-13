modded class CatchingContextBase {

    string GebGetCatchingResult() { //helper function for cftools logging; outputs the display name of the catch.
        string geboutput = m_Result.GebGetFishingResultName();
        return geboutput;
    }
}