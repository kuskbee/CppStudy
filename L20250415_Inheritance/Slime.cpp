#include "Slime.h"
#include <iostream>

int ASlime::SlimeCnt = 0;
ASlime::ASlime()
{
	Status.SetHP(10);
	Status.SetMP(10);
	Status.SetGold(10);
	Status.SetAttackPoint(5);
	Name = "<������ " + std::to_string(SlimeCnt++) + ">";
}

void ASlime::Slide()
{
	std::cout << Name << " �����̵�" << std::endl;
}
