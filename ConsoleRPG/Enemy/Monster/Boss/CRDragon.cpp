#include "CRDragon.h"

Dragon::Dragon(int level)  : MonsterBase("드레곤")
{
    Name = "Dragon";
    CurrentHealth = 4000;
    MonsterDamage = 100;
    MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
