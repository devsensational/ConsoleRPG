#pragma once

#include <memory>
#include <vector>

#include "CRConsoleRenderer.h"
#include "CRGameManager.h"
#include "CRMapCreator.h"

using namespace std;

class CRGameSystem
{
public:
	shared_ptr<vector<vector<int>>> grid;

private:
	bool bEndSignal = false;

	unique_ptr<CRMapCreator> mapCreator;

public:
	CRGameSystem();
	
	void GameStart();	// 게임 초기화 및 LIfecycle 시작
	void LIfecycle();	// 게임 생명 주기
	void GameEnd();		// 게임 종료
};

