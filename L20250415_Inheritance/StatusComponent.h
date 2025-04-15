#pragma once
class UStatusComponent
{
private:
	int HP;
	int MP;
	_int64 Gold;
	int AttackPoint;

public:
	void SetHP(int _HP)
	{ 
		HP = _HP; 
		if (HP < 0)
		{
			HP = 0;
		}
	}
	void SetMP(int _MP) { MP = _MP; }
	void SetGold(_int64 _Gold) { Gold = _Gold; }
	void SetAttackPoint(int _Atp) { AttackPoint = _Atp; }

	int GetHP() { return HP; }
	int GetMP() { return MP; }
	_int64 GetGold() { return Gold; }
	int GetAttackPoint() { return AttackPoint; }
};

