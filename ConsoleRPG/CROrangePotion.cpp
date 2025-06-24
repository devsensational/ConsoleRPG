#include "CROrangePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CROrangePotion::use(CRCharacter* character)
{
    // 체력 회복
    cout << character->getName() << "이(가) 체력을 회복했습니다!" << endl;
    character->takeHealPosition(defaultHealAmount); // 체력 35 회복
}
