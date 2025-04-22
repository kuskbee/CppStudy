#pragma once
#include "Weapon.h"
class ASword :
    public AWeapon
{
public:
    ASword();
    virtual float Attack() override;
};

