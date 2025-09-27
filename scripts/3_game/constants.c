//Define Config Version Constant
const string VERSION_GEBSFISH = "3.3"; // Current version of the mod 
const int ELEVATED_DEBUG = 2; //Elevated debug mode for more info

enum GebsfishRPC { // RPC enum generation
    CONFIGSYNC = 1126192793, //Sync config file to client; call -> GebsfishRPC.CONFIGSYNC
    PLAYPREDATORSOUND //Sync Predator sound to clients around triggering player; call -> GebsfishRPC.PLAYPREDATORSOUND
};





// LEGACY CODE - Remove in version 3.5
// Define RPC constant for predator sound
const int RPC_PLAY_PREDATOR_SOUND = 2757509117; // Unique ID for the predator sound RPC

// Define RPC constant for Config Sync
const int RPC_GEBSCONFIG_SYNC = 2757509118; // Unique ID for the predator sound RPC
