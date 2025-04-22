#include "Bow.h"

ABow::ABow()
{
	AttackAbility = 10;
	RollRandomRareRank();
}

float ABow::Attack()
{
	cout << ToStringRareRank() << " È° °ø°Ý" ;
	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}
