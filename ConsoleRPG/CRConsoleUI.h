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
	void PrintMonsterAttackLog(int damage);
	void PrintCombatLose();
	void PrintCombatWin();
	void PrintGameOver();
	void PrintInventory(const vector<shared_ptr<CRItem>> InItems);

private:
	vector<string> LeftConsole;
	vector<string> RightConsole;
};

