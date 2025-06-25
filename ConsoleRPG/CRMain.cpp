// 작성자: 김선호

#include <iostream>
#include <memory>
#include "CRGameSystem.h"

using namespace std;

int main() 
{
    CRGameSystem* GameSystem = new CRGameSystem;
    GameSystem->GameStart();
    return 0;
}
