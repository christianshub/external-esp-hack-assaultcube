#include "WinFunctions.h"
#include <iostream>

DWORD WinFunc::GetPID(LPCSTR process_name) {

	DWORD processID;
	HWND windowHandle = FindWindowA(nullptr, process_name);
	GetWindowThreadProcessId(windowHandle, &processID);

	return processID;
}

HANDLE WinFunc::GetHandle(DWORD pid) {
	return OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE, false, pid);
}


void WinFunc::GetInfo(LPCSTR process_name)
{
	processID = GetPID(process_name);
	processHandle = GetHandle(processID);
}

void WinFunc::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "=========== Game ============" << "\n";
	std::cout << "=============================" << "\n\n";

	std::cout << "PID:    " << processID << "\n";
	std::cout << "Handle: " << processHandle << "\n";

	std::cout <<"\n\n";
}