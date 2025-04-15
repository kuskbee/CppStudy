#include "BattleCharacter.h"
#include <iostream>
void ABattleCharacter::Attack(ABattleCharacter* Target)
{
	std::cout << Name << " 캐릭터가 " << Target->Name << " 공격" << std::endl;

	int AtkPoint = Status.GetAttackPoint();
	Target->Damage(AtkPoint);
	if (Target->IsDead())
	{
		_int64 DropGold = Target->Drop();
		_int64 MyGold = Status.GetGold();
		Status.SetGold(MyGold + DropGold);
	}
}

void ABattleCharacter::Die()
{
	std::cout << Name << " 캐릭터 죽음" << std::endl;
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
	_int64 Gold = Status.GetGold();
	std::cout << Name << "의 " << Gold <<"Gold 드랍!" << std::endl;
	return Gold;
}

bool ABattleCharacter::IsDead()
{
	if (Status.GetHP() == 0)
		return true;
	return false;
}
