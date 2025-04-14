#include "Grid.h"
#include <iostream>
#include <fstream>

CGrid::CGrid()
{
	ReadFromFile("matrix.txt");
}

void CGrid::PrintGrid()
{
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			Grid[y][x].PrintNode();
		}
		cout << endl;
	}
}

vector<CNode*> CGrid::GetNeighbour(CNode* CurrentNode)
{
	vector<CNode*> Neighbours;

	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			if (x == 0 && y == 0) continue;

			int IdxX = CurrentNode->Col + x;
			int IdxY = CurrentNode->Row + y;

			if (IdxX >= 0 && IdxX < GridSizeX && IdxY >= 0 && IdxY < GridSizeY)
			{
				if (Grid[IdxY][IdxX].NodeType != EN_NODETYPE::Wall)
				{
					Neighbours.push_back(&Grid[IdxY][IdxX]);
				}
			}
		}
	}

	return Neighbours;
}

void CGrid::ReadFromFile(string FileName)
{
	fstream File(FileName);
	if (!File)
	{
		cerr << "파일 열기 실패 " << FileName << endl;
	}

	File >> GridSizeX >> GridSizeY;
	Grid.assign(GridSizeY, vector<CNode>(GridSizeX));
	
	for (int y = 0; y < GridSizeY; y++)
	{
		for (int x = 0; x < GridSizeX; x++)
		{
			int Type;
			File >> Type;
			Grid[y][x] = CNode(y, x, static_cast<EN_NODETYPE>(Type));
			if (Grid[y][x].NodeType == EN_NODETYPE::Start)
			{
				StartNode = &Grid[y][x];
			}
			else if (Grid[y][x].NodeType == EN_NODETYPE::Target)
			{
				TargetNode = &Grid[y][x];
			}
		}
	}

}
