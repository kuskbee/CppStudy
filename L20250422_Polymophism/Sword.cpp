#include "Sword.h"

ASword::ASword()
{
	AttackAbility = 10;
	RollRandomRareRank();
}

float ASword::Attack()
{
	cout << ToStringRareRank() << " °Ë °ø°Ý" ;
	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}
