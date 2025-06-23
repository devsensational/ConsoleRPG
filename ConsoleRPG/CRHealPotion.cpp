#include "CRHealPotion.h"
#include <iostream>

using namespace std;

void CRHealPotion::use(CRCharacter* character) 
{
    // 체력 회복
    cout << character->getName() << "이(가) 체력을 회복했습니다!" << endl;
    character->takeHealPosition(+50); // 체력 +50 회복
}
