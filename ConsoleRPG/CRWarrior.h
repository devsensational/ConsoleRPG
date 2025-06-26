#pragma once
#include "CRCharacter.h"
using namespace std;

class CRWarrior : public CRCharacter 
{
private:
    int iStrength = 0;

public:
    CRWarrior(string name, int health, int attack, int strength, int InUniqueId)
        : CRCharacter(name, health, attack, InUniqueId), iStrength(strength)
    {

    }

    void specialMove();

};
