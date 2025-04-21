#pragma once

#include "Vector2D.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void AddActorOffset(FVector2D Delta);
	void SetActorPosition(FVector2D& Pos);
protected:
	FVector2D Location;
	char Shape;
};

