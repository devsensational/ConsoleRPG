#include "CROrangePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CROrangePotion::use(CRCharacter* character)
{
    // ü�� ȸ��
    cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->takeHealPosition(defaultHealAmount); // ü�� 35 ȸ��
}
