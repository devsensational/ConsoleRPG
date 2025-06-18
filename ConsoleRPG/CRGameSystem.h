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
	
	void GameStart();	// ���� �ʱ�ȭ �� LIfecycle ����
	void LIfecycle();	// ���� ���� �ֱ�
	void GameEnd();		// ���� ����
};

