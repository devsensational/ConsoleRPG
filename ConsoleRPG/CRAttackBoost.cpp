#include <iostream>


#include "CRCharacter.h"

#include "CRAttackBoost.h"

using namespace std;

void CRAttackBoost::use(CRCharacter* character) 
{
    // ���ݷ� ����
    //cout << character->GetName() << "��(��) ���ݷ��� �������׽��ϴ�!" << endl;
    character->DamageBoost(defaultHealAmount);
    // ���ݷ� +20 defaultHealAmount�� main���� make_shared<CRAttackBoost>("AttackBoost", 20); �Լ� ȣ���ؼ� �ʱ�ȭ.
}
