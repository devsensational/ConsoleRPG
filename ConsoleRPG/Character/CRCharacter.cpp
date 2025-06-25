#include "CRCharacter.h"
#include "../ConsoleRPG.h"
#include "../CRGameManager.h"
#include "../Singleton.h"

#include <iostream>

using namespace std;

CRCharacter::CRCharacter(string name, int health, int attack)
    : name(name),
    iHealth(health), iMaxHealth(health),
    iAttack(attack), iBaseAttack(attack), iAttackBoost(0),
    iLevel(1), iExperience(0) 
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
void CRCharacter::takeHealPotion(int heal)
{
    iHealth += heal;
    if (iHealth > iMaxHealth) iHealth = iMaxHealth;
}

void CRCharacter::takeAttackBoost(int attack)
{
    iAttackBoost = attack;
    iAttack = iBaseAttack + iAttackBoost;
}

void CRCharacter::resetBoost()
{
    iAttackBoost = 0;
    iAttack = iBaseAttack;
}

void CRCharacter::gainExp(int exp)
{
    if (iLevel < 10)
    {
        iExperience += exp;
        if (iExperience >= 100)
        {
            levelUp();
            iExperience -= 100;
        }
    }
}
/*
 *iExperience >= 100 �� �Ǹ� ����
 */
void CRCharacter::levelUp() 
{
    iLevel++;
    iMaxHealth += iLevel * 20;
    iHealth = iMaxHealth;  // ������ �� ü�� ȸ��
    
    iBaseAttack += iLevel * 5;
    if (iAttackBoost == 0) // ���� ��ȭȿ���� ���� ��
    {
        iAttack = iBaseAttack; // �⺻ ���ݷ� ������Ʈ
    }
    else // ���� ��ȭȿ���� ���� ��
    {
        iAttack = iBaseAttack + iAttackBoost; // �⺻ ���ݷ� + ��ȭȿ��
    }
    
    cout << name << " ������! ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
}

void CRCharacter::showStatus() 
{
    cout << name << " - ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
}
