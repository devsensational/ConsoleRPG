//작성자: 김선호

#include <vector>

#include "ConsoleRPG.h"
#include "CRGameSystem.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRConsoleRenderer.h"
#include "CRActor.h"
#include "CRGameMode.h"
#include "ICRGameMode.h"

/*	클래스 설명:
*	게임을 초기화하고, LIfecycle을 관리하기 위한 클래스입니다.
*/

using namespace std;

CRGameSystem::CRGameSystem()
{
	GameMode = make_unique<CRGameMode>();
	GameConsoleUI = make_unique<CRConsoleUI>();
}

/*
* 게임을 시작합니다.
* Lifecycle이 시작됩니다.
*/
void CRGameSystem::GameStart()
{
	LIfecycle();
}

/*
* 게임 전체의 주기를 반복하는 함수입니다.
*/
void CRGameSystem::LIfecycle()
{
	GameMode->GameStart();
}

/*
* 게임 종료 시그널
*/
void CRGameSystem::GameEnd()
{
	bEndSignal = true;
}
