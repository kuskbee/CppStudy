#include "Boar.h"
#include <iostream>

int ABoar::BoarCnt = 0;
ABoar::ABoar()
{
	Status.SetHP(10000);
	Status.SetMP(10000);
	Status.SetGold(5000000);
	Status.SetAttackPoint(50);
	Name = "<����� " + std::to_string(BoarCnt++) + ">";
}

void ABoar::Rush()
{
	std::cout << Name <<"�� �����ġ��!" << std::endl;
}
