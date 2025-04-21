#include <iostream>
#include "World.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Player.h"

using namespace std;

int main()
{
	UWorld* World = new UWorld;

	World->SpawnActor(new APlayer());
	World->SpawnActor(new AMonster());
	World->SpawnActor(new AGoal());

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == 0 || y == 0 || x == 9 || y == 9)
			{
				AWall* Wall = new AWall();
				Wall->Location.X = x;
				Wall->Location.Y = y;
				World->SpawnActor(Wall);
			}
		}
	}

	World->Run();
	
	return 0;
}