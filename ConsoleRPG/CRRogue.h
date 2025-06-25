#pragma once
#include "CRCharacter.h"
using namespace std;

class CRRogue : public CRCharacter 
{
private:
    int iVigor = 0; //���

public:
    CRRogue(string name, int health, int attack, int vigor, int InUniqueId)
        : CRCharacter(name, health, attack, InUniqueId), iVigor(vigor)
    {

    }


    void stealthAttack();

};
