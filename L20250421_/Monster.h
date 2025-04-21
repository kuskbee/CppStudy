#pragma once

#include "Actor.h"

using namespace std;

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;
	virtual void Move();
};

