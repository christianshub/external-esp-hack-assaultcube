#include <Windows.h>
#include <vector>
#include <iostream>
#include "Entities.h"
#include "WinFunctions.h"
#include "Offsets.h"

// ENTITIES
void Entities::GetEntityAmount()
{	
	amount = winFunc.Read<int>(LPCVOID(players_in_map));
}

void Entities::GetInfo()
{
	list.resize(amount);
	for (int i = 1; i < amount; i++)
	{
		ReadProcessMemory(winFunc.processHandle, LPCVOID(entity_base), &list[i].base, sizeof(list[i].base), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + (0x4 * i)), &list[i].base, sizeof(list[i].base), nullptr);
		ReadProcessMemory(winFunc.processHandle, (PBYTE*)(list[i].base + of_name), &list[i].name, sizeof(list[i].name), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_health), &list[i].health, sizeof(list[i].health), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posx), &list[i].position_head.x, sizeof(list[i].position_head.x), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posy), &list[i].position_head.y, sizeof(list[i].position_head.y), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posz), &list[i].position_head.z, sizeof(list[i].position_head.z), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_team), &list[i].team, sizeof(list[i].team), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posx_normal), &list[i].position_feet.x, sizeof(list[i].position_feet.x), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posy_normal), &list[i].position_feet.y, sizeof(list[i].position_feet.y), nullptr);
		ReadProcessMemory(winFunc.processHandle, LPCVOID(list[i].base + of_posz_normal), &list[i].position_feet.z, sizeof(list[i].position_feet.z), nullptr);
	}
}

void Entities::Print()
{
	std::cout << "=============================" << "\n";
	std::cout << "========= Entities ==========" << "\n";
	std::cout << "=============================" << "\n\n";
	
	for (int i = 1; i < amount; i++)
	{
		list[i].Print();
	}
	
	std::cout << "\n\n";
}