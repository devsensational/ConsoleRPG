#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"

//¿¹½Ã
class CRActor: public ICRCombat
{
public:
	CRActor();

	virtual void Act() override;
	virtual void TakeDamage(int value);

private:
	int hp = 100;
};

