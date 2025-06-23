#include <iostream>


#include "CRCharacter.h"

#include "CRAttackBoost.h"

using namespace std;

void CRAttackBoost::use(CRCharacter* character) 
{
    // 공격력 증가
    cout << character->getName() << "이(가) 공격력을 증가시켰습니다!" << endl;
    character->takeAttackBoost(+10); // 공격력 +10
}
