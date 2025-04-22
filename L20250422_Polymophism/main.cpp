#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Sword.h"
#include "Bow.h"
#include "Excalibur.h"

using namespace std;


int main()
{
	vector<AWeapon*> Weapons;

	Weapons.push_back(new ASword());
	Weapons.push_back(new ABow());
	Weapons.push_back(new AExcalibur());

	for (auto Weapon : Weapons)
	{
		float Damage = Weapon->Attack();
		cout << " ´ë¹ÌÁö : " << Damage << endl;
	}

	for (auto Weapon : Weapons)
	{
		delete Weapon;
		Weapon = nullptr;
	}
	Weapons.clear();

	return 0;
}