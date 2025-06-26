#include "CROrc.h"

Orc::Orc(int level, int InUniqueId)  {
  Name = "Orc";
  CurrentHealth = 50 + level * 20;
  MaxHealth = CurrentHealth;
  MonsterDamage = 7 + level * 5;
  MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
