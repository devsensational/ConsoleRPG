#pragma once
#include <memory>
#include <vector>

class ICRCombat;

using namespace std;

class CRCombatManager
{
public:
	CRCombatManager();


	/* ���� ���� ���� */
protected:
	unique_ptr<vector<shared_ptr<ICRCombat>>> CombatSequence;

public:
	void CombatInit(shared_ptr<ICRCombat> Unit);
	void CombatStart();
	void CombatEnd();

	void CombatWin();
	void CombatLose();
};

