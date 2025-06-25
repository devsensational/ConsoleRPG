// CRPotionFactory.h
// 포션 생성을 관리할 팩토리 클래스
#pragma once
#include "CRPotionBase.h"
#include <memory>

class CRPotionFactory {
public:
    static shared_ptr<CRPotionBase> createPotion(int healAmount) {
        if (healAmount == 20)
        {
            return make_shared<CRPotionBase>("RedPotion", healAmount);
        }
        else if (healAmount == 30)
        {
            return make_shared<CRPotionBase>("OrangePotion", healAmount);
        }
        else if (healAmount == 50)
        {
            return make_shared<CRPotionBase>("WhitePotion", healAmount);
        }
    }
};
