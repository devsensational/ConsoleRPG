#pragma once
#include "CRCharacter.h"

class CRItem {
public:
    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};
