#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "CRGameManager.h"
#include "Singleton.h"

#include <iostream>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack)
    : name(name), iHealth(health), iAttack(attack), iMaxHealth(health), iLevel(1), iExperience(0) 
{
    // ĳ���� �����ڿ��� inventory shared_ptr��ü �ʱ�ȭ.
    spInventory = make_shared<CRInventory>();




}



// �κ��丮�� �������� �Լ�
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return spInventory;
}
// ĳ���Ͱ� ���° �ε����� �ִ� �������� ����Ұ������� ���� �Լ�
void CRCharacter::useItem(int index)
{
    spInventory->useItem(index, this);
}



void CRCharacter::takeDamage(int damage) 
{
    iHealth -= damage;
    if (iHealth < 0) iHealth = 0;
}

// HealPosition ����ؼ� 50 healȸ��
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

void CRCharacter::levelUp() 
{
    if (iLevel < 10) 
    {
        iLevel++;
        iMaxHealth += iLevel * 20;
        iAttack += iLevel * 5;
        iHealth = iMaxHealth;  // ������ �� ü�� ȸ��
        cout << name << " ������! ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
    }
}

void CRCharacter::showStatus() 
{
    cout << name << " - ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
}
