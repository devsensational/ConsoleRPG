#pragma once
#include <string>
using namespace std;

class CRCharacter; // #include "CRCharacter.h"�� ���� �ʰ� ���� ���� �ϴ� ����

class CRItem {
public:
    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};
