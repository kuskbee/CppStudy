#include "BattleCharacter.h"
#include <iostream>
void ABattleCharacter::Attack(ABattleCharacter* Target)
{
	std::cout << "캐릭터 공격" << std::endl;

	int AtkPoint = Target->Status.GetAttackPoint();
	Damage(Target->Status.GetAttackPoint());
	if (Target->IsDead())
	{
		_int64 DropGold = Target->Drop();
		int MyGold = Status.GetGold();
		Status.SetGold(MyGold + DropGold);
	}
}

void ABattleCharacter::Die()
{
	std::cout << "캐릭터 죽음" << std::endl;
}

void ABattleCharacter::Damage(int DamagePoint)
{
	int HP = Status.GetHP();
	Status.SetHP(HP - DamagePoint);
	if (IsDead())
	{
		Die();
	}
}

_int64 ABattleCharacter::Drop()
{
	return Status.GetGold();
}

bool ABattleCharacter::IsDead()
{
	if (Status.GetHP() == 0)
		return true;
	return false;
}
