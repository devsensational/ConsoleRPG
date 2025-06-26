#pragma once

#include <iostream>
#include <vector>

#define CONSOLE_WIDTH 24

using namespace std;

class CRItem;

class CRConsoleUI
{
public:
	CRConsoleUI();

	void SelectName();
	void PrintCombatMenu();
	void PrintStoreMenu();

public:
	void PrintCombatUI();
	void InitCharacterStatus(const string& InName, const int &InCurrentHp, const int &InMaxHp);
	void InitMonsterStatus(const string& InName, const int& InCurrentHp, const int& InMaxHp);
	void PrintCharacterStatus(const string& InName, const int& InMaxHp, const int& InLevel, const int& InExp, const int& InDamage, const int& InGold);
	void PrintMonsterAttackLog(int InDamage);
	void PrintCharacterAttackLog(int InDamage);
	void PushConsoleLog(string InString);
	void PrintCombatLose();
	void PrintCombatWin();
	void PrintGameOver();
	void PrintInventory(const vector<shared_ptr<CRItem>> InItems);

protected:
	bool IsNumeric(const string& InStr);

private:
	vector<string> LeftConsole;
	vector<string> RightConsole;

	int LeftConsoleIndex = 0;
};

