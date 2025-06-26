#pragma once
#include "CRItem.h"
#include "CRCharacter.h"

class CROrangePotion : public CRItem
{
private:
    string strHealPosition = "Health Position";
    int defaultHealAmount = 0;


public:
    CROrangePotion(string strName, int maxValue) :
        CRItem(maxValue), strHealPosition(strName)
    {

    }

    void use(CRCharacter* character) override;
    string getName() const override { return strHealPosition; }
};
