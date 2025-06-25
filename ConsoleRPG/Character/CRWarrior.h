#pragma once
#include "CRCharacter.h"
using namespace std;

class CRWarrior : public CRCharacter 
{
private:
    int iStrength = 0;

public:
    CRWarrior(string name, int health, int attack, int strength)
        : CRCharacter(name, health, attack), iStrength(strength)
    {

    }

    void specialMove();

};
