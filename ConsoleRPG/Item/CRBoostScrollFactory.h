// 확률에 따른 주문서를 만들어줄 팩토리
#pragma once

#include "CRBoostScroll.h"
#include <memory>

class CRBoostScrollFactory
{
public:
    static shared_ptr<CRBoostScroll> createScroll(int chance)
    {
        if (chance == 1)
        {
            return make_shared<CRBoostScroll>("1% 주문서", chance);
        }
        else if (chance == 5)
        {
            return make_shared<CRBoostScroll>("5% 주문서", chance);
        }
        else if (chance == 10)
        {
            return make_shared<CRBoostScroll>("10% 주문서", chance);
        }
        else if (chance == 20)
        {
            return make_shared<CRBoostScroll>("20% 주문서", chance);
        }
        
    }
};