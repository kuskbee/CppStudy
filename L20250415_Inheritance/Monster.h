#pragma once
#include "BattleCharacter.h"
#include "StatusComponent.h"
class AMonster : public ABattleCharacter
{
public:
	AMonster();
protected:
	UStatusComponent Status;
};

