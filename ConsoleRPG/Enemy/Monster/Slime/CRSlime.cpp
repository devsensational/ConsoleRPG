#include "CRSlime.h"
#include "../../../Singleton.h"

Slime::Slime(int level, int InUniqueId)
{
  Name = "Slime";
  UniqueId = InUniqueId;
  CurrentHealth = 70 + level * 10;
  MonsterDamage = 8 + level * 3;
}
