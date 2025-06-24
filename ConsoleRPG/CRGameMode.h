#pragma once
#include <vector>
#include <string>

#include "ConsoleRPG.h"
#include "ICRCombat.h"
#include "ICRGameMode.h"

using namespace std;

class CRGameMode: public ICRGameMode
{
public:
	CRGameMode();

	/* 캐릭터 관련 섹션 */
private:
	string UserName;

	/* 게임 섹션*/
public:
	virtual void GameStart() override;

	void SetUserName();

private:
	int GameLevel = 0;

	bool bIsGameOver = false;
	bool bIsCombatOver = false;

	/* 전투 관련 섹션 */
protected:
	unique_ptr<vector<shared_ptr<ICRCombat>>> CombatSequence;

public:
	void CombatInit();
	void CombatStart();
	void CombatEnd();

	void CombatWin();
	void CombatLose();

	/* Getter / Setter */
public:
	inline int GetGameLevel() { return GameLevel; }
};

