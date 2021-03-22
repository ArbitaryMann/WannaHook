# WannaHook
WannaHook is an better alternative for library detours, with simple usage and stability

⚡ WMAttach (DetourFunc) -> Stable<br />
⚡ Call Function -> Stable<br />
⚡ OpenProcess (createThread) -> Stable<br />

📕  Note this down: this library is still under an development process and needs more essential updates to be more stable and handly<br />

✨  Documentation

```
#include "WannaHookLib.h"


void hookedConsole(string a1) {

    string x = "[WHDetouredInternal] ";
    string max = x.append(a1);
    AppFuncString("SafeLogToConsole",0x37DCD0, max.c_str());   /*/ a1 will directly print data from real function /*/
}
DWORD WINAPI App(LPVOID lpc) {
   
    AppFuncString("SafeLogToConsole",0x37DCD0, "this is called with wannahook lib.. %s %d"); /*/ THIS ONE IS FROM GROWTOPIA LOGSAFETOCONSOLE CALL /*/
    WHAttach(cloneFunc(0x37DCD0), hookedConsole);
    return 0;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LoadApp(App); /*/ Simple Right? /*/
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

```
