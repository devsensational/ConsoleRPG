#include "CRSlime.h"
#include "../../../Singleton.h"

Slime::Slime(int level, int InUniqueId)
{
  Name = "Slime";
  UniqueId = InUniqueId;
  CurrentHealth = 70 + level * 10;
  MaxHealth = CurrentHealth;
  MonsterDamage = 8 + level * 3;
}
