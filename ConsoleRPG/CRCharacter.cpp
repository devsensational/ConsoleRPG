#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "Singleton.h"
#include "CREventManager.h"

#include <iostream>
#include <algorithm>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack, const int InUniqueId)
    : name(name), iHealth(health), iAttack(attack), iMaxHealth(health), iLevel(1), iExperience(0), UniqueId(InUniqueId)
{
    spInventory = make_shared<CRInventory>(this);
    
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CharacterAttack, bind(&CRCharacter::Attack, this)));
    EventIds.push_back(Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_InventoryItemSelect, bind(&CRCharacter::useItem, this, placeholders::_1)));
    
    Status = EUnitStatus::EUS_Alive;

}



// 인벤토리를 가져오는 함수
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return spInventory;
}
// 캐릭터가 몇번째 인덱스에 있는 아이템을 사용할것인지에 대한 함수
void CRCharacter::useItem(int index)
{
    spInventory->useItem(index);
}



void CRCharacter::TakeDamage(int damage) 
{
    iHealth = clamp(iHealth - damage, 0, iMaxHealth);
    Singleton<CREventManager<string, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, iHealth, iMaxHealth);
    if (iHealth <= 0) Dead();
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

void CRCharacter::Dead()
{
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterDead, UniqueId);

    Singleton<CREventManager<>>::GetInstance().Unsubscribe(EEventType::EET_CharacterAttack, EventIds[0]);
    Status = EUnitStatus::EUS_Dead;
}

void CRCharacter::Act()
{
    Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CharacterAct);

    
}

void CRCharacter::Attack()
{
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterAttack, iAttack);
}
