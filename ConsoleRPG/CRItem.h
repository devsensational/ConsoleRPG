#pragma once
#include <string>
using namespace std;

class CRCharacter; // #include "CRCharacter.h"�� ���� �ʰ� ���� ���� �ϴ� ���� : ��ȣ������ ���� ����.

class CRItem 
{
private:
    int iMaxValue; // �ִ�


public:
    CRItem(int maxValue) : iMaxValue(maxValue)
    {

    }


    virtual void use(CRCharacter* character) = 0;
    virtual string getName() const = 0;
};
