//Define Config Version Constant
const string VERSION_GEBSFISH = "4.0.0"; // Current version of the mod
const int ELEVATED_DEBUG = 2; //Elevated debug mode for more info

// NOTE: the old GebsfishRPC enum of integer RPC ids was removed with the CF
// migration -- Community Framework addresses RPCs by string name instead
// (GetRPCManager().SendRPC("gebsfish", "ConfigSync", ...)), so the numeric
// ids had no remaining callers.
