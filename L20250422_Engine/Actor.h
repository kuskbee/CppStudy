#pragma once
#include "Vector2D.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void AddActorWorldOffset(FVector2D Offset);
	FVector2D Location;

	char Shape;
};

