#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CRConsoleUI
{
public:
	CRConsoleUI();

	void SelectName();
	void PrintCombatMenu();
	void PrintStoreMenu();

public:
	void PrintCombatUI();
	void PrintMonsterAttackLog(int damage);
	void PrintCombatLose();
	void PrintCombatWin();
	void PrintGameOver();
	

private:
	unique_ptr<vector<string>> CombatStatusList;
	unique_ptr<vector<string>> CombatLogList;
	unique_ptr<vector<string>> MenuList;
};

