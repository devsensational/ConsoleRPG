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

    void castSpell() {
        // 마법사 특수 능력 (예시)
        cout << getName() << "이(가) 마법을 시전합니다!" << endl;
    }
};
