#include "Bow.h"

ABow::ABow()
{
	AttackAbility = 10;
	RollRandomRareRank();
}

float ABow::Attack()
{
	cout << ToStringRareRank() << " Ȱ ����" ;
	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}
