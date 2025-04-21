#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Run();

	std::vector<AActor*> GetAllActors()
	{
		return Actors;
	}

	void SpawnActor(AActor* SpawnedActor);

protected:
	// World has a Actor.
	std::vector<AActor*> Actors;
};

