#include "CRWarrior.h"
#include <iostream>

using namespace std;

// 전사 클래스는 CRCharacter의 기본 기능을 그대로 사용

void CRWarrior::specialMove()
{
    // 전사의 특수기능 (예시)
    cout << GetName() << "이(가) 강력한 베기를 사용합니다!" << endl;
}