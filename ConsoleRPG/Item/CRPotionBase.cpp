#include "CRPotionBase.h"
#include <iostream>
#include "../Character/CRCharacter.h"

using namespace std;

void CRPotionBase::use(CRCharacter* character)
{
    // 체력 회복
    cout << character->getName() << "이(가) 체력을 회복했습니다!" << endl;
    /* defaultHealAmount는 main에서 make_shared<CRPotionBase>("RedPotion", 20)
     * 해당 생성자에 두번째 인자값으로 전달되어 초기화된다.
     */
    character->takeHealPotion(defaultAmount);
    
}