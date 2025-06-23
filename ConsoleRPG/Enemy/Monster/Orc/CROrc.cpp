#include "CROrc.h"
#include "../../../Singleton.h"

Orc::Orc(int level) {
  Name = "Orc";
  CurrentHealth = 50 + level * 7;
  MonsterDamage = 10 + level * 2;
}