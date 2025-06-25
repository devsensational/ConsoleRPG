#pragma once
#include <vector>
#include <string>

#include "ConsoleRPG.h"
#include "ICRCombat.h"
#include "ICRGameMode.h"
#include "CRCharacter.h"
#include "CRCombatManager.h"

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

protected:
	void CombatOver();
	void CombatWin();
	void CombatLose();

private:
	shared_ptr<CRCombatManager> CombatManager;
	shared_ptr<CRCharacter> PlayerCharacter;

	int GameLevel = 0;

	bool bIsGameOver = false;
	bool bIsCombatOver = false;

	/* Getter / Setter */
public:
	inline int GetGameLevel() { return GameLevel; }
};

