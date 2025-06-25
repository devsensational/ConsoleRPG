#include "Troll.h"

Troll::Troll(int level, int uniqueId) : MonsterBase("트롤")
{
    Name = "Troll";
    CurrentHealth = 70 + level * 10;
    MonsterDamage = 8 + level * 5;
    MonsterAttribute = EMonsterAttribute::EMA_Earth;
}