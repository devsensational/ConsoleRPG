#include "CROrangePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CROrangePotion::use(CRCharacter* character)
{
    // ü�� ȸ��
    cout << character->GetName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->Heal(defaultHealAmount); // ü�� 35 ȸ��
}
