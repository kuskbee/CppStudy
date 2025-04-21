#pragma once
#include <vector>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Initialize();
	void Run();

	std::vector<AActor*> GetAllActors()
	{
		return Actors;
	}

	void SpawnActor(AActor* SpawnedActor);

protected:
	std::vector<AActor*> Actors;
};

