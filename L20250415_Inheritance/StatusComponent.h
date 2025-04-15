#pragma once
class UStatusComponent
{
private:
	int HP;
	int MP;
	_int64 Gold;

public:
	void SetHP(int _HP) { HP = _HP; }
	void SetMP(int _MP) { MP = _MP; }
	void SetGold(int _Gold) { Gold = _Gold; }

	int GetHP() { return HP; }
	int GetMP() { return MP; }
	_int64 GetGold() { return Gold; }
};

