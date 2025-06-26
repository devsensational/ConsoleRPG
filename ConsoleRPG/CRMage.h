#pragma once
#include "CRCharacter.h"
using namespace std;

class CRMage : public CRCharacter 
{
private:
    int iMagicalPower = 0;

public:
    CRMage(string name, int health, int attack, int magicalPower, int InUniqueId)
        : CRCharacter(name, health, attack, InUniqueId), iMagicalPower(magicalPower)
    {
        
    }

    void castSpell();

};
