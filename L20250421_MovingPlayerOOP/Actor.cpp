#include "Actor.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

void GotoXY(int X, int Y)
{
	COORD Position = { X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}

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
	GotoXY(Location.X, Location.Y);
	std::cout << Shape << std::endl;
}

void AActor::SetActorPosition(FVector2D& Pos)
{
	Location = Pos;
}
