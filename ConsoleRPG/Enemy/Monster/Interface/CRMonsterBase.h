#pragma once

#include "../../../ICRCombat.h"
#include "../../../Singleton.h"
#include "../../../CREventManager.h"
#include "IMonster.h"
#include <string>
#include <algorithm>

class MonsterBase : public IMonster, ICRCombat
{
protected:
    std::string name;
    int CurrentHealth = 100;
    int MaxHealth = 100;
    int MonsterDamage = 10;

public:
    virtual ~MonsterBase() = default;

    /**
     * 몬스터 이름 조회
     * @return 몬스터 이름이 return 됩니다
     */
    std::string GetName() const override
    {
        return name;
    }

    /**
     * 몬스터 현재 체력 조회
     * @return 몬스터 현재 체력을 조회합니다
     */
    int GetCurrentMonsterHealth() const override
    {
        return CurrentHealth;
    }

    /**
     * 몬스터 최대 체력 조회
     * @return 몬스터 최대 체력을 조회합니다
     */
    int GetMaxMonsterHealth() const override
    {
        return MaxHealth;
    }

    /*
     * 몬스터가 공격받을때 사용됩니다
     */
    void TakeDamage(int value) override {
        CurrentHealth = std::clamp(CurrentHealth - value, 0, MaxHealth);
    }

    /**
     * 몬스터가 *공격*할때 사용됩니다
     */
    void Attack() override {
        Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterTakeDamage, MonsterDamage);
    }
};