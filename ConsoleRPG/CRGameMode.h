#pragma once
#include <vector>
#include <string>

#include "ConsoleRPG.h"
#include "ICRCombat.h"

using namespace std;

class CRGameMode
{
public:
	CRGameMode();

	/* 캐릭터 관련 섹션 */
private:
	string UserName;

public:
	void SetUserName(const string& text);

	/* 전투 관련 섹션 */
protected:
	unique_ptr<vector<shared_ptr<ICRCombat>>> CombatSequence;

protected:
	void CombatInit();
	void CombatStart();
	void CombatEnd();
};

