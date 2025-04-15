#pragma once
class UStatusComponent
{
private:
	int HP;
	int MP;
	_int64 Gold;
	int AttackPoint;

public:
	__forceinline void SetHP(int _HP)
	{ 
		HP = _HP; 
		if (HP < 0)
		{
			HP = 0;
		}
	}
	__forceinline void SetMP(int _MP) { MP = _MP; }
	__forceinline void SetGold(_int64 _Gold) { Gold = _Gold; }
	__forceinline void SetAttackPoint(int _Atp) { AttackPoint = _Atp; }

	__forceinline int GetHP() { return HP; }
	__forceinline int GetMP() { return MP; }
	__forceinline _int64 GetGold() { return Gold; }
	__forceinline int GetAttackPoint() { return AttackPoint; }
};

