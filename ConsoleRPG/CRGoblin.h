#pragma once
#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"



class Goblin : public MonsterBase
{
public:
	Goblin(int level);
	
	int MonsterRandHealth(int level)
	{
		return level * (15 + randHealth);
	}
	int MonsterRandAttack(int level)
	{		
		return level * (5 + randAttack);
	}
};