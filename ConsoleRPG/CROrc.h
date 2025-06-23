#pragma once
#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"

class Orc : public MonsterBase
{
public:
	Orc(int level);
	int MonsterRandHealth(int level) override
	{
		return level * (35 + randHealth);
	}
	int MonsterRandAttack(int level) override
	{
		return level * (10 + randAttack);
	}
};