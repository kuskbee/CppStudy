#include "Monster.h"

#include <iostream>

// Constructor
AMonster::AMonster()
{
	//cout << "���� ����" << endl;
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
	cout << "�̵��Ѵ�." << endl;
}