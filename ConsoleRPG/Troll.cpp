#include "CRTroll.h"
#include "Singleton.h"

Troll::Troll(int level) {
	name = "Troll";
	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
