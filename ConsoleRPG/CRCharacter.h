#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "ICRCombat.h"
#include "CRInventory.h"

using namespace std;

class CRCharacter : public ICRCombat
{
private:
    // 인벤토리를 가르킬 수 있는 쉐어드포인터를 캐릭터가 들고 있는 형태
    shared_ptr<CRInventory> spInventory;

    // 이벤트 리스터 ID 저장
    int iListenerID = 0;
    int UniqueId = 0;
    vector<int> EventIds;

protected:
    string name;
    int CurrentHp;
    int MaxHp;
    int Damage;
    int Level;
    int Experience;
    int Gold;

    EUnitStatus Status = EUnitStatus::EUS_Default;

public:
    CRCharacter(string name, int health, int attack, const int InUniqueId);
    virtual ~CRCharacter() {}

    shared_ptr<CRInventory> getInventory();
    void useItem(int index);

    void TakeDamage(int damage) override;
    void Heal(int heal);
    void DamageBoost(int attack);
    void LevelUp();
    void GetExp();
    void GetGold();
    void ShowStatus();
    void Dead() override;

    string GetName() const { return name; }
    int getHealth() const { return CurrentHp; }
    int getAttack() const { return Damage; }
    inline int GetMaxHp() const { return MaxHp; }

    // ICRCombat을(를) 통해 상속됨
    void Act() override;
    void Attack() override;


    // ICRCombat을(를) 통해 상속됨
    inline int GetUniqueId() override { return UniqueId; }
    inline EUnitStatus GetUnitStatus() override { return Status; }
};
