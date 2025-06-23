#pragma once

#include "ICRCombat.h"
#include "Singleton.h"
#include "CRConsoleRenderer.h"
#include "CRMonsterbase.h"

class Slime :public MonsterBase
{
public:
	Slime(int level);
};