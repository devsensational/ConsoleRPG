#pragma once
#include "CRItem.h"
#include "../Character/CRCharacter.h"
#include "CRPotionBase.h"

class CROrangePotion : public CRPotionBase
{
private:
    

public:
    CROrangePotion(string strName, int healAmount, int maxValue = 100) : 
        CRPotionBase(strName, healAmount)
    {
        
    }
};
