#include "Boar.h"
#include <iostream>

ABoar::ABoar()
{
	Status.SetHP(10000);
	Status.SetMP(10000);
	Status.SetGold(5000000);
}

void ABoar::Rush()
{
	std::cout << "¸äµÅÁöÀÇ ¸öÅë¹ÚÄ¡±â!" << std::endl;
}
