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


protected:
    string name;
    int iHealth;
    int iMaxHealth;
    int iAttack;
    int iLevel;
    int iExperience;

public:
    CRCharacter(string name, int health, int attack);
    virtual ~CRCharacter() {}

    shared_ptr<CRInventory> getInventory();
    void useItem(int index);

    void TakeDamage(int damage);
    void takeHealPosition(int heal);
    void takeAttackBoost(int attack);
    void levelUp();
    void showStatus();

    string getName() const { return name; }
    int getHealth() const { return iHealth; }
    int getAttack() const { return iAttack; }

    // ICRCombat��(��) ���� ��ӵ�
    void Attack() override;
};
