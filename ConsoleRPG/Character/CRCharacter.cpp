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
    // 캐릭터 생성자에서 inventory shared_ptr객체 초기화.
    spInventory = make_shared<CRInventory>();
    
}



// 인벤토리를 가져오는 함수
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return spInventory;
}
// 캐릭터가 몇번째 인덱스에 있는 아이템을 사용할것인지에 대한 함수
void CRCharacter::useItem(int index)
{
    spInventory->useItem(index, this);
}

void CRCharacter::takeDamage(int damage) 
{
    iHealth -= damage;
    if (iHealth < 0) iHealth = 0;
}

// HealPosition 사용해서 50 heal회복
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
 *iExperience >= 100 이 되면 실행
 */
void CRCharacter::levelUp() 
{
    iLevel++;
    iMaxHealth += iLevel * 20;
    iHealth = iMaxHealth;  // 레벨업 시 체력 회복
    
    iBaseAttack += iLevel * 5;
    if (iAttackBoost == 0) // 현재 강화효과가 없을 때
    {
        iAttack = iBaseAttack; // 기본 공격력 업데이트
    }
    else // 현재 강화효과가 있을 때
    {
        iAttack = iBaseAttack + iAttackBoost; // 기본 공격력 + 강화효과
    }
    
    cout << name << " 레벨업! 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
}

void CRCharacter::showStatus() 
{
    cout << name << " - 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
}
