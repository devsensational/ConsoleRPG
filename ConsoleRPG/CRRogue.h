#pragma once
#include "CRCharacter.h"
using namespace std;

class CRRogue : public CRCharacter 
{
private:
    int iVigor = 0; //±â·Â

public:
    CRRogue(string name, int health, int attack, int vigor)
        : CRCharacter(name, health, attack), iVigor(vigor)
    {

    }


    void stealthAttack();

};
