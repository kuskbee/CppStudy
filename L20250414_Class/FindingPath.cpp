#include "FindingPath.h"
#include <queue>
#include <unordered_set>

using namespace std;

void CFindingPath::StartFindingPath()
{
	CNode* StartNode = Grid.StartNode;
	CNode* TargetNode = Grid.TargetNode;

	priority_queue<CNode*, vector<CNode*>, greater<CNode*>> OpenQueue;
	unordered_set<CNode*> OpenSet;
	unordered_set<CNode*> ClosedSet;

	OpenQueue.push(StartNode);
	OpenSet.insert(StartNode);

	while (!OpenQueue.empty())
	{
		CNode* CurrentNode = OpenQueue.top();
		OpenQueue.pop();
		OpenSet.erase(CurrentNode);
		ClosedSet.insert(CurrentNode);

		if (CurrentNode == TargetNode)
		{
			RetracePath();
			break;
		}

		vector<CNode*> Neighbours = Grid.GetNeighbour(CurrentNode);
		for (CNode* Node : Neighbours)
		{
			if (ClosedSet.count(Node)) continue;

			int NewCost = CurrentNode->GCost + GetDistance(CurrentNode, Node);
			if (NewCost < Node->GCost || !OpenSet.count(Node))
			{
				Node->GCost = NewCost;
				Node->HCost = GetDistance(Node, TargetNode);
				Node->ParentNode = CurrentNode;

				if (!OpenSet.count(Node))
				{
					OpenQueue.push(Node);
					OpenSet.insert(Node);
				}
			}
		}
		
	}

}

void CFindingPath::PrintGrid()
{
	Grid.PrintGrid();
}

void CFindingPath::RetracePath()
{
	CNode* CurrentNode = Grid.TargetNode;
	while (CurrentNode != Grid.StartNode)
	{
		if (CurrentNode->NodeType == EN_NODETYPE::Floor)
		{
			CurrentNode->NodeType = EN_NODETYPE::Path;
		}		
		CurrentNode = CurrentNode->ParentNode;
	}
}

int CFindingPath::GetDistance(CNode* Start, CNode* Target)
{
	int DistX = abs(Start->Col - Target->Col);
	int DistY = abs(Start->Row - Target->Row);

	if (DistX > DistY)
	{
		return 14 * DistY + 10 * (DistX - DistY);
	}

	return 14 * DistX + 10 * (DistY - DistX);
}
