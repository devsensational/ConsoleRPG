#include "CRSlime.h"
#include "Singleton.h"

Slime::Slime(int level) {
	name = "Slime";
	baseHealth = 15;
	baseAttack = 3;

	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}

