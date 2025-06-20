#pragma once

#include "ICRUseable.h"
#include <string>
using namespace std;

// 인터페이스를 받은 상속용 아이템베이스
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