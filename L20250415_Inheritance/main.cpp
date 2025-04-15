#include <iostream>
#include <random>

#include "World.h"
#include "Player.h"
#include "Slime.h"
#include "Goblin.h"
#include "Boar.h"

using namespace std;

template<typename T>
T* GetRandomElement(vector<T*> Container, mt19937& gen)
{
	if (Container.empty())
	{
		return nullptr;
	}
	uniform_int_distribution<size_t> dist(0, Container.size() - 1);
	size_t Idx = dist(gen);
	return Container[Idx];
}

int main()
{
	UWorld NewWorld;

	// Player는 항상 존재
	const int PlayerIdx = 0;

	random_device rd;
	mt19937 gen(rd());
	
	// Slime vs Player
	if (ASlime* Slime = GetRandomElement(NewWorld.Slime, gen))
	{
		Slime->Slide();
		NewWorld.Player[PlayerIdx]->Attack(Slime);
	}
		
	// Goblin vs Player
	AGoblin* Goblin = nullptr;
	if (Goblin = GetRandomElement(NewWorld.Goblin, gen))
	{
		Goblin->Attack(NewWorld.Player[PlayerIdx]);
		Goblin->Run();
	}

	// Boar
	if(ABoar* Boar = GetRandomElement(NewWorld.Boar, gen))
	{
		Boar->Rush();
	}
	
	// Goblin's Last (Goblin vs Player - 2)
	if(Goblin)
	{
		NewWorld.Player[PlayerIdx]->Attack(Goblin);
	}

	_int64 Gold = NewWorld.Player[PlayerIdx]->GetGold();
	cout << "Player의 Gold :" << Gold << endl;
	
	return 0;
}