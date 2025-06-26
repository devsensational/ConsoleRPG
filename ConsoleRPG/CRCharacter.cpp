#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "Singleton.h"
#include "CREventManager.h"

#include <iostream>
#include <algorithm>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack, const int InUniqueId)
    : name(name), CurrentHp(health), Damage(attack), MaxHp(health), Level(1), Experience(0), Gold(0), UniqueId(InUniqueId)
{
    spInventory = make_shared<CRInventory>(this);
    
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CharacterAttack, bind(&CRCharacter::Attack, this)));
    EventIds.push_back(Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_InventoryItemSelect, bind(&CRCharacter::useItem, this, placeholders::_1)));
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRCharacter::GetExp, this)));
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRCharacter::GetGold, this)));
    
    Status = EUnitStatus::EUS_Alive;

    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
}



// �κ��丮�� �������� �Լ�
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return spInventory;
}
// ĳ���Ͱ� ���° �ε����� �ִ� �������� ����Ұ������� ���� �Լ�
void CRCharacter::useItem(int index)
{
    spInventory->useItem(index);
}



void CRCharacter::TakeDamage(int InDamage) 
{
    CurrentHp = clamp(CurrentHp - InDamage, 0, MaxHp);
    Singleton<CREventManager<string, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
    if (CurrentHp <= 0) Dead();
}

// HealPosition ����ؼ� 50 healȸ��
void CRCharacter::Heal(int InValue)
{
    CurrentHp += InValue;
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(InValue) + "�� ü���� ȸ��!");
    if (CurrentHp < 0) CurrentHp = 0;
}

void CRCharacter::DamageBoost(int InValue)
{
    Damage += InValue;
    if (Damage < 0) Damage = 0;
}

void CRCharacter::LevelUp() 
{
    if (Level < 10) 
    {
        Level++;
        MaxHp += 20;
        Damage += 5;
        CurrentHp = MaxHp;  // ������ �� ü�� ȸ��
        Experience = 0;
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "���� ��!!! ü���� ȸ���Ǿ����ϴ�!");
        //cout << name << " ������! ����: " << Level << ", ü��: " << CurrentHp << ", ���ݷ�: " << Damage << endl;
    }
}

void CRCharacter::GetExp()
{
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "50 ����ġ ȹ��!");
    Experience += 50;
    if (Experience >= 100) LevelUp();
    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
}

void CRCharacter::GetGold()
{
    int GoldValue = RandomIndexSelector(10, 20);
    Gold += GoldValue;

    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(GoldValue) + " ��� ȹ��!");
    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);

}

void CRCharacter::ShowStatus() 
{
    cout << name << " - ����: " << Level << ", ü��: " << CurrentHp << ", ���ݷ�: " << Damage << endl;
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

    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
    
}

void CRCharacter::Attack()
{
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterAttack, Damage);
}
