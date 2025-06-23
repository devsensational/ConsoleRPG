#include "CRSlime.h"
#include "../../../Singleton.h"

CRSlime::CRSlime(int level)
{
  name = "Slime";
  CurrentHealth = 70 + level * 10;
  MonsterDamage = 8 + level * 3;
}