#pragma once

class FVector2D
{
public:
	int X;
	int Y;

	FVector2D() : X(0), Y(0) {}
	FVector2D(int X, int Y) : X(X), Y(Y) {}

	void Add(FVector2D Delta);
};

