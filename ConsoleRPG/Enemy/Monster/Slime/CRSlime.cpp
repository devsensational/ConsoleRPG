#include "CRSlime.h"

Slime::Slime(int level, int InUniqueId) 
{
  Name = "Slime";
  UniqueId = InUniqueId;
  CurrentHealth = 20 + level * 20;
  MaxHealth = CurrentHealth;
  MonsterDamage = 2 + level*5;
  MonsterAttribute = EMonsterAttribute::EMA_Poison;
}