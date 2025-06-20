#pragma once

#include "CRItemBase.h"
using namespace std;

class CRHealthPotion : public CRItemBase 
{
private:
	int HealthRestore;

public:
	CRHealthPotion(int value) : CRItemBase("ü�� ����", "ü�� ȸ��"), HealthRestore(value)
	{
	}

	string GetName() const override;
	void Use(CRCharacterBase* character) override;
};