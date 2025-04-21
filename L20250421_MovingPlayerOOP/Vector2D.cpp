#include "Vector2D.h"

void FVector2D::Add(FVector2D Delta)
{
	X += Delta.X;
	Y += Delta.Y;
}
