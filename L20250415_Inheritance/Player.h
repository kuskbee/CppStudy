#pragma once
#include "BattleCharacter.h"
#include "StatusComponent.h"
class APlayer : public ABattleCharacter
{	
public:
	APlayer();
	_int64 GetGold() { return Status.GetGold(); }
};

