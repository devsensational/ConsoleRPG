#include "CRWhitePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CRWhitePotion::use(CRCharacter* character)
{
    // 체력 회복
    cout << character->GetName() << "이(가) 체력을 회복했습니다!" << endl;
    character->Heal(defaultHealAmount); // 체력 +40 회복
}
