#pragma once

struct Vector3
{
	float X;
	float Y;
	float Z;
};

class AActor
{
public:
	Vector3 Location;
	Vector3 Rotation;
	Vector3 Scale;

};

