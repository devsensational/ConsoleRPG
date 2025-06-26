#include "CRInventory.h"
#include "CRCharacter.h"

#include "CRHealthPotion.h"
#include "CROrangePotion.h"
#include "CRWhitePotion.h"
#include "CRAttackBoost.h"

#include "Singleton.h"
#include "CREventManager.h"



CRInventory::CRInventory(CRCharacter* target)
{
    Owner = target;
    Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_MonsterRandomDrop, bind(&CRInventory::CreateItem, this, placeholders::_1));
    Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_InventoryOpen, bind(&CRInventory::showItems, this));
    Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_StoreItemSelect, bind(&CRInventory::CreateItem, this, placeholders::_1));

}

void CRInventory::addItem(shared_ptr<CRItem> item)
{
    items.push_back(item);
}

void CRInventory::showItems() {
    Singleton<CREventManager<vector<shared_ptr<CRItem>>>>::GetInstance().Broadcast(EEventType::EET_ShowInventoryList, items);
        

}

void CRInventory::useItem(int index) 
{
    if (index >= 0 && index < items.size()) 
    {
        // 디버깅 로그 추가
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            "아이템 사용: " + items[index]->getName());
        
        items[index]->use(Owner);
        items.erase(items.begin() + index);
    }
    else
    {
        // 인덱스 오류 로그 추가
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, 
            "오류: 잘못된 아이템 인덱스 - " + to_string(index));
    }
}

void CRInventory::CreateItem(int index)
{
    switch (index)
    {
    case 1: 
        addItem(make_shared<CRHealthPotion>("RedPotion", 20));
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "체력 포션을 획득했습니다!");
        break;
    case 2: 
        addItem(make_shared<CRAttackBoost>("AttackBoost", 20));
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "공격력 증가 스크롤을 획득했습니다!");
        break;
    default:
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "알 수 없는 아이템 인덱스: " + to_string(index));
        break;
    }
}
