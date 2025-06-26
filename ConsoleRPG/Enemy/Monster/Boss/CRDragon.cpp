#include "CRDragon.h"

Dragon::Dragon(int level, int uniqueId)  : MonsterBase("드레곤", uniqueId)
{
    Name = "Dragon";
    CurrentHealth = 500;
    MaxHealth = 500;
    MonsterDamage = 100;
    MonsterAttribute = EMonsterAttribute::EMA_Fire;
}
