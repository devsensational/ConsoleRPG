#pragma once
#include <iostream>
#include <string>
using namespace std;

class CRCharacter 
{
public:
    CRCharacter(string name, int health, int attack);  
    virtual ~CRCharacter() {}

    void takeDamage(int damage);
    void takeHealPosition(int heal);
    void takeAttackBoost(int heal);
    void levelUp();
    void showStatus();

    string getName() const { return name; }
    int getHealth() const { return iHealth; }
    int getAttack() const { return iAttack; }

protected:
    string name;
    int iHealth;
    int iMaxHealth;
    int iAttack;
    int iLevel;
    int iExperience;
};
