#include <iostream>
#include "Windows.h"
#include "Actor.h"

AActor::AActor()
{
	Shape = ' ';
}

AActor::~AActor()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{
	COORD Position = { (SHORT)Location.X, (SHORT)Location.Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;
}

void AActor::AddActorWorldOffset(FVector2D Offset)
{
	Location.X += Offset.X;
	Location.Y += Offset.Y;
}