#include "Troll.h"

Troll::Troll(int level)
{
    Name = "Troll";
    CurrentHealth = 70 + level * 10;
    MonsterDamage = 8 + level * 3;
    MonsterAttribute = EMonsterAttribute::EMA_Earth;
}