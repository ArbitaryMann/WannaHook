#include "pch.h"
#include "WannaHookLib.h"

typedef void(__cdecl* _func)(...);
_func CallFunction;

string AppFuncString(long addr,string fmt) {
	CallFunction = (_func)((uint64_t)GetModuleHandleA(NULL) + addr);
	CallFunction(fmt); /*/ This one is for String etc /*/ 
	return fmt;
}

int AppFuncInteger(long addr, int fmt) {
	CallFunction = (_func)((uint64_t)GetModuleHandleA(NULL) + addr);
	CallFunction(fmt); /*/ This one is for String etc /*/
	return fmt;
}
float AppFuncFloat(long addr, float fmt) {
	CallFunction = (_func)((uint64_t)GetModuleHandleA(NULL) + addr);
	CallFunction(fmt); /*/ This one is for String etc /*/
	return fmt;
}
void* cloneFunc(long addr) {
	
	return CallFunction = (_func)((uint64_t)GetModuleHandleA(NULL) + addr);
}
bool WHAttach(void* lpbase, void* Internalfunc)
{
	

	
	VirtualProtect(lpbase, 5, PAGE_EXECUTE_READWRITE, NULL);

	memset(lpbase, 0x90, 5);

	uintptr_t funcToAttach = ((uintptr_t)Internalfunc - (uintptr_t)lpbase) - 5;

	*(BYTE*)lpbase = 0xE9;
	*(uintptr_t*)((uintptr_t)lpbase + 1) = funcToAttach;

	DWORD temp;
	VirtualProtect(lpbase, 5, NULL, NULL);

	return true;
}
int LoadApp(LPTHREAD_START_ROUTINE aa) {
	CreateThread(0, 0, aa, 0, 0, 0); /*/ Easier to Load Func Main  /*/
	return 0;
}