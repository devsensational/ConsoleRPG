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
    shared_ptr<CRInventory> spInventory;

    // �̺�Ʈ ������ ID ����
    int iListenerID = 0;
    int UniqueId = 0;
    vector<int> EventIds;

protected:
    string name;
    int iHealth;
    int iMaxHealth;
    int iAttack;
    int iLevel;
    int iExperience;

    EUnitStatus Status = EUnitStatus::EUS_Default;

public:
    CRCharacter(string name, int health, int attack, const int InUniqueId);
    virtual ~CRCharacter() {}

    shared_ptr<CRInventory> getInventory();
    void useItem(int index);

    void TakeDamage(int damage) override;
    void takeHealPosition(int heal);
    void takeAttackBoost(int attack);
    void levelUp();
    void showStatus();
    void Dead() override;

    string getName() const { return name; }
    int getHealth() const { return iHealth; }
    int getAttack() const { return iAttack; }
    inline int GetMaxHp() const { return iMaxHealth; }

    // ICRCombat��(��) ���� ��ӵ�
    void Act() override;
    void Attack() override;


    // ICRCombat��(��) ���� ��ӵ�
    inline int GetUniqueId() override { return UniqueId; }
    inline EUnitStatus GetUnitStatus() override { return Status; }
};
