#include "CRMage.h"
#include <iostream>

using namespace std;

// 마법사 클래스는 CRCharacter의 기본 기능을 그대로 사용
void CRMage::castSpell()
{
    // 마법사 특수 능력 (예시)
    cout << GetName() << "이(가) 마법을 시전합니다!" << endl;
}