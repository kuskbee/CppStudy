#pragma once
#include "Monster.h"
class ABoar : public AMonster
{
public:
	ABoar();
	void Rush();

public:
	static int BoarCnt;
};

