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
* ����(Combat)�� �ʱ�ȭ�մϴ�.
* CombatSequence�� ���ֵ��� �߰��մϴ�.
*/
void CRGameMode::CombatInit()
{
	//Todo: �� ĳ���Ϳ� ���� �� ���ֵ��� ���� �� CombatSequence�� �߰��ؾ� ��
}

/*
* CombatSequence�� ������ ���� ��� ������ ������ �����մϴ�.
* ICRCombat�� ���� Attack()�� ȣ���մϴ�.
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
* Combat�� �ֱⰡ ��� ������� �� ȣ��˴ϴ�.
* CombatSquence�� �ʱ�ȭ�մϴ�.
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
