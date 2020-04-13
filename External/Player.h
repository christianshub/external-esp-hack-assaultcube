#pragma once
#include "WinFunctions.h"
#include "Structs.h"

class Player {

private:
	WinFunc winFunc;
	
public:

	char name[20];
	int base;
	int health;
	float matrix[16];
	vec2d_f screen;
	vec3d_f position_head;
	vec3d_f position_feet;
	int team;
	
	Player(WinFunc wFunc)
	{
		winFunc = wFunc;
	}

	void GetInfo();
	void Print();
};
