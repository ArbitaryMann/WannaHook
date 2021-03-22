#pragma once
#include <string>
using namespace std;

string AppFuncString(long addr, string fmt);
float AppFuncFloat(long addr, float fmt);
int LoadApp(LPTHREAD_START_ROUTINE aa);
bool WHAttach(void* lpbase, void* Internalfunc);
void* cloneFunc(long addr);