#pragma once
#include "Grid.h"

class CFindingPath
{
public:
	void StartFindingPath();
	void PrintGrid();
private:
	CGrid Grid;
	void RetracePath();
	int GetDistance(CNode* Start, CNode* Target);
};

