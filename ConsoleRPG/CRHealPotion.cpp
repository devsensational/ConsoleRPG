#include "CRHealPotion.h"
#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CRHealPotion::use(CRCharacter* character) 
{
    // ü�� ȸ��
    cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->takeHealPosition(+50); // ü�� +50 ȸ��
}
