#include <iostream>
#include <vector>

#include "Actor.h"
#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
#include "Player.h"
#include "World.h"

using namespace std;

template<typename T>
class Calculator
{
public:
	static T Add(T A, T B)
	{
		return A + B;
	}

	static T Subtract(T A, T B)
	{
		return A - B;
	}

	static T Multiply(T A, T B)
	{
		return A * B;
	}

	static T Divide(T A, T B)
	{
		if (B == T{ 0 })
			throw std::invalid_argument("Division by Zero");
		return A / B;
	}
};

int main()
{
	/*cout << Calculator<int>::Add(5, 2) << endl;
	cout << Calculator<int>::Subtract(5, 2) << endl;
	cout << Calculator<int>::Multiply(5, 2) << endl;
	cout << Calculator<int>::Divide(5, 0) << endl;

	cout << Calculator<float>::Add(5.f, 2.f) << endl;
	cout << Calculator<float>::Subtract(5.f, 2.f) << endl;
	cout << Calculator<float>::Multiply(5.f, 2.f) << endl;
	cout << Calculator<float>::Divide(5.f, 2.f) << endl;*/

	//vector<AMonster*> Monsters;
	//Monsters.push_back(new ASlime);
	//Monsters.push_back(new AGoblin);

	//// All Monsters Move.
	//for (auto Monster : Monsters)
	//{
	//	// Polymophism
	//	Monster->Move();
	//}

	//for (auto Monster : Monsters)
	//{
	//	delete Monster;
	//}
	//Monsters.clear();

	UWorld* MyWorld = new UWorld();

	MyWorld->SpawnActor(new AGoblin());
	MyWorld->SpawnActor(new ASlime());
	MyWorld->SpawnActor(new ABoar());
	MyWorld->SpawnActor(new APlayer());

	MyWorld->Run();
	
	delete MyWorld;
	MyWorld = nullptr;

	return 0;
}