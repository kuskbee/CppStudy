#pragma once

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Initialize();

	class APlayer* Player;
	class ASlime* Slime;
	class AGoblin* Goblin;
	class ABoar* Boar;
};

