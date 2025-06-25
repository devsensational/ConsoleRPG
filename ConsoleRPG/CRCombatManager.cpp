#include "CRCombatManager.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRGameMode.h"
#include "Enemy/Monster/Goblin/CRGoblin.h"

CRCombatManager::CRCombatManager()
{
	CombatSequence = make_unique<vector<shared_ptr<ICRCombat>>>();

	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRCombatManager::CombatWin, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatLose, bind(&CRCombatManager::CombatLose, this));
}

/*
* ����(Combat)�� �ʱ�ȭ�մϴ�.
* CombatSequence�� ���ֵ��� �߰��մϴ�.
*/
void CRCombatManager::CombatInit(shared_ptr<ICRCombat> Unit)
{
	CombatSequence->push_back(Unit);
	CombatSequence->push_back(make_shared<Goblin>(1, 1));
	//Todo: �� ĳ���Ϳ� ���� �� ���ֵ��� ���� �� CombatSequence�� �߰��ؾ� ��
}

/*
* CombatSequence�� ������ ���� ��� ������ ������ �����մϴ�.
* ICRCombat�� ���� Attack()�� ȣ���մϴ�.
*
*/
void CRCombatManager::CombatStart()
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
void CRCombatManager::CombatEnd()
{
	//Singleton<CREventManager<>>::GetInstance().Broadcast("CombatEnd");
	CombatSequence->clear();
}

void CRCombatManager::CombatWin()
{
	CombatEnd();
}

void CRCombatManager::CombatLose()
{
	CombatEnd();
}
