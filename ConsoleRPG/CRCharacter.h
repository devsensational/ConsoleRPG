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
    // �κ��丮�� ����ų �� �ִ� ����������͸� ĳ���Ͱ� ��� �ִ� ����
    shared_ptr<CRInventory> Inventory;

    // �̺�Ʈ ������ ID ����
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

    // ICRCombat��(��) ���� ��ӵ�
    void Act() override;
    void Attack() override;


    // ICRCombat��(��) ���� ��ӵ�
    inline int GetUniqueId() override { return UniqueId; }
    inline EUnitStatus GetUnitStatus() override { return Status; }

    // 아이템 구매 함수 추가
    void BuyItem(int itemIndex, int price);
};
