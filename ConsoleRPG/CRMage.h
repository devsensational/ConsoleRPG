#pragma once
#include "CRCharacter.h"
using namespace std;

class CRMage : public CRCharacter 
{
private:
    int iMagicalPower = 0;

public:
    CRMage(string name, int health, int attack, int magicalPower)
        : CRCharacter(name, health, attack), iMagicalPower(magicalPower)
    {
        
    }

    void castSpell();

};
