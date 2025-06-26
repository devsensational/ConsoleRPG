#pragma once
#include "../Interface/CRMonsterBase.h"
#include "../Enum/CRMonsterType.h"
#include "../Struct/CRLevelRange.h"
#include <memory>

class CRMonsterFactory

{
    /**
     * @brief 지정된 몬스터 유형과 레벨에 따라 몬스터 객체를 생성합니다.
     *
     * @param monsterType 생성할 몬스터의 타입 (EMonsterType 열거형 값)
     * @param level 생성될 몬스터의 레벨
     * @return std::shared_ptr<MonsterBase> 생성된 몬스터 객체를 가리키는 스마트 포인터입니다.
     *         유효하지 않은 타입이 전달될 경우 nullptr을 반환합니다.
     */
public:
    static std::shared_ptr<MonsterBase> CreateMonster(EMonsterType monsterType, int level, int uniqueId);

    static std::shared_ptr<MonsterBase> CreateMonsterByLevel(int level, int uniqueId);
private:
    /** @brief 팩토리 클래스의 인스턴스화를 방지하기 위한 private 생성자 */
    CRMonsterFactory() = default;

    static const std::vector<LevelRange> LevelMappings;

};