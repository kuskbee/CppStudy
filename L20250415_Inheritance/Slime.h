#pragma once
#include "Monster.h"
class ASlime : public AMonster
{
public:
	ASlime();
	void Slide();
public:
	static int SlimeCnt;
};

