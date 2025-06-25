#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level) : MonsterBase("고블린") 
{
  Name = "Goblin";  
  CurrentHealth = 30 + level * 10;
  MonsterDamage = 5 + level*5;
}
