#pragma once
#include <vector>
#include "WinFunctions.h"
#include "Entity.h"


class Entities {

private:
	WinFunc winFunc;

public:
	int amount;
	std::vector<Entity> list { amount };

	void GetEntityAmount();
	
	Entities(WinFunc wFunc)
	{
		winFunc = wFunc;
		GetEntityAmount(); // Need to init with knowing how many entities there are.
	}

	void GetInfo();
	void Print();
};
