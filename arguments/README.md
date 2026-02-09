# BOF Arguments

## Summary
This is sample code to demonstrate and test BOF argument packing and parsing.

## Encoding for COFFLoader
```
C:\Users\Administrator\Desktop\mystuff\COFFLoader>python beacon_generate.py
Beacon Argument Generator
Beacon>addString c:\test\tmp\*
Beacon>addint 1
Beacon>addint 1
Beacon>generate
b'1a0000000e000000633a5c746573745c746d705c2a000100000001000000'
Beacon>exit
C:\Users\Administrator\Desktop\mystuff\COFFLoader>
```
Example encoded values:
```
c:\test\tmp\*, 1, 1
1a0000000e000000633a5c746573745c746d705c2a000100000001000000
```

```
c:\test\tmp\*, 1, 0
1a0000000e000000633a5c746573745c746d705c2a000100000000000000
```

```
c:\test\tmp\*, 0, 0
1a0000000e000000633a5c746573745c746d705c2a000000000000000000
```

## Example Output
Running arg-parse.o with arguments: `c:\test\tmp\* 0 0` using COFFLoader
```
C:\Users\Administrator\Desktop\mystuff\COFFLoader>COFFLoader64.exe go ..\..\bof-development\arguments\arg-parse.o 1a0000000e000000633a5c746573745c746d705c2a000000000000000000
Got contents of COFF file
Running/Parsing the COFF file
[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\tmp\*
[*] Recursive Flag:  0 (FALSE)
[*] CSV Output:      0 (TEXT)
------------------------------
Ran/parsed the coff
Outdata Below:

[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\tmp\*
[*] Recursive Flag:  0 (FALSE)
[*] CSV Output:      0 (TEXT)
------------------------------


C:\Users\Administrator\Desktop\mystuff\COFFLoader>
```