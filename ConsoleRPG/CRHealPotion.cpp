#include "CRHealPotion.h"
#include <iostream>

using namespace std;

void CRHealPotion::use(CRCharacter* character) 
{
    // ü�� ȸ��
    cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->takeHealPosition(+50); // ü�� +50 ȸ��
}
