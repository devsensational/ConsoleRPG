#include "CRWhitePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CRWhitePotion::use(CRCharacter* character)
{
    // ü�� ȸ��
    cout << character->GetName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->Heal(defaultHealAmount); // ü�� +40 ȸ��
}
