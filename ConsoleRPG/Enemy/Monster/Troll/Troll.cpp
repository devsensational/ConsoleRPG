#include "Troll.h"

Troll::Troll(int level, int InUniqueId) 
{
    Name = "Troll";
    UniqueId = InUniqueId;
    CurrentHealth = 70 + level * 20;
    MaxHealth = CurrentHealth;
    MonsterDamage = 10 + level * 5;
    MonsterAttribute = EMonsterAttribute::EMA_Earth;
}