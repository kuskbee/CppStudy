#include "Goblin.h"
#include <iostream>

int AGoblin::GoblinCnt = 0;
AGoblin::AGoblin()
{
	Status.SetHP(1);
	Status.SetMP(1);
	Status.SetGold(99999999999);
	Status.SetAttackPoint(1);
	Name = "<��� " + std::to_string(GoblinCnt++) + ">";
}

void AGoblin::Run()
{
	std::cout << Name << " �� �ڴ�." << std::endl;
}
