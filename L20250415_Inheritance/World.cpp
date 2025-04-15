#include "World.h"

#include <iostream>
#include <random>

#include "Player.h"
#include "Slime.h"
#include "Goblin.h"
#include "Boar.h"

UWorld::UWorld()
{
	Initialize();
}

UWorld::~UWorld()
{
	Terminate();
}

#define MONSTER_COUNT (10)
void UWorld::Initialize()
{
	Player.push_back(new APlayer());

	// �������� ���� 10���� ����
	int maxCount = MONSTER_COUNT;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, maxCount);
	
	int CreationCnt = dist(gen);
	for (int i = 0; i < CreationCnt; i++)
	{
		Slime.push_back(new ASlime);
	}
	std::cout << "������ " << CreationCnt << "���� ����" << std::endl;

	maxCount -= CreationCnt;
	dist.param(std::uniform_int_distribution<int>::param_type(0, maxCount));
	CreationCnt = dist(gen);
	for (int i = 0; i < CreationCnt; i++)
	{
		Goblin.push_back(new AGoblin);
	}
	std::cout << "��� " << CreationCnt << "���� ����" << std::endl;

	maxCount -= CreationCnt;
	CreationCnt = maxCount;
	for (int i = 0; i < CreationCnt; i++)
	{
		Boar.push_back(new ABoar);
	}
	std::cout << "����� " << CreationCnt << "���� ����" << std::endl;

}

void UWorld::Terminate()
{
	for (int i = 0; i < Player.size(); i++)
	{
		delete Player[i];
		Player[i] = nullptr;
	}
	Player.clear();

	for (int i = 0; i < Slime.size(); i++)
	{
		delete Slime[i];
		Slime[i] = nullptr;
	}
	Slime.clear();

	for (int i = 0; i < Goblin.size(); i++)
	{
		delete Goblin[i];
		Goblin[i] = nullptr;
	}
	Goblin.clear();

	for (int i = 0; i < Boar.size(); i++)
	{
		delete Boar[i];
		Boar[i] = nullptr;
	}
	Boar.clear();
}
