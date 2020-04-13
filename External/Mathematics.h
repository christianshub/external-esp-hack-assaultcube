#pragma once
#include "WinFunctions.h"
#include "Structs.h"

class Mathematics {

private:
	WinFunc winFunc;
	const double MATH_PI = 3.14159265359f;
	const int HALF_CIRCLE = 180;

public:

	vec3d_f screen;
	vec4d_f clipCoords;
	vec4d_f NDC;

	Mathematics(WinFunc wFunc)
	{
		winFunc = wFunc;
	}

	bool WorldToScreen(vec3d_f pos, vec3d_f& screen, float matrix[16], int windowWidth, int windowHeight);

	float GetDistance3D(vec3d_f m_pos, vec3d_f en_pos);
	float GetDistance2D(vec3d_f m_pos, vec3d_f en_pos);

	vec3d_f CalculateAngles(vec3d_f m_pos, vec3d_f en_pos);
	
	void GetInfo();
	void Print();
};
