#include "CRInventory.h"
#include "CRCharacter.h"

#include "CRRedPotion.h"
#include "CROrangePotion.h"
#include "CRWhitePotion.h"
#include "CRAttackBoost.h"

#include "Singleton.h"
#include "CREventManager.h"



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

void CRInventory::createItem(int index)
{
    switch (index)
    {
    case 1: 
        addItem(make_shared<CRRedPotion>("RedPotion", 20));
        break;
    case 2: 
        addItem(make_shared<CRRedPotion>("OrangePotion", 20));
        break;
    case 3: 
        addItem(make_shared<CRRedPotion>("WhitePotion", 20));
        break;
    case 4: 
        addItem(make_shared<CRAttackBoost>("AttackBoost", 20));
        break;
    default:
        break;
    }
 

        
}
