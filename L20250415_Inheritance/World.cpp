#include "World.h"
#include "Player.h"
#include "Slime.h"
#include "Goblin.h"
#include "Boar.h"

UWorld::UWorld()
{
	//
}

UWorld::~UWorld()
{
	delete Player;
	Player = nullptr;

	delete Slime;
	Slime = nullptr;

	delete Goblin;
	Goblin = nullptr;

	delete Boar;
	Boar = nullptr;
}

void UWorld::Initialize()
{
	Player = new APlayer;
	Slime = new ASlime;
	Goblin = new AGoblin;
	Boar = new ABoar;
}
