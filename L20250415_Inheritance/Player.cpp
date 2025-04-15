#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	Status.SetHP(100);
	Status.SetMP(100);
	Status.SetGold(1000000000);
	Status.SetAttackPoint(300);
}

void APlayer::Attack(ABattleCharacter* Target)
{
	std::cout << "플레이어 ";
	ABattleCharacter::Attack(Target);
}
