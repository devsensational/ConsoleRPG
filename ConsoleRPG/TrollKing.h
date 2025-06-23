#pragma once
#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"

class TrollKing : public MonsterBase {
public:
	TrollKing(int level);
	int MonsterRandHealth(int level) override
	{
		return level * (60 + randHealth);
	}
	int MonsterRandAttack(int level) override
	{
		return level * (25 + randAttack);
	}


};