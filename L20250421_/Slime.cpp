#include "Slime.h"

#include <iostream>

using namespace std;

ASlime::ASlime()
{
	//cout << "������ ����" << endl;
}

ASlime::~ASlime()
{
	//cout << "������ �Ҹ�" << endl;
}

void ASlime::Tick()
{
	Move();
}

void ASlime::Move()
{
	cout << "�̲�������." << endl;
}