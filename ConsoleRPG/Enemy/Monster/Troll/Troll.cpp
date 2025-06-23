#include "Troll.h"

CRTroll::CRTroll(int level)
{
    name = "Troll";
    CurrentHealth = 70 + level * 10;
    MonsterDamage = 8 + level * 3;
}