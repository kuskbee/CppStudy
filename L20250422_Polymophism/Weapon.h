#pragma once
#include <iostream>
using namespace std;

enum class EN_RARERANK
{
	NORMAL,
	RARE,
	ADVANCED,
	ELITE,
	EPIC,
	UNIQUE,
	COUNT, // °¹¼ö ÆÄ¾Ç¿ë
};

class AWeapon
{
public:
	AWeapon();
	virtual ~AWeapon();

	virtual float Attack();
protected:
	const char* ToStringRareRank();
	float GetBonusAttackFromRareRank();
	void RollRandomRareRank();
	float AttackAbility;
	EN_RARERANK RareRank;
};

