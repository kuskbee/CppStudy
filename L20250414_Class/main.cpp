#include <iostream>
#include <string>
#include "Image.h"

using namespace std;

enum class EN_STATE
{
	Patrol = 1,
	Chase,
	Attack,
	Death,
};

class Character
{
	Vector2<int> Pos;
};

class Transition
{
public:
	EN_STATE CurrentState;
	EN_STATE NextState;

	string Condition;
	/*Character* Enemy;
	float AttackRange = 500.f;
	float Health = 100.f;
	*/
};


class Monster
{
public:
	EN_STATE State;
	string Condition;
};

class MonsterFSM
{
public:
	Transition Transitions[5];

	void Process(Monster* _Monster)
	{
		for (int i = 0; i < 5; i++)
		{
			if (_Monster->State == Transitions[i].CurrentState &&
				_Monster->Condition == Transitions[i].Condition)
			{
				_Monster->State = Transitions[i].NextState;
			}
		}
		
	}
};

class Icon
{
public:
	Image Img;
	string Path;
};

class Skill
{
public:
	int MaxSkillLevel;
	int CurrentSkillLevel;
	Skill* NextSkill;
	Icon SkillIcon;
	bool isSelected;

	void UseSkillPoint()
	{

	}
};

class SkillTree
{
public:
	Skill Skills[22];

	void Draw()
	{

	}
};


int main()
{
	

	// Image test
	{
		Image Img;
		Img.Size.X = 100;
		Img.Size.Y = 100;
		Img.ColorTable = new Pixel[Img.Size.X * Img.Size.Y];

		Img.ColorTable[0].Pos.X = 0;
		Img.ColorTable[0].Pos.Y = 0;
		Img.ColorTable[0].Color.R = 0.f;
		Img.ColorTable[0].Color.G = 0.f;
		Img.ColorTable[0].Color.B = 0.f;

		delete[] Img.ColorTable;
	}

	// FSM (Finite State Machine)
	{
		MonsterFSM MyMonsterFSM;
		MyMonsterFSM.Transitions[0].CurrentState = EN_STATE::Patrol;
		MyMonsterFSM.Transitions[0].Condition = "적발견";
		MyMonsterFSM.Transitions[0].NextState = EN_STATE::Chase;

		MyMonsterFSM.Transitions[1].CurrentState = EN_STATE::Chase;
		MyMonsterFSM.Transitions[1].Condition = "적놓침";
		MyMonsterFSM.Transitions[1].NextState = EN_STATE::Patrol;

		MyMonsterFSM.Transitions[2].CurrentState = EN_STATE::Chase;
		MyMonsterFSM.Transitions[2].Condition = "사정거리접근";
		MyMonsterFSM.Transitions[2].NextState = EN_STATE::Attack;

		MyMonsterFSM.Transitions[3].CurrentState = EN_STATE::Attack;
		MyMonsterFSM.Transitions[3].Condition = "사정거리이탈";
		MyMonsterFSM.Transitions[3].NextState = EN_STATE::Chase;

		MyMonsterFSM.Transitions[4].CurrentState = EN_STATE::Attack;
		MyMonsterFSM.Transitions[4].Condition = "HP없음";
		MyMonsterFSM.Transitions[4].NextState = EN_STATE::Death;

		Monster Bazelgeous;
		Bazelgeous.State = EN_STATE::Patrol;
		Bazelgeous.Condition = "적발견";

		MyMonsterFSM.Process(&Bazelgeous);
		cout << "??" << endl;
		cout << static_cast<int>(Bazelgeous.State) << endl;

	}

	

}