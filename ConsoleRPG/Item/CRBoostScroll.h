#pragma once

#include <string>

#include "CRItem.h"
using namespace std;

class CRBoostScroll : public CRItem
{
private:
    string strBoostScroll = "Boost Scroll";
    int defaultAmount = 30;
    int boostChance = 0;

public:
    CRBoostScroll(string strName, int chance) :
        CRItem(), strBoostScroll(strName), boostChance(chance)
    {
        
    }

    void use(CRCharacter* character) override;
    string getName() const override { return strBoostScroll; }
};