#pragma once
#include <iostream>

using namespace std;

enum class EN_NODETYPE
{
	Floor = 0,
	Wall = 1,
	Start = 3,
	Target = -3,
	Path = -1,
};

class CNode
{
public:
	int Row;
	int Col;
	EN_NODETYPE NodeType;

	CNode() : Row(0), Col(0), NodeType(EN_NODETYPE::Floor)
	{
		//
	};
	CNode(int Row, int Col, EN_NODETYPE NodeType)
		: Row(Row), Col(Col), NodeType(NodeType)
	{
		//
	}

	int GCost = 0;
	int HCost = 0;
	CNode* ParentNode = nullptr;

	int GetFCost() const
	{
		return GCost + HCost;
	}

	bool operator < (CNode& Other) const
	{
		int MyFCost = this->GetFCost();
		int OtherFCost = Other.GetFCost();
		if (MyFCost < OtherFCost)
		{
			return true;
		}
		else if (MyFCost == OtherFCost && this->HCost < Other.HCost)
		{
			return true;
		}
		return false;
	}

	void PrintNode()
	{
		switch (NodeType)
		{
		case EN_NODETYPE::Path:
			cout << "¡Ý";
			break;
		case EN_NODETYPE::Floor:
			cout << "¡¡";
			break;
		case EN_NODETYPE::Start:
			cout << "¨ß";
			break;
		case EN_NODETYPE::Target:
			cout << "¨à";
			break;
		case EN_NODETYPE::Wall:
			cout << "¡á";
			break;
		}
	}
	
};

