#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level) {
  Name = "Goblin";
  CurrentHealth = 30 + level * 5;
  MonsterDamage = 5 + level;
}
