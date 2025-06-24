#pragma once

#include <memory>
#include <vector>

#include "CRConsoleRenderer.h"
#include "CRGameMode.h"
#include "CRConsoleUI.h"
#include "ICRCombat.h"

using namespace std;

class CRGameSystem
{
public:
	CRGameSystem();

	/* 생명주기 섹션 */
private:
	bool bEndSignal = false;

public:
	
	void GameStart();	// 게임 초기화 및 LIfecycle 시작
	void LIfecycle();	// 게임 생명 주기
	void GameEnd();		// 게임 종료

	/* 게임 매니저 섹션 */
private:
	unique_ptr<ICRGameMode> GameMode;
	unique_ptr<CRConsoleUI> GameConsoleUI;
};

