#pragma once
#include "CRItem.h"
#include "CRCharacter.h"

class CRHealPotion : public CRItem 
{
private:
    string strHealPosition = "Heath Position";

public:
    void use(CRCharacter* character) override;
    string getName() const override { return strHealPosition; }
};
