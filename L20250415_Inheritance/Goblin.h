#pragma once
#include "Monster.h"
class AGoblin : public AMonster
{
public:
	AGoblin();
	void Run();
public:
	static int GoblinCnt;
};

