#include "Goblin.h"
#include <iostream>

AGoblin::AGoblin()
{
	Status.SetHP(1);
	Status.SetMP(1);
	Status.SetGold(99999999999);
}

void AGoblin::Run()
{
	std::cout << "��� �� �ڴ�." << std::endl;
}
