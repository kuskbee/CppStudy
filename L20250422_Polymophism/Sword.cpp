#include "Sword.h"

ASword::ASword()
{
	AttackAbility = 10;
	RollRandomRareRank();
}

float ASword::Attack()
{
	cout << ToStringRareRank() << " �� ����" ;
	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}
