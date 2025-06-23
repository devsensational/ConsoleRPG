#include "CRConsoleUI.h"

CRConsoleUI::CRConsoleUI()
{

}

string CRConsoleUI::SelectName()
{
	string Name;
	cout << "닉네임을 입력해주세요: ";
	cin >> Name;

	return string();
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
