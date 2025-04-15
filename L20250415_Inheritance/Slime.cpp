#include "Slime.h"
#include <iostream>

ASlime::ASlime()
{
	Status.SetHP(10);
	Status.SetMP(10);
	Status.SetGold(10);
}

void ASlime::Slide()
{
	std::cout << "¹Ì²ôµ¢" << std::endl;
}
