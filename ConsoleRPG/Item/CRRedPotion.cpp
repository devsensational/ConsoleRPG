#include "CRRedPotion.h"
#include <iostream>

#include "../Character/CRCharacter.h"

using namespace std;

// PotionBase�� ����� ���Ƴ��� �� ������ �ʿ����
// void CRRedPotion::use(CRCharacter* character) 
// {
//     // ü�� ȸ��
//     cout << character->getName() << "��(��) ü���� ȸ���߽��ϴ�!" << endl;
//     character->takeHealPotion(defaultHealAmount); // ü�� 20 ȸ��, defaultHealAmount�� main���� make_shared<CRRedPotion>("RedPotion", 20) �ش� �����ڿ� �ι�° ���ڰ����� ���޵Ǿ� �ʱ�ȭ�ȴ�.
// } 
