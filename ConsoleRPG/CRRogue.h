#pragma once
#include "CRCharacter.h"
using namespace std;

class CRRogue : public CRCharacter 
{
private:
    int iVigor = 0; //기력

public:
    CRRogue(string name, int health, int attack, int vigor)
        : CRCharacter(name, health, attack), iVigor(vigor)
    {

    }


    void stealthAttack() 
    {
        // 도적의 특수 능력 (예시)
        cout << getName() << "이(가) 은신 공격을 합니다!" << endl;
    }
};
