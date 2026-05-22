//Define Config Version Constant
const string VERSION_GEBSFISH = "3.3"; // Current version of the mod 
const int ELEVATED_DEBUG = 2; //Elevated debug mode for more info

enum GebsfishRPC { // RPC enum generation
    CONFIGSYNC = 1126192793, //Sync config file to client; call -> GebsfishRPC.CONFIGSYNC
    PLAYPREDATORSOUND //Sync Predator sound to clients around triggering player; call -> GebsfishRPC.PLAYPREDATORSOUND
};