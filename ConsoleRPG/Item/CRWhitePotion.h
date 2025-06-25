#pragma once
#include "CRItem.h"
#include "../Character/CRCharacter.h"
#include "CRPotionBase.h"

class CRWhitePotion : public CRPotionBase
{
private:
    

public:
    CRWhitePotion(string strName, int healAmount, int maxValue = 100) : 
        CRPotionBase(strName, healAmount)
    {
        
    }
};
