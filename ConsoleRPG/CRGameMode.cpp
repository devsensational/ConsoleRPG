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
}

void CRGameMode::SetUserName(const string& text)
{
	UserName = text; 
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
