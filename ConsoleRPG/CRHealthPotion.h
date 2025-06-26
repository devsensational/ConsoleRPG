#pragma once
#include "CRItem.h"
#include "CRCharacter.h"

class CRHealthPotion : public CRItem 
{
private:
    string strHealPosition = "Health Position";
    int defaultHealAmount = 0;

public:
    CRHealthPotion(string strName, int healAmount, int maxValue = 100) : 
        CRItem(maxValue), strHealPosition(strName), defaultHealAmount(healAmount)
    {
        
    }

    void use(CRCharacter* character) override;
    string getName() const override { return strHealPosition; }
};
