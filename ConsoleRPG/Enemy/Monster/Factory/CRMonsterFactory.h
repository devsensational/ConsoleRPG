#pragma once
#include "../Interface/CRMonsterBase.h"
#include <memory>

class CRMonsterFactory

{
public:
    /**
     * @brief 몬스터 타입에 따라 해당하는 몬스터 인스턴스를 생성
     * 
     * @param monsterType 생성할 몬스터의 타입
     * @param level 몬스터의 레벨 (몬스터의 기본 능력치에 영향을 줌)
     * @return std::unique_ptr<MonsterBase> 생성된 몬스터 인스턴스.
     *         알 수 없는 몬스터 타입인 경우 nullptr 반환
     * 
     * @note 반환된 포인터는 unique_ptr로 관리되어 자동으로 메모리가 해제됩니다
     * @see EMonsterType
     * @see MonsterBase
     */

    static std::unique_ptr<MonsterBase> CreateMonster(CRMonsterFactory monsterType, int level);

private:
  /** @brief 팩토리 클래스의 인스턴스화를 방지하기 위한 private 생성자 */
  CRMonsterFactory() = default;

};