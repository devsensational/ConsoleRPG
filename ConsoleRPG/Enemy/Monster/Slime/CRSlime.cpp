#include "CRSlime.h"
#include "../../../Singleton.h"

Slime::Slime(int level)
{
  Name = "Slime";
  CurrentHealth = 70 + level * 10;
  MonsterDamage = 8 + level * 3;
}