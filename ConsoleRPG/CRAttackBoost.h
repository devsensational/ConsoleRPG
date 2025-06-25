#pragma once
#include "CRItem.h"

class CRAttackBoost : public CRItem {
private:
    string strAttackBoost = "Attack Boost";
    int defaultHealAmount = 0; 


public:
    CRAttackBoost(string strName, int maxValue) :
        CRItem(maxValue), strAttackBoost(strName)
    {

    }


    void use(CRCharacter* character) override;
    string getName() const override { return strAttackBoost; }
};
