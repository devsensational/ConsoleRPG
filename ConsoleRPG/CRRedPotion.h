#pragma once
#include "CRItem.h"
#include "CRCharacter.h"

class CRRedPotion : public CRItem 
{
private:
    string strHealPosition = "Health Position";
    int defaultHealAmount = 0;

public:
    CRRedPotion(string strName, int healAmount, int maxValue = 100) : 
        CRItem(maxValue), strHealPosition(strName), defaultHealAmount(healAmount)
    {
        
    }

    void use(CRCharacter* character) override;
    string getName() const override { return strHealPosition; }
};
