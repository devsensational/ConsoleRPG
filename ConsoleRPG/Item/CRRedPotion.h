#pragma once
#include "CRItem.h"
#include "../Character/CRCharacter.h"
#include "CRPotionBase.h"

class CRRedPotion : public CRPotionBase
{
private:
    

public:
    CRRedPotion(string strName, int healAmount, int maxValue = 100) : 
        CRPotionBase(strName, healAmount)
    {
        
    }
};
