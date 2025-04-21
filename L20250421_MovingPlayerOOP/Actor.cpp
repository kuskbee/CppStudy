#include "Actor.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

void GotoXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
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
