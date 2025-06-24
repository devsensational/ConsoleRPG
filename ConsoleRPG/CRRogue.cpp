#include "CRRogue.h"
#include <iostream>

using namespace std;

// 도적 클래스는 CRCharacter의 기본 기능을 그대로 사용
void CRRogue::stealthAttack()
{
    // 도적의 특수 능력 (예시)
    cout << getName() << "이(가) 은신 공격을 합니다!" << endl;
}