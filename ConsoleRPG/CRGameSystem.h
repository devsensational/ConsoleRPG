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
	
	void GameStart();	// 게임 초기화 및 LIfecycle 시작
	void LIfecycle();	// 게임 생명 주기
	void GameEnd();		// 게임 종료

	/* 전투 관련 섹션 */
protected:
	void CombatInit();
	void CombatStart();
	void CombatEnd();
};

