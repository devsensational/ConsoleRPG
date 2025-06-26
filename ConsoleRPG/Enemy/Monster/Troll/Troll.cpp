#include "Troll.h"

Troll::Troll(int level, int InUniqueId)
{
    Name = "Troll";
    UniqueId = InUniqueId;
    CurrentHealth = 70 + level * 10;
    MaxHealth = CurrentHealth;
    MonsterDamage = 8 + level * 3;
    MonsterAttribute = EMonsterAttribute::EMA_Earth;
}