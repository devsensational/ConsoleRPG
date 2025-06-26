#include "CRMonsterFactory.h"
#include "../Troll/Troll.h"
#include "../Goblin/CRGoblin.h"
#include "../Orc/CROrc.h"
#include "../Slime/CRSlime.h"
#include "../Boss/CRDragon.h"


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
  // 파라미터 유효성 검사
  if (level < 0 || uniqueId < 0) {
    throw std::invalid_argument("Invalid level or uniqueId");
  }

  try {
    switch (monsterType) {
    case EMonsterType::EMT_Troll:
      return std::make_shared<Troll>(level, uniqueId);

    case EMonsterType::EMT_Goblin:
      return std::make_shared<Goblin>(level, uniqueId);

    case EMonsterType::EMT_Orc:
      return std::make_shared<Orc>(level, uniqueId);

    case EMonsterType::EMT_Slime:
      return std::make_shared<Slime>(level, uniqueId);

    case EMonsterType::EMT_Dragon:
      return std::make_shared<Dragon>(level, uniqueId);

    default:
      return nullptr;
    }
  }catch (const std::bad_alloc& e) {
    // 메모리 할당 실패 처리
    return nullptr;
  }

  catch (const std::exception& e) {
    // 기타 예외 처리
    return nullptr;
  }

}

/**
 * @brief 주어진 레벨과 고유 ID를 기반으로 몬스터 객체를 생성합니다.
 *
 * @param level 생성할 몬스터의 레벨입니다. 레벨은 1에서 10 사이의 정수여야 합니다.
 *              지정된 범위를 벗어나면 nullptr을 반환합니다.
 * @param uniqueId 생성될 몬스터의 고유 식별자입니다.
 * @return std::shared_ptr<MonsterBase> 생성된 몬스터 객체를 가리키는 스마트 포인터입니다.
 *         유효하지 않은 레벨이나 메모리 할당 실패 시 nullptr을 반환합니다.
 */
std::shared_ptr<MonsterBase> CRMonsterFactory::CreateMonsterByLevel(int level, int uniqueId)
{
  if (level < 0 || level > 10)
    return nullptr;

  try {
      return LevelMappings[level].creator(level, uniqueId);
  } catch (const std::bad_alloc&) {
    return nullptr;
  }

  return nullptr;
}

/**
 * @brief 레벨 범위와 해당 범위에 적합한 몬스터를 생성하는 함수 포인터를 매핑한 정적 멤버 변수.
 *
 * @details 각 레벨 범위(minLevel과 maxLevel)에 따라 특정 몬스터(Slime, Goblin, Orc, Troll, Dragon)를 생성하기 위한
 *          MonsterCreator 함수가 정의되어 있습니다. CreateMonsterByLevel 함수에서 레벨에 따라 적절한 몬스터를 생성하는 데 사용됩니다.
 *
 * @note 유효한 레벨은 1에서 10까지입니다. 지정된 레벨이 범위를 벗어날 경우 nullptr을 반환합니다.
 * @see LevelRange
 */
const std::vector<LevelRange> CRMonsterFactory::LevelMappings = {
  {1, 2, [](int level, int uniqueId) { return std::make_shared<Slime>(level, uniqueId); }}, // 0
  {3, 5, [](int level, int uniqueId) { return std::make_shared<Goblin>(level, uniqueId); }}, // 1
  {6, 7, [](int level, int uniqueId) { return std::make_shared<Orc>(level, uniqueId); }}, // 2
  {8, 9, [](int level, int uniqueId) { return std::make_shared<Troll>(level, uniqueId); }}, // 3
  {10, 10, [](int level, int uniqueId) { return std::make_shared<Dragon>(level, uniqueId); }} // 4
};
