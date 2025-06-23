#include "TrollKing.h"
#include "Singleton.h"

TrollKing::TrollKing(int level) {
	name = "TrollKing";
	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}