#include "Slime.h"

#include <iostream>

using namespace std;

ASlime::ASlime()
{
	//cout << "슬라임 생성" << endl;
}

ASlime::~ASlime()
{
	//cout << "슬라임 소멸" << endl;
}

void ASlime::Tick()
{
	Move();
}

void ASlime::Move()
{
	cout << "미끄러진다." << endl;
}