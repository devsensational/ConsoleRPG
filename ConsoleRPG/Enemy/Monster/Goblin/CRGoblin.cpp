#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level) {
  name = "Goblin";
  health = 30 + level * 5;
  attack = 5 + level;
}
