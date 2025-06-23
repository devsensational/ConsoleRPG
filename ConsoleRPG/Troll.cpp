#include "CRTroll.h"
#include "Singleton.h"

Troll::Troll(int level) {
	name = "Troll";
	baseHealth = 50;
	baseAttack = 15;

	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
