#include "CROrc.h"

Orc::Orc(int level, int uniqueId) : MonsterBase("오크", uniqueId) {
  Name = "Orc";
  CurrentHealth = 50 + level * 7;
  MonsterDamage = 10 + level * 2;
  MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
