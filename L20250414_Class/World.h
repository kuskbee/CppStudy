#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "Floor.h"
#include "Goal.h"
#include "Wall.h"
#include "Monster.h"
#include "Player.h"

using namespace std;

class UWorld
{
public:
	APlayer* Player;
	AMonster* Monster;
	AGoal* Goal;
	AWall* Walls;
	AFloor* Floors;
};

