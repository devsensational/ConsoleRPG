//작성자: 김선호

#include <vector>

#include "ConsoleRPG.h"
#include "CRGameSystem.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRConsoleRenderer.h"
#include "CRActor.h"

/*	클래스 설명:
*	게임을 초기화하고, LIfecycle을 관리하기 위한 클래스입니다.
*/

using namespace std;

CRGameSystem::CRGameSystem()
{
	CombatSequence.push_back(make_shared<CRActor>());
	
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
* 
* 1주기 순서
* 캐릭터 생성 -> 전투 -> 전투 Log 출력 -> 전투 반복 -> (전투 종료) -> 상점 방문 -> (전투 반복) -> 게임 클리어 
*/
void CRGameSystem::LIfecycle()
{
	while (!bEndSignal)
	{
		CombatStart();
		Singleton<CRConsoleRenderer>::GetInstance().PrintBuffer();


		int n;
		cin >> n;
	}
}

/*
* 게임 종료 시그널
*/
void CRGameSystem::GameEnd()
{
	bEndSignal = true;
}

/*
* 전투(Combat)을 초기화합니다.
* CombatSequence에 유닛들을 추가합니다.
*/
void CRGameSystem::CombatInit()
{
	//Todo: 적이 될 유닛들을 CombatSequence에 추가해야 함
}

/*
* CombatSequence의 순서에 따라 모든 유닛이 공격을 수행합니다.
* ICRCombat을 통해 Attack()을 호출합니다.
* 
*/
void CRGameSystem::CombatStart()
{
	for (int i = 0; i < CombatSequence.size(); i++)
	{
		CombatSequence[i]->Attack();
		Singleton<CREventManager<>>::GetInstance().Broadcast("TakeDamage");
	}
}

/*
* Combat의 주기가 모두 종료됐을 때 호출됩니다.
* CombatSquence를 초기화합니다.
*/
void CRGameSystem::CombatEnd()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast("CombatEnd");
	CombatSequence.clear();
}
