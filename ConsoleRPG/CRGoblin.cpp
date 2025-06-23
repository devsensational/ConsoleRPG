#include "CRGoblin.h"
#include "Singleton.h"


Goblin::Goblin(int level) {
	name = "Goblin";
	baseHealth = 15;
	baseAttack = 5;

	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
