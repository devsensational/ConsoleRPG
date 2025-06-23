#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "CRInventory.h"

using namespace std;

class CRCharacter 
{
private:
    shared_ptr<CRInventory> inventory;

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

    void takeDamage(int damage);
    void takeHealPosition(int heal);
    void takeAttackBoost(int attack);
    void levelUp();
    void showStatus();

    string getName() const { return name; }
    int getHealth() const { return iHealth; }
    int getAttack() const { return iAttack; }
};
