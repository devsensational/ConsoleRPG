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
	PlayerCharacter = make_shared<CRCharacter>(UserName, 100, 10);
}

void CRGameMode::GameStart()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_SetUserName);
	SetUserName();
	while(!bIsGameOver)
	{
		CombatManager->CombatInit(PlayerCharacter);
		while (!bIsCombatOver)
		{
			CombatManager->CombatStart();
		}
		if (bIsGameOver) break;
		Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_StoreOpen);
	}
}

void CRGameMode::SetUserName()
{
	cin >> UserName;
}

