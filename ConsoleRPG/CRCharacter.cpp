#include "CRCharacter.h"
#include <iostream>

using namespace std;

CRCharacter::CRCharacter(string name, int health, int attack)
    : name(name), iHealth(health), iAttack(attack), iMaxHealth(health), iLevel(1), iExperience(0) 
{
}

void CRCharacter::takeDamage(int damage) {
    iHealth -= damage;
    if (iHealth < 0) iHealth = 0;
}

// HealPosition 사용해서 50 heal회복
void CRCharacter::takeHealPosition(int heal)
{
    iHealth += heal;
    if (iHealth < 0) iHealth = 0;
}

void CRCharacter::takeAttackBoost(int attack)
{
    iAttack += attack;
    if (iAttack < 0) iAttack = 0;
}

void CRCharacter::levelUp() {
    if (iLevel < 10) {
        iLevel++;
        iMaxHealth += iLevel * 20;
        iAttack += iLevel * 5;
        iHealth = iMaxHealth;  // 레벨업 시 체력 회복
        cout << name << " 레벨업! 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
    }
}

void CRCharacter::showStatus() {
    cout << name << " - 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
}
