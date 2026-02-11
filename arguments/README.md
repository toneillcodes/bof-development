# BOF Arguments

## Summary
This is sample code to demonstrate and test BOF argument packing and parsing.

## Testing with COFFLoader
### Encoding Arguments
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

### Example COFFLoader Output
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

## Testing with Beacon
### Example BOF Output
Path is required, but recursive and out arguments are optional:
```
[02/11 17:18:52] beacon> arg-parse /recursive:false /out:true
[02/11 17:18:52] [-] Missing required argument. Usage: arg-parse /path:C:\target [/recursive:true|false] [/out:true|false]
```

Running with only the path defined (recursive and out default to 0):
```
[02/11 17:15:42] beacon> arg-parse /path:c:\test\*
[02/11 17:15:42] [*] Tasked arg-parse execution
[02/11 17:16:10] [+] host called home, sent: 1282 bytes
[02/11 17:16:10] [+] received output:
[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\*
[*] Recursive Flag:  0 (FALSE)
[*] CSV Output:      0 (TEXT)
------------------------------
```

Running with only the path and recursive defined (out default to 0):
```
[02/11 17:16:35] beacon> arg-parse /path:c:\test\* /recursive:true
[02/11 17:16:35] [*] Tasked arg-parse execution
[02/11 17:16:35] [+] host called home, sent: 1282 bytes
[02/11 17:16:35] [+] received output:
[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\*
[*] Recursive Flag:  1 (TRUE)
[*] CSV Output:      0 (TEXT)
------------------------------
```

Running with all three arguments and no default values:
```
[02/11 17:16:41] beacon> arg-parse /path:c:\test\* /recursive:true /out:true
[02/11 17:16:41] [*] Tasked arg-parse execution
[02/11 17:16:58] [+] host called home, sent: 1282 bytes
[02/11 17:16:58] [+] received output:
[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\*
[*] Recursive Flag:  1 (TRUE)
[*] CSV Output:      1 (CSV)
------------------------------
```

Running with arguments in a different order than the BOF is expecting:
```
[02/11 17:17:29] beacon> arg-parse /recursive:false /path:c:\test\* /out:true
[02/11 17:17:29] [*] Tasked arg-parse execution
[02/11 17:17:43] [+] host called home, sent: 1282 bytes
[02/11 17:17:43] [+] received output:
[+] BOF Argument Test Success!
------------------------------
[*] Path Value:      c:\test\*
[*] Recursive Flag:  0 (FALSE)
[*] CSV Output:      1 (CSV)
------------------------------
```