#include "CRSlime.h"

Slime::Slime(int level, int uniqueId)
{
  Name = "Slime";
  CurrentHealth = 70 + level * 10;
  MonsterDamage = 8 + level * 3;
  MonsterAttribute = EMonsterAttribute::EMA_Poison;
}