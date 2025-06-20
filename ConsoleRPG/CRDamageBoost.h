#pragma once

#include "CRItemBase.h"
using namespace std;

class CRDamageBoost : public CRItemBase
{
private:
	int DamageIncrease;

public:
	CRDamageBoost(int value) : CRItemBase("강화 부적", "공격력 강화"), DamageIncrease(value)
	{
	}

	string GetName() const override;
	void Use(CRCharacterBase* character) override;
};