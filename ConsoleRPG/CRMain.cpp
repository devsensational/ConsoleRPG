// 작성자: 김선호

#include <iostream>

#include "Singleton.h"
#include "CRGameSystem.h"

int main()
{
    // new를 사용한 이유
    CRGameSystem* GameSystem = new CRGameSystem;
    GameSystem->GameStart();
    // delete 필요하지않나?

}
