#include <iostream>
#include "Entity.h"

void Entity::Print()
{
	std::cout << "Name: " << name << "\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Position (head): (" << position_head.x << ", " << position_head.y << ", " << position_head.z << ")\n";
	std::cout << "Position (feet): (" << position_feet.x << ", " << position_feet.y << ", " << position_feet.z << ")\n";
	std::cout << "Team: " << team << "\n";
	
	std::cout << "\n\n";
}