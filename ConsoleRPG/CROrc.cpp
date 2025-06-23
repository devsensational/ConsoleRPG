#include "CROrc.h"
#include "Singleton.h"


Orc::Orc(int level) {
	name = "Orc";
	baseHealth = 35;
	baseAttack = 10;

	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
