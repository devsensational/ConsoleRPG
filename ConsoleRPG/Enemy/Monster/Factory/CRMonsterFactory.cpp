#include "CRMonsterFactory.h"
#include "../Troll/Troll.h"
#include "../Goblin/CRGoblin.h"
#include "../Orc/CROrc.h"
#include "../Slime/CRSlime.h"


/**
 * @brief 지정된 몬스터 유형과 레벨에 따라 몬스터 객체를 생성합니다.
 *
 * @param monsterType 생성할 몬스터의 유형입니다. EMonsterType 열거형을 사용합니다.
 *        가능한 값: EMT_Troll, EMT_Goblin, EMT_Orc, EMT_Slime.
 * @param level 생성될 몬스터의 레벨을 나타냅니다. 정수 값이어야 합니다.
 * @return std::shared_ptr<MonsterBase> 생성된 몬스터 객체를 가리키는 스마트 포인터.
 *         유효하지 않은 유형이 사용될 경우 nullptr을 반환합니다.
 */
std::shared_ptr<MonsterBase> CRMonsterFactory::CreateMonster(EMonsterType monsterType, int level, int uniqueId)
{
  switch (monsterType)
  {
  case EMonsterType::EMT_Troll:
    return std::make_shared<Troll>(level, uniqueId);
    
  case EMonsterType::EMT_Goblin:
    return std::make_shared<Goblin>(level, uniqueId);

  case EMonsterType::EMT_Orc:
    return std::make_shared<Orc>(level, uniqueId);

  case EMonsterType::EMT_Slime:
    return std::make_shared<Slime>(level, uniqueId);
  
  default:
    return nullptr;
  }
}
