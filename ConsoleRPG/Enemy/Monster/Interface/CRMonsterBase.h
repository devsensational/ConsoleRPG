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
    int health = 100;
    int attack = 10;

public:
    virtual ~MonsterBase() = default;

    std::string GetName() const override
    {
        return name;
    }
    
    int GetHealth() const override
    {
        return health;
    }
    
    void TakeDamage(int value) override {
        health = std::max(0, health - value);
    }

    void Attack() override {
        Singleton<CREventManager<int>>::GetInstance().Subscribe(EventType::CharacterTakeDamage,
            bind(&MonsterBase::TakeDamage, this, placeholders::_1));
    }
};