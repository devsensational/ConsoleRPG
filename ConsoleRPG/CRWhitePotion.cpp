#include "CRWhitePotion.h"

#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CRWhitePotion::use(CRCharacter* character)
{
    // ü�� ȸ��
    cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->takeHealPosition(defaultHealAmount); // ü�� +40 ȸ��
}
