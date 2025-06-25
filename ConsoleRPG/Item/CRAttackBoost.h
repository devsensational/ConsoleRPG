#pragma once
#include "CRItem.h"

class CRAttackBoost : public CRItem {
private:
    string strAttackBoost = "Attack Boost";
    int defaultAmount = 0; 


public:
    CRAttackBoost(string strName, int boostAmount) :
        CRItem(), strAttackBoost(strName), defaultAmount(boostAmount)
    {

    }


    void use(CRCharacter* character) override;
    string getName() const override { return strAttackBoost; }
};
