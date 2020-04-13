#include "Mathematics.h"
#include <cmath>
#include <iostream>

bool Mathematics::WorldToScreen(vec3d_f pos, vec3d_f& screen, float matrix[16], int windowWidth, int windowHeight)
{
	
	Mathematics::clipCoords.x = pos.x * matrix[0] + pos.y * matrix[4] + pos.z * matrix[8] + matrix[12];
	Mathematics::clipCoords.y = pos.x * matrix[1] + pos.y * matrix[5] + pos.z * matrix[9] + matrix[13];
	Mathematics::clipCoords.z = pos.x * matrix[2] + pos.y * matrix[6] + pos.z * matrix[10] + matrix[14];
	Mathematics::clipCoords.w = pos.x * matrix[3] + pos.y * matrix[7] + pos.z * matrix[11] + matrix[15];

	if (clipCoords.w < 0.1f)
	{
		return false;
	}

	Mathematics::NDC.x = clipCoords.x / clipCoords.w;
	Mathematics::NDC.y = clipCoords.y / clipCoords.w;
	Mathematics::NDC.z = clipCoords.z / clipCoords.w;

	Mathematics::screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	Mathematics::screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
	
	return true;
}

float Mathematics::GetDistance3D(vec3d_f m_pos, vec3d_f en_pos)
{
	return (float)(sqrt(((en_pos.x - m_pos.x) * (en_pos.x - m_pos.x)) + ((en_pos.y - m_pos.y) * (en_pos.y - m_pos.y)) + ((en_pos.z - m_pos.z) * (en_pos.z - m_pos.z))));
}

float Mathematics::GetDistance2D(vec3d_f m_pos, vec3d_f en_pos)
{
	return { (float)(sqrt(
	((en_pos.x - m_pos.x) * (en_pos.x - m_pos.x))
	+ ((en_pos.z - m_pos.z) * (en_pos.z - m_pos.z))
	)) };
}

vec3d_f Mathematics::CalculateAngles(vec3d_f m_pos, vec3d_f en_pos)
{

	vec3d_f values;

	float aTriangle = en_pos.x - m_pos.x;
	float bTriangle = en_pos.z - m_pos.z;
	float yTriangle = en_pos.y - m_pos.y;

	float triangleHyp = Mathematics::GetDistance2D(m_pos, en_pos);

	float yaw = -(float)(atan2(aTriangle, bTriangle) * (HALF_CIRCLE / MATH_PI) + HALF_CIRCLE);
	float pitch = (float)((atan2(yTriangle, triangleHyp)) * (HALF_CIRCLE / MATH_PI));

	values.x = yaw;
	values.y = pitch;
	values.z = 0;
	return values;
}