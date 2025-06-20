#pragma once

#include "CRItemBase.h"
using namespace std;

class CRHealthPotion : public CRItemBase 
{
private:
	int HealthRestore;

public:
	CRHealthPotion(int value) : CRItemBase("체력 포션", "체력 회복"), HealthRestore(value)
	{
	}

	string GetName() const override;
	void Use(CRCharacterBase* character) override;
};