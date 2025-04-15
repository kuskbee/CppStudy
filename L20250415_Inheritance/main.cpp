#include <iostream>
#include "World.h"

using namespace std;

int main()
{
	UWorld NewWorld;
	NewWorld.Slime.Slide();
	NewWorld.Player.Attack();
	NewWorld.Goblin.Attack();
	NewWorld.Goblin.Run();
	NewWorld.Boar.Rush();
	NewWorld.Player.Attack();

	_int64 Gold = NewWorld.Player.GetGold();
	cout << "PlayerÀÇ Gold :" << Gold << endl;

	return 0;
}