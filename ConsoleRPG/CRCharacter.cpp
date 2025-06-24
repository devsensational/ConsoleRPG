#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "CRGameManager.h"
#include "Singleton.h"

#include <iostream>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack)
    : name(name), iHealth(health), iAttack(attack), iMaxHealth(health), iLevel(1), iExperience(0) 
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
        iHealth = iMaxHealth;  // 레벨업 시 체력 회복
        cout << name << " 레벨업! 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
    }
}

void CRCharacter::showStatus() 
{
    cout << name << " - 레벨: " << iLevel << ", 체력: " << iHealth << ", 공격력: " << iAttack << endl;
}
