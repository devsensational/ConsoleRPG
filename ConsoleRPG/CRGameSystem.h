#pragma once

#include <memory>
#include <vector>

#include "CRConsoleRenderer.h"
#include "CRGameManager.h"
#include "ICRCombat.h"

using namespace std;

class CRGameSystem
{
public:
	shared_ptr<vector<vector<int>>> grid;

private:
	bool bEndSignal = false;

	vector<shared_ptr<ICRCombat>> CombatSequence;

public:
	CRGameSystem();
	
	void GameStart();	// ���� �ʱ�ȭ �� LIfecycle ����
	void LIfecycle();	// ���� ���� �ֱ�
	void GameEnd();		// ���� ����

	/* ���� ���� ���� */
protected:
	void CombatInit();
	void CombatStart();
	void CombatEnd();
};

