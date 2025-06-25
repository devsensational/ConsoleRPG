#include "CRDragon.h"

Dragon::Dragon(int level, int uniqueId)  : MonsterBase("드레곤", uniqueId)
{
    Name = "Dragon";
    CurrentHealth = 4000;
    MonsterDamage = 100;
    MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
