#include "Player.h"
#include <iostream>

APlayer::APlayer()
{
	Shape = 'P';
	Location.X = 5;
	Location.Y = 6;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	//std::cout << "Player Move" << std::endl;
}
