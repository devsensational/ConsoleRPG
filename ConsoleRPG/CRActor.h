#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"

class CRActor: public ICRCombat
{
public:
	CRActor();
	// ICRCombat��(��) ���� ��ӵ�
	virtual void Attack() override;
	virtual void TakeDamage() override;
};

