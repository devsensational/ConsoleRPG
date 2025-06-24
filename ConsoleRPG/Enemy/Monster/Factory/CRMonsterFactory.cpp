#include "CRMonsterFactory.h"
#include "../Troll/Troll.h"
#include "../Enum/CRMonsterType.h"

std::unique_ptr<MonsterBase> CRMonsterFactory::CreateMonster(CRMonsterFactory monsterType, int level)
{
  switch (monsterType)
  {
  case EMonsterType::EMT_Troll:
    return std::make_unique<Troll>(level);
    
  case EMonsterType::EMT_Goblin:
    return std::make_unique<Troll>(level);

  case EMonsterType::EMT_Orc:
    return std::make_unique<Troll>(level);

  case EMonsterType::EMT_Slime:
    return std::make_unique<Troll>(level);
  
  default:
    return nullptr;
  }
}
