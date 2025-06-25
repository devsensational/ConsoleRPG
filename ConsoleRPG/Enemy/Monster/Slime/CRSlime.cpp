#include "CRSlime.h"

Slime::Slime(int level) : MonsterBase("슬라임")
{
  Name = "Slime";
  CurrentHealth = 20 + level * 10;
  MonsterDamage = 3 + level * 5;
  MonsterAttribute = EMonsterAttribute::EMA_Poison;
}