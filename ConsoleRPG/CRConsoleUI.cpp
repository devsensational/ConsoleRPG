#include <Windows.h>
#include <iomanip>
#include <sstream>

#include "CRConsoleUI.h"
#include "Singleton.h"
#include "CRItem.h"
#include "CREventManager.h"

#define MAX_LOGSIZE 10
#define LEFTCONSOLE_DEFAULT 2

CRConsoleUI::CRConsoleUI()
{
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_SetUserName, bind(&CRConsoleUI::SelectName, this));
	Singleton<CREventManager<vector<shared_ptr<CRItem>>>>::GetInstance().Subscribe(EEventType::EET_ShowInventoryList, bind(&CRConsoleUI::PrintInventory, this, placeholders::_1));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_StoreOpen, bind(&CRConsoleUI::PrintStoreMenu, this));
	Singleton<CREventManager<int>>::GetInstance().Subscribe(EEventType::EET_CharacterTakeDamage, bind(&CRConsoleUI::PrintMonsterAttackLog, this, placeholders::_1));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatLose, bind(&CRConsoleUI::PrintCombatLose, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatWin, bind(&CRConsoleUI::PrintCombatWin, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_GameOver, bind(&CRConsoleUI::PrintGameOver, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CharacterAct, bind(&CRConsoleUI::PrintCombatMenu, this));
	Singleton<CREventManager<>>::GetInstance().Subscribe(EEventType::EET_CombatApply, bind(&CRConsoleUI::PrintCombatUI, this));
	Singleton<CREventManager<string, int, int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterStatInit, 
			bind(&CRConsoleUI::InitCharacterStatus, this, placeholders::_1, placeholders::_2, placeholders::_3));
	Singleton<CREventManager<string, int, int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterStatInit,
			bind(&CRConsoleUI::InitMonsterStatus, this, placeholders::_1, placeholders::_2, placeholders::_3));
	LeftConsole.resize(LEFTCONSOLE_DEFAULT);
	
}

void CRConsoleUI::SelectName()
{
	cout << "닉네임을 입력해주세요: ";
}

void CRConsoleUI::PrintCombatMenu()
{
	int Select = 0;
	bool Exit = false;
	cout << "1. 공격" << '\n';
	cout << "2. 인벤토리" << '\n';
	cout << "행동을 선택해주세요: ";
	
	while (!Exit)
	{
		cin >> Select;
		switch (Select)
		{
		case 1:
			Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CharacterAttack);
			Exit = true;
			break;
		case 2:
			Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_InventoryOpen);
			Exit = true;
			break;
		default:
			cout << "잘못 입력하셨습니다!" << '\n';
			break;
		}
	}
}

void CRConsoleUI::PrintInventory(const vector<shared_ptr<CRItem>> InItems)
{
	if (InItems.empty())
	{
		cout << "소지한 아이템이 없습니다!";
		system("pause");
		PrintCombatMenu();
		return;
	}

	bool Exit = false;
	int Select = 0;
	while (!Exit)
	{
		for (int i = 0; i < InItems.size(); i++)
		{
			cout << i + 1 << ". " << InItems[i]->getName() << '\n';
		}
		cout << "아이템을 선택해주세요: ";
		cin >> Select;

		if (Select > InItems.size() || Select < 1)
		{
			cout << "잘못 입력하셨습니다" << '\n';
		}
		else 
		{
			Select = 0;
			Exit = true;
		}
	}

	Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_InventoryItemSelect, Select);
}

void CRConsoleUI::PrintStoreMenu()
{

	bool Exit = false;

	int Select = 0;
	while (!Exit)
	{
		cout << "상점" << '\n';
		cout << "1. 랜덤 포션" << '\n';
		cout << "2. 랜덤 스크롤" << '\n';
		cout << "상점 메뉴를 선택해주세요: ";
		cin >> Select;

		if (Select > 2 || Select < 1)
		{
			cout << "잘못 입력하셨습니다" << '\n';
		}
		else
		{
			Exit = true;
		}
	}

	//Todo: 랜덤한 숫자 들어가도록 변경
	Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_StoreItemSelect, Select);
}

void CRConsoleUI::PrintCombatUI()
{
	system("cls");
	int LogSize = max(LeftConsole.size(), RightConsole.size());
	for (int i = 0; i < LogSize; i++)
	{
		if (i >= LeftConsole.size())
		{
			cout << setw(CONSOLE_WIDTH) << RightConsole[i] << '\n';
		}
		else if (i >= RightConsole.size())
		{
			cout << LeftConsole[i] << '\n';
		}
		else
		{
			cout << LeftConsole[i] << setw(CONSOLE_WIDTH) << RightConsole[i] << '\n';
		}
	}
}

void CRConsoleUI::InitCharacterStatus(const string& InName, const int& CurrentHp, const int& MaxHp)
{
	ostringstream oss;
	oss << InName << ": " << CurrentHp << "/" << MaxHp;
	LeftConsole[0] = oss.str();
}

void CRConsoleUI::InitMonsterStatus(const string& InName, const int& CurrentHp, const int& MaxHp)
{
	ostringstream oss;
	oss << InName << ": " << CurrentHp << "/" << MaxHp;
	LeftConsole[1] = oss.str();
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

