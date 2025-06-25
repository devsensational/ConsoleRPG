#pragma once
#include "CRItem.h"

class CRPotionBase : public CRItem
{
    protected:
    string strHealPotion;
    int defaultAmount;
    
    public:
    CRPotionBase(string strName, int healAmount) :
        CRItem(), strHealPotion(strName), defaultAmount(healAmount)
    {
        
    }

    virtual void use(CRCharacter* character) override;
    virtual string getName() const override { return strHealPotion; }
};