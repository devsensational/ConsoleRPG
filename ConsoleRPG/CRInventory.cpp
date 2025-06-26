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

    
    CreateItem(1);
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
        Singleton<CREventManager<string>>::GetInstance().Broadcast(EEventType::EET_PushLog, "아이템을 사용했습니다!");
        items[index]->use(Owner);
        items.erase(items.begin() + index);
    }
}

void CRInventory::CreateItem(int index)
{
    switch (index)
    {
    case 1: 
        addItem(make_shared<CRHealthPotion>("RedPotion", 20));
        break;
    case 2: 
        addItem(make_shared<CRHealthPotion>("OrangePotion", 20));
        break;
    case 3: 
        addItem(make_shared<CRHealthPotion>("WhitePotion", 20));
        break;
    case 4: 
        addItem(make_shared<CRAttackBoost>("AttackBoost", 20));
        break;
    default:
        break;
    }
 

        
}
