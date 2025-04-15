#pragma once
#include <string>
#include "Actor.h"
#include "StatusComponent.h"
class ABattleCharacter : public AActor
{
public:
	virtual void Attack(ABattleCharacter* Target);
	virtual void Damage(int DamagePoint);
	
	bool IsDead();
protected:
	virtual void Die();
	virtual _int64 Drop();

	std::string Name;
	UStatusComponent Status;
};

