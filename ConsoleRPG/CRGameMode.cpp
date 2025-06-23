#include <memory>

#include "CRGameMode.h"
#include "ICRCombat.h"
#include "CREventManager.h"
#include "Singleton.h"

using namespace std;

CRGameMode::CRGameMode()
{
	UserName = "default";
	CombatSequence = make_unique<vector<shared_ptr<ICRCombat>>>();

	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRGameMode::CombatWin, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatLose, bind(&CRGameMode::CombatLose, this));
}

void CRGameMode::GameStart()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_SetUserName);
	SetUserName();
	while(!bIsGameOver)
	{
		while (!bIsCombatOver)
		{
			CombatStart();
		}
	}
}

void CRGameMode::SetUserName()
{
	cin >> UserName;
}


/*
* 전투(Combat)을 초기화합니다.
* CombatSequence에 유닛들을 추가합니다.
*/
void CRGameMode::CombatInit()
{
	//Todo: 내 캐릭터와 적이 될 유닛들을 생성 후 CombatSequence에 추가해야 함
}

/*
* CombatSequence의 순서에 따라 모든 유닛이 공격을 수행합니다.
* ICRCombat을 통해 Attack()을 호출합니다.
*
*/
void CRGameMode::CombatStart()
{
	if (CombatSequence->empty()) return;

	for (int i = 0; i < CombatSequence->size(); i++)
	{
		(*CombatSequence)[i]->Attack();

	}
}

/*
* Combat의 주기가 모두 종료됐을 때 호출됩니다.
* CombatSquence를 초기화합니다.
*/
void CRGameMode::CombatEnd()
{
	//Singleton<CREventManager<>>::GetInstance().Broadcast("CombatEnd");
	CombatSequence->clear();
}

void CRGameMode::CombatWin()
{
	CombatEnd();
}

void CRGameMode::CombatLose()
{
	bIsGameOver = true;
	CombatLose();
}
