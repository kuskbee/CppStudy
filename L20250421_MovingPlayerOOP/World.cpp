#include "World.h"
#include "Actor.h"
#include "Floor.h"


UWorld::UWorld()
{
	
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Initialize()
{

}

void UWorld::Run()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
		Actor->Render();
	}
}

void UWorld::SpawnActor(AActor* SpawnedActor)
{
	Actors.push_back(SpawnedActor);
}
