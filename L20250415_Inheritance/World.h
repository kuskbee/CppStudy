#pragma once

#include <vector>
class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Initialize();
	void Terminate();

	 std::vector<class APlayer*> Player;
	 std::vector<class ASlime*> Slime;
	 std::vector<class AGoblin*> Goblin;
	 std::vector<class ABoar*> Boar;
};

