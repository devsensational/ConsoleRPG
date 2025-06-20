#pragma once

#include "ICRUseable.h"
#include <string>
using namespace std;

// �������̽��� ���� ��ӿ� �����ۺ��̽�
class CRItemBase : public ICRUseable
{
public:
	string Name;
	string Description;

	CRItemBase(const string& name, const string& desc) : Name(name), Description(desc) {}

	virtual string GetName() const override
	{
		return Name;
	}
	virtual void Use(CRCharacterBase* character) override
	{

	}
};