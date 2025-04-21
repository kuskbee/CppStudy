#pragma once
#include <vector>

class Floor
{
public:
	Floor() : SizeX(10), SizeY(10), Length(100) {}
	Floor(int SizeX, int SizeY) : SizeX(SizeX), SizeY(SizeY), Length(SizeX* SizeY) {}

	void Initialize();
	void Draw();

private:
	std::vector<char> Grid;

	int SizeX;
	int SizeY;
	int Length;
};

