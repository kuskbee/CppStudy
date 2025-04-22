#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"

UWorld::UWorld()
{
	SpawnActor(new APlayer());
	SpawnActor(new AWall());
	AWall* NewWall = new AWall();
	NewWall->Location.X = 1;
	NewWall->Location.Y = 0;
	SpawnActor(NewWall);
	AWall* NewWall2 = new AWall();
	NewWall2->Location.X = 2;
	NewWall2->Location.Y = 0;
	SpawnActor(NewWall2);
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	//system("cls");
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::DestroyActor(AActor* DestroyedActor)
{
	auto Iter = find(Actors.begin(), Actors.end(), DestroyedActor);
	Actors.erase(Iter);
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}