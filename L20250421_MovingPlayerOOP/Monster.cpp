#include "Monster.h"

#include <iostream>

// Constructor
AMonster::AMonster()
{
	//cout << "���� ����" << endl;
	Shape = 'M';
	Location.X = 2;
	Location.Y = 2;
}

// Destructor
AMonster::~AMonster()
{
	//cout << "���� �Ҹ�" << endl;
}

void AMonster::Tick()
{
	Move();
}

void AMonster::Move()
{
	//cout << "�̵��Ѵ�." << endl;
}