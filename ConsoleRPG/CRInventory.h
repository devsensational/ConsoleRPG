#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "CRItem.h"

using namespace std;

class CRCharacter;

class CRInventory 
{
private:
    vector<shared_ptr<CRItem>> items;

public:
    CRInventory();


    void addItem(shared_ptr<CRItem> item);
    void showItems();
    void useItem(int index, CRCharacter* target);
    // ·£´ý ¾ÆÀÌÅÛ È¹µæ ÇÔ¼ö
    void createItem(int index);


};
