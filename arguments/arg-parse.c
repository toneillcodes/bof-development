#include <windows.h>
#include "beacon.h"

// Entry point for the BOF
void go(char* args, int len) {
    datap parser;
    char* path = NULL;
    int recursive = 0;
    int out_mode = 0;

    // Initialize the Beacon API data parser
    BeaconDataParse(&parser, args, len);

    // UNPACK: Must match the "zii" format used in bof_pack
    path = BeaconDataExtract(&parser, NULL); // 'z' -> zero-terminated string
    recursive = BeaconDataInt(&parser);      // 'i' -> 4-byte integer
    out_mode = BeaconDataInt(&parser);       // 'i' -> 4-byte integer

    // Prepare an output buffer
    formatp buffer;
    BeaconFormatAlloc(&buffer, 1024);

    BeaconFormatPrintf(&buffer, "[+] BOF Argument Test Success!\n");
    BeaconFormatPrintf(&buffer, "------------------------------\n");
    
    // Safety check for the string
    if (path) {
        BeaconFormatPrintf(&buffer, "[*] Path Value:      %s\n", path);
    } else {
        BeaconFormatPrintf(&buffer, "[-] Path Value:      NULL (Error)\n");
    }

    // Output integers
    BeaconFormatPrintf(&buffer, "[*] Recursive Flag:  %d (%s)\n", 
                       recursive, recursive ? "TRUE" : "FALSE");
    BeaconFormatPrintf(&buffer, "[*] CSV Output:      %d (%s)\n", 
                       out_mode, out_mode ? "CSV" : "TEXT");
    
    BeaconFormatPrintf(&buffer, "------------------------------\n");

    // Flush to Beacon console
    BeaconPrintf(CALLBACK_OUTPUT, "%s", BeaconFormatToString(&buffer, NULL));

    // Clean up
    BeaconFormatFree(&buffer);
}