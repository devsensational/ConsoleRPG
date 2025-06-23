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


    void specialMove() 
    {
        // 전사의 특수기능 (예시)
        cout << getName() << "이(가) 강력한 베기를 사용합니다!" << endl;
    }
};
