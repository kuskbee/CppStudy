#include "Goblin.h"

#include <iostream>

using namespace std;

AGoblin::AGoblin()
{
	//cout << "��� ����" << endl;
}

AGoblin::~AGoblin()
{
	//cout << "��� �Ҹ�" << endl;
}

void AGoblin::Tick()
{
	Move();
}

void AGoblin::Move()
{
	cout << "�ڴ�." << endl;
}
