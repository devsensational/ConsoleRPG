#include "TrollKing.h"
#include "Singleton.h"

TrollKing::TrollKing(int level) {
	name = "TrollKing";
	baseHealth = 60;
	baseAttack = 25;

	health = MonsterRandHealth(level);
	attack = MonsterRandAttack(level);
}