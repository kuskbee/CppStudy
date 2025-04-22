#include "Weapon.h"
#include <vector>
#include <random>

AWeapon::AWeapon()
{
	AttackAbility = 1;
	RollRandomRareRank();
}

AWeapon::~AWeapon()
{

}

float AWeapon::Attack()
{
	cout << "�⺻ ���� ����" ;
	float Damage = GetBonusAttackFromRareRank() * AttackAbility;
	return Damage;
}

void AWeapon::RollRandomRareRank()
{
	static const vector<float> RankWeight =
	{
		50.f,
		25.f,
		12.5f,
		7.75f,
		3.125f,
		1.625f,
	};

	static random_device rd;
	static mt19937 gen(rd());

	discrete_distribution<int> dist(RankWeight.begin(), RankWeight.end());
	int idx = dist(gen);

	if (idx < 0)
	{
		idx = 0;
	}

	if (idx >= static_cast<int>(EN_RARERANK::COUNT))
	{
		idx = static_cast<int>(EN_RARERANK::COUNT) - 1;
	}

	RareRank = static_cast<EN_RARERANK>(idx);
}


const char* AWeapon::ToStringRareRank() {
	switch (RareRank) {
	case EN_RARERANK::NORMAL:		return "�Ϲ�";
	case EN_RARERANK::RARE:			return "����";
	case EN_RARERANK::ADVANCED:     return "���";
	case EN_RARERANK::ELITE:		return "����Ʈ";
	case EN_RARERANK::EPIC:			return "����";
	case EN_RARERANK::UNIQUE:		return "����ũ";
	default:                     return "Unknown";
	}
}

float AWeapon::GetBonusAttackFromRareRank()
{
	switch (RareRank) {
	case EN_RARERANK::NORMAL:		return 1.f;
	case EN_RARERANK::RARE:			return 10.f;
	case EN_RARERANK::ADVANCED:     return 100.f;
	case EN_RARERANK::ELITE:		return 100000.f;
	case EN_RARERANK::EPIC:			return 1000000.f;
	case EN_RARERANK::UNIQUE:		return 100000000.f;
	default:                     return 0.f;
	}
}
