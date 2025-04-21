#include "Monster.h"

#include <iostream>

// Constructor
AMonster::AMonster()
{
	//cout << "몬스터 생성" << endl;
}

// Destructor
AMonster::~AMonster()
{
	//cout << "몬스터 소멸" << endl;
}

void AMonster::Tick()
{
	Move();
}

void AMonster::Move()
{
	cout << "이동한다." << endl;
}