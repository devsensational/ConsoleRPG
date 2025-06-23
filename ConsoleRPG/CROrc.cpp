#include "CROrc.h"
#include "Singleton.h"


Orc::Orc(int level) {
	name = "Orc";
	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}
