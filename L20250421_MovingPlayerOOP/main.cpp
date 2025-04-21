#include <iostream>
#include "World.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Player.h"
#include "Floor.h"

using namespace std;

int main()
{
	UWorld* World = new UWorld;

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == 0 || y == 0 || x == 9 || y == 9)
			{
				AWall* Wall = new AWall();
				FVector2D Pos(x, y);
				Wall->SetActorPosition(Pos);
				World->SpawnActor(Wall);
			}
			else
			{
				AFloor* Floor = new AFloor();
				FVector2D Pos(x, y);
				Floor->SetActorPosition(Pos);
				World->SpawnActor(Floor);
			}
		}
	}

	World->SpawnActor(new APlayer());
	World->SpawnActor(new AMonster());
	World->SpawnActor(new AGoal());

	World->Run();
	
	return 0;
}