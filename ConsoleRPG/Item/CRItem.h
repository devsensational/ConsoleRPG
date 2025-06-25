#pragma once
#include <string>
using namespace std;

class CRCharacter; // #include "CRCharacter.h"를 넣지 않고 전방 선언만 하는 이유 : 상호참조를 막기 위함.

class CRItem 
{
protected:
    int iMaxValue; // 최대


public:
    CRItem(int maxValue = 100) : iMaxValue(maxValue)
    {

    }
    virtual ~CRItem() = default;

    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};
