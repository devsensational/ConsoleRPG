#include "CRGoblin.h"
#include "Singleton.h"


Goblin::Goblin(int level) {
	name = "Goblin";
	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
