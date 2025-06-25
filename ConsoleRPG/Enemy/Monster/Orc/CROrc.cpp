#include "CROrc.h"

Orc::Orc(int level) : MonsterBase("오크") {
  Name = "Orc";
  CurrentHealth = 50 + level * 10;
  MonsterDamage = 10 + level * 5;
  MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
