#pragma once
#include <windows.h>

class WinFunc
{

public:

	DWORD processID;
	HANDLE processHandle;
	//static HWND windowHandle;
	
	static DWORD GetPID(LPCSTR process_name);

	static HANDLE GetHandle(DWORD pid);

	void GetInfo(LPCSTR process_name);
	void Print();

	template <class T>
	T Read(LPCVOID address)
	{
		T VALUE;
		ReadProcessMemory(processHandle, (LPCVOID)(address), &VALUE, sizeof(T), 0);
		return VALUE;
	}
};