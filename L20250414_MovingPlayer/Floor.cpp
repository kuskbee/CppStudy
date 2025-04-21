#include "Floor.h"
#include <iostream>

void Floor::Initialize()
{
	Grid.assign(Length, ' ');
	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			if (i == 0 || j == 0 || i == SizeY - 1 || j == SizeX - 1)
			{
				int Idx = i * SizeX + j;
				Grid[Idx] = '*';
			}
		}
	}
}

void Floor::Draw()
{
	for (int i = 0; i < SizeY; i++)
	{
		for (int j = 0; j < SizeX; j++)
		{
			int Idx = i * SizeX + j;
			std::cout << Grid[Idx] << std::endl;
		}
	}
}
