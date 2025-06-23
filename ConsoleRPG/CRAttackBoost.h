#pragma once
#include "CRItem.h"

class CRAttackBoost : public CRItem {
private:
    string strAttackBoost = "Attack Boost";

public:
    void use(CRCharacter* character) override;
    string getName() const override { return strAttackBoost; }
};
