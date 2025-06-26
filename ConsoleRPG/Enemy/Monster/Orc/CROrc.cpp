#include "CROrc.h"

Orc::Orc(int level, int InUniqueId) : MonsterBase("오크", InUniqueId) {
  Name = "Orc";
  CurrentHealth = 50 + level * 7;
  MaxHealth = CurrentHealth;
  MonsterDamage = 10 + level * 2;
  MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
