#include <windows.h>
#include "beacon.h"

// The 'go' function is the default entry point for BOFs
void go(char* args, int len) {
    
    // CALLBACK_OUTPUT sends the text back to the Beacon console
    // This behaves similarly to printf()
    BeaconPrintf(CALLBACK_OUTPUT, "Hello World from a BOF!\n");
}