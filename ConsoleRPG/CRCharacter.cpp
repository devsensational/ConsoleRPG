#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "Singleton.h"
#include "CREventManager.h"

#include <iostream>
#include <algorithm>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack, const int InUniqueId)
    : name(name), CurrentHp(health), Damage(attack), MaxHp(health), Level(1), Experience(0), Gold(100), UniqueId(InUniqueId)
{
    Inventory = make_shared<CRInventory>(this);
    
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CharacterAttack, bind(&CRCharacter::Attack, this)));
    EventIds.push_back(Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_InventoryItemSelect, bind(&CRCharacter::useItem, this, placeholders::_1)));
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRCharacter::GetExp, this)));
    EventIds.push_back(Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRCharacter::GetGold, this)));
    EventIds.push_back(Singleton<CREventManager<int, int>>::GetInstance().Subscribe(EEventType::EET_StoreItemBuy, 
        bind(&CRCharacter::BuyItem, this, placeholders::_1, placeholders::_2)));
    
    Status = EUnitStatus::EUS_Alive;

    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
}



// �κ��丮�� �������� �Լ�
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return Inventory;
}
// ĳ���Ͱ� ���° �ε����� �ִ� �������� ����Ұ������� ���� �Լ�
void CRCharacter::useItem(int index)
{
    Inventory->useItem(index);
}



void CRCharacter::TakeDamage(int InDamage) 
{
    CurrentHp = clamp(CurrentHp - InDamage, 0, MaxHp);
    Singleton<CREventManager<string, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
    if (CurrentHp <= 0) Dead();
}

// ĳ������ ü���� ȸ��
void CRCharacter::Heal(int InValue)
{
    CurrentHp += InValue;
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(InValue) + "�� ü���� ȸ��!");

    Singleton<CREventManager<string, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
    if (CurrentHp < 0) CurrentHp = 0;
}

void CRCharacter::DamageBoost(int InValue)
{
    Damage += InValue;
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(InValue) + "�� ������ ���!");
}

void CRCharacter::LevelUp() 
{
    if (Level < 10) 
    {
        Level++;
        MaxHp += 15*Level;
        Damage += 6*Level;
        CurrentHp = MaxHp;  // ������ �� ü�� ȸ��
        Experience = 0;
        Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);

        Singleton<CREventManager<string, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "���� ��!!! ü���� ȸ���Ǿ����ϴ�!");
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

    Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(GoldValue) + " ��� ȹ��!");

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

void CRCharacter::BuyItem(int itemIndex, int price)
{
    // ��尡 ������� Ȯ��
    if (Gold >= price) {
        Gold -= price;
        
        // ������ ���� �̺�Ʈ �߻�
        Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_StoreItemSelect, itemIndex);
        
        // �α� �޽��� ���
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            to_string(price) + " ��带 �����ϰ� �������� �����߽��ϴ�!");
        
        // ĳ���� ���� ������Ʈ
        Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
    }
    else {
        // ��� ���� �޽��� ���
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            "��尡 �����մϴ�!");
        
        // ���� ���� �̺�Ʈ �߻�
        Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_StoreItemBuyFailed);
    }
}
