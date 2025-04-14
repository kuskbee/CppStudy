#include <iostream>
#include <string>
#include "World.h"

using namespace std;

int main()
{
	APlayer* Player = new APlayer;

	delete Player;
	Player = nullptr;

	return 0;
}