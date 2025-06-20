#pragma once

#include "CRItemBase.h"
using namespace std;

class CRDamageBoost : public CRItemBase
{
private:
	int DamageIncrease;

public:
	CRDamageBoost(int value) : CRItemBase("��ȭ ����", "���ݷ� ��ȭ"), DamageIncrease(value)
	{
	}

	string GetName() const override;
	void Use(CRCharacterBase* character) override;
};