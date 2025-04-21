#pragma once

struct Point
{
	int X = 0;
	int Y = 0;
};

class AActor
{
public:
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();
	
	Point Location;
	char Shape;
};

