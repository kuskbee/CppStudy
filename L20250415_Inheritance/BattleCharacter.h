#pragma once
#include "Actor.h"
#include "StatusComponent.h"
class ABattleCharacter : public AActor
{
public:
	virtual void Attack(ABattleCharacter* Target);
	virtual void Die();
	virtual void Damage(int DamagePoint);
	virtual _int64 Drop();

	bool IsDead();
protected:
	UStatusComponent Status;
};

