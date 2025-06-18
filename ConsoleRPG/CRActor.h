#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"

class CRActor: public ICRCombat
{
public:
	CRActor();
	// ICRCombat을(를) 통해 상속됨
	virtual void Attack() override;
	virtual void TakeDamage() override;
};

