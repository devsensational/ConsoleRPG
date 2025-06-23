#include "CRSlime.h"
#include "Singleton.h"

Slime::Slime(int level) {
	name = "Slime";
	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}

