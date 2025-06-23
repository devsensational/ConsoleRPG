#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"

class Troll : public MonsterBase
{
public:
	Troll(int level);
	int MonsterRandHealth(int level) override
	{
		return level * (50 + randHealth);
	}
	int MonsterRandAttack(int level) override
	{
		return level * (15 + randAttack);
	}
};