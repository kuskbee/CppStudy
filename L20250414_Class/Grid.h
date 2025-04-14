#pragma once
#include <vector>
#include <string>

#include "Node.h"

using namespace std;

class CGrid
{
public:
	CGrid();

	void PrintGrid();
	vector<CNode*> GetNeighbour(CNode* CurrentNode);

	vector<vector<CNode>> Grid;
	CNode* StartNode = nullptr;
	CNode* TargetNode = nullptr;
private:
	int GridSizeX;
	int GridSizeY;

	void ReadFromFile(string FileName);
};

