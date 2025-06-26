#include <iostream>


#include "CRCharacter.h"

#include "CRAttackBoost.h"

using namespace std;

void CRAttackBoost::use(CRCharacter* character) 
{
    // 공격력 증가
    //cout << character->GetName() << "이(가) 공격력을 증가시켰습니다!" << endl;
    character->DamageBoost(defaultHealAmount);
    // 공격력 +20 defaultHealAmount는 main에서 make_shared<CRAttackBoost>("AttackBoost", 20); 함수 호출해서 초기화.
}
