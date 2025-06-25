#include "CRConsoleUI.h"
#include "Singleton.h"
#include "CREventManager.h"

CRConsoleUI::CRConsoleUI()
{
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_SetUserName, bind(&CRConsoleUI::SelectName, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_StoreOpen, bind(&CRConsoleUI::PrintStoreMenu, this));
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_CharacterTakeDamage, bind(&CRConsoleUI::PrintMonsterAttackLog, this, placeholders::_1));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatLose, bind(&CRConsoleUI::PrintCombatLose, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRConsoleUI::PrintCombatWin, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_GameOver, bind(&CRConsoleUI::PrintGameOver, this));


	
}

void CRConsoleUI::SelectName()
{
	cout << "닉네임을 입력해주세요: ";
}

void CRConsoleUI::PrintCombatMenu()
{
	int Select = 0;
	cout << "행동을 선택해주세요: ";
	cin >> Select;
	
}

void CRConsoleUI::PrintStoreMenu()
{
	int Select = 0;
	cout << "상점 메뉴를 선택해주세요: ";
	cin >> Select;
}

void CRConsoleUI::PrintCombatUI()
{
	int LogSize = max(CombatLogList->size(), CombatStatusList->size());
	for (int i = 0; i < LogSize; i++)
	{
		
	}
}

void CRConsoleUI::PrintMonsterAttackLog(int damage)
{
	cout << "몬스터가 " << damage << "데미지의 공격! " << '\n';
}

void CRConsoleUI::PrintCombatLose()
{
	cout << "전투에서 패배했습니다!" << '\n';
}
void CRConsoleUI::PrintCombatWin()
{
	cout << "전투에서 승리했습니다!" << '\n';
}

void CRConsoleUI::PrintGameOver()
{
	cout << "GAME OVER" << '\n';
}

