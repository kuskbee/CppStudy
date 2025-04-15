#include <iostream>
#include "World.h"
#include "Player.h"
#include "Slime.h"
#include "Goblin.h"
#include "Boar.h"

using namespace std;

int main()
{
	UWorld NewWorld;
	NewWorld.Initialize();

	NewWorld.Slime->Slide();
	NewWorld.Player->Attack(NewWorld.Slime);
	NewWorld.Goblin->Attack(NewWorld.Player);
	NewWorld.Goblin->Run();
	NewWorld.Boar->Rush();
	NewWorld.Player->Attack(NewWorld.Goblin);

	_int64 Gold = NewWorld.Player->GetGold();
	cout << "PlayerÀÇ Gold :" << Gold << endl;

	return 0;
}