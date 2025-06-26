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
    CRCharacter* Owner;

public:
    CRInventory(CRCharacter* target);


    void addItem(shared_ptr<CRItem> item);
    void showItems();
    void useItem(int index);
    // ���� ������ ȹ�� �Լ�
    void CreateItem(int index);


};
