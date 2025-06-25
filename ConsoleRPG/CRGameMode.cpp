#include <memory>

#include "CRGameMode.h"
#include "ICRCombat.h"
#include "CREventManager.h"
#include "Singleton.h"
#include "CRCombatManager.h"
#include "CRCharacter.h"
#include "Enemy/Monster/Goblin/CRGoblin.h"

using namespace std;

CRGameMode::CRGameMode()
{
	UserName = "default";

	CombatManager = make_shared<CRCombatManager>();


	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatLose, bind(&CRGameMode::CombatLose, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRGameMode::CombatWin, this));
}

void CRGameMode::GameStart()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_SetUserName);
	SetUserName();
	PlayerCharacter = make_shared<CRCharacter>(UserName, 10000, 20, 0);
	while(!bIsGameOver)
	{
		CombatManager->CombatInit(PlayerCharacter, GameLevel);
		while (!bIsCombatOver)
		{
			CombatManager->CombatStart();
		}
		if (bIsGameOver) break;
		Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_StoreOpen);
		bIsCombatOver = false;

		if (GameLevel >= 10) break;
	}
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_GameOver);
}

void CRGameMode::SetUserName()
{
	cin >> UserName;
}

void CRGameMode::CombatOver()
{
	bIsCombatOver = true;
}

void CRGameMode::CombatWin()
{
	GameLevel++;
	CombatOver();
}

void CRGameMode::CombatLose()
{
	CombatOver();
	bIsGameOver = true;
}

