#include <Windows.h>
#include <iomanip>
#include <sstream>

#include "CRConsoleUI.h"
#include "Singleton.h"
#include "CRItem.h"
#include "CREventManager.h"

#define MAX_LOGSIZE 10
#define LEFTCONSOLE_DEFAULT 10
#define COLUMN_WIDTH 40

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
		.Subscribe(EEventType::EET_CharacterCombatStatInit, 
			bind(&CRConsoleUI::InitCharacterStatus, this, placeholders::_1, placeholders::_2, placeholders::_3));
	Singleton<CREventManager<string, int, int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterCombatStatInit,
			bind(&CRConsoleUI::InitMonsterStatus, this, placeholders::_1, placeholders::_2, placeholders::_3));
	Singleton<CREventManager<string>>::GetInstance().Subscribe(EEventType::EET_PushLog, bind(&CRConsoleUI::PushConsoleLog, this, placeholders::_1));
	// 플레이어가 공격을 시도할 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterAttack, bind(&CRConsoleUI::PrintCharacterAttackLog, this, placeholders::_1));
	// 몬스터가 공격을 시도할 때 호출
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterAttack, bind(&CRConsoleUI::PrintMonsterAttackLog, this, placeholders::_1));
	
	Singleton<CREventManager<string, int, int, int, int, int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterStatInit,
			bind(&CRConsoleUI::PrintCharacterStatus, this, placeholders::_1, placeholders::_2, placeholders::_3, placeholders::_4, placeholders::_5, placeholders::_6));

	
	// 콘솔 사이즈 초기화
	LeftConsole.resize(LEFTCONSOLE_DEFAULT);

}

void CRConsoleUI::SelectName()
{
	cout << "닉네임을 입력해주세요: ";
}

void CRConsoleUI::PrintCombatMenu()
{
	string Select;
	int Index = 0;
	bool Exit = false;
	cout << "1. 공격" << '\n';
	cout << "2. 인벤토리" << '\n';
	cout << "행동을 선택해주세요: ";
	
	while (!Exit)
	{
		cin >> Select;
		if (IsNumeric(Select)) Index = stoi(Select);
		switch (Index)
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
	string Select;
	int Index = 0;
	while (!Exit)
	{
		for (int i = 0; i < InItems.size(); i++)
		{
			cout << i + 1 << ". " << InItems[i]->getName() << '\n';
		}
		cout << "아이템을 선택해주세요: ";
		cin >> Select;

		if(IsNumeric(Select)) Index = stoi(Select);

		if (Index > InItems.size() || Index < 1)
		{
			cout << "잘못 입력하셨습니다" << '\n';
		}
		else 
		{
			Select = "";
			Exit = true;
		}
	}

	Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_InventoryItemSelect, Index);
}

bool CRConsoleUI::IsNumeric(const string& InStr)
{
	if (InStr.empty()) return false;

	for (char c : InStr)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}

void CRConsoleUI::PrintStoreMenu()
{

	bool Exit = false;
	string EnterStore;
	cout << "상점에 입장 하시겠습니까? (Y/N) 잘못 입력 시 이용할 수 없습니다: ";
	cin >> EnterStore;
	
	if (EnterStore == "Y" || EnterStore == "y") {}
	else return;

	string Select;
	while (!Exit)
	{
		cout << "상점" << '\n';
		cout << "1. 랜덤 포션" << '\n';
		cout << "2. 랜덤 스크롤" << '\n';
		cout << "상점 메뉴를 선택해주세요: ";
		cin >> Select;

		if (Select == "1" || Select == "2")
		{
			Exit = true;
		}
		else
		{
			cout << "잘못 입력하셨습니다" << '\n';
		}
	}

	//Todo: 랜덤한 숫자 들어가도록 변경
	Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_StoreItemSelect, stoi(Select));
}

void CRConsoleUI::PrintCombatUI()
{
	system("cls");
	int LogSize = max(LeftConsole.size(), RightConsole.size());

	for (int i = 0; i < LogSize; i++)
	{
		string left = (i < LeftConsole.size()) ? LeftConsole[i] : "";
		string right = (i < RightConsole.size()) ? RightConsole[i] : "";

		// 왼쪽 출력
		cout << left;

		// 왼쪽 문자열의 길이를 기준으로 오른쪽까지의 공백 추가
		int spaceCount = COLUMN_WIDTH - (int)left.length();
		if (spaceCount > 0)
			cout << string(spaceCount, ' ');

		// 오른쪽 출력
		cout << "| " << right << '\n';
	}
	cout << "==========================================================================" << '\n';
}

void CRConsoleUI::InitCharacterStatus(const string& InName, const int& CurrentHp, const int& MaxHp)
{
	ostringstream oss;
	oss << InName << ": " << CurrentHp << "/" << MaxHp;
	LeftConsole[7] = oss.str();
}

void CRConsoleUI::InitMonsterStatus(const string& InName, const int& CurrentHp, const int& MaxHp)
{
	ostringstream oss;
	oss << InName << ": " << CurrentHp << "/" << MaxHp;
	LeftConsole[8] = oss.str();
}

void CRConsoleUI::PrintCharacterStatus(const string& InName, const int& InMaxHp, const int& InLevel, const int& InExp, const int& InDamage, const int& InGold)
{
	LeftConsole[0] = "이름: " + InName;
	LeftConsole[1] = "최대 체력: " + to_string(InMaxHp);
	LeftConsole[2] = "레벨: " + to_string(InLevel);
	LeftConsole[3] = "경험치: " + to_string(InExp);
	LeftConsole[4] = "공격력: " + to_string(InDamage);
	LeftConsole[5] = "소지 골드: " + to_string(InGold);
	LeftConsole[6] = "---------------------------------------";
}

void CRConsoleUI::PrintMonsterAttackLog(int InDamage)
{
	ostringstream oss;
	oss << "몬스터가 " << InDamage << "의 데미지로 공격!";
	PushConsoleLog(oss.str());
}

void CRConsoleUI::PrintCharacterAttackLog(int InDamage)
{
	ostringstream oss;
	oss << InDamage << "의 데미지로 몬스터를 공격!";
	PushConsoleLog(oss.str());
}

void CRConsoleUI::PushConsoleLog(string str)
{
	if (RightConsole.size() < LEFTCONSOLE_DEFAULT)
	{
		RightConsole.push_back(str);
	}
	else
	{
		RightConsole.erase(RightConsole.begin());
		RightConsole.push_back(str);
	}
	PrintCombatUI();
}

void CRConsoleUI::PrintCombatLose()
{
	PushConsoleLog("전투에서 패배했습니다!");
	PrintCombatUI();
}
void CRConsoleUI::PrintCombatWin()
{
	PushConsoleLog("전투에서 승리했습니다!");
	PrintCombatUI();
}

void CRConsoleUI::PrintGameOver()
{
	cout << "GAME OVER" << '\n';
}

