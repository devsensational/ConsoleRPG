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



// 인벤토리를 가져오는 함수
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return Inventory;
}
// 캐릭터가 몇번째 인덱스에 있는 아이템을 사용할것인지에 대한 함수
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

// 캐릭터의 체력을 회복
void CRCharacter::Heal(int InValue)
{
    CurrentHp += InValue;
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(InValue) + "의 체력을 회복!");

    Singleton<CREventManager<string, int, int>>::GetInstance()
        .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
    if (CurrentHp < 0) CurrentHp = 0;
}

void CRCharacter::DamageBoost(int InValue)
{
    Damage += InValue;
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(InValue) + "의 데미지 상승!");
}

void CRCharacter::LevelUp() 
{
    if (Level < 10) 
    {
        Level++;
        MaxHp += 15*Level;
        Damage += 6*Level;
        CurrentHp = MaxHp;  // 레벨업 시 체력 회복
        Experience = 0;
        Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);

        Singleton<CREventManager<string, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterCombatStatInit, name, CurrentHp, MaxHp);
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "레벨 업!!! 체력이 회복되었습니다!");
    }
}

void CRCharacter::GetExp()
{
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "50 경험치 획득!");
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
    Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, to_string(GoldValue) + " 골드 획득!");

}

void CRCharacter::ShowStatus() 
{
    cout << name << " - 레벨: " << Level << ", 체력: " << CurrentHp << ", 공격력: " << Damage << endl;
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
    // 골드가 충분한지 확인
    if (Gold >= price) {
        Gold -= price;
        
        // 아이템 생성 이벤트 발생
        Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_StoreItemSelect, itemIndex);
        
        // 로그 메시지 출력
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            to_string(price) + " 골드를 지불하고 아이템을 구매했습니다!");
        
        // 캐릭터 상태 업데이트
        Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
            .Broadcast(EEventType::EET_CharacterStatInit, name, MaxHp, Level, Experience, Damage, Gold);
    }
    else {
        // 골드 부족 메시지 출력
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            "골드가 부족합니다!");
        
        // 구매 실패 이벤트 발생
        Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_StoreItemBuyFailed);
    }
}
