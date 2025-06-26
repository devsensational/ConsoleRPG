#include "CRSlime.h"

Slime::Slime(int level, int InUniqueId)
{
  Name = "Slime";
  UniqueId = InUniqueId;
  CurrentHealth = 30 + level * 5;
  MaxHealth = CurrentHealth;
  MonsterDamage = 5 + level;
  MonsterAttribute = EMonsterAttribute::EMA_Poison;
}