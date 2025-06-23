#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"

class Slime :public MonsterBase
{
public:
	Slime(int level);
	int MonsterRandHealth(int level)
	{
		return level * (25 + randHealth);
	}
	int MonsterRandAttack(int level)
	{
		return level * (3 + randAttack);
	}
};