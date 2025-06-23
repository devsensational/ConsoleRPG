#include "CRInventory.h"
#include "CRCharacter.h"

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
    if (index >= 0 && index < items.size()) {
        items[index]->use(target);
        items.erase(items.begin() + index);
    }
}
