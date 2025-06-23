#pragma once
#include <string>
using namespace std;

class CRCharacter; // #include "CRCharacter.h"를 넣지 않고 전방 선언만 하는 이유

class CRItem {
public:
    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};
