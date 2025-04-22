#include "Actor.h"

AActor::AActor()
{

}

AActor::~AActor()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{

}

void AActor::AddActorWorldOffset(FVector2D Offset)
{
	Location.X += Offset.X;
	Location.Y += Offset.Y;
}