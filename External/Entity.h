#pragma once
#include "Structs.h"

class Entity {

public:

	char name[20];
	int base;
	int health;
	vec3d_f position_head;
	vec3d_f position_feet;
	int team;

	void Print();
};