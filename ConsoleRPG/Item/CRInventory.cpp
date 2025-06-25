#include "CRInventory.h"
#include "../Character/CRCharacter.h"

#include "CRAttackBoost.h"
#include "CRPotionFactory.h"
#include "CRBoostScrollFactory.h"

#include "../Singleton.h"
#include "../CREventManager.h"



CRInventory::CRInventory()
{
    Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_MonsterRandomDrop, bind(&CRInventory::createItem, this, placeholders::_1));
}

void CRInventory::addItem(shared_ptr<CRItem> item)
{
    items.push_back(item);
}

void CRInventory::showItems() {
    for (int i = 0; i < items.size(); ++i) 
    {
        cout << i << ": " << items[i]->getName() << endl;
    }
}

void CRInventory::useItem(int index, CRCharacter* target) 
{
    if (index >= 0 && index < items.size()) 
    {
        items[index]->use(target);
        items.erase(items.begin() + index);
    }
}

/*
 *나중에 전투 이후에 랜덤으로 번호를 뽑아서
 *해당 아이템이 드랍되도록 하는 구조
 */
void CRInventory::createItem(int index)
{
    switch (index)
    {
    case 1: addItem(CRPotionFactory::createPotion(20));

        break;
    case 2: addItem(CRPotionFactory::createPotion(30));

        break;
    case 3: addItem(CRPotionFactory::createPotion(50));

        break;
    case 4: addItem(make_shared<CRAttackBoost>("AttackBoost", 10));

        break;
    case 5: addItem(CRBoostScrollFactory::createScroll(1));

        break;
    case 6: addItem(CRBoostScrollFactory::createScroll(5));

        break;
    case 7: addItem(CRBoostScrollFactory::createScroll(10));

        break;
    case 8: addItem(CRBoostScrollFactory::createScroll(20));

        break;

    default:
        break;
    }
 

        
}
