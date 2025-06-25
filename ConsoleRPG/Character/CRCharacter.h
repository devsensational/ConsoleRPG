#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "../Item/CRInventory.h"

using namespace std;

class CRCharacter 
{
private:
    // 인벤토리를 가르킬 수 있는 쉐어드포인터를 캐릭터가 들고 있는 형태
    shared_ptr<CRInventory> spInventory;

    // 이벤트 리스터 ID 저장
    int iListenerID;


protected:
    string name;
    int iHealth;
    int iMaxHealth;
    int iAttack;
    int iBaseAttack;
    int iAttackBoost;
    int iLevel;
    int iExperience;

public:
    CRCharacter(string name, int health, int attack);
    virtual ~CRCharacter() {}

    shared_ptr<CRInventory> getInventory();
    void useItem(int index);

    void takeDamage(int damage);
    void takeHealPotion(int heal);
    void takeAttackBoost(int attack);
    void resetBoost();
    void gainExp(int exp);
    void levelUp();
    void showStatus();

    string getName() const { return name; }
    int getHealth() const { return iHealth; }
    int getAttack() const { return iAttack; }
};
