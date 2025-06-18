// 작성자: 김선호

#include <iostream>

#include "Singleton.h"
#include "CREventManager.h"
#include "CRGameSystem.h"

int main()
{
    CRGameSystem* GameSystem = new CRGameSystem;
    GameSystem->GameStart();

}
