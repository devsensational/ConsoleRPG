#include <iostream>


#include "CRCharacter.h"

#include "CRAttackBoost.h"

using namespace std;

void CRAttackBoost::use(CRCharacter* character) 
{
    // ���ݷ� ����
    cout << character->getName() << "��(��) ���ݷ��� �������׽��ϴ�!" << endl;
    character->takeAttackBoost(+10); // ���ݷ� +10
}
