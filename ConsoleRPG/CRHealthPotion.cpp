#include "CRHealthPotion.h"
#include <iostream>

#include "CRCharacter.h"


using namespace std;

void CRHealthPotion::use(CRCharacter* character) 
{
    // ü�� ȸ��
    cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
    character->takeHealPosition(defaultHealAmount); // ü�� 20 ȸ��, defaultHealAmout�� main���� make_shared<CRRedPotion>("RedPotion", 20) �ش� �����ڿ� �ι�° ���ڰ����� ���޵Ǿ� �ʱ�ȭ�ȴ�.
}
