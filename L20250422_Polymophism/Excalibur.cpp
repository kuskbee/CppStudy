#include "Excalibur.h"
#include <limits>

AExcalibur::AExcalibur()
{
	AttackAbility = 10000.f;
	RareRank = EN_RARERANK::UNIQUE;
}

float AExcalibur::Attack()
{
	cout << "@@@@@@";
	cout << ToStringRareRank() << " ����Į���� ����@@@@@@" ;

	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}
