#pragma once

#include <string>
//#include "CRCharacterBase.h" //순환참조?
using namespace std;

class CRCharacterBase;

class ICRUseable
{
public:
	virtual string GetName() const = 0;
	virtual void Use(CRCharacterBase* character) = 0;

	virtual ~ICRUseable() = default;
};